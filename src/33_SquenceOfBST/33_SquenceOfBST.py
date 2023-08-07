class Solution:
    def verifyPostorder(self, postorder: list[int], use_recur:bool=False) -> bool:
        if not postorder:
            return True
        
        if use_recur:
            return self.withRecur(postorder)
        else:
            return self.withStack(postorder)
                
    # 递归法
    def withRecur(self, postorder: list[int]) -> bool:
        # 递归[i,j]区间，后序中j为根节点
        def recur(i:int, j:int) -> bool:
            if i >= j :
                return True
            # 划分左右子树
            # 找到第一个大于根节点的节点，记为m
            p = i
            while postorder[p] < postorder[j]:
                p += 1
            m = p
            # 右区间内所有元素都应该大于根节点
            while postorder[p] > postorder[j]:
                p += 1
            return p == j and recur(i,m-1) and recur(m, j-1)
        return recur(0, len(postorder)-1)
    
    # 利用辅助单调栈。
    # 左子树<根<右子树，满足一定的单调性。
    # 倒序遍历后序列表，按顺序根节点和右子树先入栈
    # 此时栈内元素单调递增，栈顶永远是当前最大。
    # 每当遇到递减的节点（即进入左子树），则使栈顶出栈并成为新的curMax。
    # 每轮遍历判断当前节点ri与root的关系：
    # 1）若ri>curMax，说明不符合搜索树定义，return false。
    # 2）否则，继续遍历
    def withStack(self, postorder: list[int]) -> bool:
        stk, curMax = [], float("inf")
        # 倒序遍历后序列表
        for i in range(len(postorder)-1, -1, -1):
            if postorder[i] > curMax:
                return False
            while stk and stk[-1] > postorder[i]:
                curMax = stk.pop()
            stk.append(postorder[i])
        return True


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, postorder: list[int], expected: bool) -> None:
        text = testName
        result = self.solution.verifyPostorder(postorder)
        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    #            10
    #         /      \
    #        6        14
    #       /\        /\
    #      4  8     12  16
    def Test1(self):
        postorder = [4, 8, 6, 12, 16, 14, 10]
        self.checkResult("Test1", postorder, True)

    #           5
    #          / \
    #         4   7
    #            /
    #           6
    def Test2(self):
        postorder = [4, 6, 7, 5]
        self.checkResult("Test2", postorder, True)

    #               5
    #              /
    #             4
    #            /
    #           3
    #          /
    #         2
    #        /
    #       1
    def Test3(self):
        postorder = [1, 2, 3, 4, 5]
        self.checkResult("Test3", postorder, True)

    # 1
    #  \
    #   2
    #    \
    #     3
    #      \
    #       4
    #        \
    #         5
    def Test4(self):
        postorder = [5, 4, 3, 2, 1]
        self.checkResult("Test4", postorder, True)

    # 树中只有1个结点
    def Test5(self):
        postorder = [5]
        self.checkResult("Test5", postorder, True)

    # 不是后序遍历
    def Test6(self):
        postorder = [7, 4, 6, 5]
        self.checkResult("Test6", postorder, False)

    # 不是后序遍历
    def Test7(self):
        postorder = [4, 6, 12, 8, 16, 14, 10]
        self.checkResult("Test7", postorder, False)

    # 空列表
    def Test8(self):
        postorder = []
        self.checkResult("Test8", postorder, True)

    def runTest(self):
        self.Test1()
        self.Test2()
        self.Test3()
        self.Test4()
        self.Test5()
        self.Test6()
        self.Test7()
        self.Test8()


if __name__ == "__main__":
    test = Test()
    test.runTest()
