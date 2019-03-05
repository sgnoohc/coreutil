#include "grl.h"

void CoreUtil::grl::setup()
{

    json_file = "coreutil/data/Cert_run2.txt";
    cout << "Setting grl: " << json_file << endl;
    set_goodrun_file(json_file);

}
