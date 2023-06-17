

#include <iostream>
//-------задание 1-----------
class Pet {
    std::string name;
    std::string type;
    int age;

public:
    Pet(std::string n,std::string t,int a) {
        name = n;
        type = t;
        age = a;
    }
    void Print() {
        std::cout << std::endl;
        std::cout << "------Pet-----" << std::endl;
        std::cout << "Name:" << name << std::endl;
        std::cout << "type:" << type << std::endl;
        std::cout << "age:" << age << std::endl;

    }
    virtual void species() = 0;
    virtual void sound() = 0;
};

class Dog : public Pet {
    std::string  dog_species;
public:
    Dog(std::string n,std::string t,int a,std::string d):Pet(n,t,a){
        dog_species = d;
    }
    void species() {
        std::cout << "species:" << dog_species<<std::endl;
    }
    void sound() {
        std::cout << "woof woof"<<std::endl;
    }
};


class Cat: public Pet {
    std::string  cat_species;
public:
    Cat(std::string n, std::string t, int a, std::string c) :Pet(n, t, a) {
        cat_species = c;
    }
    void species() {
        std::cout << "species:" << cat_species << std::endl;
    }
    void sound() {
        std::cout << "meov meov"<<std::endl;
    }
};

class Parot : public Pet {
    std::string  parot_species;
public:
    Parot(std::string n, std::string t, int a, std::string p) :Pet(n, t, a) {
        parot_species = p;
    }
    void species() {
        std::cout << "species:" << parot_species << std::endl;
    }
    void sound() {
        std::cout << "arrr arrr" << std::endl;
    }
};

//-------задание 2-----------
class myString {
protected:
    int len;
    char* str;
public:
    myString(const char* s, int l) {
        int cap = 0;
        if (s)
            cap = strlen(s);
        if (cap >= l)
            l = cap + 1;
        len = l;
        if (l) {
            str = new char[l] {0};
            if (cap)
                strcpy_s(str, l, s);
        }
        else
            str = 0;
    }
    myString():
        myString(nullptr,80){}

    myString(const myString& obj) :myString(obj.str, obj.len) {}

    ~myString() {
        delete[] str;
    }

    void Clear() {
        delete[] str;
        len = 0;
    }

    myString& operator=(const myString& obj) {
        if (this == &obj) {
            return *this;
        }

        len = obj.len;
        free(str);
        str = new char[strlen(obj.str)+1];
        strcpy_s(str, strlen(obj.str)+1, obj.str);
        return *this;
    }

    friend bool operator==(myString& str1, myString& str2) {
        return str1.str == str2.str;
    }

    friend bool operator!=(myString& str1, myString& str2) {
        return !(str1 == str2);
    }

    friend std::ostream& operator<< (std::ostream& out, const myString& obj) {
        if (obj.str) {
            out << obj.str;
            return out;
        }
        else {
            std::cout << "empty\n";
        }
        
    }

    myString& operator+(const myString& obj) {
        myString temp = *this;
        str = nullptr;
        this->str = new char[strlen(obj.str) + strlen(temp.str)] {0};
        for (int ii = 0; ii < strlen(temp.str); ii++) {
            this->str[ii] = temp.str[ii];
        }
        int yy = 0;
        for (int ii = strlen(temp.str); ii < strlen(obj.str) + strlen(temp.str); ii++) {
            this->str[ii] = obj.str[yy];
            yy++;
        }
        return *this;
    }

    int getLen() {
        return len;
    }
};


class BitString : public myString {
public:
    int VerifyString(const char* s)
    {
        if (!s) return 0;
        for (int n = 0; n < strlen(s); n++)
        {
            if ((s[n] != '0') && (s[n] != '1')) return 0;
        }
        return 1;
    }

    BitString(const char* s,int l)
    {
        if (VerifyString(s)) { 
            int cap = 0;
            if (s)
                cap = strlen(s);
            if (cap >= l)
                l = cap + 1;
            len = l;
            if (l) {
                str = new char[l] {0};
                if (cap)
                    strcpy_s(str, l, s);
            }
            else
                str = 0;
        }
        else
        {
            str = nullptr;
            len = 0;
        }
    }

    BitString(const BitString& obj)
    {
        if (VerifyString(obj.str)) myString(obj);
    }

    
    void invert() {
        myString temp("1", 1);
        for (int ii = 0; ii < strlen(str); ii++) {
            if (str[ii] == '0') {
                str[ii] = '1';
            }
            else {
                str[ii] = '0';
            }
        }
        *this + temp;
    }

};

int main()
{
    //-------задание 1-----------
    /*Dog dog("nick","dog",5,"labrodor");
    dog.Print();
    dog.species();
    dog.sound();

    Cat cat("murzic", "cat", 3, "siberian cat");
    cat.Print();
    cat.sound();
    cat.species();

    Parot parot("Arra", "parot", 1, "kakadu");
    parot.Print();
    parot.sound();
    parot.species();*/
    //-------задание 2-----------

    /*myString S3("fwefhiwfiohdrg",80);
    myString S1("fwefh",80);
    S1 = S3;*/
    BitString S1("1111010101011", 15);
    S1.invert();
    std::cout << S1;
}

