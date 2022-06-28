#include "DescontoSimples.hpp"

DescontoSimples::DescontoSimples(string cod, string valorDescontoA) : Desconto(cod, valorDescontoA)
{
    this->porcentagemDesconto = valorDescontoA;
    codigoBarras = cod;

}

DescontoSimples::~DescontoSimples()
{

}