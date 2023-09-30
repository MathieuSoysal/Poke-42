# Thanks to Job Vranish (https://spin.atomicobject.com/2016/08/26/makefile-c-projects/)
TARGET_NAME := Poke42

BUILD_DIR := ./build
SRC_DIRS := ./src
TARGET = $(BUILD_DIR)/$(TARGET_NAME)

SRCS := $(shell find $(SRC_DIRS) -name '*.c')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))
HEADERS = $(shell find $(SRC_DIRS) -name '*.h')

CC = clang
CFLAGS := -Wall -Wextra -pedantic 
CFLAGS += -g3
CFLAGS += $(INC_FLAGS)
CFLAGS += -MMD -MP 

all: run

.PHONY: build
build: $(TARGET)

.PHONY: run
run: $(TARGET)
	@echo "\nrunning $^ !\n"
	@./$^

.PHONY: re
re: clean update

# Linking
$(TARGET): $(OBJS)
	@echo "Linking"
	@$(CC) $^ -o $@ $(LDFLAGS) $(LDLIBS)

# Compile C
$(BUILD_DIR)/%.c.o: %.c
	@echo "Compiling $<"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean: test_clean
	@echo "Clean up"
	@$(RM) -r $(BUILD_DIR)

.PHONY: format
format:

.PHONY: update
update:
	make clean
	mkdir -p $(BUILD_DIR)
	bear --output $(BUILD_DIR)/compile_commands.json -- make build

# aliases
.PHONY: b r f c u
b: build
r: run
f: format
c: clean
u: update

-include $(DEPS)

###############################################################################

TEST_EXEC_NAME = tests.out

TEST_BUILD_DIR = ./test/build
TEST_SRC_DIR = ./test/src

TEST_TARGET = $(TEST_BUILD_DIR)/$(TEST_EXEC_NAME)

TEST_SRC  = $(shell find $(SRC_DIRS) -name '*.c' -or -name '*.cpp' | grep -v 'main')
TEST_SRC += $(shell find $(TEST_SRC_DIR) -name '*.c' -or -name '*.cpp')

TEST_OBJECTS  := $(TEST_SRC:%=$(TEST_BUILD_DIR)/%.o)

TEST_INC_DIRS := $(shell find $(TEST_SRC_DIR) -type d)
TEST_INC_FLAGS := $(addprefix -I,$(TEST_INC_DIRS))

CXX = clang++
CXXFLAGS  = $(CFLAGS) 
CXXFLAGS += -std=c++17
CXXFLAGS += $(TEST_INC_FLAGS)

GTESTFLAGS = --gtest_color=yes --gtest_print_time=0
GTESTFLAGS += --gtest_break_on_failure

LDLIBS   = -lgtest -lgtest_main -lpthread

.PHONY: test
test: clean $(TEST_TARGET)
	./$(TEST_TARGET) $(GTEST_FLAGS)

$(TEST_TARGET): $(TEST_OBJECTS)
	@echo Linking test binary
	@$(CXX) $^ -o $@ $(LDFLAGS) $(LDLIBS)

# compile C
$(TEST_BUILD_DIR)/%.c.o: %.c
	@echo "Compiling $<"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# compile C++
$(TEST_BUILD_DIR)/%.cpp.o: %.cpp
	@echo Compiling $<
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: test_clean
test_clean:
	rm -rf $(TEST_BUILD_DIR)

.PHONY: format_tests
format_tests:
	clang-format -i $(TEST_SRC)
