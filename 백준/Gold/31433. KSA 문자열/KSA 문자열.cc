#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <cmath>
using namespace std;
int N, K;
int check(string s, string c) {
    int j = 0;
    int cnt = 0;
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        if (j >= 3) j = 0;
        if (s[i] == c[j]) {
            cnt += i - cur;
            cur = i + 1;
            j++;
        } else if (s.size() - 1 == i) {
            cnt += s.size() - cur;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s;
    int ksa, sak, aks; 
    ksa = check(s, "KSA");
    sak = check(s, "SAK");
    aks = check(s, "AKS");
    ksa *= 2;
    if (sak < 1) {
        sak +=2;
    } else {
        sak *= 2;
    }
    if (aks < 2) {
        aks += aks * 2;
    } else {
        aks *= 2;
    }
    // cout << ksa << " " << sak << " "  << aks;
    cout << min(ksa, min(aks, sak));
    return 0;
}