#ifndef _PRODUTO_HPP
#define _PRODUTO_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Produto
{

    //Attributes
    private:
    string codBarras;
    string descricao;
    string granelOuUnidade;
    string medida;
    double quantidade;
    double preco;

    //Methods
    public:
    Produto();
    Produto(string cB,string d,string gOu,string m,double q, double p);
    ~Produto();
    string obtemCodBarras() const;
    bool defineCodBarras(string codBarras);
    string obtemDescricao() const;
    bool defineDescricao(string descricao);
    string obtemGranelOuUnidade() const;
    bool defineGranelOuUnidade(string granelOuUnidade);
    string obtemMedida() const;
    bool defineMedida(string medida);
    double obtemQuantidade() const;
    bool defineQuantidade(double quantidade);
    double obtemPreco() const;
    bool definePreco(double preco);
    string str() const;
	bool fromCSV(string csv, char separador = ';'); //lê CSV
	string toCSV(char separador = ';'); //converte para CSV
    bool operator==(const Produto &produto) const;
    bool operator<(const Produto &produto) const;
    friend istream &operator>>(istream& in,Produto &produto);
    friend ostream &operator<<(ostream& out,const Produto &produto);

};

#endif