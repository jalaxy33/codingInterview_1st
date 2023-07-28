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
    def reversePrint(self, head: ListNode, isRecur: bool = False) -> list[int]:
        if isRecur:
            return self.reversePrint_Recursively(head)
        else:
            return self.reversePrint_Iteratively(head) 

    # 使用递归
    def reversePrint_Recursively(self, head: ListNode):
        if head is None:
            return []
        return self.reversePrint_Recursively(head.next) + [head.val]

    # 使用基于栈的迭代
    def reversePrint_Iteratively(self, head: ListNode):
        stk = []
        while head is not None:
            stk.append(head.val)
            head = head.next

        # 逆序输出
        return stk[::-1]


class Test:
    def __init__(self):
        self.solution = Solution()

    def testMain(self, head: ListNode):
        list_utils.PrintListNode(head)
        print(self.solution.reversePrint(head, True))
        print(self.solution.reversePrint(head, False))

    def Test1(self):
        print("\nTest1:\n")
        node1 = list_utils.CreateListNode(1)
        node2 = list_utils.CreateListNode(2)
        node3 = list_utils.CreateListNode(3)
        node4 = list_utils.CreateListNode(4)
        node5 = list_utils.CreateListNode(5)

        list_utils.ConnectListNodes(node1, node2)
        list_utils.ConnectListNodes(node2, node3)
        list_utils.ConnectListNodes(node3, node4)
        list_utils.ConnectListNodes(node4, node5)

        self.testMain(node1)

    # 只有一个结点的链表: 1
    def Test2(self):
        print("\nTest1:\n")
        node1 = list_utils.CreateListNode(1)

        self.testMain(node1)

    # 空链表
    def Test3(self):
        print("\nTest1:\n")
        self.testMain(None)

    def runTest(self):
        self.Test1()
        self.Test2()
        self.Test3()


if __name__ == "__main__":
    test = Test()
    test.runTest()
    
