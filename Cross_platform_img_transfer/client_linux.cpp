#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include<fstream>
#include<string>
#include<vector>
#include<cstring>

using namespace std;

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

//Read image file(binary mode) and convert to txt
std::string convert_img_to_txt(std::string& img){
    std::ifstream file(img,std::ios::binary);
    if(!file.is_open()){
        std::cout << "Oh no!!Error in opening the image"<<std::endl;
        return "no file";
    }

    //dumps entire file content from stream to this string
    std::string rawBuff((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());
    file.close();


    return base64encode(rawBuff);  //string is encoded

}

int main()
{
    std::string fname;
    std::cout << "Enter the location of image file: \n> ";
    std::cin >> fname;

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    inet_pton(AF_INET, "192.168.29.131", &server.sin_addr);

    connect(sock, (sockaddr*)&server, sizeof(server));

    std::string msg = convert_img_to_txt(fname);
    int buffsize = msg.size();
    int buffval = htonl(buffsize);
    send(sock, &buffval, sizeof(buffval), 0);
    cout << "sent size: "<< buffsize;
    send(sock, msg.data(), msg.size(), 0);


    close(sock);

    return 0;
}
