*** UID:0000LB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# MessageShowPane

## Status

- Confidence: very strong for the standalone reconstruction grouping, source/header contract, generated order, exact class/method/global inventory, dependencies, and compiler exclusions.
- Proposed module folder: `ui/dialogs/`
- Proposed source file: `ui/dialogs/MessageShowPane.cpp`
- Generated lead material: `class_MessageShowPane.cpp`; older generated/cache evidence attached `0x00522530` to `class_FittingRoomDownloadControlPane.cpp`. Those are historical leads only; current IDA xrefs and exact by-memory pages are authoritative.
- Evidence basis: IDA MCP boundary/xref/decompilation checks on 2026-05-24 through 2026-05-31, plus a 2026-06-14 C001 xref/boundary refresh. `simroot_v2`, Wave3 cache indexes, and older Wave2 rename/report data are lead/history sources only.

## Hypothesis

`MessageShowPane` is reconstructed as a small standalone overlay source module rather than part of the packet-driven NPC/menu-question dialog file. It owns the active floating message pane singleton, wraps wide text to a fixed 288-pixel width, positions the pane near the right edge of the play area, and paints layered shadow/face text rows.

Likely structure:

```text
ui/dialogs/MessageShowPane.cpp
```

Historical alternate considered and rejected for current reconstruction:

```text
ui/dialogs/MessageDialogs.cpp
```

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| [UID:000087][MessageShowPane](by-class/MessageShowPane.md) | Non-emitting container [UID:0002Y8][0x00521da0-0x005227c6.MessageShowPaneMethods](by-memory/0x00521da0-0x005227c6.MessageShowPaneMethods.md); exact source children [UID:0004HN][0x00521da0-0x00521fc0.MessageShowPaneConstructor](by-memory/0x00521da0-0x00521fc0.MessageShowPaneConstructor.md), [UID:000492][0x00521fc0-0x00522025.MessageShowPaneDestructor](by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md), [UID:0004HO][0x00522030-0x00522530.MessageShowPaneOnPaint](by-memory/0x00522030-0x00522530.MessageShowPaneOnPaint.md), and [UID:0001C4][0x00522530-0x005226ea.MessageShowPaneSetWrappedText](by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md); corrected vtable data [UID:0003PC][0x0061fa48-0x0061fad0.MessageShowPaneVtableData](by-memory/0x0061fa48-0x0061fad0.MessageShowPaneVtableData.md); singleton docs UID0000RK/UID0001PX; compiler support UID0001C5/UID0001C6/UID0001C7 | `MessageShowPane.cpp` | Complete Pane plus Singleton class, exact source methods, external singleton, and compiler-only ABI support. |
| [UID:0000RK][g_pMessageShowPane](by-global/g_pMessageShowPane.md) | [UID:0001PX][0x0069b4f4-0x0069b4f8.g_pMessageShowPane](by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md) | `class_MessageShowPane.cpp` global-data alias | Active message overlay singleton. |
| [UID:0003UU][0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket](by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md) | `0x005ac070-0x005ac1a8` | external local-player packet helper under [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) | Server opcode `0x58` consumer that creates, updates, or closes the active message overlay. It depends on this file's class/singleton methods but is not currently a `MessageShowPane.cpp` source body. |
| MessageShow read-only data | [UID:00025V][0x0061fa3c-0x0061fafc.MessageShowReadOnlyData](by-memory/0x0061fa3c-0x0061fafc.MessageShowReadOnlyData.md) | `.rdata` vtables/string data | Message and MessageShowPane vtables, including the primary, secondary, and tertiary MessageShowPane tables that reference the destructor/thunk cluster. |

## Behavior Model

- [UID:0004HN][0x00521da0-0x00521fc0.MessageShowPaneConstructor](by-memory/0x00521da0-0x00521fc0.MessageShowPaneConstructor.md) invokes Pane and `Singleton<MessageShowPane>` bases, copies the wide buffer at `+0xf8`, counts newline-delimited lines, measures with `GetTextWidth`, clamps to 288 pixels, builds `RectBounds`, and attaches to `g_pRenderLayer1`.
- [UID:000492][0x00521fc0-0x00522025.MessageShowPaneDestructor](by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md) authors only `RemoveFromLayer()`; Singleton clear, vptr restores, and Pane destruction are implicit/compiler-generated.
- [UID:0004HO][0x00522030-0x00522530.MessageShowPaneOnPaint](by-memory/0x00522030-0x00522530.MessageShowPaneOnPaint.md) is the vtable-only OnPaint override: background fill, six color-143 shadow passes, and two color-128 face passes with exact cumulative offsets.
- [UID:0001C4][0x00522530-0x005226ea.MessageShowPaneSetWrappedText](by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md) replaces stored text, recomputes metrics, reapplies RectBounds, and invalidates inherited `m_visibleBounds`.
- External packet helper [UID:0003UU][0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket](by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md) reads opcode `0x58` payload `payload[1]` as the on/off flag, copies the byte-counted narrow text at `payload+4` after a BE16 length at `payload+2`, converts through `MultiByteToWideChar(CP_ACP,0,...)`, updates the existing `g_pMessageShowPane` via `0x00522530`, allocates/constructs a new `MessageShowPane` when no overlay exists, or deletes the current overlay when the flag is zero.

## Boundary Notes

- Current exact `.rdata` partition is Message UID0003PB `[0x0061fa3c,0x0061fa48)`, MessageShowPane UID0003PC `[0x0061fa48,0x0061fad0)`, MetaMan UID0004SS `[0x0061fad0,0x0061fadc)`, then `Meta.dat` at `0x0061fadc`.
- IDA confirms normal function starts at `0x00521da0`, `0x00521fc0`, `0x00522030`, `0x00522530`, `0x005226f0`, `0x005226fb`, `0x00522706`, and `0x00522720`.
- `0x00522530-0x005226ea` was historically owned by `FittingRoomDownloadControlPane` in Wave2/Wave3-derived data; generated lead material places it under `MessageShowPane`. IDA xrefs, not generated ownership, prove the only direct caller is the message overlay packet handler at `0x005ac150`; its data layout and singleton flow are `MessageShowPane`-specific.
- [UID:0001C5][0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH](by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md) is a tiny constructor EH singleton-clear helper, referenced by the constructor's exception/unwind path. It is documented and ignored as standalone source.
- [UID:0001C6][0x005226fb-0x00522711.MessageShowPaneAdjustorThunks](by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md) are compiler-generated destructor adjustor thunks into generated scalar wrapper [UID:0001C7][0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor](by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md). The source destructor body is [UID:000492][0x00521fc0-0x00522025.MessageShowPaneDestructor](by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md).
- Wave3/generated attribution alone is rejected for `g_applyMessagePaneBorder`: current OnPaint evidence maps the calls to inherited GrafPort/RectBounds drawing and shows `0x0069b3fc` is a broad UI dependency, not a MessageShowPane-owned source global.
- Rename registry evidence conflicts on `0x0069b4f4`: an older row names it `g_pMessageShowPane`, while a later map row aliases `DAT_0069b4f4` to `g_pExtendedUIPane`. The direct constructor/destructor/update xrefs support `g_pMessageShowPane` for this use.
- 2026-05-31 live IDA MCP recheck of UID0001PX confirms constructor publication, ordinary reverse clear, EH/scalar duplicate clears, packet-handler reads, and broad UI cleanup. The current UID0003PC pass closes the reconstruction source route as standalone MessageShowPane.cpp.
- 2026-06-07 A010 Batch044 rechecked the immediate surrounding singleton group from `0x0069b4c8-0x0069b4f8`. The prior slot is the exact [UID:00029Z][0x0069b4f0-0x0069b4f4.RightButtonMenuPaneSingleton](by-memory/0x0069b4f0-0x0069b4f4.RightButtonMenuPaneSingleton.md), the successor is [UID:0001PY][0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane](by-memory/0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane.md), and the refreshed `g_pMessageShowPane` xrefs remain exclusive to MessageShowPane lifecycle plus packet/UI cleanup consumers. This reduces the historical `g_pExtendedUIPane` alias risk enough for the file-root confidence gate, while the final compact-source split remains open.
- UID00025V/UID0003PC and destructor/adjustor/scalar children tie the exact compiler tables to the overlay class lifecycle. The absence of an original source-path string caps confidence below 95 but no longer blocks the standalone reconstruction route.
- 2026-06-14 C001 live IDA MCP rechecked the overlay boundaries and xrefs: `lookup_funcs` reports the constructor `0x00521da0` size `0x220`, destructor `0x00521fc0` size `0x65`, text-row builder `0x00522030` size `0x500`, [UID:0001C4][0x00522530-0x005226ea.MessageShowPaneSetWrappedText](by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md) as `0x1ba`, three `0xb` EH/adjustor helpers at `0x005226f0`, `0x005226fb`, and `0x00522706`, scalar deleting destructor `0x00522720` size `0xa6`, and packet handler `0x005ac070` size `0x138`.
- The same C001 pass confirms `xrefs_to 0x00522530` has the one packet-handler caller at `0x005ac150`, `xrefs_to 0x00522720` has adjustor-thunk references plus the vtable data reference at `0x0061fa4c`, and `xrefs_to 0x0069b4f4` still has the eight lifecycle/packet/UI cleanup references recorded by the singleton pages.
- 2026-06-21 B011 source-quality recheck keeps [UID:0003UU][0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket](by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md) as an external packet-handler helper rather than this file's canonical body. It is reached only from `UserPane::OnServerMessage` case `0x58` at `0x005a8172`, takes a packet pointer, ignores the caller-seeded `ecx`, and sits in the local-player packet-helper neighborhood; this page should preserve it as dependency evidence for constructor, `SetWrappedText`, scalar deletion, and `g_pMessageShowPane`.
- 2026-06-27 B008 implementation callback resolved the destructor support split: [UID:000492][0x00521fc0-0x00522025.MessageShowPaneDestructor](by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md) carries the source `MessageShowPane::~MessageShowPane()` body, [UID:0001C7][0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor](by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md) is generated scalar deleting destructor glue, and [UID:0001C5][0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH](by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md)/[UID:0001C6][0x005226fb-0x00522711.MessageShowPaneAdjustorThunks](by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md) remain generated support.
- 2026-07-06 B004 split constructor and the then-named text-row builder into exact source children. The current callback supersedes only the source-facing identity/helper model: UID0004HO is OnPaint, standalone MessageShowPane.cpp is selected, and `0x0069b3fc` remains a broad UI dependency.

## Current Source Contract

- Source root: `NexusTK/ui/dialogs/MessageShowPane.cpp`.
- Header-facing declarations: forward declaration of `MessageShowPane`, external `g_pMessageShowPane`, complete Pane plus `Singleton<MessageShowPane>` class declaration, and method declarations.
- Generated source order:
  - UID0000RK singleton definition at position `0`.
  - UID000087 complete class declaration at position `10`.
  - UID0004HN constructor at position `20`.
  - UID000492 destructor at position `30`.
  - UID0004HO OnPaint at position `40`.
  - UID0001C4 SetWrappedText at position `50`.
- External dependency UID0003UU remains in LivingObjectPane.cpp and consumes the header-visible class/global API.
- Compiler exclusions: no handwritten RTTI/vtable arrays, vptr stores, Singleton publication/clear, constructor EH cleanup, destructor adjustors, scalar deleting wrapper, delete flags, size guard, storage free, cookies, or explicit Pane/Singleton destructor calls.
- Non-emitting exact storage UID0001PX and compiler pages UID0003PC/UID0001C5/UID0001C6/UID0001C7 must not duplicate source.
- Historical `MessageDialogs.cpp`, `FittingRoomDownloadControlPane`, `BuildMessageTextButtons`, child-button helpers, PaneRect, MeasureTextWidth, `m_bounds`, and `g_pExtendedUIPane` are retained only as superseded provenance.

## Migration Notes

Historical Wave3 planning commands are retained below for provenance only. They are not source evidence and must not be run for this batch; future migration work must recheck command spelling, EH/thunk handling, and the alias caveats before making any real or simulated migration call.

```powershell
python source-3\wave3.py create file MessageShowPane.cpp --kind source --simpath ui/dialogs/MessageShowPane.cpp --dry-run
python source-3\wave3.py attach class MessageShowPane --to-file MessageShowPane.cpp --dry-run
python source-3\wave3.py attach method 0x00522530 --to-file MessageShowPane.cpp --dry-run
python source-3\wave3.py set global-data-owner g_pMessageShowPane MessageShowPane.cpp --dry-run
```

Verify the exact Wave3 command spelling for attaching methods before any real migration.

## Cross-References

- [UID:000087][MessageShowPane](by-class/MessageShowPane.md)
- [UID:0001C3][0x00520e30-0x005227c6.MessageAndMessageShowPane](by-memory/0x00520e30-0x005227c6.MessageAndMessageShowPane.md)
- [UID:0002Y8][0x00521da0-0x005227c6.MessageShowPaneMethods](by-memory/0x00521da0-0x005227c6.MessageShowPaneMethods.md)
- [UID:0004HN][0x00521da0-0x00521fc0.MessageShowPaneConstructor](by-memory/0x00521da0-0x00521fc0.MessageShowPaneConstructor.md)
- [UID:0004HO][0x00522030-0x00522530.MessageShowPaneOnPaint](by-memory/0x00522030-0x00522530.MessageShowPaneOnPaint.md)
- [UID:0001C4][0x00522530-0x005226ea.MessageShowPaneSetWrappedText](by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md)
- [UID:0001C5][0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH](by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md)
- [UID:0001C6][0x005226fb-0x00522711.MessageShowPaneAdjustorThunks](by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md)
- [UID:000492][0x00521fc0-0x00522025.MessageShowPaneDestructor](by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md)
- [UID:0001C7][0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor](by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md)
- [UID:00025V][0x0061fa3c-0x0061fafc.MessageShowReadOnlyData](by-memory/0x0061fa3c-0x0061fafc.MessageShowReadOnlyData.md)
- [UID:0000RK][g_pMessageShowPane](by-global/g_pMessageShowPane.md)
- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:0001KM][0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md)

## Changes

- 2026-07-16 B002 UID0003PC implementation callback:
  - Raised `86/87` to `92/93` while retaining `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` and `CANONICAL_OWNER:FILE`.
  - Closed the standalone source route, exact global/class/method order, header extern route, Pane plus Singleton inheritance, corrected OnPaint identity, exact `.rdata` split including UID0004SS, packet dependency, one-definition policy, and compiler exclusions.
  - Preserved and historicalized all prior compact-MessageDialogs, FittingRoom, generated helper, alias, and migration evidence. No by-file reconstruction metadata was added.
- 2026-07-06 B004 implementation callback:
  - Added exact source children [UID:0004HN][0x00521da0-0x00521fc0.MessageShowPaneConstructor](by-memory/0x00521da0-0x00521fc0.MessageShowPaneConstructor.md) and [UID:0004HO][0x00522030-0x00522530.MessageShowPaneOnPaint](by-memory/0x00522030-0x00522530.MessageShowPaneOnPaint.md) to the proposed contents and behavior model.
  - Reworded [UID:0002Y8][0x00521da0-0x005227c6.MessageShowPaneMethods](by-memory/0x00521da0-0x005227c6.MessageShowPaneMethods.md) as a non-emitting method-cluster container rather than a method source body.
  - Preserved [UID:0003UU][0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket](by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md) as external packet-helper dependency, `MessageShowPane.cpp` as best current placement, compact `MessageDialogs.cpp` as caveat, and `0x0069b3fc` as a broad UI callback/table dependency.
- 2026-06-27 B008 implementation callback:
  - Added [UID:000492][0x00521fc0-0x00522025.MessageShowPaneDestructor](by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md) as the ordinary destructor source body and reworded [UID:0001C7][0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor](by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md) as generated scalar-deleting destructor support alongside the EH helper and adjustor thunks.
  - Evidence: live IDA/MCP confirmed exact destructor and wrapper boundaries, singleton clears, vtable references, and scalar-delete flag behavior.
- 2026-06-21 Rule 26 support sync from B011 [UID:0003UU][0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket](by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md):
  - Updated `HandleMessageShowPacket` from generic outside handler to external opcode `0x58` local-player packet-helper consumer of `MessageShowPane`.
  - Preserved the owner boundary: `MessageShowPane.cpp` owns the overlay class, singleton, constructor/destructor, and `SetWrappedText`; [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) owns the packet helper under current evidence.
- 2026-06-14 C001 Goal 2 by-file score refresh:
  - Before: `COMPLETION:85`, `CONFIDENCE:85`.
  - After: `COMPLETION:86`, `CONFIDENCE:87`.
  - Summary/evidence: live IDA MCP reconfirmed the overlay constructor/destructor/update/destructor-thunk/packet-handler boundaries, the single packet-handler caller for `SetWrappedText`, the scalar-deleting destructor's thunk/vtable references, and the eight `g_pMessageShowPane` lifecycle/packet/UI cleanup xrefs. Scores remain below final-audit quality because the compact `MessageDialogs.cpp` versus standalone `MessageShowPane.cpp` split and small read-only string-fragment naming are still open. No owner/emitter, path, or C++ reconstruction change was made.
- 2026-06-06 A008 parent-gate pass:
  - Before: the page had a valid projected path but stayed `84/78`, leaving class and destructor autogen children unable to resolve through a source-root chain.
  - After: changed completion/confidence to `85/80`, added the MessageShow read-only/vtable data to proposed contents and evidence notes, and kept the final `MessageShowPane.cpp` versus `MessageDialogs.cpp` caveat explicit.
  - Evidence: [UID:000087][MessageShowPane](by-class/MessageShowPane.md), [UID:0001C4][0x00522530-0x005226ea.MessageShowPaneSetWrappedText](by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md), [UID:0001C7][0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor](by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md), [UID:00025V][0x0061fa3c-0x0061fafc.MessageShowReadOnlyData](by-memory/0x0061fa3c-0x0061fafc.MessageShowReadOnlyData.md), and [UID:0001PX][0x0069b4f4-0x0069b4f8.g_pMessageShowPane](by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md) provide exact overlay lifecycle, vtable, singleton, and packet-handler evidence.
- 2026-06-07 A010 Batch044 parent-gate update:
  - Before: `85/80`; the file had enough completion but confidence stayed below the corrected gate because the historical `g_pExtendedUIPane` alias and surrounding singleton group had not been refreshed.
  - After: `85/85`; added surrounding-slot boundary evidence and refreshed `g_pMessageShowPane` xrefs. This supports [UID:0001PX][0x0069b4f4-0x0069b4f8.g_pMessageShowPane](by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md) assignment through [UID:0000RK][g_pMessageShowPane](by-global/g_pMessageShowPane.md); final `MessageShowPane.cpp` versus compact `MessageDialogs.cpp` remains open.
- 2026-06-05 projected-path assignment:
  - Before: the path stayed blank because the final split between `MessageShowPane.cpp` and `MessageDialogs.cpp` was still open.
  - After: set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/ui/dialogs/`, matching the documented proposed folder while preserving the caveat that `MessageShowPane.cpp` versus a compact `MessageDialogs.cpp` split still needs final audit.
  - Summary/evidence: live IDA MCP `lookup_funcs` confirms the overlay cluster at `0x00520e30`, `0x00522530`, and `0x00522720`; `callers` again ties `0x00522530` to the message overlay packet/update path at `0x005ac150`, supporting a dialog-layer source root rather than leaving file coverage in error.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Summary/evidence: the page has detailed class/global/range ownership, packet-handler behavior, boundary notes, migration notes, and cross-references; confidence remains below strong-high because the final original source split between `MessageShowPane.cpp` and `MessageDialogs.cpp` is still open.
- 2026-05-31 evidence-basis correction:
  - What existed before: the status line mixed generated `simroot_v2`/Wave3/Wave2 leads with IDA checks as if they were comparable evidence.
  - Changed to: IDA MCP is explicitly listed as the authority, while generated/cache/rename data is marked as lead/history only.
  - Summary/evidence: live IDA MCP rechecked the singleton slot and class lifecycle xrefs on 2026-05-31; the final source-file split remained open at that time.
