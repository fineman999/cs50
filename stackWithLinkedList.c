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
       // 이 부분을 구현해 주세요!
    StackNode *newNode = createStackNode(data); //새로운 노드 생성
    if (newNode == NULL) // 노드가 비정상적일 경우 강제 종료
    {
        exit(1);
    }
    newNode->next = *root; //이 newNode의 다음 newNode를 *root 포인터로 지정
    *root = newNode; // root 포인터는 항상 top(즉 LIFO(Last In First Out) 방식)을 유지해야하기 때문에 *root 포인터를 newNode 포인터로 갱신시켜준다.

    printf("%d pushed to stack\n", data);
}

int pop(StackNode **root)
{
    if (isEmpty(*root))
        return -9999;
    int popped;
    // 이 부분을 구현해 주세요!
    StackNode *deleteNode; //필요없는 노드의 메모리를 해제하기위해 노드 선언
    popped = (*root)->data; // 최근에 넣은 값(즉 root의 데이터 값)을 popped에 저장
    deleteNode = *root; // deleteNode 포인터를 *root 포인터로 바꿔준다.
    *root = (*root)->next; // 다음 Node((*root)->next)를 root 포인터로 지정.
    free(deleteNode); // 필요없는 노드의 메모리 해제

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
