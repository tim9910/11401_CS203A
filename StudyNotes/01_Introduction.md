## Data Structures: Introduction — 重點整理

### **詳細內容請參考老師提供的講義**： [01_Introduction.md](https://github.com/yfhuang/11401_CS203A/blob/main/StudyNote/01_Introduction.md)

| 主題 | 重點內容 |
|---|---|
| 資料結構（DS） | 資料結構是一種 **用來組織資料，使其能被有效使用** 的方式。 |
| 靜態資料結構 | 記憶體大小固定，通常存取速度較快。（例：Array） |
| 動態資料結構 | 記憶體大小不固定，程式執行時可調整，適合需要頻繁更新的情況。（例：Linked List） |

---

### 資料結構種類

| 類型 | 內容 | 舉例 |
|---|---|---|
| **原始資料結構** | 可存放單一值的基本型別 | `int`, `char`, `float`, `double`, pointer |
| **非原始資料結構** | 可存放多個元素，分為線性與非線性 |  |
| 線性（Linear） | 元素具有先後順序，一個接一個排列 | List, Queue, Stack |
| 非線性（Non-linear） | 元素呈多層或網狀關係 | Tree, Graph, Table |

---

### 演算法效能分析

| 概念 | 定義 |
|---|---|
| **時間複雜度** | 衡量演算法執行所需時間隨輸入大小的增長關係。 |
| **空間複雜度** | 衡量演算法所需記憶體空間隨輸入大小的增長關係。 |

---

### 常見時間複雜度等級（由快到慢）

O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(n³) < O(2ⁿ) < O(n!)


### 動態記憶體配置

#### 1️⃣ 核心概念
- 在程式執行期間向作業系統請求記憶體。
- 主要函數：
     - `malloc(size)` → 分配指定大小記憶體，回傳指標
     - `realloc(ptr, new_size)` → 調整已分配記憶體大小
     - `free(ptr)` → 釋放記憶體

#### 2️⃣ 程式碼
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