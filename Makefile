CC=gcc
CC_FLAGS=-Wall -Wextra -Werror -std=c99 -g

CC_FLAGS_TEST=-pthread -lcheck_pic -pthread -lrt -lm -lsubunit

SRC_DIR=src
HDR_DIR=includes
OBJ_DIR=obj
TST_DIR=tests
TBN_DIR=tests/bin

SRC_FILES=$(wildcard $(SRC_DIR)/*.c)
OBJ_FILES=$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

TST_FILES=$(wildcard $(TST_DIR)/*_test.c)
TBN_FILES=$(patsubst $(TST_DIR)/%_test.c, $(TBN_DIR)/%, $(TST_FILES))

all: $(OBJ_DIR) $(TBN_DIR) $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@printf "[Creating $@]\n"
	@$(CC) $(CC_FLAGS) -I$(HDR_DIR)/ -c $^ -o $@

check: $(TBN_FILES)
	@for test in $(TBN_FILES); do printf "[Running $$test]"; ./$$test; done

$(TBN_DIR)/%: $(TST_DIR)/%_test.c
	@printf "[Creating $@ test]\n"
	@$(CC) $< $(OBJ_FILES) -o $@ $(CC_FLAGS_TEST) -I$(HDR_DIR)/

$(TBN_DIR):
	@printf "[Creating $@]\n"
	@mkdir $@

$(OBJ_DIR):
	@printf "[Creating $@]\n"
	@mkdir $@

clean:
	@printf "[Cleaning the project]\n"
	@rm -rf $(BIN_FILE) $(OBJ_DIR) $(TBN_DIR)

.PHONY: clean test all
