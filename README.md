# Chat-System_ARM_architecture-EME

This project implements a chat system between two PCs using UART communication with the TM4C123GH6PM microcontroller boards as intermediaries. The chat system supports three user states: offline, read-only, and online, allowing users to send and receive messages.

## Hardware Requirements

- Two TM4C123GH6PM microcontroller boards.
- Two PCs with terminal software (e.g., PuTTY, Tera Term) to communicate with the microcontroller boards via UART.

## Software Requirements

- TI TivaWare™ Software Development Kit (SDK) for the ARM® Cortex®-M microcontrollers.
- Development environment (e.g., Code Composer Studio, Keil uVision) for building and flashing the microcontroller firmware.
- Terminal software (e.g., PuTTY, Tera Term) installed on both PCs for UART communication.

## Getting Started

1. Clone or download the project repository to your development environment.

2. Open the project in your chosen development environment (e.g., Code Composer Studio).

3. Build the firmware and flash it onto both TM4C123GH6PM microcontroller boards.

4. Connect one microcontroller board to one PC and the other microcontroller board to the other PC using UART connections.

5. Configure and open the terminal software on both PCs with the appropriate UART settings (baud rate, data bits, parity, stop bits).

6. Power up the microcontroller boards.

7. The chat system will start in the offline state by default. Follow the on-screen instructions to navigate between states and perform actions.

## User States

1. Offline State:
   - The user is not connected to the chat system.
   - No messages can be sent or received.
   - Use the provided push button to connect to the chat system.

2. Read-Only State:
   - The user is connected to the chat system but can only receive messages.
   - Incoming messages will be displayed on the terminal.
   - Use the provided push button to switch to the online state or disconnect from the chat system.

3. Online State:
   - The user is connected to the chat system and can send/receive messages.
   - Incoming messages will be displayed on the terminal.
   - Use the provided push button to send messages, switch to the read-only state, or disconnect from the chat system.

## Troubleshooting

- If there are any issues with UART communication or message display, please check the UART settings, connections, and ensure that the microcontroller firmware is correctly flashed.

