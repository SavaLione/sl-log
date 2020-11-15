/*
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * Copyright (c) 2020, Savely Pototsky (SavaLione)
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
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
 /**
 * @file
 * @brief Log
 * @author SavaLione
 * @date 11 Nov 2020
 */
#ifndef IO_LOG_LOG_H
#define IO_LOG_LOG_H

#include <sstream>

#include <platform/platform.h>

#include "io/log/log_backend.h"

#define L_LOG(Level)         ::log(P_FILE, __LINE__, Level)

#define l_log_trace        L_LOG(::log::trace)
#define l_log_debug        L_LOG(::log::debug)
#define l_log_info         L_LOG(::log::info)
#define l_log_warn         L_LOG(::log::warn)
#define l_log_err          L_LOG(::log::err)
#define l_log_critical     L_LOG(::log::critical)

class log
{
public:
    enum log_level
    {
        trace,
        debug,
        info,
        warn,
        err,
        critical,
        off,
    };

    log(const char * _file, int _line, log_level _level)
        : file(_file), line(_line), level(_level) { };
    ~log();

    void set_level(const log_level & level);
    void set_pattern(const char * pattern);

	template <class T>
	log & operator<<(const T & i)
    {
        if(log_backend::backend::instance().log)
        {
            buffer << i;
            // buffer << file << " [" << line << "] " << i;
        }
		return *this;
	}
private:
    const char * const file;
	const int line;
	const log_level level;

    std::ostringstream buffer;
};


#endif // IO_LOG_LOG_H