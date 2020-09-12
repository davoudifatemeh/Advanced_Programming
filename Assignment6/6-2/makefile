CC = g++ -std=c++11

all: 2.out

2.out: main.o file_system_interface.o file_system_methods.o directory.o link.o file.o 
	${CC} main.o file_system_interface.o file_system_methods.o directory.o link.o file.o -o 2.out

main.o: main.cpp file_system_interface.h
	${CC} -c main.cpp

file_system_interface.o: file_system_interface.cpp file_system_interface.h file_system_methods.h
	${CC} -c file_system_interface.cpp

file_system_methods.o: file_system_methods.cpp file_system_methods.h parent.h file.h directory.h link.h bad_linked_element.h bad_parent_id.h bad_title.h id_already_exists.h bad_element_id.h
	${CC} -c file_system_methods.cpp

file.o: file.cpp file.h parent.h
	${CC} -c file.cpp

directory.o: directory.cpp directory.h parent.h
	${CC} -c directory.cpp

link.o:link.cpp link.h parent.h
	${CC} -c link.cpp

.PHONY: clean
clean:
	rm *.o
	rm a.out