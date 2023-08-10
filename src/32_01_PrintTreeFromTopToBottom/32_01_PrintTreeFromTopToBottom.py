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
    def levelOrder(self, root: TreeNode) -> list[int]:
        if not root:
            return []
        results, q = [], [root]
        while q:
            tmp = q.pop(0)
            results.append(tmp.val)
            if tmp.left:
                q.append(tmp.left)
            if tmp.right:
                q.append(tmp.right)
        return results


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, root: TreeNode):
        text = testName
        result = self.solution.levelOrder(root)
        text += f"{result}"
        print(text)

    #            10
    #         /      \
    #        6        14
    #       /\        /\
    #      4  8     12  16
    def Test1(self):
        vals = [10, 6, 14, 4, 8, 12, 16]
        nodes = binary_tree.createTreeNodesVec(vals)

        idxs = [
            (0, 1, 2),
            (1, 3, 4),
            (2, 5, 6),
        ]
        binary_tree.connectTreeNodesIndexVec(nodes, idxs)

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
        nodes = binary_tree.createTreeNodesVec(vals)

        idxs = [
            (0, 1, -1),
            (1, 2, -1),
            (2, 3, -1),
            (3, 4, -1),
        ]
        binary_tree.connectTreeNodesIndexVec(nodes, idxs)

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
        nodes = binary_tree.createTreeNodesVec(vals)

        idxs = [
            (0, -1, 1),
            (1, -1, 2),
            (2, -1, 3),
            (3, -1, 4),
        ]
        binary_tree.connectTreeNodesIndexVec(nodes, idxs)

        self.checkResult("Test3", nodes[0])

    # 树中只有1个结点
    def Test4(self):
        vals = [1]
        nodes = binary_tree.createTreeNodesVec(vals)

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
