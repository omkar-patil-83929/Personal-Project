
# STM32F407 Bare-Metal GPIO Driver

A GPIO peripheral driver developed in Embedded C for STM32F407 microcontroller using direct register programming and memory-mapped I/O.

## Features
- GPIO initialization
- Input/output configuration
- Push-pull/Open-drain support
- Pull-up/Pull-down configuration
- GPIO read/write/toggle APIs
- External interrupt configuration
- NVIC interrupt handling
- Alternate function configuration

## Project Structure

drivers/Inc
- MCU register definitions
- GPIO driver APIs
- Peripheral macros

drivers/Src
- GPIO driver implementation

Src
- Application examples
- LED toggle application
- GPIO interrupt example
