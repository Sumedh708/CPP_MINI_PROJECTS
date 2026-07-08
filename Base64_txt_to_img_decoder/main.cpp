#include<iostream>
#include<fstream>
#include<string>
#include<vector>

// Decodes a Base64-encoded string into its original binary data.
std::string base64decode(const std::string &in){
    int str=0,p=-8; //str->acts like container where all characters from input string are stored. p-> stores number of available bits to group
    std::string out;    // resultant decoded string
    const std::string chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::vector<int> T(256, -1);
    // Create a lookup table that maps each Base64 character
    // to its corresponding 6-bit value (0-63).
    for (int i = 0; i < 64; i++) T[chars[i]] = i;
    //main loop starts from here to group into 8 bits each
    for(unsigned char c: in){
        if(c=='=')
            //ignoring rest of the '=' signs(which we added during encoding) and coming out of loop
            break;
        if (T[c] == -1)
            //ignoring newline or unnecessary white spaces
            continue;
        str = (str<<6)+T[c];  //'<<' makes room for incoming 6 bits
        p+=6;   //6 bits added so 6 bits available to decode
        if(p>=0){
            // Once at least 8 bits are available, extract one byte.
            // 0xFF masks the lowest 8 bits after shifting.
            out.push_back(char((str >> p) & 0xFF));
            p-=8;

        }
    }

    return out;
}

//Read text file(binary mode) and decode it back to its image
void convert_txt_to_img(std::string& txt){
    std::ifstream file(txt, std::ios::binary);
    if(!file.is_open()){
        std::cout << "Oh no!!Error in opening the txt"<<std::endl;
        return;
    }

    //dumps entire file content from stream to this string
    std::string rawBuff((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());
    file.close();
    std::string decodedRawData = base64decode(rawBuff);
    std::ofstream imageFile("image_decoded.jpg", std::ios::binary);
    if (!imageFile.is_open()) {
        std::cerr << "Error: Could not create the output image file." << std::endl;
        return;
    }

    // 5. Write the raw bytes and close
    imageFile.write(decodedRawData.data(), decodedRawData.size());
    imageFile.close();
    std::cout << "image_decoded.jpg file created successfully";

}

//main prg
int main(){
std::string fname;
std::cout << "Enter the location of encoded txt file: \n> ";
std::cin >> fname;
convert_txt_to_img(fname);
}

