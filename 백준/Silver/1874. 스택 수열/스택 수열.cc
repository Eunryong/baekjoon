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
int arr[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    stack<int> s;
    vector<string> v;

    s.push(0);
    for (int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        if (arr[tmp] == 0 && s.size() && s.top() < tmp){
            for (int i = 1; i <= tmp; i++) {
                if (arr[i] != 0) continue;
                arr[i] = 1;
                s.push(i);
                v.push_back("+");
            }
        } else if (arr[tmp] && s.size() && s.top() != tmp) {
            cout << "NO\n";
            return 0;
        }
        if (arr[tmp] && s.size() && s.top() == tmp) {
            s.pop();
            v.push_back("-");
            arr[tmp] = -1;
        }
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }
    return 0;
}