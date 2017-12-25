
#include "StringCsv.h"

namespace opmm {

	StringCsv::StringCsv()
	{

	}

	StringCsv::StringCsv(std::string str)
	{
		setStr(str);
	}

	StringCsv::~StringCsv()
	{
		return;
	}

	std::string StringCsv::str() const
	{
		return mStr;
	}

	void StringCsv::setStr(const std::string &str)
	{
		mStr = str;
		mVectorStrSplitted.clear();
        splitString3();
        mVectorStrSplittedSize = mVectorStrSplitted.size();
	}

	void StringCsv::printVectorStringSplitted()
	{
        unsigned short pos = 0;
		for (std::vector<std::string>::iterator itVec = mVectorStrSplitted.begin(); itVec != mVectorStrSplitted.end(); ++itVec)
        {
            std::cout << "[" << pos++ << "] " << *itVec << std::endl;
		}
	}

	void StringCsv::printVectorItemStringSplitted(const size_t &pos)
	{
		std::cout << mVectorStrSplitted[pos] << std::endl;
	}

	std::vector<std::string> StringCsv::vectorStrSplitted() const
	{
		return mVectorStrSplitted;
	}

	std::string StringCsv::getStrItemStringSplitted(const size_t & pos)
	{
        if (pos < StringCsv::getStrCsvSize())
            return mVectorStrSplitted[pos];
        else
            return PARAMETRO_INEXISTENTE;

	}

	void StringCsv::setStrItemStringSplitted(const size_t & pos, const std::string strValor)
	{
        mVectorStrSplitted[pos] = strValor;
    }

    std::string StringCsv::getStrItemStringSplittedRange(const size_t &pos1, const size_t &pos2)
    {
        if ((pos1 > pos2) || pos2 >= StringCsv::getStrCsvSize())
        {
            return PARAMETRO_INEXISTENTE;
        }

        std::string strTemp("");
        for(size_t i = pos1; i <= pos2; ++i)
        {
            if(i != pos2)
                strTemp += mVectorStrSplitted[i] + ",";
            else
                strTemp += mVectorStrSplitted[i];
        }

        return strTemp;

    }

	unsigned short StringCsv::getStrCsvSize()
	{
		return mVectorStrSplittedSize;
	}


	void StringCsv::splitString()
	{
		std::string::iterator itStrBeginWord = mStr.begin();
		for (std::string::iterator itStrEndWord = mStr.begin(); itStrEndWord != mStr.end(); ++itStrEndWord)
		{
			if (itStrEndWord != mStr.end())
			{
				if (*itStrEndWord == ',' || *itStrEndWord == ';')
                {
					mVectorStrSplitted.push_back(std::string(itStrBeginWord, itStrEndWord));
					itStrBeginWord = itStrEndWord + 1;
				}
				else if (itStrEndWord == (mStr.end() - 1))
				{
					mVectorStrSplitted.push_back(std::string(itStrBeginWord, mStr.end()));
				}
			}
        }
    }

    void StringCsv::splitString2()
    {

        bool atualizouAspas = false;
        std::string::iterator itStrBeginWord = mStr.begin();
        for (std::string::iterator itStrEndWord = mStr.begin(); itStrEndWord < mStr.end(); ++itStrEndWord)
        {
            if (itStrEndWord != mStr.end())
            {
                if (*itStrEndWord == ',' || *itStrEndWord == ';')
                {
                    if (itStrEndWord + 1 != mStr.end())
                    {
                        if(*(itStrEndWord + 1) == '\"')
                        {
                            if(!(std::string(itStrBeginWord, itStrEndWord) == "\"\"" || std::string(itStrBeginWord, itStrEndWord) == "\""))
                            {
                                mVectorStrSplitted.push_back(std::string(itStrBeginWord, itStrEndWord));
                            }
                            else
                            {
                                mVectorStrSplitted.push_back("");
                            }
                            //mVectorStrSplitted.push_back(std::string(itStrBeginWord, itStrEndWord));
                            itStrBeginWord = ++itStrEndWord + 1;//para não pegar a aspas
                            while(*(++itStrEndWord) != '\"'){};
                            atualizouAspas = true;
                        }
                    }

                    if(atualizouAspas)
                    {
                        atualizouAspas = false;
                        if(std::string(itStrBeginWord, itStrEndWord) != "")
                        {
                            while(itStrEndWord < itStrBeginWord)    //atualizar se o último valor for vazio
                               ++itStrEndWord;

                            if(!(std::string(itStrBeginWord, itStrEndWord) == "\"\"" || std::string(itStrBeginWord, itStrEndWord) == "\""))
                            {
                                mVectorStrSplitted.push_back(std::string(itStrBeginWord, itStrEndWord));
                            }
                            else
                            {
                                mVectorStrSplitted.push_back("");
                            }

                            if((itStrEndWord + 1) != mStr.end())
                                ++itStrEndWord;

                            itStrBeginWord = itStrEndWord + 1;
                            if((itStrEndWord + 1) == mStr.end())
                                itStrEndWord -= 1;

                            continue;
                        }
                    }

                    while(itStrEndWord < itStrBeginWord)        //atualizar se o último valor for vazio
                        ++itStrEndWord;

                    if(!(std::string(itStrBeginWord, itStrEndWord) == "\"\"" || std::string(itStrBeginWord, itStrEndWord) == "\""))
                    {
                        mVectorStrSplitted.push_back(std::string(itStrBeginWord, itStrEndWord));
                    }
                    else
                    {
                        mVectorStrSplitted.push_back("");
                    }

                    itStrBeginWord = itStrEndWord + 1;
                    if((itStrEndWord + 1) == mStr.end())
                        itStrEndWord -= 1;
                }
                else if (itStrEndWord == (mStr.end() - 1))
                {
                    if(!(std::string(itStrBeginWord, itStrEndWord) == "\"\"" || std::string(itStrBeginWord, itStrEndWord) == "\""))
                    {
                        mVectorStrSplitted.push_back(std::string(itStrBeginWord, itStrEndWord));
                    }
                    else
                    {
                        mVectorStrSplitted.push_back("");
                    }
                }
            }
        }
    }

    void StringCsv::splitString3()
    {
        std::string::iterator itStrBeginWord = mStr.begin();
        for (std::string::iterator itStrEndWord = mStr.begin(); itStrEndWord < mStr.end(); ++itStrEndWord)
        {
            if (itStrEndWord != mStr.end())
            {
                if (*itStrEndWord == ',' || *itStrEndWord == ';')
                {
                    mVectorStrSplitted.push_back(std::string(itStrBeginWord, itStrEndWord));
                    itStrBeginWord = itStrEndWord + 1;
                    if(*itStrBeginWord  == '\"')
                    {
                        ++itStrEndWord;
                        while(*(++itStrEndWord) != '\"');
                        if(itStrEndWord == (mStr.end() - 1))
                        {
                            --itStrEndWord;
                            itStrBeginWord = itStrEndWord;
                        }
                    }
                }
                else if (itStrEndWord == (mStr.end() - 1))
                {
                    mVectorStrSplitted.push_back(std::string(itStrBeginWord, mStr.end()));
                }
            }
        }
    }

}
