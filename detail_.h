#pragma once

#include <ios>

namespace unicode::detail {
    struct ios_state_saver {
        explicit ios_state_saver(std::ios& ios);
        ~ios_state_saver();

    private:
        std::ios& ios_;
        char fill_;
        std::ios::fmtflags flags_;
        std::streamsize precision_, width_;
    };
}
