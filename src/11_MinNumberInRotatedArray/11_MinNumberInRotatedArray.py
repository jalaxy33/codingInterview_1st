class Solution:
    # 二分查找
    def minArray(self, numbers: list[int], use_strat1=False) -> int:
        if not numbers:
            return 0

        i, j = 0, len(numbers) - 1
        while i < j:
            m = (i + j) // 2
            if numbers[m] > numbers[j]:
                i = m + 1
            elif numbers[m] < numbers[j]:
                j = m
            else:
                # 当相等时,不能直接判断.有两种策略:
                # 1) j-=1, 缩小判断范围
                # 2) 放弃二分, 改为线性查找
                if use_strat1:
                    j -= 1
                else:
                    x = i
                    for k in range(i + 1, j):
                        if numbers[k] < numbers[x]:
                            x = k
                    return numbers[x]
        return numbers[i]


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, numbers: list[int], expected: int) -> None:
        text = testName
        result = self.solution.minArray(numbers)
        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    # 典型输入，单调升序的数组的一个旋转
    def Test1(self):
        numbers = [3, 4, 5, 1, 2]
        self.checkResult("Test1", numbers, 1)

    # 有重复数字，并且重复的数字刚好的最小的数字
    def Test2(self):
        numbers = [3, 4, 5, 1, 1, 2]
        self.checkResult("Test2", numbers, 1)

    # 有重复数字，但重复的数字不是第一个数字和最后一个数字
    def Test3(self):
        numbers = [3, 4, 5, 1, 2, 2]
        self.checkResult("Test3", numbers, 1)

    # 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
    def Test4(self):
        numbers = [1, 0, 1, 1, 1]
        self.checkResult("Test4", numbers, 0)

    # 单调升序数组，旋转0个元素，也就是单调升序数组本身
    def Test5(self):
        numbers = [1, 2, 3, 4, 5]
        self.checkResult("Test5", numbers, 1)

    # 数组中只有一个数字
    def Test6(self):
        numbers = [2]
        self.checkResult("Test6", numbers, 2)

    # 输入空数组
    def Test7(self):
        numbers = []
        self.checkResult("Test7", numbers, 0)

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
