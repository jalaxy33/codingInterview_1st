class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s) + 1, len(p) + 1
        dp = [[False] * n for _ in range(m)]
        dp[0][0] = True
        # 初始化首行，只看偶数列
        for j in range(2, n, 2):
            dp[0][j] = dp[0][j - 2] and p[j - 1] == "*"
        # 状态转移
        for i in range(1, m):
            for j in range(1, n):
                condition = False
                # 根据p的j-1位是否为'*'分类讨论
                if p[j - 1] == "*":
                    # 在以下情况condition为true
                    # 1) s[:i)==p[:j-2), p的第i-1位重复0次
                    condition = dp[i][j - 2]
                    # 2) s[:i-1)==p[:j) 且 (p[j-2]字符再出现一次，或为'.')
                    condition = condition or (
                        dp[i - 1][j] and (p[j - 2] == s[i - 1] or p[j - 2] == ".")
                    )
                else:
                    # 在以下情况condition为true
                    # s[:i-1)==p[:j-1) 且
                    # (s的第i-1和p的第j-1个字符相同，或p[j-1]为'.')
                    condition = dp[i - 1][j - 1]
                    condition = condition and (s[i - 1] == p[j - 1] or p[j - 1] == ".")
                dp[i][j] = condition
        return dp[m - 1][n - 1]


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, s: str, p: str, expected: bool):
        text = testName if testName else ""
        if self.solution.isMatch(s, p) == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def runTest(self):
        self.checkResult("Test01", "", "", True)
        self.checkResult("Test02", "", ".*", True)
        self.checkResult("Test03", "", ".", False)
        self.checkResult("Test04", "", "c*", True)
        self.checkResult("Test05", "a", ".*", True)
        self.checkResult("Test06", "a", "a.", False)
        self.checkResult("Test07", "a", "", False)
        self.checkResult("Test08", "a", ".", True)
        self.checkResult("Test09", "a", "ab*", True)
        self.checkResult("Test10", "a", "ab*a", False)
        self.checkResult("Test11", "aa", "aa", True)
        self.checkResult("Test12", "aa", "a*", True)
        self.checkResult("Test13", "aa", ".*", True)
        self.checkResult("Test14", "aa", ".", False)
        self.checkResult("Test15", "ab", ".*", True)
        self.checkResult("Test16", "ab", ".*", True)
        self.checkResult("Test17", "aaa", "aa*", True)
        self.checkResult("Test18", "aaa", "aa.a", False)
        self.checkResult("Test19", "aaa", "a.a", True)
        self.checkResult("Test20", "aaa", ".a", False)
        self.checkResult("Test21", "aaa", "a*a", True)
        self.checkResult("Test22", "aaa", "ab*a", False)
        self.checkResult("Test23", "aaa", "ab*ac*a", True)
        self.checkResult("Test24", "aaa", "ab*a*c*a", True)
        self.checkResult("Test25", "aaa", ".*", True)
        self.checkResult("Test26", "aab", "c*a*b", True)
        self.checkResult("Test27", "aaca", "ab*a*c*a", True)
        self.checkResult("Test28", "aaba", "ab*a*c*a", False)
        self.checkResult("Test29", "bbbba", ".*a*a", True)
        self.checkResult("Test30", "bcbbabab", ".*a*a", False)


if __name__ == "__main__":
    test = Test()
    test.runTest()
