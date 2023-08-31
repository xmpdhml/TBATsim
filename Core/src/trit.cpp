#include <trit.h>

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
            case 2:
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

    Trit Trit::Add(const Trit& other)
    {
        if (data == 0b11 || other.data == 0b11)
            throw TException();
        static const unsigned char table[3][3][2] = {
            { {'0', 0}, {'0', 1}, {'0', 2}, },
            { {'0', 1}, {'1', 2}, {'0', 0}, },
            { {'0', 2}, {'0', 0}, {'T', 1}, },
        };
        const auto r = table[data][other.data];
        data = r[1];
        return r[0];
    }

    Trit Trit::Sub(const Trit& other)
    {
        if (data == 0b11 || other.data == 0b11)
            throw TException();
        static const unsigned char table[3][3][2] = {
            { {'0', 0}, {'0', 2}, {'0', 1}, },
            { {'0', 1}, {'0', 0}, {'1', 2}, },
            { {'0', 2}, {'T', 1}, {'0', 0}, },
        };
        const auto r = table[data][other.data];
        data = r[1];
        return r[0];
    }

    std::ostream& operator<<(std::ostream& os, const Trit& trit)
    { return os << trit.toString(); }

} // namespace Ternary
