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
    def pathSum(self, root: TreeNode, target: int) -> list[list[int]]:
        # result记录最终结果，path记录其中一条路径
        result, path = [], []

        def recur(root: TreeNode, target: int) -> None:
            if not root:
                return
            # 将当前结点加入路径，并更新目标值
            path.append(root.val)
            target -= root.val
            # 成功条件：1) 目标值为0，且 2) 已到达叶节点
            if target == 0 and not root.left and not root.right:
                # Python中，append是引用，而path一直在动态变化
                # result会无法记录正确的路径，因此需要将path先复制再append
                result.append(list(path))
            # 遍历左右子树
            recur(root.left, target)
            recur(root.right, target)
            # 执行到此处说明当前路径不合要求，从path中删除当前节点
            path.pop()

        recur(root, target)
        return result


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(
        self, testName: str, root: TreeNode, target: int, expected_nun: int
    ):
        print(f"==== {testName} ====")
        print(f"target sum: {target}")
        print(f"expected path num: {expected_nun}")

        result = self.solution.pathSum(root, target)
        print(f"{result}\n")

    #            10
    #         /      \
    #        5        12
    #       /\
    #      4  7
    # 有两条路径上的结点和为22
    def Test1(self):
        vals = [10, 5, 12, 4, 7]
        nodes = binary_tree.createTreeNodesVec(vals)

        idxs = [
            (0, 1, 2),
            (1, 3, 4),
        ]
        binary_tree.connectTreeNodesIndexVec(nodes, idxs)

        self.checkResult("Test1", nodes[0], 22, 2)

    #            10
    #         /      \
    #        5        12
    #       /\
    #      4  7
    # 没有路径上的结点和为15
    def Test2(self):
        vals = [10, 5, 12, 4, 7]
        nodes = binary_tree.createTreeNodesVec(vals)

        idxs = [
            (0, 1, 2),
            (1, 3, 4),
        ]
        binary_tree.connectTreeNodesIndexVec(nodes, idxs)

        self.checkResult("Test2", nodes[0], 15, 0)

    #               5
    #              /
    #             4
    #            /
    #           3
    #          /
    #         2
    #        /
    #       1
    # 有一条路径上面的结点和为15
    def Test3(self):
        vals = [5, 4, 3, 2, 1]
        nodes = binary_tree.createTreeNodesVec(vals)

        idxs = [
            (0, 1, -1),
            (1, 2, -1),
            (2, 3, -1),
            (3, 4, -1),
        ]
        binary_tree.connectTreeNodesIndexVec(nodes, idxs)

        self.checkResult("Test3", nodes[0], 15, 1)

    # 1
    #  \
    #   2
    #    \
    #     3
    #      \
    #       4
    #        \
    #         5
    # 没有路径上面的结点和为16
    def Test4(self):
        vals = [1, 2, 3, 4, 5]
        nodes = binary_tree.createTreeNodesVec(vals)

        idxs = [
            (0, -1, 1),
            (1, -1, 2),
            (2, -1, 3),
            (3, -1, 4),
        ]
        binary_tree.connectTreeNodesIndexVec(nodes, idxs)

        self.checkResult("Test4", nodes[0], 16, 0)

    # 树中只有1个结点
    def Test5(self):
        vals = [1]
        nodes = binary_tree.createTreeNodesVec(vals)

        self.checkResult("Test5", nodes[0], 1, 1)

    # 树中没有结点
    def Test6(self):
        self.checkResult("Test6", None, 0, 0)

    def runTest(self):
        self.Test1()
        self.Test2()
        self.Test3()
        self.Test4()
        self.Test5()
        self.Test6()


if __name__ == "__main__":
    test = Test()
    test.runTest()
