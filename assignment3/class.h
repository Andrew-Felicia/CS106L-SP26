#ifndef CLASS_H
#define CLASS_H

#include <string>

class coffee_shop {
private:
    std::string name;
    int coffee_kinds;

    void say_slogan();
    
public:
    //constructor and destructor.
    coffee_shop(std::string name, int coffee_kinds);

    coffee_shop();

    ~coffee_shop();

    //getter
    std::string get_name() const;

    int get_kinds() const;

    
    //setter
    void set_kinds(int kinds);

    void set_name(std::string name);


};


#endif