#include <iostream>
#include <vector> 
using std::vector;

class Observer {
    
  int id;
 
public:
  Observer( int id ) {
    this->id = id;
  }

  int getId() {
    return id;
  }
  
  void update( int data ) {
    std::cout << "Observer " << this->id << " received notification for update data " << data << "\n";
  }
};


class Subject {

private:
  int data;
  vector< Observer *> notifyList; 

public:
  void subscribe( Observer *observer ) {
    notifyList.push_back( observer );
    std::cout << "Observer " << observer->getId() << " subscribed for update" << "\n";
  }

  void unsubscribe( Observer *observer ) {
    vector< Observer *>::iterator it;
    it = find( notifyList.begin(), notifyList.end(), observer );
    if( it != notifyList.end() ) {
      notifyList.erase( it );
      std::cout << "Observer " << observer->getId() << " un-subscribed for update" << "\n";
    }
  }

  void setData( int _data ) {
    this->data = _data;
    notify();
  }
  
  void notify() {
    vector< Observer *>::iterator it;
    for( it = notifyList.begin(); it != notifyList.end(); ++it ) {
      (**it).update( data );
    }
  }
};

int main() {
  //Observer design pattern

  Subject *subject = new Subject();
  subject->setData( 100 );

  Observer *o1 = new Observer( 1 );
  subject->subscribe( o1 );
  subject->setData( 200 );

  Observer *o2 = new Observer( 2 );
  subject->subscribe( o2 );
  subject->setData( 300 );

  subject->unsubscribe( o2 );
  subject->setData( 400 );
  return 0;
}