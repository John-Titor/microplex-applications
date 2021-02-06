#
# Makefile for the Hello Kitty E36 tail light / sensor module.
#
PRODUCT      = e36-tail-module
PRODUCT_DIR := $(patsubst %/,%,$(dir $(lastword $(MAKEFILE_LIST))))
LIB_MODULES  = mscan adc pwm

BOARD        = MICROPLEX_7X

CFLAGS       = --opt-code-size --Werror
LDFLAGS      =

include $(SRCROOT)/include/rules.mk
