#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/types.h>


pthread_mutex_t player1, player2; // 뮤텍스를 활용하지 못하였으나 일단 그대로 뒀습니다.
int client_socket; // 클라이언트 소켓 변수
char msg[100]; // 클라이언트의 입력값



int main(int argc, char* argv[]) {
    int server_socket;
    int client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length;
    int length;

    // 소켓 생성
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("소켓 생성 실패");
        exit(1);
    }

    // 주소 설정
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(argv[1]);
    server_address.sin_port = htons(argv[2]);

    // 바인딩
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("바인딩 실패");
        exit(1);
    }


   // 클라이언트 대기열 설정
    if (listen(server_socket, 1) == -1) {
        perror("대기열 설정 실패");
        exit(1);
    }


    // 클라이언트 접속
    client_address_length = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_length);
    if (client_socket == -1) {
        perror("클라이언트 접속 실패");
        exit(1);
    }

    memset(msg, 0, sizeof(msg));
    if (recv(client_socket, msg, sizeof(msg), 0) <= 0) {
            perror("수신 실패");
            exit(1);
    }
    
    length = strlen(msg);

    for(int i=0; i++; i<length) {
        printf("%c\n", msg[i]);
    }
            

    // 소켓 종료
    close(client_socket);
    close(server_socket);

    return 0;
}


