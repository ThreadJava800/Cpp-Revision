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
    if (s.compare(suffix) == 0)
    {
        return s.size();
    }
    if (suffix.size() > s.size())
    {
        return ans;
    }
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
    int q;
    cin >> q;
    cycle(m, 0, q)
    {
        int k, j;
        cin >> k >> j;
        if (j == 0)
        {
            cout << 0 << endl;
            continue;
        }
        vector<string> greys(k);
        greys[0] = "a";
        cycle(i, 1, k)
        {
            greys[i] = greys[i - 1] + char(97 + i) + greys[i - 1];
        }
        string last = greys.back();
        cout << get_longest(last, last.substr(j, last.size() - j)) << endl;
    }

    return 0;
}