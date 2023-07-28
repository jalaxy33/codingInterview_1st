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
    def reverseList(self, head: ListNode, use_iter=True) -> ListNode:
        if use_iter:
            return self.reverseList_Iteratively(head)
        else:
            return self.reverseList_Recursively(head, None)

    # 基于迭代
    def reverseList_Iteratively(self, head: ListNode) -> ListNode:
        cur, pre = head, None
        while cur:
            cur.next, pre, cur = pre, cur, cur.next
        return pre

    # 基于递归
    def reverseList_Recursively(self, cur: ListNode, pre: ListNode) -> ListNode:
        if cur is None:
            return pre
        newHead = self.reverseList_Recursively(cur.next, cur)
        cur.next = pre
        return newHead


class Test:
    def __init__(self):
        self.solution = Solution()

    def testMain(self, head: ListNode) -> None:
        print("The original list is:")
        list_utils.PrintList(head)

        reversed_head = self.solution.reverseList(head)
        print("The reversed list is:")
        list_utils.PrintList(reversed_head)
        print("\n")

    def Test1(self) -> None:
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

    def Test2(self) -> None:
        node1 = list_utils.CreateListNode(1)
        self.testMain(node1)

    def Test3(self) -> None:
        self.testMain(None)

    def runTest(self):
        self.Test1()
        self.Test2()
        self.Test3()


if __name__ == "__main__":
    test = Test()
    test.runTest()
