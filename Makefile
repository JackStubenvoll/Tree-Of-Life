#Executable names:
EXE = treemaker
TEST = test

#Add all object files needed for compiling:

EXE_OBJ = somethingdifferent.o
OBJS = main.o TreeMkr.o
OBJS_TEST = main.o TreeMkr.o catchmain.o
#Use the cs225 makefile template:

include cs225/make/cs225.mk
CPP_FILES+= $(wildcard main/.cpp)
CPP_FILES+= $(wildcard TreeMkr/.cpp)
CPP_TEST+= $(wildcard TestCases/.cpp))
#CPP_TEST+= $(wildcard catch/catch/.cpp)

