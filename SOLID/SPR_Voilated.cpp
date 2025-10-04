#include<bits/stdc++.h>

using namespace std;

class Product{
    public:
    string name;
    double price;

    Product(string name,double price){
        this->name =  name;
        this->price = price;
    }
};

class ShippingCart {
    private:
    vector<Product*> products;

    public:
    void addProduct(Product* product){
        products.push_back(product);
    }

    double calculateTotalBill(){
        double total =0;
        for(auto p:products){
            total+= p->price;
        }
        return total;
    }

    void printInvoice(){
        cout<<"Invoice"<<endl;
        for(auto p:products){
            cout<<p->name<<" : "<<p->price<<endl;
        }
        cout<<"Total Bill : "<<calculateTotalBill()<<endl;
    }

    void dbConnection(){
       cout<<"Connecting to database"<<endl;
    }

};
int main(){


    ShippingCart* cart = new ShippingCart();
    Product* p1 = new Product("Product1",100);
    Product* p2 = new Product("Product2",200);
    cart->addProduct(p1);
    cart->addProduct(p2);
    cart->printInvoice();
    cart->dbConnection(); // Violation of Single Responsibility Principle

    return 0;
}