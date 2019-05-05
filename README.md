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

### Casts

#### Dynamic Cast

* Used for polymorphic hierarchical class pointer casting
* Does runtime check and return `nullptr` if the cast is incompatible.

#### Static Cast

* It is safe to cast between numerical primitive types
* Used for non-polymorphic hierarchical class pointer casting
* It is safe to cast basic class on derived class
* Be careful when you cast derived class on basic class since there is no runtime check

#### Const Cast

* Remove variable const restrictions on pointers temporally
* Do not use it to modify the content of const variables

#### Reinterpret Cast

* Used for pointer cast
* Ask compiler to treat the expression as if it has the new type
* Most dangerous cast
* Know what you are doing before doing so
