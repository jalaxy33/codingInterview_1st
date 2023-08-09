class Solution:
    def search(self, nums: list[int], target: int) -> int:
        def findBoundary(target: int) -> int:
            i, j = 0, len(nums) - 1
            while i <= j:
                m = (i + j) // 2
                if nums[m] <= target:
                    i = m + 1
                else:
                    j = m - 1
            return i

        if not nums:
            return 0
        right = findBoundary(target)
        left = findBoundary(target - 1) + 1
        return right - left + 1


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(
        self, testName: str, nums: list[int], target: int, expected: int
    ) -> None:
        text = testName
        result = self.solution.search(nums, target)
        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    # 查找的数字出现在数组的中间
    def Test1(self):
        nums = [1, 2, 3, 3, 3, 3, 4, 5]
        self.checkResult("Test1", nums, 3, 4)

    # 查找的数组出现在数组的开头
    def Test2(self):
        nums = [3, 3, 3, 3, 4, 5]
        self.checkResult("Test2", nums, 3, 4)

    # 查找的数组出现在数组的结尾
    def Test3(self):
        nums = [1, 2, 3, 3, 3, 3]
        self.checkResult("Test3", nums, 3, 4)

    # 查找的数字不存在
    def Test4(self):
        nums = [1, 3, 3, 3, 3, 4, 5]
        self.checkResult("Test4", nums, 2, 0)

    # 查找的数字比第一个数字还小，不存在
    def Test5(self):
        nums = [1, 3, 3, 3, 3, 4, 5]
        self.checkResult("Test5", nums, 0, 0)

    # 查找的数字比最后一个数字还大，不存在
    def Test6(self):
        nums = [1, 3, 3, 3, 3, 4, 5]
        self.checkResult("Test6", nums, 6, 0)

    # 数组中的数字从头到尾都是查找的数字
    def Test7(self):
        nums = [3, 3, 3, 3]
        self.checkResult("Test7", nums, 3, 4)

    # 数组中的数字从头到尾只有一个重复的数字，不是查找的数字
    def Test8(self):
        nums = [3, 3, 3, 3]
        self.checkResult("Test8", nums, 4, 0)

    # 数组中只有一个数字，是查找的数字
    def Test9(self):
        nums = [3]
        self.checkResult("Test9", nums, 3, 1)

    # 数组中只有一个数字，不是查找的数字
    def Test10(self):
        nums = [3]
        self.checkResult("Test10", nums, 4, 0)

    # 鲁棒性测试，空数组
    def Test11(self):
        nums = []
        self.checkResult("Test11", nums, 0, 0)

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
        self.Test10()
        self.Test11()


if __name__ == "__main__":
    test = Test()
    test.runTest()
