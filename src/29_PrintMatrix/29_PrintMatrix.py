class Solution:
    def spiralOrder(self, matrix: list[list[int]]) -> list[int]:
        if not matrix:
            return []

        l, r, t, b = 0, len(matrix[0]) - 1, 0, len(matrix) - 1
        result = []
        while True:
            # left -> right
            for i in range(l, r + 1):
                result.append(matrix[t][i])
            t += 1
            if t > b:
                break

            # top -> bottom
            for i in range(t, b + 1):
                result.append(matrix[i][r])
            r -= 1
            if r < l:
                break

            # right -> left
            for i in range(r, l - 1, -1):
                result.append(matrix[b][i])
            b -= 1
            if b < t:
                break

            # bottom -> top
            for i in range(b, t - 1, -1):
                result.append(matrix[i][l])
            l += 1
            if l > r:
                break
        return result


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def createMatrix(self, rows: int, cols: int) -> list[list[int]]:
        matrix = []
        for i in range(rows):
            arr = [i * cols + j + 1 for j in range(cols)]
            matrix.append(arr)
        return matrix

    def checkResult(self, testName: str, rows: int, cols: int) -> None:
        print("====", testName, "====")
        matrix = self.createMatrix(rows, cols)
        resultArr = self.solution.spiralOrder(matrix)
        print(resultArr, "\n")

    def runTest(self) -> None:
        # 1
        self.checkResult("Test1", 1, 1)

        # 1    2
        # 3    4
        self.checkResult("Test2", 2, 2)

        # 1    2    3    4
        # 5    6    7    8
        # 9    10   11   12
        # 13   14   15   16
        self.checkResult("Test3", 4, 4)

        # 1    2    3    4    5
        # 6    7    8    9    10
        # 11   12   13   14   15
        # 16   17   18   19   20
        # 21   22   23   24   25
        self.checkResult("Test4", 5, 5)

        # 1
        # 2
        # 3
        # 4
        # 5
        self.checkResult("Test5", 1, 5)

        # 1    2
        # 3    4
        # 5    6
        # 7    8
        # 9    10
        self.checkResult("Test6", 2, 5)

        # 1    2    3
        # 4    5    6
        # 7    8    9
        # 10   11   12
        # 13   14   15
        self.checkResult("Test7", 3, 5)

        # 1    2    3    4
        # 5    6    7    8
        # 9    10   11   12
        # 13   14   15   16
        # 17   18   19   20
        self.checkResult("Test8", 4, 5)

        # 1    2    3    4    5
        self.checkResult("Test9", 5, 1)

        # 1    2    3    4    5
        # 6    7    8    9    10
        self.checkResult("Test10", 5, 2)

        # 1    2    3    4    5
        # 6    7    8    9    10
        # 11   12   13   14    15
        self.checkResult("Test11", 5, 3)

        # 1    2    3    4    5
        # 6    7    8    9    10
        # 11   12   13   14   15
        # 16   17   18   19   20
        self.checkResult("Test12", 5, 4)


if __name__ == "__main__":
    test = Test()
    test.runTest()
