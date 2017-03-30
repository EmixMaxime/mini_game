## Compilation sur linux avec gcc
```bash
# Compile
gcc main.c columns.c tokens.c click.c check.c grid.c -lSDL -lSDL_mixer -o Test -I ./

# Execute
./Out
```

# Comment détecter si des coordonnées (x,y) font partie d'une zone ?
C'est pratique pour les boutons ect.

```c
// Je déclare et initialise une zone :
Zone zone;
createClicableZone(x1, x2, y1, y2, &zone);

// Je récupère (x,y) depuis un event par exemple...
int x = event.button.x;
int y = event.button.y;
bool okay = isClicableZone(x, y, zone);
```
