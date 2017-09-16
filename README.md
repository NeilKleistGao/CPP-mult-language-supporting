# C++ mult-language supporting
## English
Developed By NeilKleistGao<br/>
Powered By tinyXML<br/>
Your c++ program can use mult-language with C++ mult-language supporting.You should add this line before you use it:<br/>
```c++
#include "multLanguage.h"
```
<br/>
The class multLanguage is a singleton class.You can use it as follow:<br>
```c++
multLanguage::getInstance();
multLanguage::destroyInstance();
```
<br/>
You can set language you want.If you don't,it will use operator system's language:<br/>
```c++
multLanguage::getInstance()->setCurrentLanguage(multLanguage::Language::ru_RU);
std::cout << multLanguage::getInstance()->getCurrentLanguageCode() << std::endl;
```
<br/>
multLanguage::Language is an enum class, and you can set your language by using this.There are only 8 languages as default.If you are going to add more languages, you should add in enum and the init function in cpp file:
```c++
m_table[0x0407] = multLanguage::Language::de_DE;//#if (CURRENT_PLATFORM == WINDOWS_PLATFORM)
m_table["de_DE"] = multLanguage::Language::de_DE;//#elif (CURRENT_PLATFORM == LINUX_PLATFORM)
m_code[de_DE] = "de_DE";//both
```
<br/>
`0x0407` is the code of `GetSystemDefaultLangID();` in windows.You may search some information on Internet.
If you use linux, you can use string instead.<br/>
After setting all properties, you can use function `std::string getString(char* key);` to get string:<br/>
```c++
std::string str = multLanguage::getInstance()->getString("wow");
std::cout << str.c_str() << std::endl;
```
<br/>
So far you may write xml file by yourself and put them in directory where exe file is.You can also change the directory in cpp file.The file name is like this:`zh_CN.xml`.Below is the example of form of xml file:
 ```xml
<?xml version="1.0" encoding="UTF-8"?>
<wow>Ай-ай-ай-ай-ай, что сейчас произошло!</wow>
```
<br/>
The file should be coded in ANSI.<br/>

---------
## 中文
开发者：NeilKleistGao<br/>
使用tinyXML<br/>
你可以使用C++ mult-language supporting来使你的C++程序支持多种语言。使用前你需要添加：<br/>
```c++
#include "multLanguage.h"
```
<br/>
其中multLanguage是单例类，你可以像使用其它单例类一样使用它：<br/>
```c++
multLanguage::getInstance();
multLanguage::destroyInstance();
```
<br/>
你可以设置你需要使用的语言，默认如果你不设置，我们将使用你的系统语言，也可以获取你当前使用的语言代码：<br/>
```c++
multLanguage::getInstance()->setCurrentLanguage(multLanguage::Language::ru_RU);
std::cout << multLanguage::getInstance()->getCurrentLanguageCode() << std::endl;
```
<br/>
multLanguage::Language是一个枚举类，你可以用它设定你想要的语言。默认的语言只有8种。如果你希望添加其它语言，可以直接在头文件中的枚举类加入，并且修改cpp文件中的init函数：
```c++
m_table[0x0407] = multLanguage::Language::de_DE;//#if (CURRENT_PLATFORM == WINDOWS_PLATFORM)
m_table["de_DE"] = multLanguage::Language::de_DE;//#elif (CURRENT_PLATFORM == LINUX_PLATFORM)
m_code[de_DE] = "de_DE";//both
```
<br/>
`0x0407`为windows下的`GetSystemDefaultLangID();`函数的返回值。你可能需要查阅相关资料以了解你需要的数据。<br/>
linux下可以直接使用字符串表示。<br/>
全部设置完毕后，直接使用`std::string getString(char* key);`函数查询字符串：<br/>
```c++
std::string str = multLanguage::getInstance()->getString("wow");
std::cout << str.c_str() << std::endl;
```
<br/>
目前语言的xml文件依然需要自己写，文件直接放在exe目录下即可，也可以在cpp文件中修改目录。文件名默认为语言编码：例如中文文件名为：`zh_CN.xml`.俄语文件里面内容大致如下：<br/>
```xml
<?xml version="1.0" encoding="UTF-8"?>
<wow>Ай-ай-ай-ай-ай, что сейчас произошло!</wow>
```
<br/>
文件需要以ANSI编码。<br/>