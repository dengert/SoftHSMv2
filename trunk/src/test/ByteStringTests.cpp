/* $Id$ */

/*
 * Copyright (c) 2010 SURFnet bv
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*****************************************************************************
 ByteStringTests.cpp

 Contains test cases to test the ByteString class
 *****************************************************************************/

#include <stdlib.h>
#include <cppunit/extensions/HelperMacros.h>
#include "ByteStringTests.h"
#include "ByteString.h"

CPPUNIT_TEST_SUITE_REGISTRATION(ByteStringTests);

void ByteStringTests::setUp()
{
}

void ByteStringTests::tearDown()
{
}

void ByteStringTests::testIntegrity()
{
	unsigned char testData[] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
	                             0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10 };

	ByteString b(testData, sizeof(testData));

	// Test if the right data is returned
	CPPUNIT_ASSERT(memcmp(testData, b.byte_str(), sizeof(testData)) == 0);

	// Test size
	CPPUNIT_ASSERT(b.size() == sizeof(testData));

	// Test the copy constructor
	ByteString b2(b);

	// Test using comparison operator
	CPPUNIT_ASSERT(b == b2);

	// Test using memcmp
	CPPUNIT_ASSERT(memcmp(b.byte_str(), b2.byte_str(), b.size()) == 0);

	// Modify the copied version and test again
	b2[1] = 0x20;

	// Test using comparison operator
	CPPUNIT_ASSERT(b != b2);

	// Test using memcmp directly
	CPPUNIT_ASSERT(memcmp(b.byte_str(), b2.byte_str(), b.size()) != 0);

	// Verify that b was not affected
	CPPUNIT_ASSERT(memcmp(b.byte_str(), testData, sizeof(testData)) == 0);

	// Modify the source data and check if the array operator has functioned correctly
	testData[1] = 0x20;

	// Test if the right data is in b2
	CPPUNIT_ASSERT(memcmp(b2.byte_str(), testData, sizeof(testData)) == 0);
}

void ByteStringTests::testAppend()
{
}

void ByteStringTests::testSubstr()
{
}
