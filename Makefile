CXX = gcc
CXXFLAGS = -Wall -Iinclude -lraylib 
SRCDIR = src
OBJDIR = build
TARGET = GameOfLife 

SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) $(CXXFLAGS) -g -o $@ 

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CXX) -c $< $(CXXFLAGS) -g -o $@ 

$(OBJDIR):
	mkdir -p $(OBJDIR)
clean:
	rm -rf $(OBJDIR) $(TARGET)

#pixelDraw: main.cpp
#	g++ main.cpp -o main.o -Wall -Wextra -lraylib
