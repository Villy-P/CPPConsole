.ONESHELL:

# Platform detection
ifeq ($(OS),Windows_NT)
    DETECTED_OS := Windows
    EXE_EXT := .exe
    RM_CMD := rmdir /s /q
    MKDIR_CMD := mkdir
else
    DETECTED_OS := Unix
    EXE_EXT := 
    RM_CMD := rm -rf
    MKDIR_CMD := mkdir -p
endif

# Default target
.PHONY: all build test clean reset run install

all: build

# Reset build directory
reset:
	$(RM_CMD) build
	$(MKDIR_CMD) build
	cd build && cmake -GNinja ..

# Build the project
build:
	@if [ ! -d "build" ]; then $(MAKE) reset; fi
	ninja -C build

# Build and run tests
test: build
	cd build && ctest --output-on-failure

# Run the test executable
run: build
ifeq ($(DETECTED_OS),Windows)
	.\build\bin\cppconsole_test$(EXE_EXT)
else
	./build/bin/cppconsole_test$(EXE_EXT)
endif

# Install to system (requires privileges)
install: build
	ninja -C build install

# Clean build artifacts
clean:
	$(RM_CMD) build

# Configure without tests
configure-lib-only:
	$(RM_CMD) build
	$(MKDIR_CMD) build
	cd build && cmake -GNinja -DCPPCONSOLE_BUILD_TESTS=OFF ..

# Help target
help:
	@echo "Available targets:"
	@echo "  all          - Build the project (default)"
	@echo "  build        - Build the project"
	@echo "  test         - Build and run tests"
	@echo "  run          - Build and run the test executable" 
	@echo "  reset        - Clean and reconfigure build directory"
	@echo "  install      - Install library to system"
	@echo "  clean        - Remove build directory"
	@echo "  configure-lib-only - Configure without building tests"
	@echo "  help         - Show this help message"