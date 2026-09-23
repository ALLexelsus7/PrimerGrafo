//Automata con while e if
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Mi primer Grafo! :D\n\n";

    string palabra = ""; 
    char ini = '0';
    char salir = 'a';

    //primer digito correcto
    do {
        cout << "Ingresa el primer digito [0 o 1]: \n";
        cin >> ini;     
    } while (ini != '0' && ini != '1');
    //integro   
    palabra.append(string(1, ini));
    cout << "Palabra: " + palabra + "\n";

    //segundo o siguiente digito correcto
    if (ini == '0') {
        do {
            cout << "Ingresa el segundo digito [1]: \n";
            cin >> ini;
            //integro   
            palabra.append(string(1, ini));
            cout << "Palabra: " + palabra + "\n";
        } while (ini != '1');     
    }   

    //segundo o siguiente digito correcto
    if (ini == '1') {
        do {
            cout << "Ingresa el segundo digito [0]: ";
            cin >> ini;
            //integro   
            palabra.append(string(1, ini));
            cout << "Palabra: " + palabra + "\n";
        } while (ini != '0');
    }    

    //tercer digito correcto
    do {
        cout << "Ingresa el siguiente digito [0 o 1]: \n";
        cin >> ini;
        //integro   
        palabra.append(string(1, ini));
        cout << "Palabra: " + palabra + "\n";
        cout << "Salir ingresando la letra 'e'...\n";
        cin >> salir;
    } while ((ini != '0' && ini != '1') || salir != 'e');
    

    cout << "Palabra FINAL: " + palabra + "\n";

    //pasos
    //1. separar caracteres
    //2. comparar cada caracter
    //3. inicar la condicion

    //intentarlo ahora con switch
    //luego con nodos (lista enlazada)
}