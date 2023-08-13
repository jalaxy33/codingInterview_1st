class Solution:
    # 根据算术几何不等式：(n1+...+nk)/k >= sqrt[k](n1...nk)。
    def cuttingRope(self, n: int) -> int:
        # 两个推论：
        # 1）以相等长度分段时，乘积最大；
        # 2）对式子两边同时求导，当长度为e=2.7..时乘积最大，约等于3

        # 切分规则：
        # 1）最优：将绳子尽可能切分为多个长度为3的片段；
        # 2）次优：若最后一段长度为2，则保留；
        # 3）最差：若最后一段长度为1，则把一份1+3替换为2+2

        # 当n<=3时，由于最少要剪出一段长度为1的绳子，返回n-1。
        if n <= 3:
            return n - 1

        a, b = n // 3, n % 3
        if b == 0:
            return 3**a
        elif b == 1:
            return 3 ** (a - 1) * 4
        else:
            return 3**a * 2


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
