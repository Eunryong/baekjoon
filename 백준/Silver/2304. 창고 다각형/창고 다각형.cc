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
int arr[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    stack<int> st;
    for (int i = 1; i <= N; i++) {
        int L, H;
        cin >> L >> H;
        arr[L] = H;
    }
    int n = 0;
    for (int i = 1; i <= 1000; i++) {
        if (n <= arr[i]) {
            n = arr[i];
            st.push(i);
        }
    }
    int ans = n;
    while (!st.empty()) {
        int i = st.top();
        st.pop();
        if (st.size())
            ans += (i - st.top()) * arr[st.top()];
    }
    n = 0;
    for (int i = 1000; i >= 1; i--) {
        if (n < arr[i]) {
            n = arr[i];
            st.push(i);
        }
    }
    while (!st.empty()) {
        int i = st.top();
        st.pop();
        if (st.size())
            ans += (st.top() - i) * arr[st.top()];
    }
    cout << ans;

    return 0;
}