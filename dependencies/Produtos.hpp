// Produtos.hpp (Roland Teodorowitsch; 2 maio 2020)

#ifndef _PRODUTOS_HPP
#define _PRODUTOS_HPP

#include <string>
#include <vector>
#include <iomanip>
#include "Produto.hpp"

using namespace std;

class Produtos
{

    //Attributes
    private:	
    int numProdutos;
    vector<Produto> produtos;

    //Methods
    public:
    Produtos();
    ~Produtos();
    int obtemMaxProdutos() const;
    int obtemNumProdutos() const;
    Produto *obtem(int indice);
    Produto *busca(string cb);
    bool adiciona(Produto &produto);
    bool remove(int indice);
    string str() const;
	bool fromCSV(string csv, char separador = ';'); //lê CSV
	string toCSV(char separador = ';'); //converte para CSV 
    friend istream &operator>>(istream& in,Produtos &produtos);
    friend ostream &operator<<(ostream& out,const Produtos &produtos);
};

#endif
