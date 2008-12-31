/*
 ============================================================================
 Name		: HttpClient.cpp
 Author	  : Anton Antonov
 Version	 : 1.0
 Copyright   :   Copyright (C) 2008 Rhomobile. All rights reserved.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ============================================================================
 */

//Stubs for phonebook
#include "Phonebook.h"
#include <cpbkcontactitem.h>

extern "C" 
{
void* openPhonebook() 
{
	CPhonebook* phonebook = CPhonebook::NewL();
	return phonebook;
}

void  closePhonebook(void* pb) 
{
	if ( pb )
    {
    	CPhonebook* phonebook = (CPhonebook*)pb;
    	delete phonebook;
    }
}

VALUE getallPhonebookRecords(void* pb) 
{
	if ( pb )
	{
		CPhonebook* phonebook = (CPhonebook*)pb;
		return phonebook->getallPhonebookRecords();
	}

	return getnil();	
}

void* openPhonebookRecord(void* pb, char* id) 
{
	if ( pb && id )
	{
		CPhonebook* phonebook = (CPhonebook*)pb;
		return phonebook->openContact(id);
	}

	return NULL;
}

VALUE getPhonebookRecord(void* pb, char* id) 
{
	if ( pb && id )
	{
		CPhonebook* phonebook = (CPhonebook*)pb;
		return phonebook->getContact(id);
	}
	return getnil();	
}

//==================================================================================

VALUE getfirstPhonebookRecord(void* pb) {
	pb;
	return getnil();
}

VALUE getnextPhonebookRecord(void* pb) {
	pb;
	return getnil();}

//==================================================================================

void* createRecord() 
{
	return CPhonebook::createRecord();
}

int setRecordValue(void* record, char* prop, char* value) 
{
	CPhonebook::setRecord((CPbkContactItem*)record, prop, value);
	return 1;
}

int addRecord(void* pb, void* record) 
{
	pb;
	CPhonebook::addRecord((CPbkContactItem*)record);
	return 1;
}

int saveRecord(void* pb, void* record) {
	pb;
	record;
	return 1;
}

int deleteRecord(void* pb, void* record) {
	pb;
	record;
	return 1;
}
}