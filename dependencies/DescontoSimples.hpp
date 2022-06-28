#ifndef _DESCONTOSIMPLES_HPP
#define _DESCONTOSIMPLES_HPP
#include "Desconto.hpp"

class DescontoSimples : public Desconto
{

    //Attributes
    private:
    string codigoBarras;
    string desconto;
    string quantidade;

    //Methods
    public:
    DescontoSimples();
    DescontoSimples(string cod, string quantidade);
    ~DescontoSimples();

};

#endif