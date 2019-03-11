#include "grl.h"

void CoreUtil::grl::setup()
{

    json_file = "coreutil/data/Cert_271036-325175_13TeV_Combined161718_JSON_snt.txt";
    cout << "Setting grl: " << json_file << endl;
    set_goodrun_file(json_file);

}
