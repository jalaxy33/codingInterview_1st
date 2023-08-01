class Solution:
    def nthUglyNumber(self, n: int) -> int:
        if n < 1:
            return 0

        a, b, c = 0, 0, 0  # a,b,c分别是指向2, 3, 5倍数的序号
        dp = [1] * n  # dp[i]表示第i个丑数
        for i in range(1, n):
            n2, n3, n5 = dp[a] * 2, dp[b] * 3, dp[c] * 5
            dp[i] = min(n2, n3, n5)
            if dp[i] == n2:
                a += 1
            if dp[i] == n3:
                b += 1
            if dp[i] == n5:
                c += 1
        return dp[n - 1]


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, n: int, expected: int):
        text = testName if testName else ""

        result = self.solution.nthUglyNumber(n)
        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def runTest(self):
        self.checkResult("Test1", 1, 1)
        self.checkResult("Test2", 2, 2)
        self.checkResult("Test3", 3, 3)
        self.checkResult("Test4", 4, 4)
        self.checkResult("Test5", 5, 5)
        self.checkResult("Test6", 6, 6)
        self.checkResult("Test7", 7, 8)
        self.checkResult("Test8", 8, 9)
        self.checkResult("Test9", 9, 10)
        self.checkResult("Test10", 10, 12)
        self.checkResult("Test11", 11, 15)
        self.checkResult("Test12", 1500, 859963392)
        self.checkResult("Test13", 0, 0)


if __name__ == "__main__":
    test = Test()
    test.runTest()
