#
# Copyright (c) 2011 Michael Smith, All Rights Reserved
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
#  o Redistributions of source code must retain the above copyright 
#    notice, this list of conditions and the following disclaimer.
#  o Redistributions in binary form must reproduce the above copyright 
#    notice, this list of conditions and the following disclaimer in 
#    the documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
# INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
# STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
# OF THE POSSIBILITY OF SUCH DAMAGE.
#
#
# Common rules and targets.
#

ifeq ($(BOARD),)
$(error BOARD not defined)
endif
ifeq ($(SRCROOT),)
$(error SRCROOT not defined)
endif

#
# Common build options.
#
CFLAGS		+=	-DBOARD_$(BOARD) \
			--stack-loc 0x107e \
			--std-sdcc11 \
			$(addprefix -D,$(DEFINES))

LDFLAGS		 =	--code-loc 0x2200 \
			--data-loc 0x0080 \
			--out-fmt-s19

#
# Paths.
#
OBJROOT		?=	$(SRCROOT)/obj/$(BOARD)/$(PRODUCT)
DSTROOT		?=	$(SRCROOT)/dst
LIB_DIR		 =	$(SRCROOT)/lib

#
# Buildable and installable products
#
PRODUCT_SREC	 =	$(OBJROOT)/$(PRODUCT).s19
PRODUCT_INSTALL	?=	$(PRODUCT_SREC)

#
# Compiler and tools
#
ifeq ($(shell which sdcc),)
$(error Could not find SDCC on your path - cannot build)
endif
CC		 =	sdcc -ms08
AS		 =	sdas6808 -losp
LD		 =	sdcc -ms08
INCLUDES	 =	$(SRCROOT)/include
CFLAGS		+=	$(addprefix -I,$(INCLUDES))
DEPFLAGS	 =	-MM $(CFLAGS)
SREC_FIXUP	 =	$(SRCROOT)/tools/fix_srecords.py

#
# Non-optional library modules
#
LIB_MODULES	+=	_sdcc_external_startup
DEFINES		+=	$(addprefix WITH_,$(LIB_MODULES))

#
# Assembly source/objects must come first to ensure startup files
# can be in front.
#
ASRCS		+=	$(sort $(wildcard $(PRODUCT_DIR)/*.asm))
OBJS		+=	$(patsubst $(PRODUCT_DIR)/%.asm,$(OBJROOT)/%.rel,$(ASRCS))
CSRCS		+=	$(wildcard $(PRODUCT_DIR)/*.c)
LIBSRCS		+=	$(foreach module,$(LIB_MODULES),$(LIB_DIR)/$(module).c)
OBJS		+=	$(patsubst $(PRODUCT_DIR)/%.c,$(OBJROOT)/%.rel,$(CSRCS))
OBJS		+=	$(patsubst $(LIB_DIR)/%.c,$(OBJROOT)/%.rel,$(LIBSRCS))
#$(info $(OBJS))

ifeq ($(VERBOSE),)
v		 =	@
else
CFLAGS		+=	-V
endif

#
# Build rules
#
build:	$(PRODUCT_SREC)

$(PRODUCT_SREC):	$(OBJS)
	@echo LD $@
	@mkdir -p $(@D)
	$(v)$(LD) $(LDFLAGS) -o $@ $(OBJS)
	@echo `grep '^CSEG' obj/MICROPLEX_7X/blink/blink.map | cut -c 66-70`/36219 bytes used
	$(v)$(SREC_FIXUP) $@ || rm -f $@

$(OBJROOT)/%.rel: $(PRODUCT_DIR)/%.c
	@mkdir -p $(@D)
	@echo DEP $<
	$(v)(/bin/echo -n $(@D)/ && $(CC) $(DEPFLAGS) $<) > $@.dep
	@echo CC $<
	$(v)$(CC) -c -o $@ $(CFLAGS) $<

$(OBJROOT)/%.rel: $(PRODUCT_DIR)/%.asm
	@echo AS $<
	@mkdir -p $(@D)
	$(v)cp $< $(subst $(PRODUCT_DIR),$(OBJROOT),$<)
	$(v)$(AS) $(ASFLAGS) $(subst $(PRODUCT_DIR),$(OBJROOT),$<)

$(OBJROOT)/%.rel: $(LIB_DIR)/%.c
	@mkdir -p $(@D)
	@echo DEP $<
	$(v)(/bin/echo -n $(@D)/ && $(CC) $(DEPFLAGS) $<) > $@.dep
	@echo CC $<
	$(v)$(CC) -c -o $@ $(CFLAGS) $<

clean:
	$(v)rm -rf $(OBJROOT)/../*

#
# Dependencies
#
GLOBAL_DEPS	+=	$(MAKEFILE_LIST)
$(OBJS):	$(GLOBAL_DEPS)
-include $(wildcard $(OBJROOT)/*.dep)
