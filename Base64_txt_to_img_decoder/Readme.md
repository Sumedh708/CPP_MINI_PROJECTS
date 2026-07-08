# Custom Base64 Image Decoder

## Overview

This project is a simple C++ implementation of a Base64 image decoder. It reads a Base64-encoded text file, decodes the encoded data back into its original binary form, and recreates the image.

The project was developed to understand how Base64 decoding works internally without relying on any external libraries. Instead of using built-in functions, the decoding process is implemented manually using bitwise operations and a custom lookup table.

---

## Features

- Decodes Base64-encoded image data.
- Reconstructs the original image in binary format.
- Uses only the C++ Standard Library.
- Demonstrates manual implementation of the Base64 decoding algorithm.

---

## Concepts Used

- File handling (`ifstream` and `ofstream`)
- Binary file processing
- Bitwise operations (`<<`, `>>`, `&`)
- Lookup tables
- Stream iterators
- String manipulation
- Base64 decoding algorithm

---

## How It Works

1. The program reads the contents of a Base64-encoded text file.
2. Each Base64 character is converted into its corresponding 6-bit value using a lookup table.
3. These 6-bit values are combined to reconstruct the original 8-bit bytes.
4. The decoded bytes are written into a new image file named `image_decoded.jpg`.

---

The program will prompt for the path of the Base64 text file.

Example:

```
Enter the location of encoded txt file:
> encoded.txt
```

After successful execution, the decoded image will be saved as:

```
image_decoded.jpg
```

---

## Note

This implementation assumes that the Base64 text represents a JPEG image. The decoded output is always saved as `image_decoded.jpg`.
