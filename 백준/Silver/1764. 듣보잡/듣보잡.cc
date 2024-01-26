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
#include <set>
using namespace std;

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    map<string, int> m;
    map<string, int> m2;
    set<string> se;
    for(int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        m.insert(make_pair(s, i));
    }
    for(int i = 0; i < M; i++) {
        string s;
        cin >> s;
        if (m[s]) se.insert(s);
    }
    cout << se.size() << "\n";
    for (set<string>::iterator it = se.begin(); it != se.end(); it++) {
        cout << *it << "\n";
    }
    return 0;
}