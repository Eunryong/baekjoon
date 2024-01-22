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
    map<long, int> m;
    for (int i = 0; i < N; i++) {
        long tmp;
        cin >> tmp;
        if (m.count(tmp)) {
            m.find(tmp)->second++;
        } else {
            m.insert(make_pair(tmp, 1));
        }
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        long tmp;
        cin >> tmp;
        if (m.count(tmp))
         cout << m.find(tmp)->second << " ";
        else
         cout << "0 ";
    }
    return 0;
}