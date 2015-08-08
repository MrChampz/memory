// Copyright (C) 2015 Jonathan Müller <jonathanmueller.dev@gmail.com>
// This file is subject to the license terms in the LICENSE file
// found in the top-level directory of this distribution.

#ifndef FOONATHAN_MEMORY_DETAIL_ALIGN_HPP_INCLUDED
#define FOONATHAN_MEMORY_DETAIL_ALIGN_HPP_INCLUDED

#include <cstddef>
#include <cstdint>

#include "../config.hpp"

namespace foonathan { namespace memory
{
    namespace detail
    {
        // returns the offset needed to align ptr for given alignment
        // alignment must be a power of two
        inline std::size_t align_offset(void *ptr, std::size_t alignment) FOONATHAN_NOEXCEPT
        {
            auto address = reinterpret_cast<std::uintptr_t>(ptr);
            auto misaligned = address & (alignment - 1);
            return misaligned != 0 ? (alignment - misaligned) : 0;
        }

        // whether or not the pointer is aligned for given alignment
        // alignment must be a power of two
        inline bool is_aligned(void *ptr, std::size_t alignment) FOONATHAN_NOEXCEPT
        {
            auto address = reinterpret_cast<std::uintptr_t>(ptr);
            return address % alignment == 0u;
        }

        // maximum alignment value
        FOONATHAN_CONSTEXPR auto max_alignment = FOONATHAN_ALIGNOF(foonathan_memory_comp::max_align_t);

        // returns the minimum alignment required for a node of given size
        inline std::size_t alignment_for(std::size_t size) FOONATHAN_NOEXCEPT
        {
            return size < max_alignment ? size : max_alignment;
        }
    } // namespace detail
}} // namespace foonathan::memory

#endif // FOONATHAN_MEMORY_DETAIL_ALIGN_HPP_INCLUDED
