/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "PathOpsTestCommon.h"
#include "SkPathOpsQuad.h"
#include "Test.h"

static const SkDQuad tests[] = {
    {{{1, 1}, {2, 1}, {0, 2}}},
    {{{0, 0}, {1, 1}, {3, 1}}},
    {{{2, 0}, {1, 1}, {2, 2}}},
    {{{4, 0}, {0, 1}, {4, 2}}},
    {{{0, 0}, {0, 1}, {1, 1}}},
};

static const SkDPoint inPoint[]= {
    {1,   1.2},
    {1,   0.8},
    {1.8, 1},
    {1.5, 1},
    {0.5, 0.5},
};

static const SkDPoint outPoint[]= {
    {1,   1.6},
    {1,   1.5},
    {2.2, 1},
    {1.5, 1.5},
    {1.1, 0.5},
};

static const size_t tests_count = SK_ARRAY_COUNT(tests);

static void PathOpsDQuadTest(skiatest::Reporter* reporter) {
    for (size_t index = 0; index < tests_count; ++index) {
        const SkDQuad& quad = tests[index];
        SkASSERT(ValidQuad(quad));
        bool result = quad.pointInHull(inPoint[index]);
        if (!result) {
            SkDebugf("%s [%d] expected in hull\n", __FUNCTION__, index);
            REPORTER_ASSERT(reporter, 0);
        }
        result = quad.pointInHull(outPoint[index]);
        if (result) {
            SkDebugf("%s [%d] expected outside hull\n", __FUNCTION__, index);
            REPORTER_ASSERT(reporter, 0);
        }
    }
}

#include "TestClassDef.h"
DEFINE_TESTCLASS_SHORT(PathOpsDQuadTest)
