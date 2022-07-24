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
    cout << endl;
}


bool compare(string t, string p)
{
    cycle(l, 0, t.size())
    {
        if((p[l] != t[l]) && (p[l] != '?'))
        {
            return false;
        }
    }
    return true;
}


signed main() {
    int q;
    cin >> q;
    cycle(i, 0, q)
    {
        vector<int> indexes;
        string t, p;
        cin >> t >> p;
        if (t.size() >= p.size())
        {
            cycle(j, 0, t.size() - p.size() + 1)
            {
                if (compare(t.substr(j, p.size()), p))
                {
                    indexes.push_back(j);
                }
            }
        }
        cout << indexes.size() << endl;
        print_vector(indexes);
    }
    return 0;
}