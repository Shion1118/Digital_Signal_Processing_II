//
// 平成29年度 DSP2-1 5J25 福島シオン
// Created by Fukushima Shion on 2017/04/25.
//

#include "calc.h"

vector<complex<double>> calc::fft(vector<double> data, const int N, int mode, bool add) {

    int SIZE;

    if (add) {
        SIZE = pow(2, (int)ceil(log10(N*2) / log10(2)));
        int zero = SIZE - N;
        for (int i = 0; i < zero; i++) {
            data.emplace_back(0);
        }
    } else {
        SIZE = N;
    }

    int id[SIZE];
    for(int i = 0; i < SIZE; i++) id[i] = i;
    reverse(id, SIZE);

    complex<double> wnk[SIZE];
    twiddle_factor(wnk, SIZE, mode);

    complex<double> x[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        x[i].real(data.at(id[i]));
        x[i].imag(0.);
    }

    butterfly(x, wnk, SIZE);

    vector<complex<double>> result;
    for (complex<double> tmp: x) {
        if(mode == -1) tmp /= SIZE;
        result.emplace_back(tmp);
    }

    return result;
}

void calc::reverse(int* id, int n) {

    int r = (int)ceil(log10(n) / log10(2));

    for(int i = 0; i < n; i++) {
        id[i] = 0;
        for (int j = 0; j < r; j++) {
            id[i] += ((i >> j) & 1) << (r - j - 1);
        }
    }
}

void calc::twiddle_factor(complex<double> *wnk, int n, int mode) {

    for (int i = 0; i < n; ++i) {
        wnk[i].real(cos(mode * 2 * M_PI / n * i));
        wnk[i].imag(sin(mode * -2 * M_PI / n * i));
    }
    
}

void calc::butterfly(complex<double> *x, complex<double> *wnk, int n) {

    int r_big = 1, r_sma = n / 2, r = (int)ceil(log10(n) / log10(2));
    int up, low;
    complex<double> tmp;

    for (int i = 0; i < r; ++i){
        for (int j = 0; j < r_big; ++j) {
            for ( int k = 0; k < r_sma; ++k) {
                up = r_big * 2 * k + j;
                low = up + r_big;

                tmp = x[low] * wnk[j * r_sma];
                x[low] = x[up] - tmp;
                x[up] = x[up] + tmp;
            }
        }
        r_big *= 2;
        r_sma /= 2;
    }
}

vector<double> calc::power_spectrum(vector<complex<double>> x1, vector<complex<double>> x2) {

    vector<double> result;

    for (int i = 0; i < x1.size(); ++i) {
        result.emplace_back((conj(x1.at(i)) * x2.at(i)).real());
    }

    return result;
}
