server :
	gcc utils.c server.c -I./ -o server

client :
	gcc utils.c client.c -I./ -o client

clean :
	rm client
	rm server

re : clean server client