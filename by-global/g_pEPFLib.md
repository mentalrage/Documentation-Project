*** UID:0000QU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0000QU] no standalone global definition.
// UID00006E owns the sole declaration `extern ImageLib *g_pEPFLib`; this semantic page emits no duplicate definition. Constructor/destructor and storage children carry the concrete writes, clears, and address evidence, while ResourceLayoutTable remains a compatibility typedef/facet over ImageLib.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pEPFLib

## Status

- Symbol kind: process-wide singleton pointer / global data
- Address: [UID:0001OQ][0x0067a744-0x0067a748.g_pEPFLib](by-memory/0x0067a744-0x0067a748.g_pEPFLib.md)
- Observed aliases: current IDA `g_pEPFLib`, historical `DAT_0067a744` / `dword_67A744`
- Accepted source type: `ImageLib *`, declared once as `extern ImageLib *g_pEPFLib` by [UID:00006E][ImageLib](by-class/ImageLib.md); historical `ResourceLayoutTable *` is retained only as a superseded compatibility-facet hypothesis.
- Proposed owner module: [UID:0000K2][ImageLib](by-file/ImageLib.md)
- Confidence: strong for storage, lifetime, exact `ImageLib *` source type, ImageLib ownership, non-virtual ResourceLayout compatibility API, and broad singleton-consumer pattern. Exact lost typedef/header spelling remains inferred but does not reopen the pointer type or authorize a second object.

## Role

`g_pEPFLib` is the process-wide EPF/EPD layout and image resource registry. It is constructed by [UID:00006E][ImageLib](by-class/ImageLib.md), whose accepted source declaration exposes the non-virtual lookup family directly and then provides `typedef ImageLib ResourceLayoutTable` as a compatibility name. [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) documents that method/facet history; it is not a second constructed object or an alternate global type.

The registry's `+0x0c` field is a [UID:000079][List](by-class/List.md) of 44-byte [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md) rows. The IDA-confirmed [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md) and [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md) anchor the concrete object; earlier notes used `ResourceLayoutStore` for this field, but current evidence says that is an alias over the generic container.

The accepted source contract is:

```cpp
extern ImageLib *g_pEPFLib;
typedef ImageLib ResourceLayoutTable;
```

The typedef spelling remains an evidence-ranked reconstruction because original symbols are lost, but it is the current source contract. Do not emit `ResourceLayoutTable *g_pEPFLib`, a base subobject, a separate ResourceLayout object, `g_pResourceMan`, or a second declaration/definition from this page.

## Lifetime Evidence

- IDA MCP disassembly of `0x004cffb0` shows `ImageLib::ImageLib` writes `g_pEPFLib = this` after `LObject` construction and vtable setup.
- IDA MCP xrefs to `0x0067a744` include writes inside `ImageLib::ImageLib` at `0x004cffef` / `0x004cfff6` and cleanup in `ImageLib::~ImageLib` at `0x004d00fa`.
- The ordinary destructor at [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md) and scalar deleting destructor at `0x004e64a0` both release list-row payloads, destroy the `+0x0c` list, and clear this singleton. The source-authored ordinary destructor now expresses the clear as `g_pEPFLib = 0;`, matching the store at `0x004d00fa`.
- IDA MCP xrefs also show many reads from UI panes and image-library code that use the pointer before calling layout lookup helpers.
- A 2026-05-25 recheck confirms `0x0067a744` remains global storage, not a function, and the `ImageLib` vtable at `0x0061b654` is only referenced by the constructor/destructor family.
- `ImageLib::ScalarDeletingDestructor` at `0x004e64a0` releases cached payload blocks and clears this singleton.
- A 2026-06-14 C001 live IDA MCP recheck used active `NexusTK.exe.i64` with auto-analysis and Hex-Rays ready. `lookup_funcs` still reports `0x0067a744` as not a function; bytes around `0x0067a738-0x0067a758` are zero-initialized global storage.
- The same recheck found `0x0061b654` has only three xrefs, all from the ImageLib lifecycle family: `0x004d0009` in the constructor, `0x004d009a` in the ordinary destructor, and `0x004e64d1` in the scalar deleting destructor.
- `analyze_component` on `0x004cffb0`, `0x004d0070`, and `0x004e64a0` reconfirmed shared globals now labeled `ImageLib_vftable` and `g_pEPFLib`; paged xrefs to `0x0067a744` reconfirmed owner writes/clears and broad UI/render consumer reads, with additional pages available.
- 2026-06-16 C001 safe IDA refresh dry-run/applied/saved `dword_67A744 -> g_pEPFLib` and `off_61B654 -> ImageLib_vftable`; post-save `entity_query` confirmed both labels.
- 2026-06-27 B006 MCP session `80de0a67` keeps the same clear evidence and source split: [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md) clears this global at `0x004d00fa` and now carries formal `g_pEPFLib = 0;` C++, while [UID:0002IO][0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor](by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md) clears it at `0x004e652c` as compiler wrapper parity.

## Consumer Pattern

Typical callers load `g_pEPFLib`, pass it as `this`, then call one of the [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) methods:

- `LookupLayoutEntry` at `0x004d02f0`
- `GetEntryRect` at `0x004d0530`
- `GetFrameSize` at `0x004d1730`
- `GetEntryCount` at `0x004d1780`
- [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md), the non-virtual frame-table projection method

Callers span fitting-room/item-shop panes, minimap controls, frame chrome, image libraries, item/effect helpers, and other UI/render code. This breadth supports a central render-resource singleton rather than ownership by any one feature pane.

[UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md) is an exact create-user consumer. Its paint method reads storage `0x0067a744`, calls `LookupLayoutEntry(L"USERPART.EPF", 0, &frameContext)` around `0x004fdaf0`, and renders the selected-cell frame with `USERPART.PAL`. The global remains ImageLib-owned; [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md) merely consumes the service alongside [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md).

[UID:0002FD][0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint](by-memory/0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint.md) is a direct lookup consumer: it calls `g_pEPFLib->LookupLayoutEntry(L"CHATVAR.EPF", frameIndex, &tileContext)`, with frame `0/1` selected from `g_pChattingVarietySelectPane`, before rendering `CHATVAR.PAL`. This strengthens the accepted ImageLib/compatibility-typedef source contract without moving resource ownership into Chatting.

The UID0002P6 cross-caller audit adds an especially strong non-virtual receiver pattern: its 81-xref family spans unrelated image/render consumers, and caller windows systematically load this global into `ecx` immediately before the projection call. The callee may reuse `ecx` after entry, but that register allocation does not erase the repeated source-level singleton receiver setup. This evidence routes UID0002P6 to [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) through [UID:0000K2][ImageLib](by-file/ImageLib.md), rather than to a free ImageFrameTable helper.

Batch120 caveat: the raw-buffer helper [UID:0002KQ][0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry](by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md) is reached from `UserLookPane::ParseLookPacket` after the caller loads `g_pEPFLib` into `ecx`, but the helper overwrites `ecx` and returns as a two-argument `__stdcall` routine. This global therefore supplies caller-side context and source-neighborhood evidence only; it is not a direct function owner for that raw helper.

## ResourceLayout Boundary

Current IDA evidence supports `g_pEPFLib` as the sole ImageLib-owned object exposing ResourceLayout-style non-virtual APIs, not as proof of a separate standalone `ResourceLayoutTable *` global. UID00006E now supplies the complete accepted `ImageLib` declaration, exact non-virtual methods, `typedef ImageLib ResourceLayoutTable`, and the sole `extern ImageLib *g_pEPFLib` declaration. The 2026-06-14 recheck confirmed `0x004d0120` as the named resource-index loader; `0x004d02f0`, `0x004d0530`, `0x004d1730`, and `0x004d1780` as `thiscall` accessors that call the lookup/load path when needed; and `0x004d04d0` as a small wrapper over the lookup helper. Exact method children carry the method bodies while this semantic global page emits no second definition.

## Score Rationale

Completion is `89` because the page documents storage, aliases, ImageLib ownership, lifetime refs, vtable refs, list/resource-layout model, consumer pattern, method-body routing, accepted `ImageLib *` contract, and the raw-buffer helper caveat. Confidence remains `88`: storage/lifecycle/type and the compatibility-facet decision are strong, while exact original typedef spelling, header placement, and several private method/field spellings remain inferred. The reconstruction C++ block intentionally carries a no-standalone-definition marker because UID00006E already owns the sole external declaration and exact lifecycle/method children own their bodies; this is one-definition routing, not unresolved pointer type.

## Open Questions

- No active pointer-type, owner, storage, one-definition, or independent-object question remains. Current source uses `extern ImageLib *g_pEPFLib` and `typedef ImageLib ResourceLayoutTable` through UID00006E.
- Exact original typedef/header spelling is not symbol-proven. This remains a confidence cap only; it does not justify emitting raw aliases, an independent base/facet object, or a second global.
- Historical aliases such as `DAT_0067a744` / `dword_67A744` remain useful search provenance in dated evidence and need not be erased.

## Historical / Superseded Source-Type Assumptions

- Earlier active alternatives allowed `ResourceLayoutTable *g_pEPFLib`, a non-virtual base subobject, a helper/facet object, or an unresolved final pointer type. Those were reasonable intermediate hypotheses before UID00006E installed the complete ImageLib declaration and compatibility typedef.
- The accepted reconstruction is one `ImageLib` object at `0x0067a744`, one source declaration `extern ImageLib *g_pEPFLib`, and one compatibility alias `typedef ImageLib ResourceLayoutTable`. The older alternatives remain historical evidence only and must not produce a second class, vtable, allocation route, storage object, declaration, or definition.

## Cross-References

- [UID:0001OQ][0x0067a744-0x0067a748.g_pEPFLib](by-memory/0x0067a744-0x0067a748.g_pEPFLib.md)
- [UID:0000K2][ImageLib](by-file/ImageLib.md)
- [UID:00006E][ImageLib](by-class/ImageLib.md)
- [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md)
- [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md)
- [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)
- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)
- [UID:000079][List](by-class/List.md)
- [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0002KQ][0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry](by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md)
- [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md)

## Changes

- 2026-08-11 B005 UID0000LY consumer synchronization:
  - Added the exact NewUserShapeSelectControlPane paint dependency, `USERPART.EPF` lookup, `USERPART.PAL` render role, storage address, and non-ownership disposition. Existing score, source type, owner/emitter, and one-definition routing remain unchanged.

- 2026-08-05 B006 UID0002FD resource-contract callback:
  - Preserved `89/88`, owner/emitter, storage/lifetime/xref evidence, method inventory, raw-helper caveat, and no-standalone-definition disposition.
  - Replaced active unresolved pointer/base alternatives with UID00006E's accepted `extern ImageLib *g_pEPFLib` plus `typedef ImageLib ResourceLayoutTable` contract and historicalized the former `ResourceLayoutTable *`/base/facet alternatives.
  - Added UID0002FD as a direct `CHATVAR.EPF` lookup consumer and explicitly rejected a second ResourceLayout object, `g_pResourceMan`, duplicate declaration/definition, or Chatting ownership.
- 2026-07-22 B004 UID000438 accepted support callback:
  - Score and metadata remain unchanged.
  - Added [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md) as a direct non-virtual `g_pEPFLib` receiver consumer, supported by systematic singleton setup across its 81-xref caller family.
  - Preserved the final ImageLib/ResourceLayoutTable pointer-type caveat and the contrasting raw-helper case where caller preload alone is insufficient.

- 2026-06-30 B011 ImageLib empty-emitter implementation:
  - Changed to: `COMPLETION:89`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000K2`, `EMITTER_UIDS:0000K2`.
  - Implemented the accepted formal no-standalone-definition marker. Constructor/destructor children carry the concrete writes and clears, and the ResourceLayoutTable method children carry the singleton API behavior.
  - The page rejects a direct `ResourceLayoutTable*` global definition, a duplicate singleton-storage definition, and raw-helper ownership via this global because the final pointer/base type and header boundary remain source-shape caps.
- 2026-06-27 B006 destructor source-quality implementation: no score change. Recorded that [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md) now emits source `g_pEPFLib = 0;` for the `0x004d00fa` clear, while the scalar wrapper retains the `0x004e652c` clear as compiler parity.
- 2026-06-16 C001 IDA singleton-label sync:
  - Changed confidence from `86` to `87`.
  - Summary/evidence: live IDA reconfirmed lifecycle writes/clears and vtable refs, then C001 saved `dword_67A744 -> g_pEPFLib` and `off_61B654 -> ImageLib_vftable`. The final C++ declaration still remains blank because the exact public type/header boundary is unresolved.
- 2026-06-14 C001 live IDA/source-boundary confidence refresh:
  - Changed score from `88/82` to `89/86`.
  - Summary/evidence: live IDA MCP reconfirmed zero-initialized storage at `0x0067a744`, constructor/destructor writes and clears, ImageLib vtable refs limited to lifecycle functions, shared lifecycle globals, broad consumer reads, and ResourceLayout API edges over the same singleton. The page now distinguishes ImageLib ownership from ResourceLayout-style API exposure more explicitly.
  - Reconstruction C++ remains blank because the final pointer/base type and header boundary are still open.
- 2026-06-08 A010 Batch120 parent/source audit:
  - Changed confidence from `80` to `82`.
  - Summary/evidence: added the `ResourceLayoutRawBufferLookupEntry` caller-preload caveat. The update strengthens the distinction between the singleton's ImageLib/ResourceLayout context and direct function ownership; final pointer type remains open, so confidence stays below the `85/85` assignment gate for this global as a direct parent candidate.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/80`. Summary/evidence: the page documents memory storage, aliases, ImageLib/resource-layout role, object/list layout refs, lifetime evidence, broad consumer pattern, and open final type/base questions.
- 2026-06-05: Marked reconstructable under [UID:0000K2][ImageLib](by-file/ImageLib.md). Evidence: live IDA MCP reports 231 xrefs to `0x0067a744`; decompilation confirms `0x004cffb0` writes the singleton, `0x004d0070` clears it in ordinary teardown, and `0x004e64a0` clears it in the deleting destructor path.

## 2026-07-23 B004 Accepted UID0002E6 Reconciliation (0000QU)

- Accepted source: B004 UID0002E6 report, Gate 1 SHA F8FE25AA9AD6922244A4C7EC84D390D41DE9782819D15DCD6D192A58C1D7EF26.
- Storage 0x0067a744 remains the single typed ImageLib pointer g_pEPFLib, with ImageLib lifecycle writes/clear and the accepted UID0002DL lookup consumer. No duplicate global is emitted.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C2E6-091 | 00006E | `g_pResourceMan` is rejected. Storage 0x0067a744 is ImageLib-owned `g_pEPFLib`; the strongest complete source route is `ImageLib` with `typedef ImageLib ResourceLayoutTable`, exact non-virtual lookup methods, and one `extern ImageLib *g_pEPFLib`. | Strong | ImageLib RTTI/lifecycle, sole global writes/clears, shared +0xc List, and ResourceLayout method family. | UID00006E complete formal; UID0000K2/UID0000BY/UID0000QU support; UID0002DL. | reject-invalid | implemented |
