import heapq


class Solution:
    def getLeastNumbers(
        self, arr: list[int], k: int, use_qsort: bool = False
    ) -> list[int]:
        if k >= len(arr):
            return arr
        if k <= 0:
            return []

        if use_qsort:
            return self.quickSort(arr, k, 0, len(arr) - 1)
        else:
            return self.heapSort(arr, k)

    # 由于只需找出最小的k个数，
    # 因此仅需将数组划分为 最小k个数 和 其他数字 两部分即可。
    def quickSort(self, arr: list[int], k: int, l: int, r: int) -> list[int]:
        def partition(l: int, r: int) -> int:
            i, j = l, r
            while i < j:
                while i < j and arr[j] >= arr[l]:
                    j -= 1
                while i < j and arr[i] <= arr[l]:
                    i += 1
                arr[i], arr[j] = arr[j], arr[i]
            arr[i], arr[l] = arr[l], arr[i]
            return i

        i = partition(l, r)
        if i > k:
            return self.quickSort(arr, k, l, i - 1)
        if i < k:
            return self.quickSort(arr, k, i + 1, r)
        return [arr[i] for i in range(k)]

    # 堆排序
    def heapSort(self, arr: list[int], k: int) -> list[int]:
        # return heapq.nsmallest(k, arr)
        h = []
        for v in arr:
            heapq.heappush(h, v)
        return [heapq.heappop(h) for _ in range(k)]


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(
        self, testName: str, arr: list[int], k: int, expected: list[int]
    ) -> None:
        text = testName
        result = self.solution.getLeastNumbers(arr, k)

        if sorted(result) == sorted(expected):
            text += " passed."
        else:
            text += " failed."
        print(text)

    # k小于数组长度
    def Test1(self):
        arr = [4, 5, 1, 6, 2, 7, 3, 8]
        expected = [1, 2, 3, 4]
        k = len(expected)
        self.checkResult("Test1", arr, k, expected)

    # k等于数组的长度
    def Test2(self):
        arr = [4, 5, 1, 6, 2, 7, 3, 8]
        expected = [1, 2, 3, 4, 5, 6, 7, 8]
        k = len(expected)
        self.checkResult("Test2", arr, k, expected)

    # k大于数组的长度
    def Test3(self):
        arr = [4, 5, 1, 6, 2, 7, 3, 8]
        expected = [4, 5, 1, 6, 2, 7, 3, 8]
        k = 10
        self.checkResult("Test3", arr, k, expected)

    # k等于1
    def Test4(self):
        arr = [4, 5, 1, 6, 2, 7, 3, 8]
        expected = [1]
        k = len(expected)
        self.checkResult("Test4", arr, k, expected)

    # k等于0
    def Test5(self):
        arr = [4, 5, 1, 6, 2, 7, 3, 8]
        expected = []
        k = 0
        self.checkResult("Test5", arr, k, expected)

    # 数组中有相同的数字
    def Test6(self):
        arr = [4, 5, 1, 6, 2, 7, 2, 8]
        expected = [1, 2]
        k = len(expected)
        self.checkResult("Test6", arr, k, expected)

    # 空数组
    def Test7(self):
        arr = []
        expected = []
        k = 0
        self.checkResult("Test7", arr, k, expected)

    def runTest(self):
        self.Test1()
        self.Test2()
        self.Test3()
        self.Test4()
        self.Test5()
        self.Test6()
        self.Test7()


if __name__ == "__main__":
    test = Test()
    test.runTest()
