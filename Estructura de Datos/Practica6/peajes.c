#include "peajes.h"

typedef struct {
    int can;
    int cab;
} Pareja;

struct Peaje {
    Cabina cabinas[NCAB];
    Pareja tasas[NCAB];
};

