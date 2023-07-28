class Solution:
    def replaceSpace(self, s: str) -> str:
        # 直接调用str的api
        # return s.replace(" ", "%20")

        # 由于python中字符串不可变，因此需要新建字符串
        res = ""
        for c in s:
            if c == " ":
                res = res + "%20"
            else:
                res = res + c
        return res


class Test:
    def __init__(self):        
        self.solution = Solution()

    def testMain(self, testName: str, inputStr: str, expectedStr: str):
        if len(testName) > 0:
            text = testName + " begins: "

        resultStr = self.solution.replaceSpace(inputStr)

        # text += f"input: {inputStr}| result: {resultStr}| expected: {expectedStr}|"

        if len(expectedStr) == 0 and len(resultStr) == 0:
            text += "passed."
        elif len(expectedStr) == 0 and len(resultStr) > 0:
            text += "failed."
        elif expectedStr == resultStr:
            text += "passed."
        else:
            text += "failed."

        print(text)

    # 空格在句子中间
    def Test1(self):
        str = "hello world"
        self.testMain("Test1", str, "hello%20world")

    # 空格在句子开头
    def Test2(self):
        str = " helloworld"
        self.testMain("Test2", str, "%20helloworld")

    # 空格在句子末尾
    def Test3(self):
        str = "helloworld "
        self.testMain("Test3", str, "helloworld%20")

    # 连续有两个空格
    def Test4(self):
        str = "hello  world"
        self.testMain("Test4", str, "hello%20%20world")

    # 传入空字符串
    def Test5(self):
        self.testMain("Test5", "", "")

    # 传入内容为空的字符串
    def Test6(self):
        str = ""
        self.testMain("Test6", str, "")

    # 传入内容为一个空格的字符串
    def Test7(self):
        str = " "
        self.testMain("Test7", str, "%20")

    # 传入的字符串没有空格
    def Test8(self):
        str = "helloworld"
        self.testMain("Test8", str, "helloworld")

    # 传入的字符串全是空格
    def Test9(self):
        str = "   "
        self.testMain("Test9", str, "%20%20%20")

    def runTests(self):
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
    test.runTests()
