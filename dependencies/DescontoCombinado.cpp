#include "DescontoCombinado.hpp"

DescontoCombinado::DescontoCombinado(string cod, string valorDescontoA) : Desconto(cod, valorDescontoA)
{
    codigoBarras = cod;
}

DescontoCombinado::~DescontoCombinado()
{
    
}