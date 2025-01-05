#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    cout << "Enter two integers: "<< endl;
    cin >> num1 >> num2;
    if(num1 > num2){
        cout << "Es mayor: "<< num1 << endl;
        cout << "Es menor: "<< num2 << endl;
    } if(num2 > num1) {
        cout << "Es mayor: "<< num2 << endl;
        cout << "Es menor: "<< num1 << endl;
    } else {
        cout << "Los numeros son iguales." << endl;
    }

    return 0;
}