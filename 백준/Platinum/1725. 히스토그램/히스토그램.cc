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
int N, ans, h, w;
int arr[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    stack<int> st;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    st.push(0);
    for (int i = 1; i <= N + 1; i++) {
        if (st.size() == 1 || arr[i] > arr[st.top()])
            st.push(i);
        else {
            while (st.size() != 1 && arr[i] <= arr[st.top()]) {
                h = arr[st.top()];
                st.pop();
                w = i - st.top() - 1;
                ans = max(ans, h * w);
            }
            st.push(i);
        }
    }
    cout << ans;
    return 0;
}