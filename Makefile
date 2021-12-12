#Executable names:
EXE = main

#Add all object files needed for compiling:

EXE_OBJ = main.o
OBJS = TreeMkr.o

#Use the cs225 makefile template:

include cs225/make/cs225.mk
CPP_FILES+= $(wildcard TreeMkr/.cpp)
CPP_FILES+= $()
