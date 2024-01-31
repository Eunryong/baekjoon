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
    vector<int> v;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        sum += tmp;
        v.push_back(tmp);
    }
    int st = 1; int en = sum;
    int ans = 0;
    while (st <= en) {
        int mid = (st + en) / 2;
        int size = 1;
        int total = mid;
        bool c = 1;
        for (int i = 0; i < N; i++) {
            if (v[i] > mid) {
                c = 0;
                break;
            }
            if (v[i] > total) {
                total = mid;
                size++;
            }
            total -= v[i];
        }
        if (!c || size > M) st = mid + 1;
        else {
            ans = mid;
            en = mid - 1;
        }
    }
    cout << ans;
    return 0;
}