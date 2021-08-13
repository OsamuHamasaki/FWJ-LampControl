//
// IO.hpp
//

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <stdint.h>

#include "IO.hpp"

class SocketClient {
private:
    int sockfd;

public:
    SocketClient() : sockfd(-1) {}
    bool connectServer(char* serverIp, int port);

    void send(char* sendData, int sendDataLength) { ::send(sockfd, sendData, sendDataLength, 0); }
    void recv(char* recvBuffer, int sizeOfRecvBuffer) { ::recv(sockfd, recvBuffer, sizeOfRecvBuffer, 0); }

    void close() { ::close(sockfd); }
};

bool SocketClient::connectServer(char* serverIp, int port)
{
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd <0) 
    {
        return false;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(serverIp);

    connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    
    return true;
}

class LampIo {
private:
    uint32_t lampState;
    uint32_t buttonState;
    char sendData[2];
    char recvBuffer[8];

    SocketClient client;

public:
    LampIo() : lampState(0), buttonState(0), client() { sendData[1] = '\0'; }

    bool initialize() {
        char addr[] = "127.0.0.1";
        return client.connectServer(addr, 3000);
    }

    void finalize() { client.close(); }

    bool isPowerButtonOn() { return (buttonState & 1) == 1; }
    bool isBrightnessButtonOn() { return (buttonState & 2) == 2; }
    bool isBlinkButtonOn() { return (buttonState & 4) == 4; }

    void lampOn() { lampState |= 1; }
    void lampOff() { lampState &= ~1; }
    void lampBrighten() { lampState |= 2; }
    void lampDarken() { lampState &= ~2; }

    void tick() {
        sendData[0] = '0' + lampState;
        client.send(sendData, 2);

        client.recv(recvBuffer, sizeof(recvBuffer));
        buttonState = (uint32_t)(recvBuffer[0] - '0');
    }
};

LampIo io;

bool IO_initialize()
{
    return io.initialize();
}

void IO_finalize()
{
    io.finalize();
}

bool IO_isPowerSwitchOn()
{
    return io.isPowerButtonOn();
}

bool IO_isBrightnessSwitchOn()
{
    return io.isBrightnessButtonOn();
}

bool IO_isBlinkSwitchOn()
{
    return io.isBlinkButtonOn();
}

void IO_lampOn()
{
    io.lampOn();
}

void IO_lampOff()
{
    io.lampOff();
}

void IO_lampBrighten()
{
    io.lampBrighten();
}

void IO_lampDarken()
{
    io.lampDarken();
}

void IO_tick()
{
    io.tick();
}

// End of File

