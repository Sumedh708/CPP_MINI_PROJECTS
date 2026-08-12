# CPP_MINI_PROJECTS

Welcome to my repository! This is a curated collection of simple, lightweight terminal utilities built using C++ to practice algorithmic logic, data validation, and clean coding practices.

---

##  Current Projects

###  1. Credit Card Validator (Luhn Algorithm)
* **What it does:** Validates any 16-digit credit card number using an optimized implementation of the Luhn Algorithm.
  
###  2. Custom Base64 Image Encoder
* **What it does:** Reads raw image files (`.png`, `.jpg`, etc.) byte-by-byte in binary mode and translates them into serialized, web-ready Base64 text streams.
* **Key Concepts:** Low-level bitwise shifting (`<<`, `>>`), hexadecimal masking (`& 0x3F`), unformatted stream buffer management, and custom boundary data padding.

### 3. Custom Base64 Image Decoder
- **What it does:** Reads a Base64-encoded text file, decodes it back into its original binary format, and reconstructs the image.
- **Key Concepts:** Base64 lookup tables, bitwise operations, binary file writing, stream iterators, and byte reconstruction from 6-bit groups.

### 4. Cross-Platform TCP Image Transfer
- **What it does:** Transfers an image from a Linux client to a Windows server over a TCP connection. The client encodes the image into Base64, transmits it along with its size, and the server reconstructs the original image after receiving the complete data.
- **Key Concepts:** TCP socket programming, POSIX sockets (Linux), Winsock2 (Windows), cross-platform communication, binary file handling, Base64 encoding/decoding, network byte order (htonl()/ntohl()), and reliable data reception using multiple recv() calls.

### 5. Cross-Platform Image Transfer
* **What it does:** Transfers image data between systems using network sockets.

### 6. LRU Cache
* **What it does:** Implements a Least Recently Used cache using a doubly linked list and `std::unordered_map`.
---

##  How to Run

1. **Install the compiler:** Install the respective C++ compiler (`g++`) depending on your OS.
2. **Compile the code:** Open your terminal in the project folder and run:
   ```bash
   g++ main.cpp -o main
   ```
3. **Run the executable: **
   Windows:
   
    ```bash
      main.exe
    ```
   Linux:
    
     ```bash
      ./main
    ```   
