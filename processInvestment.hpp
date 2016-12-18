///////////////////////////////////////////////////////////////////////////////
// File Name:      processInvestment.hpp
//
// Author:         Haoda Zhang; Yijie Wang
// CS email:       haoda@cs.wisc.edu; yijiew@cs.wisc.edu
///////////////////////////////////////////////////////////////////////////////

#ifndef PROJECT_PROCESSINVESTMENT_HPP
#define PROJECT_PROCESSINVESTMENT_HPP

#include <fstream>
#include <functional>
#include <vector>

#include "option.hpp"
#include "stock.hpp"

static const int max_assignments = 7;

static const char dlm = ',';


void fillInvestments(std::ifstream &inFile,
                  std::vector<option> &gstudents,
                  std::vector<stock> &ugstudents);

void computeStatistics(std::vector<std::reference_wrapper<investment>> &students);

#endif 