#pragma once

#include <algorithm>

struct step_t {
    step_t(int x0, int y0, int x1, int y1) :
            x0{x0},
            y0{y0},
            x1{x1},
            y1{y1}{}
    int x0, y0, x1, y1;
};

struct pos_t {
    pos_t(int x, int y) :
            x{x},
            y{y}{}
    int x, y;
};

struct field_t {
    field_t() {

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if ((i + j) % 2 != 0 && i < 3 ) {
                    fld[i][j] = 'w';
                } else if ((i + j) % 2 != 0 && i > 4 ) {
                    fld[i][j] = 'b';
                } else if ((i + j) % 2 != 0) {
                    fld[i][j] = '#';
                } else {
                    fld[i][j] = '.';
                }
            }
        }
    }

    char fld[8][8];
};