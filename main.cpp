#include <iostream>
#include "Cnpj.hpp"
#include "Endereco.hpp"

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

    cout << "Testando: operator==(const Cnpj &cnpj) --> " << (Test == Test ? "1" : "0") << endl;
    
    stringstream ss(cnpj2);
    ss >> Test2;
    cout << "Testando: operator>>(istream& in,Cnpj& cnpj) --> " << Test2.str() << endl;

    stringstream ss2;
	ss2 << Test2;
    cout << "Testando: operator<<(ostream& out,const Cnpj& cnpj) --> " << ss2.str() << endl;

return true;
}
bool executaEndereco()
{
    Endereco Test;

    cout << "Testando: defineLogradouro() --> " << Test.defineLogradouro("Rua da Esperanca") << endl;
    cout << "Testando: obtemLogradouro() --> " << Test.obtemLogradouro() << endl;
    cout << "Testando: defineNumero() --> " << Test.defineNumero("1234") << endl;
    cout << "Testando: obtemNumero() --> " << Test.obtemNumero() << endl;
    cout << "Testando: defineComplemento() --> " << Test.defineComplemento("Casa") << endl;
    cout << "Testando: obtemComplemento() --> " << Test.obtemComplemento() << endl;
    cout << "Testando: defineBairro() --> " << Test.defineBairro("Noiva do Mar") << endl;
    cout << "Testando: obtemBairro() --> " << Test.obtemBairro() << endl;
    cout << "Testando: defineCidade() --> " << Test.defineCidade("Xangri-La") << endl;
    cout << "Testando: obtemCidade() --> " << Test.obtemCidade() << endl;
    cout << "Testando: defineUF() --> " << Test.defineUF("RS") << endl;
    cout << "Testando: obtemUF() --> " << Test.obtemUF() << endl;
    cout << "Testando: defineCEP() --> " << Test.defineCEP("95888-000") << endl;
    cout << "Testando: obtemCEP() --> " << Test.obtemCEP() << endl;

    cout << endl;

    cout << "Testando: str() --> " << Test.str() << endl;

    cout << endl;

    cout << "Testando: bool operator==(const Endereco &e) --> " << (Test == Test ? "1" : "0") << endl;
    
    stringstream ss("Rua da Esperanca\n4321\nCasa\nNoiva do Mar\nXangri-La");
    ss >> Test;
    cout << "Testando: istream &operator>>(istream& in,Endereco &e) --> " << Test.str() << endl;

    stringstream ss2;
	ss2 << Test;
    cout << "Testando: ostream &operator<<(ostream& out,const Endereco &e) --> " << ss2.str() << endl;

return true;
}

bool start()
{
    cout << "Started..." << endl;
    
    cout << "Starting executaCnpj()..." << endl;
    executaCnpj();
    cout << "executaCnpj() terminated." << endl << endl;

    cout << "Starting executaEndereco()..." << endl;
    executaEndereco();
    cout << "executaEndereco() terminated." << endl << endl;
    

    return true;
}

int main() 
{ 

	start();
	
return 0; 
}