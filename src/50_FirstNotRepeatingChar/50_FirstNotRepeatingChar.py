class Solution:
    def firstUniqChar(self, s: str, use_common_hash=False) -> str:
        if not s:
            return " "

        if use_common_hash:
            return self.withCommonHash(s)
        else:
            return self.withLinkedHash(s)

    # 普通哈希表
    def withCommonHash(self, s: str):
        dic = {}
        for c in s:
            dic[c] = not c in dic
        for c in s:
            if dic[c]:
                return c
        return " "

    # 有序哈希表, 键值对按插入顺序排序.
    # 优点是由于哈希表是去重的, 键值对数量 <= 字符串长度.
    # 当字符串很长(重复字符串很多)时, 第二轮遍历的效率更高.
    # Python3.6之后的字典默认就是有序哈希表
    def withLinkedHash(self, s: str):
        dic = {}
        for c in s:
            dic[c] = not c in dic
        for k, v in dic.items():
            if v:
                return k
        return " "


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, s: str, expected: str) -> None:
        text = testName
        result = self.solution.firstUniqChar(s)
        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def runTest(self) -> None:
        self.checkResult("Test1", "google", "l")
        self.checkResult("Test2", "aabccdbd", " ")
        self.checkResult("Test3", "abcdefg", "a")
        self.checkResult("Test4", "", " ")


if __name__ == "__main__":
    test = Test()
    test.runTest()
