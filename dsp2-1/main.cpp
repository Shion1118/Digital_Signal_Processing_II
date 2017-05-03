//
// 平成29年度 DSP2-1 5J25 福島シオン
// Created by Fukushima Shion on 2017/04/25.
//

#include "main.h"

int main() {

    cout << "DSP2-1 5J25 福島シオン" << endl;

    string in;
    cout << "Type Data File Name(1)" << endl;
    cin >> in;
    vector<double> data1;
    file::loadFile(in, data1);

    cout << "Type Data File Name(2)" << endl;
    cin >> in;
    vector<double> data2;
    file::loadFile(in, data2);

    int N =  data1.size();
    vector<complex<double>> data1_fft = calc::fft(data1, N, 1, true);
    vector<complex<double>> data2_fft = calc::fft(data2, N, 1, true);
    vector<double> ps = calc::power_spectrum(data1_fft, data2_fft);

    vector<complex<double>> data_ifft = calc::fft(ps, ps.size(), -1, false);
    vector<double> result;

    for (int i = 0; i < N; i++) {
        result.emplace_back(data_ifft.at(i).real() / N);
    }

    string out;
    cout << "Type Output File Name" << endl;
    cin >> out;
    file::writeFile(out, result);

    return 0;
}
