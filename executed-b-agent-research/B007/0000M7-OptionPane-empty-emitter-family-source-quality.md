** TARGET-REPORT-UID:0000M7 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0000M7] OptionPane Empty-Emitter Family Source-Quality Report

Agent: Agent-B007  
Assignment: `B007-report-0000M7-OptionPane-empty-emitter-family-20260630`  
Mode: report accepted and implemented in callback. Target/support by-* docs were edited under short leases and validators; original research evidence is preserved below.

## Finalized Report / Current Recommendation

Current recommendation: accept [UID:0000M7] `by-file/OptionPane.md` as the correct source root for the old `OptionPane`, new `NewOptionPane`, and file-level option helper family, but clear the 15 generated empty emitters with exact per-page dispositions instead of leaving blank formal C++ blocks.

Final disposition:

- Class/aggregate pages [UID:00009V], [UID:000097], and [UID:0001DW] should emit explicit `[[CHILDREN]]` markers.
- Modeled, routed helper bodies [UID:0003NN], [UID:0001DY], [UID:0003NS], [UID:0001DZ], [UID:0001E0], and source data [UID:0002ZC] are ready for exact first-draft formal C++.
- Raw no-route helper bodies [UID:0003NP], [UID:0003NQ], and [UID:0003NR] should not stay visually blank; insert exact formal no-code comments preserving the current no-route proof.
- Alias/index/generated-data pages [UID:0000TL] and [UID:00035B] should stop emitting; mark them non-reconstructable/non-emitting rather than generating empty markers.
- [UID:00027W] remains reconstructable source-shaped data but should receive a formal no-code marker, not a forced declaration, because no table reader or setter route is proven.

Confidence: high for owner/source placement and current IDA facts; medium-high for first-draft helper names because no original source symbols prove exact spellings.

## Target

- Target UID: [UID:0000M7]
- Target path: `by-file/OptionPane.md`
- Queue row: `auto-generated/-ag-research-tracker.md` -> `## Files With Empty Emitters`, row `OptionPane`, `Total Emitters: 19`, `Filled: 4`, `Marked Empty: 15`, `Complete: 21.1%`.
- Generated file checked: `auto-generated/NexusTK/ui/dialogs/OptionPane.cpp`, header `validator-command-id: 000000002826`, refreshed `2026-06-30T14:15:47-04:00`.
- Current target metadata: `COMPLETION:91`, `CONFIDENCE:85`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`.

## Current Target State

Current generated `OptionPane.cpp` already emits four filled bodies:

- [UID:0001DP] `OptionPane::OnServerOptionResponse`
- [UID:00040K] `OptionPane::ApplyServerOptionAvailability`
- [UID:0001DQ] old local `OptionPaneSendOptionPacket11B`
- [UID:0003NO] new local `NewOptionPaneSendOptionPacket11BSubcommand63`

The 15 current empty markers are:

| UID | Path / item | Current marker cause | Recommended disposition |
| --- | --- | --- | --- |
| 000097 | `by-class/NewOptionPane.md` | class marker blank | Insert `[[CHILDREN]]`; score to `87/89`. |
| 0001DW | `by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md` | broad class aggregate blank | Insert `[[CHILDREN]]`; keep as aggregate plus exact child split plan; score to `87/88`. |
| 0003NN | `0x00540db0-0x00540e4b.NewOptionPaneHandleServerOptionError` | modeled class helper blank | Insert first-draft C++; score to `88/90`. |
| 0003NP | `0x00540ef0-0x00540f4d.NewOptionPaneVisibleOptionHitTest` | raw no-function no-route helper | Insert formal no-code proof comment; score to `86/89`. |
| 0003NQ | `0x00540f50-0x00540fdf.NewOptionPaneApplyServerOptions` | raw no-function no-route helper | Insert formal no-code proof comment; score to `87/90`. |
| 0003NR | `0x00540ff0-0x0054103a.NewOptionPaneRefreshVolumeDisplay` | raw no-function no-route helper | Insert formal no-code proof comment; score to `86/89`. |
| 00009V | `by-class/OptionPane.md` | class marker blank | Insert `[[CHILDREN]]`; score to `87/88`. |
| 00035B | `0x00620c70-0x00620c74.OptionPaneRttiBoundaryData` | compiler RTTI/vtable boundary data emitted as source | Reclassify to non-reconstructable/non-emitting; score to `88/92`. |
| 0000TL | `by-global/SendOptionPacket11B_540E50.md` | alias/global page duplicates exact memory page | Reclassify to non-reconstructable/non-emitting index; exact body emits from [UID:0001DY]; score to `88/91`. |
| 0001DY | `0x00540e50-0x00540e91.SendOptionPacket11B` | modeled shared packet helper blank | Insert first-draft C++; score to `89/91`. |
| 0003NS | `0x00541040-0x00541114.SendLowHighDisplayModeOption` | modeled file helper blank | Insert first-draft C++; score to `88/90`. |
| 0001DZ | `0x00541660-0x005416d0.NewOptionPaneDrawBoldText` | modeled paint helper blank | Insert first-draft C++; score to `88/90`. |
| 0001E0 | `0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem` | modeled paint helper blank | Insert first-draft C++; score to `88/90`. |
| 00027W | `0x0066decc-0x0066dee0.OptionPaneLegacySizeWordTable_66DECC` | source-shaped data but no table reader/route | Insert formal no-code proof comment; score to `87/88`. |
| 0002ZC | `0x0066dee4-0x0066dee8.OptionPaneDlgOptEpdResourcePointer` | exact resource pointer blank | Insert first-draft static resource declaration; score to `90/94`. |

Root recommendation: raise [UID:0000M7] from `91/85` to `92/88` after these callback edits and scoped validators. Completion should not jump higher because [UID:0001DW] still needs exact method child splits for the large unsplit `NewOptionPane` method cluster.

## Evidence Checked

Current IDA MCP evidence:

- MCP endpoint: `http://127.0.0.1:13337/mcp`
- Session: `supervisor_resume_20260629`
- IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- `idb_list`: one active owned worker session for `NexusTK.exe.i64`.
- `server_health`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Current MCP tools used: `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `callees`, `get_bytes`, `get_string`, and `decompile`.
- Broad `search_text` for `DrawSectionHeader` and `DrawOptionButton` timed out. Follow-up `server_health` remained `ok`; the final report does not depend on those broad searches and uses direct xref/callee/decompile evidence instead.

by-* docs checked:

- `by-file/OptionPane.md`
- `by-class/OptionPane.md`
- `by-class/NewOptionPane.md`
- all 15 current empty-emitter pages listed above
- related filled/support pages [UID:0001DP], [UID:00040K], [UID:0001DQ], [UID:0003NO], [UID:0001DX], [UID:00023I], [UID:0001DO]
- packet/global/support pages [UID:0000Q5], [UID:0001HU], [UID:0000TL]

Generated/state files checked read-only:

- `auto-generated/NexusTK/ui/dialogs/OptionPane.cpp`
- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-file-coverage.md`
- `auto-generated/-ag-class-coverage.md`
- `auto-generated/-ag-memory-coverage.md`

Executed reports searched/opened as leads:

- Search terms included `0000M7`, `OptionPane`, `NewOptionPane`, `00540e50`, `00541040`, `00541660`, `005416d0`, `0066dee4`, `00620c70`, `0066decc`, `00540ef0`, `00540f50`, and `00540ff0`.
- Opened relevant executed reports: B001 `0001DP`, B001 `0001DW`, B001 `00027W`, B001 `B001-MEMTOOL-0053E380`, B004 `0001DO`, B010 `00023I`, and B015 `0001DX`.
- Older Wave2/Wave3/generated names were treated as lead material only.

## IDA MCP Facts

Function lookup facts:

| Address | Current MCP result |
| --- | --- |
| `0x0053ff90` | `sub_53FF90`, size `0x204`, `NewOptionPane` constructor-shaped. |
| `0x005401a0` | `sub_5401A0`, size `0x92`, destructor-shaped. |
| `0x00540240` | `sub_540240`, size `0x4d`. |
| `0x00540290` | `nullsub_45`, size `0x1`. |
| `0x005402a0` | `sub_5402A0`, size `0x108`. |
| `0x005403b0` | `sub_5403B0`, size `0xd6`, volume/config apply. |
| `0x00540490` | `sub_540490`, size `0x37`, volume callback. |
| `0x005404d0` | `sub_5404D0`, size `0xe6`. |
| `0x005405c0` | `sub_5405C0`, size `0x37`. |
| `0x00540600` | `sub_540600`, size `0x210`, paint. |
| `0x00540880` | `sub_540880`, size `0x87`, key dispatch. |
| `0x00540910` | `sub_540910`, size `0x427`, mouse dispatch. |
| `0x00540db0` | `sub_540DB0`, size `0x9b`, server-option error helper. |
| `0x00540e50` | `sub_540E50`, size `0x41`, shared `0x011b` sender. |
| `0x00540ea0` | Not a function; raw sender already filled by [UID:0003NO]. |
| `0x00540ef0` | Not a function; raw hit-test body. |
| `0x00540f50` | Not a function; raw server-option apply body. |
| `0x00540ff0` | Not a function; raw volume-display refresh body. |
| `0x00541040` | `sub_541040`, size `0xd4`, low/high display-mode helper. |
| `0x005411b0` | `sub_5411B0`, size `0x85`, option-entry setup. |
| `0x00541240` | `sub_541240`, size `0x411`, option initialization. |
| `0x00541660` | `sub_541660`, size `0x70`, section-header paint helper. |
| `0x005416d0` | `sub_5416D0`, size `0x183`, option-button paint helper. |
| `0x00541a20` | `sub_541A20`, size `0x69`, page change. |
| `0x00541a90` | `sub_541A90`, size `0x9b`, slider visibility. |
| `0x005a8c60` | `sub_5A8C60`, size `0x87`, discontiguous option packet helper. |
| `0x00620c70`, `0x0066decc`, `0x0066dee4` | Not functions; data items. |

Xref facts:

- `0x0053ff90` has one code xref at `0x004b8549` inside `GeneralPurposePanel` construction.
- `0x00540db0` has one data xref at `0x00621104`.
- `0x00540e50` has six code xrefs: `0x00540a0b`, `0x00540a23`, `0x00540a46`, `0x00540a90` inside `NewOptionPane::OnMouseClick`, plus `0x005690a4` and `0x00569164` in the `SelfLookPane` neighborhood.
- `0x00540ea0`, `0x00540ef0`, `0x00540f50`, and `0x00540ff0` have zero `xrefs_to`.
- `0x00541040` has two code xrefs at `0x00540ba9` and `0x00540bbe`, both inside `NewOptionPane::OnMouseClick`.
- `0x00541660` has four `OnPaint` xrefs: `0x00540639`, `0x0054064c`, `0x0054065f`, `0x00540672`.
- `0x005416d0` has five `OnPaint` xrefs: `0x0054068b`, `0x005406aa`, `0x005406be`, `0x005406ea`, `0x005407fd`.
- `0x005a8c60` has three `OnMouseClick` xrefs: `0x00540a58`, `0x00540aa2`, `0x00540ab4`.
- `0x00620c70` has zero xrefs; successor vtable base `0x00620c74` has refs at `0x0053d861`, `0x0053dd50`, and `0x00542946`.
- `0x0066decc` has row-0 write refs at `0x005a8bf7` and `0x005a8c3d`; `0x0066ded6` has zero xrefs.
- `0x0066dee4` has three data refs at `0x0053d89f`, `0x0053d8cb`, and `0x0053d8fd`, all inside old `OptionPane` constructor `0x0053d820`.

Byte/string facts:

- `get_bytes 0x00540e90 size 432` shows `0xcc` alignment before raw `0x00540ea0`, source-shaped raw bodies at `0x00540ea0`, `0x00540ef0`, `0x00540f50`, and `0x00540ff0`, and alignment before `0x00541040`.
- `get_bytes 0x0066decc size 32` returns five `0x0050` words, five `0x0028` words, successor flag bytes, pointer `64 12 62 00`, and following UTF-16 `S`/`U` bytes.
- `get_bytes 0x00620c70 size 8` returns `80 d4 64 00 40 29 54 00`, proving compiler/vtable boundary data before the old `OptionPane` destructor pointer.
- `get_string 0x00621264` -> `DLGOPT.EPD`.
- `get_string 0x00618784` -> `RBUTTON.PAL`.
- `get_string 0x0060ddf8` -> `BU`.

Decompile facts:

- `0x00540db0` checks `*Block[3] == 0x21`, allocates/gets alert id `624`, fetches localized message `61`, displays relative to `this - 40`, returns `1`; otherwise returns `0`.
- `0x00540e50` writes word `0x011b`, caller option byte at packet `+2`, an unsent zero scratch byte, and queues length `3` through `dword_67A7EC`.
- `0x00541040` writes config offsets `0x28de58`, `0x28de5e`, `0x28de5c`; when mode is zero calls `0x005040a0(dword_67A764)`; compares server-applied bytes `0x28de72` and `0x28de73`; conditionally queues packet byte `0x1b`, count, and option bytes `5` and/or `6`.
- `0x00541660` sets GrafPort color `128`, moves to `(x,y)`, draws wide text, moves to `(x+1,y)`, draws same text again.
- `0x005416d0` computes `entry = this + 0x98 * index`, checks entry page byte `+0x18c` against active page `this+0x12b9` or `0xff`, switches on type byte `+0x178`, draws frames through `0x004b9980`, then draws label at `+0xf8` twice with colors `6` and `128`.
- `0x005a8c60` sends four bytes through `dword_67A7EC`: `0x1b`, `0x01`, selector, and `selector == 0`.
- `0x005403b0` clamps local volume values at `this+0x12bc` and `this+0x12c0`, writes five-times-scaled config offsets `0x28de54` and `0x28de4c`, and calls sound manager helpers.
- `0x00540490` returns if old/new values match; otherwise writes nonzero volume type to `this+0x12bc`, zero volume type to `this+0x12c0`, calls `0x005403b0`, and invalidates through vtable slot `+0x20`.

## Heuristic / Inference Reanalysis And Validation

The current empty emitters are not all the same kind of problem.

1. Class/container markers are legitimate but must use `[[CHILDREN]]`, not blank C++.
2. Several old "below 95/95" blank-C++ rationales are stale under current by-structure rules. Pages such as [UID:0001DY], [UID:0003NS], [UID:0001DZ], [UID:0001E0], and [UID:0002ZC] clear the current combined-score/emitter gate and have enough exact behavior for first-draft formal C++.
3. Raw no-route helpers [UID:0003NP], [UID:0003NQ], and [UID:0003NR] should preserve their no-route evidence, but a blank formal block is poor generated output. A formal no-code proof comment is the correct disposition until a caller/pointer route and synchronized declarations are proven.
4. [UID:0000TL] is an alias/index for the exact physical function [UID:0001DY]. Emitting both would duplicate source. The memory page should own the body; the by-global page should become non-emitting support.
5. [UID:00035B] is compiler-generated RTTI/vtable boundary data. It should not emit C++ through `OptionPane.cpp`.
6. [UID:00027W] is source-shaped data but remains uncalled/unread except row writes from no-route raw setters. A declaration would freeze a storage grouping not proven by current evidence, so a formal no-code proof marker is safer.
7. [UID:0001DW] is too broad to receive a monolithic C++ body. It contains many modeled methods, a jump table, exact child helpers, raw no-route helper bodies, and padding. It should be an aggregate `[[CHILDREN]]` page plus a concrete split plan for the unsplit modeled methods.

Rejected alternatives:

- Treating all 15 empty markers as "names not final": rejected; several have stable enough behavior for first-draft formal C++.
- Emitting [UID:0000TL] and [UID:0001DY]: rejected as duplicate emission of the same physical helper.
- Keeping [UID:00035B] reconstructable/emitting: rejected because current bytes/xrefs show RTTI/vtable boundary data, not source-authored data.
- Making [UID:0001DY] a `NewOptionPane` method: rejected by two `SelfLookPane` neighborhood callers.
- Assigning paint helpers to `FittingRoomDownloadControlPane`: rejected; current xrefs are all `NewOptionPane::OnPaint`.
- Promoting raw helpers [UID:0003NP], [UID:0003NQ], [UID:0003NR] to emitted helper functions now: rejected because current MCP has no function records and no inbound xrefs/routes, while existing modeled code duplicates or owns the live behavior.

## Range / Split / Padding / Reclassification Analysis

[UID:0001DW] exact aggregate formal insertion:

```cpp
[[CHILDREN]]
```

Existing child/support pages to preserve under the aggregate:

- [UID:0003NN] `0x00540db0-0x00540e4b.NewOptionPaneHandleServerOptionError`
- [UID:0001DY] `0x00540e50-0x00540e91.SendOptionPacket11B`
- [UID:0003NO] `0x00540ea0-0x00540ee8.NewOptionPaneSendOptionPacket11BSubcommand63`
- [UID:0003NP] `0x00540ef0-0x00540f4d.NewOptionPaneVisibleOptionHitTest`
- [UID:0003NQ] `0x00540f50-0x00540fdf.NewOptionPaneApplyServerOptions`
- [UID:0003NR] `0x00540ff0-0x0054103a.NewOptionPaneRefreshVolumeDisplay`
- [UID:0003NS] `0x00541040-0x00541114.SendLowHighDisplayModeOption`
- [UID:0001DZ] `0x00541660-0x005416d0.NewOptionPaneDrawBoldText`
- [UID:0001E0] `0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem`

Recommended new child split plan for unsplit [UID:0001DW] subranges:

| Proposed child file | Range | Metadata recommendation | Disposition |
| --- | --- | --- | --- |
| `by-memory/0x0053ff90-0x00540194.NewOptionPaneConstructor.md` | `0x0053ff90-0x00540194` | new UID by validator; owner/emitter `000097`; `86/89`; reconstructable true | Constructor first-draft C++ after split. |
| `by-memory/0x005401a0-0x00540232.NewOptionPaneDestructor.md` | `0x005401a0-0x00540232` | owner/emitter `000097`; `86/89`; true | Destructor first-draft C++ after split. |
| `by-memory/0x00540240-0x0054028d.NewOptionPaneOnActivate.md` | `0x00540240-0x0054028d` | owner/emitter `000097`; `85/88`; true | Lifecycle first-draft C++. |
| `by-memory/0x00540290-0x00540291.NewOptionPaneNullHook.md` | `0x00540290-0x00540291` | owner `000097`; reconstructable false; no emitter | Null virtual/no-code proof. |
| `by-memory/0x005402a0-0x005403a8.NewOptionPaneOnLayout.md` | `0x005402a0-0x005403a8` | owner/emitter `000097`; `86/89`; true | Layout first-draft C++. |
| `by-memory/0x005403b0-0x00540486.NewOptionPaneApplyVolumeSettings.md` | `0x005403b0-0x00540486` | owner/emitter `000097`; `88/90`; true | Volume apply C++ using documented config offsets. |
| `by-memory/0x00540490-0x005404c7.NewOptionPaneOnVolumeChanged.md` | `0x00540490-0x005404c7` | owner/emitter `000097`; `88/90`; true | Callback C++; exact behavior already decompiled. |
| `by-memory/0x005404d0-0x005405b6.NewOptionPaneOnOpen.md` | `0x005404d0-0x005405b6` | owner/emitter `000097`; `86/89`; true | Open handler C++. |
| `by-memory/0x005405c0-0x005405f7.NewOptionPaneOnClose.md` | `0x005405c0-0x005405f7` | owner/emitter `000097`; `86/89`; true | Close handler C++. |
| `by-memory/0x00540600-0x00540810.NewOptionPaneOnPaint.md` | `0x00540600-0x00540810` | owner/emitter `000097`; `88/90`; true | Paint dispatcher C++; calls paint helper children. |
| `by-memory/0x00540880-0x00540907.NewOptionPaneOnKeyPress.md` | `0x00540880-0x00540907` | owner/emitter `000097`; `86/89`; true | Key handler C++. |
| `by-memory/0x00540910-0x00540d37.NewOptionPaneOnMouseClick.md` | `0x00540910-0x00540d37` | owner/emitter `000097`; `88/90`; true | Mouse dispatcher C++; calls [UID:0001DY], [UID:0003NS], and `0x005a8c60` future child. |
| `by-memory/0x00540d39-0x00540d9c.NewOptionPaneMouseClickJumpTable.md` | `0x00540d39-0x00540d9c` | owner `000097`; reconstructable false; no emitter | Compiler switch data/no-code proof. |
| `by-memory/0x005411b0-0x00541235.NewOptionPaneSetOptionEntry.md` | `0x005411b0-0x00541235` | owner/emitter `000097`; `88/90`; true | Option-entry setup C++. |
| `by-memory/0x00541240-0x00541651.NewOptionPaneInitializeOptions.md` | `0x00541240-0x00541651` | owner/emitter `000097`; `88/90`; true | Initialization C++; 25 explicit entries, holes `6` and `15`. |
| `by-memory/0x00541a20-0x00541a89.NewOptionPaneChangePage.md` | `0x00541a20-0x00541a89` | owner/emitter `000097`; `86/89`; true | Page-change C++. |
| `by-memory/0x00541a90-0x00541b2b.NewOptionPaneUpdateSliderVisibility.md` | `0x00541a90-0x00541b2b` | owner/emitter `000097`; `87/90`; true | Slider visibility C++. |

Discontiguous follow-up split recommended if supervisor wants to clear [UID:00027W] and the live selector sender:

- `by-memory/0x005a8b80-0x005a8c16.OptionPaneSetLegacySizeWordsFromThresholds.md`
- `by-memory/0x005a8c20-0x005a8c5c.OptionPaneSetLegacySizeWordsFromScaleLevel.md`
- `by-memory/0x005a8c60-0x005a8ce7.NewOptionPaneSendOptionPacket1BSelector.md`

The first two remain no-route raw setters; the third is modeled and directly called from `NewOptionPane::OnMouseClick`.

## First-Draft C++ / Marker Dispositions

### [UID:000097] NewOptionPane Class

Exact formal insertion:

```cpp
[[CHILDREN]]
```

After-score rationale: `87/89`; the class has strong owner/vtable evidence and exact children, but full class declarations and all method child splits are not complete.

### [UID:0001DW] NewOptionPane Aggregate

Exact formal insertion:

```cpp
[[CHILDREN]]
```

Do not insert method bodies into this broad page. Create the child pages listed above during callback if the supervisor accepts the split plan.

### [UID:0003NN] NewOptionPaneHandleServerOptionError

Exact formal insertion:

```cpp
bool NewOptionPane::OnServerOptionError(const PacketEvent *event)
{
    const unsigned char *payload = event->payload;

    if (payload[0] != 0x21)
        return false;

    AlertPane *alert = CreateAlertPane(624);
    if (alert != 0)
        alert->ShowMessage(GetLocalizedString(61), this);

    return true;
}
```

Evidence: modeled `0x00540db0` size `0x9b`, data xref `0x00621104`, decompile checks `Block[3][0] == 0x21`, calls alert allocation/resource id `61`, adjusts owner pointer by `this - 40`, returns `1`.

### [UID:0003NP] NewOptionPaneVisibleOptionHitTest

Exact formal insertion:

```cpp
// Raw retained NewOptionPane visible-option hit-test body at 0x00540ef0 is not emitted as a source helper yet.
// Current MCP reports no function record and no inbound xref/pointer route; NewOptionPane::OnMouseClick contains the live inline-equivalent scan.
```

Metadata remains reconstructable true with owner/emitter [UID:000097]. This is not padding, but blank C++ should be replaced by the explicit no-code marker above.

### [UID:0003NQ] NewOptionPaneApplyServerOptions

Exact formal insertion:

```cpp
// Raw retained NewOptionPane server-option apply body at 0x00540f50 is not emitted as a source helper yet.
// Current MCP reports no function record and no inbound xref/pointer route; payload and Config field declarations are not synchronized for a callable source method.
```

Metadata remains reconstructable true with owner/emitter [UID:000097].

### [UID:0003NR] NewOptionPaneRefreshVolumeDisplay

Exact formal insertion:

```cpp
// Raw retained NewOptionPane volume-display refresh body at 0x00540ff0 is not emitted as a source helper yet.
// Current MCP reports no function record and no inbound xref/pointer route; ApplyVolumeSettings and OnVolumeChanged carry the live modeled volume paths.
```

Metadata remains reconstructable true with owner/emitter [UID:000097].

### [UID:00009V] OptionPane Class

Exact formal insertion:

```cpp
[[CHILDREN]]
```

After-score rationale: `87/88`; class owner and exact children are stable, but old constructor/command subranges still need child splits from [UID:0001DO] before class source is complete.

### [UID:00035B] OptionPaneRttiBoundaryData

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:92
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

Formal C++ should remain blank after the page stops emitting. Exact no-code proof: `0x00620c70` has no xrefs, `0x00620c74` is the referenced old `OptionPane` vtable/destructor boundary, and the bytes are compiler RTTI/vtable boundary data rather than source-authored declarations.

### [UID:0000TL] SendOptionPacket11B_540E50 Global Alias

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:91
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

Formal C++ should remain blank after reclassification. The exact physical body should emit only from [UID:0001DY]. Keep [UID:0000TL] as a support/index page for name, caller split, and protocol facts.

### [UID:0001DY] SendOptionPacket11B

Exact formal insertion:

```cpp
static void SendOptionPacket11B(unsigned char optionCode)
{
    unsigned char packet[4] = {};

    *reinterpret_cast<unsigned short *>(packet) = 0x011b;
    packet[2] = optionCode;

    g_packetSender->QueueAndSendPacket(packet, 3);
}
```

Evidence: modeled `0x00540e50` size `0x41`, six callers, decompile writes opcode `0x011b`, one option byte, local unsent zero, sends length `3`.

### [UID:0003NS] SendLowHighDisplayModeOption

Exact formal insertion:

```cpp
static void SendLowHighDisplayModeOption(unsigned char displayMode)
{
    g_pConfig->m_requestedDisplayMode = displayMode;
    if (g_pConfig->m_requestedDisplayMode == 0)
        ResetDisplayEffects(g_pInterfaceEffects);

    g_pConfig->m_shadowDisplayMode = displayMode;
    g_pConfig->m_displayModeMirror = displayMode;

    const bool lowChanged = (g_pConfig->m_serverLowDisplayMode != displayMode);
    const bool highChanged = (g_pConfig->m_serverHighDisplayMode != displayMode);
    if (!lowChanged && !highChanged)
        return;

    unsigned char packet[5] = {};
    unsigned int packetSize = 2;

    packet[0] = 0x1b;
    packet[1] = static_cast<unsigned char>((lowChanged ? 1 : 0) + (highChanged ? 1 : 0));

    if (lowChanged)
        packet[packetSize++] = 5;
    if (highChanged)
        packet[packetSize++] = 6;

    g_packetSender->QueueAndSendPacket(packet, packetSize);
}
```

Evidence: modeled `0x00541040` size `0xd4`, two callers from `OnMouseClick`, config writes/comparisons, optional `0x1b` packet with subcommand bytes `5` and `6`. Field names are source-facing inferred names and should be documented as inferred.

### [UID:0001DZ] NewOptionPaneDrawBoldText

Exact formal insertion:

```cpp
static void DrawOptionPaneSectionHeader(GrafPort *port, const wchar_t *text, int x, int y)
{
    port->SetTextColor(128);
    port->MoveTo(x, y);
    port->DrawText(text, wcslen(text));

    port->MoveTo(x + 1, y);
    port->DrawText(text, wcslen(text));
}
```

Evidence: modeled `0x00541660` size `0x70`, four `OnPaint` callers, callees `0x004b9680`, `0x004b9600`, `0x004bab70`, decompile draws the same wide string twice after setting color `128`. File-local placement is safer than class method because the body consumes draw context/text/coordinates and not NewOptionPane fields.

### [UID:0001E0] NewOptionPaneDrawOptionButtonItem

Exact formal insertion:

```cpp
static void DrawOptionPaneButtonItem(NewOptionPane *pane, short optionIndex, short drawSlot)
{
    OptionEntry *entry = pane->GetOptionEntry(optionIndex);

    if (entry->page != pane->m_activePage && entry->page != 0xff)
        return;

    switch (entry->type)
    {
    case 0:
        pane->DrawButtonFrame(drawSlot, entry->bounds, kOptionButtonPalette);
        break;

    case 1:
        pane->DrawPressedButtonFrame(drawSlot, entry->bounds, kOptionButtonPalette);
        break;

    case 3:
        pane->DrawButtonFrame(drawSlot, entry->bounds, L"BU");
        break;

    case 4:
        pane->DrawButtonFrame(drawSlot, entry->bounds, L"RBUTTON.PAL");
        break;
    }

    pane->SetTextColor(6);
    pane->MoveTo(entry->bounds.left + 19, entry->bounds.top + 13);
    pane->DrawText(entry->label, wcslen(entry->label));

    pane->SetTextColor(128);
    pane->MoveTo(entry->bounds.left + 18, entry->bounds.top + 13);
    pane->DrawText(entry->label, wcslen(entry->label));
}
```

Evidence: modeled `0x005416d0` size `0x183`, five `OnPaint` callers, option entry stride `0x98`, page byte `+0x18c`, type byte `+0x178`, bounds at `+0x17c`, label at `+0xf8`, strings `BU` and `RBUTTON.PAL`. Type and helper names are inferred source-facing names; preserve that caveat.

### [UID:00027W] OptionPaneLegacySizeWordTable_66DECC

Exact formal insertion:

```cpp
// Source-shaped legacy option-size word table at 0x0066decc is intentionally not emitted yet.
// Current MCP proves row-0 setter writes and no tail-row refs, but no table reader or setter entry route proves the final declaration grouping.
```

Keep owner/emitter [UID:0000M7] unless supervisor chooses to make the page non-emitting. Do not insert the candidate `uint16_t[2][5]` declaration yet.

### [UID:0002ZC] OptionPaneDlgOptEpdResourcePointer

Exact formal insertion:

```cpp
static const wchar_t *const kOptionPaneDialogResourceName = L"DLGOPT.EPD";
```

Evidence: bytes at `0x0066dee4` are `64 12 62 00`, `get_string 0x00621264` returns `DLGOPT.EPD`, and all three xrefs are old `OptionPane` constructor refs.

## Ranked Ownership Analysis

### 1. [UID:0000M7] OptionPane by-file source root

Evidence for: projected path is `NexusTK/ui/dialogs/`; current file docs already group old and new option panes; packet helpers, paint helpers, option-size data, and `DLGOPT.EPD` resource pointer all belong to option/settings UI source; current root is `91/85`.

Evidence against: several exact method bodies are class-owned by [UID:00009V] or [UID:000097], so the file should not directly own every class method.

Decision: accepted source root and file-level helper/data owner.

### 2. [UID:000097] NewOptionPane class

Evidence for: constructor caller, vtables, method map, `OnPaint`, `OnMouseClick`, and class-shaped raw helpers all point to `NewOptionPane`.

Evidence against: shared/file helpers [UID:0001DY], [UID:0003NS], [UID:0001DZ], [UID:0001E0], [UID:0000TL], [UID:00027W], and [UID:0002ZC] are not all narrow class members.

Decision: owner/emitter for class methods and raw class-shaped helpers; class page gets `[[CHILDREN]]`.

### 3. [UID:00009V] OptionPane class

Evidence for: old `OptionPane` vtable refs and class docs; old server-response and apply helpers route through this class.

Evidence against: old local packet senders are `__stdcall`/file-local and not class methods.

Decision: owner/emitter for old class methods; class page gets `[[CHILDREN]]`.

### 4. Socket/network or SelfLookPane ownership

Evidence for: helper sends through `g_packetSender`; [UID:0001DY] has two `SelfLookPane` neighborhood callers.

Evidence against: packet construction is option/settings feature logic; network is only the send dependency; `SelfLookPane` is a consumer of the shared option helper, not the source root.

Decision: rejected as owner; preserve shared-caller caveat.

### 5. FittingRoomDownloadControlPane / LivingObjectPane ownership

Evidence for: stale generated pollution and physical address neighborhoods.

Evidence against: direct callers for paint helpers are all `NewOptionPane::OnPaint`; `0x005a8c60` callers are all `NewOptionPane::OnMouseClick`; no current route points to FittingRoom or LivingObjectPane ownership.

Decision: rejected.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | [UID:0000M7] remains the source root and should move from `91/85` to `92/88` after empty-emitter dispositions are applied. | High | generated row, by-file docs, current MCP owner/caller facts | `by-file/OptionPane.md` metadata/status/changes | incorporate | applied: metadata now `92/88`; section `2026-06-30 B007 Empty-Emitter Cleanup Implementation`; validator `000000002947` and final wait `000000002948` ok. |
| C2 | [UID:000097] and [UID:00009V] should emit `[[CHILDREN]]`, not blank markers. | High | class pages are containers with exact children | `by-class/NewOptionPane.md`, `by-class/OptionPane.md` formal blocks | incorporate | applied: both formal blocks contain `[[CHILDREN]]`; scores now `87/89` and `87/88`; validators `000000002932` and `000000002933` ok. |
| C3 | [UID:0001DW] is a broad aggregate and should emit `[[CHILDREN]]` plus the exact child split plan in this report. | High | lookup function map, jump table, exact children, padding | `by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md` | incorporate | applied: formal block contains `[[CHILDREN]]`; `Future Child Split Plan` records exact proposed files/ranges/metadata; score now `87/88`; validator `000000002934` ok. |
| C4 | [UID:0003NN] is ready for first-draft `NewOptionPane::OnServerOptionError` C++. | High | modeled function, data xref, decompile | `by-memory/0x00540db0-0x00540e4b...md` | incorporate | applied: formal block contains first-draft `NewOptionPane::OnServerOptionError`; score now `88/90`; validator `000000002935` ok. |
| C5 | [UID:0003NP], [UID:0003NQ], [UID:0003NR] are retained raw no-route helpers and should receive formal no-code comments. | High | no function records, zero xrefs, raw bytes/decompile context | their by-memory pages | incorporate | applied: all three formal blocks contain accepted no-code comments; scores now `86/89`, `87/90`, `86/89`; validators `000000002936`, `000000002937`, `000000002938` ok. |
| C6 | [UID:00035B] should be non-reconstructable/non-emitting compiler RTTI/vtable boundary data. | High | bytes and xrefs to successor vtable only | `by-memory/0x00620c70-0x00620c74...md` | incorporate | applied: metadata now `88/92`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`; no-code compiler-boundary rationale preserved; validator `000000002939` ok. |
| C7 | [UID:0000TL] is a non-emitting alias/index; [UID:0001DY] owns the physical helper C++. | High | duplicate generated markers, exact memory page, xrefs/decompile | `by-global/SendOptionPacket11B_540E50.md`, `by-memory/0x00540e50...md` | incorporate | applied: by-global now `88/91`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`; [UID:0001DY] now carries formal C++; validators `000000002940` and `000000002941` ok. |
| C8 | [UID:0001DY], [UID:0003NS], [UID:0001DZ], [UID:0001E0], and [UID:0002ZC] should receive exact first-draft formal C++. | Medium-high | current modeled functions/data, xrefs, decompiles, strings | listed by-memory pages | incorporate | applied: formal C++ inserted in all listed pages; scores now `89/91`, `88/90`, `88/90`, `88/90`, `90/94`; validators `000000002941` through `000000002944` and `000000002946` ok. |
| C9 | [UID:00027W] remains source-shaped data but not declaration-ready; use a formal no-code proof marker. | Medium-high | row writes, no tail refs, no table reader or setter route | `by-memory/0x0066decc-0x0066dee0...md` | incorporate | applied: formal no-code proof comment inserted; confidence now `88`; no forced declaration; validator `000000002945` ok. |
| C10 | Generated `OptionPane.cpp` freshness expectation: after callback validators, `Marked Empty` should drop from 15 to 0 or only intentional non-emitting pages should disappear from emitter count. | High | current generated file markers | validator/generated refresh result | incorporate | applied: final `--wait-generated` validator `000000002950` exit 0, `ok:1`, `generated_refresh: completed`; inspected generated `OptionPane.cpp` has accepted C++/no-code comments, no target `EMPTY` markers, and header `validator-command-id: 000000002950`, `validator-refreshed-at: 2026-06-30T14:45:53-04:00`. |

## Score And Metadata Recommendation

| UID | Before C/F | After C/F | Metadata changes |
| --- | ---: | ---: | --- |
| 0000M7 | 91/85 | 92/88 | keep `CANONICAL_OWNER:FILE`, path unchanged |
| 000097 | 86/87 | 87/89 | keep owner/emitter `0000M7`, add `[[CHILDREN]]` |
| 0001DW | 86/86 | 87/88 | keep owner/emitter `000097`, add `[[CHILDREN]]`, child split plan |
| 0003NN | 85/88 | 88/90 | keep owner/emitter `000097`, add C++ |
| 0003NP | 85/88 | 86/89 | keep owner/emitter `000097`, add no-code marker |
| 0003NQ | 86/89 | 87/90 | keep owner/emitter `000097`, add no-code marker |
| 0003NR | 85/88 | 86/89 | keep owner/emitter `000097`, add no-code marker |
| 00009V | 86/87 | 87/88 | keep owner/emitter `0000M7`, add `[[CHILDREN]]` |
| 00035B | 87/90 | 88/92 | `RECONSTRUCTABLE:FALSE`, clear `EMITTER_UIDS` |
| 0000TL | 87/90 | 88/91 | `RECONSTRUCTABLE:FALSE`, clear `EMITTER_UIDS`; support/index only |
| 0001DY | 87/90 | 89/91 | keep owner/emitter `0000M7`, add C++ |
| 0003NS | 85/88 | 88/90 | keep owner/emitter `0000M7`, add C++ |
| 0001DZ | 85/88 | 88/90 | keep owner/emitter `0000M7`, add C++ |
| 0001E0 | 85/88 | 88/90 | keep owner/emitter `0000M7`, add C++ |
| 00027W | 87/86 | 87/88 | keep owner/emitter `0000M7`, add no-code marker |
| 0002ZC | 88/93 | 90/94 | keep owner/emitter `0000M7`, add C++ |

Reason not higher: several [UID:0001DW] modeled methods still need exact child pages, and some helper/type/field names remain inferred rather than original-symbol proven.

## Recommended Target / Support Doc Changes

Implementation callback edited only:

- `by-file/OptionPane.md`
- `by-class/OptionPane.md`
- `by-class/NewOptionPane.md`
- the 15 current empty-emitter pages listed in this report
- no new child pages; supervisor callback explicitly excluded child creation for this pass and required the split plan to remain documented/follow-up in [UID:0001DW].

Do not edit generated files, project-level reports, manual coverage reports, validator state, queue files, lock files, supervisor ledgers, or unrelated docs.

## Validator / Generated Freshness Expectations

Implementation callback ran scoped validators from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0000M7-OptionPane-empty-emitter-family-source-quality-removed.md](0000M7-OptionPane-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If new child pages are created, use TMP references/validator UID workflow and validate every new child file. After the scoped batch, run:

> Executable block R002 was removed from this report and preserved verbatim in [0000M7-OptionPane-empty-emitter-family-source-quality-removed.md](0000M7-OptionPane-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Callback validator results:

| File | Command | command_id | command_timestamp | Exit | ok | Warnings / side effects |
| --- | --- | --- | --- | ---: | ---: | --- |
| `by-class/NewOptionPane.md` | `python .\tools\validator.py --mode file --file by-class/NewOptionPane.md --apply --queue-timeout 240` | `000000002932` | `2026-06-30T14:40:11-04:00` | 0 | 1 | Existing `missing_ref_uid 00038E` x5; generated refresh deferred. |
| `by-class/OptionPane.md` | `python .\tools\validator.py --mode file --file by-class/OptionPane.md --apply --queue-timeout 240` | `000000002933` | `2026-06-30T14:40:27-04:00` | 0 | 1 | Generated refresh deferred. |
| `by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md` | `python .\tools\validator.py --mode file --file by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md --apply --queue-timeout 240` | `000000002934` | `2026-06-30T14:40:29-04:00` | 0 | 1 | Generated refresh deferred. |
| `by-memory/0x00540db0-0x00540e4b.NewOptionPaneHandleServerOptionError.md` | `python .\tools\validator.py --mode file --file by-memory/0x00540db0-0x00540e4b.NewOptionPaneHandleServerOptionError.md --apply --queue-timeout 240` | `000000002935` | `2026-06-30T14:40:31-04:00` | 0 | 1 | Generated refresh deferred. |
| `by-memory/0x00540ef0-0x00540f4d.NewOptionPaneVisibleOptionHitTest.md` | `python .\tools\validator.py --mode file --file by-memory/0x00540ef0-0x00540f4d.NewOptionPaneVisibleOptionHitTest.md --apply --queue-timeout 240` | `000000002936` | `2026-06-30T14:40:33-04:00` | 0 | 1 | Generated refresh deferred; generated `OptionPane.cpp` header later shows this content-write id family. |
| `by-memory/0x00540f50-0x00540fdf.NewOptionPaneApplyServerOptions.md` | `python .\tools\validator.py --mode file --file by-memory/0x00540f50-0x00540fdf.NewOptionPaneApplyServerOptions.md --apply --queue-timeout 240` | `000000002937` | `2026-06-30T14:40:35-04:00` | 0 | 1 | Generated refresh deferred. |
| `by-memory/0x00540ff0-0x0054103a.NewOptionPaneRefreshVolumeDisplay.md` | `python .\tools\validator.py --mode file --file by-memory/0x00540ff0-0x0054103a.NewOptionPaneRefreshVolumeDisplay.md --apply --queue-timeout 240` | `000000002938` | `2026-06-30T14:40:36-04:00` | 0 | 1 | Generated refresh deferred; generated `OptionPane.cpp` inspected with header `000000002938`. |
| `by-memory/0x00620c70-0x00620c74.OptionPaneRttiBoundaryData.md` | `python .\tools\validator.py --mode file --file by-memory/0x00620c70-0x00620c74.OptionPaneRttiBoundaryData.md --apply --queue-timeout 240` | `000000002939` | `2026-06-30T14:40:38-04:00` | 0 | 1 | Metadata changed reconstructable true->false and emitter cleared; generated refresh deferred. |
| `by-global/SendOptionPacket11B_540E50.md` | `python .\tools\validator.py --mode file --file by-global/SendOptionPacket11B_540E50.md --apply --queue-timeout 240` | `000000002940` | `2026-06-30T14:40:40-04:00` | 0 | 1 | Metadata changed reconstructable true->false and emitter cleared; generated refresh deferred. |
| `by-memory/0x00540e50-0x00540e91.SendOptionPacket11B.md` | `python .\tools\validator.py --mode file --file by-memory/0x00540e50-0x00540e91.SendOptionPacket11B.md --apply --queue-timeout 240` | `000000002941` | `2026-06-30T14:40:42-04:00` | 0 | 1 | Generated refresh deferred. |
| `by-memory/0x00541040-0x00541114.SendLowHighDisplayModeOption.md` | `python .\tools\validator.py --mode file --file by-memory/0x00541040-0x00541114.SendLowHighDisplayModeOption.md --apply --queue-timeout 240` | `000000002942` | `2026-06-30T14:40:44-04:00` | 0 | 1 | Generated refresh deferred. |
| `by-memory/0x00541660-0x005416d0.NewOptionPaneDrawBoldText.md` | `python .\tools\validator.py --mode file --file by-memory/0x00541660-0x005416d0.NewOptionPaneDrawBoldText.md --apply --queue-timeout 240` | `000000002943` | `2026-06-30T14:40:46-04:00` | 0 | 1 | Generated refresh deferred. |
| `by-memory/0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem.md` | `python .\tools\validator.py --mode file --file by-memory/0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem.md --apply --queue-timeout 240` | `000000002944` | `2026-06-30T14:40:47-04:00` | 0 | 1 | Generated refresh deferred. |
| `by-memory/0x0066decc-0x0066dee0.OptionPaneLegacySizeWordTable_66DECC.md` | `python .\tools\validator.py --mode file --file by-memory/0x0066decc-0x0066dee0.OptionPaneLegacySizeWordTable_66DECC.md --apply --queue-timeout 240` | `000000002945` | `2026-06-30T14:40:49-04:00` | 0 | 1 | Generated refresh deferred. |
| `by-memory/0x0066dee4-0x0066dee8.OptionPaneDlgOptEpdResourcePointer.md` | `python .\tools\validator.py --mode file --file by-memory/0x0066dee4-0x0066dee8.OptionPaneDlgOptEpdResourcePointer.md --apply --queue-timeout 240` | `000000002946` | `2026-06-30T14:40:51-04:00` | 0 | 1 | Generated refresh deferred. |
| `by-file/OptionPane.md` | `python .\tools\validator.py --mode file --file by-file/OptionPane.md --apply --queue-timeout 240` | `000000002947` | `2026-06-30T14:40:53-04:00` | 0 | 1 | Generated refresh deferred. |
| `by-file/OptionPane.md` final | `python .\tools\validator.py --mode file --file by-file/OptionPane.md --apply --wait-generated --queue-timeout 240` | `000000002948` | `2026-06-30T14:41:03-04:00` | 0 | 1 | `generated_refresh: completed`; broad autogen warnings elsewhere: `autogen_children_marker_missing:59`, `autogen_emitter_has_no_code:314`; generated reports and C++ metadata refreshed by validator. |
| `by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md` follow-up | `python .\tools\validator.py --mode file --file by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md --apply --queue-timeout 240` | `000000002949` | `2026-06-30T14:45:45-04:00` | 0 | 1 | Follow-up validation after wording correction; generated refresh deferred. |
| `by-file/OptionPane.md` final follow-up | `python .\tools\validator.py --mode file --file by-file/OptionPane.md --apply --wait-generated --queue-timeout 240` | `000000002950` | `2026-06-30T14:45:53-04:00` | 0 | 1 | `generated_refresh: completed`; `autogen_cpp_update:1`; broad autogen warnings elsewhere: `autogen_children_marker_missing:59`, `autogen_emitter_has_no_code:311`; generated reports and C++ metadata refreshed by validator. |

Generated result: `auto-generated/NexusTK/ui/dialogs/OptionPane.cpp` was inspected after final wait `000000002950`. It contains the accepted formal C++/no-code comments for [UID:0003NN], [UID:0003NP], [UID:0003NQ], [UID:0003NR], [UID:0001DY], [UID:0003NS], [UID:0001DZ], [UID:0001E0], [UID:00027W], and [UID:0002ZC], and [UID:00035B]/[UID:0000TL] no longer emit. Search found no target `EMPTY` marker. Header is current for the final command: `validator-command-id: 000000002950`, `validator-refreshed-at: 2026-06-30T14:45:53-04:00`, `validator-refresh-source: foreground-generated-refresh`.

## Open Questions With Attempted Resolution

- Exact original helper names `DrawSectionHeader`, `DrawOptionButton`, `SendLowHighDisplayModeOption`, and `OptionEntry` are not binary-proven. Current evidence is strong enough for first-draft source-facing names, but report/doc text should mark them inferred.
- [UID:0001DW] exact method children are not all present. This report gives exact child file/range/metadata recommendations; supervisor can accept them for a split callback or accept only current empty-marker cleanup first.
- [UID:00027W] final declaration grouping remains unresolved because no table reader or setter route is proven. This is resolved for this pass by formal no-code marker, not by forced declaration.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B007/research/0000M7-OptionPane-empty-emitter-family-source-quality.md`

Modified during implementation callback:

- `by-file/OptionPane.md`
- `by-class/OptionPane.md`
- `by-class/NewOptionPane.md`
- `by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md`
- `by-memory/0x00540db0-0x00540e4b.NewOptionPaneHandleServerOptionError.md`
- `by-memory/0x00540ef0-0x00540f4d.NewOptionPaneVisibleOptionHitTest.md`
- `by-memory/0x00540f50-0x00540fdf.NewOptionPaneApplyServerOptions.md`
- `by-memory/0x00540ff0-0x0054103a.NewOptionPaneRefreshVolumeDisplay.md`
- `by-memory/0x00620c70-0x00620c74.OptionPaneRttiBoundaryData.md`
- `by-global/SendOptionPacket11B_540E50.md`
- `by-memory/0x00540e50-0x00540e91.SendOptionPacket11B.md`
- `by-memory/0x00541040-0x00541114.SendLowHighDisplayModeOption.md`
- `by-memory/0x00541660-0x005416d0.NewOptionPaneDrawBoldText.md`
- `by-memory/0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem.md`
- `by-memory/0x0066decc-0x0066dee0.OptionPaneLegacySizeWordTable_66DECC.md`
- `by-memory/0x0066dee4-0x0066dee8.OptionPaneDlgOptEpdResourcePointer.md`
- this report checklist/ledger

Validator-updated generated/project state:

- `auto-generated/NexusTK/ui/dialogs/OptionPane.cpp`
- validator-driven generated metadata/report refreshes and projected stats updates reported by command `000000002948`

Leases:

- Implementation callback lease batch was taken for the 16 accepted by-* docs immediately before edits.
- `unlease` after validation reported `Rejected[No active lease]` for each path because the short leases had already expired during the edit/validator batch.
- A fresh single-file lease was then taken for `by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md` for the post-scan wording correction, validator `000000002949`, and final generated wait `000000002950`; that lease released successfully.
- Current lease report after cleanup shows no active Agent-B007 leases.

Validators:

- See callback validator table above. All scoped validators and the final `--wait-generated` validator exited `0` with `ok:1`.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Applied after supervisor callback accepted the report for implementation.
- [x] Update `by-file/OptionPane.md`: root score `91/85 -> 92/88`, record the 15-empty-emitter cleanup plan, current MCP session evidence, and generated freshness expectation. Proof: metadata and `2026-06-30 B007 Empty-Emitter Cleanup Implementation`; validators `000000002947`/`000000002948`.
- [x] Update `by-class/NewOptionPane.md`: score `86/87 -> 87/89`, insert formal `[[CHILDREN]]`, preserve child/helper caveats. Proof: formal block and change note; validator `000000002932`.
- [x] Update `by-class/OptionPane.md`: score `86/87 -> 87/88`, insert formal `[[CHILDREN]]`, preserve old class split caveats. Proof: formal block and change note; validator `000000002933`.
- [x] Update [UID:0001DW] `by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md`: score `86/86 -> 87/88`, insert formal `[[CHILDREN]]`, add exact split plan or implement same-callback children if accepted. Proof: formal block plus `Future Child Split Plan`; validator `000000002934`.
- [x] If supervisor accepts split creation, create validator-assigned child UID pages for every [UID:0001DW] proposed range using TMP reference/validator UID workflow; do not invent UIDs manually. Excluded: supervisor callback explicitly said do not create proposed new child pages in this callback; split plan documented as future work.
- [x] Update [UID:0003NN]: score `85/88 -> 88/90`, insert exact `NewOptionPane::OnServerOptionError` formal C++. Proof: formal block; validator `000000002935`.
- [x] Update [UID:0003NP]: score `85/88 -> 86/89`, insert exact formal no-code proof comment. Proof: formal block; validator `000000002936`.
- [x] Update [UID:0003NQ]: score `86/89 -> 87/90`, insert exact formal no-code proof comment. Proof: formal block; validator `000000002937`.
- [x] Update [UID:0003NR]: score `85/88 -> 86/89`, insert exact formal no-code proof comment. Proof: formal block; validator `000000002938`.
- [x] Update [UID:00035B]: score `87/90 -> 88/92`, set `RECONSTRUCTABLE:FALSE`, clear `EMITTER_UIDS`, document compiler RTTI/vtable boundary no-code proof. Proof: metadata/rationale; validator `000000002939`.
- [x] Update [UID:0000TL]: score `87/90 -> 88/91`, set `RECONSTRUCTABLE:FALSE`, clear `EMITTER_UIDS`, document alias/index relationship to [UID:0001DY]. Proof: metadata/rationale; validator `000000002940`.
- [x] Update [UID:0001DY]: score `87/90 -> 89/91`, insert exact `SendOptionPacket11B` formal C++. Proof: formal block; validator `000000002941`.
- [x] Update [UID:0003NS]: score `85/88 -> 88/90`, insert exact `SendLowHighDisplayModeOption` formal C++ and mark field names inferred. Proof: formal block and reconstruction note; validator `000000002942`.
- [x] Update [UID:0001DZ]: score `85/88 -> 88/90`, insert exact `DrawOptionPaneSectionHeader` formal C++ and mark name inferred. Proof: formal block and reconstruction note; validator `000000002943`.
- [x] Update [UID:0001E0]: score `85/88 -> 88/90`, insert exact `DrawOptionPaneButtonItem` formal C++ and mark helper/type names inferred. Proof: formal block and score rationale; validator `000000002944`.
- [x] Update [UID:00027W]: score `87/86 -> 87/88`, insert exact formal no-code proof comment; do not force `uint16_t[2][5]` declaration. Proof: formal block and no-declaration wording; validator `000000002945`.
- [x] Update [UID:0002ZC]: score `88/93 -> 90/94`, insert exact `kOptionPaneDialogResourceName` formal declaration. Proof: formal block; validator `000000002946`.
- [x] Preserve negative evidence: no xrefs to `0x00540ef0`, `0x00540f50`, `0x00540ff0`; [UID:0001DY] has two `SelfLookPane` callers; [UID:00035B] is compiler boundary data; [UID:00027W] has no tail refs/table reader. Proof: preserved in relevant pages' evidence/reconstruction notes and 2026-06-30 change notes.
- [x] Run scoped validators for every changed target/support by-* file and every new child file if split creation is accepted. Proof: validators `000000002932` through `000000002947`; no new child files created by supervisor instruction.
- [x] Run final `by-file/OptionPane.md --wait-generated` validator and record generated `OptionPane.cpp` header freshness. Proof: final validator `000000002950`, `generated_refresh: completed`; generated file inspected, content has accepted cleanup, header is current at command id `000000002950`.
- [x] Do not edit generated reports, generated C++, manual coverage reports, validator state, queue/lock files, IDA DB, supervisor ledgers, or unrelated docs. Proof: no manual edits to excluded files; generated/project-level/tool state changes were validator-driven side effects only.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: callback prompt accepted this report and named implementation scope.
- [x] Take only immediate edit leases for accepted target/support files, then release them after edit/validator batch. Proof: initial lease batch succeeded before edits and had expired by cleanup; a follow-up single-file lease for [UID:0001DW] was released successfully; current lease report has no active B007 rows.
- [x] Apply accepted details at report-level factual detail. Proof: target/support docs now contain accepted behavior, xrefs, no-route proof, score rationale, owner/emitter decisions, rejected alternatives, inferred-name caveats, formal C++/markers, and split plan.
- [x] Update this checklist and Claim And Incorporation Ledger with applied/excluded proof. Proof: this callback section and ledger states updated.
- [x] Record validators with command id, timestamp, exit code, ok count, warnings, and generated refresh state. Proof: callback validator table above.
- [x] Confirm no active Agent-B007 leases remain. Proof: post-cleanup current lease report has no B007 rows; only stale Supervisor rows from 2026-06-18 are listed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0000M7-OptionPane-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0000M7-OptionPane-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T14:49:21","uid":"0000M7"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000M7-OptionPane-empty-emitter-family-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/0000M7-OptionPane-empty-emitter-family-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000M7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
