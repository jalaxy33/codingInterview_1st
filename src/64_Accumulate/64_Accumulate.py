class Solver:
    """解法类的基类"""

    def __init__(self):
        self.result = 0

    def sum(self, n: int) -> int:
        pass

    def reset(self) -> None:
        self.result = 0


# ==============================
# 解法1：利用逻辑运算的短路效应+递归
class Solver1(Solver):
    def sum(self, n: int) -> int:
        (not not n) and self.sum(n - 1)
        self.result += n
        return self.result


# =============================
# 解法2：利用类数组实现递归（对应于C++中的虚函数）


class Solver2_A:
    """基类"""

    def getSum(self, n: int) -> int:
        return 0


class Solver2_B(Solver2_A):
    """子类"""

    def __init__(self, arr: list[Solver2_A]):
        self.arr: list[Solver2_A] = arr

    def getSum(self, n: int) -> int:
        # 利用短路运算充当真假判断：!n==false, !!n==true
        return n + self.arr[not not n].getSum(n - 1)


class Solver2(Solver):
    def __init__(self):
        super().__init__()

        # 定义存储两种情况的数组
        self.cls_l = [Solver2_A(), Solver2_B([])]
        self.cls_l[1].arr = self.cls_l

    def sum(self, n: int) -> int:
        return self.cls_l[1].getSum(n)  # 递归的起点


# ===============================
# 解法3：利用函数数组实现递归（对应于C++中的函数指针）


class Solver3(Solver):
    def __init__(self):
        super().__init__()
        # 利用python的函数闭包轻松构建函数数组
        self.f = [self.terminate, self.recur]

    def sum(self, n: int) -> int:
        return self.recur(n)

    def recur(self, n: int) -> int:
        return n + self.f[not not n](n - 1)

    def terminate(self, n: int) -> int:
        return 0


# ===============================
class Solution:
    def __init__(self) -> None:
        self.solvers: list[Solver] = [
            None,
            Solver1(),
            Solver2(),
            Solver3(),
        ]

    # solver_i取值范围为1到3，对应3种解法
    def sumNums(self, n: int, solver_i: int = 3) -> int:
        if solver_i:
            solver = self.solvers[solver_i]
            solver.reset()
            return solver.sum(n)
        else:
            return 0


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, n: int, expected: int) -> None:
        text = testName
        result = self.solution.sumNums(n)

        text += f": result={result}, expected={expected},"

        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    def runTest(self) -> None:
        self.checkResult("Test1", 1, 1)
        self.checkResult("Test2", 5, 15)
        self.checkResult("Test3", 10, 55)
        self.checkResult("Test4", 0, 0)


if __name__ == "__main__":
    test = Test()
    test.runTest()
