/ Queue as an ADT should always be implemented using circular arrays or there will be chance of waste of a lot of space./

#include <iostream>
using namespace std;
#define MAX 100

class Queue{
  private:
  int front;
  int rear;
  int arr[MAX];

  public:
  Queue(){
    front = -1;
    rear = -1;
  }

  void Enque(int x);
  int Deque();
  int peekFront();
};

void Queue::Enque(int x){
  if(front == -1 && rear ==-1){
    front = 0;
    rear = 0;
    arr[rear] = x;
  }
  else if( rear+1%MAX == front  ){
    cout<<"Overflow";
  }
  else{
    rear = rear +1;
    rear = rear % MAX;
    arr[rear] = x;
  }
}

int Queue::Deque(){
  if(front > rear){
      cout<<"Queue Underflow.";
      front = -1;
      rear = -1;
      return 0;
  }
  else{
    int x = arr[front];
    front = front + 1;
    front = front % MAX;
    return x;
  }
}

int Queue::peekFront(){
  if( front > rear ||  (front == -1 && rear == -1)  ){
    cout<<"Queue Underflow";
    return 0;
  }
  else{
    return arr[front];
  }
  return 0;
}

int main() {
  Queue q;
  q.Enque(2);
  cout<<q.peekFront()<<endl;
  q.Enque(3);
  cout<<q.peekFront()<<endl;
  cout<<q.Deque()<<endl;
  cout<<q.Deque()<<endl;
  cout<<q.Deque()<<endl;
  cout<<q.peekFront();
  
}
