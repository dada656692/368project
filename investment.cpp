///////////////////////////////////////////////////////////////////////////////
// File Name:      investment.cpp
//
// Author:         Haoda Zhang; Yijie Wang
// CS email:       haoda@cs.wisc.edu; yijiew@cs.wisc.edu
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "investment.hpp"

int investment::numInvestments = 0;

investment::investment (std::string companyName,
            			int publicDate,
            			const std::vector<double> &lastWeekPrices,
            			double todayPrice) {
	investment::companyName = companyName;
	investment::publicDate = publicDate;
	investment::lastWeekPrices = lastWeekPrices;
	investment::todayPrice = todayPrice;
	++investment::numInvestments;
}


std::string investment::getCompanyName() {
	return investment::companyName;
}

int investment::getPublicDate() {
	return investment::publicDate;
}

const std::vector<double> &investment::getLastWeekPrices() {
	return investment::lastWeekPrices;
}

double investment::getTodayPrice() {
	return investment::todayPrice;
}


int investment::getNumInvestments() {
    return investment::numInvestments;
}


            	  