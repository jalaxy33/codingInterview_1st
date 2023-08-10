# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


import os
import sys

sys.path.append(os.path.split(sys.path[0])[0])


from Utilities import binary_tree
from Utilities.binary_tree import TreeNode


class Solution:
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        if not A or not B:
            return False
        return (
            self.isAHasB(A, B)
            or self.isSubStructure(A.left, B)
            or self.isSubStructure(A.right, B)
        )

    def isAHasB(self, A: TreeNode, B: TreeNode) -> bool:
        if not B:
            return True
        if not A or A.val != B.val:
            return False
        return self.isAHasB(A.left, B.left) and self.isAHasB(A.right, B.right)


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, A: TreeNode, B: TreeNode, expected: bool):
        text = testName
        result = self.solution.isSubStructure(A, B)
        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    # 树中结点含有分叉，树B是树A的子结构
    #                  8                8
    #              /       \           / \
    #             8         7         9   2
    #           /   \
    #          9     2
    #               / \
    #              4   7
    def Test1(self):
        Avals = [8, 8, 7, 9, 2, 4, 7]
        Bvals = [8, 9, 2]

        Anodes = binary_tree.createTreeNodesVec(Avals)
        Bnodes = binary_tree.createTreeNodesVec(Bvals)

        Aidxs = [
            (0, 1, 2),
            (1, 3, 4),
            (4, 5, 6),
        ]
        Bidxs = [(0, 1, 2)]
        binary_tree.connectTreeNodesIndexVec(Anodes, Aidxs)
        binary_tree.connectTreeNodesIndexVec(Bnodes, Bidxs)

        self.checkResult("Test1", Anodes[0], Bnodes[0], True)

    # 树中结点含有分叉，树B不是树A的子结构
    #                  8                8
    #              /       \           / \
    #             8         7         9   2
    #           /   \
    #          9     3
    #               / \
    #              4   7
    def Test2(self):
        Avals = [8, 8, 7, 9, 3, 4, 7]
        Bvals = [8, 9, 2]

        Anodes = binary_tree.createTreeNodesVec(Avals)
        Bnodes = binary_tree.createTreeNodesVec(Bvals)

        Aidxs = [
            (0, 1, 2),
            (1, 3, 4),
            (4, 5, 6),
        ]
        Bidxs = [(0, 1, 2)]
        binary_tree.connectTreeNodesIndexVec(Anodes, Aidxs)
        binary_tree.connectTreeNodesIndexVec(Bnodes, Bidxs)

        self.checkResult("Test2", Anodes[0], Bnodes[0], False)

    # 树中结点只有左子结点，树B是树A的子结构
    #                8                  8
    #              /                   /
    #             8                   9
    #           /                    /
    #          9                    2
    #         /
    #        2
    #       /
    #      5
    def Test3(self):
        Avals = [8, 8, 9, 2, 5]
        Bvals = [8, 9, 2]

        Anodes = binary_tree.createTreeNodesVec(Avals)
        Bnodes = binary_tree.createTreeNodesVec(Bvals)

        Aidxs = [
            (0, 1, -1),
            (1, 2, -1),
            (2, 3, -1),
            (3, 4, -1),
        ]
        Bidxs = [
            (0, 1, -1),
            (1, 2, -1),
        ]
        binary_tree.connectTreeNodesIndexVec(Anodes, Aidxs)
        binary_tree.connectTreeNodesIndexVec(Bnodes, Bidxs)

        self.checkResult("Test3", Anodes[0], Bnodes[0], True)

    # 树中结点只有左子结点，树B不是树A的子结构
    #                8                  8
    #              /                   /
    #             8                   9
    #           /                    /
    #          9                    3
    #         /
    #        2
    #       /
    #      5
    def Test4(self):
        Avals = [8, 8, 9, 2, 5]
        Bvals = [8, 9, 3]

        Anodes = binary_tree.createTreeNodesVec(Avals)
        Bnodes = binary_tree.createTreeNodesVec(Bvals)

        Aidxs = [
            (0, 1, -1),
            (1, 2, -1),
            (2, 3, -1),
            (3, 4, -1),
        ]
        Bidxs = [
            (0, 1, -1),
            (1, 2, -1),
        ]
        binary_tree.connectTreeNodesIndexVec(Anodes, Aidxs)
        binary_tree.connectTreeNodesIndexVec(Bnodes, Bidxs)

        self.checkResult("Test4", Anodes[0], Bnodes[0], False)

    # 树中结点只有右子结点，树B是树A的子结构
    #       8                   8
    #        \                   \
    #         8                   9
    #          \                   \
    #           9                   2
    #            \
    #             2
    #              \
    #               5
    def Test5(self):
        Avals = [8, 8, 9, 2, 5]
        Bvals = [8, 9, 2]

        Anodes = binary_tree.createTreeNodesVec(Avals)
        Bnodes = binary_tree.createTreeNodesVec(Bvals)

        Aidxs = [
            (0, -1, 1),
            (1, -1, 2),
            (2, -1, 3),
            (3, -1, 4),
        ]
        Bidxs = [
            (0, -1, 1),
            (1, -1, 2),
        ]
        binary_tree.connectTreeNodesIndexVec(Anodes, Aidxs)
        binary_tree.connectTreeNodesIndexVec(Bnodes, Bidxs)

        self.checkResult("Test5", Anodes[0], Bnodes[0], True)

    # 树中结点只有右子结点，树B不是树A的子结构
    #       8                   8
    #        \                   \
    #         8                   9
    #          \                 / \
    #           9               3   2
    #            \
    #             2
    #              \
    #               5
    def Test6(self):
        Avals = [8, 8, 9, 2, 5]
        Bvals = [8, 9, 3, 2]

        Anodes = binary_tree.createTreeNodesVec(Avals)
        Bnodes = binary_tree.createTreeNodesVec(Bvals)

        Aidxs = [
            (0, -1, 1),
            (1, -1, 2),
            (2, -1, 3),
            (3, -1, 4),
        ]
        Bidxs = [
            (0, -1, 1),
            (1, 2, 3),
        ]
        binary_tree.connectTreeNodesIndexVec(Anodes, Aidxs)
        binary_tree.connectTreeNodesIndexVec(Bnodes, Bidxs)

        self.checkResult("Test6", Anodes[0], Bnodes[0], False)

    # 树A为空树
    def Test7(self):
        Bvals = [8, 9, 3, 2]
        Bnodes = binary_tree.createTreeNodesVec(Bvals)

        Bidxs = [
            (0, -1, 1),
            (1, 2, 3),
        ]
        binary_tree.connectTreeNodesIndexVec(Bnodes, Bidxs)

        self.checkResult("Test7", None, Bnodes[0], False)

    # 树B为空树
    def Test8(self):
        Avals = [8, 8, 9, 2, 5]
        Anodes = binary_tree.createTreeNodesVec(Avals)

        Aidxs = [
            (0, -1, 1),
            (1, -1, 2),
            (2, -1, 3),
            (3, -1, 4),
        ]
        binary_tree.connectTreeNodesIndexVec(Anodes, Aidxs)

        self.checkResult("Test8", Anodes[0], None, False)

    # 树A和树B都为空
    def Test9(self):
        self.checkResult("Test9", None, None, False)

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


if __name__ == "__main__":
    test = Test()
    test.runTest()
