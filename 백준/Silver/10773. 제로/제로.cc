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
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == 0) 
            v.pop_back();
        else
            v.push_back(tmp);
    }
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    cout << sum;
    return 0;
}