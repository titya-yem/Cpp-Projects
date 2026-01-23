# 🏧 Real ATM Machine (C++ & SQLite3)

![C++](https://img.shields.io/badge/Language-C++-00599C?style=flat-square)
![SQLite3](https://img.shields.io/badge/Database-SQLite3-003B57?style=flat-square)
![MIT License](https://img.shields.io/badge/License-MIT-green?style=flat-square)
![Last Commit](https://img.shields.io/github/last-commit/titya-yem/Cpp-Projects/main?style=flat-square)
![Repo Stars](https://img.shields.io/github/stars/titya-yem/Cpp-Projects?style=flat-square)
![Repo Forks](https://img.shields.io/github/forks/titya-yem/Cpp-Projects?style=flat-square)

A **console-based ATM simulation** built with C++ and SQLite3, mimicking real-world ATM functionality.  
This project demonstrates **Object-Oriented Programming (OOP)**, database interaction, session-based receipts, and multi-currency account management.

---

## 📌 Why this project?

This project was designed as a **learning and portfolio project** to:

- Practice **C++ OOP concepts** (classes, vectors, modular code)
- Work with **SQLite3 databases** from C/C++
- Simulate **real-world ATM workflows** (login, deposit, transfer, receipt)
- Build a **clean, maintainable code structure** for future projects

It’s ideal for **junior developers** looking to showcase practical C++ skills.

---

## 🚀 Features

- 🔐 User login with PIN authentication
- 💳 Multiple account actions:
  - Deposit
  - Payment
  - Transfer
  - Receipt
- 💵 Multi-currency support (USD / KHR)
- 🧾 Session-based receipts (like a real ATM)
- 🗄️ Persistent storage using **SQLite3**
- 🧠 Clean OOP structure with modular design
- 🖥️ Terminal-based navigation simulating a real ATM

---

## 🛠️ Tech Stack

- **C++** — OOP & modular design
- **C** — SQLite3 integration
- **SQLite3** — database persistence
- **Vectors** — dynamic array management
- **Terminal UI** — simulating real ATM screens

---

## 📁 Project Structure

- **.vscode**
- **config**
- **Screen**
- **sqlite**
- **utils**
  -- Account
  -- CreateAccount
  -- Deposit
  -- Login
  -- Payment
  -- Receipt
  -- Transfer
- **.env.example**
- **main.cpp**
- **main.exe**
- **sqlite3.o**
- **README.md**

---

---

## 📷 Demo

**ATM login screen example:**

```bash
===============================================
|            Welcome to Le Fang ATM           |
===============================================

Do you have accounts or not ?
1) Yes (Login)
2) No (Create Account)
3) Exit ATM

Please select:

Account Menu example:

===============================================
|                 Account Menu                |
===============================================
Please select your preferred option:

1) Account     2) Deposit      3) Transfer
4) Payment     5) Receipt      6) Exit

Enter your choice:

```

---

## 🚀 Getting Started

### 1. Clone the repository

```bash
git clone https://github.com/titya-yem/Cpp-Projects.git
cd Cpp-Projects/atm-machine
```

### 2. Compile SQLite3 (C)

```bash
gcc -c sqlite/sqlite3.c -o sqlite3.o
```

### 3. Compile the C++ files

```bash
g++ main.cpp \
config/Database.cpp \
utils/Account/Account.cpp \
utils/Deposit/Deposit.cpp \
utils/CreateAccount/CreateAccount.cpp \
utils/Login/Login.cpp \
utils/Payment/Payment.cpp \
utils/Transfer/Transfer.cpp \
utils/Receipt/Receipt.cpp \
sqlite3.o \
-o main.exe
```

### 4. Run the program

```bash
./main.exe
```

## 👤 Author

Built and maintained by **Titya Yem**.
This repository is part of my learning journey in C++ and software development.
