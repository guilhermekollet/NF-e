#include "Nfe.hpp"

Nfe::Nfe()
{

    numero = 0;
    serie = 0;

}

Nfe::~Nfe()
{



}

bool Nfe::setDatabase(string url)
{

    if(url != "")
    {

        database = url;

    return true;    
    }

return false;
}

int Nfe::obtemNumero() const
{


return numero;
}

int Nfe::obtemSerie() const
{


return serie;
}

bool Nfe::incrementa()
{

    numero += 1;

}

bool Nfe::fromCSV(string csv, char separador)
{

    if(csv != "")
    {
        string numero, serie;
        stringstream buffer(csv);

        getline(buffer, numero, separador);
        getline(buffer, serie, separador); 

        this->numero = stoi(numero);
        this->serie = stoi(serie);

    return true;
    }

return false;
}

string Nfe::toCSV(char separador)
{

    stringstream ss;
    ss << numero << ";" << serie;
    
return ss.str();
}

string Nfe::str()
{

    stringstream ss;
    ss << "NCF-e: " << numero << " - Serie: " << serie;
 
return ss.str();
}

string Nfe::EmiteNFC_str()
{

    stringstream ss;
    ss << str();

    incrementa();

    ofstream writer(database, ios::trunc);
    if(writer.is_open())
    {

        writer << toCSV();

    }

    writer.close();

    time_t t;
    struct tm * tempo;
    time(&t);
    tempo = localtime(&t);

    stringstream data;
    data << "Data: ";
    
    data << tempo->tm_mday << "/";
    if(tempo->tm_mon < 10)
    {
        
        data << "0" << tempo->tm_mon << "/";
    
    }
    else
    {

        data << tempo->tm_mon << "/";

    }

    data << tempo->tm_year+1900;

    if(tempo->tm_hour < 10)
    {

        data << " - Hora: 0" << tempo->tm_hour << ":";

    }
    else
    {

        data << " - Hora: " << tempo->tm_hour << ":";

    }

    if(tempo->tm_min < 10)
    {
        
        data << "0" << tempo->tm_min << ":";
    
    }
    else
    {

        data << tempo->tm_min << ":";

    }

    if(tempo->tm_sec < 10)
    {
        
        data << "0" << tempo->tm_sec;
    
    }
    else
    {

        data << tempo->tm_sec;

    }

    lastTimeEmitted = data.str();


return ss.str();
}

string Nfe::obtemLastTimeEmitted()
{

return lastTimeEmitted;
}