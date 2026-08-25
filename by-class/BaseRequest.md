*** UID:00050F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "FileDownloader.h"
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_NETWORK_FILEDOWNLOADER_H
#define NEXUSTK_NETWORK_FILEDOWNLOADER_H

#include <string>
#include "../util/Thread.h"

class BaseRequest
{
public:
    BaseRequest()
        : downloadComplete(false),
          contentLength(0),
          bytesDownloaded(0)
    {
    }

    bool downloadComplete;
    unsigned long contentLength;
    unsigned long bytesDownloaded;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BaseRequest

## Status

- Reconstructable non-polymorphic request-state base class.
- Canonical source owner and emitter: [UID:0000JC][FileDownloader](by-file/FileDownloader.md).
- Source position `0` opens the coordinated `NexusTK/network/FileDownloader.h` declaration sequence before `CashShopVersionRequest`, `CashShopRequest`, and `FileDownloader`.
- Physical size is exactly `0x0c`; source contains three fields and no explicit padding member.
- No independent vtable, complete-object locator, virtual member, or standalone translation unit is supported.

## Summary

`BaseRequest` is the shared request-progress state embedded in both `CashShopVersionRequest` and `CashShopRequest`. RTTI base descriptors place the nonvirtual base subobject at derived offset `+0x04`, after each derived class's compiler-inserted vptr. Raw constructor stores initialize the same three values in both request families. The source class itself begins at offset `0` and occupies `0x0c`; the `+0x04` displacement belongs to derived-object layout and must not be represented as source padding in `BaseRequest`.

## Physical Layout

| Base offset | Derived offset | Size | Source field | Physical evidence |
| --- | --- | --- | --- | --- |
| `+0x00` | `+0x04` | `1` | `bool downloadComplete` | Raw request constructors clear byte `this+4`; worker paths test/set completion state. |
| `+0x01` | `+0x05` | `3` | implicit compiler alignment | Aligns the next 32-bit field; not a source member. |
| `+0x04` | `+0x08` | `4` | `unsigned long contentLength` | Raw constructors clear `this+8`; download paths track expected response length. |
| `+0x08` | `+0x0c` | `4` | `unsigned long bytesDownloaded` | Raw constructors clear `this+0x0c`; worker paths track received bytes. |

The exact base size is `0x0c`. With the derived vptr at `+0x00`, `CashShopVersionRequest` is `0x10`. `CashShopRequest` adds its 24-byte `std::string responseText` at `+0x10`, producing total size `0x28`.

## Source Layout

The formal H block is the source-facing declaration. `unsigned long` is used because the target is 32-bit Windows and the recovered values are DWORD-sized request counters. The analysis-only IDA type may require an explicit three-byte alignment field to preserve the physical `0x0c` layout, but finalized C++ relies on ordinary compiler alignment and must not expose that synthetic field.

The formal CPP block contains only `#include "FileDownloader.h"`. Other accepted class pages contribute declarations and child method definitions through the shared [UID:0000JC][FileDownloader](by-file/FileDownloader.md) emitter chain. This page does not create `BaseRequest.cpp` or a standalone source root.

## RTTI Evidence

- Shared BaseRequest type descriptor: `0x00673900`, decorated identity `??_R0?AVBaseRequest@@@8`.
- Shared base-class descriptor: `0x006403c8`, PMD `4/-1/0`, attributes `0x40`, type descriptor `0x00673900`.
- The descriptor is referenced by both the CashShopVersionRequest and CashShopRequest hierarchy arrays.
- CashShopRequest's self descriptor uses PMD `0/-1/0`; the separate BaseRequest descriptor uses `4/-1/0`, proving a nonvirtual base subobject at derived offset `+0x04`.
- No BaseRequest complete-object locator or vftable record exists in the current symbol/data inventory. This negative evidence is expected for a non-polymorphic base.

## Constructor Evidence

[UID:0002CH][0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw](by-memory/0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw.md) clears derived offsets `+0x04`, `+0x08`, and `+0x0c` before installing the CashShopRequest vptr and constructing `responseText` at `+0x10`. That ordering is the binary shape of an inlined `BaseRequest()` followed by derived-class initialization.

The live equivalent inside [UID:0002CK][0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest](by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md) repeats the `0x28`-byte request layout. [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md) allocates `0x10`, matching the vptr plus this `0x0c` base and no derived data fields.

## Sibling Class Evidence

- [UID:00001I][CashShopVersionRequest](by-class/CashShopVersionRequest.md) is a polymorphic `0x10` derived request with no derived data members.
- [UID:00001H][CashShopRequest](by-class/CashShopRequest.md) is a polymorphic `0x28` derived request whose only derived field is `responseText` at `+0x10`.
- [UID:0003FR][0x0060d794-0x0060d79c.CashShopVersionRequestVtableData](by-memory/0x0060d794-0x0060d79c.CashShopVersionRequestVtableData.md) and [UID:0003FS][0x0060d79c-0x0060d7a4.CashShopRequestVtableData](by-memory/0x0060d79c-0x0060d7a4.CashShopRequestVtableData.md) carry adjacent compiler-generated source consequences of those virtual destructors.
- The two sibling request shapes independently converge on the same three-field base instead of unrelated flattened members.

## Source Placement

Place `BaseRequest`, `CashShopVersionRequest`, `CashShopRequest`, and `FileDownloader` together in `NexusTK/network/FileDownloader.h` and their definitions/children in `NexusTK/network/FileDownloader.cpp`. Request constructors/destructors, submitters, workers, and dispatcher logic form one physical and behavioral cluster, while the three relevant vtable records are adjacent in `.rdata`.

The older standalone CashShopRequest and CashShopVersionRequest by-file pages remain valuable research aliases, but they are not independent source roots. Consolidation avoids artificial one-class-per-file output and matches the likely late-1999 through mid-2000s module style.

## Rejected Alternatives

- **Polymorphic BaseRequest:** rejected because no BaseRequest vtable/COL survives and both derived RTTI records place their own vptr before the base.
- **Explicit source padding member:** rejected because ordinary compiler alignment accounts for bytes `+0x01-+0x03`; an analysis UDT may name padding, finalized human-written source should not.
- **Flattened derived fields:** retained only as a historical analysis shape. RTTI, constructor ordering, and sibling sizes prove the shared base.
- **Standalone BaseRequest.cpp:** rejected because the constructor is trivial/inline and all observed consumers belong to the FileDownloader request module.
- **Cash-shop feature ownership:** rejected as the source emitter because FileDownloader allocates, queues, dispatches, fills, and destroys these request payloads; cash-shop/fitting-room code consumes their state.

## Historical Assumptions

Earlier pages modeled `downloadComplete`, `contentLength`, and `bytesDownloaded` as direct fields of each derived request and sometimes called the completion byte `state`. Those descriptions were useful physical observations but incomplete source reconstruction. The shared BaseRequest RTTI descriptor, PMD `+4`, constructor-store order, and `0x10`/`0x28` sibling sizes resolve the source model. The old `state` and flattened-layout names are preserved here as superseded history, not emitted source.

## Score Rationale

- Completion `93`: exact size, fields, offsets, initialization, two derived layouts, RTTI relationship, owner/emitter route, source placement, formal CPP/H, and rejected alternatives are documented.
- Confidence `94`: independent RTTI, constructor, allocation-size, sibling-layout, worker, and negative-vtable evidence agree on the same non-polymorphic base.
- The page remains below `95/95` because the original lexical class/field spellings and historical header boundary are inferred rather than recovered from source symbols. This does not block exact runtime layout or human-written source reconstruction.

## Item Summary

Non-polymorphic `0x0c` request-state base reconstructed from shared RTTI, nonvirtual derived displacement `+0x04`, constructor stores, and sibling object sizes. It contributes the FileDownloader header opening and three source fields through [UID:0000JC][FileDownloader](by-file/FileDownloader.md), with no source-level vtable or explicit padding member.

## Cross-References

- [UID:0000JC][FileDownloader](by-file/FileDownloader.md)
- [UID:00004W][FileDownloader](by-class/FileDownloader.md)
- [UID:00001I][CashShopVersionRequest](by-class/CashShopVersionRequest.md)
- [UID:00001H][CashShopRequest](by-class/CashShopRequest.md)
- [UID:0002CH][0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw](by-memory/0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw.md)
- [UID:0003FR][0x0060d794-0x0060d79c.CashShopVersionRequestVtableData](by-memory/0x0060d794-0x0060d79c.CashShopVersionRequestVtableData.md)
- [UID:0003FS][0x0060d79c-0x0060d7a4.CashShopRequestVtableData](by-memory/0x0060d79c-0x0060d7a4.CashShopRequestVtableData.md)

## Changes

- 2026-08-03 B008 UID0003FS implementation callback:
  - Created the class page at `93/94`, routed it through [UID:0000JC][FileDownloader](by-file/FileDownloader.md), and assigned header position `0`.
  - Documented exact physical/source layout, shared RTTI, constructor and sibling evidence, FileDownloader module placement, and rejected alternatives without pruning superseded flattened-layout history.
  - Added the exact formal CPP include and H guard/base-declaration blocks accepted by the UID0003FS Gate 1 report.
