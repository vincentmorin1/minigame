CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := bin/runner

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
LIB := -L lib -L /usr/local/Cellar -L /usr/local/lib
INC := -I include -I /usr/local/include

CFLAGS := -g -Wall
# Linux (default)
LDFLAGS = -lSDL2 -lGL -lGLU
# Windows (cygwin)
ifeq ($(OS), "Windows_NT")
	LDFLAGS = -lSDL2 -lopengl32 -lglu32
endif
# OS X
ifeq ($(OSTYPE), "darwin9.0")
	LDFLAGS = -lSDL2 -framework Carbon -framework OpenGL
endif

$(TARGET): $(OBJECTS)
	@echo "Linking..."
	@echo " $(CC) $^ $(LDFLAGS) -o $(TARGET) $(LIB)"; $(CC) $^ $(LDFLAGS) -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo "Building..."
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo "Cleaning..."
	@echo "$(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

test:
	$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

run:
	$(TARGET)