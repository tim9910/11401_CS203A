/*
(一)建立節點
(二)遍歷與印出
(三)釋放記憶體
*/
#include <stdio.h>
#include <stdlib.h>

// 定義節點結構 
typedef struct Node {
    int data;           // 儲存節點的資料
    struct Node* next;  // 指向下一個節點的指標
} Node;


Node* createNode(int value) {
    // 配置記憶體空間給新節點
    Node* newNode = (Node*)malloc(sizeof(Node));

    // 檢查是否配置成功
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);  
    }

    newNode->data = value;
    // 初始時next為NULL
    newNode->next = NULL;

    return newNode;
}


void traverseList(Node* head) {
    Node* current = head;  // current指向頭節點
    int index = 0;         

    // 當前節點不為 NULL 時繼續
    while (current != NULL) {
        printf("Node %d: Value = %d, Address = %p, Next = %p\n", 
               index,            // 節點編號
               current->data,    // 節點資料
               (void*)current,   // 節點本身位址
               (void*)current->next // 下一節點位址
        );
        current = current->next;
        index++;
    }
}


int main() {
    Node* head = createNode(10);          // 第1個節點 (頭節點)
    head->next = createNode(20);          // 第2個節點
    head->next->next = createNode(30);    // 第3個節點 (尾節點)
                                          //鏈結串列：10 -> 20 -> 30 -> NULL

    printf("Traversing the linked list:\n");
    traverseList(head);
        
    // 釋放記憶體 
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;   
        current = current->next; // 移動到下一節點
        free(temp);              // 釋放當前節點
    }

    return 0;
}
