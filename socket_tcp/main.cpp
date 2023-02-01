#define WIN32_LEAN_AND_MEAN  // 避免提示warning
#include<windows.h>
#include<winsock2.h>
int main()
{
    WORD ver = MAKEWORD(2,2);
    WSADATA dat;
    WSAStartup(ver, &dat);
    WSACleanup();
    return 0;
}