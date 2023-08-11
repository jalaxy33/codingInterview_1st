# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

import os
import sys

sys.path.append(os.path.split(sys.path[0])[0])

from Utilities import list_utils
from Utilities.list_utils import ListNode


class Solution:
    # 双指针，前面的指针先走k步
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return None
        p1 = p2 = head
        for i in range(k):
            if not p1:
                return None
            p1 = p1.next
        while p1:
            p1, p2 = p1.next, p2.next
        return p2


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, head: ListNode, k: int, expected: int) -> None:
        text = testName
        resultNode = self.solution.getKthFromEnd(head, k)

        if resultNode and resultNode.val == expected:
            text += " passed."
        elif not resultNode and expected == -1:
            text += " passed."
        else:
            text += " failed."
        print(text)

    # 测试要找的结点在链表中间
    def Test1(self):
        vals = [1, 2, 3, 4, 5]
        nodes = list_utils.createListNodesVec(vals)
        list_utils.connectListNodesVec(nodes)

        k = 2
        expected = 4
        self.checkResult("Test1", nodes[0], k, expected)

    # 测试要找的结点是链表的尾结点
    def Test2(self):
        vals = [1, 2, 3, 4, 5]
        nodes = list_utils.createListNodesVec(vals)
        list_utils.connectListNodesVec(nodes)

        k = 1
        expected = 5
        self.checkResult("Test2", nodes[0], k, expected)

    # 测试要找的结点是链表的头结点
    def Test3(self):
        vals = [1, 2, 3, 4, 5]
        nodes = list_utils.createListNodesVec(vals)
        list_utils.connectListNodesVec(nodes)

        k = 5
        expected = 1
        self.checkResult("Test3", nodes[0], k, expected)

    # 测试空链表
    def Test4(self):
        k = 100
        expected = -1
        self.checkResult("Test4", None, k, expected)

    # 测试输入的第二个参数大于链表的结点总数
    def Test5(self):
        vals = [1, 2, 3, 4, 5]
        nodes = list_utils.createListNodesVec(vals)
        list_utils.connectListNodesVec(nodes)

        k = 6
        expected = -1
        self.checkResult("Test5", nodes[0], k, expected)

    # 测试输入的第二个参数为0
    def Test6(self):
        vals = [1, 2, 3, 4, 5]
        nodes = list_utils.createListNodesVec(vals)
        list_utils.connectListNodesVec(nodes)

        k = 0
        expected = -1
        self.checkResult("Test6", nodes[0], k, expected)

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
