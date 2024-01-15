#include<string>
#include"configs.cpp"
#include<vector>

class subject{
    public:
        std::string name;
        std::string elective;
        bool lab;
        int credits,hoursPerCredit;
        unsigned short int bFactor;
        std::string *rooms;
        unsigned short int noRooms;
        bool readData(std::string inp);
        std::string convertToString();
        subject(){
            credits=0;
            hoursPerCredit=0;
            bFactor=0;
        };
};
bool subject::readData(std::string inp){
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
                    std::vector<std::string> temp;
                    while(true){
                        if(inp[i]==']'){
                            noRooms=commaCount+1;
                             rooms=new std::string[noRooms];
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
                                temp[commaCount].push_back(inp[i]);
                            }
                           else{
                            temp.push_back("");
                            temp[commaCount].push_back(inp[i]);
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
std::string subject::convertToString(){
    std::string out;
    out=name+",";
    out+=elective+",";
    out+=std::to_string(lab)+",";
    out+=std::to_string(credits)+",";
    out+=std::to_string(hoursPerCredit)+",";
    out+=std::to_string(bFactor)+",[";
    for(int i=0;i<noRooms-1;i++){
        out+=rooms[i]+",";
    }
    out+=rooms[noRooms-1]+"]";
    return out;
}