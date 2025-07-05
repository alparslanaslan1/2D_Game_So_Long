<img width="2500" alt="Ekran Resmi 2024-03-21 ÖÖ 7 10 56" src="https://github.com/alparslanaslan1/so_long/assets/140237544/f65fb0ec-5f6a-4871-aac7-f900c1a6b8b3">

# 2D Game: So Long

**So Long** is a 2D explorer game written in C using the MiniLibX (MLX) graphics library. The goal is to navigate a maze-like map, collect all coins, and reach the exit.

## File Structure

```
2D_Game_So_Long-main/
├── README.md                # This file
└── so_long/
    ├── Makefile             # Build rules for the game and ft_printf
    ├── src/                 # Source code
    │   ├── main.c
    │   ├── map_control.c    # Map parsing and validation
    │   ├── chars_control.c  # Player movement handlers
    │   ├── play_map_control.c # Game loop and rendering
    │   ├── exit.c           # Exit cleanup
    │   ├── mlx_create.c     # Initialize MLX window and images
    │   ├── mobilize.c       # Load assets and textures
    │   └── get_next_line.c  # Line reader for map input
    ├── img/                 # Game assets (XPM files)
    │   ├── background.xpm
    │   ├── character.xpm
    │   ├── coin1.xpm
    │   ├── coin2.xpm
    │   ├── coin3.xpm
    │   └── exit.xpm
    └── ft_printf/           # Custom printf for formatted output
        ├── ft_printf.c
        ├── ft_printf_utils.c
        ├── ft_printf.h
        └── Makefile
```

## Compilation

1. **Enter the `so_long` directory**:

   ```bash
   cd so_long
   ```

2. **Build the game**:

   ```bash
   make
   ```

   This will compile the `ft_printf` library and link the `so_long` executable.

3. **Clean build artifacts**:

   ```bash
   make clean       # Remove object files
   make fclean      # Remove objects and executable
   make re          # Full rebuild
   ```

## Usage

Run the game by providing a valid map file with the `.ber` extension:

```bash
./so_long path/to/your_map.ber
```

Controls:

* **W / ↑**: Move Up
* **A / ←**: Move Left
* **S / ↓**: Move Down
* **D / →**: Move Right
* **ESC**: Exit game

## Map Format

* Maps must be rectangular files ending in `.ber`.
* Walls are represented by `1`, empty space by `0`, coins by `C`, player start by `P`, and exit by `E`.

## Author

* **Alparslan Aslan** ([alparslanaslan504@gmail.com](mailto:alparslanaslan504@gmail.com))

## License

No explicit license provided. Use, modify, and distribute at your own risk.
