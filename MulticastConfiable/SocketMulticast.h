#ifndef SOCKETMULTICAST_H_
#define SOCKETMULTICAST_H_
#include "PaqueteDatagrama.h"
#include <errno.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include "mensaje.h"
#include "SocketDatagrama.h"
using namespace std;
//Clase SocketMulticast para implementar los sockets de envío y recepción de
//mensajes multicast, su interfaz se muestra a continuación:
class SocketMulticast{
    public:
        SocketMulticast(int);
        ~SocketMulticast();
        int recibe(PaqueteDatagrama &p);
        int recibeConfiable(PaqueteDatagrama &p);
        //En el método envia el segundo parámetro es el valor de TTL necesario para enviar el datagrama.
        int envia(PaqueteDatagrama &p, unsigned char ttl);
        int enviaConfiable(PaqueteDatagrama &p, unsigned char ttl, int num_receptores);
        //En los métodos unirseGrupo para unirse al grupo de receptores y salirseGrupo para salir del
        //grupo de receptores, el parámetro recibido es la dirección IP de multicast.
        //Se une a un grupo multicast, recibe la IP multicast
        void unirseGrupo(char *);
        //Se sale de un grupo multicast, recibe la IP multicast
        void salirseGrupo(char *);
    
    private:
        struct sockaddr_in direccionLocal;
        struct sockaddr_in direccionForanea;
        struct ip_mreq multicast;
        int contMessage;
        int lastMessage;
        int s; //ID socket
        SocketDatagrama *ack; //Acuse
};
#endif