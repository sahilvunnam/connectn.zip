connectn.out: main.o play.o setup.o
	gcc -g -Wall -Werror main.o play.o setup.o -o connectn.out

main.o: main.c play.h setup.h
	gcc -g -Wall -Werror -c main.c 

play.o: play.c play.h
	gcc -g -Wall -Werror -c play.c

setup.o: setup.c setup.h
	gcc -g -Wall -Werror -c setup.c

clean:
	rm -rf *.o *.out