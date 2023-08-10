from typing import Tuple

TreeIndex = Tuple[int, int, int]


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left: TreeNode = None
        self.right: TreeNode = None


# ==== single-node funcs ====


def createBinaryTreeNode(value) -> TreeNode:
    return TreeNode(value)


def connectTreeNodes(parent: TreeNode, left: TreeNode, right: TreeNode) -> None:
    if parent:
        parent.left = left
        parent.right = right


def printTreeNode(node: TreeNode) -> None:
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


def printTree(root: TreeNode) -> None:
    printTreeNode(root)
    if root:
        if root.left:
            printTree(root.left)
        if root.right:
            printTree(root.right)


# ==== multi-node funcs ====


def createTreeNodesVec(vals: list[int]) -> list[TreeNode]:
    nodes = []
    for i in range(len(vals)):
        nodes.append(createBinaryTreeNode(vals[i]))
    return nodes


def connectTreeNodesIndex(
    nodes: list[TreeNode], parent_i: int, left_i: int = -1, right_i: int = -1
) -> None:
    left = nodes[left_i] if left_i != -1 else None
    right = nodes[right_i] if right_i != -1 else None
    connectTreeNodes(nodes[parent_i], left, right)


def connectTreeNodesIndexVec(nodes: list[TreeNode], indexes: list[TreeIndex]):
    for idxs in indexes:
        parent_i, left_i, right_i = idxs
        connectTreeNodesIndex(nodes, parent_i, left_i, right_i)
