class Solution:
    # 借用一个辅助栈，模拟压入/弹出操作是否成功
    def validateStackSequences(self, pushed: list[int], popped: list[int]) -> bool:
        if not pushed and not popped:
            return True
        if not pushed or not popped:
            return False

        stk, i = [], 0
        for num in pushed:
            stk.append(num)
            while stk and stk[-1] == popped[i]:
                stk.pop()
                i += 1
        return not stk


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(
        self, testName: str, pushed: list[int], popped: list[int], expected: bool
    ) -> None:
        text = testName
        result = self.solution.validateStackSequences(pushed, popped)
        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def Test1(self):
        pushed = [1, 2, 3, 4, 5]
        popped = [4, 5, 3, 2, 1]

        self.checkResult("Test1", pushed, popped, True)

    def Test2(self):
        pushed = [1, 2, 3, 4, 5]
        popped = [3, 5, 4, 2, 1]

        self.checkResult("Test2", pushed, popped, True)

    def Test3(self):
        pushed = [1, 2, 3, 4, 5]
        popped = [4, 3, 5, 1, 2]

        self.checkResult("Test3", pushed, popped, False)

    def Test4(self):
        pushed = [1, 2, 3, 4, 5]
        popped = [3, 5, 4, 1, 2]

        self.checkResult("Test4", pushed, popped, False)

    # push和pop序列只有一个数字
    def Test5(self):
        pushed = [1]
        popped = [2]

        self.checkResult("Test5", pushed, popped, False)

    def Test6(self):
        pushed = [1]
        popped = [1]

        self.checkResult("Test6", pushed, popped, True)

    def Test7(self):
        pushed = []
        popped = []
        self.checkResult("Test7", pushed, popped, True)

    def Test8(self):
        pushed = []
        popped = [1]
        self.checkResult("Test8", pushed, popped, False)

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
