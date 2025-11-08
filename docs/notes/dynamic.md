# 動態記憶體配置

## 1️⃣ 核心概念
- 在程式執行期間向作業系統請求記憶體。
- 主要函數：
     - `malloc(size)` → 分配指定大小記憶體，回傳指標
     - `realloc(ptr, new_size)` → 調整已分配記憶體大小
     - `free(ptr)` → 釋放記憶體

## 2️⃣ 程式碼
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    int n = 10;

	// 1. 配置 n 個整數大小的連續記憶體
    array = (int *) malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

	// 2. 初始化已分配陣列元素
    for(int i = 0; i < n; i++) {
        array[i] = i + 1;
    }
	
	// 3. 列印初始陣列
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

	// 4. 將陣列擴充到 2n 個整數大小的新記憶體
    n = n * 2;
    array = (int *) realloc(array, n * sizeof(int));
    if (array == NULL) {
        printf("Reallocation failed\n");
        return 1;
    }

    //print出realloc後陣列頭尾的記憶體位址
    printf("\nAfter realloc memory address: %p\n", (void*)array);
    printf("After realloc end address   : %p\n", (void*)(array + n * sizeof(n) - 1));

	// 5. 初始化新分配的陣列元素
    for (int i = n/2; i < n; i++) {
        array[i] = i + 1;   
    }

    // 6. 列印擴充後陣列
    printf("Resized array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // 7. 釋放記憶體
    free(array);
    return 0;
}
```
