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
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, root: TreeNode, expected: int) -> None:
        text = testName
        result = self.solution.maxDepth(root)
        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    #            1
    #         /      \
    #        2        3
    #       /\         \
    #      4  5         6
    #        /
    #       7
    def Test1(self):
        vals = [1, 2, 3, 4, 5, 6, 7]
        nodes = binary_tree.createNodesVec(vals)

        binary_tree.connectNodesIndex(nodes, 0, 1, 2)
        binary_tree.connectNodesIndex(nodes, 1, 3, 4)
        binary_tree.connectNodesIndex(nodes, 2, -1, 5)
        binary_tree.connectNodesIndex(nodes, 4, 6, -1)

        self.checkResult("Test1", nodes[0], 4)

    #               1
    #              /
    #             2
    #            /
    #           3
    #          /
    #         4
    #        /
    #       5
    def Test2(self):
        vals = [1, 2, 3, 4, 5]
        nodes = binary_tree.createNodesVec(vals)

        binary_tree.connectNodesIndex(nodes, 0, 1, -1)
        binary_tree.connectNodesIndex(nodes, 1, 2, -1)
        binary_tree.connectNodesIndex(nodes, 2, 3, -1)
        binary_tree.connectNodesIndex(nodes, 3, 4, -1)

        self.checkResult("Test2", nodes[0], 5)

    # 1
    #  \
    #   2
    #    \
    #     3
    #      \
    #       4
    #        \
    #         5
    def Test3(self):
        vals = [1, 2, 3, 4, 5]
        nodes = binary_tree.createNodesVec(vals)

        binary_tree.connectNodesIndex(nodes, 0, -1, 1)
        binary_tree.connectNodesIndex(nodes, 1, -1, 2)
        binary_tree.connectNodesIndex(nodes, 2, -1, 3)
        binary_tree.connectNodesIndex(nodes, 3, -1, 4)

        self.checkResult("Test3", nodes[0], 5)

    # 树中只有1个结点
    def Test4(self):
        vals = [1]
        nodes = binary_tree.createNodesVec(vals)

        self.checkResult("Test4", nodes[0], 1)

    # 树中没有结点
    def Test5(self):
        self.checkResult("Test5", None, 0)

    def runTest(self):
        self.Test1()
        self.Test2()
        self.Test3()
        self.Test4()
        self.Test5()


if __name__ == "__main__":
    test = Test()
    test.runTest()
