//Automata Con switch
/*
Flujo:
    q0: lee un primer dígito, 0 o 1
    q1 o q2: según el primer dígito, exige el valor contrario
    q3: acepta el resto de bits sin restricciones

Eso corresponde a una cadena con la forma:
    01(0|1)*
    10(0|1)*
Es decir, el primer bit puede ser cualquiera, pero el segundo 
debe ser distinto, y después ya puede seguir cualquier combinación.
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Mi primer Grafo! :D\n\n";

    string palabra = ""; 
    char digito = ' ';

    //Primer digito indistinto (Estado q0 sin bucle, es decir, pasa enseguida al siguiente estado)       
    do {   
        cout << "Escribe un digito [0 o 1]: ";
        cin >> digito;
        if(digito == '0' || digito == '1'){
            //integro 
            palabra.append(string(1, digito));
        }
    } while (digito != '0' && digito != '1');
    
    cout << "Palabra actual: " + palabra + "\n";

    //Siguiente digito distinto obligado para avanzar (Estado q1 o q2 con bucle)
    switch(digito){
        case '1':
            do {
                cout << "Escribe el siguiente digito para avanzar [0]: ";
                cin >> digito;
                if(digito == '1' || digito == '0'){
                    palabra.append(string(1, digito));
                }
                cout << "Palabra actual: " + palabra + "\n";
            } while (digito != '0');                             
        break;
        case '0':
            do {
                cout << "Escribe el siguiente digito para avanzar [1]: ";
                cin >> digito;
                //integro
                if(digito == '1' || digito == '0'){
                    palabra.append(string(1, digito));
                }
                cout << "Palabra actual: " + palabra + "\n";
            } while (digito != '1'); 
        break;

        default:
        break;
    }                  

    //Ultimos digitos indistintos (Estado q3 y posible salida)
    do {
        cout << "Ingresa el siguiente digito [0 o 1], \n";
        cout << "O escribe la letra 'e' para terminar: \n";
        cin >> digito;
        //integro        
        if(digito == '1' || digito == '0'){
            palabra.append(string(1, digito));
        }else if(digito == 'e'){
            break;
        }
        cout << "Palabra actual: " + palabra + "\n";

    } while ((digito != '0' && digito != '1') || digito != 'e');

    cout << "Palabra FINAL: " + palabra + "\n";

}