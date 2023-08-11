class Solution:
    def exchange(self, nums: list[int]) -> list[int]:
        i, j = 0, len(nums) - 1
        while i < j:
            while i < j and (nums[i] & 1) == 1:
                i += 1
            while i < j and (nums[j] & 1) == 0:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]
        return nums


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, nums: list[int]) -> None:
        print(f"==== {testName} ====")
        print("original:")
        print(nums)

        result = self.solution.exchange(nums)
        print("exchanged:")
        print(result)
        print("\n")

    def Test1(self):
        nums = [1, 2, 3, 4, 5, 6, 7]
        self.checkResult("Test1", nums)

    def Test2(self):
        nums = [2, 4, 6, 1, 3, 5, 7]
        self.checkResult("Test2", nums)

    def Test3(self):
        nums = [1, 3, 5, 7, 2, 4, 6]
        self.checkResult("Test3", nums)

    def Test4(self):
        nums = [1]
        self.checkResult("Test4", nums)

    def Test5(self):
        nums = [2]
        self.checkResult("Test5", nums)

    def Test6(self):
        nums = []
        self.checkResult("Test6", nums)

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
