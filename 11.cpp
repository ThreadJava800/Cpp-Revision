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


signed main() {
    int q;
    cin >> q;
    cycle(i, 0, q)
    {
        string s, t;
        cin >> s >> t;
        int counter = 0;
        map<string, bool> pairs;
        cycle(j, 0, s.size())
        {
            cycle(k, j, s.size())
            {
                string sub = s.substr(j, k - j + 1);
                if (pairs[sub])
                {
                    counter++;
                    continue;
                }
                if ((sub.size() < t.size()) || pairs[sub])
                {
                    pairs[sub] = true;
                    counter++;
                    continue;
                }
                if (sub.find(t) == string::npos)
                {
                    pairs[sub] = true;
                    counter++;
                }
                else {
                    pairs[sub] = false;
                }
            }
        }
        cout << counter << endl;
    }
    return 0;
}