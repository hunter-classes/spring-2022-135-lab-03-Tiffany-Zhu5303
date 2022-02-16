OBJECTS= main.o reservoir.o

main: main.o reservoir.o
	g++ -o main $(OBJECTS)

main.o: main.cpp reservoir.h
	g++ -c main.cpp 

reservoir.o: reservoir.cpp reservoir.h
	g++ -c reservoir.cpp
clean:
	rm -f $(OBJECTS)
help:
	@echo "Targets:"
	@echo "  main"
	@echo "  clean"
	@echo "  help"
