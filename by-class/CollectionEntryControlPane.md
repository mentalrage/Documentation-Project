*** UID:00002W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class CollectionEntryControlPane : public ControlPane
{
public:
    CollectionEntryControlPane(unsigned char groupIndex, signed char entryIndex, const RectBounds *bounds);
    virtual ~CollectionEntryControlPane();

    void NextPage();
    void PreviousPage();

protected:
    virtual void OnDraw();

private:
    void DrawWrappedText(const wchar_t *text, int charCount, const RectBounds *bounds);

    unsigned char m_groupIndex;
    signed char m_entryIndex;
    wchar_t m_volumeEpfName[128];
    wchar_t m_volumePaletteName[128];
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CollectionEntryControlPane

## Status

- Likely source file: [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- Address range: [UID:00010X][0x0048c640-0x0048e305.CollectionDialogControls](by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md); shared GrafPort/text helpers are dependencies, not class-owned methods.
- Historical recovered class filename: `class_CollectionEntryControlPane.cpp`; it is provenance rather than source-file authority.
- Confidence: very strong for dialog-control ownership, complete declaration, constructor arguments, object size, vtable route, local class fields, exact children, wrapped-text helper, corrected collection entry-record reads, and compiler-generated destructor boundary. The two retained page methods remain raw-route source because their bodies are exact while original call routing is not statically present.

## Class Purpose

`CollectionEntryControlPane` draws one item slot in the collection detail dialog. It renders locked, empty, and collected states, formats per-volume sprite filenames (`CLTVOL%d.EPF` / `CLTVOL%d.PAL`), and draws entry name, short name, index, and description from the collection player-data block.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `CollectionEntryControlPane(unsigned char groupIndex, signed char entryIndex, const RectBounds *bounds)` | [UID:0004JL][0x0048d3a0-0x0048d47b.CollectionEntryControlPaneConstructor](by-memory/0x0048d3a0-0x0048d47b.CollectionEntryControlPaneConstructor.md) `0x0048d3a0-0x0048d47b` | Constructs a control of type `8`, installs the three vtable views at `+0x00/+0xa0/+0xa4`, stores `m_groupIndex` at `+0x108`, stores signed `m_entryIndex` at `+0x109`, enables inherited image behavior, reads the selected collection group's `groupType/volumeId` byte, and formats the cached `CLTVOL%d.EPF` / `CLTVOL%d.PAL` names into the `+0x10a` and `+0x20a` buffers. Callers at `0x0048ca46` and `0x0048ce45` push `groupIndex`, `entryIndex` or sentinel `0xfe`, and `bounds`; the callee returns with `ret 0xc`. |
| `~CollectionEntryControlPane` body | `0x0048d480-0x0048d49f` | [UID:00010Y][0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor](by-memory/0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor.md); restores the three `CollectionEntryControlPane` vtable views and tail-jumps to shared `Pane` teardown `0x00544580`. |
| `OnDraw()` | [UID:0004JM][0x0048d4a0-0x0048d992.CollectionEntryControlPaneOnDraw](by-memory/0x0048d4a0-0x0048d992.CollectionEntryControlPaneOnDraw.md) `0x0048d4a0-0x0048d992` | Virtual draw method reached from vtable slot `0x006165d4`. It initializes a tile/render context, builds the repeated fullwidth-question placeholder text, formats the one-based entry number with `%2d`, draws the `CLTENTRY` frame, checks the signed empty-slot sentinel `m_entryIndex == 0xfe`, checks `m_entryIndex < totalEntries`, branches on entry-local `+0x48`, and then draws either the placeholder `CLTICON` path or the collected-entry volume sprite plus entry strings at local `+0x18`, `+0x00`, and `+0x30`. |
| `PreviousPage()` | [UID:0004JO][0x0048d9a0-0x0048d9b1.CollectionEntryControlPanePreviousPageRaw](by-memory/0x0048d9a0-0x0048d9b1.CollectionEntryControlPanePreviousPageRaw.md) `0x0048d9a0-0x0048d9b1` | Exact retained raw-route source body; behavior and range are preserved despite absent direct routing. |
| `NextPage()` | [UID:0004JP][0x0048d9c0-0x0048d9d1.CollectionEntryControlPaneNextPageRaw](by-memory/0x0048d9c0-0x0048d9d1.CollectionEntryControlPaneNextPageRaw.md) `0x0048d9c0-0x0048d9d1` | Exact retained raw-route source body symmetric with `PreviousPage`; no invented caller edge. |
| `DrawWrappedText(const wchar_t *text, int charCount, const RectBounds *bounds)` | [UID:0004JQ][0x0048d9e0-0x0048dc22.CollectionEntryControlPaneDrawWrappedText](by-memory/0x0048d9e0-0x0048dc22.CollectionEntryControlPaneDrawWrappedText.md) `0x0048d9e0-0x0048dc22` | Private `thiscall` helper called nine times by `OnDraw`. It wraps up to `charCount` UTF-16 characters inside the supplied rect, consumes literal `\\n` explicitly, skips one following space after a wrap, aligns each run using inherited text alignment at `this+0x8c`, draws through shared GrafPort text helpers, and restores the original draw cursor. The helper takes three explicit arguments and returns with `ret 0xc`. |
| destructor adjustors | [UID:0004JX][0x0048e14b-0x0048e18d.CollectionDialogControlDestructorAdjustorThunks](by-memory/0x0048e14b-0x0048e18d.CollectionDialogControlDestructorAdjustorThunks.md) `0x0048e14b-0x0048e18d` | Shared compiler-generated secondary/tertiary vtable adjustors; entry-control cells subtract `0xa0` or `0xa4` and tail-jump to the scalar deleting destructor. Do not hand-author these as source methods. |
| `ScalarDeletingDestructor` | [UID:0004K0][0x0048e2b0-0x0048e305.CollectionEntryControlPaneScalarDeletingDestructor](by-memory/0x0048e2b0-0x0048e305.CollectionEntryControlPaneScalarDeletingDestructor.md) `0x0048e2b0-0x0048e305` | MSVC scalar deleting destructor wrapper. The exact empty ordinary destructor [UID:00010Y][0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor](by-memory/0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor.md) is authored; the compiler regenerates this wrapper and adjustors. |

## Class Layout

| Offset | Field | Evidence / caveat |
| ---: | --- | --- |
| `+0x000..+0x107` | inherited `ControlPane` / base hierarchy state | Constructor calls the base control constructor with type `8`; vtable stores show primary plus inherited secondary/tertiary views. Keep the declaration as `public ControlPane` unless the parent class declaration later exposes additional base interfaces. |
| `+0x108` | `unsigned char m_groupIndex` | Written by the constructor from the first byte argument and reused by `OnDraw` to index `group * 0x2604`. |
| `+0x109` | `signed char m_entryIndex` | Written by the constructor from the second byte argument. `0xfe` is tested as the empty/unused slot sentinel and should be treated as signed `-2`, not as a boolean or generic byte. |
| `+0x10a` | `wchar_t m_volumeEpfName[128]` | Constructor formats `CLTVOL%d.EPF` here using the selected group's `groupType/volumeId` byte. |
| `+0x20a` | `wchar_t m_volumePaletteName[128]` | Constructor formats `CLTVOL%d.PAL` here using the same group byte. |
| `+0x30a..+0x30b` | tail padding | Allocation sites and the scalar deleting destructor's array-delete path establish object size `0x30c`. |

## Shared GrafPort/Text Dependencies

These routines are dependencies used by `OnDraw` and `DrawWrappedText`; they are not owned by this class and should not appear as `CollectionEntryControlPane` methods:

| Address | Dependency role |
| --- | --- |
| `0x004b95e0` | [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md), `GrafPort::GetDrawPosition`-style draw cursor accessor. |
| `0x004b9600` | Shared draw cursor set/move helper used before drawing wrapped runs. |
| `0x004b9620` | [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md), `GrafPort::OffsetDrawPosition`-style helper. |
| `0x004ba8b0` | Shared text-fit/count helper used to determine how many UTF-16 characters fit inside the rect width. |
| `0x004ba9a0` | [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md), shared text width/measure helper. |
| `0x004bab20` | [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md), `GrafPort::DrawGlyphWithTextColors`-style shared text output helper. |
| `0x004bab70` | Shared wide-text draw helper. |

## Destructor Family Notes

- `0x0048d480-0x0048d49f` (`00010Y`) is the ordinary/non-deleting destructor body. It restores the primary vtable view at `this+0x00` from `0x00616590`, the secondary view at `this+0xa0` from `0x006165f8`, and the tertiary view at `this+0xa4` from `0x00616628`, then tail-jumps to `Pane` non-deleting teardown at `0x00544580`. Live IDA and raw PE checks found no direct static inbound route to this ordinary body; the live vtable destructor route is through scalar deleting destructor `0x0048e2b0`.
- The primary vtable first slot at `0x00616590` points to scalar deleting destructor `0x0048e2b0`. The secondary first slot at `0x006165f8` points to adjustor `0x0048e177` (`this -= 0xa0; jmp 0x0048e2b0`), and the tertiary first slot at `0x00616628` points to adjustor `0x0048e182` (`this -= 0xa4; jmp 0x0048e2b0`). The scalar deleting destructor repeats the three `CollectionEntryControlPane` vtable restores, calls `Pane` teardown `0x00544580`, and conditionally frees storage through `0x004f4ac0`.
- Do not route this destructor family to `TextButtonExControlPane`: that class has a separate ordinary teardown range at `0x004955e0-0x00495615` and scalar deleting destructor at `0x0049b860`.
- The `0x0061658c-0x00616630` vtable group in [UID:000250][0x006164f0-0x006168d0.CollectionReadOnlyData](by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md) is declaration-generated data for this private entry-control class. The primary first slot is `CollectionEntryControlPane_ScalarDeletingDestructor` at `0x0048e2b0`; secondary/tertiary first slots route through `0x0048e177` and `0x0048e182` into the same scalar destructor.

## Data Layout

Reads [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) through the collection group/entry view documented in [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md):

- `+group * 0x2604 + 0x3ec9`: group type / volume number used by the constructor when formatting `CLTVOL%d` and `CLTICON%d` resource names.
- `+group * 0x2604 + 0x3eca`: total entry count used by `OnDraw` to suppress empty slots.
- Logical entry base: `groupBase + 0x04 + entry * 0x4c`, where `groupBase == g_pCollectionData + group * 0x2604 + 0x3ec8`.
- Entry `+0x00`: 24-byte `SimpleUString` loaded from `MetaMan` `Collections` column `2` and drawn as secondary item text; use descriptive `shortName` / `subtitleText` wording until the original column label is proven.
- Entry `+0x18`: 24-byte `SimpleUString` row name/key copied from `MetaMan`, used as the collection lookup key, and drawn first in the populated branch; use descriptive `entryName` / `lookupName` wording until the original field name is proven.
- Entry `+0x30`: 24-byte `SimpleUString` loaded from `MetaMan` `Collections` column `3` and drawn as the lower description/body text; `description` is the best current source-facing role.
- Entry `+0x48`: collected/unlocked state byte populated by `CollectionDialogPane` packet-bit decoding and checked before the populated-entry draw branch; `collectedFlag` / `unlockedFlag` are role-accurate, but the final original spelling remains unproven.

The decimal decompiler offsets behind these expressions were checked with `tools/int_convert.py`: `9732 == 0x2604`, `76 == 0x4c`, `16073 == 0x3ec9`, `16074 == 0x3eca`, `16076 == 0x3ecc`, `16100 == 0x3ee4`, `16124 == 0x3efc`, and `16148 == 0x3f14`.

## Source-Quality Decisions And Rejected Alternatives

- Keep [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md) as canonical owner/emitter. The direct constructor calls at `0x0048ca46` and `0x0048ce45`, collection-only resources, collection `.rdata` vtables, and dialog-private control usage outweigh the historical generated `class_CollectionEntryControlPane.cpp` filename. Preserve the possible `CollectionPane.cpp` feature-fold as a placement caveat only.
- Keep the class declaration in this page and method bodies in the exact by-memory children produced by the complete [UID:00010X][0x0048c640-0x0048e305.CollectionDialogControls](by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md) split. The declaration emits with `[[CHILDREN]]`; ordinary source children emit bodies, while adjustors and the scalar deleting wrapper remain compiler-only.
- Reject standalone GrafPort/text helper ownership. `0x004b95e0`, `0x004b9600`, `0x004b9620`, `0x004ba8b0`, `0x004ba9a0`, `0x004bab20`, and `0x004bab70` are shared helpers called by this class, not methods that belong in `CollectionDialogPane.cpp`.
- Reject [UID:0000P1][UserPane](by-file/UserPane.md) or [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) as direct UI class owner. They own the backing local-player state view consumed by this control, not the private control class itself.
- Reject `TextButtonExControlPane`, `Pane`, or raw `ControlPane` ownership for this destructor family. Those base classes provide inherited cleanup/state; the vtable and resource route remain `CollectionEntryControlPane`.
- Reject handwritten C++ for the scalar deleting destructor and adjustor thunks. A normal virtual destructor declaration is the source-facing construct; the compiler should regenerate scalar/delete wrappers and `this` adjustors from the class layout.

## Score Rationale

The page is `90/92` because the class declaration, owner/emitter route, exact child split, constructor signature, object size, class-local fields, vtable route, `OnDraw` branch/data flow, retained page methods, private `DrawWrappedText` signature, shared-helper dependency boundary, and destructor compiler policy are resolved with report-backed evidence. Residual uncertainty is limited to original private field spellings and the historical no-direct-route status of the two retained page methods; it does not require raw-offset or handwritten compiler-support source.

## Cross-References

- [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- [UID:00002V][CollectionDialogPane](by-class/CollectionDialogPane.md)
- [UID:00002U][CollectionBarControlPane](by-class/CollectionBarControlPane.md)
- [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md)
- [UID:00010Y][0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor](by-memory/0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor.md)
- [UID:0004JL][0x0048d3a0-0x0048d47b.CollectionEntryControlPaneConstructor](by-memory/0x0048d3a0-0x0048d47b.CollectionEntryControlPaneConstructor.md)
- [UID:0004JM][0x0048d4a0-0x0048d992.CollectionEntryControlPaneOnDraw](by-memory/0x0048d4a0-0x0048d992.CollectionEntryControlPaneOnDraw.md)
- [UID:0004JO][0x0048d9a0-0x0048d9b1.CollectionEntryControlPanePreviousPageRaw](by-memory/0x0048d9a0-0x0048d9b1.CollectionEntryControlPanePreviousPageRaw.md)
- [UID:0004JP][0x0048d9c0-0x0048d9d1.CollectionEntryControlPaneNextPageRaw](by-memory/0x0048d9c0-0x0048d9d1.CollectionEntryControlPaneNextPageRaw.md)
- [UID:0004JQ][0x0048d9e0-0x0048dc22.CollectionEntryControlPaneDrawWrappedText](by-memory/0x0048d9e0-0x0048dc22.CollectionEntryControlPaneDrawWrappedText.md)
- [UID:0004K0][0x0048e2b0-0x0048e305.CollectionEntryControlPaneScalarDeletingDestructor](by-memory/0x0048e2b0-0x0048e305.CollectionEntryControlPaneScalarDeletingDestructor.md)
- [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md)
- [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md)

## Changes

- What existed before: the page documented entry-slot draw states, methods, data offsets, and shared GrafPort helper caveats, but metadata still read `0/0`.
- What it was changed to: scores were set to `76/82`.
- Summary and evidence: constructor, destructor, draw/wrapped-text behavior, category record offsets, and shared helper dependencies are documented; confidence is capped by caller-biased helper ownership and unfinished field naming.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains blank because the class completion score is below the 80% attachment gate.
  - Evidence: live IDA MCP confirms modeled method starts at `0x0048d3a0`, `0x0048d480`, `0x0048d4a0`, `0x0048d9e0`, and `0x0048e2b0`, with construction from `CollectionDialogPane` at `0x0048ca46` and `0x0048ce45`.
- 2026-06-05: Raised from `76/82` to `80/84` and attached to [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md).
  - Evidence: live IDA MCP confirmed constructor/destructor/draw/wrapped-text/scalar-destructor starts, constructor xrefs from the dialog at `0x0048ca46` and `0x0048ce45`, the virtual draw table reference at `0x006165d4`, scalar-destructor thunk/table references, and nine draw-call sites into the wrapped-text helper.
  - Remaining limits: shared GrafPort helper ownership and final member-field names are still not exhaustive, so this page only reaches the attachment gate rather than final-source readiness.
- 2026-06-13: Raised from `80/84` to `85/86` after correcting the entry-record layout against the collection data producer and dialog packet consumer.
  - Evidence: live IDA MCP session `a001_goal2_0002UM` confirmed `0x0048d3a0` stores group/entry indices and formats resources from `+0x3ec9`; `0x0048d4a0` checks total entries at `+0x3eca`, checks the entry-local state byte at `+0x48`, and renders entry-local strings at `+0x18/+0x00/+0x30`; `0x0048c640` writes packet bits to absolute `+0x3f14 + entry * 0x4c`; and `tools/int_convert.py` verified the cited decimal/hex offset pairs.
- 2026-06-16 destructor-family source-quality update:
  - Evidence: B001 reanalysis confirmed ordinary destructor `0x0048d480` has no direct static inbound route by IDA xrefs or raw PE VA/RVA/rel32 scans, while vtable destruction routes through scalar deleting destructor `0x0048e2b0` and adjustors `0x0048e177/0x0048e182`. The tail target is shared `Pane` teardown `0x00544580`, not `TextButtonExControlPane` teardown.
- 2026-06-20 B001 Rule 26 read-only-data incorporation:
  - Summary/evidence: clarified that the [UID:000250][0x006164f0-0x006168d0.CollectionReadOnlyData](by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md) entry-control vtable group is generated from this private class declaration; source reconstruction should document the scalar destructor/adjustor route and emit no hand-authored RTTI/vtable arrays.
- 2026-06-21 B010 Rule 26 class source-quality incorporation:
  - Before: `85/86`, blank formal C++, shared GrafPort helpers still appeared in the method table as caller-biased possible class methods, and final class-local field/helper names remained open.
  - After: `88/90`, with declaration-level first-draft C++, `CollectionEntryControlPane(unsigned char groupIndex, signed char entryIndex, const RectBounds *bounds)`, `virtual ~CollectionEntryControlPane()`, `OnDraw()`, private `DrawWrappedText(const wchar_t *, int, const RectBounds *)`, class-local fields at `+0x108/+0x109/+0x10a/+0x20a`, object size `0x30c`, and shared GrafPort/text helpers moved to dependency status.
  - Evidence: B010 local PE/Capstone reanalysis of constructor, draw, wrapped-text, adjustor, scalar destructor, constructor callers, and vtable cells confirms the stack signature, vtable slots, empty sentinel `0xfe`, `CLTVOL` cache buffers, `OnDraw` branch/data flow, `DrawWrappedText` wrapping/alignment behavior, and compiler-generated destructor policy.
- 2026-07-13 B004 UID00010X split callback: raised from `88/90` to `90/92` while preserving the complete existing declaration and adding only `NextPage()` and `PreviousPage()`.
  - Exact child closure: constructor [UID:0004JL][0x0048d3a0-0x0048d47b.CollectionEntryControlPaneConstructor](by-memory/0x0048d3a0-0x0048d47b.CollectionEntryControlPaneConstructor.md), empty ordinary destructor [UID:00010Y][0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor](by-memory/0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor.md), `OnDraw` [UID:0004JM][0x0048d4a0-0x0048d992.CollectionEntryControlPaneOnDraw](by-memory/0x0048d4a0-0x0048d992.CollectionEntryControlPaneOnDraw.md), retained raw page methods [UID:0004JO][0x0048d9a0-0x0048d9b1.CollectionEntryControlPanePreviousPageRaw](by-memory/0x0048d9a0-0x0048d9b1.CollectionEntryControlPanePreviousPageRaw.md)/[UID:0004JP][0x0048d9c0-0x0048d9d1.CollectionEntryControlPaneNextPageRaw](by-memory/0x0048d9c0-0x0048d9d1.CollectionEntryControlPaneNextPageRaw.md), wrapped-text helper [UID:0004JQ][0x0048d9e0-0x0048dc22.CollectionEntryControlPaneDrawWrappedText](by-memory/0x0048d9e0-0x0048dc22.CollectionEntryControlPaneDrawWrappedText.md), adjustors [UID:0004JX][0x0048e14b-0x0048e18d.CollectionDialogControlDestructorAdjustorThunks](by-memory/0x0048e14b-0x0048e18d.CollectionDialogControlDestructorAdjustorThunks.md), and compiler scalar wrapper [UID:0004K0][0x0048e2b0-0x0048e305.CollectionEntryControlPaneScalarDeletingDestructor](by-memory/0x0048e2b0-0x0048e305.CollectionEntryControlPaneScalarDeletingDestructor.md).
  - Preserved evidence: field layout, typed entry data, explicit-newline consumption, no-route history, GrafPort dependency boundary, vtable cells, destructor behavior, source owner/emitter, and all rejected ownership/helper alternatives.
