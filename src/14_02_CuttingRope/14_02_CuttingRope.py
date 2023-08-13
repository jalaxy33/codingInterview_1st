class Solution:
    # 本题与第（一）题基本一致，但是结果需要取模。
    # 与C++不同，python变量的存储空间可以视作无限大，无需考虑大数取余问题,
    # 直接取模即可.
    def cuttingRope(self, n: int) -> int:
        if n <= 3:
            return n - 1

        a, b = n // 3, n % 3
        mod = int(1e9+7)
        if b == 0:
            return 3**a % mod
        elif b == 1:
            return 3 ** (a - 1) * 4 % mod
        else:
            return 3**a * 2 % mod


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, n: int, expected: int) -> None:
        text = testName
        result = self.solution.cuttingRope(n)
        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def runTest(self) -> None:
        self.checkResult("Test1", 1, 0)
        self.checkResult("Test2", 2, 1)
        self.checkResult("Test3", 3, 2)
        self.checkResult("Test4", 4, 4)
        self.checkResult("Test5", 5, 6)
        self.checkResult("Test6", 6, 9)
        self.checkResult("Test7", 7, 12)
        self.checkResult("Test8", 8, 18)
        self.checkResult("Test9", 9, 27)
        self.checkResult("Test10", 10, 36)
        self.checkResult("Test11", 50, 86093442)


if __name__ == "__main__":
    test = Test()
    test.runTest()
