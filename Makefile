
TARGET = ./demogenfq
DU = ../util/
SRC = $(TARGET).c  $(DU)genfq.c $(DU)genctrl.c $(DU)message.c 
INC = ../util/ 
LIB = `pkg-config --libs --cflags gtk+-2.0 `
all:
#	gcc -o $(TARGET) $(SRC)  -I $(INC) $(LIB)
#	gcc -g -o $(TARGET) $(SRC) -Wall -I $(INC) $(LIB)
	gcc -o $(TARGET) $(SRC) -Wall -I $(INC) $(LIB) -lm

	./$(TARGET)
#	gdb ./$(TARGET)

