#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

vector<int> G[100010];

long long W[100010], P[100010];

long long dfsW(int p, int v) {
    long long w = 1;
    for(int i=0; i<G[v].size(); i++) {
        int u = G[v][i];
        if (u == p) continue;
        
        w += dfsW(v, u);
    }
    W[v] = w;
    return w;
}

void dfsP(int p, int v, int d) {
    P[v] = d;
    for(int i=0; i<G[v].size(); i++) {
        int u = G[v][i];
        if (u == p) continue;
        
        dfsP(v, u, d+1);
    }
}   



int main() {
    int N;
    while(cin >> N) {
        for(int i=0; i<N-1; i++) {
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        dfsW(-1, 1);
        dfsP(-1, 1, 0);

        double totA = 0, totB =0;
        for(int i=1; i<=N; i++) {
            totA += P[i] * (N-W[i]);
            totB += P[i];
        }

        cout << fixed << setprecision(8) << (totA / totB) << endl;
    }

}
