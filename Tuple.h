#ifndef TUPLE
#define TUPLE

#include "Header.h"
#include <vector>
#include <string>
#include <sstream>

class Tuple {
public:
    Tuple (std::vector<std::string> values) : values(values) {}
    
    bool operator< (const Tuple &rhs) const {
        return values < rhs.values;
    }

    int size() {
        return values.size();
    }

    void addValue(std::string value) {
        values.push_back(value);
    }

    std::string findValue(int index) {
        if (index > values.size()) {
            throw "Ouf of bounds";
        }
        return values.at(index);
    }

    std::string toString(Header header) {
        std::stringstream out;
        std::string sep = "";
        for (unsigned i = 0; i < size(); i++) {
            std::string name = header.findAttribute(i);
            std::string value = findValue(i);
            out << sep << " " << name << "=" << value;
            sep = ",";
        }
        return out.str();
    }
       
private:
    std::vector<std::string> values;
};

#endif