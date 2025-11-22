# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer: 林晉霆  
Email: s1133322@mail.yzu.edu.tw 

## My Hash Function
### Integer Keys 
- Formula / pseudocode:
  ```text
  myHashInt(key, m):
      r = digits(key) reversed
      RETURN (r * BASE + key) MOD m
  ```
- Rationale: [Explain your design choices and how they minimize collisions.]

### Non-integer Keys
- Formula / pseudocode:
  ```text
  myHashString(str, m):
      hash = 0
      FOR each character c in str:
          num = charToNum(c)
          IF num is valid:
              hash = hash * BASE + num
      RETURN hash MOD m
  ```
- Rationale: [Explain your approach and its effectiveness for non-integer keys.]

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
- For integers:
  | Table Size (m) | Index Sequence                                                           | Observation                            |
    |----------------|--------------------------------------------------------------------------|----------------------------------------|
    | 10             | 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6               | Index changes很少，高度重複            |
    | 11             | 1, 0, 10, 9, 8, 7, 6, 5, 4, 3, 4, 3, 2, 1, 0, 10, 9, 8, 7, 6             | 呈現完整循環遞減序列：10->9->8-> … ->0 |
    | 37             | 12, 22, 32, 5, 15, 25, 35, 8, 18, 3, 15, 25, 35, 8, 18, 28, 1, 11, 21, 6 | Near-uniform、Index 無明顯規律         |

- For strings:
  | Table Size (m) | Index Sequence                         | Observation                       |
  |----------------|----------------------------------------|-----------------------------------|
  | 10             | 9, 1, 8, 6, 0, 5, 7, 2, 7, 0           | 偶有跳動、沒有周期性              |
  | 11             | 0, 2, 10, 6, 0, 4, 10, 3, 8, 10        | 偶有跳動、但整體重複性還是高      |
  | 37             | 25, 27, 24, 5, 36, 14, 13, 28, 33, 9   | Near-uniform、跳動大、完全沒重複  |

## Compilation, Build, Execution, and Output

### Compilation
- The project uses a comprehensive Makefile that builds both C and C++ versions with proper flags:
  ```bash
  # Build both C and C++ versions
  make all
  
  # Build only C version
  make c
  
  # Build only C++ version
  make cxx
  ```

### Manual Compilation (if needed)
- Command for C:
  ```bash
  gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c
  ```
- Command for C++:
  ```bash
  g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX/hash_function_cpp CXX/main.cpp CXX/hash_fn.cpp
  ```

### Clean Build Files
- Remove all compiled files:
  ```bash
  make clean
  ```

### Execution
- Run the compiled binary:
  ```bash
  ./hash_function
  ```
  or
  ```bash
  ./hash_function_cpp
  ```

### Result Snapshot
- Example output for integers:
  ```
  === Hash Function Observation (C++ Version) ===

	=== Table Size m = 10 ===
	Key     Index
	-----------------
	21      2
	22      2
	23      2
	24      2
	25      2
	26      2
	27      2
	28      2
	29      2
	30      3
	51      5
	52      5
	53      5
	54      5
	55      5
	56      5
	57      5
	58      5
	59      5
	60      6

	=== Table Size m = 11 ===
	Key     Index
	-----------------
	21      1
	22      0
	23      10
	24      9
	25      8
	26      7
	27      6
	28      5
	29      4
	30      3
	51      4
	52      3
	53      2
	54      1
	55      0
	56      10
	57      9
	58      8
	59      7
	60      6

	=== Table Size m = 37 ===
	Key     Index
	-----------------
	21      12
	22      22
	23      32
	24      5
	25      15
	26      25
	27      35
	28      8
	29      18
	30      3
	51      15
	52      25
	53      35
	54      8
	55      18
	56      28
	57      1
	58      11
	59      21
	60      6	
  ```

- Example output for strings:
  ```
  === String Hash (m = 10) ===
	Key     Index
	-----------------
	cat     9
	dog     1
	bat     8
	cow     6
	ant     0
	owl     5
	bee     7
	hen     2
	pig     7
	fox     0

	=== String Hash (m = 11) ===
	Key     Index
	-----------------
	cat     0
	dog     2
	bat     10
	cow     6
	ant     0
	owl     4
	bee     10
	hen     3
	pig     8
	fox     10

	=== String Hash (m = 37) ===
	Key     Index
	-----------------
	cat     25
	dog     27
	bat     24
	cow     5
	ant     36
	owl     14
	bee     13
	hen     28
	pig     33
	fox     9
  ```

- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.
- Example output for integers:
  ```
  Hash table (m=10): [2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6]
  Hash table (m=11): [1, 0, 10, 9, 8, 7, 6, 5, 4, 3, 4, 3, 2, 1, 0, 10, 9, 8, 7, 6]
  Hash table (m=37): [12, 22, 32, 5, 15, 25, 35, 8, 18, 3, 15, 25, 35, 8, 18, 28, 1, 11, 21, 6]
  ```
- Example output for strings:
  ```
  Hash table (m=10): [9, 1, 8, 6, 0, 5, 7, 2, 7, 0]
  Hash table (m=11): [0, 2, 10, 6, 0, 4, 10, 3, 8, 10]
  Hash table (m=37): [25, 27, 24, 5, 36, 14, 13, 28, 33, 9]
  ```
- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.

## Analysis
- Prime vs non-prime `m`: Prime table sizes generally result in better distribution and fewer collisions.
  ##### 根據結果繪製碰撞率比較圖，可以清楚看出：
  ![Collision Ratio Comparison](images/collisionRatio.png)

  ##### 1. 以質數(prime)作為 table size 時，碰撞率顯著較低
  ```
  <pre style="white-space: pre-wrap;">
  圖中顯示，質數 m=11、m=37 的碰撞率都比非質數 m=10 更低，尤其是 m=37 (strings=0, integers=0.25) 明顯分佈最均勻、碰撞最少。
  </pre>
  ```
  ##### 2. 非質數(non-prime)有明顯的 clustering 與高碰撞率
  ```
  <pre style="white-space: pre-wrap;">
  圖中顯示非質數m=10時，strings 碰撞率=0.2; integers 碰撞率=0.8(極高)，容易大量集中到同一區，導致高碰撞率。
  </pre>
  ```
  ##### 因此，符合雜湊理論：使用質數作為 table size 能減少 clustering，使分佈更均勻(碰撞少)。

- Patterns or collisions: Non-prime table sizes tend to produce repetitive patterns, leading to more collisions.
  ```
  <pre style="white-space: pre-wrap;">
  觀察 integers 測試結果，非質數 m=10 呈現明顯 pattern，執行結果產生大量重複 index 被對映到 2 和 5，形成 clustering，造成 0.8 的高碰撞率。相較之下，質數 m=11 p及 m=37 則分布較均勻。
  </pre>
  ```
- Improvements: Use a prime table size and a well-designed hash function to enhance distribution.
  ##### 1. 使用質數(prime) 作為雜湊表大小，可避免產生週期性重複，分佈更均勻。
  ##### 2. 採用好的雜湊函數設計可減少 clustering 現象。

## Reflection
1. Designing hash functions requires balancing simplicity and effectiveness to minimize collisions.
2. Table size significantly impacts the uniformity of the hash distribution, with prime sizes performing better.
3. The design using a prime table size and a linear transformation formula produced the most uniform index sequence.
