class Solution:
    # 位运算替代加法.
    # 非进位和——异或；进位——与运算+左移。
    # 由于数字以补码形式存储，因此加减法的过程是相同的。
    def add(self, a: int, b: int) -> int:
        # 由于python不限定变量的大小，因此需要手动将整数
        # 变为32位，方法是与0xffffffff相与
        x = 0xFFFFFFFF
        a, b = a & x, b & x
        while b:
            a, b = (a ^ b), ((a & b) << 1) & x  # 注意保证位数
        # 当结果a为负数时(<=0x7fffffff)，需要将其1至32位取反,
        # 方法是 ~(a^x)
        return a if a <= 0x7FFFFFFF else ~(a ^ x)


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, a: int, b: int, expected: int) -> None:
        text = testName
        result = self.solution.add(a, b)
        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def runTest(self) -> None:
        self.checkResult("Test1", 1, 2, 3)
        self.checkResult("Test2", 111, 899, 1010)
        self.checkResult("Test3", -1, 2, 1)
        self.checkResult("Test4", 1, -2, -1)
        self.checkResult("Test5", 3, 0, 3)
        self.checkResult("Test6", 0, -4, -4)
        self.checkResult("Test7", -2, -8, -10)


if __name__ == "__main__":
    test = Test()
    test.runTest()
