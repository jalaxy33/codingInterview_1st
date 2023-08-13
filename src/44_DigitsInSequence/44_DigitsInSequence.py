class Solution:
    # 所给序列即0,1,2,...排列得到的序列。
    # 按照位数将序列分段，先确定所求数位的所在数字的位数，
    # 然后确认其在哪个数字的第几位。
    def findNthDigit(self, n: int) -> int:
        if n < 0:
            return -1
        if n == 0:
            return 0

        # 一位数 (1~9) 的数位数量为9，二位数 (10~99)的数位数量为2*9*10=180
        # 三位数 (100~999)的数位数量为3*9*100。可推知
        # 当前位数的数字数量 count = 9 * i(位数) * digit(10^位数)

        i, digit, count = 1, 1, 9
        # 1）确认n所在数字的位数
        while n > count:
            n -= count
            digit *= 10
            i += 1
            count = 9 * i * digit

        # 2）确认n所在的数字，此时n已经减过之前分段的数字数量了。
        # 每一段的数字从digit开始。
        num = digit + (n - 1) / i

        # 3）所求数位是所在数字的第 (n-1)%i 位，先将数字转换为字符串，
        # 方便索引求得数位值，然后再转换为整型
        return int(str(num)[(n - 1) % i])


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, n: int, expected: int) -> None:
        text = testName
        result = self.solution.findNthDigit(n)
        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def runTest(self) -> None:
        self.checkResult("Test1", 0, 0)
        self.checkResult("Test2", 1, 1)
        self.checkResult("Test3", 9, 9)
        self.checkResult("Test4", 10, 1)
        self.checkResult("Test5", 189, 9)  # 数字99的最后一位，9
        self.checkResult("Test6", 190, 1)  # 数字100的第一位，1
        self.checkResult("Test7", 1000, 3)  # 数字370的第一位，3
        self.checkResult("Test8", 1001, 7)  # 数字370的第二位，7
        self.checkResult("Test9", 1002, 0)  # 数字370的第三位，0


if __name__ == "__main__":
    test = Test()
    test.runTest()
