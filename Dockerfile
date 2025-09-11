FROM python:3.11-slim AS app

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

WORKDIR /app
COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

COPY . .
COPY mazes/*.txt /app/

ENV DISPLAY=:0

CMD ["python", "-m", "pacman.run"]
