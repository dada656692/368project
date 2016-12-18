///////////////////////////////////////////////////////////////////////////////
// File Name:      option.hpp
//
// Author:         Haoda Zhang; Yijie Wang
// CS email:       haoda@cs.wisc.edu; yijiew@cs.wisc.edu
///////////////////////////////////////////////////////////////////////////////

#ifndef PROJECT_OPTION_HPP
#define PROJECT_OPTION_HPP

#include "investment.hpp"


class option : public investment {
private:
    std::string strikePrice;
    std::string expirationDate;
    static int numOptions;

public:
    option(std::string companyName,
    			int publicDate,
                const std::vector<double> &lastWeekPrices,
                double todayPrice,
                std::string strikePrice,
                std::string expirationDate);

    std::string getStrikePrice();

    std::string getExpirationDate();

    static int getNumOptions();

    virtual double getProfit() override;

    virtual std::string getGrade() override;
};

#endif 