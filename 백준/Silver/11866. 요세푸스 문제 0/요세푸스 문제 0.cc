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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    vector<int> v;
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        v.push_back(i);
    }

    int i = K - 1;
    while (!v.empty()) { // 1 0 0 
        if (v.size() == 1) {
            i = 0;
        } else if (i >= v.size()) {
            i = i % v.size();
        }
        ans.push_back(v[i]);
        v.erase(v.begin() + i);
        i += K - 1;
    }

    cout << "<";
    for (int i = 0; i < N; i++) {
        cout << ans[i];
        if (i != N - 1) {
            cout << ", ";
        }
    }
    cout << ">";
    
    return 0;
}