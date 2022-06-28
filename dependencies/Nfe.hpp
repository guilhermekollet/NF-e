#ifndef _NFE_HPP
#define _NFE_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <ctime> 

using namespace std;

class Nfe
{

    //Attributes
    private:
    int numero;
    int serie;
    string database;
    string lastTimeEmitted;

    //Methods
    public:
    Nfe();
    ~Nfe();
    bool setDatabase(string url);
    int obtemNumero() const;
    int obtemSerie() const;
    bool incrementa();
    bool fromCSV(string csv, char separador = ';');
	string toCSV(char separador = ';');
    string str();
    string EmiteNFC_str();
    string obtemLastTimeEmitted();

};

#endif
