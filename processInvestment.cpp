///////////////////////////////////////////////////////////////////////////////
// File Name:      processInvestment.cpp
//
// Author:         Haoda Zhang; Yijie Wang
// CS email:       haoda@cs.wisc.edu; yijiew@cs.wisc.edu
///////////////////////////////////////////////////////////////////////////////

#include "processInvestment.hpp"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <stdlib.h>


void fillInvestments(std::ifstream &inFile,
                  std::vector<option> &options,
                  std::vector<stock> &stocks) {
                  
	std::string lines;   
    while (getline(inFile,lines)) {
    	std::stringstream ss(lines);
        std::string type;
        getline(ss, type, ',');
        if (type == "S") {
        	std::vector<double> lastWeekPrices;
        	std::string companyName;
			getline(ss, companyName, ',');
			std::string dateofPublic;
			getline(ss, dateofPublic, ',');
			int publicDate = std::stoi(dateofPublic);
			for (int i = 0; i < 7; ++i) {
				std::string dayPrice;
				getline(ss, dayPrice, ',');
				lastWeekPrices.push_back(atof(dayPrice.c_str()));
			}
			const std::vector<double> &constRefLastWeekPrices = lastWeekPrices;
			std::string todayP;
			getline(ss, todayP, ',');
			double todayPrice = atof(todayP.c_str());
			std::string rating;
			getline(ss, rating, ',');
			std::string recommendation;
			getline(ss, recommendation, ',');
			stock st(companyName, publicDate, constRefLastWeekPrices, 
							    todayPrice, rating, recommendation);
			stocks.push_back(st);
		}
		else {
			std::vector<double> lastWeekPrices;
        	std::string companyName;
			getline(ss, companyName, ',');
			std::string dateofPublic;
			getline(ss, dateofPublic, ',');
			int publicDate = std::stoi(dateofPublic);
			for (int i = 0; i < 7; ++i) {
				std::string dayPrice;
				getline(ss, dayPrice, ',');
				lastWeekPrices.push_back(atof(dayPrice.c_str()));
			}
			const std::vector<double> &constRefLastWeekPrices = lastWeekPrices;
			std::string todayP;
			getline(ss, todayP, ',');
			double todayPrice = atof(todayP.c_str());
			std::string strikePrice;
			getline(ss, strikePrice, ',');
			std::string expirationDate;
			getline(ss, expirationDate, ',');
			option op(companyName, publicDate, constRefLastWeekPrices, 
					      todayPrice, strikePrice, expirationDate);			
			options.push_back(op);
		}

 	}
 
}

void computeStatistics(std::vector<std::reference_wrapper<investment>> &investments) {

    int numOfStudents = 0;
    double totalProfit = 0;
    std::sort (investments.begin(), investments.end(), [] (investment &s1, investment &s2) 
    		  { return s1.getProfit() > s2.getProfit(); });
    for (auto it = investments.begin(); it != investments.end(); ++it) {
    	++numOfStudents;
    	totalProfit += it->get().getProfit();
    }
    
    std::cout << "Number of investments = " << numOfStudents << std::endl;
    std::cout << "The mean of the total profit percentage = " << totalProfit / numOfStudents << std::endl;
    std::cout << "The sorted list of investments (company name, profit, grade) " << 
    			 "in descending order of total:" << std::endl;
    for (auto it = investments.begin(); it != investments.end(); ++it) {
    	std::cout << it->get().getCompanyName() << ", ";
    	std::cout << it->get().getProfit() << ", ";
    	std::cout << it->get().getGrade() << std::endl;
    }
    std::cout << std::endl;
    
}
