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
 * Transform a bintree into a chain.
 * All lchild of nodes will be null.
 * @param root The root of the tree to be flatten.
 * @return The end node of the result chain.
 */
TreeNode *flatten(TreeNode *root)
{
    if (!root || (!root->lchild && !root->lchild))
    {
        return root;
    }

    TreeNode *lend = nullptr, *rend = nullptr;

    rend = flatten(root->rchild);
    lend = flatten(root->lchild);

    if (root->lchild)
    {
        lend->rchild = root->rchild;
        root->rchild = root->lchild;
        root->lchild = nullptr;
    }

    return rend;
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

    flatten(arr[rt]);

    TreeNode *temp = arr[rt];
    while (temp)
    {
        std::cout << temp->val << '\n';
        temp = temp->rchild;
    }
    
}