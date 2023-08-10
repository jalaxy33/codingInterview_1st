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
    def buildTree(self, preorder: list[int], inorder: list[int]) -> TreeNode:
        def recur(root: int, left: int, right: int):
            if left > right:
                return None
            node = TreeNode(preorder[root])
            i = dic[preorder[root]]
            node.left = recur(root + 1, left, i - 1)
            node.right = recur(i + root - left + 1, i + 1, right)
            return node

        dic = {}
        for i in range(len(inorder)):
            dic[inorder[i]] = i
        return recur(0, 0, len(inorder) - 1)


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(
        self, testName: str, preorder: list[int], inorder: list[int]
    ) -> None:
        print(f"==== {testName} ====")
        try:
            resultRoot = self.solution.buildTree(preorder, inorder)
            binary_tree.printTree(resultRoot)
        except:
            print("Invalid input.")

    # 普通二叉树
    #              1
    #           /     \
    #          2       3
    #         /       / \
    #        4       5   6
    #         \         /
    #          7       8
    def Test1(self):
        preorder = [1, 2, 4, 7, 3, 5, 6, 8]
        inorder = [4, 7, 2, 1, 5, 3, 8, 6]
        self.checkResult("Test1", preorder, inorder)

    # 所有结点都没有右子结点
    #            1
    #           /
    #          2
    #         /
    #        3
    #       /
    #      4
    #     /
    #    5
    def Test2(self):
        preorder = [1, 2, 3, 4, 5]
        inorder = [5, 4, 3, 2, 1]
        self.checkResult("Test2", preorder, inorder)

    # 所有结点都没有左子结点
    #            1
    #             \
    #              2
    #               \
    #                3
    #                 \
    #                  4
    #                   \
    #                    5
    def Test3(self):
        preorder = [1, 2, 3, 4, 5]
        inorder = [1, 2, 3, 4, 5]
        self.checkResult("Test3", preorder, inorder)

    # 树中只有一个结点
    def Test4(self):
        preorder = [1]
        inorder = [1]
        self.checkResult("Test4", preorder, inorder)

    # 完全二叉树
    #              1
    #           /     \
    #          2       3
    #         / \     / \
    #        4   5   6   7
    def Test5(self):
        preorder = [1, 2, 4, 5, 3, 6, 7]
        inorder = [4, 2, 5, 1, 6, 3, 7]
        self.checkResult("Test5", preorder, inorder)

    # 输入空指针
    def Test6(self):
        self.checkResult("Test6", [], [])

    # 输入的两个序列不匹配
    def Test7(self):
        preorder = [1, 2, 4, 5, 3, 6, 7]
        inorder = [4, 2, 8, 1, 6, 3, 7]
        self.checkResult("Test7", preorder, inorder)

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
