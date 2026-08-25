** TARGET-REPORT-UID:0002DC **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# UID0002DC FittingRoomListPaneConstructor Empty-Emitter Source-Quality Report


## Finalized Report / Current Recommendation

UID0002DC no longer remains an empty emitter for generic "field names/source split" reasons. The implementation callback has been applied: the current target is a reconstructable, class-owned constructor at `0x0041eb90-0x0041ecbd`, owned and emitted through [UID:000053] `FittingRoomListPane` under [UID:0000JE] `NexusTK/cashshop/FittingRoom.cpp`. Generated `auto-generated/NexusTK/cashshop/FittingRoom.cpp` refreshed at validator command `000000005814` now emits UID0002DC's constructor C++ at line `878`.

Applied recommendation: `CANONICAL_OWNER:000053`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:000053` are preserved; the target is now `COMPLETION:88`, `CONFIDENCE:91`; and the formal constructor body is present in `RECONSTRUCTION_CPP CODE`. The code uses normal C++ constructor/declaration surfaces (`ControlPane(8, bounds)`, `new FittingRoomScrollPane(FittingRoomScrollOrientation_Vertical)`, `SetVisibleFlag()`), not vtable writes, SEH/unwind scaffolding, or raw offset assignments.

The only remaining confidence caps are exact original spellings for three constructor-cleared list-state dwords and the exact enum spelling for vertical scroll orientation/display mode. Those caps do not justify a blank C++ block because current support docs already accept descriptive field names in sibling emitted methods (`m_scrollPosition`, `m_enabledItemCount`, `m_displayMode`, `m_scrollPane`, `FittingRoomListDisplayMode_Rows/Grid`, `kInvalidFittingRoomSlot`, and `m_pendingSlotTimer` direction).

## Supporting Research

Assignment source: `tools/leaser/Agents/Agent-B009/goal.md`, target UID `0002DC`, target doc `by-memory/0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md`, report path `tools/leaser/Agents/Agent-B009/research/0002DC-FittingRoomListPaneConstructor-empty-emitter-source-quality.md`.

Project workflow read: `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/SKILL.md` and `references/b-agent-research-and-implementation-workflow.md`.

Current MCP availability: read-only `idb_list` found one active IDB-backed session `e18d1e9b` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active/owned/adopted, `is_analyzing:false`, worker pid `19636`. `server_health` on `e18d1e9b` returned `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready (`2067` strings).

MCP schema-current note: the active server requires `database` for the session id, `queries` for `lookup_funcs`, `addrs` for `xrefs_to`/`callees`, `regions` for `get_bytes`, and `inputs` for `int_convert`. Initial older-schema attempts with `session_id`/`queries` mismatch were rejected before evidence use; all report evidence below uses the corrected schema against `database:"e18d1e9b"`.

## Target

Target document: `by-memory/0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md`.

Current metadata after implementation callback:

| Field | Current value |
| --- | --- |
| UID | `0002DC` |
| COMPLETION | `88` |
| CONFIDENCE | `91` |
| CANONICAL_OWNER | `000053` |
| RECONSTRUCTABLE | `TRUE` |
| EMITTER_UIDS | `000053` |
| EMITTER_POSITION_OPTIONAL | blank |
| Formal C++ | populated with `FittingRoomListPane::FittingRoomListPane(const RectBounds* bounds)` |

Historical assignment-time queue row: `auto-generated/-ag-research-tracker.md` listed UID0002DC at `86/90`, combined `88.0`, reconstructable `true`, reports `0`. That was before the implementation callback and is no longer the current target metadata. The post-callback target page is `88/91`, and generated `auto-generated/NexusTK/cashshop/FittingRoom.cpp` refreshed under validator command `000000005814`.

## Current Target State

The target page now contains the accepted MCP-backed constructor facts and formal source body: exact modeled range, sole caller, callee set, `0x110` scroll-child allocation, child construction support, adjacent raw cleanup, accepted owner/emitter routing, and source-ready `FittingRoomListPane::FittingRoomListPane(const RectBounds* bounds)` C++. The stale blank-C++ blocker text about exact base constructor name, resource-block type, child scroll-pane source constructor relationship, list/scroll field names, and raw cleanup/compiler treatment has been replaced with support-declaration confidence caps.

Current support state is stronger than that blocker text. [UID:0002DF] `FittingRoomListPane::UpdateScrollBar` now emits first-draft C++ and uses accepted source-facing names for `m_scrollPosition`, `m_enabledItemCount`, `m_displayMode`, `m_scrollPane`, row/grid display-mode constants, page-size constants, and child scroll pane current/range/visibility state. [UID:0002DX] now emits the formal destructor body `delete m_scrollPane;`, proving the constructor-owned child pointer name and lifecycle. [UID:0002DD] already contains the target-specific no-code proof for the adjacent cleanup island, so that raw island no longer blocks constructor C++.

Generated state is current after scoped validation: `auto-generated/NexusTK/cashshop/FittingRoom.cpp` header shows `validator-command-id: 000000005814`, `validator-refreshed-at: 2026-07-03T22:23:20-04:00`, and UID0002DC emits at line `878` with `Completion:88`, `Confidence:91`.

## Heuristic / Inference Reanalysis And Validation

The old blank-C++ blockers were valid before later support work, but they are now resolvable:

1. Base constructor/resource-block route: current MCP decompilation of `0x004949e0` shows `sub_4949E0(this, controlType, bounds)` calls Pane construction, writes ControlPane vtables, stores the control type byte, applies bounds when the pointer is non-null, and initializes standard ControlPane fields. This validates `ControlPane(8, bounds)` as the source-level base call for UID0002DC. The exact parameter name should be `const RectBounds *bounds`, matching the current caller [UID:0002CP] formal C++ (`new FittingRoomListPane(&bounds)`).
2. Child constructor/source split: current MCP says `0x0041d6c0` is not a modeled function and has no xrefs, but its raw bytes and disassembly are constructor-shaped `FittingRoomScrollPane` setup that takes one byte argument and copies it to child `+0xfc`. UID0002DC performs equivalent child setup inline after allocating `0x110` bytes. The support solution is not to call raw address `0x0041d6c0`; it is to introduce/record the source declaration `FittingRoomScrollPane::FittingRoomScrollPane(unsigned char orientation)` or enum equivalent, and let compiler/inlining/source-lowering explain the duplicated raw shape.
3. List-pane field names: current target and sibling methods already support source-facing fields. `this+0x108` is the list scroll position; `this+0x10a` is enabled-entry count in `UpdateScrollBar`; `this+0x10c` is row/grid display mode; `this+0x11c` is `FittingRoomScrollPane *m_scrollPane`; `this+0x121` is the selected item/index word initialized to `0xffff`; `this+0x124` is a pending slot/layout timer event id/handle canceled through the embedded `TimerHandler` facet at `this+0xa4`; `this+0x128` is a cleared flag byte. The three dwords at `+0x110/+0x114/+0x118` remain role-level list state, but that can be represented with descriptive reserved names and confidence caps rather than raw offsets.
4. Scroll-pane private-field access: the constructor should not expose child `+0x102` directly. The branch after child construction is best source-shaped as `m_scrollPane->SetVisibleFlag();`: it tests the child visibility/enabled byte, sets it to `1` if needed, and invalidates through virtual slot `+0x20`. Because the child constructor initializes low byte `+0x102` to `1` as part of word `0xff01`, the call is normally a no-op, matching the observed conditional branch without making C++ decompiler-shaped.
5. Raw cleanup/SEH treatment: current [UID:0002DD] and [UID:0002DX] resolve the adjacent cleanup island and destructor obligation. UID0002DC constructor C++ should not include cleanup funclets, vtable restoration, child virtual-delete lowering, or SEH tables. Normal C++ allocation/member construction plus the formal destructor is the source representation.

Validation against current MCP: the exact constructor callee set has only `0x004949e0`, `0x004f4aa0`, and `0x00544460`; no hidden direct child-constructor call exists. The formal source recommendation therefore depends on support declarations/inlining, not on inventing a binary callsite.

## Evidence Standards Used

I used current IDA MCP as mandatory binary evidence, current by-* docs as project documentation state, generated files/reports as lead/current-output evidence, and executed B reports only after search-gating as leads or already-incorporated support context. I treated raw starts with no IDA function record and no xrefs as source-shape evidence only, not direct callable functions. I avoided broad callgraph/type analysis and used narrow lookup/xref/callee/bytes/decompile/disasm calls with explicit address lists and instruction caps.

Numeric conversions in this report use current MCP `int_convert` for `0x12d`, `0x110`, `0x12c`, `0x11c`, `0x108`, `0x10c`, `0x121`, `0x124`, and `0xa4`.

## Evidence Checked

- `goal.md`: assigned UID0002DC, report-only pass, no by-* edits, no generated/coverage/lifecycle edits, MCP mandatory.
- Target doc `by-memory/0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md`.
- Support docs: `by-class/FittingRoomListPane.md`, `by-class/FittingRoomScrollPane.md`, `by-file/FittingRoom.md`, `by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md`, `by-memory/0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar.md`, `by-memory/0x00421410-0x00421477.FittingRoomListPaneScalarDeletingDestructor.md`, `by-memory/0x0041ecc0-0x0041ecf5.FittingRoomListPaneRawDestructorCleanup.md`, and adjacent list/input/paint/reset docs for field-name support.
- Generated lead files: `auto-generated/-ag-research-tracker.md`, `auto-generated/NexusTK/cashshop/FittingRoom.cpp`.
- Prior report search terms: `0002DC`, `0x0041eb90`, `FittingRoomListPaneConstructor`, `sub_41EB90`, `FittingRoomListPane::FittingRoomListPane`.
- Relevant prior reports/leads opened or checked by search: B005 `0002DX-FittingRoomListPaneScalarDeletingDestructor-source-quality.md`, B011 `0002DD-FittingRoomListPaneRawDestructorCleanup-source-routing.md`, B004 `0000JE-FittingRoom-empty-emitter-family-source-quality.md`, B003 `0002DT-0002DP-0002DU-FittingRoomListPaneSlotGeometry-source-quality.md`, B002 `0002D2-0002D7-0002D5-0002D9-0002DB-FittingRoomScrollPaneInteraction-source-quality.md`, and B003 `0000WR-FittingRoomUiCore-source-quality.md`.
- Current MCP `idb_list`: active session `e18d1e9b`.
- Current MCP `server_health`: ok, Hex-Rays ready.
- Current MCP `lookup_funcs`: `0x0041eb90` -> `sub_41EB90` size `0x12d`; `0x0041ecbd`, `0x0041ecc0`, `0x0041ecf5`, and `0x0041d6c0` are not functions; `0x0041ed00` -> `sub_41ED00` size `0x88`; support callees `0x004949e0`, `0x00544460`, `0x004f4aa0`, and destructor `0x00421410` are modeled.
- Current MCP `xrefs_to`: `0x0041eb90` has one code xref at `0x0041c01a` inside `sub_41BDD0`; no xrefs to `0x0041d6c0`, `0x0041ecc0`, `0x0041ecbd`, or `0x0041ecf5`; `0x0041ed00` has only the data xref at `0x0060dd1c`.
- Current MCP `callees 0x0041eb90`: only `0x004949e0`, `0x004f4aa0`, and `0x00544460`.
- Current MCP `get_bytes`: four `0xcc` bytes before the `0x0041eb90` prologue; `0x0041ecbd` region starts with three `0xcc`, then raw cleanup bytes, then eleven `0xcc`; `0x0041d6c0` decodes as raw constructor-shaped scroll-pane bytes ending in `retn 4` and padding.
- Current MCP `decompile 0x0041eb90`: base/control setup, list vtable stores, list-state initialization, `0x110` allocation, `FittingRoomScrollPane` inline setup, child store at `+0x11c`, and conditional visible/invalidate branch.
- Current MCP `disasm 0x0041eb90`: 87 total instructions; includes MSVC EH/cookie scaffolding, allocation of `0x110`, inline child setup, and compiler cleanup references. These are evidence only, not source body text.
- Current MCP `disasm 0x0041d6c0`: no-function raw constructor-shaped body calls `0x00544460`, copies one argument byte into child `+0xfc`, writes scroll-pane vtables, initializes `+0xf8/+0xfe/+0x102/+0x104`, returns with `retn 4`, and has no xrefs.
- Current MCP `decompile 0x004949e0`: validates `ControlPane(controlType, bounds)` support shape.
- Current MCP `decompile 0x00544460`: validates Pane base constructor support shape used by ControlPane and scroll-pane setup.
- Current MCP `int_convert`: `0x12d=301`, `0x110=272`, `0x12c=300`, `0x11c=284`, `0x108=264`, `0x10c=268`, `0x121=289`, `0x124=292`, `0xa4=164`.

## Claim And Incorporation Ledger

| ID | Claim | Evidence | Destination if accepted | Action | Verification state |
| --- | --- | --- | --- | --- | --- |
| C-0002DC-01 | UID0002DC is exact modeled `sub_41EB90`, range `0x0041eb90-0x0041ecbd`, size `0x12d` / 301 bytes. | MCP `lookup_funcs`; current target doc. | Target Item Summary / Raw Code Evidence; by-file UID0002DC note. | incorporate | applied |
| C-0002DC-02 | The only direct code xref/caller is `0x0041c01a` in `sub_41BDD0` / [UID:0002CP] FittingRoomDialog constructor. | MCP `xrefs_to 0x0041eb90`; [UID:0002CP] formal C++. | Target Raw Code Evidence; by-file UID0002DC note. | incorporate | applied |
| C-0002DC-03 | Constructor callees are only `ControlPane` setup `0x004949e0`, operator new `0x004f4aa0`, and Pane/scroll setup `0x00544460`. | MCP `callees`. | Target Raw Code Evidence; by-file UID0002DC note. | incorporate | applied |
| C-0002DC-04 | `0x004949e0` is source-shaped `ControlPane(controlType, bounds)`, so UID0002DC should use `ControlPane(8, bounds)`. | MCP decompile `0x004949e0`; caller uses bounds id 2. | Target formal C++; target Reconstruction Status; by-class/by-file support notes. | incorporate | applied |
| C-0002DC-05 | Constructor allocates a `0x110` / 272-byte `FittingRoomScrollPane` child and stores it at `this+0x11c` as `m_scrollPane`. | MCP decompile/disasm; int_convert; destructor UID0002DX formal C++. | Target Behavior / C++; `by-class/FittingRoomListPane.md`; `by-class/FittingRoomScrollPane.md`; `by-file/FittingRoom.md`. | incorporate | applied |
| C-0002DC-06 | Raw `0x0041d6c0` is constructor-shaped scroll-pane support but not a modeled or referenced function. | MCP `lookup_funcs`, `xrefs_to`, `get_bytes`, `disasm`. | `by-class/FittingRoomScrollPane.md` constructor-support note and Boundary Cautions; target Reconstruction Status; by-file UID0002DC note. | incorporate | applied |
| C-0002DC-07 | Adjacent `0x0041ecc0-0x0041ecf5` cleanup is no-function/no-xref compiler cleanup evidence and must not be hand-authored in this constructor. | MCP bytes/xrefs; UID0002DD no-code proof; UID0002DX destructor. | UID0002DD/UID0002DX pages already contained same-or-greater proof; target Changes / Reconstruction Status and by-file note incorporate summary. | already-present plus incorporate summary | already-present |
| C-0002DC-08 | Field support is now adequate for first-draft C++: `m_scrollPosition`, `m_enabledItemCount`, `m_displayMode`, `m_scrollPane`, `m_pendingSlotTimer`, and scroll-pane state names are accepted in sibling docs. | UID0002DF/UID0002DX/UID0002DD/FittingRoomScrollPane docs. | Target Behavior / C++; `by-class/FittingRoomListPane.md` boundary note; `by-file/FittingRoom.md` source-context note. | incorporate | applied |
| C-0002DC-09 | Three constructor-cleared dwords at `+0x110/+0x114/+0x118` remain confidence caps but can be named `m_listState0/m_listState1/m_listState2` or better support names during callback rather than blocking all C++. | Current target field list; lack of stronger direct names in support docs. | Target Behavior / Reconstruction Status / Score Rationale; `by-class/FittingRoomListPane.md` boundary note. | incorporate | applied |
| C-0002DC-10 | Formal C++ should call `m_scrollPane->SetVisibleFlag()` after construction, not expose child `+0x102`, because the binary branch is the normal visible/invalidating helper shape. | MCP decompile/disasm branch; support Pane virtual invalidation usage; current docs. | Target formal C++; target Behavior; class/file source-ready notes. | incorporate | applied |
| C-0002DC-11 | Reject Browser/generic ScrollBar/direct raw constructor/file-level/no-owner/SEH-vtable alternatives for this target. | FittingRoom docs, scroll-pane source-placement docs, MCP callee/xref evidence. | Target Changes / Reconstruction Status; `by-class/FittingRoomScrollPane.md`; `by-file/FittingRoom.md`. Browser wording is a stale report typo and was excluded as not target-applicable; relevant generic ScrollBar/direct raw/file-level/no-owner/SEH-vtable alternatives were applied. | incorporate | applied / excluded-with-reason |

## Positive Evidence Summary

The binary pattern is a normal source-authored class constructor:

- exact function at `0x0041eb90`, size `0x12d`, with prologue after four `0xcc` padding bytes;
- one real caller from the FittingRoom dialog constructor at `0x0041c01a`, where current formal C++ already calls `new FittingRoomListPane(&bounds)`;
- direct class owner [UID:000053] and file route [UID:0000JE] are consistent with the list-pane method family and generated source path;
- base setup callee `0x004949e0` decompiles as ControlPane constructor support with a control type byte and optional bounds application;
- `0x004f4aa0(0x110)` allocation plus inline setup creates the fitting-room scroll child;
- destructor UID0002DX now formally emits `delete m_scrollPane;`, tying constructor allocation to accepted source ownership;
- `FittingRoomScrollPane` docs already define the child layout and reject generic ScrollBar ownership absent a non-FittingRoom constructor/caller route;
- sibling emitted list-pane methods already use source-facing field names and constants compatible with this constructor body.

## Negative Evidence Summary

Negative checks reject the remaining no-code and alternate-owner explanations:

- No current IDA function, xref, pointer route, or call route exists for raw `0x0041d6c0`; it cannot be called by address in formal C++.
- No function/xref route exists for `0x0041ecc0`, `0x0041ecbd`, or `0x0041ecf5`; the adjacent cleanup bytes are compiler cleanup evidence covered by destructor/constructor source semantics, not a source method.
- UID0002DC has no broad helper/callgraph evidence suggesting generic `ScrollBar.cpp`, Pane, ControlPane, EventHandler, TimerHandler, or no-owner routing as direct source owner. Those are dependencies.
- The only real target callsite is from the fitting-room dialog constructor; no alternative live dispatcher or duplicate helper route was found.
- Vtable/SEH/security-cookie/deleting-helper mechanics appear in disassembly but would be decompiler-shaped if hand-authored.
- Leaving C++ blank solely because `+0x110/+0x114/+0x118` are not exact original spellings would now under-use accepted support declarations and sibling first-draft naming policy.

## Ranked Ownership Analysis

1. [UID:000053] `FittingRoomListPane` as direct owner/emitter: strongest. Evidence includes class vtable writes, sole construction from `FittingRoomDialog`, sibling list-pane methods, destructor ownership of `m_scrollPane`, and current metadata.
2. [UID:0000JE] `FittingRoom` as final source file route: strong but indirect. It owns `NexusTK/cashshop/FittingRoom.cpp` and the fitting-room feature family; UID0002DC should still emit through the class owner chain, not direct file ownership.
3. [UID:000054] `FittingRoomScrollPane`: support/dependency only. The constructor allocates and initializes a child scroll pane, but the method being reconstructed is list-pane construction.
4. `ControlPane`/`Pane`/`TimerHandler`: inherited dependency support only. They explain calls and adjusted facets but do not own the fitting-room list-pane constructor.
5. Generic `ScrollBar`/`ui/core`: rejected for this target. Current docs found no non-FittingRoom constructor/vtable/caller route, and this constructor sits in the FittingRoom UI cluster.
6. No-owner/non-emitting: rejected. The target is a modeled, directly called, reconstructable constructor with an existing owner/emitter and enough support for formal source.

## Source Placement

Source placement should remain `NexusTK/cashshop/FittingRoom.cpp` via [UID:000053] `FittingRoomListPane` -> [UID:0000JE] `FittingRoom`. The constructor is part of the fitting-room UI cluster (`0x0041ba40-0x004245f5`) and is directly constructed by [UID:0002CP] `FittingRoomDialog::FittingRoomDialog`. The scroll child is local to fitting-room list controls and shares vtable/resource suffix evidence with [UID:000054] `FittingRoomScrollPane`.

No new source file, class owner, or no-owner page is recommended.

## First-Draft C++ Recommendation

Recommended formal `RECONSTRUCTION_CPP CODE` insertion text for UID0002DC:

```cpp
FittingRoomListPane::FittingRoomListPane(const RectBounds* bounds)
    : ControlPane(8, bounds)
{
    m_scrollPosition = 0;
    m_enabledItemCount = 0;
    m_displayMode = FittingRoomListDisplayMode_Grid;
    m_listState0 = 0;
    m_listState1 = 0;
    m_listState2 = 0;
    m_selectedItemIndex = kInvalidFittingRoomSlot;
    m_pendingSlotTimer = 0;
    m_stateFlags = 0;

    m_scrollPane = new FittingRoomScrollPane(FittingRoomScrollOrientation_Vertical);
    m_scrollPane->SetVisibleFlag();
}
```

Support declaration notes required for this exact body:

- `FittingRoomListPane::FittingRoomListPane(const RectBounds* bounds)`.
- `ControlPane(8, bounds)` or exact local equivalent for `0x004949e0(this, 8, bounds)`.
- `enum FittingRoomListDisplayMode { FittingRoomListDisplayMode_Rows = 0, FittingRoomListDisplayMode_Grid = 1 };` or equivalent already used by sibling code.
- `kInvalidFittingRoomSlot = -1`; constructor writes `0xffff` to the selected slot/index word.
- `enum FittingRoomScrollOrientation { FittingRoomScrollOrientation_Vertical = 0, FittingRoomScrollOrientation_Horizontal = 1 };` or equivalent byte/enum accepted by `FittingRoomScrollPane`.
- `FittingRoomScrollPane::FittingRoomScrollPane(unsigned char orientation)` or enum overload. Its support evidence is raw `0x0041d6c0` and UID0002DC's inline child setup, not a direct call to raw address.
- `SetVisibleFlag()` should remain a source-level inherited/Pane helper. It preserves the observed conditional set/invalidate branch without direct child-private field access.
- The exact original names of `m_listState0`, `m_listState1`, `m_listState2`, and `m_stateFlags` are inferred placeholders. If callback finds same-or-greater accepted names in sibling docs, use those names and mark this row already-present/superseded rather than duplicating placeholders.

## Final Recommendation

Implementation callback has been applied. UID0002DC's formal C++ block is populated with the constructor above, the target's stale blank-C++ rationale is replaced, and the previous blockers are recorded as support declarations and confidence caps. Target metadata is now `88/91`.

Do not create a new by-memory page for raw `0x0041d6c0` during this callback unless the supervisor explicitly wants a split. It is support evidence for the `FittingRoomScrollPane` constructor declaration, not a routed function target.

Do not edit generated C++ or generated reports manually. A scoped target/support validator after callback should refresh generated output through the validator path.

## Recommended Target Doc Changes

For `by-memory/0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md`:

- Set `COMPLETION:88`, `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:000053`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000053`, blank optional emitter position.
- Insert the formal C++ block from this report into the target's formal `RECONSTRUCTION_CPP CODE` block.
- Update Item Summary to say current MCP session `e18d1e9b` confirms exact range/caller/callees, ControlPane route, `0x110` child allocation, inline scroll-pane setup, raw `0x0041d6c0` no-route support, adjacent cleanup no-code relationship, and first-draft constructor C++ readiness.
- Replace the stale "final C++ intentionally withheld" blocker with a current reconstruction status: C++ is source-ready with confidence caps for exact original names of `+0x110/+0x114/+0x118`, display/scroll orientation enum spelling, and raw child-constructor inlining.
- Preserve negative evidence rejecting direct raw `0x0041d6c0` calls, adjacent raw cleanup emission, vtable/SEH source, generic ScrollBar/Panes ownership, direct file owner, and no-owner routing.

## Recommended Support Doc Changes

For `by-class/FittingRoomListPane.md`:

- Record UID0002DC as source-ready `88/91` with constructor C++ dependent on accepted list-state/scroll support declarations.
- Add a constructor/layout note: `m_scrollPosition` and `m_enabledItemCount` are jointly cleared by the `+0x108` dword store; `m_displayMode` initializes to grid (`1`); `m_scrollPane` is constructed as a vertical `FittingRoomScrollPane`; the constructor calls inherited `SetVisibleFlag()` on the child.
- Add or refine the field map for constructor-cleared `+0x110/+0x114/+0x118` with descriptive placeholders (`m_listState0/m_listState1/m_listState2` or stronger names if already present), and make clear exact original spellings remain confidence caps.

For `by-class/FittingRoomScrollPane.md`:

- Add support declaration/evidence for `FittingRoomScrollPane::FittingRoomScrollPane(unsigned char orientation)` or enum equivalent. Evidence: raw no-function `0x0041d6c0` copies argument byte to `+0xfc`, writes scroll-pane vtables, initializes `+0xf8`, `+0xfe/+0x100`, word `+0x102=0xff01`, and active part `+0x104=0xff`; UID0002DC performs equivalent setup inline after `0x110` allocation.
- Preserve the no-route caveat for raw `0x0041d6c0`: declaration support only, not a direct by-memory source function call.
- Confirm `FittingRoomScrollOrientation_Vertical = 0` / horizontal nonzero direction if this enum exists elsewhere; otherwise document as an inferred byte enum.

For `by-file/FittingRoom.md`:

- Update the UID0002DC empty-emitter family note from "blocked by field/source split" to "source-ready after support declarations; formal constructor C++ recommended through [UID:000053]."
- Keep final source path `NexusTK/cashshop/FittingRoom.cpp`.

For `by-memory/0x0041ecc0-0x0041ecf5.FittingRoomListPaneRawDestructorCleanup.md` and [UID:0002DX]:

- No required changes if current no-code/destructor text is already at same-or-greater detail. Mark ledger rows already-present during callback unless stale wording is found.

## Score And Metadata Recommendation

Recommended target score: `COMPLETION:88`, `CONFIDENCE:91`.

Rationale for completion increase: current MCP confirms all target-local binary facts; support docs now resolve the old generic blockers into declarations/field names; adjacent raw cleanup is already no-code with destructor replacement; and a formal source-shaped constructor body can be inserted without raw offset/vtable/SEH scaffolding.

Rationale for confidence increase: evidence is consistent across current MCP (`e18d1e9b`), target docs, support docs, generated lead rows, and prior accepted reports. Confidence stays below final audit because exact original spellings for the three list-state dwords, enum names, and inlined raw child constructor support are inferred rather than symbol-proven.

No owner/emitter/reconstructable change is recommended.

## Open Questions With Attempted Resolution

| Question | Attempted resolution | Remaining impact |
| --- | --- | --- |
| What is the exact base constructor name/type? | MCP decompile `0x004949e0` proves `ControlPane(controlType, bounds)` shape; caller passes bounds pointer; UID0002DC passes control type `8`. | Use `ControlPane(8, bounds)`. No C++ blocker. |
| Is `0x0041d6c0` a callable child constructor? | MCP `lookup_funcs` says not a function; `xrefs_to` says zero; bytes/disasm show constructor-shaped support. | Add support declaration for `FittingRoomScrollPane` constructor; do not call raw address. |
| Are list fields source-quality enough? | Sibling emitted docs use accepted names for scroll/display/count/slot/timer fields. Only `+0x110/+0x114/+0x118` remain role-level. | Use descriptive placeholders/support declarations and cap confidence. Not a blank-C++ blocker. |
| Should the child branch be private field access? | The branch tests the child visible/enabled byte and invalidates if setting it. Child constructor initializes it true. Source shape matches inherited `SetVisibleFlag()`. | Use `m_scrollPane->SetVisibleFlag()`. |
| Does raw cleanup force no-code for constructor? | UID0002DD/UID0002DX already resolve cleanup/destructor source split. | Constructor can emit normal source; cleanup remains no-code. |
| Could generic ScrollBar own this constructor? | No non-FittingRoom constructor/caller/vtable route found; FittingRoomScrollPane docs reject generic reroute. | Rejected. |

## Validator Results

Implementation-callback scoped validators were run from `source-3/project-documentation`:

| File | Command | command_id | command_timestamp | Exit | ok | Warnings / side effects | Generated-refresh state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `by-memory/0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md` | `python .\tools\validator.py --mode file --file by-memory\0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md --apply --queue-timeout 240` | `000000005803` | `2026-07-03T22:14:35-04:00` | `0` | `1` | `completion_update 0002DC 88`; `confidence_update 0002DC 91`; two `autogen_registry_update` rows; projected stats update; no warnings. | deferred |
| `by-class/FittingRoomListPane.md` | `python .\tools\validator.py --mode file --file by-class\FittingRoomListPane.md --apply --queue-timeout 240` | `000000005804` | `2026-07-03T22:14:41-04:00` | `0` | `1` | projected stats update; no warnings. | deferred |
| `by-class/FittingRoomScrollPane.md` | `python .\tools\validator.py --mode file --file by-class\FittingRoomScrollPane.md --apply --queue-timeout 240` | `000000005805` | `2026-07-03T22:14:53-04:00` | `0` | `1` | pre-existing `missing_ref_uid 0003AM`; `reference_index_add 0002DC`; projected stats update. | deferred |
| `by-file/FittingRoom.md` | `python .\tools\validator.py --mode file --file by-file\FittingRoom.md --apply --queue-timeout 240` | `000000005814` | `2026-07-03T22:23:20-04:00` | `0` | `1` | four pre-existing `missing_ref_uid 0003AM`; projected stats update. | deferred-generated-refresh completed for `auto-generated/NexusTK/cashshop/FittingRoom.cpp` |

Generated freshness proof: read-only check of `auto-generated/NexusTK/cashshop/FittingRoom.cpp` shows `validator-command-id: 000000005814`, `validator-refreshed-at: 2026-07-03T22:23:20-04:00`, and UID0002DC emitted at line `878` as `FittingRoomListPane::FittingRoomListPane(const RectBounds* bounds)` with `Completion:88`, `Confidence:91`.

No `execute_report`, dry-run/probe lifecycle command, registry lifecycle command, archive move, generated-file edit, coverage edit, validator-state edit, or supervisor-ledger edit was run.

## Changed Files

- `by-memory/0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md`
- `by-class/FittingRoomListPane.md`
- `by-class/FittingRoomScrollPane.md`
- `by-file/FittingRoom.md`
- `tools/leaser/Agents/Agent-B009/research/0002DC-FittingRoomListPaneConstructor-empty-emitter-source-quality.md`

Leases used and released: B009 leased the target/class batch (`by-memory/0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md`, `by-class/FittingRoomListPane.md`, `by-class/FittingRoomScrollPane.md`), validated those files, and released them successfully. B009 later leased `by-file/FittingRoom.md`, validated it, and released it successfully. Final lease report showed no active leases.

## Implementation Tracking Checklist

- [x] Target `by-memory/0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md`: set metadata to `COMPLETION:88`, `CONFIDENCE:91`; kept owner `000053`, reconstructable true, emitter `000053`, blank optional emitter position.
- [x] Target: inserted the exact formal C++ block from `First-Draft C++ Recommendation`.
- [x] Target: updated Item Summary, Reconstruction Status, Raw Code Evidence, Score Rationale, positive/negative evidence, and rejected alternatives with current MCP session `e18d1e9b` details.
- [x] Target: removed stale "C++ withheld pending exact base/resource/child/layout/raw cleanup" current-state wording; replaced it with support-declaration confidence caps.
- [x] Support `by-class/FittingRoomListPane.md`: recorded UID0002DC as source-ready and added constructor layout/support notes for `m_scrollPosition`, `m_enabledItemCount`, `m_displayMode`, `m_scrollPane`, selected-slot/timer/flag state, and `+0x110/+0x114/+0x118` descriptive placeholders.
- [x] Support `by-class/FittingRoomScrollPane.md`: added constructor declaration/support evidence for `FittingRoomScrollPane::FittingRoomScrollPane(unsigned char orientation)` or enum equivalent; preserved raw `0x0041d6c0` no-route caveat.
- [x] Support `by-file/FittingRoom.md`: updated UID0002DC empty-emitter family note from blocked to source-ready through [UID:000053] after support declarations.
- [x] Support UID0002DD/UID0002DX: already present at same-or-greater detail; no edits required. UID0002DD already contains no-function/no-xref compiler cleanup no-code proof; UID0002DX already emits `delete m_scrollPane;` source destructor and documents the `+0x11c` lifecycle.
- [x] Claim ledger: updated each row to `applied`, `already-present`, or `excluded-with-reason` with destination section/path.
- [x] Ran scoped validators for each changed by-* doc from `source-3/project-documentation`; command IDs `000000005803`, `000000005804`, `000000005805`, and `000000005814`.
- [x] Generated freshness checked for `auto-generated/NexusTK/cashshop/FittingRoom.cpp`: header command `000000005814`, refreshed `2026-07-03T22:23:20-04:00`, UID0002DC constructor emitted at line `878`.
- [x] Did not run `execute_report`, dry-run/probe lifecycle commands, registry lifecycle commands, archive moves, generated/coverage edits, validator-state edits, or supervisor-ledger edits. Supervisor owns report execution after Gate 2.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000005821","destination_path":"executed-b-agent-research/B009/0002DC-FittingRoomListPaneConstructor-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0002DC-FittingRoomListPaneConstructor-empty-emitter-source-quality.md","timestamp":"2026-07-03T22:33:00-04:00","uid":"0002DC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
