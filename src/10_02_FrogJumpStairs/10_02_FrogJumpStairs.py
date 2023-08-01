class Solution:
    def numWays(self, n: int) -> int:
        if n < 2:
            return 1
        MOD = int(1e9 + 7)
        a, b = 1, 1
        for _  in range(n):
            a, b = b, (a + b) % MOD
        return a


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, n:int, expected:int):
        result = self.solution.numWays(n)

        text = f"Test for {n}"
        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def runTest(self):
        self.checkResult( 0, 1 )
        self.checkResult( 1, 1 )
        self.checkResult( 2, 2 )
        self.checkResult( 3, 3 )
        self.checkResult( 4, 5 )
        self.checkResult( 5, 8 )
        self.checkResult( 6, 13 )
        self.checkResult( 7, 21 )
        self.checkResult( 8, 34 )
        self.checkResult( 9, 55 )
        self.checkResult( 10, 89 )
        self.checkResult( 40, 165580141 )


if __name__ == "__main__":
    test = Test()
    test.runTest()