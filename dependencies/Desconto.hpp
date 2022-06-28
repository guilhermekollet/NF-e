#ifndef _DESCONTO_HPP
#define _DESCONTO_HPP
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Desconto
{

    //Attributes
    protected:
    int numDescontos;
    string codigoBarras;
    string quantidade;
    string porcentagemDesconto;

    vector<Desconto> Lista;

    //Methods
    public:
    Desconto();
    Desconto(string cod, string porcentagem);
    bool adiciona(Desconto &desconto);
    virtual string obtemCodigoBarras();
    virtual string obtemQuantidade();
    virtual string obtemPorcentagemDesconto();
    virtual string str();

};

#endif