*** UID:0000OB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# StringUtil

## Status

- Proposed module: `util/StringUtil.cpp`
- Proposed header: `util/StringUtil.h`
- Preferred companion module: [UID:0000OA][StringBase](by-file/StringBase.md) for the ref-counted `mystr::StringBase` family.
- Confidence: strong for utility ownership, high-confidence child attachment, vector/string-helper behavior, and exact IDA boundaries; medium-high for exact original source-file split.
- Current recovered source labels: `SimpleUString`, `SimpleUStringVector`, `StringIter`, and the string-heavy subset historically mixed with `LObject`.
- Validator output root: `NexusTK/util/StringUtil.cpp`

## File Role

`StringUtil.cpp` is the current working owner for shared client string infrastructure: the `SimpleUString` UTF-16 string helper, the vector container that stores contiguous 4-byte pointer-backed string-handle slots, the small `StringIter` character iterator used by text parsing/render helpers, and coordination with the ref-counted ANSI/UTF-16 [UID:0000OA][StringBase](by-file/StringBase.md) family currently emitted under [UID:0000KV][LObject](by-file/LObject.md).

This is utility code. It is referenced from application startup, DAT/resource loading, UI text, sound track-name formatting, patch/profile/config helpers, browser paths, and map/world UI. It should not be owned by any single caller module.

## Likely Contents

- [UID:0000D9][SimpleUString](by-class/SimpleUString.md)
- [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md)
- [UID:0000E7][StringIter](by-class/StringIter.md)
- [UID:0000OA][StringBase](by-file/StringBase.md) ref-counted string-buffer helpers, currently emitted as [UID:00007D][LObject](by-class/LObject.md) methods
- [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md), if final owner review keeps the fixed-block string pools as a separate utility file
- SSO-7 wide-string layout endpoint helpers [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md) and [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md)
- [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md)
- [UID:000236][0x005151b0-0x005151ef.DefaultCodepageConversionWrappers](by-memory/0x005151b0-0x005151ef.DefaultCodepageConversionWrappers.md)
- pointer-backed varargs format helpers around `0x00583210`, `0x00583280`, `0x00583720`, and `0x00583840`
- range comparison helpers around `0x005840f0` and `0x005845b0`

The recovered `FunctionObjectT<mystr::StringBase<...>>` classes are template/deleting-destructor support for [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), not primary `StringUtil.cpp` ownership proof. Keep them under [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md) unless caller evidence ties a construction site to this file.

## Current Ownership Map

| Area | Primary docs | StringUtil decision |
| --- | --- | --- |
| SSO-7 UTF-16 helpers | [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md), [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md) | Attach exact endpoint helpers here; do not treat the whole mixed `0x00421310-0x004216cb` island as one string source unit. |
| Pointer-backed `SimpleUString` helpers | [UID:0001J2][0x00583210-0x005845eb.SimpleUStringPointerBacked](by-memory/0x00583210-0x005845eb.SimpleUStringPointerBacked.md) | String utility ownership is likely, with broad caller fan-in and recovered-output omissions recorded. |
| `SimpleUStringVector` | [UID:000112][0x00493f10-0x00493f79.SimpleUStringVectorDestructor](by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md), [UID:00012G][0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert](by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md), [UID:0001J4][0x00584910-0x0058498b.SimpleUStringVectorPushBack](by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md) | Attach as 4-byte pointer-backed string-handle vector support, not inline `SimpleUString` object storage. |
| `StringIter` | [UID:0001J5][0x00584d80-0x00584e9e.StringIter](by-memory/0x00584d80-0x00584e9e.StringIter.md) | Keep iterator helper here while the recovered `0x00584dc0` constructor row remains a manual-boundary caveat. |
| Ref-counted `StringBase` | [UID:0000OA][StringBase](by-file/StringBase.md), [UID:0001J1][0x00582500-0x00583206.LObjectStringConstructionAndCow](by-memory/0x00582500-0x00583206.LObjectStringConstructionAndCow.md), [UID:0001J3][0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation.md) | Use `StringBase.cpp` as the preferred migration owner; keep this page as the coordinating utility-string boundary. |
| Sentinels and pools | [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md), [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md) | Shared string infrastructure; final ownership depends on the `StringUtil.cpp` versus `StringBase.cpp` split. |

## Evidence

- Live IDA confirms the UTF-16 SSO-7 endpoint helpers at `0x00421310-0x00421362` and `0x00421590-0x004216cb`.
- Live IDA confirms the historical `0x00421310-0x004216cb` page is a mixed helper island. Only [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md) and [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md) belong to the early wide-string layout; the middle contains pane, fitting-room, checkbox, runtime, and vector helpers.
- Earlier recovery mixed a true virtual base object with a reference-counted string class; live IDA confirms the string prefix at `0x00582500-0x00583206`.
- IDA confirms pointer-backed `SimpleUString` wrappers at `0x00583210`, `0x00583280`, and `0x005845b0`, with broad caller fan-in.
- IDA confirms `0x0052a460` writes a vtable named `FunctionObjectT<mystr::StringBase<wchar_t,mystr::mychar_traits<wchar_t>>>::vftable`, preserving the `StringBase` template name outside the recovered `LObject` owner.
- 2026-06-04 live IDA reconfirmed `SimpleUStringVector` destructor at `0x00493f10-0x00493f79`, grow/insert at `0x0049cc40-0x0049ce48`, and push-back at `0x00584910-0x0058498b`, proving a begin/end/capacity vector of 4-byte pointer-backed string-handle slots.
- `StringIter` methods at `0x00584d80`, `0x00584df0`, `0x00584e40`, and `0x00584e60` form a small `LObject`-derived iterator over wide-character data.
- IDA confirms empty string sentinels at `0x00670278` and `0x00670290`, plus eight `PoolAllocator` globals at `0x0069bacc-0x0069bbe4`, are used by the `0x00582d80`, `0x00582e30`, `0x005832f0`, and `0x005833a0` string allocation/release helpers.
- `by-project-structure/proposed-source-tree.md` places both `util/StringUtil.cpp` and `util/StringBase.cpp` and records the intended split: `StringUtil` coordinates the broad Unicode utility family, while `StringBase` is the preferred owner for the large ref-counted ANSI/UTF-16 buffer implementation.

## Recovered Output Caveats

- Earlier `SimpleUString` recovery omitted real disabled methods `SimpleUString_from_char` at `0x00583210`, `SimpleUString_from_wchar` at `0x00583280`, and `CompareWide` at `0x005845b0`.
- `SimpleUStringVector::GrowAndInsert` metadata ends at `0x0049ce23`, while live IDA reports start `0x0049cc40` size `0x209`, making `0x0049ce48` the last executable byte.
- Earlier `StringIter` recovery expects a constructor at `0x00584dc0`, but IDA reports `0x00584dc0` is not a function. Treat it as a projected/manual boundary until raw disassembly confirms a real constructor slice.
- Earlier `LObject` recovery contains real string code but also includes FolderTreePane traversal callbacks and historical `m_vtable`/`vftptr_0x0` naming pollution where the field is actually a string data pointer.
- Historical string metadata includes stale owner projections for unrelated byte-string/small-string helpers. Do not merge the SSO-15 byte-string family into `SimpleUString` without a separate layout pass.

## Source-Structure Decision

Use `util/StringUtil.cpp` as the broad utility-string coordination module, but prefer [UID:0000OA][StringBase](by-file/StringBase.md) / `util/StringBase.cpp` as the first migration target for the `0x00582500-0x00584d7d` ref-counted ANSI/UTF-16 buffer implementation. A later split into `SimpleUString.cpp`, `SimpleUStringVector.cpp`, and `StringIter.cpp` is plausible if original-source evidence appears, but the proposed tree currently benefits from one shared utility-string family plus the explicit `StringBase` owner candidate.

Keep [UID:0000KV][LObject](by-file/LObject.md) as the runtime/base object only. Do not move FolderTreePane callbacks into this module.

## Scope Exclusions

- Do not attach FolderTreePane traversal callbacks from earlier `LObject` recovery to `StringUtil`; they are owner pollution around the string-buffer family.
- Do not absorb packet/string-key transform helpers from [UID:0000M9][PacketTransform](by-file/PacketTransform.md) merely because they manipulate strings; their caller and global-state evidence is network-protocol specific.
- Do not treat `FunctionObjectT<mystr::StringBase<...>>` deleting-destructor wrappers as proof of a `StringUtil.cpp` class. They belong with shared callback/template support unless a construction site proves a file-local source declaration.

## Score Rationale

- Completion is raised because the page now has a cluster-by-cluster ownership map, explicit validator output root, proposed-source-tree evidence, high-confidence vector and SSO endpoint attachments, and scope exclusions for the major recovered-owner traps.
- Confidence is raised because live IDA reconfirmed exact StringUtil child boundaries, vector slot behavior, SSO endpoint behavior, caller/callee sets, and padding boundaries. It remains below final confidence because the original split between `StringUtil.cpp`, `StringBase.cpp`, possible `SimpleUString.cpp`, and pool helper ownership is still not proven from final source.

## Cross-References

- [UID:0000D9][SimpleUString](by-class/SimpleUString.md)
- [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md)
- [UID:0000E7][StringIter](by-class/StringIter.md)
- [UID:00007D][LObject](by-class/LObject.md)
- [UID:0000OA][StringBase](by-file/StringBase.md)
- [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md)
- [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md)
- [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md)
- [UID:0001J1][0x00582500-0x00583206.LObjectStringConstructionAndCow](by-memory/0x00582500-0x00583206.LObjectStringConstructionAndCow.md)
- [UID:0001J3][0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation.md)
- [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md)
- [UID:0000WT][0x00421310-0x004216cb.SimpleUStringSso7](by-memory/0x00421310-0x004216cb.SimpleUStringSso7.md)
- [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md)
- [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md)
- [UID:0001J2][0x00583210-0x005845eb.SimpleUStringPointerBacked](by-memory/0x00583210-0x005845eb.SimpleUStringPointerBacked.md)
- [UID:000236][0x005151b0-0x005151ef.DefaultCodepageConversionWrappers](by-memory/0x005151b0-0x005151ef.DefaultCodepageConversionWrappers.md)
- [UID:000112][0x00493f10-0x00493f79.SimpleUStringVectorDestructor](by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md)
- [UID:00012G][0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert](by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md)
- [UID:0001J4][0x00584910-0x0058498b.SimpleUStringVectorPushBack](by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md)
- [UID:0001J5][0x00584d80-0x00584e9e.StringIter](by-memory/0x00584d80-0x00584e9e.StringIter.md)
- [UID:0001QS][client_string_handling](by-meta/client_string_handling.md)
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)

## Changes

- 2026-05-30: Existing evidence described `0x00421310-0x004216cb` as a compact early wide-string helper neighborhood. Changed this to endpoint-only `SimpleUString`/`StringUtil` ownership and kept the full range as a mixed aggregate map. Evidence: IDA MCP function inventory/decompilation/byte audit for `0x00421310-0x004216cb`; only the `0x00421310` and `0x00421590` endpoint helpers from that island match the SSO-7 string layout.

- 2026-05-31: Updated the `SimpleUStringVector` model and projected path.
  - Before: the page described the vector as contiguous `SimpleUString` elements and left `PROPOSED_RECONSTRUCTION_PATH` blank.
  - After: documented the 4-byte pointer-backed string-handle slot model, corrected linked vector helper ranges, raised scores to `64/80`, and set `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`.
  - Evidence: IDA MCP decompilation of `0x00493f10`, `0x0049cc40`, and `0x00584910`; `proposed-source-tree.md` already lists `util/StringUtil.cpp`.
- 2026-06-02: Raised scoring from `64/80` to `72/84`.
  - Before: the page contained the main evidence but did not summarize current ownership by helper family or record the major scope exclusions in one place.
  - After: added the current ownership map, autogen root, proposed-source-tree backing, scope exclusions, and score rationale while keeping final C++ deferred.
  - Evidence: existing exact memory/type/global docs for `SimpleUString`, `SimpleUStringVector`, `StringIter`, `StringBase`, sentinels/pools, and the `util/StringUtil.cpp` / `util/StringBase.cpp` split in [proposed-source-tree](by-project-structure/proposed-source-tree.md).
- 2026-06-04 live IDA evidence pass:
  - Before: `COMPLETION:72`, `CONFIDENCE:84`, the vector class/helper pages and SSO endpoint helpers were documented but not attached to the StringUtil parent, and the file page still carried stale non-IDA provenance wording.
  - After: raised to `COMPLETION:84`, `CONFIDENCE:88`, recorded the live IDA basis for attaching [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md), vector helper pages, and SSO endpoint helpers to [UID:0000OB][StringUtil](by-file/StringUtil.md), and replaced stale provenance wording.
  - Evidence: live IDA confirms `0x00493f10`, `0x0049cc40`, `0x00584910`, `0x00421310`, and `0x00421590` function bounds, caller/callee sets, 4-byte vector slot behavior, SSO-7 reset/assign behavior, and padding boundaries. C++ remains blank because the final split across `StringUtil`, `StringBase`, possible `SimpleUString`, and pool helpers remains below the 95/95 gate.
