#include <iostream>
#include<bits/stdc++.h>
//#define INF numeric_limits<int>::max()
#define INF 100000
using namespace std;
vector<int> memo;
vector<int> coin;

int memoization(int n){
    if (n == 0) return 0;
    if (n < 0) return INF;
    if (memo[n] != -1) return memo[n];
    int best = INF;
    for (auto c : coin){
        best = min(best, memoization(n - c) + 1);
    }
    memo[n] = best;
    return best;
}

int main() {
    coin.push_back(1);
    coin.push_back(4);
    coin.push_back(5);
    int n = 12;
    memo.assign(n + 1, -1);
    cout<<memoization(n);
    return 0;
}
