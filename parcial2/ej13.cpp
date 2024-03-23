#include <iostream>
#include <fstream>
using namespace std;

// Estructuras
struct atenciones {
    int idAtencion;
    int fecha;
    int idMedico;
    int idPaciente;
    char diagnostico[20 + 1];
    int idMedicamento;
};

struct medicamentos {
    int idMedicamento;
    char descripcion[20 + 1];
    char presentacion[20 + 1];
};

void cargadatosM(FILE* A, medicamentos vm[]) {
    fseek(A, 0, SEEK_SET);

    for (int j = 0; j < 3; j++) {
        cout << "Ingrese info del medicamento numero " << j + 1 << endl;
        vm[j].idMedicamento = j + 1;
        cout << "Idmedicamento: " << vm[j].idMedicamento << endl;
        cout << "Descripcion: ";
        cin >> vm[j].descripcion;
        cout << "Presentacion: ";
        cin >> vm[j].presentacion;

        cout << "\n";
    }

    int i = 0;
    while (i < 3) {
        fwrite(&vm[i], sizeof(medicamentos), 1, A);
        i++;
    }
}

void mostrararchivo(FILE* A) {
    medicamentos reg;
    medicamentos vecMedi[3];
    fseek(A, 0, SEEK_SET);
    int j = 0;
    while (fread(&reg, sizeof(medicamentos), 1, A)) {
        vecMedi[j] = reg;
        j++;
    }

    for (int i = 0; i < 3;i++){
        cout<<"ID MEDICAMENTO: "<<vecMedi[i].idMedicamento<<endl;
        cout<<"DESCRIPCION: "<<vecMedi[i].descripcion<<endl;
        
    }
}

int main() {
    // Necesario para la funcion carga datos MEDICAMENTO
    medicamentos vm[3];
    atenciones va[3];

    FILE* A = fopen("arch.dat", "wb+");

    if (A == nullptr) {
        cerr << "Error opening file!" << endl;
        return 1; // Exit with an error code
    }

    cargadatosM(A, vm);
    mostrararchivo(A);
    fclose(A);

    return 0;
}
