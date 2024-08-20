#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    cout << "Enter two integers: ";
    cin >> num1 >> num2;
    // Producto de sumas sucesivas
    int contador, sumador;
    contador = 0;
    sumador = 0;
    while (contador < num1) {
        sumador += num2; //sumador = sumador + num2
        contador++; // contador = contador + 1
    }
    cout << num1 << " x " << num2 << " = " << sumador << endl;
}