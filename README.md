# Port Scanner
- A simple tool for scanning open and closed ports on a specified host.

# Features

- Scans a specified range of ports on a given host
- Outputs lists of open and closed ports

# Usage
```cpp
#include "portmanager/portmanager.h"

int main() {
    const auto prtmgr = std::make_unique<PortManager>();
    static const int portStart = 1;
    static const int portEnd = 1024;
    std::string host = "ip.here";

    for (int port = portStart; port < portEnd; port++) {
        prtmgr->ScanPort(host, port);
    }

    prtmgr->OutputScannedPorts();
    prtmgr->OutputOpenPorts();
}
```

# Purpose
- Designed for educational use in understanding network port scanning. Use responsibly and only with networks and hosts you own or have permission to scan.

# Todo:
- Add multithreading, right now it is pretty slow, and multithreading wouldn't be too hard to implement.
