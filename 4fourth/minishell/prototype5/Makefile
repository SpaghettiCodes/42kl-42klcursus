TEST = ./test

all: compile

compile: 
	 gcc *.c -o $(TEST) -lreadline

a_san:
	gcc *.c -o hell -fsanitize=address -lreadline

clean:
	rm ./test

re: clean all