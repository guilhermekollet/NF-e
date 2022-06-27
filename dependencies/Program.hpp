#include <iostream>
#include <fstream>
#include "Empresa.hpp"

using namespace std;

class Program
{

    //Attributes
    private:
    Empresa empresa;

    //Methods
    public:
    Program();
    ~Program();
    bool loadFile_Empresa(string urlEmpresa);
    string obtemEmpresa();

};