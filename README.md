
This file is the notes i made during learning this course.
This is a very Impressive course.

# command line compile.
```c++
g++ -std=c++23 -Wall *.cpp -o zoo
g++ -std=c++23 -Wall Animal.cpp Bird.cpp Cat.cpp Dog.cpp main.cpp -o zoo
//this two commands above are equal.
```



# lecture08

the virtual keyword: runtime polymorphism

> The `virtual` keyword enables **dynamic polymorphism**. If a virtual function is called through a base-class pointer or reference, C++ chooses which function to execute at runtime based on the actual type of the object, rather than the type of the pointer or reference.

For example:

```
Animal* p = new Dog;
p->speak();
```

- Without `virtual`, `Animal::speak()` is called because `p` is an `Animal*`.
- With `virtual`, `Dog::speak()` is called because the actual object is a `Dog`.

## Q&A. inheritance and virtual.

Overall, your understanding is **pretty good**. I'd give it around **8/10**. There are a few places where your explanations are incomplete or slightly inaccurate. Here's some feedback on each one.

---

### 1. What a pure virtual function is and why a class with one cannot be instantiated

Your answer:

> pure virtual function means the base class won't implement this, so it can't be instantiated, and you need to implement it in it's derived class.

**Mostly correct**, but there are two details:

- A pure virtual function **can** actually have an implementation (it's uncommon, but legal). The important part is that it's declared with `= 0`.
    
- The real reason the class cannot be instantiated is that it is an **abstract class**—it has at least one pure virtual function.
    

A more accurate answer would be:

> A pure virtual function is a virtual function declared with `= 0`, making the class an abstract class. Abstract classes cannot be instantiated because they have incomplete behavior. Derived classes must override all inherited pure virtual functions before they can be instantiated (unless they also remain abstract).

---

### 2. What polymorphism means and how virtual dispatch enables it

Your answer:

> polymorphism means the program runs on runtime to decide something, not decide it in compile time. virtual enables it by create a vtable.

You're close, but **polymorphism** is not simply "runtime decision making."

A better explanation is:

> Polymorphism allows the same interface (such as a base-class pointer or reference) to refer to objects of different derived types, with each object providing its own implementation of virtual functions. Virtual dispatch enables this by looking up the correct function in the object's vtable at runtime.

For example:

```cpp
Animal* p = new Dog;
p->speak();   // Calls Dog::speak()
```

The same code behaves differently depending on the actual object.

---

### 3. What the vtable is

Your answer:

> vtable is a table of function pointers that is created by the compiler to support dynamic polymorphism.

This is **excellent**.

If you wanted to be slightly more precise:

> A vtable (virtual table) is a compiler-generated table of pointers to virtual functions. Each object of a class with virtual functions contains a hidden pointer (the vptr) to its class's vtable. Virtual function calls use the vptr to find the correct implementation at runtime.

---

### 4. Why the `override` keyword is useful even though it's optional

Your answer:

> if you make mistakes by didn't override the function, you may don't notice anything, but if you use the override keyword, it will notice you if you don't override.

That's the right idea.

Here's a more polished version:

> The `override` keyword tells the compiler that a function is intended to override a virtual function from the base class. If the function signature does not match any virtual function in the base class, the compiler reports an error. This helps catch bugs caused by typos or incorrect parameter lists.

For example:

```cpp
class Animal {
public:
    virtual void speak() const;
};

class Dog : public Animal {
public:
    void speak() override;   // Error: missing const
};
```

Without `override`, this would compile and create a new function instead of overriding `Animal::speak()`.

---

### 5. Why the destructor of a base class should almost always be `virtual`

Your answer:

> because if you use new keyword in derived class, then you need to delete the space manully in the derived class implementation, if you don't use the virtual keyword in base class, the program always call the destructor from base class instead of derived class. because you need to free the memory recursively.

This is the one that needs the most improvement.

The key point is **deleting through a base-class pointer**, not whether `new` is used in the derived class.

A better answer is:

> A base class destructor should usually be virtual so that deleting an object through a base-class pointer calls the derived-class destructor first, followed by the base-class destructor. Without a virtual destructor, only the base-class destructor is called, which can cause resource leaks because the derived class's cleanup code is skipped.

For example:

```cpp
Animal* p = new Dog;
delete p;
```

If `Animal::~Animal()` is **not** virtual:

```text
Animal destructor
```

If it **is** virtual:

```text
Dog destructor
Animal destructor
```

The derived object gets cleaned up correctly.

---

### Overall

Your conceptual understanding is solid. The biggest thing to improve is distinguishing **what** a feature is from **how** the compiler implements it.

- **Polymorphism** is the programming concept.
    
- **Virtual dispatch** is the mechanism.
    
- **The vtable** is one common implementation of that mechanism.
    

Once you keep those three ideas separate, your explanations become much more precise.


# important concepts

allocate using new key word in head space.


try to write ++i instead of i++.


keywords:
using: alias for type, eg: using namespace std
const : indicate immutable
const_cast
==const correct==
mutable
`#include "xxxxx"` tells the preprocessor to **copy and paste the contents of the specified file** into the current file before compilation.you can write it any where, doesn't have to write it on the very beginning of the file.

virtual : used in dynamic polymorphism

template : A blueprint for creating classes with generic types.Template classes eliminate code redundancy! usually write everything inside .h file, but you can also sebarate them into .h and .cpp by include .cpp inside .h .    
useage:
Variadic Templates.
TMP:Template Metaprogramming

concept: using to redifine sth. eg: comparable.

operator overloading, friend.

- **`int`** is a **signed integer** used for general arithmetic.
- **`size_t`** is an **unsigned integer** specifically designed to represent **sizes and array indices**.

initializer lists:We can use initializer lists to declare and initialize them with desired values at once!

deep copy: create another independent object, and copy everything from this object to other pbject.

lvalues & rvalues : lvalue has address and can live longer, but rvalue is gone before execute the line. use `&` to reference lvalues, and use `&&` to reference rvalues.

==the special 6 member functions.==

|Function|Description|
|---|---|
|**Default constructor**|Creates a new object with default values.|
|**Destructor**|Releases the object's resources when its lifetime ends.|
|**Copy constructor**|Creates a new object by making a copy of another object. Both objects remain independent.|
|**Copy assignment**|Replaces the contents of an existing object with a copy of another object. Both objects remain independent.|
|**Move constructor**|Creates a new object by transferring ownership of another object's resources. The source object remains alive but is left in a valid moved-from state.|
|**Move assignment**|Replaces the contents of an existing object by transferring ownership of another object's resources. The source object remains alive but is left in a valid moved-from state.|
```c++
// 1. Default constructor
User();

// 2. Destructor
~User();

//the parameter passed in is lvalue, the reference to lvalue is &
// 3. Copy constructor
User(const User&);

// 4. Copy assignment
User& operator=(const User&);

//due to the parameter we passed in is rvalue, so the reference for rvalue is &&
// 5. Move constructor
User(User&&);

// 6. Move assignment
User& operator=(User&&);
```





|Syntax|Meaning|Example|When to use|
|---|---|---|---|
|`= default`|Ask the compiler to generate the standard implementation|`Point() = default;`|The compiler-generated behavior is exactly what you want.|
|`= delete`|Completely forbid using this function|`Point(const Point&) = delete;`|You want to prevent copying, moving, construction, etc.|
|`noexcept`|Promise this function never throws exceptions|`Point(Point&&) noexcept;`|Especially on move constructors and move assignment operators.|

==Rule of zero, Rule of three, Rule of five==

| Situation                                                              | Rule               |
| ---------------------------------------------------------------------- | ------------------ |
| Only STL containers / smart pointers / RAII types                      | **Rule of Zero** ⭐ |
| Own a raw resource (e.g. `new`, `delete`) and only need copy semantics | **Rule of Three**  |
| Own a raw resource and want efficient moves                            | **Rule of Five**   |
|                                                                        |                    |


caution:
initialization: () and {} and `[] in for loop to pack multiple values`, and initializer list vs. this-> in constructor. see more details below.
pointer
Instantiation


==Monadic(see lecture 15 code for more details)==
a software design pattern with a structure that combines program fragments(functions) and wrap their return values in a type with additional computation. it will return a new computional result or just return default value.


RAII says that dynamically allocated resources should be acquired inside of the constructor and released inside the destructor. ○ This is what smart pointers do for example
unique_pointer:
```c
int main() 
{
  unique_ptr<int> ptr1 = make_unique<int>(5);

  // ptr1 points to 5 (dynamically allocated on the heap)

  {

    unique_ptr<int> ptr2 = ptr1; // shallow copy

  } // <-- data for ptr2 deallocated here

  std::cout << *ptr1 << std::endl;
  return 0;
}
```
Since `ptr1` and `ptr2` point to the same memory, when `ptr2` goes out of scope, it takes `ptr1`'s data with it! As a result, `*ptr1` is undefined behaviour.
because the raw pointer is wrapped in a class, and delete/ free methods are implemented inside the wrap class. so you don't have to free the memory when you using them, cause they will free themselves automatically.

if maintain a big project, using make helps us to build files, but in order to using make, we need makefiles, and cmake helps us to generate makefiles.


# initializer list and this->

## Suppose you have

```cpp
class Person {
private:
    std::string name;

public:
    Person(std::string name);
};
```

### Option 1: Initializer list

```cpp
Person::Person(std::string name)
    : name(name) {}
```

Construction process:

```
allocate memory

↓

construct std::string "Alice"

↓

done
```

Only **one** construction happens.

---

### Option 2: Assignment

```cpp
Person::Person(std::string name) {
    this->name = name;
}
```

Construction process:

```
allocate memory

↓

default-construct std::string ""

↓

assign "Alice"

↓

done
```

There are **two** operations:

1. Construct an empty string.
    
2. Assign `"Alice"` to it.
    

That can be less efficient.

---

## Why does this matter?

For `std::string`, the difference is small.

But imagine a big object:

```cpp
class Image {
    ...
};
```

Suppose loading an image takes 100 MB.

Initializer list:

```
construct Image from file
```

Assignment:

```
construct empty Image

↓

throw away empty Image

↓

load Image from file
```

More work.

---

## Some classes **must** use initializer lists

Consider

```cpp
class Example {
private:
    const int x;
};
```

This won't compile:

```cpp
Example::Example(int x) {
    this->x = x;
}
```

because

```
const int
```

cannot be assigned after construction.

Instead:

```cpp
Example::Example(int x)
    : x(x) {}
```

---

Same for references:

```cpp
class Example {
private:
    int& ref;
};
```

You **must** write

```cpp
Example::Example(int& r)
    : ref(r) {}
```

because references cannot be reseated.

---

## Same for base classes

Earlier you wrote

```cpp
Bird::Bird(std::string name) {
    Animal(name);
}
```

That didn't work because the base class has already been constructed.

You have to write

```cpp
Bird::Bird(std::string name)
    : Animal(name) {}
```

Base classes are always initialized in the initializer list.

---

## Visual comparison

Suppose

```cpp
std::string name;
```

#### Initializer list

```
Memory
─────────────

construct "Alice"
```

One step.

---

#### Assignment

```
Memory
─────────────

construct ""

↓

assign "Alice"
```

Two steps.

---

## Modern C++ recommendation

Almost every C++ style guide says:

> **Prefer initializer lists whenever possible.**

You'll see this everywhere:

```cpp
Person::Person(std::string name)
    : name(name) {}
```

instead of

```cpp
Person::Person(std::string name) {
    this->name = name;
}
```

---

## A small note for primitive types

If the member is just an `int`:

```cpp
int age;
```

the performance difference between

```cpp
: age(age)
```

and

```cpp
this->age = age;
```

is usually negligible after optimization.

The reason we still prefer initializer lists is **consistency**. The same syntax works for:

- `int`
    
- `std::string`
    
- `std::vector`
    
- `const` members
    
- references
    
- base classes
    
- smart pointers
    
- user-defined classes
    

So if you get into the habit of always using initializer lists, you'll naturally write code that is both idiomatic and correct in all these cases.


