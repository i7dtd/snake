# Snake (ncurses) 🐍

Classic Snake game for the terminal written in C with the **ncurses** library.  
The snake moves automatically, eats food to grow, and the game ends when it hits a wall or its own body 🎮

---

## Features ✨

- Terminal UI using ncurses (window, borders, centered playfield)
- Green snake and red food via color pairs 🟩🟥
- Fixed tick rate (about 3 updates per second) using timed input ⏱️
- Food spawns only inside the map, not on borders and not on the snake 🍎
- Snake grows when eating food (score increases) 📈
- Cannot reverse directly into itself (backwards input is ignored) 🚫
- Game over on wall collision or self-collision 💥

---

## Requirements 🧰

- C compiler with C11 support (GCC or Clang)
- ncurses development library and headers installed

### Install ncurses 📦

**Debian/Ubuntu**
~~~bash
sudo apt-get update
sudo apt-get install -y build-essential libncurses5-dev libncursesw5-dev
~~~

**macOS (Homebrew)**
~~~bash
brew install ncurses
~~~

---

## Build & Run 🚀

From the project root:

~~~bash
make build
make run
~~~

Or in one line:

~~~bash
make build && make run
~~~

This produces `bin/program` and launches the game ✅

---

## Controls 🕹️

- Arrow keys or `W A S D` — change movement direction
- The snake moves automatically each tick; holding a key is not required 🙂

---

## Gameplay 📜

- Eat food to increase the snake length and score
- Food is always inside the playfield (not on the border and not inside the snake)
- Hitting a wall ends the game and shows the final score
- Hitting any part of your own body also ends the game
- Trying to reverse direction into your own neck is ignored (the snake keeps going forward)

---
