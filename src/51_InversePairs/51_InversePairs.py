class Solution:
    def reversePairs(self, nums: list[int]) -> int:
        def mergeSort(l: int, r: int):
            if l >= r:
                return 0
            # 划分&递归
            m = (l + r) // 2
            result = mergeSort(l, m) + mergeSort(m + 1, r)
            # 合并&统计逆序对
            tmp[l : r + 1] = nums[l : r + 1]
            i, j = l, m + 1
            for k in range(l, r + 1):
                if i == m + 1:
                    nums[k] = tmp[j]
                    j += 1
                elif j == r + 1 or tmp[i] <= tmp[j]:
                    nums[k] = tmp[i]
                    i += 1
                else:
                    nums[k] = tmp[j]
                    j += 1
                    result += m - i + 1
            return result

        if not len(nums):
            return 0
        tmp = [0] * len(nums)
        return mergeSort(0, len(nums) - 1)


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, nums: list[int], expected: bool) -> None:
        text = testName
        result = self.solution.reversePairs(nums)
        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def Test1(self):
        nums = [1, 2, 3, 4, 7, 6, 5]
        expected = 3
        self.checkResult("Test1", nums, expected)

    def Test2(self):
        nums = [6, 5, 4, 3, 2, 1]
        expected = 15
        self.checkResult("Test2", nums, expected)

    def Test3(self):
        nums = [1, 2, 3, 4, 5, 6]
        expected = 0
        self.checkResult("Test3", nums, expected)

    def Test4(self):
        nums = [1]
        expected = 0
        self.checkResult("Test4", nums, expected)

    def Test5(self):
        nums = [1, 2]
        expected = 0
        self.checkResult("Test5", nums, expected)

    def Test6(self):
        nums = [2, 1]
        expected = 1
        self.checkResult("Test6", nums, expected)

    def Test7(self):
        nums = [1, 2, 1, 2, 1]
        expected = 3
        self.checkResult("Test7", nums, expected)

    def Test8(self):
        nums = []
        expected = 0
        self.checkResult("Test8", nums, expected)

    def runTest(self):
        self.Test1()
        self.Test2()
        self.Test3()
        self.Test4()
        self.Test5()
        self.Test6()
        self.Test7()
        self.Test8()


if __name__ == "__main__":
    test = Test()
    test.runTest()
