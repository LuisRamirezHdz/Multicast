run: rservidor.cpp  SocketMulticast.o PaqueteDatagrama.o SocketDatagrama.o
	g++ rservidor.cpp SocketMulticast.o PaqueteDatagrama.o SocketDatagrama.o -o rservidor
	
SocketMulticast.o: SocketMulticast.cpp PaqueteDatagrama.o 
	g++ SocketMulticast.cpp -c 

PaqueteDatagrama.o: PaqueteDatagrama.cpp
	g++ PaqueteDatagrama.cpp -c

SocketDatagrama.o: SocketDatagrama.cpp
	g++ SocketDatagrama.cpp -c