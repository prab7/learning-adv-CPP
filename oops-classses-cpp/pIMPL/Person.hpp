#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <memory>

class Person {
    public:
        Person();
        Person(std::string s);
        ~Person();
        std::string GetAttribute();
    private:
        struct ptrImplPerson;
        std::unique_ptr<ptrImplPerson> m_impl;
};

#endif