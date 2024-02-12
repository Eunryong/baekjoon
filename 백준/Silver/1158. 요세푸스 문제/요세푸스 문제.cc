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
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }
    cout << "<";
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < K - 1; j++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        q.pop();
        if (i != N) {
            cout << ", ";
        }
    }
    cout << ">";
    return 0;
}