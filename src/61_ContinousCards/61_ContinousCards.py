class Solution:
    def isStraight(self, nums: list[int], use_sort: bool = False) -> bool:
        if not nums:
            return False

        if use_sort:
            return self.withSort(nums)
        else:
            return self.withSet(nums)

    def withSort(self, nums: list[int]) -> bool:
        joker = 0
        nums.sort()
        for i in range(4):
            if nums[i] == 0:
                joker += 1
            elif nums[i] == nums[i + 1]:
                return False
        return nums[4] - nums[joker] < 5

    def withSet(self, nums: list[int]) -> bool:
        repeat = set()
        max_, min_ = 0, 14
        for num in nums:
            if num == 0:
                continue
            max_ = max(max_, num)
            min_ = min(min_, num)
            if num in repeat:
                return False
            repeat.add(num)
        return max_ - min_ < 5


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, nums: list[int], expected: bool) -> None:
        text = testName
        result = self.solution.isStraight(nums)
        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def Test1(self):
        nums = [1, 3, 2, 5, 4]
        self.checkResult("Test1", nums, True)

    def Test2(self):
        nums = [1, 3, 2, 6, 4]
        self.checkResult("Test2", nums, False)

    def Test3(self):
        nums = [0, 3, 2, 6, 4]
        self.checkResult("Test3", nums, True)

    def Test4(self):
        nums = [0, 3, 1, 6, 4]
        self.checkResult("Test4", nums, False)

    def Test5(self):
        nums = [1, 3, 0, 5, 0]
        self.checkResult("Test5", nums, True)

    def Test6(self):
        nums = [1, 3, 0, 7, 0]
        self.checkResult("Test6", nums, False)

    def Test7(self):
        nums = [1, 0, 0, 5, 0]
        self.checkResult("Test7", nums, True)

    def Test8(self):
        nums = [1, 0, 0, 7, 0]
        self.checkResult("Test8", nums, False)

    def Test9(self):
        nums = [3, 0, 0, 0, 0]
        self.checkResult("Test9", nums, True)

    def Test10(self):
        nums = [0, 0, 0, 0, 0]
        self.checkResult("Test10", nums, True)

    # 有对子
    def Test11(self):
        nums = [1, 0, 0, 1, 0]
        self.checkResult("Test11", nums, False)

    # 鲁棒性测试
    def Test12(self):
        nums = []
        self.checkResult("Test12", nums, False)

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
        self.Test12()


if __name__ == "__main__":
    test = Test()
    test.runTest()
