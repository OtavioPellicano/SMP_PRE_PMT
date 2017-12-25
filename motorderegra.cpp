#include "motorderegra.h"

namespace opmm {

void pre_PMT_rule(const string &fileIn, const string &fileOut)
{
    vecStr vecStrLinhaFileOut;

    int hour;
    string strTemp;

    ifstream arqFileIn(fileIn);
    if(arqFileIn.is_open())
    {
        string str;
        for(unsigned int i = 1; getline(arqFileIn, str); ++i)
        {
            //retirando o cabecalho

            strTemp = opmm::StringCsv(str).getStrItemStringSplitted(1);

            if (i != 1)
            {
                if(isdigit(strTemp[0]))
                {
                    hour = stoi(string(strTemp, 11, 2));
                    if (hour >= 4 && hour <= 10)
                        continue;
                }
                else
                {
                    continue;
                }
            }

            vecStrLinhaFileOut.push_back(str);

        }
        qDebug() << QString("Número de linhas pós processamento: %1").arg(vecStrLinhaFileOut.size());

        arqFileIn.close();
    }
    else
    {
        qDebug() << "Impossível abrir fileIn: " << QString::fromStdString(fileIn);
    }

    //salvando no novo arquivo
    ofstream arqFileOut(fileOut);

    if(arqFileOut.is_open())
    {
        for(vecStr::iterator itVec = vecStrLinhaFileOut.begin(); itVec != vecStrLinhaFileOut.end(); ++itVec)
        {
            arqFileOut << *itVec << endl;
        }
        vecStrLinhaFileOut.clear();
        arqFileOut.close();
    }
    else
    {
        qDebug() << "Impossível abrir fileOut: " << QString::fromStdString(fileOut);
    }
}


}

