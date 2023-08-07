g_InvalidInput = False


def equal(n1: float, n2: float):
    return abs(n1 - n2) < 1e-9


class Solution:
    # 快速幂
    def myPow(self, x: float, n: int, use_iter: bool = True) -> float:
        global g_InvalidInput
        if equal(x, 0) and n < 0:
            g_InvalidInput = True
            return 0.0

        g_InvalidInput = False
        if use_iter:
            return self.powIter(x, n)
        else:
            return self.powRecur(x, n)

    def powIter(self, x: float, n: int) -> float:
        if n == 0:
            return 1.0
        if equal(x, 0.0):
            return 0.0

        # 处理负指数
        if n < 0:
            x, n = 1.0 / x, -n
        result = 1.0

        while n > 0:
            if n & 0x01:
                result *= x
            x *= x
            n >>= 1
        return result

    def powRecur(self, x: float, n: int) -> float:
        if n == 0:
            return 1.0
        if n < 0:
            return 1.0 / self.powRecur(x, -n)

        if n & 0x01:
            return x * self.powRecur(x * x, n >> 1)
        else:
            return self.powRecur(x * x, n >> 1)


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(
        self, testName: str, x: float, n: int, expected: float, expectedFlag: bool
    ) -> None:
        text = testName
        result = self.solution.myPow(x, n)
        global g_InvalidInput
        if equal(result, expected) and expectedFlag == g_InvalidInput:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def runTest(self) -> None:
        # 底数、指数都为正数
        self.checkResult("Test1", 2, 3, 8, False)

        # 底数为负数、指数为正数
        self.checkResult("Test2", -2, 3, -8, False)

        # 指数为负数
        self.checkResult("Test3", 2, -3, 0.125, False)

        # 指数为0
        self.checkResult("Test4", 2, 0, 1, False)

        # 底数、指数都为0
        self.checkResult("Test5", 0, 0, 1, False)

        # 底数为0、指数为正数
        self.checkResult("Test6", 0, 4, 0, False)

        # 底数为0、指数为负数
        self.checkResult("Test7", 0, -4, 0, True)


if __name__ == "__main__":
    test = Test()
    test.runTest()
