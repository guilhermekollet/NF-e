#include "Cnpj.hpp"

//Constructor and Destructor
Cnpj::Cnpj()
{

  raiz = "00000000";
  filial = "0000";
  dv = "00";

}

Cnpj::Cnpj(string cnpj)
{

  if(ehValido(cnpj))
  {

    define(cnpj);

  }
  else
  {

    raiz = "00000000";
    filial = "0000";
    dv = "00";
    
  }

}

Cnpj::~Cnpj()
{
    
}

bool Cnpj::ehValido(string cnpj) 
{

  if(cnpj.size() < 14) return false;
  if(cnpj.size() >= 14)
  {
    
    cnpj = regex_replace(cnpj, regex("\\."), "");
    cnpj = regex_replace(cnpj, regex("\\/"), "");
        
    int dv[2];
    dv[0] = (cnpj.at(cnpj.size()-2)-'0');
    dv[1] = (cnpj.at(cnpj.size()-1)-'0');       
    cnpj = cnpj.substr(0,12);
      
    //Checking dv[0]
    int pesoVerificador[] { 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2 };
    int multiplicador[12];
    int somatorio = 0;
    int cnpjArray[14];
    int dvF0;
    int tam = sizeof(pesoVerificador)/sizeof(int);
      
    //Producing the treated string in vector of integers
    for(int i=0; i < tam; i++)
    {

      cnpjArray[i] = cnpj.at(i)-'0';

    }
          
    //Column multiplication
    for(int i=0; i < tam; i++)
    {

      multiplicador[i] = cnpjArray[i] * pesoVerificador[i];

    }   
    
    //Sum per column
    for(int i=0; i < tam; i++)
    {

      somatorio += multiplicador[i];   

    }  
    
    //Checking
    int resta = somatorio % 11;
    if (resta < 2)
    {

        dvF0 = 0;

    }
    else
    {

        dvF0 = 11-resta;

    }
    
    if (dvF0 == dv[0])
    {

        int pesoVerificador2[] { 6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2 };
        int multiplicador2[13];
        int somatorio2 = 0;
        int dvF1;
        int tam2 = sizeof(pesoVerificador2)/sizeof(int);
  
        cnpjArray[12] = dvF0;

        //Column multiplication
        for(int i=0; i < tam2; i++)
        {

          multiplicador2[i] = cnpjArray[i] * pesoVerificador2[i];

        }  
        
        //Sum per column
        for(int i=0; i < tam2; i++)
        {

          somatorio2 += multiplicador2[i];

        }
        
        //Checking
        int resta = somatorio2 % 11;
      
        if (resta < 2)
        {

          dvF1 = 0;

        }
        else
        
        {
          dvF1 = 11-resta;

        }
        
        if (dvF1 == dv[1])
        {

          cnpjArray[13] = dv[1];

          return true;
        }
        else
        {

          return false;

        }
      }
    }
    
return false;
}

bool Cnpj::define(string cnpj)
{

  if(ehValido(cnpj))
  {

    cnpj = regex_replace(cnpj, regex("\\."), "");
    cnpj = regex_replace(cnpj, regex("\\/"), "");
        
    dv = cnpj[cnpj.size()-2];
    dv += cnpj[cnpj.size()-1];       
    raiz = cnpj.substr(0,8);
    filial = "";

    for(int i=8; i<12; i++) filial += cnpj[i];
    
  return true;
  }
  else
  {

  return false;
  }
}

string Cnpj::obtemRaiz() const
{

return raiz;
}

string Cnpj::obtemFilial() const
{

return filial;
}

string Cnpj::obtemDV() const
{

return dv;
}

string Cnpj::str() const
{

  if(raiz != "" && filial != "")
  {

    stringstream ss;

    ss << raiz.substr(0,2) << "." << raiz.substr(2,3) << "." << raiz.substr(5,7) << "/" << filial << "-" << dv;

  return ss.str(); 
  }

return "";
}

bool Cnpj::operator==(const Cnpj &cnpj) const
{

  string _this = raiz+filial+dv;
  string aux = cnpj.raiz + cnpj.filial + cnpj.dv;
  
  if(_this == aux) return true;
  
return false;
}

istream& operator>>(istream& in,Cnpj& cnpj)
{

  string aux;
  
  in >> aux;
  cnpj.define(aux);

return in;
}

ostream& operator<<(ostream& out,const Cnpj& cnpj)
{
    
  out << cnpj.str();
    
return out;
}