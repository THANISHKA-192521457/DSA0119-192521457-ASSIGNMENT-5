#include <iostream>
#include <stdexcept>
#include <string>
class BillingError : public std::runtime_error {
public: using std::runtime_error::runtime_error;
};
class InvalidCharge : public BillingError {
public: using BillingError::BillingError;
};
class ClaimError : public BillingError {
public: using BillingError::BillingError;
};
double validateBill(double amount) {
    if (amount < 0) throw InvalidCharge("negative charge");
    return amount;
}
double approveClaim(double amount, double cover) {
    validateBill(amount);
    if (cover < 0) throw InvalidCharge("negative cover");
    if (amount > cover) throw ClaimError("claim exceeds cover");
    return amount;
}
int main() {
    for (double amount : {1200.0, -5.0, 6000.0}) {
        try {
            std::cout << "approved " << approveClaim(amount, 5000) << '\n';
        } catch (const BillingError& e) {
            std::cout << "billing error: " << e.what() << '\n';
        }
    }
}
