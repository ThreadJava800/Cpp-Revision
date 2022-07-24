#include "bits/stdc++.h"
#define cycle(i, a, b) for(int i = a; i < b; i++)


using namespace std;

template<typename T>
void print_vector(vector<T> vec)
{
    for (auto v : vec)
    {
        cout << v << " ";
    }
}

vector<int> z_func(string s)
{
    int l, r, n = s.size();
    vector<int> z(n);
    z[0] = 0;
    l = r = 0;
    cycle(i, 1, n)
    {
        if(i <= r)
        {
            z[i] = min(z[i-l], r - i + 1);
        }
        while((z[i] + i < n) && (s[z[i] + i] == s[z[i]]))
        {
            z[i]++;
        }
        if(r < i + z[i] - 1)
        {
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;
}


signed main() 
{
    string s;
    cin >> s;
    print_vector(z_func(s));
    return 0;
}