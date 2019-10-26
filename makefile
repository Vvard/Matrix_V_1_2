export EXE := Matrix

###############################################

export CC := g++
export SOURCE_FILES := $(wildcard *.cpp)
export OBJ_FILES := $(patsubst %.cpp, %.o, $(SOURCE_FILES))
export DEP_FILES := $(patsubst %.cpp, %.dep, $(SOURCE_FILES))

###############################################

$(EXE) : $(SOURCE_FILES)
	$(CC) $^ -o $@ 

%.o : 

