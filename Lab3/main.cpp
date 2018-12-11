//
//  main.cpp
//  Lab3
//
//  Created by Fredrik Sellgren on 2018-12-03.
//  Copyright © 2018 Fredrik Sellgren. All rights reserved.
//

#include <iostream>
#include "P_queue.hpp"
#include <string>
#include <random>

struct Broker
{
    std::string Name;
    int Value;
    
};

std::ostream &operator << (std::ostream& stream, const Broker& Brokers)
{
    stream << Brokers.Name << " " << Brokers.Value;
    return stream;    
}

struct CompareBroker
{
    //CompareBroker so that the higest prio stands first.
    bool operator() (const Broker lhs, const Broker rhs)const
    {
        return lhs.Value > rhs.Value;
    }
};
void Wallstreet(P_queue<Broker,CompareBroker> &Buyer, P_queue <Broker,CompareBroker> &Seller)
{
    while (!Buyer.empty() && !Seller.empty())
    {
    auto Buy = Buyer.pop();
    auto Sell = Seller.pop();

        if(Sell.Value <= Buy.Value)
        {
            std::cout << Sell.Name << " säljer för " << Sell.Value << " " << Buy.Name
            << " köper denna för " << Buy.Value <<"\n";
        }
    }
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(15, 30);
    P_queue<Broker, CompareBroker> Buyers, Sellers;
    for(int i = 0; i < 7; i++)
    {
        Buyers.push({"Joakim von Anka", dist(gen)});
        Sellers.push({"Joakim von Anka", dist(gen)});
        
        Buyers.push({"Erik Pendel", dist(gen)});
        Sellers.push({"Erik Pendel", dist(gen)});
        
        Buyers.push({"Jarl Wallenburg",dist(gen)});
        Sellers.push({"Jarl Wallenburg", dist(gen)});
    }

    std::cout << "---Buyers---" << "\n";
    Buyers.print();
      std::cout << "---Sellers---" << "\n";
    Sellers.print();
    
    Wallstreet(Buyers, Sellers);
    
    return 0;
}
