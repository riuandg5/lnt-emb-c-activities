# Variable to store name of final executable
PROJECT_NAME := main

# Variable to store name of the project doxyfile
PROJECT_DOXYFILE := Doxyfile
# Variable to store name of documentation folder
DOCS_DIR := docs

# Variable to store name of src folder
SRC_DIR := src
# Variable to store names of include folders
INC_DIRS := inc
# Variable to store name of build folder
BUILD_DIR := build

# Variable to store path of all sources
SRCS := main.c $(shell find $(SRC_DIR) -name '*.c')
# Variable to store path of all object files mapped from path of all sources
OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)
# Variable to store path of all dependency files mapped from path of all objects
DEPS := $(OBJS:.o=.d)

# Variable to store name of default compiler
CC := avr-gcc
# Variable to store name of default object translator
OBJCOPY := avr-objcopy
# Variable to store name of MCU
MCU := atmega328
# Variable to store include flags by prefixing -I to include folders
INC_FLAGS := $(addprefix -I,$(INC_DIRS))
# Vriable to store C preprocessor settings
CPPFLAGS := -mmcu=$(MCU) $(INC_FLAGS) -MMD -MP
# Variable to store warning flags
WARNINGS := -Wall -Wpedantic -Wextra
# Variable to store linker flags
LDFLAGS :=

# Variable to store extension and format of final flashable executable
EXEC := hex
FORMAT := ihex
# Variable to store full name of final flashable executable
PROJECT_OUTPUT := $(BUILD_DIR)/$(PROJECT_NAME).$(EXEC)

# Variable to store extension of final executable
EL := elf
# Variable to store full name of final executable
EL_OUTPUT := $(BUILD_DIR)/$(PROJECT_NAME).$(EL)

.PHONY: build
# Default make target
build: $(PROJECT_OUTPUT)

# Translate final linked executable to flashable executable
$(PROJECT_OUTPUT): $(EL_OUTPUT)
	$(OBJCOPY) -O $(FORMAT) $< $@

# Link object files to get final linked executable
$(EL_OUTPUT): $(OBJS)
	$(CC) $(CPPFLAGS) $(WARNINGS) $^ -o $@ $(LDFLAGS)

# Compile C source files to get assembeled object files
$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(WARNINGS) -c $< -o $@

# Include dependencies generated from every c source file
-include $(DEPS)

.PHONY: analysis
# Do static analysis of code using Cppcheck command line utility
analysis: $(SRCS)
	cppcheck --enable=all --suppress=missingInclude $^

.PHONY: documentation
# Build documentation using Doxygen command line utility
documentation: $(PROJECT_DOXYFILE)
	doxygen $^

.PHONY: clean
# Clean all build files
clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(DOCS_DIR)