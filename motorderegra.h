#ifndef MOTORDEREGRA_H
#define MOTORDEREGRA_H

#include <string>
#include <map>
#include <fstream>
#include <QDebug>
#include "StringCsv.h"
#include <vector>
#include <QDateTime>

using namespace std;

typedef map<string, string> mapStrStr;
typedef vector<opmm::StringCsv> vecStrCsv;
typedef vector<string> vecStr;

namespace opmm {
    void pre_PMT_rule(const string &fileIn, const string &fileOut);
}



#endif // MOTORDEREGRA_H
