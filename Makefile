SRCDIR=src/
BINDIR=bin/
BUILDDIR=build/

CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -std=c89
LDFLAGS=-lm

# Sources and headers
SOURCES=$(wildcard $(SRCDIR)*.c)
HEADERS=$(wildcard $(SRCDIR)*.h) not needed at the moment

# Object files
OBJECTS=$(patsubst $(SRCDIR)%.c,$(BINDIR)%.o,$(SOURCES))

# Executable name
EXECUTABLE=recursive

# Default target
all: $(EXECUTABLE)

# Build the executable
$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -o $(BUILDDIR)$@ $^ $(LDFLAGS)

# Compile source files to object files
$(BINDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
# This target removes the build directory and all object files

clean:
	rm -rf $(BUILDDIR) $(BINDIR)

.phony: all clean
