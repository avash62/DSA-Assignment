#include <iostream>
using namespace std;

struct Node { int coeff, pow; Node* next; };

int main() {
    Node* p1 = new Node{5,2,new Node{4,1,new Node{2,0,NULL}}};
    Node* p2 = new Node{5,1,new Node{5,0,NULL}};

    Node* res=NULL; Node* tail=NULL;
    while(p1 || p2){
        int c=0,p=0;
        if(p1 && (!p2 || p1->pow>p2->pow)){
            c=p1->coeff; p=p1->pow; p1=p1->next;
        } else if(p2 && (!p1 || p2->pow>p1->pow)){
            c=p2->coeff; p=p2->pow; p2=p2->next;
        } else {
            c=p1->coeff+p2->coeff; p=p1->pow;
            p1=p1->next; p2=p2->next;
        }
        Node* n=new Node{c,p,NULL};
        if(!res) res=n; else tail->next=n;
        tail=n;
    }

    Node* t=res;
    while(t){ cout<<"["<<t->coeff<<","<<t->pow<<"] "; t=t->next; }
}
