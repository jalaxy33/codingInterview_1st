class Solution:
    def printNumbers(self, n: int, with_recur: bool = False) -> list[int]:
        if n <= 0:
            return []

        if with_recur:
            return self.printWithRecur(n)
        else:
            return self.printWithIter(n)

    def printWithRecur(self, n: int) -> list[int]:
        def recur(n: int, count: int, number: str) -> None:
            # 终止条件：处理到最后一位
            if count == n:
                # 不保存高位是零的数
                if number[0] != "0":
                    results.append(int(number))
                return
            for index in range(10):
                # 一位数单独处理，从而避免高位有零的情况
                if number and number[0] == "0":  # 处理非零一位数
                    recur(n, count + 1, str(index))
                else:  # 处理其他情况：0以及多位数。由于高位肯定非零，直接拼接即可
                    recur(n, count + 1, number + str(index))

        results = []
        recur(n, 0, "")
        return results

    def printWithIter(self, n: int) -> list[int]:
        results, end = [], pow(10, n)
        for i in range(1, end):
            results.append(i)
        return results


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, n: int) -> None:
        print(f"==== {testName}")
        print(f"n={n}")
        result = self.solution.printNumbers(n)
        print(result, "\n")

    def runTest(self) -> None:
        self.checkResult("Test1", 1)
        self.checkResult("Test2", 2)
        self.checkResult("Test3", 3)
        self.checkResult("Test4", 0)
        self.checkResult("Test5", -1)


if __name__ == "__main__":
    test = Test()
    test.runTest()
