#ifndef TUPLE
#define TUPLE

#include <vector>

class Tuple {
private:
    std::vector<std::string> values;
public:
    bool operator< (const Tuple &rhs) const {
        return values < rhs.values;
    }

    
};

#endif