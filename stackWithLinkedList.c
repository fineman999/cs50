#include <stdio.h>
#include <stdlib.h>
/*
✔︎ 미션 2.

1. 미션 제목
연결리스트로 Stack 만들기

2. 지시문
EDWITH CS50 강좌에서 배운 Stack을 보조미션 1에서 배열을 이용해서 구현해 보셨는데요, 이번에는 연결리스트를 이용해서 Stack을 구현하는 과제입니다.
 지난 문제와 마찬가지로 아래 표에 함수의 주석 처리된 부분들에 여러분의 코드를 채워 넣어주세요.

*/
typedef struct stackNode
{
    int data;
    struct stackNode *next;
} StackNode;

StackNode *createStackNode(int data)
{
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->data = data;
    node->next = NULL;
    return node;
}

int isEmpty(StackNode *root)
{
    return !root;
}

void push(StackNode **root, int data)
{
    StackNode *newNode = createStackNode(data);
    if (newNode == NULL)
    {
        exit(1);
    }
     // 이 부분을 구현해 주세요!
    newNode->next = *root;
    *root = newNode;

    printf("%d pushed to stack\n", data);
}

int pop(StackNode **root)
{
    if (isEmpty(*root))
        return -9999;
    int popped;
    // 이 부분을 구현해 주세요!
    StackNode *deleteNode;
    popped = (*root)->data;
    deleteNode = *root;
    *root = (*root)->next;
    free(deleteNode);

    return popped;
}

int peek(StackNode **root)
{
    if (isEmpty(*root))
        return -9999;
    return (*root)->data;
}

int main()
{
    StackNode *root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    push(&root, 40);

    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));

    push(&root, 50);
    printf("%d peeked from stack\n", peek(&root));
    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));
    return 0;
}
