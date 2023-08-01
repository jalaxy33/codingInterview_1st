class Solution:
    # 动态规划+哈希表
    def lengthOfLongestSubstring(self, s: str) -> int:
        dic = {}
        i, result = -1, 0
        for j in range(len(s)):
            if s[j] in dic:  # python判断字典是否有键的方式
                i = max(i, dic[s[j]])
            dic[s[j]] = j
            result = max(result, j - i)
        return result


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, s: str, expected: int):
        text = testName + " for " if testName else ""
        text += "input " + s

        result = self.solution.lengthOfLongestSubstring(s)
        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def runTest(self):
        self.checkResult("Test1", "abcacfrar", 4)
        self.checkResult("Test2", "acfrarabc", 4)
        self.checkResult("Test3", "arabcacfr", 4)
        self.checkResult("Test4", "aaaa", 1)
        self.checkResult("Test5", "abcdefg", 7)
        self.checkResult("Test6", "aaabbbccc", 2)
        self.checkResult("Test7", "abcdcba", 4)
        self.checkResult("Test8", "abcdaef", 6)
        self.checkResult("Test9", "a", 1)
        self.checkResult("Test10", "", 0)


if __name__ == "__main__":
    test = Test()
    test.runTest()
