#include "Cnpj.hpp"
#include "Endereco.hpp"
#include "Empresa.hpp"

#include <string>

using namespace std;

Empresa::Empresa(string nome)
{

  this->nome = nome;
      
}
    
Empresa::~Empresa()
{
          
}

string Empresa::obtemNome() const
{

return nome;
}

bool Empresa::defineNome(string nome){
    
    this->nome = nome;

}

Cnpj Empresa::obtemCNPJ() const
{

return cnpj;
}

bool Empresa::defineCNPJ(const Cnpj &cnpj)
{

    if(cnpj.str() != "")
    {

          this->cnpj = cnpj;
    
    return true;
    }

return false;
}

string Empresa::obtemInscEst() const
{

return inscEst;
}

bool Empresa::defineInscEst(string inscEst)
{
    if(inscEst != "")
    {

        this->inscEst = inscEst;

    return true;   
    }

return false;
}

Endereco Empresa::obtemEndereco() const
{

return endereco;
}

bool Empresa::defineEndereco(const Endereco &endereco)
{

    if(endereco.str() != "")
    {

        this->endereco = endereco;

    return true;
    }

return false;
}


string Empresa::obtemTelefone() const
{

return telefone;
}

bool Empresa::defineTelefone(string telefone)
{
    if(telefone != "")
    {

        this->telefone = telefone;

    return true;
    }

return false;
}

string Empresa::str() const
{

    stringstream ss;
    
    ss << nome << "; ";
    ss << cnpj.str() << "; ";
    ss << inscEst << "; ";
    ss << endereco.str() << "; ";
    ss << telefone;
  
return ss.str();
}

bool Empresa::fromCSV(string csv, char separador)
{

    if(csv != "")
    {

        string cnpj;
        string endereco;
        string telefone;

        string aux;
        stringstream buffer(csv);
        stringstream stream;

        getline(buffer, this->nome, separador);
        getline(buffer, cnpj, separador);
        getline(buffer, this->inscEst, separador);
        getline(buffer, endereco, separador);
        getline(buffer, this->telefone, separador);   
  
        this->cnpj.define(cnpj);
        this->endereco.fromCSV(endereco, ':');

    return true;
    }

return false;
}

string Empresa::toCSV(char separador)
{

}

bool Empresa::operator==(const Empresa &empresa) const
{

return (this->str() == empresa.str());
}

istream &operator>>(istream& in,Empresa &empresa)
{

    string cnpj, logradouro, numero, complemento, bairro, cidade, uf, cep;

    getline(in, empresa.nome);
    getline(in, cnpj);
    empresa.cnpj.define(cnpj);   
    getline(in, empresa.inscEst);
    getline(in, logradouro);
    empresa.endereco.defineLogradouro(logradouro);
    getline(in, numero);
    empresa.endereco.defineNumero(numero);
    getline(in, complemento);
    empresa.endereco.defineComplemento(complemento);   
    getline(in, bairro);
    empresa.endereco.defineBairro(bairro);
    getline(in, cidade);
    empresa.endereco.defineCidade(cidade);
    getline(in, uf);
    empresa.endereco.defineUF(uf);
    getline(in, cep);
    empresa.endereco.defineCEP(cep);
    getline(in, empresa.telefone);

return in;
}

ostream &operator<<(ostream& out,const Empresa &empresa)
{

  out << empresa.nome << endl;
  out << empresa.cnpj.str() << endl;
  out << empresa.inscEst << endl;
  out << empresa.endereco.obtemLogradouro() << endl;
  out << empresa.endereco.obtemNumero() << endl;
  out << empresa.endereco.obtemComplemento() << endl;
  out << empresa.endereco.obtemBairro() << endl;
  out << empresa.endereco.obtemCidade() << endl;
  out << empresa.endereco.obtemUF() << endl;
  out << empresa.endereco.obtemCEP() << endl;
  out << empresa.telefone;
    
return out;
}