#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char** argv) {
    char hostname[256];
    char *ipaddress;
    struct hostent *host_entry;

    // To retrieve hostname
    if ( gethostname(hostname, sizeof(hostname)) == -1) {
        perror("Could not resolve hostname\r\n");
        return -1;
    }

    // To retrieve host information
    host_entry = gethostbyname(hostname);
    if ( !host_entry ) {
        perror("Could not resolve host entry\n");
        return -1;
    }

    // To convert an Internet network
    // address into ASCII string
    ipaddress = inet_ntoa(*((struct in_addr*)
                           host_entry->h_addr_list[0]));

    if ( !ipaddress ) {
        perror("Could not resolve ip address\n");
        return -1;
    }

    printf("%s\n", hostname);
    printf("%s\n", ipaddress);

    return 0;
}
