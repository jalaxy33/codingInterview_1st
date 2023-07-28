class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        return s[n:] + s[:n]


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, inputStr: str, num: int, expectedStr: str):
        text = testName if testName else ""
        resultStr = self.solution.reverseLeftWords(inputStr, num)
        if (not inputStr and not expectedStr) or (inputStr and resultStr == expectedStr):
            text += " passed."
        else:
            text += " failed."
        print(text)
        
    
    def runTest(self):
        self.checkResult("Test1", "abcdefg", 2, "cdefgab" )
        self.checkResult("Test2", "abcdefg", 1, "bcdefga" )
        self.checkResult("Test3", "abcdefg", 6, "gabcdef" )
        self.checkResult("Test4", "", 6, "" )
        self.checkResult("Test5", "abcdefg", 0, "abcdefg" )
        self.checkResult("Test6", "abcdefg", 7, "abcdefg" )


if __name__ == "__main__":
    test = Test()
    test.runTest()
