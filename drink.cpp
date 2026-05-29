//https://zerojudge.tw/ShowProblem?problemid=o711

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int w1, w2, h1, h2;
    cin >> w1 >> w2 >> h1 >> h2;
    int v1, v2;
    v1 = w1 * w1 * h1;
    v2 = w2 * w2 * h2;
    vector<int> drinks(n);
    for (int i = 0; i < n; ++i) {
        cin >> drinks[i];
    }
    vector<int> deltaH(n);
    int maxH = -1;
    int totalVol = 0;
    int totalH = 0;
    int preVol = 0;
    for (int i = 0; i < n; ++i) {
        totalVol = preVol + drinks[i];
        if (preVol <= v1 && totalVol <= v1) {
            deltaH[i] = (totalVol - preVol) / (w1 * w1);
            
            
        } else if (preVol <= v1 && (v1 < totalVol) && totalVol <= (v1 + v2)) {
            deltaH[i] = (v1 - preVol) / (w1 * w1) + (totalVol - v1) / (w2 * w2);
            
            
        } else if (preVol > v1 && totalVol <= (v1 + v2)) {
            deltaH[i] = drinks[i] / (w2 * w2);
            
            
        } else if (preVol > v1 && totalVol > (v1 + v2)) {
            deltaH[i] = drinks[i] / (w2 * w2);
            if (deltaH[i] + totalH > h1 + h2) deltaH[i] = h1 + h2 - totalH;
            
        }
        if (deltaH[i] > maxH) maxH = deltaH[i];
        preVol = totalVol;
        totalH += deltaH[i];
    }
    cout << maxH << '\n';
    return 0;
}