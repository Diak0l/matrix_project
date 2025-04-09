CC := gcc
CFLAGS := -Wall -Wextra -pedantic -std=c99 -Iinclude -Isrc/matrix -Isrc/output
LDFLAGS := -L/usr/lib/x86_64-linux-gnu -lcunit -lm

SRC_DIR := src
INC_DIR := include
TEST_DIR := tests
BUILD_DIR := build

# Включите все .c файлы из подкаталогов, кроме main.c
SRCS := $(filter-out $(SRC_DIR)/main.c, $(wildcard $(SRC_DIR)/matrix/*.c) $(wildcard $(SRC_DIR)/output/*.c) $(wildcard $(SRC_DIR)/*.c))
INCS := $(wildcard $(INC_DIR)/*.h)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

# Включите все test .c файлы
TEST_SRCS := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS := $(patsubst $(TEST_DIR)/%.c,$(BUILD_DIR)/%.o,$(TEST_SRCS))

TARGET := app
TEST_TARGET := testst

.PHONY: all clean run_tests

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(OBJS) $(BUILD_DIR)/main.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(TEST_TARGET): $(OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(INCS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c $(INCS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET) $(TEST_TARGET)

run_tests: $(TEST_TARGET)
	./$(TEST_TARGET)
