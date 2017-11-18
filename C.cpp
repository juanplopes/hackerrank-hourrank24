#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
using namespace std;

vector<int> T;

int main() {
    int test; cin >> test;
    int A, B, X;
    while(cin >> A >> B >> X) {
        T.clear();
        for(int i=B; i>=A and T.size() < X; i--) {
            bool ok = true;
            for(int j=0; j<T.size() and ok; j++) {
                ok = ok and T[j] % i != 0;
            }
            if (ok) T.push_back(i);
        }
        //cout << T.size() << endl;
        if (T.size() == X) {
            for(int i=0; i<T.size(); i++) {
                cout << (i>0 ? " " : "") << T[i];            
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }

    }

}
