#Makefile
all : add-nbo
	gcc add-nbo.c -o add-nbo

clean :
	rm -r add-nbo

