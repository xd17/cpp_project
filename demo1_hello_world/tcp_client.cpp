#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
#include <stdio.h>

int main()
{
    WORD ver = MAKEWORD(2, 2);
    WSADATA dat;
    WSAStartup(ver, &dat);

    // 创建socket
    SOCKET _sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    // connect连接服务端
    sockaddr_in _sin = {};
    _sin.sin_family = AF_INET;
    _sin.sin_port = htons(4567);
    _sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    int ret_code = connect(_sock, (sockaddr *)&_sin, sizeof(_sin));
    if (ret_code == SOCKET_ERROR)
    {
        printf("ERROR: client connect %s failed....", _sin.sin_addr.S_un.S_addr);
    }
    else
    {
        printf("SUCCEED: client connect %s succeed....", _sin.sin_addr.S_un.S_addr);
    }

    // recv接受服务器返回的信息
    char recvBuf[256] = {};
    int len = recv(_sock, recvBuf, 256, 0);
    if (len > 0){
        printf("in client: %s",recvBuf);
    }
    printf("%s\n",recvBuf);
    closesocket(_sock);
    WSACleanup();
    getchar();
}