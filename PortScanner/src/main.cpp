#include "portmanager/portmanager.h"

int main()
{
    const auto prtmgr = std::make_unique<PortManager>();
    static const int portStart = 1;
    static const int portEnd = 1024;
    std::string host = "ip.here";

    for (int port = portStart; port < portEnd; port++)
    {
        prtmgr->ScanPort(host, port);
    }

    prtmgr->OutputScannedPorts();
    prtmgr->OutputOpenPorts();
}