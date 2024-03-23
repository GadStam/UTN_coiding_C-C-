#include <iostream>
using namespace std;

void generarVector(int N) {
    int vec[N];
    for(int i = 0; i<N; i++){
        vec[i]=(i+1)*2;
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
