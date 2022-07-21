#include "bits/stdc++.h"
#define cycle(i, a, b) for(int i = a; i < b; i++)


using namespace std;


vector<string> get_preffixes(string s)
{
    vector<string> ans;
    ans.push_back("");
    cycle(r, 0, s.size())
    {
        ans.push_back(s.substr(0, r + 1));
    }
    return ans;
}

vector<string> get_suffixes(string s)
{
    vector<string> ans;
    ans.push_back("");
    cycle(r, 0, s.size())
    {
        ans.push_back(s.substr(r, s.size()));
    }
    return ans;
}

void print_vector(vector<string> vec)
{
    for (auto v : vec)
    {
        cout << v << " ";
    }
    cout << endl;
}


signed main() {
    int count;
    cin >> count;
    cycle(i, 0, count) 
    {
        int answer = 0;
        string str;
        cin >> str;
        vector<string> preffixes = get_preffixes(str);
        vector<string> suffixes = get_suffixes(str);
        cycle(j, 0, str.size())
        {
            cycle(k, j, str.size())
            {
                string substring = str.substr(j, k - j + 1);
                bool flag1 = (find(preffixes.begin(), preffixes.end(), substring) != preffixes.end());
                bool flag2 = (find(suffixes.begin(), suffixes.end(), substring) != suffixes.end());
                if ((flag1 || flag2) && !(flag1 && flag2))
                {
                    answer++;
                }
            }
        }
        cout << answer << endl;
    }
    return 0;
}