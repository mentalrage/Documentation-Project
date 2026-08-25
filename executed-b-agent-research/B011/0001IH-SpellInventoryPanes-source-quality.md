** TARGET-REPORT-UID:0001IH **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B011 Source-Quality Report: [UID:0001IH] SpellInventoryPanes

Status: FINISHED

Target path: `source-3/project-documentation/by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md`

Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B011/research/0001IH-SpellInventoryPanes-source-quality.md`

Current target metadata checked:

```text
UID:0001IH
COMPLETION:85
CONFIDENCE:86
CANONICAL_OWNER:0000O1
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000O1
RECONSTRUCTION_CPP: blank
```

## Executive Recommendation

[UID:0001IH] should be reclassified from a source-bearing aggregate to a non-emitting split/index page.

Recommended metadata:

```text
COMPLETION:87
CONFIDENCE:90
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP: blank
```

Reason: the physical range is not one source body or one source file. It spans:

| Subrange / exact child | Best source route | Recommendation |
| --- | --- | --- |
| [UID:0002RI] `0x0057c2d0-0x0057cf6b` | legacy `SpellInventoryPane` family under [UID:0000O1] / [UID:0000DN] | source-authored child island, blank broad C++ |
| [UID:0001II] `0x0057c430-0x0057c43f` | [UID:0000DM] `SpellInputPaneState`, [UID:0000OH] `TargetSelectionInputPanes` | exact shared state helper; not spell-inventory-owned source |
| [UID:0002RJ] `0x0057cf70-0x0057ea57` | [UID:0000LU] / [UID:00009A] `NewSpellInventoryPane` | source-authored child island, blank broad C++ |
| [UID:0001IJ] `0x0057d0a0-0x0057d0af` | [UID:00006Y] `ItemWhoInputPaneState`, [UID:0000OH] `TargetSelectionInputPanes` | exact shared item-target state helper; not new-spell-inventory source |
| [UID:0002RK] `0x0057ea60-0x0057f58b` | [UID:0000DO] `SpellInventoryPane2`, source-rooted at [UID:0000O1] | source-authored child island including raw constructor/setup |
| [UID:0002RL] `0x0057f58b-0x0057f742` | none | compiler-generated destructor/thunk inventory; no source C++ |

The parent [UID:0001IH] should therefore document source routing and byte coverage, but it should not emit C++ and should not carry [UID:0000O1] as a canonical owner/emitter. Exact child/source pages should carry reconstructable source where appropriate; the scalar deleting destructor tail stays no-code.

## Evidence Checked

Project documentation read:

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B011/goal.md`
- `.codex/AGENTS.md`
- `by-project-structure/by-structure.md`
- `by-project-structure/inference_research.md`
- `by-project-structure/proposed-source-tree.md`
- Target [UID:0001IH] `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md`
- Child pages [UID:0002RI], [UID:0002RJ], [UID:0002RK], [UID:0002RL]
- Embedded exact children [UID:0001II] and [UID:0001IJ]
- Class/file support docs: `SpellInventoryPane`, `NewSpellInventoryPane`, `SpellInventoryPane2`, `ScrollSpellInventoryPane`, `SpellInputPanes`, `TargetSelectionInputPanes`, `UserPane`, `LivingObjectPaneUseCommandSlotDispatch`, `g_pCollectionData`, `QueueAndSendPacket`, `SendTargetedActionPacket`
- Vtable/read-only support: [UID:00026J] `0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData`, ScrollSpellInventoryPane vtable/layout pages, and current by-memory coverage rows.

IDA MCP check:

- Tried `http://127.0.0.1:13337/mcp` with a short `tools/list` request. It timed out, so no current-session IDA MCP commands were available.
- Used read-only PE/Capstone fallback against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` instead. The binary is 2679296 bytes, image base `0x00400000`, with `.text` at `0x00401000-0x0060c600`.

Local PE/Capstone findings:

- Relative refs to selected starts:
  - `0x0057c2d0`: none.
  - `0x0057cf70`: one direct call at `0x004b84cb`.
  - `0x0057ea60`: none.
  - `0x0057f030`: one call at `0x0057eeef` from the `SpellInventoryPane2` mouse path.
  - `0x0057f290`: no start ref.
  - `0x0057f5d0`: refs only from adjustor thunks at `0x0057f591` and `0x0057f59c`.
  - `0x0057f640`: refs only from adjustor thunks at `0x0057f597`, `0x0057f5a7`, and `0x0057f5b2`.
  - `0x0057f6a0`: refs only from adjustor thunks at `0x0057f5bd` and `0x0057f5c8`.
  - `0x0055f450`: one call at `0x0057d013`.
  - `0x0055f5f0`: one call at `0x0057d028`.
- Absolute VA literals:
  - No literal refs for `0x0057c2d0`, `0x0057cf70`, `0x0057ea60`, `0x0057f030`, or `0x0057f290`.
  - Scalar destructor literals appear only in vtables: `0x0057f5d0` at `0x0062d068`, `0x0057f640` at `0x0062d0f4`, and `0x0057f6a0` at `0x0062cfdc`.
- Raw constructor/setup evidence:
  - `0x0057c2d0` calls `0x00545090`, installs vtables `0x0062cfdc`, `0x0062d02c`, `0x0062d05c`, clears `+0xf8/+0xfa`, allocates a `0x15c` effect/interface object, constructs it through `0x004e97b0`, and stores it at `this+0xfc`.
  - `0x0057cf70` calls `0x00545090`, installs vtables `0x0062d068`, `0x0062d0b8`, `0x0062d0e8`, initializes state through `+0x144`, allocates `0x110`, calls `0x0055f450`, stores the scrollbar at `this+0x100`, then activates it via `0x0055f5f0`.
  - `0x0057ea60-0x0057ea9f` is real raw constructor/setup code: call `0x00545090`, store vtables `0x0062d0f4`, `0x0062d144`, `0x0062d174`, clear `+0xf8/+0xfa`, return. `0x0057ea57-0x0057ea60` is nine `0xcc` bytes, so the raw constructor start is not padding.
- Jump-table evidence:
  - `0x0057cc42-0x0057ccd0` is not padding. It begins `66 90`, then eight dword targets: `0x0057ca2c`, `0x0057ca60`, `0x0057cae8`, `0x0057cb1c`, `0x0057cb50`, `0x0057cb98`, `0x0057cbc5`, `0x0057cbf2`, followed by alignment and the next helper at `0x0057ccd0`.
  - `0x0057f26c-0x0057f28c` is the `SpellInventoryPane2` dispatcher jump table with eight dwords: `0x0057f0ab`, `0x0057f0df`, `0x0057f113`, `0x0057f147`, `0x0057f17b`, `0x0057f1c3`, `0x0057f1f0`, `0x0057f21d`. `0x0057f28c-0x0057f290` is `0xcc` alignment.
- Scalar deleting destructor proof:
  - `0x0057f58b-0x0057f5cd` is six tiny adjustor thunks. Each subtracts `0xa0` or `0xa4` from `ecx` and tail-jumps to one of the scalar deleting destructor wrappers.
  - The scalar wrappers have vtable/thunk refs and delete-flag behavior, not ordinary source callsites. `0x0057f5d0` and `0x0057f640` call base cleanup/free/guard helpers; `0x0057f6a0` additionally cleans legacy `this+0xfc` through `0x00544690`.
  - Padding between wrappers is exact: `0x0057f5cd-0x0057f5d0`, `0x0057f637-0x0057f640`, `0x0057f695-0x0057f6a0`, and `0x0057f742-0x0057f750` are `0xcc`.

## Heuristic Findings And Resolutions

### 1. Parent Source Placement

The current target metadata makes [UID:0001IH] reconstructable and assigns it to [UID:0000O1] `SpellInventoryPane`. That overstates a physical neighborhood as one source owner.

The target is a coverage/index page over multiple source routes:

- Legacy `SpellInventoryPane` source.
- New `NewSpellInventoryPane` source.
- Alternate `SpellInventoryPane2` source.
- Shared target/input state helpers physically embedded in the range.
- Compiler-generated scalar deleting destructors and this-adjusting thunks.

This matches the project rule for mixed physical aggregates: keep exact children reconstructable as appropriate, but make the parent non-emitting when no single generated source file should receive the whole range.

### 2. Class/File Split

Best-supported source split:

```text
NexusTK/ui/inventory/SpellInventoryPane.cpp
NexusTK/ui/inventory/NewSpellInventoryPane.cpp
NexusTK/ui/inventory/ScrollSpellInventoryPane.cpp
NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp
NexusTK/ui/dialogs/SpellInputPanes.cpp
```

High-probability route:

- `SpellInventoryPane.cpp` owns the legacy `SpellInventoryPane` and likely `SpellInventoryPane2`.
- `NewSpellInventoryPane.cpp` owns `NewSpellInventoryPane`.
- `ScrollSpellInventoryPane.cpp` remains a private companion for now. The only observed constructor caller is `NewSpellInventoryPane::NewSpellInventoryPane` at `0x0057d013`, so a future fold into `NewSpellInventoryPane.cpp` is plausible but not proven.
- The two state setter children in the physical range are not spell-inventory source:
  - [UID:0001II] is `SpellInputPaneState::SetInputModeFlag`, owned by [UID:0000DM] / `TargetSelectionInputPanes`.
  - [UID:0001IJ] is `ItemWhoInputPaneState::SetInputModeFlag`, owned by [UID:00006Y] / `TargetSelectionInputPanes`.
- [UID:0002RL] is no-code compiler destructor wrapper/thunk inventory.

### 3. Raw Constructor/Setup Bodies

Lack of IDA function promotion must not be treated as a blocker by itself.

- `0x0057ea60-0x0057ea9f` is class-owned source lowering for `SpellInventoryPane2::SpellInventoryPane2()`, despite no IDA function object and no start xref.
- `0x0057f290-0x0057f485` is source-authored local helper code for `SpellInventoryPane2`, despite no modeled function starts for the internal helpers.
- These raw bodies are source-bearing within [UID:0002RK], not compiler glue. They should remain covered by the exact child page and source-routed to [UID:0000DO].

### 4. Constructor Reachability

Current route evidence:

- `SpellInventoryPane` legacy constructor `0x0057c2d0`: no direct rel32 call and no absolute VA literal in the PE scan. Existing docs also record no IDA xrefs/pointer-pattern hits. This is a liveness/source-placement caveat, but the vtable stores, destructor/vtable refs, method family, and dispatcher behavior still support a real retained legacy class body.
- `NewSpellInventoryPane` constructor `0x0057cf70`: one direct caller at `0x004b84cb` in the `GeneralPurposePanel` construction path. This is live and source-routed.
- `SpellInventoryPane2` constructor `0x0057ea60`: no direct rel32 call and no absolute VA literal. It remains retained/source-authored class code because the raw constructor body, vtable store/ref pattern, reset helper, paint/input methods, and scalar wrapper all match the alternate pane.
- Scalar destructor wrappers: no ordinary modeled callers beyond vtable/thunk refs. They should not be used as evidence for handwritten source bodies.

### 5. Spell Dispatch Helper Semantics

The legacy dispatcher `0x0057c9b0`, new dispatcher `0x0057e2d0`, and alternate dispatcher `0x0057f030` all read local-player spell records through `dword_67A748`/`g_pCollectionData` as a local-player/UserPane typed view, not through a generated `SpellManager` or `g_pSpellMan`.

Resolved helper roles:

| Address | Best current role/name |
| --- | --- |
| `0x0067a748` / `dword_67A748` | local-player/UserPane state pointer, currently documented as `g_pCollectionData` with spell typed views |
| `+0x13a6ec + slot*0x148` | spell/command slot record base |
| `+0x13a794 + slot*0x148` | spell prompt/name text used by spell input panes |
| `+0x13a82c + slot*0x148` | legacy/alternate dispatcher spell-type field neighborhood; current docs use this for dispatcher reads |
| `+0x13a834 + slot*0x148` | learned/active flag used by list builders and `0x005a4310` |
| `+0x13ead4` | spell-slot active/guard/dirty flag used by slot-change/dispatch paths |
| `0x005adf40` | `SpellStringInputPane` constructor |
| `0x005ae2a0` | `SpellWhoInputPane` constructor / target prompt, currently stronger under `TargetSelectionInputPanes` |
| `0x005b0780` | `SpellFourArgsInputPane` constructor |
| `0x005b0ac0` | `SpellThreeArgsInputPane` constructor |
| `0x005b0da0` | `SpellTwoArgsInputPane` constructor |
| `0x005b1030` | `SpellOneArgInputPane` constructor |
| `0x005b1280` | `SpellSlotInputPane` constructor |
| `0x005af4f0` | `SendTargetedActionPacket`, opcode `0x0f` target/action helper |
| `0x00574bb0` | `Socket::QueueAndSendPacket` wrapper |
| `0x005a4530` | `LivingObjectPane::UseCommandSlot` / command-spell slot dispatch helper |
| `0x005a4310` | `UserPane::BuildSpellSlotLabelString` / `BuildAvailableSpellSlotRangeText` |
| `0x005a4090` | best current old-doc direction is `SlotIndexToHotkeyLetter`; no active exact page found in this pass |
| `0x0069b3fc` / `dword_69B3FC` | `SurfaceRenderCallbackTable` slot 7, fill/invalidation/presentation callback; not spell-inventory-owned |

Observed dispatcher branch order in the PE disassembly:

- String prompt.
- Target prompt or targeted direct-send path.
- Four-argument prompt.
- Three-argument prompt.
- Direct two-byte opcode `0x0f` cast packet.
- Two-argument prompt.
- One-argument prompt.
- Spell-slot prompt.

Exact original enum names for these spell-type values remain unresolved, but the helper routes and source-family placement are resolved enough to reject raw `sub_` names in support docs.

### 6. Field/Member Names

Best current source-facing field directions:

| Class | Offset | Best direction |
| --- | ---: | --- |
| `SpellInventoryPane` | `+0xf8` | `m_pageIndex` / `m_currentPage` |
| `SpellInventoryPane` | `+0xfa` | `m_spellInputActive` / pending input flag |
| `SpellInventoryPane` | `+0xfc` | owned `InterfaceEfx` / spell effect interface pointer |
| `NewSpellInventoryPane` | `+0xf8` | current row / scroll current position |
| `NewSpellInventoryPane` | `+0xf9` | small state byte, exact final name not resolved |
| `NewSpellInventoryPane` | `+0xfa` | pending input flag |
| `NewSpellInventoryPane` | `+0x100` | `m_scrollPane` / child `ScrollSpellInventoryPane *` |
| `NewSpellInventoryPane` | `+0x104` | visible spell-slot id array |
| `NewSpellInventoryPane` | `+0x139` | hover/current slot state, exact final name unresolved |
| `NewSpellInventoryPane` | `+0x13c` | stored state dword, exact final role unresolved |
| `NewSpellInventoryPane` | `+0x140` | layout/dirty state |
| `NewSpellInventoryPane` | `+0x144` | expanded/collapsed flag |
| `SpellInventoryPane2` | `+0xf8` | page/current page index |
| `SpellInventoryPane2` | `+0xfa` | pending input flag |

Use descriptive names in docs, not raw `dword` or `sub_` names. Do not promote these to final declarations until the exact class layouts are reconciled.

### 7. Scalar Deleting Destructor Policy

[UID:0002RL] is already correctly documented as non-reconstructable no-code metadata:

```text
COMPLETION:86
CONFIDENCE:88
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

Keep that policy. The six `0xb`-byte thunks are compiler ABI adjustors. The three scalar deleting destructor wrappers are vtable delete wrappers with delete-flag handling and optional storage free. They are regenerated from class destructor declarations/layout, not handwritten source items.

Support docs should not describe `0x0057f5d0`, `0x0057f640`, or `0x0057f6a0` as formal source bodies. If ordinary destructor behavior needs future source modeling, it should happen through exact class destructor/direct-cleanup pages, not through the [UID:0002RL] aggregate.

### 8. First-Draft C++ Readiness

For [UID:0001IH] itself: no formal C++ should be emitted.

Exact no-code proof:

- The target crosses multiple source owners and one no-owner compiler-glue tail.
- It contains exact embedded children [UID:0001II] and [UID:0001IJ] that are not spell-inventory source even though they lie inside the physical span.
- It contains [UID:0002RL], which is non-reconstructable compiler-generated destructor dispatch/delete glue.
- It contains retained/no-route raw source bodies that need child/class routing, not parent C++.
- Formal C++ on the parent would duplicate or misroute child source bodies and compiler glue.

For source children:

- [UID:0002RI], [UID:0002RJ], and [UID:0002RK] are source-authored and clear the 85/85 research gate, but each is a broad method/helper island. Keep their formal C++ blank until method-level pages or class-level `[[CHILDREN]]` declarations are selected by supervisor. Do not cite stale `95/95` or `90/90+` gates as the reason.
- `SpellInventoryPane2::SpellInventoryPane2()` at `0x0057ea60` is first-draft-ready as a constructor-shaped body if an exact method page is later created.
- The dispatchers are source-authored and source-shaped, but final spell-type enum names and helper signatures remain inferred. They are not suitable for parent aggregate C++.

## Recommended Exact Target Doc Changes

For `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md`:

1. Replace metadata with:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. Change Status to:

```text
- Disposition: reviewed non-emitting split/index over spell inventory executable code, embedded target/input state helpers, and compiler destructor glue.
- Entity kind: mixed physical executable aggregate / coverage index.
- Source handling: no single canonical owner. Exact children carry source routing; scalar destructor tail stays no-code.
- C++ reconstruction: intentionally blank. The page crosses multiple source owners and compiler-generated destructor wrappers.
```

3. Replace the existing `Likely source module: [UID:0000O1]` statement with a source-route table like the one in this report.

4. Add [UID:0001II] and [UID:0001IJ] to the covered-range table as exact embedded shared input-state helpers so the page does not imply those bytes are `SpellInventoryPane` or `NewSpellInventoryPane` methods.

5. Replace stale "below source-ready 95%" wording with current 85/85 gate analysis:

```text
The exact source children clear or approach the current 85/85 research gate, but this parent remains non-emitting because it is a mixed split/index. Formal C++ belongs on exact source children or class pages after field/helper names are settled, not on this aggregate.
```

6. In `Ownership Decision`, state:

```text
This physical island belongs to the spell inventory UI neighborhood, but [UID:0001IH] itself has no canonical source owner. The legacy and alternate pane children route through SpellInventoryPane/SpellInventoryPane2, the new-pane child routes through NewSpellInventoryPane, the state setter children route through TargetSelectionInputPanes, and the scalar destructor tail is compiler-generated no-code.
```

7. Add the current PE evidence:

- No direct route to `0x0057c2d0` or `0x0057ea60`.
- One direct constructor route to `0x0057cf70` from `0x004b84cb`.
- Jump tables at `0x0057cc44` and `0x0057f26c`.
- Raw `SpellInventoryPane2` constructor at `0x0057ea60`.
- Destructor wrapper refs only through vtables/thunks.

## Recommended Support Doc Changes

Support docs to update if supervisor accepts implementation:

- `by-file/SpellInventoryPane.md`
  - State that [UID:0001IH] is a physical split/index and no longer an emitting source page.
  - Keep `SpellInventoryPane.cpp` as the source family for legacy `SpellInventoryPane` and likely `SpellInventoryPane2`.
  - Keep `NewSpellInventoryPane.cpp` separate, not folded into [UID:0000O1] because of parent aggregate adjacency.
  - Mention [UID:0002RL] scalar deleting destructor wrappers are no-code compiler output.
  - Preserve constructor liveness caveats for `0x0057c2d0` and `0x0057ea60`.
- `by-file/NewSpellInventoryPane.md`
  - State that the new-pane source route is through [UID:0000LU]/[UID:00009A]/[UID:0002RJ], not through the [UID:0001IH] parent aggregate.
  - Keep `ScrollSpellInventoryPane` as private companion/provisional separate file; one-callsite evidence allows future fold but does not prove one.
- `by-class/SpellInventoryPane.md`
  - Keep legacy constructor/destructor/method evidence.
  - Reword scalar deleting destructor row as compiler wrapper/no formal C++; ordinary source cleanup is represented by the non-scalar destructor `0x0057c3a0-0x0057c400`.
  - Reject generated `SpellManager`/`g_pSpellMan`; use local-player/UserPane typed spell-state view.
- `by-class/NewSpellInventoryPane.md`
  - Replace stale `95+ source-emission gate` wording with current 85/85 eligibility plus target-specific blockers: broad method island, final fields, final spell-type names, and child/source split.
  - State [UID:0002RJ] is source-authored but broad; formal C++ should be method-level or class-level child routed, not through [UID:0001IH].
- `by-class/SpellInventoryPane2.md`
  - State the `0x0057ea60-0x0057ea9f` raw body is constructor/setup source lowering, not a blocker.
  - Reword `~SpellInventoryPane2` / `0x0057f640` as scalar deleting wrapper compiler glue unless/until an ordinary destructor body is split.
- [UID:0002RI] `SpellInventoryPaneLegacyCoreAndHelpers`
  - Remove the active `90/90+` code-entry wording.
  - Add that [UID:0001II] is an overlapping exact state-helper child with its own owner.
  - Keep C++ blank because this is a broad method/helper island with unresolved final field/helper names, not because of a stale numeric gate.
- [UID:0002RJ] `NewSpellInventoryPaneCoreAndHelpers`
  - Add that [UID:0001IJ] is an overlapping exact state-helper child with its own owner.
  - Keep C++ blank for broad-island/source-split reasons.
- [UID:0002RK] `SpellInventoryPane2CoreAndHelpers`
  - Replace stale `95/95` wording with current gate analysis.
  - Keep raw helper bodies inside this child until exact method pages are created.
- [UID:0002RL] `SpellInventoryScalarDeletingDestructors`
  - Metadata/text are already directionally correct. Ensure support docs and coverage match `not_reconstructable`, no owner, no emitter.
- [UID:0001II] and [UID:0001IJ]
  - Replace stale `90/90+` code-entry wording with current 85/85 gate plus final-name/source-shape blockers.
  - Keep exact ownership under the state classes / TargetSelectionInputPanes.
- [UID:00026J] `SpellInventoryMacroReadOnlyData`
  - Add that [UID:0001IH] is a non-emitting executable split/index, while vtables in this `.rdata` range regenerate from exact class declarations. The spell inventory vtable run may eventually deserve exact vtable-data children like ScrollSpellInventoryPane has.

## Open Questions And Current Best Directions

| Question | Resolution / best direction |
| --- | --- |
| Should [UID:0001IH] stay source-bearing? | No. It is a mixed physical split/index; mark non-reconstructable/no owner/no emitter. |
| Does no IDA function at `0x0057ea60` block source reconstruction? | No. Raw bytes prove a constructor/setup body. It is source-authored child code under [UID:0002RK]/[UID:0000DO]. |
| Are `0x0057f5d0`, `0x0057f640`, `0x0057f6a0` ordinary source destructor bodies? | No for this aggregate. They are scalar deleting destructor wrappers reached by vtables/thunks. Source declarations/class cleanup should be modeled elsewhere if needed. |
| Is `dword_67A748` a spell manager? | No. Current docs and this pass support a local-player/UserPane state pointer with spell typed views. |
| Exact final spell-type enum names? | Not proven. Helper routes are resolved; enum names should remain descriptive until a broader spell-type/packet pass. |
| Exact original `0x005a4090` name? | Current old-doc best direction is `SlotIndexToHotkeyLetter`. No active exact page found in this pass; use descriptive naming only. |
| Exact original `0x005a4310` name? | Best direction is `UserPane::BuildSpellSlotLabelString` / `BuildAvailableSpellSlotRangeText`; reject current-spell-name/getter interpretations. |
| `ScrollSpellInventoryPane` separate source or folded into `NewSpellInventoryPane.cpp`? | Separate provisional file remains acceptable; sole constructor caller keeps it private to `NewSpellInventoryPane` and prevents generic scrollbar ownership. |

## Score Recommendation

Target [UID:0001IH]:

| Field | Current | Recommended | Rationale |
| --- | ---: | ---: | --- |
| Completion | 85 | 87 | Target/source routing, raw constructor body, jump tables, state-helper overlaps, scalar no-code policy, coverage repair, and support-doc needs are now resolved at the parent level. |
| Confidence | 86 | 90 | Raw PE/Capstone evidence and existing live IDA-backed docs agree on boundaries, refs, vtables, and no-code/scalar policy. IDA MCP was unavailable in this session, so do not push higher than 90. |
| Owner | `0000O1` | `NONE` | No single source owner for the aggregate. |
| Reconstructable | TRUE | FALSE | Mixed split/index plus compiler destructor glue. |
| Emitters | `0000O1` | blank | Parent must not emit aggregate C++. |

## Exact Pending Coverage Rows

Do not edit `by-memory/-coverage-report.md` directly. If the supervisor accepts this report, replace the stale target subtree rows with:

```text
    - [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md) 0x0057c2d0-0x0057f742 | mixed executable split/index | SpellInventoryPanes : not_reconstructable : 87% : very strong : B011 source-quality recheck classifies this as a non-emitting physical index over legacy SpellInventoryPane source, NewSpellInventoryPane source, SpellInventoryPane2 source, shared input-state setter children, and compiler destructor glue; PE/Capstone fallback confirms no call/literal route to 0x0057c2d0 or 0x0057ea60, one NewSpellInventoryPane constructor caller at 0x004b84cb, raw SpellInventoryPane2 constructor bytes at 0x0057ea60, jump tables at 0x0057cc44 and 0x0057f26c, and scalar destructor refs only through vtables/thunks, so formal C++ and owner/emitter stay blank on the parent.
        - [UID:0002RI][0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers](by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md) 0x0057c2d0-0x0057cf6b | method/helper-group | SpellInventoryPaneLegacyCoreAndHelpers : reconstructable : 85% : strong : Legacy spell inventory constructor/destructor/reset/draw/key/mouse/message helpers, dispatcher, row geometry helpers, and 0x0057cc44 jump-table evidence documented; broad formal C++ remains blank pending method-level split, final field/helper names, and explicit overlap with exact state-helper child [UID:0001II].
        - [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md) 0x0057c430-0x0057c43f | method | SpellInputPaneStateSetFlag : reconstructable : 85% : strong : Exact 16-byte shared spell-input state setter for this+0xfa, owned by SpellInputPaneState/TargetSelectionInputPanes rather than the spell-inventory aggregate; caller fanout, byte body, sibling setter relationship, and blank C++ pending final names documented.
        - [UID:0002RJ][0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers](by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md) 0x0057cf70-0x0057ea57 | method/helper-group | NewSpellInventoryPaneCoreAndHelpers : reconstructable : 85% : strong : NewSpellInventoryPane constructor/layout/list/paint/input/cast/toggle helper island with one constructor caller at 0x004b84cb, child ScrollSpellInventoryPane allocation/activation, learned-spell list rebuild, cast dispatcher fanout, expanded-mode state, embedded helper spans, and formal C++ blank pending method-level source split and final field/spell-type names.
        - [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md) 0x0057d0a0-0x0057d0af | method | ItemWhoInputPaneStateSetFlag : reconstructable : 85% : strong : Exact 16-byte shared item-target state setter for this+0xfa, owned by ItemWhoInputPaneState/TargetSelectionInputPanes rather than NewSpellInventoryPane; caller fanout, byte body, sibling setter relationship, and blank C++ pending final names documented.
        - [UID:0002RK][0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md) 0x0057ea60-0x0057f58b | method/helper-group | SpellInventoryPane2CoreAndHelpers : reconstructable : 86% : strong : Alternate SpellInventoryPane2 source island with raw constructor/setup at 0x0057ea60, vtable stores 0x0062d0f4/0x0062d144/0x0062d174, reset/paint/key/mouse/message/dispatcher helpers, 0x0057f26c jump table, raw local helpers at 0x0057f290-0x0057f485, and formal C++ blank pending final method split and field/helper names.
        - [UID:0002RL][0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors](by-memory/0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors.md) 0x0057f58b-0x0057f742 | destructor/thunk-group | SpellInventoryScalarDeletingDestructors : not_reconstructable : 86% : strong : Non-emitting compiler destructor/thunk inventory: six this-adjustor thunks subtract 0xa0/0xa4 and tail-jump to scalar deleting destructor wrappers at 0x0057f5d0, 0x0057f640, and 0x0057f6a0; vtable/thunk refs, delete-flag/free/base-cleanup behavior, padding, and no formal C++ policy documented.
```

## Validator Needs After Implementation

Run from `source-3/project-documentation` after applying accepted doc changes:

> Executable block R001 was removed from this report and preserved verbatim in [0001IH-SpellInventoryPanes-source-quality-removed.md](0001IH-SpellInventoryPanes-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Minimum implementation validator set if only the target metadata/body is changed and coverage rows are not yet applied:

> Executable block R002 was removed from this report and preserved verbatim in [0001IH-SpellInventoryPanes-source-quality-removed.md](0001IH-SpellInventoryPanes-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run autogen because [UID:0001IH] changes from emitting/reconstructable to non-reconstructable/no-emitter. After refresh, generated memory coverage should report [UID:0001IH] as `not_reconstructable` with owner `NONE`; [UID:0002RL] should also remain `not_reconstructable`.

## IDA Rename/Type/Comment Recommendations

If IDA is available later, recommended non-destructive naming/comments:

| Address | Recommendation | Confidence |
| --- | --- | --- |
| `0x0057c2d0` | `SpellInventoryPane_ctor_legacy` or `SpellInventoryPane::SpellInventoryPane` | high for class, medium for liveness |
| `0x0057c9b0` | `SpellInventoryPane::ActivateSpellSlot` / `DispatchSpellSlot` | high behavior, medium exact spelling |
| `0x0057cf70` | `NewSpellInventoryPane::NewSpellInventoryPane` | high |
| `0x0057d200` | `NewSpellInventoryPane::RebuildSpellList` | high |
| `0x0057e2d0` | `NewSpellInventoryPane::CastSpell` / `ActivateSpellSlot` | high behavior, medium exact spelling |
| `0x0057e9d0` | `NewSpellInventoryPane::ToggleExpandedMode` | high |
| `0x0057ea60` | create function `SpellInventoryPane2::SpellInventoryPane2` if IDA function creation is acceptable | high for body, medium liveness |
| `0x0057f030` | `SpellInventoryPane2::ActivateSpellSlot` | high behavior, medium exact spelling |
| `0x0057f290` | local raw direct-cast packet helper; keep class-local until exact split | medium |
| `0x0057f58b-0x0057f5cd` | comment as compiler this-adjustor thunks | very high |
| `0x0057f5d0`, `0x0057f640`, `0x0057f6a0` | comment as MSVC scalar deleting destructor wrappers; no handwritten source body | very high |
| `0x005a4090` | `SlotIndexToHotkeyLetter` pending exact page | medium |
| `0x005a4310` | `UserPane::BuildSpellSlotLabelString` / `BuildAvailableSpellSlotRangeText` | high behavior, medium spelling |
| `0x0067a748` | local-player/UserPane state pointer; avoid `SpellManager`/`g_pSpellMan` | high |
| `0x0069b3fc` | `SurfaceRenderCallbackTable` slot 7, fill/invalidation callback | high |

## Implementation Readiness

Ready for supervisor implementation callback.

Do not write formal C++ to [UID:0001IH]. The correct implementation is a metadata/source-routing correction plus support-doc wording/coverage repair. Exact source methods can be reconstructed later through class/method children, especially the raw `SpellInventoryPane2` constructor and individual dispatcher methods, once helper names and enum names are accepted.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/0001IH-SpellInventoryPanes-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"0001IH"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001IH-SpellInventoryPanes-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/0001IH-SpellInventoryPanes-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001IH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
