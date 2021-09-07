# Technical prelude
SHELL := bash
.ONESHELL:
.SHELLFLAGS := -eu -o pipefail -c
.DELETE_ON_ERROR:
MAKEFLAGS += --warn-undefined-variables
MAKEFLAGS += --no-builtin-rules

cprintf: main.c
	gcc -g -Wall -Wextra -o $@ $<

.PHONY: run
run: cprintf
	./cprintf
