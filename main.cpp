#include <iostream>
#include <StringCsv.h>
#include <QDir>
#include <QStringList>
#include <QDebug>
#include <QFile>
#include <map>
#include <fstream>
#include <string>
#include "motorderegra.h"

using namespace std;


//protótipo
int main()
{


    QDir tabelaCnUfGmtDir("tabela/cn_uf_gmt.csv");
    QString tabelaCnUfGmt = tabelaCnUfGmtDir.absolutePath();


    QDir inDir("IN");
    QStringList filesFilter;
    filesFilter << "*.csv";
    QStringList inCsvFiles;
    inCsvFiles = inDir.entryList(filesFilter);

    QDir outDir("OUT");


    mapStrStr mapCnUf;
    mapStrStr mapCnGmt;

    ifstream arqTabelaCnUfGmt(tabelaCnUfGmt.toStdString());

    if(arqTabelaCnUfGmt.is_open())
    {
        string strLinhaArq;
        for(unsigned int i = 1; getline(arqTabelaCnUfGmt, strLinhaArq); ++i)
        {
            if (i != 1)
            {
                opmm::StringCsv strCsv(strLinhaArq);
                mapCnUf.insert({strCsv.getStrItemStringSplitted(0), strCsv.getStrItemStringSplitted(1)});
                mapCnGmt.insert({strCsv.getStrItemStringSplitted(0), string(strCsv.getStrItemStringSplitted(2),0,2)});
            }
        }
        arqTabelaCnUfGmt.close();
    }
    else
    {
        qDebug() << "Impossível abrir arquivo!";
    }

//    for(mapStrStr::iterator itMap = mapCnUf.begin(); itMap != mapCnUf.end(); ++itMap)
//    {
//        qDebug() << QString::fromStdString(itMap->first) << "\t" << QString::fromStdString(itMap->second);
//    }

//    for(mapStrStr::iterator itMap = mapCnGmt.begin(); itMap != mapCnGmt.end(); ++itMap)
//    {
//        qDebug() << QString::fromStdString(itMap->first) << "\t" << QString::fromStdString(itMap->second);
//    }



    //Indo Através dos arquivos
    for(QStringList::iterator itList = inCsvFiles.begin(); itList != inCsvFiles.end(); ++itList)
    {
        string fileIn;
        fileIn = inDir.absoluteFilePath(*itList).toStdString();
//        qDebug() << QString::fromStdString(inFileName);

        string fileOut;
        fileOut = outDir.absolutePath().toStdString() + "/pmt_cleanUp_" + (*itList).toStdString();

//        qDebug() << QString::fromStdString(outFileName);

        opmm::pre_PMT_rule(fileIn, fileOut);
    }


    return 0;
}

