#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    if (!(cin >> N >> M)) return 0;
    priority_queue<int> pq;
    for (int i = 1; i <= N; ++i) {
        int Ai;
        cin >> Ai;
        int initial_profit = Ai - (i - 1);
        if (initial_profit > 0) pq.push(initial_profit);
    }
    long long total_max_profit = 0;
    for (int day = 0; day < M; ++day) {
        if (pq.empty()) break;
        int current_best = pq.top();
        pq.pop();
        total_max_profit += current_best;
        if (current_best - 1 > 0) pq.push(current_best - 1);
    }
    cout << total_max_profit << '\n';
    return 0;
}