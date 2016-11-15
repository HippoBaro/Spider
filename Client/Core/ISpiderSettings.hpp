//
// Created by etiennep on 11/8/16.
//

#ifndef SPIDER_CLIENT_ISPIDERSETTINGS_HPP
#define SPIDER_CLIENT_ISPIDERSETTINGS_HPP

#include <iostream>

class ISpiderSettings {
public:
	virtual std::string getUUID() = 0;
};

#endif //SPIDER_CLIENT_ISPIDERSETTINGS_HPP