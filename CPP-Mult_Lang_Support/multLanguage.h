#pragma once
#include <map>
#include "tinyxml2.h"


#define WINDOWS_PLATFORM 0x001 //windows platform
#define LINUX_PLATFORM 0x002 //linux platform
#define CURRENT_PLATFORM WINDOWS_PLATFORM //current platform

#if (CURRENT_PLATFORM == WINDOWS_PLATFORM)
#include <Windows.h>
#include <Winnls.h>
#pragma comment(lib,"Kernel32.lib") //windows header
#elif (CURRENT_PLATFORM == LINUX_PLATFORM)
#include "iconv.hpp"// coding file
#endif

//singleton class for mult-language
class multLanguage
{
public:

	//language code
	enum Language
	{
		os_lang,// operator system's language
		en_US, //English
		zh_CN,//Chinese
		ru_RU,//Russian
		ko_KR,//Korean
		ja_PE,//Japanese
		fr_FR,//French
		es_ES,//Spanish
		de_DE//German
		//and so on
	};

	//get instance
	static multLanguage* getInstance();

	//destroy instance
	static void destroyInstance();

	//init data, if it dosen't success, it will return false
	bool init();

	//return the code of current language
	char* getCurrentLanguageCode();

	//set current language with enum Language
	void setCurrentLanguage(Language lang);

	//search string by key
	std::string getString(char* key);

private:
	//Constructor. It's private.
	multLanguage();

	//return operator system's enum language object
	Language getOSLanguage();

	//return the xml file's relative path
	std::string getFileName();
	
#if (CURRENT_PLATFORM == LINUX_PLATFORM)
	//if you use linux, you should turn ANSI into UTF8 by using this function
	std::string transform(std::string str);
#endif

	// current language
	Language m_lang;

#if (CURRENT_PLATFORM == WINDOWS_PLATFORM)
	//A map object which contains the enum of language code in windows.
	std::map<LANGID, Language> m_table;
#elif (CURRENT_PLATFORM == LINUX_PLATFORM)
	//A map object which contains the enum of language code in linux.
	std::map<std::string, Language> m_table;
#endif

	//get the string by language enum
	std::map<Language, std::string> m_code;

	//instance
	static multLanguage* m_ins;
};