#include "bits/stdc++.h"

#define cycle(i, a, b) for(int i = a; i < b; i++)

using namespace std;

int main() {
    string s;
    cin >> s;
    s += "$";
    size_t n = s.size();
    vector<int> p(n), c(n);
    {
        vector<pair<char, int>> arr(n);
        cycle(i, 0, n) arr[i] = {s[i], i};
        sort(arr.begin(), arr.end());
        cycle(i, 0, n) p[i] = arr[i].second;
        c[p[0]] = 0;
        cycle(i, 0, n - 1) {
            if (arr[i].first == arr[i + 1].first) {
                c[p[i + 1]] = c[p[i]];
            } else {
                c[p[i + 1]] = c[p[i]] + 1;
            }
        }
    }
    {
        int k = 0;
        while ((1 << k) < n) {
            vector<pair<pair<int, int>, int>> arr(n);
            cycle(i, 0, n) arr[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
            sort(arr.begin(), arr.end());
            cycle(i, 0, n) p[i] = arr[i].second;
            c[p[0]] = 0;
            cycle(i, 0, n - 1) {
                if (arr[i].first == arr[i + 1].first) {
                    c[p[i + 1]] = c[p[i]];
                } else {
                    c[p[i + 1]] = c[p[i]] + 1;
                }
            }
            k++;
        }
    }
    cycle(i, 0, n) cout << p[i] << " ";
    return 0;
}