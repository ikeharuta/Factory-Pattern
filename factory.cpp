#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pizza{
    protected:
        string name;
        string dough;
        string sauce;
        vector<string>toppings;
    public:
        void prepare(){
            cout << "Preparing " << name << endl;
            cout << "Tossing dough..." << dough << endl;
            cout << "push_backing sauce..." <<sauce << endl;
            cout << "push_backing toppings: " << endl;
            for(int i = 0; i <toppings.size(); i++){
                cout << " " << toppings[i] << endl;
            }
        }
        virtual void bake(){
            cout << "Bake for 25 minutes at 350" << endl;
        }
        virtual void cut(){
            cout << "Cutting the pizza into diagonal slices" << endl;
        }
        virtual void box(){
            cout << "Place pizza in official PizzaStore box" << endl;
        }
        string getName(){
            return name;
        }
        virtual ~Pizza(){}
};
class PizzaStore{
    protected:
        virtual Pizza* createPizza(string type) =0;
    public:
    Pizza* orderPizza(string type){
        Pizza* pizza = createPizza(type);
        if(pizza == nullptr){
            throw "Invaid pizza";
        }
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();

        return pizza;
    }
    virtual ~PizzaStore(){}
    
};
class NYStyleCheesePizza: public Pizza{
    public:
        NYStyleCheesePizza(){
            name = "NY Style Sauce and Cheese Pizza";
            dough = "Thin Crust Dough";
            sauce = "Marinara Sauce";
            toppings.push_back("Grated Reggiano Cheese");
        }
};
class NYStylePepperoniPizza: public Pizza{
    public:
        NYStylePepperoniPizza(){
            name = "NY Style Pepperoni Pizza";
            dough = "Thin Crust Dough";
            sauce = "Marinara Sauce";
            toppings.push_back("Grated Reggiano Cheese");
            toppings.push_back("Sliced Pepperoni");
            toppings.push_back("Garlic");
            toppings.push_back("Onion");
            toppings.push_back("Mushrooms");
            toppings.push_back("Red Pepper");
        }
};
class NYStyleClamPizza: public Pizza{
    public:
        NYStyleClamPizza(){
            name = "NY Style Clam Pizza";
            dough = "Thin Crust Dough";
            sauce = "Marinara Sauce";
            toppings.push_back("Grated Reggiano Cheese");
            toppings.push_back("Fresh Clams from Long Island Sound");
        }
};
class NYStyleVeggiePizza: public Pizza{
    public:
        NYStyleVeggiePizza(){
            name = "NY Style Veggie Pizza";
            dough = "Thin Crust Dough";
            sauce = "Marinara Sauce";
            toppings.push_back("Grated Reggiano Cheese");
            toppings.push_back("Garlic");
            toppings.push_back("Onion");
            toppings.push_back("Mushrooms");
            toppings.push_back("Red Pepper");
        }
};

class NYPizzaStore: public PizzaStore{
    public:
        Pizza* createPizza(string type){
            if(type == "cheese"){
                return new NYStyleCheesePizza();
            }else if(type == "pepperoni"){
                return new NYStylePepperoniPizza();
            }else if(type == "clam"){
                return new NYStyleClamPizza();
            }else if(type == "veggie"){
                return new NYStyleVeggiePizza();
            }else{
                return nullptr;
            }
        }
};

class ChicagoStyleCheesePizza: public Pizza{
    public:
        ChicagoStyleCheesePizza(){
            name = "Chicago Style Deep Dish Cheese Pizza";
            dough = "Extra Thick Crust Dough";
            sauce = "Plum Tomato Sauce";
            toppings.push_back("Shredded Mozzarella Cheese");
        }
        void cut(){
            cout << "Cutting the pizza into square slices" << endl;
        }
};
class ChicagoStylePepperoniPizza: public Pizza{
    public:
        ChicagoStylePepperoniPizza(){
            name = "Chicago Style Deep Dish Pepperoni Pizza";
            dough = "Extra Thick Crust Dough";
            sauce = "Plum Tomato Sauce";
            toppings.push_back("Shredded Mozzarella Cheese");
            toppings.push_back("Black Olives");
            toppings.push_back("Spinach");
            toppings.push_back("Eggplant");
            toppings.push_back("Sliced Pepperoni");
        }
        void cut(){
            cout << "Cutting the pizza into square slices" << endl;
        }
};
class ChicagoStyleClamPizza: public Pizza{
    public:
        ChicagoStyleClamPizza(){
            name = "Chicago Style Deep Dish Clam Pizza";
            dough = "Extra Thick Crust Dough";
            sauce = "Plum Tomato Sauce";
            toppings.push_back("Shredded Mozzarella Cheese");
            toppings.push_back("Frozen Clams from Chesapeake Bay");
        }
        void cut(){
            cout << "Cutting the pizza into square slices" << endl;
        }
};
class ChicagoStyleVeggiePizza: public Pizza{
    public:
        ChicagoStyleVeggiePizza(){
            name = "Chicago Style Deep Dish Veggie Pizza";
            dough = "Extra Thick Crust Dough";
            sauce = "Plum Tomato Sauce";
            toppings.push_back("Shredded Mozzarella Cheese");
            toppings.push_back("Black Olives");
            toppings.push_back("Spinach");
            toppings.push_back("Eggplant");
        }
        void cut(){
            cout << "Cutting the pizza into square slices" << endl;
        }
};
class ChicagoPizzaStore: public PizzaStore{
    public:
        Pizza* createPizza(string type){
            if(type == "cheese"){
                return new ChicagoStyleCheesePizza();
            }else if(type == "pepperoni"){
                return new ChicagoStylePepperoniPizza();
            }else if(type == "clam"){
                return new ChicagoStyleClamPizza();
            }else if(type == "veggie"){
                return new ChicagoStyleVeggiePizza();
            }
            else{
                return nullptr;
            }
        }
};
int main(){
    PizzaStore* nyStore = new NYPizzaStore();
    PizzaStore* chicagoStore = new ChicagoPizzaStore();

    Pizza* pizza = nyStore->orderPizza("cheese");
    cout << "Ethan ordered a " << pizza->getName() <<"\n"<< endl;

    pizza = chicagoStore->orderPizza("pepperoni");
    cout << "Joel ordered a " << pizza->getName() << endl;

    delete nyStore;
    delete chicagoStore;

    return 0;      
}
