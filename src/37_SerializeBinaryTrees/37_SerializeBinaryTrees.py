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


class Codec:
    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return "[]"

        result, q = [], [root]
        while q:
            node = q.pop(0)
            if node:
                result.append(str(node.val))
                q.append(node.left)
                q.append(node.right)
            else:
                result.append("null")
            # Python的join函数，可将列表直接转换成字符串
        return "[" + ",".join(result) + "]"

    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        if data == "[]":
            return None

        vals = data[1:-1].split(",")
        root = TreeNode(int(vals[0]))

        q, i = [root], 1
        while q:
            node = q.pop(0)
            # 左子节点
            if vals[i] != "null":
                node.left = TreeNode(int(vals[i]))
                q.append(node.left)
            i += 1
            # 右子节点
            if vals[i] != "null":
                node.right = TreeNode(int(vals[i]))
                q.append(node.right)
            i += 1
        return root


class Test:
    def __init__(self) -> None:
        self.solution = Codec()

    def checkResult(self, testName: str, root: TreeNode, data: str):
        text = f"{testName}: "

        resultStr = self.solution.serialize(root)
        resultRoot = self.solution.deserialize(resultStr)

        text += f"sameStr={data==resultStr}, "
        text += f"sameTree={self.isSameTree(root, resultRoot)}."
        print(text)

    def isSameTree(self, root1: TreeNode, root2: TreeNode):
        if not root1 and not root2:
            return True
        if not root1 or not root2 or root1.val != root2.val:
            return False
        return self.isSameTree(root1.left, root2.left) and self.isSameTree(
            root1.right, root2.right
        )

    #            8
    #        6      10
    #       5 7    9  11
    def Test1(self):
        data = "[8,6,10,5,7,9,11,null,null,null,null,null,null,null,null]"

        vals = [8, 6, 10, 5, 7, 9, 11]
        nodes = binary_tree.createTreeNodesVec(vals)

        idxs = [
            (0, 1, 2),
            (1, 3, 4),
            (2, 5, 6),
        ]
        binary_tree.connectTreeNodesIndexVec(nodes, idxs)

        self.checkResult("Test1", nodes[0], data)

    #            5
    #          4
    #        3
    #      2
    def Test2(self):
        data = "[5,4,null,3,null,2,null,null,null]"

        vals = [5, 4, 3, 2]
        nodes = binary_tree.createTreeNodesVec(vals)

        idxs = [
            (0, 1, -1),
            (1, 2, -1),
            (2, 3, -1),
        ]
        binary_tree.connectTreeNodesIndexVec(nodes, idxs)

        self.checkResult("Test2", nodes[0], data)

    #        5
    #         4
    #          3
    #           2
    def Test3(self):
        data = "[5,null,4,null,3,null,2,null,null]"

        vals = [5, 4, 3, 2]
        nodes = binary_tree.createTreeNodesVec(vals)

        idxs = [
            (0, -1, 1),
            (1, -1, 2),
            (2, -1, 3),
        ]
        binary_tree.connectTreeNodesIndexVec(nodes, idxs)

        self.checkResult("Test3", nodes[0], data)

    #        5
    #         5
    #          5
    #         5
    #        5
    #       5 5
    #      5   5
    def Test4(self):
        data = "[5,null,5,null,5,5,null,5,null,5,5,5,null,null,5,null,null,null,null]"

        vals = [5, 5, 5, 5, 5, 5, 5, 5, 5]
        nodes = binary_tree.createTreeNodesVec(vals)

        idxs = [
            (0, -1, 1),
            (1, -1, 2),
            (2, 3, -1),
            (2, 3, -1),
            (3, 4, -1),
            (4, 5, 6),
            (5, 7, -1),
            (6, -1, 8),
        ]
        binary_tree.connectTreeNodesIndexVec(nodes, idxs)

        self.checkResult("Test4", nodes[0], data)

    # 只有一个节点
    def Test5(self):
        data = "[1,null,null]"

        vals = [1]
        nodes = binary_tree.createTreeNodesVec(vals)

        self.checkResult("Test5", nodes[0], data)

    # 没有节点
    def Test6(self):
        self.checkResult("Test6", None, "[]")

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
