*This project has been created as part of the 42 curriculum by hbray, mmusquer.*

## Description

Cub3D is a project inspired by the game Wolfenstein 3D. the purpose of this project is to implement a knew technique that give the impression of 3D which is the raycasting. The Minilibx library is used to create the graphic environnement.

Our project includes several wall textures, one for each directions and one for the door. It also use group of 6 sprites to make animations for the differents graphics componants : collectibles, exit and HUD. finally it also show a dynamic minimap.

## Instructions

### Compilation 

```bash
make
make re
```

### Execution

```bash
./cub3d maps/map_ec_big.cub
./cub3d maps/map_e.cub
./cub3d maps/map_circle.cub
./cub3d maps/map_c.cub
./cub3d maps/map_medium.cub
./cub3d maps/map_cool.cub
valgrind --leak-check=full --suppressions=mlx.supp ./cub3D maps/map_cool.cub
```

### Controls

| Key | Action |
|-----|--------|
| W / A / S / D | Move |
| ← / → | Rotate |
| SPACE | Interact (door / exit) |
| C | Toggle mouse look |
| ESC | Quit |

### Map Format


| Character | Description |
|-----------|-------------|
| `1` | Wall |
| `0` | Empty space |
| `N/S/E/W` | Player spawn |
| `D` | Door |
| `R` | Collectible |
| `X` | Exit |

## Ressources

### References
[Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) — main reference for the DDA algorithm and raycasting engine
[Wolfenstein 3D](http://users.atw.hu/wolf3d/) — Original game test and inspired
[Raycasting in C | 42 Cub3d](https://www.youtube.com/watch?v=G9i78WoBBIU&t=7s) — Help understanding the subject
[MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx) — MiniLibX usage and functions

### AI usage

Claude IA was used during this project to help :
- Understanding the mathematics formula needed for the project and the implementation of the raycasting method
- Create of the texture of the 4 differents wall
Lovable IA was used during this project to help : 
- Create the 6 sprites of the exit
- Create the 6 sprites of the HUD
- Create the 6 sprites of the collectibles