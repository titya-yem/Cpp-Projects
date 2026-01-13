#ifndef UTILS_BALANCE_BALANCE_HPP
#define UTILS_BALANCE_BALANCE_HPP

class Login
{
public:
    void setTotalUSD(const float &usd);
    float getTotalUSD(const float &usd) const;

private:
    float totalUSD;
    int totalKHR;
};

#endif