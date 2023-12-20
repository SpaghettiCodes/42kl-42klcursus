SOCKET = Socket.cpp

SERVER = Server.cpp

CLIENT = Client.cpp Handler.cpp

SERVER = Server.cpp $(CLIENT) $(SOCKET)

WEBSERV = WebServer.cpp $(SERVER)

all: server

server: $(WEBSERV) main.cpp
	g++ $(WEBSERV) main.cpp -o server

webserv:
	g++ *.cpp -o webserv

clean:
	rm -rf client server webserv