

#ifndef _MC9S08DZ60_H
#define _MC9S08DZ60_H


typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;
typedef unsigned long dlong[2];


#ifndef __RESET_WATCHDOG
#ifdef _lint
  #define __RESET_WATCHDOG()  
#else
  #define __RESET_WATCHDOG() (void)(SRS = 0x55, SRS = 0xAA)
#endif
#endif 

#define REG_BASE 0x0000                


//#pragma MESSAGE DISABLE C1106 


#define VectorNumber_Vacmp2             31
#define VectorNumber_Vacmp1             30
#define VectorNumber_Vcantx             29
#define VectorNumber_Vcanrx             28
#define VectorNumber_Vcanerr            27
#define VectorNumber_Vcanwu             26
#define VectorNumber_Vrtc               25
#define VectorNumber_Viic               24
#define VectorNumber_Vadc               23
#define VectorNumber_Vport              22
#define VectorNumber_Vsci2tx            21
#define VectorNumber_Vsci2rx            20
#define VectorNumber_Vsci2err           19
#define VectorNumber_Vsci1tx            18
#define VectorNumber_Vsci1rx            17
#define VectorNumber_Vsci1err           16
#define VectorNumber_Vspi               15
#define VectorNumber_Vtpm2ovf           14
#define VectorNumber_Vtpm2ch1           13
#define VectorNumber_Vtpm2ch0           12
#define VectorNumber_Vtpm1ovf           11
#define VectorNumber_Vtpm1ch5           10
#define VectorNumber_Vtpm1ch4           9
#define VectorNumber_Vtpm1ch3           8
#define VectorNumber_Vtpm1ch2           7
#define VectorNumber_Vtpm1ch1           6
#define VectorNumber_Vtpm1ch0           5
#define VectorNumber_Vlol               4
#define VectorNumber_Vlvd               3
#define VectorNumber_Virq               2
#define VectorNumber_Vswi               1
#define VectorNumber_Vreset             0


#define Vacmp2                          0x0000FFC0
#define Vacmp1                          0x0000FFC2
#define Vcantx                          0x0000FFC4
#define Vcanrx                          0x0000FFC6
#define Vcanerr                         0x0000FFC8
#define Vcanwu                          0x0000FFCA
#define Vrtc                            0x0000FFCC
#define Viic                            0x0000FFCE
#define Vadc                            0x0000FFD0
#define Vport                           0x0000FFD2
#define Vsci2tx                         0x0000FFD4
#define Vsci2rx                         0x0000FFD6
#define Vsci2err                        0x0000FFD8
#define Vsci1tx                         0x0000FFDA
#define Vsci1rx                         0x0000FFDC
#define Vsci1err                        0x0000FFDE
#define Vspi                            0x0000FFE0
#define Vtpm2ovf                        0x0000FFE2
#define Vtpm2ch1                        0x0000FFE4
#define Vtpm2ch0                        0x0000FFE6
#define Vtpm1ovf                        0x0000FFE8
#define Vtpm1ch5                        0x0000FFEA
#define Vtpm1ch4                        0x0000FFEC
#define Vtpm1ch3                        0x0000FFEE
#define Vtpm1ch2                        0x0000FFF0
#define Vtpm1ch1                        0x0000FFF2
#define Vtpm1ch0                        0x0000FFF4
#define Vlol                            0x0000FFF6
#define Vlvd                            0x0000FFF8
#define Virq                            0x0000FFFA
#define Vswi                            0x0000FFFC
#define Vreset                          0x0000FFFE




typedef union {
  byte Byte;
  struct {
    byte PTAD0       :1;                                       
    byte PTAD1       :1;                                       
    byte PTAD2       :1;                                       
    byte PTAD3       :1;                                       
    byte PTAD4       :1;                                       
    byte PTAD5       :1;                                       
    byte PTAD6       :1;                                       
    byte PTAD7       :1;                                       
  } Bits;
} PTADSTR;
volatile PTADSTR __at (0x0000) _PTAD;
#define PTAD                            _PTAD.Byte
#define PTAD_PTAD0                      _PTAD.Bits.PTAD0
#define PTAD_PTAD1                      _PTAD.Bits.PTAD1
#define PTAD_PTAD2                      _PTAD.Bits.PTAD2
#define PTAD_PTAD3                      _PTAD.Bits.PTAD3
#define PTAD_PTAD4                      _PTAD.Bits.PTAD4
#define PTAD_PTAD5                      _PTAD.Bits.PTAD5
#define PTAD_PTAD6                      _PTAD.Bits.PTAD6
#define PTAD_PTAD7                      _PTAD.Bits.PTAD7

#define PTAD_PTAD0_MASK                 1
#define PTAD_PTAD1_MASK                 2
#define PTAD_PTAD2_MASK                 4
#define PTAD_PTAD3_MASK                 8
#define PTAD_PTAD4_MASK                 16
#define PTAD_PTAD5_MASK                 32
#define PTAD_PTAD6_MASK                 64
#define PTAD_PTAD7_MASK                 128



typedef union {
  byte Byte;
  struct {
    byte PTADD0      :1;                                       
    byte PTADD1      :1;                                       
    byte PTADD2      :1;                                       
    byte PTADD3      :1;                                       
    byte PTADD4      :1;                                       
    byte PTADD5      :1;                                       
    byte PTADD6      :1;                                       
    byte PTADD7      :1;                                       
  } Bits;
} PTADDSTR;
volatile PTADDSTR __at (0x0001) _PTADD;
#define PTADD                           _PTADD.Byte
#define PTADD_PTADD0                    _PTADD.Bits.PTADD0
#define PTADD_PTADD1                    _PTADD.Bits.PTADD1
#define PTADD_PTADD2                    _PTADD.Bits.PTADD2
#define PTADD_PTADD3                    _PTADD.Bits.PTADD3
#define PTADD_PTADD4                    _PTADD.Bits.PTADD4
#define PTADD_PTADD5                    _PTADD.Bits.PTADD5
#define PTADD_PTADD6                    _PTADD.Bits.PTADD6
#define PTADD_PTADD7                    _PTADD.Bits.PTADD7

#define PTADD_PTADD0_MASK               1
#define PTADD_PTADD1_MASK               2
#define PTADD_PTADD2_MASK               4
#define PTADD_PTADD3_MASK               8
#define PTADD_PTADD4_MASK               16
#define PTADD_PTADD5_MASK               32
#define PTADD_PTADD6_MASK               64
#define PTADD_PTADD7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTBD0       :1;                                       
    byte PTBD1       :1;                                       
    byte PTBD2       :1;                                       
    byte PTBD3       :1;                                       
    byte PTBD4       :1;                                       
    byte PTBD5       :1;                                       
    byte PTBD6       :1;                                       
    byte PTBD7       :1;                                       
  } Bits;
} PTBDSTR;
volatile PTBDSTR __at (0x0002) _PTBD;
#define PTBD                            _PTBD.Byte
#define PTBD_PTBD0                      _PTBD.Bits.PTBD0
#define PTBD_PTBD1                      _PTBD.Bits.PTBD1
#define PTBD_PTBD2                      _PTBD.Bits.PTBD2
#define PTBD_PTBD3                      _PTBD.Bits.PTBD3
#define PTBD_PTBD4                      _PTBD.Bits.PTBD4
#define PTBD_PTBD5                      _PTBD.Bits.PTBD5
#define PTBD_PTBD6                      _PTBD.Bits.PTBD6
#define PTBD_PTBD7                      _PTBD.Bits.PTBD7

#define PTBD_PTBD0_MASK                 1
#define PTBD_PTBD1_MASK                 2
#define PTBD_PTBD2_MASK                 4
#define PTBD_PTBD3_MASK                 8
#define PTBD_PTBD4_MASK                 16
#define PTBD_PTBD5_MASK                 32
#define PTBD_PTBD6_MASK                 64
#define PTBD_PTBD7_MASK                 128



typedef union {
  byte Byte;
  struct {
    byte PTBDD0      :1;                                       
    byte PTBDD1      :1;                                       
    byte PTBDD2      :1;                                       
    byte PTBDD3      :1;                                       
    byte PTBDD4      :1;                                       
    byte PTBDD5      :1;                                       
    byte PTBDD6      :1;                                       
    byte PTBDD7      :1;                                       
  } Bits;
} PTBDDSTR;
volatile PTBDDSTR __at (0x0003) _PTBDD;
#define PTBDD                           _PTBDD.Byte
#define PTBDD_PTBDD0                    _PTBDD.Bits.PTBDD0
#define PTBDD_PTBDD1                    _PTBDD.Bits.PTBDD1
#define PTBDD_PTBDD2                    _PTBDD.Bits.PTBDD2
#define PTBDD_PTBDD3                    _PTBDD.Bits.PTBDD3
#define PTBDD_PTBDD4                    _PTBDD.Bits.PTBDD4
#define PTBDD_PTBDD5                    _PTBDD.Bits.PTBDD5
#define PTBDD_PTBDD6                    _PTBDD.Bits.PTBDD6
#define PTBDD_PTBDD7                    _PTBDD.Bits.PTBDD7

#define PTBDD_PTBDD0_MASK               1
#define PTBDD_PTBDD1_MASK               2
#define PTBDD_PTBDD2_MASK               4
#define PTBDD_PTBDD3_MASK               8
#define PTBDD_PTBDD4_MASK               16
#define PTBDD_PTBDD5_MASK               32
#define PTBDD_PTBDD6_MASK               64
#define PTBDD_PTBDD7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTCD0       :1;                                       
    byte PTCD1       :1;                                       
    byte PTCD2       :1;                                       
    byte PTCD3       :1;                                       
    byte PTCD4       :1;                                       
    byte PTCD5       :1;                                       
    byte PTCD6       :1;                                       
    byte PTCD7       :1;                                       
  } Bits;
} PTCDSTR;
volatile PTCDSTR __at (0x0004) _PTCD;
#define PTCD                            _PTCD.Byte
#define PTCD_PTCD0                      _PTCD.Bits.PTCD0
#define PTCD_PTCD1                      _PTCD.Bits.PTCD1
#define PTCD_PTCD2                      _PTCD.Bits.PTCD2
#define PTCD_PTCD3                      _PTCD.Bits.PTCD3
#define PTCD_PTCD4                      _PTCD.Bits.PTCD4
#define PTCD_PTCD5                      _PTCD.Bits.PTCD5
#define PTCD_PTCD6                      _PTCD.Bits.PTCD6
#define PTCD_PTCD7                      _PTCD.Bits.PTCD7

#define PTCD_PTCD0_MASK                 1
#define PTCD_PTCD1_MASK                 2
#define PTCD_PTCD2_MASK                 4
#define PTCD_PTCD3_MASK                 8
#define PTCD_PTCD4_MASK                 16
#define PTCD_PTCD5_MASK                 32
#define PTCD_PTCD6_MASK                 64
#define PTCD_PTCD7_MASK                 128



typedef union {
  byte Byte;
  struct {
    byte PTCDD0      :1;                                       
    byte PTCDD1      :1;                                       
    byte PTCDD2      :1;                                       
    byte PTCDD3      :1;                                       
    byte PTCDD4      :1;                                       
    byte PTCDD5      :1;                                       
    byte PTCDD6      :1;                                       
    byte PTCDD7      :1;                                       
  } Bits;
} PTCDDSTR;
volatile PTCDDSTR __at (0x0005) _PTCDD;
#define PTCDD                           _PTCDD.Byte
#define PTCDD_PTCDD0                    _PTCDD.Bits.PTCDD0
#define PTCDD_PTCDD1                    _PTCDD.Bits.PTCDD1
#define PTCDD_PTCDD2                    _PTCDD.Bits.PTCDD2
#define PTCDD_PTCDD3                    _PTCDD.Bits.PTCDD3
#define PTCDD_PTCDD4                    _PTCDD.Bits.PTCDD4
#define PTCDD_PTCDD5                    _PTCDD.Bits.PTCDD5
#define PTCDD_PTCDD6                    _PTCDD.Bits.PTCDD6
#define PTCDD_PTCDD7                    _PTCDD.Bits.PTCDD7

#define PTCDD_PTCDD0_MASK               1
#define PTCDD_PTCDD1_MASK               2
#define PTCDD_PTCDD2_MASK               4
#define PTCDD_PTCDD3_MASK               8
#define PTCDD_PTCDD4_MASK               16
#define PTCDD_PTCDD5_MASK               32
#define PTCDD_PTCDD6_MASK               64
#define PTCDD_PTCDD7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTDD0       :1;                                       
    byte PTDD1       :1;                                       
    byte PTDD2       :1;                                       
    byte PTDD3       :1;                                       
    byte PTDD4       :1;                                       
    byte PTDD5       :1;                                       
    byte PTDD6       :1;                                       
    byte PTDD7       :1;                                       
  } Bits;
} PTDDSTR;
volatile PTDDSTR __at (0x0006) _PTDD;
#define PTDD                            _PTDD.Byte
#define PTDD_PTDD0                      _PTDD.Bits.PTDD0
#define PTDD_PTDD1                      _PTDD.Bits.PTDD1
#define PTDD_PTDD2                      _PTDD.Bits.PTDD2
#define PTDD_PTDD3                      _PTDD.Bits.PTDD3
#define PTDD_PTDD4                      _PTDD.Bits.PTDD4
#define PTDD_PTDD5                      _PTDD.Bits.PTDD5
#define PTDD_PTDD6                      _PTDD.Bits.PTDD6
#define PTDD_PTDD7                      _PTDD.Bits.PTDD7

#define PTDD_PTDD0_MASK                 1
#define PTDD_PTDD1_MASK                 2
#define PTDD_PTDD2_MASK                 4
#define PTDD_PTDD3_MASK                 8
#define PTDD_PTDD4_MASK                 16
#define PTDD_PTDD5_MASK                 32
#define PTDD_PTDD6_MASK                 64
#define PTDD_PTDD7_MASK                 128



typedef union {
  byte Byte;
  struct {
    byte PTDDD0      :1;                                       
    byte PTDDD1      :1;                                       
    byte PTDDD2      :1;                                       
    byte PTDDD3      :1;                                       
    byte PTDDD4      :1;                                       
    byte PTDDD5      :1;                                       
    byte PTDDD6      :1;                                       
    byte PTDDD7      :1;                                       
  } Bits;
} PTDDDSTR;
volatile PTDDDSTR __at (0x0007) _PTDDD;
#define PTDDD                           _PTDDD.Byte
#define PTDDD_PTDDD0                    _PTDDD.Bits.PTDDD0
#define PTDDD_PTDDD1                    _PTDDD.Bits.PTDDD1
#define PTDDD_PTDDD2                    _PTDDD.Bits.PTDDD2
#define PTDDD_PTDDD3                    _PTDDD.Bits.PTDDD3
#define PTDDD_PTDDD4                    _PTDDD.Bits.PTDDD4
#define PTDDD_PTDDD5                    _PTDDD.Bits.PTDDD5
#define PTDDD_PTDDD6                    _PTDDD.Bits.PTDDD6
#define PTDDD_PTDDD7                    _PTDDD.Bits.PTDDD7

#define PTDDD_PTDDD0_MASK               1
#define PTDDD_PTDDD1_MASK               2
#define PTDDD_PTDDD2_MASK               4
#define PTDDD_PTDDD3_MASK               8
#define PTDDD_PTDDD4_MASK               16
#define PTDDD_PTDDD5_MASK               32
#define PTDDD_PTDDD6_MASK               64
#define PTDDD_PTDDD7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTED0       :1;                                       
    byte PTED1       :1;                                       
    byte PTED2       :1;                                       
    byte PTED3       :1;                                       
    byte PTED4       :1;                                       
    byte PTED5       :1;                                       
    byte PTED6       :1;                                       
    byte PTED7       :1;                                       
  } Bits;
} PTEDSTR;
volatile PTEDSTR __at (0x0008) _PTED;
#define PTED                            _PTED.Byte
#define PTED_PTED0                      _PTED.Bits.PTED0
#define PTED_PTED1                      _PTED.Bits.PTED1
#define PTED_PTED2                      _PTED.Bits.PTED2
#define PTED_PTED3                      _PTED.Bits.PTED3
#define PTED_PTED4                      _PTED.Bits.PTED4
#define PTED_PTED5                      _PTED.Bits.PTED5
#define PTED_PTED6                      _PTED.Bits.PTED6
#define PTED_PTED7                      _PTED.Bits.PTED7

#define PTED_PTED0_MASK                 1
#define PTED_PTED1_MASK                 2
#define PTED_PTED2_MASK                 4
#define PTED_PTED3_MASK                 8
#define PTED_PTED4_MASK                 16
#define PTED_PTED5_MASK                 32
#define PTED_PTED6_MASK                 64
#define PTED_PTED7_MASK                 128



typedef union {
  byte Byte;
  struct {
    byte PTEDD0      :1;                                       
    byte PTEDD1      :1;                                       
    byte PTEDD2      :1;                                       
    byte PTEDD3      :1;                                       
    byte PTEDD4      :1;                                       
    byte PTEDD5      :1;                                       
    byte PTEDD6      :1;                                       
    byte PTEDD7      :1;                                       
  } Bits;
} PTEDDSTR;
volatile PTEDDSTR __at (0x0009) _PTEDD;
#define PTEDD                           _PTEDD.Byte
#define PTEDD_PTEDD0                    _PTEDD.Bits.PTEDD0
#define PTEDD_PTEDD1                    _PTEDD.Bits.PTEDD1
#define PTEDD_PTEDD2                    _PTEDD.Bits.PTEDD2
#define PTEDD_PTEDD3                    _PTEDD.Bits.PTEDD3
#define PTEDD_PTEDD4                    _PTEDD.Bits.PTEDD4
#define PTEDD_PTEDD5                    _PTEDD.Bits.PTEDD5
#define PTEDD_PTEDD6                    _PTEDD.Bits.PTEDD6
#define PTEDD_PTEDD7                    _PTEDD.Bits.PTEDD7

#define PTEDD_PTEDD0_MASK               1
#define PTEDD_PTEDD1_MASK               2
#define PTEDD_PTEDD2_MASK               4
#define PTEDD_PTEDD3_MASK               8
#define PTEDD_PTEDD4_MASK               16
#define PTEDD_PTEDD5_MASK               32
#define PTEDD_PTEDD6_MASK               64
#define PTEDD_PTEDD7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTFD0       :1;                                       
    byte PTFD1       :1;                                       
    byte PTFD2       :1;                                       
    byte PTFD3       :1;                                       
    byte PTFD4       :1;                                       
    byte PTFD5       :1;                                       
    byte PTFD6       :1;                                       
    byte PTFD7       :1;                                       
  } Bits;
} PTFDSTR;
volatile PTFDSTR __at (0x000A) _PTFD;
#define PTFD                            _PTFD.Byte
#define PTFD_PTFD0                      _PTFD.Bits.PTFD0
#define PTFD_PTFD1                      _PTFD.Bits.PTFD1
#define PTFD_PTFD2                      _PTFD.Bits.PTFD2
#define PTFD_PTFD3                      _PTFD.Bits.PTFD3
#define PTFD_PTFD4                      _PTFD.Bits.PTFD4
#define PTFD_PTFD5                      _PTFD.Bits.PTFD5
#define PTFD_PTFD6                      _PTFD.Bits.PTFD6
#define PTFD_PTFD7                      _PTFD.Bits.PTFD7

#define PTFD_PTFD0_MASK                 1
#define PTFD_PTFD1_MASK                 2
#define PTFD_PTFD2_MASK                 4
#define PTFD_PTFD3_MASK                 8
#define PTFD_PTFD4_MASK                 16
#define PTFD_PTFD5_MASK                 32
#define PTFD_PTFD6_MASK                 64
#define PTFD_PTFD7_MASK                 128



typedef union {
  byte Byte;
  struct {
    byte PTFDD0      :1;                                       
    byte PTFDD1      :1;                                       
    byte PTFDD2      :1;                                       
    byte PTFDD3      :1;                                       
    byte PTFDD4      :1;                                       
    byte PTFDD5      :1;                                       
    byte PTFDD6      :1;                                       
    byte PTFDD7      :1;                                       
  } Bits;
} PTFDDSTR;
volatile PTFDDSTR __at (0x000B) _PTFDD;
#define PTFDD                           _PTFDD.Byte
#define PTFDD_PTFDD0                    _PTFDD.Bits.PTFDD0
#define PTFDD_PTFDD1                    _PTFDD.Bits.PTFDD1
#define PTFDD_PTFDD2                    _PTFDD.Bits.PTFDD2
#define PTFDD_PTFDD3                    _PTFDD.Bits.PTFDD3
#define PTFDD_PTFDD4                    _PTFDD.Bits.PTFDD4
#define PTFDD_PTFDD5                    _PTFDD.Bits.PTFDD5
#define PTFDD_PTFDD6                    _PTFDD.Bits.PTFDD6
#define PTFDD_PTFDD7                    _PTFDD.Bits.PTFDD7

#define PTFDD_PTFDD0_MASK               1
#define PTFDD_PTFDD1_MASK               2
#define PTFDD_PTFDD2_MASK               4
#define PTFDD_PTFDD3_MASK               8
#define PTFDD_PTFDD4_MASK               16
#define PTFDD_PTFDD5_MASK               32
#define PTFDD_PTFDD6_MASK               64
#define PTFDD_PTFDD7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTGD0       :1;                                       
    byte PTGD1       :1;                                       
    byte PTGD2       :1;                                       
    byte PTGD3       :1;                                       
    byte PTGD4       :1;                                       
    byte PTGD5       :1;                                       
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTGD :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTGDSTR;
volatile PTGDSTR __at (0x000C) _PTGD;
#define PTGD                            _PTGD.Byte
#define PTGD_PTGD0                      _PTGD.Bits.PTGD0
#define PTGD_PTGD1                      _PTGD.Bits.PTGD1
#define PTGD_PTGD2                      _PTGD.Bits.PTGD2
#define PTGD_PTGD3                      _PTGD.Bits.PTGD3
#define PTGD_PTGD4                      _PTGD.Bits.PTGD4
#define PTGD_PTGD5                      _PTGD.Bits.PTGD5
#define PTGD_PTGD                       _PTGD.MergedBits.grpPTGD

#define PTGD_PTGD0_MASK                 1
#define PTGD_PTGD1_MASK                 2
#define PTGD_PTGD2_MASK                 4
#define PTGD_PTGD3_MASK                 8
#define PTGD_PTGD4_MASK                 16
#define PTGD_PTGD5_MASK                 32
#define PTGD_PTGD_MASK                  63
#define PTGD_PTGD_BITNUM                0



typedef union {
  byte Byte;
  struct {
    byte PTGDD0      :1;                                       
    byte PTGDD1      :1;                                       
    byte PTGDD2      :1;                                       
    byte PTGDD3      :1;                                       
    byte PTGDD4      :1;                                       
    byte PTGDD5      :1;                                       
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTGDD :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTGDDSTR;
volatile PTGDDSTR __at (0x000D) _PTGDD;
#define PTGDD                           _PTGDD.Byte
#define PTGDD_PTGDD0                    _PTGDD.Bits.PTGDD0
#define PTGDD_PTGDD1                    _PTGDD.Bits.PTGDD1
#define PTGDD_PTGDD2                    _PTGDD.Bits.PTGDD2
#define PTGDD_PTGDD3                    _PTGDD.Bits.PTGDD3
#define PTGDD_PTGDD4                    _PTGDD.Bits.PTGDD4
#define PTGDD_PTGDD5                    _PTGDD.Bits.PTGDD5
#define PTGDD_PTGDD                     _PTGDD.MergedBits.grpPTGDD

#define PTGDD_PTGDD0_MASK               1
#define PTGDD_PTGDD1_MASK               2
#define PTGDD_PTGDD2_MASK               4
#define PTGDD_PTGDD3_MASK               8
#define PTGDD_PTGDD4_MASK               16
#define PTGDD_PTGDD5_MASK               32
#define PTGDD_PTGDD_MASK                63
#define PTGDD_PTGDD_BITNUM              0



typedef union {
  byte Byte;
  struct {
    byte ACMOD0      :1;                                       
    byte ACMOD1      :1;                                       
    byte ACOPE       :1;                                       
    byte ACO         :1;                                       
    byte ACIE        :1;                                       
    byte ACF         :1;                                       
    byte ACBGS       :1;                                       
    byte ACME        :1;                                       
  } Bits;
  struct {
    byte grpACMOD :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ACMP1SCSTR;
volatile ACMP1SCSTR __at (0x000E) _ACMP1SC;
#define ACMP1SC                         _ACMP1SC.Byte
#define ACMP1SC_ACMOD0                  _ACMP1SC.Bits.ACMOD0
#define ACMP1SC_ACMOD1                  _ACMP1SC.Bits.ACMOD1
#define ACMP1SC_ACOPE                   _ACMP1SC.Bits.ACOPE
#define ACMP1SC_ACO                     _ACMP1SC.Bits.ACO
#define ACMP1SC_ACIE                    _ACMP1SC.Bits.ACIE
#define ACMP1SC_ACF                     _ACMP1SC.Bits.ACF
#define ACMP1SC_ACBGS                   _ACMP1SC.Bits.ACBGS
#define ACMP1SC_ACME                    _ACMP1SC.Bits.ACME
#define ACMP1SC_ACMOD                   _ACMP1SC.MergedBits.grpACMOD

#define ACMP1SC_ACMOD0_MASK             1
#define ACMP1SC_ACMOD1_MASK             2
#define ACMP1SC_ACOPE_MASK              4
#define ACMP1SC_ACO_MASK                8
#define ACMP1SC_ACIE_MASK               16
#define ACMP1SC_ACF_MASK                32
#define ACMP1SC_ACBGS_MASK              64
#define ACMP1SC_ACME_MASK               128
#define ACMP1SC_ACMOD_MASK              3
#define ACMP1SC_ACMOD_BITNUM            0



typedef union {
  byte Byte;
  struct {
    byte ACMOD0      :1;                                       
    byte ACMOD1      :1;                                       
    byte ACOPE       :1;                                       
    byte ACO         :1;                                       
    byte ACIE        :1;                                       
    byte ACF         :1;                                       
    byte ACBGS       :1;                                       
    byte ACME        :1;                                       
  } Bits;
  struct {
    byte grpACMOD :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ACMP2SCSTR;
volatile ACMP2SCSTR __at (0x000F) _ACMP2SC;
#define ACMP2SC                         _ACMP2SC.Byte
#define ACMP2SC_ACMOD0                  _ACMP2SC.Bits.ACMOD0
#define ACMP2SC_ACMOD1                  _ACMP2SC.Bits.ACMOD1
#define ACMP2SC_ACOPE                   _ACMP2SC.Bits.ACOPE
#define ACMP2SC_ACO                     _ACMP2SC.Bits.ACO
#define ACMP2SC_ACIE                    _ACMP2SC.Bits.ACIE
#define ACMP2SC_ACF                     _ACMP2SC.Bits.ACF
#define ACMP2SC_ACBGS                   _ACMP2SC.Bits.ACBGS
#define ACMP2SC_ACME                    _ACMP2SC.Bits.ACME
#define ACMP2SC_ACMOD                   _ACMP2SC.MergedBits.grpACMOD

#define ACMP2SC_ACMOD0_MASK             1
#define ACMP2SC_ACMOD1_MASK             2
#define ACMP2SC_ACOPE_MASK              4
#define ACMP2SC_ACO_MASK                8
#define ACMP2SC_ACIE_MASK               16
#define ACMP2SC_ACF_MASK                32
#define ACMP2SC_ACBGS_MASK              64
#define ACMP2SC_ACME_MASK               128
#define ACMP2SC_ACMOD_MASK              3
#define ACMP2SC_ACMOD_BITNUM            0



typedef union {
  byte Byte;
  struct {
    byte ADCH0       :1;                                       
    byte ADCH1       :1;                                       
    byte ADCH2       :1;                                       
    byte ADCH3       :1;                                       
    byte ADCH4       :1;                                       
    byte ADCO        :1;                                       
    byte AIEN        :1;                                       
    byte COCO        :1;                                       
  } Bits;
  struct {
    byte grpADCH :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADCSC1STR;
volatile ADCSC1STR __at (0x0010) _ADCSC1;
#define ADCSC1                          _ADCSC1.Byte
#define ADCSC1_ADCH0                    _ADCSC1.Bits.ADCH0
#define ADCSC1_ADCH1                    _ADCSC1.Bits.ADCH1
#define ADCSC1_ADCH2                    _ADCSC1.Bits.ADCH2
#define ADCSC1_ADCH3                    _ADCSC1.Bits.ADCH3
#define ADCSC1_ADCH4                    _ADCSC1.Bits.ADCH4
#define ADCSC1_ADCO                     _ADCSC1.Bits.ADCO
#define ADCSC1_AIEN                     _ADCSC1.Bits.AIEN
#define ADCSC1_COCO                     _ADCSC1.Bits.COCO
#define ADCSC1_ADCH                     _ADCSC1.MergedBits.grpADCH

#define ADCSC1_ADCH0_MASK               1
#define ADCSC1_ADCH1_MASK               2
#define ADCSC1_ADCH2_MASK               4
#define ADCSC1_ADCH3_MASK               8
#define ADCSC1_ADCH4_MASK               16
#define ADCSC1_ADCO_MASK                32
#define ADCSC1_AIEN_MASK                64
#define ADCSC1_COCO_MASK                128
#define ADCSC1_ADCH_MASK                31
#define ADCSC1_ADCH_BITNUM              0



typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte ACFGT       :1;                                       
    byte ACFE        :1;                                       
    byte ADTRG       :1;                                       
    byte ADACT       :1;                                       
  } Bits;
} ADCSC2STR;
volatile ADCSC2STR __at (0x0011) _ADCSC2;
#define ADCSC2                          _ADCSC2.Byte
#define ADCSC2_ACFGT                    _ADCSC2.Bits.ACFGT
#define ADCSC2_ACFE                     _ADCSC2.Bits.ACFE
#define ADCSC2_ADTRG                    _ADCSC2.Bits.ADTRG
#define ADCSC2_ADACT                    _ADCSC2.Bits.ADACT

#define ADCSC2_ACFGT_MASK               16
#define ADCSC2_ACFE_MASK                32
#define ADCSC2_ADTRG_MASK               64
#define ADCSC2_ADACT_MASK               128



typedef union {
  word Word;
   
  struct {
    
    union {
      byte Byte;
      struct {
        byte ADR8        :1;                                       
        byte ADR9        :1;                                       
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpADR_8 :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ADCRHSTR;
    #define ADCRH                       _ADCR.Overlap_STR.ADCRHSTR.Byte
    #define ADCRH_ADR8                  _ADCR.Overlap_STR.ADCRHSTR.Bits.ADR8
    #define ADCRH_ADR9                  _ADCR.Overlap_STR.ADCRHSTR.Bits.ADR9
    
    #define ADCRH_ADR_8                 _ADCR.Overlap_STR.ADCRHSTR.MergedBits.grpADR_8
    #define ADCRH_ADR                   ADCRH_ADR_8
    
    #define ADCRH_ADR8_MASK             1
    #define ADCRH_ADR9_MASK             2
    #define ADCRH_ADR_8_MASK            3
    #define ADCRH_ADR_8_BITNUM          0


    
    union {
      byte Byte;
      struct {
        byte ADR0        :1;                                       
        byte ADR1        :1;                                       
        byte ADR2        :1;                                       
        byte ADR3        :1;                                       
        byte ADR4        :1;                                       
        byte ADR5        :1;                                       
        byte ADR6        :1;                                       
        byte ADR7        :1;                                       
      } Bits;
    } ADCRLSTR;
    #define ADCRL                       _ADCR.Overlap_STR.ADCRLSTR.Byte
    #define ADCRL_ADR0                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR0
    #define ADCRL_ADR1                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR1
    #define ADCRL_ADR2                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR2
    #define ADCRL_ADR3                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR3
    #define ADCRL_ADR4                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR4
    #define ADCRL_ADR5                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR5
    #define ADCRL_ADR6                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR6
    #define ADCRL_ADR7                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR7
    
    
    #define ADCRL_ADR0_MASK             1
    #define ADCRL_ADR1_MASK             2
    #define ADCRL_ADR2_MASK             4
    #define ADCRL_ADR3_MASK             8
    #define ADCRL_ADR4_MASK             16
    #define ADCRL_ADR5_MASK             32
    #define ADCRL_ADR6_MASK             64
    #define ADCRL_ADR7_MASK             128

  } Overlap_STR;

} ADCRSTR;
volatile ADCRSTR __at (0x0012) _ADCR;
#define ADCR                            _ADCR.Word




typedef union {
  word Word;
   
  struct {
    
    union {
      byte Byte;
      struct {
        byte ADCV8       :1;                                       
        byte ADCV9       :1;                                       
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpADCV_8 :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ADCCVHSTR;
    #define ADCCVH                      _ADCCV.Overlap_STR.ADCCVHSTR.Byte
    #define ADCCVH_ADCV8                _ADCCV.Overlap_STR.ADCCVHSTR.Bits.ADCV8
    #define ADCCVH_ADCV9                _ADCCV.Overlap_STR.ADCCVHSTR.Bits.ADCV9
    
    #define ADCCVH_ADCV_8               _ADCCV.Overlap_STR.ADCCVHSTR.MergedBits.grpADCV_8
    #define ADCCVH_ADCV                 ADCCVH_ADCV_8
    
    #define ADCCVH_ADCV8_MASK           1
    #define ADCCVH_ADCV9_MASK           2
    #define ADCCVH_ADCV_8_MASK          3
    #define ADCCVH_ADCV_8_BITNUM        0


    
    union {
      byte Byte;
      struct {
        byte ADCV0       :1;                                       
        byte ADCV1       :1;                                       
        byte ADCV2       :1;                                       
        byte ADCV3       :1;                                       
        byte ADCV4       :1;                                       
        byte ADCV5       :1;                                       
        byte ADCV6       :1;                                       
        byte ADCV7       :1;                                       
      } Bits;
    } ADCCVLSTR;
    #define ADCCVL                      _ADCCV.Overlap_STR.ADCCVLSTR.Byte
    #define ADCCVL_ADCV0                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV0
    #define ADCCVL_ADCV1                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV1
    #define ADCCVL_ADCV2                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV2
    #define ADCCVL_ADCV3                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV3
    #define ADCCVL_ADCV4                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV4
    #define ADCCVL_ADCV5                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV5
    #define ADCCVL_ADCV6                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV6
    #define ADCCVL_ADCV7                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV7
    
    
    #define ADCCVL_ADCV0_MASK           1
    #define ADCCVL_ADCV1_MASK           2
    #define ADCCVL_ADCV2_MASK           4
    #define ADCCVL_ADCV3_MASK           8
    #define ADCCVL_ADCV4_MASK           16
    #define ADCCVL_ADCV5_MASK           32
    #define ADCCVL_ADCV6_MASK           64
    #define ADCCVL_ADCV7_MASK           128

  } Overlap_STR;

} ADCCVSTR;
volatile ADCCVSTR __at (0x0014) _ADCCV;
#define ADCCV                           _ADCCV.Word




typedef union {
  byte Byte;
  struct {
    byte ADICLK0     :1;                                       
    byte ADICLK1     :1;                                       
    byte MODE0       :1;                                       
    byte MODE1       :1;                                       
    byte ADLSMP      :1;                                       
    byte ADIV0       :1;                                       
    byte ADIV1       :1;                                       
    byte ADLPC       :1;                                       
  } Bits;
  struct {
    byte grpADICLK :2;
    byte grpMODE :2;
    byte         :1;
    byte grpADIV :2;
    byte         :1;
  } MergedBits;
} ADCCFGSTR;
volatile ADCCFGSTR __at (0x0016) _ADCCFG;
#define ADCCFG                          _ADCCFG.Byte
#define ADCCFG_ADICLK0                  _ADCCFG.Bits.ADICLK0
#define ADCCFG_ADICLK1                  _ADCCFG.Bits.ADICLK1
#define ADCCFG_MODE0                    _ADCCFG.Bits.MODE0
#define ADCCFG_MODE1                    _ADCCFG.Bits.MODE1
#define ADCCFG_ADLSMP                   _ADCCFG.Bits.ADLSMP
#define ADCCFG_ADIV0                    _ADCCFG.Bits.ADIV0
#define ADCCFG_ADIV1                    _ADCCFG.Bits.ADIV1
#define ADCCFG_ADLPC                    _ADCCFG.Bits.ADLPC
#define ADCCFG_ADICLK                   _ADCCFG.MergedBits.grpADICLK
#define ADCCFG_MODE                     _ADCCFG.MergedBits.grpMODE
#define ADCCFG_ADIV                     _ADCCFG.MergedBits.grpADIV

#define ADCCFG_ADICLK0_MASK             1
#define ADCCFG_ADICLK1_MASK             2
#define ADCCFG_MODE0_MASK               4
#define ADCCFG_MODE1_MASK               8
#define ADCCFG_ADLSMP_MASK              16
#define ADCCFG_ADIV0_MASK               32
#define ADCCFG_ADIV1_MASK               64
#define ADCCFG_ADLPC_MASK               128
#define ADCCFG_ADICLK_MASK              3
#define ADCCFG_ADICLK_BITNUM            0
#define ADCCFG_MODE_MASK                12
#define ADCCFG_MODE_BITNUM              2
#define ADCCFG_ADIV_MASK                96
#define ADCCFG_ADIV_BITNUM              5



typedef union {
  byte Byte;
  struct {
    byte ADPC0       :1;                                       
    byte ADPC1       :1;                                       
    byte ADPC2       :1;                                       
    byte ADPC3       :1;                                       
    byte ADPC4       :1;                                       
    byte ADPC5       :1;                                       
    byte ADPC6       :1;                                       
    byte ADPC7       :1;                                       
  } Bits;
} APCTL1STR;
volatile APCTL1STR __at (0x0017) _APCTL1;
#define APCTL1                          _APCTL1.Byte
#define APCTL1_ADPC0                    _APCTL1.Bits.ADPC0
#define APCTL1_ADPC1                    _APCTL1.Bits.ADPC1
#define APCTL1_ADPC2                    _APCTL1.Bits.ADPC2
#define APCTL1_ADPC3                    _APCTL1.Bits.ADPC3
#define APCTL1_ADPC4                    _APCTL1.Bits.ADPC4
#define APCTL1_ADPC5                    _APCTL1.Bits.ADPC5
#define APCTL1_ADPC6                    _APCTL1.Bits.ADPC6
#define APCTL1_ADPC7                    _APCTL1.Bits.ADPC7

#define APCTL1_ADPC0_MASK               1
#define APCTL1_ADPC1_MASK               2
#define APCTL1_ADPC2_MASK               4
#define APCTL1_ADPC3_MASK               8
#define APCTL1_ADPC4_MASK               16
#define APCTL1_ADPC5_MASK               32
#define APCTL1_ADPC6_MASK               64
#define APCTL1_ADPC7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte ADPC8       :1;                                       
    byte ADPC9       :1;                                       
    byte ADPC10      :1;                                       
    byte ADPC11      :1;                                       
    byte ADPC12      :1;                                       
    byte ADPC13      :1;                                       
    byte ADPC14      :1;                                       
    byte ADPC15      :1;                                       
  } Bits;
} APCTL2STR;
volatile APCTL2STR __at (0x0018) _APCTL2;
#define APCTL2                          _APCTL2.Byte
#define APCTL2_ADPC8                    _APCTL2.Bits.ADPC8
#define APCTL2_ADPC9                    _APCTL2.Bits.ADPC9
#define APCTL2_ADPC10                   _APCTL2.Bits.ADPC10
#define APCTL2_ADPC11                   _APCTL2.Bits.ADPC11
#define APCTL2_ADPC12                   _APCTL2.Bits.ADPC12
#define APCTL2_ADPC13                   _APCTL2.Bits.ADPC13
#define APCTL2_ADPC14                   _APCTL2.Bits.ADPC14
#define APCTL2_ADPC15                   _APCTL2.Bits.ADPC15

#define APCTL2_ADPC8_MASK               1
#define APCTL2_ADPC9_MASK               2
#define APCTL2_ADPC10_MASK              4
#define APCTL2_ADPC11_MASK              8
#define APCTL2_ADPC12_MASK              16
#define APCTL2_ADPC13_MASK              32
#define APCTL2_ADPC14_MASK              64
#define APCTL2_ADPC15_MASK              128



typedef union {
  byte Byte;
  struct {
    byte ADPC16      :1;                                       
    byte ADPC17      :1;                                       
    byte ADPC18      :1;                                       
    byte ADPC19      :1;                                       
    byte ADPC20      :1;                                       
    byte ADPC21      :1;                                       
    byte ADPC22      :1;                                       
    byte ADPC23      :1;                                       
  } Bits;
} APCTL3STR;
volatile APCTL3STR __at (0x0019) _APCTL3;
#define APCTL3                          _APCTL3.Byte
#define APCTL3_ADPC16                   _APCTL3.Bits.ADPC16
#define APCTL3_ADPC17                   _APCTL3.Bits.ADPC17
#define APCTL3_ADPC18                   _APCTL3.Bits.ADPC18
#define APCTL3_ADPC19                   _APCTL3.Bits.ADPC19
#define APCTL3_ADPC20                   _APCTL3.Bits.ADPC20
#define APCTL3_ADPC21                   _APCTL3.Bits.ADPC21
#define APCTL3_ADPC22                   _APCTL3.Bits.ADPC22
#define APCTL3_ADPC23                   _APCTL3.Bits.ADPC23

#define APCTL3_ADPC16_MASK              1
#define APCTL3_ADPC17_MASK              2
#define APCTL3_ADPC18_MASK              4
#define APCTL3_ADPC19_MASK              8
#define APCTL3_ADPC20_MASK              16
#define APCTL3_ADPC21_MASK              32
#define APCTL3_ADPC22_MASK              64
#define APCTL3_ADPC23_MASK              128



typedef union {
  byte Byte;
  struct {
    byte IRQMOD      :1;                                       
    byte IRQIE       :1;                                       
    byte IRQACK      :1;                                       
    byte IRQF        :1;                                       
    byte IRQPE       :1;                                       
    byte IRQEDG      :1;                                       
    byte IRQPDD      :1;                                       
    byte             :1; 
  } Bits;
} IRQSCSTR;
volatile IRQSCSTR __at (0x001C) _IRQSC;
#define IRQSC                           _IRQSC.Byte
#define IRQSC_IRQMOD                    _IRQSC.Bits.IRQMOD
#define IRQSC_IRQIE                     _IRQSC.Bits.IRQIE
#define IRQSC_IRQACK                    _IRQSC.Bits.IRQACK
#define IRQSC_IRQF                      _IRQSC.Bits.IRQF
#define IRQSC_IRQPE                     _IRQSC.Bits.IRQPE
#define IRQSC_IRQEDG                    _IRQSC.Bits.IRQEDG
#define IRQSC_IRQPDD                    _IRQSC.Bits.IRQPDD

#define IRQSC_IRQMOD_MASK               1
#define IRQSC_IRQIE_MASK                2
#define IRQSC_IRQACK_MASK               4
#define IRQSC_IRQF_MASK                 8
#define IRQSC_IRQPE_MASK                16
#define IRQSC_IRQEDG_MASK               32
#define IRQSC_IRQPDD_MASK               64



typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       
    byte PS1         :1;                                       
    byte PS2         :1;                                       
    byte CLKSA       :1;                                       
    byte CLKSB       :1;                                       
    byte CPWMS       :1;                                       
    byte TOIE        :1;                                       
    byte TOF         :1;                                       
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKSx :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1SCSTR;
volatile TPM1SCSTR __at (0x0020) _TPM1SC;
#define TPM1SC                          _TPM1SC.Byte
#define TPM1SC_PS0                      _TPM1SC.Bits.PS0
#define TPM1SC_PS1                      _TPM1SC.Bits.PS1
#define TPM1SC_PS2                      _TPM1SC.Bits.PS2
#define TPM1SC_CLKSA                    _TPM1SC.Bits.CLKSA
#define TPM1SC_CLKSB                    _TPM1SC.Bits.CLKSB
#define TPM1SC_CPWMS                    _TPM1SC.Bits.CPWMS
#define TPM1SC_TOIE                     _TPM1SC.Bits.TOIE
#define TPM1SC_TOF                      _TPM1SC.Bits.TOF
#define TPM1SC_PS                       _TPM1SC.MergedBits.grpPS
#define TPM1SC_CLKSx                    _TPM1SC.MergedBits.grpCLKSx

#define TPM1SC_PS0_MASK                 1
#define TPM1SC_PS1_MASK                 2
#define TPM1SC_PS2_MASK                 4
#define TPM1SC_CLKSA_MASK               8
#define TPM1SC_CLKSB_MASK               16
#define TPM1SC_CPWMS_MASK               32
#define TPM1SC_TOIE_MASK                64
#define TPM1SC_TOF_MASK                 128
#define TPM1SC_PS_MASK                  7
#define TPM1SC_PS_BITNUM                0
#define TPM1SC_CLKSx_MASK               24
#define TPM1SC_CLKSx_BITNUM             3



typedef union {
  word Word;
   
  struct {
    
    union {
      byte Byte;
    } TPM1CNTHSTR;
    #define TPM1CNTH                    _TPM1CNT.Overlap_STR.TPM1CNTHSTR.Byte
    
    


    
    union {
      byte Byte;
    } TPM1CNTLSTR;
    #define TPM1CNTL                    _TPM1CNT.Overlap_STR.TPM1CNTLSTR.Byte
    
    

  } Overlap_STR;

} TPM1CNTSTR;
volatile TPM1CNTSTR __at (0x0021) _TPM1CNT;
#define TPM1CNT                         _TPM1CNT.Word




typedef union {
  word Word;
   
  struct {
    
    union {
      byte Byte;
    } TPM1MODHSTR;
    #define TPM1MODH                    _TPM1MOD.Overlap_STR.TPM1MODHSTR.Byte
    
    


    
    union {
      byte Byte;
    } TPM1MODLSTR;
    #define TPM1MODL                    _TPM1MOD.Overlap_STR.TPM1MODLSTR.Byte
    
    

  } Overlap_STR;

} TPM1MODSTR;
volatile TPM1MODSTR __at (0x0023) _TPM1MOD;
#define TPM1MOD                         _TPM1MOD.Word




typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS0A       :1;                                       
    byte ELS0B       :1;                                       
    byte MS0A        :1;                                       
    byte MS0B        :1;                                       
    byte CH0IE       :1;                                       
    byte CH0F        :1;                                       
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS0x :2;
    byte grpMS0x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1C0SCSTR;
volatile TPM1C0SCSTR __at (0x0025) _TPM1C0SC;
#define TPM1C0SC                        _TPM1C0SC.Byte
#define TPM1C0SC_ELS0A                  _TPM1C0SC.Bits.ELS0A
#define TPM1C0SC_ELS0B                  _TPM1C0SC.Bits.ELS0B
#define TPM1C0SC_MS0A                   _TPM1C0SC.Bits.MS0A
#define TPM1C0SC_MS0B                   _TPM1C0SC.Bits.MS0B
#define TPM1C0SC_CH0IE                  _TPM1C0SC.Bits.CH0IE
#define TPM1C0SC_CH0F                   _TPM1C0SC.Bits.CH0F
#define TPM1C0SC_ELS0x                  _TPM1C0SC.MergedBits.grpELS0x
#define TPM1C0SC_MS0x                   _TPM1C0SC.MergedBits.grpMS0x

#define TPM1C0SC_ELS0A_MASK             4
#define TPM1C0SC_ELS0B_MASK             8
#define TPM1C0SC_MS0A_MASK              16
#define TPM1C0SC_MS0B_MASK              32
#define TPM1C0SC_CH0IE_MASK             64
#define TPM1C0SC_CH0F_MASK              128
#define TPM1C0SC_ELS0x_MASK             12
#define TPM1C0SC_ELS0x_BITNUM           2
#define TPM1C0SC_MS0x_MASK              48
#define TPM1C0SC_MS0x_BITNUM            4



typedef union {
  word Word;
   
  struct {
    
    union {
      byte Byte;
    } TPM1C0VHSTR;
    #define TPM1C0VH                    _TPM1C0V.Overlap_STR.TPM1C0VHSTR.Byte
    
    


    
    union {
      byte Byte;
    } TPM1C0VLSTR;
    #define TPM1C0VL                    _TPM1C0V.Overlap_STR.TPM1C0VLSTR.Byte
    
    

  } Overlap_STR;

} TPM1C0VSTR;
volatile TPM1C0VSTR __at (0x0026) _TPM1C0V;
#define TPM1C0V                         _TPM1C0V.Word




typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS1A       :1;                                       
    byte ELS1B       :1;                                       
    byte MS1A        :1;                                       
    byte MS1B        :1;                                       
    byte CH1IE       :1;                                       
    byte CH1F        :1;                                       
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS1x :2;
    byte grpMS1x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1C1SCSTR;
volatile TPM1C1SCSTR __at (0x0028) _TPM1C1SC;
#define TPM1C1SC                        _TPM1C1SC.Byte
#define TPM1C1SC_ELS1A                  _TPM1C1SC.Bits.ELS1A
#define TPM1C1SC_ELS1B                  _TPM1C1SC.Bits.ELS1B
#define TPM1C1SC_MS1A                   _TPM1C1SC.Bits.MS1A
#define TPM1C1SC_MS1B                   _TPM1C1SC.Bits.MS1B
#define TPM1C1SC_CH1IE                  _TPM1C1SC.Bits.CH1IE
#define TPM1C1SC_CH1F                   _TPM1C1SC.Bits.CH1F
#define TPM1C1SC_ELS1x                  _TPM1C1SC.MergedBits.grpELS1x
#define TPM1C1SC_MS1x                   _TPM1C1SC.MergedBits.grpMS1x

#define TPM1C1SC_ELS1A_MASK             4
#define TPM1C1SC_ELS1B_MASK             8
#define TPM1C1SC_MS1A_MASK              16
#define TPM1C1SC_MS1B_MASK              32
#define TPM1C1SC_CH1IE_MASK             64
#define TPM1C1SC_CH1F_MASK              128
#define TPM1C1SC_ELS1x_MASK             12
#define TPM1C1SC_ELS1x_BITNUM           2
#define TPM1C1SC_MS1x_MASK              48
#define TPM1C1SC_MS1x_BITNUM            4



typedef union {
  word Word;
   
  struct {
    
    union {
      byte Byte;
    } TPM1C1VHSTR;
    #define TPM1C1VH                    _TPM1C1V.Overlap_STR.TPM1C1VHSTR.Byte
    
    


    
    union {
      byte Byte;
    } TPM1C1VLSTR;
    #define TPM1C1VL                    _TPM1C1V.Overlap_STR.TPM1C1VLSTR.Byte
    
    

  } Overlap_STR;

} TPM1C1VSTR;
volatile TPM1C1VSTR __at (0x0029) _TPM1C1V;
#define TPM1C1V                         _TPM1C1V.Word




typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS2A       :1;                                       
    byte ELS2B       :1;                                       
    byte MS2A        :1;                                       
    byte MS2B        :1;                                       
    byte CH2IE       :1;                                       
    byte CH2F        :1;                                       
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS2x :2;
    byte grpMS2x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1C2SCSTR;
volatile TPM1C2SCSTR __at (0x002B) _TPM1C2SC;
#define TPM1C2SC                        _TPM1C2SC.Byte
#define TPM1C2SC_ELS2A                  _TPM1C2SC.Bits.ELS2A
#define TPM1C2SC_ELS2B                  _TPM1C2SC.Bits.ELS2B
#define TPM1C2SC_MS2A                   _TPM1C2SC.Bits.MS2A
#define TPM1C2SC_MS2B                   _TPM1C2SC.Bits.MS2B
#define TPM1C2SC_CH2IE                  _TPM1C2SC.Bits.CH2IE
#define TPM1C2SC_CH2F                   _TPM1C2SC.Bits.CH2F
#define TPM1C2SC_ELS2x                  _TPM1C2SC.MergedBits.grpELS2x
#define TPM1C2SC_MS2x                   _TPM1C2SC.MergedBits.grpMS2x

#define TPM1C2SC_ELS2A_MASK             4
#define TPM1C2SC_ELS2B_MASK             8
#define TPM1C2SC_MS2A_MASK              16
#define TPM1C2SC_MS2B_MASK              32
#define TPM1C2SC_CH2IE_MASK             64
#define TPM1C2SC_CH2F_MASK              128
#define TPM1C2SC_ELS2x_MASK             12
#define TPM1C2SC_ELS2x_BITNUM           2
#define TPM1C2SC_MS2x_MASK              48
#define TPM1C2SC_MS2x_BITNUM            4



typedef union {
  word Word;
   
  struct {
    
    union {
      byte Byte;
    } TPM1C2VHSTR;
    #define TPM1C2VH                    _TPM1C2V.Overlap_STR.TPM1C2VHSTR.Byte
    
    


    
    union {
      byte Byte;
    } TPM1C2VLSTR;
    #define TPM1C2VL                    _TPM1C2V.Overlap_STR.TPM1C2VLSTR.Byte
    
    

  } Overlap_STR;

} TPM1C2VSTR;
volatile TPM1C2VSTR __at (0x002C) _TPM1C2V;
#define TPM1C2V                         _TPM1C2V.Word




typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS3A       :1;                                       
    byte ELS3B       :1;                                       
    byte MS3A        :1;                                       
    byte MS3B        :1;                                       
    byte CH3IE       :1;                                       
    byte CH3F        :1;                                       
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS3x :2;
    byte grpMS3x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1C3SCSTR;
volatile TPM1C3SCSTR __at (0x002E) _TPM1C3SC;
#define TPM1C3SC                        _TPM1C3SC.Byte
#define TPM1C3SC_ELS3A                  _TPM1C3SC.Bits.ELS3A
#define TPM1C3SC_ELS3B                  _TPM1C3SC.Bits.ELS3B
#define TPM1C3SC_MS3A                   _TPM1C3SC.Bits.MS3A
#define TPM1C3SC_MS3B                   _TPM1C3SC.Bits.MS3B
#define TPM1C3SC_CH3IE                  _TPM1C3SC.Bits.CH3IE
#define TPM1C3SC_CH3F                   _TPM1C3SC.Bits.CH3F
#define TPM1C3SC_ELS3x                  _TPM1C3SC.MergedBits.grpELS3x
#define TPM1C3SC_MS3x                   _TPM1C3SC.MergedBits.grpMS3x

#define TPM1C3SC_ELS3A_MASK             4
#define TPM1C3SC_ELS3B_MASK             8
#define TPM1C3SC_MS3A_MASK              16
#define TPM1C3SC_MS3B_MASK              32
#define TPM1C3SC_CH3IE_MASK             64
#define TPM1C3SC_CH3F_MASK              128
#define TPM1C3SC_ELS3x_MASK             12
#define TPM1C3SC_ELS3x_BITNUM           2
#define TPM1C3SC_MS3x_MASK              48
#define TPM1C3SC_MS3x_BITNUM            4



typedef union {
  word Word;
   
  struct {
    
    union {
      byte Byte;
    } TPM1C3VHSTR;
    #define TPM1C3VH                    _TPM1C3V.Overlap_STR.TPM1C3VHSTR.Byte
    
    


    
    union {
      byte Byte;
    } TPM1C3VLSTR;
    #define TPM1C3VL                    _TPM1C3V.Overlap_STR.TPM1C3VLSTR.Byte
    
    

  } Overlap_STR;

} TPM1C3VSTR;
volatile TPM1C3VSTR __at (0x002F) _TPM1C3V;
#define TPM1C3V                         _TPM1C3V.Word




typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS4A       :1;                                       
    byte ELS4B       :1;                                       
    byte MS4A        :1;                                       
    byte MS4B        :1;                                       
    byte CH4IE       :1;                                       
    byte CH4F        :1;                                       
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS4x :2;
    byte grpMS4x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1C4SCSTR;
volatile TPM1C4SCSTR __at (0x0031) _TPM1C4SC;
#define TPM1C4SC                        _TPM1C4SC.Byte
#define TPM1C4SC_ELS4A                  _TPM1C4SC.Bits.ELS4A
#define TPM1C4SC_ELS4B                  _TPM1C4SC.Bits.ELS4B
#define TPM1C4SC_MS4A                   _TPM1C4SC.Bits.MS4A
#define TPM1C4SC_MS4B                   _TPM1C4SC.Bits.MS4B
#define TPM1C4SC_CH4IE                  _TPM1C4SC.Bits.CH4IE
#define TPM1C4SC_CH4F                   _TPM1C4SC.Bits.CH4F
#define TPM1C4SC_ELS4x                  _TPM1C4SC.MergedBits.grpELS4x
#define TPM1C4SC_MS4x                   _TPM1C4SC.MergedBits.grpMS4x

#define TPM1C4SC_ELS4A_MASK             4
#define TPM1C4SC_ELS4B_MASK             8
#define TPM1C4SC_MS4A_MASK              16
#define TPM1C4SC_MS4B_MASK              32
#define TPM1C4SC_CH4IE_MASK             64
#define TPM1C4SC_CH4F_MASK              128
#define TPM1C4SC_ELS4x_MASK             12
#define TPM1C4SC_ELS4x_BITNUM           2
#define TPM1C4SC_MS4x_MASK              48
#define TPM1C4SC_MS4x_BITNUM            4



typedef union {
  word Word;
   
  struct {
    
    union {
      byte Byte;
    } TPM1C4VHSTR;
    #define TPM1C4VH                    _TPM1C4V.Overlap_STR.TPM1C4VHSTR.Byte
    
    


    
    union {
      byte Byte;
    } TPM1C4VLSTR;
    #define TPM1C4VL                    _TPM1C4V.Overlap_STR.TPM1C4VLSTR.Byte
    
    

  } Overlap_STR;

} TPM1C4VSTR;
volatile TPM1C4VSTR __at (0x0032) _TPM1C4V;
#define TPM1C4V                         _TPM1C4V.Word




typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS5A       :1;                                       
    byte ELS5B       :1;                                       
    byte MS5A        :1;                                       
    byte MS5B        :1;                                       
    byte CH5IE       :1;                                       
    byte CH5F        :1;                                       
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS5x :2;
    byte grpMS5x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1C5SCSTR;
volatile TPM1C5SCSTR __at (0x0034) _TPM1C5SC;
#define TPM1C5SC                        _TPM1C5SC.Byte
#define TPM1C5SC_ELS5A                  _TPM1C5SC.Bits.ELS5A
#define TPM1C5SC_ELS5B                  _TPM1C5SC.Bits.ELS5B
#define TPM1C5SC_MS5A                   _TPM1C5SC.Bits.MS5A
#define TPM1C5SC_MS5B                   _TPM1C5SC.Bits.MS5B
#define TPM1C5SC_CH5IE                  _TPM1C5SC.Bits.CH5IE
#define TPM1C5SC_CH5F                   _TPM1C5SC.Bits.CH5F
#define TPM1C5SC_ELS5x                  _TPM1C5SC.MergedBits.grpELS5x
#define TPM1C5SC_MS5x                   _TPM1C5SC.MergedBits.grpMS5x

#define TPM1C5SC_ELS5A_MASK             4
#define TPM1C5SC_ELS5B_MASK             8
#define TPM1C5SC_MS5A_MASK              16
#define TPM1C5SC_MS5B_MASK              32
#define TPM1C5SC_CH5IE_MASK             64
#define TPM1C5SC_CH5F_MASK              128
#define TPM1C5SC_ELS5x_MASK             12
#define TPM1C5SC_ELS5x_BITNUM           2
#define TPM1C5SC_MS5x_MASK              48
#define TPM1C5SC_MS5x_BITNUM            4



typedef union {
  word Word;
   
  struct {
    
    union {
      byte Byte;
    } TPM1C5VHSTR;
    #define TPM1C5VH                    _TPM1C5V.Overlap_STR.TPM1C5VHSTR.Byte
    
    


    
    union {
      byte Byte;
    } TPM1C5VLSTR;
    #define TPM1C5VL                    _TPM1C5V.Overlap_STR.TPM1C5VLSTR.Byte
    
    

  } Overlap_STR;

} TPM1C5VSTR;
volatile TPM1C5VSTR __at (0x0035) _TPM1C5V;
#define TPM1C5V                         _TPM1C5V.Word




typedef union {
  word Word;
   
  struct {
    
    union {
      byte Byte;
      struct {
        byte SBR8        :1;                                       
        byte SBR9        :1;                                       
        byte SBR10       :1;                                       
        byte SBR11       :1;                                       
        byte SBR12       :1;                                       
        byte             :1; 
        byte RXEDGIE     :1;                                       
        byte LBKDIE      :1;                                       
      } Bits;
      struct {
        byte grpSBR_8 :5;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SCI1BDHSTR;
    #define SCI1BDH                     _SCI1BD.Overlap_STR.SCI1BDHSTR.Byte
    #define SCI1BDH_SBR8                _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR8
    #define SCI1BDH_SBR9                _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR9
    #define SCI1BDH_SBR10               _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR10
    #define SCI1BDH_SBR11               _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR11
    #define SCI1BDH_SBR12               _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR12
    #define SCI1BDH_RXEDGIE             _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.RXEDGIE
    #define SCI1BDH_LBKDIE              _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.LBKDIE
    
    #define SCI1BDH_SBR_8               _SCI1BD.Overlap_STR.SCI1BDHSTR.MergedBits.grpSBR_8
    #define SCI1BDH_SBR                 SCI1BDH_SBR_8
    
    #define SCI1BDH_SBR8_MASK           1
    #define SCI1BDH_SBR9_MASK           2
    #define SCI1BDH_SBR10_MASK          4
    #define SCI1BDH_SBR11_MASK          8
    #define SCI1BDH_SBR12_MASK          16
    #define SCI1BDH_RXEDGIE_MASK        64
    #define SCI1BDH_LBKDIE_MASK         128
    #define SCI1BDH_SBR_8_MASK          31
    #define SCI1BDH_SBR_8_BITNUM        0


    
    union {
      byte Byte;
      struct {
        byte SBR0        :1;                                       
        byte SBR1        :1;                                       
        byte SBR2        :1;                                       
        byte SBR3        :1;                                       
        byte SBR4        :1;                                       
        byte SBR5        :1;                                       
        byte SBR6        :1;                                       
        byte SBR7        :1;                                       
      } Bits;
    } SCI1BDLSTR;
    #define SCI1BDL                     _SCI1BD.Overlap_STR.SCI1BDLSTR.Byte
    #define SCI1BDL_SBR0                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR0
    #define SCI1BDL_SBR1                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR1
    #define SCI1BDL_SBR2                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR2
    #define SCI1BDL_SBR3                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR3
    #define SCI1BDL_SBR4                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR4
    #define SCI1BDL_SBR5                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR5
    #define SCI1BDL_SBR6                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR6
    #define SCI1BDL_SBR7                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR7
    
    
    #define SCI1BDL_SBR0_MASK           1
    #define SCI1BDL_SBR1_MASK           2
    #define SCI1BDL_SBR2_MASK           4
    #define SCI1BDL_SBR3_MASK           8
    #define SCI1BDL_SBR4_MASK           16
    #define SCI1BDL_SBR5_MASK           32
    #define SCI1BDL_SBR6_MASK           64
    #define SCI1BDL_SBR7_MASK           128

  } Overlap_STR;

} SCI1BDSTR;
volatile SCI1BDSTR __at (0x0038) _SCI1BD;
#define SCI1BD                          _SCI1BD.Word




typedef union {
  byte Byte;
  struct {
    byte PT          :1;                                       
    byte PE          :1;                                       
    byte ILT         :1;                                       
    byte WAKE        :1;                                       
    byte M           :1;                                       
    byte RSRC        :1;                                       
    byte SCISWAI     :1;                                       
    byte LOOPS       :1;                                       
  } Bits;
} SCI1C1STR;
volatile SCI1C1STR __at (0x003A) _SCI1C1;
#define SCI1C1                          _SCI1C1.Byte
#define SCI1C1_PT                       _SCI1C1.Bits.PT
#define SCI1C1_PE                       _SCI1C1.Bits.PE
#define SCI1C1_ILT                      _SCI1C1.Bits.ILT
#define SCI1C1_WAKE                     _SCI1C1.Bits.WAKE
#define SCI1C1_M                        _SCI1C1.Bits.M
#define SCI1C1_RSRC                     _SCI1C1.Bits.RSRC
#define SCI1C1_SCISWAI                  _SCI1C1.Bits.SCISWAI
#define SCI1C1_LOOPS                    _SCI1C1.Bits.LOOPS

#define SCI1C1_PT_MASK                  1
#define SCI1C1_PE_MASK                  2
#define SCI1C1_ILT_MASK                 4
#define SCI1C1_WAKE_MASK                8
#define SCI1C1_M_MASK                   16
#define SCI1C1_RSRC_MASK                32
#define SCI1C1_SCISWAI_MASK             64
#define SCI1C1_LOOPS_MASK               128



typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       
    byte RWU         :1;                                       
    byte RE          :1;                                       
    byte TE          :1;                                       
    byte ILIE        :1;                                       
    byte RIE         :1;                                       
    byte TCIE        :1;                                       
    byte TIE         :1;                                       
  } Bits;
} SCI1C2STR;
volatile SCI1C2STR __at (0x003B) _SCI1C2;
#define SCI1C2                          _SCI1C2.Byte
#define SCI1C2_SBK                      _SCI1C2.Bits.SBK
#define SCI1C2_RWU                      _SCI1C2.Bits.RWU
#define SCI1C2_RE                       _SCI1C2.Bits.RE
#define SCI1C2_TE                       _SCI1C2.Bits.TE
#define SCI1C2_ILIE                     _SCI1C2.Bits.ILIE
#define SCI1C2_RIE                      _SCI1C2.Bits.RIE
#define SCI1C2_TCIE                     _SCI1C2.Bits.TCIE
#define SCI1C2_TIE                      _SCI1C2.Bits.TIE

#define SCI1C2_SBK_MASK                 1
#define SCI1C2_RWU_MASK                 2
#define SCI1C2_RE_MASK                  4
#define SCI1C2_TE_MASK                  8
#define SCI1C2_ILIE_MASK                16
#define SCI1C2_RIE_MASK                 32
#define SCI1C2_TCIE_MASK                64
#define SCI1C2_TIE_MASK                 128



typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       
    byte FE          :1;                                       
    byte NF          :1;                                       
    byte OR          :1;                                       
    byte IDLE        :1;                                       
    byte RDRF        :1;                                       
    byte TC          :1;                                       
    byte TDRE        :1;                                       
  } Bits;
} SCI1S1STR;
volatile SCI1S1STR __at (0x003C) _SCI1S1;
#define SCI1S1                          _SCI1S1.Byte
#define SCI1S1_PF                       _SCI1S1.Bits.PF
#define SCI1S1_FE                       _SCI1S1.Bits.FE
#define SCI1S1_NF                       _SCI1S1.Bits.NF
#define SCI1S1_OR                       _SCI1S1.Bits.OR
#define SCI1S1_IDLE                     _SCI1S1.Bits.IDLE
#define SCI1S1_RDRF                     _SCI1S1.Bits.RDRF
#define SCI1S1_TC                       _SCI1S1.Bits.TC
#define SCI1S1_TDRE                     _SCI1S1.Bits.TDRE

#define SCI1S1_PF_MASK                  1
#define SCI1S1_FE_MASK                  2
#define SCI1S1_NF_MASK                  4
#define SCI1S1_OR_MASK                  8
#define SCI1S1_IDLE_MASK                16
#define SCI1S1_RDRF_MASK                32
#define SCI1S1_TC_MASK                  64
#define SCI1S1_TDRE_MASK                128



typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       
    byte LBKDE       :1;                                       
    byte BRK13       :1;                                       
    byte RWUID       :1;                                       
    byte RXINV       :1;                                       
    byte             :1; 
    byte RXEDGIF     :1;                                       
    byte LBKDIF      :1;                                       
  } Bits;
} SCI1S2STR;
volatile SCI1S2STR __at (0x003D) _SCI1S2;
#define SCI1S2                          _SCI1S2.Byte
#define SCI1S2_RAF                      _SCI1S2.Bits.RAF
#define SCI1S2_LBKDE                    _SCI1S2.Bits.LBKDE
#define SCI1S2_BRK13                    _SCI1S2.Bits.BRK13
#define SCI1S2_RWUID                    _SCI1S2.Bits.RWUID
#define SCI1S2_RXINV                    _SCI1S2.Bits.RXINV
#define SCI1S2_RXEDGIF                  _SCI1S2.Bits.RXEDGIF
#define SCI1S2_LBKDIF                   _SCI1S2.Bits.LBKDIF

#define SCI1S2_RAF_MASK                 1
#define SCI1S2_LBKDE_MASK               2
#define SCI1S2_BRK13_MASK               4
#define SCI1S2_RWUID_MASK               8
#define SCI1S2_RXINV_MASK               16
#define SCI1S2_RXEDGIF_MASK             64
#define SCI1S2_LBKDIF_MASK              128



typedef union {
  byte Byte;
  struct {
    byte PEIE        :1;                                       
    byte FEIE        :1;                                       
    byte NEIE        :1;                                       
    byte ORIE        :1;                                       
    byte TXINV       :1;                                       
    byte TXDIR       :1;                                       
    byte T8          :1;                                       
    byte R8          :1;                                       
  } Bits;
} SCI1C3STR;
volatile SCI1C3STR __at (0x003E) _SCI1C3;
#define SCI1C3                          _SCI1C3.Byte
#define SCI1C3_PEIE                     _SCI1C3.Bits.PEIE
#define SCI1C3_FEIE                     _SCI1C3.Bits.FEIE
#define SCI1C3_NEIE                     _SCI1C3.Bits.NEIE
#define SCI1C3_ORIE                     _SCI1C3.Bits.ORIE
#define SCI1C3_TXINV                    _SCI1C3.Bits.TXINV
#define SCI1C3_TXDIR                    _SCI1C3.Bits.TXDIR
#define SCI1C3_T8                       _SCI1C3.Bits.T8
#define SCI1C3_R8                       _SCI1C3.Bits.R8

#define SCI1C3_PEIE_MASK                1
#define SCI1C3_FEIE_MASK                2
#define SCI1C3_NEIE_MASK                4
#define SCI1C3_ORIE_MASK                8
#define SCI1C3_TXINV_MASK               16
#define SCI1C3_TXDIR_MASK               32
#define SCI1C3_T8_MASK                  64
#define SCI1C3_R8_MASK                  128



typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       
    byte R1_T1       :1;                                       
    byte R2_T2       :1;                                       
    byte R3_T3       :1;                                       
    byte R4_T4       :1;                                       
    byte R5_T5       :1;                                       
    byte R6_T6       :1;                                       
    byte R7_T7       :1;                                       
  } Bits;
} SCI1DSTR;
volatile SCI1DSTR __at (0x003F) _SCI1D;
#define SCI1D                           _SCI1D.Byte
#define SCI1D_R0_T0                     _SCI1D.Bits.R0_T0
#define SCI1D_R1_T1                     _SCI1D.Bits.R1_T1
#define SCI1D_R2_T2                     _SCI1D.Bits.R2_T2
#define SCI1D_R3_T3                     _SCI1D.Bits.R3_T3
#define SCI1D_R4_T4                     _SCI1D.Bits.R4_T4
#define SCI1D_R5_T5                     _SCI1D.Bits.R5_T5
#define SCI1D_R6_T6                     _SCI1D.Bits.R6_T6
#define SCI1D_R7_T7                     _SCI1D.Bits.R7_T7

#define SCI1D_R0_T0_MASK                1
#define SCI1D_R1_T1_MASK                2
#define SCI1D_R2_T2_MASK                4
#define SCI1D_R3_T3_MASK                8
#define SCI1D_R4_T4_MASK                16
#define SCI1D_R5_T5_MASK                32
#define SCI1D_R6_T6_MASK                64
#define SCI1D_R7_T7_MASK                128



typedef union {
  word Word;
   
  struct {
    
    union {
      byte Byte;
      struct {
        byte SBR8        :1;                                       
        byte SBR9        :1;                                       
        byte SBR10       :1;                                       
        byte SBR11       :1;                                       
        byte SBR12       :1;                                       
        byte             :1; 
        byte RXEDGIE     :1;                                       
        byte LBKDIE      :1;                                       
      } Bits;
      struct {
        byte grpSBR_8 :5;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SCI2BDHSTR;
    #define SCI2BDH                     _SCI2BD.Overlap_STR.SCI2BDHSTR.Byte
    #define SCI2BDH_SBR8                _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.SBR8
    #define SCI2BDH_SBR9                _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.SBR9
    #define SCI2BDH_SBR10               _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.SBR10
    #define SCI2BDH_SBR11               _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.SBR11
    #define SCI2BDH_SBR12               _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.SBR12
    #define SCI2BDH_RXEDGIE             _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.RXEDGIE
    #define SCI2BDH_LBKDIE              _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.LBKDIE
    
    #define SCI2BDH_SBR_8               _SCI2BD.Overlap_STR.SCI2BDHSTR.MergedBits.grpSBR_8
    #define SCI2BDH_SBR                 SCI2BDH_SBR_8
    
    #define SCI2BDH_SBR8_MASK           1
    #define SCI2BDH_SBR9_MASK           2
    #define SCI2BDH_SBR10_MASK          4
    #define SCI2BDH_SBR11_MASK          8
    #define SCI2BDH_SBR12_MASK          16
    #define SCI2BDH_RXEDGIE_MASK        64
    #define SCI2BDH_LBKDIE_MASK         128
    #define SCI2BDH_SBR_8_MASK          31
    #define SCI2BDH_SBR_8_BITNUM        0


    
    union {
      byte Byte;
      struct {
        byte SBR0        :1;                                       
        byte SBR1        :1;                                       
        byte SBR2        :1;                                       
        byte SBR3        :1;                                       
        byte SBR4        :1;                                       
        byte SBR5        :1;                                       
        byte SBR6        :1;                                       
        byte SBR7        :1;                                       
      } Bits;
    } SCI2BDLSTR;
    #define SCI2BDL                     _SCI2BD.Overlap_STR.SCI2BDLSTR.Byte
    #define SCI2BDL_SBR0                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR0
    #define SCI2BDL_SBR1                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR1
    #define SCI2BDL_SBR2                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR2
    #define SCI2BDL_SBR3                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR3
    #define SCI2BDL_SBR4                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR4
    #define SCI2BDL_SBR5                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR5
    #define SCI2BDL_SBR6                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR6
    #define SCI2BDL_SBR7                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR7
    
    
    #define SCI2BDL_SBR0_MASK           1
    #define SCI2BDL_SBR1_MASK           2
    #define SCI2BDL_SBR2_MASK           4
    #define SCI2BDL_SBR3_MASK           8
    #define SCI2BDL_SBR4_MASK           16
    #define SCI2BDL_SBR5_MASK           32
    #define SCI2BDL_SBR6_MASK           64
    #define SCI2BDL_SBR7_MASK           128

  } Overlap_STR;

} SCI2BDSTR;
volatile SCI2BDSTR __at (0x0040) _SCI2BD;
#define SCI2BD                          _SCI2BD.Word




typedef union {
  byte Byte;
  struct {
    byte PT          :1;                                       
    byte PE          :1;                                       
    byte ILT         :1;                                       
    byte WAKE        :1;                                       
    byte M           :1;                                       
    byte RSRC        :1;                                       
    byte SCISWAI     :1;                                       
    byte LOOPS       :1;                                       
  } Bits;
} SCI2C1STR;
volatile SCI2C1STR __at (0x0042) _SCI2C1;
#define SCI2C1                          _SCI2C1.Byte
#define SCI2C1_PT                       _SCI2C1.Bits.PT
#define SCI2C1_PE                       _SCI2C1.Bits.PE
#define SCI2C1_ILT                      _SCI2C1.Bits.ILT
#define SCI2C1_WAKE                     _SCI2C1.Bits.WAKE
#define SCI2C1_M                        _SCI2C1.Bits.M
#define SCI2C1_RSRC                     _SCI2C1.Bits.RSRC
#define SCI2C1_SCISWAI                  _SCI2C1.Bits.SCISWAI
#define SCI2C1_LOOPS                    _SCI2C1.Bits.LOOPS

#define SCI2C1_PT_MASK                  1
#define SCI2C1_PE_MASK                  2
#define SCI2C1_ILT_MASK                 4
#define SCI2C1_WAKE_MASK                8
#define SCI2C1_M_MASK                   16
#define SCI2C1_RSRC_MASK                32
#define SCI2C1_SCISWAI_MASK             64
#define SCI2C1_LOOPS_MASK               128



typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       
    byte RWU         :1;                                       
    byte RE          :1;                                       
    byte TE          :1;                                       
    byte ILIE        :1;                                       
    byte RIE         :1;                                       
    byte TCIE        :1;                                       
    byte TIE         :1;                                       
  } Bits;
} SCI2C2STR;
volatile SCI2C2STR __at (0x0043) _SCI2C2;
#define SCI2C2                          _SCI2C2.Byte
#define SCI2C2_SBK                      _SCI2C2.Bits.SBK
#define SCI2C2_RWU                      _SCI2C2.Bits.RWU
#define SCI2C2_RE                       _SCI2C2.Bits.RE
#define SCI2C2_TE                       _SCI2C2.Bits.TE
#define SCI2C2_ILIE                     _SCI2C2.Bits.ILIE
#define SCI2C2_RIE                      _SCI2C2.Bits.RIE
#define SCI2C2_TCIE                     _SCI2C2.Bits.TCIE
#define SCI2C2_TIE                      _SCI2C2.Bits.TIE

#define SCI2C2_SBK_MASK                 1
#define SCI2C2_RWU_MASK                 2
#define SCI2C2_RE_MASK                  4
#define SCI2C2_TE_MASK                  8
#define SCI2C2_ILIE_MASK                16
#define SCI2C2_RIE_MASK                 32
#define SCI2C2_TCIE_MASK                64
#define SCI2C2_TIE_MASK                 128



typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       
    byte FE          :1;                                       
    byte NF          :1;                                       
    byte OR          :1;                                       
    byte IDLE        :1;                                       
    byte RDRF        :1;                                       
    byte TC          :1;                                       
    byte TDRE        :1;                                       
  } Bits;
} SCI2S1STR;
volatile SCI2S1STR __at (0x0044) _SCI2S1;
#define SCI2S1                          _SCI2S1.Byte
#define SCI2S1_PF                       _SCI2S1.Bits.PF
#define SCI2S1_FE                       _SCI2S1.Bits.FE
#define SCI2S1_NF                       _SCI2S1.Bits.NF
#define SCI2S1_OR                       _SCI2S1.Bits.OR
#define SCI2S1_IDLE                     _SCI2S1.Bits.IDLE
#define SCI2S1_RDRF                     _SCI2S1.Bits.RDRF
#define SCI2S1_TC                       _SCI2S1.Bits.TC
#define SCI2S1_TDRE                     _SCI2S1.Bits.TDRE

#define SCI2S1_PF_MASK                  1
#define SCI2S1_FE_MASK                  2
#define SCI2S1_NF_MASK                  4
#define SCI2S1_OR_MASK                  8
#define SCI2S1_IDLE_MASK                16
#define SCI2S1_RDRF_MASK                32
#define SCI2S1_TC_MASK                  64
#define SCI2S1_TDRE_MASK                128



typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       
    byte LBKDE       :1;                                       
    byte BRK13       :1;                                       
    byte RWUID       :1;                                       
    byte RXINV       :1;                                       
    byte             :1; 
    byte RXEDGIF     :1;                                       
    byte LBKDIF      :1;                                       
  } Bits;
} SCI2S2STR;
volatile SCI2S2STR __at (0x0045) _SCI2S2;
#define SCI2S2                          _SCI2S2.Byte
#define SCI2S2_RAF                      _SCI2S2.Bits.RAF
#define SCI2S2_LBKDE                    _SCI2S2.Bits.LBKDE
#define SCI2S2_BRK13                    _SCI2S2.Bits.BRK13
#define SCI2S2_RWUID                    _SCI2S2.Bits.RWUID
#define SCI2S2_RXINV                    _SCI2S2.Bits.RXINV
#define SCI2S2_RXEDGIF                  _SCI2S2.Bits.RXEDGIF
#define SCI2S2_LBKDIF                   _SCI2S2.Bits.LBKDIF

#define SCI2S2_RAF_MASK                 1
#define SCI2S2_LBKDE_MASK               2
#define SCI2S2_BRK13_MASK               4
#define SCI2S2_RWUID_MASK               8
#define SCI2S2_RXINV_MASK               16
#define SCI2S2_RXEDGIF_MASK             64
#define SCI2S2_LBKDIF_MASK              128



typedef union {
  byte Byte;
  struct {
    byte PEIE        :1;                                       
    byte FEIE        :1;                                       
    byte NEIE        :1;                                       
    byte ORIE        :1;                                       
    byte TXINV       :1;                                       
    byte TXDIR       :1;                                       
    byte T8          :1;                                       
    byte R8          :1;                                       
  } Bits;
} SCI2C3STR;
volatile SCI2C3STR __at (0x0046) _SCI2C3;
#define SCI2C3                          _SCI2C3.Byte
#define SCI2C3_PEIE                     _SCI2C3.Bits.PEIE
#define SCI2C3_FEIE                     _SCI2C3.Bits.FEIE
#define SCI2C3_NEIE                     _SCI2C3.Bits.NEIE
#define SCI2C3_ORIE                     _SCI2C3.Bits.ORIE
#define SCI2C3_TXINV                    _SCI2C3.Bits.TXINV
#define SCI2C3_TXDIR                    _SCI2C3.Bits.TXDIR
#define SCI2C3_T8                       _SCI2C3.Bits.T8
#define SCI2C3_R8                       _SCI2C3.Bits.R8

#define SCI2C3_PEIE_MASK                1
#define SCI2C3_FEIE_MASK                2
#define SCI2C3_NEIE_MASK                4
#define SCI2C3_ORIE_MASK                8
#define SCI2C3_TXINV_MASK               16
#define SCI2C3_TXDIR_MASK               32
#define SCI2C3_T8_MASK                  64
#define SCI2C3_R8_MASK                  128



typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       
    byte R1_T1       :1;                                       
    byte R2_T2       :1;                                       
    byte R3_T3       :1;                                       
    byte R4_T4       :1;                                       
    byte R5_T5       :1;                                       
    byte R6_T6       :1;                                       
    byte R7_T7       :1;                                       
  } Bits;
} SCI2DSTR;
volatile SCI2DSTR __at (0x0047) _SCI2D;
#define SCI2D                           _SCI2D.Byte
#define SCI2D_R0_T0                     _SCI2D.Bits.R0_T0
#define SCI2D_R1_T1                     _SCI2D.Bits.R1_T1
#define SCI2D_R2_T2                     _SCI2D.Bits.R2_T2
#define SCI2D_R3_T3                     _SCI2D.Bits.R3_T3
#define SCI2D_R4_T4                     _SCI2D.Bits.R4_T4
#define SCI2D_R5_T5                     _SCI2D.Bits.R5_T5
#define SCI2D_R6_T6                     _SCI2D.Bits.R6_T6
#define SCI2D_R7_T7                     _SCI2D.Bits.R7_T7

#define SCI2D_R0_T0_MASK                1
#define SCI2D_R1_T1_MASK                2
#define SCI2D_R2_T2_MASK                4
#define SCI2D_R3_T3_MASK                8
#define SCI2D_R4_T4_MASK                16
#define SCI2D_R5_T5_MASK                32
#define SCI2D_R6_T6_MASK                64
#define SCI2D_R7_T7_MASK                128



typedef union {
  byte Byte;
  struct {
    byte IREFSTEN    :1;                                       
    byte IRCLKEN     :1;                                       
    byte IREFS       :1;                                       
    byte RDIV0       :1;                                       
    byte RDIV1       :1;                                       
    byte RDIV2       :1;                                       
    byte CLKS0       :1;                                       
    byte CLKS1       :1;                                       
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpRDIV :3;
    byte grpCLKS :2;
  } MergedBits;
} MCGC1STR;
volatile MCGC1STR __at (0x0048) _MCGC1;
#define MCGC1                           _MCGC1.Byte
#define MCGC1_IREFSTEN                  _MCGC1.Bits.IREFSTEN
#define MCGC1_IRCLKEN                   _MCGC1.Bits.IRCLKEN
#define MCGC1_IREFS                     _MCGC1.Bits.IREFS
#define MCGC1_RDIV0                     _MCGC1.Bits.RDIV0
#define MCGC1_RDIV1                     _MCGC1.Bits.RDIV1
#define MCGC1_RDIV2                     _MCGC1.Bits.RDIV2
#define MCGC1_CLKS0                     _MCGC1.Bits.CLKS0
#define MCGC1_CLKS1                     _MCGC1.Bits.CLKS1
#define MCGC1_RDIV                      _MCGC1.MergedBits.grpRDIV
#define MCGC1_CLKS                      _MCGC1.MergedBits.grpCLKS

#define MCGC1_IREFSTEN_MASK             1
#define MCGC1_IRCLKEN_MASK              2
#define MCGC1_IREFS_MASK                4
#define MCGC1_RDIV0_MASK                8
#define MCGC1_RDIV1_MASK                16
#define MCGC1_RDIV2_MASK                32
#define MCGC1_CLKS0_MASK                64
#define MCGC1_CLKS1_MASK                128
#define MCGC1_RDIV_MASK                 56
#define MCGC1_RDIV_BITNUM               3
#define MCGC1_CLKS_MASK                 192
#define MCGC1_CLKS_BITNUM               6



typedef union {
  byte Byte;
  struct {
    byte EREFSTEN    :1;                                       
    byte ERCLKEN     :1;                                       
    byte EREFS       :1;                                       
    byte LP          :1;                                       
    byte HGO         :1;                                       
    byte RANGE       :1;                                       
    byte BDIV0       :1;                                       
    byte BDIV1       :1;                                       
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpBDIV :2;
  } MergedBits;
} MCGC2STR;
volatile MCGC2STR __at (0x0049) _MCGC2;
#define MCGC2                           _MCGC2.Byte
#define MCGC2_EREFSTEN                  _MCGC2.Bits.EREFSTEN
#define MCGC2_ERCLKEN                   _MCGC2.Bits.ERCLKEN
#define MCGC2_EREFS                     _MCGC2.Bits.EREFS
#define MCGC2_LP                        _MCGC2.Bits.LP
#define MCGC2_HGO                       _MCGC2.Bits.HGO
#define MCGC2_RANGE                     _MCGC2.Bits.RANGE
#define MCGC2_BDIV0                     _MCGC2.Bits.BDIV0
#define MCGC2_BDIV1                     _MCGC2.Bits.BDIV1
#define MCGC2_BDIV                      _MCGC2.MergedBits.grpBDIV

#define MCGC2_EREFSTEN_MASK             1
#define MCGC2_ERCLKEN_MASK              2
#define MCGC2_EREFS_MASK                4
#define MCGC2_LP_MASK                   8
#define MCGC2_HGO_MASK                  16
#define MCGC2_RANGE_MASK                32
#define MCGC2_BDIV0_MASK                64
#define MCGC2_BDIV1_MASK                128
#define MCGC2_BDIV_MASK                 192
#define MCGC2_BDIV_BITNUM               6



typedef union {
  byte Byte;
  struct {
    byte TRIM0       :1;                                       
    byte TRIM1       :1;                                       
    byte TRIM2       :1;                                       
    byte TRIM3       :1;                                       
    byte TRIM4       :1;                                       
    byte TRIM5       :1;                                       
    byte TRIM6       :1;                                       
    byte TRIM7       :1;                                       
  } Bits;
} MCGTRMSTR;
volatile MCGTRMSTR __at (0x004A) _MCGTRM;
#define MCGTRM                          _MCGTRM.Byte
#define MCGTRM_TRIM0                    _MCGTRM.Bits.TRIM0
#define MCGTRM_TRIM1                    _MCGTRM.Bits.TRIM1
#define MCGTRM_TRIM2                    _MCGTRM.Bits.TRIM2
#define MCGTRM_TRIM3                    _MCGTRM.Bits.TRIM3
#define MCGTRM_TRIM4                    _MCGTRM.Bits.TRIM4
#define MCGTRM_TRIM5                    _MCGTRM.Bits.TRIM5
#define MCGTRM_TRIM6                    _MCGTRM.Bits.TRIM6
#define MCGTRM_TRIM7                    _MCGTRM.Bits.TRIM7

#define MCGTRM_TRIM0_MASK               1
#define MCGTRM_TRIM1_MASK               2
#define MCGTRM_TRIM2_MASK               4
#define MCGTRM_TRIM3_MASK               8
#define MCGTRM_TRIM4_MASK               16
#define MCGTRM_TRIM5_MASK               32
#define MCGTRM_TRIM6_MASK               64
#define MCGTRM_TRIM7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte FTRIM       :1;                                       
    byte OSCINIT     :1;                                       
    byte CLKST0      :1;                                       
    byte CLKST1      :1;                                       
    byte IREFST      :1;                                       
    byte PLLST       :1;                                       
    byte LOCK        :1;                                       
    byte LOLS        :1;                                       
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpCLKST :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} MCGSCSTR;
volatile MCGSCSTR __at (0x004B) _MCGSC;
#define MCGSC                           _MCGSC.Byte
#define MCGSC_FTRIM                     _MCGSC.Bits.FTRIM
#define MCGSC_OSCINIT                   _MCGSC.Bits.OSCINIT
#define MCGSC_CLKST0                    _MCGSC.Bits.CLKST0
#define MCGSC_CLKST1                    _MCGSC.Bits.CLKST1
#define MCGSC_IREFST                    _MCGSC.Bits.IREFST
#define MCGSC_PLLST                     _MCGSC.Bits.PLLST
#define MCGSC_LOCK                      _MCGSC.Bits.LOCK
#define MCGSC_LOLS                      _MCGSC.Bits.LOLS
#define MCGSC_CLKST                     _MCGSC.MergedBits.grpCLKST

#define MCGSC_FTRIM_MASK                1
#define MCGSC_OSCINIT_MASK              2
#define MCGSC_CLKST0_MASK               4
#define MCGSC_CLKST1_MASK               8
#define MCGSC_IREFST_MASK               16
#define MCGSC_PLLST_MASK                32
#define MCGSC_LOCK_MASK                 64
#define MCGSC_LOLS_MASK                 128
#define MCGSC_CLKST_MASK                12
#define MCGSC_CLKST_BITNUM              2



typedef union {
  byte Byte;
  struct {
    byte VDIV0       :1;                                       
    byte VDIV1       :1;                                       
    byte VDIV2       :1;                                       
    byte VDIV3       :1;                                       
    byte             :1; 
    byte CME         :1;                                       
    byte PLLS        :1;                                       
    byte LOLIE       :1;                                       
  } Bits;
  struct {
    byte grpVDIV :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} MCGC3STR;
volatile MCGC3STR __at (0x004C) _MCGC3;
#define MCGC3                           _MCGC3.Byte
#define MCGC3_VDIV0                     _MCGC3.Bits.VDIV0
#define MCGC3_VDIV1                     _MCGC3.Bits.VDIV1
#define MCGC3_VDIV2                     _MCGC3.Bits.VDIV2
#define MCGC3_VDIV3                     _MCGC3.Bits.VDIV3
#define MCGC3_CME                       _MCGC3.Bits.CME
#define MCGC3_PLLS                      _MCGC3.Bits.PLLS
#define MCGC3_LOLIE                     _MCGC3.Bits.LOLIE
#define MCGC3_VDIV                      _MCGC3.MergedBits.grpVDIV

#define MCGC3_VDIV0_MASK                1
#define MCGC3_VDIV1_MASK                2
#define MCGC3_VDIV2_MASK                4
#define MCGC3_VDIV3_MASK                8
#define MCGC3_CME_MASK                  32
#define MCGC3_PLLS_MASK                 64
#define MCGC3_LOLIE_MASK                128
#define MCGC3_VDIV_MASK                 15
#define MCGC3_VDIV_BITNUM               0



typedef union {
  byte Byte;
  struct {
    byte LSBFE       :1;                                       
    byte SSOE        :1;                                       
    byte CPHA        :1;                                       
    byte CPOL        :1;                                       
    byte MSTR        :1;                                       
    byte SPTIE       :1;                                       
    byte SPE         :1;                                       
    byte SPIE        :1;                                       
  } Bits;
} SPIC1STR;
volatile SPIC1STR __at (0x0050) _SPIC1;
#define SPIC1                           _SPIC1.Byte
#define SPIC1_LSBFE                     _SPIC1.Bits.LSBFE
#define SPIC1_SSOE                      _SPIC1.Bits.SSOE
#define SPIC1_CPHA                      _SPIC1.Bits.CPHA
#define SPIC1_CPOL                      _SPIC1.Bits.CPOL
#define SPIC1_MSTR                      _SPIC1.Bits.MSTR
#define SPIC1_SPTIE                     _SPIC1.Bits.SPTIE
#define SPIC1_SPE                       _SPIC1.Bits.SPE
#define SPIC1_SPIE                      _SPIC1.Bits.SPIE

#define SPIC1_LSBFE_MASK                1
#define SPIC1_SSOE_MASK                 2
#define SPIC1_CPHA_MASK                 4
#define SPIC1_CPOL_MASK                 8
#define SPIC1_MSTR_MASK                 16
#define SPIC1_SPTIE_MASK                32
#define SPIC1_SPE_MASK                  64
#define SPIC1_SPIE_MASK                 128



typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       
    byte SPISWAI     :1;                                       
    byte             :1; 
    byte BIDIROE     :1;                                       
    byte MODFEN      :1;                                       
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SPIC2STR;
volatile SPIC2STR __at (0x0051) _SPIC2;
#define SPIC2                           _SPIC2.Byte
#define SPIC2_SPC0                      _SPIC2.Bits.SPC0
#define SPIC2_SPISWAI                   _SPIC2.Bits.SPISWAI
#define SPIC2_BIDIROE                   _SPIC2.Bits.BIDIROE
#define SPIC2_MODFEN                    _SPIC2.Bits.MODFEN

#define SPIC2_SPC0_MASK                 1
#define SPIC2_SPISWAI_MASK              2
#define SPIC2_BIDIROE_MASK              8
#define SPIC2_MODFEN_MASK               16



typedef union {
  byte Byte;
  struct {
    byte SPR0        :1;                                       
    byte SPR1        :1;                                       
    byte SPR2        :1;                                       
    byte             :1; 
    byte SPPR0       :1;                                       
    byte SPPR1       :1;                                       
    byte SPPR2       :1;                                       
    byte             :1; 
  } Bits;
  struct {
    byte grpSPR  :3;
    byte         :1;
    byte grpSPPR :3;
    byte         :1;
  } MergedBits;
} SPIBRSTR;
volatile SPIBRSTR __at (0x0052) _SPIBR;
#define SPIBR                           _SPIBR.Byte
#define SPIBR_SPR0                      _SPIBR.Bits.SPR0
#define SPIBR_SPR1                      _SPIBR.Bits.SPR1
#define SPIBR_SPR2                      _SPIBR.Bits.SPR2
#define SPIBR_SPPR0                     _SPIBR.Bits.SPPR0
#define SPIBR_SPPR1                     _SPIBR.Bits.SPPR1
#define SPIBR_SPPR2                     _SPIBR.Bits.SPPR2
#define SPIBR_SPR                       _SPIBR.MergedBits.grpSPR
#define SPIBR_SPPR                      _SPIBR.MergedBits.grpSPPR

#define SPIBR_SPR0_MASK                 1
#define SPIBR_SPR1_MASK                 2
#define SPIBR_SPR2_MASK                 4
#define SPIBR_SPPR0_MASK                16
#define SPIBR_SPPR1_MASK                32
#define SPIBR_SPPR2_MASK                64
#define SPIBR_SPR_MASK                  7
#define SPIBR_SPR_BITNUM                0
#define SPIBR_SPPR_MASK                 112
#define SPIBR_SPPR_BITNUM               4



typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODF        :1;                                       
    byte SPTEF       :1;                                       
    byte             :1; 
    byte SPRF        :1;                                       
  } Bits;
} SPISSTR;
volatile SPISSTR __at (0x0053) _SPIS;
#define SPIS                            _SPIS.Byte
#define SPIS_MODF                       _SPIS.Bits.MODF
#define SPIS_SPTEF                      _SPIS.Bits.SPTEF
#define SPIS_SPRF                       _SPIS.Bits.SPRF

#define SPIS_MODF_MASK                  16
#define SPIS_SPTEF_MASK                 32
#define SPIS_SPRF_MASK                  128



typedef union {
  byte Byte;
} SPIDSTR;
volatile SPIDSTR __at (0x0055) _SPID;
#define SPID                            _SPID.Byte




typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte AD1         :1;                                       
    byte AD2         :1;                                       
    byte AD3         :1;                                       
    byte AD4         :1;                                       
    byte AD5         :1;                                       
    byte AD6         :1;                                       
    byte AD7         :1;                                       
  } Bits;
  struct {
    byte         :1;
    byte grpAD_1 :7;
  } MergedBits;
} IICASTR;
volatile IICASTR __at (0x0058) _IICA;
#define IICA                            _IICA.Byte
#define IICA_AD1                        _IICA.Bits.AD1
#define IICA_AD2                        _IICA.Bits.AD2
#define IICA_AD3                        _IICA.Bits.AD3
#define IICA_AD4                        _IICA.Bits.AD4
#define IICA_AD5                        _IICA.Bits.AD5
#define IICA_AD6                        _IICA.Bits.AD6
#define IICA_AD7                        _IICA.Bits.AD7
#define IICA_AD_1                       _IICA.MergedBits.grpAD_1
#define IICA_AD                         IICA_AD_1

#define IICA_AD1_MASK                   2
#define IICA_AD2_MASK                   4
#define IICA_AD3_MASK                   8
#define IICA_AD4_MASK                   16
#define IICA_AD5_MASK                   32
#define IICA_AD6_MASK                   64
#define IICA_AD7_MASK                   128
#define IICA_AD_1_MASK                  254
#define IICA_AD_1_BITNUM                1



typedef union {
  byte Byte;
  struct {
    byte ICR0        :1;                                       
    byte ICR1        :1;                                       
    byte ICR2        :1;                                       
    byte ICR3        :1;                                       
    byte ICR4        :1;                                       
    byte ICR5        :1;                                       
    byte MULT0       :1;                                       
    byte MULT1       :1;                                       
  } Bits;
  struct {
    byte grpICR  :6;
    byte grpMULT :2;
  } MergedBits;
} IICFSTR;
volatile IICFSTR __at (0x0059) _IICF;
#define IICF                            _IICF.Byte
#define IICF_ICR0                       _IICF.Bits.ICR0
#define IICF_ICR1                       _IICF.Bits.ICR1
#define IICF_ICR2                       _IICF.Bits.ICR2
#define IICF_ICR3                       _IICF.Bits.ICR3
#define IICF_ICR4                       _IICF.Bits.ICR4
#define IICF_ICR5                       _IICF.Bits.ICR5
#define IICF_MULT0                      _IICF.Bits.MULT0
#define IICF_MULT1                      _IICF.Bits.MULT1
#define IICF_ICR                        _IICF.MergedBits.grpICR
#define IICF_MULT                       _IICF.MergedBits.grpMULT

#define IICF_ICR0_MASK                  1
#define IICF_ICR1_MASK                  2
#define IICF_ICR2_MASK                  4
#define IICF_ICR3_MASK                  8
#define IICF_ICR4_MASK                  16
#define IICF_ICR5_MASK                  32
#define IICF_MULT0_MASK                 64
#define IICF_MULT1_MASK                 128
#define IICF_ICR_MASK                   63
#define IICF_ICR_BITNUM                 0
#define IICF_MULT_MASK                  192
#define IICF_MULT_BITNUM                6



typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte RSTA        :1;                                       
    byte TXAK        :1;                                       
    byte TX          :1;                                       
    byte MST         :1;                                       
    byte IICIE       :1;                                       
    byte IICEN       :1;                                       
  } Bits;
} IICC1STR;
volatile IICC1STR __at (0x005A) _IICC1;
#define IICC1                           _IICC1.Byte
#define IICC1_RSTA                      _IICC1.Bits.RSTA
#define IICC1_TXAK                      _IICC1.Bits.TXAK
#define IICC1_TX                        _IICC1.Bits.TX
#define IICC1_MST                       _IICC1.Bits.MST
#define IICC1_IICIE                     _IICC1.Bits.IICIE
#define IICC1_IICEN                     _IICC1.Bits.IICEN

#define IICC1_RSTA_MASK                 4
#define IICC1_TXAK_MASK                 8
#define IICC1_TX_MASK                   16
#define IICC1_MST_MASK                  32
#define IICC1_IICIE_MASK                64
#define IICC1_IICEN_MASK                128



typedef union {
  byte Byte;
  struct {
    byte RXAK        :1;                                       
    byte IICIF       :1;                                       
    byte SRW         :1;                                       
    byte             :1; 
    byte ARBL        :1;                                       
    byte BUSY        :1;                                       
    byte IAAS        :1;                                       
    byte TCF         :1;                                       
  } Bits;
} IICSSTR;
volatile IICSSTR __at (0x005B) _IICS;
#define IICS                            _IICS.Byte
#define IICS_RXAK                       _IICS.Bits.RXAK
#define IICS_IICIF                      _IICS.Bits.IICIF
#define IICS_SRW                        _IICS.Bits.SRW
#define IICS_ARBL                       _IICS.Bits.ARBL
#define IICS_BUSY                       _IICS.Bits.BUSY
#define IICS_IAAS                       _IICS.Bits.IAAS
#define IICS_TCF                        _IICS.Bits.TCF

#define IICS_RXAK_MASK                  1
#define IICS_IICIF_MASK                 2
#define IICS_SRW_MASK                   4
#define IICS_ARBL_MASK                  16
#define IICS_BUSY_MASK                  32
#define IICS_IAAS_MASK                  64
#define IICS_TCF_MASK                   128



typedef union {
  byte Byte;
  struct {
    byte DATA0       :1;                                       
    byte DATA1       :1;                                       
    byte DATA2       :1;                                       
    byte DATA3       :1;                                       
    byte DATA4       :1;                                       
    byte DATA5       :1;                                       
    byte DATA6       :1;                                       
    byte DATA7       :1;                                       
  } Bits;
} IICDSTR;
volatile IICDSTR __at (0x005C) _IICD;
#define IICD                            _IICD.Byte
#define IICD_DATA0                      _IICD.Bits.DATA0
#define IICD_DATA1                      _IICD.Bits.DATA1
#define IICD_DATA2                      _IICD.Bits.DATA2
#define IICD_DATA3                      _IICD.Bits.DATA3
#define IICD_DATA4                      _IICD.Bits.DATA4
#define IICD_DATA5                      _IICD.Bits.DATA5
#define IICD_DATA6                      _IICD.Bits.DATA6
#define IICD_DATA7                      _IICD.Bits.DATA7

#define IICD_DATA0_MASK                 1
#define IICD_DATA1_MASK                 2
#define IICD_DATA2_MASK                 4
#define IICD_DATA3_MASK                 8
#define IICD_DATA4_MASK                 16
#define IICD_DATA5_MASK                 32
#define IICD_DATA6_MASK                 64
#define IICD_DATA7_MASK                 128



typedef union {
  byte Byte;
  struct {
    byte AD8         :1;                                       
    byte AD9         :1;                                       
    byte AD10        :1;                                       
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte ADEXT       :1;                                       
    byte GCAEN       :1;                                       
  } Bits;
  struct {
    byte grpAD_8 :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} IICC2STR;
volatile IICC2STR __at (0x005D) _IICC2;
#define IICC2                           _IICC2.Byte
#define IICC2_AD8                       _IICC2.Bits.AD8
#define IICC2_AD9                       _IICC2.Bits.AD9
#define IICC2_AD10                      _IICC2.Bits.AD10
#define IICC2_ADEXT                     _IICC2.Bits.ADEXT
#define IICC2_GCAEN                     _IICC2.Bits.GCAEN
#define IICC2_AD_8                      _IICC2.MergedBits.grpAD_8
#define IICC2_AD                        IICC2_AD_8

#define IICC2_AD8_MASK                  1
#define IICC2_AD9_MASK                  2
#define IICC2_AD10_MASK                 4
#define IICC2_ADEXT_MASK                64
#define IICC2_GCAEN_MASK                128
#define IICC2_AD_8_MASK                 7
#define IICC2_AD_8_BITNUM               0



typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       
    byte PS1         :1;                                       
    byte PS2         :1;                                       
    byte CLKSA       :1;                                       
    byte CLKSB       :1;                                       
    byte CPWMS       :1;                                       
    byte TOIE        :1;                                       
    byte TOF         :1;                                       
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKSx :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM2SCSTR;
volatile TPM2SCSTR __at (0x0060) _TPM2SC;
#define TPM2SC                          _TPM2SC.Byte
#define TPM2SC_PS0                      _TPM2SC.Bits.PS0
#define TPM2SC_PS1                      _TPM2SC.Bits.PS1
#define TPM2SC_PS2                      _TPM2SC.Bits.PS2
#define TPM2SC_CLKSA                    _TPM2SC.Bits.CLKSA
#define TPM2SC_CLKSB                    _TPM2SC.Bits.CLKSB
#define TPM2SC_CPWMS                    _TPM2SC.Bits.CPWMS
#define TPM2SC_TOIE                     _TPM2SC.Bits.TOIE
#define TPM2SC_TOF                      _TPM2SC.Bits.TOF
#define TPM2SC_PS                       _TPM2SC.MergedBits.grpPS
#define TPM2SC_CLKSx                    _TPM2SC.MergedBits.grpCLKSx

#define TPM2SC_PS0_MASK                 1
#define TPM2SC_PS1_MASK                 2
#define TPM2SC_PS2_MASK                 4
#define TPM2SC_CLKSA_MASK               8
#define TPM2SC_CLKSB_MASK               16
#define TPM2SC_CPWMS_MASK               32
#define TPM2SC_TOIE_MASK                64
#define TPM2SC_TOF_MASK                 128
#define TPM2SC_PS_MASK                  7
#define TPM2SC_PS_BITNUM                0
#define TPM2SC_CLKSx_MASK               24
#define TPM2SC_CLKSx_BITNUM             3



typedef union {
  word Word;
   
  struct {
    
    union {
      byte Byte;
    } TPM2CNTHSTR;
    #define TPM2CNTH                    _TPM2CNT.Overlap_STR.TPM2CNTHSTR.Byte
    
    


    
    union {
      byte Byte;
    } TPM2CNTLSTR;
    #define TPM2CNTL                    _TPM2CNT.Overlap_STR.TPM2CNTLSTR.Byte
    
    

  } Overlap_STR;

} TPM2CNTSTR;
volatile TPM2CNTSTR __at (0x0061) _TPM2CNT;
#define TPM2CNT                         _TPM2CNT.Word




typedef union {
  word Word;
   
  struct {
    
    union {
      byte Byte;
    } TPM2MODHSTR;
    #define TPM2MODH                    _TPM2MOD.Overlap_STR.TPM2MODHSTR.Byte
    
    


    
    union {
      byte Byte;
    } TPM2MODLSTR;
    #define TPM2MODL                    _TPM2MOD.Overlap_STR.TPM2MODLSTR.Byte
    
    

  } Overlap_STR;

} TPM2MODSTR;
volatile TPM2MODSTR __at (0x0063) _TPM2MOD;
#define TPM2MOD                         _TPM2MOD.Word




typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS0A       :1;                                       
    byte ELS0B       :1;                                       
    byte MS0A        :1;                                       
    byte MS0B        :1;                                       
    byte CH0IE       :1;                                       
    byte CH0F        :1;                                       
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS0x :2;
    byte grpMS0x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM2C0SCSTR;
volatile TPM2C0SCSTR __at (0x0065) _TPM2C0SC;
#define TPM2C0SC                        _TPM2C0SC.Byte
#define TPM2C0SC_ELS0A                  _TPM2C0SC.Bits.ELS0A
#define TPM2C0SC_ELS0B                  _TPM2C0SC.Bits.ELS0B
#define TPM2C0SC_MS0A                   _TPM2C0SC.Bits.MS0A
#define TPM2C0SC_MS0B                   _TPM2C0SC.Bits.MS0B
#define TPM2C0SC_CH0IE                  _TPM2C0SC.Bits.CH0IE
#define TPM2C0SC_CH0F                   _TPM2C0SC.Bits.CH0F
#define TPM2C0SC_ELS0x                  _TPM2C0SC.MergedBits.grpELS0x
#define TPM2C0SC_MS0x                   _TPM2C0SC.MergedBits.grpMS0x

#define TPM2C0SC_ELS0A_MASK             4
#define TPM2C0SC_ELS0B_MASK             8
#define TPM2C0SC_MS0A_MASK              16
#define TPM2C0SC_MS0B_MASK              32
#define TPM2C0SC_CH0IE_MASK             64
#define TPM2C0SC_CH0F_MASK              128
#define TPM2C0SC_ELS0x_MASK             12
#define TPM2C0SC_ELS0x_BITNUM           2
#define TPM2C0SC_MS0x_MASK              48
#define TPM2C0SC_MS0x_BITNUM            4



typedef union {
  word Word;
   
  struct {
    
    union {
      byte Byte;
    } TPM2C0VHSTR;
    #define TPM2C0VH                    _TPM2C0V.Overlap_STR.TPM2C0VHSTR.Byte
    
    


    
    union {
      byte Byte;
    } TPM2C0VLSTR;
    #define TPM2C0VL                    _TPM2C0V.Overlap_STR.TPM2C0VLSTR.Byte
    
    

  } Overlap_STR;

} TPM2C0VSTR;
volatile TPM2C0VSTR __at (0x0066) _TPM2C0V;
#define TPM2C0V                         _TPM2C0V.Word




typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS1A       :1;                                       
    byte ELS1B       :1;                                       
    byte MS1A        :1;                                       
    byte MS1B        :1;                                       
    byte CH1IE       :1;                                       
    byte CH1F        :1;                                       
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS1x :2;
    byte grpMS1x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM2C1SCSTR;
volatile TPM2C1SCSTR __at (0x0068) _TPM2C1SC;
#define TPM2C1SC                        _TPM2C1SC.Byte
#define TPM2C1SC_ELS1A                  _TPM2C1SC.Bits.ELS1A
#define TPM2C1SC_ELS1B                  _TPM2C1SC.Bits.ELS1B
#define TPM2C1SC_MS1A                   _TPM2C1SC.Bits.MS1A
#define TPM2C1SC_MS1B                   _TPM2C1SC.Bits.MS1B
#define TPM2C1SC_CH1IE                  _TPM2C1SC.Bits.CH1IE
#define TPM2C1SC_CH1F                   _TPM2C1SC.Bits.CH1F
#define TPM2C1SC_ELS1x                  _TPM2C1SC.MergedBits.grpELS1x
#define TPM2C1SC_MS1x                   _TPM2C1SC.MergedBits.grpMS1x

#define TPM2C1SC_ELS1A_MASK             4
#define TPM2C1SC_ELS1B_MASK             8
#define TPM2C1SC_MS1A_MASK              16
#define TPM2C1SC_MS1B_MASK              32
#define TPM2C1SC_CH1IE_MASK             64
#define TPM2C1SC_CH1F_MASK              128
#define TPM2C1SC_ELS1x_MASK             12
#define TPM2C1SC_ELS1x_BITNUM           2
#define TPM2C1SC_MS1x_MASK              48
#define TPM2C1SC_MS1x_BITNUM            4



typedef union {
  word Word;
   
  struct {
    
    union {
      byte Byte;
    } TPM2C1VHSTR;
    #define TPM2C1VH                    _TPM2C1V.Overlap_STR.TPM2C1VHSTR.Byte
    
    


    
    union {
      byte Byte;
    } TPM2C1VLSTR;
    #define TPM2C1VL                    _TPM2C1V.Overlap_STR.TPM2C1VLSTR.Byte
    
    

  } Overlap_STR;

} TPM2C1VSTR;
volatile TPM2C1VSTR __at (0x0069) _TPM2C1V;
#define TPM2C1V                         _TPM2C1V.Word




typedef union {
  byte Byte;
  struct {
    byte RTCPS0      :1;                                       
    byte RTCPS1      :1;                                       
    byte RTCPS2      :1;                                       
    byte RTCPS3      :1;                                       
    byte RTIE        :1;                                       
    byte RTCLKS0     :1;                                       
    byte RTCLKS1     :1;                                       
    byte RTIF        :1;                                       
  } Bits;
  struct {
    byte grpRTCPS :4;
    byte         :1;
    byte grpRTCLKS :2;
    byte         :1;
  } MergedBits;
} RTCSCSTR;
volatile RTCSCSTR __at (0x006C) _RTCSC;
#define RTCSC                           _RTCSC.Byte
#define RTCSC_RTCPS0                    _RTCSC.Bits.RTCPS0
#define RTCSC_RTCPS1                    _RTCSC.Bits.RTCPS1
#define RTCSC_RTCPS2                    _RTCSC.Bits.RTCPS2
#define RTCSC_RTCPS3                    _RTCSC.Bits.RTCPS3
#define RTCSC_RTIE                      _RTCSC.Bits.RTIE
#define RTCSC_RTCLKS0                   _RTCSC.Bits.RTCLKS0
#define RTCSC_RTCLKS1                   _RTCSC.Bits.RTCLKS1
#define RTCSC_RTIF                      _RTCSC.Bits.RTIF
#define RTCSC_RTCPS                     _RTCSC.MergedBits.grpRTCPS
#define RTCSC_RTCLKS                    _RTCSC.MergedBits.grpRTCLKS

#define RTCSC_RTCPS0_MASK               1
#define RTCSC_RTCPS1_MASK               2
#define RTCSC_RTCPS2_MASK               4
#define RTCSC_RTCPS3_MASK               8
#define RTCSC_RTIE_MASK                 16
#define RTCSC_RTCLKS0_MASK              32
#define RTCSC_RTCLKS1_MASK              64
#define RTCSC_RTIF_MASK                 128
#define RTCSC_RTCPS_MASK                15
#define RTCSC_RTCPS_BITNUM              0
#define RTCSC_RTCLKS_MASK               96
#define RTCSC_RTCLKS_BITNUM             5



typedef union {
  byte Byte;
} RTCCNTSTR;
volatile RTCCNTSTR __at (0x006D) _RTCCNT;
#define RTCCNT                          _RTCCNT.Byte




typedef union {
  byte Byte;
} RTCMODSTR;
volatile RTCMODSTR __at (0x006E) _RTCMOD;
#define RTCMOD                          _RTCMOD.Byte




typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte LVD         :1;                                       
    byte LOC         :1;                                       
    byte ILAD        :1;                                       
    byte ILOP        :1;                                       
    byte COP         :1;                                       
    byte PIN         :1;                                       
    byte POR         :1;                                       
  } Bits;
} SRSSTR;
volatile SRSSTR __at (0x1800) _SRS;
#define SRS                             _SRS.Byte
#define SRS_LVD                         _SRS.Bits.LVD
#define SRS_LOC                         _SRS.Bits.LOC
#define SRS_ILAD                        _SRS.Bits.ILAD
#define SRS_ILOP                        _SRS.Bits.ILOP
#define SRS_COP                         _SRS.Bits.COP
#define SRS_PIN                         _SRS.Bits.PIN
#define SRS_POR                         _SRS.Bits.POR

#define SRS_LVD_MASK                    2
#define SRS_LOC_MASK                    4
#define SRS_ILAD_MASK                   8
#define SRS_ILOP_MASK                   16
#define SRS_COP_MASK                    32
#define SRS_PIN_MASK                    64
#define SRS_POR_MASK                    128



typedef union {
  byte Byte;
  struct {
    byte BDFR        :1;                                       
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SBDFRSTR;
volatile SBDFRSTR __at (0x1801) _SBDFR;
#define SBDFR                           _SBDFR.Byte
#define SBDFR_BDFR                      _SBDFR.Bits.BDFR

#define SBDFR_BDFR_MASK                 1



typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte IICPS       :1;                                       
    byte SCI2PS      :1;                                       
    byte STOPE       :1;                                       
    byte COPT0       :1;                                       
    byte COPT1       :1;                                       
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpCOPT :2;
  } MergedBits;
} SOPT1STR;
volatile SOPT1STR __at (0x1802) _SOPT1;
#define SOPT1                           _SOPT1.Byte
#define SOPT1_IICPS                     _SOPT1.Bits.IICPS
#define SOPT1_SCI2PS                    _SOPT1.Bits.SCI2PS
#define SOPT1_STOPE                     _SOPT1.Bits.STOPE
#define SOPT1_COPT0                     _SOPT1.Bits.COPT0
#define SOPT1_COPT1                     _SOPT1.Bits.COPT1
#define SOPT1_COPT                      _SOPT1.MergedBits.grpCOPT

#define SOPT1_IICPS_MASK                8
#define SOPT1_SCI2PS_MASK               16
#define SOPT1_STOPE_MASK                32
#define SOPT1_COPT0_MASK                64
#define SOPT1_COPT1_MASK                128
#define SOPT1_COPT_MASK                 192
#define SOPT1_COPT_BITNUM               6



typedef union {
  byte Byte;
  struct {
    byte MCSEL0      :1;                                       
    byte MCSEL1      :1;                                       
    byte MCSEL2      :1;                                       
    byte             :1; 
    byte ADHTS       :1;                                       
    byte             :1; 
    byte COPW        :1;                                       
    byte COPCLKS     :1;                                       
  } Bits;
  struct {
    byte grpMCSEL :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} SOPT2STR;
volatile SOPT2STR __at (0x1803) _SOPT2;
#define SOPT2                           _SOPT2.Byte
#define SOPT2_MCSEL0                    _SOPT2.Bits.MCSEL0
#define SOPT2_MCSEL1                    _SOPT2.Bits.MCSEL1
#define SOPT2_MCSEL2                    _SOPT2.Bits.MCSEL2
#define SOPT2_ADHTS                     _SOPT2.Bits.ADHTS
#define SOPT2_COPW                      _SOPT2.Bits.COPW
#define SOPT2_COPCLKS                   _SOPT2.Bits.COPCLKS
#define SOPT2_MCSEL                     _SOPT2.MergedBits.grpMCSEL

#define SOPT2_MCSEL0_MASK               1
#define SOPT2_MCSEL1_MASK               2
#define SOPT2_MCSEL2_MASK               4
#define SOPT2_ADHTS_MASK                16
#define SOPT2_COPW_MASK                 64
#define SOPT2_COPCLKS_MASK              128
#define SOPT2_MCSEL_MASK                7
#define SOPT2_MCSEL_BITNUM              0



typedef union {
  word Word;
   
  struct {
    
    union {
      byte Byte;
      struct {
        byte ID8         :1;                                       
        byte ID9         :1;                                       
        byte ID10        :1;                                       
        byte ID11        :1;                                       
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpID_8 :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SDIDHSTR;
    #define SDIDH                       _SDID.Overlap_STR.SDIDHSTR.Byte
    #define SDIDH_ID8                   _SDID.Overlap_STR.SDIDHSTR.Bits.ID8
    #define SDIDH_ID9                   _SDID.Overlap_STR.SDIDHSTR.Bits.ID9
    #define SDIDH_ID10                  _SDID.Overlap_STR.SDIDHSTR.Bits.ID10
    #define SDIDH_ID11                  _SDID.Overlap_STR.SDIDHSTR.Bits.ID11
    
    #define SDIDH_ID_8                  _SDID.Overlap_STR.SDIDHSTR.MergedBits.grpID_8
    #define SDIDH_ID                    SDIDH_ID_8
    
    #define SDIDH_ID8_MASK              1
    #define SDIDH_ID9_MASK              2
    #define SDIDH_ID10_MASK             4
    #define SDIDH_ID11_MASK             8
    #define SDIDH_ID_8_MASK             15
    #define SDIDH_ID_8_BITNUM           0


    
    union {
      byte Byte;
      struct {
        byte ID0         :1;                                       
        byte ID1         :1;                                       
        byte ID2         :1;                                       
        byte ID3         :1;                                       
        byte ID4         :1;                                       
        byte ID5         :1;                                       
        byte ID6         :1;                                       
        byte ID7         :1;                                       
      } Bits;
    } SDIDLSTR;
    #define SDIDL                       _SDID.Overlap_STR.SDIDLSTR.Byte
    #define SDIDL_ID0                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID0
    #define SDIDL_ID1                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID1
    #define SDIDL_ID2                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID2
    #define SDIDL_ID3                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID3
    #define SDIDL_ID4                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID4
    #define SDIDL_ID5                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID5
    #define SDIDL_ID6                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID6
    #define SDIDL_ID7                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID7
    
    
    #define SDIDL_ID0_MASK              1
    #define SDIDL_ID1_MASK              2
    #define SDIDL_ID2_MASK              4
    #define SDIDL_ID3_MASK              8
    #define SDIDL_ID4_MASK              16
    #define SDIDL_ID5_MASK              32
    #define SDIDL_ID6_MASK              64
    #define SDIDL_ID7_MASK              128

  } Overlap_STR;

} SDIDSTR;
volatile SDIDSTR __at (0x1806) _SDID;
#define SDID                            _SDID.Word




typedef union {
  byte Byte;
  struct {
    byte BGBE        :1;                                       
    byte             :1; 
    byte LVDE        :1;                                       
    byte LVDSE       :1;                                       
    byte LVDRE       :1;                                       
    byte LVWIE       :1;                                       
    byte LVWACK      :1;                                       
    byte LVWF        :1;                                       
  } Bits;
} SPMSC1STR;
volatile SPMSC1STR __at (0x1809) _SPMSC1;
#define SPMSC1                          _SPMSC1.Byte
#define SPMSC1_BGBE                     _SPMSC1.Bits.BGBE
#define SPMSC1_LVDE                     _SPMSC1.Bits.LVDE
#define SPMSC1_LVDSE                    _SPMSC1.Bits.LVDSE
#define SPMSC1_LVDRE                    _SPMSC1.Bits.LVDRE
#define SPMSC1_LVWIE                    _SPMSC1.Bits.LVWIE
#define SPMSC1_LVWACK                   _SPMSC1.Bits.LVWACK
#define SPMSC1_LVWF                     _SPMSC1.Bits.LVWF

#define SPMSC1_BGBE_MASK                1
#define SPMSC1_LVDE_MASK                4
#define SPMSC1_LVDSE_MASK               8
#define SPMSC1_LVDRE_MASK               16
#define SPMSC1_LVWIE_MASK               32
#define SPMSC1_LVWACK_MASK              64
#define SPMSC1_LVWF_MASK                128



typedef union {
  byte Byte;
  struct {
    byte PPDC        :1;                                       
    byte             :1; 
    byte PPDACK      :1;                                       
    byte PPDF        :1;                                       
    byte LVWV        :1;                                       
    byte LVDV        :1;                                       
    byte             :1; 
    byte             :1; 
  } Bits;
} SPMSC2STR;
volatile SPMSC2STR __at (0x180A) _SPMSC2;
#define SPMSC2                          _SPMSC2.Byte
#define SPMSC2_PPDC                     _SPMSC2.Bits.PPDC
#define SPMSC2_PPDACK                   _SPMSC2.Bits.PPDACK
#define SPMSC2_PPDF                     _SPMSC2.Bits.PPDF
#define SPMSC2_LVWV                     _SPMSC2.Bits.LVWV
#define SPMSC2_LVDV                     _SPMSC2.Bits.LVDV

#define SPMSC2_PPDC_MASK                1
#define SPMSC2_PPDACK_MASK              4
#define SPMSC2_PPDF_MASK                8
#define SPMSC2_LVWV_MASK                16
#define SPMSC2_LVDV_MASK                32



typedef union {
  byte Byte;
  struct {
    byte Bit8        :1;                                       
    byte Bit9        :1;                                       
    byte Bit10       :1;                                       
    byte Bit11       :1;                                       
    byte Bit12       :1;                                       
    byte Bit13       :1;                                       
    byte Bit14       :1;                                       
    byte Bit15       :1;                                       
  } Bits;
} DBGCAHSTR;
volatile DBGCAHSTR __at (0x1810) _DBGCAH;
#define DBGCAH                          _DBGCAH.Byte
#define DBGCAH_Bit8                     _DBGCAH.Bits.Bit8
#define DBGCAH_Bit9                     _DBGCAH.Bits.Bit9
#define DBGCAH_Bit10                    _DBGCAH.Bits.Bit10
#define DBGCAH_Bit11                    _DBGCAH.Bits.Bit11
#define DBGCAH_Bit12                    _DBGCAH.Bits.Bit12
#define DBGCAH_Bit13                    _DBGCAH.Bits.Bit13
#define DBGCAH_Bit14                    _DBGCAH.Bits.Bit14
#define DBGCAH_Bit15                    _DBGCAH.Bits.Bit15

#define DBGCAH_Bit8_MASK                1
#define DBGCAH_Bit9_MASK                2
#define DBGCAH_Bit10_MASK               4
#define DBGCAH_Bit11_MASK               8
#define DBGCAH_Bit12_MASK               16
#define DBGCAH_Bit13_MASK               32
#define DBGCAH_Bit14_MASK               64
#define DBGCAH_Bit15_MASK               128



typedef union {
  byte Byte;
  struct {
    byte Bit0        :1;                                       
    byte Bit1        :1;                                       
    byte Bit2        :1;                                       
    byte Bit3        :1;                                       
    byte Bit4        :1;                                       
    byte Bit5        :1;                                       
    byte Bit6        :1;                                       
    byte Bit7        :1;                                       
  } Bits;
} DBGCALSTR;
volatile DBGCALSTR __at (0x1811) _DBGCAL;
#define DBGCAL                          _DBGCAL.Byte
#define DBGCAL_Bit0                     _DBGCAL.Bits.Bit0
#define DBGCAL_Bit1                     _DBGCAL.Bits.Bit1
#define DBGCAL_Bit2                     _DBGCAL.Bits.Bit2
#define DBGCAL_Bit3                     _DBGCAL.Bits.Bit3
#define DBGCAL_Bit4                     _DBGCAL.Bits.Bit4
#define DBGCAL_Bit5                     _DBGCAL.Bits.Bit5
#define DBGCAL_Bit6                     _DBGCAL.Bits.Bit6
#define DBGCAL_Bit7                     _DBGCAL.Bits.Bit7

#define DBGCAL_Bit0_MASK                1
#define DBGCAL_Bit1_MASK                2
#define DBGCAL_Bit2_MASK                4
#define DBGCAL_Bit3_MASK                8
#define DBGCAL_Bit4_MASK                16
#define DBGCAL_Bit5_MASK                32
#define DBGCAL_Bit6_MASK                64
#define DBGCAL_Bit7_MASK                128



typedef union {
  byte Byte;
  struct {
    byte Bit8        :1;                                       
    byte Bit9        :1;                                       
    byte Bit10       :1;                                       
    byte Bit11       :1;                                       
    byte Bit12       :1;                                       
    byte Bit13       :1;                                       
    byte Bit14       :1;                                       
    byte Bit15       :1;                                       
  } Bits;
} DBGCBHSTR;
volatile DBGCBHSTR __at (0x1812) _DBGCBH;
#define DBGCBH                          _DBGCBH.Byte
#define DBGCBH_Bit8                     _DBGCBH.Bits.Bit8
#define DBGCBH_Bit9                     _DBGCBH.Bits.Bit9
#define DBGCBH_Bit10                    _DBGCBH.Bits.Bit10
#define DBGCBH_Bit11                    _DBGCBH.Bits.Bit11
#define DBGCBH_Bit12                    _DBGCBH.Bits.Bit12
#define DBGCBH_Bit13                    _DBGCBH.Bits.Bit13
#define DBGCBH_Bit14                    _DBGCBH.Bits.Bit14
#define DBGCBH_Bit15                    _DBGCBH.Bits.Bit15

#define DBGCBH_Bit8_MASK                1
#define DBGCBH_Bit9_MASK                2
#define DBGCBH_Bit10_MASK               4
#define DBGCBH_Bit11_MASK               8
#define DBGCBH_Bit12_MASK               16
#define DBGCBH_Bit13_MASK               32
#define DBGCBH_Bit14_MASK               64
#define DBGCBH_Bit15_MASK               128



typedef union {
  byte Byte;
  struct {
    byte Bit0        :1;                                       
    byte Bit1        :1;                                       
    byte Bit2        :1;                                       
    byte Bit3        :1;                                       
    byte Bit4        :1;                                       
    byte Bit5        :1;                                       
    byte Bit6        :1;                                       
    byte Bit7        :1;                                       
  } Bits;
} DBGCBLSTR;
volatile DBGCBLSTR __at (0x1813) _DBGCBL;
#define DBGCBL                          _DBGCBL.Byte
#define DBGCBL_Bit0                     _DBGCBL.Bits.Bit0
#define DBGCBL_Bit1                     _DBGCBL.Bits.Bit1
#define DBGCBL_Bit2                     _DBGCBL.Bits.Bit2
#define DBGCBL_Bit3                     _DBGCBL.Bits.Bit3
#define DBGCBL_Bit4                     _DBGCBL.Bits.Bit4
#define DBGCBL_Bit5                     _DBGCBL.Bits.Bit5
#define DBGCBL_Bit6                     _DBGCBL.Bits.Bit6
#define DBGCBL_Bit7                     _DBGCBL.Bits.Bit7

#define DBGCBL_Bit0_MASK                1
#define DBGCBL_Bit1_MASK                2
#define DBGCBL_Bit2_MASK                4
#define DBGCBL_Bit3_MASK                8
#define DBGCBL_Bit4_MASK                16
#define DBGCBL_Bit5_MASK                32
#define DBGCBL_Bit6_MASK                64
#define DBGCBL_Bit7_MASK                128



typedef union {
  word Word;
   
  struct {
    
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       
        byte Bit9        :1;                                       
        byte Bit10       :1;                                       
        byte Bit11       :1;                                       
        byte Bit12       :1;                                       
        byte Bit13       :1;                                       
        byte Bit14       :1;                                       
        byte Bit15       :1;                                       
      } Bits;
    } DBGFHSTR;
    #define DBGFH                       _DBGF.Overlap_STR.DBGFHSTR.Byte
    #define DBGFH_Bit8                  _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit8
    #define DBGFH_Bit9                  _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit9
    #define DBGFH_Bit10                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit10
    #define DBGFH_Bit11                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit11
    #define DBGFH_Bit12                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit12
    #define DBGFH_Bit13                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit13
    #define DBGFH_Bit14                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit14
    #define DBGFH_Bit15                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit15
    
    
    #define DBGFH_Bit8_MASK             1
    #define DBGFH_Bit9_MASK             2
    #define DBGFH_Bit10_MASK            4
    #define DBGFH_Bit11_MASK            8
    #define DBGFH_Bit12_MASK            16
    #define DBGFH_Bit13_MASK            32
    #define DBGFH_Bit14_MASK            64
    #define DBGFH_Bit15_MASK            128


    
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       
        byte Bit1        :1;                                       
        byte Bit2        :1;                                       
        byte Bit3        :1;                                       
        byte Bit4        :1;                                       
        byte Bit5        :1;                                       
        byte Bit6        :1;                                       
        byte Bit7        :1;                                       
      } Bits;
    } DBGFLSTR;
    #define DBGFL                       _DBGF.Overlap_STR.DBGFLSTR.Byte
    #define DBGFL_Bit0                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit0
    #define DBGFL_Bit1                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit1
    #define DBGFL_Bit2                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit2
    #define DBGFL_Bit3                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit3
    #define DBGFL_Bit4                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit4
    #define DBGFL_Bit5                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit5
    #define DBGFL_Bit6                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit6
    #define DBGFL_Bit7                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit7
    
    
    #define DBGFL_Bit0_MASK             1
    #define DBGFL_Bit1_MASK             2
    #define DBGFL_Bit2_MASK             4
    #define DBGFL_Bit3_MASK             8
    #define DBGFL_Bit4_MASK             16
    #define DBGFL_Bit5_MASK             32
    #define DBGFL_Bit6_MASK             64
    #define DBGFL_Bit7_MASK             128

  } Overlap_STR;

} DBGFSTR;
volatile DBGFSTR __at (0x1814) _DBGF;
#define DBGF                            _DBGF.Word




typedef union {
  byte Byte;
  struct {
    byte RWBEN       :1;                                       
    byte RWB         :1;                                       
    byte RWAEN       :1;                                       
    byte RWA         :1;                                       
    byte BRKEN       :1;                                       
    byte TAG         :1;                                       
    byte ARM         :1;                                       
    byte DBGEN       :1;                                       
  } Bits;
} DBGCSTR;
volatile DBGCSTR __at (0x1816) _DBGC;
#define DBGC                            _DBGC.Byte
#define DBGC_RWBEN                      _DBGC.Bits.RWBEN
#define DBGC_RWB                        _DBGC.Bits.RWB
#define DBGC_RWAEN                      _DBGC.Bits.RWAEN
#define DBGC_RWA                        _DBGC.Bits.RWA
#define DBGC_BRKEN                      _DBGC.Bits.BRKEN
#define DBGC_TAG                        _DBGC.Bits.TAG
#define DBGC_ARM                        _DBGC.Bits.ARM
#define DBGC_DBGEN                      _DBGC.Bits.DBGEN

#define DBGC_RWBEN_MASK                 1
#define DBGC_RWB_MASK                   2
#define DBGC_RWAEN_MASK                 4
#define DBGC_RWA_MASK                   8
#define DBGC_BRKEN_MASK                 16
#define DBGC_TAG_MASK                   32
#define DBGC_ARM_MASK                   64
#define DBGC_DBGEN_MASK                 128



typedef union {
  byte Byte;
  struct {
    byte TRG0        :1;                                       
    byte TRG1        :1;                                       
    byte TRG2        :1;                                       
    byte TRG3        :1;                                       
    byte             :1; 
    byte             :1; 
    byte BEGIN       :1;                                       
    byte TRGSEL      :1;                                       
  } Bits;
  struct {
    byte grpTRG  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGTSTR;
volatile DBGTSTR __at (0x1817) _DBGT;
#define DBGT                            _DBGT.Byte
#define DBGT_TRG0                       _DBGT.Bits.TRG0
#define DBGT_TRG1                       _DBGT.Bits.TRG1
#define DBGT_TRG2                       _DBGT.Bits.TRG2
#define DBGT_TRG3                       _DBGT.Bits.TRG3
#define DBGT_BEGIN                      _DBGT.Bits.BEGIN
#define DBGT_TRGSEL                     _DBGT.Bits.TRGSEL
#define DBGT_TRG                        _DBGT.MergedBits.grpTRG

#define DBGT_TRG0_MASK                  1
#define DBGT_TRG1_MASK                  2
#define DBGT_TRG2_MASK                  4
#define DBGT_TRG3_MASK                  8
#define DBGT_BEGIN_MASK                 64
#define DBGT_TRGSEL_MASK                128
#define DBGT_TRG_MASK                   15
#define DBGT_TRG_BITNUM                 0



typedef union {
  byte Byte;
  struct {
    byte CNT0        :1;                                       
    byte CNT1        :1;                                       
    byte CNT2        :1;                                       
    byte CNT3        :1;                                       
    byte             :1; 
    byte ARMF        :1;                                       
    byte BF          :1;                                       
    byte AF          :1;                                       
  } Bits;
  struct {
    byte grpCNT  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGSSTR;
volatile DBGSSTR __at (0x1818) _DBGS;
#define DBGS                            _DBGS.Byte
#define DBGS_CNT0                       _DBGS.Bits.CNT0
#define DBGS_CNT1                       _DBGS.Bits.CNT1
#define DBGS_CNT2                       _DBGS.Bits.CNT2
#define DBGS_CNT3                       _DBGS.Bits.CNT3
#define DBGS_ARMF                       _DBGS.Bits.ARMF
#define DBGS_BF                         _DBGS.Bits.BF
#define DBGS_AF                         _DBGS.Bits.AF
#define DBGS_CNT                        _DBGS.MergedBits.grpCNT

#define DBGS_CNT0_MASK                  1
#define DBGS_CNT1_MASK                  2
#define DBGS_CNT2_MASK                  4
#define DBGS_CNT3_MASK                  8
#define DBGS_ARMF_MASK                  32
#define DBGS_BF_MASK                    64
#define DBGS_AF_MASK                    128
#define DBGS_CNT_MASK                   15
#define DBGS_CNT_BITNUM                 0



typedef union {
  byte Byte;
  struct {
    byte DIV0        :1;                                       
    byte DIV1        :1;                                       
    byte DIV2        :1;                                       
    byte DIV3        :1;                                       
    byte DIV4        :1;                                       
    byte DIV5        :1;                                       
    byte PRDIV8      :1;                                       
    byte DIVLD       :1;                                       
  } Bits;
  struct {
    byte grpDIV  :6;
    byte grpPRDIV_8 :1;
    byte         :1;
  } MergedBits;
} FCDIVSTR;
volatile FCDIVSTR __at (0x1820) _FCDIV;
#define FCDIV                           _FCDIV.Byte
#define FCDIV_DIV0                      _FCDIV.Bits.DIV0
#define FCDIV_DIV1                      _FCDIV.Bits.DIV1
#define FCDIV_DIV2                      _FCDIV.Bits.DIV2
#define FCDIV_DIV3                      _FCDIV.Bits.DIV3
#define FCDIV_DIV4                      _FCDIV.Bits.DIV4
#define FCDIV_DIV5                      _FCDIV.Bits.DIV5
#define FCDIV_PRDIV8                    _FCDIV.Bits.PRDIV8
#define FCDIV_DIVLD                     _FCDIV.Bits.DIVLD
#define FCDIV_DIV                       _FCDIV.MergedBits.grpDIV

#define FCDIV_DIV0_MASK                 1
#define FCDIV_DIV1_MASK                 2
#define FCDIV_DIV2_MASK                 4
#define FCDIV_DIV3_MASK                 8
#define FCDIV_DIV4_MASK                 16
#define FCDIV_DIV5_MASK                 32
#define FCDIV_PRDIV8_MASK               64
#define FCDIV_DIVLD_MASK                128
#define FCDIV_DIV_MASK                  63
#define FCDIV_DIV_BITNUM                0



typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       
    byte SEC1        :1;                                       
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte EPGMOD      :1;                                       
    byte FNORED      :1;                                       
    byte KEYEN       :1;                                       
  } Bits;
  struct {
    byte grpSEC  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FOPTSTR;
volatile FOPTSTR __at (0x1821) _FOPT;
#define FOPT                            _FOPT.Byte
#define FOPT_SEC0                       _FOPT.Bits.SEC0
#define FOPT_SEC1                       _FOPT.Bits.SEC1
#define FOPT_EPGMOD                     _FOPT.Bits.EPGMOD
#define FOPT_FNORED                     _FOPT.Bits.FNORED
#define FOPT_KEYEN                      _FOPT.Bits.KEYEN
#define FOPT_SEC                        _FOPT.MergedBits.grpSEC

#define FOPT_SEC0_MASK                  1
#define FOPT_SEC1_MASK                  2
#define FOPT_EPGMOD_MASK                32
#define FOPT_FNORED_MASK                64
#define FOPT_KEYEN_MASK                 128
#define FOPT_SEC_MASK                   3
#define FOPT_SEC_BITNUM                 0



typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MRDS0       :1;                                       
    byte MRDS1       :1;                                       
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpMRDS :2;
    byte         :1;
  } MergedBits;
} FTSTMODSTR;
volatile FTSTMODSTR __at (0x1822) _FTSTMOD;
#define FTSTMOD                         _FTSTMOD.Byte
#define FTSTMOD_MRDS0                   _FTSTMOD.Bits.MRDS0
#define FTSTMOD_MRDS1                   _FTSTMOD.Bits.MRDS1
#define FTSTMOD_MRDS                    _FTSTMOD.MergedBits.grpMRDS

#define FTSTMOD_MRDS0_MASK              32
#define FTSTMOD_MRDS1_MASK              64
#define FTSTMOD_MRDS_MASK               96
#define FTSTMOD_MRDS_BITNUM             5



typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte KEYACC      :1;                                       
    byte EPGSEL      :1;                                       
    byte             :1; 
  } Bits;
} FCNFGSTR;
volatile FCNFGSTR __at (0x1823) _FCNFG;
#define FCNFG                           _FCNFG.Byte
#define FCNFG_KEYACC                    _FCNFG.Bits.KEYACC
#define FCNFG_EPGSEL                    _FCNFG.Bits.EPGSEL

#define FCNFG_KEYACC_MASK               32
#define FCNFG_EPGSEL_MASK               64



typedef union {
  byte Byte;
  struct {
    byte FPS0        :1;                                       
    byte FPS1        :1;                                       
    byte FPS2        :1;                                       
    byte FPS3        :1;                                       
    byte FPS4        :1;                                       
    byte FPS5        :1;                                       
    byte EPS0        :1;                                       
    byte EPS1        :1;                                       
  } Bits;
  struct {
    byte grpFPS  :6;
    byte grpEPS  :2;
  } MergedBits;
} FPROTSTR;
volatile FPROTSTR __at (0x1824) _FPROT;
#define FPROT                           _FPROT.Byte
#define FPROT_FPS0                      _FPROT.Bits.FPS0
#define FPROT_FPS1                      _FPROT.Bits.FPS1
#define FPROT_FPS2                      _FPROT.Bits.FPS2
#define FPROT_FPS3                      _FPROT.Bits.FPS3
#define FPROT_FPS4                      _FPROT.Bits.FPS4
#define FPROT_FPS5                      _FPROT.Bits.FPS5
#define FPROT_EPS0                      _FPROT.Bits.EPS0
#define FPROT_EPS1                      _FPROT.Bits.EPS1
#define FPROT_FPS                       _FPROT.MergedBits.grpFPS
#define FPROT_EPS                       _FPROT.MergedBits.grpEPS

#define FPROT_FPS0_MASK                 1
#define FPROT_FPS1_MASK                 2
#define FPROT_FPS2_MASK                 4
#define FPROT_FPS3_MASK                 8
#define FPROT_FPS4_MASK                 16
#define FPROT_FPS5_MASK                 32
#define FPROT_EPS0_MASK                 64
#define FPROT_EPS1_MASK                 128
#define FPROT_FPS_MASK                  63
#define FPROT_FPS_BITNUM                0
#define FPROT_EPS_MASK                  192
#define FPROT_EPS_BITNUM                6



typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte FBLANK      :1;                                       
    byte             :1; 
    byte FACCERR     :1;                                       
    byte FPVIOL      :1;                                       
    byte FCCF        :1;                                       
    byte FCBEF       :1;                                       
  } Bits;
} FSTATSTR;
volatile FSTATSTR __at (0x1825) _FSTAT;
#define FSTAT                           _FSTAT.Byte
#define FSTAT_FBLANK                    _FSTAT.Bits.FBLANK
#define FSTAT_FACCERR                   _FSTAT.Bits.FACCERR
#define FSTAT_FPVIOL                    _FSTAT.Bits.FPVIOL
#define FSTAT_FCCF                      _FSTAT.Bits.FCCF
#define FSTAT_FCBEF                     _FSTAT.Bits.FCBEF

#define FSTAT_FBLANK_MASK               4
#define FSTAT_FACCERR_MASK              16
#define FSTAT_FPVIOL_MASK               32
#define FSTAT_FCCF_MASK                 64
#define FSTAT_FCBEF_MASK                128



typedef union {
  byte Byte;
  struct {
    byte FCMD0       :1;                                       
    byte FCMD1       :1;                                       
    byte FCMD2       :1;                                       
    byte FCMD3       :1;                                       
    byte FCMD4       :1;                                       
    byte FCMD5       :1;                                       
    byte FCMD6       :1;                                       
    byte FCMD7       :1;                                       
  } Bits;
} FCMDSTR;
volatile FCMDSTR __at (0x1826) _FCMD;
#define FCMD                            _FCMD.Byte
#define FCMD_FCMD0                      _FCMD.Bits.FCMD0
#define FCMD_FCMD1                      _FCMD.Bits.FCMD1
#define FCMD_FCMD2                      _FCMD.Bits.FCMD2
#define FCMD_FCMD3                      _FCMD.Bits.FCMD3
#define FCMD_FCMD4                      _FCMD.Bits.FCMD4
#define FCMD_FCMD5                      _FCMD.Bits.FCMD5
#define FCMD_FCMD6                      _FCMD.Bits.FCMD6
#define FCMD_FCMD7                      _FCMD.Bits.FCMD7

#define FCMD_FCMD0_MASK                 1
#define FCMD_FCMD1_MASK                 2
#define FCMD_FCMD2_MASK                 4
#define FCMD_FCMD3_MASK                 8
#define FCMD_FCMD4_MASK                 16
#define FCMD_FCMD5_MASK                 32
#define FCMD_FCMD6_MASK                 64
#define FCMD_FCMD7_MASK                 128



typedef union {
  byte Byte;
  struct {
    byte PTAPE0      :1;                                       
    byte PTAPE1      :1;                                       
    byte PTAPE2      :1;                                       
    byte PTAPE3      :1;                                       
    byte PTAPE4      :1;                                       
    byte PTAPE5      :1;                                       
    byte PTAPE6      :1;                                       
    byte PTAPE7      :1;                                       
  } Bits;
} PTAPESTR;
volatile PTAPESTR __at (0x1840) _PTAPE;
#define PTAPE                           _PTAPE.Byte
#define PTAPE_PTAPE0                    _PTAPE.Bits.PTAPE0
#define PTAPE_PTAPE1                    _PTAPE.Bits.PTAPE1
#define PTAPE_PTAPE2                    _PTAPE.Bits.PTAPE2
#define PTAPE_PTAPE3                    _PTAPE.Bits.PTAPE3
#define PTAPE_PTAPE4                    _PTAPE.Bits.PTAPE4
#define PTAPE_PTAPE5                    _PTAPE.Bits.PTAPE5
#define PTAPE_PTAPE6                    _PTAPE.Bits.PTAPE6
#define PTAPE_PTAPE7                    _PTAPE.Bits.PTAPE7

#define PTAPE_PTAPE0_MASK               1
#define PTAPE_PTAPE1_MASK               2
#define PTAPE_PTAPE2_MASK               4
#define PTAPE_PTAPE3_MASK               8
#define PTAPE_PTAPE4_MASK               16
#define PTAPE_PTAPE5_MASK               32
#define PTAPE_PTAPE6_MASK               64
#define PTAPE_PTAPE7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTASE0      :1;                                       
    byte PTASE1      :1;                                       
    byte PTASE2      :1;                                       
    byte PTASE3      :1;                                       
    byte PTASE4      :1;                                       
    byte PTASE5      :1;                                       
    byte PTASE6      :1;                                       
    byte PTASE7      :1;                                       
  } Bits;
} PTASESTR;
volatile PTASESTR __at (0x1841) _PTASE;
#define PTASE                           _PTASE.Byte
#define PTASE_PTASE0                    _PTASE.Bits.PTASE0
#define PTASE_PTASE1                    _PTASE.Bits.PTASE1
#define PTASE_PTASE2                    _PTASE.Bits.PTASE2
#define PTASE_PTASE3                    _PTASE.Bits.PTASE3
#define PTASE_PTASE4                    _PTASE.Bits.PTASE4
#define PTASE_PTASE5                    _PTASE.Bits.PTASE5
#define PTASE_PTASE6                    _PTASE.Bits.PTASE6
#define PTASE_PTASE7                    _PTASE.Bits.PTASE7

#define PTASE_PTASE0_MASK               1
#define PTASE_PTASE1_MASK               2
#define PTASE_PTASE2_MASK               4
#define PTASE_PTASE3_MASK               8
#define PTASE_PTASE4_MASK               16
#define PTASE_PTASE5_MASK               32
#define PTASE_PTASE6_MASK               64
#define PTASE_PTASE7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTADS0      :1;                                       
    byte PTADS1      :1;                                       
    byte PTADS2      :1;                                       
    byte PTADS3      :1;                                       
    byte PTADS4      :1;                                       
    byte PTADS5      :1;                                       
    byte PTADS6      :1;                                       
    byte PTADS7      :1;                                       
  } Bits;
} PTADSSTR;
volatile PTADSSTR __at (0x1842) _PTADS;
#define PTADS                           _PTADS.Byte
#define PTADS_PTADS0                    _PTADS.Bits.PTADS0
#define PTADS_PTADS1                    _PTADS.Bits.PTADS1
#define PTADS_PTADS2                    _PTADS.Bits.PTADS2
#define PTADS_PTADS3                    _PTADS.Bits.PTADS3
#define PTADS_PTADS4                    _PTADS.Bits.PTADS4
#define PTADS_PTADS5                    _PTADS.Bits.PTADS5
#define PTADS_PTADS6                    _PTADS.Bits.PTADS6
#define PTADS_PTADS7                    _PTADS.Bits.PTADS7

#define PTADS_PTADS0_MASK               1
#define PTADS_PTADS1_MASK               2
#define PTADS_PTADS2_MASK               4
#define PTADS_PTADS3_MASK               8
#define PTADS_PTADS4_MASK               16
#define PTADS_PTADS5_MASK               32
#define PTADS_PTADS6_MASK               64
#define PTADS_PTADS7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTAMOD      :1;                                       
    byte PTAIE       :1;                                       
    byte PTAACK      :1;                                       
    byte PTAIF       :1;                                       
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} PTASCSTR;
volatile PTASCSTR __at (0x1844) _PTASC;
#define PTASC                           _PTASC.Byte
#define PTASC_PTAMOD                    _PTASC.Bits.PTAMOD
#define PTASC_PTAIE                     _PTASC.Bits.PTAIE
#define PTASC_PTAACK                    _PTASC.Bits.PTAACK
#define PTASC_PTAIF                     _PTASC.Bits.PTAIF

#define PTASC_PTAMOD_MASK               1
#define PTASC_PTAIE_MASK                2
#define PTASC_PTAACK_MASK               4
#define PTASC_PTAIF_MASK                8



typedef union {
  byte Byte;
  struct {
    byte PTAPS0      :1;                                       
    byte PTAPS1      :1;                                       
    byte PTAPS2      :1;                                       
    byte PTAPS3      :1;                                       
    byte PTAPS4      :1;                                       
    byte PTAPS5      :1;                                       
    byte PTAPS6      :1;                                       
    byte PTAPS7      :1;                                       
  } Bits;
} PTAPSSTR;
volatile PTAPSSTR __at (0x1845) _PTAPS;
#define PTAPS                           _PTAPS.Byte
#define PTAPS_PTAPS0                    _PTAPS.Bits.PTAPS0
#define PTAPS_PTAPS1                    _PTAPS.Bits.PTAPS1
#define PTAPS_PTAPS2                    _PTAPS.Bits.PTAPS2
#define PTAPS_PTAPS3                    _PTAPS.Bits.PTAPS3
#define PTAPS_PTAPS4                    _PTAPS.Bits.PTAPS4
#define PTAPS_PTAPS5                    _PTAPS.Bits.PTAPS5
#define PTAPS_PTAPS6                    _PTAPS.Bits.PTAPS6
#define PTAPS_PTAPS7                    _PTAPS.Bits.PTAPS7

#define PTAPS_PTAPS0_MASK               1
#define PTAPS_PTAPS1_MASK               2
#define PTAPS_PTAPS2_MASK               4
#define PTAPS_PTAPS3_MASK               8
#define PTAPS_PTAPS4_MASK               16
#define PTAPS_PTAPS5_MASK               32
#define PTAPS_PTAPS6_MASK               64
#define PTAPS_PTAPS7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTAES0      :1;                                       
    byte PTAES1      :1;                                       
    byte PTAES2      :1;                                       
    byte PTAES3      :1;                                       
    byte PTAES4      :1;                                       
    byte PTAES5      :1;                                       
    byte PTAES6      :1;                                       
    byte PTAES7      :1;                                       
  } Bits;
} PTAESSTR;
volatile PTAESSTR __at (0x1846) _PTAES;
#define PTAES                           _PTAES.Byte
#define PTAES_PTAES0                    _PTAES.Bits.PTAES0
#define PTAES_PTAES1                    _PTAES.Bits.PTAES1
#define PTAES_PTAES2                    _PTAES.Bits.PTAES2
#define PTAES_PTAES3                    _PTAES.Bits.PTAES3
#define PTAES_PTAES4                    _PTAES.Bits.PTAES4
#define PTAES_PTAES5                    _PTAES.Bits.PTAES5
#define PTAES_PTAES6                    _PTAES.Bits.PTAES6
#define PTAES_PTAES7                    _PTAES.Bits.PTAES7

#define PTAES_PTAES0_MASK               1
#define PTAES_PTAES1_MASK               2
#define PTAES_PTAES2_MASK               4
#define PTAES_PTAES3_MASK               8
#define PTAES_PTAES4_MASK               16
#define PTAES_PTAES5_MASK               32
#define PTAES_PTAES6_MASK               64
#define PTAES_PTAES7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTBPE0      :1;                                       
    byte PTBPE1      :1;                                       
    byte PTBPE2      :1;                                       
    byte PTBPE3      :1;                                       
    byte PTBPE4      :1;                                       
    byte PTBPE5      :1;                                       
    byte PTBPE6      :1;                                       
    byte PTBPE7      :1;                                       
  } Bits;
} PTBPESTR;
volatile PTBPESTR __at (0x1848) _PTBPE;
#define PTBPE                           _PTBPE.Byte
#define PTBPE_PTBPE0                    _PTBPE.Bits.PTBPE0
#define PTBPE_PTBPE1                    _PTBPE.Bits.PTBPE1
#define PTBPE_PTBPE2                    _PTBPE.Bits.PTBPE2
#define PTBPE_PTBPE3                    _PTBPE.Bits.PTBPE3
#define PTBPE_PTBPE4                    _PTBPE.Bits.PTBPE4
#define PTBPE_PTBPE5                    _PTBPE.Bits.PTBPE5
#define PTBPE_PTBPE6                    _PTBPE.Bits.PTBPE6
#define PTBPE_PTBPE7                    _PTBPE.Bits.PTBPE7

#define PTBPE_PTBPE0_MASK               1
#define PTBPE_PTBPE1_MASK               2
#define PTBPE_PTBPE2_MASK               4
#define PTBPE_PTBPE3_MASK               8
#define PTBPE_PTBPE4_MASK               16
#define PTBPE_PTBPE5_MASK               32
#define PTBPE_PTBPE6_MASK               64
#define PTBPE_PTBPE7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTBSE0      :1;                                       
    byte PTBSE1      :1;                                       
    byte PTBSE2      :1;                                       
    byte PTBSE3      :1;                                       
    byte PTBSE4      :1;                                       
    byte PTBSE5      :1;                                       
    byte PTBSE6      :1;                                       
    byte PTBSE7      :1;                                       
  } Bits;
} PTBSESTR;
volatile PTBSESTR __at (0x1849) _PTBSE;
#define PTBSE                           _PTBSE.Byte
#define PTBSE_PTBSE0                    _PTBSE.Bits.PTBSE0
#define PTBSE_PTBSE1                    _PTBSE.Bits.PTBSE1
#define PTBSE_PTBSE2                    _PTBSE.Bits.PTBSE2
#define PTBSE_PTBSE3                    _PTBSE.Bits.PTBSE3
#define PTBSE_PTBSE4                    _PTBSE.Bits.PTBSE4
#define PTBSE_PTBSE5                    _PTBSE.Bits.PTBSE5
#define PTBSE_PTBSE6                    _PTBSE.Bits.PTBSE6
#define PTBSE_PTBSE7                    _PTBSE.Bits.PTBSE7

#define PTBSE_PTBSE0_MASK               1
#define PTBSE_PTBSE1_MASK               2
#define PTBSE_PTBSE2_MASK               4
#define PTBSE_PTBSE3_MASK               8
#define PTBSE_PTBSE4_MASK               16
#define PTBSE_PTBSE5_MASK               32
#define PTBSE_PTBSE6_MASK               64
#define PTBSE_PTBSE7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTBDS0      :1;                                       
    byte PTBDS1      :1;                                       
    byte PTBDS2      :1;                                       
    byte PTBDS3      :1;                                       
    byte PTBDS4      :1;                                       
    byte PTBDS5      :1;                                       
    byte PTBDS6      :1;                                       
    byte PTBDS7      :1;                                       
  } Bits;
} PTBDSSTR;
volatile PTBDSSTR __at (0x184A) _PTBDS;
#define PTBDS                           _PTBDS.Byte
#define PTBDS_PTBDS0                    _PTBDS.Bits.PTBDS0
#define PTBDS_PTBDS1                    _PTBDS.Bits.PTBDS1
#define PTBDS_PTBDS2                    _PTBDS.Bits.PTBDS2
#define PTBDS_PTBDS3                    _PTBDS.Bits.PTBDS3
#define PTBDS_PTBDS4                    _PTBDS.Bits.PTBDS4
#define PTBDS_PTBDS5                    _PTBDS.Bits.PTBDS5
#define PTBDS_PTBDS6                    _PTBDS.Bits.PTBDS6
#define PTBDS_PTBDS7                    _PTBDS.Bits.PTBDS7

#define PTBDS_PTBDS0_MASK               1
#define PTBDS_PTBDS1_MASK               2
#define PTBDS_PTBDS2_MASK               4
#define PTBDS_PTBDS3_MASK               8
#define PTBDS_PTBDS4_MASK               16
#define PTBDS_PTBDS5_MASK               32
#define PTBDS_PTBDS6_MASK               64
#define PTBDS_PTBDS7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTBMOD      :1;                                       
    byte PTBIE       :1;                                       
    byte PTBACK      :1;                                       
    byte PTBIF       :1;                                       
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} PTBSCSTR;
volatile PTBSCSTR __at (0x184C) _PTBSC;
#define PTBSC                           _PTBSC.Byte
#define PTBSC_PTBMOD                    _PTBSC.Bits.PTBMOD
#define PTBSC_PTBIE                     _PTBSC.Bits.PTBIE
#define PTBSC_PTBACK                    _PTBSC.Bits.PTBACK
#define PTBSC_PTBIF                     _PTBSC.Bits.PTBIF

#define PTBSC_PTBMOD_MASK               1
#define PTBSC_PTBIE_MASK                2
#define PTBSC_PTBACK_MASK               4
#define PTBSC_PTBIF_MASK                8



typedef union {
  byte Byte;
  struct {
    byte PTBPS0      :1;                                       
    byte PTBPS1      :1;                                       
    byte PTBPS2      :1;                                       
    byte PTBPS3      :1;                                       
    byte PTBPS4      :1;                                       
    byte PTBPS5      :1;                                       
    byte PTBPS6      :1;                                       
    byte PTBPS7      :1;                                       
  } Bits;
} PTBPSSTR;
volatile PTBPSSTR __at (0x184D) _PTBPS;
#define PTBPS                           _PTBPS.Byte
#define PTBPS_PTBPS0                    _PTBPS.Bits.PTBPS0
#define PTBPS_PTBPS1                    _PTBPS.Bits.PTBPS1
#define PTBPS_PTBPS2                    _PTBPS.Bits.PTBPS2
#define PTBPS_PTBPS3                    _PTBPS.Bits.PTBPS3
#define PTBPS_PTBPS4                    _PTBPS.Bits.PTBPS4
#define PTBPS_PTBPS5                    _PTBPS.Bits.PTBPS5
#define PTBPS_PTBPS6                    _PTBPS.Bits.PTBPS6
#define PTBPS_PTBPS7                    _PTBPS.Bits.PTBPS7

#define PTBPS_PTBPS0_MASK               1
#define PTBPS_PTBPS1_MASK               2
#define PTBPS_PTBPS2_MASK               4
#define PTBPS_PTBPS3_MASK               8
#define PTBPS_PTBPS4_MASK               16
#define PTBPS_PTBPS5_MASK               32
#define PTBPS_PTBPS6_MASK               64
#define PTBPS_PTBPS7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTBES0      :1;                                       
    byte PTBES1      :1;                                       
    byte PTBES2      :1;                                       
    byte PTBES3      :1;                                       
    byte PTBES4      :1;                                       
    byte PTBES5      :1;                                       
    byte PTBES6      :1;                                       
    byte PTBES7      :1;                                       
  } Bits;
} PTBESSTR;
volatile PTBESSTR __at (0x184E) _PTBES;
#define PTBES                           _PTBES.Byte
#define PTBES_PTBES0                    _PTBES.Bits.PTBES0
#define PTBES_PTBES1                    _PTBES.Bits.PTBES1
#define PTBES_PTBES2                    _PTBES.Bits.PTBES2
#define PTBES_PTBES3                    _PTBES.Bits.PTBES3
#define PTBES_PTBES4                    _PTBES.Bits.PTBES4
#define PTBES_PTBES5                    _PTBES.Bits.PTBES5
#define PTBES_PTBES6                    _PTBES.Bits.PTBES6
#define PTBES_PTBES7                    _PTBES.Bits.PTBES7

#define PTBES_PTBES0_MASK               1
#define PTBES_PTBES1_MASK               2
#define PTBES_PTBES2_MASK               4
#define PTBES_PTBES3_MASK               8
#define PTBES_PTBES4_MASK               16
#define PTBES_PTBES5_MASK               32
#define PTBES_PTBES6_MASK               64
#define PTBES_PTBES7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTCPE0      :1;                                       
    byte PTCPE1      :1;                                       
    byte PTCPE2      :1;                                       
    byte PTCPE3      :1;                                       
    byte PTCPE4      :1;                                       
    byte PTCPE5      :1;                                       
    byte PTCPE6      :1;                                       
    byte PTCPE7      :1;                                       
  } Bits;
} PTCPESTR;
volatile PTCPESTR __at (0x1850) _PTCPE;
#define PTCPE                           _PTCPE.Byte
#define PTCPE_PTCPE0                    _PTCPE.Bits.PTCPE0
#define PTCPE_PTCPE1                    _PTCPE.Bits.PTCPE1
#define PTCPE_PTCPE2                    _PTCPE.Bits.PTCPE2
#define PTCPE_PTCPE3                    _PTCPE.Bits.PTCPE3
#define PTCPE_PTCPE4                    _PTCPE.Bits.PTCPE4
#define PTCPE_PTCPE5                    _PTCPE.Bits.PTCPE5
#define PTCPE_PTCPE6                    _PTCPE.Bits.PTCPE6
#define PTCPE_PTCPE7                    _PTCPE.Bits.PTCPE7

#define PTCPE_PTCPE0_MASK               1
#define PTCPE_PTCPE1_MASK               2
#define PTCPE_PTCPE2_MASK               4
#define PTCPE_PTCPE3_MASK               8
#define PTCPE_PTCPE4_MASK               16
#define PTCPE_PTCPE5_MASK               32
#define PTCPE_PTCPE6_MASK               64
#define PTCPE_PTCPE7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTCSE0      :1;                                       
    byte PTCSE1      :1;                                       
    byte PTCSE2      :1;                                       
    byte PTCSE3      :1;                                       
    byte PTCSE4      :1;                                       
    byte PTCSE5      :1;                                       
    byte PTCSE6      :1;                                       
    byte PTCSE7      :1;                                       
  } Bits;
} PTCSESTR;
volatile PTCSESTR __at (0x1851) _PTCSE;
#define PTCSE                           _PTCSE.Byte
#define PTCSE_PTCSE0                    _PTCSE.Bits.PTCSE0
#define PTCSE_PTCSE1                    _PTCSE.Bits.PTCSE1
#define PTCSE_PTCSE2                    _PTCSE.Bits.PTCSE2
#define PTCSE_PTCSE3                    _PTCSE.Bits.PTCSE3
#define PTCSE_PTCSE4                    _PTCSE.Bits.PTCSE4
#define PTCSE_PTCSE5                    _PTCSE.Bits.PTCSE5
#define PTCSE_PTCSE6                    _PTCSE.Bits.PTCSE6
#define PTCSE_PTCSE7                    _PTCSE.Bits.PTCSE7

#define PTCSE_PTCSE0_MASK               1
#define PTCSE_PTCSE1_MASK               2
#define PTCSE_PTCSE2_MASK               4
#define PTCSE_PTCSE3_MASK               8
#define PTCSE_PTCSE4_MASK               16
#define PTCSE_PTCSE5_MASK               32
#define PTCSE_PTCSE6_MASK               64
#define PTCSE_PTCSE7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTCDS0      :1;                                       
    byte PTCDS1      :1;                                       
    byte PTCDS2      :1;                                       
    byte PTCDS3      :1;                                       
    byte PTCDS4      :1;                                       
    byte PTCDS5      :1;                                       
    byte PTCDS6      :1;                                       
    byte PTCDS7      :1;                                       
  } Bits;
} PTCDSSTR;
volatile PTCDSSTR __at (0x1852) _PTCDS;
#define PTCDS                           _PTCDS.Byte
#define PTCDS_PTCDS0                    _PTCDS.Bits.PTCDS0
#define PTCDS_PTCDS1                    _PTCDS.Bits.PTCDS1
#define PTCDS_PTCDS2                    _PTCDS.Bits.PTCDS2
#define PTCDS_PTCDS3                    _PTCDS.Bits.PTCDS3
#define PTCDS_PTCDS4                    _PTCDS.Bits.PTCDS4
#define PTCDS_PTCDS5                    _PTCDS.Bits.PTCDS5
#define PTCDS_PTCDS6                    _PTCDS.Bits.PTCDS6
#define PTCDS_PTCDS7                    _PTCDS.Bits.PTCDS7

#define PTCDS_PTCDS0_MASK               1
#define PTCDS_PTCDS1_MASK               2
#define PTCDS_PTCDS2_MASK               4
#define PTCDS_PTCDS3_MASK               8
#define PTCDS_PTCDS4_MASK               16
#define PTCDS_PTCDS5_MASK               32
#define PTCDS_PTCDS6_MASK               64
#define PTCDS_PTCDS7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTDPE0      :1;                                       
    byte PTDPE1      :1;                                       
    byte PTDPE2      :1;                                       
    byte PTDPE3      :1;                                       
    byte PTDPE4      :1;                                       
    byte PTDPE5      :1;                                       
    byte PTDPE6      :1;                                       
    byte PTDPE7      :1;                                       
  } Bits;
} PTDPESTR;
volatile PTDPESTR __at (0x1858) _PTDPE;
#define PTDPE                           _PTDPE.Byte
#define PTDPE_PTDPE0                    _PTDPE.Bits.PTDPE0
#define PTDPE_PTDPE1                    _PTDPE.Bits.PTDPE1
#define PTDPE_PTDPE2                    _PTDPE.Bits.PTDPE2
#define PTDPE_PTDPE3                    _PTDPE.Bits.PTDPE3
#define PTDPE_PTDPE4                    _PTDPE.Bits.PTDPE4
#define PTDPE_PTDPE5                    _PTDPE.Bits.PTDPE5
#define PTDPE_PTDPE6                    _PTDPE.Bits.PTDPE6
#define PTDPE_PTDPE7                    _PTDPE.Bits.PTDPE7

#define PTDPE_PTDPE0_MASK               1
#define PTDPE_PTDPE1_MASK               2
#define PTDPE_PTDPE2_MASK               4
#define PTDPE_PTDPE3_MASK               8
#define PTDPE_PTDPE4_MASK               16
#define PTDPE_PTDPE5_MASK               32
#define PTDPE_PTDPE6_MASK               64
#define PTDPE_PTDPE7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTDSE0      :1;                                       
    byte PTDSE1      :1;                                       
    byte PTDSE2      :1;                                       
    byte PTDSE3      :1;                                       
    byte PTDSE4      :1;                                       
    byte PTDSE5      :1;                                       
    byte PTDSE6      :1;                                       
    byte PTDSE7      :1;                                       
  } Bits;
} PTDSESTR;
volatile PTDSESTR __at (0x1859) _PTDSE;
#define PTDSE                           _PTDSE.Byte
#define PTDSE_PTDSE0                    _PTDSE.Bits.PTDSE0
#define PTDSE_PTDSE1                    _PTDSE.Bits.PTDSE1
#define PTDSE_PTDSE2                    _PTDSE.Bits.PTDSE2
#define PTDSE_PTDSE3                    _PTDSE.Bits.PTDSE3
#define PTDSE_PTDSE4                    _PTDSE.Bits.PTDSE4
#define PTDSE_PTDSE5                    _PTDSE.Bits.PTDSE5
#define PTDSE_PTDSE6                    _PTDSE.Bits.PTDSE6
#define PTDSE_PTDSE7                    _PTDSE.Bits.PTDSE7

#define PTDSE_PTDSE0_MASK               1
#define PTDSE_PTDSE1_MASK               2
#define PTDSE_PTDSE2_MASK               4
#define PTDSE_PTDSE3_MASK               8
#define PTDSE_PTDSE4_MASK               16
#define PTDSE_PTDSE5_MASK               32
#define PTDSE_PTDSE6_MASK               64
#define PTDSE_PTDSE7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTDDS0      :1;                                       
    byte PTDDS1      :1;                                       
    byte PTDDS2      :1;                                       
    byte PTDDS3      :1;                                       
    byte PTDDS4      :1;                                       
    byte PTDDS5      :1;                                       
    byte PTDDS6      :1;                                       
    byte PTDDS7      :1;                                       
  } Bits;
} PTDDSSTR;
volatile PTDDSSTR __at (0x185A) _PTDDS;
#define PTDDS                           _PTDDS.Byte
#define PTDDS_PTDDS0                    _PTDDS.Bits.PTDDS0
#define PTDDS_PTDDS1                    _PTDDS.Bits.PTDDS1
#define PTDDS_PTDDS2                    _PTDDS.Bits.PTDDS2
#define PTDDS_PTDDS3                    _PTDDS.Bits.PTDDS3
#define PTDDS_PTDDS4                    _PTDDS.Bits.PTDDS4
#define PTDDS_PTDDS5                    _PTDDS.Bits.PTDDS5
#define PTDDS_PTDDS6                    _PTDDS.Bits.PTDDS6
#define PTDDS_PTDDS7                    _PTDDS.Bits.PTDDS7

#define PTDDS_PTDDS0_MASK               1
#define PTDDS_PTDDS1_MASK               2
#define PTDDS_PTDDS2_MASK               4
#define PTDDS_PTDDS3_MASK               8
#define PTDDS_PTDDS4_MASK               16
#define PTDDS_PTDDS5_MASK               32
#define PTDDS_PTDDS6_MASK               64
#define PTDDS_PTDDS7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTDMOD      :1;                                       
    byte PTDIE       :1;                                       
    byte PTDACK      :1;                                       
    byte PTDIF       :1;                                       
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} PTDSCSTR;
volatile PTDSCSTR __at (0x185C) _PTDSC;
#define PTDSC                           _PTDSC.Byte
#define PTDSC_PTDMOD                    _PTDSC.Bits.PTDMOD
#define PTDSC_PTDIE                     _PTDSC.Bits.PTDIE
#define PTDSC_PTDACK                    _PTDSC.Bits.PTDACK
#define PTDSC_PTDIF                     _PTDSC.Bits.PTDIF

#define PTDSC_PTDMOD_MASK               1
#define PTDSC_PTDIE_MASK                2
#define PTDSC_PTDACK_MASK               4
#define PTDSC_PTDIF_MASK                8



typedef union {
  byte Byte;
  struct {
    byte PTDPS0      :1;                                       
    byte PTDPS1      :1;                                       
    byte PTDPS2      :1;                                       
    byte PTDPS3      :1;                                       
    byte PTDPS4      :1;                                       
    byte PTDPS5      :1;                                       
    byte PTDPS6      :1;                                       
    byte PTDPS7      :1;                                       
  } Bits;
} PTDPSSTR;
volatile PTDPSSTR __at (0x185D) _PTDPS;
#define PTDPS                           _PTDPS.Byte
#define PTDPS_PTDPS0                    _PTDPS.Bits.PTDPS0
#define PTDPS_PTDPS1                    _PTDPS.Bits.PTDPS1
#define PTDPS_PTDPS2                    _PTDPS.Bits.PTDPS2
#define PTDPS_PTDPS3                    _PTDPS.Bits.PTDPS3
#define PTDPS_PTDPS4                    _PTDPS.Bits.PTDPS4
#define PTDPS_PTDPS5                    _PTDPS.Bits.PTDPS5
#define PTDPS_PTDPS6                    _PTDPS.Bits.PTDPS6
#define PTDPS_PTDPS7                    _PTDPS.Bits.PTDPS7

#define PTDPS_PTDPS0_MASK               1
#define PTDPS_PTDPS1_MASK               2
#define PTDPS_PTDPS2_MASK               4
#define PTDPS_PTDPS3_MASK               8
#define PTDPS_PTDPS4_MASK               16
#define PTDPS_PTDPS5_MASK               32
#define PTDPS_PTDPS6_MASK               64
#define PTDPS_PTDPS7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTDES0      :1;                                       
    byte PTDES1      :1;                                       
    byte PTDES2      :1;                                       
    byte PTDES3      :1;                                       
    byte PTDES4      :1;                                       
    byte PTDES5      :1;                                       
    byte PTDES6      :1;                                       
    byte PTDES7      :1;                                       
  } Bits;
} PTDESSTR;
volatile PTDESSTR __at (0x185E) _PTDES;
#define PTDES                           _PTDES.Byte
#define PTDES_PTDES0                    _PTDES.Bits.PTDES0
#define PTDES_PTDES1                    _PTDES.Bits.PTDES1
#define PTDES_PTDES2                    _PTDES.Bits.PTDES2
#define PTDES_PTDES3                    _PTDES.Bits.PTDES3
#define PTDES_PTDES4                    _PTDES.Bits.PTDES4
#define PTDES_PTDES5                    _PTDES.Bits.PTDES5
#define PTDES_PTDES6                    _PTDES.Bits.PTDES6
#define PTDES_PTDES7                    _PTDES.Bits.PTDES7

#define PTDES_PTDES0_MASK               1
#define PTDES_PTDES1_MASK               2
#define PTDES_PTDES2_MASK               4
#define PTDES_PTDES3_MASK               8
#define PTDES_PTDES4_MASK               16
#define PTDES_PTDES5_MASK               32
#define PTDES_PTDES6_MASK               64
#define PTDES_PTDES7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTEPE0      :1;                                       
    byte PTEPE1      :1;                                       
    byte PTEPE2      :1;                                       
    byte PTEPE3      :1;                                       
    byte PTEPE4      :1;                                       
    byte PTEPE5      :1;                                       
    byte PTEPE6      :1;                                       
    byte PTEPE7      :1;                                       
  } Bits;
} PTEPESTR;
volatile PTEPESTR __at (0x1860) _PTEPE;
#define PTEPE                           _PTEPE.Byte
#define PTEPE_PTEPE0                    _PTEPE.Bits.PTEPE0
#define PTEPE_PTEPE1                    _PTEPE.Bits.PTEPE1
#define PTEPE_PTEPE2                    _PTEPE.Bits.PTEPE2
#define PTEPE_PTEPE3                    _PTEPE.Bits.PTEPE3
#define PTEPE_PTEPE4                    _PTEPE.Bits.PTEPE4
#define PTEPE_PTEPE5                    _PTEPE.Bits.PTEPE5
#define PTEPE_PTEPE6                    _PTEPE.Bits.PTEPE6
#define PTEPE_PTEPE7                    _PTEPE.Bits.PTEPE7

#define PTEPE_PTEPE0_MASK               1
#define PTEPE_PTEPE1_MASK               2
#define PTEPE_PTEPE2_MASK               4
#define PTEPE_PTEPE3_MASK               8
#define PTEPE_PTEPE4_MASK               16
#define PTEPE_PTEPE5_MASK               32
#define PTEPE_PTEPE6_MASK               64
#define PTEPE_PTEPE7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTESE0      :1;                                       
    byte PTESE1      :1;                                       
    byte PTESE2      :1;                                       
    byte PTESE3      :1;                                       
    byte PTESE4      :1;                                       
    byte PTESE5      :1;                                       
    byte PTESE6      :1;                                       
    byte PTESE7      :1;                                       
  } Bits;
} PTESESTR;
volatile PTESESTR __at (0x1861) _PTESE;
#define PTESE                           _PTESE.Byte
#define PTESE_PTESE0                    _PTESE.Bits.PTESE0
#define PTESE_PTESE1                    _PTESE.Bits.PTESE1
#define PTESE_PTESE2                    _PTESE.Bits.PTESE2
#define PTESE_PTESE3                    _PTESE.Bits.PTESE3
#define PTESE_PTESE4                    _PTESE.Bits.PTESE4
#define PTESE_PTESE5                    _PTESE.Bits.PTESE5
#define PTESE_PTESE6                    _PTESE.Bits.PTESE6
#define PTESE_PTESE7                    _PTESE.Bits.PTESE7

#define PTESE_PTESE0_MASK               1
#define PTESE_PTESE1_MASK               2
#define PTESE_PTESE2_MASK               4
#define PTESE_PTESE3_MASK               8
#define PTESE_PTESE4_MASK               16
#define PTESE_PTESE5_MASK               32
#define PTESE_PTESE6_MASK               64
#define PTESE_PTESE7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTEDS0      :1;                                       
    byte PTEDS1      :1;                                       
    byte PTEDS2      :1;                                       
    byte PTEDS3      :1;                                       
    byte PTEDS4      :1;                                       
    byte PTEDS5      :1;                                       
    byte PTEDS6      :1;                                       
    byte PTEDS7      :1;                                       
  } Bits;
} PTEDSSTR;
volatile PTEDSSTR __at (0x1862) _PTEDS;
#define PTEDS                           _PTEDS.Byte
#define PTEDS_PTEDS0                    _PTEDS.Bits.PTEDS0
#define PTEDS_PTEDS1                    _PTEDS.Bits.PTEDS1
#define PTEDS_PTEDS2                    _PTEDS.Bits.PTEDS2
#define PTEDS_PTEDS3                    _PTEDS.Bits.PTEDS3
#define PTEDS_PTEDS4                    _PTEDS.Bits.PTEDS4
#define PTEDS_PTEDS5                    _PTEDS.Bits.PTEDS5
#define PTEDS_PTEDS6                    _PTEDS.Bits.PTEDS6
#define PTEDS_PTEDS7                    _PTEDS.Bits.PTEDS7

#define PTEDS_PTEDS0_MASK               1
#define PTEDS_PTEDS1_MASK               2
#define PTEDS_PTEDS2_MASK               4
#define PTEDS_PTEDS3_MASK               8
#define PTEDS_PTEDS4_MASK               16
#define PTEDS_PTEDS5_MASK               32
#define PTEDS_PTEDS6_MASK               64
#define PTEDS_PTEDS7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTFPE0      :1;                                       
    byte PTFPE1      :1;                                       
    byte PTFPE2      :1;                                       
    byte PTFPE3      :1;                                       
    byte PTFPE4      :1;                                       
    byte PTFPE5      :1;                                       
    byte PTFPE6      :1;                                       
    byte PTFPE7      :1;                                       
  } Bits;
} PTFPESTR;
volatile PTFPESTR __at (0x1868) _PTFPE;
#define PTFPE                           _PTFPE.Byte
#define PTFPE_PTFPE0                    _PTFPE.Bits.PTFPE0
#define PTFPE_PTFPE1                    _PTFPE.Bits.PTFPE1
#define PTFPE_PTFPE2                    _PTFPE.Bits.PTFPE2
#define PTFPE_PTFPE3                    _PTFPE.Bits.PTFPE3
#define PTFPE_PTFPE4                    _PTFPE.Bits.PTFPE4
#define PTFPE_PTFPE5                    _PTFPE.Bits.PTFPE5
#define PTFPE_PTFPE6                    _PTFPE.Bits.PTFPE6
#define PTFPE_PTFPE7                    _PTFPE.Bits.PTFPE7

#define PTFPE_PTFPE0_MASK               1
#define PTFPE_PTFPE1_MASK               2
#define PTFPE_PTFPE2_MASK               4
#define PTFPE_PTFPE3_MASK               8
#define PTFPE_PTFPE4_MASK               16
#define PTFPE_PTFPE5_MASK               32
#define PTFPE_PTFPE6_MASK               64
#define PTFPE_PTFPE7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTFSE0      :1;                                       
    byte PTFSE1      :1;                                       
    byte PTFSE2      :1;                                       
    byte PTFSE3      :1;                                       
    byte PTFSE4      :1;                                       
    byte PTFSE5      :1;                                       
    byte PTFSE6      :1;                                       
    byte PTFSE7      :1;                                       
  } Bits;
} PTFSESTR;
volatile PTFSESTR __at (0x1869) _PTFSE;
#define PTFSE                           _PTFSE.Byte
#define PTFSE_PTFSE0                    _PTFSE.Bits.PTFSE0
#define PTFSE_PTFSE1                    _PTFSE.Bits.PTFSE1
#define PTFSE_PTFSE2                    _PTFSE.Bits.PTFSE2
#define PTFSE_PTFSE3                    _PTFSE.Bits.PTFSE3
#define PTFSE_PTFSE4                    _PTFSE.Bits.PTFSE4
#define PTFSE_PTFSE5                    _PTFSE.Bits.PTFSE5
#define PTFSE_PTFSE6                    _PTFSE.Bits.PTFSE6
#define PTFSE_PTFSE7                    _PTFSE.Bits.PTFSE7

#define PTFSE_PTFSE0_MASK               1
#define PTFSE_PTFSE1_MASK               2
#define PTFSE_PTFSE2_MASK               4
#define PTFSE_PTFSE3_MASK               8
#define PTFSE_PTFSE4_MASK               16
#define PTFSE_PTFSE5_MASK               32
#define PTFSE_PTFSE6_MASK               64
#define PTFSE_PTFSE7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTFDS0      :1;                                       
    byte PTFDS1      :1;                                       
    byte PTFDS2      :1;                                       
    byte PTFDS3      :1;                                       
    byte PTFDS4      :1;                                       
    byte PTFDS5      :1;                                       
    byte PTFDS6      :1;                                       
    byte PTFDS7      :1;                                       
  } Bits;
} PTFDSSTR;
volatile PTFDSSTR __at (0x186A) _PTFDS;
#define PTFDS                           _PTFDS.Byte
#define PTFDS_PTFDS0                    _PTFDS.Bits.PTFDS0
#define PTFDS_PTFDS1                    _PTFDS.Bits.PTFDS1
#define PTFDS_PTFDS2                    _PTFDS.Bits.PTFDS2
#define PTFDS_PTFDS3                    _PTFDS.Bits.PTFDS3
#define PTFDS_PTFDS4                    _PTFDS.Bits.PTFDS4
#define PTFDS_PTFDS5                    _PTFDS.Bits.PTFDS5
#define PTFDS_PTFDS6                    _PTFDS.Bits.PTFDS6
#define PTFDS_PTFDS7                    _PTFDS.Bits.PTFDS7

#define PTFDS_PTFDS0_MASK               1
#define PTFDS_PTFDS1_MASK               2
#define PTFDS_PTFDS2_MASK               4
#define PTFDS_PTFDS3_MASK               8
#define PTFDS_PTFDS4_MASK               16
#define PTFDS_PTFDS5_MASK               32
#define PTFDS_PTFDS6_MASK               64
#define PTFDS_PTFDS7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte PTGPE0      :1;                                       
    byte PTGPE1      :1;                                       
    byte PTGPE2      :1;                                       
    byte PTGPE3      :1;                                       
    byte PTGPE4      :1;                                       
    byte PTGPE5      :1;                                       
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTGPE :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTGPESTR;
volatile PTGPESTR __at (0x1870) _PTGPE;
#define PTGPE                           _PTGPE.Byte
#define PTGPE_PTGPE0                    _PTGPE.Bits.PTGPE0
#define PTGPE_PTGPE1                    _PTGPE.Bits.PTGPE1
#define PTGPE_PTGPE2                    _PTGPE.Bits.PTGPE2
#define PTGPE_PTGPE3                    _PTGPE.Bits.PTGPE3
#define PTGPE_PTGPE4                    _PTGPE.Bits.PTGPE4
#define PTGPE_PTGPE5                    _PTGPE.Bits.PTGPE5
#define PTGPE_PTGPE                     _PTGPE.MergedBits.grpPTGPE

#define PTGPE_PTGPE0_MASK               1
#define PTGPE_PTGPE1_MASK               2
#define PTGPE_PTGPE2_MASK               4
#define PTGPE_PTGPE3_MASK               8
#define PTGPE_PTGPE4_MASK               16
#define PTGPE_PTGPE5_MASK               32
#define PTGPE_PTGPE_MASK                63
#define PTGPE_PTGPE_BITNUM              0



typedef union {
  byte Byte;
  struct {
    byte PTGSE0      :1;                                       
    byte PTGSE1      :1;                                       
    byte PTGSE2      :1;                                       
    byte PTGSE3      :1;                                       
    byte PTGSE4      :1;                                       
    byte PTGSE5      :1;                                       
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTGSE :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTGSESTR;
volatile PTGSESTR __at (0x1871) _PTGSE;
#define PTGSE                           _PTGSE.Byte
#define PTGSE_PTGSE0                    _PTGSE.Bits.PTGSE0
#define PTGSE_PTGSE1                    _PTGSE.Bits.PTGSE1
#define PTGSE_PTGSE2                    _PTGSE.Bits.PTGSE2
#define PTGSE_PTGSE3                    _PTGSE.Bits.PTGSE3
#define PTGSE_PTGSE4                    _PTGSE.Bits.PTGSE4
#define PTGSE_PTGSE5                    _PTGSE.Bits.PTGSE5
#define PTGSE_PTGSE                     _PTGSE.MergedBits.grpPTGSE

#define PTGSE_PTGSE0_MASK               1
#define PTGSE_PTGSE1_MASK               2
#define PTGSE_PTGSE2_MASK               4
#define PTGSE_PTGSE3_MASK               8
#define PTGSE_PTGSE4_MASK               16
#define PTGSE_PTGSE5_MASK               32
#define PTGSE_PTGSE_MASK                63
#define PTGSE_PTGSE_BITNUM              0



typedef union {
  byte Byte;
  struct {
    byte PTGDS0      :1;                                       
    byte PTGDS1      :1;                                       
    byte PTGDS2      :1;                                       
    byte PTGDS3      :1;                                       
    byte PTGDS4      :1;                                       
    byte PTGDS5      :1;                                       
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTGDS :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTGDSSTR;
volatile PTGDSSTR __at (0x1872) _PTGDS;
#define PTGDS                           _PTGDS.Byte
#define PTGDS_PTGDS0                    _PTGDS.Bits.PTGDS0
#define PTGDS_PTGDS1                    _PTGDS.Bits.PTGDS1
#define PTGDS_PTGDS2                    _PTGDS.Bits.PTGDS2
#define PTGDS_PTGDS3                    _PTGDS.Bits.PTGDS3
#define PTGDS_PTGDS4                    _PTGDS.Bits.PTGDS4
#define PTGDS_PTGDS5                    _PTGDS.Bits.PTGDS5
#define PTGDS_PTGDS                     _PTGDS.MergedBits.grpPTGDS

#define PTGDS_PTGDS0_MASK               1
#define PTGDS_PTGDS1_MASK               2
#define PTGDS_PTGDS2_MASK               4
#define PTGDS_PTGDS3_MASK               8
#define PTGDS_PTGDS4_MASK               16
#define PTGDS_PTGDS5_MASK               32
#define PTGDS_PTGDS_MASK                63
#define PTGDS_PTGDS_BITNUM              0



typedef union {
  byte Byte;
  struct {
    byte INITRQ      :1;                                       
    byte SLPRQ       :1;                                       
    byte WUPE        :1;                                       
    byte TIME        :1;                                       
    byte SYNCH       :1;                                       
    byte CSWAI       :1;                                       
    byte RXACT       :1;                                       
    byte RXFRM       :1;                                       
  } Bits;
} CANCTL0STR;
volatile CANCTL0STR __at (0x1880) _CANCTL0;
#define CANCTL0                         _CANCTL0.Byte
#define CANCTL0_INITRQ                  _CANCTL0.Bits.INITRQ
#define CANCTL0_SLPRQ                   _CANCTL0.Bits.SLPRQ
#define CANCTL0_WUPE                    _CANCTL0.Bits.WUPE
#define CANCTL0_TIME                    _CANCTL0.Bits.TIME
#define CANCTL0_SYNCH                   _CANCTL0.Bits.SYNCH
#define CANCTL0_CSWAI                   _CANCTL0.Bits.CSWAI
#define CANCTL0_RXACT                   _CANCTL0.Bits.RXACT
#define CANCTL0_RXFRM                   _CANCTL0.Bits.RXFRM

#define CANCTL_ARR                      ((volatile byte * __far) &CANCTL0)

#define CANCTL0_INITRQ_MASK             1
#define CANCTL0_SLPRQ_MASK              2
#define CANCTL0_WUPE_MASK               4
#define CANCTL0_TIME_MASK               8
#define CANCTL0_SYNCH_MASK              16
#define CANCTL0_CSWAI_MASK              32
#define CANCTL0_RXACT_MASK              64
#define CANCTL0_RXFRM_MASK              128



typedef union {
  byte Byte;
  struct {
    byte INITAK      :1;                                       
    byte SLPAK       :1;                                       
    byte WUPM        :1;                                       
    byte BORM        :1;                                       
    byte LISTEN      :1;                                       
    byte LOOPB       :1;                                       
    byte CLKSRC      :1;                                       
    byte CANE        :1;                                       
  } Bits;
} CANCTL1STR;
volatile CANCTL1STR __at (0x1881) _CANCTL1;
#define CANCTL1                         _CANCTL1.Byte
#define CANCTL1_INITAK                  _CANCTL1.Bits.INITAK
#define CANCTL1_SLPAK                   _CANCTL1.Bits.SLPAK
#define CANCTL1_WUPM                    _CANCTL1.Bits.WUPM
#define CANCTL1_BORM                    _CANCTL1.Bits.BORM
#define CANCTL1_LISTEN                  _CANCTL1.Bits.LISTEN
#define CANCTL1_LOOPB                   _CANCTL1.Bits.LOOPB
#define CANCTL1_CLKSRC                  _CANCTL1.Bits.CLKSRC
#define CANCTL1_CANE                    _CANCTL1.Bits.CANE

#define CANCTL1_INITAK_MASK             1
#define CANCTL1_SLPAK_MASK              2
#define CANCTL1_WUPM_MASK               4
#define CANCTL1_BORM_MASK               8
#define CANCTL1_LISTEN_MASK             16
#define CANCTL1_LOOPB_MASK              32
#define CANCTL1_CLKSRC_MASK             64
#define CANCTL1_CANE_MASK               128



typedef union {
  byte Byte;
  struct {
    byte BRP0        :1;                                       
    byte BRP1        :1;                                       
    byte BRP2        :1;                                       
    byte BRP3        :1;                                       
    byte BRP4        :1;                                       
    byte BRP5        :1;                                       
    byte SJW0        :1;                                       
    byte SJW1        :1;                                       
  } Bits;
  struct {
    byte grpBRP  :6;
    byte grpSJW  :2;
  } MergedBits;
} CANBTR0STR;
volatile CANBTR0STR __at (0x1882) _CANBTR0;
#define CANBTR0                         _CANBTR0.Byte
#define CANBTR0_BRP0                    _CANBTR0.Bits.BRP0
#define CANBTR0_BRP1                    _CANBTR0.Bits.BRP1
#define CANBTR0_BRP2                    _CANBTR0.Bits.BRP2
#define CANBTR0_BRP3                    _CANBTR0.Bits.BRP3
#define CANBTR0_BRP4                    _CANBTR0.Bits.BRP4
#define CANBTR0_BRP5                    _CANBTR0.Bits.BRP5
#define CANBTR0_SJW0                    _CANBTR0.Bits.SJW0
#define CANBTR0_SJW1                    _CANBTR0.Bits.SJW1

#define CANBTR_ARR                      ((volatile byte * __far) &CANBTR0)
#define CANBTR0_BRP                     _CANBTR0.MergedBits.grpBRP
#define CANBTR0_SJW                     _CANBTR0.MergedBits.grpSJW

#define CANBTR0_BRP0_MASK               1
#define CANBTR0_BRP1_MASK               2
#define CANBTR0_BRP2_MASK               4
#define CANBTR0_BRP3_MASK               8
#define CANBTR0_BRP4_MASK               16
#define CANBTR0_BRP5_MASK               32
#define CANBTR0_SJW0_MASK               64
#define CANBTR0_SJW1_MASK               128
#define CANBTR0_BRP_MASK                63
#define CANBTR0_BRP_BITNUM              0
#define CANBTR0_SJW_MASK                192
#define CANBTR0_SJW_BITNUM              6



typedef union {
  byte Byte;
  struct {
    byte TSEG10      :1;                                       
    byte TSEG11      :1;                                       
    byte TSEG12      :1;                                       
    byte TSEG13      :1;                                       
    byte TSEG20      :1;                                       
    byte TSEG21      :1;                                       
    byte TSEG22      :1;                                       
    byte SAMP        :1;                                       
  } Bits;
  struct {
    byte grpTSEG_10 :4;
    byte grpTSEG_20 :3;
    byte         :1;
  } MergedBits;
} CANBTR1STR;
volatile CANBTR1STR __at (0x1883) _CANBTR1;
#define CANBTR1                         _CANBTR1.Byte
#define CANBTR1_TSEG10                  _CANBTR1.Bits.TSEG10
#define CANBTR1_TSEG11                  _CANBTR1.Bits.TSEG11
#define CANBTR1_TSEG12                  _CANBTR1.Bits.TSEG12
#define CANBTR1_TSEG13                  _CANBTR1.Bits.TSEG13
#define CANBTR1_TSEG20                  _CANBTR1.Bits.TSEG20
#define CANBTR1_TSEG21                  _CANBTR1.Bits.TSEG21
#define CANBTR1_TSEG22                  _CANBTR1.Bits.TSEG22
#define CANBTR1_SAMP                    _CANBTR1.Bits.SAMP
#define CANBTR1_TSEG_10                 _CANBTR1.MergedBits.grpTSEG_10
#define CANBTR1_TSEG_20                 _CANBTR1.MergedBits.grpTSEG_20
#define CANBTR1_TSEG                    CANBTR1_TSEG_10

#define CANBTR1_TSEG10_MASK             1
#define CANBTR1_TSEG11_MASK             2
#define CANBTR1_TSEG12_MASK             4
#define CANBTR1_TSEG13_MASK             8
#define CANBTR1_TSEG20_MASK             16
#define CANBTR1_TSEG21_MASK             32
#define CANBTR1_TSEG22_MASK             64
#define CANBTR1_SAMP_MASK               128
#define CANBTR1_TSEG_10_MASK            15
#define CANBTR1_TSEG_10_BITNUM          0
#define CANBTR1_TSEG_20_MASK            112
#define CANBTR1_TSEG_20_BITNUM          4



typedef union {
  byte Byte;
  struct {
    byte RXF         :1;                                       
    byte OVRIF       :1;                                       
    byte TSTAT0      :1;                                       
    byte TSTAT1      :1;                                       
    byte RSTAT0      :1;                                       
    byte RSTAT1      :1;                                       
    byte CSCIF       :1;                                       
    byte WUPIF       :1;                                       
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpTSTAT :2;
    byte grpRSTAT :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANRFLGSTR;
volatile CANRFLGSTR __at (0x1884) _CANRFLG;
#define CANRFLG                         _CANRFLG.Byte
#define CANRFLG_RXF                     _CANRFLG.Bits.RXF
#define CANRFLG_OVRIF                   _CANRFLG.Bits.OVRIF
#define CANRFLG_TSTAT0                  _CANRFLG.Bits.TSTAT0
#define CANRFLG_TSTAT1                  _CANRFLG.Bits.TSTAT1
#define CANRFLG_RSTAT0                  _CANRFLG.Bits.RSTAT0
#define CANRFLG_RSTAT1                  _CANRFLG.Bits.RSTAT1
#define CANRFLG_CSCIF                   _CANRFLG.Bits.CSCIF
#define CANRFLG_WUPIF                   _CANRFLG.Bits.WUPIF
#define CANRFLG_TSTAT                   _CANRFLG.MergedBits.grpTSTAT
#define CANRFLG_RSTAT                   _CANRFLG.MergedBits.grpRSTAT

#define CANRFLG_RXF_MASK                1
#define CANRFLG_OVRIF_MASK              2
#define CANRFLG_TSTAT0_MASK             4
#define CANRFLG_TSTAT1_MASK             8
#define CANRFLG_RSTAT0_MASK             16
#define CANRFLG_RSTAT1_MASK             32
#define CANRFLG_CSCIF_MASK              64
#define CANRFLG_WUPIF_MASK              128
#define CANRFLG_TSTAT_MASK              12
#define CANRFLG_TSTAT_BITNUM            2
#define CANRFLG_RSTAT_MASK              48
#define CANRFLG_RSTAT_BITNUM            4



typedef union {
  byte Byte;
  struct {
    byte RXFIE       :1;                                       
    byte OVRIE       :1;                                       
    byte TSTATE0     :1;                                       
    byte TSTATE1     :1;                                       
    byte RSTATE0     :1;                                       
    byte RSTATE1     :1;                                       
    byte CSCIE       :1;                                       
    byte WUPIE       :1;                                       
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpTSTATE :2;
    byte grpRSTATE :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANRIERSTR;
volatile CANRIERSTR __at (0x1885) _CANRIER;
#define CANRIER                         _CANRIER.Byte
#define CANRIER_RXFIE                   _CANRIER.Bits.RXFIE
#define CANRIER_OVRIE                   _CANRIER.Bits.OVRIE
#define CANRIER_TSTATE0                 _CANRIER.Bits.TSTATE0
#define CANRIER_TSTATE1                 _CANRIER.Bits.TSTATE1
#define CANRIER_RSTATE0                 _CANRIER.Bits.RSTATE0
#define CANRIER_RSTATE1                 _CANRIER.Bits.RSTATE1
#define CANRIER_CSCIE                   _CANRIER.Bits.CSCIE
#define CANRIER_WUPIE                   _CANRIER.Bits.WUPIE
#define CANRIER_TSTATE                  _CANRIER.MergedBits.grpTSTATE
#define CANRIER_RSTATE                  _CANRIER.MergedBits.grpRSTATE

#define CANRIER_RXFIE_MASK              1
#define CANRIER_OVRIE_MASK              2
#define CANRIER_TSTATE0_MASK            4
#define CANRIER_TSTATE1_MASK            8
#define CANRIER_RSTATE0_MASK            16
#define CANRIER_RSTATE1_MASK            32
#define CANRIER_CSCIE_MASK              64
#define CANRIER_WUPIE_MASK              128
#define CANRIER_TSTATE_MASK             12
#define CANRIER_TSTATE_BITNUM           2
#define CANRIER_RSTATE_MASK             48
#define CANRIER_RSTATE_BITNUM           4



typedef union {
  byte Byte;
  struct {
    byte TXE0        :1;                                       
    byte TXE1        :1;                                       
    byte TXE2        :1;                                       
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTXE  :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTFLGSTR;
volatile CANTFLGSTR __at (0x1886) _CANTFLG;
#define CANTFLG                         _CANTFLG.Byte
#define CANTFLG_TXE0                    _CANTFLG.Bits.TXE0
#define CANTFLG_TXE1                    _CANTFLG.Bits.TXE1
#define CANTFLG_TXE2                    _CANTFLG.Bits.TXE2
#define CANTFLG_TXE                     _CANTFLG.MergedBits.grpTXE

#define CANTFLG_TXE0_MASK               1
#define CANTFLG_TXE1_MASK               2
#define CANTFLG_TXE2_MASK               4
#define CANTFLG_TXE_MASK                7
#define CANTFLG_TXE_BITNUM              0



typedef union {
  byte Byte;
  struct {
    byte TXEIE0      :1;                                       
    byte TXEIE1      :1;                                       
    byte TXEIE2      :1;                                       
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTXEIE :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTIERSTR;
volatile CANTIERSTR __at (0x1887) _CANTIER;
#define CANTIER                         _CANTIER.Byte
#define CANTIER_TXEIE0                  _CANTIER.Bits.TXEIE0
#define CANTIER_TXEIE1                  _CANTIER.Bits.TXEIE1
#define CANTIER_TXEIE2                  _CANTIER.Bits.TXEIE2
#define CANTIER_TXEIE                   _CANTIER.MergedBits.grpTXEIE

#define CANTIER_TXEIE0_MASK             1
#define CANTIER_TXEIE1_MASK             2
#define CANTIER_TXEIE2_MASK             4
#define CANTIER_TXEIE_MASK              7
#define CANTIER_TXEIE_BITNUM            0



typedef union {
  byte Byte;
  struct {
    byte ABTRQ0      :1;                                       
    byte ABTRQ1      :1;                                       
    byte ABTRQ2      :1;                                       
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpABTRQ :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTARQSTR;
volatile CANTARQSTR __at (0x1888) _CANTARQ;
#define CANTARQ                         _CANTARQ.Byte
#define CANTARQ_ABTRQ0                  _CANTARQ.Bits.ABTRQ0
#define CANTARQ_ABTRQ1                  _CANTARQ.Bits.ABTRQ1
#define CANTARQ_ABTRQ2                  _CANTARQ.Bits.ABTRQ2
#define CANTARQ_ABTRQ                   _CANTARQ.MergedBits.grpABTRQ

#define CANTARQ_ABTRQ0_MASK             1
#define CANTARQ_ABTRQ1_MASK             2
#define CANTARQ_ABTRQ2_MASK             4
#define CANTARQ_ABTRQ_MASK              7
#define CANTARQ_ABTRQ_BITNUM            0



typedef union {
  byte Byte;
  struct {
    byte ABTAK0      :1;                                       
    byte ABTAK1      :1;                                       
    byte ABTAK2      :1;                                       
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpABTAK :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTAAKSTR;
volatile CANTAAKSTR __at (0x1889) _CANTAAK;
#define CANTAAK                         _CANTAAK.Byte
#define CANTAAK_ABTAK0                  _CANTAAK.Bits.ABTAK0
#define CANTAAK_ABTAK1                  _CANTAAK.Bits.ABTAK1
#define CANTAAK_ABTAK2                  _CANTAAK.Bits.ABTAK2
#define CANTAAK_ABTAK                   _CANTAAK.MergedBits.grpABTAK

#define CANTAAK_ABTAK0_MASK             1
#define CANTAAK_ABTAK1_MASK             2
#define CANTAAK_ABTAK2_MASK             4
#define CANTAAK_ABTAK_MASK              7
#define CANTAAK_ABTAK_BITNUM            0



typedef union {
  byte Byte;
  struct {
    byte TX0         :1;                                       
    byte TX1         :1;                                       
    byte TX2         :1;                                       
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTX   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTBSELSTR;
volatile CANTBSELSTR __at (0x188A) _CANTBSEL;
#define CANTBSEL                        _CANTBSEL.Byte
#define CANTBSEL_TX0                    _CANTBSEL.Bits.TX0
#define CANTBSEL_TX1                    _CANTBSEL.Bits.TX1
#define CANTBSEL_TX2                    _CANTBSEL.Bits.TX2
#define CANTBSEL_TX                     _CANTBSEL.MergedBits.grpTX

#define CANTBSEL_TX0_MASK               1
#define CANTBSEL_TX1_MASK               2
#define CANTBSEL_TX2_MASK               4
#define CANTBSEL_TX_MASK                7
#define CANTBSEL_TX_BITNUM              0



typedef union {
  byte Byte;
  struct {
    byte IDHIT0      :1;                                       
    byte IDHIT1      :1;                                       
    byte IDHIT2      :1;                                       
    byte             :1; 
    byte IDAM0       :1;                                       
    byte IDAM1       :1;                                       
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpIDHIT :3;
    byte         :1;
    byte grpIDAM :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANIDACSTR;
volatile CANIDACSTR __at (0x188B) _CANIDAC;
#define CANIDAC                         _CANIDAC.Byte
#define CANIDAC_IDHIT0                  _CANIDAC.Bits.IDHIT0
#define CANIDAC_IDHIT1                  _CANIDAC.Bits.IDHIT1
#define CANIDAC_IDHIT2                  _CANIDAC.Bits.IDHIT2
#define CANIDAC_IDAM0                   _CANIDAC.Bits.IDAM0
#define CANIDAC_IDAM1                   _CANIDAC.Bits.IDAM1
#define CANIDAC_IDHIT                   _CANIDAC.MergedBits.grpIDHIT
#define CANIDAC_IDAM                    _CANIDAC.MergedBits.grpIDAM

#define CANIDAC_IDHIT0_MASK             1
#define CANIDAC_IDHIT1_MASK             2
#define CANIDAC_IDHIT2_MASK             4
#define CANIDAC_IDAM0_MASK              16
#define CANIDAC_IDAM1_MASK              32
#define CANIDAC_IDHIT_MASK              7
#define CANIDAC_IDHIT_BITNUM            0
#define CANIDAC_IDAM_MASK               48
#define CANIDAC_IDAM_BITNUM             4



typedef union {
  byte Byte;
  struct {
    byte BOHOLD      :1;                                       
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} CANMISCSTR;
volatile CANMISCSTR __at (0x188D) _CANMISC;
#define CANMISC                         _CANMISC.Byte
#define CANMISC_BOHOLD                  _CANMISC.Bits.BOHOLD

#define CANMISC_BOHOLD_MASK             1



typedef union {
  byte Byte;
  struct {
    byte RXERR0      :1;                                       
    byte RXERR1      :1;                                       
    byte RXERR2      :1;                                       
    byte RXERR3      :1;                                       
    byte RXERR4      :1;                                       
    byte RXERR5      :1;                                       
    byte RXERR6      :1;                                       
    byte RXERR7      :1;                                       
  } Bits;
} CANRXERRSTR;
volatile CANRXERRSTR __at (0x188E) _CANRXERR;
#define CANRXERR                        _CANRXERR.Byte
#define CANRXERR_RXERR0                 _CANRXERR.Bits.RXERR0
#define CANRXERR_RXERR1                 _CANRXERR.Bits.RXERR1
#define CANRXERR_RXERR2                 _CANRXERR.Bits.RXERR2
#define CANRXERR_RXERR3                 _CANRXERR.Bits.RXERR3
#define CANRXERR_RXERR4                 _CANRXERR.Bits.RXERR4
#define CANRXERR_RXERR5                 _CANRXERR.Bits.RXERR5
#define CANRXERR_RXERR6                 _CANRXERR.Bits.RXERR6
#define CANRXERR_RXERR7                 _CANRXERR.Bits.RXERR7

#define CANRXERR_RXERR0_MASK            1
#define CANRXERR_RXERR1_MASK            2
#define CANRXERR_RXERR2_MASK            4
#define CANRXERR_RXERR3_MASK            8
#define CANRXERR_RXERR4_MASK            16
#define CANRXERR_RXERR5_MASK            32
#define CANRXERR_RXERR6_MASK            64
#define CANRXERR_RXERR7_MASK            128



typedef union {
  byte Byte;
  struct {
    byte TXERR0      :1;                                       
    byte TXERR1      :1;                                       
    byte TXERR2      :1;                                       
    byte TXERR3      :1;                                       
    byte TXERR4      :1;                                       
    byte TXERR5      :1;                                       
    byte TXERR6      :1;                                       
    byte TXERR7      :1;                                       
  } Bits;
} CANTXERRSTR;
volatile CANTXERRSTR __at (0x188F) _CANTXERR;
#define CANTXERR                        _CANTXERR.Byte
#define CANTXERR_TXERR0                 _CANTXERR.Bits.TXERR0
#define CANTXERR_TXERR1                 _CANTXERR.Bits.TXERR1
#define CANTXERR_TXERR2                 _CANTXERR.Bits.TXERR2
#define CANTXERR_TXERR3                 _CANTXERR.Bits.TXERR3
#define CANTXERR_TXERR4                 _CANTXERR.Bits.TXERR4
#define CANTXERR_TXERR5                 _CANTXERR.Bits.TXERR5
#define CANTXERR_TXERR6                 _CANTXERR.Bits.TXERR6
#define CANTXERR_TXERR7                 _CANTXERR.Bits.TXERR7

#define CANTXERR_TXERR0_MASK            1
#define CANTXERR_TXERR1_MASK            2
#define CANTXERR_TXERR2_MASK            4
#define CANTXERR_TXERR3_MASK            8
#define CANTXERR_TXERR4_MASK            16
#define CANTXERR_TXERR5_MASK            32
#define CANTXERR_TXERR6_MASK            64
#define CANTXERR_TXERR7_MASK            128



typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       
    byte AC1         :1;                                       
    byte AC2         :1;                                       
    byte AC3         :1;                                       
    byte AC4         :1;                                       
    byte AC5         :1;                                       
    byte AC6         :1;                                       
    byte AC7         :1;                                       
  } Bits;
} CANIDAR0STR;
volatile CANIDAR0STR __at (0x1890) _CANIDAR0;
#define CANIDAR0                        _CANIDAR0.Byte
#define CANIDAR0_AC0                    _CANIDAR0.Bits.AC0
#define CANIDAR0_AC1                    _CANIDAR0.Bits.AC1
#define CANIDAR0_AC2                    _CANIDAR0.Bits.AC2
#define CANIDAR0_AC3                    _CANIDAR0.Bits.AC3
#define CANIDAR0_AC4                    _CANIDAR0.Bits.AC4
#define CANIDAR0_AC5                    _CANIDAR0.Bits.AC5
#define CANIDAR0_AC6                    _CANIDAR0.Bits.AC6
#define CANIDAR0_AC7                    _CANIDAR0.Bits.AC7

#define CANIDAR_ARR                     ((volatile byte * __far) &CANIDAR0)

#define CANIDAR0_AC0_MASK               1
#define CANIDAR0_AC1_MASK               2
#define CANIDAR0_AC2_MASK               4
#define CANIDAR0_AC3_MASK               8
#define CANIDAR0_AC4_MASK               16
#define CANIDAR0_AC5_MASK               32
#define CANIDAR0_AC6_MASK               64
#define CANIDAR0_AC7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       
    byte AC1         :1;                                       
    byte AC2         :1;                                       
    byte AC3         :1;                                       
    byte AC4         :1;                                       
    byte AC5         :1;                                       
    byte AC6         :1;                                       
    byte AC7         :1;                                       
  } Bits;
} CANIDAR1STR;
volatile CANIDAR1STR __at (0x1891) _CANIDAR1;
#define CANIDAR1                        _CANIDAR1.Byte
#define CANIDAR1_AC0                    _CANIDAR1.Bits.AC0
#define CANIDAR1_AC1                    _CANIDAR1.Bits.AC1
#define CANIDAR1_AC2                    _CANIDAR1.Bits.AC2
#define CANIDAR1_AC3                    _CANIDAR1.Bits.AC3
#define CANIDAR1_AC4                    _CANIDAR1.Bits.AC4
#define CANIDAR1_AC5                    _CANIDAR1.Bits.AC5
#define CANIDAR1_AC6                    _CANIDAR1.Bits.AC6
#define CANIDAR1_AC7                    _CANIDAR1.Bits.AC7

#define CANIDAR1_AC0_MASK               1
#define CANIDAR1_AC1_MASK               2
#define CANIDAR1_AC2_MASK               4
#define CANIDAR1_AC3_MASK               8
#define CANIDAR1_AC4_MASK               16
#define CANIDAR1_AC5_MASK               32
#define CANIDAR1_AC6_MASK               64
#define CANIDAR1_AC7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       
    byte AC1         :1;                                       
    byte AC2         :1;                                       
    byte AC3         :1;                                       
    byte AC4         :1;                                       
    byte AC5         :1;                                       
    byte AC6         :1;                                       
    byte AC7         :1;                                       
  } Bits;
} CANIDAR2STR;
volatile CANIDAR2STR __at (0x1892) _CANIDAR2;
#define CANIDAR2                        _CANIDAR2.Byte
#define CANIDAR2_AC0                    _CANIDAR2.Bits.AC0
#define CANIDAR2_AC1                    _CANIDAR2.Bits.AC1
#define CANIDAR2_AC2                    _CANIDAR2.Bits.AC2
#define CANIDAR2_AC3                    _CANIDAR2.Bits.AC3
#define CANIDAR2_AC4                    _CANIDAR2.Bits.AC4
#define CANIDAR2_AC5                    _CANIDAR2.Bits.AC5
#define CANIDAR2_AC6                    _CANIDAR2.Bits.AC6
#define CANIDAR2_AC7                    _CANIDAR2.Bits.AC7

#define CANIDAR2_AC0_MASK               1
#define CANIDAR2_AC1_MASK               2
#define CANIDAR2_AC2_MASK               4
#define CANIDAR2_AC3_MASK               8
#define CANIDAR2_AC4_MASK               16
#define CANIDAR2_AC5_MASK               32
#define CANIDAR2_AC6_MASK               64
#define CANIDAR2_AC7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       
    byte AC1         :1;                                       
    byte AC2         :1;                                       
    byte AC3         :1;                                       
    byte AC4         :1;                                       
    byte AC5         :1;                                       
    byte AC6         :1;                                       
    byte AC7         :1;                                       
  } Bits;
} CANIDAR3STR;
volatile CANIDAR3STR __at (0x1893) _CANIDAR3;
#define CANIDAR3                        _CANIDAR3.Byte
#define CANIDAR3_AC0                    _CANIDAR3.Bits.AC0
#define CANIDAR3_AC1                    _CANIDAR3.Bits.AC1
#define CANIDAR3_AC2                    _CANIDAR3.Bits.AC2
#define CANIDAR3_AC3                    _CANIDAR3.Bits.AC3
#define CANIDAR3_AC4                    _CANIDAR3.Bits.AC4
#define CANIDAR3_AC5                    _CANIDAR3.Bits.AC5
#define CANIDAR3_AC6                    _CANIDAR3.Bits.AC6
#define CANIDAR3_AC7                    _CANIDAR3.Bits.AC7

#define CANIDAR3_AC0_MASK               1
#define CANIDAR3_AC1_MASK               2
#define CANIDAR3_AC2_MASK               4
#define CANIDAR3_AC3_MASK               8
#define CANIDAR3_AC4_MASK               16
#define CANIDAR3_AC5_MASK               32
#define CANIDAR3_AC6_MASK               64
#define CANIDAR3_AC7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       
    byte AM1         :1;                                       
    byte AM2         :1;                                       
    byte AM3         :1;                                       
    byte AM4         :1;                                       
    byte AM5         :1;                                       
    byte AM6         :1;                                       
    byte AM7         :1;                                       
  } Bits;
} CANIDMR0STR;
volatile CANIDMR0STR __at (0x1894) _CANIDMR0;
#define CANIDMR0                        _CANIDMR0.Byte
#define CANIDMR0_AM0                    _CANIDMR0.Bits.AM0
#define CANIDMR0_AM1                    _CANIDMR0.Bits.AM1
#define CANIDMR0_AM2                    _CANIDMR0.Bits.AM2
#define CANIDMR0_AM3                    _CANIDMR0.Bits.AM3
#define CANIDMR0_AM4                    _CANIDMR0.Bits.AM4
#define CANIDMR0_AM5                    _CANIDMR0.Bits.AM5
#define CANIDMR0_AM6                    _CANIDMR0.Bits.AM6
#define CANIDMR0_AM7                    _CANIDMR0.Bits.AM7

#define CANIDMR_ARR                     ((volatile byte * __far) &CANIDMR0)

#define CANIDMR0_AM0_MASK               1
#define CANIDMR0_AM1_MASK               2
#define CANIDMR0_AM2_MASK               4
#define CANIDMR0_AM3_MASK               8
#define CANIDMR0_AM4_MASK               16
#define CANIDMR0_AM5_MASK               32
#define CANIDMR0_AM6_MASK               64
#define CANIDMR0_AM7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       
    byte AM1         :1;                                       
    byte AM2         :1;                                       
    byte AM3         :1;                                       
    byte AM4         :1;                                       
    byte AM5         :1;                                       
    byte AM6         :1;                                       
    byte AM7         :1;                                       
  } Bits;
} CANIDMR1STR;
volatile CANIDMR1STR __at (0x1895) _CANIDMR1;
#define CANIDMR1                        _CANIDMR1.Byte
#define CANIDMR1_AM0                    _CANIDMR1.Bits.AM0
#define CANIDMR1_AM1                    _CANIDMR1.Bits.AM1
#define CANIDMR1_AM2                    _CANIDMR1.Bits.AM2
#define CANIDMR1_AM3                    _CANIDMR1.Bits.AM3
#define CANIDMR1_AM4                    _CANIDMR1.Bits.AM4
#define CANIDMR1_AM5                    _CANIDMR1.Bits.AM5
#define CANIDMR1_AM6                    _CANIDMR1.Bits.AM6
#define CANIDMR1_AM7                    _CANIDMR1.Bits.AM7

#define CANIDMR1_AM0_MASK               1
#define CANIDMR1_AM1_MASK               2
#define CANIDMR1_AM2_MASK               4
#define CANIDMR1_AM3_MASK               8
#define CANIDMR1_AM4_MASK               16
#define CANIDMR1_AM5_MASK               32
#define CANIDMR1_AM6_MASK               64
#define CANIDMR1_AM7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       
    byte AM1         :1;                                       
    byte AM2         :1;                                       
    byte AM3         :1;                                       
    byte AM4         :1;                                       
    byte AM5         :1;                                       
    byte AM6         :1;                                       
    byte AM7         :1;                                       
  } Bits;
} CANIDMR2STR;
volatile CANIDMR2STR __at (0x1896) _CANIDMR2;
#define CANIDMR2                        _CANIDMR2.Byte
#define CANIDMR2_AM0                    _CANIDMR2.Bits.AM0
#define CANIDMR2_AM1                    _CANIDMR2.Bits.AM1
#define CANIDMR2_AM2                    _CANIDMR2.Bits.AM2
#define CANIDMR2_AM3                    _CANIDMR2.Bits.AM3
#define CANIDMR2_AM4                    _CANIDMR2.Bits.AM4
#define CANIDMR2_AM5                    _CANIDMR2.Bits.AM5
#define CANIDMR2_AM6                    _CANIDMR2.Bits.AM6
#define CANIDMR2_AM7                    _CANIDMR2.Bits.AM7

#define CANIDMR2_AM0_MASK               1
#define CANIDMR2_AM1_MASK               2
#define CANIDMR2_AM2_MASK               4
#define CANIDMR2_AM3_MASK               8
#define CANIDMR2_AM4_MASK               16
#define CANIDMR2_AM5_MASK               32
#define CANIDMR2_AM6_MASK               64
#define CANIDMR2_AM7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       
    byte AM1         :1;                                       
    byte AM2         :1;                                       
    byte AM3         :1;                                       
    byte AM4         :1;                                       
    byte AM5         :1;                                       
    byte AM6         :1;                                       
    byte AM7         :1;                                       
  } Bits;
} CANIDMR3STR;
volatile CANIDMR3STR __at (0x1897) _CANIDMR3;
#define CANIDMR3                        _CANIDMR3.Byte
#define CANIDMR3_AM0                    _CANIDMR3.Bits.AM0
#define CANIDMR3_AM1                    _CANIDMR3.Bits.AM1
#define CANIDMR3_AM2                    _CANIDMR3.Bits.AM2
#define CANIDMR3_AM3                    _CANIDMR3.Bits.AM3
#define CANIDMR3_AM4                    _CANIDMR3.Bits.AM4
#define CANIDMR3_AM5                    _CANIDMR3.Bits.AM5
#define CANIDMR3_AM6                    _CANIDMR3.Bits.AM6
#define CANIDMR3_AM7                    _CANIDMR3.Bits.AM7

#define CANIDMR3_AM0_MASK               1
#define CANIDMR3_AM1_MASK               2
#define CANIDMR3_AM2_MASK               4
#define CANIDMR3_AM3_MASK               8
#define CANIDMR3_AM4_MASK               16
#define CANIDMR3_AM5_MASK               32
#define CANIDMR3_AM6_MASK               64
#define CANIDMR3_AM7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       
    byte AC1         :1;                                       
    byte AC2         :1;                                       
    byte AC3         :1;                                       
    byte AC4         :1;                                       
    byte AC5         :1;                                       
    byte AC6         :1;                                       
    byte AC7         :1;                                       
  } Bits;
} CANIDAR4STR;
volatile CANIDAR4STR __at (0x1898) _CANIDAR4;
#define CANIDAR4                        _CANIDAR4.Byte
#define CANIDAR4_AC0                    _CANIDAR4.Bits.AC0
#define CANIDAR4_AC1                    _CANIDAR4.Bits.AC1
#define CANIDAR4_AC2                    _CANIDAR4.Bits.AC2
#define CANIDAR4_AC3                    _CANIDAR4.Bits.AC3
#define CANIDAR4_AC4                    _CANIDAR4.Bits.AC4
#define CANIDAR4_AC5                    _CANIDAR4.Bits.AC5
#define CANIDAR4_AC6                    _CANIDAR4.Bits.AC6
#define CANIDAR4_AC7                    _CANIDAR4.Bits.AC7

#define CANIDAR4_AC0_MASK               1
#define CANIDAR4_AC1_MASK               2
#define CANIDAR4_AC2_MASK               4
#define CANIDAR4_AC3_MASK               8
#define CANIDAR4_AC4_MASK               16
#define CANIDAR4_AC5_MASK               32
#define CANIDAR4_AC6_MASK               64
#define CANIDAR4_AC7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       
    byte AC1         :1;                                       
    byte AC2         :1;                                       
    byte AC3         :1;                                       
    byte AC4         :1;                                       
    byte AC5         :1;                                       
    byte AC6         :1;                                       
    byte AC7         :1;                                       
  } Bits;
} CANIDAR5STR;
volatile CANIDAR5STR __at (0x1899) _CANIDAR5;
#define CANIDAR5                        _CANIDAR5.Byte
#define CANIDAR5_AC0                    _CANIDAR5.Bits.AC0
#define CANIDAR5_AC1                    _CANIDAR5.Bits.AC1
#define CANIDAR5_AC2                    _CANIDAR5.Bits.AC2
#define CANIDAR5_AC3                    _CANIDAR5.Bits.AC3
#define CANIDAR5_AC4                    _CANIDAR5.Bits.AC4
#define CANIDAR5_AC5                    _CANIDAR5.Bits.AC5
#define CANIDAR5_AC6                    _CANIDAR5.Bits.AC6
#define CANIDAR5_AC7                    _CANIDAR5.Bits.AC7

#define CANIDAR5_AC0_MASK               1
#define CANIDAR5_AC1_MASK               2
#define CANIDAR5_AC2_MASK               4
#define CANIDAR5_AC3_MASK               8
#define CANIDAR5_AC4_MASK               16
#define CANIDAR5_AC5_MASK               32
#define CANIDAR5_AC6_MASK               64
#define CANIDAR5_AC7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       
    byte AC1         :1;                                       
    byte AC2         :1;                                       
    byte AC3         :1;                                       
    byte AC4         :1;                                       
    byte AC5         :1;                                       
    byte AC6         :1;                                       
    byte AC7         :1;                                       
  } Bits;
} CANIDAR6STR;
volatile CANIDAR6STR __at (0x189A) _CANIDAR6;
#define CANIDAR6                        _CANIDAR6.Byte
#define CANIDAR6_AC0                    _CANIDAR6.Bits.AC0
#define CANIDAR6_AC1                    _CANIDAR6.Bits.AC1
#define CANIDAR6_AC2                    _CANIDAR6.Bits.AC2
#define CANIDAR6_AC3                    _CANIDAR6.Bits.AC3
#define CANIDAR6_AC4                    _CANIDAR6.Bits.AC4
#define CANIDAR6_AC5                    _CANIDAR6.Bits.AC5
#define CANIDAR6_AC6                    _CANIDAR6.Bits.AC6
#define CANIDAR6_AC7                    _CANIDAR6.Bits.AC7

#define CANIDAR6_AC0_MASK               1
#define CANIDAR6_AC1_MASK               2
#define CANIDAR6_AC2_MASK               4
#define CANIDAR6_AC3_MASK               8
#define CANIDAR6_AC4_MASK               16
#define CANIDAR6_AC5_MASK               32
#define CANIDAR6_AC6_MASK               64
#define CANIDAR6_AC7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       
    byte AC1         :1;                                       
    byte AC2         :1;                                       
    byte AC3         :1;                                       
    byte AC4         :1;                                       
    byte AC5         :1;                                       
    byte AC6         :1;                                       
    byte AC7         :1;                                       
  } Bits;
} CANIDAR7STR;
volatile CANIDAR7STR __at (0x189B) _CANIDAR7;
#define CANIDAR7                        _CANIDAR7.Byte
#define CANIDAR7_AC0                    _CANIDAR7.Bits.AC0
#define CANIDAR7_AC1                    _CANIDAR7.Bits.AC1
#define CANIDAR7_AC2                    _CANIDAR7.Bits.AC2
#define CANIDAR7_AC3                    _CANIDAR7.Bits.AC3
#define CANIDAR7_AC4                    _CANIDAR7.Bits.AC4
#define CANIDAR7_AC5                    _CANIDAR7.Bits.AC5
#define CANIDAR7_AC6                    _CANIDAR7.Bits.AC6
#define CANIDAR7_AC7                    _CANIDAR7.Bits.AC7

#define CANIDAR7_AC0_MASK               1
#define CANIDAR7_AC1_MASK               2
#define CANIDAR7_AC2_MASK               4
#define CANIDAR7_AC3_MASK               8
#define CANIDAR7_AC4_MASK               16
#define CANIDAR7_AC5_MASK               32
#define CANIDAR7_AC6_MASK               64
#define CANIDAR7_AC7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       
    byte AM1         :1;                                       
    byte AM2         :1;                                       
    byte AM3         :1;                                       
    byte AM4         :1;                                       
    byte AM5         :1;                                       
    byte AM6         :1;                                       
    byte AM7         :1;                                       
  } Bits;
} CANIDMR4STR;
volatile CANIDMR4STR __at (0x189C) _CANIDMR4;
#define CANIDMR4                        _CANIDMR4.Byte
#define CANIDMR4_AM0                    _CANIDMR4.Bits.AM0
#define CANIDMR4_AM1                    _CANIDMR4.Bits.AM1
#define CANIDMR4_AM2                    _CANIDMR4.Bits.AM2
#define CANIDMR4_AM3                    _CANIDMR4.Bits.AM3
#define CANIDMR4_AM4                    _CANIDMR4.Bits.AM4
#define CANIDMR4_AM5                    _CANIDMR4.Bits.AM5
#define CANIDMR4_AM6                    _CANIDMR4.Bits.AM6
#define CANIDMR4_AM7                    _CANIDMR4.Bits.AM7

#define CANIDMR4_AM0_MASK               1
#define CANIDMR4_AM1_MASK               2
#define CANIDMR4_AM2_MASK               4
#define CANIDMR4_AM3_MASK               8
#define CANIDMR4_AM4_MASK               16
#define CANIDMR4_AM5_MASK               32
#define CANIDMR4_AM6_MASK               64
#define CANIDMR4_AM7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       
    byte AM1         :1;                                       
    byte AM2         :1;                                       
    byte AM3         :1;                                       
    byte AM4         :1;                                       
    byte AM5         :1;                                       
    byte AM6         :1;                                       
    byte AM7         :1;                                       
  } Bits;
} CANIDMR5STR;
volatile CANIDMR5STR __at (0x189D) _CANIDMR5;
#define CANIDMR5                        _CANIDMR5.Byte
#define CANIDMR5_AM0                    _CANIDMR5.Bits.AM0
#define CANIDMR5_AM1                    _CANIDMR5.Bits.AM1
#define CANIDMR5_AM2                    _CANIDMR5.Bits.AM2
#define CANIDMR5_AM3                    _CANIDMR5.Bits.AM3
#define CANIDMR5_AM4                    _CANIDMR5.Bits.AM4
#define CANIDMR5_AM5                    _CANIDMR5.Bits.AM5
#define CANIDMR5_AM6                    _CANIDMR5.Bits.AM6
#define CANIDMR5_AM7                    _CANIDMR5.Bits.AM7

#define CANIDMR5_AM0_MASK               1
#define CANIDMR5_AM1_MASK               2
#define CANIDMR5_AM2_MASK               4
#define CANIDMR5_AM3_MASK               8
#define CANIDMR5_AM4_MASK               16
#define CANIDMR5_AM5_MASK               32
#define CANIDMR5_AM6_MASK               64
#define CANIDMR5_AM7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       
    byte AM1         :1;                                       
    byte AM2         :1;                                       
    byte AM3         :1;                                       
    byte AM4         :1;                                       
    byte AM5         :1;                                       
    byte AM6         :1;                                       
    byte AM7         :1;                                       
  } Bits;
} CANIDMR6STR;
volatile CANIDMR6STR __at (0x189E) _CANIDMR6;
#define CANIDMR6                        _CANIDMR6.Byte
#define CANIDMR6_AM0                    _CANIDMR6.Bits.AM0
#define CANIDMR6_AM1                    _CANIDMR6.Bits.AM1
#define CANIDMR6_AM2                    _CANIDMR6.Bits.AM2
#define CANIDMR6_AM3                    _CANIDMR6.Bits.AM3
#define CANIDMR6_AM4                    _CANIDMR6.Bits.AM4
#define CANIDMR6_AM5                    _CANIDMR6.Bits.AM5
#define CANIDMR6_AM6                    _CANIDMR6.Bits.AM6
#define CANIDMR6_AM7                    _CANIDMR6.Bits.AM7

#define CANIDMR6_AM0_MASK               1
#define CANIDMR6_AM1_MASK               2
#define CANIDMR6_AM2_MASK               4
#define CANIDMR6_AM3_MASK               8
#define CANIDMR6_AM4_MASK               16
#define CANIDMR6_AM5_MASK               32
#define CANIDMR6_AM6_MASK               64
#define CANIDMR6_AM7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       
    byte AM1         :1;                                       
    byte AM2         :1;                                       
    byte AM3         :1;                                       
    byte AM4         :1;                                       
    byte AM5         :1;                                       
    byte AM6         :1;                                       
    byte AM7         :1;                                       
  } Bits;
} CANIDMR7STR;
volatile CANIDMR7STR __at (0x189F) _CANIDMR7;
#define CANIDMR7                        _CANIDMR7.Byte
#define CANIDMR7_AM0                    _CANIDMR7.Bits.AM0
#define CANIDMR7_AM1                    _CANIDMR7.Bits.AM1
#define CANIDMR7_AM2                    _CANIDMR7.Bits.AM2
#define CANIDMR7_AM3                    _CANIDMR7.Bits.AM3
#define CANIDMR7_AM4                    _CANIDMR7.Bits.AM4
#define CANIDMR7_AM5                    _CANIDMR7.Bits.AM5
#define CANIDMR7_AM6                    _CANIDMR7.Bits.AM6
#define CANIDMR7_AM7                    _CANIDMR7.Bits.AM7

#define CANIDMR7_AM0_MASK               1
#define CANIDMR7_AM1_MASK               2
#define CANIDMR7_AM2_MASK               4
#define CANIDMR7_AM3_MASK               8
#define CANIDMR7_AM4_MASK               16
#define CANIDMR7_AM5_MASK               32
#define CANIDMR7_AM6_MASK               64
#define CANIDMR7_AM7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte ID21        :1;                                       
    byte ID22        :1;                                       
    byte ID23        :1;                                       
    byte ID24        :1;                                       
    byte ID25        :1;                                       
    byte ID26        :1;                                       
    byte ID27        :1;                                       
    byte ID28        :1;                                       
  } Bits;
} CANRIDR0STR;
volatile CANRIDR0STR __at (0x18A0) _CANRIDR0;
#define CANRIDR0                        _CANRIDR0.Byte
#define CANRIDR0_ID21                   _CANRIDR0.Bits.ID21
#define CANRIDR0_ID22                   _CANRIDR0.Bits.ID22
#define CANRIDR0_ID23                   _CANRIDR0.Bits.ID23
#define CANRIDR0_ID24                   _CANRIDR0.Bits.ID24
#define CANRIDR0_ID25                   _CANRIDR0.Bits.ID25
#define CANRIDR0_ID26                   _CANRIDR0.Bits.ID26
#define CANRIDR0_ID27                   _CANRIDR0.Bits.ID27
#define CANRIDR0_ID28                   _CANRIDR0.Bits.ID28

#define CANRIDR_ARR                     ((volatile byte * __far) &CANRIDR0)

#define CANRIDR0_ID21_MASK              1
#define CANRIDR0_ID22_MASK              2
#define CANRIDR0_ID23_MASK              4
#define CANRIDR0_ID24_MASK              8
#define CANRIDR0_ID25_MASK              16
#define CANRIDR0_ID26_MASK              32
#define CANRIDR0_ID27_MASK              64
#define CANRIDR0_ID28_MASK              128



typedef union {
  byte Byte;
  struct {
    byte ID15        :1;                                       
    byte ID16        :1;                                       
    byte ID17        :1;                                       
    byte IDE         :1;                                       
    byte SRR         :1;                                       
    byte ID18        :1;                                       
    byte ID19        :1;                                       
    byte ID20        :1;                                       
  } Bits;
  struct {
    byte grpID_15 :3;
    byte         :1;
    byte         :1;
    byte grpID_18 :3;
  } MergedBits;
} CANRIDR1STR;
volatile CANRIDR1STR __at (0x18A1) _CANRIDR1;
#define CANRIDR1                        _CANRIDR1.Byte
#define CANRIDR1_ID15                   _CANRIDR1.Bits.ID15
#define CANRIDR1_ID16                   _CANRIDR1.Bits.ID16
#define CANRIDR1_ID17                   _CANRIDR1.Bits.ID17
#define CANRIDR1_IDE                    _CANRIDR1.Bits.IDE
#define CANRIDR1_SRR                    _CANRIDR1.Bits.SRR
#define CANRIDR1_ID18                   _CANRIDR1.Bits.ID18
#define CANRIDR1_ID19                   _CANRIDR1.Bits.ID19
#define CANRIDR1_ID20                   _CANRIDR1.Bits.ID20
#define CANRIDR1_ID_15                  _CANRIDR1.MergedBits.grpID_15
#define CANRIDR1_ID_18                  _CANRIDR1.MergedBits.grpID_18
#define CANRIDR1_ID                     CANRIDR1_ID_15

#define CANRIDR1_ID15_MASK              1
#define CANRIDR1_ID16_MASK              2
#define CANRIDR1_ID17_MASK              4
#define CANRIDR1_IDE_MASK               8
#define CANRIDR1_SRR_MASK               16
#define CANRIDR1_ID18_MASK              32
#define CANRIDR1_ID19_MASK              64
#define CANRIDR1_ID20_MASK              128
#define CANRIDR1_ID_15_MASK             7
#define CANRIDR1_ID_15_BITNUM           0
#define CANRIDR1_ID_18_MASK             224
#define CANRIDR1_ID_18_BITNUM           5



typedef union {
  byte Byte;
  struct {
    byte ID7         :1;                                       
    byte ID8         :1;                                       
    byte ID9         :1;                                       
    byte ID10        :1;                                       
    byte ID11        :1;                                       
    byte ID12        :1;                                       
    byte ID13        :1;                                       
    byte ID14        :1;                                       
  } Bits;
} CANRIDR2STR;
volatile CANRIDR2STR __at (0x18A2) _CANRIDR2;
#define CANRIDR2                        _CANRIDR2.Byte
#define CANRIDR2_ID7                    _CANRIDR2.Bits.ID7
#define CANRIDR2_ID8                    _CANRIDR2.Bits.ID8
#define CANRIDR2_ID9                    _CANRIDR2.Bits.ID9
#define CANRIDR2_ID10                   _CANRIDR2.Bits.ID10
#define CANRIDR2_ID11                   _CANRIDR2.Bits.ID11
#define CANRIDR2_ID12                   _CANRIDR2.Bits.ID12
#define CANRIDR2_ID13                   _CANRIDR2.Bits.ID13
#define CANRIDR2_ID14                   _CANRIDR2.Bits.ID14

#define CANRIDR2_ID7_MASK               1
#define CANRIDR2_ID8_MASK               2
#define CANRIDR2_ID9_MASK               4
#define CANRIDR2_ID10_MASK              8
#define CANRIDR2_ID11_MASK              16
#define CANRIDR2_ID12_MASK              32
#define CANRIDR2_ID13_MASK              64
#define CANRIDR2_ID14_MASK              128



typedef union {
  byte Byte;
  struct {
    byte RTR         :1;                                       
    byte ID0         :1;                                       
    byte ID1         :1;                                       
    byte ID2         :1;                                       
    byte ID3         :1;                                       
    byte ID4         :1;                                       
    byte ID5         :1;                                       
    byte ID6         :1;                                       
  } Bits;
  struct {
    byte         :1;
    byte grpID   :7;
  } MergedBits;
} CANRIDR3STR;
volatile CANRIDR3STR __at (0x18A3) _CANRIDR3;
#define CANRIDR3                        _CANRIDR3.Byte
#define CANRIDR3_RTR                    _CANRIDR3.Bits.RTR
#define CANRIDR3_ID0                    _CANRIDR3.Bits.ID0
#define CANRIDR3_ID1                    _CANRIDR3.Bits.ID1
#define CANRIDR3_ID2                    _CANRIDR3.Bits.ID2
#define CANRIDR3_ID3                    _CANRIDR3.Bits.ID3
#define CANRIDR3_ID4                    _CANRIDR3.Bits.ID4
#define CANRIDR3_ID5                    _CANRIDR3.Bits.ID5
#define CANRIDR3_ID6                    _CANRIDR3.Bits.ID6
#define CANRIDR3_ID                     _CANRIDR3.MergedBits.grpID

#define CANRIDR3_RTR_MASK               1
#define CANRIDR3_ID0_MASK               2
#define CANRIDR3_ID1_MASK               4
#define CANRIDR3_ID2_MASK               8
#define CANRIDR3_ID3_MASK               16
#define CANRIDR3_ID4_MASK               32
#define CANRIDR3_ID5_MASK               64
#define CANRIDR3_ID6_MASK               128
#define CANRIDR3_ID_MASK                254
#define CANRIDR3_ID_BITNUM              1



typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       
    byte DB1         :1;                                       
    byte DB2         :1;                                       
    byte DB3         :1;                                       
    byte DB4         :1;                                       
    byte DB5         :1;                                       
    byte DB6         :1;                                       
    byte DB7         :1;                                       
  } Bits;
} CANRDSR0STR;
volatile CANRDSR0STR __at (0x18A4) _CANRDSR0;
#define CANRDSR0                        _CANRDSR0.Byte
#define CANRDSR0_DB0                    _CANRDSR0.Bits.DB0
#define CANRDSR0_DB1                    _CANRDSR0.Bits.DB1
#define CANRDSR0_DB2                    _CANRDSR0.Bits.DB2
#define CANRDSR0_DB3                    _CANRDSR0.Bits.DB3
#define CANRDSR0_DB4                    _CANRDSR0.Bits.DB4
#define CANRDSR0_DB5                    _CANRDSR0.Bits.DB5
#define CANRDSR0_DB6                    _CANRDSR0.Bits.DB6
#define CANRDSR0_DB7                    _CANRDSR0.Bits.DB7

#define CANRDSR_ARR                     ((volatile byte * __far) &CANRDSR0)

#define CANRDSR0_DB0_MASK               1
#define CANRDSR0_DB1_MASK               2
#define CANRDSR0_DB2_MASK               4
#define CANRDSR0_DB3_MASK               8
#define CANRDSR0_DB4_MASK               16
#define CANRDSR0_DB5_MASK               32
#define CANRDSR0_DB6_MASK               64
#define CANRDSR0_DB7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       
    byte DB1         :1;                                       
    byte DB2         :1;                                       
    byte DB3         :1;                                       
    byte DB4         :1;                                       
    byte DB5         :1;                                       
    byte DB6         :1;                                       
    byte DB7         :1;                                       
  } Bits;
} CANRDSR1STR;
volatile CANRDSR1STR __at (0x18A5) _CANRDSR1;
#define CANRDSR1                        _CANRDSR1.Byte
#define CANRDSR1_DB0                    _CANRDSR1.Bits.DB0
#define CANRDSR1_DB1                    _CANRDSR1.Bits.DB1
#define CANRDSR1_DB2                    _CANRDSR1.Bits.DB2
#define CANRDSR1_DB3                    _CANRDSR1.Bits.DB3
#define CANRDSR1_DB4                    _CANRDSR1.Bits.DB4
#define CANRDSR1_DB5                    _CANRDSR1.Bits.DB5
#define CANRDSR1_DB6                    _CANRDSR1.Bits.DB6
#define CANRDSR1_DB7                    _CANRDSR1.Bits.DB7

#define CANRDSR1_DB0_MASK               1
#define CANRDSR1_DB1_MASK               2
#define CANRDSR1_DB2_MASK               4
#define CANRDSR1_DB3_MASK               8
#define CANRDSR1_DB4_MASK               16
#define CANRDSR1_DB5_MASK               32
#define CANRDSR1_DB6_MASK               64
#define CANRDSR1_DB7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       
    byte DB1         :1;                                       
    byte DB2         :1;                                       
    byte DB3         :1;                                       
    byte DB4         :1;                                       
    byte DB5         :1;                                       
    byte DB6         :1;                                       
    byte DB7         :1;                                       
  } Bits;
} CANRDSR2STR;
volatile CANRDSR2STR __at (0x18A6) _CANRDSR2;
#define CANRDSR2                        _CANRDSR2.Byte
#define CANRDSR2_DB0                    _CANRDSR2.Bits.DB0
#define CANRDSR2_DB1                    _CANRDSR2.Bits.DB1
#define CANRDSR2_DB2                    _CANRDSR2.Bits.DB2
#define CANRDSR2_DB3                    _CANRDSR2.Bits.DB3
#define CANRDSR2_DB4                    _CANRDSR2.Bits.DB4
#define CANRDSR2_DB5                    _CANRDSR2.Bits.DB5
#define CANRDSR2_DB6                    _CANRDSR2.Bits.DB6
#define CANRDSR2_DB7                    _CANRDSR2.Bits.DB7

#define CANRDSR2_DB0_MASK               1
#define CANRDSR2_DB1_MASK               2
#define CANRDSR2_DB2_MASK               4
#define CANRDSR2_DB3_MASK               8
#define CANRDSR2_DB4_MASK               16
#define CANRDSR2_DB5_MASK               32
#define CANRDSR2_DB6_MASK               64
#define CANRDSR2_DB7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       
    byte DB1         :1;                                       
    byte DB2         :1;                                       
    byte DB3         :1;                                       
    byte DB4         :1;                                       
    byte DB5         :1;                                       
    byte DB6         :1;                                       
    byte DB7         :1;                                       
  } Bits;
} CANRDSR3STR;
volatile CANRDSR3STR __at (0x18A7) _CANRDSR3;
#define CANRDSR3                        _CANRDSR3.Byte
#define CANRDSR3_DB0                    _CANRDSR3.Bits.DB0
#define CANRDSR3_DB1                    _CANRDSR3.Bits.DB1
#define CANRDSR3_DB2                    _CANRDSR3.Bits.DB2
#define CANRDSR3_DB3                    _CANRDSR3.Bits.DB3
#define CANRDSR3_DB4                    _CANRDSR3.Bits.DB4
#define CANRDSR3_DB5                    _CANRDSR3.Bits.DB5
#define CANRDSR3_DB6                    _CANRDSR3.Bits.DB6
#define CANRDSR3_DB7                    _CANRDSR3.Bits.DB7

#define CANRDSR3_DB0_MASK               1
#define CANRDSR3_DB1_MASK               2
#define CANRDSR3_DB2_MASK               4
#define CANRDSR3_DB3_MASK               8
#define CANRDSR3_DB4_MASK               16
#define CANRDSR3_DB5_MASK               32
#define CANRDSR3_DB6_MASK               64
#define CANRDSR3_DB7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       
    byte DB1         :1;                                       
    byte DB2         :1;                                       
    byte DB3         :1;                                       
    byte DB4         :1;                                       
    byte DB5         :1;                                       
    byte DB6         :1;                                       
    byte DB7         :1;                                       
  } Bits;
} CANRDSR4STR;
volatile CANRDSR4STR __at (0x18A8) _CANRDSR4;
#define CANRDSR4                        _CANRDSR4.Byte
#define CANRDSR4_DB0                    _CANRDSR4.Bits.DB0
#define CANRDSR4_DB1                    _CANRDSR4.Bits.DB1
#define CANRDSR4_DB2                    _CANRDSR4.Bits.DB2
#define CANRDSR4_DB3                    _CANRDSR4.Bits.DB3
#define CANRDSR4_DB4                    _CANRDSR4.Bits.DB4
#define CANRDSR4_DB5                    _CANRDSR4.Bits.DB5
#define CANRDSR4_DB6                    _CANRDSR4.Bits.DB6
#define CANRDSR4_DB7                    _CANRDSR4.Bits.DB7

#define CANRDSR4_DB0_MASK               1
#define CANRDSR4_DB1_MASK               2
#define CANRDSR4_DB2_MASK               4
#define CANRDSR4_DB3_MASK               8
#define CANRDSR4_DB4_MASK               16
#define CANRDSR4_DB5_MASK               32
#define CANRDSR4_DB6_MASK               64
#define CANRDSR4_DB7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       
    byte DB1         :1;                                       
    byte DB2         :1;                                       
    byte DB3         :1;                                       
    byte DB4         :1;                                       
    byte DB5         :1;                                       
    byte DB6         :1;                                       
    byte DB7         :1;                                       
  } Bits;
} CANRDSR5STR;
volatile CANRDSR5STR __at (0x18A9) _CANRDSR5;
#define CANRDSR5                        _CANRDSR5.Byte
#define CANRDSR5_DB0                    _CANRDSR5.Bits.DB0
#define CANRDSR5_DB1                    _CANRDSR5.Bits.DB1
#define CANRDSR5_DB2                    _CANRDSR5.Bits.DB2
#define CANRDSR5_DB3                    _CANRDSR5.Bits.DB3
#define CANRDSR5_DB4                    _CANRDSR5.Bits.DB4
#define CANRDSR5_DB5                    _CANRDSR5.Bits.DB5
#define CANRDSR5_DB6                    _CANRDSR5.Bits.DB6
#define CANRDSR5_DB7                    _CANRDSR5.Bits.DB7

#define CANRDSR5_DB0_MASK               1
#define CANRDSR5_DB1_MASK               2
#define CANRDSR5_DB2_MASK               4
#define CANRDSR5_DB3_MASK               8
#define CANRDSR5_DB4_MASK               16
#define CANRDSR5_DB5_MASK               32
#define CANRDSR5_DB6_MASK               64
#define CANRDSR5_DB7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       
    byte DB1         :1;                                       
    byte DB2         :1;                                       
    byte DB3         :1;                                       
    byte DB4         :1;                                       
    byte DB5         :1;                                       
    byte DB6         :1;                                       
    byte DB7         :1;                                       
  } Bits;
} CANRDSR6STR;
volatile CANRDSR6STR __at (0x18AA) _CANRDSR6;
#define CANRDSR6                        _CANRDSR6.Byte
#define CANRDSR6_DB0                    _CANRDSR6.Bits.DB0
#define CANRDSR6_DB1                    _CANRDSR6.Bits.DB1
#define CANRDSR6_DB2                    _CANRDSR6.Bits.DB2
#define CANRDSR6_DB3                    _CANRDSR6.Bits.DB3
#define CANRDSR6_DB4                    _CANRDSR6.Bits.DB4
#define CANRDSR6_DB5                    _CANRDSR6.Bits.DB5
#define CANRDSR6_DB6                    _CANRDSR6.Bits.DB6
#define CANRDSR6_DB7                    _CANRDSR6.Bits.DB7

#define CANRDSR6_DB0_MASK               1
#define CANRDSR6_DB1_MASK               2
#define CANRDSR6_DB2_MASK               4
#define CANRDSR6_DB3_MASK               8
#define CANRDSR6_DB4_MASK               16
#define CANRDSR6_DB5_MASK               32
#define CANRDSR6_DB6_MASK               64
#define CANRDSR6_DB7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       
    byte DB1         :1;                                       
    byte DB2         :1;                                       
    byte DB3         :1;                                       
    byte DB4         :1;                                       
    byte DB5         :1;                                       
    byte DB6         :1;                                       
    byte DB7         :1;                                       
  } Bits;
} CANRDSR7STR;
volatile CANRDSR7STR __at (0x18AB) _CANRDSR7;
#define CANRDSR7                        _CANRDSR7.Byte
#define CANRDSR7_DB0                    _CANRDSR7.Bits.DB0
#define CANRDSR7_DB1                    _CANRDSR7.Bits.DB1
#define CANRDSR7_DB2                    _CANRDSR7.Bits.DB2
#define CANRDSR7_DB3                    _CANRDSR7.Bits.DB3
#define CANRDSR7_DB4                    _CANRDSR7.Bits.DB4
#define CANRDSR7_DB5                    _CANRDSR7.Bits.DB5
#define CANRDSR7_DB6                    _CANRDSR7.Bits.DB6
#define CANRDSR7_DB7                    _CANRDSR7.Bits.DB7

#define CANRDSR7_DB0_MASK               1
#define CANRDSR7_DB1_MASK               2
#define CANRDSR7_DB2_MASK               4
#define CANRDSR7_DB3_MASK               8
#define CANRDSR7_DB4_MASK               16
#define CANRDSR7_DB5_MASK               32
#define CANRDSR7_DB6_MASK               64
#define CANRDSR7_DB7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte DLC0        :1;                                       
    byte DLC1        :1;                                       
    byte DLC2        :1;                                       
    byte DLC3        :1;                                       
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDLC  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANRDLRSTR;
volatile CANRDLRSTR __at (0x18AC) _CANRDLR;
#define CANRDLR                         _CANRDLR.Byte
#define CANRDLR_DLC0                    _CANRDLR.Bits.DLC0
#define CANRDLR_DLC1                    _CANRDLR.Bits.DLC1
#define CANRDLR_DLC2                    _CANRDLR.Bits.DLC2
#define CANRDLR_DLC3                    _CANRDLR.Bits.DLC3
#define CANRDLR_DLC                     _CANRDLR.MergedBits.grpDLC

#define CANRDLR_DLC0_MASK               1
#define CANRDLR_DLC1_MASK               2
#define CANRDLR_DLC2_MASK               4
#define CANRDLR_DLC3_MASK               8
#define CANRDLR_DLC_MASK                15
#define CANRDLR_DLC_BITNUM              0



typedef union {
  word Word;
   
  struct {
    
    union {
      byte Byte;
      struct {
        byte TSR8        :1;                                       
        byte TSR9        :1;                                       
        byte TSR10       :1;                                       
        byte TSR11       :1;                                       
        byte TSR12       :1;                                       
        byte TSR13       :1;                                       
        byte TSR14       :1;                                       
        byte TSR15       :1;                                       
      } Bits;
    } CANRTSRHSTR;
    #define CANRTSRH                    _CANRTSR.Overlap_STR.CANRTSRHSTR.Byte
    #define CANRTSRH_TSR8               _CANRTSR.Overlap_STR.CANRTSRHSTR.Bits.TSR8
    #define CANRTSRH_TSR9               _CANRTSR.Overlap_STR.CANRTSRHSTR.Bits.TSR9
    #define CANRTSRH_TSR10              _CANRTSR.Overlap_STR.CANRTSRHSTR.Bits.TSR10
    #define CANRTSRH_TSR11              _CANRTSR.Overlap_STR.CANRTSRHSTR.Bits.TSR11
    #define CANRTSRH_TSR12              _CANRTSR.Overlap_STR.CANRTSRHSTR.Bits.TSR12
    #define CANRTSRH_TSR13              _CANRTSR.Overlap_STR.CANRTSRHSTR.Bits.TSR13
    #define CANRTSRH_TSR14              _CANRTSR.Overlap_STR.CANRTSRHSTR.Bits.TSR14
    #define CANRTSRH_TSR15              _CANRTSR.Overlap_STR.CANRTSRHSTR.Bits.TSR15
    
    
    #define CANRTSRH_TSR8_MASK          1
    #define CANRTSRH_TSR9_MASK          2
    #define CANRTSRH_TSR10_MASK         4
    #define CANRTSRH_TSR11_MASK         8
    #define CANRTSRH_TSR12_MASK         16
    #define CANRTSRH_TSR13_MASK         32
    #define CANRTSRH_TSR14_MASK         64
    #define CANRTSRH_TSR15_MASK         128


    
    union {
      byte Byte;
      struct {
        byte TSR0        :1;                                       
        byte TSR1        :1;                                       
        byte TSR2        :1;                                       
        byte TSR3        :1;                                       
        byte TSR4        :1;                                       
        byte TSR5        :1;                                       
        byte TSR6        :1;                                       
        byte TSR7        :1;                                       
      } Bits;
    } CANRTSRLSTR;
    #define CANRTSRL                    _CANRTSR.Overlap_STR.CANRTSRLSTR.Byte
    #define CANRTSRL_TSR0               _CANRTSR.Overlap_STR.CANRTSRLSTR.Bits.TSR0
    #define CANRTSRL_TSR1               _CANRTSR.Overlap_STR.CANRTSRLSTR.Bits.TSR1
    #define CANRTSRL_TSR2               _CANRTSR.Overlap_STR.CANRTSRLSTR.Bits.TSR2
    #define CANRTSRL_TSR3               _CANRTSR.Overlap_STR.CANRTSRLSTR.Bits.TSR3
    #define CANRTSRL_TSR4               _CANRTSR.Overlap_STR.CANRTSRLSTR.Bits.TSR4
    #define CANRTSRL_TSR5               _CANRTSR.Overlap_STR.CANRTSRLSTR.Bits.TSR5
    #define CANRTSRL_TSR6               _CANRTSR.Overlap_STR.CANRTSRLSTR.Bits.TSR6
    #define CANRTSRL_TSR7               _CANRTSR.Overlap_STR.CANRTSRLSTR.Bits.TSR7
    
    
    #define CANRTSRL_TSR0_MASK          1
    #define CANRTSRL_TSR1_MASK          2
    #define CANRTSRL_TSR2_MASK          4
    #define CANRTSRL_TSR3_MASK          8
    #define CANRTSRL_TSR4_MASK          16
    #define CANRTSRL_TSR5_MASK          32
    #define CANRTSRL_TSR6_MASK          64
    #define CANRTSRL_TSR7_MASK          128

  } Overlap_STR;

} CANRTSRSTR;
volatile CANRTSRSTR __at (0x18AE) _CANRTSR;
#define CANRTSR                         _CANRTSR.Word




typedef union {
  byte Byte;
  struct {
    byte ID21        :1;                                       
    byte ID22        :1;                                       
    byte ID23        :1;                                       
    byte ID24        :1;                                       
    byte ID25        :1;                                       
    byte ID26        :1;                                       
    byte ID27        :1;                                       
    byte ID28        :1;                                       
  } Bits;
} CANTIDR0STR;
volatile CANTIDR0STR __at (0x18B0) _CANTIDR0;
#define CANTIDR0                        _CANTIDR0.Byte
#define CANTIDR0_ID21                   _CANTIDR0.Bits.ID21
#define CANTIDR0_ID22                   _CANTIDR0.Bits.ID22
#define CANTIDR0_ID23                   _CANTIDR0.Bits.ID23
#define CANTIDR0_ID24                   _CANTIDR0.Bits.ID24
#define CANTIDR0_ID25                   _CANTIDR0.Bits.ID25
#define CANTIDR0_ID26                   _CANTIDR0.Bits.ID26
#define CANTIDR0_ID27                   _CANTIDR0.Bits.ID27
#define CANTIDR0_ID28                   _CANTIDR0.Bits.ID28

#define CANTIDR_ARR                     ((volatile byte * __far) &CANTIDR0)

#define CANTIDR0_ID21_MASK              1
#define CANTIDR0_ID22_MASK              2
#define CANTIDR0_ID23_MASK              4
#define CANTIDR0_ID24_MASK              8
#define CANTIDR0_ID25_MASK              16
#define CANTIDR0_ID26_MASK              32
#define CANTIDR0_ID27_MASK              64
#define CANTIDR0_ID28_MASK              128



typedef union {
  byte Byte;
  struct {
    byte ID15        :1;                                       
    byte ID16        :1;                                       
    byte ID17        :1;                                       
    byte IDE         :1;                                       
    byte SRR         :1;                                       
    byte ID18        :1;                                       
    byte ID19        :1;                                       
    byte ID20        :1;                                       
  } Bits;
  struct {
    byte grpID_15 :3;
    byte         :1;
    byte         :1;
    byte grpID_18 :3;
  } MergedBits;
} CANTIDR1STR;
volatile CANTIDR1STR __at (0x18B1) _CANTIDR1;
#define CANTIDR1                        _CANTIDR1.Byte
#define CANTIDR1_ID15                   _CANTIDR1.Bits.ID15
#define CANTIDR1_ID16                   _CANTIDR1.Bits.ID16
#define CANTIDR1_ID17                   _CANTIDR1.Bits.ID17
#define CANTIDR1_IDE                    _CANTIDR1.Bits.IDE
#define CANTIDR1_SRR                    _CANTIDR1.Bits.SRR
#define CANTIDR1_ID18                   _CANTIDR1.Bits.ID18
#define CANTIDR1_ID19                   _CANTIDR1.Bits.ID19
#define CANTIDR1_ID20                   _CANTIDR1.Bits.ID20
#define CANTIDR1_ID_15                  _CANTIDR1.MergedBits.grpID_15
#define CANTIDR1_ID_18                  _CANTIDR1.MergedBits.grpID_18
#define CANTIDR1_ID                     CANTIDR1_ID_15

#define CANTIDR1_ID15_MASK              1
#define CANTIDR1_ID16_MASK              2
#define CANTIDR1_ID17_MASK              4
#define CANTIDR1_IDE_MASK               8
#define CANTIDR1_SRR_MASK               16
#define CANTIDR1_ID18_MASK              32
#define CANTIDR1_ID19_MASK              64
#define CANTIDR1_ID20_MASK              128
#define CANTIDR1_ID_15_MASK             7
#define CANTIDR1_ID_15_BITNUM           0
#define CANTIDR1_ID_18_MASK             224
#define CANTIDR1_ID_18_BITNUM           5



typedef union {
  byte Byte;
  struct {
    byte ID7         :1;                                       
    byte ID8         :1;                                       
    byte ID9         :1;                                       
    byte ID10        :1;                                       
    byte ID11        :1;                                       
    byte ID12        :1;                                       
    byte ID13        :1;                                       
    byte ID14        :1;                                       
  } Bits;
} CANTIDR2STR;
volatile CANTIDR2STR __at (0x18B2) _CANTIDR2;
#define CANTIDR2                        _CANTIDR2.Byte
#define CANTIDR2_ID7                    _CANTIDR2.Bits.ID7
#define CANTIDR2_ID8                    _CANTIDR2.Bits.ID8
#define CANTIDR2_ID9                    _CANTIDR2.Bits.ID9
#define CANTIDR2_ID10                   _CANTIDR2.Bits.ID10
#define CANTIDR2_ID11                   _CANTIDR2.Bits.ID11
#define CANTIDR2_ID12                   _CANTIDR2.Bits.ID12
#define CANTIDR2_ID13                   _CANTIDR2.Bits.ID13
#define CANTIDR2_ID14                   _CANTIDR2.Bits.ID14

#define CANTIDR2_ID7_MASK               1
#define CANTIDR2_ID8_MASK               2
#define CANTIDR2_ID9_MASK               4
#define CANTIDR2_ID10_MASK              8
#define CANTIDR2_ID11_MASK              16
#define CANTIDR2_ID12_MASK              32
#define CANTIDR2_ID13_MASK              64
#define CANTIDR2_ID14_MASK              128



typedef union {
  byte Byte;
  struct {
    byte RTR         :1;                                       
    byte ID0         :1;                                       
    byte ID1         :1;                                       
    byte ID2         :1;                                       
    byte ID3         :1;                                       
    byte ID4         :1;                                       
    byte ID5         :1;                                       
    byte ID6         :1;                                       
  } Bits;
  struct {
    byte         :1;
    byte grpID   :7;
  } MergedBits;
} CANTIDR3STR;
volatile CANTIDR3STR __at (0x18B3) _CANTIDR3;
#define CANTIDR3                        _CANTIDR3.Byte
#define CANTIDR3_RTR                    _CANTIDR3.Bits.RTR
#define CANTIDR3_ID0                    _CANTIDR3.Bits.ID0
#define CANTIDR3_ID1                    _CANTIDR3.Bits.ID1
#define CANTIDR3_ID2                    _CANTIDR3.Bits.ID2
#define CANTIDR3_ID3                    _CANTIDR3.Bits.ID3
#define CANTIDR3_ID4                    _CANTIDR3.Bits.ID4
#define CANTIDR3_ID5                    _CANTIDR3.Bits.ID5
#define CANTIDR3_ID6                    _CANTIDR3.Bits.ID6
#define CANTIDR3_ID                     _CANTIDR3.MergedBits.grpID

#define CANTIDR3_RTR_MASK               1
#define CANTIDR3_ID0_MASK               2
#define CANTIDR3_ID1_MASK               4
#define CANTIDR3_ID2_MASK               8
#define CANTIDR3_ID3_MASK               16
#define CANTIDR3_ID4_MASK               32
#define CANTIDR3_ID5_MASK               64
#define CANTIDR3_ID6_MASK               128
#define CANTIDR3_ID_MASK                254
#define CANTIDR3_ID_BITNUM              1



typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       
    byte DB1         :1;                                       
    byte DB2         :1;                                       
    byte DB3         :1;                                       
    byte DB4         :1;                                       
    byte DB5         :1;                                       
    byte DB6         :1;                                       
    byte DB7         :1;                                       
  } Bits;
} CANTDSR0STR;
volatile CANTDSR0STR __at (0x18B4) _CANTDSR0;
#define CANTDSR0                        _CANTDSR0.Byte
#define CANTDSR0_DB0                    _CANTDSR0.Bits.DB0
#define CANTDSR0_DB1                    _CANTDSR0.Bits.DB1
#define CANTDSR0_DB2                    _CANTDSR0.Bits.DB2
#define CANTDSR0_DB3                    _CANTDSR0.Bits.DB3
#define CANTDSR0_DB4                    _CANTDSR0.Bits.DB4
#define CANTDSR0_DB5                    _CANTDSR0.Bits.DB5
#define CANTDSR0_DB6                    _CANTDSR0.Bits.DB6
#define CANTDSR0_DB7                    _CANTDSR0.Bits.DB7

#define CANTDSR_ARR                     ((volatile byte * __far) &CANTDSR0)

#define CANTDSR0_DB0_MASK               1
#define CANTDSR0_DB1_MASK               2
#define CANTDSR0_DB2_MASK               4
#define CANTDSR0_DB3_MASK               8
#define CANTDSR0_DB4_MASK               16
#define CANTDSR0_DB5_MASK               32
#define CANTDSR0_DB6_MASK               64
#define CANTDSR0_DB7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       
    byte DB1         :1;                                       
    byte DB2         :1;                                       
    byte DB3         :1;                                       
    byte DB4         :1;                                       
    byte DB5         :1;                                       
    byte DB6         :1;                                       
    byte DB7         :1;                                       
  } Bits;
} CANTDSR1STR;
volatile CANTDSR1STR __at (0x18B5) _CANTDSR1;
#define CANTDSR1                        _CANTDSR1.Byte
#define CANTDSR1_DB0                    _CANTDSR1.Bits.DB0
#define CANTDSR1_DB1                    _CANTDSR1.Bits.DB1
#define CANTDSR1_DB2                    _CANTDSR1.Bits.DB2
#define CANTDSR1_DB3                    _CANTDSR1.Bits.DB3
#define CANTDSR1_DB4                    _CANTDSR1.Bits.DB4
#define CANTDSR1_DB5                    _CANTDSR1.Bits.DB5
#define CANTDSR1_DB6                    _CANTDSR1.Bits.DB6
#define CANTDSR1_DB7                    _CANTDSR1.Bits.DB7

#define CANTDSR1_DB0_MASK               1
#define CANTDSR1_DB1_MASK               2
#define CANTDSR1_DB2_MASK               4
#define CANTDSR1_DB3_MASK               8
#define CANTDSR1_DB4_MASK               16
#define CANTDSR1_DB5_MASK               32
#define CANTDSR1_DB6_MASK               64
#define CANTDSR1_DB7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       
    byte DB1         :1;                                       
    byte DB2         :1;                                       
    byte DB3         :1;                                       
    byte DB4         :1;                                       
    byte DB5         :1;                                       
    byte DB6         :1;                                       
    byte DB7         :1;                                       
  } Bits;
} CANTDSR2STR;
volatile CANTDSR2STR __at (0x18B6) _CANTDSR2;
#define CANTDSR2                        _CANTDSR2.Byte
#define CANTDSR2_DB0                    _CANTDSR2.Bits.DB0
#define CANTDSR2_DB1                    _CANTDSR2.Bits.DB1
#define CANTDSR2_DB2                    _CANTDSR2.Bits.DB2
#define CANTDSR2_DB3                    _CANTDSR2.Bits.DB3
#define CANTDSR2_DB4                    _CANTDSR2.Bits.DB4
#define CANTDSR2_DB5                    _CANTDSR2.Bits.DB5
#define CANTDSR2_DB6                    _CANTDSR2.Bits.DB6
#define CANTDSR2_DB7                    _CANTDSR2.Bits.DB7

#define CANTDSR2_DB0_MASK               1
#define CANTDSR2_DB1_MASK               2
#define CANTDSR2_DB2_MASK               4
#define CANTDSR2_DB3_MASK               8
#define CANTDSR2_DB4_MASK               16
#define CANTDSR2_DB5_MASK               32
#define CANTDSR2_DB6_MASK               64
#define CANTDSR2_DB7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       
    byte DB1         :1;                                       
    byte DB2         :1;                                       
    byte DB3         :1;                                       
    byte DB4         :1;                                       
    byte DB5         :1;                                       
    byte DB6         :1;                                       
    byte DB7         :1;                                       
  } Bits;
} CANTDSR3STR;
volatile CANTDSR3STR __at (0x18B7) _CANTDSR3;
#define CANTDSR3                        _CANTDSR3.Byte
#define CANTDSR3_DB0                    _CANTDSR3.Bits.DB0
#define CANTDSR3_DB1                    _CANTDSR3.Bits.DB1
#define CANTDSR3_DB2                    _CANTDSR3.Bits.DB2
#define CANTDSR3_DB3                    _CANTDSR3.Bits.DB3
#define CANTDSR3_DB4                    _CANTDSR3.Bits.DB4
#define CANTDSR3_DB5                    _CANTDSR3.Bits.DB5
#define CANTDSR3_DB6                    _CANTDSR3.Bits.DB6
#define CANTDSR3_DB7                    _CANTDSR3.Bits.DB7

#define CANTDSR3_DB0_MASK               1
#define CANTDSR3_DB1_MASK               2
#define CANTDSR3_DB2_MASK               4
#define CANTDSR3_DB3_MASK               8
#define CANTDSR3_DB4_MASK               16
#define CANTDSR3_DB5_MASK               32
#define CANTDSR3_DB6_MASK               64
#define CANTDSR3_DB7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       
    byte DB1         :1;                                       
    byte DB2         :1;                                       
    byte DB3         :1;                                       
    byte DB4         :1;                                       
    byte DB5         :1;                                       
    byte DB6         :1;                                       
    byte DB7         :1;                                       
  } Bits;
} CANTDSR4STR;
volatile CANTDSR4STR __at (0x18B8) _CANTDSR4;
#define CANTDSR4                        _CANTDSR4.Byte
#define CANTDSR4_DB0                    _CANTDSR4.Bits.DB0
#define CANTDSR4_DB1                    _CANTDSR4.Bits.DB1
#define CANTDSR4_DB2                    _CANTDSR4.Bits.DB2
#define CANTDSR4_DB3                    _CANTDSR4.Bits.DB3
#define CANTDSR4_DB4                    _CANTDSR4.Bits.DB4
#define CANTDSR4_DB5                    _CANTDSR4.Bits.DB5
#define CANTDSR4_DB6                    _CANTDSR4.Bits.DB6
#define CANTDSR4_DB7                    _CANTDSR4.Bits.DB7

#define CANTDSR4_DB0_MASK               1
#define CANTDSR4_DB1_MASK               2
#define CANTDSR4_DB2_MASK               4
#define CANTDSR4_DB3_MASK               8
#define CANTDSR4_DB4_MASK               16
#define CANTDSR4_DB5_MASK               32
#define CANTDSR4_DB6_MASK               64
#define CANTDSR4_DB7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       
    byte DB1         :1;                                       
    byte DB2         :1;                                       
    byte DB3         :1;                                       
    byte DB4         :1;                                       
    byte DB5         :1;                                       
    byte DB6         :1;                                       
    byte DB7         :1;                                       
  } Bits;
} CANTDSR5STR;
volatile CANTDSR5STR __at (0x18B9) _CANTDSR5;
#define CANTDSR5                        _CANTDSR5.Byte
#define CANTDSR5_DB0                    _CANTDSR5.Bits.DB0
#define CANTDSR5_DB1                    _CANTDSR5.Bits.DB1
#define CANTDSR5_DB2                    _CANTDSR5.Bits.DB2
#define CANTDSR5_DB3                    _CANTDSR5.Bits.DB3
#define CANTDSR5_DB4                    _CANTDSR5.Bits.DB4
#define CANTDSR5_DB5                    _CANTDSR5.Bits.DB5
#define CANTDSR5_DB6                    _CANTDSR5.Bits.DB6
#define CANTDSR5_DB7                    _CANTDSR5.Bits.DB7

#define CANTDSR5_DB0_MASK               1
#define CANTDSR5_DB1_MASK               2
#define CANTDSR5_DB2_MASK               4
#define CANTDSR5_DB3_MASK               8
#define CANTDSR5_DB4_MASK               16
#define CANTDSR5_DB5_MASK               32
#define CANTDSR5_DB6_MASK               64
#define CANTDSR5_DB7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       
    byte DB1         :1;                                       
    byte DB2         :1;                                       
    byte DB3         :1;                                       
    byte DB4         :1;                                       
    byte DB5         :1;                                       
    byte DB6         :1;                                       
    byte DB7         :1;                                       
  } Bits;
} CANTDSR6STR;
volatile CANTDSR6STR __at (0x18BA) _CANTDSR6;
#define CANTDSR6                        _CANTDSR6.Byte
#define CANTDSR6_DB0                    _CANTDSR6.Bits.DB0
#define CANTDSR6_DB1                    _CANTDSR6.Bits.DB1
#define CANTDSR6_DB2                    _CANTDSR6.Bits.DB2
#define CANTDSR6_DB3                    _CANTDSR6.Bits.DB3
#define CANTDSR6_DB4                    _CANTDSR6.Bits.DB4
#define CANTDSR6_DB5                    _CANTDSR6.Bits.DB5
#define CANTDSR6_DB6                    _CANTDSR6.Bits.DB6
#define CANTDSR6_DB7                    _CANTDSR6.Bits.DB7

#define CANTDSR6_DB0_MASK               1
#define CANTDSR6_DB1_MASK               2
#define CANTDSR6_DB2_MASK               4
#define CANTDSR6_DB3_MASK               8
#define CANTDSR6_DB4_MASK               16
#define CANTDSR6_DB5_MASK               32
#define CANTDSR6_DB6_MASK               64
#define CANTDSR6_DB7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       
    byte DB1         :1;                                       
    byte DB2         :1;                                       
    byte DB3         :1;                                       
    byte DB4         :1;                                       
    byte DB5         :1;                                       
    byte DB6         :1;                                       
    byte DB7         :1;                                       
  } Bits;
} CANTDSR7STR;
volatile CANTDSR7STR __at (0x18BB) _CANTDSR7;
#define CANTDSR7                        _CANTDSR7.Byte
#define CANTDSR7_DB0                    _CANTDSR7.Bits.DB0
#define CANTDSR7_DB1                    _CANTDSR7.Bits.DB1
#define CANTDSR7_DB2                    _CANTDSR7.Bits.DB2
#define CANTDSR7_DB3                    _CANTDSR7.Bits.DB3
#define CANTDSR7_DB4                    _CANTDSR7.Bits.DB4
#define CANTDSR7_DB5                    _CANTDSR7.Bits.DB5
#define CANTDSR7_DB6                    _CANTDSR7.Bits.DB6
#define CANTDSR7_DB7                    _CANTDSR7.Bits.DB7

#define CANTDSR7_DB0_MASK               1
#define CANTDSR7_DB1_MASK               2
#define CANTDSR7_DB2_MASK               4
#define CANTDSR7_DB3_MASK               8
#define CANTDSR7_DB4_MASK               16
#define CANTDSR7_DB5_MASK               32
#define CANTDSR7_DB6_MASK               64
#define CANTDSR7_DB7_MASK               128



typedef union {
  byte Byte;
  struct {
    byte DLC0        :1;                                       
    byte DLC1        :1;                                       
    byte DLC2        :1;                                       
    byte DLC3        :1;                                       
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDLC  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTDLRSTR;
volatile CANTDLRSTR __at (0x18BC) _CANTDLR;
#define CANTDLR                         _CANTDLR.Byte
#define CANTDLR_DLC0                    _CANTDLR.Bits.DLC0
#define CANTDLR_DLC1                    _CANTDLR.Bits.DLC1
#define CANTDLR_DLC2                    _CANTDLR.Bits.DLC2
#define CANTDLR_DLC3                    _CANTDLR.Bits.DLC3
#define CANTDLR_DLC                     _CANTDLR.MergedBits.grpDLC

#define CANTDLR_DLC0_MASK               1
#define CANTDLR_DLC1_MASK               2
#define CANTDLR_DLC2_MASK               4
#define CANTDLR_DLC3_MASK               8
#define CANTDLR_DLC_MASK                15
#define CANTDLR_DLC_BITNUM              0



typedef union {
  byte Byte;
  struct {
    byte PRIO0       :1;                                       
    byte PRIO1       :1;                                       
    byte PRIO2       :1;                                       
    byte PRIO3       :1;                                       
    byte PRIO4       :1;                                       
    byte PRIO5       :1;                                       
    byte PRIO6       :1;                                       
    byte PRIO7       :1;                                       
  } Bits;
} CANTTBPRSTR;
volatile CANTTBPRSTR __at (0x18BD) _CANTTBPR;
#define CANTTBPR                        _CANTTBPR.Byte
#define CANTTBPR_PRIO0                  _CANTTBPR.Bits.PRIO0
#define CANTTBPR_PRIO1                  _CANTTBPR.Bits.PRIO1
#define CANTTBPR_PRIO2                  _CANTTBPR.Bits.PRIO2
#define CANTTBPR_PRIO3                  _CANTTBPR.Bits.PRIO3
#define CANTTBPR_PRIO4                  _CANTTBPR.Bits.PRIO4
#define CANTTBPR_PRIO5                  _CANTTBPR.Bits.PRIO5
#define CANTTBPR_PRIO6                  _CANTTBPR.Bits.PRIO6
#define CANTTBPR_PRIO7                  _CANTTBPR.Bits.PRIO7

#define CANTTBPR_PRIO0_MASK             1
#define CANTTBPR_PRIO1_MASK             2
#define CANTTBPR_PRIO2_MASK             4
#define CANTTBPR_PRIO3_MASK             8
#define CANTTBPR_PRIO4_MASK             16
#define CANTTBPR_PRIO5_MASK             32
#define CANTTBPR_PRIO6_MASK             64
#define CANTTBPR_PRIO7_MASK             128



typedef union {
  word Word;
   
  struct {
    
    union {
      byte Byte;
      struct {
        byte TSR8        :1;                                       
        byte TSR9        :1;                                       
        byte TSR10       :1;                                       
        byte TSR11       :1;                                       
        byte TSR12       :1;                                       
        byte TSR13       :1;                                       
        byte TSR14       :1;                                       
        byte TSR15       :1;                                       
      } Bits;
    } CANTTSRHSTR;
    #define CANTTSRH                    _CANTTSR.Overlap_STR.CANTTSRHSTR.Byte
    #define CANTTSRH_TSR8               _CANTTSR.Overlap_STR.CANTTSRHSTR.Bits.TSR8
    #define CANTTSRH_TSR9               _CANTTSR.Overlap_STR.CANTTSRHSTR.Bits.TSR9
    #define CANTTSRH_TSR10              _CANTTSR.Overlap_STR.CANTTSRHSTR.Bits.TSR10
    #define CANTTSRH_TSR11              _CANTTSR.Overlap_STR.CANTTSRHSTR.Bits.TSR11
    #define CANTTSRH_TSR12              _CANTTSR.Overlap_STR.CANTTSRHSTR.Bits.TSR12
    #define CANTTSRH_TSR13              _CANTTSR.Overlap_STR.CANTTSRHSTR.Bits.TSR13
    #define CANTTSRH_TSR14              _CANTTSR.Overlap_STR.CANTTSRHSTR.Bits.TSR14
    #define CANTTSRH_TSR15              _CANTTSR.Overlap_STR.CANTTSRHSTR.Bits.TSR15
    
    
    #define CANTTSRH_TSR8_MASK          1
    #define CANTTSRH_TSR9_MASK          2
    #define CANTTSRH_TSR10_MASK         4
    #define CANTTSRH_TSR11_MASK         8
    #define CANTTSRH_TSR12_MASK         16
    #define CANTTSRH_TSR13_MASK         32
    #define CANTTSRH_TSR14_MASK         64
    #define CANTTSRH_TSR15_MASK         128


    
    union {
      byte Byte;
      struct {
        byte TSR0        :1;                                       
        byte TSR1        :1;                                       
        byte TSR2        :1;                                       
        byte TSR3        :1;                                       
        byte TSR4        :1;                                       
        byte TSR5        :1;                                       
        byte TSR6        :1;                                       
        byte TSR7        :1;                                       
      } Bits;
    } CANTTSRLSTR;
    #define CANTTSRL                    _CANTTSR.Overlap_STR.CANTTSRLSTR.Byte
    #define CANTTSRL_TSR0               _CANTTSR.Overlap_STR.CANTTSRLSTR.Bits.TSR0
    #define CANTTSRL_TSR1               _CANTTSR.Overlap_STR.CANTTSRLSTR.Bits.TSR1
    #define CANTTSRL_TSR2               _CANTTSR.Overlap_STR.CANTTSRLSTR.Bits.TSR2
    #define CANTTSRL_TSR3               _CANTTSR.Overlap_STR.CANTTSRLSTR.Bits.TSR3
    #define CANTTSRL_TSR4               _CANTTSR.Overlap_STR.CANTTSRLSTR.Bits.TSR4
    #define CANTTSRL_TSR5               _CANTTSR.Overlap_STR.CANTTSRLSTR.Bits.TSR5
    #define CANTTSRL_TSR6               _CANTTSR.Overlap_STR.CANTTSRLSTR.Bits.TSR6
    #define CANTTSRL_TSR7               _CANTTSR.Overlap_STR.CANTTSRLSTR.Bits.TSR7
    
    
    #define CANTTSRL_TSR0_MASK          1
    #define CANTTSRL_TSR1_MASK          2
    #define CANTTSRL_TSR2_MASK          4
    #define CANTTSRL_TSR3_MASK          8
    #define CANTTSRL_TSR4_MASK          16
    #define CANTTSRL_TSR5_MASK          32
    #define CANTTSRL_TSR6_MASK          64
    #define CANTTSRL_TSR7_MASK          128

  } Overlap_STR;

} CANTTSRSTR;
volatile CANTTSRSTR __at (0x18BE) _CANTTSR;
#define CANTTSR                         _CANTTSR.Word




typedef union {
  byte Byte;
  struct {
    byte FTRIM       :1;                                       
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} NVFTRIMSTR;
volatile NVFTRIMSTR __at (0xFFAE) _NVFTRIM;
#define NVFTRIM                         _NVFTRIM.Byte
#define NVFTRIM_FTRIM                   _NVFTRIM.Bits.FTRIM

#define NVFTRIM_FTRIM_MASK              1



typedef union {
  byte Byte;
  struct {
    byte TRIM0       :1;                                       
    byte TRIM1       :1;                                       
    byte TRIM2       :1;                                       
    byte TRIM3       :1;                                       
    byte TRIM4       :1;                                       
    byte TRIM5       :1;                                       
    byte TRIM6       :1;                                       
    byte TRIM7       :1;                                       
  } Bits;
} NVMCGTRMSTR;
volatile NVMCGTRMSTR __at (0xFFAF) _NVMCGTRM;
#define NVMCGTRM                        _NVMCGTRM.Byte
#define NVMCGTRM_TRIM0                  _NVMCGTRM.Bits.TRIM0
#define NVMCGTRM_TRIM1                  _NVMCGTRM.Bits.TRIM1
#define NVMCGTRM_TRIM2                  _NVMCGTRM.Bits.TRIM2
#define NVMCGTRM_TRIM3                  _NVMCGTRM.Bits.TRIM3
#define NVMCGTRM_TRIM4                  _NVMCGTRM.Bits.TRIM4
#define NVMCGTRM_TRIM5                  _NVMCGTRM.Bits.TRIM5
#define NVMCGTRM_TRIM6                  _NVMCGTRM.Bits.TRIM6
#define NVMCGTRM_TRIM7                  _NVMCGTRM.Bits.TRIM7

#define NVMCGTRM_TRIM0_MASK             1
#define NVMCGTRM_TRIM1_MASK             2
#define NVMCGTRM_TRIM2_MASK             4
#define NVMCGTRM_TRIM3_MASK             8
#define NVMCGTRM_TRIM4_MASK             16
#define NVMCGTRM_TRIM5_MASK             32
#define NVMCGTRM_TRIM6_MASK             64
#define NVMCGTRM_TRIM7_MASK             128



typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       
    byte KEY1        :1;                                       
    byte KEY2        :1;                                       
    byte KEY3        :1;                                       
    byte KEY4        :1;                                       
    byte KEY5        :1;                                       
    byte KEY6        :1;                                       
    byte KEY7        :1;                                       
  } Bits;
} NVBACKKEY0STR;

#define _NVBACKKEY0 (*(const NVBACKKEY0STR * __far)0x0000FFB0)
#define NVBACKKEY0                      _NVBACKKEY0.Byte
#define NVBACKKEY0_KEY0                 _NVBACKKEY0.Bits.KEY0
#define NVBACKKEY0_KEY1                 _NVBACKKEY0.Bits.KEY1
#define NVBACKKEY0_KEY2                 _NVBACKKEY0.Bits.KEY2
#define NVBACKKEY0_KEY3                 _NVBACKKEY0.Bits.KEY3
#define NVBACKKEY0_KEY4                 _NVBACKKEY0.Bits.KEY4
#define NVBACKKEY0_KEY5                 _NVBACKKEY0.Bits.KEY5
#define NVBACKKEY0_KEY6                 _NVBACKKEY0.Bits.KEY6
#define NVBACKKEY0_KEY7                 _NVBACKKEY0.Bits.KEY7

#define NVBACKKEY_ARR                   ((volatile byte * __far) &NVBACKKEY0)

#define NVBACKKEY0_KEY0_MASK            1
#define NVBACKKEY0_KEY1_MASK            2
#define NVBACKKEY0_KEY2_MASK            4
#define NVBACKKEY0_KEY3_MASK            8
#define NVBACKKEY0_KEY4_MASK            16
#define NVBACKKEY0_KEY5_MASK            32
#define NVBACKKEY0_KEY6_MASK            64
#define NVBACKKEY0_KEY7_MASK            128



typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       
    byte KEY1        :1;                                       
    byte KEY2        :1;                                       
    byte KEY3        :1;                                       
    byte KEY4        :1;                                       
    byte KEY5        :1;                                       
    byte KEY6        :1;                                       
    byte KEY7        :1;                                       
  } Bits;
} NVBACKKEY1STR;

#define _NVBACKKEY1 (*(const NVBACKKEY1STR * __far)0x0000FFB1)
#define NVBACKKEY1                      _NVBACKKEY1.Byte
#define NVBACKKEY1_KEY0                 _NVBACKKEY1.Bits.KEY0
#define NVBACKKEY1_KEY1                 _NVBACKKEY1.Bits.KEY1
#define NVBACKKEY1_KEY2                 _NVBACKKEY1.Bits.KEY2
#define NVBACKKEY1_KEY3                 _NVBACKKEY1.Bits.KEY3
#define NVBACKKEY1_KEY4                 _NVBACKKEY1.Bits.KEY4
#define NVBACKKEY1_KEY5                 _NVBACKKEY1.Bits.KEY5
#define NVBACKKEY1_KEY6                 _NVBACKKEY1.Bits.KEY6
#define NVBACKKEY1_KEY7                 _NVBACKKEY1.Bits.KEY7

#define NVBACKKEY1_KEY0_MASK            1
#define NVBACKKEY1_KEY1_MASK            2
#define NVBACKKEY1_KEY2_MASK            4
#define NVBACKKEY1_KEY3_MASK            8
#define NVBACKKEY1_KEY4_MASK            16
#define NVBACKKEY1_KEY5_MASK            32
#define NVBACKKEY1_KEY6_MASK            64
#define NVBACKKEY1_KEY7_MASK            128



typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       
    byte KEY1        :1;                                       
    byte KEY2        :1;                                       
    byte KEY3        :1;                                       
    byte KEY4        :1;                                       
    byte KEY5        :1;                                       
    byte KEY6        :1;                                       
    byte KEY7        :1;                                       
  } Bits;
} NVBACKKEY2STR;

#define _NVBACKKEY2 (*(const NVBACKKEY2STR * __far)0x0000FFB2)
#define NVBACKKEY2                      _NVBACKKEY2.Byte
#define NVBACKKEY2_KEY0                 _NVBACKKEY2.Bits.KEY0
#define NVBACKKEY2_KEY1                 _NVBACKKEY2.Bits.KEY1
#define NVBACKKEY2_KEY2                 _NVBACKKEY2.Bits.KEY2
#define NVBACKKEY2_KEY3                 _NVBACKKEY2.Bits.KEY3
#define NVBACKKEY2_KEY4                 _NVBACKKEY2.Bits.KEY4
#define NVBACKKEY2_KEY5                 _NVBACKKEY2.Bits.KEY5
#define NVBACKKEY2_KEY6                 _NVBACKKEY2.Bits.KEY6
#define NVBACKKEY2_KEY7                 _NVBACKKEY2.Bits.KEY7

#define NVBACKKEY2_KEY0_MASK            1
#define NVBACKKEY2_KEY1_MASK            2
#define NVBACKKEY2_KEY2_MASK            4
#define NVBACKKEY2_KEY3_MASK            8
#define NVBACKKEY2_KEY4_MASK            16
#define NVBACKKEY2_KEY5_MASK            32
#define NVBACKKEY2_KEY6_MASK            64
#define NVBACKKEY2_KEY7_MASK            128



typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       
    byte KEY1        :1;                                       
    byte KEY2        :1;                                       
    byte KEY3        :1;                                       
    byte KEY4        :1;                                       
    byte KEY5        :1;                                       
    byte KEY6        :1;                                       
    byte KEY7        :1;                                       
  } Bits;
} NVBACKKEY3STR;

#define _NVBACKKEY3 (*(const NVBACKKEY3STR * __far)0x0000FFB3)
#define NVBACKKEY3                      _NVBACKKEY3.Byte
#define NVBACKKEY3_KEY0                 _NVBACKKEY3.Bits.KEY0
#define NVBACKKEY3_KEY1                 _NVBACKKEY3.Bits.KEY1
#define NVBACKKEY3_KEY2                 _NVBACKKEY3.Bits.KEY2
#define NVBACKKEY3_KEY3                 _NVBACKKEY3.Bits.KEY3
#define NVBACKKEY3_KEY4                 _NVBACKKEY3.Bits.KEY4
#define NVBACKKEY3_KEY5                 _NVBACKKEY3.Bits.KEY5
#define NVBACKKEY3_KEY6                 _NVBACKKEY3.Bits.KEY6
#define NVBACKKEY3_KEY7                 _NVBACKKEY3.Bits.KEY7

#define NVBACKKEY3_KEY0_MASK            1
#define NVBACKKEY3_KEY1_MASK            2
#define NVBACKKEY3_KEY2_MASK            4
#define NVBACKKEY3_KEY3_MASK            8
#define NVBACKKEY3_KEY4_MASK            16
#define NVBACKKEY3_KEY5_MASK            32
#define NVBACKKEY3_KEY6_MASK            64
#define NVBACKKEY3_KEY7_MASK            128



typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       
    byte KEY1        :1;                                       
    byte KEY2        :1;                                       
    byte KEY3        :1;                                       
    byte KEY4        :1;                                       
    byte KEY5        :1;                                       
    byte KEY6        :1;                                       
    byte KEY7        :1;                                       
  } Bits;
} NVBACKKEY4STR;

#define _NVBACKKEY4 (*(const NVBACKKEY4STR * __far)0x0000FFB4)
#define NVBACKKEY4                      _NVBACKKEY4.Byte
#define NVBACKKEY4_KEY0                 _NVBACKKEY4.Bits.KEY0
#define NVBACKKEY4_KEY1                 _NVBACKKEY4.Bits.KEY1
#define NVBACKKEY4_KEY2                 _NVBACKKEY4.Bits.KEY2
#define NVBACKKEY4_KEY3                 _NVBACKKEY4.Bits.KEY3
#define NVBACKKEY4_KEY4                 _NVBACKKEY4.Bits.KEY4
#define NVBACKKEY4_KEY5                 _NVBACKKEY4.Bits.KEY5
#define NVBACKKEY4_KEY6                 _NVBACKKEY4.Bits.KEY6
#define NVBACKKEY4_KEY7                 _NVBACKKEY4.Bits.KEY7

#define NVBACKKEY4_KEY0_MASK            1
#define NVBACKKEY4_KEY1_MASK            2
#define NVBACKKEY4_KEY2_MASK            4
#define NVBACKKEY4_KEY3_MASK            8
#define NVBACKKEY4_KEY4_MASK            16
#define NVBACKKEY4_KEY5_MASK            32
#define NVBACKKEY4_KEY6_MASK            64
#define NVBACKKEY4_KEY7_MASK            128



typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       
    byte KEY1        :1;                                       
    byte KEY2        :1;                                       
    byte KEY3        :1;                                       
    byte KEY4        :1;                                       
    byte KEY5        :1;                                       
    byte KEY6        :1;                                       
    byte KEY7        :1;                                       
  } Bits;
} NVBACKKEY5STR;

#define _NVBACKKEY5 (*(const NVBACKKEY5STR * __far)0x0000FFB5)
#define NVBACKKEY5                      _NVBACKKEY5.Byte
#define NVBACKKEY5_KEY0                 _NVBACKKEY5.Bits.KEY0
#define NVBACKKEY5_KEY1                 _NVBACKKEY5.Bits.KEY1
#define NVBACKKEY5_KEY2                 _NVBACKKEY5.Bits.KEY2
#define NVBACKKEY5_KEY3                 _NVBACKKEY5.Bits.KEY3
#define NVBACKKEY5_KEY4                 _NVBACKKEY5.Bits.KEY4
#define NVBACKKEY5_KEY5                 _NVBACKKEY5.Bits.KEY5
#define NVBACKKEY5_KEY6                 _NVBACKKEY5.Bits.KEY6
#define NVBACKKEY5_KEY7                 _NVBACKKEY5.Bits.KEY7

#define NVBACKKEY5_KEY0_MASK            1
#define NVBACKKEY5_KEY1_MASK            2
#define NVBACKKEY5_KEY2_MASK            4
#define NVBACKKEY5_KEY3_MASK            8
#define NVBACKKEY5_KEY4_MASK            16
#define NVBACKKEY5_KEY5_MASK            32
#define NVBACKKEY5_KEY6_MASK            64
#define NVBACKKEY5_KEY7_MASK            128



typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       
    byte KEY1        :1;                                       
    byte KEY2        :1;                                       
    byte KEY3        :1;                                       
    byte KEY4        :1;                                       
    byte KEY5        :1;                                       
    byte KEY6        :1;                                       
    byte KEY7        :1;                                       
  } Bits;
} NVBACKKEY6STR;

#define _NVBACKKEY6 (*(const NVBACKKEY6STR * __far)0x0000FFB6)
#define NVBACKKEY6                      _NVBACKKEY6.Byte
#define NVBACKKEY6_KEY0                 _NVBACKKEY6.Bits.KEY0
#define NVBACKKEY6_KEY1                 _NVBACKKEY6.Bits.KEY1
#define NVBACKKEY6_KEY2                 _NVBACKKEY6.Bits.KEY2
#define NVBACKKEY6_KEY3                 _NVBACKKEY6.Bits.KEY3
#define NVBACKKEY6_KEY4                 _NVBACKKEY6.Bits.KEY4
#define NVBACKKEY6_KEY5                 _NVBACKKEY6.Bits.KEY5
#define NVBACKKEY6_KEY6                 _NVBACKKEY6.Bits.KEY6
#define NVBACKKEY6_KEY7                 _NVBACKKEY6.Bits.KEY7

#define NVBACKKEY6_KEY0_MASK            1
#define NVBACKKEY6_KEY1_MASK            2
#define NVBACKKEY6_KEY2_MASK            4
#define NVBACKKEY6_KEY3_MASK            8
#define NVBACKKEY6_KEY4_MASK            16
#define NVBACKKEY6_KEY5_MASK            32
#define NVBACKKEY6_KEY6_MASK            64
#define NVBACKKEY6_KEY7_MASK            128



typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       
    byte KEY1        :1;                                       
    byte KEY2        :1;                                       
    byte KEY3        :1;                                       
    byte KEY4        :1;                                       
    byte KEY5        :1;                                       
    byte KEY6        :1;                                       
    byte KEY7        :1;                                       
  } Bits;
} NVBACKKEY7STR;

#define _NVBACKKEY7 (*(const NVBACKKEY7STR * __far)0x0000FFB7)
#define NVBACKKEY7                      _NVBACKKEY7.Byte
#define NVBACKKEY7_KEY0                 _NVBACKKEY7.Bits.KEY0
#define NVBACKKEY7_KEY1                 _NVBACKKEY7.Bits.KEY1
#define NVBACKKEY7_KEY2                 _NVBACKKEY7.Bits.KEY2
#define NVBACKKEY7_KEY3                 _NVBACKKEY7.Bits.KEY3
#define NVBACKKEY7_KEY4                 _NVBACKKEY7.Bits.KEY4
#define NVBACKKEY7_KEY5                 _NVBACKKEY7.Bits.KEY5
#define NVBACKKEY7_KEY6                 _NVBACKKEY7.Bits.KEY6
#define NVBACKKEY7_KEY7                 _NVBACKKEY7.Bits.KEY7

#define NVBACKKEY7_KEY0_MASK            1
#define NVBACKKEY7_KEY1_MASK            2
#define NVBACKKEY7_KEY2_MASK            4
#define NVBACKKEY7_KEY3_MASK            8
#define NVBACKKEY7_KEY4_MASK            16
#define NVBACKKEY7_KEY5_MASK            32
#define NVBACKKEY7_KEY6_MASK            64
#define NVBACKKEY7_KEY7_MASK            128



typedef union {
  byte Byte;
  struct {
    byte FPS0        :1;                                       
    byte FPS1        :1;                                       
    byte FPS2        :1;                                       
    byte FPS3        :1;                                       
    byte FPS4        :1;                                       
    byte FPS5        :1;                                       
    byte EPS0        :1;                                       
    byte EPS1        :1;                                       
  } Bits;
  struct {
    byte grpFPS  :6;
    byte grpEPS  :2;
  } MergedBits;
} NVPROTSTR;

#define _NVPROT (*(const NVPROTSTR * __far)0x0000FFBD)
#define NVPROT                          _NVPROT.Byte
#define NVPROT_FPS0                     _NVPROT.Bits.FPS0
#define NVPROT_FPS1                     _NVPROT.Bits.FPS1
#define NVPROT_FPS2                     _NVPROT.Bits.FPS2
#define NVPROT_FPS3                     _NVPROT.Bits.FPS3
#define NVPROT_FPS4                     _NVPROT.Bits.FPS4
#define NVPROT_FPS5                     _NVPROT.Bits.FPS5
#define NVPROT_EPS0                     _NVPROT.Bits.EPS0
#define NVPROT_EPS1                     _NVPROT.Bits.EPS1
#define NVPROT_FPS                      _NVPROT.MergedBits.grpFPS
#define NVPROT_EPS                      _NVPROT.MergedBits.grpEPS

#define NVPROT_FPS0_MASK                1
#define NVPROT_FPS1_MASK                2
#define NVPROT_FPS2_MASK                4
#define NVPROT_FPS3_MASK                8
#define NVPROT_FPS4_MASK                16
#define NVPROT_FPS5_MASK                32
#define NVPROT_EPS0_MASK                64
#define NVPROT_EPS1_MASK                128
#define NVPROT_FPS_MASK                 63
#define NVPROT_FPS_BITNUM               0
#define NVPROT_EPS_MASK                 192
#define NVPROT_EPS_BITNUM               6



typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       
    byte SEC1        :1;                                       
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte EPGMOD      :1;                                       
    byte FNORED      :1;                                       
    byte KEYEN       :1;                                       
  } Bits;
  struct {
    byte grpSEC  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NVOPTSTR;

#define _NVOPT (*(const NVOPTSTR * __far)0x0000FFBF)
#define NVOPT                           _NVOPT.Byte
#define NVOPT_SEC0                      _NVOPT.Bits.SEC0
#define NVOPT_SEC1                      _NVOPT.Bits.SEC1
#define NVOPT_EPGMOD                    _NVOPT.Bits.EPGMOD
#define NVOPT_FNORED                    _NVOPT.Bits.FNORED
#define NVOPT_KEYEN                     _NVOPT.Bits.KEYEN
#define NVOPT_SEC                       _NVOPT.MergedBits.grpSEC

#define NVOPT_SEC0_MASK                 1
#define NVOPT_SEC1_MASK                 2
#define NVOPT_EPGMOD_MASK               32
#define NVOPT_FNORED_MASK               64
#define NVOPT_KEYEN_MASK                128
#define NVOPT_SEC_MASK                  3
#define NVOPT_SEC_BITNUM                0




#define mBlank                          0x05
#define mByteProg                       0x20
#define mBurstProg                      0x25
#define mSectorErase                    0x40
#define mMassErase                      0x41
#define mEraseAbort                     0x47








#define IICC                             IICC1
#define IICC_RSTA                        IICC1_RSTA
#define IICC_RSTA_MASK                   IICC1_RSTA_MASK
#define IICC_TXAK                        IICC1_TXAK
#define IICC_TXAK_MASK                   IICC1_TXAK_MASK
#define IICC_TX                          IICC1_TX
#define IICC_TX_MASK                     IICC1_TX_MASK
#define IICC_MST                         IICC1_MST
#define IICC_MST_MASK                    IICC1_MST_MASK
#define IICC_IICIE                       IICC1_IICIE
#define IICC_IICIE_MASK                  IICC1_IICIE_MASK
#define IICC_IICEN                       IICC1_IICEN
#define IICC_IICEN_MASK                  IICC1_IICEN_MASK
#endif

