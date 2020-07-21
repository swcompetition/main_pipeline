CC=g++-10
INC_PARAMS=$(foreach d, $(INCLUDE_PATH), -I$d)
CFLAGS=-Wall -O3 $(INC_PARAMS)
TARGET=app.out
INCLUDE_PATH=Data_Memory\
	Instruction_Memory\
	Register\
	ALU\
	mpipe_src\
	Control\
	ALU_control\

OBJS=Control/Control.o \
	Data_Memory/DMem.o \
	Instruction_Memory/Instruction_Memory.o \
	Register/Register.o \
	Register/RMem.o \
	mpipe_src/MainExecuter.o \
	ALU/ALU.o \
	ALU_control/ALU_control.cpp\
	main.o\
	
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	find . -name "*.o" -exec rm -f {} \;
	find . -name "*.out" -exec rm -f {} \;