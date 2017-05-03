//
// Created by Fukushima Shion on 2017/04/25.
//

#pragma once

#include <iterator>
#include <iostream>
#include <vector>
#include <cmath>
#include <complex>

using namespace std;

class calc {

    public:
        static vector<complex<double>> fft(vector<double> data, const int N, int mode, bool add);
        static vector<double> power_spectrum(vector<complex<double>> x1, vector<complex<double>> x2);

    private:
        static void reverse(int* id, int n);
        static void twiddle_factor(complex<double>* wnk, int n, int mode);
        static void butterfly(complex<double> *x, complex<double> *wnk, int n);

};
