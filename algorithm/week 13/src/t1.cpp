#include <iostream>
#include <string>

int main()
{
    size_t cur = 0;
    std::string s, t;
    std::cin >> s >> t;

    for (auto x : s)
    {
        if (x == t[cur])
        {
            ++cur;
            if (cur == t.length())
            {
                break;
            }
        }
    }

    std::cout << (cur == t.length() ? "true" : "false") << std::endl;
}