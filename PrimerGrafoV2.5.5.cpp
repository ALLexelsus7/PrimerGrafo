//pasos
    //1. separar caracteres
    //2. comparar cada caracter
    //3. inicar la condicion

#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Grafo con la palabra definida" << endl;

    string palabra = "0000011111";
    int estado = 0;
    int operacion = 0;
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
                operacion = 1;
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
                operacion = 2;
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
                operacion = 2;
            break;

            case 3: //estado q3
                // el valor anterior fue 0 o 1, ahora puede ser 0 o 1 o terminar la palabra
                operacion++;
                palabraCorrecta = true;
            break;
        }
    } 

    if(palabraCorrecta){
        cout << "Palabra Correcta!: " + palabra;
    }
   
}