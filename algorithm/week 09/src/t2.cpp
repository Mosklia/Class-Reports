#include <iostream>

int main()
{
    int k, mod;
    std::cin >> k >> mod;

    int temp = 3, res = 1;
    for (int i = 1; i <= k; i <<= 1)
    {
        if (k & i) res = res * temp % mod;
        temp = temp * temp % mod;
    }

    std::cout << res << std::endl;
}