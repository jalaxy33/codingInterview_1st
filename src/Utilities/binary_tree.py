class BinaryTreeNode:
    def __init__(self, x):
        self.val = x
        self.left: BinaryTreeNode = None
        self.right: BinaryTreeNode = None


# ==== single-node funcs ====


def createBinaryTreeNode(value) -> BinaryTreeNode:
    return BinaryTreeNode(value)


def connectTreeNodes(
    parent: BinaryTreeNode, left: BinaryTreeNode, right: BinaryTreeNode
) -> None:
    if parent:
        parent.left = left
        parent.right = right


def printTreeNode(node: BinaryTreeNode) -> None:
    if node:
        print(f"value of this node is: {node.val}.")

        if node.left:
            print(f"value of its left child is: {node.left.val}.")
        else:
            print("left child is nullptr.")

        if node.right:
            print(f"value of its left child is: {node.right.val}.")
        else:
            print("left child is nullptr.")
    else:
        print("this node is nullptr.")
    print("\n")


def printTree(root: BinaryTreeNode) -> None:
    printTreeNode(root)
    if root:
        if root.left:
            printTree(root.left)
        if root.right:
            printTree(root.right)


# ==== multi-node funcs ====


def createNodesVec(vals: list[int]) -> list[BinaryTreeNode]:
    nodes = []
    for i in range(len(vals)):
        nodes.append(createBinaryTreeNode(vals[i]))
    return nodes


def connectNodesIndex(
    nodes: list[BinaryTreeNode], parent_i: int, left_i: int = -1, right_i: int = -1
) -> None:
    left = nodes[left_i] if left_i != -1 else None
    right = nodes[right_i] if right_i != -1 else None
    connectTreeNodes(nodes[parent_i], left, right)
