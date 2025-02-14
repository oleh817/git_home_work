OBJ_MAIN = main.o
OBJ1 = src1.o
OBJ2 = src2.o
OBJ3 = src3.o

MAKE1 = make1
MAKE2 = make2
MAKE3 = make3

ifeq ($(USE_MAKEFILE_INCLUDE), yes)
    include $(OBJ1)
    include $(OBJ1)
    include $(OBJ1)
else
    all: program

    make1.mk:
		make -f $(MAKE1)

    make2.mk:
		make -f $(MAKE2)

    make3.mk:
		make -f $(MAKE3)
endif

main.o: main.c
		gcc -c main.c -o main.o

program: $(OBJ_MAIN) $(OBJ1) $(OBJ2) $(OBJ3)
		gcc $(OBJ_MAIN) $(OBJ1) $(OBJ2) $(OBJ3) -o program

clean:
		rm -f $(OBJ_MAIN) $(OBJ1) $(OBJ2) $(OBJ3) program
