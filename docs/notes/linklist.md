# 鏈結串列（Linked List）

## 1️⃣ 核心概念
- 鏈結串列是一種線性資料結構，由節點（Node）串接而成。
- 每個節點包含：
    - **資料（data）**：儲存節點的值
    - **指標（next）**：指向下一個節點(Node)
- 特點：
    - 節點可以動態增加或刪除
    - 可以從頭節點開始順序遍歷
    - 只能單向遍歷，無法直接回到前一個節點

## 2️⃣ 程式碼
```c
#include <stdio.h>
#include <stdlib.h>

// 定義節點結構 
typedef struct Node {
    int data;           // 儲存節點的資料
    struct Node* next;  // 指向下一個節點的指標
} Node;

/*
 * 建立新節點
 * 參數: value (節點儲存的資料)
 * 回傳: 指向新節點的指標
 */
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

/*
 * 遍歷鏈結串列並印出節點資訊
 * 參數: head (鏈結串列的頭節點指標)
 * 回傳: 無
 */
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
        
    // 釋放鏈結串列記憶體 
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;     //暫存目前節點
        current = current->next; // 移動到下一節點
        free(temp);              // 釋放當前節點
    }

    return 0;
}
```

!!! tip "小技巧"
	- 建立頭節點（head）有助於方便插入或遍歷。
	- 插入或刪除節點時，通常需要記錄前一個節點的位置。
	- 遍歷時要檢查 next 是否為 NULL，避免存取錯誤。
	- 使用完鏈結串列後，務必釋放每個節點的記憶體，避免記憶體洩漏。
