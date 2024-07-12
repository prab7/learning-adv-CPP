#include "Person.hpp"

struct Person::ptrImplPerson {
    std::string m_name;
    std::string m_strength;
    std::string m_speed;
};

Person::Person() = default;

Person::Person(std::string s) {
    m_impl = std::make_unique<ptrImplPerson>();
    m_impl->m_name = s; 
    m_impl->m_strength = "n/a";
    m_impl->m_speed = "n/a";
}

Person::~Person(){
}

std::string Person::GetAttribute(){
    return m_impl->m_name + ", " + m_impl->m_strength + " " + m_impl->m_speed;
}

// is the performance tradeoff worth it for a more stable API?
