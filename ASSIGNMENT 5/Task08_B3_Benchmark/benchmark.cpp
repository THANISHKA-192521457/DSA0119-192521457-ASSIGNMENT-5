#include <chrono>
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include <string>
struct Bill { int type; double a, b; };
struct Base {
    virtual ~Base() = default;
    virtual double total() const = 0;
};
struct OP : Base {
    double a,b; OP(double x,double y):a(x),b(y){}
    double total() const override { return a+b; }
};
struct IP : Base {
    double a,b; IP(double x,double y):a(x),b(y){}
    double total() const override { return a+b; }
};
template<class F> double timeMs(F f) {
    auto start=std::chrono::steady_clock::now();
    volatile double sink=f();
    auto end=std::chrono::steady_clock::now();
    (void)sink;
    return std::chrono::duration<double,std::milli>(end-start).count();
}
int main(int argc,char**argv) {
    std::size_t n = argc>1 ? std::stoull(argv[1]) : 1000000;
    std::vector<Bill> sw; sw.reserve(n);
    std::vector<std::unique_ptr<Base>> poly; poly.reserve(n);
    for(std::size_t i=0;i<n;++i) {
        double x=100.0+(i%17), y=50.0+(i%11);
        sw.push_back({int(i%2),x,y});
        if(i%2) poly.push_back(std::make_unique<IP>(x,y));
        else poly.push_back(std::make_unique<OP>(x,y));
    }
    double tSwitch=timeMs([&]{
        double s=0; for(const auto& b:sw)
            switch(b.type){case 0:s+=b.a+b.b;break;case 1:s+=b.a+b.b;break;}
        return s;
    });
    double tVirtual=timeMs([&]{
        double s=0; for(const auto& b:poly) s+=b->total();
        return s;
    });
    std::cout<<"Bills: "<<n<<"\nSwitch total time (ms): "<<tSwitch
             <<"\nVirtual total time (ms): "<<tVirtual<<"\n";
}
