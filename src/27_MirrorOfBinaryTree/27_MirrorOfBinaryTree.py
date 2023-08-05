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
    def mirrorTree(self, root: TreeNode, use_recur: bool = False) -> TreeNode:
        if use_recur:
            return self.withRecur(root)
        else:
            return self.withIter(root)

    def withRecur(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        root.left, root.right = self.withRecur(root.right), self.withRecur(root.left)
        return root

    def withIter(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        stk = [root]
        while stk:
            node: TreeNode = stk.pop()
            if node.left:
                stk.append(node.left)
            if node.right:
                stk.append(node.right)
            node.left, node.right = node.right, node.left
        return root


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, root: TreeNode) -> None:
        print(f"==== {testName} ====")

        print("[original]:")
        binary_tree.printTree(root)

        print("[mirrored]:")
        mirror = self.solution.mirrorTree(root)
        binary_tree.printTree(root)

    # 测试完全二叉树：除了叶子节点，其他节点都有两个子节点
    #            8
    #        6      10
    #       5 7    9  11
    def Test1(self):
        vals = [8, 6, 10, 5, 7, 9, 11]
        nodes = binary_tree.createNodesVec(vals)

        binary_tree.connectNodesIndex(nodes, 0, 1, 2)
        binary_tree.connectNodesIndex(nodes, 1, 3, 4)
        binary_tree.connectNodesIndex(nodes, 2, 5, 6)

        self.checkResult("Test1", nodes[0])

    # 测试二叉树：出叶子结点之外，左右的结点都有且只有一个左子结点
    #            8
    #          7
    #        6
    #      5
    #    4
    def Test2(self):
        vals = [8, 7, 6, 5, 4]
        nodes = binary_tree.createNodesVec(vals)

        binary_tree.connectNodesIndex(nodes, 0, 1, -1)
        binary_tree.connectNodesIndex(nodes, 1, 2, -1)
        binary_tree.connectNodesIndex(nodes, 2, 3, -1)
        binary_tree.connectNodesIndex(nodes, 3, 4, -1)

        self.checkResult("Test2", nodes[0])

    # 测试二叉树：出叶子结点之外，左右的结点都有且只有一个右子结点
    #            8
    #             7
    #              6
    #               5
    #                4
    def Test3(self):
        vals = [8, 7, 6, 5, 4]
        nodes = binary_tree.createNodesVec(vals)

        binary_tree.connectNodesIndex(nodes, 0, -1, 1)
        binary_tree.connectNodesIndex(nodes, 1, -1, 2)
        binary_tree.connectNodesIndex(nodes, 2, -1, 3)
        binary_tree.connectNodesIndex(nodes, 3, -1, 4)

        self.checkResult("Test3", nodes[0])

    # 测试空二叉树：根结点为空指针
    def Test4(self):
        self.checkResult("Test4", None)

    # 测试只有一个结点的二叉树
    def Test5(self):
        vals = [8]
        nodes = binary_tree.createNodesVec(vals)

        self.checkResult("Test5", nodes[0])

    def runTest(self):
        self.Test1()
        self.Test2()
        self.Test3()
        self.Test4()
        self.Test5()


if __name__ == "__main__":
    test = Test()
    test.runTest()
