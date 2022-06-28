#include "Program.hpp"

Program::Program()
{

}

Program::~Program()
{

}

void Program::menu_Carregamento(string urlEmpresa, string urlProdutos)
{
    bool loop;
    
    do
    {
        
        int value;
        string urEm;
        string urPr;

        cout << endl;

        cout << "1) Carregar dados salvos" << endl;
        cout << "2) Carregar novos dados" << endl;
        cout << "3) Sair" << endl;

        cout << endl;

        cout << "> ";
        cin >> value;

        switch(value)
        {

            case 1:
                system("clear||cls");
                if(loadFile_Empresa(urlEmpresa) && loadFile_Produtos(urlProdutos)) loop = false;

                cout << empresa.obtemNome() << " - Logado | " << produtos.obtemNumProdutos() << " produtos cadastrados."<< endl << endl;

            break;

            case 2:
                system("clear||cls");

                cout << "Insira o nome do arquivo referente a Empresa:" << endl;
                cout << "> ";
                cin >> urEm;

                if(loadFile_Empresa(urEm))
                {
                    cout << endl << "Carregamento realizado! " << empresa.obtemNome() << " definida." << endl << endl;

                    cout << endl << "Insira o nome do arquivo referente aos Produtos:" << endl;
                    cout << "> ";
                    cin >> urPr;

                    if(loadFile_Produtos(urPr))
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

            case 3:
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
        int status = 0;

        cout << "1) Gerar Relatorio" << endl;
        cout << "2) Iniciar Venda" << endl;
        cout << "3) Sair" << endl;

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

                cout << "Conectando ao sistema de Emissao de Cupom Fiscal" << endl << endl;
                
                if(loadFile_Nfe("data/nf-e.csv"))
                {

                    cout << "[1/3] NF-E CONECTADO!" << endl << endl;
                    status += 1;

                }

                if(loadFile_Descontos("data/descontos.csv"))
                {

                    cout << "[2/3] TABELA DE DESCONTOS CONECTADA!" << endl << endl;
                    status += 1;

                }

                    cout << "[!!!/3] TABELA DE COMPRAS NAO CARREGADA!" << endl << "[ATENCAO] EXIBICAO DE MODULO PERMITIDO..." << endl << endl;
                    status += 1;

                if(status == 3) cout << obtemCumpomFiscal() << endl;
                else cout << "Nao foi possivel gerar o cupom fiscal." << endl;
            
            break;

            case 3:
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

bool Program::loadFile_Nfe(string urlNfe)
{

    if(urlNfe != "")
    {
        ifstream read(urlNfe);
        string auxStream;
        stringstream stream;

        do
        {
            getline(read, auxStream, '\r');
            stream << auxStream;

        } while (read.good());

        if(nfe.fromCSV(stream.str())) nfe.setDatabase(urlNfe);

        read.close();

        if(nfe.obtemNumero() > 0) return true;
    }

return false;
}

bool Program::loadFile_Descontos(string urlDescontos)
{

    if(urlDescontos != "")
    {
        ifstream read(urlDescontos);
        string auxStream;
        stringstream stream;
        string codigoBarrasA;
        string valorDescontoA;
        string quantidadeItensA;
        string itensPagosA;
        string quantidadeItensB;
        string codigoBarrasB;
        string valorDescontoB;

        do
        {
            getline(read, codigoBarrasA, ';');
            getline(read, valorDescontoA, ';');

            if(valorDescontoA != "")
            {

                Desconto *d = new Desconto(codigoBarrasA,valorDescontoA);
                descontos.adiciona(*d);

                cout << endl << codigoBarrasA << " - Possui direito a Desconto Simples!" << endl;
                
            }

            getline(read, quantidadeItensA, ';');
            getline(read, itensPagosA, ';');
            quantidadeItensB = itensPagosA;
            getline(read, codigoBarrasB, ';');

            if(codigoBarrasB != "")
            {

                Desconto *d = new Desconto(codigoBarrasA,valorDescontoA);
                descontos.adiciona(*d);

                cout << endl << codigoBarrasA << " - Possui direito a Desconto Combinado se levar " << codigoBarrasB << endl;
                
            }

            getline(read, valorDescontoB, '\n');

            cout << "CodigoBarrasA:  " << codigoBarrasA << "  ";
            
            cout << "valorDescontoA:  " << valorDescontoA << "  ";

            cout << "quantidadeItensA:  " << quantidadeItensA << "  ";
            
            cout << "itensPagosA:  " << itensPagosA << "  ";
            
            cout << "quantidadeItensB:  " << quantidadeItensB << "  ";
            
            cout << "codigoBarrasB:  " << codigoBarrasB << "  ";
            
            cout << "valorDescontoB:  " << valorDescontoB << "  " << endl;

        } while (read.good());   
    
        cout << endl << "Descontos adicionados: " << endl << descontos.str() << endl;
        
        read.close();

    return true;
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

string toolTable_Center(int largura,string text)
{

    int diferenca = largura - text.length();
    int position = diferenca / 2;

    string newText = "";

    for(int i=0; i < position; i++)
    {

            newText += " ";

    }

    newText += text;

    for(int i=0; i < position; i++)
    {

            newText += " ";

    }

return newText;
}

string Program::obtemCumpomFiscal()
{
    //Variables List
    int larguraTable = 100; //Tamanho da Tabela

    //_Header
    string ssHeader_Empresa = empresa.obtemNome() + " - Telefone: " + empresa.obtemTelefone();
    string ssHeader_Endereco = empresa.obtemEndereco().obtemLogradouro() + ", " + empresa.obtemEndereco().obtemNumero() + " - " + empresa.obtemEndereco().obtemBairro() + " - " + empresa.obtemEndereco().obtemCidade() + "-" + empresa.obtemEndereco().obtemUF() + " CEP " + empresa.obtemEndereco().obtemCEP();
    string ssHeader_Institucional = "CNPJ: " + empresa.obtemCNPJ().str() + " - IE: " + empresa.obtemInscEst();
    string ssHeader_Tittle = "DOCUMENTO AUXILIAR DA NOTA FISCAL DE CONSUMIDOR ELETRONICA";

    //_Footer
    nfe.EmiteNFC_str();
    string data = nfe.obtemLastTimeEmitted();

    //Table Header
    stringstream ssHeader;
    ssHeader << setw(larguraTable) << setfill('-') << "" << endl;

    ssHeader << setw(larguraTable) << setfill(' ') << toolTable_Center(larguraTable, ssHeader_Empresa) << endl;
    ssHeader << setw(larguraTable) << setfill(' ') << toolTable_Center(larguraTable, ssHeader_Endereco) << endl;
    ssHeader << setw(larguraTable) << setfill(' ') << toolTable_Center(larguraTable, ssHeader_Institucional) << endl;
    
    ssHeader << setw(larguraTable) << setfill('-') << "" << endl;

    ssHeader << setw(larguraTable) << setfill(' ') << toolTable_Center(larguraTable, ssHeader_Tittle) << endl;

    ssHeader << setw(larguraTable) << setfill('-') << "";


    //Table Tittle
    stringstream ssContent;
    ssContent << setiosflags(ios::left) << setw (2) << setfill(' ') << "I.";
    ssContent << "  ";

    ssContent << setiosflags(ios::left) << setw (13) << setfill(' ') << "CODIGO";
    ssContent << "  ";

    ssContent << setiosflags(ios::left) << setw (50) << setfill (' ') << "DESCRICAO";
    ssContent << "  ";

    ssContent << setiosflags(ios::right) << setw (5) << setfill (' ') << "R$ UN";
    ssContent << "  ";

    ssContent << setiosflags(ios::right) << setw (3) << setfill (' ') << "QTD";
    ssContent << "  ";

    ssContent << setiosflags(ios::right) << setw(8) << setfill(' ') << "DESCONTO";
    ssContent << "  ";

    ssContent << setiosflags(ios::left) << setw(7) << setfill(' ') << "VAL(R$)";
    ssContent << "  ";
        
    ssContent << endl << setw(larguraTable) << setfill('-') << "";

    //ss << endl << produtos.str();

    stringstream ssFooter;
    ssFooter << setw(larguraTable) << setfill('-') << "" << endl;

    ssFooter << setiosflags(ios::right) << setw(86) << setfill(' ') << "TOTAL";
    ssFooter << setiosflags(ios::right) << setw(14) << setfill(' ') << "000,00" << endl;

    ssFooter << setw(larguraTable) << setfill('-') << "" << endl;

    ssFooter << setiosflags(ios::left) << setw(22) << setfill(' ') << nfe.str();
    ssFooter << setiosflags(ios::left) << setw(78) << setfill(' ') << data << endl;
    
    ssFooter << setw(larguraTable) << setfill('-') << "" << endl;

    stringstream ssAll;
    ssAll << ssHeader.str() << endl << ssContent.str() << endl << ssFooter.str() << endl;

return ssAll.str();
}