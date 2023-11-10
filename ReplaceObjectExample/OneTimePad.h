#ifndef ONETIMEPAD_H
#define ONETIMEPAD_H


#include <vector>

class OneTimePad {

public:
    static OneTimePad* getInstance();

    void regenerateOTP(const std::vector<int>& newOTP);

    std::vector<int> getOTP();
private:
    static OneTimePad* instance;
    std::vector<int> otp;  // Private variable to store the OTP
    OneTimePad(){

    }

};


#endif // ONETIMEPAD_H
