# 全局标记，应对可能的不合法输入
g_InvalidFlag = False
invalidReturn = 0


class Solution:
    def majorityElement(self, nums: list[int], which_solution: int = 3) -> int:
        global g_InvalidFlag
        if not nums:
            g_InvalidFlag = True
            return invalidReturn

        g_InvalidFlag = False
        if which_solution == 1:
            return self.withHash(nums)
        elif which_solution == 2:
            return self.withSort(nums)
        elif which_solution == 3:
            return self.withVoting(nums)
        else:
            raise ValueError("Invalid solution selection!")

    # 哈希表统计法
    def withHash(self, nums: list[int]) -> int:
        dic = {}
        for num in nums:
            if num not in dic:
                dic[num] = 1
            else:
                dic[num] += 1
        half = len(nums) >> 1
        for num, cnt in dic.items():
            if cnt > half:
                return num
        global g_InvalidFlag
        g_InvalidFlag = True
        return invalidReturn

    # 数组排序法。将数组排序，众数一定是数组的中位数。
    def withSort(self, nums: list[int]) -> int:
        nums.sort()
        middle = len(nums) >> 1
        result, count = nums[middle], 0
        for num in nums:
            if num == result:
                count += 1
        if count <= middle:
            global g_InvalidFlag
            g_InvalidFlag = True
            return invalidReturn
        return result

    # 摩尔投票法，本题的最优解。核心理念是票数正负抵消。
    # 先假设一个众数，开始遍历数组。遇到该数票数+1，不是该数票数-1.
    # 当票数为0时，则将假设的众数换成其他数。
    def withVoting(self, nums: list[int]) -> int:
        result, votes = 0, 0
        for num in nums:
            if votes == 0:
                result = num
            votes += 1 if num == result else -1
        half, count = len(nums) >> 1, 0
        for num in nums:
            if num == result:
                count += 1
        if count <= half:
            global g_InvalidFlag
            g_InvalidFlag = True
            return invalidReturn
        return result


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(
        self, testName: str, nums: list[int], expected: int, invalid: bool
    ) -> None:
        text = testName
        result = self.solution.majorityElement(nums)
        global g_InvalidFlag
        if result == expected and g_InvalidFlag == invalid:
            text += " passed."
        else:
            text += " failed."
        print(text)

    # 存在出现次数超过数组长度一半的数字
    def Test1(self):
        nums = [1, 2, 3, 2, 2, 2, 5, 4, 2]
        self.checkResult("Test1", nums, 2, False)

    # 不存在出现次数超过数组长度一半的数字
    def Test2(self):
        nums = [1, 2, 3, 2, 4, 2, 5, 2, 3]
        self.checkResult("Test2", nums, invalidReturn, True)

    # 出现次数超过数组长度一半的数字都出现在数组的前半部分
    def Test3(self):
        nums = [2, 2, 2, 2, 2, 1, 3, 4, 5]
        self.checkResult("Test3", nums, 2, False)

    # 出现次数超过数组长度一半的数字都出现在数组的后半部分
    def Test4(self):
        nums = [1, 3, 4, 5, 2, 2, 2, 2, 2]
        self.checkResult("Test4", nums, 2, False)

    # 数组只有一个元素
    def Test5(self):
        nums = [1]
        self.checkResult("Test5", nums, 1, False)

    # 输入空数组
    def Test6(self):
        nums = []
        self.checkResult("Test6", nums, invalidReturn, True)

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
