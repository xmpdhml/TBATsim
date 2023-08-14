#include <Types.h>

namespace Ternary
{
    Trit::Trit(char trit)
    {
        switch (trit)
        {
            case 0:
            case '0':
                data = 0b00;
                break;
            case 1:
            case '1':
                data = 0b01;
                break;
            case -1:
            case 'T':
                data = 0b10;
                break;
            default:
                data = 0b11;
        }
    }

    std::ostream& operator<<(std::ostream& os, const Trit& trit)
    {
        switch (trit.data)
        {
            case 0b00:
                os << "0";
            case 0b01:
                os << "1";
            case 0b10:
                os << "T";
            default:
                os << "X";
        }
        return os;
    }

    bool Trit::operator== (const Trit& other) const noexcept
    {
        return !isNaN() && (data == other.data);
    }

    bool Trit::isNaN() const noexcept
    {
        return data == 0b11;
    }

    Tryte::Tryte(short tryte /* = 0 */)
    {
        if (tryte < -364 || tryte > 364)
        {
            data = 0b111111111111;
            return;
        }

        bool neg;
        if (tryte < 0)
        {
            neg = true;
            tryte = -tryte;
        }
        else
        {
            neg = false;
        }

        data = 0;
        while (tryte)
        {
            auto r = (tryte + 1) / 3;
            r = tryte - 3 * r;
            data <<= 2;
            switch (r)
            {
                case -1:
                    data |= neg ? 0b01 : 0b10;
                    break;
                case 1:
                    data |= neg ? 0b10 : 0b01;
                    break;
                case 0:
                    // data |= 0b00;
                    break;
            }
            tryte /= 3;
        }

    }
    
    std::ostream& operator<<(std::ostream& os, const Tryte& trite)
    {
        short mask = 0b110000000000;
        bool hasPrinted = false;
        for (int i = 0; i < 6; ++i)
        {
            switch ((trite.data & mask) >> (10 - 2 * i))
            {
                case 0b00:
                    if (hasPrinted)
                        os << "0";
                    break;
                case 0b01:
                    os << "1";
                    hasPrinted = true;
                    break;
                case 0b10:
                    os << "T";
                    hasPrinted = true;
                    break;
                default:
                    os << "X";
                    hasPrinted = true;
                    break;
            }
            mask >>= 2;
        }
        if (!hasPrinted)
            os << "0";
        return os;
    }

    bool Tryte::isNaN() const noexcept
    {
        auto r = data & 0b101010101010;
        r >>= 1;
        r &= data & 0b010101010101;
        return r;
    }

} // namespace Ternary
