class Solution:
    def fib(self, n: int) -> int:
        MOD = int(1e9 + 7)

        if n < 2:
            return n
        a, b = 0, 1
        for _ in range(n):
            # 需要考虑大数越界问题，对1000000007(8个0，最小的十位质数)取余
            a, b = b, (a + b) % MOD
        return a


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, n: int, expected: int):
        result = self.solution.fib(n)

        text = f"Test for {n}"
        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def runTest(self):
        self.checkResult(0, 0)
        self.checkResult(1, 1)
        self.checkResult(2, 1)
        self.checkResult(3, 2)
        self.checkResult(4, 3)
        self.checkResult(5, 5)
        self.checkResult(6, 8)
        self.checkResult(7, 13)
        self.checkResult(8, 21)
        self.checkResult(9, 34)
        self.checkResult(10, 55)
        self.checkResult(40, 102334155)


if __name__ == "__main__":
    test = Test()
    test.runTest()
