# EVSE Fault Injector

An open-source tool for fault injection and testing of EV chargers using simulated or real hardware.

## Features
- Simulate faults in EVSE protocols (e.g., OCPP, ISO 15118).
- Test chargers with:
  - A simulated EV charger for independent protocol testing.
  - Real chargers via a configurable backend.
- Inject faults like:
  - Delayed responses.
  - Malformed messages.
  - Disconnections.
- Log and analyze charger behavior under fault conditions.

## Getting Started
### Prerequisites
- **C++17 or higher**
- **CMake 3.10 or higher**
- Dependencies: Boost.Asio, nlohmann/json, spdlog

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/<your-username>/evse-fault-injector.git
   cd evse-fault-injector
2. Build the project using CMake:    
    ```
    mkdir build && cd build
    cmake ..
    make
    ```
### Roadmap    
- [x] Basic WebSocket server for fault injection.    
- [ ] Simulated EV charger for protocol testing.    
- [ ] Real charger integration.    
- [ ] Automated test scripts for fault injection.   


### License    
This project is licensed under the MIT License - see the LICENSE file for details.

---

### **4. Add the License File**
Use the MIT License for simplicity:
```plaintext
MIT License

Copyright (c) 2024 <Kiran Jojare>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
```