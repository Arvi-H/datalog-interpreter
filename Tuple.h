#ifndef TUPLE
#define TUPLE

#include "Header.h"
#include <vector>
#include <string>
#include <sstream>

class Tuple {
public:
    Tuple() = default;
    Tuple (std::vector<std::string> values) : rowValues(values) {}
    
    bool operator< (const Tuple &rhs) const {
        return rowValues < rhs.rowValues;
    }
    
    std::string findValue(int index) {
        if (index > rowValues.size()) {
            throw "Ouf of bounds";
        }
        return rowValues.at(index);
    }

    void addValue(std::string value) {
        rowValues.push_back(value);
    }
    
/*
    int size() {
        return values.size();
    }

    void addValue(std::string value) {
        values.push_back(value);
    }


    std::string toString(Header header) {
        std::stringstream out;
        std::string sep = "";
        for (unsigned i = 0; i < size(); i++) {
            out << sep << " " << header.findAttribute(i) << "=" << findValue(i);
            sep = ",";
        }
        return out.str();
    }
*/
       
private:
    std::vector<std::string> rowValues;
};

#endif