#include "detail_.h"

namespace unicode::detail {
    ios_state_saver::ios_state_saver(std::ios& ios)
        : ios_{ ios }
    {
        // save state
        fill_ = ios.fill();
        flags_ = ios.flags();
        precision_ = ios.precision();
        width_ = ios.width();
    }

    ios_state_saver::~ios_state_saver()
    {
        // restore state
        ios_.fill(fill_);
        ios_.flags(flags_);
        ios_.precision(precision_);
        ios_.width(width_);
    }
}
