import heapq


class MedianFinder:
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.A = []  # 小顶堆，保存较大的一半
        self.B = []  # 大顶堆，保存较小的一半

    def addNum(self, num: int) -> None:
        if len(self.A) != len(self.B):
            # 当数据流总元素数为奇数时，向B添加元素。
            # 先将该元素插入A，再将A堆顶插入B
            # 由于python中heapq默认为小顶堆，因此取反后加入
            heapq.heappush(self.B, -heapq.heappushpop(self.A, num))
        else:
            # 当数据流总元素数为偶数时，向A添加元素。
            # 先将该元素插入B，再将B堆顶插入A
            # 由于python中heapq默认为小顶堆，因此取反后加入
            heapq.heappush(self.A, -heapq.heappushpop(self.B, -num))

    def findMedian(self) -> float:
        # 当总元素数为奇数时，返回A的堆顶，否则返回堆顶均值
        # B中元素需要先取反
        return (
            self.A[0] if len(self.A) != len(self.B) else (self.A[0] - self.B[0]) / 2.0
        )

    def reset(self) -> None:
        self.A.clear()
        self.B.clear()


class Test:
    def __init__(self) -> None:
        self.solution = MedianFinder()

    def checkResult(self, testName: str, num: int, expected: float) -> None:
        text = testName

        self.solution.addNum(num)
        result = self.solution.findMedian()

        if abs(result - expected) < 1e-9:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def runTest(self) -> None:
        self.solution.reset()

        self.checkResult("Test1", 5, 5)
        self.checkResult("Test2", 2, 3.5)
        self.checkResult("Test3", 3, 3)
        self.checkResult("Test4", 4, 3.5)
        self.checkResult("Test5", 1, 3)
        self.checkResult("Test6", 6, 3.5)
        self.checkResult("Test7", 7, 4)
        self.checkResult("Test8", 0, 3.5)
        self.checkResult("Test9", 8, 4)


if __name__ == "__main__":
    test = Test()
    test.runTest()
