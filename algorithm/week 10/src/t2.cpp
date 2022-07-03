#include <iostream>
#include <algorithm> // std::swap

const size_t MAXN = 100;

double a_arr[100], b_arr[100];
int *a = a_arr, *b = b_arr;
size_t n;

#define get_mid(arr, x, y) ((((y - x)) & 1) ? (arr[(x + y) / 2] + arr[(x + y + 1 / 2)]) / 2 : arr[(x + y) / 2])

int main()
{
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> b[i];
    }

    int al = 0, ar = n - 1, bl = 0, br = n - 1;
    double res = 0;
    bool flag = true;

    while (flag && ar > al)
    {
        if (get_mid(a, al, ar) > get_mid(b, bl, br))
        {
            std::swap(a, b);
        }
        int amid = (al + ar) / 2, bmid = (bl + br) / 2;
        int aml = amid, amr = amid + 1, bml = bmid, bmr = bmid + 1;
        if ((ar - al) % 1)
        {
            aml--;
            bml--;
        }
        if (get_mid(a, al, aml) > get_mid(b, bl, bml))
        {
            bl = br = -1;
            break;
        }
        else if (get_mid(a, amr, ar)  )
    }
}