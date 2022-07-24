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

int get_longest(string s, string suffix)
{
    int ans = 0;
    cycle(j, 0, s.size())
    {
        if (s[j] == suffix[j])
        {
            ans += 1;
        }
        else
        {
            break;
        }
    }
    return ans;
}


signed main() {
    vector<int> preffixes;
    string s;
    cin >> s;
    preffixes.resize(s.size());
    cycle(i, 1, s.size())
    {
        string suffix = s.substr(i, s.size() - i);
        preffixes[i] = get_longest(s, suffix);
    }
    print_vector(preffixes);
    return 0;
}