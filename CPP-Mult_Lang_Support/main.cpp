#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "multLanguage.h"

void pause()
{
#if (CURRENT_PLATFORM == WINDOWS_PLATFORM)
	system("pause");
#elif (CURRENT_PLATFORM == LINUX_PLATFORM)
	getchar();
#endif
}

int main()
{
	multLanguage::getInstance()->setCurrentLanguage(multLanguage::Language::es_ES);
	std::cout << multLanguage::getInstance()->getCurrentLanguageCode() << std::endl;

	pause();
	multLanguage::destroyInstance();
	return 0;
}