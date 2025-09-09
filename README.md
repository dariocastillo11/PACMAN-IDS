# Pacman_Complete

Este es un proyecto de **Pacman** completo desarrollado en Python usando **Pygame**.  
El juego incluye laberintos (`maze1.txt`, `maze2.txt`, etc.), fantasmas, frutas, power-ups y animaciones.

---

## Contenido del juego

- Pacman se mueve usando las **flechas del teclado**:
  - `↑` Arriba  
  - `↓` Abajo  
  - `←` Izquierda  
  - `→` Derecha  

- Acciones especiales:
  - `F` → Dispara (si se habilita algún power-up de ataque).  

- Objetivo:  
  Comer todos los puntos del laberinto mientras evitas los fantasmas y aprovechás los power-ups para sobrevivir más tiempo o atacar.

- Laberintos:  
  Los laberintos están en la carpeta `mazes/`. Cada archivo `.txt` define la estructura del nivel.

- Sonidos:  
  Incluye efectos de sonido y música de fondo (asegurate de tener el contenedor con soporte de audio si querés oírlos).

---

## Requisitos

- Docker instalado en tu sistema.
- Acceso a tu servidor X11 si querés ejecutar el juego con interfaz gráfica en Linux.

---

## Construcción de la imagen Docker

Desde la carpeta raíz del proyecto (donde está el `Dockerfile`):

```bash
# Permitir que Docker acceda a X11
xhost +local:docker

# Construir la imagen
sudo docker build -t pacman-game .
````

---

## Ejecutar el juego

```bash
sudo docker run -it \
    -e DISPLAY=$DISPLAY \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    pacman-game
```

* Esto abrirá la ventana del juego usando tu servidor X11 local.
* Asegurate de que la carpeta `mazes/` y las imágenes estén incluidas en el contenedor (ya está hecho en el `Dockerfile`).

---

## Notas

* El juego usa Pygame 2.6 y Python 3.11.
* Los sprites y animaciones están dentro de la carpeta `images/`.
* Los laberintos `.txt` se cargan desde la carpeta `mazes/` dentro del contenedor.
* Para habilitar sonido completo en contenedor, puede ser necesario instalar y configurar ALSA o PulseAudio (no obligatorio para jugar).

---

## Autores

* Darío Alberto Castillo
* Proyecto educativo de Ingeniería de Software, 4to año, FCEFyN, UNC.

---

¡Disfrutá tu juego de Pacman en Docker! 🎮


---


# PACMAN
# PACMAN
