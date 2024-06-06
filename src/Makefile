CC := g++
SOURCES := $(wildcard *.cpp)
BUILDDIR := .
SOURCEDIR := .
OBJECTS := $(SOURCES:.cpp=.o)
TARGET := test
CFLAGS := 

all : $(TARGET)

$(TARGET) : $(OBJECTS)

# $@ - имя цели, %< - файлы после : 
$(BUILDDIR)/%.o: $(SOURCEDIR)/%.cpp
	$(CC) -c $(CFLAGS) $< -o $@
clean : 
	rm -rf *.o
rebuild : clean all
