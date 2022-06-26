#include <iostream>
#include "Cnpj.hpp"

using namespace std;

bool executaCnpj()
{

    Cnpj Test;
    Cnpj Test2;
    string cnpj = "44.786.289/0001-91";
    string cnpj2 = "45135880000141";

    cout << "Testando: ehValido() --> " << Test.ehValido(cnpj) << endl;
    cout << "Testando: define() --> " << Test.define(cnpj) << endl;

    cout << endl;

    cout << "Obtendo: obtemRaiz() --> " << Test.obtemRaiz() << endl;
    cout << "Obtendo: obtemFilial() --> " << Test.obtemFilial() << endl;
    cout << "Obtendo: obtemDV() --> " << Test.obtemDV() << endl;
    cout << "Obtendo: str() --> " << Test.str() << endl;

    cout << endl;

    cout << "Testando: operator==(const Cnpj &cnpj)() --> " << (Test == Test ? "1" : "0") << endl;
    
    stringstream ss(cnpj2);
    ss >> Test2;
    cout << "Testando: operator>>(istream& in,Cnpj& cnpj) --> " << Test2.str() << endl;

    stringstream ss2;
	ss2 << Test2;
    cout << "Testando: operator<<(ostream& out,const Cnpj& cnpj) --> " << ss2.str() << endl;

return true;
}

bool start()
{
    cout << "Started..." << endl;
    cout << "Starting executaCnpj()..." << endl << endl;
    executaCnpj();
    cout << "executaCnpj() terminated." << endl << endl;
    
    return true;
}

int main() 
{ 

	start();
	
return 0; 
}