#include <iostream>
using namespace std;
int main() {
// 優化輸入輸出效率
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    float Weight, Height;
    cin >> Weight >> Height;

    float BMI;
    BMI = Weight / ((Height / 100) * (Height / 100));
    cout << "BMI = " << BMI << endl;
    
    return 0;
}