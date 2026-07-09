#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string.h>


// Decodes a Base64-encoded string into its original binary data.
std::string base64decode(const std::string &in){
    int str=0,p=-8; //str->acts like container where all characters from input string are stored. i-> stores number of available bits to group
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

//Read text and decode it back to its image
void convert_txt_to_img(std::string& txt){

    std::string decodedRawData = base64decode(txt); //convert 6 bits to 8 bits
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

WSADATA wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);

    SOCKET serverSocket, clientSocket;

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (sockaddr*)&server, sizeof(server));

    listen(serverSocket, 5);

    std::cout << "Waiting for client..." << std::endl;

    clientSocket = accept(serverSocket, NULL, NULL);

    std::cout << "Client Connected!" << std::endl;



    int buffsize=0;

    recv(clientSocket, (char*)&buffsize, sizeof(buffsize), 0);
    int buffval = ntohl(buffsize),s=0;
    char buffer[buffval];
    std::cout << "waiting to recieve "<< buffval <<"bytes:\n"<<std::endl;
    std::string res;
    while(buffval>s){
        int pizz=recv(clientSocket, buffer, sizeof(buffer), 0);
        s+=pizz;
        std::cout<<s<<std::endl;
        std::string dat(buffer, pizz);
        res+=dat;
    }
    convert_txt_to_img(res);
    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

}



