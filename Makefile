CXX      := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -Iinclude
BUILD_DIR:= build
TARGET   := taskforge
ZIP_NAME := submission.zip
FLAT_DIR := flat_src
ZIP_RESOURCES := Dockerfile Makefile README.md docs # other files/directories to include in zip

# find main.cpp and all src/ cpp files
SRCS     := $(shell find src -type f -name '*.cpp')

# Map main.cpp -> build/main.o and src/path/file.cpp -> build/src/path/file.o
OBJS     := $(patsubst src/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

all: $(TARGET)
	./$(TARGET)

# link object files into final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# compile each .cpp into a .o file inside build/
$(BUILD_DIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# flatten source tree and generate zip
zip:
	@rm -rf $(FLAT_DIR) $(ZIP_NAME)
	@mkdir -p $(FLAT_DIR)
	@cp Makefile $(FLAT_DIR)/
	@# Copy files or flatten directory contents listed in ZIP_RESOURCES
	@for item in $(ZIP_RESOURCES); do \
		if [ -d "$$item" ]; then \
			cp -r "$$item"/* $(FLAT_DIR)/ 2>/dev/null || true; \
		elif [ -f "$$item" ]; then \
			cp "$$item" $(FLAT_DIR)/; \
		fi; \
	done
	@# Copy C++ sources/headers, excluding build and temp dirs
	@find . -type f \( -name '*.cpp' -o -name '*.h' -o -name '*.hpp' \) ! -path "./$(BUILD_DIR)/*" ! -path "./$(FLAT_DIR)/*" -exec cp {} $(FLAT_DIR)/ \;
	@if [ -d resources ]; then cp -r resources/* $(FLAT_DIR)/ 2>/dev/null || true; fi
	@# Patch include directives
	@for f in $(FLAT_DIR)/*; do \
		[ -f "$$f" ] && sed -i -E 's/#include "([^"]*\/)?([^"\/]+)"/#include "\2"/g' "$$f"; \
	done
	cd $(FLAT_DIR) && zip -j ../$(ZIP_NAME) *
	@rm -rf $(FLAT_DIR)

docker:
	sudo docker build -t taskforge .

# Clean build output
clean:
	rm -rf $(BUILD_DIR) $(TARGET) *.o $(ZIP_NAME) $(FLAT_DIR)

.PHONY: all clean docker zip