#pragma once

#include "code_point.h"

namespace unicode {
    enum class decode_error {
        none,
        invalid_sequence,
        missing_data
    };

    template <class InputIter>
    struct decode_result {
        code_point cp;      // The decoded code point. On error this equals replacement().
        InputIter iter;     // The iterator is placed after the code point.
        decode_error error; // The error field determines the success of the operation.
    };

    // The replacement code point.
    constexpr code_point replacement() noexcept { return 0xFFFD_cp; }
}
