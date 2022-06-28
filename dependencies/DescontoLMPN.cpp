#include "DescontoLMPN.hpp"

DescontoLMPN::DescontoLMPN(string cod, string valorDescontoA) : Desconto(cod, valorDescontoA)
{
    codigoBarras = cod;
}

DescontoLMPN::~DescontoLMPN()
{
    
}