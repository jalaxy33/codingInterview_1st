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
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        elif not l2:
            return l1

        head = cur = ListNode(0)
        while l1 and l2:
            if l1.val < l2.val:
                cur.next, l1 = l1, l1.next
            else:
                cur.next, l2 = l2, l2.next
            cur = cur.next
        cur.next = l1 if l1 else l2
        return head.next


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, l1: ListNode, l2: ListNode) -> None:
        print(f"==== {testName} ====")
        resultNode = self.solution.mergeTwoLists(l1, l2)
        list_utils.printList(resultNode)
        print("\n")

    # list1: 1->3->5
    # list2: 2->4->6
    def Test1(self):
        vals1 = [1, 3, 5]
        vals2 = [2, 4, 6]
        nodes1 = list_utils.createListNodesVec(vals1)
        nodes2 = list_utils.createListNodesVec(vals2)
        list_utils.connectListNodesVec(nodes1)
        list_utils.connectListNodesVec(nodes2)

        self.checkResult("Test1", nodes1[0], nodes2[0])

    # 两个链表中有重复的数字
    # list1: 1->3->5
    # list2: 1->3->5
    def Test2(self):
        vals1 = [1, 3, 5]
        vals2 = [1, 3, 5]
        nodes1 = list_utils.createListNodesVec(vals1)
        nodes2 = list_utils.createListNodesVec(vals2)
        list_utils.connectListNodesVec(nodes1)
        list_utils.connectListNodesVec(nodes2)

        self.checkResult("Test2", nodes1[0], nodes2[0])

    # 两个链表都只有一个数字
    # list1: 1
    # list2: 2
    def Test3(self):
        vals1 = [1]
        vals2 = [2]
        nodes1 = list_utils.createListNodesVec(vals1)
        nodes2 = list_utils.createListNodesVec(vals2)
        list_utils.connectListNodesVec(nodes1)
        list_utils.connectListNodesVec(nodes2)

        self.checkResult("Test3", nodes1[0], nodes2[0])

    # 一个链表为空链表
    # list1: 1->3->5
    # list2: 空链表
    def Test4(self):
        vals1 = [1, 3, 5]
        nodes1 = list_utils.createListNodesVec(vals1)
        list_utils.connectListNodesVec(nodes1)

        self.checkResult("Test4", nodes1[0], None)

    # 两个链表都为空链表
    # list1: 空链表
    # list2: 空链表
    def Test5(self):
        self.checkResult("Test5", None, None)

    def runTest(self):
        self.Test1()
        self.Test2()
        self.Test3()
        self.Test4()
        self.Test5()


if __name__ == "__main__":
    test = Test()
    test.runTest()
