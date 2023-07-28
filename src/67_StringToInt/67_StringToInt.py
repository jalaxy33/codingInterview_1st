from enum import Enum

Status = Enum("Status", ("sValid", "sInvalid"))
g_status = Status.sValid


class Solution:
    def strToInt(self, s: str) -> int:
        global g_status
        g_status = Status.sInvalid

        result, i, sign, length = 0, 0, 1, len(s)
        INT_MAX, INT_MIN, boundary = 2**31 - 1, -(2**31), 2**31 // 10
        if length == 0:
            return 0
        # 忽略开头的空格
        while s[i] == " ":
            i += 1
            if i == length:
                return 0
        # 处理正负号
        if s[i] == "-":
            sign = -1
        if s[i] in "+-":
            i += 1
        # 处理其他字符
        hasDigit = False
        for j in range(i, length):
            if s[j] < "0" or s[j] > "9":
                break
            if result > boundary or result == boundary and s[j] > "7":
                g_status = Status.sValid
                return INT_MAX if sign == 1 else INT_MIN
            # ord库函数将Unicode字符转换为对应的数字
            result = result * 10 + (ord(s[j]) - ord("0"))
            hasDigit = True
        if hasDigit:
            g_status = Status.sValid
        return sign * result


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, s: str) -> None:
        result = self.solution.strToInt(s)
        global g_status
        if result == 0 and g_status == Status.sInvalid:
            print(f"the input {s} is invalid.")
        else:
            print(f"number for {s} is {result}.")

    def runTest(self):
        self.checkResult("")

        self.checkResult("123")

        self.checkResult("+123")

        self.checkResult("-123")

        self.checkResult("1a33")

        self.checkResult("+0")

        self.checkResult("-0")

        # 有效的最大正整数, 0x7FFFFFFF
        self.checkResult("+2147483647")

        self.checkResult("-2147483647")

        self.checkResult("+2147483648")

        # 有效的最小负整数, 0x80000000
        self.checkResult("-2147483648")

        self.checkResult("+2147483649")

        self.checkResult("-2147483649")

        self.checkResult("+")

        self.checkResult("-")


if __name__ == "__main__":
    test = Test()
    test.runTest()
