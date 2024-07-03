CC = clang

# Define the libraries and frameworks
LIBS = libraylib.a
FRAMEWORKS = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL

# Pattern rule to build an executable from a .c file
%: %.c
	$(CC) $(FRAMEWORKS) $(LIBS) $< -o $@

# Clean target to remove all executables
clean:
	rm -f $(wildcard *.c) $(wildcard *.o)

# Phony targets
.PHONY: clean

