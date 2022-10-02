#include <iostream>
#include <vector>
#include "csv.h"
#include <fstream>
using std::cout;
using std::cerr;
using std::endl;
using std::cin;
using std::string;
using std::ofstream;
using std::ifstream;
using std::vector;

class transaction {
public:
    double amount;
    std::string description;
    transaction() = default;
    transaction(double _amount, std::string _description) {
        this->amount = _amount;
        this->description = _description;
    }
};