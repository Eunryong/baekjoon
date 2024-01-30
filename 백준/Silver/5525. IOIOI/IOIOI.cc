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

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    string s;
    for (int i = 0; i < N; i++) {
        s += "IO";
    }
    s += "I";
    string src;
    cin >> src;
    int ans = 0;
    for (int i = 0; i < src.size(); i++) {
        if (src.find(s, i) != string::npos){
            i = src.find(s, i);
            ans++;
        }
    }
    cout << ans;

    return 0;
}