recrevstack.exe: recrevstack.o item.o stack.o
	gcc recrevstack.o item.o stack.o -o recrevstack.exe -lm
	
item.o: item.c
	gcc -c item.c


stack.o: stack.c
	gcc -c stack.c

recrevstack.o: recrevstack.c item.o stack.o
	gcc -c recrevstack.c item.o stack.o
	 
clean:
	rm *o