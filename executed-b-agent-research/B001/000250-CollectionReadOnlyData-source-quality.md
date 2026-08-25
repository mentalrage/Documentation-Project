** TARGET-REPORT-UID:000250 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000250 CollectionReadOnlyData Source-Quality Research

Assignment: `B001-000250-CollectionReadOnlyData-source-quality`  
Agent: `Agent-B001`  
Target: `[UID:000250] source-3/project-documentation/by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md`  
Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/000250-CollectionReadOnlyData-source-quality.md`  
Current target score: `84/90`

## Final Recommendation

Raise the target to `88/91`, keep `RECONSTRUCTABLE:TRUE`, keep `CANONICAL_OWNER:0000IB`, keep `EMITTER_UIDS:0000IB`, and keep the source placement through `NexusTK/ui/dialogs/CollectionDialogPane.cpp`.

This range should not emit hand-authored RTTI or vtable cells. Those bytes are compiler-generated from the source declarations for `CollectionDialogPane`, `CollectionEntryControlPane`, and `CollectionBarControlPane`. It should, however, stop being treated as a blank code-emitting page: the string half of the range is source-level data and can be represented as file-local wide string constants in `CollectionDialogPane.cpp`.

Recommended target C++ direction:

```cpp
namespace {

static const wchar_t kCollectionDialogPaneName[] = L"Collection Dialog Pane";
static const wchar_t kCollectionDialogPaletteName[] = L"DLGCLT.PAL";
static const wchar_t kCollectionDialogEpfName[] = L"DLGCLT.EPF";
static const wchar_t kCollectionNamePaletteName[] = L"CLTNAME.PAL";
static const wchar_t kCollectionNameEpfName[] = L"CLTNAME.EPF";
static const wchar_t kCollectionVolumeEpfFormat[] = L"CLTVOL%d.EPF";
static const wchar_t kCollectionVolumePaletteFormat[] = L"CLTVOL%d.PAL";
static const wchar_t kCollectionEntryNumberFormat[] = L"%2d";
static const wchar_t kCollectionEntryEpfName[] = L"CLTENTRY.EPF";
static const wchar_t kCollectionEntryPaletteName[] = L"CLTENTRY.PAL";
static const wchar_t kCollectionIconEpfName[] = L"CLTICON.EPF";
static const wchar_t kCollectionIconPaletteName[] = L"CLTICON.PAL";
static const wchar_t kCollectionNumericFontName[] = L"9X11FONT.BIN";
static const wchar_t kCollectionBarEpfName[] = L"CLTBAR.EPF";
static const wchar_t kCollectionBarPaletteName[] = L"CLTBAR.PAL";
static const wchar_t kCollectionProgressTextFormat[] = L"%d/%d (%d%%)";
static const wchar_t kCollectionSymbolFontEpfName[] = L"FONTSYMB.EPF";
static const wchar_t kCollectionSymbolFontPaletteName[] = L"FONTSYMB.PAL";

} // namespace
```

Do not add source declarations for `??_R4*`, `??_7*`, complete-object locators, or vtable arrays to the target C++ block. Those are generated-binary output from the class declarations.

## Report-Only Compliance

No target, support, source, generated, IDA DB, or coverage files were edited. This report is the only intended changed file for this assignment.

Current IDA MCP probe:

```text
IDA_MCP_UNAVAILABLE: Unable to connect to the remote server
```

Because live IDA was unavailable for this turn, the recommendations below use the existing live-IDA-backed docs and previous B001 executed report evidence. I did not create or edit target/support docs, and I did not edit `by-memory/-coverage-report.md`.

## Evidence Checked

Primary target and coverage:

- `by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md`
- `by-memory/-coverage-report.md` current `000250` row
- `auto-generated/-ag-memory-coverage.md` route showing this UID emits through `0000IB` to `auto-generated/NexusTK/ui/dialogs/CollectionDialogPane.cpp`

Direct owner/support docs:

- `by-file/CollectionDialogPane.md`
- `by-class/CollectionDialogPane.md`
- `by-class/CollectionEntryControlPane.md`
- `by-class/CollectionBarControlPane.md`
- `by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md`
- `by-memory/0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor.md`
- `by-memory/0x0048e140-0x0048e14b.ClearCollectionDialogPaneSingleton.md`
- `by-global/g_pCollectionDialogPane.md`
- `tools/leaser/Agents/Agent-B001/research/executed/00010Y-collection-entry-control-pane-destructor-source-quality.md`

Collection interaction/support docs:

- `by-file/CollectionPane.md`
- `by-class/CollectionPane.md`
- `by-memory/0x0056e940-0x0056fe75.CollectionPane.md`
- `by-memory/0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail.md`
- `by-global/g_pCollectionData.md`
- `by-type/by-struct/CollectionPlayerDataLayout.md`
- `by-resource/collection-ui-resources.md`

Boundary and shared-slot docs:

- `by-memory/0x006163dc-0x006164f0.ClanResourceStringData.md`
- `by-memory/0x006168d0-0x00617a38.ConfigChannelReadOnlyData.md`
- `by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md`
- `by-class/LObject.md`
- `by-class/GrafPort.md`
- `by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md`
- `by-memory/0x00544460-0x00545086.PaneCore.md`
- `by-type/by-vtable/PanelPaneVtables.md`
- `by-type/by-vtable/AlertPaneVtables.md`
- `by-type/by-vtable/DescPaneVtables.md`

Conversions checked with `tools/int_convert.py`:

- `0x3e0` / 992-byte target span
- `0x270` / 624-byte collection-dialog allocation
- `0xa0` / 160 and `0xa4` / 164 vtable-adjustor offsets
- `0x108` / 264 and `0x109` / 265 entry-control local index offsets
- `0x2604` / 9732 group stride
- `0x4c` / 76 entry stride
- `0x3ec8` / 16072 loaded flag
- `0x3ec9` / 16073 group type/volume byte
- `0x3eca` / 16074 total entry count
- `0x3ecb` / 16075 collected entry count
- `0x48` / 72 entry state byte
- `0x18` / 24 and `0x30` / 48 entry-string offsets
- `0x5f` / 95 dialog scalar destructor size from support docs
- `0xb4` / 180 bar scalar destructor size from support docs
- `0x55` / 85 entry scalar destructor size from support docs

## Boundary, Split, And Ownership

The current target range is correct:

- It starts at `0x006164f0`, the `CollectionDialogPane` RTTI/complete-object-locator pointer that was previously miscounted with the clan resource-string tail.
- The predecessor `0x006163dc-0x006164f0.ClanResourceStringData` ends with the clan `%s (%d)` wide string terminator before `0x006164f0`.
- The target ends at `0x006168d0`, where the successor `Config` vtable begins.
- The range size is `0x3e0` / 992 bytes, verified with `int_convert.py`.

No required split is recommended before implementation. A future precision pass could split the target into exact children if the supervisor wants per-class vtable pages:

```text
0x006164f0-0x0061658c  CollectionDialogPaneVtableData
0x0061658c-0x00616630  CollectionEntryControlPaneVtableData
0x00616630-0x006166d4  CollectionBarControlPaneVtableData
0x006166d4-0x006168d0  CollectionDialogResourceStringData
```

That split is optional because all four subranges route to the same source file and the current target is compact, fully bounded, and already owner/emitter-valid. Do not merge the range into the predecessor clan data or successor Config data.

Keep direct owner/emitter `[UID:0000IB] CollectionDialogPane`. `CollectionPane.cpp` owns the main five-row collection summary panel and the `OpenOrRequestGroupDetail` helper; it does not own the private dialog/control `.rdata` island. `CollectionPane::OpenOrRequestGroupDetail` allocates `0x270` / 624 bytes and calls the `CollectionDialogPane` constructor only after checking group data and the singleton. That is caller evidence, not data ownership.

Best source placement remains:

```text
NexusTK/ui/dialogs/CollectionDialogPane.cpp
```

Rejected placement alternatives:

- Reject `CollectionPane.cpp` as direct owner: it is the caller/request route, while this data is the detail dialog and private child-control class data.
- Reject `Pane.cpp`, `ControlPane.cpp`, `DialogPane.cpp`, or `TextButtonExControlPane.cpp` as direct owners: they explain inherited slots and cleanup helpers, but the class-specific RTTI names and resource literals are collection-dialog-private.
- Reject `RECONSTRUCTABLE:FALSE`: even though the vtable/RTTI cells are generated by MSVC, the owning declarations and the wide resource strings are source-level reconstruction inputs.

## Vtable, RTTI, And Slot Findings

The target contains nine MSVC vtable views:

| Class | Views | Primary base | Source handling |
| --- | --- | --- | --- |
| `CollectionDialogPane` | primary/secondary/tertiary | `0x006164f4` | Generate from the `CollectionDialogPane` declaration; first primary slot is `CollectionDialogPane_ScalarDeletingDestructor` at `0x0048e250`. |
| `CollectionEntryControlPane` | primary/secondary/tertiary | `0x00616590` | Generate from the private entry-control declaration; first primary slot is `0x0048e2b0`, and the secondary/tertiary first slots route through `0x0048e177`/`0x0048e182`. |
| `CollectionBarControlPane` | primary/secondary/tertiary | `0x00616634` | Generate from the private bar-control declaration; first primary slot is `CollectionBarControlPane` scalar deleting destructor at `0x0048e190`. |

Raw/shared slot names should be replaced by source-facing descriptions in the target text:

| Current raw name | Best source-quality direction | Evidence |
| --- | --- | --- |
| `sub_48E250` | `CollectionDialogPane_ScalarDeletingDestructor` | C001 IDA DB names and class doc already use this name. |
| `sub_48E2B0` | `CollectionEntryControlPane_ScalarDeletingDestructor` | B001 `00010Y` report proved primary vtable route `0x00616590 -> 0x0048e2b0`. |
| `sub_48E190` | `CollectionBarControlPane_ScalarDeletingDestructor` | Bar class doc records `0x0048e190-0x0048e243` as scalar deleting destructor and constructor/destructor/scalar paths sharing `0x00616634/0x0061669c/0x006166cc`. |
| `sub_4F4B10` | inherited `LObject` runtime-class accessor | `LObject` docs identify `0x004f4b10-0x004f4b16` as the runtime-class accessor returning the `LObject` record. |
| `nullsub_18` | inherited `LObject::VirtualNoop(int, int)` / default no-op virtual | `0x0041b6c0-0x0041b6c3` page accepts descriptive `LObject::VirtualNoop(int, int)`. |
| `sub_4B8E20` | inherited `GrafPort`/pane render-region update support | `GrafPort` class and related vtable docs identify `0x004b8e20` as `GrafPort::UpdateRenderRegion`/render-region support. |
| `nullsub_19` | inherited/default pane draw-style no-op slot | `PaneCore`, `PanelPaneVtables`, and related vtable pages identify `0x0041d680-0x0041d682` as the inherited/default no-op draw-style slot. |
| `sub_49F2E0` | inherited `DialogPane` border/tile/background drawing virtual | `AlertPaneVtables` and `BulletinDialogVtables` describe `0x0049f2e0` as inherited dialog border/tile drawing. |
| `nullsub_26` | `CollectionDialogPane` no-op virtual at `0x0048d180-0x0048d182` | The class page documents this disabled/no-op virtual; old report notes identify it as `CollectionDialogPane::virt_meth_0x48d180` / IDA `nullsub_26`. |

High-probability adjustor-thunk mapping:

| Thunk | Likely route | Confidence |
| --- | --- | --- |
| `0x0048e14b` | `CollectionBarControlPane` secondary destructor adjustor into `0x0048e190` | Medium-high; class docs bound `0x0048e14b-0x0048e160` as bar adjustors, but live slot dump was unavailable this turn. |
| `0x0048e156` | `CollectionBarControlPane` tertiary destructor adjustor into `0x0048e190` | Medium-high; same evidence/caveat as above. |
| `0x0048e161` | `CollectionDialogPane` secondary destructor adjustor into `0x0048e250` | Medium-high; class docs bound `0x0048e161-0x0048e176` as dialog adjustors, but live slot dump was unavailable this turn. |
| `0x0048e16c` | `CollectionDialogPane` tertiary destructor adjustor into `0x0048e250` | Medium-high; same evidence/caveat as above. |
| `0x0048e177` | `CollectionEntryControlPane` secondary destructor adjustor into `0x0048e2b0` | Very strong; B001 `00010Y` report and target doc both record `0x006165f8 -> 0x0048e177 -> 0x0048e2b0`. |
| `0x0048e182` | `CollectionEntryControlPane` tertiary destructor adjustor into `0x0048e2b0` | Very strong; B001 `00010Y` report and target doc both record `0x00616628 -> 0x0048e182 -> 0x0048e2b0`. |

Do not finalize a complete slot-by-slot table above `88` completion until a live IDA vtable dword dump can refresh all three classes. The remaining unknown is not whether the slots are collection-owned; it is exact inherited-source spelling for every base slot. The currently explainable raw labels should no longer appear as unexplained blockers.

## Class Declaration Direction

`CollectionDialogPane`:

- Source-declared detail dialog class.
- Dialog-family base; exact inheritance spelling should stay in the class/file docs until a full class-layout pass confirms it.
- Source responsibilities: singleton guard, group lookup, packet-bit entry-state writes, child bar/entry construction, pagination, button handling, and modeless dialog lifecycle.
- Vtable/RTTI in this target regenerates from the class declaration; do not hand-author data symbols.

`CollectionEntryControlPane`:

- Private control class in or near `CollectionDialogPane.cpp`.
- Constructor stores group index at `+0x108` / 264 and entry index at `+0x109` / 265.
- Uses `g_pCollectionData` group stride `0x2604` / 9732 and entry stride `0x4c` / 76.
- Reads entry string fields at `+0x00`, `+0x18` / 24, and `+0x30` / 48, and entry state at `+0x48` / 72.
- Destructor family should remain class-owned: ordinary body `0x0048d480`, scalar deleting destructor `0x0048e2b0`, and adjustors `0x0048e177/0x0048e182`.
- Do not route the entry ordinary/scalar destructor family to `TextButtonExControlPane`; B001 `00010Y` proves the tail cleanup target is shared `Pane` teardown at `0x00544580`.

`CollectionBarControlPane`:

- Private progress-bar control in or near `CollectionDialogPane.cpp`.
- Reads total/collected counts from `g_pCollectionData` group header bytes `+0x3eca` / 16074 and `+0x3ecb` / 16075.
- Loads `9X11FONT.BIN`, draws `CLTBAR`, and uses `FONTSYMB` sprites for punctuation in `%d/%d (%d%%)`.
- Current class doc says `g_collectionProgressTable`; support docs should replace that with a local typed view over `g_pCollectionData` rather than a separate global.

Exact base-class spelling for the private controls is still a class-layout task, not a target blocker. The target can be brought to source-quality as read-only data with constants and vtable-generation notes while class layout remains in the class pages.

## Resource/String Constant Naming

Recommended source-facing constant names for the target strings:

| Address | Literal | Recommended constant |
| --- | --- | --- |
| `0x006166d4` | `Collection Dialog Pane` | `kCollectionDialogPaneName` |
| `0x00616704` | `DLGCLT.PAL` | `kCollectionDialogPaletteName` |
| `0x0061671c` | `DLGCLT.EPF` | `kCollectionDialogEpfName` |
| `0x00616734` | `CLTNAME.PAL` | `kCollectionNamePaletteName` |
| `0x0061674c` | `CLTNAME.EPF` | `kCollectionNameEpfName` |
| `0x00616764` | `CLTVOL%d.EPF` | `kCollectionVolumeEpfFormat` |
| `0x00616780` | `CLTVOL%d.PAL` | `kCollectionVolumePaletteFormat` |
| `0x006167bc` | `%2d` | `kCollectionEntryNumberFormat` |
| `0x006167c4` | `CLTENTRY.EPF` | `kCollectionEntryEpfName` |
| `0x006167e0` | `CLTENTRY.PAL` | `kCollectionEntryPaletteName` |
| `0x006167fc` | `CLTICON.EPF` | `kCollectionIconEpfName` |
| `0x00616814` | `CLTICON.PAL` | `kCollectionIconPaletteName` |
| `0x0061682c` | `9X11FONT.BIN` | `kCollectionNumericFontName` |
| `0x00616848` | `CLTBAR.EPF` | `kCollectionBarEpfName` |
| `0x00616860` | `CLTBAR.PAL` | `kCollectionBarPaletteName` |
| `0x00616878` | `%d/%d (%d%%)` | `kCollectionProgressTextFormat` |
| `0x00616894` | `FONTSYMB.EPF` | `kCollectionSymbolFontEpfName` |
| `0x006168b0` | `FONTSYMB.PAL` | `kCollectionSymbolFontPaletteName` |

The constants are local source names, not proof of original identifier spellings. They are useful because the target already emits through `CollectionDialogPane.cpp`, and the string cluster is source-declared behavior. The actual EPF/PAL/BIN payloads remain resource-derived.

Shared-resource caveat:

- `9X11FONT.BIN` and `FONTSYMB.*` are shared UI font/symbol dependencies with collection call sites. Keeping local string constants in this file is fine; claiming collection-private ownership of the resource payloads is not.

## Generated-Binary Versus Source-Declared Handling

Target-specific generated/no-code proof:

- The `??_R4*` RTTI locator dwords and `??_7*` vtable labels are MSVC-generated binary data.
- The nine vtable views must be reproduced by compiling the owning class declarations and virtual methods.
- Hand-emitting vtable arrays or RTTI symbols in C++ would be wrong source reconstruction.

Target-specific source-declared proof:

- The `0x006166d4-0x006168d0` string cluster is a set of source-level wide string literals/constants used by the dialog/control code.
- These names are not resource payloads; they are source constants passed into image/font/resource loaders.
- The target has a valid owner/emitter and clears the current score gate once this source-quality report is incorporated.

Therefore the recommended C++ is not a no-op and not raw data. It is only the source-level constants. Vtables/RTTI remain declaration-generated.

## Recommended Target Doc Changes

Metadata:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:0000IB
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000IB
```

Replace the current summary statement that says no final C++ is emitted from this aggregate page with:

```text
The exact RTTI and vtable bytes are compiler-emitted data, but the owning class declarations and the wide resource/string constants are source-level reconstruction inputs for CollectionDialogPane.cpp. Final C++ for this UID should emit only the file-local wide resource constants; do not hand-author MSVC RTTI, complete-object-locator, or vtable arrays.
```

Add a source-quality slot note under "Vtable And RTTI Inventory":

```text
The raw inherited slot labels are not collection-local helpers. `0x004f4b10` is the inherited LObject runtime-class accessor, `0x0041b6c0` / `nullsub_18` is the inherited LObject default no-op virtual, `0x004b8e20` is inherited GrafPort/pane render-region support, `0x0041d680` / `nullsub_19` is an inherited/default pane draw-style no-op slot, and `0x0049f2e0` is an inherited DialogPane border/tile drawing virtual. Keep collection-specific renames on the first-slot scalar destructors and private draw/paint methods, not on these inherited base slots.
```

Replace the `CollectionBarControlPane` vtable row's raw first-slot wording with:

```text
The primary vtable base is `0x00616634`; its first slot points to `0x0048e190`, the `CollectionBarControlPane` scalar deleting destructor. Constructor `0x0048dc30`, destructor body `0x0048dce0`, and scalar deleting destructor `0x0048e190` all share the three bar-control vtable views `0x00616634`, `0x0061669c`, and `0x006166cc`.
```

Add a caveated adjustor note:

```text
The target's current docs prove the entry-control first-slot adjustor route. Existing class docs also bound bar adjustors at `0x0048e14b/0x0048e156` and dialog adjustors at `0x0048e161/0x0048e16c`; a live vtable slot dump should confirm those exact secondary/tertiary first slots before the target claims them with final confidence.
```

Replace the stale rebuild note "Keep C++ blank until final source declarations and member names reach the 95/95 final-source gate" with:

```text
Current code-entry policy is satisfied after this source-quality pass. Emit source-level file-local constants for the 18 wide strings, but leave MSVC RTTI/vtable cells to be regenerated from the CollectionDialogPane, CollectionEntryControlPane, and CollectionBarControlPane declarations.
```

Add the first-draft C++ constants shown in the final recommendation.

## Recommended Support-Doc Changes

`by-file/CollectionDialogPane.md`:

```text
- [UID:000250] should emit only source-level wide string constants for the collection detail dialog resources. Its `CollectionDialogPane`, `CollectionEntryControlPane`, and `CollectionBarControlPane` RTTI/vtables are compiler-generated from the private dialog/control declarations and must not be hand-authored as raw data.
```

`by-class/CollectionDialogPane.md`:

```text
- The `0x006164f0-0x0061658c` vtable group is declaration-generated data for this class. The first primary slot is `CollectionDialogPane_ScalarDeletingDestructor` at `0x0048e250`; inherited base slots should be described through LObject/Pane/DialogPane docs rather than as collection-local raw `sub_*` helpers.
```

`by-class/CollectionEntryControlPane.md`:

```text
- The `0x0061658c-0x00616630` vtable group is declaration-generated data for this private entry-control class. The primary first slot is `CollectionEntryControlPane_ScalarDeletingDestructor` at `0x0048e2b0`; secondary/tertiary first slots route through `0x0048e177` and `0x0048e182` into the same scalar destructor.
```

`by-class/CollectionBarControlPane.md`:

```text
- The `0x00616630-0x006166d4` vtable group is declaration-generated data for this private progress-bar class. The primary first slot is `CollectionBarControlPane_ScalarDeletingDestructor` at `0x0048e190`; constructor/destructor/scalar-delete paths share vtable views `0x00616634`, `0x0061669c`, and `0x006166cc`.
- Replace the `g_collectionProgressTable` wording with a typed local view over `g_pCollectionData`; no separate collection-progress global is proven.
```

`by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md`:

```text
- `0x0048e190-0x0048e243` should be named `CollectionBarControlPane_ScalarDeletingDestructor`; `0x0048e2b0-0x0048e304` should be named `CollectionEntryControlPane_ScalarDeletingDestructor`. The adjustor thunk cluster remains compiler-generated glue, not feature behavior.
```

`by-resource/collection-ui-resources.md`:

```text
- [UID:000250] emits file-local wide constants for dialog/control resource names in `CollectionDialogPane.cpp`; resource payload ownership remains as documented here. `9X11FONT.BIN` and `FONTSYMB.*` stay shared UI font/symbol resources with collection call sites, not collection-private payloads.
```

No support-doc update is required for `g_pCollectionData` unless the supervisor wants to remove alias ambiguity; the existing page already says `g_collectionProgressTable` is a view alias over `dword_67A748`.

## IDA Rename, Type, And Comment Recommendations

No IDA DB edits were made because current MCP was unavailable. Recommended future edits:

| Address / item | Recommendation | Confidence |
| --- | --- | --- |
| `0x0048e190` | Rename to `CollectionBarControlPane_ScalarDeletingDestructor` if still raw. | High |
| `0x0048dce0` | Rename to `CollectionBarControlPane_Destructor` or `CollectionBarControlPane_NonDeletingDestructor` if still raw. | High |
| `0x0048e2b0` | Rename to `CollectionEntryControlPane_ScalarDeletingDestructor` if still raw. | Very high |
| `0x0048e14b` | Rename/comment as `CollectionBarControlPane_SecondaryDeletingDestructorAdjustor`. | Medium-high pending live slot confirmation |
| `0x0048e156` | Rename/comment as `CollectionBarControlPane_TertiaryDeletingDestructorAdjustor`. | Medium-high pending live slot confirmation |
| `0x0048e161` | Rename/comment as `CollectionDialogPane_SecondaryDeletingDestructorAdjustor`. | Medium-high pending live slot confirmation |
| `0x0048e16c` | Rename/comment as `CollectionDialogPane_TertiaryDeletingDestructorAdjustor`. | Medium-high pending live slot confirmation |
| `0x0048e177` | Rename/comment as `CollectionEntryControlPane_SecondaryDeletingDestructorAdjustor`. | Very high |
| `0x0048e182` | Rename/comment as `CollectionEntryControlPane_TertiaryDeletingDestructorAdjustor`. | Very high |
| `0x006164f0` | Add comment: `CollectionDialogPane complete-object-locator pointer; corrected start of collection .rdata island.` | High |
| `0x006166d4-0x006168d0` strings | Add constants/comments using the names in this report. | High |
| `0x0061682c`, `0x00616894`, `0x006168b0` | Comment as shared font/symbol resource names consumed by collection controls, not private payload ownership. | High |
| `CollectionEntryControlPane +0x108/+0x109` | Field comments `m_groupIndex` and `m_entryIndex`. | High |
| `g_pCollectionData` collection view | Prefer `CollectionGroupRecord` / `CollectionEntryRecord` typed-view comments over a new `g_collectionProgressTable` global. | High |

Do not rename inherited base slots such as `0x004f4b10`, `0x0041b6c0`, `0x004b8e20`, `0x0041d680`, or `0x0049f2e0` as collection-local methods.

## Open Questions And Attempted Resolution

1. Exact original source file: `CollectionDialogPane.cpp` versus a folded `CollectionPane.cpp`.
   - Checked `CollectionPane` file/class/open-helper docs and `CollectionDialogPane` file/class docs.
   - Best answer: keep `CollectionDialogPane.cpp`. `CollectionPane` is a caller/requester, while this target is dialog/control-local data.

2. Exact full vtable slot table for all nine views.
   - Checked target docs, class docs, previous `00010Y` report, and shared LObject/Pane/GrafPort/DialogPane slot docs.
   - Best answer: inherited raw labels can be explained now; a live IDA dword dump is still needed before claiming every secondary/tertiary first-slot and every inherited slot with final audit confidence.

3. Whether this should remain no-code.
   - Checked active autogen route and target disposition.
   - Best answer: no-code is correct for RTTI/vtable bytes only. The string constants are source-level and should be emitted as file-local constants.

4. Whether `9X11FONT.BIN` and `FONTSYMB.*` are collection-owned.
   - Checked `collection-ui-resources.md`.
   - Best answer: they are shared UI dependencies with collection call sites. Do not claim payload ownership here.

5. Whether `g_collectionProgressTable` is a real global.
   - Checked `g_pCollectionData.md`, `CollectionBarControlPane.md`, and `CollectionPlayerDataLayout.md`.
   - Best answer: no separate global is proven. Use a typed local view over `g_pCollectionData`.

6. Exact private-control base classes.
   - Checked constructor/destructor/control docs. Evidence supports dialog/control-family declarations and vtable offsets, but exact source inheritance spelling still belongs in a later class-layout pass.
   - Best answer: not a blocker for this target; vtables regenerate from class declarations, and this target can emit constants without final base-class spelling.

## Exact Coverage-Report Replacement Row

Do not edit `by-memory/-coverage-report.md` in this B-agent report. If the supervisor accepts the implementation, replace the current `000250` row with:

```text
    - [UID:000250][0x006164f0-0x006168d0.CollectionReadOnlyData](by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md) 0x006164f0-0x006168d0 | vtable/string-data | CollectionReadOnlyData : reconstructable : 88% : strong : B001 source-quality pass confirms the exact 0x3e0 / 992-byte CollectionDialogPane read-only island, corrected RTTI start, owner/emitter 0000IB, no required split, compiler-generated CollectionDialogPane/Entry/Bar RTTI/vtables regenerated from class declarations, inherited LObject/Pane/GrafPort/DialogPane slot meanings for stale raw labels, entry/bar/dialog destructor and adjustor routes, source-level wide constants for DLGCLT/CLTNAME/CLTVOL/CLTENTRY/CLTICON/CLTBAR/progress/font resource names, shared font/symbol non-ownership, and first-draft C++ limited to file-local constants rather than hand-authored vtables.
```

## Validation Commands Needed

After implementation edits, run from `E:\NTK\GhidraBridge`:

> Executable block R001 was removed from this report and preserved verbatim in [000250-CollectionReadOnlyData-source-quality-removed.md](000250-CollectionReadOnlyData-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If live IDA is available during implementation review, additionally request a dword slot dump for:

```text
0x006164f0-0x0061658c
0x0061658c-0x00616630
0x00616630-0x006166d4
```

Use that only to confirm the secondary/tertiary first-slot adjustor mappings and complete inherited slot labels; it should not change the owner/emitter or string-constant recommendation unless the dump contradicts current docs.

## Implementation Readiness

Ready for supervisor implementation callback.

Recommended implementation scope:

- Update target score to `88/91`.
- Add source-quality slot explanations and adjustor caveats.
- Add the first-draft C++ constants block.
- Update support docs only where listed above.
- Update the coverage row only after supervisor approval.

Do not:

- hand-author vtables/RTTI,
- split the target unless the supervisor explicitly asks for exact child pages,
- move owner/emitter away from `0000IB`,
- introduce a separate `g_collectionProgressTable` global,
- claim shared `9X11FONT.BIN` or `FONTSYMB.*` payload ownership.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/000250-CollectionReadOnlyData-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"000250"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000250-CollectionReadOnlyData-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/000250-CollectionReadOnlyData-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000250"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
