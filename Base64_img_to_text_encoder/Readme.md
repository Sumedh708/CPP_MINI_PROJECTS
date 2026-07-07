#  Custom Base64 Image Encoder

Have you ever wondered how an image can be converted entirely into plain text and embedded directly inside an HTML file, or sent across a network without getting corrupted? That is exactly what this project does.

This is a lightweight, zero-dependency command-line utility built in standard C++. It reads any raw image file from your disk and translates it into a web-ready Base64 text stream. Instead of taking a pre-made library off the shelf, I implemented the core bit-shifting mechanics and binary-stream parsing completely from scratch.

---

##  How the Algorithm Works (The Deep Dive)

Computer memory treats images as a raw sequence of 8-bit blocks (bytes). However, legacy network protocols and text files don't handle raw binary data gracefully. Base64 bridges this gap by mapping raw bytes to a safe alphabet of 64 visible text characters (`A-Z`, `a-z`, `0-9`, `+`, `/`).

The main engineering challenge here is a structural mismatch:
* **Raw data** uses **8 bits** per unit.
* **Base64** uses **6-bit indices** to select characters.

To solve this, my code groups **3 raw bytes (24 bits)** together and slices them into **4 clean, 6-bit pieces** using low-level bitwise operations.



### Handling the Tricky Edge Cases:
What happens if the image ends and you have 1 or 2 awkward bytes left over? That's where the **cleanup phase** in my code comes in:
1. **The Shift & Mask:** The expression `((str << 8) >> (i + 8)) & 0x3F` dynamically shifts those trailing, hanging bits to the right edge and pads the remainder with zeros to forge a complete 6-bit chunk.
2. **The Padding:** If the final encoded string length isn't a multiple of 4, the program manually appends `=` padding characters to keep the structural format valid for standard web decoders.

---

##  Key Technical Highlights

* **Tapping the Raw Stream:** Instead of standard text-reading formats that discard characters like tabs (`\n`) or spaces, I used `std::istreambuf_iterator<char>`. This targets the unformatted hardware stream buffer directly, ensuring that every single byte of the image flows into memory completely unaltered.
* **The Unsigned Fix:** Standard loops using plain `char` can cause severe data corruption due to "sign extension" (where values above 127 are accidentally interpreted as negative numbers). Forcing the loop to process `unsigned char` guarantees smooth, predictable mathematical shifts from 0 to 255.
* **Proactive Resource Management:** The image file stream is explicitly shut down via `file.close()` the exact millisecond the data buffer finishes loading, ensuring zero memory leaks or locked file handles.
