///////////////////////////////////////////////////////////////////////////////
// File Name:      main.cpp
//
// Author:         Haoda Zhang; Yijie Wang
// CS email:       haoda@cs.wisc.edu; yijiew@cs.wisc.edu
//
// Description:    The main program for project.
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <functional>
#include <vector>

#include "option.hpp"
#include "processInvestment.hpp"
#include "stock.hpp"


int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cerr << "USAGE: " << argv[0] << " <investment.txt>" << std::endl;
        return 1;
    }
    
    std::ifstream inFile(argv[1]);
    if (!inFile.is_open()) {
        std::cerr << "Input file " << argv[1] << " cannot be opened!" << std::endl;
        return 1;
    }
	
    std::vector<option> options;
    std::vector<stock> stocks;

    fillInvestments(inFile, options, stocks);

    std::cout << "The total number of students in the class = "
              << investment::getNumInvestments() << std::endl << std::endl;

    std::vector<std::reference_wrapper<investment>> stocksRefs;
    for (auto it = stocks.begin(); it != stocks.end(); ++it) {
        stocksRefs.push_back(*it);
    }

    std::cout << "STOCK STATISTICS" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    computeStatistics(stocksRefs);

    std::vector<std::reference_wrapper<investment>> optionsRefs;
    for (auto it = options.begin(); it != options.end(); ++it) {
        optionsRefs.push_back(*it);
    }

    std::cout << "OPTION STATISTICS" << std::endl;
    std::cout << "---------------------------" << std::endl;
    computeStatistics(optionsRefs);

    return 0;
}