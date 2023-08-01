class Solution:
    # 动态规划
    def maxProfit(self, prices: list[int]) -> int:
        cost, profit = float("+inf"), float("-inf")  # python表示无穷大
        for price in prices:
            profit = max(profit, price - cost)
            cost = min(cost, price)
        # 利润为负时不交易，利润返回0
        return 0 if profit < 0 else profit


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, prices: list[int], expected: int):
        text = testName if testName else ""

        result = self.solution.maxProfit(prices)
        if result == expected or expected < 0 and result == 0:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def Test1(self):
        numbers = [4, 1, 3, 2, 5]
        self.checkResult("Test1", numbers, 4)

    # 价格递增
    def Test2(self):
        numbers = [1, 2, 4, 7, 11, 16]
        self.checkResult("Test2", numbers, 15)

    # 价格递减
    def Test3(self):
        numbers = [16, 11, 7, 4, 2, 1]
        self.checkResult("Test3", numbers, -1)

    # 价格全部相同
    def Test4(self):
        numbers = [16, 16, 16, 16, 16]
        self.checkResult("Test4", numbers, 0)

    def Test5(self):
        numbers = [9, 11, 5, 7, 16, 1, 4, 2]
        self.checkResult("Test5", numbers, 11)

    def Test6(self):
        numbers = [2, 4]
        self.checkResult("Test6", numbers, 2)

    def Test7(self):
        numbers = [4, 2]
        self.checkResult("Test7", numbers, -2)

    def Test8(self):
        numbers = []
        self.checkResult("Test8", numbers, 0)

    def Test9(self):
        numbers = [7, 6, 4, 3, 1]
        self.checkResult("Test9", numbers, -1)

    def runTest(self):
        self.Test1()
        self.Test2()
        self.Test3()
        self.Test4()
        self.Test5()
        self.Test6()
        self.Test7()
        self.Test8()
        self.Test9()


if __name__ == "__main__":
    test = Test()
    test.runTest()
