all: compile

compile : 
	g++ -Wall -Wextra -Werror -std=c++98 -o megaphone megaphone.cpp

test : compile
	./megaphone "shhhhh... I think the students are asleep..."
	./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
	./megaphone