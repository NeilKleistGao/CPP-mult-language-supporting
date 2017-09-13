#include "multLanguage.h"
#include <assert.h>

multLanguage* multLanguage::m_ins = NULL;

multLanguage::multLanguage()
{

}

multLanguage* multLanguage::getInstance()
{
	if (m_ins == NULL)
	{
		m_ins = new(std::nothrow)multLanguage();

		if (m_ins && m_ins->init())
		{
			return m_ins;
		}
		else
		{
			delete m_ins;
			m_ins = NULL;
			assert(0, "Memory Error: Can't init instance.");
			return NULL;
		}
	}
	else
	{
		return m_ins;
	}
}

void multLanguage::destroyInstance()
{
	delete m_ins;
	m_ins = NULL;
}

char* multLanguage::getCurrentLanguageCode()
{
	return const_cast<char*>(this->m_code[this->m_lang].c_str());
}

void multLanguage::setCurrentLanguage(multLanguage::Language lang = multLanguage::Language::os_lang)
{
	this->m_lang = lang;

	if (lang == multLanguage::Language::os_lang)
	{
		this->m_lang = this->getOSLanguage();
	}
}

multLanguage::Language multLanguage::getOSLanguage()
{
#if (CURRENT_PLATFORM == WINDOWS_PLATFORM)
	LANGID code = GetSystemDefaultLangID();
	return this->m_table[code];
#elif (CURRENT_PLATFORM == LINUX_PLATFORM)
	std::string lang = std::getenv("LANG");
	return this->m_table[lang];
#endif
}

char* multLanguage::getFileName()
{
	std::string name = m_code[m_lang];
	name += ".xml";
	return const_cast<char*>(name.c_str());
}

char* multLanguage::getString(char* key)
{
	return "rua!";
}

bool multLanguage::init()
{
#if (CURRENT_PLATFORM == WINDOWS_PLATFORM)
	m_table[0x0804] = multLanguage::Language::zh_CN;
	m_table[0x0409] = multLanguage::Language::en_US;
	m_table[0x0419] = multLanguage::Language::ru_RU;
	m_table[0x0412] = multLanguage::Language::ko_KR;
	m_table[0x0411] = multLanguage::Language::ja_PE;
	m_table[0x040c] = multLanguage::Language::fr_FR;
	m_table[0x0c0a] = multLanguage::Language::es_ES;
	m_table[0x0407] = multLanguage::Language::de_DE;
#elif (CURRENT_PLATFORM == LINUX_PLATFORM)
	m_table["zh_CN"] = multLanguage::Language::zh_CN;
	m_table["en_US"] = multLanguage::Language::en_US;
	m_table["ru_RU"] = multLanguage::Language::ru_RU;
	m_table["ko_KR"] = multLanguage::Language::ko_KR;
	m_table["ja_PE"] = multLanguage::Language::ja_PE;
	m_table["fr_FR"] = multLanguage::Language::fr_FR;
	m_table["es_ES"] = multLanguage::Language::es_ES;
	m_table["de_DE"] = multLanguage::Language::de_DE;
#endif

	m_code[en_US] = "en_US";
	m_code[zh_CN] = "zh_CN";
	m_code[ru_RU] = "ru_RU";
	m_code[ko_KR] = "ko_KR";
	m_code[ja_PE] = "ja_PE";
	m_code[fr_FR] = "fr_FR";
	m_code[es_ES] = "es_ES";
	m_code[de_DE] = "de_DE";

	this->m_lang = this->getOSLanguage();
	this->m_max = 8;

	return true;
}