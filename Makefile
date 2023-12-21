G++ = g++
FILES = main.cpp doubleList.cpp
EXE = DoubleList
DEL = rm

all:
	$(G++) $(FILES) -o $(EXE)
del:
	$(DEL) -r $(EXE)