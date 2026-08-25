// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000L7
// Source by-file doc: by-file/MemoryMan.md
// UID:00007U | by-class/MemoryMan.md | Completion:91 | Confidence:91
#include "MemoryMan.h"

// UID:0000T8 | by-global/MemoryAllocationHelpers.md | Completion:88 | Confidence:90
// MemoryAllocationHelpers is an index for the MemoryMan.cpp allocation
// helper family. Exact helper and operator bodies emit on their child pages;
// this aggregate page must not emit a duplicate source block.

// UID:0000RH | by-global/g_pMemoryMan.md | Completion:90 | Confidence:90
static MemoryMan *g_pMemoryMan = NULL;

// UID:000196 | by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md | Completion:90 | Confidence:92
void *operator new(size_t size)
{
    return GetMemoryMan()->AllocateBufferMemory(size);
}

// UID:000197 | by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md | Completion:89 | Confidence:91
void operator delete(void *block)
{
    GetMemoryMan()->FreeBufferMemory(block);
}

// UID:0001BC | by-memory/0x00516030-0x00516036.GetMemoryMan.md | Completion:90 | Confidence:92
MemoryMan* GetMemoryMan()
{
    return g_pMemoryMan;
}

// UID:00029R | by-memory/0x0069b3a8-0x0069b3ac.MemoryManStaticObjectStorage.md | Completion:90 | Confidence:90
static MemoryMan g_staticMemoryManObject;

// UID:0002B0 | by-memory/0x0069b4fc-0x0069b500.g_pMemoryMan.md | Completion:89 | Confidence:91
// The source-level singleton pointer declaration is emitted by [UID:0000RH][g_pMemoryMan](by-global/g_pMemoryMan.md).
// This page documents the exact 0x0069b4fc-0x0069b500 storage slot and must
// not emit a duplicate g_pMemoryMan definition.
