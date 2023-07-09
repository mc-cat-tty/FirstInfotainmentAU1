# FirstInfotaimentAU1
## What is it?
Formula student driver's dashboard (https://github.com/mc-cat-tty/FirstInfotainmentAU1) porting for AU1 revision of the Discovery F469 board.

## Usage
### Dos and don'ts
The following build procedure should always work:
 1. open project in TouchGFX and generate resources (code, typographies and other assets)
 2. build STM32F469I-DISCO-REV-AU1 subproject form STM32CubeIDE
 3. Flash it by running or debugging it

Never regenerate IOC's code in this project. The correct procedure is opening the FirstInfotaiment's IOC file and generate the code from there, taking into account that some pins are initialized by hand in _main.h_ and _main.c_ files.

## How to synchronize main and ported projects
This is a sore point. Both Unix symbolic links and CubeIDE links (link between porting resources and original ones) have been tried to make synchronization smooth, but they didn't work. I had to copy by hand source code and headers.

This is the list of non-boilerplate files:
 - Core/Inc/main.h
 - Core/Src/main.c and Core/Src/user_code.c
 - Shared folder
 - mmr_core folder (submodule)
 - TouchGFX (see below)

The last folder must be synchronized through TouchGFX import GUI option.

# STM32F469I-DISCO-REV-AU1 TBS

The default IDE is set to STM32CubeIDE, to change IDE open the STM32F469I-DISCO-REV-AU1.ioc with CubeMX and select from the supported IDEs (EWARM from version 8.50.9, MDK-ARM, and STM32CubeIDE). Supports flashing of the STM32F469I-DISCO-REV-AU1 board directly from TouchGFX Designer using GCC and STM32CubeProgrammer.Flashing the board requires STM32CubeProgrammer which can be downloaded from the ST webpage. 

This TBS is configured for 480 x 800 pixels 16bpp screen resolution.  

Performance testing can be done using the GPIO pins designated with the following signals: VSYNC_FREQ  - Pin PA2(D5), RENDER_TIME - Pin PA6(D6), FRAME_RATE  - Pin PA1(D3), MCU_ACTIVE  - Pin PG12(D4)
