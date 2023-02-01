#define WIN32_LEAN_AND_MEAN
#include<windows.h>
#include<winsock2.h>
#include<stdio.h>
int main(){
    WORD ver = MAKEWORD(2,2);  // 启动网络库
    WSADATA dat;
    WSAStartup(ver, &dat);

    // 创建socket对象
    SOCKET _sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    // 绑定
    sockaddr_in _sin = {};   // 结构体
    _sin.sin_family = AF_INET;
    _sin.sin_port = htons(4567); 
    _sin.sin_addr.S_un.S_addr = INADDR_ANY; // 泛指本机（主机上所有的网卡）
    int ret_code = bind(_sock, (sockaddr*)&_sin, sizeof(_sin));  //此处需要将sockaddr_in强制转化为sockaddr类型
    if (ret_code == SOCKET_ERROR){
        printf("ERROR, bind port %d:%d failed...\n", _sin.sin_addr.S_un.S_addr, _sin.sin_port);
    }else{
        printf("SUCCEED, bind port %d:%d succeed...\n", _sin.sin_addr.S_un.S_addr, _sin.sin_port);
    }
    // 监听
    ret_code = listen(_sock, 5);
    if (ret_code == SOCKET_ERROR){
        printf("ERROR, listen failed\n");
    }else{
        printf("SUCCEED, listen succeed\n");
    }
    // accept等待客户端连接
    SOCKET _clientSock = INVALID_SOCKET;
    sockaddr_in clientsockAddr = {};
    int nAddrLen = sizeof(sockaddr_in);
    char msgBuf[] = "Hello, I'm Server.\n";
    while (true)
    {
        //循环accept等客户端连接
        _clientSock = accept(_sock, (sockaddr*)&clientsockAddr, &nAddrLen);
        if (_clientSock == INVALID_SOCKET){
            printf("ERROR: ACCEPT socket error\n");
        }
        printf("New Client Connection: IP = %d strIP= %s \n", clientsockAddr.sin_addr, inet_ntoa(clientsockAddr.sin_addr));
        // send 向客户端发送数据
        send(_clientSock, msgBuf, strlen(msgBuf)+1, 0);
    }
    // 关闭socket
    closesocket(_sock);
    WSACleanup();  // 清除网络环境
}