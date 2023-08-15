#include <stdio.h>
#include <string.h>

int queue[10000];   // queue의 기능을 하는 배열
int size = 0;   // queue의 길이
char command[50];   // 명령어를 입력받을 배열

void push(int num) {        // queue에 숫자를 입력하는 함수
    queue[size] = num;      // 마지막 자리에 입력받은 숫자를 넣음
    size += 1;              // 사이즈 1 증가
}

int empty() {           // queue가 비어있는지 확인하는 함수
    if (size == 0)       // 사이즈가 0이면
        return 1;       // 1을 리턴
    else
        return 0;       // 그렇지 않으면 0을 리턴
}

void pop() {        // 인덱스 0번을 출력 후 삭제하는 함수
    if (empty()) {       // queue가 비어있으면
        printf("-1\n");     // -1을 출력
    } else {
        printf("%d\n", queue[0]); // 그렇지 않을 경우 큐의 첫번째 수 출력
        for (int i = 0; i < size - 1; i++) {
            queue[i] = queue[i + 1];  // 배열을 한칸씩 앞당김
        }
        size--;
    }
}

int front() {
    if (empty()) {       // queue가 비어있으면
        return -1;      // -1 
    }
    return queue[0];    // 그렇지 않을 경우 첫번째 인덱스 반환
}

int back() {
    if (empty()) {       // queue가 비어있으면
        return -1;      // -1
    }
    return queue[size - 1];    // 그렇지 않을 경우 마지막 인덱스 반환
}

int main(void) {
    int n = 0;   // 제일 처음 입력받는 수(명령어의 길이)
    int data;   // queue에 넣을 수

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", command);

        if (!strcmp(command, "push")) {   // 입력받은 명령어가 push인 경우
            scanf("%d", &data);
            push(data);                    // push함수 실행    
        } 
        else if (!strcmp(command, "pop")) {  // 입력받은 명령어가 pop인 경우
            pop();                       // pop함수 실행
        } 
        else if (!strcmp(command, "empty")) { // 입력받은 명령어가 empty인 경우
            printf("%d\n", empty());       // empty함수 실행 및 리턴 값 출력
        } 
        else if (!strcmp(command, "size")) { // 입력받은 명령어가 size인 경우
            printf("%d\n", size);        // 배열의 길이 출력
        } 
        else if (!strcmp(command, "front")) { // 입력받은 명령어가 front인 경우
            printf("%d\n", front());   // front함수 리턴 값 출력
        } 
        else if (!strcmp(command, "back")) { //입력받은 명령어가 back인 경우
            printf("%d\n", back()); // back함수 리턴 값 출력
        } 
        else
            printf("잘못된 명령어 입니다.\n");
    }

    return 0;
}
