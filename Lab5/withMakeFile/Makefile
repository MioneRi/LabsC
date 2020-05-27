all: build run clean
NAME_PART = main
PATH_LIB = C:/Users/PC/Desktop/LabsC/SomeLibs

build:
	cd $(CURDIR)
	gcc -std=c11 -c $(PATH_LIB)/StrokiLiba.c -o StrokiLiba.o
	ar rcs libStrokiLiba.a StrokiLiba.o
	gcc -std=c11 -I $(PATH_LIB) -c "$(NAME_PART).c" -o "$(NAME_PART).o"
	gcc -std=c11 "$(NAME_PART).o" -L . -l StrokiLiba -o "$(NAME_PART).exe"

run:
	./$(NAME_PART)

clean:
	del *.exe
	del *.o
	del *.a