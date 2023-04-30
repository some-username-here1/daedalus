/*
Copyright (C) 2008 StrmnNrmn

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/



#ifndef SYSPS2_INCLUDE_PLATFORM_H_
#define SYSPS2_INCLUDE_PLATFORM_H_

//
//	Make sure this platform is defined correctly
//
#ifndef DAEDALUS_PS2
#define DAEDALUS_PS2
#endif

#define DAEDALUS_ENABLE_DYNAREC
#define DAEDALUS_ENABLE_OS_HOOKS

#define DAEDALUS_ENDIAN_MODE DAEDALUS_ENDIAN_LITTLE

#define DAEDALUS_EXPECT_LIKELY(c) __builtin_expect((c),1)
#define DAEDALUS_EXPECT_UNLIKELY(c) __builtin_expect((c),0)

#define DAEDALUS_ATTRIBUTE_NOINLINE __attribute__((noinline))

#define DAEDALUS_HALT			__asm__ __volatile__ ( "break" )

#define DAEDALUS_DYNAREC_HALT	SW(Ps2Reg_R0, Ps2Reg_R0, 0)

#define MAKE_UNCACHED_PTR(x)	(reinterpret_cast< void * >( reinterpret_cast<u32>( (x) ) | 0x20000000 ))

#define DAEDALUS_ATTRIBUTE_PURE   __attribute__((pure))
#define DAEDALUS_ATTRIBUTE_CONST   __attribute__((const))

#define __has_feature(x) 0

#define DAEDALUS_PS2_USE_VU0
#define USE_FILEXIO

#endif // SYSPS2_INCLUDE_PLATFORM_H_
