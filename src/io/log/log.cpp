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
#include "io/log/log.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

void log::set_level(const log_level & level)
{
    switch (level)
    {
    case trace:
        spdlog::set_level(spdlog::level::trace);
        break;
    case debug:
        spdlog::set_level(spdlog::level::debug);
        break;
    case info:
        spdlog::set_level(spdlog::level::info);
        break;
    case warn:
        spdlog::set_level(spdlog::level::warn);
        break;
    case err:
        spdlog::set_level(spdlog::level::err);
        break;
    case critical:
        spdlog::set_level(spdlog::level::critical);
        break;
    case off:
        spdlog::set_level(spdlog::level::off);
        break;
    default:
        spdlog::set_level(spdlog::level::info);
        break;
    }
}

void log::set_pattern(const char * pattern)
{
//    spdlog::set_pattern("[%H:%M:%S %z] [%^%L%$] [thread %t] %v");
}

log::~log()
{
    if(log_backend::backend::instance().log)
    {
        switch (level)
        {
        case trace:
            log_backend::backend::instance().log_trace(buffer.str());
            break;
        case debug:
            log_backend::backend::instance().log_debug(buffer.str());
            break;
        case info:
            log_backend::backend::instance().log_info(buffer.str());
            break;
        case warn:
            log_backend::backend::instance().log_warn(buffer.str());
            break;
        case err:
            log_backend::backend::instance().log_error(buffer.str());
            break;
        case critical:
            log_backend::backend::instance().log_critical(buffer.str());
            break;
        default:
            log_backend::backend::instance().log_info(buffer.str());
            break;
        }
    }
}