class Solution:
    def movingCount(self, m: int, n: int, k: int, use_dfs=False) -> int:
        visited = set() # 用可动态增长的集合来记录是否已访问
        if use_dfs:
            return self.dfs(0, 0, m, n, k, visited)
        else:
            return self.bfs(m, n, k, visited)

    def dfs(self, i: int, j: int, m: int, n: int, k: int, visited: set) -> int:
        if i >= m or j >= n or (i, j) in visited or self.digitSum(i, j) > k:
            return 0

        visited.add((i, j))
        result = (
            1
            + self.dfs(i + 1, j, m, n, k, visited)
            + self.dfs(i, j + 1, m, n, k, visited)
        )
        return result

    def bfs(self, m: int, n: int, k: int, visited: set):
        q = [(0,0)] # 将起点入队
        while q:
            # 将队首单元格出队
            i, j = q.pop(0)
            # 判断是否跳过该单元格
            if i >= m or j >= n or (i, j) in visited or self.digitSum(i, j) > k:
                continue
            # 标记当前单元格，更新步长
            visited.add((i, j))
            # 将下方和右方单元格入队，以继续遍历
            q.append((i + 1, j))
            q.append((i, j + 1))
        # 返回集合的长度
        return len(visited) 

    def digitSum(self, i: int, j: int) -> int:
        return i % 10 + i // 10 + j % 10 + j // 10


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, m: int, n: int, k: int, expected: int):
        text = testName if testName else ""

        result = self.solution.movingCount(m, n, k)
        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def runTest(self):
        # 方格多行多列
        self.checkResult("Test1", 10, 10, 5, 21)
        # 方格多行多列
        self.checkResult("Test2", 20, 20, 15, 359)
        # 方格只有一行，机器人只能到达部分方格
        self.checkResult("Test3", 1, 100, 10, 29)
        # 方格只有一行，机器人能到达所有方格
        self.checkResult("Test4", 1, 10, 10, 10)
        # 方格只有一列，机器人只能到达部分方格
        self.checkResult("Test5", 100, 1, 15, 79)
        # 方格只有一列，机器人能到达所有方格
        self.checkResult("Test6", 10, 1, 15, 10)
        # 方格只有一行一列
        self.checkResult("Test7", 1, 1, 15, 1)
        # 方格只有一行一列
        self.checkResult("Test8", 1, 1, 0, 1)
        # 机器人不能进入任意一个方格
        self.checkResult("Test9", 10, 10, -10, 0)


if __name__ == "__main__":
    test = Test()
    test.runTest()
