#include "Program.hpp"

Program::Program()
{

}

Program::~Program()
{

}

bool Program::loadFile_Empresa(string urlEmpresa)
{

    if(urlEmpresa != "")
    {

        ifstream read(urlEmpresa);
        string auxStream;
        stringstream stream;

        do
        {
            read >> auxStream;
            stream << auxStream;
            stream << " ";

        } while (read.good());

        empresa.fromCSV(stream.str());

        read.close();

    return true;
    }

return false;
}

string Program::obtemEmpresa()
{

return empresa.str();
}