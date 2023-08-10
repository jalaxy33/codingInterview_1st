class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def createListNode(value) -> ListNode:
    return ListNode(value)


def connectListNodes(curNode: ListNode, nextNode: ListNode):
    if curNode is None:
        print("Error to connect two nodes.")
    curNode.next = nextNode


def printListNode(node: ListNode):
    if node is None:
        print("The node is None")
    else:
        print(f"The key in node is {node.val}")


def printList(head: ListNode):
    print("PrintList starts.")

    import copy

    node = copy.deepcopy(head)
    vals = []
    while node is not None:
        vals.append(node.val)
        node = node.next
    print(vals)
    print("PrintList ends.")


# ========= multi-nodes ==============


def createListNodesVec(vals: list[int]) -> list[ListNode]:
    nodes = []
    for i in range(len(vals)):
        nodes.append(createListNode(vals[i]))
    return nodes


def connectListNodesVec(nodes: list[ListNode]) -> None:
    if len(nodes) < 2:
        return
    for i in range(len(nodes) - 1):
        connectListNodes(nodes[i], nodes[i + 1])
