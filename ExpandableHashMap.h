// ExpandableHashMap.h

// Skeleton for the ExpandableHashMap class template.  You must implement the first six
// member functions.
#ifndef HASHMAP_INCLUDED
#define HASHMAP_INCLUDED

#include <vector>
#include <list>
#include "provided.h"
#include <iostream>

template<typename KeyType, typename ValueType>

class ExpandableHashMap
{
public:
    ExpandableHashMap(double maximumLoadFactor = 0.5);
    ~ExpandableHashMap();
    void reset();
    int size() const;
    void associate(const KeyType& key, const ValueType& value);

      // for a map that can't be modified, return a pointer to const ValueType
    const ValueType* find(const KeyType& key) const;

      // for a modifiable map, return a pointer to modifiable ValueType
    ValueType* find(const KeyType& key)
    {
        return const_cast<ValueType*>(const_cast<const ExpandableHashMap*>(this)->find(key));
    }

      // C++11 syntax for preventing copying and assignment
    ExpandableHashMap(const ExpandableHashMap&) = delete;
    ExpandableHashMap& operator=(const ExpandableHashMap&) = delete;

private:
    std::vector <std::list<std::pair<KeyType, ValueType>>> v;
    int m_size;
    int m_bucketsUsed;
    int m_totalBuckets;
    double maxLoad;
    const unsigned int hasherHelper(const KeyType& key) const;
    void rehash();
};

    
template<typename KeyType, typename ValueType>
ExpandableHashMap<KeyType,ValueType>::ExpandableHashMap(double maximumLoadFactor)
{
    m_bucketsUsed=0;
    m_totalBuckets=8;
    maxLoad=maximumLoadFactor;
    m_size=0;
    reset();
}

template<typename KeyType, typename ValueType>
ExpandableHashMap<KeyType,ValueType>::~ExpandableHashMap()
{
}

template<typename KeyType, typename ValueType>
void ExpandableHashMap<KeyType,ValueType>::reset()
{
    v.clear();
    
    m_size=0;
    m_bucketsUsed=0;
    
    v.resize(8);
    v.size();
}

template<typename KeyType, typename ValueType>
int ExpandableHashMap<KeyType,ValueType>::size() const
{
    return m_size;  // Delete this line and implement this function correctly
}

template<typename KeyType, typename ValueType>
void  ExpandableHashMap<KeyType,ValueType>::associate(const KeyType& key, const ValueType& value)
{
    unsigned int hasher(const KeyType& k); // prototype
    int index= hasherHelper(key);
   
    
    auto it= v[index] .begin();
    
    while(it!=v[index].end()){
        if(std::get<0>(*it)==key){
            std::pair<KeyType, ValueType> p(key,value);
            *it=p;
            return;
            
        }
        it++;
    }
        
    if(v[index].empty())m_bucketsUsed++;
    
    v[index].push_back(std::pair<KeyType,ValueType>(key,value));
    m_size++;
    
    if(m_size/m_totalBuckets>maxLoad)rehash();
    
    
    
}
template<typename KeyType, typename ValueType>
const ValueType* ExpandableHashMap< KeyType,ValueType>::find(const KeyType& key) const
{
    int index= hasherHelper(key);
    auto it= v[index].begin();
    KeyType k;
    
    
    while(it !=v[index].end()){
        k=std::get<0>(*it);
        if(k==key)return &std::get<1>(*it);
        it++;
            
            }
    
    
    
    
    return nullptr;
}
template<typename KeyType, typename ValueType>

const unsigned int ExpandableHashMap< KeyType,ValueType>::hasherHelper(const KeyType& key) const{
     unsigned int hasher(const KeyType& k); // prototype
    return (hasher(key)%v.size());
}





template<typename KeyType, typename ValueType>
void ExpandableHashMap< KeyType,ValueType>::rehash(){
    std::vector <std::list<std::pair<KeyType, ValueType>>>  tempVec(v);

    
    m_totalBuckets*=2;
    std::list<std::pair<KeyType, ValueType> >l;
   
    
    std::vector <std::list<std::pair<KeyType, ValueType>>>  blankVec(m_totalBuckets,l);
    
  
    m_size=0;
    v.clear();
    v=blankVec;
    
    

    auto it =tempVec[0].begin();
    for(int i=0;i<tempVec.size();i++){
        it=tempVec[i].begin();
        while(it!= tempVec[i].end()){
            associate(std::get<0>(*it),std::get<1>(*it));
            it++;
        }
    }
    
    
    
    
    
    
}
#endif
