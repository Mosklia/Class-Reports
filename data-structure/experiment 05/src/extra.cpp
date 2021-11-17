#include <iostream>
#include <algorithm>

const int maxn = 100000;

struct count_node
// Storages the original value of elements in the array
// and its frequency.
{
    int value, frequency;

    /**
     * @brief Constructor of struct count_node.
     * @param v Value of the element.
     * @param f Frequency of the element.
     */
    count_node(int v = 0, int f = 0)
    : value(v), frequency(f)
    {
    }

    /**
     * @brief This does what you think it does.
     * @param other The other node to compare.
     * @return Whether @code this->value @endcode
       appears more than @code other.value @endcode
     */
    bool operator< (const count_node &other) const
    {
        return frequency > other.frequency;
    }
};

int arr[maxn]; // The given array.
count_node cnt[maxn]; // Count the elements.

int main()
{
    int n, k;

    while (std::cin >> n >> k)
    {
        for (int i = 0; i < n; ++i)
        {
            std::cin >> arr[i];
        }

        std::sort(arr, arr + n); // First sort
        // After this sort, the same elems are continous.

        int temp = 1; // How many different elems do we have.

        cnt[0].value = arr[0];
        cnt[0].frequency = 1;

        for (int i = 1; i < n; ++i)
        {
            // A unique elem was found.
            if (arr[i] != arr[i - 1])
            {
                cnt[temp++].value = arr[i];
            }

            ++cnt[temp - 1].frequency; // Add the counter.
        }

        std::sort(cnt, cnt + temp); // Second sort
        // After this sort, all counter are ordered by their values.
        // And elements are ordered by their frequency.

        for (int i = 0; i < k; ++i)
        {
            std::cout << cnt[i].value << ' ';
        }
        std::cout << std::endl;

        // Reset the counters.
        for (int i = 0; i < temp; ++i)
        {
            cnt[i] = count_node();
        }
    }
    
}