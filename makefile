.ONESHELL:
.PHONY: setup setup-prod build build-prod run run-build-if clean rebuild production help

BUILD_DIR := build
BIN_DIR := $(BUILD_DIR)\bin
JOBS ?= 4
EXECUTABLE_TEST := CPP_CONSOLE

ifeq ($(OS),Windows_NT)
	EXE := .exe
	SEP := \\
	CLEAN := cmd /c del /Q
	EXEC_PREFIX :=
else
	EXE :=
	SEP := /
	CLEAN := rm -rf
	EXEC_PREFIX := ./
endif

# Run once when first initializing project
setup:
	cmake -S . -B $(BUILD_DIR) -G Ninja \
	-DCMAKE_C_COMPILER=clang \
	-DCMAKE_CXX_COMPILER=clang++ \
	-DCMAKE_BUILD_TYPE=Debug

# Sets up program to be build for production
setup-prod:
	cmake -S . -B $(BUILD_DIR) -G Ninja -DCMAKE_BUILD_TYPE=Release

# Runs the CMake file
build:
	cmake --build $(BUILD_DIR) --config Debug -- -j$(JOBS)

# Runs the CMake file in production mode
build-prod:
	cmake --build $(BUILD_DIR) --config Release -- -j$(JOBS)

run-test: build
	@echo Running test executable...
	cd $(BIN_DIR) && "${EXEC_PREFIX}$(EXECUTABLE_TEST)$(EXE)" $(args)

# Cleans up the build directory
clean:
	$(CLEAN) $(BUILD_DIR)
	
rebuild: clean setup run-test
production: clean setup-prod build-prod

help:
	@echo "Available targets:"
	@echo "  setup       - Configure Debug build"
	@echo "  setup-prod  - Configure Release build"
	@echo "  build       - Build Debug build"
	@echo "  build-prod  - Build Release build"
	@echo "  run-test    - Run Debug test executable"
	@echo "  clean       - Remove build directory"
	@echo "  rebuild     - Clean, setup Debug, build and run"