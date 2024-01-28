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
    priority_queue<int, vector<int>, greater<int> > pq;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (!tmp) {
            if (!pq.size())
                cout << "0\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else {
            pq.push(tmp);
        }
    }
    return 0;
}