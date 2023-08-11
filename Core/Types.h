#pragma once

namespace Ternary
{
    struct Trit
    {
        unsigned char data : 2;
    };

    struct Tryte
    // 6-trit
    {
        unsigned short data : 12;
    };

} // namespace Ternary
