all: compile

compile: 
	gcc *.c -lpthread -o ./test
	
san_com:
	gcc *.c -lpthread -fsanitize=thread -g3 -o ./test