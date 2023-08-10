#pragma once

#include <string>

#include <Core/Types.h>
#include <exceptions.h>

namespace Utilities
{

    class TConvertException : public TException
    {
    };

    std::string ToString(TCore::Trit trit, bool allow_NaN = false);

} // namespace Utilities
