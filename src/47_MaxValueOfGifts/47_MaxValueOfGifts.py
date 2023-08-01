class Solution:
    # 动态规划
    def maxValue(self, grid: list[list[int]]) -> int:
        if not grid:
            return 0

        m, n = len(grid), len(grid[0])
        # 初始化首行首列
        for j in range(1, n):
            grid[0][j] += grid[0][j - 1]
        for i in range(1, m):
            grid[i][0] += grid[i - 1][0]

        # dp[i,j] = max(dp[左边], dp[上边]) + grid[i,j]
        for i in range(1, m):
            for j in range(1, n):
                grid[i][j] += max(grid[i][j - 1], grid[i - 1][j])
        return grid[m - 1][n - 1]


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, grid: list[list[int]], expected: int):
        text = testName if testName else ""
        if self.solution.maxValue(grid) == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def Test1(self):
        grid = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
        expected = 29
        self.checkResult("Test1", grid, expected)

    def Test2(self):
        grid = [
            [1, 10, 3, 8],
            [12, 2, 9, 6],
            [5, 7, 4, 11],
            [3, 7, 16, 5],
        ]
        expected = 53
        self.checkResult("Test2", grid, expected)

    def Test3(self):
        grid = [[1, 10, 3, 8]]
        expected = 22
        self.checkResult("Test3", grid, expected)

    def Test4(self):
        grid = [[1], [12], [5], [3]]
        expected = 21
        self.checkResult("Test4", grid, expected)

    def Test5(self):
        grid = [[3]]
        expected = 3
        self.checkResult("Test5", grid, expected)

    def Test6(self):
        grid = []
        expected = 0
        self.checkResult("Test6", grid, expected)

    def runTest(self):
        self.Test1()
        self.Test2()
        self.Test3()
        self.Test4()
        self.Test5()
        self.Test6()


if __name__ == "__main__":
    test = Test()
    test.runTest()
