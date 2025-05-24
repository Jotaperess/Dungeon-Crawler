#include "fase.h"



// verificador de fase
int verificarfase(int fase) {
    switch (fase) {
        case 1:
        return 10;
        break;

        case 2:
            return 10;
            break;

        case 3:
            return 20;
            break;

        case 4:
            return 40;
            break;

        default:
            return -1;
            break;
    }
}