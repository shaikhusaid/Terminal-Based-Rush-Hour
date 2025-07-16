# Terminal Based Rush-Hour Game Using OOP (Object Oriented Programming) in C++
🚦 Terminal-Based Rush Hour Game (C++)

A simple **console-based car puzzle game** developed in C++ where the player controls a taxi (`C`) navigating through a city grid, avoiding buildings (`B`), trees (`T`), other cars (`O`), and utilizing fuel stations (`F`). The game runs entirely in the terminal.

---

## 🎮 Features

- Grid-based movement system using `W`, `A`, `S`, `D`
- Collision detection with objects like buildings and cars
- Dynamic display using ASCII characters
- Real-time input with `getch()` (no need to press Enter)
- Randomly placed city elements like:
  - 🏢 Buildings (`B`)
  - 🌳 Trees (`T`)
  - 🚗 Other cars (`O`)
  - ⛽ Fuel stations (`F`)
  - 🚕 Player’s car (`C`)

---

## 🧱 Object Representation

| Symbol | Object        | Collidable |
|--------|---------------|------------|
| `C`    | Player Car    | No         |
| `B`    | Building       | Yes        |
| `T`    | Tree           | Yes        |
| `O`    | Other Car      | Yes        |
| `F`    | Fuel Station   | No         |
| `.`    | Empty Road     | No         |

---

## 🧩 How to Play

- Use the keyboard:
  - `W` = Up
  - `A` = Left
  - `S` = Down
  - `D` = Right
  - `Q` = Quit game
- The goal is to freely navigate without colliding with buildings, other cars, or trees.
- Move over fuel stations for a realistic city vibe (optional interaction).

---

## 🛠️ Built With

- C++
- `#include <iostream>`
- `#include <conio.h>` for real-time input
- `#include <windows.h>` for screen clearing

---

## 📁 File Structure

