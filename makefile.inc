help:
	@echo "make build:	build static pages in public/ directory"
	@echo "make aliyun:	build static pages and make new commit in aliyun"
	@echo "make undo:	drop last commit of aliyun branch"

build-release:
	-rm -rf public-release/
	hugo -d public-release $(HUGO_OPTS)

aliyun: build-release
	@if ! git rev-parse refs/heads/pages/aliyun >/dev/null 2>&1 ; then \
		echo "Branch pages/aliyun not exists, forgot check it out?" >&2; \
		exit 1; \
	fi
	@git add public-release && \
	tree=$$(git write-tree) && \
	newtree=$$(git ls-tree $$tree | grep "public-release$$" | awk '{print $$3;}') && \
	oldtree=$$(git rev-parse refs/heads/pages/aliyun^{tree}) && \
	if [ "$$oldtree" = "$$newtree" ]; then \
	  echo "HTML is uptodate, branch pages/aliyun not changed." ; \
	else \
	  commit=$$(git log --format=%B -1 | git commit-tree $$newtree -p refs/heads/pages/aliyun) && \
	  git update-ref -m "HTML compiled from $$(git rev-parse HEAD)" refs/heads/pages/aliyun $$commit && \
	  echo "Branch pages/aliyun changed." ; \
	fi && \
	git rm --cached -r -q public-release && \
	rm -rf public-release

undo:
	@if ! git rev-parse refs/heads/pages/aliyun^ >/dev/null 2>&1 ; then \
		echo "Branch pages/aliyun not exists or only one commit, forgot check it out?" >&2; \
		exit 1; \
	fi
	if git update-ref -m "rollback to commit $$(git rev-parse refs/heads/pages/aliyun)" refs/heads/pages/aliyun $$(git rev-parse refs/heads/pages/aliyun^); then \
		echo "pages/aliyun branch rollback to last commit."; \
	fi

.PHONY: help aliyun undo
