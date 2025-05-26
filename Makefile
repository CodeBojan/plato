# makefile template from https://www.lucavall.in/blog/crafting-clean-maintainable-understandable-makefile-for-c-project
# Project Settings
debug ?= 0
NAME := plato
SRC_DIR := source
BUILD_DIR := build
INCLUDE_DIR := include
LIB_DIR := lib
TESTS_DIR := tests
BIN_DIR := bin

CC := gcc
CFLAGS := -g3 -Wall -Wextra -Wconversion -Wdouble-promotion -Wno-unused-parameter -Wno-unused-function -Wno-sign-conversion -fsanitize=undefined,null,address

OBJS := $(patsubst %.c, %.o, $(wildcard $(SRC_DIR)/**/*.c))

#Targets

$(NAME) : client server

#$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $(patsubst %, build/%, $(OBJS))
client: $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $(BUILD_DIR)/$(dir $<)/client.o
# This makefile setup is only for this mockup client/server test model, and it is bound to change.
# It might not be the best, but it does it's job. A better structure would be to have a different directory in the source for client/server
server: $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $(BUILD_DIR)/$(dir $<)/server.o

$(OBJS): dir
	@mkdir -p $(BUILD_DIR)/$(@D)
	@$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ -c $*.c

dir:
	@mkdir -p $(BUILD_DIR) $(BIN_DIR)

clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR)
