/*
** EPITECH PROJECT, 2022
** fil.hpp
** fil description:
** fil.hpp
*/

#ifndef FILE_HPP_
    #define FILE_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

#include <iomanip>
#include <list>
#include <iterator>

class file {
    public:
        file ();
        ~file ();
        void usage();
        int TempIncrease(unsigned int period);
        int TempRelative(unsigned int period);
        int StandardDeriv(unsigned int period);
        void output(unsigned int period);
        int program(int period);
        void display(unsigned int period);
        bool faith(unsigned int period);
    protected:
    private:
    std::vector<double> last;
    double g, t, f, d, s;
    int ok, r;
    int j;
    char input[1000];
    std::list<double> list;
};

#endif /* !fil_HPP_ */