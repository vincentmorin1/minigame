CC := g++
BUILDDIR := build
BUILDTESTDIR := test

SRCDIR := src/main
TARGET := bin/runner

TESTDIR := src/test
TESTTARGET := bin/tester

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

TESTSOURCES := $(shell find $(TESTDIR) -type f -name *.$(SRCEXT))
TESTOBJECTS := $(patsubst $(TESTDIR)/%,$(BUILDTESTDIR)/%,$(TESTSOURCES:.$(SRCEXT)=.o))

LIB := -L lib -L /usr/local/Cellar -L /usr/local/lib
INC := -I include -I /usr/local/include -I /usr/include/c++/7

CFLAGS := -g -Wall -std=c++11
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
	@mkdir -p bin
	@echo "Linking..."
	@echo " $(CC) $^ $(LDFLAGS) -o $(TARGET) $(LIB)"; $(CC) $^ $(LDFLAGS) -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(BUILDTESTDIR)/%.o: $(TESTDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDTESTDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo "Cleaning..."
	@echo "$(RM) -r $(BUILDDIR)"; $(RM) -r $(BUILDDIR) 
	@echo "$(RM) -r bin"; $(RM) -r bin

test: $(TESTOBJECTS)
	@echo "Linking..."
	@echo " $(CC) $^ $(LDFLAGS) -o $(TESTTARGET) $(LIB)"; $(CC) $^ $(LDFLAGS) -o $(TESTTARGET) $(LIB)
	$(TESTTARGET)

run:
	$(TARGET)
