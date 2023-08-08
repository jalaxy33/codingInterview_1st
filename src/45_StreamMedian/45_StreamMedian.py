import functools


class Solution:
    def minNumber(self, nums: list[int], use_myQsort: bool = False) -> str:
        strs = [str(num) for num in nums]
        if use_myQsort:  # 自己实现快速排序
            self.myQsort(strs, 0, len(strs) - 1)
        else:
            # 使用库函数，用functools.cmp_to_key设定比较规则
            strs.sort(key=functools.cmp_to_key(self.sort_rule))
        return "".join(strs)

    def myQsort(self, strs: list[str], l: int, r: int):
        # partition
        if l >= r:
            return
        i, j = l, r
        while i < j:
            while i < j and strs[j] + strs[l] >= strs[l] + strs[j]:
                j -= 1
            while i < j and strs[i] + strs[l] <= strs[l] + strs[i]:
                i += 1
            strs[i], strs[j] = strs[j], strs[i]
        strs[i], strs[l] = strs[l], strs[i]
        # recur
        self.myQsort(strs, l, i - 1)
        self.myQsort(strs, i + 1, r)

    def sort_rule(self, x: str, y: str) -> int:
        a, b = x + y, y + x
        if a > b:
            return 1
        elif a < b:
            return -1
        else:
            return 0


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, nums: list[int], expected: str) -> None:
        text = testName
        result = self.solution.minNumber(nums)
        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def Test1(self):
        nums = [3, 5, 1, 4, 2]
        expected = "12345"
        self.checkResult("Test1", nums, expected)

    def Test2(self):
        nums = [3, 32, 321]
        expected = "321323"
        self.checkResult("Test2", nums, expected)

    def Test3(self):
        nums = [3, 323, 32123]
        expected = "321233233"
        self.checkResult("Test3", nums, expected)

    def Test4(self):
        nums = [1, 11, 111]
        expected = "111111"
        self.checkResult("Test4", nums, expected)

    def Test5(self):
        nums = [321]
        expected = "321"
        self.checkResult("Test5", nums, expected)

    def Test6(self):
        nums = []
        expected = ""
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
