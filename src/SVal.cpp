/*
 * GenMC -- Generic Model Checking.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you can access it online at
 * http://www.gnu.org/licenses/gpl-3.0.html.
 *
 * Author: Michalis Kokologiannakis <michalis@mpi-sws.org>
 */

#include "SVal.hpp"
#include "SAddr.hpp"

auto operator<<(llvm::raw_ostream &s, const SVal &v) -> llvm::raw_ostream &
{
	s << v.get();
	return s;
}

static_assert(sizeof(SVal::Value) >= sizeof(SAddr::Width), "SVal needs to be able to hold SAddr");
static_assert(sizeof(SVal::Value) >= sizeof(uintptr_t), "SVal needs to be able to hold pointers");
