# Cross-Platform TCP Image Transfer

## Overview

This project demonstrates image transfer between a Linux client and a Windows server using TCP sockets in C++. The client reads an image, encodes it using Base64, and sends it over the network. The server receives the encoded data, decodes it, and reconstructs the original image.

The project was developed to understand socket programming, cross-platform networking, and reliable data transfer using TCP.

---

## Features

* Cross-platform communication (Linux client and Windows server)
* Image transfer over TCP
* Base64 encoding and decoding
* Binary file handling
* Winsock2 implementation on Windows
* POSIX socket implementation on Linux
* Dynamic data reception based on transmitted file size

---

## Technologies Used

* C++
* TCP Sockets
* Winsock2 (Windows)
* POSIX Sockets (Linux)
* File Streams
* Base64 Encoding/Decoding

---

## Project Structure

```text
.
├── client.cpp
├── server.cpp
└── README.md
```

---

## How It Works

1. The client reads an image file in binary mode.
2. The image is encoded into a Base64 string.
3. The client sends the size of the encoded data.
4. The client sends the encoded data over a TCP connection.
5. The server first receives the data size.
6. The server continues receiving data until the complete message is received.
7. The received Base64 string is decoded back into binary.
8. The reconstructed image is saved as `image_decoded.jpg`.

---

## Building

### Linux Client

Compile using:

```bash
g++ client.cpp -o client
```

### Windows Server

Compile using MinGW:

```bash
x86_64-w64-mingw32-g++ server.cpp -o server.exe -lws2_32 -static
```

---

## Running

### Server

Run the Windows executable first.

```
server.exe
```

### Client

Run the Linux client.

```
./client
```

Enter the path of the image when prompted.

Example:

```
Enter the location of image file:
> sample.jpg
```

---

## Future Improvements

* Support transfer of any file type
* Add progress reporting
* Allow multiple file transfers in one session
* Add encryption for secure communication
* Improve error handling
* Add a graphical user interface

