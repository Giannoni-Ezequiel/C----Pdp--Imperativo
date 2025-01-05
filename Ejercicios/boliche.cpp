#include <iostream>
using namespace std;

int main() {
    cout << "Ingrese su nombre: "<< endl;
    string nom;
    cin >> nom;
    cout << "Se llama: " << nom << endl;

    cout << "Ingrese su edad: "<< endl;
    int edad;
    cin >> edad;
    /*
    // Para un solo caso
    if(edad >= 18){
        cout << "Es mayor de edad." << endl;
    } else {
        cout << "No es mayor de edad." << endl;
    }
    */
   //Entrada al boliche
    while(edad>0){
        if(edad >= 18){
        cout << "Es mayor de edad." << endl;
    } else {
        cout << "No es mayor de edad." << endl;
    }
        cout << "Ingrese su edad: "<< endl; // Este código se repetirá mientras la edad sea mayor a 0
        cin >> edad;
    }
    return 0;
}