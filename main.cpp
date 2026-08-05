#include<iostream>
#include<string>

class Node{
    public:
        std::string url;
        Node* next;
    public:
        Node(std::string cur_url){
            url=cur_url;
            next=nullptr;
        }
        Node(std::string cur_url,Node* nexturl){
            url=cur_url;
            next=nexturl;
        }
};
//browser implemented using 2 stacks
class BrowserHistory{
    std::string current_page;
    Node* back_head = NULL; 
    Node* next_head = NULL;
    public:
        BrowserHistory(){
            current_page="www.sumedh.com";
            back_head = nullptr; //used to go previous page
            next_head = nullptr; //used to go next page
        }
        std::string open_web(std::string url){
            
            if(back_head==NULL){
                back_head = new Node(current_page);
                current_page = url;
                return current_page;
            }
            Node* temp;
            //delete the next stack once you visit a website
            while(next_head!=NULL){
                temp=next_head;
                next_head=next_head->next;
                delete temp;
            }
            back_head= new Node(current_page,back_head);
            current_page=url;
            return current_page;
        }
        std::string go_prev(){
            if(back_head!=NULL){
                std::string pop = back_head->url;
                //add current page to next stack to go next
                if(next_head==NULL){
                    next_head = new Node(current_page);
                }
                else{
                    next_head= new Node(current_page,next_head);
                }
                Node* remove=back_head;
                back_head=back_head->next;
                delete remove;
                current_page=pop;
                return pop;
            }
            return current_page;
        }
        std::string go_next(){
            if(next_head!=NULL){
                std::string pop = next_head->url;
                //add current page to go back once next
                if(back_head==NULL){
                    back_head = new Node(current_page);
                }
                else{
                    back_head= new Node(current_page,back_head);
                }
                Node* remove=next_head;
                next_head=next_head->next;
                delete remove;
                current_page=pop; 
                return pop;
            }
            return current_page;
        }
        std::string print(){
            return current_page;
        }

};

//main program only consisting of methods and menu driven program
int main(){
    BrowserHistory browser;
    std::cout << "##########BROWSER##################"<< std::endl;
    int c=0;
    std::string url;
    while(c!=5){
        std::cout << "\nPls choose any of the options listed:\n1)Open website\n2)go previous\n3)go next\n4)present website\n5)exit"<<std::endl;
        std::cout << "\nPlease enter your choice> ";
        std::cin>>c;
        std::cin.ignore();
        if(c==1){   
            std::cout<< "\nurl> ";
            std::getline(std::cin,url);
            std::cout << "You entered: " << browser.open_web(url)<<std::endl;
        }
        else if(c==2){
            
            std::cout << "You moved to " << browser.go_prev()<<std::endl;
        }
        else if(c==3){
            
            std::cout << "You moved to " << browser.go_next()<<std::endl;
        }
        else if(c==4){
            std::cout << browser.print() << " is your current page\n"<<std::endl;
        }
        else{
            std::cout<< "Please give a valid i/p from 1-5"<< std::endl;
        }
    }
}