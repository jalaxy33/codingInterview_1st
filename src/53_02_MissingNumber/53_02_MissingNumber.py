class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        if not nums:
            return -1

        i, j = 0, len(nums) - 1
        while i <= j:
            m = (i + j) // 2
            if nums[m] == m:
                i = m + 1
            else:
                j = m - 1
        return i


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, nums: list[int], expected: int) -> None:
        text = testName
        result = self.solution.missingNumber(nums)
        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    # 缺失的是第一个数字0
    def Test1(self):
        nums = [1, 2, 3, 4, 5]
        expected = 0
        self.checkResult("Test1", nums, expected)

    # 缺失的是最后一个数字
    def Test2(self):
        nums = [0, 1, 2, 3, 4]
        expected = 5
        self.checkResult("Test2", nums, expected)

    # 缺失的是中间某个数字0
    def Test3(self):
        nums = [0, 1, 2, 4, 5]
        expected = 3
        self.checkResult("Test3", nums, expected)

    # 数组中只有一个数字，缺失的是第一个数字0
    def Test4(self):
        nums = [1]
        expected = 0
        self.checkResult("Test4", nums, expected)

    # 数组中只有一个数字，缺失的是最后一个数字1
    def Test5(self):
        nums = [0]
        expected = 1
        self.checkResult("Test5", nums, expected)

    # 空数组
    def Test6(self):
        nums = []
        expected = -1
        self.checkResult("Test6", nums, expected)

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
