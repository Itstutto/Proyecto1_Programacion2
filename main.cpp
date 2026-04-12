#include <iostream>
#include "Equipo.h"
#include "Servidores.h"
using namespace std;
int main() {
    try {
        Servidores servidor1("Servidor1", 5, 10, 8, true);
        servidor1.setUso(false);
        cout << servidor1.toString() << endl;
    }catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }


    return 0;
}