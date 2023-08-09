class Solution:
    def findNumberIn2DArray(self, matrix: list[list[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False

        rows, cols = len(matrix), len(matrix[0])
        i, j = 0, cols - 1  # 选矩阵右上角为标志
        while i < rows and j >= 0:
            if matrix[i][j] > target:
                j -= 1
            elif matrix[i][j] < target:
                i += 1
            else:
                return True
        return False


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(
        self, testName: str, matrix: list[list[int]], target: int, expected: bool
    ) -> None:
        text = testName
        result = self.solution.findNumberIn2DArray(matrix, target)
        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    #  1   2   8   9
    #  2   4   9   12
    #  4   7   10  13
    #  6   8   11  15
    # 要查找的数在数组中
    def Test1(self):
        matrix = [
            [1, 2, 8, 9],
            [2, 4, 9, 12],
            [4, 7, 10, 13],
            [6, 8, 11, 15],
        ]
        self.checkResult("Test1", matrix, 7, True)

    #  1   2   8   9
    #  2   4   9   12
    #  4   7   10  13
    #  6   8   11  15
    # 要查找的数不在数组中
    def Test2(self):
        matrix = [
            [1, 2, 8, 9],
            [2, 4, 9, 12],
            [4, 7, 10, 13],
            [6, 8, 11, 15],
        ]
        self.checkResult("Test2", matrix, 5, False)

    #  1   2   8   9
    #  2   4   9   12
    #  4   7   10  13
    #  6   8   11  15
    # 要查找的数是数组中最小的数字
    def Test3(self):
        matrix = [
            [1, 2, 8, 9],
            [2, 4, 9, 12],
            [4, 7, 10, 13],
            [6, 8, 11, 15],
        ]
        self.checkResult("Test3", matrix, 1, True)

    #  1   2   8   9
    #  2   4   9   12
    #  4   7   10  13
    #  6   8   11  15
    # 要查找的数是数组中最大的数字
    def Test4(self):
        matrix = [
            [1, 2, 8, 9],
            [2, 4, 9, 12],
            [4, 7, 10, 13],
            [6, 8, 11, 15],
        ]
        self.checkResult("Test4", matrix, 15, True)

    #  1   2   8   9
    #  2   4   9   12
    #  4   7   10  13
    #  6   8   11  15
    # 要查找的数比数组中最小的数字还小
    def Test5(self):
        matrix = [
            [1, 2, 8, 9],
            [2, 4, 9, 12],
            [4, 7, 10, 13],
            [6, 8, 11, 15],
        ]
        self.checkResult("Test5", matrix, 0, False)

    #  1   2   8   9
    #  2   4   9   12
    #  4   7   10  13
    #  6   8   11  15
    # 要查找的数比数组中最大的数字还大
    def Test6(self):
        matrix = [
            [1, 2, 8, 9],
            [2, 4, 9, 12],
            [4, 7, 10, 13],
            [6, 8, 11, 15],
        ]
        self.checkResult("Test6", matrix, 16, False)

    # 鲁棒性测试，输入空指针
    def Test7(self):
        matrix = []
        self.checkResult("Test7", matrix, 16, False)

    def runTest(self):
        self.Test1()
        self.Test2()
        self.Test3()
        self.Test4()
        self.Test5()
        self.Test6()
        self.Test7()


if __name__ == "__main__":
    test = Test()
    test.runTest()
