#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

/**
 * SIMPLE FACTORY PATTERN IMPLEMENTATION
 * 
 * The Simple Factory pattern is a creational design pattern that provides
 * a way to create objects without specifying their exact class. It encapsulates
 * object creation logic in a factory class.
 * 
 * Components:
 * 1. Product Interface (Burger) - Abstract base class
 * 2. Concrete Products (BasicBurger, StandardBurger, PremiumBurger) - Concrete implementations
 * 3. Factory Class (BurgerFactory) - Creates objects based on input
 * 4. Client (main) - Uses the factory to create objects
 */

/**
 * @brief Abstract base class representing a Burger
 * 
 * This is the Product interface in the Simple Factory pattern.
 * It defines the common interface that all concrete burger types must implement.
 * The virtual destructor and pure virtual method make this an abstract class.
 */
class Burger{
    public:
    /**
     * @brief Pure virtual method for burger preparation
     * 
     * This method must be implemented by all concrete burger classes.
     * It defines the common interface for burger preparation process.
     */
    virtual void prepration() = 0;
    
    /**
     * @brief Virtual destructor for proper cleanup
     * 
     * Virtual destructor ensures that derived class destructors
     * are called when deleting objects through base class pointers.
     */
    virtual ~Burger() = default;
};

/**
 * @brief Concrete implementation of Burger - Basic Burger
 * 
 * This is a Concrete Product in the Simple Factory pattern.
 * It represents the most basic type of burger with standard ingredients.
 */
class BasicBurger : public Burger{
    public:
    /**
     * @brief Implementation of burger preparation for basic burger
     * 
     * This method provides the specific preparation process for a basic burger.
     * It overrides the pure virtual method from the base class.
     */
    void prepration() override{
        cout<<"we are prepare basic burger for you please wait!!!"<<endl;
    }
    
};

/**
 * @brief Concrete implementation of Burger - Standard Burger
 * 
 * This is a Concrete Product in the Simple Factory pattern.
 * It represents a standard burger with additional ingredients compared to basic.
 */
class StandardBurger : public Burger{
    public:
    /**
     * @brief Implementation of burger preparation for standard burger
     * 
     * This method provides the specific preparation process for a standard burger.
     * It overrides the pure virtual method from the base class.
     */
    void prepration() override{
        cout<<"we are prepare Standard burger for you please wait!!!"<<endl;
    }
    
};

/**
 * @brief Concrete implementation of Burger - Premium Burger
 * 
 * This is a Concrete Product in the Simple Factory pattern.
 * It represents the highest quality burger with premium ingredients.
 */
class PremiumBurger : public Burger{
    public:
    /**
     * @brief Implementation of burger preparation for premium burger
     * 
     * This method provides the specific preparation process for a premium burger.
     * It overrides the pure virtual method from the base class.
     */
    void prepration() override{
        cout<<"we are prepare premium burger for you please wait!!!"<<endl;
    }
    
};


/**
 * @brief Factory class for creating Burger objects
 * 
 * This is the Factory class in the Simple Factory pattern.
 * It encapsulates the object creation logic and provides a single method
 * to create different types of burgers based on the input parameter.
 * 
 * Benefits:
 * - Centralizes object creation logic
 * - Makes it easy to add new burger types
 * - Client code doesn't need to know about concrete classes
 */
class BurgerFactory {
    public:
    /**
     * @brief Factory method to create Burger objects
     * 
     * @param type String representing the type of burger to create
     * @return Burger* Pointer to the created burger object, or nullptr if invalid type
     * 
     * This method implements the factory logic:
     * - "basic" -> creates BasicBurger
     * - "standard" -> creates StandardBurger  
     * - "premium" -> creates PremiumBurger
     * - any other value -> returns nullptr and prints error message
     */
    Burger* createBurger(string& type){
        if(type == "basic"){
            return new BasicBurger();
        }
        else if(type == "standard"){
            return new StandardBurger();
        }
        else if(type == "premium"){
            return new PremiumBurger();
        }else{
            cout<<"Invalid Burger Type, Please Enter Valid Input"<<endl;
            return nullptr;
        }
    }
};


/**
 * @brief Main function demonstrating Simple Factory pattern usage
 * 
 * This function acts as the Client in the Simple Factory pattern.
 * It demonstrates how to use the factory to create different types of burgers
 * without knowing the specific concrete classes.
 */
int main() 
{
    // Test data for different burger types
    string type1 = "basic";      // Valid type
    string type2 = "premium";    // Valid type  
    string type3 = "meal";       // Invalid type (for error handling demonstration)
    string type4 = "standard";   // Valid type
    
    // Create factory instance
    // The client only needs to know about the factory, not concrete classes
    BurgerFactory* burgerobj = new BurgerFactory();
   
    // Demonstrate factory usage
    // Client requests a burger through the factory without knowing the concrete class
    Burger* create = burgerobj->createBurger(type4);
    
    // Use the created object through the common interface
    if(create != nullptr) {
        create->prepration();
        
        // Clean up memory (important for proper resource management)
        delete create;
    }
    
    // Clean up factory
    delete burgerobj;

    return 0;
}
