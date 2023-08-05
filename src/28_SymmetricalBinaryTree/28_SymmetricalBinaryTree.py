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
from Utilities.binary_tree import BinaryTreeNode as TreeNode


class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        return not root or self.recur(root.left, root.right)

    def recur(self, lNode: TreeNode, rNode: TreeNode) -> bool:
        if not lNode and not rNode:
            return True
        if not lNode or not rNode or lNode.val != rNode.val:
            return False
        return self.recur(lNode.left, rNode.right) and self.recur(
            lNode.right, rNode.left
        )


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, root: TreeNode, expected: bool):
        text = testName
        result = self.solution.isSymmetric(root)
        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    #            8
    #        6      6
    #       5 7    7 5
    def Test1(self):
        vals = [8, 6, 6, 5, 7, 7, 5]
        nodes = binary_tree.createNodesVec(vals)

        binary_tree.connectNodesIndex(nodes, 0, 1, 2)
        binary_tree.connectNodesIndex(nodes, 1, 3, 4)
        binary_tree.connectNodesIndex(nodes, 2, 5, 6)

        self.checkResult("Test1", nodes[0], True)

    #            8
    #        6      9
    #       5 7    7 5
    def Test2(self):
        vals = [8, 6, 9, 5, 7, 7, 5]
        nodes = binary_tree.createNodesVec(vals)

        binary_tree.connectNodesIndex(nodes, 0, 1, 2)
        binary_tree.connectNodesIndex(nodes, 1, 3, 4)
        binary_tree.connectNodesIndex(nodes, 2, 5, 6)

        self.checkResult("Test2", nodes[0], False)

    #            8
    #        6      6
    #       5 7    7
    def Test3(self):
        vals = [8, 6, 6, 5, 7, 7]
        nodes = binary_tree.createNodesVec(vals)

        binary_tree.connectNodesIndex(nodes, 0, 1, 2)
        binary_tree.connectNodesIndex(nodes, 1, 3, 4)
        binary_tree.connectNodesIndex(nodes, 2, 5, -1)

        self.checkResult("Test3", nodes[0], False)

    #               5
    #              / \
    #             3   3
    #            /     \
    #           4       4
    #          /         \
    #         2           2
    #        /             \
    #       1               1
    def Test4(self):
        vals = [5, 3, 3, 4, 4, 2, 2, 1, 1]
        nodes = binary_tree.createNodesVec(vals)

        binary_tree.connectNodesIndex(nodes, 0, 1, 2)
        binary_tree.connectNodesIndex(nodes, 1, 3, -1)
        binary_tree.connectNodesIndex(nodes, 2, -1, 4)
        binary_tree.connectNodesIndex(nodes, 3, 5, -1)
        binary_tree.connectNodesIndex(nodes, 4, -1, 6)
        binary_tree.connectNodesIndex(nodes, 5, 7, -1)
        binary_tree.connectNodesIndex(nodes, 6, -1, 8)

        self.checkResult("Test4", nodes[0], True)

    #               5
    #              / \
    #             3   3
    #            /     \
    #           4       4
    #          /         \
    #         6           2
    #        /             \
    #       1               1
    def Test5(self):
        vals = [5, 3, 3, 4, 4, 6, 2, 1, 1]
        nodes = binary_tree.createNodesVec(vals)

        binary_tree.connectNodesIndex(nodes, 0, 1, 2)
        binary_tree.connectNodesIndex(nodes, 1, 3, -1)
        binary_tree.connectNodesIndex(nodes, 2, -1, 4)
        binary_tree.connectNodesIndex(nodes, 3, 5, -1)
        binary_tree.connectNodesIndex(nodes, 4, -1, 6)
        binary_tree.connectNodesIndex(nodes, 5, 7, -1)
        binary_tree.connectNodesIndex(nodes, 6, -1, 8)

        self.checkResult("Test5", nodes[0], False)

    #               5
    #              / \
    #             3   3
    #            /     \
    #           4       4
    #          /         \
    #         2           2
    #                      \
    #                       1
    def Test6(self):
        vals = [5, 3, 3, 4, 4, 2, 2, 1]
        nodes = binary_tree.createNodesVec(vals)

        binary_tree.connectNodesIndex(nodes, 0, 1, 2)
        binary_tree.connectNodesIndex(nodes, 1, 3, -1)
        binary_tree.connectNodesIndex(nodes, 2, -1, 4)
        binary_tree.connectNodesIndex(nodes, 3, 5, -1)
        binary_tree.connectNodesIndex(nodes, 4, -1, 6)
        binary_tree.connectNodesIndex(nodes, 5, -1, -1)
        binary_tree.connectNodesIndex(nodes, 6, -1, 7)

        self.checkResult("Test6", nodes[0], False)

    # 只有一个结点
    def Test7(self):
        vals = [1]
        nodes = binary_tree.createNodesVec(vals)

        self.checkResult("Test7", nodes[0], True)

    # 没有结点
    def Test8(self):
        self.checkResult("Test8", None, True)

    # 所有结点都有相同的值，树对称
    #               5
    #              / \
    #             5   5
    #            /     \
    #           5       5
    #          /         \
    #         5           5
    def Test9(self):
        vals = [5, 5, 5, 5, 5, 5, 5]
        nodes = binary_tree.createNodesVec(vals)

        binary_tree.connectNodesIndex(nodes, 0, 1, 2)
        binary_tree.connectNodesIndex(nodes, 1, 3, -1)
        binary_tree.connectNodesIndex(nodes, 2, -1, 4)
        binary_tree.connectNodesIndex(nodes, 3, 5, -1)
        binary_tree.connectNodesIndex(nodes, 4, -1, 6)

        self.checkResult("Test9", nodes[0], True)

    # 所有结点都有相同的值，树不对称
    #               5
    #              / \
    #             5   5
    #            /     \
    #           5       5
    #          /       /
    #         5       5
    def Test10(self):
        vals = [5, 5, 5, 5, 5, 5, 5]
        nodes = binary_tree.createNodesVec(vals)

        binary_tree.connectNodesIndex(nodes, 0, 1, 2)
        binary_tree.connectNodesIndex(nodes, 1, 3, -1)
        binary_tree.connectNodesIndex(nodes, 2, -1, 4)
        binary_tree.connectNodesIndex(nodes, 3, 5, -1)
        binary_tree.connectNodesIndex(nodes, 4, 6, -1)

        self.checkResult("Test10", nodes[0], False)

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


if __name__ == "__main__":
    test = Test()
    test.runTest()
