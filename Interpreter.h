#ifndef INTERPRETER
#define INTERPRETER

#include <set>
#include <map>
#include <vector>
#include "DatalogProgram.h"
#include "Database.h"
#include "Relation.h"

class Interpreter {
    public:
        Interpreter(DatalogProgram program) : program(program) {}

    // Run Interpreter
        void start() {
            interpretSchemes();
            interpretFacts();
            interpretQueries();
        }

        void interpretSchemes() {
            for (Predicate scheme : program.getSchemes()) {
                Header header;
                
                for (Parameter p : scheme.getParameters()) {
                    header.addAttribute(p.getID());
                }
                
                database.addRelation(scheme.getID(), header);
            }   
        }

        void interpretFacts() {
            for (Predicate fact : program.getFacts()) {
                Tuple tuple;
                
                for (Parameter p : fact.getParameters()) {
                    tuple.addValue(p.getID());
                }
                
                database.addTuple(fact.getID(), tuple);
            }
        }

        void interpretQueries() {
            for (Predicate query : program.getQueries()) {
                std::cout << query.toString() << "?";
                Relation result = evaluatePredicate(query);
                if (result.getSetSize() == 0) {
                    std::cout << " " << "No" << std::endl;
                } else {
                    std::cout << " " << "Yes(" << result.getSetSize() << ")" << std::endl;
                }

                std::cout << result.toString();
            }
        }


        Relation evaluatePredicate(Predicate predicate) {
            Relation output = database.getRelation(predicate.getID());
            std::map<std::string, unsigned int> seen;
            std::vector<int> uniqueIndex;
            unsigned int col = 0;

            for (Parameter parameter : predicate.getParameters()) {
                std::string val = parameter.getID();
                
                if (parameter.isConstant()) {
                    output = output.select(col, parameter.getID());    // select type 1 (int, value)
                } else {
                    // seenBefore()
                    if (seen.count(val) > 0) {
                        output = output.select(col, seen.at(val));   // select type 2 (int, int)
                    // mark it as seen
                    } else {  
                        seen.insert({val, col});
                        uniqueIndex.push_back(col);
                    }
                }
                col++;
            }

            // rename
            auto iter = seen.begin();
            col = 0;
            while (iter != seen.end()) {
                output = output.rename(iter->second, iter->first);
                ++iter;
                ++col;
            }
            
            // project
            output = output.project(uniqueIndex);

            return output;
        }

    private:
        DatalogProgram program;
        Database database;
};

#endif