//ACT 1
//Alex Ruiz Jordan 24110097
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Grafo con la palabra predefinida" << endl;

    string palabra = "11010";
    int estado = 0;
    bool palabraCorrecta = false;
    
    for(size_t i = 0; i < palabra.length(); i++){ //Itera segun el tamanio de la palabra (size_t o auto para que detecte solo)
        switch(estado){
            case 0: //estado q0
                if(palabra[0] == '0'){
                    //si es 0 pasa al estado q1
                    estado = 1;
                }else{
                    //si no, es 1 y pasa a q2
                    estado = 2;
                }
            break;

            case 1: //estado q1
                //el valor anterior fue 0, ahora debe ser 1
                if(palabra[1] == '1'){
                    //pasa al estado q3
                    estado = 3;
                }else{
                    //si no, se queda en este estado q1
                    estado = 1;
                    cout << "Palabra Incorrecta!: " + palabra;
                    return 0;
                }
            break;
            case 2: //estado q2
                //el valor anterior fue 1, ahora debe ser 0
                if(palabra[1] == '0'){
                    //pasa al estado q3
                    estado = 3;
                }else{
                    //si no, se queda en este estado q2
                    estado = 2;
                    cout << "Palabra Incorrecta!: " + palabra;
                    return 0;
                }
            break;

            case 3: //estado q3
                // el valor anterior fue 0 o 1, ahora puede ser 0 o 1 o terminar la palabra
                palabraCorrecta = true;
            break;
        }
    } 

    if(palabraCorrecta){
        cout << "Palabra Correcta!: " + palabra;
    }
   
}