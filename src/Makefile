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
	rm -rf *.o *.gcno *.gcda *.out *.info $(TARGET)
	rm -rf cvg
	rm -rf results
lcov_report : clean
	g++ test.cpp --coverage
	./a.out
	mkdir cvg
	cd cvg
	lcov -c -d ../ -o my.info
	genhtml -o results/ my.info

rebuild : clean all
