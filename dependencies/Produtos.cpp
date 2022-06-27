#include "Produtos.hpp"

Produtos::Produtos()
{

  numProdutos = 0;

}

Produtos::~Produtos()
{
  
}

int Produtos::obtemMaxProdutos() const
{

return produtos.max_size();
}

int Produtos::obtemNumProdutos() const
{

return numProdutos;
}

Produto *Produtos::obtem(int indice)
{

  if(indice >= numProdutos) return nullptr;
  if(indice >= 0 && indice <= produtos.max_size()) return &produtos.at(indice);
  
return nullptr;
}

Produto *Produtos::busca(string cb)
{

    for(int i=0; i < numProdutos; i++)
    {

      if(produtos.at(i).obtemCodBarras() == cb) return &produtos.at(i);

    }

return nullptr;
}

bool Produtos::adiciona(Produto &produto)
{

    if(numProdutos < produtos.max_size())
    {

        produtos.push_back(produto);
        numProdutos++;
  
  return true;
  }

return false;
}

bool Produtos::remove(int indice)
{

    if(indice < 0 || indice >= numProdutos) return false;
    
    for(int i = indice; i<numProdutos - 1; i++)
    {

        produtos[i] = produtos[i+1];
    
    }
  
    --numProdutos;
  
return true;
}

string Produtos::str() const
{

    stringstream ss;
    
    for(int i=0; i < numProdutos; i++)
    {

        ss << produtos.at(i).str() << endl;
  
    }

return ss.str();
}

bool Produtos::fromCSV(string csv, char separador)
{

    if(csv != "")
    {

    istringstream buffer(csv);
    string aux;

    do
    {

        Produto *p = new Produto();
        getline(buffer, aux);
        p->fromCSV(aux);
        adiciona(*p);
        delete p;

    }
    while(buffer.good());
    return true;
    }

return false;
}

istream &operator>>(istream& in,Produtos &produtos)
{

    while(in.good())
    {
 
        Produto *produto = new Produto();
        string cod, des, gra, med, qt, pre;
        double quantidade, preco;

        getline(in, cod);
        if(cod == "") break;
        produto->defineCodBarras(cod);
        
        getline(in,des);
        produto->defineDescricao(des);
        getline(in,gra);
        produto->defineGranelOuUnidade(gra);
        getline(in,med);
        produto->defineMedida(med);
        getline(in,qt);
        quantidade = atof(qt.c_str()); 
        produto->defineQuantidade(quantidade); 
        getline(in, pre);
        preco = atof(pre.c_str());
        produto->definePreco(preco);
        produtos.adiciona(*produto);
    }

return in;
}

ostream &operator<<(ostream& out,const Produtos &produtos)
{

    for(int i=0; i < produtos.numProdutos; i++)
    out << &produtos.produtos.at(i) << endl;

return out;
}