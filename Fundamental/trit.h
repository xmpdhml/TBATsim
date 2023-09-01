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
        Trit Add(const Trit& other, const Trit& carry = Trit(0));
        Trit Sub(const Trit& other, const Trit& carry = Trit(0));
        void Mul(const Trit& other);

    };

    std::ostream& operator<<(std::ostream& os, const Trit& trit);

} // namespace Ternary
