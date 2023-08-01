g_InvalidInput = False


class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        global g_InvalidInput
        if not nums:
            g_InvalidInput = True
            return 0
        g_InvalidInput = False
        result, pre = nums[0], 0
        for x in nums:
            pre = max(pre + x, x)
            result = max(pre, result)
        return result


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, nums: list[int], expected: int, expectedFlag):
        text = testName if testName else ""
        result = self.solution.maxSubArray(nums)
        if result == expected and expectedFlag == g_InvalidInput:
            text += " passed."
        else:
            text += " failed."
        print(text)

    # 1, -2, 3, 10, -4, 7, 2, -5
    def Test1(self):
        nums = [1, -2, 3, 10, -4, 7, 2, -5]
        self.checkResult("Test1", nums, 18, False)

    # 所有数字都是负数
    # -2, -8, -1, -5, -9
    def Test2(self):
        nums = [-2, -8, -1, -5, -9]
        self.checkResult("Test2", nums, -1, False)

    # 所有数字都是正数
    # 2, 8, 1, 5, 9
    def Test3(self):
        nums = [2, 8, 1, 5, 9]
        self.checkResult("Test3", nums, 25, False)

    # 无效输入
    def Test4(self):
        nums = []
        self.checkResult("Test4", nums, 0, True)

    def runTest(self):
        self.Test1()
        self.Test2()
        self.Test3()
        self.Test4()


if __name__ == "__main__":
    test = Test()
    test.runTest()
