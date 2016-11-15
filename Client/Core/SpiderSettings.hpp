//
// Created by etiennep on 11/8/16.
//

#ifndef SPIDER_CLIENT_SPIDERSETTINGS_HPP
#define SPIDER_CLIENT_SPIDERSETTINGS_HPP

#include "ISpiderSettings.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <tchar.h>

class SpiderSettings : public ISpiderSettings {
private:
	std::string random_string(size_t length)
	{
		srand(time(NULL));
		auto randchar = []() -> char
		{
			const char charset[] =
				"0123456789"
				"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
				"abcdefghijklmnopqrstuvwxyz";
			const size_t max_index = (sizeof(charset) - 1);
			return charset[rand() % max_index];
		};
		std::string str(length, 0);
		std::generate_n(str.begin(), length, randchar);
		return str;
	}

public:
	std::string getUUID() override final {
		HKEY MyRegistryKey;
		std::string uuid;

		if (ERROR_SUCCESS != RegOpenKeyEx(HKEY_CURRENT_USER, _T("Software\\Spider"), 0, KEY_ALL_ACCESS, &MyRegistryKey))
		{
			DWORD dwDisposition = 0;
			RegCreateKeyEx(HKEY_CURRENT_USER, _T("Software\\Spider"), 0, NULL, 0, KEY_ALL_ACCESS, NULL, &MyRegistryKey, &dwDisposition);
			uuid = random_string(16);
			RegSetValueEx(MyRegistryKey, TEXT("UUID"), 0, REG_SZ, (LPBYTE)uuid.c_str(), strlen(uuid.c_str()) + 1);
		}
		else {
			DWORD dwType = REG_SZ;
			HKEY hKey = 0;
			char value[1024];
			DWORD value_length = 1024;
			RegQueryValueEx(MyRegistryKey, _T("UUID"), NULL, &dwType, (LPBYTE)&value, &value_length);
			uuid = value;
		}
		RegCloseKey(MyRegistryKey);
		return (uuid);
	}
};

#endif //SPIDER_CLIENT_SPIDERSETTINGS_HPP