class Node:
    def __init__(self, x: int, next: "Node" = None, random: "Node" = None):
        self.val = int(x)
        self.next = next
        self.random = random


def CreateNode(value) -> Node:
    return Node(value)


def BuildNodes(curNode: Node, nextNode: Node, randNode: Node):
    if curNode is None:
        print("Error to connect two nodes.")
    curNode.next = nextNode
    curNode.random = randNode


def PrintList(head: Node):
    node = head
    while node is not None:
        print(f"The value of this node is: {node.val}")
        if node.random is not None:
            print(f"The value of its random sibling is: {node.random.val}\n")
        else:
            print("This node does not have a sibling.\n")
        node = node.next
