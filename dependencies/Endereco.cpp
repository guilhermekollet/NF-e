#include "Endereco.hpp"

Endereco::Endereco()
{

  logradouro = "";
  numero = "";
  complemento = "";
  bairro = "";
  cidade = "";
  uf = "";
  cep = "";

}

Endereco::Endereco(string logradouro, string numero, string complemento, string bairro, string cidade, string uf, string cep)
{

    this->logradouro = logradouro;
    this->numero = numero;
    this->complemento = complemento;
    this->bairro = bairro;
    this->cidade = cidade;
    this->uf = uf;
    this->cep = cep;

}

Endereco::~Endereco()
{
    
}

string Endereco::obtemLogradouro() const
{

return logradouro;
}

bool Endereco::defineLogradouro(string logradouro)
{

  this->logradouro = logradouro;

return true;
}

string Endereco::obtemNumero() const
{

return numero;
}

bool Endereco::defineNumero(string numero)
{

    this->numero = numero;

return true;
}

string Endereco::obtemComplemento() const
{

return complemento;
}

bool Endereco::defineComplemento(string complemento)
{

    this->complemento = complemento;

return true;
}

string Endereco::obtemBairro() const
{

return bairro;
}

bool Endereco::defineBairro(string bairro)
{

    this->bairro = bairro;

return true;
}

string Endereco::obtemCidade() const
{

return cidade;
}

bool Endereco::defineCidade(string cidade)
{

    this->cidade = cidade;

return true;
}

string Endereco::obtemUF() const
{

return uf;
}

bool Endereco::defineUF(string uf)
{

    this->uf = uf;

return true;
}

string Endereco::obtemCEP() const
{

return cep;
}

bool Endereco::defineCEP(string CEP)
{

    this->cep = cep;

return true;
}

string Endereco::str() const
{

    stringstream ss;
    
    ss << logradouro;
    
    if(numero != "") ss << ", " << numero;
      
    if(complemento != "") ss << " / " << complemento;
      
    if(bairro != "") ss << " - Bairro " << bairro;

    ss << " - " << cidade << "/" << uf << " - CEP ";
    
    if(cep != "") ss << cep;
  
return ss.str();
}

bool Endereco::fromCSV(string csv, char separador)
{
    
    if(csv != "")
    {

        string aux;
        stringstream buffer(csv);

        getline(buffer, this->logradouro, separador);
        getline(buffer, this->numero, separador);
        getline(buffer, this->complemento, separador);
        getline(buffer, this->bairro, separador);
        getline(buffer, this->cidade, separador);
        getline(buffer, this->uf, separador);
        getline(buffer, this->cep, separador);

    return true;
    }

return false;
}

bool Endereco::operator==(const Endereco &endereco) const
{
    
    string _this = logradouro + numero + complemento + bairro + cidade + uf + cep;
    string obj = endereco.logradouro + endereco.numero + endereco.complemento + endereco.bairro + endereco.cidade + endereco.uf + endereco.cep;
  
    if(_this == obj) return true;
  
return false;
}

istream &operator>>(istream& in,Endereco &endereco)
{

  getline(in, endereco.logradouro);
  getline(in, endereco.numero);
  getline(in, endereco.complemento);
  getline(in, endereco.bairro);
  getline(in, endereco.cidade);
  getline(in, endereco.uf);
  getline(in, endereco.cep);

return in;
}

ostream &operator<<(ostream& out,const Endereco &endereco)
{

  out << endereco.logradouro << endl;
  out << endereco.numero << endl;
  out << endereco.complemento << endl;
  out << endereco.bairro << endl;
  out << endereco.cidade << endl;
  out << endereco.uf << endl;
  out << endereco.cep;

return out;
}