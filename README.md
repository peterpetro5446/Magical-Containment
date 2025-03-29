# Magical Motes and Devices – Volume Sorter

This C program simulates the storage of magical motes (spheres) inside magical devices (boxes). The goal is to calculate the **total volume of uncontained motes** when each mote must be matched to a box that can hold it.

---

## Problem Overview

- You are given a list of **magical motes** (spheres) by their **radii**
- And a list of **magical devices** (boxes) defined by **length × width × height**
- A mote can only be placed into a device if its **volume is less than or equal** to the device's volume
- Each device can hold **only one** mote
- The objective is to compute the **total volume of motes that cannot be stored in any device**

---

## Features

- **Custom volume calculation**:
  - Mote: `V = 4/3 * π * r³`
  - Device: `V = l × w × h`
- **Efficient sorting** using custom merge sort (descending)
- **Greedy matching** strategy
- Double precision output with **six decimal places**
- Input validation against min/max constraints

---

## Input Format


- `M`: Number of magical motes (1 ≤ M ≤ 500000)
- `D`: Number of magical devices (1 ≤ D ≤ 500000)
- Next `M` lines: Radius values for each sphere
- Next `D` lines: Box dimensions

---

## Output Format

- One line containing the **sum of the volumes** of all motes that could **not** be contained, printed with **six digits after the decimal**.

---

## How to Compile and Run

```bash
gcc -o motes_volume motes_volume.c -lm
./motes_volume < input.txt


