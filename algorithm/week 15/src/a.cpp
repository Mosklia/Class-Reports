#include <iostream>

// 用来表示棋盘局面的数据类型
using stat_t = unsigned short;

/**
 * @brief 递归求解 n-皇后问题
 *
 * @param level 当前递归剩余的深度，亦为当前正在放置的皇后的倒序次序
 * @param n 棋盘宽度，亦为问题中的 n
 * @param left 由于右上方存在皇后，本层无法放置皇后的位置
 * @param mid 由于正上方存在皇后，本层无法放置皇后的位置
 * @param right 由于左上方存在皇后，本层无法放置皇后的位置
 * @return size_t
 */
size_t dfs(size_t level, size_t n, stat_t left = 0U, stat_t mid = 0U, stat_t right = 0U)
{
    // 找到一组合法方案
    if (level <= 0)
    {
        return 1U;
    }

    const stat_t mask = (1U << n) - 1;      // 当前层的位掩码
    const stat_t stat = left | mid | right; // 上一层传下来的无法放置皇后的位置
    size_t res = 0;                         // 本层计算出的答案

    for (size_t i = 0; i < n; ++i)
    {
        const stat_t next_state = 1U << i; // 本层将要放置的皇后所处的位置
        if (stat & next_state)
        {
            continue;
        }

        // 向下移动一层后，left 会向左移动一位，right 会向右移动一位，mid 不变
        // 最后再与 mask 按位与来保证不在棋盘内的格子不受影响（虽然不按位与也没问题就是了）
        res += dfs(
            level - 1,
            n,
            ((left | next_state) << 1) & mask,
            (mid | next_state) & mask,
            ((right | next_state) >> 1) & mask);
    }

    return res;
}

int main()
{
    size_t n;
    std::cin >> n;
    std::cout << dfs(n, n) << std::endl;
}
