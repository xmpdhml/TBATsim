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

    std::string Trit::toString() const noexcept
    {
        switch (data)
        {
            case 0b00:
                return "0";
            case 0b01:
                return "1";
            case 0b10:
                return "T";
            default:
                return "X";
        }
    }

    Trit Trit::operator-() const noexcept
    {
        Trit t;
        t.data = data ? ~data : 0;
        return t;
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
        int shift = 0;
        while (tryte)
        {
            auto r = (tryte + 1) / 3;
            r = tryte - 3 * r;
            switch (r)
            {
                case -1:
                    data |= (neg ? 0b01 : 0b10) << shift;
                    ++tryte;
                    break;
                case 1:
                    data |= (neg ? 0b10 : 0b01) << shift;
                    break;
                case 0:
                    // data |= 0b00;
                    break;
            }
            shift += 2;
            tryte /= 3;
        }

    }

    std::string Tryte::toString() const noexcept
    {
        char s[7];
        short mask = 0b110000000000;
        char* p = s;
        bool hasPrinted = false;
        for (int i = 0; i < 6; ++i)
        {
            switch ((data & mask) >> (10 - 2 * i))
            {
                case 0b00:
                    if (hasPrinted)
                        *p++ = '0';
                    break;
                case 0b01:
                    *p++ = '1';
                    hasPrinted = true;
                    break;
                case 0b10:
                    *p++ = 'T';
                    hasPrinted = true;
                    break;
                default:
                    *p++ = 'X';
                    hasPrinted = true;
                    break;
            }
            mask >>= 2;
        }
        if (!hasPrinted)
            *p++ = '0';
        *p = '\0';
        return std::string(s);
    }

    Tryte Tryte::operator-() const noexcept
    {
        Tryte t;
        t.data = (data & 0b101010101010) >> 1 | (data & 0b010101010101) << 1;
        return t;
    }

    std::ostream& operator<<(std::ostream& os, const Trit& trit)
    { return os << trit.toString(); }

    std::ostream& operator<<(std::ostream& os, const Tryte& tryte)
    { return os << tryte.toString(); }


} // namespace Ternary
