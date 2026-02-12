# Smart Dog Collar Simulator (Firmware Logic)

A C-based simulation of an embedded firmware system for a smart pet collar. This project demonstrates how hardware registers are manipulated using bitwise operations to trigger alerts based on geofencing logic.

## Project Goal
To simulate low-level hardware control logic without physical hardware. The program tracks a dog's distance from home and activates specific "hardware pins" (simulated via bits) depending on safety zones.

## Key Features
* **Geofencing Logic:** Automatically calculates safety zones based on a user-defined boundary.
* **Hardware Abstraction:** Simulates GPIO pin states using an 8-bit register (`unsigned char`)
* **Bitwise State Monitoring:** Displays the real-time binary state of the collar for debugging.
* **Simulation Modes:**
    * **Manual Mode:** User inputs specific distances to test boundary conditions.
    * **Random Mode:** Generates random distances to simulate unpredictable pet movement. 

## Technical Concepts Applied
* **Bitwise Operations:** Using `&` (AND), `|` (OR), and `<<` (Left Shift) to mask and toggle specific bits.
* **Data Structures:** Using `struct` to model the Dog object (Name, Location, Limits).
* **Pointers:** Passing structures by reference (`struct Dog *d`) to modify data efficiently without copying.
* **Input/Output:** Handling user input streams and formatted output.

## Hardware Register Map
The system uses a single byte (`unsigned char`) to control all peripherals.

| Bit Index | Peripheral | Function |
| :--- | :--- | :--- |
| **0** | **LED** | Visual Warning (Yellow Light) |
| **1** | **SPEAKER** | Audio Warning (Beep) |
| **2** | **VIBRATION**| Haptic Feedback (Buzz) |
| **3** | **ALARM** | High Priority Alert (Alarm + GPS) |
| **4-7** | **N/F** | No Function (Reserved) |

## Limitations & Known Issues
* **Menu Input:** The main menu currently utilizes `scanf` for integer selection. Entering non-numeric characters will cause the simulator to loop. (To be patched in v3.0).
* **Distance Calculation:** Distances are currently linear (1D). Future versions will implement 2D (X, Y) coordinate tracking.

* **NOTE:** The Dog Name input has been patched in v2.0 and now fully supports spaces and sanitizes input using a custom pointer driver.

## Attribution
* **Random Number Logic:** The algorithm for generating random float values within a specific range was developed with assistance from Gemini (Google, 2026).
