// ======================================================================== //
// Copyright 2009-2017 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#pragma once

#include "rtcore_device.h"

/*! \ingroup embree_kernel_api */
/*! \{ */

#if defined(__cplusplus)
extern "C" {
#endif

/*! \brief Specifies the format of buffers and other data structures */
enum RTCFormat
{
  RTC_FORMAT_UNDEFINED = 0,

  RTC_FORMAT_UINT,
  RTC_FORMAT_UINT2,
  RTC_FORMAT_UINT3,
  RTC_FORMAT_UINT4,

  RTC_FORMAT_INT,
  RTC_FORMAT_INT2,
  RTC_FORMAT_INT3,
  RTC_FORMAT_INT4,

  RTC_FORMAT_FLOAT,
  RTC_FORMAT_FLOAT2,
  RTC_FORMAT_FLOAT3,
  RTC_FORMAT_FLOAT4,

  RTC_FORMAT_FLOAT3X4
  // ...
};

/*! \brief Specifies the type of buffers */
enum RTCBufferType 
{
  RTC_BUFFER_TYPE_INDEX,
  RTC_BUFFER_TYPE_VERTEX,
  RTC_BUFFER_TYPE_VERTEX_ATTRIBUTE,

  RTC_BUFFER_TYPE_FACE,
  RTC_BUFFER_TYPE_LEVEL,

  RTC_BUFFER_TYPE_EDGE_CREASE_INDEX,
  RTC_BUFFER_TYPE_EDGE_CREASE_WEIGHT,

  RTC_BUFFER_TYPE_VERTEX_CREASE_INDEX,
  RTC_BUFFER_TYPE_VERTEX_CREASE_WEIGHT,

  RTC_BUFFER_TYPE_HOLE
};

/*! \brief Defines an opaque buffer type */
typedef struct __RTCBuffer* RTCBuffer;

/*! \brief Creates a new buffer. */
RTCORE_API RTCBuffer rtcNewBuffer(RTCDevice device, size_t byteStride, unsigned int numItems);

/*! \brief Creates a new shared buffer. */
RTCORE_API RTCBuffer rtcNewSharedBuffer(RTCDevice device, void* ptr, size_t byteStride, unsigned int numItems);

/*! Returns a pointer to the buffer data. */
RTCORE_API void* rtcGetBufferData(RTCBuffer buffer);

/*! Releases the buffer handle. */
RTCORE_API void rtcReleaseBuffer(RTCBuffer buffer);

#if defined(__cplusplus)
}
#endif

/*! @} */