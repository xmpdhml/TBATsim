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
                data = 0b11;
                break;
            default:
                data = 0b10;
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
            case 0b11:
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
        return data == 0b10;
    }
    
} // namespace Ternary
