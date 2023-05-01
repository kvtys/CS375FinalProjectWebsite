# Specifiy the target
all: sorts
# Specify the object files that the target depends on
# Also specify the object files needed to create the executable

sorts: main.o sortJect.o sortSource.o 
	g++ main.o sortJect.o sortSource.o  -o sorts

# Specify how the object files should be created from source files
main.o: main.cpp
	g++ -c main.cpp
sortJect.o: sortJect.cpp
	g++ -c sortJect.cpp
sortSource.o: sortSource.cpp
	g++ -c sortSource.cpp
# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o *.gch sorts 