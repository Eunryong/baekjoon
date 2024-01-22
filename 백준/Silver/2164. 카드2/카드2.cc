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

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    while (q.size() != 1) {
        q.pop();
        int tmp = q.front();
        q.pop();
        q.push(tmp);
    }
    cout << q.front();

    return 0;
}