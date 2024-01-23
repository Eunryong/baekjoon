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
vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int sum = 0;
    for (int i = 666; sum < N; i++) {
        string s = to_string(i);
        if (s.find("666") != string::npos) {
            ans.push_back(i); 
            sum++;
        }
    }
    cout << ans.back();
    return 0;
}