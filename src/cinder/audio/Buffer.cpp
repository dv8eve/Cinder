/*
 Copyright (c) 2010, The Barbarian Group
 All rights reserved.

 Redistribution and use in source and binary forms, with or without modification, are permitted provided that
 the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this list of conditions and
	the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
	the following disclaimer in the documentation and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
 WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
*/

#include "cinder/audio/Buffer.h"

namespace cinder { namespace audio {

template<typename T>
PcmBufferT<T>::PcmBufferT( uint32_t aMaxSampleCount, uint16_t aChannelCount ) 
	: mMaxSampleCount( aMaxSampleCount ), mChannelCount( aChannelCount ), mSampleCount( 0 )
{
	mData = new T[mMaxSampleCount * mChannelCount];
}

template<typename T>
void PcmBufferT<T>::appendData( T * aData, uint32_t aSampleCount )
{
	if( mSampleCount + aSampleCount > mMaxSampleCount ) {
		throw; //TODO
	}
	
	memcpy( &( mData[mSampleCount] ), aData, aSampleCount * sizeof(T) );
	mSampleCount += aSampleCount;
}

template<typename T>
PcmBufferT<T>::~PcmBufferT()
{
	delete [] mData;
}

template class PcmBufferT<float>;

}} //namespace