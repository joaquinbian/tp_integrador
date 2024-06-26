#include <iostream>
#include <cstdlib>  // Para srand() y rand()
#include <ctime>
int main() {
    srand(time(0)); // Inicializa la semilla con un valor fijo

    for (int i = 0; i < 5; ++i) {
        std::cout << rand() << std::endl; // Genera números pseudoaleatorios
    }

    return 0;
}