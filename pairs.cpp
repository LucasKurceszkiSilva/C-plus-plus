#include <bits/stdc++.h>
using namespace std;

int main(){
    int sw; cin >> sw;
    switch(sw){
        case 1:
            pair<int, string> p1={1, "Hello world"};
            cout << p1.first << " " << p1.second << endl;
        case 2:
            int a; cin >> a;
            string b; cin >> b;
            pair<int, string> p2={a, b};
            cout << p2.first << " " << p2.second;
        case 3:
            pair<double, int> p3=make_pair(23.2, 4);
            cout << p3.first << " " << p3.second;
        case 4:
            pair<int, string> p4={1, ""};
            string x; cin >> x;
            p4.second=x;
            cout << p4.first << " " << p4.second;
        case 5:
            pair<int, int> p5={2, 2}, p6={2, 3}, p7={3, 3};
            cout << (p5==p6) << endl << (p6==p7) << endl;
        case 6:
            int inta, intb;
            pair<int, int> p8={2, 4};
            tie(inta, intb)=p8;
            cout << p8.first << " " << p8.second;
        default :
            cout << "invalid input";
    }
    return 0;
}