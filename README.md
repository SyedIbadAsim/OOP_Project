# 🍽️ UniQuick - Restaurant Management System

UniQuick is a console-based Restaurant Management System developed in **C++** as a second-semester Object-Oriented Programming (OOP) project. The system simulates the food ordering and table booking services available at FAST University restaurants, providing an interactive and user-friendly experience.

---

## 📌 Project Overview

UniQuick allows students to:

* Create and manage accounts
* Browse menus from different FAST restaurants
* Place food orders
* View billing with discounts
* Make secure payments
* Book restaurant tables
* Manage restaurant data through file handling

The project demonstrates the practical implementation of Object-Oriented Programming concepts including:

* Classes and Objects
* Inheritance
* Polymorphism
* Encapsulation
* File Handling
* Function Overloading
* Data Structures (Vectors)

---

## 🚀 Features

### 🔐 User Authentication

#### Sign Up

Users can create a new account by providing:

* Name
* Email Address
* Phone Number
* Username
* Password

Passwords are hashed before being stored for basic security.

#### Login

Existing users can log in using:

* Username
* Password

If authentication fails, users can either retry or create a new account.

---

### 🍔 Restaurant Management

The system includes multiple FAST food outlets:

1. Cafeteria
2. Pizza Fast
3. Fast Dhabba
4. Fast Shawarma
5. Fast Juice Bar

Each restaurant has its own menu loaded dynamically from text files.

---

### 📋 Menu Management

Menus display:

* Item Code
* Item Name
* Price

Menu data is read from external files, making it easy to update without modifying source code.

---

### 🛒 Order Management

Users can:

* Select items using item codes
* Order from multiple restaurants
* Add multiple menu items
* Review their order before confirmation

#### Order Summary

After confirmation, the system generates a bill showing:

* Ordered Items
* Total Price
* 10% Discount
* Final Payable Amount

---

### 💳 Payment System

Supported payment methods:

#### Cash Payment

Simple cash-on-delivery option.

#### Online Payment

Users provide:

* Bank Name
* Account Number
* OTP Verification

The system validates account number and OTP format before processing payment.

---

### 🪑 Table Booking

Users can reserve tables in:

* Cafeteria
* Pizza Fast
* Fast Dhabba

Features:

* Random table availability generation
* View booked tables
* View available tables
* Reserve available tables

---

### 🎨 Console UI Features

Custom console interface includes:

* Colored text output
* Cursor positioning
* Screen clearing
* Animated text display
* Structured menu layouts

Implemented using Windows Console API.

---

## 🛠️ Tech Stack

| Technology     | Purpose                   |
| -------------- | ------------------------- |
| C++            | Core Programming Language |
| OOP Concepts   | System Design             |
| STL Vector     | Data Storage              |
| File Handling  | Menu & User Data Storage  |
| Windows API    | Console UI Management     |
| Hash Functions | Password Encryption       |
| Text Files     | Persistent Storage        |

---

## 📂 Project Structure

```text
UniQuick/
│
├── main.cpp
├── Cafeteria.txt
├── Pizza_Fast.txt
├── Fast_Dhabba.txt
├── Fast_Shawarma.txt
├── Fast_Juice_Bar.txt
├── Uniquick_User_Data.txt
└── README.md
```

---

## 📄 Data Files

### Menu Files

The following files store menu information:

* Cafeteria.txt
* Pizza_Fast.txt
* Fast_Dhabba.txt
* Fast_Shawarma.txt
* Fast_Juice_Bar.txt

Format:

```text
ITEM_CODE ITEM_NAME PRICE
```

Example:

```text
CF101 Burger 350
CF102 Sandwich 250
CF103 Tea 100
```

### User Data File

```text
Uniquick_User_Data.txt
```

Stores:

```text
username hashed_password
```

---

## ⚙️ How to Run

### Prerequisites

* Windows Operating System
* C++ Compiler (GCC / MinGW)
* Code::Blocks, Dev-C++, or Visual Studio

---

### Compilation

Using g++:

```bash
g++ main.cpp -o UniQuick
```

---

### Execution

```bash
UniQuick.exe
```

or

```bash
./UniQuick
```

---

## 🔑 OOP Concepts Used

### Inheritance

```cpp
class Cafeteria : public Restuarants
class Pizza_Fast : public Restuarants
class Fast_Dhabba : public Restuarants
```

### Polymorphism

Virtual functions are used for:

```cpp
virtual void booking_table()
```

### Encapsulation

User data and authentication logic are encapsulated within the `User` class.

### Abstraction

Restaurant operations are managed through a common base class:

```cpp
class Restuarants
```

---

## 📈 Future Improvements

* Admin Dashboard
* Inventory Management
* Real Database Integration (MySQL)
* QR Code Payments
* GUI Version using Qt
* Online Food Delivery Module
* Sales Reports and Analytics
* Password Recovery System

---

## 📜 License

This project was developed for educational purposes as part of an Object-Oriented Programming course project.
