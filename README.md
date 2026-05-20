# 🔗 Server-Client Armstrong Number Checker

A simple **IPC (Inter-Process Communication)** project in **C** using **Named Pipes (FIFOs)** to check whether a number is an **Armstrong Number** through a **Server-Client architecture**.

---

## 📘 What is an Armstrong Number?

An **Armstrong Number** is a number whose sum of its digits, each raised to the power of the total number of digits, is equal to the number itself.

### ✨ Example

```text
153 → 1³ + 5³ + 3³
     = 1 + 125 + 27
     = 153
```

So, **153 is an Armstrong Number** ✅

---

## ⚙️ How It Works

```text
[Client]  ---(pipe1)--->  [Server]
[Client]  <---(pipe2)---  [Server]
```

### 📌 Workflow

1. Client takes a number as input
2. Client sends the number to the server using `pipe1`
3. Server reads the number from `pipe1`
4. Server checks whether the number is an Armstrong number
5. Server sends the result back using `pipe2`
6. Client displays the result on the screen

🛑 Type `exit` in the client to disconnect both programs.

---

## 📂 Project Structure

```text
.
├── fifoclient.c   # Client Program
├── fifoserver.c   # Server Program
└── README.md
```

---

## 🛠️ Requirements

- GCC Compiler
- Linux Environment
- Named Pipes (FIFO support)

---

## 🚀 How to Run

### 1️⃣ Create the Named Pipes

```bash
mkfifo pipe1 && mkfifo pipe2
```

---

### 2️⃣ Compile and Run the Server

```bash
gcc fifoserver.c -lm
./a.out
```

> `-lm` is used to link the math library.

---

### 3️⃣ Compile and Run the Client

```bash
gcc fifoclient.c
./a.out
```

---

## 💡 Usage

- Enter a number in the client terminal
- The server checks whether it is an Armstrong number
- Result is displayed on the client side

### Example

```text
Enter a number: 153
153 is an Armstrong Number
```

To terminate the communication:

```text
exit
```

---

## 🧠 Concepts Used

- Inter-Process Communication (IPC)
- Named Pipes (FIFO)
- Client-Server Model
- File Handling in C
- Mathematical Computation

---

## ❤️ Made With Love

Made with ❤️ by **Deon George**
