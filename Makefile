CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := bin/runner

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -Wall
LDFLAGS := -lSDL -lGL -lGLU
LIB := -L lib -L /opt/local/lib
INC := -I include -I /opt/local/include

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
	$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

run:
	$(TARGET)