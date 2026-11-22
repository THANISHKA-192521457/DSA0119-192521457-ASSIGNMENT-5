#include <chrono>
#include <iostream>
#include <stdexcept>
#include <vector>
int main(int argc,char**argv) {
    const int n=1000000;
    int invalidPercent=argc>1?std::stoi(argv[1]):1;
    std::vector<double> amounts(n,100.0);
    for(int i=0;i<n*invalidPercent/100;++i) amounts[i]=-1;
    auto start=std::chrono::steady_clock::now();
    int rejected=0;
    for(double x:amounts) if(x<0) ++rejected;
    auto mid=std::chrono::steady_clock::now();
    int caught=0;
    for(double x:amounts) {
        try { if(x<0) throw std::invalid_argument("negative"); }
        catch(const std::exception&) { ++caught; }
    }
    auto end=std::chrono::steady_clock::now();
    std::cout<<"Invalid percent: "<<invalidPercent<<"\nReturn-code ms: "
      <<std::chrono::duration<double,std::milli>(mid-start).count()
      <<"\nException ms: "<<std::chrono::duration<double,std::milli>(end-mid).count()
      <<"\nRejected: "<<rejected<<" caught: "<<caught<<"\n";
}
