class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def CreateListNode(value) -> ListNode:
    return ListNode(value)


def ConnectListNodes(curNode: ListNode, nextNode: ListNode):
    if curNode is None:
        print("Error to connect two nodes.")
    curNode.next = nextNode


def PrintListNode(node: ListNode):
    if node is None:
        print("The node is None")
    else:
        print(f"The key in node is {node.val}")


def PrintList(head: ListNode):
    print("PrintList starts.")

    import copy

    node = copy.deepcopy(head)
    vals = []
    while node is not None:
        vals.append(node.val)
        node = node.next
    print(vals)
    print("PrintList ends.")
