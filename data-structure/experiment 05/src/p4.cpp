#include <iostream>
#include <algorithm>
#include <queue> // For std::queue.

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

// Max size of the tree.
const int maxn = 3000;

// Pre- and in-order array.
int pre_arr[maxn + 3], in_arr[maxn + 3];
// The order of elements appear in the pre- and in-order array.
int pre_order[maxn + 3], in_order[maxn + 3];

/**
 * @brief Construct the tree via given segment of @code pre_arr @endcode.
 * @param begin Beginning index of the given segment
 * @param end Ending index of the given segment.
 * @return Root of the tree to construct.
 */
TreeNode *construct(int begin, int end)
{
    // Segment is empty.
    if (begin > end)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(pre_arr[begin]);

    int root_in = in_order[root->val]; // Index of root in in_arr.

    int lc_begin = begin + 1;
    int lc_end = pre_order[in_arr[root_in - 1]];
    int rc_begin = std::max(lc_end, begin) + 1;
    int rc_end = end;

    root->lchild = construct(lc_begin, lc_end);
    root->rchild = construct(rc_begin, rc_end);

    return root;
}

/**
 * @brief Print the level-order array of the tree.
 * @param root The root of the tree to print.
 */
void print(TreeNode *root)
{
    std::queue<TreeNode*> que; // BFS queue
    que.push(root);

    while (!que.empty())
    {
        TreeNode *cur = que.front(); // Currently used node
        que.pop();
        std::cout << cur->val << ' ';

        // Access the children
        if (cur->lchild)
        {
            que.push(cur->lchild);
        }
        if (cur->rchild)
        {
            que.push(cur->rchild);
        }
    }
}

/**
 * @brief Delete the whole tree.
 * @param root Root of the tree to delete.
 */
void erase(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    // std::cout << root->val << ' ';

    erase(root->lchild);
    erase(root->rchild);
    delete root;
}

int main()
{
    int n; // Size of the tree.
    TreeNode *rt;

    while (std::cin >> n)
    {
        // Input the data.
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> pre_arr[i];
            pre_order[pre_arr[i]] = i;
        }
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> in_arr[i];
            in_order[in_arr[i]] = i;
        }

        // Construct the tree using the whole array.
        rt = construct(1, n);

        print(rt);

        erase(rt);
    }
    
}