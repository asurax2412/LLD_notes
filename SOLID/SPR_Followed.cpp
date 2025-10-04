/*
 * SINGLE RESPONSIBILITY PRINCIPLE (SRP) - FOLLOWED EXAMPLE
 * 
 * This file demonstrates how to FOLLOW the Single Responsibility Principle.
 * Each class has a single, well-defined responsibility:
 * 1. Product - Represents product data
 * 2. ShippingCart - Manages cart operations only
 * 3. InvoicePrinter - Handles invoice printing (UI responsibility)
 * 4. dbConnection - Handles database operations (Data persistence responsibility)
 * 
 * This follows SRP because each class has only one reason to change.
 * If we need to change how invoices are printed, we only modify InvoicePrinter.
 * If we need to change database operations, we only modify dbConnection.
 */

#include<bits/stdc++.h>

using namespace std;

// Product class - Single responsibility: Represent product data
class Product{
    public:
    string name;
    double price;

    Product(string name,double price){
        this->name =  name;
        this->price = price;
    }
};

/*
 * ✅ FOLLOWING SRP: ShippingCart class has SINGLE responsibility
 * 
 * Responsibility: Managing products in the shopping cart
 * - Adding products to cart
 * - Providing access to products
 * - Calculating total bill (related to cart management)
 * 
 * What it does NOT do:
 * - Printing invoices (handled by InvoicePrinter)
 * - Database operations (handled by dbConnection)
 * 
 * Benefits:
 * - If cart logic changes, only this class needs modification
 * - Easy to test cart functionality in isolation
 * - Clear separation of concerns
 */
class ShippingCart{
    private:
    vector<Product*> products;

    public:
    // ✅ CORRECT: Adding products to cart (core cart responsibility)
    void addProduct(Product* product){
        products.push_back(product);
    }
    
    // ✅ CORRECT: Providing access to products (cart responsibility)
    const vector<Product*>& getProducts() { 
        return products;
    } 

    // ✅ CORRECT: Calculating total (related to cart management)
    double calculateTotalBill(){
        double total =0;
        for(auto p:products){
            total+= p->price;
        }
        return total;
    }
};

/*
 * ✅ FOLLOWING SRP: InvoicePrinter class has SINGLE responsibility
 * 
 * Responsibility: Handling invoice printing (UI responsibility)
 * - Takes a ShippingCart reference
 * - Formats and prints invoice information
 * - Only changes if invoice format requirements change
 */
class InvoicePrinter{
    private:
    ShippingCart* cart;

    public:
    InvoicePrinter(ShippingCart* cart){
        this->cart =  cart;
    }

    // ✅ CORRECT: Printing invoice is this class's only responsibility
    void printInvoice(){
        cout<<"Invoice"<<endl;
        for(auto p:cart->getProducts()){
            cout<<p->name<<" : "<<p->price<<endl;
        }
        cout<<"Total Bill : "<<cart->calculateTotalBill()<<endl;
    }
};

/*
 * ✅ FOLLOWING SRP: dbConnection class has SINGLE responsibility
 * 
 * Responsibility: Handling database operations (Data persistence responsibility)
 * - Takes a ShippingCart reference
 * - Manages database connections
 * - Only changes if database technology or connection logic changes
 */
class dbConnection{
    private:
    ShippingCart* cart;

    public:
    dbConnection(ShippingCart* cart){
        this->cart = cart;
    }
    
    // ✅ CORRECT: Database operations are this class's only responsibility
    void DBConnection(){
       cout<<"Connecting to database"<<endl;
    }

};



int main(){
    // Demonstration of SRP being followed
    cout << "=== SRP FOLLOWED EXAMPLE ===" << endl;
    
    // Create cart and add products (cart's responsibility)
    ShippingCart* cart = new ShippingCart();
    Product* p1 = new Product("Product1",100);
    Product* p2 = new Product("Product2",200);
    cart->addProduct(p1);
    cart->addProduct(p2);

    // Create separate classes for different responsibilities
    InvoicePrinter* printer = new InvoicePrinter(cart);  // UI responsibility
    dbConnection* dbConn = new dbConnection(cart);       // Data persistence responsibility

    // Each class handles its own responsibility
    printer->printInvoice();    // ✅ UI work handled by InvoicePrinter
    dbConn->DBConnection();     // ✅ Database work handled by dbConnection

    cout << "\nNote: This design follows SRP - each class has a single responsibility!" << endl;
    cout << "- ShippingCart: Manages cart operations" << endl;
    cout << "- InvoicePrinter: Handles invoice printing" << endl;
    cout << "- dbConnection: Handles database operations" << endl;

    return 0;
}