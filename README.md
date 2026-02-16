# Smart Dog Collar Simulator (Firmware Logic)

A C-based simulation of an embedded firmware system for a smart pet collar. This project demonstrates how hardware registers are manipulated using bitwise operations to trigger alerts based on geofencing logic.

## Project Goal
To simulate low-level hardware control logic without physical hardware. The program tracks a dog's distance from home and activates specific "hardware pins" (simulated via bits) depending on safety zones.

## Key Features
* **Geofencing Logic:** Automatically calculates safety zones based on a user-defined boundary.
* **Hardware Abstraction:** Simulates GPIO pin states using an 8-bit register (`unsigned char`)
* **Bitwise State Monitoring:** Displays the real-time binary state of the collar for debugging.
* **Simulation Modes:**
    * **Manual Mode:** User inputs geospatial coordinates (latitude/longitude micro-offsets) to test boundary conditions and trigger the internal distance engine
    * **Random Mode:** Generates random distances to simulate unpredictable pet movement. 
* **Modular Architecture:** Refactored the monolithic codebase into separated application (`dog_collar.c`) and driver (`my_functions.c`/`.h`) files.
* **Geospatial Engine:** Implemented a custom Pythagorean distance calculator to convert raw latitude/longitude coordinates into real-world meters.
* **Data Packets:** Organized GPS data into nested `Location` and `Dog` structs for memory-safe data transmission.
* **Input Validation:** Constrained manual GPS input to a micro-offset grid (Kent area) to ensure realistic testing parameters.

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
* **Floating-Point Precision Loss:** The current engine uses standard `float` data types for coordinate math. Due to truncation errors during micro-offset division, calculated boundary distances may suffer from slight precision loss, making the effective safe zone marginally smaller than intended. (Can be patched in future versions by upgrading to `double` precision).

* **NOTE (v3.0 Update):** The simulator has been successfully refactored into a modular C architecture (`.c` and `.h` files). It now features a live geospatial engine that dynamically calculates distances using Pythagorean math and nested `Location` data packets, replacing the old manual distance inputs.
* **NOTE (v3.1 Update):** All vulnerable `scanf` functions have been replaced with memory-safe string parsing (`fgets`, `atoi`, and `atof`). This eliminates the terminal infinite-loop bug and fully stabilizes the simulation environment.

## Attribution
* **Random Number Logic:** The algorithm for generating random float values within a specific range was developed with assistance from Gemini (Google, 2026).
* **Micro-Offset Geofence Logic:** The mathematical concept and implementation for constraining user input to local, street-level coordinate offsets was developed with architectural assistance from Gemini (Google, 2026).
