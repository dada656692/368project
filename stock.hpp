///////////////////////////////////////////////////////////////////////////////
// File Name:      stock.hpp
//
// Author:         Haoda Zhang; Yijie Wang
// CS email:       haoda@cs.wisc.edu; yijiew@cs.wisc.edu
///////////////////////////////////////////////////////////////////////////////

#ifndef A3_UNDERGRADSTUDENT_HPP
#define A3_UNDERGRADSTUDENT_HPP

#include "investment.hpp"

#include <string>
#include <vector>

class stock : public investment {
private:
    std::string Rating;
    std::string Recommendation;
    static int numStocks;

public:
    stock(std::string companyName,
          int publicDate,
          const std::vector<double> &lastWeekPrices,
          double todayPrice,
          std::string Rating,
          std::string Recommendation);

    std::string getRating();

    std::string getRecommendation();

    static int getNumStocks();

    virtual double getProfit() override;

    virtual std::string getGrade() override;
};

#endif 