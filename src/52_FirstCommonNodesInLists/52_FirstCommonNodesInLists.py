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
    # 双指针A和B分别从两个链表头出发。当A遍历完A链表开始遍历B链表，反之亦然。
    # 由于遍历的长度一致，因此一定会在重合点相遇，此时A==B，返回A或B均可。
    # 设A链B链长度分别为a和b，重合长度为c。则每个指针走的距离均为 a + b -c。
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if headA == headB:
            return headA
        if not headA or not headB:
            return None

        A, B = headA, headB
        while A != B:
            A = A.next if A else headB
            B = B.next if B else headA
        return A


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def checkResult(
        self, testName: str, headA: ListNode, headB: ListNode, pExpected: ListNode
    ) -> None:
        text = testName
        pResult = self.solution.getIntersectionNode(headA, headB)
        if pResult == pExpected:
            text += " passed."
        else:
            text += " failed."
        print(text)

    # 第一个公共结点在链表中间
    # 1 - 2 - 3 \
    #            6 - 7
    #     4 - 5 /
    def Test1(self):
        vals1 = [1, 2, 3, 6, 7]
        vals2 = [4, 5]

        nodes1 = list_utils.createListNodesVec(vals1)
        nodes2 = list_utils.createListNodesVec(vals2)
        list_utils.connectListNodesVec(nodes1)
        list_utils.connectListNodesVec(nodes2)

        list_utils.connectListNodes(nodes2[1], nodes1[3])
        self.checkResult("Test1", nodes1[0], nodes2[0], nodes1[3])

    # 没有公共结点
    # 1 - 2 - 3 - 4
    #
    # 5 - 6 - 7
    def Test2(self):
        vals1 = [1, 2, 3, 4]
        vals2 = [5, 6, 7]

        nodes1 = list_utils.createListNodesVec(vals1)
        nodes2 = list_utils.createListNodesVec(vals2)
        list_utils.connectListNodesVec(nodes1)
        list_utils.connectListNodesVec(nodes2)

        self.checkResult("Test2", nodes1[0], nodes2[0], None)

    # 公共结点是最后一个结点
    # 1 - 2 - 3 - 4 \
    #                7
    #         5 - 6 /
    def Test3(self):
        vals1 = [1, 2, 3, 4, 7]
        vals2 = [5, 6]

        nodes1 = list_utils.createListNodesVec(vals1)
        nodes2 = list_utils.createListNodesVec(vals2)
        list_utils.connectListNodesVec(nodes1)
        list_utils.connectListNodesVec(nodes2)

        list_utils.connectListNodes(nodes2[1], nodes1[4])
        self.checkResult("Test3", nodes1[0], nodes2[0], nodes1[4])

    # 公共结点是第一个结点
    # 1 - 2 - 3 - 4 - 5
    # 两个链表完全重合
    def Test4(self):
        vals1 = [1, 2, 3, 4, 5]
        nodes1 = list_utils.createListNodesVec(vals1)
        list_utils.connectListNodesVec(nodes1)

        self.checkResult("Test4", nodes1[0], nodes1[0], nodes1[0])

    # 输入的两个链表有一个空链表
    def Test5(self):
        vals1 = [1, 2, 3, 4, 5]
        nodes1 = list_utils.createListNodesVec(vals1)
        list_utils.connectListNodesVec(nodes1)

        self.checkResult("Test5", nodes1[0], None, None)

    # 输入的两个链表都是空链表
    def Test6(self):
        self.checkResult("Test6", None, None, None)

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
