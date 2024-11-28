#ifndef BI_RING_BASE_ITERATOR_H
#define BI_RING_BASE_ITERATOR_H


#include <stdexcept>

#include "biRing.hpp"

template <typename Key, typename Info>
template <typename Derived>
class BiRing<Key, Info>::base_iterator
{
public:
    base_iterator() : pCurr(nullptr), pRing(nullptr) {}
    base_iterator(Node* node, const BiRing* ring) : pCurr(node), pRing(ring) {}
    virtual ~base_iterator() = default;

    virtual Derived& operator+=(const int nr) { return this->move(nr); }
    virtual Derived& operator-=(const int nr) { return this->move(-nr); }
    
    virtual Derived& operator++() { return this->move(true); }
    virtual Derived& operator--() { return this->move(false); }
    
    virtual Derived operator++(int)
    {
        auto temp = static_cast<Derived>(*this);
        this->operator++();
        return temp;
    }

    virtual Derived operator--(int)
    {
        auto temp = static_cast<Derived>(*this);
        this->operator--();
        return temp;
    }

    virtual Derived operator+(const int nr)
    {
        auto temp = static_cast<Derived>(*this);
        return this->move(temp, nr);
    }

    virtual Derived operator-(const int nr)
    {
        auto temp = static_cast<Derived>(*this);
        return this->move(temp, -nr);
    }

    Derived& operator=(const Derived& other)
    {
        if (this != &other) {
            this->pCurr = other.pCurr;
        }
        return static_cast<Derived&>(*this);
    }

    template<typename K, typename I>
    [[nodiscard]] bool isInRing(const BiRing<K, I>& ring) { return this->pRing == &ring; }
    [[nodiscard]] bool isValid() const { return this->pCurr != nullptr; }
    bool operator==(const Derived& other) const { return this->pCurr == other.pCurr; }
    bool operator!=(const Derived& other) const { return this->pCurr != other.pCurr; }
    friend BiRing;
protected:
    Node* pCurr;
    const BiRing* pRing;
		
    virtual Derived& move(bool forward)
    {
        if (!this->isValid())
        {
            throw std::runtime_error("Cannot move not valid baseIterator");
        }
        this->pCurr = forward ? this->pCurr->next : this->pCurr->prev;
        return static_cast<Derived&>(*this);
    }
    
    virtual Derived& move(Derived& obj, const int nr)
    {
        for(int i = abs(nr); 0 < i; --i)
        {
            obj.move(nr > 0);
        }
        return obj;
    }
    
    virtual Derived& move(const int nr)
    {
        return this->move(static_cast<Derived&>(*this), nr);
    }
};


#endif //BI_RING_BASE_ITERATOR_H
