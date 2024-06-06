/*
** EPITECH PROJECT, 2022
** file.cpp
** file description:
** file.cpp
*/

#include "FILE.hpp"

file::file()
{
    this->j = 0;
}

file::~file()
{
}

void file::usage()
{
    std::cout << ("SYNOPSIS") << std::endl;
    std::cout << ("\t./groundhog period") << std::endl;
    std::cout << "" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "|tperiod\tthe number of days defining" << std::endl;
}

int file::TempIncrease(unsigned int period)
{
    if (last.size() <= period)
       return (84);
    this->g = 0;
    size_t index = last.size() - period;
    for (size_t i = index; i != last.size(); i++)
    {
        double p = last[i] - last[i - 1];
        g += (p > 0 ? p : 0);
    }
    g /= period;
    return (g);
}

int file::StandardDeriv(unsigned int period)
{
    double f1 = 0;
    double f2 = 0;

    for (auto i = last.end() - period; i != last.end(); i++)
    {
        f1 += *i;
        f2 += pow(*i, 2);
    }
    s = sqrt(f2 / period - (f1 / period) * (f1 / period));
    return (s);
}

int file::TempRelative(unsigned int period)
{
    if (last.size() <= period)
      return (84);
    this->ok = this->r;
    double v1 = this->last[this->last.size() - period - 1];
    double v2 = this->last.back();
    this->r = (int)(round((v2 - v1) /v1 * 100));
    return (r);
}

void file::display(unsigned int period)
{
    this->TempIncrease(period);
    this->TempRelative(period);
    this->StandardDeriv(period);
}

void file::output(unsigned int period)
{
    std::cout << std::setprecision(2) << std::fixed << "g=";
    if (last.size() <= period)
        std::cout << "nan";
    else
        std::cout << this->g;
    std::cout << "\t\tr=";
    if (last.size() <= period)
        std::cout << "nan";
    else
        std::cout << this->r;
    std::cout << "%\t\ts=";
    if (last.size() < period)
        std::cout << "nan";
    else
        std::cout << this->s;
    if (((this->ok < 0 && this->r >= 0) || (this->ok >= 0 && this->r < 0)) && this->ok)
    {
        ++this->j;
        std::cout << "\t\ta switch occurs";
    }
    std::cout << std::endl;
}

int file::program(int period)
{
    while (1)
    {
        std::scanf("%s", input);
        if (std::strcmp("STOP", input) == 0)
            break;
        if (std::atof(input) != 0)
        {
            last.push_back(std::atof(input));
            display(period);
            output(period);
        }
    }
    std::cout << "Global tendency switched " << this->j << " times" << std::endl;
    return (0);
}

int main(int ac, char **av)
{
    file ok;
    if (ac != 2 || std::atoi(av[1]) < 1 || (av[1] >= "a" && av[1] <= "z"))
        return (84);
    if (std::strcmp("-h", av[1]) == 0)
        ok.usage();
    return (ok.program(std::atoi(av[1])));
}