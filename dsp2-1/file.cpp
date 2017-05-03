//
// 平成29年度 DSP2-1 5J25 福島シオン
// Created by Fukushima Shion on 2017/04/25.
//

#include "file.h"

void file::loadFile(string name, vector<double> &vec) {

    ifstream in("data/" + name);

    if(!in) {
        cout << "File Not Found!!"<< endl;
        return;
    } else {
        string tmp;
        while(getline(in, tmp)) {
            vec.emplace_back(stod(tmp));
        }
    }
}

void file::writeFile(string name, const vector<double> &vec) {

    ofstream out("data/" + name);

    if (!out) {
        cout << "Cannot Write File!!"<< endl;
        return;
    } else {
        for (double tmp: vec) {
            out << tmp << endl;
        }
    }

}
