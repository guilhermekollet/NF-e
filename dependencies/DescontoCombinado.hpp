#ifndef _DESCONTOCOMBINADO_HPP
#define _DESCONTOCOMBINADO_HPP
#include "Desconto.hpp"

class DescontoCombinado : public Desconto
{

    //Attributes
    private:
    string codigoBarras;
    string desconto;
    string quantidade;

    //Methods
    public:
    DescontoCombinado();
    DescontoCombinado(string cod, string valorDescontoA);
    ~DescontoCombinado();

};

#endif