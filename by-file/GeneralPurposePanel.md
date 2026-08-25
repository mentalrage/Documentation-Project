*** UID:0000JQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# GeneralPurposePanel

## Status

- Confidence: very strong for both panel classes, direct Singleton inheritance/layout, complete authored method order, singleton one-definition routes, compiler/vtable/padding exclusions, all alternate-global references, and `ui/panels/` placement; original spelling remains the only confidence cap.
- Proposed module: `ui/panels/GeneralPurposePanel.cpp`
- Primary classes: `GeneralPurposePanel` and `GeneralPurposePanel2`
- Main address doc: [UID:00015V][0x004b83d0-0x004b8bd3.GeneralPurposePanel](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md)

## Role

`GeneralPurposePanel.cpp` owns the in-game general-purpose panel shell that switches between major side-panel pages: self look, user look/profile, inventory, spell inventory, group, collection, and options. `GeneralPurposePanel2` is a smaller alternate shell with one child pane.

## Source-Quality Direction

This file emits the two shell class declarations and routes exact method bodies through child by-memory pages. [UID:00015V][0x004b83d0-0x004b8bd3.GeneralPurposePanel](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md) is a broad aggregate over both classes, source-authored methods, compiler cleanup helpers, scalar deleting destructor wrappers, vtable support, and padding, so it stays an inventory/no-monolithic-code page rather than a single C++ block.

The primary source order is [UID:0000R0][g_pGeneralPurposePanel](by-global/g_pGeneralPurposePanel.md) definition at position 0, [UID:00005Q][GeneralPurposePanel](by-class/GeneralPurposePanel.md) declaration at position 10, then exact method children UID0004UL constructor at 10, UID0004UM ordinary destructor at 20, UID00015W accessors at 30, and UID00015X tab switch at 40 within the class child insertion. Alternate order is [UID:0000R1][g_pGeneralPurposePanel2](by-global/g_pGeneralPurposePanel2.md) sole definition at file position 20, [UID:00005R][GeneralPurposePanel2](by-class/GeneralPurposePanel2.md) declaration at file position 30, then UID0004UU constructor/UID0004UV destructor/UID0004UW GetChild/UID0004UX GetActive/UID0004UY DispatchRefresh/UID00015Y Switch at child positions 10/20/30/40/50/60. Physical storage, UID00015Z Singleton base destructors, UID0004UZ/UID0004UN scalar wrappers, UID0003BD/UID0003BC vtable data, and UID00015V aggregate remain non-emitting.

Accepted source-facing names from the B003 source-quality pass:

- `GeneralPurposePanel::m_childPanes[7]` at offsets `+0x04..+0x1c`.
- `GeneralPurposePanel::m_activeChildIndex` at `+0x20`; FrameChrome consumes this as `g_pGeneralPurposePanel->m_activeChildIndex + 5` when rebuilding the dynamic `AboveFrame` slot.
- `GeneralPurposePanel2::m_childPanes[1]` at `+0x04`; constructor element zero is a concrete `NewSystemMessagePane`.
- `GeneralPurposePanel2::m_activeChildIndex` at `+0x08`.
- `GeneralPurposePanel::DispatchActiveChildRefresh`, `GeneralPurposePanel::SwitchActiveTab(int, const unsigned char *)`, and `GeneralPurposePanel2::SwitchActiveChild(int, const unsigned char *)` as source-facing method names pending symbol-level spelling proof. Earlier docs used `RefreshActiveChild` for `0x004b8630`; keep it as a descriptive alias only.

## Proposed Contents

| Structure | Address evidence | Role |
| --- | --- | --- |
| `GeneralPurposePanel` | [UID:0004UL][0x004b83d0-0x004b857e.GeneralPurposePanelConstructor](by-memory/0x004b83d0-0x004b857e.GeneralPurposePanelConstructor.md), [UID:0004UM][0x004b8580-0x004b85e3.GeneralPurposePanelDestructor](by-memory/0x004b8580-0x004b85e3.GeneralPurposePanelDestructor.md), [UID:0004UN][0x004b8b40-0x004b8bd3.GeneralPurposePanelScalarDeletingDestructor](by-memory/0x004b8b40-0x004b8bd3.GeneralPurposePanelScalarDeletingDestructor.md) | Direct `LObject` plus `Singleton<GeneralPurposePanel>` 0x24-byte seven-pane shell with one externally linked singleton definition. |
| `GeneralPurposePanel2` | UID0004UU-UID0004UZ plus UID00015Y/UID0003BD | Direct `LObject` plus `Singleton<GeneralPurposePanel2>` 12-byte one-pane shell with constructor/destructor/GetChild/GetActive/DispatchRefresh/Switch source methods, one external singleton definition, and compiler-only scalar/vtable support. |
| shared panel tab helpers | [UID:00015W][0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md), [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md) | IDA-confirmed child lookup, active-child refresh dispatch, and active-tab switching methods owned by the seven-child shell despite stale `SpellOneArgInputPane` generated ownership. The one-child `GeneralPurposePanel2` switch remains attached to the class row above. |
| singleton clear helpers | [UID:00015Z][0x004b8a80-0x004b8a9a.GeneralPurposePanelSingletonClearHelpers](by-memory/0x004b8a80-0x004b8a9a.GeneralPurposePanelSingletonClearHelpers.md) | Tiny global cleanup helpers for nearby panel singletons. |

Exact source/compiler split status:

| Split | Current route |
| --- | --- |
| [UID:0004UL][0x004b83d0-0x004b857e.GeneralPurposePanelConstructor](by-memory/0x004b83d0-0x004b857e.GeneralPurposePanelConstructor.md) / primary constructor | Complete authored seven-child direct-Singleton body, position 10. |
| [UID:0004UM][0x004b8580-0x004b85e3.GeneralPurposePanelDestructor](by-memory/0x004b8580-0x004b85e3.GeneralPurposePanelDestructor.md) / primary ordinary destructor | Complete authored seven-unconditional-deletion body, position 20. |
| [UID:0004UU][0x004b8830-0x004b88e1.GeneralPurposePanel2Constructor](by-memory/0x004b8830-0x004b88e1.GeneralPurposePanel2Constructor.md) | Complete one-child `NewSystemMessagePane` constructor; Singleton publication/vptr/EH are compiler lowering, position 10. |
| [UID:0004UV][0x004b88f0-0x004b8944.GeneralPurposePanel2Destructor](by-memory/0x004b88f0-0x004b8944.GeneralPurposePanel2Destructor.md) | Complete unconditional child deletion request; Singleton clear/LObject teardown are implicit, position 20. |
| [UID:0004UW][0x004b8950-0x004b8969.GeneralPurposePanel2GetChildPaneByIndex](by-memory/0x004b8950-0x004b8969.GeneralPurposePanel2GetChildPaneByIndex.md) | Complete upper-bound-only one-child accessor, position 30. |
| [UID:0004UX][0x004b8970-0x004b8980.GeneralPurposePanel2GetActiveChildPane](by-memory/0x004b8970-0x004b8980.GeneralPurposePanel2GetActiveChildPane.md) | Complete retained `-1`-sentinel active-child accessor, position 40. |
| [UID:0004UY][0x004b8980-0x004b8994.GeneralPurposePanel2DispatchActiveChildRefresh](by-memory/0x004b8980-0x004b8994.GeneralPurposePanel2DispatchActiveChildRefresh.md) | Complete retained active-child `InvalidateRect(NULL)` dispatcher, position 50. |
| [UID:00015Y][0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md) | Complete accepted one-child activation/layout switch, position 60. |
| [UID:0004UZ][0x004b8aa0-0x004b8b32.GeneralPurposePanel2ScalarDeletingDestructor](by-memory/0x004b8aa0-0x004b8b32.GeneralPurposePanel2ScalarDeletingDestructor.md) and [UID:0004UN][0x004b8b40-0x004b8bd3.GeneralPurposePanelScalarDeletingDestructor](by-memory/0x004b8b40-0x004b8bd3.GeneralPurposePanelScalarDeletingDestructor.md) | Exact false/non-emitting compiler scalar deleting destructors; ordinary UID0004UV/UID0004UM remain sole authored bodies. |

## Boundaries

- C163: preserve `[0x004b83c5,0x004b83d0)` as the exact predecessor boundary before `GeneralPurposePanel`: eleven `cc` bytes, zero inbound xrefs, alignment/padding only, and no authored source emission.
- Keep [UID:0000ME][PanelPane](by-file/PanelPane.md) in `ui/core`; it is a reusable base for many panel classes and is constructed by `NewOptionPane`, group panes, and other features. It is not a base of GeneralPurposePanel: RTTI, base-constructor calls, PMD, EBO, and the exact 0x24-byte layout prove direct `LObject` plus `Singleton<GeneralPurposePanel>` instead.
- Keep `NewOptionPane` in [UID:0000M7][OptionPane](by-file/OptionPane.md); `GeneralPurposePanel` constructs it but does not own option-page internals.
- Keep `UserPane`, `UserLookPane`, inventory, spell inventory, group, and collection panes in their feature files. The general panel shell owns composition and page switching, not the full implementation of every child page.
- Keep [UID:0000PN][FrameChromeSlots](by-global/FrameChromeSlots.md) and [UID:0000YI][0x004615b0-0x00461658.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md) with [UID:0000JL][FrameChrome](by-file/FrameChrome.md). `GeneralPurposePanel` calls the refresh pair after switching tabs and supplies `m_activeChildIndex`, but that pair releases/rebuilds frame-chrome pane state.

## Evidence

- IDA confirms `GeneralPurposePanel::GeneralPurposePanel` at `0x004b83d0-0x004b857e`, with callers at `0x004f7ff7` and `0x004f8835`.
- Both callers allocate `0x24` bytes. Decorated RTTI/CHD entries contain `GeneralPurposePanel`, `LObject`, and `Singleton<GeneralPurposePanel>` only; Singleton PMD `{4,-1,0}` proves EBO over `m_childPanes[0]`.
- [UID:00028X][0x0067a874-0x0067a878.g_pGeneralPurposePanel](by-memory/0x0067a874-0x0067a878.g_pGeneralPurposePanel.md) is four loader-zeroed bytes with 87 refs, five compiler/template lifetime writes, and 82 reads. UID0000R0 supplies the only typed zero definition and UID00005Q one extern declaration.
- IDA confirms `GeneralPurposePanel2::GeneralPurposePanel2` at `0x004b8830-0x004b88e1`, with caller at `0x004f8020`.
- IDA decompilation of the constructor shows seven owned child pointers in `GeneralPurposePanel`, in index order: `0` self look, `1` user look/profile, `2` inventory, `3` spell inventory, `4` group, `5` collection, and `6` option.
- IDA decompilation of `0x004b85f0`, `0x004b8620`, `0x004b8630`, and `0x004b8650` shows child lookup, active child retrieval, active child refresh, and active tab switching over the same child array.
- IDA xrefs show `0x004b8650` calls [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md) trigger helper `0x004e9ee0` when switching or refreshing panel tabs in the old interface-effect path.
- IDA MCP confirms the new-layout tab switch path calls [UID:0000YI][0x004615b0-0x00461658.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md): `0x004615b0` releases the dynamic `AboveFrame` slot and the adjacent creator rebuilds it into `0x0067a840` using `g_pGeneralPurposePanel->m_activeChildIndex + 5`.
- 2026-05-25 IDA MCP recheck confirms `0x004b89a0` is a real `GeneralPurposePanel2` one-child switch helper and `0x004b8a80` / `0x004b8a90` are singleton clear helpers for `g_pGeneralPurposePanel2` / `g_pGeneralPurposePanel`.
- 2026-05-25 macro/profile follow-up uses this child index map to resolve [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) state labels: index `3` / spell inventory writes state `2` / `.usr` `S`, and index `2` / inventory writes state `3` / `.usr` `I`.
- Batch 118 live IDA `py_eval` rechecked `GeneralPurposePanel2` constructor `0x004b8830-0x004b88e1` and switch helper `0x004b89a0-0x004b8a7f`, including the final `retn 8` byte. The switch helper has one caller at `0x005a771b`, uses the one-child slot initialized by the constructor, and depends on FrameChrome only through the post-switch refresh pair.
- 2026-06-16 A002 live IDA MCP refresh on session `c001_midiplayer_rdata_20260615` reconfirmed the current helper boundaries and owner decision: `lookup_funcs` returns `0x004b85f0` size `0x27`, `0x004b8620` size `0x10`, `0x004b8630` size `0x14`, and `0x004b8650` size `0x1d3`; `xrefs_to` returns broad side-panel caller fan-in for `0x004b8650` with 35 code refs and active-child helper refs from screen/user-pane flows; decompilation shows `this[8]` as the active child index, `this[index + 1]` as the child array, EPF/new-layout limit `7`, legacy limit `4`, and no spell-input local state. Vtable data refs at `0x0061a888` and `0x0061a898` still come only from the `GeneralPurposePanel` and `GeneralPurposePanel2` constructor/destructor/scalar-destructor paths.
- 2026-06-20 B003 local binary research verified the aggregate is `0x803` / 2051 bytes, confirmed the adjacent vtable records at `0x0061a884` and `0x0061a894`, found `GeneralPurposePanel` vtable stores from `0x004b842e`, `0x004b85a9`, and `0x004b8b73`, found `GeneralPurposePanel2` vtable stores from `0x004b888e`, `0x004b8917`, and `0x004b8ac7`, and preserved FrameChrome, SystemMessagePanes, PaneCore, RectBounds, InterfaceEfx, and TotemFrame as dependencies rather than owned bodies.

## GeneralPurposePanel2 Complete Evidence

- RTTI has exactly `GeneralPurposePanel2`, direct `LObject`, and direct `Singleton<GeneralPurposePanel2>` entries. Singleton PMD `{4,-1,0}`, 12-byte allocation, `m_childPanes[0]` at `+0x04`, and `m_activeChildIndex` at `+0x08` prove EBO and reject historical `PanelPane` inheritance.
- The physical slot UID0002VS is four loader-zero bytes in `.data` virtual tail. UID0000R1 owns one external zero definition, UID00005R one extern, and compiler direct-Singleton lowering supplies publication/clear.
- Exactly 14 refs comprise five writes at `0x004b8872`, `0x004b8879`, `0x004b8925`, `0x004b8a80`, `0x004b8adc` and nine reads at `0x005049ee`, `0x0050fef7`, `0x005a7711`, `0x005a792e`, `0x005a7ed5`, `0x005a7fb9`, `0x005a9143`, `0x005aac2b`, `0x005aacda`.
- Exact alternate hashes: constructor `F807DB74...5CBA`, ordinary destructor `9FE98A30...BAA9`, GetChild `776C2ED1...2512`, GetActive `F4397739...FD86`, DispatchRefresh `D5329704...CBA0`, switch `3E97C0CF...7D24`, scalar wrapper `BDA7F0D9...CC58`, and vtable `82C6C54C...D524`.
- Exact compiler alignment is preserved at `0x004b8823-0x004b8830`, `0x004b88e1-0x004b88f0`, `0x004b8944-0x004b8950`, `0x004b8969-0x004b8970`, `0x004b8994-0x004b89a0`, `0x004b8a7f-0x004b8a80`, `0x004b8a8b-0x004b8a90`, `0x004b8a9b-0x004b8aa0`, and `0x004b8b32-0x004b8b40`; no padding emits source.
- MapPane/UserPane/SystemMessagePanes are consumers/dependencies only. Compiler publication/clear, vptr/EH, base teardown, scalar flags/delete, RTTI/vtable bytes, raw labels, monolithic aggregate source, `0xffffffff` initialization, and consumer-owned definitions are excluded.

## Caveats

The 2026-06-16 focused owner review resolves the old `SpellOneArgInputPane` helper-placement blocker for `0x004b85f0-0x004b8822`; these helpers belong with `GeneralPurposePanel`. The accepted B003 AboveFrame pass names the active-index member `m_activeChildIndex` at `+0x20` / raw `this[8]`, and the B005 UID00015X pass preserves `m_childPanes[7]` as the child-array name.

B005 historically narrowed the remaining `SwitchActiveTab` blockers. The 2026-07-13 B004 pass resolves them: [UID:0004KU][0x00544ee0-0x00544f2e.PaneCollapse](by-memory/0x00544ee0-0x00544f2e.PaneCollapse.md) is `Pane::Collapse`, inherited `+0x0c` is `UpdateRenderRegion`, and inherited `+0x48` is the common `OnActivate(const unsigned char *packetData)` contract. UID00015X and UID00015Y now carry exact managed bodies rather than blank emitters.

The active switch helper at `0x004b89a0-0x004b8a7f` stays with `GeneralPurposePanel2` and emits as `GeneralPurposePanel2::SwitchActiveChild`.

## 2026-07-13 B004 Accepted Source-Unit Reconciliation

- Source placement remains `NexusTK/ui/panels/GeneralPurposePanel.cpp`. No new file or feature-owner route is introduced.
- [UID:00005Q][GeneralPurposePanel](by-class/GeneralPurposePanel.md) and [UID:00005R][GeneralPurposePanel2](by-class/GeneralPurposePanel2.md) close their class declarations before `[[CHILDREN]]` so exact by-memory definitions are emitted at file scope.
- UID00015X and UID00015Y use nullable `const unsigned char *packetData` activation arguments. Derived Pane-family `+0x48` implementations either consume packet data or ignore it; `bool showChild` is superseded.
- The primary shell keeps `Pane *m_childPanes[7]` and `m_activeChildIndex` at `+0x20`. The alternate shell uses `Pane *m_childPanes[1]` and `m_activeChildIndex` at `+0x08` while preserving concrete NewSystemMessagePane construction at element zero.
- UID00015X preserves EPF/current limit seven, legacy limit four, same-tab exceptions for indexes zero/one, old-child collapse before active-index store, two exact rectangles, unconditional EPF activation, conditional legacy activation, FrameChrome refresh only in EPF mode, and legacy InterfaceEfx trigger.
- UID00015Y preserves upper-bound-only `>=1` rejection, `-1` sentinel, active-index store before old-child collapse, exact `(832,376,1021,641)` bounds, optional child activation, and unconditional FrameChrome refresh.
- [UID:00015V][0x004b83d0-0x004b8bd3.GeneralPurposePanel](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md) is a non-emitting split/index over both classes, exact source children, compiler wrappers, vtable support, singleton helpers, and padding. It remains the source-unit inventory without a monolithic body.
- PaneCollapse, RectBounds, TotemFrame, g_pBackPane, MainUiLayerSlots, FrameChrome, InterfaceEfx, UserPane, and derived Pane implementations are dependencies. Their definitions remain in established owners.
- Historical SpellOneArgInputPane generated ownership, singular alternate child field, bool activation, unresolved helper/slot blockers, and aggregate monolithic emission are retained only as rejected/superseded evidence.
- Score `89/91` reflects exact switch bodies, corrected declarations, generated placement shape, owner/emitter route, dependencies, and history. Constructor/destructor splits and original spelling certainty remain caps.

Frame-refresh helpers `0x004615b0/0x004615d0` and the legacy interface-effect trigger `0x004e9ee0` remain external dependencies, not ownership evidence for moving this file out of `ui/panels/`. No B-agent escalation is indicated by the current evidence.

## 2026-07-20 UID00028X Source-Unit Reconciliation

- File metadata is `90/92`; the by-file root remains prose-only and intentionally has no reconstruction metadata or managed C++.
- UID00005Q now carries the complete direct `LObject` plus `Singleton<GeneralPurposePanel>` declaration, exact seven-pointer-plus-index layout, virtual destructor, one extern, and class closure before `[[CHILDREN]]`.
- UID0000R0 emits the sole zero-initialized definition at file position 0. UID00028X is physical backing only, so the one-definition rule is explicit and verifiable.
- Primary authored order is UID0004UL constructor, UID0004UM ordinary destructor, UID00015W accessors, and UID00015X switch. Their exact hashes, ranges, padding, calls, fields, and source bodies are documented on the child pages.
- UID00015Z comprises two compiler Singleton base destructors; UID0004UN is the primary scalar deleting wrapper; UID0003BC is class-owned source-declared/generated-binary RTTI/vtable data. None emits handwritten ABI source.
- GeneralPurposePanel2 remains a separate comparator with its current accepted class/global/storage/switch route unchanged; no target callback result is claimed for that sibling.
- Historical `PanelPane` inheritance, static `0xffffffff`, manual singleton assignment/clear, SpellOneArgInputPane helper ownership, bool activation, unresolved primary split, monolithic aggregate emission, raw scalar/vtable source, and consumer-owned definitions remain explicitly rejected or superseded.

## 2026-07-21 UID0002VS Alternate Source-Unit Reconciliation

- Raised file metadata `90/92 -> 92/94` after completing the alternate direct-base class/global/source/compiler split; this by-file root remains prose-only with no reconstruction metadata.
- Serially registered UID0004UU-UID0004UZ and linked the complete six authored-method order plus false scalar wrapper. UID00015Y's body/score remain exact, now at child position 60; UID00015Z remains byte-for-byte false/no-code.
- UID0000R1 emits the sole GP2 zero definition at file position 20 and UID00005R emits the direct-base class/extern at position 30. UID0002VS/UID0003BD/UID0004UZ/UID00015V remain false/non-emitting.
- Preserved the complete primary family, all dependencies, caller/consumer facts, padding, vtable evidence, and historical alternatives while superseding the 2026-07-20 statement that GP2 remained merely a comparator.

## Cross References

- [UID:00005Q][GeneralPurposePanel](by-class/GeneralPurposePanel.md)
- [UID:00005R][GeneralPurposePanel2](by-class/GeneralPurposePanel2.md)
- [UID:0000ME][PanelPane](by-file/PanelPane.md)
- [UID:0000M7][OptionPane](by-file/OptionPane.md)
- [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)
- [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- [UID:0000PN][FrameChromeSlots](by-global/FrameChromeSlots.md)
- [UID:0000YI][0x004615b0-0x00461658.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md)
- [UID:00015V][0x004b83d0-0x004b8bd3.GeneralPurposePanel](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md)
- [UID:0004UL][0x004b83d0-0x004b857e.GeneralPurposePanelConstructor](by-memory/0x004b83d0-0x004b857e.GeneralPurposePanelConstructor.md)
- [UID:0004UM][0x004b8580-0x004b85e3.GeneralPurposePanelDestructor](by-memory/0x004b8580-0x004b85e3.GeneralPurposePanelDestructor.md)
- [UID:00015W][0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md)
- [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md)
- [UID:0004UN][0x004b8b40-0x004b8bd3.GeneralPurposePanelScalarDeletingDestructor](by-memory/0x004b8b40-0x004b8bd3.GeneralPurposePanelScalarDeletingDestructor.md)
- [UID:0003BC][0x0061a884-0x0061a894.GeneralPurposePanelVtableData](by-memory/0x0061a884-0x0061a894.GeneralPurposePanelVtableData.md)
- [UID:00015Y][0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md)
- [UID:0000R0][g_pGeneralPurposePanel](by-global/g_pGeneralPurposePanel.md)
- [UID:0000R1][g_pGeneralPurposePanel2](by-global/g_pGeneralPurposePanel2.md)
- [UID:0004UU][0x004b8830-0x004b88e1.GeneralPurposePanel2Constructor](by-memory/0x004b8830-0x004b88e1.GeneralPurposePanel2Constructor.md)
- [UID:0004UV][0x004b88f0-0x004b8944.GeneralPurposePanel2Destructor](by-memory/0x004b88f0-0x004b8944.GeneralPurposePanel2Destructor.md)
- [UID:0004UW][0x004b8950-0x004b8969.GeneralPurposePanel2GetChildPaneByIndex](by-memory/0x004b8950-0x004b8969.GeneralPurposePanel2GetChildPaneByIndex.md)
- [UID:0004UX][0x004b8970-0x004b8980.GeneralPurposePanel2GetActiveChildPane](by-memory/0x004b8970-0x004b8980.GeneralPurposePanel2GetActiveChildPane.md)
- [UID:0004UY][0x004b8980-0x004b8994.GeneralPurposePanel2DispatchActiveChildRefresh](by-memory/0x004b8980-0x004b8994.GeneralPurposePanel2DispatchActiveChildRefresh.md)
- [UID:0004UZ][0x004b8aa0-0x004b8b32.GeneralPurposePanel2ScalarDeletingDestructor](by-memory/0x004b8aa0-0x004b8b32.GeneralPurposePanel2ScalarDeletingDestructor.md)
- [UID:0003BD][0x0061a894-0x0061a8a4.GeneralPurposePanel2VtableData](by-memory/0x0061a894-0x0061a8a4.GeneralPurposePanel2VtableData.md)

## Changes

- 2026-07-21 B005 accepted UID0002VS callback: raised `90/92 -> 92/94`; preserved the complete primary family; added the alternate direct LObject/Singleton class, sole global/extern, UID0004UU-UID0004UZ splits, exact source order, all 14 refs, loader-zero one-definition proof, PMD/EBO/layout, hashes/padding, consumer/dependency boundaries, compiler exclusions, negative evidence, and superseded sibling assumptions without by-file formal metadata.
- 2026-07-20 B002 UID00028X accepted callback: raised `89/91 -> 90/92`; preserved the prose-only by-file root; incorporated sole definition/extern policy, direct LObject/Singleton hierarchy, PMD/EBO/0x24 layout, real primary constructor/destructor/scalar children, exact source order, compiler exclusions, physical/global storage route, sibling boundary, historical alternatives, and complete no-duplicate source plan without adding by-file reconstruction metadata.
- 2026-07-13 B004 accepted UID00015Y callback: raised `86/88 -> 89/91`; synchronized both pointer-valued switch signatures, the alternate one-element Pane array, UID0004KU Collapse and Pane activation contracts, exact child emission, non-emitting aggregate disposition, class-before-children placement, dependencies, negatives, and source route without changing the reconstruction path.
- 2026-06-20 B003 Rule 26 source-quality incorporation: added the source-split/no-monolithic-code direction for [UID:00015V][0x004b83d0-0x004b8bd3.GeneralPurposePanel](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md), accepted source-facing field names for both shell classes, documented constructor/destructor/accessor child-page needs, and preserved external ownership for FrameChrome, SystemMessagePanes, PaneCore, RectBounds, InterfaceEfx, and TotemFrame dependencies. File score unchanged because ownership and placement were already above gate; this is a detail/declaration-quality incorporation.
- 2026-07-08 B005 UID00015X implementation callback: kept file metadata unchanged; synced the `SwitchActiveTab` support caveat with current MCP evidence. `RectBounds::SetLTRB`, `Pane::MarkForDeletion`, `Pane::UnregisterEventHandler`, and Pane bounds/layer/order slots are now source-quality for prose, while helper `0x00544ee0` source spelling/declaration plus inherited `+0x0c` and `+0x48` remain the exact formal-C++ blockers for [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md).
- 2026-06-21 B007 ScreenPane palette-helper support sync: changed the preferred source-facing name for `0x004b8630` from `RefreshActiveChild` to `DispatchActiveChildRefresh`, retaining the older phrase as an alias only. This matches the method's role as the active-child refresh dispatcher called by `ScreenPane::HandleMessage` and [UID:0003A2][0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw](by-memory/0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md).
- 2026-06-20 B003 AboveFrame source-quality implementation: corrected the FrameChrome refresh helper link to `0x004615b0-0x00461658` and accepted `m_activeChildIndex` as the source-facing name for the active index used by the dynamic `AboveFrame` recreate helper. Ownership of the helper pair remains FrameChrome.
- 2026-06-20 B006 Rule 26 reconciliation: score unchanged; independently reconfirmed the same ownership boundary. `GeneralPurposePanel` owns `m_activeChildIndex`; FrameChrome owns the dynamic AboveFrame release/recreate helpers and reads the member only to choose the tab-frame index.
- 2026-06-16 A002 source-quality refresh:
  - Before: `COMPLETION:85`, `CONFIDENCE:86`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`.
  - Summary/evidence: live IDA MCP rechecked the primary and alternate panel constructors/destructors, `0x004b85f0/0x004b8620/0x004b8630` child accessors, `0x004b8650` tab switch, `0x004b89a0` one-child switch, singleton clears, vtable store refs, caller fan-in, and padding around the split boundaries. This resolves the remaining helper-owner review for the stale `SpellOneArgInputPane` pollution while preserving final source-name and shared-layout-helper caveats.
- 2026-06-08 A006 Batch 118 parent-gate repair:
  - Before: `COMPLETION:84`, `CONFIDENCE:80`.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:86`.
  - Summary/evidence: corrected the `GeneralPurposePanel2` switch-helper range to [UID:00015Y][0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md), moved it from under-review helper status into the `GeneralPurposePanel2` class row, and recorded the fresh IDA boundary/caller/field evidence. Remaining uncertainty is final public method naming and higher-level user-message semantics, not source-file ownership.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:80`.
  - Summary/evidence: panel shell responsibility, child composition/index map, tab switching helpers, singleton clears, frame-chrome/interface effect boundaries, and ownership caveats are documented; confidence remains below 100 because final folder and helper ownership still need focused review.
- 2026-06-05 reconstruction path classification:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, leaving the file row in error.
  - Changed to: `NexusTK/ui/panels/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `GeneralPurposePanel.cpp` under `NexusTK/ui/panels/`, and live IDA MCP xrefs/decompilation confirm `0x004b83d0`, `0x004b8580`, `0x004b8830`, `0x004b88f0`, `0x004b8a80`, `0x004b8a90`, and `0x004b8b40` write/clear the two panel singleton globals in this file's lifecycle island.
