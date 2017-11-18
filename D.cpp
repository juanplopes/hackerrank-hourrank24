#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

long long A[1000100], B[1000100];
priority_queue<long long> Q;



int main() {
    int N, M, X, K;
    while(cin >> N >> M >> X >> K) {
        while(Q.size() > 0) Q.pop();
        
        for(int i=1; i<=N; i++)
            cin >> A[i];
        
        for(int i=1; i<=M; i++)
            cin >> B[i];

        for(int i=1; i<=min(N, M-X); i++) {
            for(int j=i+X; j<=M; j++) {
                long long v = A[i]*B[j];
                //cout << " " << A[i] << " " << B[j] << " " << v << endl;
                if (Q.size() < K) {
                    Q.push(v);
                } else if (Q.top() > v) {
                    Q.pop(); Q.push(v);
                }
            }
        }
        
        cout << Q.top() << endl;
        
    }

}
