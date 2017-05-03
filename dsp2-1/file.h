//
// Created by Fukushima Shion on 2017/04/25.
//

#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class file {

    public:
        static void loadFile(string name, vector<double> &vec);
        static void writeFile(string name, const vector<double> &vec);

};