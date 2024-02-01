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

char lc[26];
char rc[26];
int N;

void preorder(char p) {
    cout << p;
    if (lc[p - 'A']) 
        preorder(lc[p - 'A']);
    if (rc[p - 'A'])
        preorder(rc[p - 'A']);
}

void inorder(char p) {
    if (lc[p - 'A'])
        inorder(lc[p - 'A']);
    cout << p;
    if (rc[p - 'A'])
        inorder(rc[p - 'A']);
}

void postorder(char p) {
    if (lc[p - 'A'])
        postorder(lc[p - 'A']);
    if (rc[p - 'A'])
        postorder(rc[p - 'A']);
    cout << p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    char p, l, c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> p >> l >> c;
            if (isalpha(l)) {
                lc[p - 'A'] = l;
            }
            if (isalpha(c)) {
                rc[p - 'A'] = c;
            }
        }
    }
    
    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');

    return 0;
}