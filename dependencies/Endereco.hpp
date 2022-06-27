#ifndef _ENDERECO_HPP
#define _ENDERECO_HPP

#include <string>
#include <sstream>

using namespace std;

class Endereco
{

    //Attributes
    private:
    string logradouro;
    string numero;
    string complemento;
    string bairro;
    string cidade;
    string uf;
    string cep;
    
    //Methods
    public:
    Endereco();
    Endereco(string logradouro, string numero, string complemento, string bairro, string cidade, string uf, string cep);
    ~Endereco();
    string obtemLogradouro() const;
    bool defineLogradouro(string logradouro);
    string obtemNumero() const;
    bool defineNumero(string numero);
    string obtemComplemento() const;
    bool defineComplemento(string complemento);
    string obtemBairro() const;
    bool defineBairro(string bairro);
    string obtemCidade() const;
    bool defineCidade(string cidade);
    string obtemUF() const;
    bool defineUF(string UF);
    string obtemCEP() const;
    bool defineCEP(string CEP);
    string str() const;
	bool fromCSV(string csv, char separador = ';'); //lê CSV
	string toCSV(char separador = ';'); //converte para CSV
    bool operator==(const Endereco &endereco) const;
    friend istream &operator>>(istream& in,Endereco &endereco);
    friend ostream &operator<<(ostream& out,const Endereco &endereco);
};

#endif
