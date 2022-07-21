#include "bits/stdc++.h"
#define cycle(i, a, b) for(int i = a; i < b; i++)


using namespace std;


signed main() {
    int count;
    vector<string> strings;
    vector<int> answers;
    cin >> count;
    cin >> ws;
    cycle(i, 0, count) {
        int maxi = 1;
        string tmp;
        cin >> tmp;
        if(tmp == "")
        {
            maxi = 0;
        }
        cycle(j, 0, tmp.size()) {
            string substring = tmp.substr(0, j + 1);
            string reversed = substring;
            reverse(reversed.begin(), reversed.end());
            if(substring == reversed)
            {
                maxi = j + 1;
            }
        }
        cout << maxi << endl;
    }

    return 0;
}