#include<iostream>
#include<unordered_map>

class Node{
    public:
        int key;
        int value;
        Node* next;
        Node* prev;
    public:
        Node(int num, int val){
            key = num;
            value = val;
            next = nullptr;
            prev = nullptr;
        }
          
};
//Implementing LRU Cache using double linked list and hash map
class LRUCache{
    private:
        Node* dummy_head = new Node(0, 0);
        Node* mru = dummy_head;
        Node* dummy_tail = new Node(0, 0);
        Node* head = dummy_tail;
        std::unordered_map<int, Node*> cache_map;
        int capacity;
        int size = 0;
    public:
        LRUCache(int cap){
            if(cap <= 0){  
                capacity = 1;
            }
            else{
                capacity = cap;
                size = 0;
            }
        }
        void move_to_mru(Node* node){
                node->prev->next = node->next;
                node->next->prev = node->prev;
                node->next = dummy_tail;
                dummy_tail->prev = node;
                node->prev = mru;
                mru->next = node;
                mru = node;
        }
        //Add an element to cache
        void add(int key,int value){
            //first check if key exists: if yes then update it and mark it most recently used
            auto it = cache_map.find(key);
            if (it != cache_map.end()){
                get(key);
                it->second->value = value;
                return;
            } 
            if(size == capacity){
                Node* del = head;
                head = head->next;
                head->prev = dummy_head;
                dummy_head->next = head;
                cache_map.erase(del->key);
                delete del;
                size--;
            }
            Node* new_node = new Node(key, value);
            new_node->next = dummy_tail;
            new_node->prev = mru;
            dummy_tail->prev = new_node;
            if(head == dummy_tail){
                head = new_node;   
                head->next=dummy_tail; 
            }    
            mru = new_node;
            size++;
            cache_map[key] = mru;
            }
            
        
        void print(){
            if(head == nullptr){
                std::cout << "Nothing stored\n";
            }
            else{
                Node* temp = head;
                while(temp!=dummy_tail){
                    std::cout << temp->key << ": " << temp->value << std::endl;
                    temp = temp->next;
                }
            }
        }
        int get(int key){
            auto it = cache_map.find(key);
            if (it != cache_map.end()) {
                Node* node = it->second;
                if(node == mru){
                    return node->value;
                }
                if(node == head)
                    head = head->next;
                move_to_mru(node);
                return node->value;
            }
            else{
                return -1;
            }
        }
        ~LRUCache(){
            Node* temp = dummy_head;
            while(temp != nullptr){
                Node* next = temp->next;
                delete temp;
                temp = next;
            }
        }
};
int main(){
    LRUCache cache(3);
    std::cout << "################### LRU CACHE ###################" << std::endl;
    cache.add(1,100);
    cache.add(2,70);
    cache.add(3,430);
    int val = cache.get(1);
    cache.print();
    return 0;
}