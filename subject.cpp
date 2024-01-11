#include<string>
#include"configs.cpp"
#include<vector>
using namespace std;

class subject{
    public:
        string name;
        string elective;
        int lab;
         int credits,hoursPerCredit;
        unsigned short int bFactor;
        unsigned int *rooms;
        unsigned short int noRooms;
        bool readData(string inp);
        string convertToString();
        subject(){
            credits=0;
            hoursPerCredit=0;
            bFactor=0;
        };

};
bool subject::readData(string inp){
    enum format{
        namen,
        electiven,
        labn,
        creditsn,
        hoursPerCreditn,
        bFactorn,
        roomsn,
    };
    int commaCount=0;
    try{
        for(int i=0;i<inp.size();i++){
            if(inp[i]==','){
                commaCount++;
                continue;
            }
            switch(commaCount){
                case namen:
                    name.push_back(inp[i]);
                    break;
                case electiven:
                    elective.push_back(inp[i]);
                    break;
                case labn:
                    lab=inp[i]-'0';
                    break;
                case creditsn:
                    credits=credits*10+inp[i]-'0';
                    break;
                case hoursPerCreditn:
                    hoursPerCredit=hoursPerCredit*10+inp[i]-'0';
                    break;
                case bFactorn:
                    bFactor=bFactor*10+inp[i]-'0';
                    break;
                case roomsn:
                    int commaCount=0;
                    i++;
                    vector<unsigned> temp;
                    while(true){
                        if(inp[i]==']'){
                            noRooms=commaCount+1;
                             rooms=new unsigned[noRooms];
                             for(commaCount;commaCount>=0;commaCount--){
                                 rooms[commaCount]=temp[commaCount];
                             }
                            break;
                        }
                        else if(inp[i]==','){
                            commaCount++;
                        }
                        else{
                            if(temp.size()>commaCount){
                                temp[commaCount]=temp[commaCount]*10+inp[i]-'0';
                            }
                           else{
                            temp.push_back(inp[i]-'0');
                           }
                        }
                        i++;
                    }

            }
        }
     }
     catch(...){
         return 0;
     }
}
string subject::convertToString(){
    string out;
    out=name+",";
    out+=elective+",";
    out+=to_string(lab)+",";
    out+=to_string(credits)+",";
    out+=to_string(hoursPerCredit)+",";
    out+=to_string(bFactor)+",[";
    for(int i=0;i<noRooms-1;i++){
        out+=to_string(rooms[i])+",";
    }
    out+=to_string(rooms[noRooms-1])+"]";
    return out;
}