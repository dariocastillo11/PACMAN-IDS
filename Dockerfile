FROM python:3.11-slim

# Instala dependencias del sistema necesarias para pygame
RUN apt-get update && apt-get install -y \
    python3-tk \
    libgl1 \
    x11-apps \
    libasound2 \
    libasound2-dev \
    libsdl2-mixer-2.0-0 \
    libpulse0 \
    libgstreamer1.0-0 \
    libgstreamer-plugins-base1.0-0 \
    libglib2.0-0 \
    libgthread-2.0-0 \
    && rm -rf /var/lib/apt/lists/*


# Crea el directorio de la app
WORKDIR /app

# Copia requirements e instala dependencias de Python
COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

# Copia el resto de la app (incluyendo la carpeta mazes)
COPY . .
COPY mazes/*.txt /app/

# Expone el display X11 (para entorno gráfico)
ENV DISPLAY=:0

# Comando para ejecutar el juego
CMD ["python", "-m", "pacman.run"]
