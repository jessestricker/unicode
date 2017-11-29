#include "code_point.h"

#include <iomanip>
#include <ostream>
#include "detail_.h"

namespace unicode {
    std::ostream& operator<<(std::ostream& os, code_point cp)
    {
        auto iss = detail::ios_state_saver{ os }; // restore ostream state
        return os << "U+" << std::hex << std::uppercase
                  << std::setw(4) << std::setfill('0')
                  << cp.value_;
    }
}
