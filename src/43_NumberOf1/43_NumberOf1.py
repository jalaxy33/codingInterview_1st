class Solution:
    # 从低位到高位遍历数字的各位，每次将数字分为 high | cur | low 三部分。
    # 例如2314，遍历到十位时，high=23，cur=1，low=4。
    # 统计各位上1的个数。
    def countDigitOne(self, n: int) -> int:
        # digit用以表示当前遍历的数位，初始为个位，后续会*10。
        digit, result = 1, 0
        high, cur, low = n // 10, n % 10, 0

        # cur数值的不同，决定了该位上1的数量：
        # 1）当cur为0时，如2304的十位，十位为1的数字可能是 0010~2219，
        # 只看高低位 000~229，共230种可能性。此时1的个数 = high * digit,
        # 只由高位决定。
        # 2）当cur为1时，如2314的十位，十位为1的数字可能是 0010~2314，
        # 共 234-0+1=235 种可能。也可以理解为 2304+14，比第一种情况要多算
        # 10~14 的情况。1的个数 = high * digit + low + 1。
        # 3）当cur为2~9时，如2324的十位，十位为1的数字的可能是 0010~2319，
        # 共 239-0+1=240 种可能。也可以理解为 2304+19，比第一种情况要多算
        # 10~19 的情况。1的个数 = high * digit + digit = (high + 1) * digit

        # digit从低位到高位进行遍历，直到 high==0 && cur==0
        while high or cur:
            # 算result
            if cur == 0:
                result += high * digit
            elif cur == 1:
                result += high * digit + low + 1
            else:
                result += (high + 1) * digit
            # 左移数位
            low += cur * digit
            cur = high % 10
            high //= 10
            digit *= 10
        return result


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, n: int, expected: int) -> None:
        text = testName
        result = self.solution.countDigitOne(n)
        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def runTest(self) -> None:
        self.checkResult("Test1", 1, 1)
        self.checkResult("Test2", 5, 1)
        self.checkResult("Test3", 10, 2)
        self.checkResult("Test4", 55, 16)
        self.checkResult("Test5", 99, 20)
        self.checkResult("Test6", 10000, 4001)
        self.checkResult("Test7", 21345, 18821)
        self.checkResult("Test8", 0, 0)


if __name__ == "__main__":
    test = Test()
    test.runTest()
