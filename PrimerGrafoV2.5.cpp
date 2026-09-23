/*Segun copilot
q0: acepta el primer bit
q1 o q2: exige el bit contrario para avanzar (sin bucle)
q3: si ya llegó ahí, acepta 0 o 1 indefinidamente
Eso coincide con la idea del autómata: 
los primeros dos bits deben ser distintos, 
y después la cadena puede continuar libremente.
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    
    cout << "Automata: dos primeros digitos distintos, luego acepta cualquier secuencia\n\n";

    string palabra = "";
    char digito;
    int estado = 0; // q0 = 0, q1/q2 = 1, q3 = 2

    while (true) {
        cout << "Ingresa un digito [0 o 1] o 'e' para terminar: ";
        cin >> digito;

        if (digito == 'e' || digito == 'E') {
            break;
        }

        if (digito != '0' && digito != '1') {
            cout << "Entrada invalida, solo se aceptan 0 o 1.\n";
            continue;
        }

        palabra += digito;

        switch (estado) {
            case 0: // q0
                if (digito == '0') {
                    estado = 1; // q1
                } else { // digito == '1'
                    estado = 2; // q2
                }
                break;

            case 1: // q1: debe venir un 1 para avanzar a q3
                if (digito == '1') {
                    estado = 3; // q3
                } else {
                    cout << "La cadena NO pertenece al lenguaje: q1 solo acepta '1' para avanzar.\n";
                    return 0;
                }
                break;

            case 2: // q2: debe venir un 0 para avanzar a q3
                if (digito == '0') {
                    estado = 3; // q3
                } else {
                    cout << "La cadena NO pertenece al lenguaje: q2 solo acepta '0' para avanzar.\n";
                    return 0;
                }
                break;

            case 3: // q3: acepta cualquier bit 0 o 1
                // Se queda en q3
                break;
        }

        cout << "Palabra actual: " << palabra << "\n";

        if (estado == 3) {
            cout << "Estado actual: q3 (aceptado)\n";
        } else if (estado == 1) {
            cout << "Estado actual: q1\n";
        } else if (estado == 2) {
            cout << "Estado actual: q2\n";
        }
    }

    if (estado == 3) {
        cout << "\nLa palabra final ingresada es valida: " << palabra << "\n";
    } else {
        cout << "\nLa palabra final ingresada NO es valida porque no se completaron los dos primeros digitos distintos.\n";
    }

    return 0;
}
