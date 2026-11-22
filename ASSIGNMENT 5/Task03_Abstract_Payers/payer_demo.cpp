#include <iostream>
#include <memory>
#include <string>
#include <vector>
class Bill {
public:
    virtual ~Bill() = default;
    virtual double total() const = 0;
};
class OutPatientBill : public Bill {
    double consultation, tests;
public:
    OutPatientBill(double c, double t) : consultation(c), tests(t) {}
    double total() const override { return consultation + tests; }
};
class Payer {
public:
    virtual ~Payer() = default;
    virtual double amountCovered(const Bill& b) const = 0;
    virtual std::string name() const = 0;
};
class SelfPay : public Payer {
public:
    double amountCovered(const Bill& b) const override { return b.total(); }
    std::string name() const override { return "SelfPay"; }
};
class Insurance : public Payer {
    double limit, copayPercent;
public:
    Insurance(double l, double c) : limit(l), copayPercent(c) {}
    double amountCovered(const Bill& b) const override {
        const double eligible = std::min(b.total(), limit);
        return eligible * (1.0 - copayPercent / 100.0);
    }
    std::string name() const override { return "Insurance"; }
};
class GovernmentScheme : public Payer {
    double packageRate;
public:
    explicit GovernmentScheme(double r) : packageRate(r) {}
    double amountCovered(const Bill& b) const override {
        return std::min(b.total(), packageRate);
    }
    std::string name() const override { return "GovernmentScheme"; }
};
// Extension example: add a new derived class without modifying existing classes.
class CorporatePayer : public Payer {
    double discountPercent;
public:
    explicit CorporatePayer(double d) : discountPercent(d) {}
    double amountCovered(const Bill& b) const override {
        return b.total() * discountPercent / 100.0;
    }
    std::string name() const override { return "CorporatePayer"; }
};
int main() {
    OutPatientBill bill(500, 1200);
    std::vector<std::unique_ptr<Payer>> payers;
    payers.push_back(std::make_unique<SelfPay>());
    payers.push_back(std::make_unique<Insurance>(5000, 20));
    payers.push_back(std::make_unique<GovernmentScheme>(1500));
    payers.push_back(std::make_unique<CorporatePayer>(70));
    for (const auto& p : payers)
        std::cout << p->name() << ": " << p->amountCovered(bill) << '\n';
}
