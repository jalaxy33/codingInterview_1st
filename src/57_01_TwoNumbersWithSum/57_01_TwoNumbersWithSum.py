class Solution:
    # nums是有序列表，可以用双指针法，空间复杂度为O(1)。
    # 无序列表可用哈希表法遍历数组找到组合，时空复杂度均为O(n)。
    def twoSum(self, nums: list[int], target: int, use_twop=False) -> list[int]:
        if not nums:
            return []

        if use_twop:
            return self.withTwoPointer(nums, target)
        else:
            return self.withHash(nums, target)

    # 双指针法。指针i和j分别位于数组左右，
    # 根据比较nums[i]+nums[j]与target的大小，调整i和j的位置
    def withTwoPointer(self, nums: list[int], target: int) -> list[int]:
        i, j = 0, len(nums) - 1
        while i < j:
            s = nums[i] + nums[j]
            if s < target:
                i += 1
            elif s > target:
                j -= 1
            else:
                return [nums[i], nums[j]]
        return []

    # 哈希表法
    def withHash(self, nums: list[int], target: int) -> list[int]:
        dic = set()
        for num in nums:
            dic.add(num)
        for num in nums:
            if target - num in dic:
                return [num, target - num]
        return []


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(
        self, testName: str, nums: list[int], target: int, valid: bool
    ) -> None:
        text = testName
        result = self.solution.twoSum(nums, target)

        if len(result) == 2 and valid:
            total = sum(result)
            if total == target:
                text += " passed."
            else:
                text += " failed."
        elif not result and not valid:
            text += " passed."
        else:
            text += " failed."
        print(text)

    # 存在和为s的两个数字，这两个数字位于数组的中间
    def Test1(self):
        nums = [1, 2, 4, 7, 11, 15]
        self.checkResult("Test1", nums, 15, True)

    # 存在和为s的两个数字，这两个数字位于数组的两段
    def Test2(self):
        nums = [1, 2, 4, 7, 11, 16]
        self.checkResult("Test2", nums, 17, True)

    # 不存在和为s的两个数字
    def Test3(self):
        nums = [1, 2, 4, 7, 11, 16]
        self.checkResult("Test3", nums, 10, False)

    # 鲁棒性测试
    def Test4(self):
        nums = []
        self.checkResult("Test4", nums, 0, False)

    def runTest(self):
        self.Test1()
        self.Test2()
        self.Test3()
        self.Test4()


if __name__ == "__main__":
    test = Test()
    test.runTest()
