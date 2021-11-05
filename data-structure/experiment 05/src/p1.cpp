#include <iostream>
#include <algorithm> // for function std::max

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
 * Find the depth of subtree p, assuming depth of p is d.
 * @param p The root of subtree to be processed.
 * @param d The depth of node p.
 * @return The depth of the subtree.
 */
int dfs(TreeNode *p, int d = 1)
{
    int res = d; // Result

    // DFS
    if (p->lchild)
    {
        // Update the res.
        res = std::max(res, dfs(p->lchild, d + 1));
    }
    if (p->rchild)
    {
        // See line 36.
        res = std::max(res, dfs(p->rchild, d + 1));
    }

    return res;
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

    // Print result.
    std::cout << dfs(arr[rt]) << std::endl;
}
