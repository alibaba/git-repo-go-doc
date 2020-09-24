help:
	@echo "make build:    build static pages in public/ directory"
	@echo "make aliyun: build static pages and make new commit in aliyun"
	@echo "make undo:     drop last commit of aliyun branch"

build-release:
	-rm -rf public-release/
	hugo -d public-release $(HUGO_OPTS)

aliyun: build-release
	@if ! git rev-parse refs/heads/aliyun >/dev/null 2>&1 ; then \
		echo "Branch aliyun not exists, forgot check it out?" >&2; \
		exit 1; \
	fi
	@git add public-release && \
	tree=$$(git write-tree) && \
	newtree=$$(git ls-tree $$tree | grep "public-release$$" | awk '{print $$3;}') && \
	oldtree=$$(git rev-parse refs/heads/aliyun^{tree}) && \
	if [ "$$oldtree" = "$$newtree" ]; then \
	  echo "HTML is uptodate, branch aliyun not changed." ; \
	else \
	  commit=$$(git log --format=%B -1 | git commit-tree $$newtree -p refs/heads/aliyun) && \
	  git update-ref -m "HTML compiled from $$(git rev-parse HEAD)" refs/heads/aliyun $$commit && \
	  echo "Branch aliyun changed." ; \
	fi && \
	git rm --cached -r -q public-release && \
	rm -rf public-release

undo:
	@if ! git rev-parse refs/heads/aliyun^ >/dev/null 2>&1 ; then \
		echo "Branch aliyun not exists or only one commit, forgot check it out?" >&2; \
		exit 1; \
	fi
	if git update-ref -m "rollback to commit $$(git rev-parse refs/heads/aliyun)" refs/heads/aliyun $$(git rev-parse refs/heads/aliyun^); then \
		echo "aliyun branch rollback to last commit."; \
	fi

.PHONY: help aliyun undo
