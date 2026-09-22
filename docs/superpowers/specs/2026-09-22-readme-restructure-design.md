# README 重整設計

日期：2026-09-22
狀態：已實作

## 背景

repo 目前有 260 個解答檔（216 C++ / 44 Python）、7 個 template、10 個 SQL，
README 以 26 個分類收錄 249 筆。主要問題有兩類：

**分類過粗。** `Array`（33 題）與 `String`（25 題）實質上是垃圾桶，裡面混雜
prefix sum、matrix、counting、simulation 等思路完全不同的題型。`DP`（20 題）
未區分 knapsack / grid / interval。複習時無法「針對某個 pattern 集中練」。

**手打連結累積錯誤。** 每筆條目都手寫一段 90 字元的 GitHub 絕對路徑，已累積
11 處錯誤（見「待修正項目」）。

## 目標

1. 分類細化到「同一標題底下的題目思路真的同質」
2. 降低新增一題的手動成本
3. 每題有一句解法摘要，複習時不必點進原始碼就能自我檢測
4. 修正既有錯誤，並讓同類錯誤更不容易再發生

## 非目標（已明確排除）

- **不做**任何腳本、git hook、CI 檢查。README 純手動維護。
- **不做**複習狀態追蹤（複習日期／次數／信心度）。
- **不做**一題掛多 tag／出現在多個分類。手動模式下維護成本過高。
- **不做**原始碼 metadata 標頭。

## 設計

### D1. 相對路徑連結

    舊：[[C++]](https://github.com/come880412/Leetcode_practice/blob/main/Solution/0840.cpp)
    新：[C++](Solution/0840.cpp)

90 字元 → 18 字元。GitHub 正常運作，VSCode 可 ctrl+click 直接跳轉，
repo 改名或被 fork 不會失效。手打長度大幅縮短是降低筆誤的主要手段。

### D2. 一題一個家

每題只出現在一個子分類底下。跨分類查找靠 GitHub 頁面 Ctrl+F（例如搜
`monotonic`、`prefix`），不額外維護索引。

**既有的兩處重複必須擇一保留：**
- 1334 目前同時在 `Dijkstra` 與 `Floyd-Warshall` → 保留 Floyd-Warshall
- 2684 目前同時在 `DP` 與 `BFS` → 保留 DP

### D3. 條目格式

    - `M 1425` [840. Magic Squares in a Grid](https://leetcode.com/problems/magic-squares-in-a-grid/) — [C++](Solution/0840.cpp) · 3x3 暴力枚舉+逐項檢查

欄位依序為：難度與 rating（無 rating 時寫 `` `M` ``）、題號與標題連結、
解答連結（多語言並列）、`·` 之後為解法摘要。

**解法摘要**一句話，寫給未來的自己看，不求完整。由 Claude 讀 260 個原始碼
起草，使用者再逐題修訂。

### D4. 分類體系

五個區塊、26 個主分類、約 45 個子分類。

**A. 資料結構**

| 主分類 | 子分類 |
|---|---|
| Array & Matrix | Prefix Sum / Difference、Matrix & 2D Grid、Sorting-based、Counting |
| String | Parsing & Building、Pattern Matching、Palindrome、Counting |
| Hash Table | — |
| Linked List | — |
| Stack | Parentheses、Monotonic Stack |
| Queue & Deque | Monotonic Deque ※ |
| Heap / Priority Queue | — |
| Trie | — |
| Union-Find | — |
| Segment Tree / BIT ※ | — |

**B. 掃描技巧**

| 主分類 | 子分類 |
|---|---|
| Two Pointers | Opposite Direction、Fast & Slow |
| Sliding Window | Fixed Size、Variable Size |
| Binary Search | On Sorted Array、On Answer |
| Interval | Merge / Insert、Sweep Line |

**C. 演算法範式**

| 主分類 | 子分類 |
|---|---|
| Greedy | — |
| Dynamic Programming | Linear、Grid、Knapsack、Subsequence、Interval/Palindrome、Bitmask ※、Digit ※ |
| Backtracking | — |
| Simulation | — |

**D. 樹與圖**

| 主分類 | 子分類 |
|---|---|
| Tree | Traversal、BST、Construction、Tree DP |
| Graph | Traversal、Topological Sort、Dijkstra、Floyd-Warshall、MST ※ |

**E. 其他**

Bit Manipulation ／ Math（Number Theory、Prime、Combinatorics、Geometry）／
Design ／ SQL ／ Templates

※ 標記代表目前零題的缺口。空標題保留在 README 中作為持續提醒。

### D5. 取消 DFS / BFS 主分類

DFS/BFS 是手段而非題型。現行 `BFS` 區塊混雜樹的題（102、2458、2641）與網格的題
（1765、2684、2812），兩者思路不同。拆入 `Tree > Traversal` 與
`Graph > Traversal` 後，同一標題底下才真正同質。

`DFS` 區塊的 133、200 移入 `Graph > Traversal`。386 的解法是在一棵隱含的
10 元 trie 上做 preorder DFS，移入 `Trie`。

### D6. 收編 SQL

`Solution_SQL/README.md` 目前未被主 README 連結，等同不存在。主 README
新增 `SQL` 分類，連結至該檔；該檔連結同步改為相對路徑。

## 待修正項目

### 連結指向錯誤的檔案

| README 行 | 題號 | 目前指向 | 應指向 |
|---|---|---|---|
| L27 | 3194 | `3179.cpp` | `3194.cpp` |
| L44 | 273 | `0796.cpp` | `0273.cpp` |
| L45 | 796 | `0273.cpp` | `0796.cpp` |
| L87 | 3217 | `3271.cpp`（不存在） | `3217.cpp` |
| L204 | 386 | `0200.cpp` | `0386.cpp` |
| L291 | 7 | `0190.cpp` | `0007.cpp` |

### 連結指向不存在的檔案

| README 行 | 題號 | 問題 | 處置 |
|---|---|---|---|
| L25 | 3178 | `3178.cpp` 不存在，解答從未 commit | 移除該筆條目（已確認） |
| L204 | 386 | `0386.py` 不存在 | 移除該 Python 連結，只保留 C++ |

### 其他

- L35：網址打成 `hhttps://`
- L312：`Useful_functions/ReverseCstring.cpp`，實際檔名為 `reverseCstring.cpp`。
  本機 Windows 檔案系統大小寫不敏感所以看不出來，GitHub 上為 404。
- `2583.cpp`（Kth Largest Sum in a Binary Tree）完全未收錄，
  應新增至 `Tree > Traversal`。
- `Solution_SQL/README.md` 中 1527 的 LeetCode 網址誤植為 1757 那題的網址。
- `Solution_SQL/README.md` 未被主 README 連結（見 D6）。

## 驗收標準

1. `Solution/`、`Solution_SQL/`、`Useful_functions/` 中每個檔案都恰好被 README
   收錄一次（1334、2684 的重複已消除）
2. README 中每個相對路徑連結都對應到實際存在的檔案
3. 每筆條目都有解法摘要
4. 無 `github.com/come880412` 絕對路徑殘留
5. ※ 缺口分類的空標題存在於 README 中
