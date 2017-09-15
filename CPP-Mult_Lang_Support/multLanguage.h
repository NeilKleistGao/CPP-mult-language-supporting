#pragma once
#include <map>
#include "tinyxml2.h"


#define WINDOWS_PLATFORM 0x001
#define LINUX_PLATFORM 0x002
#define CURRENT_PLATFORM WINDOWS_PLATFORM

#if (CURRENT_PLATFORM == WINDOWS_PLATFORM)
#include <Windows.h>
#include <Winnls.h>
#pragma comment(lib,"Kernel32.lib")
#elif (CURRENT_PLATFORM == LINUX_PLATFORM)
#include "iconv.hpp"
#endif

class multLanguage
{
public:
	enum Language
	{
		os_lang,
		en_US, 
		zh_CN,
		ru_RU,
		ko_KR,
		ja_PE,
		fr_FR,
		es_ES,
		de_DE
	};

	static multLanguage* getInstance();
	static void destroyInstance();
	bool init();
	char* getCurrentLanguageCode();
	void setCurrentLanguage(Language lang);
	std::string getString(char* key);

private:
	multLanguage();
	Language getOSLanguage();
	std::string getFileName();
	//wchar_t* transform(const char* buff);
#if (CURRENT_PLATFORM == LINUX_PLATFORM)
	std::string transform(std::string str);
#endif

	Language m_lang;

#if (CURRENT_PLATFORM == WINDOWS_PLATFORM)
	std::map<LANGID, Language> m_table;
#elif (CURRENT_PLATFORM == LINUX_PLATFORM)
	std::map<std::string, Language> m_table;
#endif

	std::map<Language, std::string> m_code;
	
	int m_max;

	static multLanguage* m_ins;
};