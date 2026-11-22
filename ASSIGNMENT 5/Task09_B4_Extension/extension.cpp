#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
class Bill {
public: virtual ~Bill()=default; virtual double total() const=0;
};
class OutPatientBill : public Bill {
    double consult, tests;
public: OutPatientBill(double c,double t):consult(c),tests(t){}
    double total() const override{return consult+tests;}
};
// New bill type added without modifying existing classes.
class EmergencyBill : public Bill {
    double base, hourly; int hours;
public: EmergencyBill(double b,double h,int hrs):base(b),hourly(h),hours(hrs){}
    double total() const override{return base+hourly*hours;}
};
class Payer {
public: virtual ~Payer()=default; virtual double covered(const Bill&) const=0;
};
class SelfPay : public Payer {
public: double covered(const Bill& b) const override{return b.total();}
};
// New payer type added without modifying existing classes.
class CorporatePayer : public Payer {
    double percentage;
public: explicit CorporatePayer(double p):percentage(p){}
    double covered(const Bill& b) const override{return b.total()*percentage/100.0;}
};
int main(){
    EmergencyBill emergency(1000,250,3);
    CorporatePayer corporate(80);
    std::cout<<"Emergency total: "<<emergency.total()<<'\n';
    std::cout<<"Corporate coverage: "<<corporate.covered(emergency)<<'\n';
}
