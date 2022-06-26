#include <iostream>
#include "dependencies/Cnpj.hpp"
#include "dependencies/Endereco.hpp"
#include "dependencies/Empresa.hpp"

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

bool executaEmpresa()
{

    Empresa Test;
    Cnpj CnpjTest("44.786.289/0001-91");
    Endereco EnderecoTest();
    Endereco EnderecoTest2("Rua da Esperanca","608","Casa","Noiva do Mar","Xangri-La","RS","95888-000");

    cout << "Testando: defineNome(""OBIN FARM & TECHNOLOGIES"") --> " << Test.defineNome("OBIN FARM & TECHNOLOGIES") << endl;
    cout << "Testando: obtemNome() --> " << Test.obtemNome() << endl;
    cout << "Testando: defineCNPJ(CnpjTest) --> " << Test.defineCNPJ(CnpjTest) << endl;
    cout << "Testando: obtemCNPJ() --> " << Test.obtemCNPJ() << endl;
    cout << "Testando: defineInscEst(""388.108.598.269"") --> " << Test.defineInscEst("388.108.598.269") << endl;
    cout << "Testando: obtemInscEst() --> " << Test.obtemInscEst() << endl;
    cout << "Testando: defineEndereco(EnderecoTest2) --> " << Test.defineEndereco(EnderecoTest2) << endl;
    cout << "Testando: obtemEndereco() --> " << Test.obtemEndereco() << endl;
    cout << "Testando: defineTelefone() --> " << Test.defineTelefone("51 995774400") << endl;
    cout << "Testando: obtemTelefone() --> " << Test.obtemTelefone() << endl;

    cout << endl;

    cout << "Testando: str() --> " << Test.str() << endl;

    cout << endl;

    cout << "Testando: bool operator==(Test) --> " << (Test == Test ? "1" : "0") << endl;
    
    stringstream ss("Nome\n44.786.289/0001-91\n321.321.321\nLogradouro\nNumero\nComplemento\nBairro\nCidade\nUF\nCEP\n51 985172499");
    ss >> Test;
    cout << "Testando: istream &operator>>(istream& in,Empresa &e) --> " << Test.str() << endl;

    stringstream ss2;
	ss2 << Test;
    cout << "Testando: ostream &operator<<(ostream& out,const Empresa &e) --> " << ss2.str() << endl;

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

    cout << "Starting executaEmpresa()..." << endl;
    executaEmpresa();
    cout << "executaEmpresa() terminated." << endl << endl;

return true;
}

int main() 
{ 

	start();
	
return 0; 
}