class Solution:
    def convert(self, s: str, numRows: int) -> str:
        n = len(s)
        tmp = ["" for _ in range(numRows)]
        if numRows == 1:
            return s

        repeat_num = (numRows - 1) * 2
        for i in range(len(s)):
            if i % repeat_num < numRows:
                tmp[i % repeat_num] += s[i]
            else:
                tmp[repeat_num - (i % repeat_num)] += s[i]
        
        result = ""
        for tmp_str in tmp:
            print(tmp_str)
            result += tmp_str
        
        return result