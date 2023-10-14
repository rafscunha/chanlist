
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
SRC_DIR = .
LIST_DIR = List
NODE_DIR = Node
BUILD_DIR = build
STUDENT_DIR= Student
TARGET = program
SRCS = $(wildcard $(SRC_DIR)/*.cpp $(STUDENT_DIR)/*.cpp)
OBJS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(SRCS)))

# Lista de arquivos .hpp
HEADERS = $(wildcard $(LIST_DIR)/*.hpp $(NODE_DIR)/*.hpp $(STUDENT_DIR)/*.hpp)

# Regras
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o:  $(NODE_DIR)/%.hpp $(HEADERS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o:  $(LIST_DIR)/%.hpp $(HEADERS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(STUDENT_DIR)/%.cpp $(STUDENT_DIR)/%.hpp $(HEADERS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean