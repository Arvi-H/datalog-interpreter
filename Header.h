#ifndef HEADER
#define HEADER

#include <iostream>
#include <vector>
#include <string>

class Header {
public:
    // Set attributes
    Header() = default;
    Header(std::vector<std::string> attributes) : columnNames(attributes) {}
    
    void addAttribute(std::string attribute) {
        columnNames.push_back(attribute);
    }
    
    std::string findAttribute(int index) {
        if (index > columnNames.size()) {
            throw "Out of Bounds";
        } 

        return columnNames.at(index);
    }
/*
    // attributes helper functions
    int size() {
        return attributes.size();
    }


*/

private:
    // Vector of attributes
    std::vector<std::string> columnNames;
};
 

#endif