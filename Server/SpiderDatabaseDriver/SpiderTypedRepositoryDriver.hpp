//
// Created by hippolyteb on 11/14/16.
//

#ifndef SPIDER_SERVER_SPIDERKEYVALUESTORETYPEDDRIVER_HPP
#define SPIDER_SERVER_SPIDERKEYVALUESTORETYPEDDRIVER_HPP

#include <string>
#include <bits/unique_ptr.h>
#include <vector>
#include "../Interfaces/Database/ISpiderKeyValueDatabaseDriver.hpp"

template <class Type>
class SpiderTypedRepositoryDriver {
private:
    std::unique_ptr<ISpiderKeyValueDatabaseDriver> _driver;

public:
    SpiderTypedRepositoryDriver(ISpiderKeyValueDatabaseDriver *driver) : _driver(driver) {}

    virtual std::vector<Type> GetSecondaryKeyElements(const std::string &key, const int64_t &start, const int64_t &len) {
        std::vector<Type> ret;

        for(auto const& value: _driver->GetSecondaryKeyElements(key, start, len))
        {
            Type temp;
            temp.ParseFromString(value);
            ret.push_back(temp);
        }
        return ret;
    }

    virtual void PushElement(const std::string &key, const Type &element) {
        _driver->PushElement(key, element.SerializeAsString());
    }
};

#endif //SPIDER_SERVER_SPIDERKEYVALUESTORETYPEDDRIVER_HPP
