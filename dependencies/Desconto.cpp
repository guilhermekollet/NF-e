#include "Desconto.hpp"

Desconto::Desconto()
{

}

Desconto::Desconto(string cod, string porcentagem)
{
    codigoBarras = cod;
    porcentagemDesconto = porcentagem;
    numDescontos = 1;
}

bool Desconto::adiciona(Desconto &desconto)
{

    if(desconto.obtemCodigoBarras() != "")
    {

        Lista.push_back(desconto);
        numDescontos++;

    }

}

string Desconto::obtemCodigoBarras()
{

return codigoBarras;
}

string Desconto::obtemQuantidade()
{

return quantidade;
}

string Desconto::obtemPorcentagemDesconto()
{

return porcentagemDesconto;
}

string Desconto::str()
{

    stringstream ss;

    for(int i=0; i < numDescontos; i++)
    {
        ss << "Codigo de Barras: " << Lista.at(i).obtemCodigoBarras() << "  -  Porcentagem: " << stof(Lista.at(i).obtemPorcentagemDesconto())*100 << "%" << endl;
    
    return ss.str();
    }

}
