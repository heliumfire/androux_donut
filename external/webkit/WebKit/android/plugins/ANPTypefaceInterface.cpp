/*
 * Copyright 2008, The Android Open Source Project
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

// must include config.h first for webkit to fiddle with new/delete
#include "config.h"
#include "SkANP.h"

static ANPTypeface* anp_createFromName(const char name[], ANPTypefaceStyle s) {
    SkTypeface* tf = SkTypeface::CreateFromName(name,
                                        static_cast<SkTypeface::Style>(s));
    return reinterpret_cast<ANPTypeface*>(tf);
}

static ANPTypeface* anp_createFromTypeface(const ANPTypeface* family,
                                           ANPTypefaceStyle s) {
    SkTypeface* tf = SkTypeface::CreateFromTypeface(family,
                                          static_cast<SkTypeface::Style>(s));
    return reinterpret_cast<ANPTypeface*>(tf);
}

static int32_t anp_getRefCount(const ANPTypeface* tf) {
    return tf ? tf->getRefCnt() : 0;
}

static void anp_ref(ANPTypeface* tf) {
    tf->safeRef();
}

static void anp_unref(ANPTypeface* tf) {
    tf->safeUnref();
}

static ANPTypefaceStyle anp_getStyle(const ANPTypeface* tf) {
    SkTypeface::Style s = tf ? tf->style() : SkTypeface::kNormal;
    return static_cast<ANPTypefaceStyle>(s);
}

///////////////////////////////////////////////////////////////////////////////

#define ASSIGN(obj, name)   (obj)->name = anp_##name

void ANPTypefaceInterfaceV0_Init(ANPInterface* v) {
    ANPTypefaceInterfaceV0* i = reinterpret_cast<ANPTypefaceInterfaceV0*>(v);
    
    ASSIGN(i, createFromName);
    ASSIGN(i, createFromTypeface);
    ASSIGN(i, getRefCount);
    ASSIGN(i, ref);
    ASSIGN(i, unref);
    ASSIGN(i, getStyle);
}
