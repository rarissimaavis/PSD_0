main.exe: main.o item.o stack.o
	gcc main.o item.o stack.o -o main.exe -lm
	
item.o: item.c
	gcc -c item.c

stack.o: stack.c
	gcc -c stack.c

main.o: main.c item.o stack.o
	gcc -c main.c item.o stack.o
	 
clean:
	rm *o