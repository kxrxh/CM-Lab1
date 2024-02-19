# Specify the name of your project
PROJECT_NAME := lab1_cpp

# Specify the build directory
BUILD_DIR := build

INPUT_FOLDER := ./inputs

# Default target
all: release

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clear the build directory
clear:
	rm -rf $(BUILD_DIR)
	rm -rf .cache
	rm -f $(PROJECT_NAME)

# Debug build
debug: $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake -DCMAKE_BUILD_TYPE=Debug ..
	cmake --build $(BUILD_DIR)

# Release build
release: $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake -DCMAKE_BUILD_TYPE=Release ..
	cmake --build $(BUILD_DIR) --config Release
	mv $(BUILD_DIR)/$(PROJECT_NAME) ./$(PROJECT_NAME)

run: release
	./$(PROJECT_NAME) -f $(INPUT_FOLDER)/input1.txt
	./$(PROJECT_NAME) -f $(INPUT_FOLDER)/input2.txt
	./$(PROJECT_NAME) -f $(INPUT_FOLDER)/input3.txt
	./$(PROJECT_NAME) -f $(INPUT_FOLDER)/input4.txt
	./$(PROJECT_NAME) -f $(INPUT_FOLDER)/input5.txt
	./$(PROJECT_NAME) -f $(INPUT_FOLDER)/input6.txt

# Phony targets
.PHONY: all clear debug release
