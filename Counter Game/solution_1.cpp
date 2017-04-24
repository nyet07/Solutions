#include <cmath>
#include <utility>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <utility>

#define b0000 0x0
#define b0001 0x1
#define b0010 0x2
#define b0011 0x3
#define b0100 0x4
#define b0101 0x5
#define b0110 0x6
#define b0111 0x7
#define b1000 0x8
#define b1001 0x9
#define b1010 0xA
#define b1011 0xB
#define b1100 0xC
#define b1101 0xD
#define b1110 0xE
#define b1111 0xF

using namespace std;

using LWORD = long int;

bool is_power2(LWORD count){
   short int counter = 0;
   while(count){
       if(1 & count) ++counter;
       if(counter > 1) return false;
       count >>= 1;
   }
   return true;
}

LWORD left_most_bit(LWORD n){
    if(!n) return 0;
    LWORD ret = 1;
    while(n >>= 1){
        ret <<= 1;
    }
    return ret;
}

LWORD next_count(LWORD count){
    if(is_power2(count)){
        count /= 2;
    }
    else{
        int temp = left_most_bit(count);
        count -= temp;
    }
    
    return count;
}

std::pair<std::string, bool> louise = std::make_pair("Louise", true);
std::pair<std::string, bool> richard = std::make_pair("Richard", false);

void display_result();

void update(){
    if(louise.second == true) louise.second = false;
    else louise.second = true;
    
    if(richard.second == true) richard.second = false;
    else richard.second = true;
}

void display_result(){
    if(louise.second == true)
        cout << louise.first;
    else
        cout << richard.first;
    cout << endl;
}

void reset(){
    louise.second = true;
    richard.second = false;
}

void exec(LWORD count){
    while((count = next_count(count)) > 1){
        update();
    }
    display_result();
    reset();
}

void is_power2_test(){
    cout << "---------IS_POWER2_TEST-------------" << endl;
    cout << "2 : " << is_power2(2) << endl;
    cout << "3 : " << is_power2(3) << endl;
    cout << "7 : " << is_power2(7) << endl;
    cout << "17 : " << is_power2(17) << endl;
    cout << "32 : " << is_power2(32) << endl;
    cout << "512 : " << is_power2(512) << endl;
    cout << "2048 : " << is_power2(2048) << endl;
    cout << "100 : " << is_power2(100) << endl;
    cout << "1023 : " << is_power2(1023) << endl;
    cout << "3000 : " << is_power2(3000) << endl;
    cout << "5000 : " << is_power2(5000) << endl;
    cout << "8000 : " << is_power2(8000) << endl;    
    cout << "4096 : " << is_power2(4096) << endl;
    cout << "8192 : " << is_power2(8192) << endl;
    cout << "8000 : " << is_power2(8000) << endl;
    cout << "801231 : " << is_power2(801231) << endl;

}

void left_most_bit_test(){
    cout << "---------LEFT-MOST BIT TEST-------------" << endl;
    cout << "7 : " << left_most_bit(7) << endl;
    cout << "10 : " << left_most_bit(10) << endl;
    cout << "15 : " << left_most_bit(15) << endl;
    cout << "20 : " << left_most_bit(20) << endl;
    cout << "3 : " << left_most_bit(3) << endl;
    cout << "100 : " << left_most_bit(100) << endl;
    cout << "93 : " << left_most_bit(93) << endl;
    cout << "33 : " << left_most_bit(33) << endl;
    cout << "88 : " << left_most_bit(88) << endl;
    cout << "2222 : " << left_most_bit(2222) << endl;
    cout << "280 : " << left_most_bit(280) << endl;    
    cout << "8000 : " << left_most_bit(8000) << endl;

}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //Handle the edge Case
    int test_cases = 0; cin >> test_cases;
    vector<long int> cases(test_cases);
    for(int i  = 0; i < test_cases; ++i){
        cin >> cases[i];
    }
    
    for(auto i : cases){
        exec(i);
    }
    
    return 0;
}
