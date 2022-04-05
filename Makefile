connectn.out: main.o board.o gameplay.o winningconditions.o commandlines.o inputvalid.o
		gcc -g -Wall -Werror main.o board.o gameplay.o winningconditions.o commandlines.o inputvalid.o -o connectn.out

main.o: board.h main.c
		gcc -g -Wall -Werror -c main.c

board.o: board.h board.c
		gcc -g -Wall -Werror -c board.c

gameplay.o: gameplay.h gameplay.c board.h commandlines.h winningconditions.h inputvalid.h
		gcc -g -Wall -Werror -c gameplay.c

winningconditions.o: winningconditions.h winningconditions.c
		gcc -g -Wall -Werror -c winningconditions.c

commandlines.o: commandlines.c commandlines.h
		gcc -g -Wall -Werror -c commandlines.c

inputvalid.o: inputvalid.c inputvalid.h
		gcc -g -Wall -Werror -c inputvalid.c

clean:
		rm -f *.o *.out
