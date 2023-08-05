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
    def levelOrder(self, root: TreeNode) -> list[list[int]]:
        if not root:
            return []

        results, q = [], [root]
        while q:
            layer = []
            size = len(q)
            for _ in range(size):
                tmp = q.pop(0)
                layer.append(tmp.val)
                if tmp.left:
                    q.append(tmp.left)
                if tmp.right:
                    q.append(tmp.right)
            # 由层数的奇偶决定是否倒序输出
            results.append(layer[::-1] if len(results) % 2 == 1 else layer)
        return results


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, root: TreeNode):
        print("==== " + testName + " ====")
        result = self.solution.levelOrder(root)
        for layer in result:
            print(layer)

    #            10
    #         /      \
    #        6        14
    #       /\        /\
    #      4  8     12  16
    def Test1(self):
        vals = [10, 6, 14, 4, 8, 12, 16]
        nodes = binary_tree.createNodesVec(vals)

        binary_tree.connectNodesIndex(nodes, 0, 1, 2)
        binary_tree.connectNodesIndex(nodes, 1, 3, 4)
        binary_tree.connectNodesIndex(nodes, 2, 5, 6)

        self.checkResult("Test1", nodes[0])

    #               5
    #              /
    #             4
    #            /
    #           3
    #          /
    #         2
    #        /
    #       1
    def Test2(self):
        vals = [5, 4, 3, 2, 1]
        nodes = binary_tree.createNodesVec(vals)

        binary_tree.connectNodesIndex(nodes, 0, 1, -1)
        binary_tree.connectNodesIndex(nodes, 1, 2, -1)
        binary_tree.connectNodesIndex(nodes, 2, 3, -1)
        binary_tree.connectNodesIndex(nodes, 3, 4, -1)

        self.checkResult("Test2", nodes[0])

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

        self.checkResult("Test3", nodes[0])

    # 树中只有1个结点
    def Test4(self):
        vals = [1]
        nodes = binary_tree.createNodesVec(vals)

        self.checkResult("Test4", nodes[0])

    # 树中没有结点
    def Test5(self):
        self.checkResult("Test5", None)

    def runTest(self):
        self.Test1()
        self.Test2()
        self.Test3()
        self.Test4()
        self.Test5()


if __name__ == "__main__":
    test = Test()
    test.runTest()
