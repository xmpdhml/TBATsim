#include <convert.h>

namespace Utilities
{
    std::string ToString(TCore::Trit trit, bool allow_NaN /*= false*/)
    {
        switch (trit.data)
        {
        case 0b00:
            return "0";
        case 0b01:
            return "1";
        case 0b11:
            return "T";
        case 0b10:
        default:
            if (allow_NaN)
            {
                return "N";
            }
            else
            {
                throw TConvertException();
            }
        }
    }

} // namespace Utilities
