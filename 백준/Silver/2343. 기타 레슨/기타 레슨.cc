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
        v.push_back(tmp);
        sum += v[i];
    }

    int st = *max_element(v.begin(), v.end()), en = sum;
    while (st <= en) {
        int mid = (st + en) / 2;
        int size = 0;
        int tmp = 0;
        for (int i = 0; i < N; i++) {
            if (tmp + v[i] > mid) {
                tmp = 0;
                size++;
            }
            tmp += v[i];
        }
        if (tmp) size++;
        if (size <= M) en = mid - 1;
        else st = mid + 1;
    }
    cout << st << "\n";
    return 0;
}