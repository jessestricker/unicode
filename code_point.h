#pragma once

#include <cstdint>
#include <iosfwd>

namespace unicode {
    // declaration
    // --------------------

    struct code_point {
        using value_type = std::uint_fast32_t;

        constexpr static code_point min() noexcept;
        constexpr static code_point max() noexcept;

        constexpr code_point() noexcept = default;
        constexpr explicit code_point(value_type value) noexcept;
        constexpr explicit operator value_type() const noexcept;

        constexpr bool ok() const noexcept;

        constexpr friend bool operator==(code_point lhs, code_point rhs) noexcept;
        constexpr friend bool operator!=(code_point lhs, code_point rhs) noexcept;
        constexpr friend bool operator<(code_point lhs, code_point rhs) noexcept;
        constexpr friend bool operator>(code_point lhs, code_point rhs) noexcept;
        constexpr friend bool operator<=(code_point lhs, code_point rhs) noexcept;
        constexpr friend bool operator>=(code_point lhs, code_point rhs) noexcept;

        friend std::ostream& operator<<(std::ostream& os, code_point cp);

    private:
        value_type value_{};
    };

    constexpr code_point operator"" _cp(unsigned long long value) noexcept;

    // implementation
    // --------------------

    constexpr code_point code_point::min() noexcept { return 0x0000_cp; }
    constexpr code_point code_point::max() noexcept { return 0x10FFFF_cp; }

    constexpr unicode::code_point::code_point(value_type value) noexcept
        : value_{ value }
    {
    }

    constexpr code_point::operator value_type() const noexcept { return value_; }

    constexpr bool code_point::ok() const noexcept
    {
        return min() <= *this && *this <= max();
    }

    constexpr bool operator==(code_point lhs, code_point rhs) noexcept { return lhs.value_ == rhs.value_; }
    constexpr bool operator!=(code_point lhs, code_point rhs) noexcept { return !(lhs == rhs); }
    constexpr bool operator<(code_point lhs, code_point rhs) noexcept { return lhs.value_ <= rhs.value_; }
    constexpr bool operator>(code_point lhs, code_point rhs) noexcept { return rhs < lhs; }
    constexpr bool operator<=(code_point lhs, code_point rhs) noexcept { return !(lhs > rhs); }
    constexpr bool operator>=(code_point lhs, code_point rhs) noexcept { return !(lhs < rhs); }

    constexpr code_point operator""_cp(unsigned long long value) noexcept
    {
        return code_point{ static_cast<code_point::value_type>(value) };
    }
}
