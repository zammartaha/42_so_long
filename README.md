*This project has been created as part of the 42 curriculum by tzammar.*

# So Long

## Description

**So Long** is a small 2D game project created using the **MiniLibX** graphical library.

The objective of this project is to create a basic top-down graphical game where a character collects items and reaches an exit. It serves as an introduction to window management, event handling (keyboard and mouse), and texture rendering. The project also heavily emphasizes map parsing and validation, ensuring the game world is constructed correctly before the graphical window ever opens.

## Instructions

### Dependencies
This project requires several external libraries to be present in your root directory (or correctly linked in your Makefile). You must ensure the following are included:

* **[MiniLibX Linux](https://github.com/42paris/minilibx-linux):** The graphical library used for rendering.
* **libft:** Your custom C library.
* **ft_printf:** Your custom printf implementation.
* **get_next_line:** Your function for reading map files line-by-line.

### Compilation
To compile the game, run the following command in the root of the repository:

```bash
make
```
This will link all dependencies and generate the so_long executable.

### Usage
**The game takes a map file ending in .ber as an argument.**
```Bash
./so_long maps/map.ber
```
**Controls:**
* W / A / S / D (or Arrow Keys): Move the main character.
* ESC or Clicking [X]: Close the window and exit the game cleanly.

## Features
* **Graphics:** Renders textures (xpm images) for walls, floor, collectibles, the player, and the exit.
* **Movement:** Smooth character movement with collision detection (cannot walk through walls).

## Game Logic:
* The player must collect all collectibles (C) on the map.
* Once all items are collected, the exit (E) unlocks.
* The game finishes when the player enters the unlocked exit.
* Map Validation: The program rigorously checks the input .ber map file to ensure:
	* It is rectangular.
	* It is surrounded by walls.
	* It contains a valid path to all collectibles and the exit (flood fill algorithm).
	* It contains exactly one player, one exit, and at least one collectible.
* Move Counter: Displays the number of moves made in the shell (or on screen).

## Resources
### References
* **[MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)** - Unofficial but excellent documentation for using the MiniLibX library.
* **[Flood Fill Algorithm](https://en.wikipedia.org/wiki/Flood_fill)** - Essential for verifying map validity.