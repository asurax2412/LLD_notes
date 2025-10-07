#include <bits/stdc++.h>
#define ll long long int 
using namespace std;


class Singleton{
    private:
    static Singleton* instance ;
    
    Singleton(){
        cout<<"Object created "<<endl;
    }
    
    public:
    static Singleton* getInstace(){
        return instance;
    }
};

//Intialize static members
Singleton* Singleton::instance = new Singleton();

int main() 
{
    
    Singleton* obj1 = Singleton::getInstace();
    Singleton* obj2 = Singleton::getInstace();

   
	return 0;
}
