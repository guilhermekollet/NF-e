#ifndef _PROGRAM_HPP
#define _PROGRAM_HPP

#include <iostream>
#include <fstream>
#include "Empresa.hpp"
#include "Produtos.hpp"
#include "Nfe.hpp"
#include "DescontoCombinado.hpp"
#include "DescontoLMPN.hpp"
#include "DescontoSimples.hpp"

using namespace std;

class Program
{

    //Attributes
    private:
    Empresa empresa;
    Produtos produtos;
    Nfe nfe;
    Desconto descontos;

    //Methods
    public:
    Program();
    ~Program();
    void menu_Carregamento(string urlEmpresa, string urlProdutos);
    void menu_Interface();
    bool loadFile_Empresa(string urlEmpresa);
    bool loadFile_Produtos(string urlProdutos);
    bool loadFile_Compras(string urlCompras);
    bool loadFile_Nfe(string urlNfe);
    bool loadFile_Descontos(string urlDescontos);
    string obtemEmpresa();
    string obtemProdutos();
    string obtemRelatorio();
    string obtemCumpomFiscal();

};

#endif