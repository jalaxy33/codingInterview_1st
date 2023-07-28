class Solution:
    def isNumber(self, s: str) -> bool:
        if not s:
            return False
        isDigit, isDot, isE = False, False, False

        # 去除首尾空格
        s_ = s.strip()
        # 遍历每个字符
        for i, c in enumerate(s_):
            if c >= "0" and c <= "9":
                isDigit = True
            elif c == ".":
                if isDot or isE:
                    return False
                isDot = True
            elif c == "e" or c == "E":
                if not isDigit or isE:
                    return False
                isE = True
                isDigit = False
            elif c == "+" or c == "-":
                if i != 0 and s_[i - 1] != "e" and s_[i - 1] != "E":
                    return False
            else:
                return False
        return isDigit


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, s: str, expected: bool) -> None:
        text = testName if testName else ""
        if self.solution.isNumber(s) == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def runTest(self) -> None:
        self.checkResult("Test1", "100", True)
        self.checkResult("Test2", "123.45e+6  ", True)
        self.checkResult("Test3", "+500   ", True)
        self.checkResult("Test4", " 5e2", True)
        self.checkResult("Test5", "3.1416", True)
        self.checkResult("Test6", "  600.", True)
        self.checkResult("Test7", "-.123", True)
        self.checkResult("Test8", "-1E-16  ", True)
        self.checkResult("Test9", "1.79769313486232E+308", True)

        print("\n")

        self.checkResult("Test10", "12e", False)
        self.checkResult("Test11", "1a3.14", False)
        self.checkResult("Test12", "1+23", False)
        self.checkResult("Test13", "1.2.3", False)
        self.checkResult("Test14", "+-5", False)
        self.checkResult("Test15", "12e+5.4", False)
        self.checkResult("Test16", ".", False)
        self.checkResult("Test17", ".e1", False)
        self.checkResult("Test18", "e1", False)
        self.checkResult("Test19", "+.", False)
        self.checkResult("Test20", "", False)
        self.checkResult("Test21", "   ", False)
        self.checkResult("Test22", " .  ", False)


if __name__ == "__main__":
    test = Test()
    test.runTest()
