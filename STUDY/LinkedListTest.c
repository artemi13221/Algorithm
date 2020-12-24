#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ch {
    char s[50];
    struct ch *link;
} CH;

int main() {
    CH *list = NULL; //Linked List의 맨 처음 주소
    CH *prev = NULL, *p = NULL, *next = NULL; //현재에서 전 주소, 현재 주소, 다음 주소의 포인터
    char name[50];

    p = (CH *)malloc(sizeof(CH));
    strcpy(p->s, "apple");
    list = p;
    p->link = NULL;
    prev = p;

    while(1) {
        printf("끝말입기를 입력하세요. 현재 단어 : %s (종료하실려면 -1를 눌러주세요.) : ", prev->s);
        scanf("%s", name);
        if(strcmp(name, "-1") == 0) {
            break;
        }
        int len = 0;
        while((prev->s)[len]) {
            len++;
        }
        if((prev->s)[len-1] != name[0]) {
            printf("잘못된 단어를 입력하셨습니다. 다시 입력해주세요.\n");
            continue;
        }
        p = (CH *)malloc(sizeof(CH));
        strcpy(p->s, name);
        prev->link = p;
        p->link = NULL;
        prev = p;
    }
    p = list;
    while(p->link != NULL) {
        printf("%s->", p->s);
        p = p->link;
    }
    printf("%s\n", p->s);
    p = list;
    while(p != NULL) {
        next = p->link;
        free(p);
        p = next;
    }
    return 0;
}