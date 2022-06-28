#ifndef _DESCONTOLMPN_HPP
#define _DESCONTOLMPN_HPP
#include "Desconto.hpp"

class DescontoLMPN : public Desconto
{

    //Attributes
    private:
    string codigoBarras;
    string desconto;
    string quantidade;

    //Methods
    public:
    DescontoLMPN();
    DescontoLMPN(string cod, string valorDescontoA);
    ~DescontoLMPN();

};

#endif