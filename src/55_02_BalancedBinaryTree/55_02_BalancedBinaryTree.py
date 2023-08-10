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
    def isBalanced(self, root: TreeNode) -> bool:
        return self.recur(root) != -1

    # 后序遍历+剪枝。从底至顶判断左右子树是否平衡。
    # 返回当前子树的深度，或者不平衡标志-1
    def recur(self, root: TreeNode) -> int:
        if not root:
            return 0
        # 判断左子树
        left = self.recur(root.left)
        if left == -1:  # 如果左子树不是平衡树则提前结束（剪枝）
            return -1
        # 判断右子树
        right = self.recur(root.right)
        if right == -1:
            return -1
        # 左右子树均平衡，判断当前是否平衡。
        # 若是则返回当前深度 (子树深度+1)，否则返回-1
        return max(left, right) + 1 if abs(left - right) < 2 else -1


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, root: TreeNode, expected: bool) -> None:
        text = testName
        result = self.solution.isBalanced(root)
        if result == expected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    # 完全二叉树
    #             1
    #         /      \
    #        2        3
    #       /\       / \
    #      4  5     6   7
    def Test1(self):
        vals = [1, 2, 3, 4, 5, 6, 7]
        nodes = binary_tree.createTreeNodesVec(vals)

        idxs = [
            (0, 1, 2),
            (1, 3, 4),
            (2, 5, 6),
        ]
        binary_tree.connectTreeNodesIndexVec(nodes, idxs)

        self.checkResult("Test1", nodes[0], True)

    # 不是完全二叉树，但是平衡二叉树
    #             1
    #         /      \
    #        2        3
    #       /\         \
    #      4  5         6
    #        /
    #       7
    def Test2(self):
        vals = [1, 2, 3, 4, 5, 6, 7]
        nodes = binary_tree.createTreeNodesVec(vals)

        idxs = [
            (0, 1, 2),
            (1, 3, 4),
            (2, -1, 5),
            (4, 6, -1),
        ]
        binary_tree.connectTreeNodesIndexVec(nodes, idxs)

        self.checkResult("Test2", nodes[0], True)

    # 不是平衡二叉树
    #             1
    #         /      \
    #        2        3
    #       /\
    #      4  5
    #        /
    #       6
    def Test3(self):
        vals = [1, 2, 3, 4, 5, 6]
        nodes = binary_tree.createTreeNodesVec(vals)

        idxs = [
            (0, 1, 2),
            (1, 3, 4),
            (4, 5, -1),
        ]
        binary_tree.connectTreeNodesIndexVec(nodes, idxs)

        self.checkResult("Test3", nodes[0], False)

    #               1
    #              /
    #             2
    #            /
    #           3
    #          /
    #         4
    #        /
    #       5
    def Test4(self):
        vals = [1, 2, 3, 4, 5]
        nodes = binary_tree.createTreeNodesVec(vals)

        idxs = [
            (0, 1, -1),
            (1, 2, -1),
            (2, 3, -1),
            (3, 4, -1),
        ]
        binary_tree.connectTreeNodesIndexVec(nodes, idxs)

        self.checkResult("Test4", nodes[0], False)

    # 1
    #  \
    #   2
    #    \
    #     3
    #      \
    #       4
    #        \
    #         5
    def Test5(self):
        vals = [1, 2, 3, 4, 5]
        nodes = binary_tree.createTreeNodesVec(vals)

        idxs = [
            (0, -1, 1),
            (1, -1, 2),
            (2, -1, 3),
            (3, -1, 4),
        ]
        binary_tree.connectTreeNodesIndexVec(nodes, idxs)

        self.checkResult("Test5", nodes[0], False)

    # 树中只有1个结点
    def Test6(self):
        vals = [1]
        nodes = binary_tree.createTreeNodesVec(vals)

        self.checkResult("Test6", nodes[0], True)

    # 树中没有结点
    def Test7(self):
        self.checkResult("Test7", None, True)

    def runTest(self):
        self.Test1()
        self.Test2()
        self.Test3()
        self.Test4()
        self.Test5()
        self.Test6()
        self.Test7()


if __name__ == "__main__":
    test = Test()
    test.runTest()
