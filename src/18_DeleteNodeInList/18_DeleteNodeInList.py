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
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        if not head:
            return None
        if head.val == val:
            return head.next

        pre, cur = head, head.next
        while cur and cur.val != val:
            pre, cur = cur, cur.next
        if cur:
            pre.next = cur.next
        return head


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(self, testName: str, head: ListNode, val: int) -> None:
        print(f"==== {testName} ====")
        resultHead = self.solution.deleteNode(head, val)
        list_utils.printList(resultHead)
        print("\n")

    # 链表中有多个结点，删除中间的结点
    def Test1(self):
        vals = [1, 2, 3, 4, 5]
        nodes = list_utils.createListNodesVec(vals)
        list_utils.connectListNodesVec(nodes)

        val = 3
        self.checkResult("Test1", nodes[0], val)

    # 链表中有多个结点，删除尾结点
    def Test2(self):
        vals = [1, 2, 3, 4, 5]
        nodes = list_utils.createListNodesVec(vals)
        list_utils.connectListNodesVec(nodes)

        val = 5
        self.checkResult("Test2", nodes[0], val)

    # 链表中有多个结点，删除头结点
    def Test3(self):
        vals = [1, 2, 3, 4, 5]
        nodes = list_utils.createListNodesVec(vals)
        list_utils.connectListNodesVec(nodes)

        val = 1
        self.checkResult("Test3", nodes[0], val)

    # 链表中只有一个结点，删除头结点
    def Test4(self):
        vals = [1]
        nodes = list_utils.createListNodesVec(vals)
        list_utils.connectListNodesVec(nodes)

        val = 1
        self.checkResult("Test4", nodes[0], val)

    # 链表为空
    def Test5(self):
        val = -1
        self.checkResult("Test5", None, val)

    def runTest(self):
        self.Test1()
        self.Test2()
        self.Test3()
        self.Test4()
        self.Test5()


if __name__ == "__main__":
    test = Test()
    test.runTest()
