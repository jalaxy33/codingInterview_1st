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
    # 中序遍历的倒序
    def kthLargest(self, root: TreeNode, k: int) -> int:
        def dfs(root: TreeNode):
            if not root:
                return
            dfs(root.right)
            if self.k == 0:
                return
            self.k -= 1
            if self.k == 0:
                self.result = root.val
            dfs(root.left)

        self.k, self.result = k, 0
        dfs(root)
        return self.result


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, root: TreeNode, k: int, expected: int) -> None:
        text = testName
        result = self.solution.kthLargest(root, k)

        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    #            8
    #        6      10
    #       5 7    9  11
    def TestA(self):
        vals = [8, 6, 10, 5, 7, 9, 11]
        nodes = binary_tree.createTreeNodesVec(vals)

        idxs = [
            (0, 1, 2),
            (1, 3, 4),
            (2, 5, 6),
        ]
        binary_tree.connectTreeNodesIndexVec(nodes, idxs)

        self.checkResult("TestA1", nodes[0], 1, 11)
        self.checkResult("TestA2", nodes[0], 2, 10)
        self.checkResult("TestA3", nodes[0], 3, 9)
        self.checkResult("TestA4", nodes[0], 4, 8)
        self.checkResult("TestA5", nodes[0], 5, 7)
        self.checkResult("TestA6", nodes[0], 6, 6)
        self.checkResult("TestA7", nodes[0], 7, 5)
        print("\n")

    #               5
    #              /
    #             4
    #            /
    #           3
    #          /
    #         2
    #        /
    #       1
    def TestB(self):
        vals = [5, 4, 3, 2, 1]
        nodes = binary_tree.createTreeNodesVec(vals)

        idxs = [
            (0, 1, -1),
            (1, 2, -1),
            (2, 3, -1),
            (3, 4, -1),
        ]
        binary_tree.connectTreeNodesIndexVec(nodes, idxs)

        self.checkResult("TestB1", nodes[0], 1, 5)
        self.checkResult("TestB2", nodes[0], 2, 4)
        self.checkResult("TestB3", nodes[0], 3, 3)
        self.checkResult("TestB4", nodes[0], 4, 2)
        self.checkResult("TestB5", nodes[0], 5, 1)
        print("\n")

    # 1
    #  \
    #   2
    #    \
    #     3
    #      \
    #       4
    #        \
    #         5
    def TestC(self):
        vals = [1, 2, 3, 4, 5]
        nodes = binary_tree.createTreeNodesVec(vals)

        idxs = [
            (0, -1, 1),
            (1, -1, 2),
            (2, -1, 3),
            (3, -1, 4),
        ]
        binary_tree.connectTreeNodesIndexVec(nodes, idxs)

        self.checkResult("TestC1", nodes[0], 1, 5)
        self.checkResult("TestC2", nodes[0], 2, 4)
        self.checkResult("TestC3", nodes[0], 3, 3)
        self.checkResult("TestC4", nodes[0], 4, 2)
        self.checkResult("TestC5", nodes[0], 5, 1)
        print("\n")

    # There is only one node in a tree
    def TestD(self):
        vals = [1]
        nodes = binary_tree.createTreeNodesVec(vals)

        self.checkResult("TestD1", nodes[0], 1, 1)
        print("\n")

    def runTest(self):
        self.TestA()
        self.TestB()
        self.TestC()
        self.TestD()


if __name__ == "__main__":
    test = Test()
    test.runTest()
