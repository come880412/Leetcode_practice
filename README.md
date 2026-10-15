# Leetcode_practice

C++ / Python 解題紀錄。分類依據是**解這題需要想到的技巧**，而不是題目給的資料型別 —— 例如 1475 給的是陣列，但關鍵是「下一個更小元素」，所以歸在 Monotonic Stack。

每行格式：`難度 rating` ・題目 ・解答連結 ・一句話解法摘要

> 想跨分類找題目就在本頁 Ctrl+F，例如搜 `prefix`、`monotonic`、`二分`、`快慢指標`。

---

## A. 資料結構

### Array & Matrix

#### Prefix Sum / Difference Array
- `M` [238. Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) — [C++](Solution/0238.cpp) · 算總乘積再除自己，用 0 的個數分三種情況避開除以零
- `E 1416` [1652. Defuse the Bomb](https://leetcode.com/problems/defuse-the-bomb) — [C++](Solution/1652.cpp) · 環狀陣列取模，k 正負決定往後或往前累加
- `M 1294` [1769. Minimum Number of Operations to Move All Balls to Each Box](https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box) — [C++](Solution/1769.cpp) · 左右各掃一次，前綴累積「球數 × 距離」
- `M 1435` [2559. Count Vowel Strings in Ranges](https://leetcode.com/problems/count-vowel-strings-in-ranges) — [C++](Solution/2559.cpp) · 前綴計數頭尾皆母音的字串，查詢 O(1) 相減
- `M 1523` [3152. Special Array II](https://leetcode.com/problems/special-array-ii) — [C++](Solution/3152.cpp) [Python](Solution/3152.py) · 前綴計數「相鄰同奇偶」的次數，區間內為 0 才合格
- `M 1369` [3179. Find the N-th Value After K Seconds](https://leetcode.com/problems/find-the-n-th-value-after-k-seconds/) — [C++](Solution/3179.cpp) · 原地跑 k 輪前綴和，每步取模
- `M 1556` [3652. Best Time to Buy and Sell Stock using Strategy](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy/) — [Python](Solution/3652.py) · 前綴和 + 前綴利潤，枚舉窗口只算「換掉這段」的差額
- `M` [4071. Minimum Rotations to Dial a Number II](https://leetcode.com/problems/minimum-rotations-to-dial-a-number-ii/) — [C++](Solution/4071.cpp)

#### Matrix / 2D Grid
- `M 1425` [840. Magic Squares in a Grid](https://leetcode.com/problems/magic-squares-in-a-grid/) — [C++](Solution/0840.cpp) · 枚舉所有 3x3 左上角，逐項檢查行列對角線和 + 1~9 不重複
- `M 1678` [885. Spiral Matrix III](https://leetcode.com/problems/spiral-matrix-iii/) — [C++](Solution/0885.cpp) · 步長規律 右1下1 左2上2 右3下3，走出界就不記錄
- `M 1374` [1267. Count Servers that Communicate](https://leetcode.com/problems/count-servers-that-communicate) — [C++](Solution/1267.cpp) · 先統計每行每列的伺服器數，再看各點所在行或列是否 > 1
- `M 1421` [2326. Spiral Matrix IV](https://leetcode.com/problems/spiral-matrix-iv) — [C++](Solution/2326.cpp) · 四方向循環，撞到邊界就縮界並轉向
- `M 1502` [2661. First Completely Painted Row or Column](https://leetcode.com/problems/first-completely-painted-row-or-column) — [C++](Solution/2661.cpp) · hash 存 值→座標，邊塗邊累加行列計數
- `M 1540` [3128. Right Triangles](https://leetcode.com/problems/right-triangles/) — [Python](Solution/3128.py) · 每個 1 當直角頂點，貢獻 (該行1數-1)×(該列1數-1)
- `M 1348` [3195. Find the Minimum Area to Cover All Ones I](https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/) — [C++](Solution/3195.cpp) · 記錄所有 1 的 minR/maxR/minC/maxC 相乘
- `E` [4052. Cyclically Shift Rows and Columns](https://leetcode.com/problems/cyclically-shift-rows-and-columns) — [C++](Solution/4052.cpp) · 先做完整列平移再做整行平移，位置用 `(j-k+n)%n`

#### Sorting-based
- `M` [179. Largest Number](https://leetcode.com/problems/largest-number/) — [C++](Solution/0179.cpp) · 自訂比較子 `a+b > b+a`，注意全 0 要回傳 "0"
- `M` [912. Sort an Array](https://leetcode.com/problems/sort-an-array) — [C++](Solution/0912.cpp) · 手刻 merge sort（檔內另附 quick sort 註解版）
- `E 1355` [1331. Rank Transform of an Array](https://leetcode.com/problems/rank-transform-of-an-array) — [C++](Solution/1331.cpp) · 複製一份排序後掃一次建立 值→排名 的 hash
- `M 1323` [2491. Divide Players Into Teams of Equal Skill](https://leetcode.com/problems/divide-players-into-teams-of-equal-skill) — [C++](Solution/2491.cpp) · 排序後頭尾配對，每組和必須相同
- `M 2047` [2948. Make Lexicographically Smallest Array by Swapping Elements](https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements) — [C++](Solution/2948.cpp) · 排序後依 limit 切成連通群組，群內可任意排 → 由小到大填回原位置
- `M 1604` [3107. Minimum Operations to Make Median of Array Equal to K](https://leetcode.com/problems/minimum-operations-to-make-median-of-array-equal-to-k/) — [C++](Solution/3107.cpp) · 排序後從中位數往 k 的方向推，只調整擋路的元素
- `M 1194` [3194. Minimum Average of Smallest and Largest Elements](https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements/) — [C++](Solution/3194.cpp) · 排序後頭尾配對取最小平均
- `M` [4031. Find All Numbers Disappeared in an Array II](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array-ii) — [Python](Solution/4031.py) · 去重排序後掃相鄰差距，輸出中間的空洞區間

#### Counting / Scanning
- `E 1217` [3105. Longest Strictly Increasing or Strictly Decreasing Subarray](https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/) — [C++](Solution/3105.cpp) · 同時維護遞增與遞減兩個計數器，斷掉就歸 1
- `E 1211` [3168. Minimum Number of Chairs in a Waiting Room](https://leetcode.com/problems/minimum-number-of-chairs-in-a-waiting-room/) — [C++](Solution/3168.cpp) · E 加 L 減，取過程中的最大值
- `E 1163` [3232. Find if Digit Game Can Be Won](https://leetcode.com/problems/find-if-digit-game-can-be-won/) — [C++](Solution/3232.cpp) · 個位數總和與兩位數總和相等才輸
- `E` [4038. Count Integers Appearing in a Single Block](https://leetcode.com/problems/count-integers-appearing-in-a-single-block/) — [Python](Solution/4038.py) · 只在數值改變時計數，最後統計出現次數恰為 1 的
- `E` [4043. Count Rotations With Exactly K Equal Adjacent Pairs](https://leetcode.com/problems/count-rotations-with-exactly-k-equal-adjacent-pairs/) — [Python](Solution/4043.py) · 先算環上相鄰相同的總數，再枚舉切哪條邊
- `M` [4044. Count Good Cyclic Rotations](https://leetcode.com/problems/count-good-cyclic-rotations/) — [Python](Solution/4044.py) · 旋轉一格只有對半位置的兩個元素會換邊，O(1) 更新前後半和
- `E` [4048. Count Values With Equally Spaced Occurrences I](https://leetcode.com/problems/count-values-with-equally-spaced-occurrences-i) — [C++](Solution/4048.cpp) · 值域小，直接存每個值的出現位置再檢查等差
- `M` [4049. Count Values With Equally Spaced Occurrences II](https://leetcode.com/problems/count-values-with-equally-spaced-occurrences-ii/) — [C++](Solution/4049.cpp) · 值域大改存狀態（count/last/diff/valid），一次掃描即時判斷等差

### String

#### Parsing & Building
- `M` [6. Zigzag Conversion](https://leetcode.com/problems/zigzag-conversion/) — [C++](Solution/0006.cpp) [Python](Solution/0006.py) · 週期 `2*numRows-2`，用 `i%週期` 決定落在第幾列
- `M` [8. String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/description/) — [C++](Solution/0008.cpp) · 空白 → 正負號 → 數字；溢位用 `num > (INT_MAX-digit)/10` 先擋
- `H` [273. Integer to English Words](https://leetcode.com/problems/integer-to-english-words/) — [C++](Solution/0273.cpp) · 建 0~20/整十/單位對照表，依 十億/百萬/千/百 遞迴切
- `M` [592. Fraction Addition and Subtraction](https://leetcode.com/problems/fraction-addition-and-subtraction) — [C++](Solution/0592.cpp) · 手動解析正負號與分子分母，每步通分後用 gcd 約分
- `E 1259` [884. Uncommon Words from Two Sentences](https://leetcode.com/problems/uncommon-words-from-two-sentences/) — [C++](Solution/0884.cpp) · 兩句一起丟進同一個詞頻表，取次數為 1 的
- `E 1125` [1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence](https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence) — [C++](Solution/1455.cpp) · 手動切詞並逐字比對前綴，回傳 1-indexed 位置
- `M 1460` [1910. Remove All Occurrences of a Substring](https://leetcode.com/problems/remove-all-occurrences-of-a-substring) — [C++](Solution/1910.cpp) · 反覆 find + erase 直到找不到
- `E 1254` [1945. Sum of Digits of String After Convert](https://leetcode.com/problems/sum-of-digits-of-string-after-convert) — [C++](Solution/1945.cpp) · 字母轉 1~26 先加一次，之後重複 k-1 次數字位數和
- `E 1262` [2490. Circular Sentence](https://leetcode.com/problems/circular-sentence) — [C++](Solution/2490.cpp) · 切詞後檢查每個詞尾 == 下個詞頭，且最後一個要接回第一個
- `E 1282` [2696. Minimum String Length After Removing Substrings](https://leetcode.com/problems/minimum-string-length-after-removing-substrings) — [C++](Solution/2696.cpp) · 掃到 "AB"/"CD" 就 erase 並退回重掃（stack 版更快）
- `M 1311` [3163. String Compression III](https://leetcode.com/problems/string-compression-iii) — [C++](Solution/3163.cpp) · 連續相同字元計數，上限 9 就強制斷開
- `E` [4030. Check ASCII Palindromic](https://leetcode.com/problems/check-ascii-palindromic) — [Python](Solution/4030.py) · 每個字元轉 8-bit，頭尾對應位置需互為 bit 反轉

#### Pattern Matching（前綴 / KMP）
- `E` [14. Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/) — [C++](Solution/0014.cpp) · 以最短字串長度為上限，逐欄比對所有字串
- `H` [214. Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome) — [C++](Solution/0214.cpp) · 組 `s + '#' + reverse(s)` 後求 KMP failure table，末值即最長迴文前綴
- `E 1167` [796. Rotate String](https://leetcode.com/problems/rotate-string) — [C++](Solution/0796.cpp) · 逐次旋轉比對 O(n²)；`(s+s).find(goal)` 更快
- `E 1167` [2185. Counting Words With a Given Prefix](https://leetcode.com/problems/counting-words-with-a-given-prefix) — [C++](Solution/2185.cpp) · 逐字 substr 比對前綴
- `E 1214` [3042. Count Prefix and Suffix Pairs I](https://leetcode.com/problems/count-prefix-and-suffix-pairs-i) — [C++](Solution/3042.cpp) · 暴力配對，同一迴圈內同時檢查前綴與後綴

#### Counting / Frequency
- `M 1288` [1684. Count the Number of Consistent Strings](https://leetcode.com/problems/count-the-number-of-consistent-strings) — [C++](Solution/1684.cpp) · allowed 建 hash，逐字檢查是否全在集合內
- `E 1300` [1790. Check if One String Swap Can Make Strings Equal](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal) — [C++](Solution/1790.cpp) · 差異數必須是 0 或 2，且那兩處要恰好互換
- `M 1479` [2914. Minimum Number of Changes to Make Binary String Beautiful](https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful) — [C++](Solution/2914.cpp) · 兩兩一組，組內不同就改一次
- `M 1445` [3223. Minimum Length of String After Operations](https://leetcode.com/problems/minimum-length-of-string-after-operations) — [C++](Solution/3223.cpp) · 同字元每湊滿 3 個就消掉 2 個
- `M 1451` [3227. Vowels Game in a String](https://leetcode.com/problems/vowels-game-in-a-string/) — [C++](Solution/3227.cpp) · 只要字串含任一母音 Alice 必勝
- `M 1198` [3295. Report Spam Message](https://leetcode.com/problems/report-spam-message) — [C++](Solution/3295.cpp) · 禁字建 hash，命中 2 次即回傳
- `M 2556` [3234. Count the Number of Substrings With Dominant Ones](https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/) — [C++](Solution/3234.cpp) · 前綴計 0/1 個數，用「零數平方」的關係大幅跳過不可能的右端點

### Hash Table
- `E` [1. Two Sum](https://leetcode.com/problems/two-sum/) — [C++](Solution/0001.cpp) · 邊掃邊存，先查 `target-nums[i]` 再插入自己
- `M` [49. Group Anagrams](https://leetcode.com/problems/group-anagrams/) — [C++](Solution/0049.cpp) · 排序後的字串當 key 分組
- `M` [128. Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/) — [C++](Solution/0128.cpp) · 全丟 set，從每個數往兩邊延伸並邊走邊 erase 避免重複展開
- `E` [217. Contains Duplicate](https://leetcode.com/problems/contains-duplicate/) — [C++](Solution/0217.cpp) · set 邊插邊查
- `E` [242. Valid Anagram](https://leetcode.com/problems/valid-anagram/) — [C++](Solution/0242.cpp) [Python](Solution/0242.py) · 一個字串加、另一個減，最後全為 0
- `M 1544` [1233. Remove Sub-Folders from the Filesystem](https://leetcode.com/problems/remove-sub-folders-from-the-filesystem) — [C++](Solution/1233.cpp) · 依路徑長度排序，逐層檢查父路徑是否已存在
- `M 1385` [3185. Count Pairs That Form a Complete Day II](https://leetcode.com/problems/count-pairs-that-form-a-complete-day-ii/) — [C++](Solution/3185.cpp) · 對 24 取模後找互補餘數，邊掃邊累加
- `M` [4039. Sum of Decoded Numbers](https://leetcode.com/problems/sum-of-decoded-numbers/) — [Python](Solution/4039.py) · 個位當切點拆出 x、y，用 `pow(x, y, MOD)` 快速冪

### Linked List
- `M` [2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) — [C++](Solution/0002.cpp) · dummy 頭 + carry，迴圈條件要包含 `carry != 0`
- `M` [19. Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) — [C++](Solution/0019.cpp) [Python](Solution/0019.py) · 快慢指標相隔 n，dummy 頭處理刪頭節點
- `E` [21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) — [C++](Solution/0021.cpp) · dummy 頭逐一接較小者，剩下的整串接上
- `H` [25. Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/) — [C++](Solution/0025.cpp) · 先探測是否還有完整 k 組，再反轉該組並接回前一組尾端
- `M` [86. Partition List](https://leetcode.com/problems/partition-list) — [C++](Solution/0086.cpp) · 拆成兩條 dummy 鏈再接起來，右鏈尾記得斷 nullptr
- `E` [92. Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/) — [C++](Solution/0092.cpp) · 頭插法：把後面的節點一個個搬到 prev 之後
- `E` [141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/) — [C++](Solution/0141.cpp) [Python](Solution/0141.py) · 快慢指標相遇即有環
- `M` [143. Reorder List](https://leetcode.com/problems/reorder-list/) — [C++](Solution/0143.cpp) · 快慢指標找中點 → 反轉後半 → 交錯合併（中點要斷開）
- `M` [147. Insertion Sort List](https://leetcode.com/problems/insertion-sort-list) — [C++](Solution/0147.cpp) · 每個節點從 dummy 往後找插入位置
- `E` [206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) — [C++](Solution/0206.cpp) · 遞迴版（迭代版在註解內）
- `M 1782` [1171. Remove Zero Sum Consecutive Nodes from Linked List](https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list) — [C++](Solution/1171.cpp) · 前綴和相同代表中間那段總和為 0，用 hash 記 前綴和→節點
- `M 1279` [2807. Insert Greatest Common Divisors in Linked List](https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list) — [C++](Solution/2807.cpp) · 相鄰兩節點算 gcd 插入中間，指標一次跳兩格
- `M 1341` [3217. Delete Nodes From Linked List Present in Array](https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array) — [C++](Solution/3217.cpp) · nums 建 hash，重建一條只留未命中節點的鏈

### Stack

#### Parentheses / Basic
- `E` [20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) — [C++](Solution/0020.cpp) · 右括號查表比對棧頂，結束時棧必須為空
- `M 1242` [921. Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid) — [C++](Solution/0921.cpp) · 配對成功就 pop，最後殘留的棧大小即答案
- `E 1311` [1021. Remove Outermost Parentheses](https://leetcode.com/problems/remove-outermost-parentheses/) — [C++](Solution/1021.cpp)
- `M 1688` [1963. Minimum Number of Swaps to Make the String Balanced](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced) — [C++](Solution/1963.cpp) · 掃出「多餘右括號」的最大值，一次交換可消兩個 → `(maxExtra+1)/2`

#### Monotonic Stack
- `E` [496. Next Greater Element I](https://leetcode.com/problems/next-greater-element-i) — [C++](Solution/0496.cpp) · 遞減棧，遇到更大的就把棧內較小者全部結算
- `M` [739. Daily Temperatures](https://leetcode.com/problems/daily-temperatures/) — [C++](Solution/0739.cpp) · 棧存 (index, 溫度)，彈出時用索引差算等待天數
- `M 1607` [962. Maximum Width Ramp](https://leetcode.com/problems/maximum-width-ramp/) — [C++](Solution/0962.cpp) · 先建遞減棧存候選左端點，再從右往左貪心彈出算最大寬度
- `E 1212` [1475. Final Prices With a Special Discount in a Shop](https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop) — [C++](Solution/1475.cpp) · 找下一個 ≤ 自己的價格當折扣（目前是 O(n²) 暴力版，可改單調棧）
- `M` [4054. Count Shadow Pairs I](https://leetcode.com/problems/count-shadow-pairs-i/) — [C++](Solution/4054.cpp) · 遞增棧壓縮相同值，維護 running 總數再扣掉等值的部分

### Queue & Deque
> ⚠️ 尚無題目。建議補：239. Sliding Window Maximum（單調遞減 deque）、1696. Jump Game VI

### Heap / Priority Queue
- `M` [215. Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array) — [C++](Solution/0215.cpp) · 全丟 max heap 彈 k 次（維持大小 k 的 min heap 更省）
- `M` [347. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) — [C++](Solution/0347.cpp) [Python](Solution/0347.py) · 先統計詞頻，再用 (次數, 值) 丟 heap 取前 k
- `M` [703. Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/) — [C++](Solution/0703.cpp) · 維持大小為 k 的 min heap，堆頂就是第 k 大
- `M 1820` [1405. Longest Happy String](https://leetcode.com/problems/longest-happy-string) — [C++](Solution/1405.cpp) · 每次取剩餘最多的字元放 2 個；若與上個相同就改放次多的 1 個
- `M 1695` [1942. The Number of the Smallest Unoccupied Chair](https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair) — [C++](Solution/1942.cpp) · 兩個 heap：空椅編號 + 離場時間，到點先回收再分配
- `M 1680` [2182. Construct String With Repeat Limit](https://leetcode.com/problems/construct-string-with-repeat-limit) — [C++](Solution/2182.cpp) · 貪心取最大字元到上限，卡住就插入次大的 1 個
- `M 1386` [2530. Maximal Score After Applying K Operations](https://leetcode.com/problems/maximal-score-after-applying-k-operations) — [C++](Solution/2530.cpp) · max heap 取頂加分後改成 `ceil(x/3)` 放回
- `M 1772` [3170. Lexicographically Minimum String After Removing Stars](https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/) — [C++](Solution/3170.cpp) · heap 存 (字元, -索引)，遇 `*` 刪掉最小且最靠右的
- `E 1177` [3264. Final Array State After K Multiplication Operations I](https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i) — [C++](Solution/3264.cpp) · min heap 存 (值, 原索引)，操作 k 次後依索引回填
- `E 1457` [3318. Find X-Sum of All K-Long Subarrays I](https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i) — [C++](Solution/3318.cpp) · 滑動視窗維護詞頻，每個視窗用 heap 取前 x 高頻

### Trie
- `M` [208. Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/) — [C++](Solution/0208.cpp) · 每節點一個 char→node 的 map，加 isLeaf 區分完整單字
- `M` [211. Design Add and Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure/) — [C++](Solution/0211.cpp) · `.` 時把所有子節點一起推進候選集（檔內另附長度分桶版）
- `M` [386. Lexicographical Numbers](https://leetcode.com/problems/lexicographical-numbers) — [C++](Solution/0386.cpp) · 把數字看成 10 元 trie，對它做 preorder DFS
- `M` [421. Maximum XOR of Two Numbers in an Array](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array) — [C++](Solution/0421.cpp) · 二元 trie 存 32 bit，查詢時貪心往相反 bit 走
- `H 1725` [2416. Sum of Prefix Scores of Strings](https://leetcode.com/problems/sum-of-prefix-scores-of-strings) — [C++](Solution/2416.cpp) · 插入時每個節點累加經過次數，查詢時沿路加總
- `M 1688` [3043. Find the Length of the Longest Common Prefix](https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix) — [C++](Solution/3043.cpp) · arr1 全部轉字串建 trie，arr2 逐一查最長可走深度

### Union-Find
- `M` [261. Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree) — [Python](Solution/0261.py) · 邊數必須是 n-1 且無環且連通（檔內同時有 BFS 與 union-find 兩版）
- `M` [684. Redundant Connection](https://leetcode.com/problems/redundant-connection/) — [C++](Solution/0684.cpp) · 路徑壓縮 + 按秩合併，第一條讓兩端已同根的邊就是答案

### Segment Tree / BIT
> ⚠️ 尚無題目。建議補：307. Range Sum Query - Mutable、315. Count of Smaller Numbers After Self

---

## B. 掃描技巧

### Two Pointers

#### Opposite Direction（對撞）
- `M` [11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/) — [C++](Solution/0011.cpp) [Python](Solution/0011.py) · 較矮的那邊往內收，因為只有它限制了面積
- `M` [15. 3Sum](https://leetcode.com/problems/3sum/) — [C++](Solution/0015.cpp) [Python](Solution/0015.py) · 排序後固定第一個數，剩下對撞找兩數和；三處都要跳過重複
- `M` [611. Valid Triangle Number](https://leetcode.com/problems/valid-triangle-number/) — [C++](Solution/0611.cpp) · 排序後固定最大邊，左右對撞；成立時一次算進 `right-left` 組

#### Same Direction（同向）
- `M 1693` [2337. Move Pieces to Obtain a String](https://leetcode.com/problems/move-pieces-to-obtain-a-string) — [C++](Solution/2337.cpp) · 跳過 `_` 逐一配對，L 只能左移、R 只能右移
- `M 1414` [2825. Make String a Subsequence Using Cyclic Increments](https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments) — [C++](Solution/2825.cpp) · 子序列比對，每字元允許「原字元或 +1（z→a）」
- `M 1593` [3228. Maximum Number of Operations to Move Ones to the End](https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/) — [C++](Solution/3228.cpp) · 累積 1 的個數，每遇到「一段 0 之後的 1」就結算一次

> 快慢指標（Fast & Slow）的題目放在 [Linked List](#linked-list)：19、109、141、143

### Sliding Window

#### Fixed Size
- `E` [643. Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/) — [Python](Solution/0643.py) · 固定窗口滾動和，離開窗口的元素減掉
- `M 1748` [1297. Maximum Number of Occurrences of a Substring](https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/) — [Python](Solution/1297.py) · 只需檢查 minSize（更長的必然包含更短的），窗口內維護相異字元數
- `M 1317` [1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold](https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold) — [Python](Solution/1343.py) · 固定窗口和與 `k*threshold` 比較
- `M 1263` [1456. Maximum Number of Vowels in a Substring of Given Length](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/) — [Python](Solution/1456.py) · 窗口內母音計數，達到 k 可提前回傳
- `M 1358` [2090. K Radius Subarray Averages](https://leetcode.com/problems/k-radius-subarray-averages) — [Python](Solution/2090.py) · 前綴和取 `2k+1` 長度區間，邊界不足補 -1
- `M 1748` [2134. Minimum Swaps to Group All 1's Together II](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/) — [C++](Solution/2134.cpp) · 窗口大小 = 1 的總數，找窗口內 0 最少的位置；環狀用取模
- `M 1545` [2841. Maximum Sum of Almost Unique Subarray](https://leetcode.com/problems/maximum-sum-of-almost-unique-subarray) — [Python](Solution/2841.py) · 窗口同時維護總和與相異元素數，相異數 ≥ m 才更新答案

#### Variable Size
- `M` [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) — [C++](Solution/0003.cpp) · 記錄每字元最後出現位置，左界只能往右不能倒退
- `H` [76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/description/) — [C++](Solution/0076.cpp) · 用「已滿足數量的相異字元數」判斷窗口是否合格，合格就收縮左界
- `M` [424. Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/) — [C++](Solution/0424.cpp) · 窗口長度 − 最高頻字元數 > k 就收縮
- `M 1638` [2779. Maximum Beauty of an Array After Applying Operation](https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation) — [C++](Solution/2779.cpp) · 排序後找最長區間使 `max-min ≤ 2k`
- `M 1847` [3297. Count Substrings That Can Be Rearranged to Contain a String I](https://leetcode.com/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-i) — [C++](Solution/3297.cpp) · 窗口合格時右端可任意延伸 → 一次加 `n-right`
- `M` [4032. Longest Subarray With at Most K Distinct Prime Factors](https://leetcode.com/problems/longest-subarray-with-at-most-k-distinct-prime-factors/) — [Python](Solution/4032.py) · 先預處理每個數的質因數，窗口維護相異質因數計數

### Binary Search

#### On Sorted Array
- `M` [33. Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) — [C++](Solution/0033.cpp) [Python](Solution/0033.py) · 每次判斷哪一半是有序的，再看 target 是否落在那半
- `M` [34. Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array) — [Python](Solution/0034.py) · `lower_bound(target)` 與 `lower_bound(target+1)-1`
- `E` [35. Search Insert Position](https://leetcode.com/problems/search-insert-position/) — [Python](Solution/0035.py) · 標準 lower_bound 模板
- `M` [153. Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) — [C++](Solution/0153.cpp) · 未旋轉可直接回傳；否則往無序的那半收斂
- `E` [704. Binary Search](https://leetcode.com/problems/binary-search/) — [Python](Solution/0704.py) · 基本模板
- `E` [744. Find Smallest Letter Greater Than Target](https://leetcode.com/problems/find-smallest-letter-greater-than-target/) — [Python](Solution/0744.py) · upper_bound，越界要繞回第一個字母
- `M 1355` [1894. Find the Student that Will Replace the Chalk](https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk) — [C++](Solution/1894.cpp) · k 先對總和取模，再在前綴和上二分
- `M 1724` [2070. Most Beautiful Item for Each Query](https://leetcode.com/problems/most-beautiful-item-for-each-query) — [C++](Solution/2070.cpp) · 依價格排序後建前綴最大美值，查詢時二分找最後一個 ≤ query 的位置
- `M 1702` [2080. Range Frequency Queries](https://leetcode.com/problems/range-frequency-queries) — [Python](Solution/2080.py) · 值→索引清單，查詢時在清單上二分算區間內個數
- `M 1720` [2563. Count the Number of Fair Pairs](https://leetcode.com/problems/count-the-number-of-fair-pairs) — [C++](Solution/2563.cpp) · 排序後對每個 i 二分出合法 j 的上下界

#### On Answer（二分答案）
- `M 1505` [2981. Find Longest Special Substring That Occurs Thrice I](https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i) — [C++](Solution/2981.cpp) · 對「長度」二分，每次線性驗證是否存在出現 3 次的同字元子字串
- `M 2153` [2812. Find the Safest Path in a Grid](https://leetcode.com/problems/find-the-safest-path-in-a-grid) — [C++](Solution/2812.cpp) · 多源 BFS 算出各格到小偷的距離，再對「安全係數」二分 + BFS 驗證
- `M 1694` [3296. Minimum Number of Seconds to Make Mountain Height Zero](https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero) — [C++](Solution/3296.cpp) · 對「時間」二分，用等差級數反解每個工人能挖多少

### Interval

#### Merge / Insert
- `M` [56. Merge Intervals](https://leetcode.com/problems/merge-intervals/) — [C++](Solution/0056.cpp) · 排序後原地合併，重疊就把結尾取 max
- `M` [57. Insert Interval](https://leetcode.com/problems/insert-interval/) — [C++](Solution/0057.cpp) · 分成「完全在左」「重疊」「完全在右」三段處理
- `M` [435. Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/description/) — [C++](Solution/0435.cpp) · 重疊時貪心保留結尾較早的那個
- `M 1483` [3169. Count Days Without Meetings](https://leetcode.com/problems/count-days-without-meetings) — [C++](Solution/3169.cpp) · 排序後累加相鄰會議之間的空檔，含頭尾

#### 區間分組 / 預約
- `E` [252. Meeting Rooms](https://leetcode.com/problems/meeting-rooms/) — [C++](Solution/0252.cpp) · 排序後檢查是否有任一開始時間早於前一個結束
- `M` [253. Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/) — [C++](Solution/0253.cpp) · min heap 存各房間結束時間，可重用就 pop
- `M` [729. My Calendar I](https://leetcode.com/problems/my-calendar-i) — [C++](Solution/0729.cpp) · 線性掃已預約區間檢查重疊（`start < e && end > s`）
- `M` [731. My Calendar II](https://leetcode.com/problems/my-calendar-ii) — [C++](Solution/0731.cpp) · 另存一份「已重疊兩次」的區間，撞到它才拒絕
- `M 1713` [2406. Divide Intervals Into Minimum Number of Groups](https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups) — [C++](Solution/2406.cpp) · 同 253：min heap 存結尾，無法重用就開新組
- `M` [4057. Number of Intersecting Interval Pairs II](https://leetcode.com/problems/number-of-intersecting-interval-pairs-ii/) — [C++](Solution/4057.cpp) · 依起點排序，heap 淘汰已結束的區間，堆大小即與目前區間相交的數量

---

## C. 演算法範式

### Greedy
- `M` [55. Jump Game](https://leetcode.com/problems/jump-game/) — [C++](Solution/0055.cpp) · 維護能到的最遠位置，走到超過它就失敗（檔內另附 DP 版）
- `E` [121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) — [C++](Solution/0121.cpp) · 記錄目前最低買點，每步更新最大差值
- `M` [624. Maximum Distance in Arrays](https://leetcode.com/problems/maximum-distance-in-arrays) — [C++](Solution/0624.cpp) · 邊掃邊拿「前面的極值」配「當前的極值」，自然避開同陣列配對
- `M` [670. Maximum Swap](https://leetcode.com/problems/maximum-swap) — [C++](Solution/0670.cpp) · 記錄每個數字最後出現位置，從左找第一個能換到更大數的位置
- `E 1285` [860. Lemonade Change](https://leetcode.com/problems/lemonade-change) — [C++](Solution/0860.cpp) · 找 15 元時優先用 10+5，留下較靈活的 5 元
- `M 1384` [2091. Removing Minimum and Maximum From Array](https://leetcode.com/problems/removing-minimum-and-maximum-from-array) — [Python](Solution/2091.py) · 找出 min/max 位置後枚舉四種「從兩端刪」的組合取最小
- `M 1839` [2311. Longest Binary Subsequence Less Than or Equal to K](https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/) — [C++](Solution/2311.cpp) · 0 全都要，1 從最高位開始丟掉直到值 ≤ k
- `M 1779` [2601. Prime Subtraction Operation](https://leetcode.com/problems/prime-subtraction-operation) — [C++](Solution/2601.cpp) · 每個數減去「能減的最大質數」讓它盡量小，才給後面留空間
- `M 1422` [2938. Separate Black and White Balls](https://leetcode.com/problems/separate-black-and-white-balls) — [C++](Solution/2938.cpp) · 累積已遇到的 1 的個數，每遇到一個 0 就加上該數
- `H 2066` [3229. Minimum Operations to Make Array Equal to Target](https://leetcode.com/problems/minimum-operations-to-make-array-equal-to-target/) — [C++](Solution/3229.cpp) · 看差分序列，同號可延續、變號要重新計費
- `M` [4045. Count Robot Groups](https://leetcode.com/problems/count-robot-groups/) — [Python](Solution/4045.py) · 從右往左掃，間距超過 distance 且速度追不上就開新組

### Dynamic Programming

#### Linear（1D）
- `E` [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) — [C++](Solution/0053.cpp) · Kadane：`dp[i] = max(nums[i], nums[i]+dp[i-1])`
- `E` [70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) — [C++](Solution/0070.cpp) [Python](Solution/0070.py) · 費氏數列
- `M` [91. Decode Ways](https://leetcode.com/problems/decode-ways/) — [C++](Solution/0091.cpp) · 分「單獨一位」與「和前一位組成 10~26」，`'0'` 要特判
- `M` [139. Word Break](https://leetcode.com/problems/word-break/) — [C++](Solution/0139.cpp) [Python](Solution/0139.py) · `dp[i]` = 前 i 個字可切完，枚舉切點查字典
- `M` [152. Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) — [C++](Solution/0152.cpp) [Python](Solution/0152.py) · 正反各掃一次累乘，遇 0 重置（避開負號翻轉問題）
- `M` [198. House Robber](https://leetcode.com/problems/house-robber/) — [C++](Solution/0198.cpp) [Python](Solution/0198.py) · `dp[i] = max(dp[i-1], dp[i-2]+nums[i])`
- `M` [213. House Robber II](https://leetcode.com/problems/house-robber-ii/) — [C++](Solution/0213.cpp) · 環狀 → 拆成「不搶最後一間」與「不搶第一間」取 max
- `M 1785` [1911. Maximum Alternating Subsequence Sum](https://leetcode.com/problems/maximum-alternating-subsequence-sum/) — [C++](Solution/1911.cpp)

- `M 1840` [3186. Maximum Total Damage With Spell Casting](https://leetcode.com/problems/maximum-total-damage-with-spell-casting/) — [C++](Solution/3186.cpp) · 依傷害值去重排序，轉移時只能接 `< 當前-2` 的最佳值
- `M 1846` [3196. Maximize Total Cost of Alternating Subarrays](https://leetcode.com/problems/maximize-total-cost-of-alternating-subarrays/) — [C++](Solution/3196.cpp) · 每個位置選「自己單獨一組」或「和前一個湊成一組」
- `M` [4050. Minimum Days to Score Exactly N Points](https://leetcode.com/problems/minimum-days-to-score-exactly-n-points/) — [C++](Solution/4050.cpp) · 枚舉連續天數 L 對應的三角數，`dp[i] = min(dp[i-T(L)] + 1 + L)`

#### Grid（2D）
- `M` [62. Unique Paths](https://leetcode.com/problems/unique-paths/) — [C++](Solution/0062.cpp) [Python](Solution/0062.py) · `dp[i][j] = dp[i-1][j] + dp[i][j-1]`，首行首列填 1
- `M 1613` [1277. Count Square Submatrices with All Ones](https://leetcode.com/problems/count-square-submatrices-with-all-ones) — [C++](Solution/1277.cpp) · `dp[i][j]` = 以此為右下角的最大正方形邊長 = 左/上/左上三者 min + 1
- `M 1956` [1463. Cherry Pickup II](https://leetcode.com/problems/cherry-pickup-ii/) — [C++](Solution/1463.cpp) · 兩個機器人同步逐列下移，狀態 `dp[row][y1][y2]`，同格只算一次
- `M 2105` [1937. Maximum Number of Points with Cost](https://leetcode.com/problems/maximum-number-of-points-with-cost/) — [C++](Solution/1937.cpp) · 拆絕對值為左右兩次掃描，`left[c] = max(left[c-1]-1, dp[r-1][c])`
- `M 1625` [2684. Maximum Number of Moves in a Grid](https://leetcode.com/problems/maximum-number-of-moves-in-a-grid) — [C++](Solution/2684.cpp) · 由右往左遞推三個方向的最大步數（檔內另附 BFS 版）

#### Knapsack
- `M` [322. Coin Change](https://leetcode.com/problems/coin-change/) — [C++](Solution/0322.cpp) · 完全背包，外層硬幣內層金額，`dp[a] = min(dp[a], dp[a-coin]+1)`
- `M` [377. Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/) — [C++](Solution/0377.cpp) · 要算排列數 → 外層目標值內層硬幣（與 322 的迴圈順序相反）
- `M 1848` [3180. Maximum Total Reward Using Operations I](https://leetcode.com/problems/maximum-total-reward-using-operations-i) — [C++](Solution/3180.cpp) · 排序後做可達性 DP，只能從 `j < num` 的狀態轉移
- `M` [4040. Minimum Operations to Form Subset Sum I](https://leetcode.com/problems/minimum-operations-to-form-subset-sum-i/) — [Python](Solution/4040.py) · 先算每個數翻倍/減半到各值的成本，再做完全背包

#### Subsequence（LIS / LCS）
- `M` [300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) — [C++](Solution/0300.cpp) · O(n²) 雙迴圈版 + O(n log n) 貪心維護遞增尾陣列版

#### Interval / Palindrome
- `M` [647. Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/) — [C++](Solution/0647.cpp) · `res[i][j] = s[i]==s[j] && res[i+1][j-1]`，由內而外遞推
- `H 2013` [2472. Maximum Number of Non-overlapping Palindrome Substrings](https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/) — [C++](Solution/2472.cpp) · 先預處理迴文表，再做線性 DP 挑不重疊且長度 ≥ k 的

#### Bitmask DP
> ⚠️ 尚無題目。建議補：847. Shortest Path Visiting All Nodes、698. Partition to K Equal Sum Subsets

#### Digit DP
> ⚠️ 尚無題目。建議補：902. Numbers At Most N Given Digit Set、2376. Count Special Integers

### Backtracking
- `M` [22. Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) — [C++](Solution/0022.cpp) · 排序後同層跳過重複元素，超過 target 提前 break
- `M` [40. Combination Sum II](https://leetcode.com/problems/combination-sum-ii/) — [C++](Solution/0040.cpp) · 排序後同層跳過重複元素，超過 target 提前 break
- `M` [131. Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/) — [C++](Solution/0131.cpp) · 枚舉第一段切點，是迴文才遞迴切剩下的
- `M` [241. Different Ways to Add Parentheses](https://leetcode.com/problems/different-ways-to-add-parentheses/) — [C++](Solution/0241.cpp) · 以每個運算子為中心分治，左右結果做笛卡兒積；用 memo 快取
- `M` [494. Target Sum](https://leetcode.com/problems/target-sum) — [C++](Solution/0494.cpp) · 每個數選 + 或 −，全枚舉（可轉成子集和 DP 優化）
- `M 1739` [1593. Split a String Into the Max Number of Unique Substrings](https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings) — [C++](Solution/1593.cpp) · set 記已用過的片段，回溯時要 erase
- `M 1567` [2044. Count Number of Maximum Bitwise-OR Subsets](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/) — [C++](Solution/2044.cpp) · 先求全體 OR 的上限，再枚舉子集數達標的個數

### Simulation
- `M 1846` [874. Walking Robot Simulation](https://leetcode.com/problems/walking-robot-simulation/) — [C++](Solution/0874.cpp) · 障礙物按 x/y 分別存 set，用 upper_bound 一次算出能走到哪裡
- `M 1479` [1545. Find Kth Bit in Nth Binary String](https://leetcode.com/problems/find-kth-bit-in-nth-binary-string) — [C++](Solution/1545.cpp) · 直接依規則 `S + "1" + invert(reverse(S))` 造出字串

---

## D. 樹與圖

### Tree

#### Traversal
- `E` [100. Same Tree](https://leetcode.com/problems/same-tree/) — [C++](Solution/0100.cpp) · 同步遞迴比對，先處理空節點的四種組合
- `E` [101. Symmetric Tree](https://leetcode.com/problems/symmetric-tree/) — [C++](Solution/0101.cpp) · 比對「左的左 vs 右的右」與「左的右 vs 右的左」
- `M` [102. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) — [C++](Solution/0102.cpp) · BFS，每輪先記下 `q.size()` 當作本層節點數
- `E` [104. Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) — [C++](Solution/0104.cpp) · 後序遞迴取左右深度 max + 1
- `E` [145. Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal) — [C++](Solution/0145.cpp) · 左 → 右 → 根
- `E` [226. Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/description/) — [C++](Solution/0226.cpp) [Python](Solution/0226.py) · 交換左右子樹後遞迴
- `E` [572. Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/) — [C++](Solution/0572.cpp) · 每個節點都試著和 subRoot 做一次完整比對
- `E` [590. N-ary Tree Postorder Traversal](https://leetcode.com/problems/n-ary-tree-postorder-traversal) — [C++](Solution/0590.cpp) · 走完所有 children 再記錄自己
- `M 1477` [951. Flip Equivalent Binary Trees](https://leetcode.com/problems/flip-equivalent-binary-trees) — [C++](Solution/0951.cpp) · 每層試「不翻」與「翻」兩種配對，任一成立即可
- `M 1649` [1367. Linked List in Binary Tree](https://leetcode.com/problems/linked-list-in-binary-tree/) — [C++](Solution/1367.cpp) · 雙層遞迴：外層換起點，內層沿左或右往下比對
- `M` [2583. Kth Largest Sum in a Binary Tree](https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/) — [C++](Solution/2583.cpp) · 遞迴時帶層數累加各層和，排序後取第 k 大
- `M 1676` [2641. Cousins in Binary Tree II](https://leetcode.com/problems/cousins-in-binary-tree-ii) — [C++](Solution/2641.cpp) · BFS 時佇列一併帶著「兄弟組的和」，新值 = 本層總和 − 該組和

#### BST
- `M` [98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/description/) — [C++](Solution/0098.cpp) [Python](Solution/0098.py) · 往下傳遞上下界，不能只比父節點
- `M` [230. Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/) — [C++](Solution/0230.cpp) · 中序走訪即為遞增序列，取第 k-1 個
- `M` [235. Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) — [C++](Solution/0235.cpp) · 兩點分別落在左右兩側（或等於自己）時，當前節點就是 LCA

#### Construction
- `M` [105. Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/) — [C++](Solution/0105.cpp) · preorder 首元素為根，在 inorder 中切出左右子樹
- `M` [109. Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/) — [C++](Solution/0109.cpp) · 快慢指標找中點當根，左半要先斷開再遞迴

#### Tree DP
- `M 1472` [2265. Count Nodes Equal to Average of Subtree](https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/) — [C++](Solution/2265.cpp) · 後序回傳 (子樹和, 節點數)，順路統計
- `H 2298` [2458. Height of Binary Tree After Subtree Removal Queries](https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries) — [C++](Solution/2458.cpp) · 移除某節點後的高度取決於兄弟子樹，再往下傳遞全域最大值
- `M 1603` [3319. K-th Largest Perfect Subtree Size in Binary Tree](https://leetcode.com/problems/k-th-largest-perfect-subtree-size-in-binary-tree) — [C++](Solution/3319.cpp) · 後序回傳 (高度, 完美子樹大小)，左右等高才是完美

### Graph

#### Traversal（DFS / BFS）
- `M` [133. Clone Graph](https://leetcode.com/problems/clone-graph/description/) — [C++](Solution/0133.cpp) [Python](Solution/0133.py) · DFS + 原節點→複本 的 hash，必須先登記自己再遞迴鄰居（否則環會無限遞迴）
- `M` [200. Number of Islands](https://leetcode.com/problems/number-of-islands/) — [C++](Solution/0200.cpp) [Python](Solution/0200.py) · 遇到 '1' 就計數並用 DFS 把整座島沉掉
- `M` [417. Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow/) — [C++](Solution/0417.cpp) [Python](Solution/0417.py) · 從兩片海的邊界反向往高處 BFS，取兩張表的交集
- `M 1782` [1765. Map of Highest Peak](https://leetcode.com/problems/map-of-highest-peak) — [C++](Solution/1765.cpp) · 多源 BFS：所有水域同時入隊，層數即高度

#### Topological Sort
- `M` [207. Course Schedule](https://leetcode.com/problems/course-schedule/) — [C++](Solution/0207.cpp) · 入度為 0 的先入隊，能走完所有節點代表無環
- `H 2449` [2127. Maximum Employees to Be Invited to a Meeting](https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting) — [C++](Solution/2127.cpp) · 拓撲排序剝掉鏈找出環；答案取「最大環」與「所有雙人環 + 兩側鏈」的較大者

#### Shortest Path — Dijkstra
- `M 1846` [1514. Path with Maximum Probability](https://leetcode.com/problems/path-with-maximum-probability) — [C++](Solution/1514.cpp) · 把「最短距離」換成「最大機率」，改用 max heap 且鬆弛改成乘法
- `M 1567` [3243. Shortest Distance After Road Addition Queries I](https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i) — [C++](Solution/3243.cpp) · 每加一條邊就重跑一次 Dijkstra（檔內另附 BFS 版）
- `H 2270` [3244. Shortest Distance After Road Addition Queries II](https://leetcode.com/problems/shortest-distance-after-road-addition-queries-ii) — [C++](Solution/3244.cpp) · 題目保證區間不交錯 → 用 set 直接刪掉被捷徑跳過的節點，答案即 `size-1`

#### Shortest Path — Floyd-Warshall
- `M 1854` [1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance) — [C++](Solution/1334.cpp) · 三層迴圈求全點對最短路（檔內另附逐點 Dijkstra 版）

#### Minimum Spanning Tree
> ⚠️ 尚無題目。建議補：1584. Min Cost to Connect All Points、1135. Connecting Cities With Minimum Cost

---

## E. 其他

### Bit Manipulation
- `E` [190. Reverse Bits](https://leetcode.com/problems/reverse-bits) — [C++](Solution/0190.cpp) · 逐位取出後左移堆疊 32 次
- `E` [268. Missing Number](https://leetcode.com/problems/missing-number/) — [C++](Solution/0268.cpp) · 標記命中表找空位（XOR 或等差和更省空間）
- `M` [371. Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/) — [C++](Solution/0371.cpp) · `a^b` 是不進位加法，`(a&b)<<1` 是進位，反覆到進位為 0
- `E` [476. Number Complement](https://leetcode.com/problems/number-complement) — [C++](Solution/0476.cpp) · 從最高位找到第一個 1 之後，每位都 XOR 翻轉
- `M 1459` [1310. XOR Queries of a Subarray](https://leetcode.com/problems/xor-queries-of-a-subarray) — [C++](Solution/1310.cpp) [Python](Solution/1310.py) · 前綴 XOR，區間值 = `prefix[r] ^ prefix[l-1]`
- `E 1282` [2220. Minimum Bit Flips to Convert Number](https://leetcode.com/problems/minimum-bit-flips-to-convert-number) — [C++](Solution/2220.cpp) · 數 `start ^ goal` 有幾個 1
- `E 1642` [2275. Largest Combination With Bitwise AND Greater Than Zero](https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero) — [C++](Solution/2275.cpp) · 逐位統計有幾個數該位為 1，取最大值
- `M 1495` [2419. Longest Subarray With Maximum Bitwise AND](https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and) — [C++](Solution/2419.cpp) · AND 不會讓值變大 → 找全域最大值的最長連續段
- `M 1622` [2425. Bitwise XOR of All Pairings](https://leetcode.com/problems/bitwise-xor-of-all-pairings) — [C++](Solution/2425.cpp) · 各元素出現次數 = 對方陣列長度，只有奇數長度那邊要 XOR
- `M 1532` [2429. Minimize XOR](https://leetcode.com/problems/minimize-xor) — [C++](Solution/2429.cpp) · 使 1 的個數與 num2 相同：多了就從低位拿掉，少了就從低位補上
- `M 1496` [3011. Find if Array Can Be Sorted](https://leetcode.com/problems/find-if-array-can-be-sorted) — [C++](Solution/3011.cpp) · 相同 popcount 的才能互換 → 依 popcount 分段，前段 max ≤ 後段 min
- `E 1247` [3226. Number of Bit Changes to Make Two Integers Equal](https://leetcode.com/problems/number-of-bit-changes-to-make-two-integers-equal/) — [C++](Solution/3226.cpp) · 只能把 1 變 0；出現「n 為 0 而 k 為 1」就回傳 -1

### Math

#### Number Theory
- `M` [7. Reverse Integer](https://leetcode.com/problems/reverse-integer/) — [C++](Solution/0007.cpp) · 逐位取出重組，每步先檢查是否會超過 `INT_MAX/10`
- `M` [539. Minimum Time Difference](https://leetcode.com/problems/minimum-time-difference/) — [C++](Solution/0539.cpp) · 全轉成分鐘排序，別忘了跨午夜的 `1440 - (max-min)`
- `M` [650. 2 Keys Keyboard](https://leetcode.com/problems/2-keys-keyboard/) — [C++](Solution/0650.cpp) · 答案是 n 的所有質因數之和
- `M 1787` [1497. Check If Array Pairs Are Divisible by k](https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k) — [C++](Solution/1497.cpp) · 統計餘數頻率（負數要先正規化），餘數 i 與 k−i 必須等量
- `M 2038` [1590. Make Sum Divisible by P](https://leetcode.com/problems/make-sum-divisible-by-p) — [C++](Solution/1590.cpp) · 求最短子陣列其前綴模等於目標餘數，用 hash 存 模→最近索引
- `M 1444` [2028. Find Missing Observations](https://leetcode.com/problems/find-missing-observations) — [C++](Solution/2028.cpp) · 先算缺少的總點數，平均分配後把餘數逐一補到不超過 6
- `M 1518` [3334. Find the Maximum Factor Score of Array](https://leetcode.com/problems/find-the-maximum-factor-score-of-array) — [C++](Solution/3334.cpp) · 前後綴各存 GCD 與 LCM，枚舉刪掉哪一個元素

#### Prime
- `M 1509` [3233. Non-Special Prime Count](https://leetcode.com/problems/non-special-prime-count/) — [C++](Solution/3233.cpp) · special 數必為質數平方 → 只需枚舉 `p*p ≤ r` 的質數

### Design
- `M` [146. LRU Cache](https://leetcode.com/problems/lru-cache/) — [C++](Solution/0146.cpp) · `list` + `hash(key→iterator)`，get 時用 `splice` O(1) 搬到最前
- `H` [432. All O`one Data Structure](https://leetcode.com/problems/all-oone-data-structure) — [C++](Solution/0432.cpp) · 依計數值排序的雙向鏈，每節點掛同值 key 的 set，增減時只移動一格
- `M` [641. Design Circular Deque](https://leetcode.com/problems/design-circular-deque) — [C++](Solution/0641.cpp) · vector 直接模擬（正規做法是環形陣列 + 頭尾指標）
- `M 1285` [1381. Design a Stack With Increment Operation](https://leetcode.com/problems/design-a-stack-with-increment-operation) — [C++](Solution/1381.cpp) · vector 當底層，increment 直接改前 k 個（可用延遲標記優化）
- `M 1453` [1472. Design Browser History](https://leetcode.com/problems/design-browser-history/) — [C++](Solution/1453.cpp)
- `E 1334` [3242. Design Neighbor Sum Service](https://leetcode.com/problems/design-neighbor-sum-service/) — [C++](Solution/3242.cpp) · 建 值→座標 的 hash，查詢時套四個方向偏移量

### SQL
→ [Solution_SQL/README.md](Solution_SQL/README.md)

---

## Templates（常用實作）

複製貼上就能用的演算法與資料結構模板。

#### 搜尋與排序
- Binary Search — [C++](Useful_functions/binSearch.cpp)

#### 資料結構
- Max Heap — [C++](Useful_functions/maxHeap.cpp)
- Disjoint Set — [C++](Useful_functions/DisJointSet.cpp)

#### 字串演算法
- Rabin-Karp — [C++](Useful_functions/rabinKarp.cpp)
- String Reduction — [C++](Useful_functions/stringReduction.cpp)
- Caesar Cipher — [C++](Useful_functions/CeasarCipher.cpp)

#### 面試題
- Reverse C-string（Qualcomm）— [C++](Useful_functions/reverseCstring.cpp)
