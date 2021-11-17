#include <iostream>
#include <algorithm> // for function std::swap

// Node type of tree
struct TreeNode
{
    TreeNode *lchild; // Left child
    TreeNode *rchild; // Right child
    int val;

    /**
     * Constructor of TreeNode.
     * @param v Data to be stored in *this.
     * @param l Left child node of this node.
     * @param r Right child node of this node.
     */
    TreeNode(int v = 0, TreeNode *l = nullptr, TreeNode *r = nullptr)
    : lchild(l), rchild(r), val(v)
    {
    }
};

/**
 * @brief Swap the tree's left child with its right child.
 * Also do the same operations on its children.
 * @param root The root of the tree to be inverted.
 * @return The end node of the result tree. Equals to (@code root).
 */
TreeNode *invert_tree(TreeNode *root)
{
    if (!root)
    {
        return root;
    }

    std::swap(root->lchild, root->rchild);
    invert_tree(root->lchild);
    invert_tree(root->rchild);

    return root;
}

/**
 * @brief Print the preorder of a tree.
 * @param root The root of the tree to print.
 */
void preorder_search(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    std::cout << root->val << ' ';
    preorder_search(root->lchild);
    preorder_search(root->rchild);
}

int main()
{
    // Input format:
    // First line: n rt (how many nodes the tree has; root of the tree.)
    // Next n lines (line 2..n+1):
    // i+1-th line: l_i r_i (lchild and rchild of i-th node, 0 means null.)
    int n, rt;
    TreeNode *arr[10001] = {nullptr};
    std::cin >> n >> rt;

    // Initialize the nodes.
    for (int i = 1; i <= n; ++i)
    {
        arr[i] = new TreeNode(i);
    }

    // Build the tree.
    for (int i = 1; i <= n; ++i)
    {
        int l, r;
        std::cin >> l >> r;
        arr[i]->lchild = arr[l];
        arr[i]->rchild = arr[r];
    }

    preorder_search(invert_tree(arr[rt]));
}