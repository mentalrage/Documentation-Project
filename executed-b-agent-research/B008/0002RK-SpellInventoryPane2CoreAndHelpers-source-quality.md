** TARGET-REPORT-UID:0002RK **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002RK SpellInventoryPane2CoreAndHelpers Source-Quality Report

Agent: B008
Assignment id: B008-report-0002RK-spell-inventory-pane2-core-and-helpers-20260626
Mode: report-only research first
Target: [UID:0002RK] `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md`
MCP session: `80de0a67`, `NexusTK.exe.i64`, health `ok`, auto-analysis ready, Hex-Rays ready

## Assignment State

`goal.md` identifies [UID:0002RK] as the current assignment. The active-folder reports `00012U-DialogPaneSlideAnimation-source-quality.md` and `0002RV-TextBoxPaneConstructor-source-quality.md` still exist in `Agent-B008/research/`, but they are not the current `goal.md` target. I followed `goal.md` and did not switch to the older active files.

## Current Target State

- Target header currently says `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000DO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000DO`, blank formal C++. This reflects the earlier rejected target/support-only implementation and should be corrected by the new split plan, not treated as accepted final state.
- The live target file is `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md`.
- The generated research tracker still contains the stale row/path `by-memory/0x0057eaa0-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` at `78/82`. A scoped validator dry run against the live path produced command `000000002473` and reported the exact pending repair: `path_update 0002RK ... was by-memory/0x0057eaa0-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md`, plus reference source path updates for [UID:0000DO], [UID:0000O0], [UID:0000O1], and [UID:0001IH]. This is a validator-owned registry/generated-state problem, not something to repair by manually editing generated reports.
- Direct class parent [UID:0000DO] `SpellInventoryPane2` is still `85/87`, reconstructable, owner/emitter [UID:0000O1], and contains support notes from the earlier target/support pass that should be corrected where they conflict with this rework.
- Source root [UID:0000O1] `SpellInventoryPane` is `86/88`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/inventory/"`.
- Physical parent [UID:0001IH] `SpellInventoryPanes` is a non-emitting split/index at `87/90`, `RECONSTRUCTABLE:FALSE`.
- Related `.rdata` aggregate [UID:00026J] `SpellInventoryMacroReadOnlyData` is a non-emitting mixed index at `87/92`.

## Evidence Checked

- Read target [UID:0002RK], parent [UID:0001IH], class [UID:0000DO], file [UID:0000O1], rdata aggregate [UID:00026J], and current tracker row.
- Searched current docs, executed B reports, archived reports, and active B008 reports for `0002RK`, `SpellInventoryPane2CoreAndHelpers`, `0x0057ea60`, and stale `0x0057eaa0`.
- IDA MCP:
  - `tools/list` verified active schema.
  - `idb_list` found active session `80de0a67`.
  - `server_health` returned status `ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`.
  - `lookup_funcs` on all candidate starts from `0x0057ea60` through `0x0057f58b`.
  - `xrefs_to` on modeled functions, raw helper starts, jump table, and destructor-tail boundary.
  - `callers` and `callees` on the modeled methods.
  - `decompile` for `0x0057eaa0`, `0x0057eac0`, `0x0057eb00`, `0x0057edb0`, `0x0057ee30`, `0x0057f000`, `0x0057f030`, `0x0057f490`, and `0x0057f530`.
  - `insn_query` over raw constructor/setup `0x0057ea60-0x0057eaa0`, raw setter/null span `0x0057ead0-0x0057eb00`, and mixed dispatcher/helper span `0x0057f26c-0x0057f490`.
  - `find_bytes`, `find data_ref`, and `find immediate` for raw/helper starts and modeled helper starts.
- `int_convert.py` verified decimal/hex pairs: `1287916 == 0x13a6ec`, `1305373 == 0x13eb1d`, `2678362 == 0x28de5a`, `328 == 0x148`, `248 == 0xf8`, `249 == 0xf9`, `250 == 0xfa`.
- Earlier report evidence included validator dry run `python .\tools\validator.py --mode file --file by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md --queue-timeout 240` showing the stale-path repair plan. This report-only rework did not run validators, acquire leases, or edit by-* files.

## 2026-06-26 Resume MCP Revalidation

- At `2026-06-26T06:23:13-04:00`, direct JSON-RPC `initialize` and `tools/list` against `http://127.0.0.1:13337/mcp` succeeded. Current tool schema requires `database='80de0a67'` on inspection calls.
- `idb_list` reconfirmed one active owned/adopted worker session: `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, worker PID `26892`.
- `server_health(database='80de0a67')` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.
- `lookup_funcs(database='80de0a67')` reconfirmed `0x0057ea60` is not an IDA function, while `0x0057eaa0`, `0x0057eb00`, `0x0057f030`, `0x0057f490`, and `0x0057f530` are modeled as `sub_57EAA0`, `sub_57EB00`, `sub_57F030`, `sub_57F490`, and `sub_57F530` respectively.
- `xrefs_to(database='80de0a67')` reconfirmed no xrefs to `0x0057ea60` or `0x0057f290`, a data xref from `0x0057f0a4` to the dispatcher table at `0x0057f26c`, and a code xref from `0x0057eead` to `0x0057f490`.
- Follow-up check at `2026-06-26T06:43:02-04:00` reconfirmed `idb_list` session `80de0a67`, worker PID `26892`, `is_analyzing:false`; `server_health(database='80de0a67')` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`; `lookup_funcs(database='80de0a67')` reconfirmed `0x0057ea60` is not an IDA function and `0x0057f030` is modeled as `sub_57F030` size `0x23c`.
- The supervisor rejection changes the report recommendation: split [UID:0002RK] now, create exact child pages with formal C++ or no-code proof, and convert the broad page into a non-emitting index parent. The earlier target/support-only recommendation is superseded.

## Function And Raw-Span Inventory

| Range | Current IDA state | Source-facing role |
| --- | --- | --- |
| `0x0057ea57-0x0057ea60` | `0xcc` alignment | Pre-constructor padding from the prior child. |
| `0x0057ea60-0x0057eaa0` | no function object; `insn_query` decodes 17 instructions ending at `retn` | `SpellInventoryPane2` constructor/setup. Calls `sub_545090`, stores vtables `0x0062d0f4`, `0x0062d144`, `0x0062d174`, clears `+0xf8` word and `+0xfa` byte. |
| `0x0057eaa0-0x0057eac0` | `sub_57EAA0`, size `0x1f` | Destructor/teardown helper or reset-vtables-and-base-cleanup body. Stores the same three vtable views and tail-calls `sub_5450D0`. No direct xrefs found. |
| `0x0057eac0-0x0057ead5` | `sub_57EAC0`, size `0x15`; data xref from `0x0062d13c` | `ResetPage` style virtual: clears page word at `+0xf8` and calls child/refresh virtual at vtable slot `+0x20` on the embedded pane view. |
| `0x0057ead5-0x0057eae0` | alignment | Padding before raw setter. |
| `0x0057eae0-0x0057eaee` | no function object; raw 6-instruction body | `SetSpellInputActive` duplicate/local setter: writes argument byte to `this+0xfa`, returns `retn 4`. |
| `0x0057eaf0-0x0057eaf1` | `nullsub_55`, size `0x1` | Empty virtual/no-op retained as one-byte `retn`. |
| `0x0057eaf1-0x0057eb00` | alignment | Padding before paint. |
| `0x0057eb00-0x0057eda4` | `sub_57EB00`, size `0x2a4`; vtable/data xref from `0x0062d138` | Paint/list method. Loads `SPELLINV.EPF`, scans learned spell records from `dword_67A748 + 0x13a6ec + 0x148 * slot`, draws hotkey/name rows, sets page/next flags. |
| `0x0057edb0-0x0057ee2c` | `sub_57EDB0`, size `0x7c`; vtable/data xref from `0x0062d14c` | Page-key handling. Uses `std::ctype<char>::do_narrow`, PageUp/PageDown-like values, modifies `+0xf8`, checks `+0xf9`, refreshes child pane. |
| `0x0057ee30-0x0057eff7` | `sub_57EE30`, size `0x1c7`; vtable/data xref from `0x0062d148` | Mouse handler. Blocks when local-player guard at `dword_67A748 + 0x13eb1d` is set (Verified with int_convert.py) or pending input `+0xfa` is set, handles page buttons, row hit-test, visible-row mapping, and dispatcher call. |
| `0x0057f000-0x0057f028` | `sub_57F000`, size `0x28`; vtable/data xref from `0x0062d154` | Message/reset handler. For message bytes `23` or `24`, calls a virtual at base-adjusted slot `+0x48` with zero, then returns false. |
| `0x0057f030-0x0057f26c` | `sub_57F030`, size `0x23c`; code caller `0x0057eeef` | `ActivateSpellSlot`. Checks one-based slot `1..52`, validates learned spell record, then dispatches on `spellRecord[+4] - 1`. |
| `0x0057f26c-0x0057f28c` | data xref from `0x0057f0a4` | Eight-entry dispatcher jump table: `0x0057f0ab`, `0x0057f0df`, `0x0057f113`, `0x0057f147`, `0x0057f17b`, `0x0057f1c3`, `0x0057f1f0`, `0x0057f21d`. |
| `0x0057f28c-0x0057f290` | alignment | Padding before local packet helper. |
| `0x0057f290-0x0057f2ee` | no function object; no direct xrefs | Local direct-cast packet sender. Calls `sub_575380(0x0f, &packet[0])`, writes slot byte through second `sub_575380`, zero terminates scratch byte, and sends two bytes through `sub_574BB0(dword_67A7EC, packet, 2)`. |
| `0x0057f2f0-0x0057f36f` | no function object; no direct xrefs | Page-button rectangle builder. Index `0` builds `(14,221)-(36,239)`, index `1` builds `(157,221)-(179,239)`, otherwise invalid `-1` rect. |
| `0x0057f371-0x0057f380` | alignment | Padding. |
| `0x0057f380-0x0057f3d1` | no function object; no direct xrefs | Spell-row rectangle builder. Rows `0..9` build `(2, 10 + 23 * row)-(170, 33 + 23 * row)`, otherwise invalid rect. |
| `0x0057f3d3-0x0057f3e0` | alignment | Padding. |
| `0x0057f3e0-0x0057f486` | no function object; no direct xrefs | Page-button hit-test helper. Iterates the two page-button rectangles, calls rectangle builder and `sub_4B7E80`, returns `0`, `1`, or `-1`. |
| `0x0057f488-0x0057f490` | alignment | Padding before modeled row hit-test. |
| `0x0057f490-0x0057f523` | `sub_57F490`, code caller `0x0057eead` | `HitTestSpellRow`: scans ten row rectangles and returns row index or `-1`. |
| `0x0057f530-0x0057f58b` | `sub_57F530`, code caller `0x0057eed6` | `VisibleOrdinalToSpellSlot`: maps visible row ordinal to one-based spell slot by scanning active spell records. |

## Positive Evidence

- The raw constructor/setup body at `0x0057ea60` is real source-authored class code, not padding: it starts after nine `0xcc` bytes, calls the same base constructor family as related panes, stores all three `SpellInventoryPane2` vtable views, clears class state, and returns cleanly.
- The direct owner remains [UID:0000DO] `SpellInventoryPane2`. The constructor and `sub_57EAA0` store the `SpellInventoryPane2` vtable group, modeled virtuals are referenced from the same `.rdata` vtable group, and the mouse/dispatcher/paint behavior is alternate spell pane logic.
- The source root remains [UID:0000O1] `SpellInventoryPane`: the code uses the same spell inventory record model, resources, input-pane constructors, and packet funnel documented for the legacy and new spell inventory family.
- `0x0057f26c-0x0057f28c` is a true switch table owned by `sub_57F030`, not a helper body or padding. The following `0x0057f290-0x0057f485` span decodes into four retained local helper bodies.
- The current stale generated tracker row is explainable by validator registry state. The live by-memory page is correctly named and the dry-run validator knows the exact path update required.
- The current support docs are broadly correct but incomplete/stale: [UID:0000DO] and [UID:0000O1] mention `+0xf8` and `+0xfa`, and prior text may describe `+0xf9` as a next-page flag. This pass corrects `+0xf9` to `m_isLastPage`, because paint sets it true and clears it only when a later learned spell exists.

## Negative Evidence And Rejected Alternatives

- No direct xref, data ref, immediate ref, or little-endian absolute pointer hit was found for raw starts `0x0057ea60`, `0x0057eae0`, `0x0057f290`, `0x0057f2f0`, `0x0057f380`, or `0x0057f3e0`. This rejects promotion of those raw starts as independently routed public entry points right now; it does not reject them as source-authored code because byte shape and local use prove their roles.
- `0x0057eaa0` also has no direct xrefs despite being a modeled function. Treat it as retained teardown/reset helper evidence until an exact destructor-flow split proves the source spelling. Do not overclaim it as a vtable slot.
- [UID:0001IH] is not the source owner. It is a mixed physical split/index over legacy, new-pane, alternate-pane, shared state helpers, and compiler destructor glue.
- [UID:00026J] is not the source owner. Its spell-inventory vtables and strings are `.rdata` evidence that should regenerate from class declarations and source literals.
- [UID:0000O0] `SpellInputPanes`, [UID:0000OH] `TargetSelectionInputPanes`, [UID:0000NS] Socket/packet send docs, and [UID:0002W8]/historical `dword_67A748` local-player storage are dependencies, not direct owners of this range.
- The old tracker path `0x0057eaa0-0x0057f58b` is stale. It should not be restored, and no manual generated-report edit should be made.

## Heuristic / Inference Reanalysis And Validation

### Field Names

Best current source-facing names for [UID:0002RK]:

| Offset | Evidence | Best inferred name |
| --- | --- | --- |
| `+0xf8` (`248`, `0xf8`, Verified with int_convert.py) | Constructor clears word; `ResetPage` clears it; key and page-button paths decrement/increment it; paint uses it as `13 * page` skip count. | `m_pageIndex` or `m_currentPage`; prefer `m_pageIndex` for consistency with zero-based page arithmetic. |
| `+0xf9` (`249`, `0xf9`, Verified with int_convert.py) | Paint sets it true before scanning for remaining spells and clears it if a later learned spell exists; key/page-down checks `!this[89]` before incrementing page. | `m_isLastPage`; reject prior `m_hasNextPage` wording as inverted. |
| `+0xfa` (`250`, `0xfa`, Verified with int_convert.py) | Constructor clears it; raw setter writes it; mouse handler blocks when set; dispatcher direct-cast clears it after sending packet. | `m_spellInputActive` or `m_pendingInput`; prefer `m_spellInputActive` because existing docs describe pending input and target-input state helpers. |

### Helper And Method Names

Use descriptive names now, marked inferred:

- `SpellInventoryPane2::SpellInventoryPane2`
- `SpellInventoryPane2::~SpellInventoryPane2`; reject `ResetVtablesAndCleanup`/`DestroyPaneCore` as decompiler-mechanics names.
- `SpellInventoryPane2::ResetPage`
- `SpellInventoryPane2::SetSpellInputActive`
- `SpellInventoryPane2::OnPaint`
- `SpellInventoryPane2::OnKeyEvent`
- `SpellInventoryPane2::OnMouseEvent`
- `SpellInventoryPane2::OnPaneMessage`
- `SpellInventoryPane2::ActivateSpellSlot`
- local static/helper names `SendDirectSpellPacket`, `BuildPageButtonRect`, `BuildSpellRowRect`, `HitTestPageButton`, `HitTestSpellRow`, and `VisibleOrdinalToSpellSlot`.

These are not original-name proof, but they are source-facing and avoid IDA/decompiler labels. They match behavior and the existing legacy spell inventory naming pattern.

### Dispatcher Route Names

`sub_57F030` dispatch order remains:

1. string prompt constructor `0x005adf40`,
2. who/target prompt constructor `0x005ae2a0`,
3. four-argument prompt constructor `0x005b0780`,
4. three-argument prompt constructor `0x005b0ac0`,
5. direct two-byte opcode `0x0f` cast packet through `sub_574BB0(dword_67A7EC, packet, 2)`,
6. two-argument prompt constructor `0x005b0da0`,
7. one-argument prompt constructor `0x005b1030`,
8. spell-slot prompt constructor `0x005b1280`.

Use the current-pass `SpellInputKind` enum names listed below. A later project-wide pass may adjust exact spelling, but raw route numbers or `caseN` placeholders should not remain in emitted C++.

### Source Placement

[UID:0002RK] should stay source-routed through [UID:0000DO] `SpellInventoryPane2`, likely under [UID:0000O1] `NexusTK/ui/inventory/SpellInventoryPane.cpp`. Do not move it to `NewSpellInventoryPane`, `SpellInputPanes`, `TargetSelectionInputPanes`, packet/socket code, or the `.rdata` aggregate. The alternate class is physically adjacent to new-pane code, but its vtable group and method behavior are distinct.

## Split / Range Recommendation

Reworked recommendation after supervisor rejection: **split [UID:0002RK] now, make the broad page a non-emitting index/coverage parent, and create exact child pages with formal C++ or exact no-code proof during the accepted implementation callback.** The previous target/support-only recommendation is superseded and should not be implemented.

Reasoning:

- The range is one class-owned source island, but it is not one source function. It contains a raw constructor, destructor/reset body, virtual methods, retained local helpers, a dispatcher jump table, and alignment bytes. Leaving [UID:0002RK] as one emitting aggregate with blank C++ would preserve a source-quality blocker instead of fixing it.
- The split is now implementation-ready. Current MCP session `80de0a67` gives exact modeled function starts/sizes, raw-span disassembly, jump-table xref, helper roles, caller/callee evidence, and negative raw-entry routes. The remaining names are best-inferred source-facing names, not blockers.
- `0x0057f26c` is compiler-lowered jump table data owned by `ActivateSpellSlot`, not a separate human-authored source unit.
- Padding/alignment remains documented on the parent and is not reconstructable source code.

Convert [UID:0002RK] to:

- `COMPLETION:90`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:0000DO`
- `RECONSTRUCTABLE:FALSE`
- blank `EMITTER_UIDS`
- blank `RECONSTRUCTION_CPP CODE`

The no-code proof for [UID:0002RK] is structural: after child pages exist, the broad range is only an index over method/helper children plus jump-table/alignment bytes. Any aggregate formal C++ would duplicate children or conflate unrelated class methods/local helpers into a decompiler-shaped wrapper that original source would not have contained.

Implementation-ready child plan:

| Proposed file | Role | Completion | Confidence | Owner | Reconstructable | Emitters | Nested | Formal C++ disposition |
| --- | --- | ---: | ---: | --- | --- | --- | ---: | --- |
| `by-memory/0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md` | raw constructor/setup | 90 | 92 | `0000DO` | `TRUE` | `0000DO` | 0 | Insert formal constructor C++ below. |
| `by-memory/0x0057eaa0-0x0057eac0.SpellInventoryPane2Destructor.md` | non-deleting destructor body | 90 | 92 | `0000DO` | `TRUE` | `0000DO` | 0 | Insert formal destructor C++ below. |
| `by-memory/0x0057eac0-0x0057ead5.SpellInventoryPane2ResetPage.md` | reset page virtual | 89 | 91 | `0000DO` | `TRUE` | `0000DO` | 0 | Insert formal reset C++ below. |
| `by-memory/0x0057eae0-0x0057eaee.SpellInventoryPane2SetSpellInputActive.md` | raw target-input state setter | 89 | 91 | `0000DO` | `TRUE` | `0000DO` | 0 | Insert formal setter C++ below. |
| `by-memory/0x0057eaf0-0x0057eaf1.SpellInventoryPane2SourceEmptyVirtual.md` | one-byte no-op virtual | 86 | 92 | `0000DO` | `FALSE` | blank | 0 | Exact no-code proof; no formal C++ body. |
| `by-memory/0x0057eb00-0x0057eda4.SpellInventoryPane2OnPaint.md` | paint/list method | 89 | 91 | `0000DO` | `TRUE` | `0000DO` | 0 | Insert formal paint C++ below. |
| `by-memory/0x0057edb0-0x0057ee2c.SpellInventoryPane2OnKeyEvent.md` | page key handling | 89 | 91 | `0000DO` | `TRUE` | `0000DO` | 0 | Insert formal key C++ below. |
| `by-memory/0x0057ee30-0x0057eff7.SpellInventoryPane2OnMouseEvent.md` | mouse/page/spell activation | 89 | 91 | `0000DO` | `TRUE` | `0000DO` | 0 | Insert formal mouse C++ below. |
| `by-memory/0x0057f000-0x0057f028.SpellInventoryPane2OnPaneMessage.md` | spell-input reset message handler | 88 | 90 | `0000DO` | `TRUE` | `0000DO` | 0 | Insert formal message C++ below. |
| `by-memory/0x0057f030-0x0057f28c.SpellInventoryPane2ActivateSpellSlot.md` | dispatcher plus compiler jump table | 90 | 92 | `0000DO` | `TRUE` | `0000DO` | 0 | Insert formal dispatcher C++ below; carry jump table as compiler lowering. |
| `by-memory/0x0057f290-0x0057f2ee.SpellInventoryPane2SendDirectSpellPacket.md` | retained direct-cast packet helper | 89 | 91 | `0000DO` | `TRUE` | `0000DO` | 0 | Insert formal local helper C++ below. |
| `by-memory/0x0057f2f0-0x0057f36f.SpellInventoryPane2BuildPageButtonRect.md` | page button rectangle builder | 90 | 92 | `0000DO` | `TRUE` | `0000DO` | 0 | Insert formal local helper C++ below. |
| `by-memory/0x0057f380-0x0057f3d1.SpellInventoryPane2BuildSpellRowRect.md` | row rectangle builder | 90 | 92 | `0000DO` | `TRUE` | `0000DO` | 0 | Insert formal local helper C++ below. |
| `by-memory/0x0057f3e0-0x0057f486.SpellInventoryPane2HitTestPageButton.md` | two-button hit test | 90 | 92 | `0000DO` | `TRUE` | `0000DO` | 0 | Insert formal local helper C++ below. |
| `by-memory/0x0057f490-0x0057f523.SpellInventoryPane2HitTestSpellRow.md` | ten-row hit test | 90 | 92 | `0000DO` | `TRUE` | `0000DO` | 0 | Insert formal local helper C++ below. |
| `by-memory/0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot.md` | visible ordinal to one-based spell slot mapper | 90 | 92 | `0000DO` | `TRUE` | `0000DO` | 0 | Insert formal local helper C++ below. |

Padding/alignment subranges stay on [UID:0002RK] as non-reconstructable boundary evidence and should not become child pages: `0x0057ead5-0x0057eae0`, `0x0057eaf1-0x0057eb00`, `0x0057f28c-0x0057f290`, `0x0057f371-0x0057f380`, `0x0057f3d3-0x0057f3e0`, and `0x0057f488-0x0057f490`.

## Source-Facing Names And Rejected Alternatives

These names are not symbol-proven, but they are current-pass best source-facing choices. They should be used in formal child C++ and support docs instead of IDA labels:

| Binary fact | Best current source-facing name | Rejected alternatives / reason |
| --- | --- | --- |
| `this+0xf8`, word/dword-like page index cleared by constructor/reset and changed by page keys/buttons | `m_pageIndex` | `m_currentPage` is plausible but less aligned with direct index arithmetic. |
| `this+0xf9`, set `true` by paint and cleared if any learned spell remains after visible rows; page-down tests `!this[89]` | `m_isLastPage` | Previous `m_hasNextPage` is wrong/inverted. `m_noNextPage` is behaviorally correct but less natural for UI code. |
| `this+0xfa`, gate set when prompt panes open, cleared by direct-cast and message reset | `m_spellInputActive` | `m_targetInputActive` is too narrow; routes include string/number/spell-slot prompts. |
| record at `g_pUserPane + 0x13a6ec + slot * 0x148`, byte `+0`, dword `+4` | `UserSpellRecord`, `learned`, `inputKind` | `SpellRecord::enabled` and `route` were rejected because byte `+0` gates learned/available spells and dword `+4` dispatches input kind, not network opcode. |
| `inputKind` cases 1..8 | `kSpellInputString`, `kSpellInputTarget`, `kSpellInputFourArguments`, `kSpellInputThreeArguments`, `kSpellInputDirect`, `kSpellInputTwoArguments`, `kSpellInputOneArgument`, `kSpellInputSpellSlot` | Raw numeric constants and `case5` names are rejected. `CastRoute` is too protocol-oriented for prompt-pane construction. |
| key event `a2[4] == 8`, `do_narrow(a2[8], a2[266])`, signed `0x93/0x94`, IME byte at `+266` | `PaneKeyEvent`, `eventKind`, `keyCode`, `imeActive`, `kPaneKeyPageUp`, `kPaneKeyPageDown` | Raw byte offsets and signed decimal `-109/-108` should stay evidence, not source names. |
| mouse event byte at `+4`, point fields consumed by rect hit tests | `PaneMouseEvent`, `event.type`, `event.x`, `event.y`, `kPaneMouseDown`, `kPaneMouseDoubleClick` | `OnMouseClick` is too narrow because the body gates on event type and supports page buttons plus double-click cast behavior. |
| pane message payload byte `23` or `24` clears input-active flag | `PaneMessage`, `kPaneMessageSpellInputClosed`, `kPaneMessageSpellInputCancelled` | Exact names are inferred; raw numeric-only code is not acceptable for final source shape. |
| `0x0057eaa0` vtable reset and base cleanup body | `SpellInventoryPane2::~SpellInventoryPane2()` | `ResetVtablesAndCleanup` describes compiler/decompiler mechanics, not the human source body. |
| `0x0057f290` local packet sender | `SendDirectSpellPacket` | `SendCastPacket` is too broad because only input-kind 5/no-prompt spells use it. |

Support declarations that should be documented with the children:

```cpp
enum SpellInputKind
{
    kSpellInputString = 1,
    kSpellInputTarget = 2,
    kSpellInputFourArguments = 3,
    kSpellInputThreeArguments = 4,
    kSpellInputDirect = 5,
    kSpellInputTwoArguments = 6,
    kSpellInputOneArgument = 7,
    kSpellInputSpellSlot = 8
};

struct UserSpellRecord
{
    unsigned char learned;
    unsigned char reserved0[3];
    SpellInputKind inputKind;
    unsigned char payload[0x140];
};
```

The `payload` field is intentionally conservative because this pass proves the `learned` and `inputKind` fields used by [UID:0002RK], while name text and prompt metadata should be documented from the larger spell-record consumers before tightening the whole struct.

## Score And Metadata Recommendation

After split implementation:

- [UID:0002RK] broad parent: `90/92`, `CANONICAL_OWNER:0000DO`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++.
- Every child row above should receive the listed score/metadata. Reconstructable child pages emit through [UID:0000DO]. The source-empty no-op child is non-reconstructable with blank emitter unless the supervisor explicitly wants a formal empty virtual body project-wide.
- [UID:0000DO] `by-class/SpellInventoryPane2.md`: raise from current `85/87` to at least `89/90` after support notes, field notes, method list, and child references are updated.
- [UID:0000O1] `by-file/SpellInventoryPane.md`: keep or raise to `88/89` depending on validator policy after support/source-root sync.
- [UID:0001IH] `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md`: keep non-emitting parent status; add a support sync to current MCP-backed split.

Reason this is higher than the rejected report:

- The broad-island blocker is repaired by a concrete split, not deferred.
- The child pages have exact ranges, metadata, owner/emitter route, C++/no-code disposition, and validators.
- Source-facing names for route enums, event/message fields, spell-record fields, and destructor/reset spelling are inferred and alternatives are rejected.
- Aggregate no-code is now paired with a child-emission plan instead of blank C++.

## Formal C++ For Child Pages

All C++ below is intended as exact `RECONSTRUCTION_CPP CODE` insertion content for the corresponding child pages after supervisor acceptance. It is first-draft but formal; it should not be copied into prose-only sections.

### `0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md`

```cpp
SpellInventoryPane2::SpellInventoryPane2()
{
    m_pageIndex = 0;
    m_isLastPage = false;
    m_spellInputActive = false;
}
```

Notes: the binary calls the base setup before vtable stores and clears `+0xf8` and `+0xfa`; `+0xf9` is left false by zeroed construction/base initialization. If the class declaration requires an explicit base initializer, use the established `Pane`/inventory-pane base once confirmed in [UID:0000DO].

### `0x0057eaa0-0x0057eac0.SpellInventoryPane2Destructor.md`

```cpp
SpellInventoryPane2::~SpellInventoryPane2()
{
}
```

Notes: decompilation shows vtable restoration and base cleanup. That is ordinary non-deleting destructor lowering, so the source-facing function is the destructor, not a helper named `ResetVtablesAndCleanup`.

### `0x0057eac0-0x0057ead5.SpellInventoryPane2ResetPage.md`

```cpp
void SpellInventoryPane2::ResetPage()
{
    m_pageIndex = 0;
    Invalidate();
}
```

### `0x0057eae0-0x0057eaee.SpellInventoryPane2SetSpellInputActive.md`

```cpp
void SpellInventoryPane2::SetSpellInputActive(bool active)
{
    m_spellInputActive = active;
}
```

### `0x0057eaf0-0x0057eaf1.SpellInventoryPane2SourceEmptyVirtual.md`

Exact no-code proof: the entire child body is one `retn`, has no side effects, no callees, and no meaningful body separate from the vtable slot declaration. Keep formal C++ blank for this child unless the supervisor explicitly chooses to emit source-empty virtual bodies project-wide.

### `0x0057eb00-0x0057eda4.SpellInventoryPane2OnPaint.md`

```cpp
void SpellInventoryPane2::OnPaint()
{
    EpfFrame spellIcon;
    RectBounds textRect(12, 20, 22, 41);
    int visibleOrdinal = 0;

    LoadEpfFrame(g_pEPFLib, L"SPELLINV.EPF", 0, &spellIcon);
    DrawEpfFrame(0, 0, spellIcon);

    m_isLastPage = true;

    for (int spellSlot = 1; spellSlot <= kMaxSpellInventorySlots; ++spellSlot)
    {
        const UserSpellRecord& spell = g_pUserPane->GetSpellRecord(spellSlot);
        if (!spell.learned)
            continue;

        ++visibleOrdinal;
        if (visibleOrdinal <= m_pageIndex * kSpellInventoryRows)
            continue;

        if (visibleOrdinal > (m_pageIndex + 1) * kSpellInventoryRows)
        {
            m_isLastPage = false;
            break;
        }

        const char hotkey = SlotIndexToHotkeyLetter(spellSlot);
        DrawSpellHotkey(textRect, hotkey);
        DrawSpellName(textRect, spell);
        OffsetRect(&textRect, 0, 23);
    }
}
```

Notes: helper names `EpfFrame`, `LoadEpfFrame`, `DrawEpfFrame`, `DrawSpellHotkey`, `DrawSpellName`, and `SlotIndexToHotkeyLetter` are inferred from local behavior and existing UI/resource patterns. Keep raw offsets and color constants in evidence prose until the shared drawing helpers are fully typed.

### `0x0057edb0-0x0057ee2c.SpellInventoryPane2OnKeyEvent.md`

```cpp
bool SpellInventoryPane2::OnKeyEvent(PaneKeyEvent *event)
{
    if (event->eventKind != kPaneKeyDown || event->imeActive)
        return false;

    const int key = NarrowInputEventByte(event);

    if (key == kPaneKeyPageUp)
    {
        if (m_pageIndex > 0)
        {
            --m_pageIndex;
            Invalidate();
        }
        return true;
    }

    if (key == kPaneKeyPageDown)
    {
        if (!m_isLastPage)
        {
            ++m_pageIndex;
            Invalidate();
        }
        return true;
    }

    return false;
}
```

### `0x0057ee30-0x0057eff7.SpellInventoryPane2OnMouseEvent.md`

```cpp
bool SpellInventoryPane2::OnMouseEvent(const PaneMouseEvent& event)
{
    if (g_pUserPane->m_localInputLocked)
        return false;

    bool handled = false;

    if (event.type == kPaneMouseDown)
    {
        const int button = HitTestPageButton(event.x, event.y);
        if (button == 0 && m_pageIndex > 0)
        {
            --m_pageIndex;
            Invalidate();
            handled = true;
        }
        else if (button == 1 && !m_isLastPage)
        {
            ++m_pageIndex;
            Invalidate();
            handled = true;
        }

        if (!handled && !g_pConfig->m_spellInventoryDoubleClickCast && !m_spellInputActive)
        {
            const int row = HitTestSpellRow(event.x, event.y);
            if (row >= 0)
            {
                const int spellSlot = VisibleOrdinalToSpellSlot(m_pageIndex * kSpellInventoryRows + row + 1);
                ActivateSpellSlot(spellSlot);
                handled = true;
            }
        }
    }
    else if (event.type == kPaneMouseDoubleClick)
    {
        if (g_pConfig->m_spellInventoryDoubleClickCast && !m_spellInputActive)
        {
            const int row = HitTestSpellRow(event.x, event.y);
            if (row >= 0)
            {
                const int spellSlot = VisibleOrdinalToSpellSlot(m_pageIndex * kSpellInventoryRows + row + 1);
                ActivateSpellSlot(spellSlot);
                handled = true;
            }
        }
    }

    return handled;
}
```

Notes: `m_spellInventoryDoubleClickCast` is the best current name for `dword_67A7C8 + 0x28de5a`; the byte gates single-click versus double-click spell activation.

### `0x0057f000-0x0057f028.SpellInventoryPane2OnPaneMessage.md`

```cpp
bool SpellInventoryPane2::OnPaneMessage(const PaneMessage& message)
{
    if (message.payload[0] == kPaneMessageSpellInputClosed ||
        message.payload[0] == kPaneMessageSpellInputCancelled)
    {
        SetSpellInputActive(false);
    }

    return false;
}
```

### `0x0057f030-0x0057f28c.SpellInventoryPane2ActivateSpellSlot.md`

```cpp
void SpellInventoryPane2::ActivateSpellSlot(int spellSlot)
{
    if (spellSlot < 1 || spellSlot > kMaxSpellInventorySlots)
        return;

    const UserSpellRecord& spell = g_pUserPane->GetSpellRecord(spellSlot);
    if (!spell.learned)
        return;

    switch (spell.inputKind)
    {
    case kSpellInputString:
        new SpellStringInputPane(spellSlot);
        m_spellInputActive = true;
        break;
    case kSpellInputTarget:
        new SpellWhoInputPane(spellSlot);
        m_spellInputActive = true;
        break;
    case kSpellInputFourArguments:
        new SpellFourArgsInputPane(spellSlot);
        m_spellInputActive = true;
        break;
    case kSpellInputThreeArguments:
        new SpellThreeArgsInputPane(spellSlot);
        m_spellInputActive = true;
        break;
    case kSpellInputDirect:
        SendDirectSpellPacket(spellSlot);
        m_spellInputActive = false;
        break;
    case kSpellInputTwoArguments:
        new SpellTwoArgsInputPane(spellSlot);
        m_spellInputActive = true;
        break;
    case kSpellInputOneArgument:
        new SpellOneArgInputPane(spellSlot);
        m_spellInputActive = true;
        break;
    case kSpellInputSpellSlot:
        new SpellSlotInputPane(spellSlot);
        m_spellInputActive = true;
        break;
    default:
        break;
    }
}
```

### `0x0057f290-0x0057f2ee.SpellInventoryPane2SendDirectSpellPacket.md`

```cpp
void SpellInventoryPane2::SendDirectSpellPacket(int spellSlot)
{
    unsigned char packet[3];

    WritePacketByte(packet, 0x0f);
    WritePacketByte(packet + 1, spellSlot);
    packet[2] = 0;

    g_pPacketSender->Send(packet, 2);
}
```

Notes: the binary uses packet helper calls around a stack buffer and sends length `2` through `sub_574BB0(dword_67A7EC, packet, 2)`. `WritePacketByte` and `g_pPacketSender->Send` are source-facing helper names inferred from the packet-sender pattern; do not emit raw helper labels.

### `0x0057f2f0-0x0057f36f.SpellInventoryPane2BuildPageButtonRect.md`

```cpp
void SpellInventoryPane2::BuildPageButtonRect(int button, RectBounds *rect)
{
    if (button == 0)
    {
        rect->Set(14, 221, 36, 239);
    }
    else if (button == 1)
    {
        rect->Set(157, 221, 179, 239);
    }
    else
    {
        rect->Set(-1, -1, -1, -1);
    }
}
```

### `0x0057f380-0x0057f3d1.SpellInventoryPane2BuildSpellRowRect.md`

```cpp
void SpellInventoryPane2::BuildSpellRowRect(int row, RectBounds *rect)
{
    if (row < 0 || row >= kSpellInventoryRows)
    {
        rect->Set(-1, -1, -1, -1);
        return;
    }

    const int top = 10 + row * 23;
    rect->Set(2, top, 170, top + 23);
}
```

### `0x0057f3e0-0x0057f486.SpellInventoryPane2HitTestPageButton.md`

```cpp
int SpellInventoryPane2::HitTestPageButton(int x, int y)
{
    for (int button = 0; button < 2; ++button)
    {
        RectBounds rect;
        BuildPageButtonRect(button, &rect);
        if (rect.Contains(x, y))
            return button;
    }

    return -1;
}
```

### `0x0057f490-0x0057f523.SpellInventoryPane2HitTestSpellRow.md`

```cpp
int SpellInventoryPane2::HitTestSpellRow(int x, int y)
{
    for (int row = 0; row < kSpellInventoryRows; ++row)
    {
        RectBounds rect;
        BuildSpellRowRect(row, &rect);
        if (rect.Contains(x, y))
            return row;
    }

    return -1;
}
```

### `0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot.md`

```cpp
int SpellInventoryPane2::VisibleOrdinalToSpellSlot(int visibleOrdinal)
{
    int learnedCount = 0;

    for (int spellSlot = 1; spellSlot <= kMaxSpellInventorySlots; ++spellSlot)
    {
        const UserSpellRecord& spell = g_pUserPane->GetSpellRecord(spellSlot);
        if (!spell.learned)
            continue;

        ++learnedCount;
        if (learnedCount == visibleOrdinal)
            return spellSlot;
    }

    return -1;
}
```

## Open Questions With Attempted Resolution

- Raw constructor lacks IDA function/xrefs: resolved by creating the exact constructor child. Negative route evidence affects confidence wording but does not block source reconstruction because raw bytes prove the base call, vtable triad, and member clears.
- Raw local helper starts have no direct entry route: resolved by splitting them as class-local helper children. They are source-authored retained helper bodies because they have distinct behavior, stack cookies where expected, and direct calls/uses from `SpellInventoryPane2` methods.
- `0x0057eaa0` spelling: resolved as `SpellInventoryPane2::~SpellInventoryPane2()` rather than a source helper. Vtable reset/base cleanup are compiler/destructor lowering.
- Spell-route enum names: resolved as `SpellInputKind` and `kSpellInput*` names above. Numeric cases and `caseN` names rejected.
- Event/message names: resolved to current project-facing `PaneKeyEvent`, `PaneMouseEvent`, and `PaneMessage` names with inferred constants. Exact original class spelling remains inferential but no longer blocks C++.
- Spell record fields: current child C++ needs only `learned` and `inputKind`. Full record payload remains intentionally conservative until broader spell consumers tighten it.
- Stale tracker path `0x0057eaa0` versus live page `0x0057ea60`: validator-owned repair only. Implementation should run scoped validation on the live page and later execute the report; do not manually edit generated tracker rows.
- Owner/source placement: [UID:0000DO] remains direct class owner and [UID:0000O1] remains likely file root. `SpellInputPanes`, packet sender, config/global docs, and vtable pages are support dependencies, not alternate owners.

## Recommended Target Doc Changes

Apply these only after supervisor acceptance and implementation callback:

1. Convert [UID:0002RK] `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` into a non-emitting split/index parent:
   - set metadata to `90/92`, `CANONICAL_OWNER:0000DO`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++;
   - add the current MCP session `80de0a67` evidence, including the `2026-06-26T06:43` recheck;
   - add child list, padding/alignment notes, source-facing names, no-aggregate-C++ proof, and stale-path validator plan.
2. Create every child page listed in the implementation-ready child plan:
   - use the listed half-open range, metadata, owner/emitter, `Nested:0`, evidence summary, and formal C++/no-code disposition;
   - link each child back to [UID:0002RK], [UID:0000DO], and [UID:0000O1] as appropriate.
3. Update [UID:0000DO] `by-class/SpellInventoryPane2.md`:
   - add or correct fields `m_pageIndex`, `m_isLastPage`, and `m_spellInputActive`;
   - replace stale `m_hasNextPage` wording with `m_isLastPage` and explain the inversion evidence;
   - list the method/local-helper children and source-facing route/event names;
   - raise support metadata to at least `89/90` if validator policy allows.
4. Update [UID:0000O1] `by-file/SpellInventoryPane.md`:
   - document the split and likely source root;
   - note that `SpellInventoryPane2` owns the dispatcher/local helper children while prompt pane constructors and packet sender remain dependencies.
5. Update [UID:0001IH] `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md`:
   - keep it non-emitting;
   - add current live MCP confirmation for [UID:0002RK] and child coverage.
6. Optional support docs if supervisor wants full cross-linking in the same callback:
   - [UID:00026J] vtable/readonly-data page: add child method name mapping if not already present at equal detail;
   - `by-global/g_pCollectionData.md`: add the `UserSpellRecord` `learned`/`inputKind` field names if not already present at equal detail;
   - `by-file/SpellInputPanes.md`: cross-link route constructors to the inferred `SpellInputKind` names.

## Expected Validators After Implementation

Run from `source-3/project-documentation` after implementation callback edits:

> Executable block R001 was removed from this report and preserved verbatim in [0002RK-SpellInventoryPane2CoreAndHelpers-source-quality-removed.md](0002RK-SpellInventoryPane2CoreAndHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After supervisor verifies implementation, execute this report with the validator lifecycle command:

> Executable block R002 was removed from this report and preserved verbatim in [0002RK-SpellInventoryPane2CoreAndHelpers-source-quality-removed.md](0002RK-SpellInventoryPane2CoreAndHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Manual Coverage / Generated Report Disposition

- B008 must not edit `by-memory/-coverage-report.md`, generated reports, project-level reports, validator state, or IDA DB.
- Manual coverage updates, if needed, are supervisor-owned after verified implementation.
- `auto-generated/-ag-research-tracker.md` should refresh through the scoped validators and later `execute_report`; do not manually edit the stale `0x0057eaa0` row.

## Implementation Tracking Checklist

Implementation callback status: B008 applied the accepted split/index implementation to required target/support by-* docs, created the exact child pages, ran scoped validators, and did not edit generated/project-level files, manual coverage reports, validator/tool state, or IDA DB. The report should still be executed only by the supervisor after independent claim-by-claim verification.

- [x] Convert [UID:0002RK] into a non-emitting split/index parent with `90/92`, owner `0000DO`, `RECONSTRUCTABLE:FALSE`, blank emitter, blank formal C++, child list, padding notes, no-aggregate-C++ proof, current MCP evidence, and stale-path validator plan. Proof: `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` now has the requested metadata, blank formal C++, exact child table [UID:00044D] through [UID:00044S], `m_isLastPage` correction, stale-path validator plan, MCP session `80de0a67` evidence, negative raw-route evidence, source-placement rationale, and explicit no-aggregate-C++ proof.
- [x] Create `by-memory/0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md` with listed metadata and formal constructor C++. Proof: child [UID:00044D] exists at `90/92`, owner/emitter [UID:0000DO], `RECONSTRUCTABLE:TRUE`, `Nested:0`, and formal `RECONSTRUCTION_CPP CODE` contains the constructor body.
- [x] Create `by-memory/0x0057eaa0-0x0057eac0.SpellInventoryPane2Destructor.md` with listed metadata and formal destructor C++. Proof: child [UID:00044E] exists at `90/92`, owner/emitter [UID:0000DO], `RECONSTRUCTABLE:TRUE`, `Nested:0`, and formal C++ contains `SpellInventoryPane2::~SpellInventoryPane2()`.
- [x] Create `by-memory/0x0057eac0-0x0057ead5.SpellInventoryPane2ResetPage.md` with listed metadata and formal reset C++. Proof: child [UID:00044F] exists at `89/91`, owner/emitter [UID:0000DO], `RECONSTRUCTABLE:TRUE`, and formal C++ resets `m_pageIndex` and invalidates/redraws the pane.
- [x] Create `by-memory/0x0057eae0-0x0057eaee.SpellInventoryPane2SetSpellInputActive.md` with listed metadata and formal setter C++. Proof: child [UID:00044G] exists at `89/91`, owner/emitter [UID:0000DO], `RECONSTRUCTABLE:TRUE`, and formal C++ writes `m_spellInputActive`.
- [x] Create `by-memory/0x0057eaf0-0x0057eaf1.SpellInventoryPane2SourceEmptyVirtual.md` with listed metadata and exact no-code proof. Proof: child [UID:00044H] exists at `86/92`, owner [UID:0000DO], `RECONSTRUCTABLE:FALSE`, blank emitter/formal C++, and target-specific no-code proof states the range is a one-byte `retn` with no side effects/callees.
- [x] Create `by-memory/0x0057eb00-0x0057eda4.SpellInventoryPane2OnPaint.md` with listed metadata and formal paint C++. Proof: child [UID:00044I] exists at `89/91`, owner/emitter [UID:0000DO], `RECONSTRUCTABLE:TRUE`, and formal C++ models `SPELLINV.EPF`, learned spell scan, hotkey/name row drawing, page skip, and `m_isLastPage`.
- [x] Create `by-memory/0x0057edb0-0x0057ee2c.SpellInventoryPane2OnKeyEvent.md` with listed metadata and formal key-event C++. Proof: child [UID:00044J] exists at `89/91`, owner/emitter [UID:0000DO], `RECONSTRUCTABLE:TRUE`, and formal C++ handles Page Up/Page Down with IME and `m_isLastPage`.
- [x] Create `by-memory/0x0057ee30-0x0057eff7.SpellInventoryPane2OnMouseEvent.md` with listed metadata and formal mouse-event C++. Proof: child [UID:00044K] exists at `89/91`, owner/emitter [UID:0000DO], `RECONSTRUCTABLE:TRUE`, and formal C++ models local input lock, page buttons, single/double-click config gate, row hit-test, visible-slot mapping, and dispatcher call.
- [x] Create `by-memory/0x0057f000-0x0057f028.SpellInventoryPane2OnPaneMessage.md` with listed metadata and formal pane-message C++. Proof: child [UID:00044L] exists at `88/90`, owner/emitter [UID:0000DO], `RECONSTRUCTABLE:TRUE`, and formal C++ clears spell-input-active state for message payloads `23` or `24`.
- [x] Create `by-memory/0x0057f030-0x0057f28c.SpellInventoryPane2ActivateSpellSlot.md` with listed metadata, formal dispatcher C++, and jump-table compiler-lowering note. Proof: child [UID:00044M] exists at `90/92`, owner/emitter [UID:0000DO], `RECONSTRUCTABLE:TRUE`, formal C++ dispatches the eight `SpellInputKind` routes, and body prose documents the owned compiler-lowered jump table at `0x0057f26c-0x0057f28c`.
- [x] Create `by-memory/0x0057f290-0x0057f2ee.SpellInventoryPane2SendDirectSpellPacket.md` with listed metadata and formal packet-helper C++. Proof: child [UID:00044N] exists at `89/91`, owner/emitter [UID:0000DO], `RECONSTRUCTABLE:TRUE`, and formal C++ builds/sends the two-byte opcode `0x0f` direct spell packet.
- [x] Create `by-memory/0x0057f2f0-0x0057f36f.SpellInventoryPane2BuildPageButtonRect.md` with listed metadata and formal rectangle-helper C++. Proof: child [UID:00044O] exists at `89/91`, owner/emitter [UID:0000DO], `RECONSTRUCTABLE:TRUE`, and formal C++ emits previous/next page-button rectangles plus invalid fallback.
- [x] Create `by-memory/0x0057f380-0x0057f3d1.SpellInventoryPane2BuildSpellRowRect.md` with listed metadata and formal row-rectangle C++. Proof: child [UID:00044P] exists at `89/91`, owner/emitter [UID:0000DO], `RECONSTRUCTABLE:TRUE`, and formal C++ maps rows `0..9` to `(2, 10 + 23 * row)-(170, top + 23)`.
- [x] Create `by-memory/0x0057f3e0-0x0057f486.SpellInventoryPane2HitTestPageButton.md` with listed metadata and formal page-button hit-test C++. Proof: child [UID:00044Q] exists at `89/91`, owner/emitter [UID:0000DO], `RECONSTRUCTABLE:TRUE`, and formal C++ iterates the two button rectangles and returns `0`, `1`, or `-1`.
- [x] Create `by-memory/0x0057f490-0x0057f523.SpellInventoryPane2HitTestSpellRow.md` with listed metadata and formal row hit-test C++. Proof: child [UID:00044R] exists at `89/91`, owner/emitter [UID:0000DO], `RECONSTRUCTABLE:TRUE`, and formal C++ scans ten row rectangles.
- [x] Create `by-memory/0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot.md` with listed metadata and formal visible-ordinal mapper C++. Proof: child [UID:00044S] exists at `90/92`, owner/emitter [UID:0000DO], `RECONSTRUCTABLE:TRUE`, and formal C++ maps visible learned-spell ordinal to one-based spell slot.
- [x] Update [UID:0000DO] `by-class/SpellInventoryPane2.md` with fields `m_pageIndex`, `m_isLastPage`, `m_spellInputActive`, method/helper child mapping, source-facing names, and support score recommendation. Proof: metadata is now `89/90`; method/helper table maps [UID:00044D] through [UID:00044S]; current field note corrects `+0xf9` to `m_isLastPage`; class text records `SpellInputKind`, `UserSpellRecord`, source-placement, dependency separation, and blank class-level C++ rationale.
- [x] Update [UID:0000O1] `by-file/SpellInventoryPane.md` with split/source-root support, ownership rationale, and dependency separation. Proof: metadata is now `88/89`; file text documents [UID:0002RK] as a non-emitting split/index parent, child pages [UID:00044D] through [UID:00044S] routing through [UID:0000DO], `m_isLastPage`, and dependencies such as prompt panes, packet sender, config/global storage, and `UserPane` spell records as dependencies rather than alternate owners.
- [x] Update [UID:0001IH] `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md` with live MCP-backed split support while preserving non-emitting parent status. Proof: parent remains `87/90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++; text now records the [UID:0002RK] split into [UID:00044D] through [UID:00044S], current MCP-backed alternate-pane evidence, no future-child-C++ blocker for 0002RK, and `m_isLastPage`.
- [x] Optionally update [UID:00026J], `by-global/g_pCollectionData.md`, and `by-file/SpellInputPanes.md` if supervisor wants cross-linking beyond the required target/class/file/parent support edits. Proof/no-edit decision: not edited. `by-global/g_pCollectionData.md` already documents the `g_pUserPane + 0x13a6ec + slot * 0x148` spell-record view, learned/active byte, input kind/cast route dword, route numbers, and rejected `SpellManager`/`g_pSpellMan` names at equal or greater support detail. `by-file/SpellInputPanes.md` already documents the spell prompt constructors and direct packet helper family at broader detail. [UID:00026J] already documents the `SpellInventoryPane2` vtable triplet `0x0062d0f4`, `0x0062d144`, and `0x0062d174` and store refs. Required cross-linking is already present through the edited class/file/parent docs.
- [x] Run the scoped validators listed above, record exit code, `ok`, `command_id`, `command_timestamp`, generated-refresh state, and any validator-owned path/reference updates. Proof: all scoped validators below exited `0` with `ok:1`. Normal file validators scheduled/generated refresh work through validator-owned background jobs; queue status at command `000000002725` (`2026-06-26T14:38:17-04:00`) still showed generated-refresh jobs queued/processing, so generated output was not treated as current evidence by B008.
  - `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md`: command `000000002688`, `2026-06-26T14:35:51-04:00`, exit `0`, `ok:1`.
  - `by-memory/0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md`: command `000000002689`, `2026-06-26T14:35:57-04:00`, exit `0`, `ok:1`.
  - `by-memory/0x0057eaa0-0x0057eac0.SpellInventoryPane2Destructor.md`: command `000000002690`, `2026-06-26T14:35:58-04:00`, exit `0`, `ok:1`.
  - `by-memory/0x0057eac0-0x0057ead5.SpellInventoryPane2ResetPage.md`: command `000000002691`, `2026-06-26T14:36:00-04:00`, exit `0`, `ok:1`.
  - `by-memory/0x0057eae0-0x0057eaee.SpellInventoryPane2SetSpellInputActive.md`: command `000000002692`, `2026-06-26T14:36:01-04:00`, exit `0`, `ok:1`.
  - `by-memory/0x0057eaf0-0x0057eaf1.SpellInventoryPane2SourceEmptyVirtual.md`: command `000000002694`, `2026-06-26T14:36:03-04:00`, exit `0`, `ok:1`.
  - `by-memory/0x0057eb00-0x0057eda4.SpellInventoryPane2OnPaint.md`: command `000000002695`, `2026-06-26T14:36:05-04:00`, exit `0`, `ok:1`.
  - `by-memory/0x0057edb0-0x0057ee2c.SpellInventoryPane2OnKeyEvent.md`: command `000000002696`, `2026-06-26T14:36:06-04:00`, exit `0`, `ok:1`.
  - `by-memory/0x0057ee30-0x0057eff7.SpellInventoryPane2OnMouseEvent.md`: command `000000002697`, `2026-06-26T14:36:08-04:00`, exit `0`, `ok:1`.
  - `by-memory/0x0057f000-0x0057f028.SpellInventoryPane2OnPaneMessage.md`: command `000000002699`, `2026-06-26T14:36:20-04:00`, exit `0`, `ok:1`.
  - `by-memory/0x0057f030-0x0057f28c.SpellInventoryPane2ActivateSpellSlot.md`: command `000000002700`, `2026-06-26T14:36:22-04:00`, exit `0`, `ok:1`.
  - `by-memory/0x0057f290-0x0057f2ee.SpellInventoryPane2SendDirectSpellPacket.md`: command `000000002701`, `2026-06-26T14:36:24-04:00`, exit `0`, `ok:1`.
  - `by-memory/0x0057f2f0-0x0057f36f.SpellInventoryPane2BuildPageButtonRect.md`: command `000000002702`, `2026-06-26T14:36:25-04:00`, exit `0`, `ok:1`.
  - `by-memory/0x0057f380-0x0057f3d1.SpellInventoryPane2BuildSpellRowRect.md`: command `000000002703`, `2026-06-26T14:36:27-04:00`, exit `0`, `ok:1`.
  - `by-memory/0x0057f3e0-0x0057f486.SpellInventoryPane2HitTestPageButton.md`: command `000000002704`, `2026-06-26T14:36:28-04:00`, exit `0`, `ok:1`.
  - `by-memory/0x0057f490-0x0057f523.SpellInventoryPane2HitTestSpellRow.md`: command `000000002705`, `2026-06-26T14:36:30-04:00`, exit `0`, `ok:1`.
  - `by-memory/0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot.md`: command `000000002706`, `2026-06-26T14:36:41-04:00`, exit `0`, `ok:1`.
  - `by-class/SpellInventoryPane2.md`: command `000000002707`, `2026-06-26T14:36:43-04:00`, exit `0`, `ok:1`.
  - `by-file/SpellInventoryPane.md`: command `000000002708`, `2026-06-26T14:36:53-04:00`, exit `0`, `ok:1`.
  - `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md`: command `000000002709`, `2026-06-26T14:36:55-04:00`, exit `0`, `ok:1`.
- [x] B008 must report lease acquisition/release only during implementation callback; no leases were used for this report-only rework. Proof: implementation leases were taken for existing target/support files during the edit batch. The final physical-parent lease on `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md` was explicitly released by `python .\source-3\project-documentation\tools\leaser\leaser.py B008 unlease ...` with `Success`; final active-lease proof is reported in the implementation response.
- [ ] Supervisor verifies all report claims against implemented docs and then runs `execute_report B008 0002RK-SpellInventoryPane2CoreAndHelpers-source-quality.md 0002RK --apply`. This remains unchecked because report execution is supervisor-owned after independent verification.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0002RK-SpellInventoryPane2CoreAndHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0002RK-SpellInventoryPane2CoreAndHelpers-source-quality.md","timestamp":"2026-06-26T14:53:54","uid":"0002RK"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002RK-SpellInventoryPane2CoreAndHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/0002RK-SpellInventoryPane2CoreAndHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002RK"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
