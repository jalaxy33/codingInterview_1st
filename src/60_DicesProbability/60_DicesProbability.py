class Solution:
    # 动态规划
    def dicesProbability(self, n: int, FACES=6) -> list[float]:
        if n < 1:
            return []

        dp = [1.0 / FACES] * FACES
        for i in range(2, n + 1):
            tmp = [0] * (FACES * i - i + 1)
            for j in range(len(dp)):
                for k in range(FACES):
                    tmp[j + k] += dp[j] / FACES
            dp = tmp
        return dp


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, n: int):
        text = testName + ", " if testName else ""
        text += f"n={n}: "
        results = self.solution.dicesProbability(n)
        text += f"{results}\n"
        print(text)

    def runTest(self):
        self.checkResult("Test1", 1)
        self.checkResult("Test2", 2)
        self.checkResult("Test3", 3)
        self.checkResult("Test4", 4)
        self.checkResult("Test5", 11)
        self.checkResult("Test6", 0)


if __name__ == "__main__":
    test = Test()
    test.runTest()
