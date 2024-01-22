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

    cin >> N;
    map<int, string> m;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        m.insert(make_pair(tmp, ""));
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        if (m.count(tmp)) {
            cout << "1\n";
        } else
            cout << "0\n";
    }
    return 0;
}