# Environment Monitor


## short description of project
Enviromental monetring divice used for monitoring conditions in eletrical cabinets. Records sound, vibrations, if the door is opened (with tof), inside temperature, inside humidity, outside humidity, and outside temperature. The sensors are controlled with a STM32. Power and communication is done over ethernet. There are also some LED's and a buzzer that gives feedback to on-site opperators. Data processing is done on server, only recording, transmission, recieving and and signals to LED's/buzzer is controlled by microcontroller.


## Installation

### Prerequisites
- STM32Cube VS code extension or STM32Cubeide, installation guide: (https://www.st.com/content/st_com/en/campaigns/stm32-vs-code-extension-z11.html)
- Git installed (https://git-scm.com)

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
        - Icache (1-way)
        - Usart3 (Asynchronous)
        - I2C1 (I2C)
        - I2C2 (I2C)
        - I2S2 (Half-duplex master recieve)
            - Enable clock
            - 16 bits Data on 16 Bits frame
            - Set audio frequency to 32Khz
        - GPDMA1
            - Set channel 0 to: Standard request mode
                - Circular mode: Enable
                - Priority: Very high
                - Request: SPI2_RX/I2S2_RX
        - ETH(RMII)
            - Go to Project manager
                - Advanced settings
                    - set MX_ETH_init to not static 
        - Rename following GPIO pins to:
            - PF4 - LED_YELLOW
            - PG4 - LED_RED
            - PB0 - LED_GREEN
    - In project manager:
        - Name project
        - Choose installation-path
        - Set toolchain to CMake
    - Click Generate code in upper right conrner
        - Click open folder and copy path
3. In STM32 VS Code extension click Import Cmake project
    - Paste copied path
    - From dropdown-menu in VS code, choose improt project

4. Add the following includes to your `main.c`:
```c
/* USER CODE BEGIN Includes */
#include "Environment-monitor/Mic/mic.h"
#include "Environment-monitor/Temp_humid/temp_humid.h"
#include "Environment-monitor/Vib/vib.h"
#include "Environment-monitor/Tof/tof.h"
#include "Environment-monitor/GPIO/gpio.h"
#include "Environment-monitor/Ethernet/ethernet.h"
#include "Environment-monitor/Div/div.h"
#include <stdint.h>
```

5. Navigate to your STM32 project's Core/Src directory:
```bash
cd "Project_name"/Core/Src
```

6. Clone the repository:
```bash
git clone https://github.com/HansOlavAarvik/Environment-monitor.git
```


7. Configure CMake 

- Rewrite CMakeLists.txt to:
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
add_executable(${CMAKE_PROJECT_NAME}
    Core/Src/main.c
    Core/Src/Environment-monitor/Div/div.c
    Core/Src/Environment-monitor/Ethernet/ethernet.c
    Core/Src/Environment-monitor/GPIO/gpio.c
    Core/Src/Environment-monitor/Mic/mic.c
    Core/Src/Environment-monitor/Temp_humid/temp_humid.c
    Core/Src/Environment-monitor/Tof/tof.c
    Core/Src/Environment-monitor/Vib/vib.c
)

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

  - If there is a build folder delete it
  - Rebuild:


```bash 
cmake --build build
```

