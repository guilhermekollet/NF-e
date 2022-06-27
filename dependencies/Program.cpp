#include "Program.hpp"

Program::Program()
{

}

Program::~Program()
{

}

void Program::menu_Carregamento()
{
    bool loop;
    
    do
    {
        
        int value;
        string urlEmpresa;
        string urlProdutos;

        cout << "1) Carregar dados" << endl;
        cout << "2) Sair" << endl;

        cout << endl;

        cout << "> ";
        cin >> value;

        switch(value)
        {

            case 1:
                system("clear||cls");
                cout << "Insira o nome do arquivo referente a Empresa:" << endl;
                cout << "> ";
                cin >> urlEmpresa;

                if(loadFile_Empresa(urlEmpresa))
                {
                    cout << endl << "Carregamento realizado! " << empresa.obtemNome() << " definida." << endl << endl;

                    cout << endl << "Insira o nome do arquivo referente aos Produtos:" << endl;
                    cout << "> ";
                    cin >> urlProdutos;

                    if(loadFile_Produtos(urlProdutos))
                    {

                        cout << endl << "Carregamento realizado! " << produtos.obtemNumProdutos() << " produtos localizados." << endl << endl << endl;
                    
                    loop = false;
                    }
                    else
                    {

                        cout << endl << "Nao foi possivel carregar, confira se a url esta correta! " << endl << endl;
                    
                    break;
                    }

                }
                else
                {

                    cout << endl << "Nao foi possivel carregar, confira se a url esta correta! " << endl << endl;
                    
                break;
                }

            break;

            case 2:
                system("clear||cls");
                exit(1);

            break;
            
            default:
            
            break;
        }

    } 
    while(loop);
    
}

void Program::menu_Interface()
{

    bool loop;
    
    do
    {

        int value;

        cout << "1) Gerar Relatorio" << endl;
        cout << "2) Sair" << endl;

        cout << endl;

        cout << "> ";
        cin >> value;

        switch(value)
        {

            case 1:
                system("clear||cls");
                cout << obtemRelatorio() << endl;

            break;
            
            case 2:
                system("clear||cls");
                exit(1);
            
            break;
            
            default:

            break;

        }   

    }
    while(loop);

}

bool Program::loadFile_Empresa(string urlEmpresa)
{

    if(urlEmpresa != "")
    {

        ifstream read(urlEmpresa);
        string auxStream;
        stringstream stream;

        do
        {
            getline(read, auxStream, '\r');
            stream << auxStream;

        } while (read.good());

        empresa.fromCSV(stream.str());

        read.close();

        if(empresa.obtemNome() != "") return true;
    }

return false;
}

bool Program::loadFile_Produtos(string urlProdutos)
{

    if(urlProdutos != "")
    {
        ifstream read(urlProdutos);
        string auxStream;
        stringstream stream;

        do
        {
            getline(read, auxStream, '\r');
            stream << auxStream;

        } while (read.good());

        produtos.fromCSV(stream.str(), '\r');

        read.close();

        if(produtos.obtemNumProdutos() > 0) return true;
    }

return false;
}

string Program::obtemEmpresa()
{

return empresa.str();
}

string Program::obtemProdutos()
{

return produtos.str();
}

string Program::obtemRelatorio()
{

    stringstream ss;
    ss << setiosflags(ios::left) << setw (13) << setfill(' ') << "COD DE BARRAS";
    ss << "  ";

    ss << setiosflags(ios::left) << setw (42) << setfill (' ') << "DESCRICAO";
    ss << "  ";

    ss << setiosflags(ios::left) << setw (7) << setfill (' ') << "UN./GR.";
    ss << "  ";

    ss << setiosflags(ios::left) << setw (5) << setfill (' ') << "MEDIDA";
    ss << "  ";

    ss << setiosflags(ios::right) << setw(8) << setfill(' ') << "EMBAL.";
    ss << "  ";

    ss << setiosflags(ios::left) << setw(5) << setfill(' ') << "PRECO";
    ss << "  ";

    ss << setiosflags(ios::left) << setw(8) << setfill(' ') << "VALOR/MEDIDA";
    ss << "  ";
        
    ss << endl << setw(108) << setfill('=') << "";

    ss << endl << produtos.str();

return ss.str();
}