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
    list<pair<int, int> > li;
    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;
        li.push_back({i, n});
    }
    for (int i = 1; i <= N; i++) {        
        int n = li.front().second;
        cout << li.front().first << " ";
        li.pop_front();
        if (n >= 0) {
            while (--n > 0) {
                li.push_back(li.front());
                li.pop_front();
            }
        } else {
            while (++n <= 0) {
                li.push_front(li.back());
                li.pop_back();
            }
        }
    }

    return 0;
}