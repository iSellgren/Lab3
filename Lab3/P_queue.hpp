//
//  Priority_que.hpp
//  Lab3
//
//  Created by Fredrik Sellgren on 2018-12-03.
//  Copyright © 2018 Fredrik Sellgren. All rights reserved.

// implementation borde ligga i headern
// När man kompillerar en template så tittar kompilatorn in i templaten, samt in i
// template argumentens typ, detta görs för att den vill ha info för att generera optimal kod.
// Kompilatorer idag kräver att mallen är helt definerad när den används.
// Detta inkluderar alla medlemsfunktioner, och alla template funktioner,

#ifndef P_queue_hpp
#define P_queue_hpp
#include <vector>
#include <stdio.h>
#include <iostream>
#include <functional>
#include <algorithm>

template <typename T, typename Comparison>

class P_queue
{
public:
    T pop()
    {

        T value = Elements.front();
        
        Elements.erase(Elements.begin());
        return value;
    }
    
    void push(const T &value)
    {
        Comparison comp;
        auto min = std::find_if(Elements.begin(), Elements.end(), [comp,&value](const T & e)
        {
            
            return (comp(e, value));
        });
        
        Elements.insert(min, value);
    }

    size_t size() const
    {   // Return number of elements in the queue
        return Elements.size();
    }
    
    bool empty() const
    {
        //Returns true if the queue is empty
        return Elements.empty();
    }
    
    const T& top() const
    {
        //Return reference to the first element
        return Elements.front();
    }
    
    void print() const
    {
        // Printing the element.
        for(auto &element : Elements)
        {
            std::cout << element << "\n";
        }
    }
private:
    std::vector<T> Elements;
    
};

#endif /* Priority_que_hpp */
