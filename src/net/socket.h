#ifndef __CROSS_PLATFORM_SOCKET__
    #ifdef _WIN32
        #ifndef _WIN32_WINNT
            #define WIN32_WINNT 0x0501
        #endif
    
        #include <winsock2.h>
        #include <Ws2tcpip.h>

        int sockInit(void) { WSADATA wsa_data; return WSAStartup(MAKEWORD(1,1), &wsa_data); }
        int sockQuit(void) { return WSACleanup(); }

        int sockClose(SOCKET sock) {
            int status = 0;

            status = shutdown(sock, SD_BOTH);
            if (status == 0) { status = closesocket(sock); }

            return status;
        }
    #else
        #include <sys/socket.h>
        #include <arpa/inet.h>
        #include <unistd.h>
        #include <netdb.h>

        typedef int SOCKET;

        int sockInit(void) { return 0; }
        int sockQuit(void) { return 0; }

        int sockClose(SOCKET sock) {
            int status = 0;

            status = shutdown(sock, SHUT_RDWR);
            if (status == 0) { status = close(sock); }

            return status;
        }
    #endif
#endif