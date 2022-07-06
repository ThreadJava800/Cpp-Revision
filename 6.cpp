#include "bits/stdc++.h"
#define cycle(i, a, b) for(int i = a; i < b; i++)

using namespace std;


int binary_search(vector<int> sorted_numbers, int key)
{
    int middle = -1;
    int left = 0;
    int right = sorted_numbers.size();
    while (left < right)
    {
        middle = (left + right) / 2;
        if (sorted_numbers[middle] > key)
        {
            right = middle;
        }
        else
        {
            left = middle + 1;
        }
    }
    return middle;
}

signed main()
{
    int n, key;
    cin >> n;
    vector<int> numbers(n);
    cycle(i, 0, n)
    {
        cin >> numbers[i];
    }
    cin >> key;
    sort(numbers.begin(), numbers.end());
    int key_index = binary_search(numbers, key);
    if (key_index != -1)
    {
        cout << key_index;
    }
    return 0;
}
