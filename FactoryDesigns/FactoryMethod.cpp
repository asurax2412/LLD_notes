#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

/**
 * FACTORY METHOD PATTERN IMPLEMENTATION
 * 
 * The Factory Method pattern is a creational design pattern that provides
 * an interface for creating objects in a superclass, but allows subclasses
 * to alter the type of objects that will be created.
 * 
 * Key Components:
 * 1. Product Interface (Burger) - Abstract base class for products
 * 2. Concrete Products - Specific implementations (Basic, Standard, Premium, Wheat variants)
 * 3. Creator Interface (BurgerFactory) - Abstract factory class
 * 4. Concrete Creators (SinghBurger, KingBurger) - Specific factory implementations
 * 5. Client (main) - Uses factories to create products
 * 
 * Key Difference from Simple Factory:
 * - Uses inheritance and polymorphism
 * - Each concrete factory creates a family of related products
 * - More flexible and follows Open/Closed Principle
 */

/**
 * @brief Abstract base class representing a Burger
 * 
 * This is the Product interface in the Factory Method pattern.
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
 * This is a Concrete Product in the Factory Method pattern.
 * It represents the most basic type of regular burger with standard ingredients.
 * Part of the SinghBurger product family.
 */
class BasicBurger : public Burger{
    public:
    /**
     * @brief Implementation of burger preparation for basic burger
     * 
     * This method provides the specific preparation process for a basic regular burger.
     * It overrides the pure virtual method from the base class.
     */
    void prepration() override{
        cout<<"we are prepare basic burger for you please wait!!!"<<endl;
    }
    
};

/**
 * @brief Concrete implementation of Burger - Standard Burger
 * 
 * This is a Concrete Product in the Factory Method pattern.
 * It represents a standard regular burger with additional ingredients compared to basic.
 * Part of the SinghBurger product family.
 */
class StandardBurger : public Burger{
    public:
    /**
     * @brief Implementation of burger preparation for standard burger
     * 
     * This method provides the specific preparation process for a standard regular burger.
     * It overrides the pure virtual method from the base class.
     */
    void prepration() override{
        cout<<"we are prepare Standard burger for you please wait!!!"<<endl;
    }
    
};

/**
 * @brief Concrete implementation of Burger - Premium Burger
 * 
 * This is a Concrete Product in the Factory Method pattern.
 * It represents the highest quality regular burger with premium ingredients.
 * Part of the SinghBurger product family.
 */
class PremiumBurger : public Burger{
    public:
    /**
     * @brief Implementation of burger preparation for premium burger
     * 
     * This method provides the specific preparation process for a premium regular burger.
     * It overrides the pure virtual method from the base class.
     */
    void prepration() override{
        cout<<"we are prepare premium burger for you please wait!!!"<<endl;
    }
    
};

/**
 * @brief Concrete implementation of Burger - Basic Wheat Burger
 * 
 * This is a Concrete Product in the Factory Method pattern.
 * It represents the most basic type of wheat burger with standard wheat ingredients.
 * Part of the KingBurger product family.
 */
class BasicWheatBurger : public Burger{
    public:
    /**
     * @brief Implementation of burger preparation for basic wheat burger
     * 
     * This method provides the specific preparation process for a basic wheat burger.
     * It overrides the pure virtual method from the base class.
     */
    void prepration() override{
        cout<<"we are prepare basic Wheat burger for you please wait!!!"<<endl;
    }
    
};

/**
 * @brief Concrete implementation of Burger - Standard Wheat Burger
 * 
 * This is a Concrete Product in the Factory Method pattern.
 * It represents a standard wheat burger with additional wheat ingredients compared to basic.
 * Part of the KingBurger product family.
 * 
 * Note: Class name has a typo (StandarWheatdBurger) but kept for consistency with original code.
 */
class StandarWheatdBurger : public Burger{
    public:
    /**
     * @brief Implementation of burger preparation for standard wheat burger
     * 
     * This method provides the specific preparation process for a standard wheat burger.
     * It overrides the pure virtual method from the base class.
     */
    void prepration() override{
        cout<<"we are prepare Standard Wheat burger for you please wait!!!"<<endl;
    }
    
};

/**
 * @brief Concrete implementation of Burger - Premium Wheat Burger
 * 
 * This is a Concrete Product in the Factory Method pattern.
 * It represents the highest quality wheat burger with premium wheat ingredients.
 * Part of the KingBurger product family.
 */
class PremiumWheatBurger : public Burger{
    public:
    /**
     * @brief Implementation of burger preparation for premium wheat burger
     * 
     * This method provides the specific preparation process for a premium wheat burger.
     * It overrides the pure virtual method from the base class.
     */
    void prepration() override{
        cout<<"we are prepare premium Wheat burger for you please wait!!!"<<endl;
    }
    
};


/**
 * @brief Abstract factory class for creating Burger objects
 * 
 * This is the Creator interface in the Factory Method pattern.
 * It declares the factory method that subclasses must implement to create
 * specific types of burger objects.
 * 
 * Key Features:
 * - Defines the interface for creating products
 * - Allows subclasses to decide which concrete class to instantiate
 * - Follows the Open/Closed Principle
 */
class BurgerFactory {
    public:
    /**
     * @brief Pure virtual factory method to create Burger objects
     * 
     * @param type String representing the type of burger to create
     * @return Burger* Pointer to the created burger object
     * 
     * This method must be implemented by concrete factory classes.
     * Each concrete factory will create its own family of products.
     */
    virtual Burger* createBurger(string& type) = 0;
    
    /**
     * @brief Virtual destructor for proper cleanup
     * 
     * Virtual destructor ensures that derived class destructors
     * are called when deleting objects through base class pointers.
     */
    virtual ~BurgerFactory() = default;
};


/**
 * @brief Concrete factory for creating regular burger variants
 * 
 * This is a Concrete Creator in the Factory Method pattern.
 * It implements the factory method to create regular burger products
 * (Basic, Standard, Premium) as part of the SinghBurger product family.
 * 
 * Product Family: Regular Burgers
 * - BasicBurger: Basic regular burger
 * - StandardBurger: Standard regular burger  
 * - PremiumBurger: Premium regular burger
 */
class SinghBurger : public BurgerFactory{
    public:
    /**
     * @brief Factory method implementation for regular burger creation
     * 
     * @param type String representing the type of regular burger to create
     * @return Burger* Pointer to the created regular burger object, or nullptr if invalid type
     * 
     * This method creates regular burger variants:
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
 * @brief Concrete factory for creating wheat burger variants
 * 
 * This is a Concrete Creator in the Factory Method pattern.
 * It implements the factory method to create wheat burger products
 * (BasicWheat, StandardWheat, PremiumWheat) as part of the KingBurger product family.
 * 
 * Product Family: Wheat Burgers
 * - BasicWheatBurger: Basic wheat burger
 * - StandarWheatdBurger: Standard wheat burger
 * - PremiumWheatBurger: Premium wheat burger
 */
class KingBurger : public BurgerFactory{
    public:
    /**
     * @brief Factory method implementation for wheat burger creation
     * 
     * @param type String representing the type of wheat burger to create
     * @return Burger* Pointer to the created wheat burger object, or nullptr if invalid type
     * 
     * This method creates wheat burger variants:
     * - "basic" -> creates BasicWheatBurger
     * - "standard" -> creates StandarWheatdBurger
     * - "premium" -> creates PremiumWheatBurger
     * - any other value -> returns nullptr and prints error message
     */
    Burger* createBurger(string& type){
        if(type == "basic"){
            return new BasicWheatBurger();
        }
        else if(type == "standard"){
            return new StandarWheatdBurger();
        }
        else if(type == "premium"){
            return new PremiumWheatBurger();
        }else{
            cout<<"Invalid Burger Type, Please Enter Valid Input"<<endl;
            return nullptr;
        }
    }
    
};

/**
 * @brief Main function demonstrating Factory Method pattern usage
 * 
 * This function acts as the Client in the Factory Method pattern.
 * It demonstrates how to use different concrete factories to create
 * different families of products without knowing the specific concrete classes.
 * 
 * Key Demonstration Points:
 * - Polymorphism: Client works with factory interface, not concrete factories
 * - Product Families: Different factories create different product variants
 * - Flexibility: Easy to switch between different factory implementations
 */
int main() 
{
    // Test data for different burger types
    string type1 = "basic";      // Valid type
    string type2 = "premium";    // Valid type  
    string type3 = "meal";       // Invalid type (for error handling demonstration)
    string type4 = "standard";   // Valid type
    
    // Demonstrate Factory Method pattern
    // Client works with factory interface, not concrete factory classes
    // This allows for easy switching between different product families
    
    // Create KingBurger factory (creates wheat burger family)
    BurgerFactory* burgerobj = new KingBurger();
   
    // Use the factory to create a product
    // The client doesn't need to know about concrete product classes
    Burger* create = burgerobj->createBurger(type4);
    
    // Use the created object through the common interface
    if(create != nullptr) {
        create->prepration(); // This will call PremiumWheatBurger::prepration()
        
        // Clean up memory (important for proper resource management)
        delete create;
    }
    
    // Demonstrate switching to different factory
    // SinghBurger factory creates regular burger family
    BurgerFactory* singhFactory = new SinghBurger();
    Burger* regularBurger = singhFactory->createBurger(type1);
    
    if(regularBurger != nullptr) {
        regularBurger->prepration(); // This will call BasicBurger::prepration()
        delete regularBurger;
    }
    
    // Clean up factories
    delete burgerobj;
    delete singhFactory;

    return 0;
}
