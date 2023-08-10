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
from Utilities.binary_tree import TreeNode as Node


class Solution:
    # 中序遍历
    def treeToDoublyList(self, root: "Node") -> "Node":
        def dfs(cur: "Node") -> None:
            if not cur:
                return

            dfs(cur.left)

            # pre为空说明刚开始，记录当前节点为头节点
            # 否则连接cur与pre
            if self.pre:
                self.pre.right = cur
            else:
                self.head = cur
            cur.left = self.pre
            self.pre = cur

            dfs(cur.right)

        self.head: "Node" = None
        self.pre: "Node" = None
        if not root:
            return
        dfs(root)
        # 最后连接头尾节点
        if self.head:
            self.head.left = self.pre
        if self.pre:
            self.pre.right = self.head
        return self.head


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, root: Node):
        print(f"==== {testName} ====")
        resultHead = self.solution.treeToDoublyList(root)
        self.printDoubleLinkedList(resultHead)

    def printDoubleLinkedList(self, head: Node):
        tail = head.left if head else None

        # 先切断首尾节点的连接
        if tail:
            tail.right = None
        if head:
            head.left = None

        node, vals = head, []
        while node:
            vals.append(node.val)
            if not node.right:
                break
            node = node.right
        print(f"(L -> R) {vals}")

        node, vals = tail, []
        while node:
            vals.append(node.val)
            if not node.left:
                break
            node = node.left
        print(f"(R -> L) {vals}")

        # 最后再重新连接首尾节点
        if tail:
            tail.right = head
        if head:
            head.left = tail

    #            10
    #         /      \
    #        5        14
    #       /\       /  \
    #      4  7    12    16
    def Test1(self):
        vals = [10, 5, 14, 4, 7, 12, 16]
        nodes = binary_tree.createTreeNodesVec(vals)

        idxs = [
            (0, 1, 2),
            (1, 3, 4),
            (2, 5, 6),
        ]
        binary_tree.connectTreeNodesIndexVec(nodes, idxs)

        self.checkResult("Test1", nodes[0])

    #            10
    #         /      \
    #        5        14
    #       /\
    #      4  7
    # 没有路径上的结点和为15
    def Test2(self):
        vals = [10, 5, 14, 4, 7]
        nodes = binary_tree.createTreeNodesVec(vals)

        idxs = [
            (0, 1, 2),
            (1, 3, 4),
        ]
        binary_tree.connectTreeNodesIndexVec(nodes, idxs)

        self.checkResult("Test2", nodes[0])

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

        self.checkResult("Test3", nodes[0])

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

        self.checkResult("Test4", nodes[0])

    # 树中只有1个结点
    def Test5(self):
        vals = [1]
        nodes = binary_tree.createTreeNodesVec(vals)

        self.checkResult("Test5", nodes[0])

    # 树中没有结点
    def Test6(self):
        self.checkResult("Test6", None)

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
