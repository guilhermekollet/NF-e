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

bool Endereco::operator==(const Endereco &e) const
{
    
    string _this = logradouro + numero + complemento + bairro + cidade + uf + cep;
    string obj = e.logradouro + e.numero + e.complemento + e.bairro + e.cidade + e.uf + e.cep;
  
    if(_this == obj) return true;
  
return false;
}

istream &operator>>(istream& in,Endereco &e)
{

  getline(in, e.logradouro);
  getline(in, e.numero);
  getline(in, e.complemento);
  getline(in, e.bairro);
  getline(in, e.cidade);
  getline(in, e.uf);
  getline(in, e.cep);

return in;
}

ostream &operator<<(ostream& out,const Endereco &e)
{

  out << e.logradouro << endl;
  out << e.numero << endl;
  out << e.complemento << endl;
  out << e.bairro << endl;
  out << e.cidade << endl;
  out << e.uf << endl;
  out << e.cep;

return out;
}