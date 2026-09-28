CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# Picks up every .cpp file in the directory.
# New classes added by teammates won't need the Makefile edited.
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
TARGET = campusguard

.PHONY: all clean run files docs

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

files:
	@echo "Sources:"
	@echo $(SRCS)

docs:
	doxygen Doxyfile