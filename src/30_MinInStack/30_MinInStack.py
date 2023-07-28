# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.min()

import math

class MinStack:
    def __init__(self):
        self.A, self.B = [], [math.inf]

    def push(self, x: int) -> None:
        self.A.append(x)
        self.B.append(min(x, self.B[-1]))

    def pop(self) -> None:
        self.A.pop()
        self.B.pop()

    def top(self) -> int:
        return self.A[-1]

    def min(self) -> int:
        return self.B[-1]


class Test:
    def checkResult(self, testName: str, stk: MinStack, expected: int):
        text = testName if testName else ""
        if stk.min() == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def runTest(self):
        stk = MinStack()

        stk.push(3)
        self.checkResult("Test1", stk, 3)
        stk.push(4)
        self.checkResult("Test2", stk, 3)
        stk.push(2)
        self.checkResult("Test3", stk, 2)
        stk.push(3)
        self.checkResult("Test4", stk, 2)
        stk.pop()
        self.checkResult("Test5", stk, 2)
        stk.pop()
        self.checkResult("Test6", stk, 3)
        stk.pop()
        self.checkResult("Test7", stk, 3)
        stk.push(0)
        self.checkResult("Test8", stk, 0)


if __name__ == "__main__":
    test = Test()
    test.runTest()
