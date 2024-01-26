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
    map<string, string> m;
    for (int i = 0; i < N; i++) {
        string d, p;
        cin >> d >> p;
        m.insert(make_pair(d, p));
    }
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        cout << m[s] << "\n";
    }

    return 0;
}