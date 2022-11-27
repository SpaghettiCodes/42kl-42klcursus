all: compile

compile:
	gcc *.c -o ./pipex

addr_san:
	gcc *.c -fsanitize=address -o ./pipex

run:
	./pipex $(ARGS)