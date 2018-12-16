CCOPTION = Wall std=gnu++11 D__USE_MINGW_ANSI_STDIO=1
FLAGS = $(addprefix -,$(CCOPTION))
CC = g++
OBJ = main.o 
SRC_DIR = /Users/nsbhasin/Desktop/Competitive Programming/CodeChef/RAINBOWA

output.out: $(OBJ) 
	 $(CC) $(FLAGS) $(OBJ) -o output.out 

main.o: $(SRC_DIR)\main.cpp 
	 $(CC) $(FLAGS) -c $(SRC_DIR)\main.cpp -o main.o 


clean: 
	rm $(OBJ_DIR)/*.o
	rm $(BUILD_DIR)/*.out
