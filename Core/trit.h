#pragma once

#include <string>
#include <ostream>
#include <compare>

#include <exceptions.h>

namespace Ternary
{
    struct Trit
    {
        unsigned char data : 2;

        Trit(char trit = 0);

        std::string toString() const;

        Trit operator-() const;

        std::weak_ordering operator<=>(const Trit& other) const;

        bool operator==(const Trit& other) const
        { return operator<=>(other) == std::weak_ordering::equivalent; }

        // tritwise operators
        Trit& operator&=(const Trit& other);
        Trit& operator|=(const Trit& other);
        Trit operator&(const Trit& other) const;
        Trit operator|(const Trit& other) const;

        // arithmetic functions
        Trit Add(const Trit& other);
        Trit Sub(const Trit& other);
        Trit Mul(const Trit& other);

    };

/*
    struct Tryte
    // 6-trit
    {
        unsigned short data : 12;

        Tryte(short tryte = 0);
        Tryte(const char* tryte);

        Tryte operator-() const;

        std::string toString() const;

        std::weak_ordering operator<=>(const Tryte& other) const;

        bool operator==(const Tryte& other) const
        { return operator<=>(other) == std::weak_ordering::equivalent; }

        Tryte& operator&=(const Tryte& other);
        Tryte& operator|=(const Tryte& other);
        Tryte operator&(const Tryte& other) const;
        Tryte operator|(const Tryte& other) const;
    };
    */

    std::ostream& operator<<(std::ostream& os, const Trit& trit);

    //std::ostream& operator<<(std::ostream& os, const Tryte& tryte);

} // namespace Ternary
