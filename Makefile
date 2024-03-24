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
SOURCES = fredJourney.c
OBJECTS = $(SOURCES:.c=.o)
OBJECTS_WITH_PATH = $(addprefix $(BIN_DIR)/,$(OBJECTS))

# Target rules
all: $(BIN_DIR) fredJourney

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

fredJourney: $(OBJECTS_WITH_PATH)
	$(CC) -o $(BIN_DIR)/$@ $^ $(LDFLAGS) $(LIBS)

# Pattern rule for object file compilation
$(BIN_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

# Utility rule for counting lines of code
count:
	wc *.c *.cc *.C *.cpp *.h *.hpp

# Clean the build directory
clean:
	rm -f $(BIN_DIR)/*.o
	rm -f $(BIN_DIR)/fredJourney
