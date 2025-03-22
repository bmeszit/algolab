FROM ubuntu:latest

RUN apt update && apt install -y \
    time \
    bc \
    git \
    python3 \
    build-essential

RUN git config --global --add safe.directory /app

CMD ["bash"]
