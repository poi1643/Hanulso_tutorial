#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

// #define SERVER_IP "127.0.0.1"
// #define PORT 12345

// argv[1]은 서버 IP argv[2]는 서버 포트

int main(int argc, char* argv[]) {
    char PORT, SERVER_IP;
    int client_socket;
    struct sockaddr_in server_address;
    char result[100];
    char choice[100];

    // 클라이언트 소켓 생성
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("소켓 생성 실패");
        exit(1);
    }

    // 서버 주소 설정
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(argv[2]);

    // 서버에 연결
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("서버 연결 실패");
        exit(1);
    }

    printf("메신저 입니다.\n");

    // 가위바위보 입력
    while (1) {
        strcpy(choice, argv[3]);
        choice[strcspn(choice, "\n")] = '\0'; // 개행 문자 제거

        
        // 전송
        if (send(client_socket, choice, strlen(choice), 0) == -1) {
            perror("데이터 전송 실패");
            exit(1);
        }
        
        /* 입력이 q라면 프로그램 종료
        if (strcmp(choice, "q") == 0) {
            printf("채팅이 종료됩니다.\n");
            break;
        }*/

        /* 결과 수신
        memset(result, 0, sizeof(result));
        if (recv(client_socket, result, sizeof(result), 0) <= 0) {
            perror("데이터 수신 실패");
            exit(1);
        }
        printf("\n상대방 : %s\n", result);  
        */
    }

    // 소켓 종료
    close(client_socket);

    return 0;
}

