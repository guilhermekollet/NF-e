#ifndef _CNPJ_HPP
#define _CNPJ_HPP
#include <string>
#include <regex>
#include <sstream>

using namespace std;

class Cnpj
{

    //Attributes
    private:
    string raiz;
    string filial;
    string dv;

    //Methods
    public:
    Cnpj();
    ~Cnpj();
    static bool ehValido(string cnpj);
    bool define(string cnpj);
    string obtemRaiz() const;
    string obtemFilial() const;
    string obtemDV() const;
    string str() const;
    bool operator==(const Cnpj &cnpj) const;
    friend istream& operator>>(istream& in,Cnpj& cnpj);
    friend ostream& operator<<(ostream& out,const Cnpj& cnpj);		

};
#endif