/*
 * Simple TCP client stub - connects to a server, reads response, and prints it.
 * Compile: gcc -o level0 level0.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define HOST "127.0.0.1"  /* Server hostname or IP */
#define PORT 9999         /* Server port */
#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    /* Create a TCP socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("[-] Socket creation failed");
        exit(EXIT_FAILURE);
    }

    /* Set up server address structure */
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    /* Convert IP address from text to binary */
    if (inet_pton(AF_INET, HOST, &server_addr.sin_addr) <= 0) {
        perror("[-] Invalid address");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    /* Connect to the server */
    printf("[*] Connecting to %s:%d...\n", HOST, PORT);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("[-] Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("[+] Connected!\n");

    /* Receive data from the server */
    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    
    if (bytes_received < 0) {
        perror("[-] Receive failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    /* Print the response */
    printf("[+] Received: %s\n", buffer);

    /* Clean up */
    close(sockfd);

    return 0;
}

