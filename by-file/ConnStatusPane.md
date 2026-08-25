*** UID:0000IF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ConnStatusPane

## Accepted Whole-File Closure - 2026-08-22

- Canonical standalone unit is `NexusTK/network/ConnStatusPane.cpp` with required paired `ConnStatusPane.h`; [UID:000037][ConnStatusPane](by-class/ConnStatusPane.md) owns the exact CPP include/specialization preamble and complete H declaration.
- Source order is class preamble, [UID:0002B9][0x0069adf4-0x0069adf8.g_pConnStatusPane](by-memory/0x0069adf4-0x0069adf8.g_pConnStatusPane.md) definition at child position `10`, then [UID:000113][0x00494520-0x004949df.ConnStatusPane](by-memory/0x00494520-0x004949df.ConnStatusPane.md) at position `20`. Compiler vtable/RTTI/resource pages emit blank fragments.
- Source placement is settled as `network/`. Earlier `ui/status` discussion is rejected historical tree-organization speculation: packet/timing/config/singleton behavior and the established path outweigh visual-pane consumption.
- The unit is reconstructable with exact signed `0x128` class layout, six authored methods, external singleton, three vtable views, exhaustive record-level RTTI, class-local `CONNSTAT.EPD`, and shared external rendering/resource dependencies.
- UID0000IF C138/C139 direct-header prerequisites are implemented. `StringUtil.h` now emits one guarded, placeholder-free ordered SimpleUString/SimpleUStringVector/StringIter/extern union; `Config.h` directly includes it before the by-value vector member and has no vector forward declaration; `TimerMgr.h` now owns one guarded, placeholder-free declaration union with unchanged public `DWORD m_currentTick`. These dependency repairs preserve ConnStatusPane behavior/source and close compilation readiness without moving ownership.

## Exact 96-Row Reconciliation

| Inventory class | Count | Complete disposition |
| --- | ---: | --- |
| Physical code rows | 17 | Six authored definitions, six alignment spans, two switch tables, two destructor adjustors, and one scalar deleting destructor, all exact on UID000113. |
| Compiler vtable cells | 34 | Three COL pointers plus 31 slots: primary UID00035G contains one COL/18 slots; cross-index UID000569 contains two COLs/13 slots. |
| Physical RTTI records | 17 | Two class-local TypeDescriptors; three class-local COLs; two CHDs; two BCAs; three class-local/self/direct BCDs; five individually excluded shared base BCDs. |
| Resource/data/global rows | 4 | Class-local `CONNSTAT.EPD`; two-byte following alignment; shared external `NPAL7.PAL`; external singleton storage. |
| Type/layout rows | 2 | Exact inheritance hierarchy and exact signed `0x128` layout. |
| Documentation/generated-route rows | 22 | Target, class, method, singleton, compiler-data children, two aggregate indexes, two callers, Surface/resource support, generated CPP/H route, C138 Config/StringUtil complete-type route, and C139 TimerMgr direct-header route. |
| Total | 96 | Every row has a source, compiler, no-code, external, or documentation disposition; no catch-all binary row remains. |

### Code And Compiler Rows

| Exact range | Current disposition |
| --- | --- |
| `[0x494520,0x4945e0)` | Authored constructor. |
| `[0x4945e0,0x494609)` | Authored ordinary destructor. |
| `[0x494609,0x494610)` | Seven-byte alignment, no source. |
| `[0x494610,0x49461f)` | Authored no-xref `CaptureLatencyStartTick`; retained because it writes the consumed pending-tick field. |
| `[0x49461f,0x494620)` | One-byte alignment. |
| `[0x494620,0x4946b1)` | Authored `OnPaint`. |
| `[0x4946b1,0x4946c0)` | Fifteen-byte alignment. |
| `[0x4946c0,0x494765)` | Authored `HandlePacketEvent`. |
| `[0x494765,0x494768)` | Three-byte switch alignment. |
| `[0x494768,0x494770)` | Compiler jump table from packet switch. |
| `[0x494770,0x494793)` | Compiler index table from packet switch. |
| `[0x494793,0x4947a0)` | Thirteen-byte alignment. |
| `[0x4947a0,0x494964)` | Authored `UpdateConnectionFrame`. |
| `[0x494964,0x49496f)` | Compiler A0 destructor adjustor. |
| `[0x49496f,0x49497a)` | Compiler A4 destructor adjustor. |
| `[0x49497a,0x494980)` | Six-byte alignment. |
| `[0x494980,0x4949df)` | Compiler scalar deleting destructor. |

### Exact Data Children

- [UID:00035G][0x006179e8-0x00617a34.ConnStatusPanePrimaryVtableData](by-memory/0x006179e8-0x00617a34.ConnStatusPanePrimaryVtableData.md): raw primary COL pointer plus 18 slots; ends before the secondary COL.
- [UID:000569][0x00617a34-0x00617a70.ConnStatusPaneAdjustedVtableData](by-memory/0x00617a34-0x00617a70.ConnStatusPaneAdjustedVtableData.md): two COL pointers plus 13 adjusted slots; independent class-owned sibling crossing the UID000251/UID000252 boundary at `0x617a38`.
- [UID:00056A][0x00617a70-0x00617a8a.ConnStatusPaneResourceStringData](by-memory/0x00617a70-0x00617a8a.ConnStatusPaneResourceStringData.md): exact 26-byte UTF-16 `CONNSTAT.EPD` object emitted by OnPaint's source expression; following `[0x617a8a,0x617a8c)` is compiler alignment indexed by UID000252.
- [UID:000567][0x006457f8-0x006458d0.ConnStatusPaneRttiHierarchyData](by-memory/0x006457f8-0x006458d0.ConnStatusPaneRttiHierarchyData.md): primary/secondary/tertiary COLs, both CHDs/BCAs, class/Singleton BCDs, and five exact shared-base exclusions.
- [UID:000568][0x00675738-0x00675784.ConnStatusPaneTypeDescriptorData](by-memory/0x00675738-0x00675784.ConnStatusPaneTypeDescriptorData.md): exact adjacent ConnStatusPane and Singleton TypeDescriptors.

### Source And Dependency Closure

- Exact layout after Pane's `0xf8` prefix is signed `int[10] +0xf8`, signed `int +0x120`, `short +0x124`, then two tail-pad bytes. Direct RTTI bases are Pane and `Singleton<ConnStatusPane>`; inherited facets expose EventHandler at `+0xa0` and TimerHandler at `+0xa4`.
- Sole construction allocates `0x128` at `0x004f87cc` and calls `0x494520` at `0x004f87ec` in both [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) and [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md).
- External support remains with established owners: `g_pfnFillRect` under [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md), shared `NPAL7.PAL` under [UID:0001RD][iconspane-icon-resources](by-resource/iconspane-icon-resources.md), complete guarded TimerMgr plus public `m_currentTick` under [UID:0000F1][TimerMgr](by-class/TimerMgr.md), and complete Config/StringUtil/Event/ImageLib/GrafPort/MapPane/Pane/Singleton contracts under their existing docs. C138/C139 change dependency visibility/framing only, not ConnStatus ownership or emitted method text.
- Broad UID000251/UID000252 pages remain ownerless non-emitting indexes. They link the crossing UID000569 sibling from both sides without false containment; only UID000252 wholly contains UID00056A and the following two-byte alignment.

## Generated Output Audit

- Historical pre-callback receipt command `000000026955` observed an incomplete 4,406-byte CPP and absent required H. That dated state is not current authority after this accepted callback.
- Generated files are validator-owned. Every callback command, header, hash, byte-size, line-count, and semantic receipt is dated historical evidence only, never permanent current authority. Every later gate must physically reread the then-current generated CPP/H headers, command IDs, hashes, sizes, line counts, and semantic inventory before relying on generated output.
- Required CPP shape is one include/specialization preamble, one singleton definition, six authored methods, no handwritten destructor wrappers/vtables/RTTI, and no C++11/decompiler placeholders. Required H shape is the exact complete class, extern singleton, signed fields, and `0x128` size assertion.
- C138 generated proof passed at command `000000027417`: `StringUtil.h` has one guard pair, zero placeholders, and exact declaration order SimpleUString -> SimpleUStringVector -> StringIter -> extern; vector and iterator children are namespace-scope CPP definitions. Config proof passed at command `000000027421`: one direct `StringUtil.h` include precedes the exact by-value member and zero vector forward declarations remain. C139 proof passed at command `000000027425`: `TimerMgr.h` has one guard pair, zero placeholders, each declaration once in preserved order, and unchanged public `DWORD m_currentTick`.
- Final ConnStatusPane proof remains semantic rather than ownership-changing: the regenerated CPP/H must preserve the exact required shapes above after the owning scoped validator, and each later supervisor gate must reread that then-current output rather than treating these callback command IDs as permanent authority.

## Current Score Rationale

- Completion `93`: exact 96-row whole-unit inventory, canonical source/header route, source order, signed layout, compiler/data children, complete direct dependency headers, and generated-output contract are closed. C138/C139 ordinary implementation and physical generated proof are complete; the score remains below 100 for stripped private spelling and because supervisor Gate 2A/2B are separate authority.
- Confidence `95`: code, callers, field accesses, vptrs, physical RTTI, resources, singleton lifecycle, and current formal source converge. Remaining uncertainty is only stripped private original spelling.

## Historical Status

The sections below preserve earlier research chronology. The accepted 96-row whole-file/direct-header closure above supersedes old scores, provisional placement, incomplete inventory, stale generated-currentness, pre-split boundary statements, and the temporary C138/C139 compilation-readiness block.

- Confidence: strong for the core `ConnStatusPane` class, singleton/vtable evidence, latency/status field roles, and first-draft source shape.
- Proposed module folder: `network/`
- Proposed source file: `network/ConnStatusPane.cpp`
- Evidence basis: live IDA MCP/disassembly boundary, vtable, singleton, caller, paint/message/update, and destructor checks, refreshed by Agent-C001 against the 2026-06-14 IDA 9.1 MCP session.

## Historical Hypothesis

`ConnStatusPane` is the in-game connection-status indicator. It samples request/response timing, maps latency to a `CONNSTAT.EPD` frame, paints the frame with `NPAL7.PAL`, and reacts to selected server-message opcodes to update connection/parcel-notification state.

The class is game-network UI rather than generic pane core. A practical source placement is:

```text
network/ConnStatusPane.cpp
network/ConnStatusPane.h
```

The active source placement is `NexusTK/network/ConnStatusPane.cpp`. Although the class paints a UI indicator, its class-local behavior is connection-message handling, latency sampling, map/config-gated status display, and the `g_pConnStatusPane` network/status singleton. A future tree-level `ui/status` split is possible, but it is no longer a blocker for this target or its first-draft C++.

## Historical Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `ConnStatusPane` | `0x00494520-0x004949df` | `ConnStatusPane.cpp` | Constructor, ordinary destructor, private TimerMgr latency-start helper, paint, connection-message handler, latency-frame update, and compiler-generated destructor adjustor/scalar family. |
| `ConnStatusPanePrimaryVtableData` | `0x006179ec-0x00617a38` | `ConnStatusPane.cpp` | Primary vtable emitted by the `ConnStatusPane` declaration; exact child [UID:00035G][0x006179e8-0x00617a34.ConnStatusPanePrimaryVtableData](by-memory/0x006179e8-0x00617a34.ConnStatusPanePrimaryVtableData.md) now attaches to the class. |
| Inherited Pane/EventHandler bridge/default slots | `0x00544db0-0x00544dd9` | `Pane.cpp` | Shared base-pane virtual wrappers reused by many vtables, including `ConnStatusPane`; historical `SetConnecting` / `SetDisconnected` / `SetConnected` labels are aliases, not class-local source. |
| `g_pConnStatusPane` | `0x0069adf4` | `ConnStatusPane.cpp` | Singleton pointer for the active status pane. |

## Historical Generated Output Note

Current generated output is populated, not zero-byte. B003 observed `project-documentation/auto-generated/NexusTK/network/ConnStatusPane.cpp` at `validator-command-id: 000000007318`, `validator-refreshed-at: 2026-07-05T18:48:04-04:00`: it contained [UID:000113][0x00494520-0x004949df.ConnStatusPane](by-memory/0x00494520-0x004949df.ConnStatusPane.md) method code that references `g_pConnStatusPane`, while [UID:0002B9][0x0069adf4-0x0069adf8.g_pConnStatusPane](by-memory/0x0069adf4-0x0069adf8.g_pConnStatusPane.md) still appeared as an empty marker until the singleton storage declaration was added to its formal block. The storage definition belongs in `ConnStatusPane.cpp` as `ConnStatusPane *g_pConnStatusPane;` with external linkage, not file-local `static`, because [UID:0002QH][0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown](by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md) emits through `MapPane.cpp` and reads the same slot at `0x00504a32`. Generated C++ remains validator-owned output and should be checked by header command id/freshness after scoped validation rather than edited by hand.

## Historical Boundary Notes

- Live IDA on 2026-06-04 used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- IDA confirms local functions at `0x00494520-0x004945e0`, `0x004945e0-0x00494609`, `0x00494610-0x0049461f`, `0x00494620-0x004946b1`, `0x004946c0-0x00494765`, `0x004947a0-0x00494964`, `0x00494964-0x0049496f`, `0x0049496f-0x0049497a`, and `0x00494980-0x004949df`.
- `0x004f87ec` inside `0x004f7d10` is the sole constructor caller, matching main UI graph setup.
- Constructor and destructor paths write `g_pConnStatusPane` at `0x0069adf4`; another live xref reads it at `0x00504a32`.
- Constructor/vtable-reset/destructor stores use primary vtable `0x006179ec`, secondary vtable `0x00617a38`, and tertiary vtable `0x00617a68`.
- [UID:00035G][0x006179e8-0x00617a34.ConnStatusPanePrimaryVtableData](by-memory/0x006179e8-0x00617a34.ConnStatusPanePrimaryVtableData.md) records the exact primary vtable child, including slot dwords through the RTTI locator at `0x00617a34`.
- `ConnStatusPane` vtable slots place paint at `0x00617a30 -> 0x00494620`, message handling at `0x00617a48 -> 0x004946c0`, and destructor adjustors at `0x00617a38 -> 0x00494964` / `0x00617a68 -> 0x0049496f`.
- The `0x00544db0`, `0x00544dc0`, and `0x00544dd0` methods appear in `ConnStatusPane` slots but are shared base-pane wrappers: live IDA reports broad vtable fan-in for all three, including 79/72/120 data refs respectively.

## Historical 2026-06-14 C001 IDA MCP Refresh

- Current IDA MCP health reports active database `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, imagebase `0x00400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- `lookup_funcs` reconfirmed the local function inventory: constructor `0x00494520` size `0xc0` / 192 bytes, reset helper `0x004945e0` size `0x29` / 41 bytes, snapshot helper `0x00494610` size `0x0f` / 15 bytes, paint `0x00494620` size `0x91` / 145 bytes, message handler `0x004946c0` size `0xa5` / 165 bytes, frame updater `0x004947a0` size `0x1c4` / 452 bytes, adjustor thunk `0x00494964` size `0x0b`, and scalar deleting destructor `0x00494980` size `0x5f` / 95 bytes. Size conversions were verified with `tools/int_convert.py`.
- `xrefs_to` reconfirmed the single constructor caller at `0x004f87ec`, the four singleton refs to `0x0069adf4` at `0x00494545`, `0x004945fa`, `0x004949a0`, and `0x00504a32`, and the three-way constructor/reset/scalar-destructor vtable stores for `0x006179ec`, `0x00617a38`, and `0x00617a68`.
- `analyze_component` identifies the constructor as the only interface function in this local component, keeps paint/message/update/destructor/snapshot/reset functions internal-only, and records the internal edge `0x004946c0 -> 0x004947a0`.
- The latency-frame thresholds remain `0x190` / 400, `0x320` / 800, and `0x4b0` / 1200. These conversions were verified with `tools/int_convert.py`.
- `find_regex` found the `ConnStatusPane` and `Singleton<ConnStatusPane>` RTTI strings at `0x00675740` and `0x00675760`, matching the existing class/vtable interpretation. It did not recover the EPF/PAL literals from the current string cache, so those remain documented through the existing decompile/disassembly evidence rather than a new string-cache claim.

## Historical Score Rationale

Completion is now `88` because the file page has current IDA 9.1 evidence for the exact local function inventory, constructor caller, singleton lifecycle, vtable-store triad, internal call edge, latency thresholds, and B002's 2026-06-18 source-quality pass for the method island. Confidence is now `90` because current docs and exported data agree on the active `network/` source placement, class/file owner route, field roles, vtable slots, singleton, and first-draft C++ readiness. The remaining cap is exact original naming for some config/event/render helper declarations.

## Historical Cross-References

- [UID:000037][ConnStatusPane](by-class/ConnStatusPane.md)
- [UID:000113][0x00494520-0x004949df.ConnStatusPane](by-memory/0x00494520-0x004949df.ConnStatusPane.md)
- [UID:00035G][0x006179e8-0x00617a34.ConnStatusPanePrimaryVtableData](by-memory/0x006179e8-0x00617a34.ConnStatusPanePrimaryVtableData.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)

## Changes

- 2026-08-24 B003 UID0000IF C002/C003/C009/C085/C094/C138/C139 accepted ordinary callback:
  - Retained `93/95`, standalone `NexusTK/network/ConnStatusPane.cpp/.h`, exact owned binary/source boundary, source order, behavior, layout, compiler-data children, and historical callback evidence.
  - Reconciled the active inventory from 94 to 96 rows by adding the implemented C138 Config/StringUtil and C139 TimerMgr direct-header routes. Current active prose now records complete guarded placeholder-free dependencies and compilation readiness while preserving generated files as validator-owned dynamic authority.

- 2026-08-22 B003 UID0000IF accepted implementation callback: raised `88/90 -> 93/95`; replaced active source placement, whole-file inventory, boundary, generated-output, score, and cross-reference authority with the exact 94-row closure; linked corrected UID00035G and new UID000567-UID00056A pages; and historicalized the prior draft sections while preserving their chronology.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:78`.
  - Summary/evidence: class role, network/status UI placement options, local IDA function starts, singleton, base-pane wrapper caveat, and cross-references are documented; confidence remains medium-high because final `network` versus `ui/status` placement is unresolved.
- 2026-06-04: Raised from `80/78` to `84/84` and filled `PROPOSED_RECONSTRUCTION_PATH` with `NexusTK/network/`.
  - Before: parent placement was plausible but had a blank validator path, stale provenance wording, and only coarse IDA-start evidence.
  - After: live IDA evidence records executable identity, exact local ranges, constructor caller, singleton xrefs, vtable stores/slots, base-wrapper fan-in counts, and the reason the `0x00544d*` methods remain shared `Pane` dependencies.
  - Reasoning: `network/ConnStatusPane.cpp` is the best current reconstruction path because the class is connection-status UI with network-message handling, while `ui/status/` remains a plausible future split. Parent confidence is now high enough to receive the reconstructable class child, but final placement and field names remain below final-code confidence.
- 2026-06-12 A001 Batch 256: Raised `84/84 -> 85/85`.
  - Evidence: exact primary vtable child [UID:00035G][0x006179e8-0x00617a34.ConnStatusPanePrimaryVtableData](by-memory/0x006179e8-0x00617a34.ConnStatusPanePrimaryVtableData.md) now documents the class vtable declaration side and supports routing through [UID:000037][ConnStatusPane](by-class/ConnStatusPane.md) at `85/87`. Final `network` versus `ui/status` placement remains the main confidence cap.
- 2026-06-14 C001 Goal 2 score pass: Raised `85/85 -> 87/88`.
  - Evidence: current IDA 9.1 MCP session reconfirmed exact local function sizes, constructor/singleton/vtable xrefs, component interface/internal split, message-to-frame-update edge, RTTI strings, and latency thresholds with `tools/int_convert.py` conversions. No owner/emitter route changed.
- 2026-06-18 B002 source-quality pass: Raised `87/88 -> 88/90` and removed the active network-versus-UI-status and stale blank-C++ blockers. `NexusTK/network/ConnStatusPane.cpp` remains the active source root; `ui/status` is only a future tree-organization alternative. The file now records first-draft C++ readiness, TimerMgr latency sampling, connection-message opcode cases `4/11/21/38`, `g_pConfig+0x28de75` and MapPane status-gate dependencies, generated-output alias-pollution rejection, and the compiler-generated destructor-thunk/scalar policy.
