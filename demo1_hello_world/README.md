### 1. SOCKET API
Client: Socket -> connect -> send -> recv -> closesocket <br>
Server: Socket -> bind -> listen -> accept -> recv -> send -> closesocket


### 2. USAGE
##### 2.1 start server
`g++ tcp_server.cpp -o tcp_server.o -lwsock32` <br>
`.\tcp_server.o`

##### 2.2 start_client
`g++ tcp_client.cpp -o tcp_client.o -lwsock32`
`.\tcp_client.o`

### 3. ERROR
1. undefined reference to `__imp_WSAStartup`
**_solution_**:  add `-lwsock32`  to complie


### 4. WIN_CMD
##### 4.1 find pid by name
`tasklist | findstr tcp_server`
##### 4.2 kill by pid
`taskkill /t /f /im $pid`
