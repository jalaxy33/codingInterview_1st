class Solution:
    def constructArr(self, A: list[int]) -> list[int]:
        # 由于不能使用除法，可以将B视为一个nxn矩阵
        # B[0] = 1    A[1] A[2] ... A[n]
        # B[1] = A[0] 1    A[2] ... A[n]
        # ...
        # B[n] = A[0] A[1] A[2] ... 1
        # 可以分为上下三角两部分，分别计算两部分结果即可

        if not A:
            return []
        length, B = len(A), [1] * len(A)
        for i in range(1, length):
            B[i] = B[i - 1] * A[i - 1]  # 下三角
        tmp = 1
        for i in range(length - 2, -1, -1):
            tmp *= A[i + 1]  # 上三角
            B[i] *= tmp  # 上三角*下三角
        return B


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, A: list[int], expected: list[int]) -> None:
        text = testName
        B = self.solution.constructArr(A)
        if B == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    # 输入数组中没有0
    def Test1(self):
        A = [1, 2, 3, 4, 5]
        expected = [120, 60, 40, 30, 24]
        self.checkResult("Test1", A, expected)

    # 输入数组中有一个0
    def Test2(self):
        A = [1, 2, 0, 4, 5]
        expected = [0, 0, 40, 0, 0]
        self.checkResult("Test2", A, expected)

    # 输入数组中有两个0
    def Test3(self):
        A = [1, 2, 0, 4, 0]
        expected = [0, 0, 0, 0, 0]
        self.checkResult("Test3", A, expected)

    # 输入数组中有正、负数
    def Test4(self):
        A = [1, -2, 3, -4, 5]
        expected = [120, -60, 40, -30, 24]
        self.checkResult("Test4", A, expected)

    # 输入输入中只有两个数字
    def Test5(self):
        A = [1, -2]
        expected = [-2, 1]
        self.checkResult("Test5", A, expected)

    def runTest(self):
        self.Test1()
        self.Test2()
        self.Test3()
        self.Test4()
        self.Test5()


if __name__ == "__main__":
    test = Test()
    test.runTest()
