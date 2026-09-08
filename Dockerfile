# ==========( Stage 1: Build Environment )========== #

# create an environment where we will install a c++ compiler to compile the program
FROM ubuntu:22.04 AS builder

# work in /app directory
WORKDIR /app

# install c++ compiler
RUN apt update && apt install -y g++

# copy all project files into the directory
COPY . .

# find all .cpp files in project, and then compile executable with c++11
RUN g++ -std=c++11 -g $(find . -name "*.cpp") -o taskforge

# ==========( Stage 2: Minimal Runtime Environment )========== #

# use a lightweight environment (linux Ubuntu)
FROM ubuntu:22.04

# work in /app directory
WORKDIR /app

# install GDB and Valgrind
RUN apt-get update && apt-get install -y --no-install-recommends \
    gdb \
    make \
    valgrind \
    && rm -rf /var/lib/apt/lists/*

# copy the executable from earlier into the directory
COPY --from=builder /app/taskforge .
COPY src/ ./src/
COPY Makefile .

# during docker runtime: run the executable
CMD ["./taskforge"]