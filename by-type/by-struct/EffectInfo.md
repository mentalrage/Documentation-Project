*** UID:0001U8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct EffectInfo
{
    int effectKeyOrId;
    EffectFrameRecord *primaryFrames;
    int primaryUnknown0;
    unsigned char primaryFlagOrReserved;
    unsigned char primaryPadding[3];
    int primaryFrameCount;
    int primaryRangeStart;
    int primaryRangeEnd;
    EffectFrameRecord *secondaryFrames;
    int secondaryUnknown0;
    unsigned char secondaryFlagOrReserved;
    unsigned char secondaryPadding[3];
    int secondaryFrameCount;
    int secondaryRangeStart;
    int secondaryRangeEnd;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EffectInfo

## UID0003Z4 Effect-List Consumer Synchronization - 2026-07-14

- Preserve all current metadata and formal C++. `effectKeyOrId` is copied into public `EffectObjectPane::m_effectId` at relative `+0x148` and is the exact key used by UID0004QK/UID0004QL same-ID deletion, UID000232 reuse, UID0003Z6 special-effect ID 134 removal, and UID0004QH final cleanup.
- Descriptor primary/secondary frame/range groups map to LivingObjectPane `m_primaryEffectObjectPanes` and `m_secondaryEffectObjectPanes`; MapPane creation selector `1` registers primary/type 2 and selector `0` registers secondary/type 4.
- Historical target-list type2/type4 labels and any ObjectPane-object-ID comparison are rejected for current source. This bounded dependency synchronization does not alter EffectInfo layout, score, owner, or unrelated fields.
- Cross-references: [UID:0004QK][0x0053adb0-0x0053ae06.LivingObjectPaneAddPrimaryEffectObjectPane](by-memory/0x0053adb0-0x0053ae06.LivingObjectPaneAddPrimaryEffectObjectPane.md), [UID:0004QL][0x0053ae10-0x0053ae66.LivingObjectPaneAddSecondaryEffectObjectPane](by-memory/0x0053ae10-0x0053ae66.LivingObjectPaneAddSecondaryEffectObjectPane.md), and [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md).

## Status

- Confidence: strong for size, pointer/count ownership, and descriptor source; medium for final semantic field names.
- Owner file: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md).
- Autogen parent: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), emitted after [UID:0001U7][EffectFrameRecord](by-type/by-struct/EffectFrameRecord.md) at position `2`.
- Source resource: `EFFECT.TBL`.
- Size: `0x34` bytes.
- Rebuild handling: `resource-derived` source declaration/POD layout owned by the effect image-library module.

## Layout

```text
EffectInfo
  +0x00  int effectKeyOrId
  +0x04  EffectFrameRecord* primaryFrames
  +0x08  int primaryUnknown0
  +0x0c  uint8 primaryFlagOrReserved
  +0x0d  uint8[3] primaryPadding
  +0x10  int primaryFrameCount
  +0x14  int primaryRangeStart
  +0x18  int primaryRangeEnd
  +0x1c  EffectFrameRecord* secondaryFrames
  +0x20  int secondaryUnknown0
  +0x24  uint8 secondaryFlagOrReserved
  +0x25  uint8[3] secondaryPadding
  +0x28  int secondaryFrameCount
  +0x2c  int secondaryRangeStart
  +0x30  int secondaryRangeEnd
```

The `primary` and `secondary` labels follow the runtime selection names used in this documentation, not recovered original authoring terminology. The loader reads the `+0x1c` sequence header first and the `+0x04` sequence header second, while `EffectObjectPane` selects between the two headers with its constructor mode argument.

## Loader Behavior

- `EffectObjImageLib::LoadEffectTables` reads an `EFFECT.TBL` count, resizes the descriptor array to `count * 0x34`, then loads each descriptor.
- Each descriptor owns two heap arrays of [UID:0001U7][EffectFrameRecord](by-type/by-struct/EffectFrameRecord.md) entries.
- Each frame record is `0x10` bytes; the loader reads two integer fields, one float field, and one integer field per record.
- The ordinary and scalar deleting destructors free both frame arrays per descriptor and reset pointer/count/range fields.
- The descriptor starts with the source effect key/id at `+0x00`; `EffectObjectPane` copies this value into its runtime object at `+0x148`.
- The two sequence headers are each 24 bytes: pointer, scalar/flag/reserved dword pair, count, range start, and range end. `EffectObjectPane` copies either `+0x04..+0x1b` or `+0x1c..+0x33` into its runtime frame-sequence fields at `+0x12c..+0x143`, then initializes current-frame state separately.
- [UID:00023H][0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping](by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md) returns runtime byte `+0x14c`. The constructor sets that byte from the selected sequence range fields copied into runtime `+0x13c/+0x140`, so descriptor ranges with nonnegative start and end become reusable/loop-active effect children.
- No nested ownership has been observed beyond the two frame-array pointers. Cleanup is descriptor-array-level through [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), so this remains a plain file-level resource POD rather than a runtime class.
- 2026-06-16 generated-output check: active `source-3/simroot_v2/class_EffectObjImageLib.cpp` now includes the destructor, `RenderEffectFrame`, `GetEffectInfo`, and `LoadEffectTables`, but its local `struct EffectInfo` at `GetEffectInfo` is still a generated overlay with generic `arg*` fields and no stable pointer/header member declarations. That output confirms the type is routed to `EffectObjImageLib.cpp`, but it does not safely resolve the final source-facing member names.

## MapPane Object-Effect Use

[UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md) uses `EffectInfo::effectKeyOrId` at `+0x00` to match existing `EffectObjectPane` children by their copied `m_effectId` at `+0x148`. It processes `secondaryFrameCount` / `secondaryRangeStart` / `secondaryRangeEnd` first through `LivingObjectPane::m_secondaryEffectObjectPanes`, then `primaryFrameCount` / `primaryRangeStart` / `primaryRangeEnd` through `m_primaryEffectObjectPanes`.

Source-ready [UID:0003TE][0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch](by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md) is the coordinate/no-target counterpart. It copies exactly one complete 52-byte descriptor, checks the clamped visible coordinate first, then processes the secondary count/range before the primary count/range. For each nonnegative range it scans the corresponding ObjectList effect-row bucket in reverse and matches `effectKeyOrId` plus `EffectObjectPane::IsLooping()`; an unmatched or negative-range pass still creates a null-target pane through UID0003TF with sequence `0` for secondary or `1` for primary. Negative ranges therefore suppress reuse eligibility, not creation.

UID0003TE forwards the same descriptor by value to UID0003TF and preserves the descriptor's source ownership in EffectObjImageLib. Its coordinate, timer-action, and render-order arguments are separate MapPane method inputs, not EffectInfo fields. This consumer adds no evidence for renaming `primaryUnknown0`, `primaryFlagOrReserved`, `secondaryUnknown0`, or `secondaryFlagOrReserved`; those original spellings remain unresolved and the existing formal declaration and `88/90` score stay unchanged.

Source-ready [UID:0003TF][0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane](by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md) consumes the complete descriptor by value. Its explicit `retn 0x4c` and frame slots `[ebp+0x14..+0x47]` prove the `0x34` copy rather than a reference/pointer signature. UID000232 and the coordinate dispatcher each copy/push the full record before calling it.

UID0003TF initializes `rangeStart/rangeEnd` from secondary offsets `+0x2c/+0x30`, replacing them with primary offsets `+0x14/+0x18` only for sequence `1`. The selected range controls both constructor `m_looping` initialization and whether MapPane schedules timer event 2; both bounds must be nonnegative for scheduling. Sequence `0` registers through the secondary LivingObjectPane list, sequence `1` through the primary list, while other values enter neither target list.

The constructor copies `effectKeyOrId` to EffectObjectPane `+0x148` and one 24-byte sequence header (`+0x04` or `+0x1c`) to EffectObjectPane `+0x12c..+0x143`. It stores the separately supplied `renderAfterLivingObjects` byte at EffectObjectPane `+0x14d`; that flag is not an EffectInfo field and must not be modeled as descriptor padding or a compact-descriptor property.

Metadata and formal POD stay `88/90`, owner/emitter UID0000IY, position `2`, and reconstructable true. Unknown scalar/reserved names are not consumed by UID0003TF and remain unchanged; target completion does not justify speculative struct renaming.

The `primary` and `secondary` names remain descriptive documentation terms rather than original-name proof. UID 000232 depends on the established field offsets and pass order, not on those labels being final source spellings.

B008's UID 000232 recheck independently validated this MapPane pass mapping and rejected coordinate/position interpretations for `+0x14/+0x18/+0x2c/+0x30`: those fields are loop/range bounds consumed by `EffectObjectPane` construction and MapPane reuse tests, not map coordinates. No struct-field rename is applied here because original source spellings remain unavailable.

## Ownership And Parent Gate

Attach this source declaration to [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md). `EffectInfo` is an `EFFECT.TBL` descriptor type owned by the effect image library: the constructor calls `LoadEffectTables`, `GetEffectInfo` copies descriptors out of the library's `ProtectedArray<EffectInfo>`, the destructor frees descriptor-owned frame arrays, and runtime effect panes consume copied descriptors rather than declaring or owning the resource format.

Do not attach this struct to [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md) as an object-layout field. The class has a `ProtectedArray<EffectInfo>` member and scratch descriptor, but the struct itself is a file/resource-record declaration shared by loader/accessor/runtime consumers. The direct file parent is `89/86`, and this child is now `86/89`, so the strict child/direct-parent `85/85` gate clears.

## IDA Evidence

- 2026-05-31 IDA MCP `decompile 0x004de7d0` confirms the descriptor protected array is allocated and copied in `52`-byte strides.
- IDA `decompile 0x004de3e0` copies one descriptor as three 16-byte chunks plus a final four-byte field, proving the `0x34` byte size used by callers.
- IDA destructor decompilation at `0x004de050` and `0x004e62f0` iterates descriptors in `0x34` byte steps, frees both nested frame arrays, clears the two count fields, and resets range fields to `-1`.
- 2026-06-11 A003 live IDA MCP `py_eval` reconfirmed `GetEffectInfo` at `0x004de3e0-0x004de420`, `LoadEffectTables` at `0x004de7d0-0x004dec23`, the ordinary destructor at `0x004de050-0x004de18a`, the scalar deleting destructor at `0x004e62f0-0x004e6456`, and `EffectObjectPane` construction at `0x005387b0-0x0053887c`.
- The same live pass confirmed `GetEffectInfo` callers at `0x0050e33b`, `0x0050e89d`, and `0x005a2ef4`; `LoadEffectTables` has the constructor caller at `0x004ddffb`; `EffectObjectPane` construction is called from the create/apply helper at `0x0050eacf`.
- 2026-06-11 decompilation of `LoadEffectTables` confirms descriptor-array allocation/copy/advance at `count * 52`, `memmove(..., 52 * count)`, and `+52` per descriptor. The loader reads descriptor integer fields at `+0x00`, `+0x28`, `+0x2c`, `+0x30`, `+0x10`, `+0x14`, and `+0x18`, allocates the `+0x1c` frame array as `16 * +0x28`, allocates the `+0x04` frame array as `16 * +0x10`, then copies the assembled `0x34` descriptor into the protected array or scratch fallback.
- 2026-06-11 destructor decompilation confirms the `+0x1c` array pointer is freed and cleared first, with `+0x28` cleared and `+0x2c/+0x30` set to `-1`; the `+0x04` array pointer is freed and cleared second, with `+0x10` cleared and `+0x14/+0x18` set to `-1`.
- 2026-06-11 decompilation of `EffectObjectPane` construction confirms the copied descriptor's `+0x00` id is stored at runtime offset `+0x148`, and the constructor copies either the `+0x04..+0x1b` or `+0x1c..+0x33` 24-byte sequence header into runtime offsets `+0x12c..+0x143`.
- 2026-06-16 live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed `GetEffectInfo` at `0x004de3e0-0x004de420`, with callers at `0x0050e33b`, `0x0050e89d`, and `0x005a2ef4`; the decompilation still copies three 16-byte chunks plus the final dword from either `this+0x14` scratch storage or `this[3] + 52 * (effectId - 1)`.
- The same session reconfirmed `LoadEffectTables` at `0x004de7d0-0x004dec23`, `EffectObjectPane` construction at `0x005387b0-0x0053887c`, and `RenderEffectFrame` at `0x004de190-0x004de29f`. The constructor still copies one 24-byte descriptor sequence header by mode, while render/update consumers reach the selected `EffectFrameRecord` entries through the copied header rather than re-reading the descriptor table.

## Score Rationale

- Completion is `88` because the page records the exact `0x34` layout, loader read/order details, two owned `EffectFrameRecord` arrays, descriptor-copy accessor behavior, destructor cleanup offsets, runtime `EffectObjectPane` header selection, resource-derived ownership, direct file-parent gate, active generated-output limitations, emitter order, and formal first-draft POD declaration.
- Confidence is `90` because the descriptor size, stride, copy shape, frame-array ownership, cleanup offsets, caller flow, runtime consumer selection, and generated-output blocker were rechecked against live IDA MCP and linked effect pages. Confidence remains below final-audit quality because source-facing names for the two sequence families and scalar/reserved fields are still provisional.

## Cross-References

- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md)
- [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md)
- [UID:0001U7][EffectFrameRecord](by-type/by-struct/EffectFrameRecord.md)
- [UID:00017L][0x004de050-0x004de189.EffectObjImageLibDestructor](by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md)
- [UID:0002HA][0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo](by-memory/0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md)
- [UID:0002HB][0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables](by-memory/0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables.md)
- [UID:0001D9][0x005387b0-0x00538baa.EffectObjectPaneCore](by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md)
- [UID:00023H][0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping](by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md)

## Changes

- 2026-07-15 Agent-B005 UID0003TE callback:
  - Added the exact coordinate/no-target consumer, one-record copy, secondary-before-primary pass order, reverse row-bucket reuse match, negative-range create behavior, null-target sequence mapping, and separation of MapPane arguments from descriptor fields.
  - Preserved the complete `0x34` formal POD, ownership/emission route, `88/90` metadata, and all uncertainty for unrelated scalar/flag names.

- 2026-07-15 B001 UID0003TF accepted source-quality callback:
  - Preserved the exact `0x34` POD formal, `88/90` score, owner/emitter/position, loader/destructor evidence, and unresolved original scalar spellings.
  - Added exact by-value target ABI, primary/secondary range selection, constructor copy, event-2 gate, list-registration mapping, and separation of `renderAfterLivingObjects` from descriptor fields.

- 2026-06-30 B008 empty-emitter implementation callback:
  - Before: `86/89`, blank formal block and no emitter position.
  - After: `88/90`, formal `EffectInfo` POD declaration attached at emitter position `2` under [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md).
  - Summary/evidence: accepted report used current MCP session `supervisor_resume_20260629`, server-health call id `3`, `0x34` descriptor stride/copy proof, loader read order, two `EffectFrameRecord` pointer/count/range families, destructor cleanup/reset offsets, `EffectObjectPane` descriptor-copy consumers, and MapPane pass mapping to emit the descriptor support type. Primary/secondary and scalar/reserved field names remain documentation terms, not original-name proof.

- 2026-06-20 B007 object-effect descriptor implementation support:
  - Added UID 000232 usage: `effectKeyOrId` matches `EffectObjectPane::m_effectId`, secondary fields drive type-4 attached-object processing first, and primary fields drive type-2 attached-object processing second.
  - Retained the caveat that `primary` and `secondary` are documentation terms, not original source proof.
- 2026-06-21 B008 object-effect report incorporation:
  - Added B008's validation that UID 000232 uses `+0x14/+0x18/+0x2c/+0x30` as primary/secondary range bounds rather than coordinates, while preserving the existing descriptive field names.
- 2026-06-16 A002 Goal2 type-confidence refresh:
  - Before: `85/88`.
  - After: `86/89`; owner/emitter remain [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), with final C++ still blank.
  - Summary/evidence: live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed the `GetEffectInfo` copy shape/callers, loader/accessor/consumer method boundaries, and `EffectObjectPane` 24-byte sequence-header selection. Active generated `class_EffectObjImageLib.cpp` was checked; it proves current routing but still uses generic/generated `EffectInfo` field names, so the final member-name blocker remains real.
- 2026-06-18 B003 source-quality follow-up:
  - Added the [UID:00023H][0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping](by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md) runtime consumer link.
  - Evidence: B003 tied `EffectInfo +0x00` to runtime `EffectObjectPane +0x148` and the selected sequence range fields to runtime loop/reuse byte `+0x14c`.
- 2026-06-11 A003 normal assignment pass:
  - Before: `76/86`, reconstructable but unassigned, with loader/destructor/accessor evidence but no runtime descriptor-selection details or parent-gate decision.
  - After: raised to `85/88` and attached to [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md).
  - Summary/evidence: live IDA MCP reconfirmed exact function boundaries and callers, descriptor-array `52`-byte stride, `GetEffectInfo` by-value copy shape, loader field reads and owned array allocations, destructor cleanup offsets for both frame-array families, and `EffectObjectPane` runtime selection/copy of one 24-byte sequence header. The direct file parent is `89/86`, so the strict child/direct-parent `85/85` gate clears. B008's 2026-06-30 callback later attached the formal POD declaration while preserving original-name caveats.
- 2026-05-31 IDA evidence and scoring update:
  - Before: metadata was unevaluated (`0/0`) and reconstructability was blank.
  - After: marked `RECONSTRUCTABLE:TRUE`, with completion/confidence set to `76/86`.
  - Summary/evidence: IDA MCP confirms the `0x34` descriptor size, descriptor-copy helper, loader ownership of two nested frame arrays, and destructor cleanup; final user-facing names for several descriptor scalar fields remain provisional.
