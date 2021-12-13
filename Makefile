#Executable names:
EXE = treemaker
TEST = test

#Add all object files needed for compiling:

EXE_OBJ = main.o
OBJS = TreeMkr.o catch.o catchmain.o
OBJS_TEST = catch.o TreeMkr.o TestCases.o cs225/catch/catchmain.o
#Use the cs225 makefile template:

include cs225/make/cs225.mk
CPP_FILES+= $(wildcard main/.cpp)
CPP_FILES+= $(wildcard TreeMkr/.cpp)
CPP_TEST+= $(wildcard TestCases/.cpp)
#CPP_TEST+= $(wildcard cs225/catch/catchmain/.cpp)
#.cpp)

