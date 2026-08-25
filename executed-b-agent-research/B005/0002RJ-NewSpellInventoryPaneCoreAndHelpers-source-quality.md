** TARGET-REPORT-UID:0002RJ **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002RJ NewSpellInventoryPaneCoreAndHelpers Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: refresh [UID:0002RJ] `by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md` as the broad `NewSpellInventoryPane` source-authored method/helper island, but do not insert aggregate formal C++ into this page.
- Direct owner/emitter repair: use [UID:00009A] `NewSpellInventoryPane` as the direct canonical owner and emitter route, with [UID:0000LU] `NewSpellInventoryPane` kept as the source-file route only. The current file-level `CANONICAL_OWNER:0000LU` is too coarse for this by-memory method island.
- Recommended metadata after implementation: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00009A`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009A`, blank `EMITTER_POSITION_OPTIONAL`, and a blank formal `RECONSTRUCTION_CPP CODE` block at the aggregate level.
- Formal C++ disposition: no formal C++ insertion text for [UID:0002RJ]. This is a target-specific no-code proof, not a deferred naming blocker: the physical span contains 22 IDA functions, switch tables, no-xref raw helper-shaped blocks, and the embedded foreign [UID:0001IJ] `ItemWhoInputPaneState::SetInputModeFlag(bool)` body. Exact method children are required before any source body can be emitted safely.
- Required action after supervisor acceptance: update the target at report-level detail, reconcile [UID:00009A] `by-class/NewSpellInventoryPane.md`, keep [UID:0001IJ] owned by [UID:00006Y]/[UID:0000OH], and optionally create the method-child split pages listed below. Do not hand-edit generated reports, project-level generated files, validator state/cache, IDA DB, or any `-coverage-report.md`.
- Confidence: high for boundaries, vtable/caller evidence, field/data-model names, child scrollbar relation, dispatcher fanout, and source route; medium-high for final original spell route enum names because those remain inferred from branch behavior and prompt-helper support pages rather than symbols.

## Target

- Target UID: `0002RJ`
- Target path: `by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md`
- Assignment id: `B005-report-0002RJ-new-spell-inventory-pane-core-and-helpers-20260626`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`
- Current live target metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000LU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LU`, blank emitter position, blank formal C++.
- Current generated queue state is stale relative to the target page: `auto-generated/-ag-research-tracker.md` still shows [UID:0002RJ] as `78/84`; generated coverage also still carries older `78%` wording. This report does not edit generated files.

## Supervisor Active Recheck

The user/supervisor explicitly assigned [UID:0002RJ] and prohibited by-* edits during this report-only pass. I did not choose a new target, did not spawn subagents, and did not edit target/support by-* docs, generated reports, project-level generated files, validator state/cache, IDA DB, `by-memory/-coverage-report.md`, or any other `-coverage-report.md`.

Workspace note: `git status --short` showed pre-existing modified `by-class/NewSpellInventoryPane.md`, `by-file/NewSpellInventoryPane.md`, and `by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md` before this report file was created. I did not edit those files during this report-only pass.

Read-only MCP/process availability during this pass:

- MCP endpoint: `http://127.0.0.1:13337/mcp`.
- Listener check at 2026-06-26T01:19 Eastern: `127.0.0.1:13337` in `Listen` state, owning PID `13684`, process `python.exe`.
- `initialize` and `tools/list` succeeded.
- Active database session from `idb_list`: `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_active:true`, `is_analyzing:false`, `backend:"worker"`, `owned:true`, `adopted:true`, PID/worker PID `26892`.
- `server_health` on database `80de0a67`: `status:"ok"`, module `NexusTK.exe`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.

## Evidence Checked

IDA MCP and local evidence used:

- `server_health`, `idb_list`, listener/process status.
- `entity_query kind=functions` for `0x0057cf70-0x0057ea60`.
- `lookup_funcs` for the target function starts, the embedded setter, the scalar destructor tail, and raw no-function helper-shaped starts.
- `xref_query` for target function starts, vtable entries, child scrollbar constructor/activation, raw no-function starts, and prompt/packet/helper callees where needed.
- `callees` for all IDA function starts in the target span.
- `decompile` for the constructor, layout/list helpers, paint, key/mouse input, timer/scroll callbacks, cast dispatcher, direct packet helper, button rect, row hit-test, visible-row resolver, stop/reset helper, and expand toggle.
- `disasm`/`insn_query` for the range boundaries, padding, embedded [UID:0001IJ] setter, switch tables, and no-xref raw helper-shaped blocks.
- `int_convert` for function sizes, field offsets, spell record stride, slot counts, and packet opcodes.
- Current target/support docs: [UID:0002RJ], [UID:00009A] `NewSpellInventoryPane`, [UID:0000LU] `NewSpellInventoryPane`, [UID:0001IH] `SpellInventoryPanes`, [UID:0001IJ] `ItemWhoInputPaneStateSetFlag`, [UID:0002RI] legacy spell inventory page, [UID:0002RK] `SpellInventoryPane2`, [UID:0002RL] scalar destructor inventory, [UID:0000CN]/[UID:0000NJ] `ScrollSpellInventoryPane`, [UID:0000O0] `SpellInputPanes`, [UID:0000OH] `TargetSelectionInputPanes`, and [UID:0002W8] `g_pUserPane`.

Negative checks and rejected evidence:

- No live IDA function object exists at raw starts `0x0057d040`, `0x0057e5a0`, `0x0057e6f0`, `0x0057e760`, or `0x0057e960`.
- `xref_query` reports zero incoming xrefs to those raw starts. They are retained no-route context in the broad page, not source emitters.
- [UID:0001IJ] `0x0057d0a0-0x0057d0af` is physically inside the target span but has 17 external direct xrefs and an established [UID:00006Y]/[UID:0000OH] owner route. It must not be renamed or reparented as `NewSpellInventoryPane`.
- `0x0062d068` points to scalar deleting destructor wrapper `0x0057f5d0`, not to raw `0x0057d040`; the destructor wrapper remains documented in [UID:0002RL].
- No validators were run because this is report-only and no by-* docs were edited.

## IDA MCP Facts

Live IDA MCP on 2026-06-26, database `80de0a67`:

- Boundary:
  - Previous legacy function `sub_57CF10` returns at `0x0057cf68`; `0x0057cf6b-0x0057cf70` is alignment before the target constructor.
  - Target starts at `0x0057cf70` with `sub_57CF70`.
  - Target ends at `0x0057ea57`; `0x0057ea57-0x0057ea60` is alignment, and `0x0057ea60` begins raw `SpellInventoryPane2` constructor/setup bytes tracked by [UID:0002RK].
- Function inventory in `0x0057cf70-0x0057ea60`: 22 IDA functions:
  - `0x57cf70 sub_57CF70 size 0xcf`
  - `0x57d080 sub_57D080 size 0x17`
  - `0x57d0a0 sub_57D0A0 size 0x10` (foreign [UID:0001IJ])
  - `0x57d0b0 nullsub_54 size 0x1`
  - `0x57d0c0 sub_57D0C0 size 0x88`
  - `0x57d150 sub_57D150 size 0xa5`
  - `0x57d200 sub_57D200 size 0x160`
  - `0x57d360 sub_57D360 size 0x38`
  - `0x57d3a0 sub_57D3A0 size 0x66`
  - `0x57d410 sub_57D410 size 0x16`
  - `0x57d430 sub_57D430 size 0x494`
  - `0x57d8d0 sub_57D8D0 size 0xe1`
  - `0x57d9c0 sub_57D9C0 size 0x7cf`
  - `0x57e1b0 sub_57E1B0 size 0x28`
  - `0x57e1e0 sub_57E1E0 size 0xe1`
  - `0x57e2d0 sub_57E2D0 size 0x29d`
  - `0x57e620 sub_57E620 size 0x69`
  - `0x57e690 sub_57E690 size 0x57`
  - `0x57e800 sub_57E800 size 0xc8`
  - `0x57e8d0 sub_57E8D0 size 0x85`
  - `0x57e9a0 sub_57E9A0 size 0x25`
  - `0x57e9d0 sub_57E9D0 size 0x87`
- Size conversions checked by `int_convert`: `0xcf` = 207, `0x160` = 352, `0x494` = 1172, `0x7cf` = 1999, `0x29d` = 669, `0x148` = 328.
- Constructor xrefs and child scrollbar relation:
  - `xrefs_to 0x0057cf70`: one code xref at `0x004b84cb` inside `sub_4B83D0`.
  - Constructor calls `0x00545090`, allocation helper `0x004f4aa0`, `ScrollSpellInventoryPane` constructor `0x0055f450`, and activation helper `0x0055f5f0`.
  - `xrefs_to 0x0055f450`: one call at `0x0057d013`.
  - `xrefs_to 0x0055f5f0`: one call at `0x0057d028`.
  - Constructor installs `NewSpellInventoryPane` vtables `0x0062d068`, `0x0062d0b8`, and `0x0062d0e8`, clears fields at `+0xf8`, `+0xf9/+0xfa`, `+0x140`, `+0x139/+0x13a`, and `+0x13c`, allocates 272 bytes for the child scroll pane, stores it at `+0x100`, and activates it.
- Vtable slot evidence:
  - `0x0062d068 -> 0x0057f5d0` scalar deleting destructor wrapper, not inside [UID:0002RJ].
  - Primary vtable entries include `0x0062d074 -> 0x0057d0c0`, `0x0062d094 -> 0x0057d150`, `0x0062d098 -> 0x0057d3a0`, `0x0062d0a0 -> 0x0057d410`, `0x0062d0ac -> 0x0057d430`, and `0x0062d0b0 -> 0x0057d080`.
  - Secondary vtable entries include `0x0062d0bc -> 0x0057d9c0`, `0x0062d0c0 -> 0x0057d8d0`, `0x0062d0c8 -> 0x0057e1b0`, and tertiary `0x0062d0ec -> 0x0057e1e0`.
- Embedded [UID:0001IJ]:
  - `lookup_funcs 0x0057d0a0` reports size `0x10`, exact end `0x0057d0b0`.
  - Decompile/disasm writes the argument byte to `[ecx+0xfa]` and returns it.
  - `xref_query to 0x0057d0a0` reports 17 direct code xrefs from target-selection/spell-input/item-input constructor/destructor families, not from `NewSpellInventoryPane`.
- `sub_57D200` list/scroll sync:
  - Scans 52 one-based spell slots.
  - Reads learned/active bytes from `g_pUserPane` historical `dword_67A748` at `+0x13a834 + slot * 0x148`.
  - Stores learned slot ids in the `this+0x104` byte array.
  - Stores `this+0xf9` as 52 in expanded mode or learned-count in collapsed mode.
  - Uses 13 visible rows in collapsed mode and 26 in expanded mode.
  - Calls child scroll helpers `0x0055f560` to set the scroll range/max and `0x0055f5c0` to set current position.
  - Clamps scroll/current offset to `0..30000` and mirrors the final value to `this+0xf8`.
- Paint `sub_57D430`:
  - Calls `sub_57D200` first.
  - Uses `SPELLINV.EPF` for collapsed mode and alternate EPF table `0x0061c97c` for expanded mode.
  - Draws key labels via `SlotIndexToHotkeyLetter` candidate `0x005a4090`.
  - Draws spell display strings from the one-based spell record base `g_pUserPane + 0x13a6ec + slot * 0x148`, display text at record `+8` (equivalent to `+0x13a83c` for slot 1).
  - Uses highlight bytes at outer `+0x139` and `+0x13a`.
  - Draws the expand/collapse button rectangle `[168,37,185,54]` and uses `7 * this+0x140` plus mode-dependent offsets to pick the button frame.
- Input call flow:
  - `sub_57D8D0` key handler handles page up/down style keys by subtracting/adding 13 to `+0xf8`, calls `sub_57D200`, invalidates/redraws, and uses `+` to call `sub_57E9D0` expand toggle.
  - `sub_57D9C0` mouse handler calls row hit-test `0x0057e800`, visible-slot resolver `0x0057e8d0`, button rect `0x0057e690`, stop/reset helper `0x0057e9a0`, expand toggle `0x0057e9d0`, drag/selection helper `0x004c7f90`, direct packet helpers `0x00575380`/`0x00574bb0`, cast dispatcher `0x0057e2d0`, and child-scroll event forwarding after pane-local coordinate adjustment.
  - At the end of `sub_57D9C0`, the handler fetches the child scroll pane bounds, subtracts the child top/left from the event point, dispatches to the child scroll pane secondary input handler at `m_scrollPane + 0xa0`, then restores the original point. Preserve the project convention: `Point` storage is y/x while `RectBounds` is left/top/right/bottom.
- Cast dispatcher `sub_57E2D0`:
  - Validates one-based spell slots `1..52`.
  - Computes record base as `g_pUserPane + 0x13a6ec + slot * 0x148`.
  - Checks the learned/active byte, then branches on the route/type dword at record `+4` after subtracting 1.
  - Case 0: allocates prompt memory and calls `SpellStringInputPane` constructor `0x005adf40`; sets `this+0xfa` to 1.
  - Case 1: if active mounted/target state exists at `dword_67A764`, calls `SendTargetedActionPacket` `0x005af4f0`; otherwise allocates and calls `SpellWhoInputPane` `0x005ae2a0`; prompt path sets `this+0xfa` to 1.
  - Case 2: `SpellFourArgsInputPane` `0x005b0780`; sets `this+0xfa` to 1.
  - Case 3: `SpellThreeArgsInputPane` `0x005b0ac0`; sets `this+0xfa` to 1.
  - Cases 4 and 8: direct two-byte spell-cast packet via `0x0057e620`; clears `this+0xfa` to 0.
  - Case 5: `SpellTwoArgsInputPane` `0x005b0da0`; sets `this+0xfa` to 1.
  - Case 6: `SpellOneArgInputPane` `0x005b1030`; sets `this+0xfa` to 1.
  - Case 7: `SpellSlotInputPane` `0x005b1280`; sets `this+0xfa` to 1.
  - Switch table starts at `0x0057e570` after the function return span and belongs to this dispatcher.
- Direct packet helper `sub_57E620`:
  - Checks global gate `unk_69B380 <= 0`.
  - Builds opcode `0x0f` plus the spell slot byte and calls `QueueAndSendPacket` candidate `0x00574bb0` through `dword_67A7EC`, length 2.
- Geometry helpers:
  - `sub_57E690(part, outRect)` returns button rectangle `[168,37,185,54]` when `part == 2`, otherwise invalid `[-1,-1,-1,-1]`.
  - `sub_57E800(point)` loops visible rows and returns row index or `-1`; row rectangles are `left=2`, `top=16 + 20 * row`, `right=170`, `bottom=36 + 20 * row`; rows `0..12` are valid in collapsed mode, rows `0..26` are allowed only when expanded.
  - `sub_57E8D0(visibleOrdinal)` maps collapsed visible ordinals through learned slots by scanning `1..52`; expanded mode returns the ordinal only when the corresponding record is learned/active; otherwise returns `-1`.
  - Raw no-xref `0x0057e6f0` and `0x0057e960` are duplicate row-geometry/point helpers by byte behavior but have no incoming xrefs or IDA function object.
- Expand/timer helpers:
  - `sub_57E9A0` stops/clears the active repeat/timer handle at `+0x13c` via `0x00597610`.
  - `sub_57E9D0` toggles byte `+0x144`, clears scroll position `+0xf8`, writes button state `+0x140 = 2`, calls layout/paint invalidation virtuals, recomputes the spell list, and redraws.

## Function / Child Inventory

This target should remain a broad island with blank aggregate C++. Exact method children can be created when the supervisor wants split execution. Recommended direct owner/emitter for source-bearing NewSpellInventoryPane children is [UID:00009A] with [UID:0000LU] as the file route.

| Range | Current IDA object | Best-supported source-facing role | Disposition |
| --- | --- | --- | --- |
| `0x0057cf70-0x0057d03f` | `sub_57CF70` | `NewSpellInventoryPane::NewSpellInventoryPane()` | Source-bearing child candidate, owner/emitter [UID:00009A], position 10, blank parent C++ |
| `0x0057d040-0x0057d075` | no IDA function | No-route destructor-shaped clone that releases `m_scrollPane` and jumps to base cleanup | Keep as raw/no-route context in [UID:0002RJ]; do not emit; scalar wrapper is [UID:0002RL] |
| `0x0057d080-0x0057d097` | `sub_57D080` | Refresh/rebuild plus invalidate/redraw helper | Source-bearing child candidate, position 20 |
| `0x0057d0a0-0x0057d0b0` | `sub_57D0A0` | [UID:0001IJ] `ItemWhoInputPaneState::SetInputModeFlag(bool)` | Existing foreign child; keep [UID:00006Y]/[UID:0000OH] owner/emitter and do not fold into [UID:0002RJ] |
| `0x0057d0b0-0x0057d0b1` | `nullsub_54` | No-op virtual/null stub | No xrefs; keep as non-emitting context unless a future exact ABI-stub page is requested |
| `0x0057d0c0-0x0057d148` | `sub_57D0C0` | Resize/layout bounds; positions child scrollbar at right side | Source-bearing child candidate, position 30 |
| `0x0057d150-0x0057d1f5` | `sub_57D150` | Expanded/collapsed mode bounds/layout helper | Source-bearing child candidate, position 40 |
| `0x0057d200-0x0057d360` | `sub_57D200` | `RebuildSpellList` / scrollbar range-current sync | Source-bearing child candidate, position 50 |
| `0x0057d360-0x0057d398` | `sub_57D360` | Scroll-position changed helper | Source-bearing child candidate, position 60 |
| `0x0057d3a0-0x0057d406` | `sub_57D3A0` | Layout child scroll pane after parent layout | Source-bearing child candidate, position 70 |
| `0x0057d410-0x0057d426` | `sub_57D410` | Hide/close child scroll pane then base hide | Source-bearing child candidate, position 80 |
| `0x0057d430-0x0057d8c4` | `sub_57D430` | Paint spell list and expand button | Source-bearing child candidate, position 90 |
| `0x0057d8d0-0x0057d9b1` | `sub_57D8D0` | Key event handler | Source-bearing child candidate, position 100 |
| `0x0057d9c0-0x0057e1b0` | `sub_57D9C0` plus switch table at `0x0057e190` | Mouse event handler, row hover, selection/drag, cast, child scroll forwarding | Source-bearing child candidate, position 110; include switch table support |
| `0x0057e1b0-0x0057e1d8` | `sub_57E1B0` | Timer/message cleanup callback | Source-bearing child candidate, position 120 |
| `0x0057e1e0-0x0057e2c1` | `sub_57E1E0` | Scroll-repeat/up-down callback from child scroll pane | Source-bearing child candidate, position 130 |
| `0x0057e2d0-0x0057e5a0` | `sub_57E2D0` plus switch table `0x0057e570-0x0057e594` | `CastSpell(uint8_t spellSlot)` dispatcher | Source-bearing child candidate, position 140; include switch table support |
| `0x0057e5a0-0x0057e613` | no IDA function | No-route direct packet helper-shaped block, opcode `0x30`/length 4 | Keep as raw/no-route context; zero incoming xrefs |
| `0x0057e620-0x0057e689` | `sub_57E620` | `SendDirectSpellCastPacket(uint8_t spellSlot)` for opcode `0x0f` length 2 | Source-bearing child candidate, position 150 |
| `0x0057e690-0x0057e6e7` | `sub_57E690` | `GetButtonRect` / expand-button rect helper | Source-bearing child candidate, position 160 |
| `0x0057e6f0-0x0057e758` | no IDA function | No-route row-rect helper-shaped block | Keep as raw/no-route context; zero incoming xrefs |
| `0x0057e760-0x0057e7f2` | no IDA function | No-route button hit-test helper-shaped block | Keep as raw/no-route context; zero incoming xrefs |
| `0x0057e800-0x0057e8c8` | `sub_57E800` | `HitTestSpellRow(Point point)` | Source-bearing child candidate, position 170 |
| `0x0057e8d0-0x0057e955` | `sub_57E8D0` | `ResolveVisibleSpellSlot(int visibleOrdinal)` | Source-bearing child candidate, position 180 |
| `0x0057e960-0x0057e997` | no IDA function | No-route row origin/point helper-shaped block | Keep as raw/no-route context; zero incoming xrefs |
| `0x0057e9a0-0x0057e9c5` | `sub_57E9A0` | Stop/clear active repeat timer or hover timer handle | Source-bearing child candidate, position 190 |
| `0x0057e9d0-0x0057ea57` | `sub_57E9D0` | `ToggleExpandedMode()` | Source-bearing child candidate, position 200 |

Recommended child-page metadata when split execution is accepted:

- Source-bearing `NewSpellInventoryPane` children: `CANONICAL_OWNER:00009A`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009A`; formal C++ initially blank unless a child-specific accepted report supplies exact insertion text.
- Foreign [UID:0001IJ]: no metadata change from this assignment.
- Raw no-xref helper-shaped blocks: keep documented in [UID:0002RJ] and do not create emitting children unless future evidence finds real callers or vtable/data pointers. If a coverage-only page is required, use `RECONSTRUCTABLE:FALSE`, blank emitters, and no C++.
- Validators for target/support implementation: run scoped validators for [UID:0002RJ] and [UID:00009A]. If child pages are created, run validators for every new child page plus `by-class/NewSpellInventoryPane.md`.

## Field, Data Model, And Helper Names

Recommended source-facing names and caveats:

- `m_scrollPosition` / `m_topVisibleIndex`: byte at `+0xf8`, written by constructor, list sync, key handling, scroll callback, and expand toggle.
- `m_spellListCount`: byte at `+0xf9`, written by `sub_57D200` as learned-count in collapsed mode or 52 in expanded mode.
- `m_pendingSpellInput`: byte at `+0xfa`, set by `CastSpell` prompt-allocation paths and cleared by direct cast. Do not confuse this local field with [UID:0001IJ] `ItemWhoInputPaneState::m_active` just because the foreign helper writes offset `+0xfa` on its own state object.
- `m_scrollPane`: pointer at `+0x100` to the embedded [UID:0000CN] `ScrollSpellInventoryPane` child.
- `m_visibleSpellSlots`: byte array at `+0x104`, filled by `sub_57D200` with one-based learned slot ids.
- `m_hoverSpellSlot`: byte at `+0x139`, initialized to `0xff` and used by paint/mouse hover.
- `m_selectedOrDragSpellSlot`: byte at `+0x13a`, initialized with `+0x139` and used for current selected/drag source comparisons.
- `m_activeRepeatTimer`: dword at `+0x13c`, stopped by `sub_57E9A0` through `0x00597610`.
- `m_expandButtonState`: dword at `+0x140`, drives the expand/collapse button frame in paint and is set to 2 by `ToggleExpandedMode`.
- `m_expanded`: byte at `+0x144`, toggles between collapsed 13-row and expanded 26-row/52-slot behavior.
- `g_pUserPane`: canonical name for historical `dword_67A748`; reject `g_pCollectionData`, `g_pSpellMan`, and `SpellManager` for this target.
- Spell record model: one-based record base `g_pUserPane + 0x13a6ec + slot * 0x148`; learned/active byte at record `+0`; route/type dword at record `+4`; display string at record `+8`; existing support also records prompt/name material at `+0x13a794 + slot * 0x148` and active byte at `+0x13a834 + slot * 0x148`.
- Spell route enum names remain descriptive: `StringPrompt`, `TargetPromptOrDirectTargetedAction`, `FourArgsPrompt`, `ThreeArgsPrompt`, `DirectCast`, `TwoArgsPrompt`, `OneArgPrompt`, and `SpellSlotPrompt`.
- Prompt helper names should match current support: `SpellStringInputPane`, `SpellWhoInputPane`, `SpellFourArgsInputPane`, `SpellThreeArgsInputPane`, `SpellTwoArgsInputPane`, `SpellOneArgInputPane`, `SpellSlotInputPane`, and `SendTargetedActionPacket`.
- Geometry helpers should use project conventions: `RectBounds` arguments are left/top/right/bottom, while `Point` storage and some helper callsites use y/x ordering.

## Source Owner And Rejected Alternatives

Recommended route:

- Direct class/source owner: [UID:00009A] `NewSpellInventoryPane`.
- Source file route: [UID:0000LU] `NexusTK/ui/inventory/NewSpellInventoryPane.cpp`.
- Parent physical index: [UID:0001IH] `SpellInventoryPanes`.
- Child scrollbar class: [UID:0000CN] / [UID:0000NJ] `ScrollSpellInventoryPane`.
- Prompt/helper dependencies: [UID:0000O0] `SpellInputPanes`, [UID:0000OH] `TargetSelectionInputPanes`, packet helpers [UID:0001L9]/[UID:0001HU].

Rejected alternatives:

- [UID:0000LU] as direct canonical owner for [UID:0002RJ]: too coarse. It remains the source-file route, but the by-memory method island should attach directly to [UID:00009A].
- [UID:0001IH] `SpellInventoryPanes` as emitter: rejected because it is a non-emitting split/index over legacy, new, alternate, state-helper, and destructor islands.
- `ScrollSpellInventoryPane` ownership: rejected for [UID:0002RJ]. The target constructs and drives a child scroll pane, but the child scroll class owns only its own methods and fields.
- `SpellInputPanes` or `TargetSelectionInputPanes` ownership: rejected for the NewSpellInventoryPane dispatcher and pending flag. Those modules own prompt panes and the embedded [UID:0001IJ] state helper, not the spell-inventory cast dispatcher.
- `SpellInventoryPane`, `SpellInventoryPane2`, or a generic shared spell inventory owner: rejected because vtables, callers, fields, and mode/layout behavior are specific to `NewSpellInventoryPane`.
- `g_pUserPane`/player-data ownership: rejected because spell records are data dependencies, not source ownership for UI methods.

## Formal C++ / No-Code Proof

Formal `RECONSTRUCTION_CPP CODE` for [UID:0002RJ] should remain empty:

```cpp
```

This is the exact aggregate-level insertion text: no code between `BEGIN` and `END`.

Proof:

- [UID:0002RJ] is not one C++ function. Live IDA reports 22 functions in the span, plus switch-support data and no-xref raw helper-shaped blocks.
- The span physically contains [UID:0001IJ], an already accepted foreign source helper with [UID:00006Y]/[UID:0000OH] owner/emitter. An aggregate C++ body would either omit it or duplicate/reparent it incorrectly.
- `sub_57D9C0` and `sub_57E2D0` require switch-support/jump table handling outside their IDA function end; source bodies belong on exact method children, not on the broad page.
- Raw no-function blocks at `0x0057d040`, `0x0057e5a0`, `0x0057e6f0`, `0x0057e760`, and `0x0057e960` have zero incoming xrefs and failed `lookup_funcs`/`decompile` as functions. They should be retained as no-route context rather than source emitters.
- Existing sibling policy supports this: [UID:0002RI] and [UID:0002RK] stay source-routed/reconstructable but keep aggregate C++ blank because method-level splits are required.

Therefore the current blocker is resolved as an implementation-ready split/no-code plan. It is not acceptable to insert a short summary, marker C++, or a partial class method bundle into [UID:0002RJ].

## Implementation-Ready Repair Plan

Target [UID:0002RJ]:

- Set metadata to `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00009A`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009A`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Replace file-direct owner wording with source route wording: direct owner/emitter [UID:00009A], file route [UID:0000LU].
- Update Item Summary to mention: exact `0x0057cf70-0x0057ea57` boundary, 22 IDA functions, embedded [UID:0001IJ] exclusion, child scroll pane at `+0x100`, learned-spell list model, cast dispatcher fanout, and no aggregate formal C++.
- Add live MCP facts: prior alignment `0x0057cf6b-0x0057cf70`, target end alignment `0x0057ea57-0x0057ea60`, function inventory, vtable slot map, one constructor caller, child scroll constructor/activation xrefs, `sub_57D200` list/scroll behavior, paint/input/cast helper roles, raw no-xref helper-shaped blocks, and direct source-owner rejections.
- Preserve [UID:0001IJ] as an embedded foreign child and link its exact route.
- Do not hand-edit generated tracker/coverage rows; let validator/autogen refresh stale `78/84` rows.

Support [UID:00009A] `by-class/NewSpellInventoryPane.md`:

- Add/reconcile a support note that [UID:0002RJ] has source-quality reanalysis but remains aggregate-C++ blank.
- Replace stale file-direct ownership wording with direct class owner/emitter and file route [UID:0000LU].
- Reconcile field aliases listed in this report, especially `m_scrollPosition`, `m_spellListCount`, `m_pendingSpellInput`, `m_scrollPane`, `m_visibleSpellSlots`, `m_hoverSpellSlot`, `m_selectedOrDragSpellSlot`, `m_activeRepeatTimer`, `m_expandButtonState`, and `m_expanded`.
- Reconcile helper names for `RebuildSpellList`, `HitTestSpellRow`, `ResolveVisibleSpellSlot`, `CastSpell`, `SendDirectSpellCastPacket`, `GetButtonRect`, and `ToggleExpandedMode`.
- Preserve the child scrollbar relation without moving `ScrollSpellInventoryPane` ownership into this class page.

Optional support [UID:0000LU] `by-file/NewSpellInventoryPane.md`:

- Only edit if implementation needs a file-level source-route note. If edited, preserve [UID:0000LU] as source file, not direct owner of [UID:0002RJ].

Optional child split execution:

- If the supervisor accepts child-page creation, use the function/child inventory above. Create source-bearing child pages under [UID:00009A], keep [UID:0002RJ] as the aggregate/index context, validate each new page, then validate [UID:0002RJ] and `by-class/NewSpellInventoryPane.md`.
- Do not create emitting children for no-route raw blocks unless new caller/pointer evidence is found.

Scoped validators after implementation edits:

> Executable block R001 was removed from this report and preserved verbatim in [0002RJ-NewSpellInventoryPaneCoreAndHelpers-source-quality-removed.md](0002RJ-NewSpellInventoryPaneCoreAndHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If `by-file/NewSpellInventoryPane.md` is edited:

> Executable block R002 was removed from this report and preserved verbatim in [0002RJ-NewSpellInventoryPaneCoreAndHelpers-source-quality-removed.md](0002RJ-NewSpellInventoryPaneCoreAndHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If child pages are created, run one scoped validator per new child page.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Remaining uncertainty |
| --- | --- | --- | --- | --- |
| [UID:0002RJ] should route directly through [UID:00009A], not [UID:0000LU]. | High | Vtable entries, fields, methods, constructor caller, and support docs all identify `NewSpellInventoryPane`; [UID:0000LU] is the file route. | File-level current metadata is coarser; rejected by current B-agent direct-owner policy and sibling scroll callback precedents. | None for owner route. |
| Aggregate formal C++ must stay blank. | High | 22 functions, switch tables, raw no-xref helper-shaped blocks, and embedded foreign [UID:0001IJ]. | Considered class-method bundle or draft code; rejected as invalid aggregate source. | Child pages can later carry method-level formal C++. |
| [UID:0001IJ] is foreign to NewSpellInventoryPane. | Very high | Existing page, live size `0x10`, 17 external xrefs, source route [UID:00006Y]/[UID:0000OH]. | Physical adjacency inside [UID:0002RJ] and same `+0xfa` offset are not ownership proof. | None. |
| Raw starts `0x57d040`, `0x57e5a0`, `0x57e6f0`, `0x57e760`, and `0x57e960` are no-route context. | High | `lookup_funcs` says `Not a function`; xrefs-to are zero; decompile fails; disassembly shows function-shaped bytes. | Vtable/entry checks route live destructor to `0x57f5d0`; live mouse/cast callers use recognized helpers instead. | If future pointer scans find references, split as retained raw helpers. |
| Learned-spell row model uses one-based spell records at `g_pUserPane + 0x13a6ec + slot * 0x148`. | High | `sub_57D200`, paint, cast dispatcher, and support pages agree; `0x148` = 328. | Historical `g_pCollectionData`/`SpellManager` labels rejected by [UID:0002W8]. | Original struct/enum names remain inferred. |
| `m_spellListCount` at `+0xf9` is now resolved enough to replace "unresolved small state byte". | Medium-high | `sub_57D200` writes learned count or 52; key/paint compare it against 13/26 visibility. | Existing page left it unresolved; no symbol name exists. | Exact original field spelling unknown. |
| `+0xfa` in this class is best named `m_pendingSpellInput`. | Medium-high | `CastSpell` sets it on prompt allocation and clears it on direct-cast path. | [UID:0001IJ] uses `m_active` at the same offset on a different state object; do not reuse that name here. | Exact original field spelling unknown. |
| Score can rise to `88/90`. | Medium-high | Live MCP closes boundary, owner, xref, child-scroll, list-model, dispatcher, raw-block, and no-code questions. | Higher score rejected because method children/formal C++ are not created and some enum/helper names remain inferred. | Validator/autogen should refresh stale generated rows after implementation. |

## Positive Evidence Summary

- Live MCP confirms the target's start/end boundaries and adjacent alignment bytes.
- Live MCP confirms all 22 function starts/sizes and the embedded [UID:0001IJ] exact child.
- Vtable data xrefs identify the NewSpellInventoryPane virtual methods and keep the scalar deleting destructor in [UID:0002RL].
- Constructor has one code caller and constructs/activates exactly one `ScrollSpellInventoryPane` child.
- List, paint, key, mouse, cast, direct packet, geometry, timer, and expand-toggle behavior are all decompiled and internally consistent.
- Existing file/class support docs corroborate the [UID:00009A] -> [UID:0000LU] source route and prompt-helper names.

## Negative Evidence Summary

- No IDA MCP evidence supports file-level [UID:0000LU] as direct by-memory owner; it is only the source-file route.
- No evidence supports `ScrollSpellInventoryPane`, `SpellInputPanes`, `TargetSelectionInputPanes`, `SpellInventoryPane`, `SpellInventoryPane2`, `g_pUserPane`, or a generic shared spell inventory bucket as owner for [UID:0002RJ].
- No incoming xrefs or function objects support source emission from raw helper-shaped starts.
- Physical overlap with [UID:0001IJ] is not owner proof and must not override the accepted [UID:00006Y]/[UID:0000OH] route.

## Required Implementation Checklist

- [x] Target [UID:0002RJ] metadata updated to `88/90`, direct owner/emitter [UID:00009A], source-file route [UID:0000LU], blank formal C++.
  - Proof: `by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md` now has `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00009A`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009A`, blank `EMITTER_POSITION_OPTIONAL`, and no text between `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END`. The body explicitly records [UID:0000LU] as source-file route only.
- [x] Target [UID:0002RJ] body updated with exact live MCP facts: boundary, alignment, 22-function inventory, vtable map, constructor caller, child scroll xrefs, list model, dispatcher fanout, geometry helpers, raw no-xref blocks, [UID:0001IJ] exclusion, and source-owner rejections.
  - Proof: target body now includes MCP availability at 2026-06-26T01:29 Eastern, exact `0x0057cf70-0x0057ea57` boundary, `0x0057cf6b-0x0057cf70` and `0x0057ea57-0x0057ea60` alignment, full 22-function inventory, vtable slot map, one constructor caller at `0x004b84cb`, child scroll constructor/activation xrefs at `0x0057d013`/`0x0057d028`, list/paint/input/cast/toggle behavior, raw no-xref block findings, field/helper aliases, rejected owners, and aggregate no-code proof.
- [x] [UID:0001IJ] kept as foreign exact child; no NewSpellInventoryPane reparenting or duplicate C++.
  - Proof: target and support docs state [UID:0001IJ] remains [UID:00006Y]/[UID:0000OH] owned/emitted, has size `0x10`, writes `[ecx+0xfa]`, and has 17 external xrefs from target-selection/spell-input/item-input families. No C++ was inserted for [UID:0001IJ] in [UID:0002RJ].
- [x] [UID:00009A] `by-class/NewSpellInventoryPane.md` reconciled with field/helper aliases, child scrollbar relation, aggregate-C++ no-code policy, and source route.
  - Proof: class page now records [UID:0002RJ] as direct class-owned/emitted method island, [UID:0000LU] as source-file route, `m_scrollPosition`/`m_topVisibleIndex`, `m_spellListCount`, `m_pendingSpellInput`, `m_scrollPane`, `m_visibleSpellSlots`, `m_hoverSpellSlot`, `m_selectedOrDragSpellSlot`, `m_activeRepeatTimer`, `m_expandButtonState`, `m_expanded`, helper names including `RebuildSpellList`, `HitTestSpellRow`, `ResolveVisibleSpellSlot`, `CastSpell`, `SendDirectSpellCastPacket`, `GetButtonRect`, `ToggleExpandedMode`, and the child scrollbar constructor/activation relation.
- [x] Optional [UID:0000LU] `by-file/NewSpellInventoryPane.md` edited only if needed for a file-route support note.
  - Proof: by-file support edit was needed because the page still carried stale [UID:0002RJ] `85/88` references and ambiguous direct-route wording. It now records [UID:0002RJ] at `88/90`, [UID:00009A] as direct owner/emitter, this file as source-file route only, and the accepted field/helper and no-code dispositions.
- [x] Optional method child split pages created only if supervisor accepts split execution, using exact ranges/dispositions in this report.
  - Proof: supervisor explicitly said not to create optional method child split pages in this callback. No child pages were created. The exact split inventory was preserved in [UID:0002RJ] as a future implementation-ready plan with ranges, roles, owner/emitter disposition, and positions.
- [x] Scoped validators run from `source-3/project-documentation` for every edited target/support file, with command ids/timestamps recorded.
  - Proof: target validator `python .\tools\validator.py --mode file --file by-memory\0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md --apply --queue-timeout 240` passed with `command_id: 000000002084`, `command_timestamp: 2026-06-26T01:37:45-04:00`, exit code 0, `ok: 1`, `generated_refresh: deferred`. Class validator `python .\tools\validator.py --mode file --file by-class\NewSpellInventoryPane.md --apply --queue-timeout 240` passed with `command_id: 000000002085`, `command_timestamp: 2026-06-26T01:37:50-04:00`, exit code 0, `ok: 1`, `generated_refresh: deferred`. By-file validator `python .\tools\validator.py --mode file --file by-file\NewSpellInventoryPane.md --apply --queue-timeout 240` passed with `command_id: 000000002086`, `command_timestamp: 2026-06-26T01:38:00-04:00`, exit code 0, `ok: 1`, `generated_refresh: deferred`.
- [x] Leases used only for the immediate edit batch and released immediately after the validator batch.
  - Proof: `B005` leased exactly `by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md`, `by-class/NewSpellInventoryPane.md`, and `by-file/NewSpellInventoryPane.md`; initial lease request returned `Success` for all three, and the pre-validation renewal also returned `Success` for all three. A later renewal attempt was rejected as `Already has lease`, confirming the same lease was still active. After validators, `python leaser.py B005 unlease ...` returned `Success` for all three paths. Final `Agent-B005/current_leases.md` readback showed no active B005 leases.
- [x] Generated tracker/coverage/source output not hand-edited; stale generated rows left for validator/autogen refresh.
  - Proof: no generated reports, generated C++, coverage reports, validator state/cache, or IDA DB files were manually edited. Scoped validators reported validator-owned generated refresh as `deferred`; the validator also made its normal projected-stats updates to `project-level/-auto-completion-stats.md`. No auto-generated source or coverage file was edited by hand during this callback.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0002RJ-NewSpellInventoryPaneCoreAndHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0002RJ-NewSpellInventoryPaneCoreAndHelpers-source-quality.md","timestamp":"2026-06-26T01:49:04","uid":"0002RJ"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002RJ-NewSpellInventoryPaneCoreAndHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/0002RJ-NewSpellInventoryPaneCoreAndHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002RJ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
