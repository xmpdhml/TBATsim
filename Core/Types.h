#pragma once

#include <string>
#include <ostream>

#include <exceptions.h>

namespace Ternary
{
    struct Trit
    {
        unsigned char data : 2;

        Trit(char trit = 0);

        std::string toString() const noexcept;

        Trit operator-() const noexcept;

        bool operator==(const Trit& other) const noexcept
        { return data == other.data; }
    };

    struct Tryte
    // 6-trit
    {
        unsigned short data : 12;

        Tryte(short tryte = 0);
        Tryte(const char* tryte);

        Tryte(const Tryte& other) = default;
        Tryte(Tryte&& other) = default;
        Tryte& operator=(const Tryte& other) = default;
        Tryte& operator=(Tryte&& other) = default;

        bool operator==(const Tryte& other) const noexcept
        { return data == other.data; }

        Tryte operator-() const noexcept;

        std::string toString() const noexcept;
    };

    std::ostream& operator<<(std::ostream& os, const Trit& trit);

    std::ostream& operator<<(std::ostream& os, const Tryte& tryte);

} // namespace Ternary
