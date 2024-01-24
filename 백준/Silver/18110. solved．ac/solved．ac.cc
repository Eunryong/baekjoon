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
    vector<int> v;
    if (N == 0) {
        cout << N;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    int st;
    float start = (float)N * 0.15;
    st = round(start);
    int sum = 0;
    for (int i = st; i < N - st; i++) {
        sum += v[i];
    }
    float ans = round((float)sum / (N - (2 * st)));
    cout << ans;
    return 0;
}