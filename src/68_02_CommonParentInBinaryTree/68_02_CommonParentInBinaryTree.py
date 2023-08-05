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
    def lowestCommonAncestor(
        self, root: "TreeNode", p: "TreeNode", q: "TreeNode"
    ) -> "TreeNode":
        if not root or root == p or root == q:
            return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        if not left:  # 共同祖先不在左侧
            return right
        if not right:  # 共同祖先不在右侧
            return left
        return root  # 两侧均非空，说明当前正是共同祖先


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(
        self,
        testName: str,
        root: TreeNode,
        p: TreeNode,
        q: TreeNode,
        expected: TreeNode,
    ) -> None:
        text = testName
        result = self.solution.lowestCommonAncestor(root, p, q)
        if (not expected and not result) or (
            expected and result and expected.val == result.val
        ):
            text += " passed."
        else:
            text += " failed."
        print(text)

    #      6
    #    /   \
    #   2     8
    #  / \    / \
    # 0   4  7   9
    #    / \
    #   3   5
    # p=0, q=5, expected=2
    def Test1(self):
        vals = [6, 2, 8, 0, 4, 7, 9, 3, 5]
        nodes = binary_tree.createNodesVec(vals)

        binary_tree.connectNodesIndex(nodes, 0, 1, 2)
        binary_tree.connectNodesIndex(nodes, 1, 3, 4)
        binary_tree.connectNodesIndex(nodes, 2, 5, 6)
        binary_tree.connectNodesIndex(nodes, 4, 7, 8)

        self.checkResult("Test1", nodes[0], nodes[3], nodes[8], nodes[1])

    #               5
    #              /
    #             4
    #            /
    #           3
    #          /
    #         2
    #        /
    #       1
    # p=1, q=3, expected=4
    def Test2(self):
        vals = [5, 4, 3, 2, 1]
        nodes = binary_tree.createNodesVec(vals)

        binary_tree.connectNodesIndex(nodes, 0, 1, -1)
        binary_tree.connectNodesIndex(nodes, 1, 2, -1)
        binary_tree.connectNodesIndex(nodes, 2, 3, -1)
        binary_tree.connectNodesIndex(nodes, 3, 4, -1)

        self.checkResult("Test2", nodes[0], nodes[4], nodes[2], nodes[2])

    # 输入None
    def Test3(self):
        self.checkResult("Test3", None, None, None, None)

    def runTest(self):
        self.Test1()
        self.Test2()
        self.Test3()


if __name__ == "__main__":
    test = Test()
    test.runTest()
