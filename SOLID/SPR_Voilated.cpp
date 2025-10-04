/*
 * SINGLE RESPONSIBILITY PRINCIPLE (SRP) - VIOLATED EXAMPLE
 * 
 * This file demonstrates a VIOLATION of the Single Responsibility Principle.
 * The ShippingCart class has multiple responsibilities:
 * 1. Managing products in the cart
 * 2. Calculating total bill
 * 3. Printing invoice (UI responsibility)
 * 4. Database connection (Data persistence responsibility)
 * 
 * This violates SRP because a class should have only one reason to change.
 * If we need to change how invoices are printed, how database connections work,
 * or how calculations are done, we'd have to modify the same class.
 */

#include<bits/stdc++.h>

using namespace std;

// Product class - Represents a single product with name and price
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
 * VIOLATION: ShippingCart class has MULTIPLE responsibilities
 * 
 * Responsibilities it handles:
 * 1. ✅ Managing products in cart (addProduct, getProducts) - CORRECT
 * 2. ✅ Calculating total bill - CORRECT (related to cart management)
 * 3. ❌ Printing invoice - WRONG (UI responsibility)
 * 4. ❌ Database connection - WRONG (Data persistence responsibility)
 * 
 * Problems with this design:
 * - If invoice format changes, we modify ShippingCart
 * - If database technology changes, we modify ShippingCart
 * - If printing method changes (e.g., to PDF), we modify ShippingCart
 * - Class becomes harder to test, maintain, and understand
 * - Violates the principle: "A class should have only one reason to change"
 */
class ShippingCart {
    private:
    vector<Product*> products;

    public:
    // ✅ CORRECT: Adding products to cart (core cart responsibility)
    void addProduct(Product* product){
        products.push_back(product);
    }

    // ✅ CORRECT: Calculating total (related to cart management)
    double calculateTotalBill(){
        double total =0;
        for(auto p:products){
            total+= p->price;
        }
        return total;
    }

    // ❌ VIOLATION: Printing invoice is a UI responsibility, not cart responsibility
    void printInvoice(){
        cout<<"Invoice"<<endl;
        for(auto p:products){
            cout<<p->name<<" : "<<p->price<<endl;
        }
        cout<<"Total Bill : "<<calculateTotalBill()<<endl;
    }

    // ❌ VIOLATION: Database connection is a data persistence responsibility
    void dbConnection(){
       cout<<"Connecting to database"<<endl;
    }

};
int main(){
    // Demonstration of SRP violation
    cout << "=== SRP VIOLATION EXAMPLE ===" << endl;
    
    ShippingCart* cart = new ShippingCart();
    Product* p1 = new Product("Product1",100);
    Product* p2 = new Product("Product2",200);
    
    // Adding products to cart (correct responsibility)
    cart->addProduct(p1);
    cart->addProduct(p2);
    
    // ❌ VIOLATION: Cart is doing UI work (printing)
    cart->printInvoice();
    
    // ❌ VIOLATION: Cart is doing database work
    cart->dbConnection(); // Violation of Single Responsibility Principle
    
    cout << "\nNote: This design violates SRP because ShippingCart has multiple responsibilities!" << endl;

    return 0;
}