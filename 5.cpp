#include <bits/stdc++.h>
#define cycle(i, a, b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

signed main()
{
    int n;
    cin >> n;
    vector<int> values(n);
    ll counter = 0;
    cin >> values[0];
    cycle(i, 1, n)
    {
        cin >> values[i];
        if(values[i] < values[i - 1])
        {
            counter += (values[i - 1] - values[i]);
            values[i] = values[i - 1];
        }
    }
    cout << counter;
    return 0;
}

