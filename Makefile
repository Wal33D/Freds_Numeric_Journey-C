# Compiler settings
CC = gcc
CFLAGS =
# Include flags, here used to suppress warnings
INCFLAGS = -w
# Linker flags
LDFLAGS =
# Libraries
LIBS = -lpthread

# Output directory for binaries
BIN_DIR = ./bin

# Source and object files
# Add userInputHelpers.c to the SOURCES and adjust paths to src directory
SOURCES = src/fredJourney.c src/userInputHelpers.c
OBJECTS = $(SOURCES:.c=.o)
OBJECTS_WITH_PATH = $(addprefix $(BIN_DIR)/,$(notdir $(OBJECTS)))

# Target rules
all: $(BIN_DIR) fredJourney startScript

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

fredJourney: $(OBJECTS_WITH_PATH)
	$(CC) -o $(BIN_DIR)/$@ $^ $(LDFLAGS) $(LIBS)

# Pattern rule for object file compilation, adjusted for src directory
$(BIN_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

# Rule to create a start script
startScript:
	echo "#!/bin/sh" > startFredJourney.sh
	echo "exec $(BIN_DIR)/fredJourney \"\$$@\"" >> startFredJourney.sh
	chmod +x startFredJourney.sh

# Utility rule for counting lines of code, adjusted for src directory
count:
	wc -l src/*.c src/*.h

# Clean the build directory
clean:
	rm -f $(BIN_DIR)/*.o
	rm -f $(BIN_DIR)/fredJourney
	rm -f startFredJourney.sh
