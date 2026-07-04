#include <iostream>
#include <string>
#include <algorithm>

//checking if credit card number is valid using luhn algorithm
int check_valid(std::string num){
    num.erase(std::remove(num.begin(), num.end(), ' '), num.end());     //remove all whitespaces
    if(num.length()==16){
        int i,sum=0,j=1;
        std::string sums="";
        for(i=14;i>=0;i-=2)
            sums+=std::to_string(2*(num[i]-'0'));   //doubling every alternate digit from right(end) to left(start) and adding naother string

        for(char l:sums){
            sum+=(l-'0');   //calculate sum of each doubled digit
            if(j>15)
                continue;
            sum+=(num[j]-'0');  //adding rest of the digits as it is to sum
            j+=2;
        }
        if(sum%10==0)
            return 0;
    }
    return -1;  //credit card number is invalid if number of digit not equal to 16 or does not satisfy luhn's algorithm
}
int main()
{
    std::string num;
    while(true){
        std::cout << "Enter your 16 credit card number: ";
        std::getline(std::cin,num);    //taking input in string for easy indexing
        if(check_valid(num)!=-1){
            std::cout << "\nYour credit card number is valid!"<<std::endl;
            break;
        }
        else{
            std::cout <<"\nYour credit card number is invalid!Try again\n\n"<<std::endl;
        }
    }
    return 0;

}
