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

    def checkResult(self, head: ListNode):
        list_utils.printListNode(head)
        print(self.solution.reversePrint(head, True))
        print(self.solution.reversePrint(head, False))

    def Test1(self):
        print("\nTest1:\n")
        vals = [1,2,3,4,5]
        nodes = list_utils.createListNodesVec(vals)
        list_utils.connectListNodesVec(nodes)

        self.checkResult(nodes[0])

    # 只有一个结点的链表: 1
    def Test2(self):
        print("\nTest1:\n")
        node1 = list_utils.createListNode(1)

        self.checkResult(node1)

    # 空链表
    def Test3(self):
        print("\nTest1:\n")
        self.checkResult(None)

    def runTest(self):
        self.Test1()
        self.Test2()
        self.Test3()


if __name__ == "__main__":
    test = Test()
    test.runTest()
    
