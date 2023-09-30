EXEC = tests.out

CC  = clang
CXX = clang++

TEST_BUILD_DIR = ./build
TEST_SRC_DIR   = ./src

SRCS  := $(shell find $(TEST_SRC_DIR) -name '*.c' -or -name '*.cpp')
SRCS_H = $(SRCS) $(shell find $(TEST_SRC_DIR) -name '*.h')
OBJS  := $(SRCS:%=$(TEST_BUILD_DIR)/%.o)

LDLIBS   = -lgtest -lgtest_main -lpthread
LDLIBS  += -lft
LDFLAGS += -L..

CFLAGS  = -Wall -Wextra -Werror
CFLAGS += -pedantic
CFLAGS += -g3
CFLAGS += -I..

CXXFLAGS  = $(CFLAGS) 
CXXFLAGS += -std=c++17

GTESTFLAGS = --gtest_color=yes --gtest_print_time=0
GTESTFLAGS += --gtest_break_on_failure

.PHONY: test
test: fullclean $(TEST_BUILD_DIR)/$(EXEC)
	@echo
	@python3 -c 'print("-" * 80)'
	@echo TEST OUTPUT
	@python3 -c 'print("-" * 80)'
	@echo
	@$(TEST_BUILD_DIR)/$(EXEC) $(GTESTFLAGS)

# Linking
$(TEST_BUILD_DIR)/$(EXEC): $(OBJS)
	@make -s -C ..
	@echo Linking test binary
	@$(CXX) $^ -o $@ $(LDFLAGS) $(LDLIBS)

# Compile C 
$(TEST_BUILD_DIR)/%.c.o: %.c
	@echo Compiling $<
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Compile CXX
$(TEST_BUILD_DIR)/%.cpp.o: %.cpp
	@echo Compiling $<
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@echo Cleaning up test
	@$(RM) -r $(TEST_BUILD_DIR)

.PHONY: fullclean
fullclean: clean
	make -C .. clean

.PHONY: fmt
fmt:
	@echo Formatting tests
	@clang-format -i $(SRCS)
