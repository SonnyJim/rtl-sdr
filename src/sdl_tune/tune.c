// Client side implementation of UDP client-server model 
#include "sdl_tune.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
    
#define PORT     6020
struct packet_t 
{
	uint8_t cmd;
	long	data;
};

struct packet_t packet;
#define UDP_BUFFSIZE sizeof(packet)

static void send_packet ()
{
    int sockfd; 
    char buffer[UDP_BUFFSIZE]; 
    struct sockaddr_in     servaddr; 
    
    // Creating socket file descriptor 
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    memset(&servaddr, 0, sizeof(servaddr)); 
        
    // Filling server information 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
        
    memcpy (buffer, &packet.cmd, sizeof(packet.cmd));
    memcpy (buffer + sizeof(packet.cmd), &packet.data, sizeof(packet.data));
    sendto(sockfd, (const char *)buffer, UDP_BUFFSIZE, 
        MSG_CONFIRM, (const struct sockaddr *) &servaddr,  
            sizeof(servaddr)); 
    close(sockfd); 
 
}

void send_freq(int freq) { 
	packet.cmd = 0x00;
	packet.data = freq;
	send_packet ();
}

void change_demod (void)
{
	demod++;
	if (demod > 3)
		demod = 0;
	packet.cmd = 0x01;
	packet.data = demod;
	send_packet ();
}
