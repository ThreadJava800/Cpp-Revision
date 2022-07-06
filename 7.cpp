#include "bits/stdc++.h"


using namespace std;

vector<int> quick_sort(vector<int> values, int l, int r)
{
    int left = l, right = r;
    int pivot = values[(left + right) / 2];
    while (left <= right)
    {
        while (values[left] < pivot)
        {
            left++;
        }
        while (values[right] > pivot)
        {
            right--;
        }
        if (left <= right)
        {
            int tmp = values[left];
            values[left] = values[right];
            values[right] = tmp;
            left++;
            right--;
        }
    }
    if (l < right)
    {
        quick_sort(values, l, right);
    }
    if (left < r)
    {
        quick_sort(values, left, r);
    }
    return values;
}

signed main()
{
    int length;
    cin >> length;
    vector<int> numbers(length);
    for(int i = 0; i < length; i++)
    {
        cin >> numbers[i];
    }
    numbers = quick_sort(numbers, 0, length - 1);
    for(auto val : numbers)
    {
        cout << val << " ";
    }
    return 0;
}
