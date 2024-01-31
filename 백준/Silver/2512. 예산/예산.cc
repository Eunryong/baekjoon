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
int M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    cin >> M;
    int st = 0, en = *max_element(v.begin(), v.end());
    while (st <= en) {
        int mid = (st + en) / 2;
        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (mid > v[i])
                sum += v[i];
            else
                sum += mid;
        }
        if (sum <= M) st = mid + 1;
        else en = mid - 1;
    }
    cout << st - 1;
    return 0;
}