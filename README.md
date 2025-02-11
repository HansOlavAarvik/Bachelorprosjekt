# Environment Monitor

This repository contains sensor monitoring modules for STM32 microcontrollers. The modules provide interfaces for microphone, temperature/humidity, vibration, time-of-flight, GPIO, and Ethernet functionality.

## Installation

### Prerequisites
- STM32Cube VS code extension or STM32Cubeide (installation guide: https://www.st.com/content/st_com/en/campaigns/stm32-vs-code-extension-z11.html)
- Git installed on your system

### Quiality of life extensions
- Seiral monitor (https://marketplace.visualstudio.com/items?itemName=ms-vscode.vscode-serial-monitor)


### Installation guide with STM32 VS code extension

1. Install all prerequisites

2. Navigate to STM32 VS code extension and click Launch STM32CubeMX
    
    - Start proejct from ST-board
    - Find right board (NUCLEO-H563ZI used in development)
    - Launch project
        - Without trustzone
        - Unselect all example code
    - Enable following Pins:
        -Icache (1-way)
        -Usart3 (Asynchronous)
        -I2C1 (I2C)
        -I2C2 (I2C)
        -I2S1 (Half-duplex slave recieve)
            -Set audio frequency to 48Khz
        -ETH(RMII)
    - In project manager:
        - Name project
        - Set toolchain to CMake
    - Click Generate code in upper right conrner
        - Click open folder and copy path
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



7. Configure CMake 

- Rewrite CMake configure to:
```bash
cmake_minimum_required(VERSION 3.22)

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

# Project name
set(CMAKE_PROJECT_NAME YourProject)

# Include toolchain file
include("cmake/gcc-arm-none-eabi.cmake")

# Enable CMake support for ASM and C
enable_language(C ASM)

# Core project settings
project(${CMAKE_PROJECT_NAME})

# Create executable
add_executable(${CMAKE_PROJECT_NAME})

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    Core/Inc
    # Add other include directories here
)

# Add sources
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add your source files here
)

# Link libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx
)
```

    - Delete Build folder
    - Rebuild with 


```bash 
cmake --build build/Debug
```

