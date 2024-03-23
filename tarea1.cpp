#include <iostream>
using namespace std;




int main (){
int TipodeInfracción;
char MotivodeInfracción [30];
int ValorMulta;
string GravedadInfraccion;

int PrecioMulta_L = 0;
int PrecioMulta_M = 0;
int PrecioMulta_G = 0;

int i;
for (i = 0; i <= 2; i++){
    cout << "ingrese el tipo de infraccion" << endl;
    cin >> TipodeInfracción;
    cout << "ingrese el Motivo de la infraccion" << endl;
    cin >> MotivodeInfracción;
    cout << "ingrese La gravedad de la infraccion (L, M o G)" << endl;
    cin >> GravedadInfraccion;
    cout << "ingrese el Valor de la multa" << endl;
    cin >> ValorMulta;
    

    if (GravedadInfraccion == "L")
    {
       PrecioMulta_L = ValorMulta;
    }else if (GravedadInfraccion == "G")
    {
        PrecioMulta_G = ValorMulta;
    }else{
        PrecioMulta_M = ValorMulta;
    }
    
    




    
}

cout << "el valor por multa L es " << PrecioMulta_L << endl;
cout << "el valor por multa G es " << PrecioMulta_G << endl;
cout << "el valor por multa M es " << PrecioMulta_M << endl;


return 0;

}


