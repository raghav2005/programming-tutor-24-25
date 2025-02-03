# Compiler
JAVAC = javac
JAVA = java

# Directories
SRC_DIR = .
BIN_DIR = bin

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.java) $(wildcard $(SRC_DIR)/animals/*.java)

# Default target: Compile the program
all: compile

# Compile Java files and store them in bin/ directory
compile:
	@mkdir -p $(BIN_DIR)
	$(JAVAC) -d $(BIN_DIR) $(SOURCES)

# Run the program
run: compile
	$(JAVA) -cp $(BIN_DIR) InterfaceExample

# Clean compiled files
clean:
	rm -rf $(BIN_DIR)
