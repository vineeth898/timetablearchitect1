#include<iostream>
#include<string>
using namespace std;
string name="vineeth";
string elective="esc";
int lab=0;
int credits=1,hourspercredit=1;
unsigned short int bfactor=5;
unsigned int *rooms;
string convertToString();
int main(){
    cout<<convertToString();
}
string convertToString(){
    string out;
    out=name+",";
    out+=elective+",";
    out+=to_string(lab)+",";
    out+=to_string(credits)+",";
    out+=to_string(hourspercredit)+",";
    out+=to_string(bfactor)+",";
    return out;
}