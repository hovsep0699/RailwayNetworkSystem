ROOTDIR = $(shell git rev-parse --show-toplevel)
TOPDIR += $(ROOTDIR)/src
SRCDIR = $(CURDIR)/src
CONFDIR += $(ROOTDIR)/conf
INCDIR += $(SRCDIR)/include
THIRDTYDIR = $(ROOTDIR)/3pty
BUILDDIR += $(ROOTDIR)/build
OBJDIR += $(BUILDDIR)/obj
DEPSDIR += $(BUILDDIR)/deps

INCLUDE += -I $(ROOTDIR)/include