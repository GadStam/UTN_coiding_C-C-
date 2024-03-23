#include <iostream>
using namespace std;

void generarVector(int N) {
    int vec[N];
    for(int i = 0; i<N; i++){
        cout << "ingrese el numero del vec en la posicion " << i << endl;
        cin >> vec[i];
    }
    if(vec[N-1]<10){
        for(int i = 0; i<N; i++){
        vec[i] = -vec[i];
        }
        
    }

    for(int i = 0; i<N; i++){
        cout << "el vector es: " << endl;
        cout << vec[i] << endl;
        }

    
    
}

int main() {
    int N;
    cout << "ingrese la cantidad de numeros del vec: ";
    cin >>N;

    while(N > 30){
        cout << "ingrese devuelta la cantidad de numeros del vec: ";
        cin >>N;

    }

    generarVector(N);

    return 0;
}
