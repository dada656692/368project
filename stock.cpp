///////////////////////////////////////////////////////////////////////////////
// File Name:      stock.cpp
//
// Author:         Haoda Zhang; Yijie Wang
// CS email:       haoda@cs.wisc.edu; yijiew@cs.wisc.edu
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "stock.hpp"

#include <string>
#include <vector>

int stock::numStocks = 0;

stock::stock(std::string companyName,
			 int publicDate,
             const std::vector<double> &lastWeekPrices,
             double todayPrice,
             std::string Rating,
             std::string Recommendation) : investment(companyName,
            										  publicDate,
            										  lastWeekPrices,
           											  todayPrice) {
	stock::Rating = Rating;
	stock::Recommendation = Recommendation;
	++stock::numStocks;
}

std::string stock::getRating() {
	return stock::Rating;
}

std::string stock::getRecommendation() {
	return stock::Recommendation;
}

double stock::getProfit() {
	double percentageofProfit = 0;
	for (std::vector<double>::const_iterator it = investment::getLastWeekPrices().begin(); 
		 it != investment::getLastWeekPrices().end(); ++it) { 
		 return (investment::getTodayPrice() - *it) / *it;
	}
}

std::string stock::getGrade() {
	double passScore = 0.05;
	double t = getProfit();
	if (t >= passScore) {
		return "Good Return";
	} else {
		return "Bad Return";
	}
}

int stock::getNumStocks() {
	return stock::numStocks;
}
                     			 