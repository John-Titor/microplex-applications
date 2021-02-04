#
# Makefile for messing around with the MRS Microplex devices
#

#
# Generic actions (targets) that the user may invoke.
#
ACTIONS		 = build clean flash

#
# Locate the root of the source tree.
#
export SRCROOT	:= $(abspath $(dir $(lastword $(MAKEFILE_LIST))))

#
# Things we will try to build
#
APPS	 	 ?= blink

#
# Build a full list of targets.
#
TARGETS		 = $(foreach action,$(ACTIONS), \
			$(foreach app,$(APPS), \
				$(action)~$(app)))

all:		build

#
# Composite targets for handling actions.
#
build:		$(filter build~%,$(TARGETS))
clean:		$(filter clean~%,$(TARGETS))
flash:		$(filter flash~%,$(TARGETS))

#
# Call the app makefiles to do the things
#
$(TARGETS):	config  = $(subst ~, ,$@)
$(TARGETS):	action  = $(word 1, $(config))
$(TARGETS):	app	= $(word 2, $(config))
$(TARGETS):
	@echo % $(action) $(app)
	@$(MAKE) -f $(app)/app.mk $(action) \
		APP=$(APP)

.PHONY:	$(ACTIONS) $(TARGETS)

help:
	@echo ""
	@echo "Build things."
	@echo ""
	@echo "Common targets are:"
	@echo ""
	@echo "    all         - Builds everything, this is the default target."
	@echo "    clean       - Cleans all build products"
	@echo ""
	@echo "Common options:"
	@echo ""
	@echo "    RELEASE=1   - Build the release (no assertions, no debug logging)"
	@echo "                  configuration."
	@echo ""
	@echo "A specific app may be built by selecting one or more of the following targets:"
	@echo ""
	@for i in $(TARGETS); do echo "    $$i"; done
	@echo ""
	@echo "The following maintenance targets are mostly of interest to"
	@echo "developers:"
	@echo ""
	@echo "    format      - Automatically (re)formats source code to conform"
	@echo "                  to the project coding style.  Should be used before"
	@echo "                  checking in or submitting a patch."
	@echo ""


.PHONY:	format
format:
	astyle -r $(FMT) "*.c" "*.h"
#
# Below are options passed to Artistic Style for the format target
#

# Basic style is what AS calls K&R
FMT		+= --style=kr

# Indent using 8-space tabs
FMT		+= --indent=spaces=4

# Don't make backups
FMT		+= --suffix=none

# Indent multiline preprocessor blocks
FMT		+= --indent-preprocessor

# Do smart multiline expression indentation
FMT		+= --min-conditional-indent=0

# Pad conditionals and else blocks
# Not sure about this one yet
#FMT		+= --break-blocks=all

# Add space padding around operators
FMT		+= --pad-oper

# Add space padding after paren headers
FMT		+= --pad-header

# Clean up excess paren padding
FMT		+= --unpad-paren

# Avoid breaking up 'clever' formatting
FMT		+= --keep-one-line-blocks
FMT		+= --keep-one-line-statements

# * belongs with the name (looks good, but syntactically bad)
FMT		+= --align-pointer=name

# force *nix line endings
FMT		+= --lineend=linux

# ignore various things that should be ignored
FMT		+= --ignore-exclude-errors-x
FMT		+= --exclude=obj

# ignore various files we want to be able to diff with upstream providers
FMT		+= --exclude=mc9s08dz60.h
