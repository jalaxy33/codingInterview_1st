class Solution:
    def findRepeatNumber(self, nums: list[int], use_hash=False) -> int:
        if use_hash:
            return self.withHash(nums)
        else:
            return self.withSwap(nums)

    def withHash(self, nums: list[int]) -> int:
        dic = set() 
        for num in nums:
            if num in dic:
                return num
            dic.add(num)
        return -1

    def withSwap(self, nums: list[int]) -> int:
        i = 0
        while i < len(nums):
            if i == nums[i]:
                i += 1
                continue
            if nums[nums[i]] == nums[i]:
                return nums[i]
            # 注意赋值顺序
            nums[nums[i]], nums[i] = nums[i], nums[nums[i]]
        return -1


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, nums: list[int], expected: list[int]) -> None:
        text = testName
        result = self.solution.findRepeatNumber(nums)
        if result in expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    # 重复的数字是数组中最小的数字
    def Test1(self):
        nums = [2, 1, 3, 1, 4]
        expected = [1]
        self.checkResult("Test1", nums, expected)

    # 重复的数字是数组中最大的数字
    def Test2(self):
        nums = [2, 4, 3, 1, 4]
        expected = [4]
        self.checkResult("Test2", nums, expected)

    # 数组中存在多个重复的数字
    def Test3(self):
        nums = [2, 4, 2, 1, 4]
        expected = [2, 4]
        self.checkResult("Test3", nums, expected)

    # 没有重复的数字
    def Test4(self):
        nums = [2, 1, 3, 0, 4]
        expected = [-1]  # not in use in the test function
        self.checkResult("Test4", nums, expected)

    # 没有重复的数字
    def Test5(self):
        nums = [2, 1, 3, 5, 4, 0]
        expected = [-1]  # not in use in the test function
        self.checkResult("Test5", nums, expected)

    # 无效的输入
    def Test6(self):
        nums = []
        expected = [-1]  # not in use in the test function
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
