#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Bill {
public:
    virtual ~Bill() = default;
    virtual double total() const = 0;
    virtual std::string type() const = 0;
};
class OutPatientBill : public Bill {
    double consultation, tests;
public:
    OutPatientBill(double c,double t):consultation(c),tests(t){}
    double total() const override{return consultation+tests;}
    std::string type() const override{return "OutPatient";}
};
class InPatientBill : public Bill {
    int days; double roomRate, procedures, medicines;
public:
    InPatientBill(int d,double r,double p,double m):days(d),roomRate(r),procedures(p),medicines(m){}
    double total() const override{return days*roomRate+procedures+medicines;}
    std::string type() const override{return "InPatient";}
};
class DayCareBill : public Bill {
    double packagePrice;
public:
    explicit DayCareBill(double p):packagePrice(p){}
    double total() const override{return packagePrice;}
    std::string type() const override{return "DayCare";}
};
class EmergencyBill : public Bill {
    double baseCharge,hourlyCharge; int hours;
public:
    EmergencyBill(double b,double h,int hrs):baseCharge(b),hourlyCharge(h),hours(hrs){}
    double total() const override{return baseCharge+hourlyCharge*hours;}
    std::string type() const override{return "Emergency";}
};
class Payer {
public:
    virtual ~Payer()=default;
    virtual double amountCovered(const Bill&) const=0;
    virtual std::string name() const=0;
};
class SelfPay : public Payer {
public:
    double amountCovered(const Bill& b) const override{return b.total();}
    std::string name() const override{return "SelfPay";}
};
class Insurance : public Payer {
    double limit, copayPercent;
public:
    Insurance(double l,double c):limit(l),copayPercent(c){}
    double amountCovered(const Bill& b) const override{
        return std::min(b.total(),limit)*(1.0-copayPercent/100.0);
    }
    std::string name() const override{return "Insurance";}
};
class GovernmentScheme : public Payer {
    double packageLimit;
public:
    explicit GovernmentScheme(double p):packageLimit(p){}
    double amountCovered(const Bill& b) const override{return std::min(b.total(),packageLimit);}
    std::string name() const override{return "GovernmentScheme";}
};
int main(){
    std::vector<std::unique_ptr<Bill>> bills;
    bills.push_back(std::make_unique<OutPatientBill>(500,1200));
    bills.push_back(std::make_unique<InPatientBill>(3,2500,40000,3000));
    bills.push_back(std::make_unique<DayCareBill>(18000));
    bills.push_back(std::make_unique<EmergencyBill>(2000,500,4));
    std::vector<std::unique_ptr<Payer>> payers;
    payers.push_back(std::make_unique<SelfPay>());
    payers.push_back(std::make_unique<Insurance>(50000,20));
    payers.push_back(std::make_unique<GovernmentScheme>(20000));
    for(const auto& b:bills){
        std::cout<<b->type()<<" total="<<b->total()<<'\n';
        for(const auto& p:payers)
            std::cout<<"  "<<p->name()<<" covers="<<p->amountCovered(*b)<<'\n';
    }
}
