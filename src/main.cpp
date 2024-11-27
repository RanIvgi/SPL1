//#include "Simulation.h"
#include <iostream>
#include "Settlement.h"

using namespace std;

//Simulation* backup = nullptr;

int main(int argc, char** argv){
    if(argc!=2){
        cout << "usage: simulation <config_path>" << endl;
        return 0;
    }
    string configurationFile = argv[1];
    //Simulation simulation(configurationFile);
    //simulation.start();
    Settlement *s1 = new Settlement("Tel aviv", SettlementType::CITY);
    cout << s1->toString() << endl;

    delete s1;
    
//    if(backup!=nullptr){
//    	delete backup;
//    	backup = nullptr;
//    }
    return 0;
}