#include <iostream>


struct Node {
    int data{0};
    Node* prev, *next;
    Node(const int& data) : data(data), prev(nullptr), next(NULL) {}
 int& get_ref_data() { return data; }
}; 
 class DoubleList {
    Node* head{nullptr}, *tail{nullptr};
    int size{0};
    public:
    Node* get_at_index(int idx) { 
        if(idx < 0 || idx >= size) 
        return nullptr;
        int n = 0 ;
         Node* curr = head;
         while(n < idx) {
            curr = curr->next;
            n++;
         }
         return curr;
    }
    Node* push_back(const int& value) { 
        Node* new_node = new Node(value);
        if(head == nullptr) {
      head = tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
        }
        tail = new_node;
        size++;
        return new_node;
    }
      Node* push_front(const int& value) { 
        Node* new_node = new Node(value);
        if(head == nullptr) {
            head = tail = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
        }
        head = new_node;
        size++;
        return new_node;
    }
   

    void pop_front() { 
        if(!head) return;
         Node* old_head = head;
        if(head == tail) {
            delete head;
            head = tail = nullptr;
            size = 0;
            return;
        }
            head = head -> next;
            head -> prev = nullptr;
            delete old_head;
            size--;
    }
     void show_list() const {
        Node* current = head;
        while(current) { 
            std::cout << current -> data << " ";
            current = current->next;
        }
        std::cout << std::endl;
        std::cout << " Current size_list: " << get_size();
     }
    ~DoubleList() { 
        while(head != nullptr) { 
        pop_front();   
          }
    }
    int get_size() const { return size; }
      void pop_back() { 
        if(head == nullptr) return;
        if(head == tail) {
            delete tail;
            head = tail = nullptr;
            size = 0;
            return;
        }
         Node* old_tail = tail;
         tail = tail -> prev;
         tail-> next = nullptr;
         delete old_tail;
         size--;
      }
        int& operator[](int idx) { 
            Node* node = get_at_index(idx);
            if(!node) throw std::out_of_range("Error 303, invalid idx!!!");
            return node->data;
        }
        void insert(int idx, int& value) { 
            if(idx < 0 || idx > size ) 
            return;
            if(idx == 0) {
                push_front(value);
                return;
            } else if(idx == size) {
                push_back(value);
                return;
            }
             Node* left = get_at_index(idx);
             Node* right = left->next;
             Node* node = new Node(value);
               left->next = node;
               node->prev = left;
                node->next = right;
                  right->prev = node;
                  size++;
        } 
         void erase(int idx) { 
             if(idx < 0 || idx >= size ) 
            return;
            if(idx == 0) {
                pop_front();
                return;
            } else if(idx == size - 1) {
                pop_back();
                return;
            }
            Node* target = get_at_index(idx);
             Node* left = target->prev;
             Node* right = target->next;
              left->next = right;
              right->prev = left;
              target->next = nullptr;
              delete target;
              size--;                 
         }
 };



int main(void) {
DoubleList lst;
lst.push_back(13);
lst.push_back(40);
lst.push_front(32);
lst.push_front(331);
// lst.show_list();
lst[2] = 55;
lst[0] = 666;
  std::cout << "\n";
lst.show_list(); 
 // Thanks for watching my code-vibe, gl) 0_o
}



