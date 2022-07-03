#include <iostream>
#include <string>
#include <vector>

using data_t = unsigned short;

constexpr data_t MAX_CODE = 127;
constexpr size_t MAX_LEN = 9, MAX_SEGS = 3, MAX_SEG_LEN = 3;
// using sol_t = data_t [3];

struct sol_t
{
    data_t *elem = new data_t[MAX_SEGS] {0};

    sol_t()
    {
    }

    sol_t(const sol_t &other)
    {
        *this = other;
    }

    sol_t& operator=(const sol_t &other)
    {
        for (size_t i = 0; i < MAX_SEGS; ++i)
        {
            elem[i] = other[i];
        }
        return *this;
    }

    data_t& operator[](size_t index)
    {
        return elem[index];
    }

    const data_t& operator[](size_t index) const
    {
        return elem[index];
    }
};

std::ostream &operator<<(std::ostream &ost, const sol_t &sol)
{
    return ost << '{' << sol[0] << "、" << sol[1] << "、" << sol[2] << '}';
}

template<typename Tp>
std::ostream &operator<<(std::ostream &ost, const std::vector<Tp> &vec)
{
    ost << '[';
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (i > 0)
        {
            ost << '#';
        }

        ost << vec[i];
    }
    return ost << ']';
}

/**
 * @brief 将一个字符串转换成一个非负整数 data_t
 * 
 * @param s 要转换的字符串
 * @return data_t 转换的结果
 */
data_t to_code(const std::string &s)
{
    constexpr data_t BASE = 10;
    data_t res = 0;
    for (const auto &x : s)
    {
        res = res * BASE + (x - '0');
    }
    return res;
}

/**
 * @brief 判断一个字符串是否为合法的编码
 * 
 * @param s 待判断的字符串
 * @return true 该字符串是一个合法的编码
 * @return false 该字符串不是一个合法的编码
 */
bool check_code(const std::string &s)
{
    return s.length() == 1 ? true : (s[0] != '0' && to_code(s) < MAX_CODE);
}

const std::vector<sol_t>& dfs(size_t level, const std::string &s)
{
    static sol_t sol;               // 记录单次的方案
    static std::vector<sol_t> res;  // 记录所有方案

    if (level >= MAX_SEGS)
    {
        if (s.length() == 0)
        {
            res.push_back(sol);
        }
        return res;
    }

    for (size_t i = 1; i <= std::min(s.length(), MAX_SEG_LEN); ++i)
    {
        if (check_code(s.substr(0, i)))
        {
            sol[level] = to_code(s.substr(0, i));
            dfs(level + 1, s.substr(i));
            sol[level] = 0U;
        }
    }

    return res;
}

int main()
{
    std::string s;
    std::cin >> s;
    std::cout << dfs(0, s) << std::endl;
}