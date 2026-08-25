*** UID:0000O1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/inventory/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# SpellInventoryPane

## UID0000O1 Accepted Whole-File Reconstruction - 2026-08-22

This file root reconstructs exactly the legacy `SpellInventoryPane` and alternate `SpellInventoryPane2` classes in `NexusTK/ui/inventory/SpellInventoryPane.cpp` and `SpellInventoryPane.h`. [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md) and [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md) remain separate accepted compilation units; physical adjacency and the private-scrollbar relationship do not merge either unit into this one.

Source emission is deterministic: [UID:0000DN][SpellInventoryPane](by-class/SpellInventoryPane.md) supplies the CPP preamble, complete legacy definitions, and the opening H fragment at position `010`; [UID:0000DO][SpellInventoryPane2](by-class/SpellInventoryPane2.md) supplies `[[CHILDREN]]` and the closing H fragment at position `020`; Pane2 source-bearing children emit definitions at positions `100` through `240`. The legacy [UID:0002RI][0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers](by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md), Pane2 [UID:0002RK][0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md), broad [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md), compiler [UID:0002RL][0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors](by-memory/0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors.md), and mixed-rdata [UID:00026J][0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData](by-memory/0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData.md) pages are non-emitting indexes or compiler/data evidence.

The whole-file inventory covers 30 source definitions: 15 legacy definitions from UID0000DN and 15 Pane2 definitions from exact children UID00044D/E/F/G/I/J/K/L/M/N/O/P/Q/R/S. UID00044H remains a protected one-byte no-route nullsub with blank CPP/H and no invented declaration. All code gaps, the legacy and Pane2 eight-entry switch tables, adjustor thunks, scalar deleting destructors, RTTI/vtables, alignment, and padding have explicit compiler/no-code dispositions.

Dependencies stay externally owned: `PanelPane`, `Event`, `RectBounds`, `InterfaceEfx`, `UserPane` spell records, prompt/target-selection panes, map objects, packet/socket support, rendering libraries, configuration, and UI globals are included or forward-declared only. [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md) is physically embedded in the legacy address island but remains owned by [UID:0000DM][SpellInputPaneState](by-class/SpellInputPaneState.md) and emits through `TargetSelectionInputPanes.cpp`; it is not target-owned source.

Target read-only data emits through source constructs rather than raw arrays: legacy `L"SPELLINV.EPD"` and `L"%c: %s"`, Pane2 `L"SPELLINV.EPF"`, and the Pane2 initial `RectBounds {12,20,22,41}`. `MAGEFX.EPD`, `INTEFX.PAD`, `SPELLBUT.EPD`, `NPAL6.PAL`, and `ITEMINV.PAL` remain external resource dependencies. No target-owned global or static storage definition was discovered; anonymous namespace values are compile-time source constants only.

Historical validator command `000000026432` produced an incomplete CPP and no physical H. That receipt is immutable history, not current generated proof. Mutable generated CPP/H state is established only by fresh validator output and supervisor Gate 2A physical readback; generated files are never edited directly.

## Status

- Confidence: very strong for the complete two-class source inventory, `ui/inventory/` placement, exact owner/emitter routes, formal CPP/H, vtable/compiler coverage, and all method/helper boundaries; original private spellings and direct constructor entry routes remain unavailable.
- Proposed module folder: `ui/inventory/`
- Target files: `ui/inventory/SpellInventoryPane.cpp` and `ui/inventory/SpellInventoryPane.h` only. `NewSpellInventoryPane.cpp/.h` and `ScrollSpellInventoryPane.cpp/.h` are separate compilation units.
- Current canonical target outputs are `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.cpp` and `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.h`; legacy `SpellInventoryPane` and alternate `SpellInventoryPane2` share this file root. The excluded units have separate current outputs at `auto-generated/NexusTK/ui/inventory/NewSpellInventoryPane.cpp`, `auto-generated/NexusTK/ui/inventory/NewSpellInventoryPane.h`, `auto-generated/NexusTK/ui/inventory/ScrollSpellInventoryPane.cpp`, and `auto-generated/NexusTK/ui/inventory/ScrollSpellInventoryPane.h`. Earlier `class_SpellInventoryPane.cpp`, `class_SpellInventoryPane2.cpp`, `class_NewSpellInventoryPane.cpp`, and `class_ScrollSpellInventoryPane.cpp` names are historical/nonexistent and are not current generated routes.
- B008 split status: [UID:0002RK][0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md) is now a non-emitting split/index parent. Exact `SpellInventoryPane2` children [UID:00044D][0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor](by-memory/0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md) through [UID:00044S][0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot](by-memory/0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot.md) emit through [UID:0000DO][SpellInventoryPane2](by-class/SpellInventoryPane2.md) into this file root.
- Evidence basis: existing documentation plus targeted IDA MCP boundary, caller/callee, vtable, and raw-byte checks on 2026-05-23 and 2026-06-01.

## Hypothesis

The spell inventory panes are the spell-side counterpart to the item inventory module. They display learned spells from player data, handle page or scroll navigation, and dispatch spell activation to direct-cast paths or spell-specific input panes.

The accepted current structure is:

```text
ui/inventory/SpellInventoryPane.cpp
ui/inventory/SpellInventoryPane.h
```

The target contains legacy `SpellInventoryPane` plus `SpellInventoryPane2`; NewSpell and Scroll are explicitly excluded and stay under their own file roots.

[UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md) is now a non-emitting physical split/index, not a source file output unit. It spans legacy `SpellInventoryPane`, `NewSpellInventoryPane`, `SpellInventoryPane2`, embedded shared input-state helpers, and compiler destructor glue. Exact child pages and class/file pages carry source routing; the broad parent should not emit C++ or force all children through this file root.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `SpellInventoryPane` | legacy core [UID:0002RI][0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers](by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md) plus non-contiguous scalar-wrapper refs in [UID:0002RL][0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors](by-memory/0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors.md) | `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.cpp`; declaration in `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.h` | Legacy spell inventory pane with page display, [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md), mouse selection, and close-message handling. The scalar deleting destructor wrapper is compiler output, while ordinary cleanup is represented by the non-scalar destructor in the legacy core child. |
| `NewSpellInventoryPane` | `0x0057cf70-0x0057f636` | separate [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md) | Excluded separate compilation unit; adjacency is index evidence only. |
| `SpellInventoryPane2` | `0x0057ea60-0x0057f694` | `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.cpp`; declaration in `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.h` | Alternate grid/page spell inventory variant. The broad [UID:0002RK][0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md) page is a non-emitting index; exact source-bearing child pages [UID:00044D][0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor](by-memory/0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md) through [UID:00044S][0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot](by-memory/0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot.md) now cover constructor, destructor, methods, dispatcher, and local helpers. |
| `ScrollSpellInventoryPane` | `0x0055f450-0x005608fc` | separate [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md) | Excluded separate private/companion scrollbar compilation unit. |

## Behavior Summary

- Legacy spell inventory displays up to 13 spells per page and uses Page Up/Page Down plus scroll buttons.
- New spell inventory scans the global spell table, supports normal 13-row and expanded 26-row modes, and uses a child scrollbar.
- Legacy `SpellInventoryPane::ActivateSpellSlot` dispatches one-based spell slots `1..52` through different input panes, targeted-action sending, or direct-cast paths based on the local-player spell record route/type field.
- B007 2026-06-19 reanalysis corrects the legacy record view to `g_pUserPane + 0x13a6ec + 0x148 * slot`, with record-local `+0` as learned/active and `+4` as the route/type field. Older `+0x13a82c` spell-record wording should not be reused for this body without a new byte proof.
- B011 2026-06-21 parent split/index recheck keeps generated `SpellManager` / `g_pSpellMan` interpretations rejected. `dword_67A748` / `g_pCollectionData` should be documented as the local-player/UserPane state pointer with spell typed views, and prompt/helper names should remain descriptive until a broader spell-type/packet pass resolves original enum names.
- The shared display helper at `0x005a4090` should use the descriptive working name `SlotIndexToHotkeyLetter` for spell inventory paint prose until an exact active page recovers the original spelling. [UID:0001PI][0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable](by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md) slot 7 / `dword_69B3FC` is likewise a render dependency, not a spell-inventory owner.
- The legacy child's `0x0057cc42-0x0057ccd0` span is mixed: dispatcher alignment, eight-entry jump table, padding, and retained no-route direct-spell packet helper at `0x0057cc70-0x0057ccd0`. `0x0057cd60-0x0057cdb3` and `0x0057cdc0-0x0057ce68` are also retained no-route row/page helper bodies, not padding.
- B008 2026-06-26 split implementation converts [UID:0002RK][0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md) into a non-emitting `SpellInventoryPane2` split/index and creates exact child pages [UID:00044D][0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor](by-memory/0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md) through [UID:00044S][0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot](by-memory/0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot.md). Reconstructable children route through [UID:0000DO][SpellInventoryPane2](by-class/SpellInventoryPane2.md) into this file root; [UID:00044H][0x0057eaf0-0x0057eaf1.SpellInventoryPane2SourceEmptyVirtual](by-memory/0x0057eaf0-0x0057eaf1.SpellInventoryPane2SourceEmptyVirtual.md) is source-empty/no-code. `+0xf9` is now `m_isLastPage`, not `m_hasNextPage`: paint sets it true and clears it when a later learned spell exists; page-down and next-page button logic advance only while it is false.
- `SpellInventoryPane2` prompt dependencies stay separated from source ownership: [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md) owns string/number/spell-slot prompt pane classes, target-selection docs own who/target prompt support, socket/packet docs own the queue/send funnel, and `UserPane`/global support docs own spell-record storage. The dispatcher and UI geometry helpers remain `SpellInventoryPane2` source behavior in this file family.
- Scrollbar code mirrors item scrollbar behavior but has separate addresses, owner classes, and helper names.

## IDA MCP Evidence

Targeted checks on 2026-05-23 and 2026-06-01 confirmed:

- `0x0057c2d0-0x0057c39f`, `0x0057c450-0x0057c710`, and `0x0057c790-0x0057c979` for legacy spell inventory construction, draw, and mouse handling.
- `0x0057cf70-0x0057d03f`, `0x0057d430-0x0057d8c4`, `0x0057d9c0-0x0057e18f`, and `0x0057e2d0-0x0057e56d` for the new spell inventory constructor, paint, mouse, and cast dispatcher.
- `0x0057eb00-0x0057eda4`, `0x0057ee30-0x0057eff7`, and `0x0057f640-0x0057f695` for the alternate spell inventory render, click, and destructor paths.
- `0x0055f450-0x0055f4f1`, `0x0055f890-0x0055ff70`, and `0x00560290-0x00560517` for the spell inventory scrollbar.
- IDA function inventory for `0x0057c2d0-0x0057f742` shows 55 function entries plus mixed compiler/support spans at `0x0057cc42-0x0057ccd0`, `0x0057e18f-0x0057e1b0`, `0x0057e56d-0x0057e620`, and `0x0057f26c-0x0057f490`. The NewSpell span is now split literally: `[0x0057e18f,0x0057e190)` is one byte of padding and `[0x0057e190,0x0057e1b0)` is the switch table; neither is uncovered or a handwritten source body.
- Vtable dword review at `0x0062d02c-0x0062d174` maps `SpellInventoryPane`, `NewSpellInventoryPane`, and `SpellInventoryPane2` virtual slots directly back into this executable island.
- Batch 250 live IDA review on 2026-06-12 proves `SpellInventoryPane2` has raw constructor/setup code at `0x0057ea60-0x0057ea9f`: it calls the `PanelPane` constructor helper, stores vtables `0x0062d0f4`, `0x0062d144`, and `0x0062d174`, and clears page/state fields before the IDA-defined reset/helper functions begin.
- The same review splits the previous broad non-padding span `0x0057f26c-0x0057f490` into an eight-entry `sub_57F030` jump table, alignment, and raw local helper bodies for direct-cast packets and page/row geometry.
- B008 live MCP session `80de0a67` on 2026-06-26 reconfirms the `SpellInventoryPane2` raw constructor/setup, modeled methods, raw setter, `0x0057f26c-0x0057f28c` jump table, retained local helpers at `0x0057f290-0x0057f485`, modeled callers for `0x0057f030` and `0x0057f490`, and negative route checks for raw helper starts. This removes the offline-only caveat for the [UID:0002RK][0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md) support facts. The accepted split resolves source splitting with child pages [UID:00044D][0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor](by-memory/0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md) through [UID:00044S][0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot](by-memory/0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot.md); spell-route enum names are current best source-facing inferences (`SpellInputKind` and `kSpellInput*` route names).
- 2026-06-16 A002 file-root refresh reconfirmed the spell-inventory function inventory from the legacy constructor `0x0057c2d0` through the scalar deleting destructor `0x0057f6a0`, plus the companion scrollbar constructor `0x0055f450` and raw scrollbar reset start `0x005608a0`. Legacy dispatcher `0x0057c9b0` still has only the two callers inside legacy mouse selection at `0x0057c84f` and `0x0057c934`; it allocates the spell input pane family, sends the direct two-byte cast packet through `0x00574bb0`, and keeps the `0x0057cc42-0x0057ccd0` dispatcher mixed span inside the legacy child island.
- B007 2026-06-19 source-quality reanalysis refines [UID:0002RI][0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers](by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md): `0x0057cc42-0x0057cc44` is `66 90` alignment, `0x0057cc44-0x0057cc64` is the eight-entry `ActivateSpellSlot` jump table, `0x0057cc64-0x0057cc70` is padding, and `0x0057cc70-0x0057ccd0` is a retained no-route direct-spell packet helper that writes opcode `0x0f`, the selected slot, an unsent local byte, and calls `QueueAndSendPacket(g_packetSender, packet, 2)`.
- The same reanalysis records `0x0057cd60-0x0057cdb3` as a retained row-rectangle builder and `0x0057cdc0-0x0057ce68` as a retained page-button hit-test helper. They remain source-relevant evidence in `SpellInventoryPane.cpp` but should not be emitted as if direct call routes were proved.
- Ownership alternatives are rejected at file level: [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md) owns constructed string/four/three/two/one/slot prompt panes; [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md) owns `SpellWhoInputPane` and targeted-action support; [UID:0000NS][Socket](by-file/Socket.md) owns the queue/send funnel; [UID:0000P1][UserPane](by-file/UserPane.md) owns the spell table storage. The dispatcher, page/row geometry, and pending-input state remain legacy `SpellInventoryPane` source behavior.
- The same pass checked constructor/reachability blockers directly. `xrefs_to(0x0057c2d0)` remains empty and `find_bytes` found no absolute pointer hit for the legacy constructor; `xrefs_to(0x0057cf70)` still has the one external constructor call at `0x004b84cb`; `xrefs_to(0x0057ea60)` remains empty and `find_bytes` found no pointer hit for the raw `SpellInventoryPane2` constructor start. Vtable-store xrefs still tie legacy tables `0x0062cfdc`/`0x0062d02c` and alternate tables `0x0062d0f4`/`0x0062d144`/`0x0062d174` to their constructor/destructor/reset sites.

IDA still has no function object at `SpellInventoryPane2::SpellInventoryPane2` start `0x0057ea60`, but the raw bytes are now documented as class-owned constructor/setup code in [UID:0002RK][0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md). The separate `ScrollSpellInventoryPane::ResetScrollState` generated start at `0x005608a0` remains raw/non-modeled with no pointer-pattern hit in the 2026-06-16 scan, so the standalone-vs-folded scrollbar source question remains a real final-source blocker rather than stale evidence.

## File-Split Guidance

Use these working files for future migration planning:

```text
ui/inventory/SpellInventoryPane.cpp
ui/inventory/NewSpellInventoryPane.cpp
ui/inventory/ScrollSpellInventoryPane.cpp
```

Keep item inventory source separate from spell inventory source. The controls are visually similar, but spell inventory reads spell-table records and dispatches cast/input-pane behavior rather than item use, tooltip, or drag-transfer packets.

Keep `NewSpellInventoryPane.cpp` separate from this file for current reconstruction. The shared [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md) physical span is adjacency evidence only; it does not prove that the newer pane source was folded into legacy `SpellInventoryPane.cpp`. `ScrollSpellInventoryPane.cpp` remains a private companion/provisional separate file because the sole observed constructor caller is `NewSpellInventoryPane::NewSpellInventoryPane`, while the dedicated scrollbar docs still clear 85/85.

## Cross-References

- [UID:0000DN][SpellInventoryPane](by-class/SpellInventoryPane.md)
- [UID:0000DO][SpellInventoryPane2](by-class/SpellInventoryPane2.md)
- [UID:00009A][NewSpellInventoryPane](by-class/NewSpellInventoryPane.md)
- [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md)
- [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md)
- [UID:0000DX][SpellWhoInputPane](by-class/SpellWhoInputPane.md)
- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md)
- [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md)
- [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)
- [UID:00044D][0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor](by-memory/0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md) through [UID:00044S][0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot](by-memory/0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot.md) exact `SpellInventoryPane2` child pages routed through [UID:0000DO][SpellInventoryPane2](by-class/SpellInventoryPane2.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `82` and confidence to `78`.
  - Evidence: document covers legacy/new/alternate spell inventory roles, proposed source split, behavior summary, IDA boundary checks, file-split guidance, and cross-references; confidence remains capped by unresolved exact legacy/new split and raw constructor/reset starts.
- 2026-06-01: Added projected path and raised confidence to `82`.
  - Before: the page text proposed `ui/inventory/`, but validator metadata had no projected path and confidence stayed below the parent-attachment threshold.
  - After: `PROPOSED_RECONSTRUCTION_PATH` is `NexusTK/ui/inventory/`; confidence reflects current IDA function inventory, vtable-slot review, caller/callee evidence, and raw switch-table/padding classification.
  - Evidence: IDA MCP confirms all major spell inventory executable families remain in the same address island with dedicated spell inventory vtables and no item-inventory or generic-control ownership drift.
- 2026-06-12 A001 Batch 250: Raised `82/82 -> 85/86`.
  - Evidence: live IDA raw-byte review resolved the `SpellInventoryPane2` constructor/setup boundary, repaired [UID:0002RK][0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md) to `0x0057ea60-0x0057f58b` at `86/89`, raised [UID:0000DO][SpellInventoryPane2](by-class/SpellInventoryPane2.md) to `85/87`, and preserved the likely `NexusTK/ui/inventory/` source root without forcing unresolved old/new file split questions to final-source confidence.
- 2026-06-16 A002 file-root completion pass:
  - Before: `85/86`; the file root was gate-supported but still carried older constructor/reachability and source-split evidence.
  - After: `86/88`; refreshed legacy/new/alternate function inventory, dispatcher caller/callee behavior, constructor xrefs, raw pointer-pattern checks, vtable-store evidence, and scrollbar raw-reset blocker. The `ui/inventory/SpellInventoryPane.cpp` source family remains correct, while final legacy/new/alternate split and field/helper names remain below final-source quality.
- 2026-06-21 Rule 26 B007 legacy dispatcher support sync:
  - Score unchanged at `86/88`.
  - Summary/evidence: incorporated the corrected `0002RI` legacy dispatcher/geometry evidence, stale spell-record offset rejection, `g_pUserPane + 0x13a6ec + 0x148 * slot` one-based spell-record model, no-route packet/row/page helper bodies, and file-level ownership rejection for prompt-pane, target-selection, Socket, and UserPane dependencies.
- 2026-06-21 Rule 26 B011 parent split/index sync:
  - Score unchanged at `86/88`.
  - Summary/evidence: recorded that [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md) is no longer an emitting source page, preserved `SpellInventoryPane.cpp` as the source family for legacy `SpellInventoryPane` and likely `SpellInventoryPane2`, kept `NewSpellInventoryPane.cpp` separate, kept `ScrollSpellInventoryPane.cpp` as a private companion/provisional file, and reaffirmed that [UID:0002RL][0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors](by-memory/0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors.md) is compiler destructor wrapper glue.
- 2026-06-26 B008 support sync:
  - Score unchanged at `86/88`.
  - Summary/evidence: added current live MCP support for [UID:0002RK][0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md), documented the target/support-only split decision and future candidate child metadata, and added alternate-pane `+0xf9 m_hasNextPage` to the file-root field/source-family guidance without changing the file-root/source-family decision.
- 2026-06-26 B008 split implementation:
  - Changed score from `86/88` to `88/89`.
  - Summary/evidence: incorporated the accepted [UID:0002RK][0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md) split/index conversion and exact child pages [UID:00044D][0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor](by-memory/0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md) through [UID:00044S][0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot](by-memory/0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot.md), corrected alternate-pane `+0xf9` to `m_isLastPage`, kept [UID:0000DO][SpellInventoryPane2](by-class/SpellInventoryPane2.md) routed through this file root, and clarified that prompt panes, packet sending, config/global storage, and `UserPane` spell records are dependencies rather than alternate owners.
