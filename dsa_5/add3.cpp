#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

int main() {
    Node* n1=new Node{1,NULL};
    Node* n2=new Node{2,NULL};
    Node* n3=new Node{3,NULL};
    Node* n4=new Node{4,NULL};
    n1->next=n2; n2->next=n3; n3->next=n4; n4->next=n2; // loop

    Node* slow=n1; Node* fast=n1;
    bool loop=false;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){ loop=true; break; }
    }

    if(loop){
        slow=n1;
        while(slow->next!=fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=NULL;
        cout<<"Loop removed\n";
    } else cout<<"No loop\n";
}
