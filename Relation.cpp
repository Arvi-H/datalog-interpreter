#include "Relation.h"

// Helper Functions
std::string Relation::getName() {
    return Relation::name;
}

void Relation::addTuple(Tuple t) {
    Relation::tuples.insert(t);
}

void Relation::setTuples(std::set<Tuple> tuples) {
    this->tuples = tuples;
}

// Relational Algebra
Relation Relation::select(int columnIndex, std::string value) {
    Relation newRelation(Relation::name, Relation::columnNames);

    for (Tuple tuple : tuples) {
        if (tuple.findValue(columnIndex) == value) {
            newRelation.addTuple(tuple);
        }
    }

    return newRelation;
}

Relation Relation::select(int columnIndex1, int columnIndex2) {
    Relation newRelation(Relation::name, Relation::columnNames);

    for (Tuple tuple : tuples) {
        if (tuple.findValue(columnIndex1) == tuple.findValue(columnIndex2)) {
            newRelation.addTuple(tuple);
        }
    }

    return newRelation;
}

// TODO: Delete pointer 
Relation Relation::project(std::vector<int> columnsToProject) {
    Relation* newRelation;
    Header newHeader;

    // Update columnNames with the selcted columns (passed in the function)
    for (auto i : columnsToProject) {
        newHeader.addAttribute(Relation::columnNames.findAttribute(i));
    }
    
    newRelation = new Relation(Relation::name, newHeader);  

    // Update rows at the selcted columns (passed in the function)
    for (auto tuple : tuples) {
        Tuple newTuple;

        for (auto i : columnsToProject) {
            newTuple.addValue(tuple.findValue(i));
        }

        newRelation->addTuple(newTuple);
    }
}

Relation Relation::rename(std::vector<std::string> newColumnNames) {
    // Rename old columns 
    Header columnNames(newColumnNames);
    
    Relation newRelation(Relation::name, Relation::columnNames);
    newRelation.setTuples(tuples);
    
    return newRelation;
}