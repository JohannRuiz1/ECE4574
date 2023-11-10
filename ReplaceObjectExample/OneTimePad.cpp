#include "OneTimePad.h"

#include <iostream>
#include <vector>
#include <mutex>

OneTimePad* OneTimePad::instance = nullptr;

OneTimePad* OneTimePad::getInstance() {
    static std::mutex mutex;
    std::lock_guard<std::mutex> lock(mutex);

    if (instance == NULL) {
        instance = new OneTimePad();
    }

    return instance;
}

std::vector<int> OneTimePad::getOTP() {
    return otp;
}

void OneTimePad::regenerateOTP(const std::vector<int>& newOTP) {
    instance->otp = newOTP;
}

