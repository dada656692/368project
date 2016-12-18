///////////////////////////////////////////////////////////////////////////////
// File Name:      option.cpp
//
// Author:         Haoda Zhang; Yijie Wang
// CS email:       haoda@cs.wisc.edu; yijiew@cs.wisc.edu
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "option.hpp"

int option::numOptions = 0;

option::option(std::string companyName,
    			int publicDate,
                const std::vector<double> &lastWeekPrices,
                double todayPrice,
                std::string strikePrice,
                std::string expirationDate) : investment(companyName,
            										  publicDate,
            										  lastWeekPrices,
           											  todayPrice) {
	option::strikePrice = strikePrice;
	option::expirationDate = expirationDate;
	++option::numOptions;
}

std::string option::getStrikePrice() {
	return option::strikePrice;
}

std::string option::getExpirationDate() {
	return option::expirationDate;
}

double option::getProfit() {
	double percentageofProfit = 0;
	for (std::vector<double>::const_iterator it = investment::getLastWeekPrices().begin(); 
		 it != investment::getLastWeekPrices().end(); ++it) { 
		 return (investment::getTodayPrice() - *it) / *it;
	}
}

std::string option::getGrade() {
	double passScore = 0.05;
	double t = getProfit();
	if (t >= passScore) {
		return "Good Return";
	} else {
		return "Bad Return";
	}
}

int option::getNumOptions() {
	return option::numOptions;
}