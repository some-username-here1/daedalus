/*
Copyright (C) 2009 StrmnNrmn

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

#ifndef CORE_DYNAMO_H_
#define CORE_DYNAMO_H_

void Dynamo_SelectCore();
void Dynamo_Reset();

#ifdef DAEDALUS_DEBUG_DYNAREC
	void			CPU_DumpFragmentCache();
#endif
void Dynarec_ClearedCPUStuffToDo();
void Dynarec_SetCPUStuffToDo();

void CPU_ResetFragmentCache();

#endif // CORE_DYNAMO_H_
