#include <bits/stdc++.h>
#define cycle(i, a, b) for(int i = a; i < b; i++)

using namespace std;


signed main()
{
    int n;
    cin >> n;
    vector<int> values(n);
    cycle(i, 0, n - 1)
    {
        int temp;
        cin >> temp;
        values[temp - 1] = 1;
    }
    cycle(i, 0, values.size())
    {
        if(values[i] == 0)
        {
            cout << (i + 1);
            break;
        }
    }
    return 0;
}