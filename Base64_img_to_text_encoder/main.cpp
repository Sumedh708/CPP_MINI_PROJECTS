#include<iostream>
#include<fstream>
#include<string>
#include<vector>

/*here 3 bytes(8bits*3=24bits) are grouped together and converted into group of 4(6 bits each).
each 6 bits are given corresponding ASCII values(0-63) and converted to a character(here defined in string chars)
*/
std::string base64encode(std::string &in){
    int str=0,i=-6; //str->acts like container where all characters from input string are stored. i-> stores number of available bits to group
    std::string out;    // resultant encoded string
    const std::string chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    //main loop starts from here to group into 6 bits each
    for(unsigned char c: in){
        str = (str<<8)+c;  //'<<' makes room for incoming 8 bits
        i+=8;   //8 bits added so 8 bits available to encode
        while(i>=0){
            //0x3F(001111)-> is used to convert the (str>>i) resultant to exact 6 bits..character from chars corresponding to those 6 bits is appended to resultant encoded string out
            out.push_back(chars[(str>>i) & 0x3F]);
            i-=6;
        }
    }
    if(i>-6)
        //remaining bits even after grouping are also encoded a character
        out.push_back(chars[((str<<8) >> (i+8)) & 0x3F]);
    while(out.size()%4)
        //if resultant string length is not a multiple of 4, then '=' is added to group correctly
        out.push_back('=');
    return out;
}

//Read image file(binary mode) and dump encoded data in txt file
void convert_img_to_txt(std::string& img){
    std::ifstream file(img,std::ios::binary);
    if(!file.is_open()){
        std::cerr << "Oh no!!Error in opening the image"<<std::endl;
        return;
    }

    //dumps entire file content from stream to this string
    std::string rawBuff((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());
    file.close();
    std::ofstream outF("image_encoded.txt");
    if (!outF.is_open()) {
        std::cerr << "Error: Could not create output file." << std::endl;
        return;
    }

    outF << base64encode(rawBuff);  //string is encoded and written to file
    std::cout << "image_encoded.txt file created successfully"
    outF.close();
}

//main prg
int main(){
std::string fname;
std::cout << "Enter the location of image file: \n> ";
std::cin >> fname;
convert_img_to_txt(fname);
}
