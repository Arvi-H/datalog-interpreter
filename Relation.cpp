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

int Relation::getSetSize() {
    return tuples.size();
}

std::string Relation::toString() {
    std::stringstream out;
    for (Tuple t : Relation::tuples) {
        if (t.getTupleSize() > 0) {
            out << " " << t.toString(Relation::columnNames) << std::endl;
        }
    }
    
    return out.str();
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

Relation Relation::project(std::vector<int> columnsToProject) {
    Header newHeader;

    // Update columnNames with the selcted columns (passed in the function)
    for (auto i : columnsToProject) {
        newHeader.addAttribute(Relation::columnNames.findAttribute(i));
    }
    
    Relation newRelation(Relation::name, newHeader);  

    // Update rows at the selcted columns (passed in the function)
    for (auto tuple : tuples) {
        Tuple newTuple;

        for (auto i : columnsToProject) {
            newTuple.addValue(tuple.findValue(i));
        }

        newRelation.addTuple(newTuple);
    }

    return newRelation;
}

Relation Relation::rename(std::vector<std::string> newColumnNames) {
    Header columnNames(newColumnNames);
    
    Relation newRelation(Relation::name, columnNames);
    newRelation.setTuples(tuples);
    
    return newRelation;
}