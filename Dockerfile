FROM ubuntu:latest

RUN apt update
RUN apt install -y time bc git build-essential python3 python-is-python3

RUN git config --global --add safe.directory /app

CMD ["bash"]
