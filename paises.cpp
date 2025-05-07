#include <iostream>

using namespace std;
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a=1){
        cout << "Brasil" << endl;
    }else{
        cout << "Equador" << endl;
        if(b==1){
            cout << "Colombia" << endl;
        }else{
            cout << "Peru" << endl;
            if(c==1){
                cout << "Chile" << endl;
            }else{
                cout << "Venezuela" << endl;
            }
        }
    }
    cout << "Bolivia" << endl;
    return 0;
}