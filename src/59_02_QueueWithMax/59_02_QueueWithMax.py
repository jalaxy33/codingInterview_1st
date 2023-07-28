# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()


class MaxQueue:
    def __init__(self):
        self.que, self.deq = [], []

    def max_value(self) -> int:
        return self.deq[0] if self.deq else -1

    def push_back(self, value: int) -> None:
        self.que.append(value)
        while self.deq and self.deq[-1] < value:
            self.deq.pop()
        self.deq.append(value)

    def pop_front(self) -> int:
        if not self.que:
            return -1
        val = self.que[0]
        self.que.pop(0)
        if val == self.deq[0]:
            self.deq.pop(0)
        return val


class Test:
    def checkResult(self, testName: str, q: MaxQueue, expected: int) -> None:
        text = testName if testName else ""
        if q.max_value() == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def runTest(self):
        q = MaxQueue()

        # {2}
        q.push_back(2)
        self.checkResult("Test1", q, 2)

        # {2, 3}
        q.push_back(3)
        self.checkResult("Test2", q, 3)

        # {2, 3, 4}
        q.push_back(4)
        self.checkResult("Test3", q, 4)

        # {2, 3, 4, 2}
        q.push_back(2)
        self.checkResult("Test4", q, 4)

        # {3, 4, 2}
        q.pop_front()
        self.checkResult("Test5", q, 4)

        # {4, 2}
        q.pop_front()
        self.checkResult("Test6", q, 4)

        # {2}
        q.pop_front()
        self.checkResult("Test7", q, 2)

        # {2, 6}
        q.push_back(6)
        self.checkResult("Test8", q, 6)

        # {2, 6, 2}
        q.push_back(2)
        self.checkResult("Test9", q, 6)

        # {2, 6, 2, 5}
        q.push_back(5)
        self.checkResult("Test9", q, 6)

        # {6, 2, 5}
        q.pop_front()
        self.checkResult("Test10", q, 6)

        # {2, 5}
        q.pop_front()
        self.checkResult("Test11", q, 5)

        # {5}
        q.pop_front()
        self.checkResult("Test12", q, 5)

        # {5, 1}
        q.push_back(1)
        self.checkResult("Test13", q, 5)


if __name__ == "__main__":
    test = Test()
    test.runTest()
