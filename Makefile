calculate:calculate.o helper.o cal.o
	gcc -o calculate calculate.o helper.o cal.o
calculate.o:calculate.c calculate.h
	gcc -c calculate.c
helper.o:helper.c helper.h
	gcc -c helper.c
cal.o:cal.c my.h
	gcc -c cal.c
clean:
	rm calculate.o helper.o cal.o

