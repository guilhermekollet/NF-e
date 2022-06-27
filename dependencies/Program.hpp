#include <iostream>
#include <fstream>
#include "Empresa.hpp"
#include "Produtos.hpp"

using namespace std;

class Program
{

    //Attributes
    private:
    Empresa empresa;
    Produtos produtos;

    //Methods
    public:
    Program();
    ~Program();
    void menu_Carregamento(string urlEmpresa, string urlProdutos);
    void menu_Interface();
    bool loadFile_Empresa(string urlEmpresa);
    bool loadFile_Produtos(string urlProdutos);
    string obtemEmpresa();
    string obtemProdutos();
    string obtemRelatorio();

};