#pragma once
#include <map>
#include "tinyxml2.h"

#if (CURRENT_PLATFORM == WINDOWS_PLATFORM)
#include <Windows.h>
#include <Winnls.h>
#pragma comment(lib,"Kernel32.lib")
#endif

#define WINDOWS_PLATFORM 0x001
#define LINUX_PLATFORM 0x002
#define CURRENT_PLATFORM WINDOWS_PLATFORM

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
	char* getString(char* key);

private:
	multLanguage();
	Language getOSLanguage();
	char* getFileName();

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