
    Tree（樹）
    │
    ├── 1. 定義
    │        ├── 非線性、階層式資料結構
    │        ├── 由 nodes 與 edges 組成
    │        ├── 具有父子關係（parent–child）
    │        └── 無循環（no cycles）
    │
    ├── 2. 資料結構
    │        ├── Node
    │        │     ├── Root（根節點）：沒有父節點
    │        │     ├── Parent（父節點）：有子節點的節點
    │        │     ├── Children（子節點）：由父節點延伸
    │        │     ├── Leaf（葉節點）：沒有子節點
    │        │     ├── Sibling（兄弟節點）：有相同父節點的節點
    │        │     └── Internal Node（內部節點）：非葉節點
    │        │     
    │        ├── Edge：連接兩個節點的線
    │        ├── Subtree：由某節點與其後代形成，分左、右子樹
    │        ├── Depth：從Root到節點的距離
    │        ├── Height：節點到最深葉子的距離
    │        └── Degree：節點的子節點數量
    │
    ├── 3. 特性
    │        ├── n 個節點 → n - 1 條邊
    │        ├── 每節點最多只有一個父節點（root 除外）
    │        └── 0 個或多個子節點
    │
    ├── 4. 用途
    │        ├── 檔案系統
    │        ├── 組織架構
    │        ├── 資料庫索引
    │        ├── 網路拓撲
    │        ├── IP路由查表
    │        ├── 快取
    │        └── 機器學習分類
    │
    ├── 5. 種類
    │        ├── General Tree（一般樹）
    │        │     └── 每個節點可有任意多個子節點
    │        │
    │        ├── Binary Tree（二元樹）
    │        │     ├── 每節點最多2子節點（左、右）
    │        │     └── 種類
    │        │           ├── Strict Binary Tree
    │        │           │       └── 每個節點的degree只能是 0 或 2
    │        │           │
    │        │           ├── Degenerate Binary Tree
    │        │           │       └── 每個節點只有一個子節點(左或右)，樹的結構像單向的linklist
    │        │           │
    │        │           ├── Prefect Binary Tree        
    │        │           │       └── 每層節點都被填滿(節點總數=2^(h+1)-1)
    │        │           │
    │        │           └── Complete Binary Tree（完全二元樹）    
    │        │                   ├── 除最後一層外皆滿、最後一層需由左至右連續填入
    │        │                   └── 種類
    │        │                         ├── MaxHeap Tree: 每個節點的值不小於其子節點，根節點是整棵樹的最大值 
    │        │                         └── MinHeap Tree: 每個節點的值不大於其子節點，根節點是整棵樹的最小值  
    │        │
    │        ├── Binary Search Tree（BST, 二元搜尋樹）
    │        │      └── 每節點最多2子節點，且左子樹 < 根 < 右子樹
    │        │
    │        └── Balanced BST（平衡二元搜尋樹）
    │               ├── 特性
    │               │     ├── BST + 高度平衡機制 (高度差受限制)
    │               │     ├── 樹高度維持接近 log n
    │               │     └── 插入/刪除後會自動進行平衡調整
    │               │     
    │               └── 種類
    │                     ├── AVL Tree: 高度差超過 1 時 -> 旋轉調整
    │                     └── Red-Black Tree: 紅黑節點規則違反時 -> 調整平衡
    │
    ├── 6. Traversal
    │        ├── 定義:以特定順序訪問每個節點的過程
    │        ├── 類型
    │        │     ├── Depth-First Traversal（DFT）
    │        │     │      ├── 沿著樹的一條路徑走到底，再回到分叉點訪問其他節點
    │        │     │      ├── 使用資料結構: stack (遞迴)    
    │        │     │      └── 分類
    │        │     │            ├── Preorder (前序): 根 -> 左 -> 右
    │        │     │            │   
    │        │     │            │     function PreOrder(node):
    │        │     │            │        if node is null:
    │        │     │            │           return 
    │        │     │            │        visit(node)          // 訪問根節點
    │        │     │            │        PreOrder(node.left)  // 左子樹
    │        │     │            │        PreOrder(node.right) // 右子樹
    │        │     │            │   
    │        │     │            ├── Inorder (中序): 左 -> 根 -> 右
    │        │     │            │   
    │        │     │            │     function InOrder(node):
    │        │     │            │        if node is null:
    │        │     │            │           return 
    │        │     │            │        InOrder(node.left)  // 左子樹
    │        │     │            │        visit(node)         // 訪問根節點
    │        │     │            │        InOrder(node.right) // 右子樹
    │        │     │            │   
    │        │     │            └── Postorder (後序): 左 -> 右 -> 根
    │        │     │                
    │        │     │                  function PostOrder(node):
    │        │     │                     if node is null:
    │        │     │                        return 
    │        │     │                     PostOrder(node.left)  // 左子樹
    │        │     │                     PostOrder(node.right) // 右子樹
    │        │     │                     visit(node)          // 訪問根節點
    │        │     │                ```
    │        │     │                
    │        │     │       
    │        │     └── Breadth-First Traversal（BFT）
    │        │            ├── 逐層訪問節點，先訪問同層的所有節點，再進入下一層
    │        │            └── 使用資料結構: Queue 
    │        │            
    │        │                function BFT(root):
    │        │                    if root is null:
    │        │                        return
    │        │                    queue = empty queue
    │        │                    queue.enqueue(root)           //將根加入queue
    │        │                    while queue is not empty:       //節點未訪問完
    │        │                        node = queue.dequeue()
    │        │                        visit(node)
    │        │                        if node.left is not null:   //存在左節點
    │        │                            queue.enqueue(node.left)
    │        │                        if node.right is not null:  //存在右節點
    │        │                            queue.enqueue(node.right)
    │        │  
    │        └── DFT vs BFT    
    │              ├── 時間複雜度: 皆為 O(n)
    │              └── 空間複雜度
    │                      ├── DFT:依樹高度，平衡樹 O(log n)，Skewed Tree最壞 O(n) 
    │                      └── BFT:依樹最寬層節點數，最壞情況 O(n)       
    │                          
    ├── 7. Degenerate Tree（退化/Skewed樹）
    │        ├── 定義：每個節點只有 1 個子節點，外觀像 Linked List（鏈結串列）
    │        ├── 形成原因
    │        │     ├── BST 遞增/遞減插入
    │        │     └── 未平衡化
    │        └── 缺點：搜尋/插入/刪除退化成 O(n)
    │      
    ├── 8. Rebalancing    
>>>>| data structure | Invariant | Rebalancing Trigger | Criterion | Adjustment |
>>>>|--------|------------------------|------------|---------|----------------|
>>>>| **Max Heap** | Heap Property（parent ≥ child） | Insert、Delete | Key Comparison | Heapify-up（swap） |
>>>>| **Min Heap** | Heap Property（parent ≤ child） | Insert、Delete | Key Comparison | Heapify-down（swap） |
>>>>| **AVL Tree** | 高度平衡（\|左-右\| ≤ 1） | Insert、Delete | 高度差 | 旋轉（LL、RR、LR、RL） |
>>>>| **Red-Black Tree** | 顏色規則、黑高度一致 | Insert、Delete | 違反紅黑規則 | 換色 + 旋轉 |
    └── 9. Performance  
             ├── Time Complexity
>>>>>>>| data structure | Operation | Worst | Average | Note |
>>>>>>>|--------|------------------------|------------|---------|----------------|
>>>>>>>| **Max/Min Heap** | Insert/Delete | O(log n) | O(log n) |  |
>>>>>>>| **AVL Tree** | Insert/Delete/Search | O(log n) | O(log n) |  |
>>>>>>>| **Red-Black Tree** | Insert/Delete/Search | O(log n) | O(log n) |  |
>>>>>>>| **Binary Search Tree(BST)** | Insert/Delete/Search | O(n) | O(log n) | 平衡樹 O(log n) ; Skewed Tree O(n)最壞 |
             └── Space Complexity     
>>>>>>>| data structure | Space Complexity | Note |
>>>>>>>|--------|------------------------|------------|
>>>>>>>| **Max/Min Heap** | O(n) |  |
>>>>>>>| **AVL Tree** | O(n) |  |
>>>>>>>| **Red-Black Tree** | O(n) |  |
>>>>>>>| **Binary Search Tree(BST)** | O(n) |  |