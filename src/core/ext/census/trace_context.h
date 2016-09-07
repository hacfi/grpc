/*
 *
 * Copyright 2016, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/* Functions for manipulating trace contexts as define in
   src/proto/census/trace.proto */
#ifndef GRPC_CORE_EXT_CENSUS_TRACE_CONTEXT_H
#define GRPC_CORE_EXT_CENSUS_TRACE_CONTEXT_H

#include "src/core/ext/census/gen/trace_context.pb.h"

// Maximum number of bytes required to encode a TraceContext
#define TRACE_MAX_CONTEXT_SIZE 31

/* Encode a trace context (ctxt) in proto format to the buffer provided.  The
size of buffer must be at least TRACE_MAX_CONTEXT_SIZE.  On success, returns the
number of bytes consumed in buffer in msg_length. On failure, returns 0 in
msg_length. */
bool encode_trace_context(google_trace_TraceContext *ctxt, uint8_t *buffer,
                          const size_t size, size_t *msg_length);

/* Decode a proto-encoded TraceContext from the provided buffer into the
TraceContext structure (ctxt).  The function expects to be supplied the number
of bytes to be read from buffer (nbytes).  This function will also validate that
the TraceContext has a span_id and a trace_id. */
bool decode_trace_context(google_trace_TraceContext *ctxt, uint8_t *buffer,
                          size_t nbytes);

#endif
