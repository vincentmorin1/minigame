CC := g++
SRCDIR := src/main
BUILDDIR := build
TARGET := bin/runner

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
LIB := -L lib -L /usr/local/Cellar -L /usr/local/lib
INC := -I include -I /usr/local/include -I /usr/include/c++/7

CFLAGS := -g -Wall
ifeq ($(OS), "Windows_NT")
		LDFLAGS := -lSDL2 -lopengl32 -lglu32
else
UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
			LDFLAGS := -lSDL2 -lGL -lGLU
	endif
	ifeq ($(UNAME_S),Darwin)
			LDFLAGS := -lSDL2 -framework Carbon -framework OpenGL
	endif
endif

$(TARGET): $(OBJECTS)
	@echo "Linking..."
	@echo " $(CC) $^ $(LDFLAGS) -o $(TARGET) $(LIB)"; $(CC) $^ $(LDFLAGS) -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo "Cleaning..."
	@echo "$(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

test:
	$(CC) $(CFLAGS) src/test/tester.cpp $(INC) $(LIB) -o bin/tester

run:
	$(TARGET)