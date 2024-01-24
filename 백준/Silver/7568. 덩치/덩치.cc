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
int arr[51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector< pair<int, int> > v;
    cin >> N;
    fill_n(arr, 50, 1);
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j)
                continue;
            if ((v[i].first) < v[j].first && v[i].second < v[j].second) {
                arr[i]++;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }


    return 0;
}