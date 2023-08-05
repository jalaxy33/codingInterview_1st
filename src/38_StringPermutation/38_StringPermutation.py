class Solution:
    def permutation(self, s: str) -> list[str]:
        # python中str不可变，先转换为list
        result, s = [], list(s)

        def dfs(index: int) -> None:
            if index == len(s) - 1:
                # 输出前先将list转换回str
                result.append("".join(s))
                return
            st = set()
            for i in range(index, len(s)):
                if s[i] in st:
                    continue
                st.add(s[i])
                s[i], s[index] = s[index], s[i]
                dfs(index + 1)
                s[i], s[index] = s[index], s[i]

        dfs(0)
        return result


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, s: str):
        print(f"==== {testName} ====")
        print(s)

        result = self.solution.permutation(s)
        print(result, "\n")

    def runTest(self):
        self.checkResult("Test1", "")
        self.checkResult("Test2", "a")
        self.checkResult("Test3", "ab")
        self.checkResult("Test4", "abc")


if __name__ == "__main__":
    test = Test()
    test.runTest()
