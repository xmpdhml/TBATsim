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
                throw TException();
        }
    }

    std::string Trit::toString() const
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
                throw TException();
        }
    }

    Trit Trit::operator-() const
    {
        if (data == 0b11)
            throw TException();
        Trit t;
        t.data = data ? ~data : 0;
        return t;
    }

    std::weak_ordering Trit::operator<=>(const Trit& other) const
    {
        if (data == 0b11 || other.data == 0b11)
            throw TException();

        static const std::weak_ordering table[3][3] = {
            {std::weak_ordering::equivalent, std::weak_ordering::less, std::weak_ordering::greater},
            {std::weak_ordering::greater, std::weak_ordering::equivalent, std::weak_ordering::greater},
            {std::weak_ordering::less, std::weak_ordering::less, std::weak_ordering::equivalent}
        };

        return table[data][other.data];                    
    }

    Trit& Trit::operator&=(const Trit& other)
    {
        if (data == 0b11 || other.data == 0b11)
            throw TException();
        if (data == 0b10)
            return *this;
        if (other.data == 0b10)
        {
            data = 0b10;
            return *this;
        }
        data &= other.data;
        return *this;
    }
    Trit Trit::operator&(const Trit& other) const
    {
        Trit t(*this);
        return t &= other;
    }

    Trit& Trit::operator|=(const Trit& other)
    {
        if (data == 0b11 || other.data == 0b11)
            throw TException();
        if (data == 0b01)
            return *this;
        if (other.data == 0b01)
        {
            data = 0b01;
            return *this;
        }
        data &= other.data; // not a typo
        return *this;
    }
    Trit Trit::operator|(const Trit& other) const
    {
        Trit t(*this);
        return t |= other;
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

    std::string Tryte::toString() const
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
                    throw TException();
            }
            mask >>= 2;
        }
        if (!hasPrinted)
            *p++ = '0';
        *p = '\0';
        return std::string(s);
    }

    Tryte Tryte::operator-() const
    {
        if (((data & 0b101010101010) >> 1) & (data & 0b010101010101))
            throw TException();
        Tryte t;
        t.data = (data & 0b101010101010) >> 1 | (data & 0b010101010101) << 1;
        return t;
    }

    std::weak_ordering Tryte::operator<=>(const Tryte& other) const
    {
        if (((data & 0b101010101010) >> 1) & (data & 0b010101010101))
            throw TException();
        if (((other.data & 0b101010101010) >> 1) & (other.data & 0b010101010101))
            throw TException();

        Trit t, o;
        for (int i = 5; i >= 0; --i)
        {
            t.data = (data & (0b11 << (2 * i))) >> (2 * i);
            o.data = (other.data & (0b11 << (2 * i))) >> (2 * i);
            if (t != o)
                return t <=> o;
        }
        return std::weak_ordering::equivalent;
    }

    std::ostream& operator<<(std::ostream& os, const Trit& trit)
    { return os << trit.toString(); }

    std::ostream& operator<<(std::ostream& os, const Tryte& tryte)
    { return os << tryte.toString(); }


} // namespace Ternary
