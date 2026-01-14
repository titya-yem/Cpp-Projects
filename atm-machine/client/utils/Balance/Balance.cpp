#include "Balance.hpp"

void Login::setTotalUSD(const float &usd)
{
    // will fetch data from db of user by id from Balance table
    this->totalUSD = totalUSD;
}

float Login::getTotalUSD(const float &usd) const
{
    return totalUSD;
}
