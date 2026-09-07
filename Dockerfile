# ==========( Stage 1: Build Environment )========== #

# create an environment where we will install a c++ compiler to compile the program
FROM ubuntu:22.04 AS builder

# work in /app directory
WORKDIR /app

# install c++ compiler
RUN apt update && apt install -y g++

# copy all project files into the directory
COPY . .

# find all .cpp files in src/ and its subdirectories, and then compile executable with c++11
RUN g++ -std=c++11 $(find src -name "*.cpp") -o taskforge

# ==========( Stage 2: Minimal Runtime Environment )========== #

# use a lightweight environment (linux Ubuntu)
FROM ubuntu:22.04

# work in /app directory
WORKDIR /app

# copy the executable from earlier into the directory
COPY --from=builder /app/taskforge .

# during docker runtime: run the executable
CMD ["./taskforge"]