#include "grl.h"

void CoreUtil::grl::setup()
{

    json_file = "Cert_271036-306462_13TeV_2016and2017_23Sep2016ReReco_Collisions16_JSON_EOY2017ReReco_Collisions17_JSON_v1_snt.txt";
    cout << "Setting grl: " << json_file << endl;
    set_goodrun_file(json_file);

}
