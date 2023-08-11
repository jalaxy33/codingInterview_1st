class Solution:
    def hammingWeight(self, n: int, which_solution: int = 2) -> int:
        if which_solution == 1:
            return self.solution1(n)
        elif which_solution == 2:
            return self.solution2(n)
        else:
            raise ValueError("Invalid solution selection!")

    def solution1(self, n: int) -> int:
        result = 0
        while n:
            result += n & 1
            n >>= 1
        return result

    # 利用 n&(n-1) 将n最右边的1变成0.
    # 循环消去所有1, 可以减少循环次数
    def solution2(self, n: int) -> int:
        result = 0
        while n:
            result += 1
            n &= n - 1
        return result


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, n: int, expected: int) -> None:
        text = testName
        result = self.solution.hammingWeight(n)
        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def runTest(self) -> None:
        self.checkResult("Test1", 0, 0)
        self.checkResult("Test2", 1, 1)
        self.checkResult("Test3", 11, 3)
        self.checkResult("Test4", 128, 1)
        self.checkResult("Test5", 0x7FFFFFFF, 31)
        self.checkResult("Test6", 0xFFFFFFFF, 32)
        self.checkResult("Test7", 0x80000000, 1)


if __name__ == "__main__":
    test = Test()
    test.runTest()
