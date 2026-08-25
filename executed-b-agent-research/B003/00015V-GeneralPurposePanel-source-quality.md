** TARGET-REPORT-UID:00015V **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B-Agent Source-Quality Report: [UID:00015V] GeneralPurposePanel

Agent: Agent-B003  
Assignment: source-quality / heuristic research  
Target: `source-3/project-documentation/by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md`  
Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/00015V-GeneralPurposePanel-source-quality.md`

## Executive Recommendation

Keep [UID:00015V] routed to [UID:0000JQ] `GeneralPurposePanel.cpp`:

```text
CANONICAL_OWNER:0000JQ
EMITTER_UIDS:0000JQ
RECONSTRUCTABLE:TRUE
```

Recommended metadata change:

```text
COMPLETION:86
CONFIDENCE:91
```

The current `84/90` already clears the active C++ gate because `(84 + 90) / 2 = 87`, and the owner/emitter route is nonblank. However, [UID:00015V] should still not receive a monolithic formal C++ body. It is a broad aggregate spanning two classes, several already split child helper pages, compiler-generated cleanup/deleting-destructor code, vtable plumbing, and padding. The source-quality direction is to improve the aggregate inventory and route exact child bodies to child pages, not to paste all bodies into this parent memory page.

Best first-draft C++ direction:

- Keep aggregate [UID:00015V] blank or limit it to a generator-level `[[CHILDREN]]` marker if the supervisor requests one later.
- Add or update exact child pages for constructors/destructors and the `GeneralPurposePanel2` accessor before emitting source code.
- Let [UID:00005Q] `GeneralPurposePanel` and [UID:00005R] `GeneralPurposePanel2` emit class declarations through [UID:0000JQ] `NexusTK/ui/panels/GeneralPurposePanel.cpp`.
- Keep FrameChrome, SystemMessagePanes, PaneCore, RectBounds, InterfaceEfx, and TotemFrame helpers as dependencies, not as `GeneralPurposePanel.cpp` implementation bodies.

## Evidence Checked

Instruction sources read:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B003/goal.md`

Target and support documentation checked:

- [UID:00015V] `0x004b83d0-0x004b8bd3.GeneralPurposePanel.md`
- [UID:0000JQ] `by-file/GeneralPurposePanel.md`
- [UID:00005Q] `by-class/GeneralPurposePanel.md`
- [UID:00005R] `by-class/GeneralPurposePanel2.md`
- [UID:00015W] `GeneralPurposePanelChildAccessors`
- [UID:00015X] `GeneralPurposePanelSwitchActiveTab`
- [UID:00015Y] `GeneralPurposePanel2SwitchActiveChild`
- [UID:00015Z] `GeneralPurposePanelSingletonClearHelpers`
- [UID:0003BC] `GeneralPurposePanelVtableData`
- [UID:0003BD] `GeneralPurposePanel2VtableData`
- [UID:0000R0] `g_pGeneralPurposePanel`
- [UID:0000R1] `g_pGeneralPurposePanel2`
- [UID:00028X] `g_pGeneralPurposePanel` storage
- [UID:0002VS] `g_pGeneralPurposePanel2Storage`
- [UID:0000JL] `FrameChrome`
- [UID:0000YI] `AboveFrameRefreshHelpers`
- [UID:0000PN] `FrameChromeSlots`
- [UID:0000U2] `BuildAboveFrameBorder_00461310`
- [UID:0000SW] `g_useEpfAssets`
- [UID:0000OE] `SystemMessagePanes`
- Prior B003 executed report for [UID:00018H] `InterfaceEfxMgr::TriggerInterfaceEffect`

Generated and coverage files checked:

- `source-3/project-documentation/auto-generated/NexusTK/ui/panels/GeneralPurposePanel.cpp`
- `source-3/project-documentation/auto-generated/-ag-memory-coverage.md`
- `source-3/project-documentation/auto-generated/-ag-class-coverage.md`
- `source-3/project-documentation/auto-generated/-ag-global-coverage.md`
- `source-3/project-documentation/project-level/-auto-completion-stats.md`
- `source-3/project-documentation/by-memory/-coverage-report.md`

Binary evidence checked locally from:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
```

IDA MCP was attempted at `http://127.0.0.1:13337/mcp` but was unavailable. The fresh validation in this report therefore uses local PE section mapping, raw bytes, Capstone disassembly, direct rel32 call scans, VA dword reference scans, and `int_convert.py` decimal checks.

## Local Binary Facts

PE section mapping:

```text
.text  0x00401000-0x0060c600 raw=0x400    rsize=0x20b600
.rdata 0x0060d000-0x0066c200 raw=0x20ba00 rsize=0x5f200
.data  0x0066d000-0x0069ce24 raw=0x26ac00 rsize=0xd800
.rsrc  0x0069d000-0x006b2e00 raw=0x278400 rsize=0x15e00
```

Aggregate target size:

```text
0x004b8bd3 - 0x004b83d0 = 0x803 / 2051 bytes
```

`0x803 = 2051` was verified with `int_convert.py`.

Vtable data bytes at `0x0061a884` confirm the two adjacent class vtables:

```text
94 7c 64 00 40 8b 4b 00 10 4b 4f 00 c0 b6 41 00
34 7d 64 00 a0 8a 4b 00 10 4b 4f 00 c0 b6 41 00
```

This resolves to:

- `0x0061a888`: `GeneralPurposePanel` vtable, first slot `0x004b8b40`.
- `0x0061a898`: `GeneralPurposePanel2` vtable, first slot `0x004b8aa0`.

Selected dword reference evidence:

- `0x004b8b40` appears as a vtable slot at `0x0061a888`.
- `0x004b8aa0` appears as a vtable slot at `0x0061a898`.
- `0x0061a888` is stored from code at `0x004b842e`, `0x004b85a9`, and `0x004b8b73`.
- `0x0061a898` is stored from code at `0x004b888e`, `0x004b8917`, and `0x004b8ac7`.
- `0x0067a874` is the `g_pGeneralPurposePanel` singleton and is referenced by construction, destruction, FrameChrome, and many UI consumers.
- `0x0069b358` is the `g_pGeneralPurposePanel2` singleton and is referenced by construction, destruction, cleanup, and system-message-panel consumers.
- `0x0067a840` is the FrameChrome-owned dynamic `AboveFrame` slot, not a `GeneralPurposePanel` field.

The raw-file bytes for late `.data` addresses around `0x0069b358` are not directly recoverable from initialized raw section payload because the RVA sits in the virtual tail beyond initialized file data. Treat the current `g_pGeneralPurposePanel2` storage initializer notes as requiring raw-file/live-IDB reconciliation, but this does not block owner or source routing.

## Exact Method / Class Inventory

Fresh local disassembly supports the following half-open ranges:

| Range | Size | Recommended source-quality identity | Route |
|---|---:|---|---|
| `0x004b83d0-0x004b857e` | `0x1ae` / 430 | `GeneralPurposePanel::GeneralPurposePanel()` | [UID:00005Q] via [UID:0000JQ] |
| `0x004b8580-0x004b85e3` | `0x63` / 99 | `GeneralPurposePanel::~GeneralPurposePanel()` | [UID:00005Q] via [UID:0000JQ] |
| `0x004b85f0-0x004b8617` | `0x27` / 39 | `GeneralPurposePanel::GetChildPaneByIndex(int index)` | Existing [UID:00015W] |
| `0x004b8620-0x004b8630` | `0x10` / 16 | `GeneralPurposePanel::GetActiveChildPane()` | Existing [UID:00015W] |
| `0x004b8630-0x004b8644` | `0x14` / 20 | `GeneralPurposePanel::RefreshActiveChild()` / current `DispatchActiveChildRefresh` | Existing [UID:00015W] |
| `0x004b8650-0x004b8823` | `0x1d3` / 467 | `GeneralPurposePanel::SwitchActiveTab(int tabIndex, bool showChild)` | Existing [UID:00015X] |
| `0x004b8830-0x004b88e1` | `0xb1` / 177 | `GeneralPurposePanel2::GeneralPurposePanel2()` | [UID:00005R] via [UID:0000JQ] |
| `0x004b88f0-0x004b8944` | `0x54` / 84 | `GeneralPurposePanel2::~GeneralPurposePanel2()` | [UID:00005R] via [UID:0000JQ] |
| `0x004b8950-0x004b8969` | `0x19` / 25 | `GeneralPurposePanel2::GetChildPaneByIndex(int index)` | [UID:00005R] via [UID:0000JQ] |
| `0x004b89a0-0x004b8a7f` | `0xdf` / 223 | `GeneralPurposePanel2::SwitchActiveChild(int index, bool showChild)` | Existing [UID:00015Y] |
| `0x004b8a80-0x004b8a8b` | `0xb` / 11 | compiler cleanup helper clearing `g_pGeneralPurposePanel2` | Existing [UID:00015Z], non-reconstructable |
| `0x004b8a90-0x004b8a9b` | `0xb` / 11 | compiler cleanup helper clearing `g_pGeneralPurposePanel` | Existing [UID:00015Z], non-reconstructable |
| `0x004b8aa0-0x004b8b32` | `0x92` / 146 | `GeneralPurposePanel2` scalar deleting destructor wrapper | compiler-generated / vtable support |
| `0x004b8b40-0x004b8bd3` | `0x93` / 147 | `GeneralPurposePanel` scalar deleting destructor wrapper | compiler-generated / vtable support |

All listed hex-to-decimal conversions were verified with `int_convert.py`.

Important exact-boundary notes:

- `GeneralPurposePanel::SwitchActiveTab` returns at `0x004b8820` and the following `0xcc` padding begins at `0x004b8823`.
- `GeneralPurposePanel2::SwitchActiveChild` returns at `0x004b8a7c` and padding begins before the cleanup helper at `0x004b8a80`.
- Target [UID:00015V] ends at `0x004b8bd3`; byte `0x004b8bd3` is padding after `GeneralPurposePanel` scalar deleting destructor.

## Caller / Vtable Evidence

Direct call evidence:

- `0x004b83d0` constructor is called from `0x004f7ff7` and `0x004f8835`.
- `0x004b8830` constructor is called from `0x004f8020`.
- `0x004b85f0` has broad side-panel fan-in across UI code, including callers in the `0x004c7xxx`, `0x0050fxxx`, `0x00514xxx`, `0x00569xxx`, `0x005a3xxx`, and `0x005bxxxx` ranges.
- `0x004b8620` direct callers include `0x0049e5d5`, `0x005698a8`, `0x005a6d30`, and `0x005a6e33`.
- `0x004b8630` direct callers include `0x00556e06` and `0x005593fc`.
- `0x004b8650` has broad tab-switch fan-in, including callers at `0x00508040`, `0x00508679`, `0x00508cb2`, `0x005119d2`, `0x005139e7`, `0x005139fd`, `0x005144e2`, `0x0053edfc`, `0x00541b9c`, `0x005a400a`, and `0x005a403a`.
- `0x004b8950` direct callers include `0x0050feff`, `0x005a794a`, `0x005a7ef4`, `0x005a7f1d`, `0x005a7fc7`, `0x005a7fde`, `0x005a9152`, `0x005aac48`, and `0x005aace2`.
- `0x004b89a0` direct caller is `0x005a771b`.
- `0x004b8a80` and `0x004b8a90` are reached through cleanup-table wrapper jumps at `0x005ff294` and `0x005ff1fe`, respectively.

Dependency call evidence:

- `0x004615b0` FrameChrome release helper is called from `0x004b872e` and `0x004b8a62`.
- `0x004615d0` FrameChrome recreate helper is called from `0x004b8733` and `0x004b8a67`.
- `0x004e9ee0` `InterfaceEfxMgr::TriggerInterfaceEffect(int effectId)` is called from `0x004b880b`.
- `0x00588560` `NewSystemMessagePane` constructor is called from `0x004b88ae`.

## Field, Global, And Helper Naming Recommendations

Recommended global names:

| Raw/global | Recommended name | Owner |
|---|---|---|
| `dword_67A874` | `g_pGeneralPurposePanel` | [UID:0000R0] via [UID:0000JQ] |
| `dword_69B358` | `g_pGeneralPurposePanel2` | [UID:0000R1] via [UID:0000JQ] |
| `byte_66DA97` | `g_useEpfAssets` | [UID:0000SW] |
| `dword_69B35C` | `g_pTotemFrame` | TotemFrame support docs |
| `dword_67A840` | dynamic `AboveFrame` slot | [UID:0000JL] FrameChrome |

Recommended `GeneralPurposePanel` fields:

| Offset | Recommended name | Evidence |
|---:|---|---|
| `+0x00` | vptr | vtable stores to `0x0061a888` |
| `+0x04..+0x1c` | `m_childPanes[7]` | seven constructor child stores; `0x04` to `0x1c` are 4 to 28 bytes, verified with `int_convert.py` |
| `+0x20` | `m_activeChildIndex` | `0x20 = 32`, verified with `int_convert.py`; read by active-child accessor and FrameChrome dynamic `AboveFrame` builder |

`GeneralPurposePanel` child order:

| Index | Constructor target | Best source-quality child meaning |
|---:|---|---|
| 0 | `0x00565610` | self-look pane |
| 1 | `0x0059f260` | user-look / profile pane |
| 2 | `0x004eb420` | inventory pane |
| 3 | `0x0057cf70` | spell inventory pane |
| 4 | `0x0056ca20` | group pane |
| 5 | `0x0056e940` | collection pane |
| 6 | `0x0053ff90` | option / new option pane |

Recommended `GeneralPurposePanel2` fields:

| Offset | Recommended name | Evidence |
|---:|---|---|
| `+0x00` | vptr | vtable stores to `0x0061a898` |
| `+0x04` | `m_systemMessagePane` | single child constructed via `NewSystemMessagePane::NewSystemMessagePane()` at `0x00588560`; `0x04 = 4`, verified with `int_convert.py` |
| `+0x08` | `m_activeChildIndex` | initialized to `-1`; accepts only child index 0; `0x08 = 8`, verified with `int_convert.py` |

Recommended method/helper names:

| Address | Recommended name |
|---:|---|
| `0x004b83d0` | `GeneralPurposePanel::GeneralPurposePanel()` |
| `0x004b8580` | `GeneralPurposePanel::~GeneralPurposePanel()` |
| `0x004b85f0` | `GeneralPurposePanel::GetChildPaneByIndex(int index)` |
| `0x004b8620` | `GeneralPurposePanel::GetActiveChildPane()` |
| `0x004b8630` | `GeneralPurposePanel::RefreshActiveChild()`; current docs' `DispatchActiveChildRefresh` is behaviorally correct but less source-facing |
| `0x004b8650` | `GeneralPurposePanel::SwitchActiveTab(int tabIndex, bool showChild)` |
| `0x004b8830` | `GeneralPurposePanel2::GeneralPurposePanel2()` |
| `0x004b88f0` | `GeneralPurposePanel2::~GeneralPurposePanel2()` |
| `0x004b8950` | `GeneralPurposePanel2::GetChildPaneByIndex(int index)` |
| `0x004b89a0` | `GeneralPurposePanel2::SwitchActiveChild(int index, bool showChild)` |
| `0x004b8a80` | compiler cleanup helper for `g_pGeneralPurposePanel2` |
| `0x004b8a90` | compiler cleanup helper for `g_pGeneralPurposePanel` |
| `0x004b8aa0` | `GeneralPurposePanel2` scalar deleting destructor wrapper |
| `0x004b8b40` | `GeneralPurposePanel` scalar deleting destructor wrapper |

External helper name direction:

- `0x004b78d0`: RectBounds dependency, likely `RectBounds::SetLTRB` / `SetRectBounds`, not `GeneralPurposePanel` owned.
- `0x00544690`: `Pane::MarkForDeletion()`, deferred pane cleanup helper.
- `0x00544ee0`: inherited Pane hide/collapse helper for old child panes; exact final source name still belongs to PaneCore support.
- `0x004615b0`: FrameChrome release helper for the dynamic `AboveFrame` slot.
- `0x004615d0`: FrameChrome recreate helper for the dynamic `AboveFrame` slot.
- `0x004e9ee0`: `InterfaceEfxMgr::TriggerInterfaceEffect(int effectId)`.
- `0x00588560`: `NewSystemMessagePane::NewSystemMessagePane()`.

## Owner / Emitter / Source-File Routing

The correct route remains:

- [UID:00015V] aggregate memory page owner/emitter: [UID:0000JQ].
- [UID:00005Q] `GeneralPurposePanel` class owner/emitter: [UID:0000JQ].
- [UID:00005R] `GeneralPurposePanel2` class owner/emitter: [UID:0000JQ].
- [UID:0000R0] and [UID:0000R1] singleton globals emit through [UID:0000JQ].
- Source path: `NexusTK/ui/panels/GeneralPurposePanel.cpp`.

Do not route the following into `GeneralPurposePanel.cpp` as owned implementation:

- FrameChrome `AboveFrame` helpers at `0x004615b0` and `0x004615d0`: owner remains [UID:0000JL].
- Dynamic `AboveFrame` slot `0x0067a840`: owner remains [UID:0000JL] / FrameChromeSlots.
- `NewSystemMessagePane` implementation and related globals: owner remains [UID:0000OE] `SystemMessagePanes`.
- `InterfaceEfxMgr::TriggerInterfaceEffect`: owner remains [UID:00018H].
- Pane lifecycle/base helper implementations: owner remains PaneCore.
- RectBounds helper implementation: owner remains RectBounds.
- TotemFrame singleton and implementation: owner remains TotemFrame support docs.

## FrameChrome / AboveFrame Interaction

`GeneralPurposePanel::SwitchActiveTab` and `GeneralPurposePanel2::SwitchActiveChild` call the FrameChrome release/recreate pair in the EPF/new-layout path:

```text
0x004b872e -> 0x004615b0
0x004b8733 -> 0x004615d0
0x004b8a62 -> 0x004615b0
0x004b8a67 -> 0x004615d0
```

This is a dependency relationship only. FrameChrome owns the dynamic `AboveFrame` slot and helper bodies.

The active child/frame-index issue resolves as follows:

- `GeneralPurposePanel::m_activeChildIndex` is stored at `this + 0x20`.
- FrameChrome's dynamic `AboveFrame` builder reads `g_pGeneralPurposePanel + 0x20`.
- The frame part/resource index is derived as `m_activeChildIndex + 5`.
- Therefore the active index is a `GeneralPurposePanel` tab/child index reused by FrameChrome, not a separate `AboveFrame` field.

Support docs that should be updated later:

- [UID:0000YI] should name the `g_pGeneralPurposePanel->m_activeChildIndex + 5` dependency explicitly.
- [UID:0000U2] already has the right dynamic-frame relationship; it should use the same field name.
- [UID:0000YI] has a range/title off-by-one concern noted by B007: the recreate helper body is half-open through `0x00461658`, while the current path/title uses `0x00461657`.

## SystemMessagePanes Interaction

`GeneralPurposePanel2` is a one-child shell. Its constructor:

- Allocates `0x304` / 772 bytes for the child, verified with `int_convert.py`.
- Calls `0x00588560`, identified by [UID:0000OE] as `NewSystemMessagePane::NewSystemMessagePane()`.
- Stores the result in `this + 0x04`.
- Initializes `this + 0x08` active child index to `-1`.

This is composition. The `NewSystemMessagePane` class body and related globals remain in [UID:0000OE] `SystemMessagePanes`.

## Source Split / Child Page Needs

Existing child pages are directionally correct:

- [UID:00015W] should remain the child-accessor page for `0x004b85f0`, `0x004b8620`, and `0x004b8630`.
- [UID:00015X] should remain the `GeneralPurposePanel::SwitchActiveTab` page.
- [UID:00015Y] should remain the `GeneralPurposePanel2::SwitchActiveChild` page.
- [UID:00015Z] should remain non-reconstructable compiler/linker cleanup support.

Additional child pages are needed before first-draft C++ is clean:

- `0x004b83d0-0x004b857e.GeneralPurposePanelConstructor.md`
- `0x004b8580-0x004b85e3.GeneralPurposePanelDestructor.md`
- `0x004b8830-0x004b88e1.GeneralPurposePanel2Constructor.md`
- `0x004b88f0-0x004b8944.GeneralPurposePanel2Destructor.md`
- `0x004b8950-0x004b8969.GeneralPurposePanel2GetChildPaneByIndex.md`
- `0x004b8aa0-0x004b8b32.GeneralPurposePanel2ScalarDeletingDestructor.md`, preferably non-reconstructable/compiler-generated or vtable-support only.
- `0x004b8b40-0x004b8bd3.GeneralPurposePanelScalarDeletingDestructor.md`, preferably non-reconstructable/compiler-generated or vtable-support only.

The scalar deleting destructor pages should not hand-author source bodies. They are compiler wrappers regenerated from destructors, delete flags, vtable/RTTI emission, and allocator/delete helpers.

## Compiler-Generated / Raw-Name Reanalysis

Replace raw labels in prose and tables:

```text
sub_4B83D0 -> GeneralPurposePanel::GeneralPurposePanel()
sub_4B8580 -> GeneralPurposePanel::~GeneralPurposePanel()
sub_4B85F0 -> GeneralPurposePanel::GetChildPaneByIndex(int)
sub_4B8620 -> GeneralPurposePanel::GetActiveChildPane()
sub_4B8630 -> GeneralPurposePanel::RefreshActiveChild()
sub_4B8650 -> GeneralPurposePanel::SwitchActiveTab(int, bool)
sub_4B8830 -> GeneralPurposePanel2::GeneralPurposePanel2()
sub_4B88F0 -> GeneralPurposePanel2::~GeneralPurposePanel2()
sub_4B8950 -> GeneralPurposePanel2::GetChildPaneByIndex(int)
sub_4B89A0 -> GeneralPurposePanel2::SwitchActiveChild(int, bool)
sub_4B8A80 -> compiler cleanup helper clearing g_pGeneralPurposePanel2
sub_4B8A90 -> compiler cleanup helper clearing g_pGeneralPurposePanel
sub_4B8AA0 -> GeneralPurposePanel2 scalar deleting destructor wrapper
sub_4B8B40 -> GeneralPurposePanel scalar deleting destructor wrapper
```

Replace raw globals where they appear in target/support text:

```text
dword_67A874 -> g_pGeneralPurposePanel
dword_69B358 -> g_pGeneralPurposePanel2
byte_66DA97  -> g_useEpfAssets
dword_69B35C -> g_pTotemFrame
dword_67A840 -> FrameChrome dynamic AboveFrame slot
```

Keep raw names for unresolved external layer/context globals until their owner docs provide final names:

- `dword_67A740`
- `dword_69B368`

These are UI layer/context arguments consumed by pane show/layout calls, but their final aliases should come from MainUiLayerSlots or equivalent support docs, not this target.

## Heuristic / Inference Reanalysis And Validation

Heuristic issue: broad source-quality method/class inventory.

- Validation: local Capstone disassembly recovered exact half-open bodies, padding, calls, and vtable references inside the `0x803` / 2051-byte aggregate.
- Best-guess direction: [UID:00015V] should become a strong aggregate inventory page with explicit children, not a monolithic C++ source body.

Heuristic issue: source split or child-page needs.

- Validation: the aggregate contains two classes, already split accessor/switch/cleanup pages, unsplit constructor/destructor/accessor bodies, and compiler-generated scalar deleting destructors.
- Best-guess direction: create the constructor/destructor/accessor/scalar-deleting-destructor child pages listed above. Keep scalar deleting destructor pages non-source or compiler-support.

Heuristic issue: field/global names including active child/frame index fields.

- Validation: `this + 0x20` on `GeneralPurposePanel` is read by accessors and FrameChrome dynamic-frame builder; `this + 0x08` on `GeneralPurposePanel2` is the one-child active index. The seven child pointers occupy `+0x04..+0x1c`.
- Best-guess direction: use `m_childPanes[7]`, `m_activeChildIndex`, `m_systemMessagePane`, `g_pGeneralPurposePanel`, and `g_pGeneralPurposePanel2`. Document that FrameChrome derives `AboveFrame` id as `m_activeChildIndex + 5`.

Heuristic issue: owner/emitter/source-file route.

- Validation: by-file, by-class, by-global, and auto-generated coverage all route this family through [UID:0000JQ] `NexusTK/ui/panels/GeneralPurposePanel.cpp`. Generated source file currently contains only a placeholder.
- Best-guess direction: keep owner/emitter exactly as [UID:0000JQ]. Do not route child pane implementations or FrameChrome helpers into this file.

Heuristic issue: FrameChrome/AboveFrame interaction.

- Validation: `SwitchActiveTab` and `SwitchActiveChild` call `0x004615b0`/`0x004615d0`; FrameChrome support docs own those helpers and the `0x0067a840` dynamic slot.
- Best-guess direction: target docs should describe dependency and active-index handoff, while FrameChrome docs should own helper implementation and the off-by-one range repair.

Heuristic issue: compiler-generated/raw names.

- Validation: vtable slots, scalar deleting destructor shapes, cleanup-table jumps, and singleton clear helpers match generated code patterns.
- Best-guess direction: do not source-author [UID:00015Z] or scalar deleting destructor wrappers. Keep them as compiler-generated support and let source destructors plus vtables regenerate them.

Heuristic issue: first-draft C++ readiness.

- Validation: active gate is met, but the aggregate includes multiple child pages and generated wrappers. Existing child pages are close to first-draft C++ but still need method/member naming and PaneCore virtual-slot finalization.
- Best-guess direction: first-draft C++ should be produced on child pages and class/file docs, not in this aggregate page.

## Exact Aggregate No-Code Proof

[UID:00015V] should not emit a monolithic `RECONSTRUCTION_CPP` body even though it clears the active gate.

Proof:

1. The range contains two classes: `GeneralPurposePanel` and `GeneralPurposePanel2`.
2. The range already has exact source-bearing child pages for accessors and switch helpers: [UID:00015W], [UID:00015X], and [UID:00015Y].
3. The range includes compiler/linker-generated singleton clear helpers [UID:00015Z].
4. The range includes scalar deleting destructor wrappers at `0x004b8aa0` and `0x004b8b40`, which are compiler-generated and should not be hand-authored.
5. The range includes padding bytes between functions and at the aggregate end.
6. The switch helpers depend on external owners: FrameChrome, PaneCore, RectBounds, InterfaceEfx, and TotemFrame.
7. The `GeneralPurposePanel2` constructor composes a `NewSystemMessagePane`, but that child implementation is owned by [UID:0000OE].

Therefore a single parent C++ block would duplicate child pages, mix source-authored code with compiler wrappers, and overrun ownership boundaries. The correct source-quality result is an aggregate inventory plus child-page route, not parent-page code.

## Recommended Exact Doc Changes

Recommended target metadata replacement:

```text
COMPLETION:86
CONFIDENCE:91
```

Recommended target summary addition:

```text
[UID:00015V] is the aggregate memory span for the `GeneralPurposePanel.cpp` source unit's two side-panel shell classes, `GeneralPurposePanel` and `GeneralPurposePanel2`. The aggregate is source-bearing through [UID:0000JQ], but the parent memory page should not emit monolithic C++ because exact child pages own the accessor/switch helpers and additional constructor/destructor/scalar-deleting-destructor splits are required. `GeneralPurposePanel::m_activeChildIndex` at `this + 0x20` is also consumed by FrameChrome's dynamic `AboveFrame` refresh path as `m_activeChildIndex + 5`.
```

Recommended target function table replacement:

```text
| Range | Source-quality identity | Notes |
|---|---|---|
| `0x004b83d0-0x004b857e` | `GeneralPurposePanel::GeneralPurposePanel()` | Constructs the seven-child side-panel shell and writes `g_pGeneralPurposePanel`. |
| `0x004b8580-0x004b85e3` | `GeneralPurposePanel::~GeneralPurposePanel()` | Marks children for deferred deletion, clears singleton, chains base pane teardown. |
| `0x004b85f0-0x004b8617` | `GeneralPurposePanel::GetChildPaneByIndex(int index)` | Existing [UID:00015W]; EPF/new mode exposes seven children, legacy exposes four. |
| `0x004b8620-0x004b8630` | `GeneralPurposePanel::GetActiveChildPane()` | Existing [UID:00015W]; reads `m_activeChildIndex` at `this + 0x20`. |
| `0x004b8630-0x004b8644` | `GeneralPurposePanel::RefreshActiveChild()` | Existing [UID:00015W]; dispatches the active child's refresh/update virtual call. |
| `0x004b8650-0x004b8823` | `GeneralPurposePanel::SwitchActiveTab(int tabIndex, bool showChild)` | Existing [UID:00015X]; handles EPF/new frame refresh and legacy interface effects. |
| `0x004b8830-0x004b88e1` | `GeneralPurposePanel2::GeneralPurposePanel2()` | Constructs the one-child system-message shell and writes `g_pGeneralPurposePanel2`. |
| `0x004b88f0-0x004b8944` | `GeneralPurposePanel2::~GeneralPurposePanel2()` | Marks the system-message child for deferred deletion and clears singleton. |
| `0x004b8950-0x004b8969` | `GeneralPurposePanel2::GetChildPaneByIndex(int index)` | Returns the single `NewSystemMessagePane` child for index 0. |
| `0x004b89a0-0x004b8a7f` | `GeneralPurposePanel2::SwitchActiveChild(int index, bool showChild)` | Existing [UID:00015Y]; one-child switch/layout helper. |
| `0x004b8a80-0x004b8a8b` | compiler cleanup helper | Existing [UID:00015Z]; clears `g_pGeneralPurposePanel2`. |
| `0x004b8a90-0x004b8a9b` | compiler cleanup helper | Existing [UID:00015Z]; clears `g_pGeneralPurposePanel`. |
| `0x004b8aa0-0x004b8b32` | `GeneralPurposePanel2` scalar deleting destructor wrapper | Compiler-generated vtable target. |
| `0x004b8b40-0x004b8bd3` | `GeneralPurposePanel` scalar deleting destructor wrapper | Compiler-generated vtable target. |
```

Recommended target no-code rationale replacement:

```text
Formal aggregate C++ remains intentionally blank. This range clears the active source gate, but it is an aggregate over two classes, exact child helper pages, compiler cleanup helpers, scalar deleting destructor wrappers, vtable support, and padding. Emitting one monolithic C++ block here would duplicate [UID:00015W], [UID:00015X], [UID:00015Y], and [UID:00015Z] and would mix compiler-generated wrappers with source-authored methods. First-draft C++ should be emitted through [UID:00005Q] and [UID:00005R] child method pages into [UID:0000JQ] `NexusTK/ui/panels/GeneralPurposePanel.cpp`; this parent memory page should remain an inventory or `[[CHILDREN]]` aggregate only.
```

Recommended [UID:00015W] updates:

- Keep owner/emitter [UID:00005Q].
- Rename `DispatchActiveChildRefresh` to source-facing `RefreshActiveChild` unless existing naming consistency requires the current name.
- Name `this + 0x20` as `m_activeChildIndex`.
- Name `byte_66DA97` as `g_useEpfAssets`.

Recommended [UID:00015X] updates:

- Keep owner/emitter [UID:00005Q].
- Name method `GeneralPurposePanel::SwitchActiveTab(int tabIndex, bool showChild)`.
- Name `this + 0x20` as `m_activeChildIndex`.
- Name external helpers as FrameChrome release/recreate dynamic `AboveFrame` helpers.
- Name the legacy call `InterfaceEfxMgr::TriggerInterfaceEffect(m_activeChildIndex)`.
- Keep `0x004b78d0`, `0x00544690`, and `0x00544ee0` as external RectBounds/PaneCore dependencies pending final support names.

Recommended [UID:00015Y] updates:

- Keep owner/emitter [UID:00005R].
- Name `this + 0x04` as `m_systemMessagePane`.
- Name `this + 0x08` as `m_activeChildIndex`.
- Name method `GeneralPurposePanel2::SwitchActiveChild(int index, bool showChild)`.
- Keep FrameChrome helper calls as dependencies.

Recommended [UID:00015Z] updates:

- Keep `RECONSTRUCTABLE:FALSE`.
- Keep it non-emitting.
- Clarify that the helpers are cleanup-table/compiler-generated singleton-clear helpers for `g_pGeneralPurposePanel2` and `g_pGeneralPurposePanel`.

Recommended [UID:0000YI] / [UID:0000U2] support updates:

- Explicitly identify the source of the dynamic `AboveFrame` id as `g_pGeneralPurposePanel->m_activeChildIndex + 5`.
- Keep FrameChrome ownership for `0x004615b0`, `0x004615d0`, and `0x0067a840`.
- Review the `0x004615d0` helper end address and path/title mismatch: current evidence supports half-open `0x004615d0-0x00461658`.

Recommended [UID:0002VS] support update:

- Reconcile raw-file, static IDB, and live-IDB notes for `g_pGeneralPurposePanel2` storage. The raw PE initialized payload did not provide stable bytes for `0x0069b358`, so avoid using raw static bytes alone as source initializer evidence.

## Validator Needs

No validators were run because this assignment is report-only and no target/support documentation was edited.

If the supervisor sends an implementation callback, run validators after edits on at least:

_Executable command block removed from the research report; preserved in [00015V-GeneralPurposePanel-source-quality-removed.md](00015V-GeneralPurposePanel-source-quality-removed.md)._

Also validate any newly created constructor/destructor/scalar-deleting-destructor child pages.

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` directly. Let the supervisor or coverage tooling apply the replacement row below.

## Exact Pending Coverage Text

Exact replacement row for [UID:00015V]:

```text
    - [UID:00015V][0x004b83d0-0x004b8bd3.GeneralPurposePanel](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md) : reconstructable : 86% : very strong : B003 source-quality recheck preserves [UID:0000JQ] `GeneralPurposePanel.cpp` owner/emitter while proving target-specific no-monolithic-C++ handling: fresh local PE/Capstone scan confirms exact `0x803` / 2051-byte aggregate bounds (Verified with int_convert.py), half-open method inventory for `GeneralPurposePanel`, `GeneralPurposePanel2`, source-authored child access/switch helpers, compiler-generated singleton clear/deleting-destructor support, constructor callers `0x004f7ff7`/`0x004f8835` and `0x004f8020`, broad side-panel caller fan-in for `0x004b85f0`/`0x004b8650`, one-child `GeneralPurposePanel2` switch caller `0x005a771b`, vtable slots at `0x0061a888`/`0x0061a898`, `g_pGeneralPurposePanel` and `g_pGeneralPurposePanel2` lifecycle writes, `m_childPanes[7]` plus active index `+0x20` / 32 (Verified with int_convert.py), `GeneralPurposePanel2` single `NewSystemMessagePane` child and active index `+0x08` / 8 (Verified with int_convert.py), FrameChrome `AboveFrame` refresh dependency through `0x004615b0`/`0x004615d0`, legacy `InterfaceEfxMgr::TriggerInterfaceEffect` dependency at `0x004b880b`, and required child-page split/route before any formal aggregate C++ beyond an optional `[[CHILDREN]]` marker.
```

Support coverage rows observed stale during this pass:

- [UID:00015W] current coverage row still reports `84%`, while the page is now `85/91`.
- [UID:00015X] current coverage row still reports `84%`, while the page is now `85/91`.
- [UID:00015Y] current coverage row still says parent routing was below gate, while the page is now `86/90` with [UID:00005R] owner/emitter.
- [UID:00015Z] current coverage row still treats the cleanup helpers as reconstructable/owner-pending, while the page is now `RECONSTRUCTABLE:FALSE` and non-emitting.

## Open Questions

- Exact original source names for `GetChildPaneByIndex`, `GetActiveChildPane`, `RefreshActiveChild`, `SwitchActiveTab`, and `SwitchActiveChild` are not symbol-proven. The recommended names are source-facing best guesses from behavior and support-document convention.
- Exact names for the Pane virtual slots used by switch helpers at `+0x2c`, `+0x30`, `+0x3c`, `+0x40`, and `+0x48` still need PaneCore confirmation.
- Exact final name for `0x00544ee0` should come from PaneCore support docs; behavior is old-child hide/collapse.
- `dword_67A740` and `dword_69B368` should be named by their owning UI layer/context support docs before final C++.
- [UID:0000YI] `AboveFrameRefreshHelpers` needs range/title reconciliation around `0x00461657` versus half-open `0x00461658`.
- [UID:0002VS] static storage bytes for `g_pGeneralPurposePanel2` need raw-file/live-IDB reconciliation.

## Changed Files

Only this B-agent report was added:

```text
source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/00015V-GeneralPurposePanel-source-quality.md
```

No target by-memory page, support by-* page, auto-generated file, or coverage report was edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/00015V-GeneralPurposePanel-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:26","uid":"00015V"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00015V-GeneralPurposePanel-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/00015V-GeneralPurposePanel-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00015V"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
