# -*- makefile -*-
#----------------------------------------------------------------------------
#       GNU ACE Workspace
#
# 
#
# This file was generated by MPC.  Any changes made directly to
# this file will be lost the next time it is generated.
#
# MPC Command:
# /home/johnny/DOC_ROOT/stage-4253/ACE_wrappers/bin/mwc.pl -type gnuace -exclude TAO/TAO_ACE.mwc -workers 8 -recurse -hierarchy -relative ACE_ROOT=/home/johnny/DOC_ROOT/stage-4253/ACE_wrappers -relative TAO_ROOT=/home/johnny/DOC_ROOT/stage-4253/ACE_wrappers/TAO
#
#----------------------------------------------------------------------------

MAKEFILE = GNUmakefile

ifeq ($(findstring k,$(MAKEFLAGS)),k)
  KEEP_GOING = -
endif

include $(ACE_ROOT)/include/makeinclude/macros.GNU

all: blobby http_client

depend: blobby-depend http_client-depend

REMAINING_TARGETS := $(filter-out all depend,$(TARGETS_NESTED:.nested=)) $(CUSTOM_TARGETS)

$(REMAINING_TARGETS):
	$(KEEP_GOING)@cd Blobby && $(MAKE) -f GNUmakefile.blobby $(@)
	$(KEEP_GOING)@cd Caching && $(MAKE) -f GNUmakefile.http_client $(@)

.PHONY: blobby
blobby:
	$(KEEP_GOING)@cd Blobby && $(MAKE) -f GNUmakefile.blobby all

.PHONY: blobby-depend
blobby-depend:
	$(KEEP_GOING)@cd Blobby && $(MAKE) -f GNUmakefile.blobby depend

.PHONY: http_client
http_client:
	$(KEEP_GOING)@cd Caching && $(MAKE) -f GNUmakefile.http_client all

.PHONY: http_client-depend
http_client-depend:
	$(KEEP_GOING)@cd Caching && $(MAKE) -f GNUmakefile.http_client depend

project_name_list:
	@echo blobby
	@echo http_client
