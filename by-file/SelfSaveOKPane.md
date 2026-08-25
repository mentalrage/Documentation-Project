*** UID:0000NN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# SelfSaveOKPane

## Status

- Current accepted source pair: `NexusTK/ui/dialogs/SelfSaveOKPane.cpp` and `SelfSaveOKPane.h`; no source split, second header, or third-party import is justified.
- UID0000CX owns the complete fieldless class declaration and CPP prologue, then routes exact children through this file. The H channel derives from `TextBoxPane`, declares the constructor and protected `OnTimer` override, adds no fields, and asserts exact size `0x174`.
- Source-authored bodies are the file-local factory [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md), constructor and timer override [UID:0001B0][0x005147d0-0x00514914.SelfSaveOKPane](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md), plus the separate MapPane-owned opcode-`0x21` inline duplicate.
- Compiler/data evidence is explicit rather than empty: [UID:0001YV][SelfSaveOKPane_vtables](by-type/by-vtable/SelfSaveOKPane_vtables.md), [UID:0002OU][0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData](by-memory/0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData.md), and [UID:0003JL][0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString](by-memory/0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString.md) use covered-by source markers instead of handwritten raw arrays.
- Current generated destinations are `auto-generated/NexusTK/ui/dialogs/SelfSaveOKPane.cpp` and `.h`; generated files are validator-owned and must match the complete inventory after a waited refresh.
- Confidence is very strong for behavior, boundaries, layout, source placement, provider routing, and generated shape. The remaining cap is original spelling of the unreferenced factory callback and its unused argument.

## UID0000OJ Incorporation - 2026-08-16

| Claim | Incorporated disposition |
| --- | --- |
| C0000OJ-054 | Guarded SelfSaveOKPane H and source include route are installed through UID0000CX. |
| C0000OJ-468 | Complete TextBoxPane base is visible before the derived declaration; duplicate or raw TextBox declarations are rejected. |

## File Role

The recoverable SelfSaveOKPane-specific source is a small `TextBoxPane`-based confirmation/status pane. It inserts a pooled twelve-space literal, localized caption id `61`, and the spacer again; attaches itself to `g_pBackPane` through `g_mainUiLayerSlots.rootPaneLayerContext`; and self-dismisses through a timer-handler facet.

This page is the canonical whole-file inventory and a guardrail against historical generated-owner pollution. SpelledPane methods, shared TextEditPane helpers, raw vtable arrays, and raw literal arrays are not SelfSaveOKPane source.

The pane is packet-created. [UID:0000L3][MapPane](by-file/MapPane.md) packet case `0x21` contains the live inline construction block around `0x00508511-0x005085ed`; IDA also has the standalone constructor/timer island at [UID:0001B0][0x005147d0-0x00514914.SelfSaveOKPane](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md) and a retained no-route helper at [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md). The accepted source-shaped role for [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md) is `CreateSelfSaveOKPane(int unusedPacket)`: use `new SelfSaveOKPane` and return success, but do not emit decompiler-shaped allocation calls, manual vtable stores, text-helper internals, or attach/timer raw calls in the helper.

The MapPane inline packet case is a consumer/sibling route, not this file's owner. Fresh 2026-06-23 MCP and PE route scans found no caller, entry xref, branch route, function-pointer/table entry, or VA/RVA/raw-offset dword route to `0x00513800`, so the helper remains a SelfSaveOKPane-owned retained helper with a no-route cap rather than a MapPane-owned packet dispatcher method.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:0000CX][SelfSaveOKPane](by-class/SelfSaveOKPane.md) constructor | `0x005147d0-0x005148d5` | First-draft C++ now lives in [UID:0001B0][0x005147d0-0x00514914.SelfSaveOKPane](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md); builds the text-box pane, localized caption, bounds, layer attach, and timer. |
| `SelfSaveOKPane::OnTimer` | `0x005148e0-0x00514913` | Timer-handler facet method reached through vtable slot `0x0061e850`; removes/detaches and deletes the owner when timer id is zero, returns `true`. |
| `CreateSelfSaveOKPane(int unusedPacket)` retained helper | [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md) | Allocates and constructs the same pane sequence in the binary, but should be emitted source-shaped as `new SelfSaveOKPane` plus `return true`; no direct caller/xref/table/pointer route is currently reported. |
| [UID:0001YV][SelfSaveOKPane_vtables](by-type/by-vtable/SelfSaveOKPane_vtables.md) | `0x0061e7a4`, `0x0061e81c`, `0x0061e84c` | Three vtables installed by the constructor/inline construction paths; timer virtual slot points at `0x005148e0` / `SelfSaveOKPane::OnTimer`. |
| [UID:0002OU][0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData](by-memory/0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData.md) | `0x0061e7a0-0x0061e854` | Exact primary/secondary/timer COL and vtable bytes. Compiler-generated from the class declaration and sole override; emits a covered-by marker, not raw arrays. |
| [UID:0003JL][0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString](by-memory/0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString.md) | 12-space UTF-16 literal at `0x0061ea8c-0x0061eaa8` | Fixed spacer text used by the constructor, factory helper, and MapPane packet-case inline construction block. |
| [UID:0000L3][MapPane](by-file/MapPane.md) opcode `0x21` inline duplicate | exact researched slice begins `0x00508511`, 222 bytes | MapPane owns the inline packet-switch bytes. They construct the same type but do not call or own the standalone factory, constructor, or class methods. |
| unrelated packet sender | `0x00513920-0x005139a4` | Raw opcode-`0x45` packet sender; excluded from this source file. |
| separator padding | `0x005139a4-0x005139b0` and `0x00513a1a-0x00513a20` | Compiler/linker alignment around unrelated successor helpers. |
| unrelated UI active-tab/sound helper | `0x005139b0-0x00513a1a` | Independent helper ending before the next modeled function at `0x00513a20`; excluded from SelfSaveOKPane. |

## UID0000NN Whole-File Source Closure - 2026-08-17

### Exact Source Order And Behavior

1. UID0001AY emits file-local `static bool __stdcall CreateSelfSaveOKPane(int unusedPacket)`. The exact `[0x00513800,0x00513920)` body is 288 bytes, SHA256 `150CE4080002D08330522FECA02C181192AFB423766F8AA785378D327F0AC151`, allocates `0x174`, duplicates the class construction sequence, ignores one stack argument, and returns true. Source keeps the callback ABI but expresses construction as `new SelfSaveOKPane;`.
2. UID0001B0 emits `SelfSaveOKPane::SelfSaveOKPane()` over `[0x005147d0,0x005148d6)` and `SelfSaveOKPane::OnTimer` over `[0x005148e0,0x00514914)`. Ten `0xcc` bytes separate them and twelve trailing `0xcc` bytes end before `0x00514920`.
3. The constructor uses `TextBoxPane(408, 12, false, 143, 1, NULL)`, `InsertText` in spacer/caption/spacer order, localized id `61`, bounds `(14,456)-(422,468)`, `g_pBackPane`, `g_mainUiLayerSlots.rootPaneLayerContext`, and timer `(0,1000,0,0)`.
4. `OnTimer` is the sole source-authored override. Timer id zero calls inherited `RemoveFromLayer()` and deletes the owning pane; every path returns true. The machine-level `this-0xa4` adjustment and scalar-delete flag are multiple-inheritance/compiler lowering, not source statements.
5. MapPane opcode `0x21` owns an inline duplicate beginning at `0x00508511`. It has the same allocation, three facet stores, spacer/caption/spacer sequence, bounds, layer route, and timer schedule, but no call reaches the standalone factory or constructor.

### Compiler Data And Literal Disposition

- Three construction sites store primary/secondary/timer vtable bases at `0x0061e7a4`, `0x0061e81c`, and `0x0061e84c`. Each base has one store from MapPane (`0x0050855b/61/6b`), the factory (`0x00513871/77/81`), and constructor (`0x00514829/2f/39`).
- The three vtable facets match `TextBoxPane` except the timer facet's `0x0061e850 -> 0x005148e0` override. Exact class inheritance and `OnTimer` regenerate the `0x0061e7a0-0x0061e854` RTTI/COL/vtable bytes; no handwritten array belongs in source.
- UID0003JL is a 26-byte, 13-wide-character pooled literal item followed by a separate two-byte alignment word. Its six refs are `0x00508550`, `0x00508593`, `0x00513866`, `0x005138a9`, `0x0051481b`, and `0x00514861`. Source uses `L"            "` at construction sites; no exported literal global is justified.

### Provider Ownership And Generated Contract

- `g_pLanguageMan` and `LanguageMan::GetLocalizedString` remain in the LanguageMan owner; `g_pBackPane` remains in BackPane; `rootPaneLayerContext` remains in `MainUiLayerSlots`; `InsertText` remains in TextEditPane; `AddToLayer` and `RemoveFromLayer` remain inherited Pane methods; timer scheduling remains TimerMgr/TimerHandler behavior. This file consumes those APIs and introduces no duplicate declarations or definitions.
- The generated CPP must contain the four-include provider prologue, file-local factory, constructor, timer override, and three non-empty covered-by markers. It must contain no raw `sub_`, `dword_`, `unk_`, or `asc_` placeholder and no empty emitter marker.
- The generated H must remain the single guarded fieldless `0x174` class declaration with constructor and protected `OnTimer`; no second header, source split, or third-party import is permitted.

### Superseded Historical Assumptions

The old generated 24-method SelfSaveOKPane aggregation, SpelledPane ownership, broad TextEditPane ownership, MapPane-child-class theory, raw vtable-array emission, raw spacer-array emission, and aggregate physical-range owner are retained only as rejected history. Caller fanout, exact vtables, construction sites, source ranges, and current provider declarations disprove those routes.

### Score Rationale

`94/94` reflects exhaustive whole-file inventory, exact behavior and boundaries, complete source and header shape, stable owner/emitter routing, explicit compiler/data handling, and resolved provider dependencies. Scores remain below the final barrier because the original registration route and exact spelling of `CreateSelfSaveOKPane` and `unusedPacket` are not recoverable from current evidence.

## 2026-06-26 B002 Source-Readiness Sync

- [UID:0001B0][0x005147d0-0x00514914.SelfSaveOKPane](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md) is now `90/91` and owns formal first-draft source for `SelfSaveOKPane::SelfSaveOKPane()` and `bool SelfSaveOKPane::OnTimer(int timerId, int, int)`.
- Live MCP session `80de0a67` bounded the constructor as `0x005147d0` size `0x106`, the timer callback as `0x005148e0` size `0x34`, padding at `0x005148d6-0x005148df`, no function at `0x00514914`, and next function `sub_514920` at `0x00514920`.
- Source helper mapping is stable for file-level placement: `TextBoxPane(408, 12, false, 143, 1, NULL)`, `g_pLanguageMan->GetLocalizedString(61)`, three text writes around the 12-space spacer, `InitRectBounds(&bounds, 14, 456, 422, 468)`, inherited `AddToLayer(&bounds, 0, g_pBackPane, g_mainUiLayerSlots[1])`, and `ScheduleTimer(0, 1000, 0, 0)`.
- Timer slot evidence is now source-ready: `0x0061e850 -> 0x005148e0` names the callback `OnTimer`; owner primary slot `+0x38` points at `0x0055ef10`, supporting source-facing `RemoveFromLayer()` before `delete this`.
- The old "blank C++ until final 95+" posture no longer applies to [UID:0001B0][0x005147d0-0x00514914.SelfSaveOKPane](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md). The remaining file-level caps are exact text-wrapper naming, global-name spelling polish, and final original source-tree confirmation.

## Explicit Exclusions

The following generated contents should not be assigned to this source file without new evidence:

- [UID:0000NZ][SpelledPane](by-file/SpelledPane.md) entry-list methods at `0x0056bca0-0x0056c0da`.
- SpelledPane entry-vector insert/erase helpers at `0x00572fd0-0x00573231` and `0x00573900-0x00573961`.
- Shared text-control methods at `0x0058e270-0x005905f0`, which have broad callers and should be reviewed with [UID:0000ON][TextEditPane](by-file/TextEditPane.md) / [UID:0000OJ][TextBoxPane](by-file/TextBoxPane.md). `SelfSaveOKPane.cpp` may call the source-facing text setter, but it does not own the helper family.

## Evidence Notes

- `simroot_v2/class_SelfSaveOKPane.meta_wave3` records 24 methods under this class, but IDA caller checks split those methods across at least three source families.
- IDA MCP confirms no direct callers to `0x005147d0` or `0x005148e0` in the current database, but `xrefs_to` confirms `0x005148e0` is present in the timer-facet vtable at `0x0061e850`.
- IDA MCP confirms the SelfSaveOKPane vtable bases are written by `0x005147d0`, [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md), and [UID:0000L3][MapPane](by-file/MapPane.md) packet case `0x21`. This resolves the earlier live/dead ambiguity enough to treat the small pane as packet-created UI.
- 2026-06-23 B004 source-quality implementation: IDA MCP endpoint `http://127.0.0.1:13337/mcp`, session `0b5e057e`, reconfirmed [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md) as `sub_513800`, prototype shape `char __stdcall(int)`, size `0x120` / 288 bytes (Verified with `int_convert.py`), no callers, empty entry xrefs, construction stores at `0x00513871`/`0x00513877`/`0x00513881`, spacer refs at `0x00513866`/`0x005138a9`, localized string id `0x3d` / 61 (Verified with `int_convert.py`), rect `(14,456)-(422,468)`, attach through `g_pBackPane` / `g_mainUiLayerSlots[1]`, and timer setup at `+0xa4`. The supplemental PE route scan over the read-only `NexusTK.exe` hash `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632` found zero `E8`/`E9`/near-conditional branch hits and zero VA/RVA/raw-offset dword hits to `0x00513800`, while positive controls found ordinary MapPane dispatcher calls and the SelfSaveOKPane vtable/string routes. This preserves `SelfSaveOKPane.cpp` as the helper owner and rejects MapPane/packet-dispatcher ownership for [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md).
- 2026-06-01 IDA MCP reconfirmed `0x00513800`, `0x005147d0`, and `0x005148e0` boundaries, the three shared SelfSaveOKPane vtable writes, and the one-slot timer facet at `0x0061e850`. The project source tree already carries `ui/dialogs/SelfSaveOKPane.cpp`, so the file page uses `NexusTK/ui/dialogs/` as the reconstruction path.
- 2026-06-12 A002 Batch 346 live IDA MCP split exact spacer literal [UID:0003JL][0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString](by-memory/0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString.md) from a mixed MapPane/resource string index. The literal is pushed twice in the standalone constructor, twice in the factory helper, and twice in the MapPane packet-case inline construction block, always surrounding localized string id `61`.
- IDA MCP confirms the supposed SelfSave entry-list helpers are called by self-look/system-message paths and by `SpelledPane` refresh flow.
- 2026-05-26 IDA `py_eval` recheck confirms current active metadata still reports `vtable_count: 0` and `method_count: 24` for `SelfSaveOKPane`, while IDA shows the narrow pane island has three vtables and the extra methods have non-SelfSave caller evidence.

## Cross-References

- [UID:0000CX][SelfSaveOKPane](by-class/SelfSaveOKPane.md)
- [UID:0001B0][0x005147d0-0x00514914.SelfSaveOKPane](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md)
- [UID:0000NZ][SpelledPane](by-file/SpelledPane.md)
- [UID:0000OJ][TextBoxPane](by-file/TextBoxPane.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0001YV][SelfSaveOKPane_vtables](by-type/by-vtable/SelfSaveOKPane_vtables.md)
- [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md)
- [UID:0003JL][0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString](by-memory/0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString.md)
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md)

## Changes

- 2026-08-17 B007 UID0000NN accepted callback: raised `88/87` to `94/94`, installed the exhaustive source-order and boundary inventory, resolved current `InsertText` and `rootPaneLayerContext` dependencies, recorded MapPane inline-byte ownership, preserved all rejected historical theories, and defined the exact CPP/H generated contract without splitting the file or duplicating provider ownership.
- 2026-06-26 B002 implementation sync for [UID:0001B0][0x005147d0-0x00514914.SelfSaveOKPane](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md): raised to `88/87`, recorded the accepted first-draft `SelfSaveOKPane::SelfSaveOKPane` / `SelfSaveOKPane::OnTimer` source body in the child, corrected stale `OnTimerExpired` and screen/render-layer wording, and preserved [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md) factory plus MapPane inline-construction boundaries.
- 2026-06-23 B004 [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md) implementation support sync:
  - Added the accepted `CreateSelfSaveOKPane(int unusedPacket)` retained helper role for [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md), with source-shaped C++ rationale: represent the binary's inlined construction body as `new SelfSaveOKPane` and `return true`, not as raw allocation, manual vtable stores, or decompiler helper calls.
  - Preserved the no-route caveat and MapPane rejection: packet case `0x21` is the live inline SelfSaveOKPane construction route, while MCP and PE scans found no caller/table/pointer/branch/VA/RVA/raw-offset route to `0x00513800`.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `78`.
  - Evidence: document captures the narrow pane island, packet-created construction paths, factory/helper, vtable refs, explicit generated-owner exclusions, IDA evidence, and cross-references; confidence is limited by final original file placement.
- 2026-06-01: Set `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` and raised confidence to `80`.
  Evidence: the proposed source tree includes `ui/dialogs/SelfSaveOKPane.cpp`, and IDA MCP reconfirms the compact SelfSaveOKPane constructor/factory/timer/vtable island plus MapPane packet-case construction evidence. Placement is now strong enough for child attachment, but still below final-source quality.
- 2026-06-12 A002 Batch 346:
  - Before: `86/80`; the page did not list the exact SelfSaveOKPane spacer literal and remained below the current strict confidence gate.
  - After: `87/85`; [UID:0003JL][0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString](by-memory/0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString.md) is documented as file-contained class source data.
  - Evidence: live IDA xrefs and decompilation show the literal used only by SelfSaveOKPane construction variants, including the inline MapPane packet-case construction copy.
