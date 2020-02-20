# Makefile for Sphinx documentation
#

# You can set these variables from the command line.
SPHINXOPTS    =
SPHINXBUILD   = sphinx-build
PAPER         =
BUILDDIR      = _build

# Internal variables.
PAPEROPT_a4     = -D latex_paper_size=a4
PAPEROPT_letter = -D latex_paper_size=letter
ALLSPHINXOPTS   = -d $(BUILDDIR)/doctrees $(PAPEROPT_$(PAPER)) $(SPHINXOPTS) .

.PHONY: help clean html dirhtml singlehtml pickle json htmlhelp qthelp devhelp epub latex latexpdf text man changes linkcheck doctest

help:
	@echo "make gh-pages: build static pages and make new commit in gh-pages"
	@echo "make undo:     drop last commit of gh-pages branch"

build:
	-rm -rf public/
	hugo
	cp CNAME public/

gh-pages: build
	@if ! git rev-parse refs/heads/gh-pages >/dev/null 2>&1 ; then \
		echo "Branch gh-pages not exists, forgot check it out?" >&2; \
		exit 1; \
	fi
	@git add -f public; \
	tree=$$(git write-tree); \
	newtree=$$(git ls-tree $$tree | grep "public$$" | awk '{print $$3;}') ; \
	oldtree=$$(git rev-parse refs/heads/gh-pages^{tree}); \
	if [ "$$oldtree" = "$$newtree" ]; then \
	  echo "HTML is uptodate, branch gh-pages not changed." ; \
	else \
	  commit=$$(git log --format=%B -1 | git commit-tree $$newtree -p refs/heads/gh-pages) ; \
	  git update-ref -m "HTML compiled from $$(git rev-parse HEAD)" refs/heads/gh-pages $$commit ; \
	  echo "Branch gh-pages changed." ; \
	  [ -x .git/hooks/post-commit ] && .git/hooks/post-commit; \
	fi; \
	git rm --cached -r -q public

undo:
	@if ! git rev-parse refs/heads/gh-pages^ >/dev/null 2>&1 ; then \
		echo "Branch gh-pages not exists or only one commit, forgot check it out?" >&2; \
		exit 1; \
	fi
	if git update-ref -m "shift from $$(git rev-parse refs/heads/gh-pages)" refs/heads/gh-pages $$(git rev-parse refs/heads/gh-pages^); then \
		echo "gh-pages branch shift to last commit."; \
	fi

.PHONY: build gh-pages undo
