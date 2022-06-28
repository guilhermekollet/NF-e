#include <iostream>
#include "dependencies/Program.hpp"

using namespace std;

bool runProgram(string urlEmpresa, string urlProdutos)
{

    Program pInit;
    pInit.menu_Carregamento(urlEmpresa, urlProdutos);
    pInit.menu_Interface();

return true;
}

bool start()
{

    runProgram("data/empresa.csv", "data/produtos.csv");

return true;
}

int main() 
{ 

	start();
	
return 0; 
}