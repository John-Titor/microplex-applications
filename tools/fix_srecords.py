#!/usr/bin/env python3
#
# Perform post-link fixup operations on SDCC-generated S-records.
#
#  - Take the interrupt table at the end of memory and generate the
#    thunk table at 0xaf80-0xafff.
#  - Sort records by address, and make sure the S9 record is last.
#

import argparse
import struct
from pathlib import Path


def srec_sum(srec):
    count = int(f'0x{srec[2:4]}', 16)
    sum = 0
    for ofs in range(2, 2 + (count * 2), 2):
        sum += int(f'0x{srec[ofs:ofs+2]}', 16)
    return (~sum) & 0xff


def check_sums(srecords):
    for srec in srecords:
        claimed_sum = int(f'0x{srec[-3:-1]}', 16)
        calc_sum = srec_sum(srec)
        if calc_sum != claimed_sum:
            raise RuntimeError(f'oops, {calc_sum} wrong for {srec}')


def fixup_vectors(input_records):
    """
    The MC9S08DZ60 has 32 interrupt vectors, nominally placed in
    memory at 0xffc0 in reverse order. I.e. vector 0, the reset
    vector, is at 0xfffe.

    Since the Microplex ROM occupies that range of flash, there
    is a table of 32 4-byte thunk functions at 0xaf80-0afff.

    We will generate the thunk functions from the vector table.
    If a vector for interrupt 32 (which does not exist) is
    supplied, it will be used to initialize unused vectors; otherwise
    they will be set to the reset vector.
    """
    vectors = dict()
    output_records = list()
    default_vector = None
    # iterate input records
    for srec in input_records:
        # only care about S1 records
        if srec[1] == '1':
            address = int(f'0x{srec[4:8]}', 16)
            # check for conflicts
            if (address >= 0xaf80) and (address < 0xb000):
                raise RuntimeError('vector thunks already present')
            # does this record contain vectors?
            # should be nothing else nearby, so records for
            # vectors should only have vectors.
            # remember to include vector 32
            if address >= 0xffbe:
                # extract vector hex bytes
                hex_vectors = srec[8:-3]
                vector = (0xfffe - address) >> 1
                while len(hex_vectors) > 0:
                    vectors[vector] = hex_vectors[:4]
                    hex_vectors = hex_vectors[4:]
                    log(f'vector {vector}:{vectors[vector]}')
                    vector -= 1
                continue

        # not vector data, save as-is
        output_records += [srec]

    # make sure there is a reset vector, and if supplied, set
    # the default vector handler to the special vector 32 handler
    try:
        default_vector = vectors[0]
    except KeyError:
        raise RuntimeError('no reset vector')
    try:
        default_vector = vectors[32]
    except KeyError:
        pass

    # insert default vectors
    for i in range(1, 32):
        if i not in vectors:
            log(f'default vector {i}')
            vectors[i] = default_vector

    # generate output s-records for the vector thunks
    for vector in range(31, 0, -8):
        srec = f'S123{0xaffc - (vector * 4):04X}'
        for vector in range(vector, vector - 8, -1):
            srec += f'CC{vectors[vector]}9D'
        srec += f'{srec_sum(srec):02X}\n'
        output_records += [srec]

    return output_records


def fixup_sort(input_records):
    s1_records = dict()
    s9_record = None
    for srec in input_records:
        if srec[1] == '1':
            address = int(f'0x{srec[4:8]}', 16)
            s1_records[address] = srec
        elif srec[1] == '9':
            if s9_record is not None:
                raise RuntimeError('duplicate S9 records in input')
            s9_record = srec
    output_records = list()
    for address in sorted(s1_records):
        output_records += [s1_records[address]]
    output_records += list(s9_record)
    return output_records


parser = argparse.ArgumentParser(description='SDCC S-record fixup for MRS Microplex 7*')
parser.add_argument('srecords',
                    type=Path,
                    metavar='S-record-file',
                    help='name of the S-record file to fix up')
parser.add_argument('--verbose',
                    action='store_true',
                    help='print verbose progress information')

args = parser.parse_args()
if args.verbose:
    def log(msg):
        print(msg)
else:
    def log(msg):
        pass

with open(args.srecords) as f:
    srecords = f.readlines()
check_sums(srecords)
srecords = fixup_vectors(srecords)
srecords = fixup_sort(srecords)

with open(args.srecords, 'w') as f:
    f.writelines(srecords)
