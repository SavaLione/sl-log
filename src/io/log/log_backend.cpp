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
 * @brief Log backend
 * @author SavaLione
 * @date 11 Nov 2020
 */
#include "io/log/log_backend.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/async.h>

log_backend::backend log_backend::backend::Instance;

std::shared_ptr<spdlog::logger> async_file;

log_backend::backend& log_backend::backend::instance()
{
    return log_backend::backend::Instance;
}

log_backend::backend::backend()
{
    try
    {
        async_file = spdlog::basic_logger_mt<spdlog::async_factory>(" ", "log");
    }
    catch(const std::exception& e)
    {
        //std::cerr << e.what() << '\n';
        log = false;
    }
    
}

log_backend::backend::~backend()
{

}

void log_backend::backend::log_trace(const std::string & str)
{
    async_file->trace(str);
}

void log_backend::backend::log_debug(const std::string & str)
{
    async_file->debug(str);
}

void log_backend::backend::log_info(const std::string & str)
{
    async_file->info(str);
}

void log_backend::backend::log_warn(const std::string & str)
{
    async_file->warn(str);
}

void log_backend::backend::log_error(const std::string & str)
{
    async_file->error(str);
}

void log_backend::backend::log_critical(const std::string & str)
{
    async_file->critical(str);
}