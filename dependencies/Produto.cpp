#include "Produto.hpp"

Produto::Produto()
{

  codBarras = "";
  descricao = "";
  granelOuUnidade = "unidade";
  medida = "";
  quantidade = 0.0;
  preco = 0.0;

}

Produto::Produto(string cB,string d,string gOu,string m,double q, double p)
{

  codBarras = cB;
  descricao = d;
  granelOuUnidade = gOu;
  medida = m;
  quantidade = q;
  preco = p;

}

Produto::~Produto()
{
    
}

string Produto::obtemCodBarras() const
{

return codBarras;
}

bool Produto::defineCodBarras(string codBarras)
{

    if(codBarras != "")
    {

        this->codBarras = codBarras;

    return true;
    }

return false;
}

string Produto::obtemDescricao() const
{

return descricao;
}

bool Produto::defineDescricao(string descricao)
{

    if(descricao != "")
    {

        this->descricao = descricao;

    return true;
    }

return false;
}

string Produto::obtemGranelOuUnidade() const
{

return granelOuUnidade;
}

bool Produto::defineGranelOuUnidade(string granelOuUnidade)
{

    if(granelOuUnidade != "")
    {

        this->granelOuUnidade = granelOuUnidade;

    return true;
    }

return false;
}

string Produto::obtemMedida() const
{

return medida;
}

bool Produto::defineMedida(string medida)
{

    if(medida != "")
    {

        this->medida = medida;

    return true;
    }

return false;
}

double Produto::obtemQuantidade() const
{

return quantidade;
}

bool Produto::defineQuantidade(double quantidade)
{

    if(quantidade > -1.0)
    {

        this->quantidade = quantidade;

    return true;
    }

return false;
}

double Produto::obtemPreco() const
{

return preco;
}

bool Produto::definePreco(double preco)
{

    if(preco > -1.0)
    {

        this->preco = preco;

    return true;
    }

return false;
}

string Produto::str() const
{
    
    stringstream ss;
      
  ss << setiosflags(ios::left) << setw (13) << setfill(' ') << codBarras;
  ss << "  ";

  ss << setiosflags(ios::left) << setw (40) << setfill (' ') << descricao;
  ss << "  ";

  ss << setiosflags(ios::left) << setw (7) << setfill (' ') << granelOuUnidade;
  ss << "  ";

  ss << setiosflags(ios::left) << setw (5) << setfill (' ') << medida;
  ss << "  ";

  ss << setiosflags(ios::right) << setw(8) << setfill(' ') << setprecision(4) << fixed << quantidade;
  ss << "  ";

  ss << setiosflags(ios::left) << setw(5) << setfill(' ') << setprecision(2) << fixed << preco;
  ss << "  ";

  double valorUnid = preco / quantidade;

  ss << setiosflags(ios::left) << setw(8) << setfill(' ') << setprecision(4) << fixed << valorUnid;
  ss << "  ";
      
  ss << "R$/" << medida;

return ss.str();
}

bool Produto::fromCSV(string csv, char separador)
{

    if(csv != "")
    {

        string quantidade;
        string preco;

        string aux;
        stringstream buffer(csv);
        stringstream stream;

        getline(buffer, this->codBarras, separador);
        getline(buffer, this->descricao, separador);
        getline(buffer, this->granelOuUnidade, separador);
        getline(buffer, this->medida, separador);
        getline(buffer, quantidade, separador);   
        getline(buffer, preco, separador);   

        this->quantidade = atof(quantidade.c_str());
        this->preco = atof(preco.c_str());

    return true;
    }

return false;
}

string toCSV(char separador)
{

}

bool Produto::operator==(const Produto &produto) const
{

return (this->codBarras == produto.codBarras
&& this->descricao == produto.descricao
&& this->granelOuUnidade == produto.granelOuUnidade
&& this->medida == produto.medida
&& this->quantidade == produto.quantidade
&& this->preco == produto.preco);
}

bool Produto::operator<(const Produto &produto) const
{
    
    if(this->descricao.length() < produto.descricao.length()) return true;
    else if(this->codBarras == produto.codBarras) return false;
    else return false; 

}

istream &operator>>(istream& in,Produto &produto)
{

  getline(in, produto.codBarras);
  getline(in, produto.descricao);
  in >> produto.granelOuUnidade;
  in >> produto.medida;
  in >> produto.quantidade;
  in >> produto.preco;

return in;
}

ostream &operator<<(ostream& out,const Produto &produto)
{

  out << produto.codBarras << endl;
  out << produto.descricao << endl;
  out << produto.granelOuUnidade << endl;
  out << produto.medida << endl;
  out << setprecision(4) << fixed << produto.quantidade << endl;
  out << setprecision(2) << fixed << produto.preco;
  out << setprecision(2);

return out;
}