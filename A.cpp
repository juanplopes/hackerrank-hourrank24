#include <iostream>
#include <string>
using namespace std;

int main() {
    string sp = "!@#$%^&*()-+";
    string s; int test;
    while(cin >> test >> s) {
        int d = 0, l = 0, u = 0, spe = 0;
        for(int i=0; i<s.size(); i++) {
            char c = s[i];
            d += (c >= '0' and c <= '9' ? 1 : 0);
            l += (c >= 'a' and c <= 'z' ? 1 : 0);
            u += (c >= 'A' and c <= 'Z' ? 1 : 0);
            spe += (sp.find(c) < sp.size() ? 1 : 0);
        }   
        //cout << " " << s << endl;
        //cout << " " << d << " " << l << " " << u << " " << spe << endl;
        cout << max(6-(int)s.size(), 4-(min(d, 1)+min(l, 1)+min(u,1)+min(spe, 1))) << endl;
    }

}
