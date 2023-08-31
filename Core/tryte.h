#pragma once

#include <trit.h>

namespace Ternary
{
    struct Tryte
    {
        Trit trits[6];
        
        Tryte(short tryte = 0);
        
        std::string toString() const;
        
        Tryte operator-() const;
        std::weak_ordering operator<=>(const Tryte& other) const;

        bool operator==(const Tryte& other) const
        { return operator<=>(other) == std::weak_ordering::equivalent; }

        Tryte& operator&=(const Tryte& other);
        Tryte& operator|=(const Tryte& other);
        Tryte operator&(const Tryte& other) const;
        Tryte operator|(const Tryte& other) const;
    };


    std::ostream& operator<<(std::ostream& os, const Tryte& tryte);
    
} // namespace Ternary
