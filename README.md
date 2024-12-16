
# EVSE Fault Injector

An open-source tool for fault injection and testing of Electric Vehicle Supply Equipment (EVSE) chargers using both simulated and real hardware.

---

## **Overview**
The EVSE Fault Injector is designed to simulate and test EV chargers under various fault conditions. It enables developers and testers to:
- Validate EVSE protocol implementations (e.g., OCPP, ISO 15118).
- Simulate real-world fault scenarios.
- Analyze and debug charger behavior during abnormal conditions.

---

## **Features**
- **Fault Simulation:**
  - Delayed responses to simulate network latency.
  - Malformed messages to test protocol robustness.
  - Random disconnections to mimic hardware failures.
- **Testing Modes:**
  - A simulated EV charger for independent protocol testing.
  - Integration with real chargers via a configurable backend.
- **Analysis and Logging:**
  - Real-time logging and fault analysis.
  - Structured logs using spdlog for detailed debugging.

---

## **Getting Started**

### **Prerequisites**
Before building and running the project, ensure you have the following installed:
- **C++17 or higher**
- **CMake 3.10 or higher**
- Required dependencies:
  - Boost.Asio
  - nlohmann/json
  - spdlog

### **Installation**
Follow these steps to set up the project:

1. Clone the repository:
   ```bash
   git clone https://github.com/<your-username>/evse-fault-injector.git
   cd evse-fault-injector
   ```

2. Build the project using CMake:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```

3. Run the WebSocket server:
   ```bash
   ./evse_fault_injector
   ```

---

## **Roadmap**
Here’s what’s planned for future versions of EVSE Fault Injector:

- [x] Basic WebSocket server for fault injection.
- [ ] Simulated EV charger for protocol testing.
- [ ] Real charger integration with fault simulation.
- [ ] Automated test scripts for fault injection scenarios.
- [ ] Advanced fault simulation (e.g., power fluctuation, packet loss).

---

## **Contributing**
Contributions are welcome! If you have ideas for new features or improvements, feel free to open an issue or submit a pull request.

---

## **License**
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## **Contact**
**Maintainer:** Kiran Jojare  
Feel free to reach out for queries, suggestions, or contributions: kijo7257@colorado.edu
