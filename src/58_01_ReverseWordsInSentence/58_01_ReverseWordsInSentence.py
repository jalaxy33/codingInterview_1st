class Solution:
    def reverseWords(self, s: str, use_pointer=False) -> str:
        if not s:
            return ""
        
        if use_pointer:
            return self.withPointers(s)
        else:
            return " ".join(reversed(s.split()))
        
    # 快慢指针
    def withPointers(self, s:str) -> str:
        s = s.strip()
        result, i = "", len(s) - 1
        while i >= 0:
            end = i
            # 从右往左搜索首个空格，并添加单词
            while i >= 0 and s[i] != " ":
                i -= 1
            result += s[i + 1 : end + 1] + " "  # 单词间需要空格
            # 跳过单词间原有空格
            while i >= 0 and s[i] == " ":
                i -= 1
        return result[:-1]  # 去掉最后添加的空格并返回



class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, s: str, expected: str) -> None:
        text = testName
        result = self.solution.reverseWords(s)

        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    # 功能测试，句子中有多个单词
    def Test1(self):
        s = "I am a student."
        expected = "student. a am I"

        self.checkResult("Test1", s, expected)

    # 功能测试，句子中只有一个单词
    def Test2(self):
        s = "Wonderful"
        expected = "Wonderful"

        self.checkResult("Test2", s, expected)

    # 边界值测试，测试空字符串
    def Test3(self):
        self.checkResult("Test3", "", "")

    # 边界值测试，字符串中只有空格
    def Test4(self):
        s = "   "
        expected = ""
        self.checkResult("Test4", s, expected)

    def runTest(self):
        self.Test1()
        self.Test2()
        self.Test3()
        self.Test4()


if __name__ == "__main__":
    test = Test()
    test.runTest()
