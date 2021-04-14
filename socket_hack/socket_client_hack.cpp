// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <random>
#define PORT 9999

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    std::string cmd("moveTo(150,150,700,0.5,90,False)\n");
    std::string cmd2("moveTo(5,150,700,0.5,90,False)\n");

    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
//    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    if(inet_pton(AF_INET, "192.168.50.14", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
//    cmd_args = cmd + "({0},{1},{2},{3},{4},{5})".format(position, speed, acceleration, torque, tolerance, waitFlag) + "\n"

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
//    send(sock , hello , strlen(hello) , 0 );

    for (int i = 0; i < 3; i++) {
        send(sock , cmd.c_str(), cmd.length(), 0 );
        usleep(500000);
        send(sock , cmd2.c_str(), cmd2.length(), 0 );
        usleep(500000);
    }
    srand(time(NULL));
    char buff[4096];
    for (int i = 0; i < 100; i++) {
        float r = float(rand())/RAND_MAX;
        float position, speed, acceleration, torque, tolerance;
        position = 140*r;
        speed = 150;
        acceleration = 700;
        torque =0.5;
        tolerance = 90;
        sprintf(buff, "moveTo(%d,%d,%d,%.2f,%d,False)\n", int(position), int(speed), int(acceleration), torque, int(tolerance));
        printf("%s", buff);
//        send(sock , cmd.c_str(), cmd.length(), 0 );
        send(sock , buff, strlen(buff), 0 );
        usleep(1000);
//        send(sock , cmd2.c_str(), cmd2.length(), 0 );
//        usleep(500000);
    }
    printf("Hello message sent\n");
//    valread = read( sock , buffer, 1024);
//    printf("%s\n",buffer );
    close(sock);
    return 0;
}
