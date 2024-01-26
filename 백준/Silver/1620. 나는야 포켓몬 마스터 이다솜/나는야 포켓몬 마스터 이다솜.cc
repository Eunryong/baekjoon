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
    map<int, string> m;
    map<string, int> m2;
    for (int i = 0; i < N; i++) {
        string s;
        cin >>s;
        m.insert(make_pair(i + 1, s));
        m2.insert(make_pair(s, i + 1));
    }
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        if (isdigit(s[0])) {
            int tmp = stoi(s);
            cout << m[tmp] << "\n";
        } else {
            cout << m2[s] << "\n";
        }
    }
    return 0;
}