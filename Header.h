#ifndef HEADER
#define HEADER

#include <iostream>
#include <vector>
#include <string>

class Header {
    public:
        // Set attributes
        Header (std::vector<std::string> attributes) : attributes(attributes) {}
        
        // attributes helper functions
        int size();
        void addAttribute(std::string attribute);
        std::string findAttribute(int index);

    private:
        // Vector of attributes
        std::vector<std::string> attributes;
};

#endif