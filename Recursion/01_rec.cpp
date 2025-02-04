#include<bits/stdc++.h>
using namespace std;

void printHelper(int n) {
    // ------------ goal
    /*
    print 10 to 1 using rec
    */
    if(n == 0) {
        return;
    }
    cout << n << ' ';
    printHelper(n-1);
}

void print_Helper(int n) {
    // ------------ goal
    /*
    print 1 to 10 using rec
    */
    if(n > 10) return;
    cout << n << ' ';
    print_Helper(n+1);
}


void helper_function1(int n) {
    // ------------ goal
    /*
    print even no. using rec
    */
    if(n == 0) { // base condition
        return;
    }
    else if(n%2 != 0) {
        n--;
    }
    cout << n << ' ';
    helper_function1(n-2);

}

int factorialHelperfunc(int n) {
    // ------------ goal
    /*
        To find the factorial of any number
        5! = 5x4x3x2x1
    */
    if(n == 0) {  // base condition
        // 0! = 1
        return 1;
    }
    int ans = n;
    ans = ans * factorialHelperfunc(n-1);
    return ans;
}

void helperFunc_PrintOddNum(int n) {
    if(n == -1) return;
    else if(n%2==0) {
        n--;
    }
    helperFunc_PrintOddNum(n-2);
    cout << n << ' ';
}

int fibonaciiHelperFunc(int n) {
    // ------------ goal
    /*
        To find the nth fibanocii number
        1 + 1 + 2 + 3 + 5 + 8 + 13 + 21 + 34 
        i  ii  iii  iv  v  vi  vii  viii  ix
    */
    if(n<=1) {
        return n;
    }

    return fibonaciiHelperFunc(n-1) + fibonaciiHelperFunc(n-2);
}

int GCDHelperFunc(int a, int b) {
    if(b == 0) {
        return a;
    }
    return GCDHelperFunc(b, a%b);
}

void calGCDFunc() {
    cout << "Enter Value's to Calculate GCD:- " << '\n';
    int a, b;
    cin >> a >> b;

    cout << "GCD of " << a << " & " << b << " is:-> " << GCDHelperFunc(a, b) << '\n';
}

int main() {
    int n;
    cin >> n;
    printHelper(n);
    cout << "\n";
    print_Helper(1);
    cout << "\n";
    helper_function1(n);
    cout << '\n';
    cout << n << "! " << "= " << factorialHelperfunc(n) << '\n';

    cout << n << "th fibonacii number is:-> " << fibonaciiHelperFunc(n) << '\n';

    cout << "odd no's :-> "<< ' ';
    helperFunc_PrintOddNum(n);


    cout << '\n';
    // GCD of two number 
    calGCDFunc();
}