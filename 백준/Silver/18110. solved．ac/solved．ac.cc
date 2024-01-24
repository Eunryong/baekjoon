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
    if (N == 0) {
        cout << N;
        return 0;
    }
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    int st;
    double start = (double)N * 0.15;
    st = round(start);
    int sum = 0;
    for (int i = st; i < v.size() - st; i++) {
        sum += v[i];
    }
    double ans = (double)sum / (v.size() - (2 * st));
    double r_ans = round(ans);
    cout << r_ans;
    return 0;
}