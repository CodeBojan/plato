SRCS=$(wildcard ./*.c)
OBJS=$(SRCS:.c=)
PROGS=$(SRCS:.c=)

#one exe file will cover only one file that is tested

SRC_DIR := ../src
INC_DIRS := -I../inc

CC := gcc
CFLAGS := 
SRC_FILE := $(SRC_DIR)/$(MODULE_NAME).c
TEST_FILE := test_$(MODULE_NAME).c
EXE_FILE := test_$(MODULE_NAME)
UNITY := ./unity/unity.c

all: $(PROGS) 

%: %.c	
	$(CC) $(CFLAGS) -o $@ $(INC_DIR) $<

single:
	$(CC) $(CFLAGS) $(INC_DIRS) $(TEST_FILE) $(SRC_FILE) $(UNITY) -o $(EXE_FILE)

clean:
	rm -f $(PROGS)

single_clean:
	rm -f $(EXE_FILE)


