#ifndef _EMPRESA_HPP
#define _EMPRESA_HPP

#include <string>
#include "Cnpj.hpp"
#include "Endereco.hpp"

using namespace std;

class Empresa
{

    //Attributes
    private:
    string nome;
    Cnpj cnpj;
    string inscEst;
    Endereco endereco;
    string telefone;

    //Methods
    public:
    Empresa(string nome = "");
    ~Empresa();
    string obtemNome() const;
    bool defineNome(string nome);
    Cnpj obtemCNPJ() const;
    bool defineCNPJ(const Cnpj &cnpj);
    string obtemInscEst() const;
    bool defineInscEst(string inscEst);
    Endereco obtemEndereco() const;
    bool defineEndereco(const Endereco &endereco);
    string obtemTelefone() const;
    bool defineTelefone(string telefone);
    string str() const;
	bool fromCSV(string csv, char separador = ';'); //lê CSV
	string toCSV(char separador = ';'); //converte para CSV
    bool operator==(const Empresa &empresa) const;
    friend istream &operator>>(istream& in,Empresa &empresa);
    friend ostream &operator<<(ostream& out,const Empresa &empresa);
    
};

#endif
