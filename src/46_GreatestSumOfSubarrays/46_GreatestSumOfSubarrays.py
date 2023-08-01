class Solution:
    # 从右往左逐位取余
    def translateNum(self, num: int) -> int:
        if num < 0:
            return 0
        a, b = 1, 1
        y = num % 10
        while num > 9:
            num //= 10  # python的整除号是//
            x = num % 10
            tmp = 10 * x + y
            a, b = (a + b if 10 <= tmp <= 25 else a), a
            y = x
        return a


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, num: int, expected: int):
        text = testName if testName else ""
        if self.solution.translateNum(num) == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def runTest(self):
        self.checkResult("Test1", 0, 1)
        self.checkResult("Test2", 10, 2)
        self.checkResult("Test3", 125, 3)
        self.checkResult("Test4", 126, 2)
        self.checkResult("Test5", 426, 1)
        self.checkResult("Test6", 100, 2)
        self.checkResult("Test7", 101, 2)
        self.checkResult("Test8", 12258, 5)
        self.checkResult("Test9", -100, 0)


if __name__ == "__main__":
    test = Test()
    test.runTest()
