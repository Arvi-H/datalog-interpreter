#include "Header.h"

int Header::size() {
    return attributes.size();
}

void Header::addAttribute(std::string attribute) {
    attributes.push_back(attribute);
}

std::string Header::findAttribute(int index) {
    if (index > attributes.size()) {
        throw "Out of Bounds";
    } 

    return attributes.at(index);
}
