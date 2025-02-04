#include<iostream>
using namespace std;

bool isEven(int n) {
    if(n==0) {
        return true;
    }

    return !isEven(n-1);
}

int main() {
    int n;
    cin >> n;

    cout << "is " << n << " Even :-> ";
    if(isEven(n)) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }
}