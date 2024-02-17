# Specify the name of your project
PROJECT_NAME := lab1_cpp

# Specify the build directory
BUILD_DIR := build

# Default target
all: release

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clear the build directory
clear:
	rm -rf $(BUILD_DIR)
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

# Phony targets
.PHONY: all clear debug release
