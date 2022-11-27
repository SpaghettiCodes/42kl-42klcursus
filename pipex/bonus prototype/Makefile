all: compile

compile:
	gcc *.c -o ./pipex

address_sans:
	gcc *.c -fsanitize=address -o ./pipex	

run:
	./pipex $(ARGS)