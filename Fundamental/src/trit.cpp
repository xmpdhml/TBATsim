#include <trit.h>

#include <tryte.h>

#include <array>

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

    static const std::array<std::array<std::array<std::pair<unsigned char, unsigned char>, 3>, 3>, 3> trit_add_table = 
        []() {
            std::array<std::array<std::array<std::pair<unsigned char, unsigned char>, 3>, 3>, 3> table;
            int v[] = {0, 1, -1};
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    for (int k = 0; k < 3; ++k)
                    {
                        auto r = v[i] + v[j] + v[k];
                        Tryte t(r);
                        table[i][j][k] = {static_cast<unsigned char>(t.trits[0].data), static_cast<unsigned char>(t.trits[1].data)};
                    }
            return table;
        }();

    Trit Trit::Add(const Trit& other, const Trit& carry)
    {
        if (data == 0b11 || other.data == 0b11)
            throw TException();

        const auto r = trit_add_table[data][other.data][carry.data];
        data = r.first;
        Trit ret;
        ret.data = r.second;
        return ret;
    }

    static const std::array<std::array<std::array<std::pair<unsigned char, unsigned char>, 3>, 3>, 3> trit_sub_table =
        []() {
            std::array<std::array<std::array<std::pair<unsigned char, unsigned char>, 3>, 3>, 3> table;
            int v[] = {0, 1, -1};
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    for (int k = 0; k < 3; ++k)
                    {
                        auto r = v[i] - v[j] + v[k];
                        Tryte t(r);
                        table[i][j][k] = {static_cast<unsigned char>(t.trits[0].data), static_cast<unsigned char>(t.trits[1].data)};
                    }
            return table;
        }();

    Trit Trit::Sub(const Trit& other, const Trit& carry)
    {
        if (data == 0b11 || other.data == 0b11)
            throw TException();

        const auto r = trit_sub_table[data][other.data][carry.data];
        data = r.first;
        Trit ret;
        ret.data = r.second;
        return ret;
    }

    void Trit::Mul(const Trit &other)
    {
        if (data == 0b11 || other.data == 0b11)
            throw TException();
        static const unsigned char table[3][3] = {
            {0, 0, 0},
            {0, 1, 2},
            {0, 2, 1},
        };
        data = table[data][other.data];
    }

    std::ostream& operator<<(std::ostream& os, const Trit& trit)
    { return os << trit.toString(); }

} // namespace Ternary
