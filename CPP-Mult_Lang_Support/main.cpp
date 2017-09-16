#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "multLanguage.h"
#include "tinyxml2.h"

void pause()//pause for linux&windows
{
#if (CURRENT_PLATFORM == WINDOWS_PLATFORM)
	system("pause");
#elif (CURRENT_PLATFORM == LINUX_PLATFORM)
	getchar();
#endif
}

int main()
{
	multLanguage::getInstance()->setCurrentLanguage(multLanguage::Language::ru_RU);//set language
	std::string str = multLanguage::getInstance()->getString("wow");//get string whose key is "wow"
	std::cout << str.c_str() << std::endl;//print the result

	multLanguage::getInstance()->setCurrentLanguage(multLanguage::Language::es_ES);
	std::cout << multLanguage::getInstance()->getCurrentLanguageCode() << std::endl;//print the language code

	pause();
	multLanguage::destroyInstance();//destroy the instance
	return 0;
}