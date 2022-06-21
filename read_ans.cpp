//##2.read_ans.cpp
#include <iostream>
#include <fstream>

using namespace std;

struct trade {
    int stk_code;
    int bid_id;
    int ask_id;
    double price;
    int volume;
}__attribute__((packed));

int main() {
    int lines = 10000;
    struct trade* t1 = new struct trade[lines];
    struct trade* t2 = new struct trade[lines];
	
    std::ifstream infile1("/test_data/100x1000x1000/trade5",std::ios::in | std::ios::binary);
    std::ifstream infile2("/test_data/100x10x10/trade5",std::ios::in | std::ios::binary);
    infile1.read((char *)t1, sizeof(trade) * lines);
    infile1.close();
    infile2.read((char *)t2, sizeof(trade) * lines);
    infile2.close();
	
    int L = 0;
    int xx = 2000;
    for(int i = L; i < L + xx; ++i){
        trade tmp1 = *(t1 + i);
        trade tmp2 = *(t2 + i);
		
        if (tmp1.volume != tmp2.volume || tmp1.bid_id != tmp2.bid_id || tmp1.ask_id != tmp2.ask_id ||i % 100 == 0) {
            printf("%d %d %d %lf %d\n",
            (t1+i)->stk_code, (t1+i)->bid_id, (t1+i)->ask_id,
            (t1+i)->price, (t1+i)->volume);
			
            printf("%d %d %d %lf %d\n",
            (t2+i)->stk_code, (t2+i)->bid_id, (t2+i)->ask_id,
            (t2+i)->price, (t2+i)->volume);
        }
    }
    return 0;
}
