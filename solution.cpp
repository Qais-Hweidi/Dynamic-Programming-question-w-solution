// Qais Hweidi

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    
    int N;
    cin >> N;

    vector<double> x(N), y(N), energy(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> energy[i];
    }

    vector<double> maxArr(N, 0);
    maxArr[0] = energy[0];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            double dst = distance(x[j], y[j], x[i], y[i]);
            maxArr[i] = max(maxArr[i], maxArr[j] + energy[i] - dst);
        }
    }

    printf("%.4f", maxArr[N-1]);

    return 0;
}


