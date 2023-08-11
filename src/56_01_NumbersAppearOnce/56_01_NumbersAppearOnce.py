class Solution:
    def singleNumbers(self, nums: list[int]) -> list[int]:
        if len(nums) < 2:
            return []

        n = 0
        for num in nums:
            n ^= num

        if n == 0:
            return []

        index = 1
        while (n & index) == 0:
            index <<= 1

        x, y = 0, 0
        for num in nums:
            if num & index:
                x ^= num
            else:
                y ^= num
        return [x, y]


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(
        self,
        testName: str,
        nums: list[int],
        expected1: int,
        expected2: int,
        valid: bool,
    ) -> None:
        text = testName
        results = self.solution.singleNumbers(nums)
        if len(results) == 2 and results[0] != results[1] and valid:
            if expected1 in results and expected2 in results:
                text += " passed."
            else:
                text += " failed."
        elif (len(results) < 2 or results[0] == results[1]) and not valid:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def Test1(self):
        nums = [2, 4, 3, 6, 3, 2, 5, 5]
        self.checkResult("Test1", nums, 4, 6, True)

    def Test2(self):
        nums = [4, 6]
        self.checkResult("Test2", nums, 4, 6, True)

    def Test3(self):
        nums = [4, 6, 1, 1]
        self.checkResult("Test3", nums, 4, 6, True)

    def Test4(self):
        nums = [4]
        self.checkResult("Test4", nums, -1, -1, False)

    def Test5(self):
        nums = [1, 1, 1, 1]
        self.checkResult("Test5", nums, -1, -1, False)

    def Test6(self):
        nums = []
        self.checkResult("Test6", nums, -1, -1, False)

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
