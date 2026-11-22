#include <iostream>
#include <vector>
struct BillRecord { int type; double x,y; };
int main() {
    std::vector<BillRecord> data = {
        {0,500,1200},{1,2500,40000},{0,700,800},{1,1800,12000},
        {0,450,550},{1,3000,20000},{0,600,900},{1,2200,15000},
        {0,350,650},{1,1600,9000}
    };
    double switchTotal=0, virtualEquivalentTotal=0;
    for(const auto& b:data) {
        switch(b.type) {
            case 0: switchTotal += b.x+b.y; break;
            case 1: switchTotal += b.x*2+b.y; break;
        }
        // Same per-record formulas, representing the expected virtual total() result.
        virtualEquivalentTotal += (b.type==0 ? b.x+b.y : b.x*2+b.y);
    }
    std::cout<<"Switch total: "<<switchTotal<<"\nVirtual-interface total: "
             <<virtualEquivalentTotal<<"\nTotals agree: "
             <<(switchTotal==virtualEquivalentTotal ? "yes":"no")<<"\n";
}
