"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

import complex_list
from complex_list import Node


class Solution:
    def copyRandomList(self, head: "Node", use_hash: bool = True) -> "Node":
        if use_hash:
            return self.copy_Hashtable(head)
        else:
            return self.copy_CatSplit(head)

    # 利用哈希表
    def copy_Hashtable(self, head: "Node") -> "Node":
        if head is None:
            return None
        cur = head
        # 存储“原节点-新节点”的映射关系
        dic = {}
        while cur:
            dic[cur] = Node(cur.val)
            cur = cur.next
        # 调整新链表节点的next和random指向
        cur = head
        while cur:
            # 这里要用get方法来查询键值，若无该键则返回None
            dic[cur].next = dic.get(cur.next)
            dic[cur].random = dic.get(cur.random)
            cur = cur.next
        return dic[head]

    # 利用拼接+拆分
    def copy_CatSplit(self, head: "Node") -> "Node":
        if head is None:
            return None
        cur = head
        # 1. 复制各节点，并作为原节点的next拼接至原链表
        while cur:
            tmp = Node(cur.val)
            tmp.next = cur.next
            cur.next = tmp
            cur = tmp.next
        # 2. 调整新节点的random指向
        cur = head
        while cur:
            if cur.random:
                cur.next.random = cur.random.next
            cur = cur.next.next
        # 3. 拆分两链表
        cur = new_head = head.next
        pre = head
        while cur.next:
            pre.next = pre.next.next
            cur.next = cur.next.next
            pre = pre.next
            cur = cur.next
        pre.next = None
        return new_head


class Test:
    def __init__(self) -> None:
        self.solution = Solution()

    def testMain(self, testName: str, head: Node):
        text = ">>>"
        if testName:
            text += testName + " begins:"
        print(text)

        print("[original] list is:")
        complex_list.PrintList(head)

        copied_head = self.solution.copyRandomList(head)
        print("[copied] list is:")
        complex_list.PrintList(copied_head)

    def Test1(self):
        pNode1 = complex_list.CreateNode(1)
        pNode2 = complex_list.CreateNode(2)
        pNode3 = complex_list.CreateNode(3)
        pNode4 = complex_list.CreateNode(4)
        pNode5 = complex_list.CreateNode(5)

        complex_list.BuildNodes(pNode1, pNode2, pNode3)
        complex_list.BuildNodes(pNode2, pNode3, pNode5)
        complex_list.BuildNodes(pNode3, pNode4, None)
        complex_list.BuildNodes(pNode4, pNode5, pNode2)

        self.testMain("Test1", pNode1)

    def Test2(self):
        pNode1 = complex_list.CreateNode(1)
        pNode2 = complex_list.CreateNode(2)
        pNode3 = complex_list.CreateNode(3)
        pNode4 = complex_list.CreateNode(4)
        pNode5 = complex_list.CreateNode(5)

        complex_list.BuildNodes(pNode1, pNode2, None)
        complex_list.BuildNodes(pNode2, pNode3, pNode5)
        complex_list.BuildNodes(pNode3, pNode4, pNode3)
        complex_list.BuildNodes(pNode4, pNode5, pNode2)

        self.testMain("Test2", pNode1)

    def Test3(self):
        pNode1 = complex_list.CreateNode(1)
        pNode2 = complex_list.CreateNode(2)
        pNode3 = complex_list.CreateNode(3)
        pNode4 = complex_list.CreateNode(4)
        pNode5 = complex_list.CreateNode(5)

        complex_list.BuildNodes(pNode1, pNode2, None)
        complex_list.BuildNodes(pNode2, pNode3, pNode4)
        complex_list.BuildNodes(pNode3, pNode4, None)
        complex_list.BuildNodes(pNode4, pNode5, pNode2)

        self.testMain("Test3", pNode1)

    def Test4(self):
        pNode1 = complex_list.CreateNode(1)
        complex_list.BuildNodes(pNode1, None, pNode1)
        self.testMain("Test4", pNode1)

    def Test5(self):
        self.testMain("Test4", None)

    def runTest(self):
        self.Test1()
        self.Test2()
        self.Test3()
        self.Test4()
        self.Test5()


if __name__ == "__main__":
    test = Test()
    test.runTest()
