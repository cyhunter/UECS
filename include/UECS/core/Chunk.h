#pragma once

#include <UTemplate/Typelist.h>

#include <cstdint>
#include <array>
#include <tuple>
#include <vector>
#include <cassert>

namespace Ubpa {
	using byte = uint8_t;
	static_assert(sizeof(byte) == 1);
	struct Chunk {
		static constexpr size_t size = 16 * 1024;

		template<size_t N>
		struct Info {
			constexpr Info(size_t capacity, std::array<size_t, N> sizes, std::array<size_t, N> offsets)
				: capacity(capacity), sizes(sizes), offsets(offsets) {}

			size_t capacity;
			std::array<size_t, N> sizes;
			std::array<size_t, N> offsets;
		};

		template<typename... Cmpts>
		static constexpr Info<sizeof...(Cmpts)> StaticInfo() noexcept;

		// capacity, offsets
		static const std::tuple<size_t, std::vector<size_t>> CO(const std::vector<size_t>& sizes) noexcept;

		constexpr byte* Data() noexcept { return buffer.data(); }

	private:
		std::array<byte, size> buffer;
	};
	static_assert(sizeof(Chunk) == Chunk::size);
}

#include "detail/Chunk.inl"
