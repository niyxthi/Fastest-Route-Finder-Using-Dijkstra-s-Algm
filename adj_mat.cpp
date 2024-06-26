#include "adj_mat.h"

void adj_mat(int a[40][40]) {
    for (int i = 0; i < 13; i++) { // Blue line from central to airport
        a[i][i + 1] = 2;
        a[i + 1][i] = 2;
    }
    a[0][14] = 3; // Red line from central to egmore
    a[14][0] = 3;
    for (int i = 14; i < 26; i++) { // Red line from egmore to tambaram
        a[i][i + 1] = 3;
        a[i + 1][i] = 3;
    }
    a[19][20] = 0; // removing saidapet and st.thomas mount egde
    a[20][19] = 0;
    a[19][9] = 3; // saidapet to guindy
    a[9][19] = 3;
    a[9][20] = 3; // guindy to st.thomas mount
    a[20][9] = 3;
    a[22][23] = 0; // remove meenambakam to pallavaram
    a[23][22] = 0;
    a[22][13] = 2; // meenambakam to airport (tirusulam)
    a[13][22] = 2;
    a[13][23] = 3; // airport to pallavaram
    a[23][13] = 3;
    a[14][27] = 2; // green line egmore to nehru park metro
    a[27][14] = 2;
    for (int i = 27; i < 38; i++) { // green line nehru park to ekatuthangal
        a[i][i + 1] = 2;
        a[i + 1][i] = 2;
    }
    a[33][34] = 3; // Thirumangalam to Koyambedu
    a[34][33] = 3;
    a[38][39] = 3; // Ashoknagar to ekkatuthangal - 3 mins
    a[39][38] = 3;
    a[39][10] = 2; // ekatuthangal to alandur
    a[10][39] = 2;
    a[10][20] = 2; // alandur to St.Thomas mount
    a[20][10] = 2;
}
