//##1.read_stock.cpp
#include <iostream>
#include <fstream>

using namespace std;

//交易
struct trade {
    int stk_code;
    int bid_id;
    int ask_id;
    double price;
    int volume;
}__attribute__((packed));   //不想要字节对齐的时候，可以在结构体声明当中，加上左边代码，可以做到让结构体按照紧凑排列的方式，占用内存。

//订单
struct order {
    int order_id;
    int price;
    int volume;
    unsigned char combined;
}__attribute__((packed));

int main() {
    int lines = 10000;
    struct order* t = new struct order[lines];
    std::ifstream infile("H:/test_data/100x10x10/trade3",std::ios::in | std::ios::binary);

    infile.read((char *)t, sizeof(order) * lines);
    infile.close();

    int L = 9310;
    for(int i = L; i < L + 20; ++i){
        unsigned char ch = (t + i) ->combined;
        int stk_code = (ch >> 4) & 15;
        int type = ch & 7;
        int dir = ((ch >> 3) & 1) ? 1 : 2;
        if (i % 1 == 0) printf("%d %d %d %d %d %d\n",
        stk_code, dir , 
        (t+i)->order_id, (t+i)->price, (t+i)->volume,
        type);
    }
    return 0;
}


























