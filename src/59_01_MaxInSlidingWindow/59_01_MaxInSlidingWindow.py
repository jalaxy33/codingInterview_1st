import collections


class Solution:
    def maxSlidingWindow(self, nums: list[int], k: int) -> list[int]:
        if len(nums) < k or k < 1:
            return []

        index = collections.deque()  # 用于存放可能的窗口最大值的序号
        # 未形成窗口时
        for i in range(k):
            while index and nums[index[-1]] < nums[i]:
                index.pop()
            index.append(i)

        # 形成窗口后
        results = [nums[index[0]]]
        for i in range(k, len(nums)):
            if index and index[0] <= (i - k):
                index.popleft()
            while index and nums[index[-1]] < nums[i]:
                index.pop()
            index.append(i)
            results.append(nums[index[0]])
        return results


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(
        self, testName: str, nums: list[int], k: int, expected: list[int]
    ) -> None:
        text = testName if testName else ""

        results = self.solution.maxSlidingWindow(nums, k)
        if results == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def Test1(self):
        nums = [2, 3, 4, 2, 6, 2, 5, 1]
        expected = [4, 4, 6, 6, 6, 5]
        k = 3
        self.checkResult("Test1", nums, k, expected)

    def Test2(self):
        nums = [1, 3, -1, -3, 5, 3, 6, 7]
        expected = [3, 3, 5, 5, 6, 7]
        k = 3
        self.checkResult("Test2", nums, k, expected)

    # 输入数组单调递增
    def Test3(self):
        nums = [1, 3, 5, 7, 9, 11, 13, 15]
        expected = [7, 9, 11, 13, 15]
        k = 4
        self.checkResult("Test3", nums, k, expected)

    # 输入数组单调递减
    def Test4(self):
        nums = [16, 14, 12, 10, 8, 6, 4]
        expected = [16, 14, 12]
        k = 5
        self.checkResult("Test4", nums, k, expected)

    # 滑动窗口的大小为1
    def Test5(self):
        nums = [10, 14, 12, 11]
        expected = [10, 14, 12, 11]
        k = 1
        self.checkResult("Test5", nums, k, expected)

    # 滑动窗口的大小等于数组的长度
    def Test6(self):
        nums = [10, 14, 12, 11]
        expected = [14]
        k = 4
        self.checkResult("Test6", nums, k, expected)

    # 滑动窗口的大小为0
    def Test7(self):
        nums = [10, 14, 12, 11]
        expected = []
        k = 0
        self.checkResult("Test7", nums, k, expected)

    # 滑动窗口的大小大于输入数组的长度
    def Test8(self):
        nums = [10, 14, 12, 11]
        expected = []
        k = 5
        self.checkResult("Test8", nums, k, expected)

    # 输入数组为空
    def Test9(self):
        nums, expected = [], []
        k = 5
        self.checkResult("Test9", nums, k, expected)

    def runTest(self):
        self.Test1()
        self.Test2()
        self.Test3()
        self.Test4()
        self.Test5()
        self.Test6()
        self.Test7()
        self.Test8()
        self.Test9()


if __name__ == "__main__":
    test = Test()
    test.runTest()
