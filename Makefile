SRCDIR=src/
BINDIR=bin/
BUILDDIR=build/
DESTDIR?=/usr/local/

CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -std=c89
LDFLAGS=-lm
INSTALL=install

# Sources and headers
SOURCES=$(wildcard $(SRCDIR)*.c)
HEADERS=$(wildcard $(SRCDIR)*.h) not needed at the moment

# Object files
OBJECTS=$(patsubst $(SRCDIR)%.c,$(BINDIR)%.o,$(SOURCES))

# Executable name
EXECUTABLE=collatz

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

# installation part

install: $(EXECUTIBLE)
	@mkdir -p $(DESTDIR)
	$(INSTALL) -m 755 $(BUILDDIR)$(EXECUTABLE) $(DESTDIR)bin

.phony: all clean install
