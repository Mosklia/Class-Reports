#include <iostream>
#include <algorithm>
#include <string>

const int maxm = 26;

int arr[maxm * 2 + 1];

int find(int t)
{
    return t == arr[t] ? t : (arr[t] = find(arr[t]));
}

void join(int x, int y)
{
    arr[find(arr[x])] = arr[find(arr[y])];
}

int main()
{
    int n;
    while (std::cin >> n)
    {
        for (int i = 1; i <= 2 * maxm; ++i)
        {
            arr[i] = i;
        }

        for (int i = 1; i <= n; ++i)
        {
            std::string s;
            std::cin >> s;

            const int a = s[0] - 96, b = s[3] - 96;
            const int a2 = a + maxm, b2 = b + maxm;

            if (s[1] == '!')
            {
                join(a, b2);
                join(b, a2);
            }
            else
            {
                join(a, b);
                join(b2, a2);
            }
        }

        bool flag = true;

        for (int i = 1; i <= maxm; ++i)
        {
            if (find(i) == find(i + maxm))
            {
                flag = false;
                break;
            }
        }

        std::cout << (flag ? '1' : '0') << std::endl;
    }
}