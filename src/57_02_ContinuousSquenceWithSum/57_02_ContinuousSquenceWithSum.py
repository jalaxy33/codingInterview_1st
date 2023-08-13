class Solution:
    def findContinuousSequence(
        self, target: int, which_solution: int = 1
    ) -> list[list[int]]:
        if target < 3:
            return []  # 至少三个元素

        if which_solution == 1:
            return self.withSumFormula(target)
        elif which_solution == 2:
            return self.withSlidingWindow(target)
        else:
            raise ValueError("Invalid solution selection!")

    # 利用求和公式
    def withSumFormula(self, target: int) -> list[list[int]]:
        # 设连续序列的左右边界为i和j，求和公式为
        # target = (i+j) * (j-i+1) / 2
        # 解方程得：
        # j = 1/2 * ( -1 + sqrt( 1 + 4( 2target + i^2 - i ) ) )

        i, j = 1, 2.0
        results = []
        while i < j:
            j = (-1 + (1 + 4 * (2 * target + i * i - i)) ** 0.5) / 2
            if j == int(j):
                results.append(list(range(i, int(j) + 1)))
            i += 1
        return results

    # 滑动窗口（双指针）
    def withSlidingWindow(self, target: int) -> list[list[int]]:
        i, j, s = 1, 2, 3
        results = []
        while i < j:
            if s == target:
                results.append(list(range(i, j + 1)))
            # 找到一组了也可以继续往后找
            if s >= target:
                s -= i
                i += 1
            else:
                j += 1
                s += j
        return results


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, target: int) -> None:
        print("====", testName, "====")
        result = self.solution.findContinuousSequence(target)
        print(result, "\n")

    def runTest(self) -> None:
        self.checkResult("Test1", 1)
        self.checkResult("Test2", 3)
        self.checkResult("Test3", 4)
        self.checkResult("Test4", 9)
        self.checkResult("Test5", 15)
        self.checkResult("Test6", 100)


if __name__ == "__main__":
    test = Test()
    test.runTest()
