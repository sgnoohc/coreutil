#include "grl.h"

void CoreUtil::grl::setup()
{

    json_file = "Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON_snt.txt"; // 26p4 fb
    cout << "Setting grl: " << json_file << endl;
    set_goodrun_file(json_file);

}
