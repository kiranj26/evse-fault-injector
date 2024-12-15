# EVSE Fault Injector

An open-source fault injection tool for testing the robustness and compliance of EV chargers using protocols like OCPP and ISO 15118.

## Features
- Simulate faults in EVSE protocols (e.g., OCPP, ISO 15118).
- Inject communication delays, malformed messages, or disconnections.
- Log and visualize charger responses.
- Automate fault injection with scripts.

## Getting Started

### Installation
1. Clone the repository:    
```
git clone https://github.com/your-username/evse-fault-injector.git cd evse-fault-injector
```


2. Install dependencies:
```
pip install -r requirements.txt
```

### Running the Tool
Start the OCPP Fault Injection Server:    
```
python backend/ocpp_server.py --fault delay --delay-time 5
```

## Roadmap
- [x] OCPP Fault Injection (basic faults)
- [ ] ISO 15118 Fault Injection (coming soon)
- [ ] Graphical User Interface (GUI)

## Contributing
We welcome contributions! Please see [CONTRIBUTING.md](CONTRIBUTING.md) for details.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
