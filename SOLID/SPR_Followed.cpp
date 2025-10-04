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

class ShippingCart{
    private:
    vector<Product*> products;

    public:
    void addProduct(Product* product){
        products.push_back(product);
    }
    
    const vector<Product*>& getProducts() { 
        return products;
    } 

    double calculateTotalBill(){
        double total =0;
        for(auto p:products){
            total+= p->price;
        }
        return total;
    }
};

class InvoicePrinter{
    private:
    ShippingCart* cart;

    public:
    InvoicePrinter(ShippingCart* cart){
        this->cart =  cart;
    }

    void printInvoice(){
        cout<<"Invoice"<<endl;
        for(auto p:cart->getProducts()){
            cout<<p->name<<" : "<<p->price<<endl;
        }
        cout<<"Total Bill : "<<cart->calculateTotalBill()<<endl;
    }
};



class dbConnection{
    private:
    ShippingCart* cart;

    public:
    dbConnection(ShippingCart* cart){
        this->cart = cart;
    }
    
    void DBConnection(){
       cout<<"Connecting to database"<<endl;
    }

};



int main(){


    ShippingCart* cart = new ShippingCart();
    Product* p1 = new Product("Product1",100);
    Product* p2 = new Product("Product2",200);
    cart->addProduct(p1);
    cart->addProduct(p2);

    InvoicePrinter* printer = new InvoicePrinter(cart);
    dbConnection* dbConn = new dbConnection(cart);


    printer->printInvoice();
    dbConn->DBConnection(); // Violation of Single Responsibility Principle

    return 0;
}