#ifndef RELATION
#define RELATION

#include <string>
#include <set>
#include <sstream>
#include "Header.h"
#include "Tuple.h"

class Relation {
    public: 
        Relation() = default;
        Relation(std::string name, Header columnNames) : name(name), columnNames(columnNames) {}
       

        // Helper Functions
        std::string getName();
        void addTuple(Tuple t);
        void setTuples(std::set<Tuple> tuples);
        int getSetSize();
        std::string toString();

        // Relational Algebra
        Relation select(int columnIndex, std::string value);
        Relation select(int columnIndex1, int columnIndex2);
        Relation project(std::vector<int> columnsToProject);
        Relation rename(std::vector<std::string> newColumnNames);
        Relation rename(unsigned int colToRename, std::string newName);

    private:
        std::string name;
        Header columnNames;
        std::set<Tuple> tuples;
};

#endif