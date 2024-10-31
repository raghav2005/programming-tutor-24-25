# NOTE: generally, you don't need to do the stuff with the object files as gcc automatically handles this - i've included it here purely to show how you'd get them, just in case you wanted the .o files for whatever reason

# compiler
CC = gcc

# compiler flags (definitely have these 2 to make sure there are no warnings at all)
CFLAGS = -Wall -Wextra

# executable name
TARGET = c_learning

# source files
SRCS = c_learning.c add_func.c

# object files (replace .c with .o in SRCS) - not explicitly required, but better to have
OBJS = $(SRCS:.c=.o)

# default target to build the executable - run when running `make`
all: $(TARGET)

# rule to link object files and create the final executable
# the first $(OBJS) means that these must be created or updated before running $(TARGET) i.e. they're prerequisites
# in this case, $(OBJS) expands to c_learning.o add_func.o - the SRCS files with .o instead of .c as defined above
# the pattern rule below does the creation for these .o files
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# pattern rule to compile each source file (.c) into an object file (.o)
# $< is an automatic variable representing the first prerequisite (in this case, the .c file)
# $@ sets the output file to the target (in this case, the .o file)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

# run the program
run: $(TARGET)
	./$(TARGET)

# phony targets (targets that don’t represent files)
# prevents conflicts if files with these names already exist in the directory
.PHONY: all clean run
