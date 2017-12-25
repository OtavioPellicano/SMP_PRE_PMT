//#pragma once
#ifndef STRINGCSV_H
#define STRINGCSV_H

#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <exception>

namespace opmm {

	class StringCsv
	{
	public:
		StringCsv();
		StringCsv(std::string str);

		~StringCsv();

		std::string str() const;
		void setStr(const std::string &str);

		void printVectorStringSplitted();
		void printVectorItemStringSplitted(const size_t &pos);

		std::vector<std::string> vectorStrSplitted() const;

		std::string getStrItemStringSplitted(const size_t &pos);
		void setStrItemStringSplitted(const size_t &pos, const std::string strValor);

        std::string getStrItemStringSplittedRange(const size_t &pos1, const size_t &pos2);

		unsigned short getStrCsvSize();

	private:
        const std::string PARAMETRO_INEXISTENTE = "$PI$";


		std::string mStr;
		std::vector<std::string> mVectorStrSplitted;
		unsigned short mVectorStrSplittedSize;
		void splitString();

        void splitString2();

        void splitString3();

	};


}

#endif // STRINGCSV_H
