CC=g++-10.1
CFLAGS=-Wall -O3 -I $(INC_PARAMS)
TARGET=app.out
INCLUDE_PATH=Data_Memory\
	Instruction_Memory\
	Register\
	ALU
INC_PARAMS=$(foreach d, $(INCLUDE_PATH), -I$d)
OBJS=Data_Memory/DMem.o \
	Insturction_Memory/test.o \
	Insturction_Memory/Instruction_Memory.o \
	Register/Register.o \
	Register/RMem.o \
	mpipe_src/MainExecuter.o \
	ALU/ALU.o \
	
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	find . -name "*.o" -exec rm -f {} \;
	find . -name "*.out" -exec rm -f {} \;