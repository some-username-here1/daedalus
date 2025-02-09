/*
Copyright (C) 2012 StrmnNrmn

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

#include "stdafx.h"

#include "RomFile/RomFileMemory.h"
#include "Utility/MemoryHeap.h"

#include <stdlib.h>

extern bool PSP_IS_SLIM;
//*****************************************************************************
//
//*****************************************************************************
CROMFileMemory::~CROMFileMemory()
{
}

//*****************************************************************************
//
//*****************************************************************************
class IROMFileMemory : public CROMFileMemory
{
public:
	IROMFileMemory();
	~IROMFileMemory();

//	virtual	bool	IsAvailable();
	virtual void *	Alloc( u32 size );
	virtual void	Free(void * ptr);

private:
#if defined(DAEDALUS_PSP) || defined(DAEDALUS_PS2)
	CMemoryHeap *	mRomMemoryHeap;
#endif
};


//*****************************************************************************
//
//*****************************************************************************
template<> bool CSingleton< CROMFileMemory >::Create()
{
	#ifdef DAEDALUS_ENABLE_ASSERTS
	DAEDALUS_ASSERT_Q(mpInstance == NULL);
	#endif

	mpInstance = new IROMFileMemory();
	return mpInstance != NULL;
}

//*****************************************************************************
//
//*****************************************************************************
IROMFileMemory::IROMFileMemory()
{
#ifdef DAEDALUS_PSP
	//
	// Allocate large memory heap for SLIM+ (32Mb) Used for ROM Buffer and ROM Cache
	// Otherwise allocate small memory heap for PHAT (2Mb) Used for ROM cache only
	//
	if( PSP_IS_SLIM )
	{
		mRomMemoryHeap = CMemoryHeap::Create( 32 * 1024 * 1024 );
	}
	else
	{
		mRomMemoryHeap = CMemoryHeap::Create( 4 * 1024 * 1024 );
	}
#elif defined(DAEDALUS_PS2)
	mRomMemoryHeap = CMemoryHeap::Create(4 * 1024 * 1024);
#endif
}

//*****************************************************************************
//
//*****************************************************************************
IROMFileMemory::~IROMFileMemory()
{
#if defined(DAEDALUS_PSP) || defined(DAEDALUS_PS2)
	delete mRomMemoryHeap;
#endif
}

//*****************************************************************************
//
//*****************************************************************************
/*
bool IROMFileMemory::IsAvailable()
{
	DAEDALUS_ASSERT( mRomMemoryHeap != NULL, "This heap isn't available" );

	return mRomMemoryHeap != NULL;
}
*/
//*****************************************************************************
//
//*****************************************************************************
void * IROMFileMemory::Alloc( u32 size )
{
#if defined(DAEDALUS_PSP) || defined(DAEDALUS_PS2)
	return mRomMemoryHeap->Alloc( size );
#else
	return malloc( size );
#endif
}

//*****************************************************************************
//
//*****************************************************************************
void  IROMFileMemory::Free(void * ptr)
{
#if defined(DAEDALUS_PSP) || defined(DAEDALUS_PS2)
	mRomMemoryHeap->Free( ptr );
#else
	free( ptr );
#endif
}
