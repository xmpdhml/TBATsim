#include <tryte.h>

namespace Ternary
{
    Tryte::Tryte(short tryte)
    {
        if (tryte < -364 || tryte > 364)
            throw TException();

        bool neg;
        if (tryte < 0)
        {
            neg = true;
            tryte = -tryte;
        }
        else
            neg = false;

        for (int i = 0; i < 6; ++i)
        {
            auto r = (tryte + 1) / 3;
            r = tryte - 3 * r;
            switch (r)
            {
            case -1:
                trits[i] = (neg ? 1 : -1);
                ++tryte;
                break;
            case 1:
                trits[i] = (neg ? -1 : 1);
                break;
            case 0:
                trits[i] = 0;
                break;
            }
            tryte /= 3;
        }
    }

    Tryte Tryte::FromString(const std::string& str)
    {
        auto size = str.size();
        auto trits = str.data();
        Tryte ret;
        if (size > 6)
            throw TException();
        for (int i = 0; i < 6; ++i)
        {
            if (i < size)
            {
                switch (trits[size - 1 - i])
                {
                case '0':
                    ret.trits[i].data = 0;
                    break;
                case '1':
                    ret.trits[i].data = 1;
                    break;
                case 'T':
                    ret.trits[i].data = 2;
                    break;
                default:
                    throw TException();
                }
            }
            else
            {
                ret.trits[i].data = 0;
            }            
        }
        return ret;
    }

    std::string Tryte::toString() const
    {
        char s[7];
        char* p = s;
        bool hasPrinted = false;
        for (int i = 5; i >= 0; --i)
        {
            switch (trits[i].data)
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
        }
        if (!hasPrinted)
            *p++ = '0';
        *p = '\0';
        return std::string(s);
    }

    Tryte Tryte::operator-() const
    {
        Tryte t;
        for (int i = 0; i < 6; ++i)
            t.trits[i] = -trits[i];
        return t;
    }

    Tryte &Tryte::operator&=(const Tryte &other)
    {
        for (int i = 0; i < 6; ++i)
            trits[i] &= other.trits[i];
        return *this;
    }

    Tryte &Tryte::operator|=(const Tryte &other)
    {
        for (int i = 0; i < 6; ++i)
            trits[i] |= other.trits[i];
        return *this;
    }

    Tryte Tryte::operator&(const Tryte &other) const
    {
        Tryte t(*this);
        t &= other;
        return t;
    }

    Tryte Tryte::operator|(const Tryte &other) const
    {
        Tryte t(*this);
        t |= other;
        return t;
    }

    Tryte Tryte::operator+(const Tryte &other) const
    {
        Tryte r(*this);
        r.Add(other);
        return r;
    }

    Tryte Tryte::operator-(const Tryte &other) const
    {
        Tryte r(*this);
        r.Sub(other);
        return r;
    }

    Trit Tryte::Add(const Tryte &other)
    {
        Trit t;
        for (int i = 0; i < 6; ++i)
        {
            t = trits[i].Add(other.trits[i], t);
        }
        return t;
    }

    Trit Tryte::Sub(const Tryte &other)
    {
        Trit t;
        for (int i = 0; i < 6; ++i)
        {
            t = trits[i].Sub(other.trits[i], t);
        }
        return t;
    }

    Tryte Tryte::Mul(const Tryte &other)
    {
        return Tryte();
    }

    std::weak_ordering Tryte::operator<=>(const Tryte& other) const
    {
        for (int i = 5; i >= 0; --i)
        {
            if (trits[i].data != other.trits[i].data)
                return trits[i] <=> other.trits[i];
        }
        return std::weak_ordering::equivalent;
    }


    std::ostream& operator<<(std::ostream& os, const Tryte& tryte)
    {
        return os << tryte.toString();
    }

} // namespace Ternar
