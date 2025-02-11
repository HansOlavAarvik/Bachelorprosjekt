# Environment Monitor

This repository contains sensor monitoring modules for STM32 microcontrollers. The modules provide interfaces for microphone, temperature/humidity, vibration, time-of-flight, GPIO, and Ethernet functionality.

## Installation

### Prerequisites
- STM32Cube VS code extension or STM32Cubeide
- Git installed on your system

### Steps

1. Install all prerequisites

2. Navigate to STM32 VS code extension and click Launch STM32CubeMX
    
    -Start proejct from ST-board
    -Find right board (NUCLEO-H563ZI used in development)
    -Launch project
        -Without trustzone
        -Unselect all example code
    -Enable following Pins:
        -Icache (1-way)
        -Usart3 (Asynchronous)
        -I2C1 (I2C)
        -I2C2 (I2C)
        -I2S1 (Half-duplex slave recieve)
            -Set audio frequency to 48Khz
        -ETH(RMII)
    -In project manager:
        -Name project
        -Set toolchain to CMake
    -Click Generate code in upper right conrner
        -Click open folder and copy path
3. In STM32 VS Code extension click Import Cmake project
    -paste copied path
    -from dropdown-menu in VS code, choose improt project

4. Add the following includes to your `main.c`:
```c
/* USER CODE BEGIN Includes */
#include "Environment-monitor/Mic/mic.h"
#include "Environment-monitor/Temp_humid/temp_humid.h"
#include "Environment-monitor/Vib/vib.h"
#include "Environment-monitor/Tof/tof.h"
#include "Environment-monitor/GPIO/gpio.h"
#include "Environment-monitor/Ethernet/ethernet.h"
```

5. Navigate to your STM32 project's Core/Src directory:
```bash
cd Your_Project/Core/Src
```

6. Clone the repository:
```bash
git clone https://github.com/HansOlavAarvik/Environment-monitor.git
```



7. Update your project's include paths in your IDE to include the Environment-monitor directory.

### Project Structure
```
Environment-monitor/
├── Mic/
│   ├── mic.c
│   └── mic.h
├── Temp_humid/
│   ├── temp_humid.c
│   └── temp_humid.h
├── Vib/
│   ├── vib.c
│   └── vib.h
├── Tof/
│   ├── tof.c
│   └── tof.h
├── GPIO/
│   ├── gpio.c
│   └── gpio.h
└── Ethernet/
    ├── ethernet.c
    └── ethernet.h
```


