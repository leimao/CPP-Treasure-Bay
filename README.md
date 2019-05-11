# C++ Treasure Bay

Lei Mao

## Introduction

C++ is one of the most important low level programming languages. Its usages have expanded tremendously these years, but it is becoming harder for users, especially new users, to take the advantage of them. The purpose of this repository is to help the users to understand some of the basic and advanced usages of C++ by looking at the compact code and the program outputs without talking too much about the lengthy concepts like other tutorial websites do.

No bullshit. Show me the code.

## Collections

### Friend

Use cases of making friend class and friend functions.

### Inheritance

Comprehensive use cases of public, protected and private class inheritance.

### Typedef

Some confusing typedef usages.

### Template Specialization

Flexible implementation of different function and class for some particular template types.

### Operator Overloading

Operator overloading use cases of unary, binary, and conversion operators.

### Casts

#### Dynamic Cast

* Used for polymorphic hierarchical class pointer casting
* Does runtime check and return `nullptr` if the cast is incompatible.

#### Static Cast

* It is safe to cast between numerical primitive types
* Used for non-polymorphic hierarchical class pointer casting
* It is safe to cast basic class on derived class
* Be careful when you cast derived class on basic class since there is no runtime check

#### Reinterpret Cast

* Used for pointer cast
* Ask compiler to treat the expression as if it has the new type
* Most dangerous cast
* Know what you are doing before doing so

#### Const Cast

* Remove variable const restrictions on pointers temporally
* Do not use it to modify the content of const variables

### Smart Pointers

#### Shared Pointer

* Shared pointer is a smart pointer object that retains shared ownership of an object through a pointer. 
* Several shared pointer objects may own the same object. 
* Object owned would be destroyed once the last smart pointer owning the object loses ownership.

#### Unique Pointer

* Unique pointer is a smart pointer object that uniquely owns an object through a pointer.
* Could only transfer the ownership but not copy.
* It assumes only one unique pointer pointing to the object. Another unique pointer pointing to the same object will cause problems.

### Singleton


### Virtual Functions

#### Override

Actually we are overriding virtual functions routinely without even using `override` specifier. However, using `override` could help you prevent some weird bug in your code. So it is always best practice to use `override` when you really want to `override` a virtual function. In addition, it also makes understanding the code much easier.

#### Virtual Destructor

If the derived class have different destructor compared to the base class, it is recommended to make the destructor in the base class virtual. In this way, the base class destructor will always be called when you try to delete a derived class. It is best practice to make the base class destructor virtual when the base class is meant to be inherited polymorphically.

### Default

#### Constructor

#### Destructor


### Lambda Expression