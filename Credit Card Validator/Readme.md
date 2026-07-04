# 💳 Credit Card Validator (Luhn Algorithm)

This is a lightweight terminal utility that checks whether a 16-digit credit card number is visually valid using the classic **Luhn Algorithm** (also known as the "Mod 10" algorithm). 

---

## ✨ Features

* **Smart Space Stripping:** Automatically handles credit card numbers typed with spaces (e.g., `4111 1111 1111 1111`) using the C++ erase-remove idiom.
* **Optimized Single-Loop Execution:** Processes the mathematical validation of both doubled and untouched digits within a single efficient loop constraint.
* **Safe Input Handling:** Employs `std::getline` to capture complete terminal input lines without breaking the console input buffers.

---

## 🧠 How the Algorithm Works

1. Starting from the rightmost digit and moving left, every coordinate position's alternate digit is multiplied by 2.
2. If doubling a digit results in a two-digit number (greater than 9, like $7 \times 2 = 14$), the individual digits are summed up ($1 + 4 = 5$).
3. All the resulting values and the remaining untouched digits are added together.
4. If the final total sum is perfectly divisible by 10 (`sum % 10 == 0`), the card number is mathematically valid.

---

## 📂 Project Structure

* `main.cpp` - The complete source code containing the validation engine and interactive user input loop.
