#include<string>
#include"configs.cpp"
#include<vector>
using namespace std;

class subject{
    public:
        string name;
        string elective;
        int lab;
         int credits,hourspercredit;
        unsigned short int bfactor;
        unsigned int *rooms;
        unsigned short int noRooms;
        bool readData(string inp);
        string convertToString();
        subject(){
            credits=0;
            hourspercredit=0;
            bfactor=0;
        };

};
bool subject::readData(string inp){
    enum format{
        namen,
        electiven,
        labn,
        creditsn,
        hourspercreditn,
        bfactorn,
        roomsn,
    };
    int commacount=0;
    // try{
        for(int i=0;i<inp.size();i++){
            if(inp[i]==','){
                commacount++;
                continue;
            }
            switch(commacount){
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
                case hourspercreditn:
                    hourspercredit=hourspercredit*10+inp[i]-'0';
                    break;
                case bfactorn:
                    bfactor=bfactor*10+inp[i]-'0';
                    break;
                case roomsn:
                    int commacount=0;
                    i++;
                    vector<unsigned> temp;
                    while(true){
                        if(inp[i]==']'){
                            noRooms=commacount+1;
                             rooms=new unsigned[noRooms];
                             for(commacount;commacount>=0;commacount--){
                                 rooms[commacount]=temp[commacount];
                             }
                            break;
                        }
                        else if(inp[i]==','){
                            commacount++;
                        }
                        else{
                            if(temp.size()>commacount){
                                temp[commacount]=temp[commacount]*10+inp[i]-'0';
                            }
                           else{
                            temp.push_back(inp[i]-'0');
                           }
                        }
                        i++;
                    }

            }
        }
    // }
    // catch(...){
        // return 0;
    // }
}
string subject::convertToString(){
    string out;
    out=name+",";
    out+=elective+",";
    out+=to_string(lab)+",";
    out+=to_string(credits)+",";
    out+=to_string(hourspercredit)+",";
    out+=to_string(bfactor)+",[";
    for(int i=0;i<noRooms-1;i++){
        out+=to_string(rooms[i])+",";
    }
    out+=to_string(rooms[noRooms-1])+"]";
    return out;
}