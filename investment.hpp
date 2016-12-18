///////////////////////////////////////////////////////////////////////////////
// File Name:      investment.hpp
//
// Author:         Haoda Zhang; Yijie Wang
// CS email:       haoda@cs.wisc.edu; yijiew@cs.wisc.edu
///////////////////////////////////////////////////////////////////////////////

#ifndef PROJECT_INVESTMENT_HPP
#define PROJECT_INVESTMENT_HPP

#include <string>
#include <vector>

const int current_year = 2016;

class investment {
private:
    int id;
    std::string companyName;
    int publicDate;
    std::vector<double> lastWeekPrices;
    double todayPrice;
    static int numInvestments;

public:
    investment(std::string companyName,
            int publicDate,
            const std::vector<double> &lastWeekPrices,
            double todayPrice);

    std::string getCompanyName();

    int getPublicDate();

    const std::vector<double> &getLastWeekPrices();

    double getTodayPrice();

    static int getNumInvestments();

    virtual double getProfit() = 0;

    virtual std::string getGrade() = 0;
};

#endif 