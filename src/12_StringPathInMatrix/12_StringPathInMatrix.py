class Solution:
    # dfs+剪枝
    def exist(self, board: list[list[str]], word: str) -> bool:
        rows, cols = len(board), len(board[0])

        def dfs(i: int, j: int, k: int) -> bool:
            if not 0 <= i < rows or not 0 <= j < cols or board[i][j] != word[k]:
                return False
            if k == len(word) - 1:
                return True

            board[i][j] = ""
            result = (
                dfs(i - 1, j, k + 1)
                or dfs(i + 1, j, k + 1)
                or dfs(i, j - 1, k + 1)
                or dfs(i, j + 1, k + 1)
            )
            board[i][j] = word[k]
            return result

        for i in range(rows):
            for j in range(cols):
                if dfs(i, j, 0):
                    return True
        return False


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(
        self, testName: str, board: list[list[str]], word: str, expected: bool
    ):
        text = testName if testName else ""

        result = self.solution.exist(board, word)
        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    # ABCE
    # SFCS
    # ADEE

    # SEE
    def Test1(self):
        board = [
            ["A", "B", "C", "E"],
            ["S", "F", "C", "S"],
            ["A", "D", "E", "E"],
        ]
        word = "SEE"
        self.checkResult("Test1", board, word, True)

    # ABTG
    # CFCS
    # JDEH

    # BFCE
    def Test2(self):
        board = [
            ["A", "B", "T", "G"],
            ["C", "F", "C", "S"],
            ["J", "D", "E", "H"],
        ]
        word = "BFCE"
        self.checkResult("Test2", board, word, True)

    # ABTG
    # CFCS
    # JDEH

    # ABFB
    def Test3(self):
        board = [
            ["A", "B", "T", "G"],
            ["C", "F", "C", "S"],
            ["J", "D", "E", "H"],
        ]
        word = "ABFB"
        self.checkResult("Test3", board, word, False)

    # ABCEHJIG
    # SFCSLOPQ
    # ADEEMNOE
    # ADIDEJFM
    # VCEIFGGS

    # SLHECCEIDEJFGGFIE
    def Test4(self):
        board = [
            ["A", "B", "C", "E", "H", "J", "I", "G"],
            ["S", "F", "C", "S", "L", "O", "P", "Q"],
            ["A", "D", "E", "E", "M", "N", "O", "E"],
            ["A", "D", "I", "D", "E", "J", "F", "M"],
            ["V", "C", "E", "I", "F", "G", "G", "S"],
        ]
        word = "SLHECCEIDEJFGGFIE"
        self.checkResult("Test4", board, word, True)

    # ABCEHJIG
    # SFCSLOPQ
    # ADEEMNOE
    # ADIDEJFM
    # VCEIFGGS

    # SGGFIECVAASABCEHJIGQEM
    def Test5(self):
        board = [
            ["A", "B", "C", "E", "H", "J", "I", "G"],
            ["S", "F", "C", "S", "L", "O", "P", "Q"],
            ["A", "D", "E", "E", "M", "N", "O", "E"],
            ["A", "D", "I", "D", "E", "J", "F", "M"],
            ["V", "C", "E", "I", "F", "G", "G", "S"],
        ]
        word = "SGGFIECVAASABCEHJIGQEM"
        self.checkResult("Test5", board, word, True)

    # ABCEHJIG
    # SFCSLOPQ
    # ADEEMNOE
    # ADIDEJFM
    # VCEIFGGS

    # SGGFIECVAASABCEEJIGOEM
    def Test6(self):
        board = [
            ["A", "B", "C", "E", "H", "J", "I", "G"],
            ["S", "F", "C", "S", "L", "O", "P", "Q"],
            ["A", "D", "E", "E", "M", "N", "O", "E"],
            ["A", "D", "I", "D", "E", "J", "F", "M"],
            ["V", "C", "E", "I", "F", "G", "G", "S"],
        ]
        word = "SGGFIECVAASABCEEJIGOEM"
        self.checkResult("Test6", board, word, False)

    # ABCEHJIG
    # SFCSLOPQ
    # ADEEMNOE
    # ADIDEJFM
    # VCEIFGGS

    # SGGFIECVAASABCEHJIGQEMS
    def Test7(self):
        board = [
            ["A", "B", "C", "E", "H", "J", "I", "G"],
            ["S", "F", "C", "S", "L", "O", "P", "Q"],
            ["A", "D", "E", "E", "M", "N", "O", "E"],
            ["A", "D", "I", "D", "E", "J", "F", "M"],
            ["V", "C", "E", "I", "F", "G", "G", "S"],
        ]
        word = "SGGFIECVAASABCEHJIGQEMS"
        self.checkResult("Test7", board, word, False)

    # AAAA
    # AAAA
    # AAAA

    # AAAAAAAAAAAA
    def Test8(self):
        board = [
            ["A", "A", "A", "A"],
            ["A", "A", "A", "A"],
            ["A", "A", "A", "A"],
        ]
        word = "AAAAAAAAAAAA"
        self.checkResult("Test8", board, word, True)

    # AAAA
    # AAAA
    # AAAA

    # AAAAAAAAAAAAA
    def Test9(self):
        board = [
            ["A", "A", "A", "A"],
            ["A", "A", "A", "A"],
            ["A", "A", "A", "A"],
        ]
        word = "AAAAAAAAAAAAA"
        self.checkResult("Test9", board, word, False)

    # A

    # A
    def Test10(self):
        board = [["A"]]
        word = "A"
        self.checkResult("Test10", board, word, True)

    # A

    # B
    def Test11(self):
        board = [["A"]]
        word = "B"
        self.checkResult("Test11", board, word, False)

    def Test12(self):
        board = []
        word = ""
        self.checkResult("Test12", board, word, False)

    def runTest(self):
        self.Test1()
        self.Test2()
        self.Test3()
        self.Test4()
        self.Test5()
        self.Test6()
        self.Test7()
        self.Test8()
        self.Test9()
        self.Test10()
        self.Test11()


if __name__ == "__main__":
    test = Test()
    test.runTest()
