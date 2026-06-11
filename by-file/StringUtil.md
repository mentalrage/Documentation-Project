*** UID:0000OB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# StringUtil

## Status

- Proposed module: `util/StringUtil.cpp`
- Proposed header: `util/StringUtil.h`
- Preferred companion module: [UID:0000OA][StringBase](by-file/StringBase.md) for the ref-counted `mystr::StringBase` family.
- Confidence: strong for utility ownership, high-confidence child attachment, vector/string-helper behavior, fixed-capacity wide-format wrappers, and exact IDA boundaries; medium-high for exact original source-file split.
- Current recovered source labels: `SimpleUString`, `SimpleUStringVector`, `StringIter`, and the string-heavy subset historically mixed with `LObject`.
- Validator output root: `NexusTK/util/StringUtil.cpp`

## File Role

`StringUtil.cpp` is the current working owner for shared client string infrastructure: the `SimpleUString` UTF-16 string helper, the vector container that stores contiguous 4-byte pointer-backed string-handle slots, the small `StringIter` character iterator used by text parsing/render helpers, and coordination with the ref-counted ANSI/UTF-16 [UID:0000OA][StringBase](by-file/StringBase.md) family historically tracked under [UID:0000KV][LObject](by-file/LObject.md).

This is utility code. It is referenced from application startup, DAT/resource loading, UI text, sound track-name formatting, patch/profile/config helpers, browser paths, and map/world UI. It should not be owned by any single caller module.

## Likely Contents

- [UID:0000D9][SimpleUString](by-class/SimpleUString.md)
- [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md)
- [UID:0000E7][StringIter](by-class/StringIter.md)
- [UID:0000OA][StringBase](by-file/StringBase.md) ref-counted string-buffer helpers, historically tracked as [UID:00007D][LObject](by-class/LObject.md) methods
- [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md), if final owner review keeps the fixed-block string pools as a separate utility file
- SSO-7 wide-string layout helpers [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md), [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md), and [UID:0002U5][0x00423060-0x00423204.FittingRoomEntryPartVectorGrowCopy](by-memory/0x00423060-0x00423204.FittingRoomEntryPartVectorGrowCopy.md)
- [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md)
- [UID:0000PW][g_emptySimpleUString](by-global/g_emptySimpleUString.md), the shared empty `SimpleUString` fallback object returned by metadata and UI/string consumers
- [UID:000236][0x005151b0-0x005151ef.DefaultCodepageConversionWrappers](by-memory/0x005151b0-0x005151ef.DefaultCodepageConversionWrappers.md)
- [UID:0002UA][0x004236e0-0x00423710.WideFormatWrapper](by-memory/0x004236e0-0x00423710.WideFormatWrapper.md), the fixed-`0x104` wide-format wrapper used by fitting-room, minimap, map-file, and screenshot path builders
- [UID:00030V][0x00421230-0x0042125d.WideFormatWrapper32](by-memory/0x00421230-0x0042125d.WideFormatWrapper32.md), the fixed-`0x20` wide-format wrapper used by fitting-room paint and non-fitting-room UI formatting callers; [UID:00030X][0x00421260-0x00421290.WideFormatWrapper128](by-memory/0x00421260-0x00421290.WideFormatWrapper128.md), the fixed-`0x80` sibling now assigned here after direct wrapper-family evidence review
- [UID:0001ZY][0x00453820-0x00453904.WideStringMapNodeSupport](by-memory/0x00453820-0x00453904.WideStringMapNodeSupport.md), shared wide-string keyed map/tree node support used by minimap and metadata code
- pointer-backed varargs format helpers around `0x00583210`, `0x00583280`, `0x00583720`, and `0x00583840`
- range comparison helpers around `0x005840f0` and `0x005845b0`

The recovered `FunctionObjectT<mystr::StringBase<...>>` classes are template/deleting-destructor support for [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), not primary `StringUtil.cpp` ownership proof. Keep them under [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md) unless caller evidence ties a construction site to this file.

## Current Ownership Map

| Area | Primary docs | StringUtil decision |
| --- | --- | --- |
| SSO-7 UTF-16 helpers | [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md), [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md), [UID:0002U5][0x00423060-0x00423204.FittingRoomEntryPartVectorGrowCopy](by-memory/0x00423060-0x00423204.FittingRoomEntryPartVectorGrowCopy.md) | Attach exact SSO-7 helpers through [UID:0000D9][SimpleUString](by-class/SimpleUString.md); do not treat either mixed `0x00421310-0x004216cb` or fitting-room physical adjacency as one string source unit. |
| Pointer-backed `SimpleUString` helpers | [UID:0001J2][0x00583210-0x005845eb.SimpleUStringPointerBacked](by-memory/0x00583210-0x005845eb.SimpleUStringPointerBacked.md) | String utility ownership is likely, with broad caller fan-in and recovered-output omissions recorded. |
| `SimpleUStringVector` | [UID:000112][0x00493f10-0x00493f79.SimpleUStringVectorDestructor](by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md), [UID:00012G][0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert](by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md), [UID:0001J4][0x00584910-0x0058498b.SimpleUStringVectorPushBack](by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md) | Attach as 4-byte pointer-backed string-handle vector support, not inline `SimpleUString` object storage. Exact method children route through [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md) where a class parent exists. |
| `StringIter` | [UID:0001J5][0x00584d80-0x00584e9e.StringIter](by-memory/0x00584d80-0x00584e9e.StringIter.md) | Keep iterator helper here while the recovered `0x00584dc0` constructor row remains a manual-boundary caveat. |
| Wide-string keyed map/tree support | [UID:0001ZY][0x00453820-0x00453904.WideStringMapNodeSupport](by-memory/0x00453820-0x00453904.WideStringMapNodeSupport.md) | Attach as shared utility string/container support: 44-byte nodes with UTF-16 small-string payloads, minimap and metadata caller spread, and a distinct layout from the 16-byte [UID:0000KR][LinkedList](by-file/LinkedList.md) helper family. |
| Ref-counted `StringBase` | [UID:0000OA][StringBase](by-file/StringBase.md), [UID:0001J1][0x00582500-0x00583206.LObjectStringConstructionAndCow](by-memory/0x00582500-0x00583206.LObjectStringConstructionAndCow.md), [UID:0001J3][0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation.md) | Use `StringBase.cpp` as the preferred migration owner; keep this page as the coordinating utility-string boundary. |
| Fixed wide path formatting | [UID:0002UA][0x004236e0-0x00423710.WideFormatWrapper](by-memory/0x004236e0-0x00423710.WideFormatWrapper.md), [UID:00030V][0x00421230-0x0042125d.WideFormatWrapper32](by-memory/0x00421230-0x0042125d.WideFormatWrapper32.md), [UID:00030X][0x00421260-0x00421290.WideFormatWrapper128](by-memory/0x00421260-0x00421290.WideFormatWrapper128.md) | Attach fixed-capacity wrappers here as shared `wchar_t` formatting utility code. `0002UA`, `00030V`, and `00030X` are assigned here; `00030X` has narrower direct caller fan-in than the others, but its fixed `0x80` CRT wrapper body and sibling pattern support `StringUtil` over fitting-room ownership. Physical adjacency to fitting-room is not ownership proof. |
| Sentinels and pools | [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md), [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md) | Shared string infrastructure; final ownership depends on the `StringUtil.cpp` versus `StringBase.cpp` split. |
| Empty `SimpleUString` fallback | [UID:0000PW][g_emptySimpleUString](by-global/g_emptySimpleUString.md), [UID:00027J][0x0066daec-0x0066db04.g_emptySimpleUString](by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md) | Attach the process-wide empty fallback here as shared `SimpleUString` support. `MetaMan`, `ItemHelpPane`, `CollectionPane`, and later UI/string helpers consume it, but the caller spread argues against metadata-local ownership. |

## Evidence

- Live IDA confirms the UTF-16 SSO-7 endpoint helpers at `0x00421310-0x00421362` and `0x00421590-0x004216cb`.
- 2026-06-10 B001 IDA MCP confirms [UID:0002U5][0x00423060-0x00423204.FittingRoomEntryPartVectorGrowCopy](by-memory/0x00423060-0x00423204.FittingRoomEntryPartVectorGrowCopy.md) is also SSO-7 `SimpleUString` support: exact `0x1a4` body, length/capacity at `+0x10/+0x14`, inline threshold `8`, growth through `0x00423d00`, cleanup through `0x00421310`, and callers from both fitting-room and startup conversion code.
- Live IDA confirms the historical `0x00421310-0x004216cb` page is a mixed helper island. Only [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md) and [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md) belong to the early wide-string layout; the middle contains pane, fitting-room, checkbox, runtime, and vector helpers.
- Earlier recovery mixed a true virtual base object with a reference-counted string class; live IDA confirms the string prefix at `0x00582500-0x00583206`.
- IDA confirms pointer-backed `SimpleUString` wrappers at `0x00583210`, `0x00583280`, and `0x005845b0`, with broad caller fan-in.
- 2026-06-07 IDA caller refresh confirms [UID:0002UA][0x004236e0-0x00423710.WideFormatWrapper](by-memory/0x004236e0-0x00423710.WideFormatWrapper.md) has broad path-formatting fan-in outside fitting-room, while its callee set is only the CRT stdio option accessor and secure wide-format routine. Treat it as shared string/format utility support, not fitting-room-private code.
- 2026-06-07 A010 Batch066 parent-gate review confirms [UID:0002UA][0x004236e0-0x00423710.WideFormatWrapper](by-memory/0x004236e0-0x00423710.WideFormatWrapper.md) can attach here under the corrected 85/85 rule: the child is `85/88`, this file page is `85/88`, and the direct ownership evidence is the documented shared fixed-`0x104` path-formatting role across fitting-room, minimap, map load/save, and screenshot callers.
- 2026-06-07 Batch 001 attached [UID:0001ZY][0x00453820-0x00453904.WideStringMapNodeSupport](by-memory/0x00453820-0x00453904.WideStringMapNodeSupport.md) here as shared wide-string keyed map/tree node support. The exact page records live IDA function starts at `0x00453820`, `0x00453840`, `0x00453860`, and `0x004538f0`, 44-byte node allocation/destruction behavior, UTF-16 small-string payload handling, minimap and metadata caller spread, and the exclusion from the separate `LinkedList` intrusive-list helper family.
- 2026-06-07 A003 Batch 074 attaches [UID:0000PW][g_emptySimpleUString](by-global/g_emptySimpleUString.md) here as shared empty `SimpleUString` fallback storage. The global page is `88/86`, this file is `85/88`, the exact storage child is [UID:00027J][0x0066daec-0x0066db04.g_emptySimpleUString](by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md), and the consumer spread covers metadata plus non-metadata UI/string paths. This makes `StringUtil` the corrected direct source-root parent while leaving the fine-grained `StringUtil.cpp` versus later `SimpleUString.cpp` split open.
- 2026-06-10 B001-021 supersedes the older virtual-readable candidate decision for [UID:00022C][0x004b12a0-0x004b13ce.VirtualReadableStringHelpers](by-memory/0x004b12a0-0x004b13ce.VirtualReadableStringHelpers.md): live IDA maps the receiver's virtual slots to the [UID:00004V][File](by-class/File.md) stream contract, so the string routines are output-buffer dependencies rather than direct `StringUtil` ownership evidence.
- 2026-06-08 A002 Batch101 parent-source follow-up checked this page as the direct owner for the fixed-capacity wide-format children split from [UID:0002DR][0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers](by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md). [UID:00030V][0x00421230-0x0042125d.WideFormatWrapper32](by-memory/0x00421230-0x0042125d.WideFormatWrapper32.md) clears `85/85` and has fitting-room plus non-fitting-room callers, so it attaches here. The later [UID:00030X][0x00421260-0x00421290.WideFormatWrapper128](by-memory/0x00421260-0x00421290.WideFormatWrapper128.md) follow-up confirms the same CRT option helper, fixed `0x80` secure wide-format body, and StringUtil wrapper-family pattern, so it also attaches here despite a fitting-room-only direct caller set.
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
- Do not attach [UID:00022C][0x004b12a0-0x004b13ce.VirtualReadableStringHelpers](by-memory/0x004b12a0-0x004b13ce.VirtualReadableStringHelpers.md) to `StringUtil` solely from callee similarity. B001-021 identifies the primary receiver as the [UID:00004V][File](by-class/File.md) stream interface; `StringUtil`/`StringBase` helpers only allocate and assign the destination strings.
- Do not absorb packet/string-key transform helpers from [UID:0000M9][PacketTransform](by-file/PacketTransform.md) merely because they manipulate strings; their caller and global-state evidence is network-protocol specific.
- Do not treat `FunctionObjectT<mystr::StringBase<...>>` deleting-destructor wrappers as proof of a `StringUtil.cpp` class. They belong with shared callback/template support unless a construction site proves a file-local source declaration.

## Score Rationale

- Completion is `87` because the page now has a cluster-by-cluster ownership map, explicit validator output root, proposed-source-tree evidence, high-confidence vector and SSO endpoint attachments, fixed-wide-format helper ownership including `0002UA`, `00030V`, and `00030X`, and scope exclusions for the major recovered-owner traps.
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
- [UID:0000PW][g_emptySimpleUString](by-global/g_emptySimpleUString.md)
- [UID:0001J1][0x00582500-0x00583206.LObjectStringConstructionAndCow](by-memory/0x00582500-0x00583206.LObjectStringConstructionAndCow.md)
- [UID:0001J3][0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation.md)
- [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md)
- [UID:0000WT][0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland](by-memory/0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland.md)
- [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md)
- [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md)
- [UID:0002U5][0x00423060-0x00423204.FittingRoomEntryPartVectorGrowCopy](by-memory/0x00423060-0x00423204.FittingRoomEntryPartVectorGrowCopy.md)
- [UID:0001J2][0x00583210-0x005845eb.SimpleUStringPointerBacked](by-memory/0x00583210-0x005845eb.SimpleUStringPointerBacked.md)
- [UID:000236][0x005151b0-0x005151ef.DefaultCodepageConversionWrappers](by-memory/0x005151b0-0x005151ef.DefaultCodepageConversionWrappers.md)
- [UID:0002UA][0x004236e0-0x00423710.WideFormatWrapper](by-memory/0x004236e0-0x00423710.WideFormatWrapper.md)
- [UID:00030V][0x00421230-0x0042125d.WideFormatWrapper32](by-memory/0x00421230-0x0042125d.WideFormatWrapper32.md)
- [UID:00030X][0x00421260-0x00421290.WideFormatWrapper128](by-memory/0x00421260-0x00421290.WideFormatWrapper128.md)
- [UID:0001ZY][0x00453820-0x00453904.WideStringMapNodeSupport](by-memory/0x00453820-0x00453904.WideStringMapNodeSupport.md)
- [UID:000112][0x00493f10-0x00493f79.SimpleUStringVectorDestructor](by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md)
- [UID:00012G][0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert](by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md)
- [UID:0001J4][0x00584910-0x0058498b.SimpleUStringVectorPushBack](by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md)
- [UID:0001J5][0x00584d80-0x00584e9e.StringIter](by-memory/0x00584d80-0x00584e9e.StringIter.md)
- [UID:0001QS][client_string_handling](by-meta/client_string_handling.md)
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)

## Changes

- 2026-06-10 B001-005 split-gate update: added [UID:0002U5][0x00423060-0x00423204.FittingRoomEntryPartVectorGrowCopy](by-memory/0x00423060-0x00423204.FittingRoomEntryPartVectorGrowCopy.md) to the SSO-7 helper set through direct parent [UID:0000D9][SimpleUString](by-class/SimpleUString.md). Evidence: IDA MCP confirms SimpleUString SSO-7 layout and mixed fitting-room/startup caller spread, making `StringUtil` the broad file parent rather than the direct child parent.
- 2026-06-10 B001-016 split audit: rerouted [UID:000112][0x00493f10-0x00493f79.SimpleUStringVectorDestructor](by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md) through direct class parent [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md), which remains attached here. Evidence: B001-016 IDA MCP reconfirmed the exact destructor boundary, vector triplet cleanup, 4-byte slot loop, caller/callee set, and padding.
- 2026-06-08 supervisor/B001 follow-up application:
  - Before: `COMPLETION:86`, `CONFIDENCE:88`.
  - After: `COMPLETION:87`, `CONFIDENCE:88`.
  - Evidence: accepted [UID:00030X][0x00421260-0x00421290.WideFormatWrapper128](by-memory/0x00421260-0x00421290.WideFormatWrapper128.md) as the fixed-`0x80` wide-format wrapper sibling of [UID:00030V][0x00421230-0x0042125d.WideFormatWrapper32](by-memory/0x00421230-0x0042125d.WideFormatWrapper32.md). The child page now records direct IDA evidence for the CRT option helper, `___stdio_common_vswprintf_s` fixed-capacity call, negative-result normalization, and why `StringUtil` is stronger than fitting-room caller locality.
- 2026-06-08 A002 Batch101 parent-source follow-up:
  - Before: `COMPLETION:85`, `CONFIDENCE:88`.
  - After: `COMPLETION:86`, `CONFIDENCE:88`.
  - Evidence: added fixed-capacity wrapper child evidence for [UID:00030V][0x00421230-0x0042125d.WideFormatWrapper32](by-memory/0x00421230-0x0042125d.WideFormatWrapper32.md), whose fitting-room and non-fitting-room caller mix supports direct `StringUtil` ownership. At that point [UID:00030X][0x00421260-0x00421290.WideFormatWrapper128](by-memory/0x00421260-0x00421290.WideFormatWrapper128.md) was recorded as a likely sibling pending the child gate; the later supervisor/B001 follow-up above superseded that pending state and assigned `00030X` here.
- 2026-06-07 A003 Batch 074 parent-chain repair:
  - Changed to: documentation only; scores unchanged at `85/88`.
  - Summary/evidence: added [UID:0000PW][g_emptySimpleUString](by-global/g_emptySimpleUString.md) to the StringUtil ownership map as a shared empty `SimpleUString` fallback. This supports generated coverage repair for [UID:00027J][0x0066daec-0x0066db04.g_emptySimpleUString](by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md): global child `88/86`, file parent `85/88`, metadata and non-metadata consumers, and no direct-parent gate support for `StringBase` because its confidence remains `80`.

- 2026-06-07 A010 Batch066 parent-gate update:
  - Before: `COMPLETION:84`, which blocked corrected 85/85 routing for [UID:0002UA][0x004236e0-0x00423710.WideFormatWrapper](by-memory/0x004236e0-0x00423710.WideFormatWrapper.md) despite the page already documenting shared wide-format utility ownership.
  - After: `COMPLETION:85`, `CONFIDENCE:88`, with an explicit Batch066 evidence note tying the fixed-`0x104` wide-format wrapper to this file page.
  - Evidence: [UID:0002UA][0x004236e0-0x00423710.WideFormatWrapper](by-memory/0x004236e0-0x00423710.WideFormatWrapper.md) documents the exact function body, CRT secure-format callee pair, and fitting-room/minimap/map/screenshot caller spread; the existing ownership map already places fixed wide path formatting under shared utility-string support rather than a caller-local module.
- 2026-06-07 A009 Batch 001 parent update: added [UID:0001ZY][0x00453820-0x00453904.WideStringMapNodeSupport](by-memory/0x00453820-0x00453904.WideStringMapNodeSupport.md) as shared wide-string keyed map/tree node support. Evidence comes from the child page's live IDA-confirmed four helper starts, 44-byte node layout, UTF-16 small-string payload behavior, minimap and metadata caller spread, and explicit exclusion from the separate 16-byte `LinkedList` helper family.
- 2026-06-08 A009 Batch117 candidate-source audit, superseded by 2026-06-10 B001-021:
  - Changed to: documentation only; scores remain `85/88`.
  - Summary/evidence: A009 checked [UID:00022C][0x004b12a0-0x004b13ce.VirtualReadableStringHelpers](by-memory/0x004b12a0-0x004b13ce.VirtualReadableStringHelpers.md) as a plausible shared string utility helper pair. B001-021 later compared the virtual slots to File-family vtables and rejected direct `StringUtil` ownership in favor of [UID:00004V][File](by-class/File.md).
- 2026-06-07: Added [UID:0002UA][0x004236e0-0x00423710.WideFormatWrapper](by-memory/0x004236e0-0x00423710.WideFormatWrapper.md) as shared fixed-wide-format support and accepted it as a child of this utility-string parent. Evidence: live IDA `callers` shows fitting-room plus minimap/map/screenshot path builders, and `callees` shows only the CRT formatting wrapper path; this resolves the immediate unassigned parent without claiming fitting-room ownership.
- 2026-05-30: Existing evidence described `0x00421310-0x004216cb` as a compact early wide-string helper neighborhood. Changed this to endpoint-only `SimpleUString`/`StringUtil` ownership and kept the full range as a mixed aggregate map. Evidence: IDA MCP function inventory/decompilation/byte audit for `0x00421310-0x004216cb`; only the `0x00421310` and `0x00421590` endpoint helpers from that island match the SSO-7 string layout.

- 2026-05-31: Updated the `SimpleUStringVector` model and projected path.
  - Before: the page described the vector as contiguous `SimpleUString` elements and left `PROPOSED_RECONSTRUCTION_PATH` blank.
  - After: documented the 4-byte pointer-backed string-handle slot model, corrected linked vector helper ranges, raised scores to `64/80`, and set `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`.
  - Evidence: IDA MCP decompilation of `0x00493f10`, `0x0049cc40`, and `0x00584910`; `proposed-source-tree.md` already lists `util/StringUtil.cpp`.
- 2026-06-02: Raised scoring from `64/80` to `72/84`.
  - Before: the page contained the main evidence but did not summarize current ownership by helper family or record the major scope exclusions in one place.
  - After: added the current ownership map, validator output root, proposed-source-tree backing, scope exclusions, and score rationale while keeping final C++ deferred.
  - Evidence: existing exact memory/type/global docs for `SimpleUString`, `SimpleUStringVector`, `StringIter`, `StringBase`, sentinels/pools, and the `util/StringUtil.cpp` / `util/StringBase.cpp` split in [proposed-source-tree](by-project-structure/proposed-source-tree.md).
- 2026-06-04 live IDA evidence pass:
  - Before: `COMPLETION:72`, `CONFIDENCE:84`, the vector class/helper pages and SSO endpoint helpers were documented but not attached to the StringUtil parent, and the file page still carried stale non-IDA provenance wording.
  - After: raised to `COMPLETION:84`, `CONFIDENCE:88`, recorded the live IDA basis for attaching [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md), vector helper pages, and SSO endpoint helpers to [UID:0000OB][StringUtil](by-file/StringUtil.md), and replaced stale provenance wording.
  - Evidence: live IDA confirms `0x00493f10`, `0x0049cc40`, `0x00584910`, `0x00421310`, and `0x00421590` function bounds, caller/callee sets, 4-byte vector slot behavior, SSO-7 reset/assign behavior, and padding boundaries. C++ remains blank because the final split across `StringUtil`, `StringBase`, possible `SimpleUString`, and pool helpers remains below the 95/95 gate.
