# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()


class CQueue:
    def __init__(self):
        self.A = []
        self.B = []

    def appendTail(self, value: int) -> None:
        self.A.append(value)

    def deleteHead(self) -> int:
        if self.B:
            return self.B.pop()

        if not self.A:
            return -1

        while self.A:
            self.B.append(self.A.pop())
        return self.B.pop()


class Test:
    def __init__(self):
        self.queue = CQueue()

    def checkResults(self, text: str, actual: int, expected: int):
        if actual == expected:
            print(f"{text} passed.")
        else:
            print(f"{text} failed.")

    def runTest(self):
        self.queue.appendTail(1)
        self.queue.appendTail(2)
        self.queue.appendTail(3)

        head = self.queue.deleteHead()
        self.checkResults("delete 1", head, 1)

        head = self.queue.deleteHead()
        self.checkResults("delete 2", head, 2)

        self.queue.appendTail(4)
        head = self.queue.deleteHead()
        self.checkResults("delete 3", head, 3)

        self.queue.appendTail(5)
        head = self.queue.deleteHead()
        self.checkResults("delete 4", head, 4)

        head = self.queue.deleteHead()
        self.checkResults("delete 5", head, 5)


if __name__ == "__main__":
    test = Test()
    test.runTest()
