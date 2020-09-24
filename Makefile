# Makefile for build git-repo documentation
#

# You can set these variables from the command line.
HUGO_OPTS     =

-include makefile.inc

build:
	-rm -rf public/
	hugo $(HUGO_OPTS)
	cp CNAME public/

.PHONY: build
