#pragma once

#include <string>
#include <ostream>

namespace Ternary
{
    struct Trit
    {
        unsigned char data : 2;

        Trit(char trit = 0);

        friend std::ostream& operator<<(std::ostream& os, const Trit& trit);

        bool operator==(const Trit& other) const noexcept;

        bool isNaN() const noexcept;
    };

    struct Tryte
    // 6-trit
    {
        unsigned short data : 12;

        Tryte(short tryte = 0);
        Tryte(const char* tryte);

        friend std::ostream& operator<<(std::ostream& os, const Tryte& tryte);

        bool isNaN() const noexcept;
    };

} // namespace Ternary
