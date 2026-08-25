** TARGET-REPORT-UID:0004EL **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0004EL PrettyButtonControlPane2ScalarDeletingDestructor Source-Quality Report


## Finalized Report / Current Recommendation

- Implemented target: [UID:0004EL] `by-memory/0x0054bbc0-0x0054bc3d.PrettyButtonControlPane2ScalarDeletingDestructor.md` is now compiler-only deleting-destructor output at `92/94`, owner `0000AS`, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal, unchanged `Nested:0`, exact range/padding, and complete no-code proof.
- Implemented source cause: [UID:000038] `ControlPane` R7 at position `10`, [UID:00001E] `ButtonControlPane` R8 at position `10`, and [UID:0000AS] `PrettyButtonControlPane2` R2 at position `20` now supply the complete `0x108`, `0x10c`, and `0x12c` declarations. UID0004EB R6 remains the sole human class2 destructor body.
- Implemented source repairs: UID0004EA uses exact R3 with canonical `RectBounds`, normalized `m_visualStateFrameActive`, and protected inherited state assignments in observed body order; UID0004EF uses exact R4; UID0002UX remains R5 generated-binary data at `90/94`; parent/file/base support is synchronized without loss.
- Validation state: all 13 changed ordinary pages passed scoped validation; B003 final waited command `000000013727` refreshed all three generated C++ outputs to one common epoch and passed the accepted structure/count/no-marker assertions. Later read-only external command `000000013759` refreshed only the generated epoch/header while preserving those semantic assertions. R1-R8 have byte-for-byte destination parity.
- Manual coverage handoff: B003 supplied the exact supervisor-owned replacement/insertion text from callback-time read-only snapshots and did not edit coverage. This artifact does not assert whether those rows are later stale, absent, applied, replaced, or otherwise current.
- Confidence: very strong for the target range, bytes, ABI, flag matrix, teardown sequence, vtable/thunk reachability, `ControlPane` size `0x108`, `ButtonControlPane` size `0x10c`, class2 size `0x12c`, source/compiler decomposition, and no-code decision; strong for final source-facing access and descriptive member spellings.
- Review handoff: the accepted implementation callback is complete with no blocked claim. The following literal marker records B003's callback-return state at evidence time only; it is not current lifecycle authority and does not override later validator-owned headers, history, registry, audit, coverage, execution, revalidation, invalidation, count, path, move, or archive state.

Callback-return marker:
READY_FOR_SUPERVISOR_GATE2_REVIEW

## Supporting Research

- Canonical assignment read: `tools/leaser/Agents/Agent-B003/goal.md`.
- Workflow/template read:
  - `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/SKILL.md`
  - `references/b-agent-research-and-implementation-workflow.md`
  - `references/b-agent-report-template.md`
  - `references/score-blocker-audit-standard.md`
  - relevant ownership, reconstructable, emitter, covered-by, compiler/container, and C++ rules in `by-structure.md`.
- Current target and direct support read:
  - [UID:0004EL] target.
  - [UID:0004EB] ordinary class2 destructor.
  - [UID:0004EA], [UID:0004EC], [UID:0004ED], [UID:0004EE], [UID:0004EF], and [UID:0004EG] source children.
  - [UID:0004EH] and [UID:0004EI] compiler adjustor thunks.
  - [UID:0000AS] class page.
  - [UID:0000MP] file page.
  - [UID:0001F9] non-emitting executable split/index.
  - [UID:0002UX] three-view vtable/RTTI page.
  - [UID:00001E] `ButtonControlPane`.
  - [UID:000038] `ControlPane`.
  - [UID:0000A2] `Pane`.
  - [UID:0002PB] exact `ControlPane` constructor.
  - [UID:0003J8]/[UID:0003J9] exact `ControlPane` vtable data/type support.
  - [UID:000118] button/choice executable index.
  - [UID:00011Y] button/choice destructor/thunk index.
  - [UID:000252] control-family read-only/vtable index.
  - [UID:0001W4]/[UID:0001WS] one-pointer `mystr::StringBase` layout/type evidence.
  - [UID:0001WQ]/[UID:00005L] `FunctionObject0` declaration and scalar-wrapper policy.
  - [UID:000197] MemoryMan-backed global `operator delete`.
- Generated state read, never edited:
  - `auto-generated/NexusTK/ui/core/ControlPane.cpp`
  - `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp`
  - `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp`
  - `auto-generated/-ag-research-tracker.md`
  - `auto-generated/-ag-memory-coverage.md`
  - `auto-generated/-ag-coverage-report-by-memory.md`.
- Callback-time manual coverage snapshots read, never edited:
  - `by-memory/-coverage-report.md`
  - `by-class/-coverage-report.md`
  - `by-file/-coverage-report.md`.
- Relevant executed reports opened as leads and independently revalidated against current docs/MCP:
  - `executed-b-agent-research/B011/0001F9-PrettyButtonControls-source-quality.md`
  - `executed-b-agent-research/B004/0004EB-PrettyButtonControlPane2DestructorBody-source-quality.md`
  - `executed-b-agent-research/B006/0002UX-PrettyButtonControlPane2VtableData-source-quality.md`
  - `executed-b-agent-research/B003/0004EA-PrettyButtonControlPane2Constructor-source-quality.md`
  - `executed-b-agent-research/B011/0004EC-PrettyButtonControlPane2StateByteVirtualForwarder-source-quality.md`
  - `executed-b-agent-research/B013/0004ED-PrettyButtonControlPane2SetCallback-source-quality.md`
  - `executed-b-agent-research/B004/0004EE-PrettyButtonControlPane2SetVisualState-source-quality.md`
  - `executed-b-agent-research/B005/0004EF-PrettyButtonControlPane2OnPaint-source-quality.md`
  - `executed-b-agent-research/B006/0004EG-PrettyButtonControlPane2OnClick-source-quality.md`.
- At the historical report-search checkpoint, no prior dedicated UID0004EL report existed. Exact searches found only family/support mentions in executed reports and zero prior target matches in `archived`, `Older-Research`, `SpecialReports`, or active B-agent research roots.
- Historical failed-artifact note: exact SHA256 `16E865812ECD09DBE97F7825DF0671B786A3CC3CED267872B1A69FB563A6C414` failed Gate 1 because it left the `ButtonControlPane`/`ControlPane` declaration and inherited-access contract as future work. This additive repair preserves all accepted target research and closes that associated dependency now.
- Historical Wave2/Wave3/simroot labels were treated as search provenance only. No stale Wave workflow or generated grade was used as evidence.

## Target

- Target UID: `0004EL`.
- Target path: `by-memory/0x0054bbc0-0x0054bc3d.PrettyButtonControlPane2ScalarDeletingDestructor.md`.
- Exact half-open range: `[0x0054bbc0,0x0054bc3d)`.
- B003 callback direct semantic owner result: [UID:0000AS] `PrettyButtonControlPane2`.
- B003 callback source route result: [UID:0000AS] -> [UID:0000MP] -> `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.
- B003 callback score/state result: target `92/94`; class `92/93`; file `90/92`; parent split/index unchanged `88/90`; vtable page `90/94`; ordinary destructor unchanged `88/91`.
- Historical queue context: the report-only evidence snapshot showed this target under by-memory Not-Covered Files - Reconstructable at `86/90` with a comment emitter. That pre-callback queue state is superseded by the implemented ordinary metadata and is retained only as assignment provenance.

## Current Target State

- Implemented metadata:
  - `COMPLETION:92`
  - `CONFIDENCE:94`
  - `CANONICAL_OWNER:0000AS`
  - `RECONSTRUCTABLE:FALSE`
  - blank `EMITTER_UIDS`
  - blank `EMITTER_POSITION_OPTIONAL`
  - `Nested:0`
  - exact R1 blank formal.
- Implemented Item Summary and sections record exact 125-byte size, SHA256, predecessor/successor padding, x86 ABI, 39 instructions, 7 blocks, complexity 3, complete bit1/bit4 matrix, ordinary-destructor parity, vtable/thunk-only reachability, source/compiler decomposition, rejected alternatives, history, and score rationale.
- Implemented base/class closure:
  - `+0xff` is inherited `ControlPane::m_controlFlags`;
  - `+0x100` is inherited `ControlPane::m_reservedControlState`;
  - `ControlPane` initializes them to `0/0`;
  - `ButtonControlPane` overwrites them to `1/1`;
  - Pretty constructors then overwrite them to the constructor argument and `0`.
- Exact R7/R8/R2 declarations now expose that state legally, close the `0x108`/`0x10c`/`0x12c` layouts, and place class definitions before child bodies.
- UID0004EA exact R3 uses `RectBounds`, `m_visualStateFrameActive`, and body assignments `m_controlFlags -> m_callback -> m_reservedControlState`; UID0004EF exact R4 uses the same frame-active name.
- B003 waited generated epoch was validator command `000000013727`, refreshed `2026-07-16T09:50:07-04:00`. A later evidence-time read-only external epoch was command `000000013759`, refreshed `2026-07-16T10:03:01-04:00`:
  - `ControlPane.cpp` SHA256 `B04068D588FF338513F61DDE5EA06A61B1B3CE4309DDE9F67B1806EC32CE98E1`, 2,898 bytes, 100 lines;
  - `ButtonControlPane.cpp` SHA256 `6EA48456FC42C4C6259CFB522618EA1C1B0B17DC8A89D2BA7BC8EE8082F9154B`, 9,985 bytes, 301 lines;
  - `PrettyButtonControlPane.cpp` SHA256 `F78FC98ACDFC4A3C7D6B46EC4F2399C21C332A5DF3A6A46CECB282CD328BF9A0`, 9,677 bytes, 270 lines.
- Generated semantic result:
  - all three accepted class declarations close before routed definitions;
  - UID000038, UID00001E, and UID0000AS class-marker symptoms are absent;
  - class2 has exactly seven qualified definitions, one per accepted method;
  - UID0004EL target/title/address/comment count is zero;
  - UID0002UX R5 marker count is one;
  - no raw vtable/RTTI arrays, naked/assembly bodies, absolute VA source, decompiler `sub_` names, raw this-offset casts, or guard calls are emitted in the accepted three-file scope.
- B003 performed the ordinary implementation and scoped/generated validation listed below. B003 performed no report execution, report probe/count/revalidation, move, archive, or lifecycle command; any later external lifecycle or coverage state is authoritative only in validator/supervisor-owned records and current files.

## Executive Recommendation

- Implemented exactly: UID0004EL is `92/94`, false/blank, owner `0000AS`; a covered-by/comment emitter is rejected.
- Implemented exactly: ControlPane R7 (`91/93`, position `10`), ButtonControlPane R8 (`91/93`, position `10`), and PrettyButtonControlPane2 R2 (`92/93`, position `20`) close the source declarations and exact layouts.
- Implemented exactly: UID0004EA R3, UID0004EF R4, UID0002UX R5 at `90/94`, and unchanged UID0004EB R6.
- Implemented exactly: UID0000IG/UID0000HY/UID0000MP are `90/92`; UID0001F9, UID0002PB, UID000118, UID0004EA, UID0004EB, UID0004EF, UID0004EH, and UID0004EI retain accepted scores/routes.
- Preserved exactly: no split, merge, rename, new UID, new file, direct IDA mutation, manual generated edit, or manual coverage edit occurred.

## Supervisor Active Recheck

- Historical pre-callback requirement: supervisor Gate 1 required a complete report-first dependency closure before ordinary edits. Exact accepted report SHA `3E06565D8E165FE29206E75E21B2384233C6973458F751B735534CFC666E9F0A` passed that gate.
- Callback result: every accepted target/base/class/file/vtable/aggregate item is applied or verified at same-or-greater detail; associated source blockers were not deferred.
- The target remains one exact modeled function with parent-only adjacent padding; no split/rename/new UID was introduced.
- Source-bearing dependency is current:
  - UID0004EB owns the one human destructor body.
  - UID0000AS owns the declaration and virtual destructor prototype.
  - UID0004EL remains retained compiler output with no source emission.
- External supervisor review/execution/count/path/move/archive status is not asserted or directed by this artifact.

## Inference Research Guidance Check

- Direct IDA fact, documentation evidence, and inference are separated throughout this report.
- Existing target documentation was treated as a hypothesis, not authority. Its broad compiler-wrapper classification was revalidated; its target-level reconstructable/emitter/comment disposition was rejected.
- Source-quality names use the strongest current family convention:
  - `PrettyButtonControlPane2`
  - `m_visualStateFrameActive`
  - `m_selected`
  - frame ID fields
  - pointer-backed `mystr::StringBase`
  - `FunctionObject0 *m_callback`.
- Protected access for `m_controlFlags`, `m_reservedControlState`, `m_enabled`, `m_controlActive`, and `m_visualState` is now an evidence-backed source requirement: many accepted derived constructors/methods write those bytes directly and no setter-call lowering appears.
- Exact original access labels and private member spellings remain inferred, but the three declarations are mechanically source-safe and behaviorally complete.
- Consumer callers, vtable cells, and neighboring address locality were not treated as ownership by themselves.
- Wave2/Wave3 and simroot references were ignored as current authority and retained only as historical/search provenance where useful.

## Heuristic / Inference Reanalysis And Validation

### Compiler-wrapper identity

- Live MCP models `sub_54BBC0` at `0x0054bbc0`, size `0x7d` / decimal 125 (Verified with MCP `int_convert`).
- The function receives `this` in `ecx`, consumes one four-byte stack flags argument (`retn 4`), and returns complete `this` in `eax`.
- It restores all three class2 vtable views, destroys the same members/base as UID0004EB, tests deleting flags, optionally frees object storage, and is reached by the primary vtable and two receiver-adjustor thunks.
- These are compiler deleting-destructor characteristics, not a separately source-authored method.

### Flag and free behavior

- `(flags & 1) == 0`: perform teardown, do not release object storage, return complete `this`.
- `(flags & 1) != 0 && (flags & 4) == 0`: perform teardown, call [UID:000197] `operator delete(this)`, return complete `this`.
- `(flags & 1) != 0 && (flags & 4) != 0`: perform teardown, push object size `0x12c` / decimal 300 and `this`, directly call `0x0041b6a0`, then return without storage release.
- Live MCP proves `0x0041b6a0` is a one-byte `retn` function named `@_guard_check_icall_nop@4`. The bit-4 path is therefore a direct no-op compiler/runtime branch, not vector deletion, sized deletion, or an indirect user callback.

### Teardown sequence

The target duplicates UID0004EB's ordinary destructor lowering instead of calling UID0004EB:

1. Load `m_callback` from complete-object offset `+0x128`.
2. Restore class2 primary/secondary/tertiary vtables at complete-object offsets `+0x00`, `+0xa0`, and `+0xa4`.
3. If `m_callback` is non-null, invoke virtual slot zero with deleting flag `1`, source-shaped as `delete m_callback`.
4. Destroy `m_paletteResourceName` at `+0x124` through `sub_582B70`.
5. Destroy `m_epfResourceName` at `+0x120` through `sub_582B70`.
6. Call/tail through `sub_544580` for inherited Pane/ControlPane teardown.
7. Apply compiler deletion flags and return complete `this`.

Vtable stores, member destructor calls, base destructor calls, delete flags, object storage release, return-this ABI, and the no-op bit-4 branch are all compiler lowering. The only source-authored derived destructor statement is the accepted UID0004EB `delete m_callback;`.

### Reachability

- Primary vtable cell `0x0062237c` contains `0x0054bbc0`.
- Secondary vtable cell `0x006223e4` contains `0x0054bb89`, whose exact two-instruction thunk subtracts `0xa0` and jumps to UID0004EL.
- Tertiary vtable cell `0x00622414` contains `0x0054bb94`, whose exact two-instruction thunk subtracts `0xa4` and jumps to UID0004EL.
- `xrefs_to 0x0054bbc0` returns the two thunk jumps plus primary vtable data reference. No ordinary direct call exists.
- This is sufficient liveness for compiler ABI coverage and directly rejects a dead/raw helper interpretation.

### Base declaration and protected-access closure

Evidence-time MCP session `64c11373` and callback-time documentation close the base chain instead of leaving it as an unresolved contract.

#### `ControlPane` exact source-facing state

- `sub_4949E0` is `[0x004949e0,0x00494a81)`, size `0xa1`, with source signature `ControlPane::ControlPane(unsigned char controlType, const RectBounds *bounds)`.
- `ControlPane` calls `Pane(1)`, optionally calls `SetBounds(bounds, 0)`, and initializes:

| Complete-object offset | Source field | Type / access | Direct evidence |
| --- | --- | --- | --- |
| `+0xf8` | `m_rangeStart` | `short`, protected | Constructor dword zero at `+0xf8`; neutral base-range alias accepted by UID0002PB. |
| `+0xfa` | `m_rangeCurrent` | `short`, protected | Same dword zero; derived slider/progress consumers. |
| `+0xfc` | `m_rangeEnd` | `short`, protected | Constructor word zero; derived slider/progress consumers. |
| `+0xfe` | `m_controlType` | `unsigned char`, protected | First explicit constructor argument. |
| `+0xff` | `m_controlFlags` | `unsigned char`, protected | Base zero; many accepted derived constructors directly assign this byte. |
| `+0x100` | `m_reservedControlState` | `unsigned char`, protected | Base zero; Button and Pretty constructor stores prove inherited lifetime. |
| `+0x101` | `m_enabled` | `bool`, protected | Base true; Enable/Disable and derived overrides use it. |
| `+0x102` | `m_controlActive` | `bool`, protected | Base false; Activate/Deactivate and Button constructor use it. |
| `+0x103` | `m_visualState` | `unsigned char`, protected | Base value `10`; state virtuals and Pretty methods use it. |
| `+0x104` | `m_ignoreHitTesting` | `bool`, protected | Base false; exact getter/setter use it. |
| `+0x105..+0x107` | natural tail alignment | no source member | `ControlPane` deleting wrapper passes object size `0x108`. |

- `sub_49B170` is a compiler deleting wrapper with size immediate `0x108` and direct `Pane` teardown. No `ControlPane`-owned member destructor or ordinary source body exists, so an inline empty virtual destructor is the precise human source cause.
- Primary vtable state slots and current child pages prove `SetVisualState`, `Enable`, `Disable`, `SetIgnoreHitTesting`, `Deactivate`, `Activate`, and byte-return `HitTestPart(int,int)`; `IgnoresHitTesting()` is the exact nonvirtual getter.
- The primary slot order is exact: `+0x48 SetVisualState`, `+0x4c Enable`, `+0x50 Disable`, `+0x54 SetIgnoreHitTesting`, `+0x58 Deactivate`, `+0x5c Activate`, and `+0x60 HitTestPart`. The `0x0041d690` base body ignores both coordinates, returns byte `10`, and is overridden at the same terminal control-family slot by concrete panes with part/type-specific byte returns. `GetFixedValue10` is retained only as the old descriptive placeholder; `HitTestPart(int x,int y)` is the coherent source-facing family contract.
- Protected access is more plausible than private fields plus invented setters:
  - accepted TextEdit, PopupMenu, Scrollable, StaticText, EPFImage, UserShape/UserFace, SpellMacro, and Pretty constructors compile to direct writes at `+0xff`;
  - Pretty/other derived methods directly read `m_enabled`, `m_controlActive`, and `m_visualState`;
  - no call target or vtable route implements a field-setting facade for the Pretty stores.

#### `ButtonControlPane` exact source-facing state

- `sub_494EB0` is `[0x00494eb0,0x00494f38)`, size `0x88`, with one explicit bounds pointer/reference ABI argument.
- It calls `ControlPane(0, bounds)`, writes the three button vtables, then performs this exact source-visible order:
  1. `m_controlActive = false` at inherited `+0x102`;
  2. `m_controlSelected = false` at button-owned `+0x108`;
  3. `m_controlFlags = 1` at inherited `+0xff`;
  4. `m_reservedControlState = 1` at inherited `+0x100`;
  5. `SetMode(1)`.
- `sub_49B0D0` is the compiler deleting wrapper with object-size immediate `0x10c`, direct inherited `Pane` teardown, and no button-owned teardown. An inline empty virtual destructor is therefore exact.
- `sub_494F40` is source-facing `void SetControlSelected(bool selected)`: it updates `+0x108` only on change and invalidates inherited bounds through primary slot `+0x20`.
- `sub_494F70` is the current EventHandler secondary-facet override `bool HandleKeyOrTextEvent(Event *event)`, historically called `OnKeyPress`; secondary-table position and current project interface naming reject retaining `OnKeyPress` in the formal declaration.
- The one button-owned byte plus natural tail alignment closes `ButtonControlPane` at `0x10c`.

#### Required declaration order and includes

The implementation-ready source dependency order is:

```text
Pane.h
  -> ControlPane.h includes Pane.h and forward-declares RectBounds
  -> ButtonControlPane.h includes ControlPane.h and forward-declares Event/RectBounds
  -> PrettyButtonControlPane.h includes ButtonControlPane.h, FunctionObjects.h, and StringBase.h
  -> PrettyButtonControlPane.cpp emits the exact class2 children
```

- `ControlPane` and `ButtonControlPane` must be complete before `PrettyButtonControlPane2` derives from them; a forward declaration is insufficient for a base class.
- `mystr::StringBase<...>` must be complete before it is used as a by-value member; the failed R2's template forward declaration was not sufficient.
- `FunctionObject0` is stored as a pointer, but R6 performs `delete m_callback`; its full virtual-destructor declaration must therefore be visible at the destructor definition. Current [UID:0001WQ] `FunctionObjectTemplates` supplies that declaration through the header-heavy [UID:0000JO] `util/FunctionObjects.h` route, so R2 must include `FunctionObjects.h` rather than relying on a forward declaration.
- `RectBounds` may be forward-declared because the constructors use pointer/reference parameters.
- Exact original header paths are unavailable, but source-facing `Pane.h`, `ControlPane.h`, `ButtonControlPane.h`, `FunctionObjects.h`, and `StringBase.h` are implementation-ready dependency names and do not alter ABI.

### Class layout and declaration closure

The bit-4 size immediate and current family field evidence close the complete object at exactly `0x12c`:

| Offset / span | Size | Source member / subobject | Evidence and disposition |
| --- | ---: | --- | --- |
| `+0x000..+0x10b` | `0x10c` | `ButtonControlPane` base | Base deleting wrapper size and the first class2 field at `+0x10c`. |
| `+0x10c..+0x10f` | `4` | `int m_normalFrameId` | Constructor store; default paint frame. |
| `+0x110..+0x113` | `4` | `int m_pressedFrameId` | Constructor store; state-11 paint frame. |
| `+0x114..+0x117` | `4` | `int m_selectedFrameId` | Constructor store; selected paint frame. |
| `+0x118..+0x11b` | `4` | `int m_disabledFrameId` | Constructor store; disabled paint frame. |
| `+0x11c` | `1` | `bool m_selected` | UID0004EC write and UID0004EF read. |
| `+0x11d` | `1` | `bool m_visualStateFrameActive` | UID0004EE write and UID0004EF read; accepted normalization target. |
| `+0x11e..+0x11f` | `2` | natural alignment | Implicit alignment before a 32-bit string object; no raw padding member. |
| `+0x120..+0x123` | `4` | `mystr::StringBase<wchar_t,...> m_epfResourceName` | Constructor helper, paint `c_str`, destructor release. |
| `+0x124..+0x127` | `4` | `mystr::StringBase<wchar_t,...> m_paletteResourceName` | Constructor helper, paint `c_str`, destructor release. |
| `+0x128..+0x12b` | `4` | `FunctionObject0 *m_callback` | Constructor clear, setter replacement, click invoke, destructor delete. |

- The order naturally creates the exact two-byte alignment and total `0x12c` size with no raw offset fields, reserve arrays, or reverse-engineering comments in C++.
- The complete source surface is:
  - public constructor;
  - public virtual destructor;
  - public `SetSelected` and `SetCallback`;
  - protected virtual `SetState`, `OnPaint`, and `OnClick`;
  - private derived fields above.
- `[[CHILDREN]]` must appear after the closed class so qualified method definitions emit at namespace scope.

### Constructor source-shape repair

- Pre-callback UID0004EA put stale aliases `m_constructorFlag` and `m_reservedState` in the derived member initializer list even though their offsets `+0xff/+0x100` are inherited `ControlPane` fields. That was not legal derived-class C++, and the aliases were weaker than the accepted support evidence.
- Current binary order after the two string constructions is:
  1. store the constructor argument to inherited `m_controlFlags` at `+0xff`;
  2. clear callback at `+0x128`;
  3. clear inherited `m_reservedControlState` at `+0x100`.
- Source-safe first draft therefore:
  - keeps only derived fields that are actually initialized before the body in the initializer list;
  - assigns `m_controlFlags`, `m_callback`, and `m_reservedControlState` inside the body in observed order;
  - relies on the exact protected state declared by R7, not on an undeclared future interface.
- Rejected alternatives:
  - duplicate derived fields at `+0xff/+0x100`: impossible because those offsets are inside the `0x10c` base;
  - raw byte casts or offset writes: decompiler-shaped and not human source;
  - invented setter calls: no call lowering exists and direct derived writes are a repeated family convention;
  - retaining `m_constructorFlag`/`m_reservedState`: weaker than the accepted neutral base names and inconsistent with other current derived constructors.

### Name normalization

- `m_visualStateFrameActive` is preferred over `m_state11VisualActive` because:
  - UID0004EE is the direct writer and already uses `m_visualStateFrameActive`;
  - class1 `SetState` and constructor support also use the same family name;
  - it describes the field's source role without baking raw state literal `0x0b` into the identifier.
- UID0004EA and UID0004EF are normalized to that one spelling. The former spelling remains historical search provenance.

### Rejected alternatives

- Handwritten scalar-wrapper C++: rejected because it would expose compiler flags, vptr stores, base/member destruction, object deletion, and return-this ABI.
- Comment-only target marker: rejected because current scalar-wrapper policy keeps these exact pages blank/non-emitting; the comment is artificial generated-source pollution.
- Covered-by target comment: rejected because UID0004EL is compiler output, not a reconstructable source-authored body intentionally shared with another emitter.
- Merge into UID0004EB: rejected because the binary contains a distinct modeled deleting entry and a separate raw ordinary destructor body.
- Keep target reconstructable true with blank emitter: rejected because the page itself is not a source-level item; source semantics are fully carried elsewhere.
- Direct file ownership: rejected because the class is the narrow semantic owner.
- FunctionObjects, StringBase, Pane, MemoryMan, or caller ownership: rejected as dependency ownership.
- New wrapper source file: rejected because deleting destructors are generated from class declarations and ordinary destructors.
- Raw layout fields or explicit vtable arrays: rejected.

## Evidence Standards Used

- Mandatory live IDA MCP facts are primary for function extent, bytes, hash input, instructions, decompilation, CFG, xrefs, vtable cells, callees, and helper identity.
- Current by-* docs are used as documentation evidence and independently checked where they affect this target.
- Executed reports are leads/history, not substitutes for current MCP.
- Generated C++ is a read-only symptom/source-route check, not source authority.
- Manual coverage hashes, metrics, row text, and line positions are callback-time read-only evidence; the report supplies exact immutable supervisor-owned handoff text without asserting later coverage state.
- Negative evidence includes no ordinary callers, no source-level second destructor contract, no vector/sized-delete behavior on bit 4, no need for a new split, and no independent helper/source owner.
- The evidence ladder is sufficient for very strong target confidence because binary, vtable, ordinary-destructor, class-field, generated-state, and project policy evidence all converge.

## Evidence Checked

### IDA MCP/manual-disassembly/raw-byte checks

- Fresh `idb_list` discovered active database `64c11373` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- `server_health(database='64c11373')` returned:
  - `status:ok`
  - module `NexusTK.exe`
  - imagebase `0x400000`
  - `auto_analysis_ready:true`
  - `hexrays_ready:true`
  - `strings_cache_ready:true`
  - strings cache size `2067`.
- Bounded positive availability probe:
  - `lookup_funcs 0x0054bbc0 -> sub_54BBC0 size 0x7d`.
  - `get_bytes 0x0054bbc0 size 125` returned real target bytes.
- Target MCP calls:
  - `lookup_funcs`
  - `get_bytes`
  - `analyze_function`
  - `decompile`
  - `disasm`
  - `xrefs_to`
  - `int_convert`.
- Family MCP calls:
  - `analyze_function` for `0x0054b8c0`, `0x0054ba30`, `0x0054baa0`, and `0x0054bb50`;
  - scoped `insn_query` for raw UID0004EB;
  - `disasm` for UID0004EH, UID0004EI, and sibling UID0004EM;
  - `get_int` for vtable cells `0x0062237c`, `0x0062239c`, `0x006223c0`, `0x006223c4`, `0x006223e4`, `0x00622414`, and `0x00622418`;
  - `lookup_funcs`/`disasm` for `0x0041b6a0`;
  - current `operator delete` support check at `0x004f4ac0`.
- Gate 1 repair MCP calls under the same healthy database:
  - `lookup_funcs` for `0x004949e0`, `0x00494eb0`, `0x00494f40`, `0x00494f70`, `0x0049b0d0`, `0x0049b170`, and `0x0054b8c0`;
  - full `analyze_function(include_asm=true)` for those seven functions;
  - bounded bytes for the `ControlPane`/`ButtonControlPane` deleting wrappers and complete button constructor;
  - `get_int` for `ControlPane` and `ButtonControlPane` primary/secondary/tertiary vtable cells.
- Repair-pass direct MCP results:
  - `sub_4949E0` size `0xa1`, packed fields through `+0x104`, and `sub_49B170` object-size immediate `0x108`;
  - `sub_494EB0` size `0x88`, exact inherited/button store order, and `sub_49B0D0` object-size immediate `0x10c`;
  - `sub_494F40` exact selected-byte transition;
  - `sub_494F70` exact secondary-facet key/text event override;
  - `sub_54B8C0` exact `+0xff`, `+0x128`, `+0x100` post-string store order.
- One MCP initialize request transiently timed out under load. It was not used as evidence. After a three-second bounded retry, `server_health`, helper lookup, and one-byte helper disassembly succeeded; MCP remained usable and no fallback conclusion was taken.
- At the final evidence recheck, `idb_list` returned database `64c11373`; `server_health.status:ok` reported analysis/Hex-Rays/strings ready, `lookup_funcs` resolved `0x0054bbc0 -> sub_54BBC0 size 0x7d`, and bounded `get_bytes` returned the expected first 16 target bytes `55 8b ec 56 8b f1 8b 8e 28 01 00 00 c7 06 7c 23`. These are captured evidence-time facts, not an assertion about later session availability.

### Existing report searches

Exact terms:

- `0004EL`
- `0x0054bbc0`
- `PrettyButtonControlPane2ScalarDeletingDestructor`
- `sub_54BBC0`.

Exact roots and outcomes:

| Root | Outcome |
| --- | --- |
| `executed-b-agent-research/**` | Family/support matches only: B011 split, B004 ordinary destructor, B006 vtable, and sibling method reports. No dedicated UID0004EL target report. |
| `archived/**` | Zero matches for all four exact terms. |
| `tools/leaser/Agents/Older-Research/**` | Zero matches for all four exact terms. |
| `tools/leaser/Agents/SpecialReports/**` | Zero matches for all four exact terms. |
| `tools/leaser/Agents/Agent-B*/research/**` | Zero active report matches for all four exact terms at evidence time. |

### Documentation/generated/manual checks

- Target/support files and their evidence-time hashes are recorded under `Changed Files`.
- Callback-time [UID:000038] `ControlPane`, [UID:00001E] `ButtonControlPane`, their file pages, exact constructor/vtable/destructor support, accepted sibling derived constructors, and generated `ControlPane.cpp`/`ButtonControlPane.cpp` were reread for this repair.
- Historical pre-callback generated evidence confirmed one coordinated declaration-order defect: UID000038/UID00001E/UID0000AS marker symptoms, missing base/class declarations, and stale Pretty aliases.
- B003 command-13727 generated files and later evidence-time read-only external command-13759 files were parsed by line, definition/name counts, marker counts, class-closure order, and prohibited raw-ABI patterns; all accepted generated assertions passed at both observed epochs.
- Manual memory/class/file rows and root hashes/metrics were reread at the recorded callback-time snapshot.
- The tracker row and generated memory coverage row were reread at callback evidence time.
- At callback closure, the lease ledger `tools/leaser/Agents/current_leases.md` contained no B003 lease.

### Failed, unavailable, or intentionally skipped checks

- No IDA mutation, rename, type application, comment edit, process management, or IDB save was attempted.
- No PE fallback-only conclusion was used because MCP was healthy after bounded retry.
- Scoped implementation validators and the final waited refresh were run only after the exact report passed Gate 1; their results are recorded below.
- No report execution/probe/count/move/archive/revalidation/lifecycle command was run.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state | Implementation proof |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | Evidence-time IDB session `64c11373` was healthy and returned real target bytes/function data; the transient initialize timeout was retried successfully and is not evidence. | Very high | `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, bounded retry. | Target `IDA Evidence`; class/file/parent current evidence; report Validator Results. | incorporate | applied | Target and support pages retain the evidence-time session/health facts; command `13717` validated the target, and the report preserves the bounded-retry distinction. |
| C02 | UID0004EL is exactly `[0x0054bbc0,0x0054bc3d)`, size `0x7d` / 125, SHA256 `85FB4BCE...95EC8`, with 11-byte predecessor and 3-byte successor `0xcc` pads excluded. | Very high | MCP bytes/hash/disasm; parent exact table. | Target boundary/bytes/hash; parent inventory; manual row. | incorporate | applied | Target hash `62A85D...4908C` contains exact bytes/hash/pads; parent hash `6C63FC...EC5C2` preserves all address-ordered padding/children. |
| C03 | The ABI is x86 `__thiscall`, one four-byte flags argument, complete-object `this` return in EAX, 39 instructions, 7 IDA blocks, complexity 3. | Very high | MCP disasm/analyze/decompile. | Target ABI/CFG/instruction evidence. | incorporate | applied | Exact ABI/CFG/instruction evidence is in UID0004EL and passed command `13717`. |
| C04 | Flag matrix is exact: bit 1 controls deletion; bit 4 redirects to direct one-byte no-op `0x0041b6a0` with size `0x12c`; only bit1-set/bit4-clear calls global operator delete. | Very high | Target disasm; helper disasm; UID000197. | Target flag matrix/callees/no-code proof; class layout. | incorporate | applied | UID0004EL contains the three-row matrix/no-op proof; UID0000AS contains the `0x12c` layout. Commands `13717` and `13721` passed. |
| C05 | Target teardown duplicates UID0004EB: callback delete, `+0x124/+0x120` string cleanup, inherited base teardown, then deletion ABI. | Very high | Target and raw ordinary disassembly; family docs. | Target behavior/source split; ordinary destructor cross-link; parent/file/class prose. | incorporate | applied | Target/class/parent/file pages describe exact parity; R6 remains byte-identical at hash `4D1FCD...8CF1`. |
| C06 | Reachability is compiler-vtable-only: primary slot points directly to target; secondary/tertiary thunks subtract `0xa0`/`0xa4`; no ordinary direct call exists. | Very high | MCP xrefs, vtable ints, thunk disassembly. | Target reachability; vtable page; parent/class inventory. | incorporate | applied | UID0004EL and UID0002UX record all three routes; UID0004EH/EI remain unchanged hashes `E08958...2433` / `89B292...CFBC`. |
| C07 | UID0004EL must become `92/94`, `RECONSTRUCTABLE:FALSE`, blank emitter/formal, owner `0000AS`, blank position, `Nested:0`. | Very high | Compiler-wrapper identity; accepted scalar-wrapper precedent; source dependency closure. | Target metadata/formal/summary/score/policy. | incorporate | applied | UID0004EL callback-time hash `62A85D...4908C`; validator `13717` recorded score, true-to-false, emitter clear, and block-to-blank changes. |
| C08 | A target covered-by comment is invalid here; compiler-only false/blank is the precise disposition. | High | `by-structure.md`; FunctionObject/ScrolledPicture scalar-wrapper precedents. | Target C++ policy and rejected alternatives. | reject-invalid | excluded-with-reason | Covered-by/comment emission is explicitly rejected; R1 is blank, and B003 command-13727 plus later evidence-time command-13759 output contained zero UID0004EL title/address/comment occurrences. |
| C09 | No rename/split/merge/new child is needed; target path/title/range and relative `Nested:0` remain exact. | Very high | Modeled function; exact pads; predecessor/successor Nested 0. | Target/parent/manual/checklist. | already-present | already-present | Exact path/UID/range/Nested were retained; no rename/new UID/new page operation occurred. |
| C10 | Complete class size is `0x12c` with base `0x10c`, four ints, two bools, natural 2-byte alignment, two one-pointer wide StringBase fields, and callback pointer. | Very high for layout, high for spellings | Size immediate; constructor/state/paint/destructor/callback evidence; type docs. | Class layout/prose/formal; target size evidence; file support. | incorporate | applied | UID0000AS exact layout/R2 at hash `96BA72...7838A`; parent/file carry the same layout; command `13721` passed. |
| C11 | The accepted UID0000AS transition is `92/93`, position `20`, with a complete class declaration closed before `[[CHILDREN]]`, explicit complete-type includes for ButtonControlPane/StringBase/FunctionObject0 deletion, and the accepted base contract; source owner/file route stay unchanged. | High | Complete method/tail layout, repaired base chain, ordinary destructor delete, and generated empty-marker defect. | `by-class/PrettyButtonControlPane2.md` metadata/formal/status/layout/access. | incorporate | applied | UID0000AS hash `96BA72...7838A`; command `13721` recorded score/position/block; B003 command `13727` and later evidence-time command `13759` showed class close at line 45 before definitions and no UID0000AS marker. |
| C12 | UID0004EA must use `m_visualStateFrameActive`, use `RectBounds`, and move inherited `m_controlFlags`, owned `m_callback`, and inherited `m_reservedControlState` assignments into the body in observed order. | Very high | Constructor stores/order; current ControlPane field contract; repeated derived direct writes; C++ inherited-member rules. | Constructor formal/prose; class/formal parity; file generated expectations. | incorporate | applied | UID0004EA hash `D06B67...C5229`; R3 parity true; command `13722` passed; generated class2 constructor appears once. |
| C13 | UID0004EF must normalize `m_state11VisualActive` to `m_visualStateFrameActive` without any behavior or score change. | High | UID0004EE direct writer; class1 family naming; paint branch. | OnPaint formal/field table/prose; class declaration. | incorporate | applied | UID0004EF remains `88/90`, hash `606CCD...DD37D`; R4 parity true; command `13723` passed. |
| C14 | UID0002UX remains class-owned reconstructable generated-binary data with its existing marker, but rises `88/93 -> 90/94` and records the target's false/blank compiler disposition and complete class cause. | High | Exact vtable bytes/slots/xrefs; class declaration closure. | Vtable metadata/summary/slot/reconstruction/score. | incorporate | applied | UID0002UX hash `38B830...3F85`; command `13724` recorded `90/94`; B003 command `13727` and later evidence-time command `13759` emitted R5 exactly once. |
| C15 | UID0001F9 remains `88/90`, false/blank split index; update only UID0004EL role plus class2 layout/name/source/compiler facts and preserve all ranges/pads/children. | Very high | Current parent complete table and target reanalysis. | Parent Item Summary/inventory/evidence/score history. | incorporate | applied | UID0001F9 hash `6C63FC...EC5C`; command `13725` passed with metadata unchanged and complete class1/child/pad union preserved. |
| C16 | UID0000MP rises `89/91 -> 90/92`, preserves source route, and records complete class2 declaration/ordering plus target no-emission; class1 declaration/scalar-wrapper debt remains a cap. | High | Current file/source route; generated output; target/class repair. | File source inventory/generated policy/score. | incorporate | applied | UID0000MP hash `6EFBB6...C452`; command `13726` recorded `90/92`; class1 UID0000AR/UID0004EM remained read-only. |
| C17 | UID0004EB remains `88/91`, true/emitting, exact destructor body `delete m_callback;`; no formal or metadata change is required. | Very high | Live raw body and current target page. | Ordinary destructor verify-only cross-link; target/class/file support. | already-present | already-present | UID0004EB remained hash `4D1FCD...8CF1`; R6 parity true; no lease/edit/validator was issued for it. |
| C18 | UID0004EH/UID0004EI remain `86/90`, false, blank emitters/formals, owner `0000AS`; no edit was required because callback-time text did not contradict the accepted facts. | Very high | Live thunk disassembly and callback-time pages. | Verify-only pages; target/vtable/class evidence. | already-present | already-present | Callback-time hashes were `E08958...2433` and `89B292...CFBC`; metadata/formals were unchanged false/blank. |
| C19 | Waited generated output after callback must close all three class declarations before qualified definitions, remove UID000038/UID00001E/UID0000AS marker symptoms, preserve routed child definitions once, preserve R8's exact inline constructor/destructor plus declarations without speculative duplicate bodies, remove UID0004EL output, retain UID0002UX marker once, and emit no raw vtable/RTTI/ABI wrapper code. | High | Historical pre-callback three-file generated defects and repaired formal route design. | Final waited ControlPane/ButtonControlPane/PrettyButtonControlPane validation/readback; report callback proof. | incorporate | applied | B003 command `13727` completed the waited refresh; later evidence-time command `13759` preserved Control line 45/class-before-defs, Button line 35/class-before-derived declarations, Pretty line 45/class-before-seven definitions, target zero, R5 one, and no raw arrays/naked/asm/offset/decompiler source. |
| C20 | At B003 callback-time read-only snapshots, affected Pretty, ControlPane, and ButtonControlPane manual rows were stale or absent, so this report supplies exact supervisor-owned replacement/insertion handoff text; B003 must not edit coverage. | Very high | Callback-time manual hashes, metrics, row positions/text. | Immutable report handoff material; later coverage state is external and not asserted. | incorporate | applied | Callback-time hashes/rows were read at the listed snapshot positions; exact no-loss handoff text is retained unchanged; B003 made zero manual coverage edits and makes no claim about later application or current row state. |
| C21 | `+0xff/+0x100` are inherited `ControlPane::m_controlFlags` and `m_reservedControlState`, not Pretty-owned `m_constructorFlag`/`m_reservedState`. | Very high | ControlPane constructor, Button constructor, Pretty constructors, repeated derived writes. | ControlPane/Button/Pretty class and constructor docs; R2/R3/R7/R8. | incorporate | applied | Exact field/access prose is present in UID000038, UID00001E, UID0000AS, UID0002PB, UID000118, and UID0004EA; R2/R3/R7/R8 parity true. |
| C22 | `ControlPane` is exactly `0x108`; its `+0xf8..+0x104` fields must be protected and R7 supplies the complete source declaration at position `10`, including exact primary virtual order through terminal `HitTestPart(int,int)`. | Very high for layout/slot order; high for access/names | UID0002PB, UID0003J8/J9, scalar wrapper `0x108`, current method children and same-slot concrete overrides. | `by-class/ControlPane.md`; `by-file/ControlPane.md`; constructor/vtable support. | incorporate | applied | UID000038/UID0000IG/UID0002PB hashes and commands `13697/13700/13701`; generated ControlPane class closes before five current qualified definitions with no class marker. |
| C23 | `ButtonControlPane` is exactly `0x10c`; R8 supplies the complete source declaration, inline exact constructor/empty destructor, selected byte, and current key/text override at position `10`. | Very high for layout/body; high for names/access | `sub_494EB0`, `sub_494F40`, `sub_494F70`, `sub_49B0D0`, vtable cells. | `by-class/ButtonControlPane.md`; `by-file/ButtonControlPane.md`; aggregate/destructor support. | incorporate | applied | UID00001E/UID0000HY/UID000118 hashes and commands `13705/13709/13712`; generated R8 constructor/destructor/declarations each occur once with no duplicate Button body. |
| C24 | Direct protected field access is the source-faithful route; invented setters, duplicate derived fields, and raw offset writes are rejected. | High | Repeated accepted direct derived assignments and absence of setter calls/routes. | Heuristic/negative evidence; ControlPane/Button/Pretty support docs. | reject-invalid | excluded-with-reason | R2/R3/R7/R8 use direct protected fields; docs explicitly reject setters/duplicates/offsets; generated source has zero raw this-offset/cast patterns. |
| C25 | Source dependency order requires complete `Pane`/`ControlPane`/`ButtonControlPane` bases, complete StringBase storage, and complete FunctionObject0 at the deleting destructor definition; forward declaration remains valid only for Event and RectBounds pointer/reference uses. | High | C++ base/by-value/delete completeness rules, UID0001WQ/UID0000JO, and historical generated defects. | R2/R6/R7/R8; class/file generated-placement prose. | incorporate | applied | R2/R7/R8 exact includes/forward declarations match the report; R6 parity true; B003 command-13727 and later evidence-time command-13759 output ordered declarations before definitions. |
| C26 | Canonical rectangle spelling for repaired declarations is `RectBounds`; historical `Rect` remains provenance only. | High | UID0001VP/UID0000BU; ControlPane constructor; broad current derived-control declarations. | R2/R3/R7/R8; Pretty/Control/Button docs. | incorporate | applied | R2/R3/R7/R8 parity true and current class2/base generated declarations use `RectBounds`; stale `Rect` remains only historical class1/provenance text. |
| C27 | Historical ControlPane/ButtonControlPane/PrettyButtonControlPane generated files demonstrated one declaration-order/type-completeness defect chain and required coordinated waited readback. | Very high | Historical generated hashes/content and callback emitter routes. | Three file pages; Validator Results/checklist. | incorporate | applied | Historical command-13678 defect is preserved; B003 command `13727` supplied the coordinated waited callback epoch, and later evidence-time command `13759` preserved all accepted readback assertions. |
| C28 | The accepted ControlPane/ButtonControlPane class/file score increases accompany complete declarations while raw-helper liveness, exact original spellings, and broad file split remain explicit caps. | High | Resolved layouts/source causes plus retained unrelated blockers. | Score matrix; class/file docs; manual class/file rows. | incorporate | applied | Scores were applied by commands `13697/13700/13705/13709/13721/13726`; raw-helper, spelling, file-split, and class1 caps remain explicit; exact manual rows remain in the handoff. |

Action counts: `incorporate=23`, `already-present=3`, `reject-invalid=2`, `historicalize=0`, `reject-stale=0`, `not-applicable=0`.

Verification-state counts: `applied=23`, `already-present=3`, `excluded-with-reason=2`, `blocked=0`.

## Positive Evidence Summary

- Exact modeled function, range, 125-byte hash, first/last bytes, clean pads, and complete instruction inventory are available from live MCP.
- Vtable and two adjusted entries prove active compiler lifecycle reachability.
- Ordinary destructor and wrapper perform the same derived teardown; only the wrapper accepts flags and releases object storage.
- The one-byte bit-4 helper removes the remaining "vector/sized deletion" ambiguity.
- The `0x12c` size immediate independently closes the class tail layout.
- Constructor, selected setter, visual-state setter, paint, callback setter, click, ordinary destructor, and vtable pages all agree on the same derived fields.
- Current compiler-backed type evidence resolves the wide string fields and callback pointer.
- Current `ControlPane` constructor/scalar wrapper close the inherited state band and exact `0x108` base size.
- Current `ButtonControlPane` constructor/scalar wrapper close the `m_controlSelected` byte and exact `0x10c` base size.
- Repeated accepted derived constructors independently prove protected direct access to `m_controlFlags`; the Pretty stores are not an isolated anomaly.
- Historical pre-callback generated output exposed one coordinated three-file source-contract defect chain: missing `ControlPane`, `ButtonControlPane`, and `PrettyButtonControlPane2` declarations/type completeness, unavailable inherited state, and UID0004EL artificial compiler-wrapper comment output. B003 command `13727` repaired that chain, and later evidence-time external command `13759` preserved the repaired structure at its recorded snapshot.
- The three class declarations can be complete without raw offsets, duplicate fields, invented setter calls, or ABI code.

## IDA MCP Facts

### Session and health

- Evidence-time database: `64c11373`.
- IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Health: `ok`; auto-analysis, Hex-Rays, and strings cache ready.

### Exact target bytes and boundaries

- Range: `[0x0054bbc0,0x0054bc3d)`.
- Size: `0x7d` / decimal 125 (Verified with MCP `int_convert`).
- SHA256: `85FB4BCE2152DA8366C2B5F5CD30DFC676843B1E8453FE7CD416E6EB21E95EC8`.
- First 16 bytes:

```text
55 8b ec 56 8b f1 8b 8e 28 01 00 00 c7 06 7c 23
```

- Last 16 bytes:

```text
56 e8 6d fa ec ff 83 c4 08 8b c6 5e 5d c2 04 00
```

- Predecessor:
  - [UID:0004EK] ends at `0x0054bbb5`.
  - `[0x0054bbb5,0x0054bbc0)` is 11 `0xcc` bytes.
- Successor:
  - `[0x0054bc3d,0x0054bc40)` is 3 `0xcc` bytes.
  - [UID:0004EM] begins at `0x0054bc40`.

### Complete target instruction inventory

```text
54bbc0 push ebp
54bbc1 mov ebp, esp
54bbc3 push esi
54bbc4 mov esi, ecx
54bbc6 mov ecx, [esi+128h]
54bbcc mov dword ptr [esi], offset PrettyButtonControlPane2 primary vtable
54bbd2 mov dword ptr [esi+0A0h], offset PrettyButtonControlPane2 secondary vtable
54bbdc mov dword ptr [esi+0A4h], offset PrettyButtonControlPane2 tertiary vtable
54bbe6 test ecx, ecx
54bbe8 jz 54bbf0
54bbea mov eax, [ecx]
54bbec push 1
54bbee call dword ptr [eax]
54bbf0 lea ecx, [esi+124h]
54bbf6 call sub_582B70
54bbfb lea ecx, [esi+120h]
54bc01 call sub_582B70
54bc06 mov ecx, esi
54bc08 call sub_544580
54bc0d mov eax, [ebp+arg_0]
54bc10 test al, 1
54bc12 jz 54bc36
54bc14 test al, 4
54bc16 jnz 54bc28
54bc18 push esi
54bc19 call sub_4F4AC0
54bc1e add esp, 4
54bc21 mov eax, esi
54bc23 pop esi
54bc24 pop ebp
54bc25 retn 4
54bc28 push 12Ch
54bc2d push esi
54bc2e call 41B6A0h
54bc33 add esp, 8
54bc36 mov eax, esi
54bc38 pop esi
54bc39 pop ebp
54bc3a retn 4
```

### Function analysis

- MCP prototype lead: `void **__thiscall(void **Block, char)`.
- Source-facing ABI interpretation:
  - receiver: complete `PrettyButtonControlPane2 *`;
  - explicit stack slot: compiler flags dword, low byte tested;
  - return: complete object pointer.
- Instruction count: `39`.
- Basic blocks: `7`.
- Cyclomatic complexity: `3`.
- Callees:
  - `sub_582B70`
  - `sub_544580`
  - `sub_4F4AC0`
  - `@_guard_check_icall_nop@4`.

### Xrefs and vtable cells

| Address | Current value / xrefs | Meaning |
| --- | --- | --- |
| `0x0062237c` | `0x0054bbc0`; stores at `0x54b91f`, `0x54b999`, `0x54bbcc` | Primary class2 deleting-destructor slot/base. |
| `0x0062239c` | `0x00544800` | Inherited `Pane::InvalidateRect`, confirming UID0004EC is not a vtable target. |
| `0x006223c0` | `0x0054baa0` | Class2 `OnPaint`. |
| `0x006223c4` | `0x0054ba30` | Class2 `SetState`. |
| `0x006223e4` | `0x0054bb89`; stores at `0x54b925`, `0x54b99f`, `0x54bbd2` | Secondary view deleting thunk. |
| `0x00622414` | `0x0054bb94`; stores at `0x54b92f`, `0x54b9a9`, `0x54bbdc` | Tertiary view deleting thunk. |
| `0x00622418` | `0x0054bb50` | Class2 `OnClick`. |

- `xrefs_to 0x0054bbc0`:
  - code `0x0054bb8f` from [UID:0004EH];
  - code `0x0054bb9a` from [UID:0004EI];
  - data `0x0062237c`.

### Ordinary destructor comparison

Live scoped disassembly of `[0x0054b990,0x0054b9db)` confirms:

- callback load from `+0x128`;
- the same three vtable restores;
- callback deleting call with flag `1`;
- cleanup at `+0x124` and `+0x120`;
- tail jump to `sub_544580`;
- no flags argument or object storage release.

### Sibling scalar wrapper comparison

[UID:0004EM] at `[0x0054bc40,0x0054bcbd)` is structurally identical apart from:

- class1 vtable addresses;
- class1 callback/string offsets (`+0x124/+0x120/+0x11c`);
- object size `0x128` instead of `0x12c`.

This corroborates a compiler family pattern and does not transfer class1 scope into this report.

### Base-chain MCP facts

| Function / data | Exact fact | Source conclusion |
| --- | --- | --- |
| `0x004949e0-0x00494a81` | `ControlPane` constructor, size `0xa1`; writes `+0xf8..+0x104`. | Exact protected state band and constructor declaration. |
| `0x0049b170-0x0049b1ab` | Compiler deleting wrapper; size immediate `0x108`; no owned teardown. | `ControlPane` total size `0x108`; inline empty virtual destructor. |
| `0x00494eb0-0x00494f38` | `ButtonControlPane` constructor, size `0x88`; calls `ControlPane(0,bounds)`, writes `+0x102/+0x108/+0xff/+0x100`, calls `SetMode(1)`. | Exact inline constructor source and protected access. |
| `0x00494f40-0x00494f64` | Selected-byte transition at `+0x108`, invalidation on change. | `void SetControlSelected(bool)`. |
| `0x00494f70-0x0049500d` | Secondary-facet Event input, key-down type `8`, Space/Enter handling. | `bool HandleKeyOrTextEvent(Event *)`; historical `OnKeyPress` superseded. |
| `0x0049b0d0-0x0049b10b` | Compiler deleting wrapper; size immediate `0x10c`; no owned teardown. | `ButtonControlPane` total size `0x10c`; inline empty virtual destructor. |
| `0x00617a90/0x00617af8/0x00617b28` | ControlPane primary/secondary/tertiary bases. | R7 virtual declarations regenerate compiler tables. |
| `0x00617bd8/0x00617c40/0x00617c48/0x00617c70` | Button deleting slot, secondary adjustor, key/text slot, tertiary adjustor. | R8 destructor/event declaration regenerates compiler routes. |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0054b8c0-0x0054b98d` | [UID:0004EA] constructor | Human source constructor | TRUE | [UID:0000AS] | `89/91` | exact R3 applied |
| `0x0054b990-0x0054b9db` | [UID:0004EB] ordinary destructor | Human source destructor body | TRUE | [UID:0000AS] | `88/91` | verify-only, unchanged |
| `0x0054b9e0-0x0054b9f9` | [UID:0004EC] `SetSelected` | Human source method | TRUE | [UID:0000AS] | `88/90` | verify-only, unchanged |
| `0x0054ba00-0x0054ba24` | [UID:0004ED] `SetCallback` | Human source method | TRUE | [UID:0000AS] | `88/90` | verify-only, unchanged |
| `0x0054ba30-0x0054ba92` | [UID:0004EE] `SetState` | Human source virtual | TRUE | [UID:0000AS] | `88/91` | verify-only, naming authority |
| `0x0054baa0-0x0054bb48` | [UID:0004EF] `OnPaint` | Human source virtual | TRUE | [UID:0000AS] | `88/90` | exact R4 applied |
| `0x0054bb50-0x0054bb89` | [UID:0004EG] `OnClick` | Human source virtual | TRUE | [UID:0000AS] | `88/91` | verify-only, unchanged |
| `0x0054bb89-0x0054bb94` | [UID:0004EH] secondary adjustor | Compiler ABI thunk | FALSE | [UID:0000AS] | `86/90` | already correct |
| `0x0054bb94-0x0054bb9f` | [UID:0004EI] tertiary adjustor | Compiler ABI thunk | FALSE | [UID:0000AS] | `86/90` | already correct |
| `0x0054bbc0-0x0054bc3d` | [UID:0004EL] target | Compiler deleting-destructor clone | FALSE | [UID:0000AS] | `92/94` | applied, no emit |
| `0x00622378-0x0062241c` | [UID:0002UX] vtable/RTTI | Source-declared/generated-binary data | TRUE | [UID:0000AS] | `90/94` | R5 retained |
| class | [UID:0000AS] | Human class declaration/child route | TRUE | [UID:0000MP] | `92/93` | complete R2 applied |
| class | [UID:00001E] `ButtonControlPane` | Human base declaration and protected-state consumer | TRUE | [UID:0000HY] | `91/93` | complete R8 applied |
| class | [UID:000038] `ControlPane` | Human base declaration and protected state owner | TRUE | [UID:0000IG] | `91/93` | complete R7 applied |
| executable parent | [UID:0001F9] | Non-emitting split/index | FALSE | [UID:0000MP] | `88/90` | bounded class2 sync applied |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| target `0x0054bbc0` | code refs from `0x0054bb8f`, `0x0054bb9a`; data ref `0x0062237c` | Compiler lifecycle entry through primary and adjusted vtable views. |
| ordinary destructor `0x0054b990` | no direct raw-entry xrefs | Raw complete-object destructor body; source dependency proven by wrapper parity and class lifecycle, not ordinary callers. |
| constructor `0x0054b8c0` | callers at `0x52c6e1`, `0x52c745` in `sub_52C360` | Active object construction and argument/field evidence. |
| `SetState 0x0054ba30` | data ref from `0x006223c4`, no direct code callers | Virtual method and direct frame-active naming authority. |
| `OnPaint 0x0054baa0` | data ref from `0x006223c0`, no direct code callers | Virtual field consumer. |
| `OnClick 0x0054bb50` | data ref from `0x00622418`, no direct code callers | Tertiary-view virtual callback consumer. |
| `sub_4F4AC0` | broad global delete wrapper | Compiler storage release dependency, not PrettyButton ownership. |
| `0x0041b6a0` | direct one-byte `retn` | Compiler no-op flag-4 branch, not a source helper. |

## Documentation Evidence And IDA Status

- Historical pre-callback ordinary state:
  - target metadata/formal disposition was stale;
  - class/base pages lacked complete declarations;
  - constructor/paint formals used conflicting aliases and illegal inherited initializer entries;
  - generated command `13678` preserved UID000038/UID00001E/UID0000AS marker symptoms and the target comment emitter.
- Historical command `13678` (`2026-07-16T08:54:37-04:00`) files were:
  - `ControlPane.cpp` SHA256 `AD57088D9C46C54469998A8DA58CA64EE9FACDD9ADB0BE3A54C2E4D04A931CDA`, 2,063 bytes, 62 lines;
  - `ButtonControlPane.cpp` SHA256 `BC515617A85A72C8FF1C8EDFD427D595809963FA8D5D42D5C40A75C02CF4B59B`, 9,550 bytes, 275 lines;
  - `PrettyButtonControlPane.cpp` SHA256 `0B88A93694B188B682ED4D05F7EC24BE1E11C9E70858D60F69786020835B0203`, 8,707 bytes, 236 lines.
- Command `13678` was not issued by B003; it is a historical read-only external validator epoch and does not change the captured pre-callback evidence.
- Current ordinary state implements R1-R8 and all accepted score/prose/support changes. UID0004EB and UID0004EH/EI remain exact verify-only pages.
- B003 waited command `13727` replaced the accepted defects through validator-owned generation; later evidence-time external command `13759` preserved the same semantic result with newer headers at the recorded snapshot. B003 did not hand-edit generated output. Evidence-time hashes/metrics/counts are recorded in `Current Target State` and `Validator Results`.

## Ranked Ownership Analysis

### 1. [UID:0000AS] PrettyButtonControlPane2

- Evidence for:
  - target restores all three class2 vtables;
  - target destroys class2 fields and inherited state;
  - primary and adjusted vtable entries route here;
  - ordinary destructor, constructor, setters, paint, click, and vtable data all converge on this class;
  - complete class declaration regenerates target/compiler data.
- Evidence against:
  - none for semantic ownership.
- Decision: retain as canonical owner; clear target emitter because ownership and emission are separate.

### 2. [UID:0004EB] ordinary destructor / [UID:0000MP] source file

- Evidence for:
  - UID0004EB owns the one human destructor body;
  - UID0000MP is the coherent source module for both styled-button classes.
- Evidence against:
  - UID0004EB is a source child, not the semantic parent page;
  - UID0000MP is broader than the class and should not replace class ownership.
- Decision: ordinary destructor is the target's source dependency; file remains final source route.

### 3. [UID:0001F9] physical parent split/index

- Evidence for:
  - contains the exact target range and padding in address order.
- Evidence against:
  - spans two classes, raw bodies, thunks, wrappers, and padding;
  - already reviewed false/blank.
- Decision: retain as non-emitting physical inventory only.

### 4. FunctionObjects, StringBase, Pane/ButtonControlPane, MemoryMan, and feature callers

- Evidence for:
  - provide callback, string, base teardown, delete, and construction dependencies;
  - `ControlPane` and `ButtonControlPane` provide the exact source declaration/access chain needed by the derived class.
- Evidence against:
  - none owns the derived deleting wrapper;
  - base ownership does not transfer the class2 target or derived fields.
- Decision: support dependencies only, with R7/R8 required as implementation dependencies rather than alternative target owners.

### 5. No owner / direct file owner / new ABI wrapper file

- Evidence for:
  - no defensible source advantage.
- Evidence against:
  - class identity and source cause are exact.
- Decision: reject.

## Source Placement

- Recommended source file: [UID:0000MP] `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.
- Recommended source hierarchy:

```text
PrettyButtonControlPane2 class declaration
  -> includes complete ButtonControlPane declaration
  -> ButtonControlPane includes complete ControlPane declaration
  -> ControlPane includes complete Pane declaration
  -> constructor and ordinary destructor
  -> SetSelected / SetCallback / SetState / OnPaint / OnClick
  -> compiler regenerates vtables, two adjustor thunks, and UID0004EL deleting entry
```

- UID0004EL has no target-level source emission.
- Rejected placements:
  - standalone deleting-destructor source file;
  - FunctionObjects;
  - StringBase;
  - Pane/ButtonControlPane;
  - create-user caller source;
  - direct parent aggregate output.
- Required source-header dependency placement:
  - `ControlPane.h` owns R7 and protected state;
  - `ButtonControlPane.h` owns R8;
  - `PrettyButtonControlPane.h` owns R2 and includes `ButtonControlPane.h` plus complete StringBase support.
- Remaining placement uncertainty: exact original header basenames/paths and whether both styled classes shared one header remain inferred, but the current class/file routes and include dependency order are strong and sufficient.

## Range / Split / Padding / Reclassification Analysis

- Exact target range stays `[0x0054bbc0,0x0054bc3d)`.
- Exact function size stays `0x7d` / 125.
- Exact target hash is recorded above.
- Predecessor/successor padding dispositions stay parent-only:
  - `[0x0054bbb5,0x0054bbc0)` 11-byte alignment.
  - `[0x0054bc3d,0x0054bc40)` 3-byte alignment.
- No padding child page is required.
- No range endpoint, title, filename, UID, position, or nesting change is required.
- Relative `Nested:0` is correct:
  - predecessor [UID:0004EK] is `Nested:0`;
  - target does not open/close a source nesting container;
  - successor [UID:0004EM] remains `Nested:0`.
- Reclassification is required only for target source semantics:
  - `RECONSTRUCTABLE:TRUE -> FALSE`
  - `EMITTER_UIDS:0000AS -> blank`
  - comment formal -> blank.
- Parent [UID:0001F9] remains false/blank and retains all exact child/padding rows.

## Negative Evidence Summary

- No ordinary direct caller exists for UID0004EL.
- No source-level second destructor contract exists.
- No evidence supports handwritten flags, vptr writes, member/base destructor calls, storage deletion, return-this ABI, or no-op helper calls.
- No evidence supports vector deletion or sized deletion on the flag-4 branch; live helper disassembly is one `retn`.
- No evidence supports target-level covered-by emission after the target is correctly false.
- No evidence supports a range split, merge, rename, new child, new owner, new source file, or manual vtable definition.
- No evidence supports raw `void **Block`, `char a2`, `sub_` names, or offset-indexed final C++.
- No evidence supports duplicate derived fields for inherited `+0xff/+0x100` state.
- No evidence supports private base fields plus hidden setter calls: every checked derived write lowers directly and no corresponding helper target exists.
- No evidence supports retaining `m_constructorFlag`/`m_reservedState` after current ControlPane evidence names the neutral base fields.
- No evidence supports a forward-declared incomplete `ButtonControlPane` base or forward-declared by-value StringBase member.
- No evidence supports deleting `m_callback` while `FunctionObject0` remains incomplete; the accepted shared FunctionObjects declaration is available and must be included.
- No evidence supports retaining both `m_state11VisualActive` and `m_visualStateFrameActive` as separate fields; constructor clears one word at `+0x11c` and writer/reader evidence resolves two adjacent booleans only.
- Historical pre-callback generated output was not evidence that the target comment should stay; it was the symptom of stale target emission. At the later command-13759 evidence snapshot, UID0004EL title/address/comment occurrence count was zero.

## IDA Rename / Type / Comment Recommendations

- No IDA DB mutation is requested.
- Source-facing/documentation names:
  - target role: `PrettyButtonControlPane2 scalar deleting destructor` or `compiler deleting-destructor clone`;
  - class field: `m_visualStateFrameActive`;
  - string fields: `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >`;
  - callback field: `FunctionObject0 *m_callback`.
  - inherited state: `m_controlFlags`, `m_reservedControlState`, `m_enabled`, `m_controlActive`, `m_visualState`.
  - button state: `m_controlSelected`.
  - current event override: `HandleKeyOrTextEvent(Event *)`.
  - bounds type: `RectBounds`.
- Preserve `sub_54BBC0` only as an IDA/history search label.
- Preserve `m_state11VisualActive` only as a superseded documentation alias.
- Preserve `m_constructorFlag`, `m_reservedState`, `Rect`, and `OnKeyPress` only as superseded documentation/search aliases.
- If a future authorized IDA annotation pass occurs, a comment at `0x0054bbc0` may state "compiler-generated PrettyButtonControlPane2 deleting destructor; source is virtual ~PrettyButtonControlPane2 plus class layout." No rename/type mutation is needed for this report.

## First-Draft C++ Recommendation

### R1 - UID0004EL target formal destination

Eligible for draft C++: no.

Exact managed blank block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact no-code proof:

1. The target accepts compiler deletion flags and returns complete `this`.
2. It duplicates the ordinary destructor's member/base teardown.
3. It conditionally calls global operator delete.
4. It contains a compiler/runtime bit-4 no-op branch with object-size immediate.
5. It is entered through deleting vtable slots and receiver-adjustor thunks.
6. The human source is already represented by the virtual destructor declaration and UID0004EB body.
7. Any target C++ would duplicate source or expose ABI artifacts.

### R2 - UID0000AS class formal destination

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ButtonControlPane.h"
#include "FunctionObjects.h"
#include "StringBase.h"

struct RectBounds;

class PrettyButtonControlPane2 : public ButtonControlPane
{
public:
    PrettyButtonControlPane2(const RectBounds &bounds,
                             const wchar_t *epfResourceName,
                             const wchar_t *paletteResourceName,
                             int normalFrameId,
                             int pressedFrameId,
                             int selectedFrameId,
                             int disabledFrameId,
                             unsigned char constructorFlag);
    virtual ~PrettyButtonControlPane2();

    void SetSelected(bool selected);
    void SetCallback(FunctionObject0 *callback);

protected:
    virtual void SetState(unsigned char state);
    virtual int OnPaint();
    virtual bool OnClick(unsigned int action, int x, int y);

private:
    int m_normalFrameId;
    int m_pressedFrameId;
    int m_selectedFrameId;
    int m_disabledFrameId;
    bool m_selected;
    bool m_visualStateFrameActive;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > m_epfResourceName;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > m_paletteResourceName;
    FunctionObject0 *m_callback;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason it preserves exact behavior:

- declaration order closes the exact `0x12c` layout;
- `FunctionObjects.h` makes `FunctionObject0` complete before R6 deletes the callback;
- virtual declarations generate the observed vtable slots and deleting entries;
- method signatures match accepted children;
- no ABI glue is handwritten.

### R3 - UID0004EA constructor formal destination

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
PrettyButtonControlPane2::PrettyButtonControlPane2(const RectBounds &bounds,
                                                   const wchar_t *epfResourceName,
                                                   const wchar_t *paletteResourceName,
                                                   int normalFrameId,
                                                   int pressedFrameId,
                                                   int selectedFrameId,
                                                   int disabledFrameId,
                                                   unsigned char constructorFlag)
    : ButtonControlPane(bounds),
      m_normalFrameId(normalFrameId),
      m_pressedFrameId(pressedFrameId),
      m_selectedFrameId(selectedFrameId),
      m_disabledFrameId(disabledFrameId),
      m_selected(false),
      m_visualStateFrameActive(false),
      m_epfResourceName(epfResourceName),
      m_paletteResourceName(paletteResourceName)
{
    m_controlFlags = constructorFlag;
    m_callback = NULL;
    m_reservedControlState = 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

This is behaviorally equivalent to current evidence while being legal derived-class C++. It preserves observed post-string store order for inherited `m_controlFlags` at `+0xff`, owned `m_callback` at `+0x128`, and inherited `m_reservedControlState` at `+0x100`. R7 makes the inherited fields protected, so R3 does not depend on an undeclared future interface.

### R4 - UID0004EF OnPaint formal destination

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int PrettyButtonControlPane2::OnPaint()
{
    int frameId;

    if (!m_enabled) {
        frameId = m_disabledFrameId;
    } else if (m_visualStateFrameActive) {
        frameId = m_pressedFrameId;
    } else if (m_selected) {
        frameId = m_selectedFrameId;
    } else {
        frameId = m_normalFrameId;
    }

    EPFTileContext tileContext;
    tileContext.Init();

    g_pEPFLib->LookupLayoutEntry(m_epfResourceName.c_str(), frameId, &tileContext);

    FrameDrawRecord drawRecord;
    return RenderTileFrame(&tileContext,
                           &drawRecord,
                           &m_bounds,
                           1,
                           m_paletteResourceName.c_str(),
                           0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Only the accepted field spelling changes; behavior remains byte-for-byte sourced from the accepted UID0004EF evidence.

### R5 - UID0002UX vtable formal destination

Verify and retain exactly:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// PrettyButtonControlPane2 RTTI/vtable data is generated by the compiler from the class declaration and virtual method layout.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

This is a generated-binary marker on a source-declared data page, not handwritten vtable bytes.

### R6 - UID0004EB ordinary destructor formal destination

Verify and retain exactly:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
PrettyButtonControlPane2::~PrettyButtonControlPane2()
{
    delete m_callback;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R7 - UID000038 ControlPane class formal destination

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "Pane.h"

struct RectBounds;

class ControlPane : public Pane
{
public:
    ControlPane(unsigned char controlType, const RectBounds *bounds);
    virtual ~ControlPane() {}

protected:
    virtual void SetVisualState(unsigned char visualState);

public:
    virtual void Enable();
    virtual void Disable();
    bool IgnoresHitTesting() const;
    virtual void SetIgnoreHitTesting(bool ignoreHitTesting);

protected:
    virtual void Deactivate();
    virtual void Activate();
    virtual unsigned char HitTestPart(int, int)
    {
        return 10;
    }

    short m_rangeStart;
    short m_rangeCurrent;
    short m_rangeEnd;
    unsigned char m_controlType;
    unsigned char m_controlFlags;
    unsigned char m_reservedControlState;
    bool m_enabled;
    bool m_controlActive;
    unsigned char m_visualState;
    bool m_ignoreHitTesting;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

R7 closes the exact `0x108` base layout without raw padding fields. Its virtual declaration order preserves primary slots `+0x48..+0x60` exactly even though access labels change between them. The public constructor and enabled/hit-testing API match current source consumers. The state-changing virtuals and the `+0xf8..+0x104` state band are protected because current derived controls call or access them directly. The inline empty virtual destructor is the human source cause of the observed compiler deleting wrapper and direct inherited teardown.

### R8 - UID00001E ButtonControlPane class formal destination

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ControlPane.h"

class Event;
struct RectBounds;

class ButtonControlPane : public ControlPane
{
public:
    explicit ButtonControlPane(const RectBounds &bounds)
        : ControlPane(0, &bounds)
    {
        m_controlActive = false;
        m_controlSelected = false;
        m_controlFlags = 1;
        m_reservedControlState = 1;
        SetMode(1);
    }

    virtual ~ButtonControlPane() {}

    void SetControlSelected(bool selected);

protected:
    virtual bool HandleKeyOrTextEvent(Event *event);

    bool m_controlSelected;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

R8 closes the exact `0x10c` object size and preserves the constructor's source-visible store order. `m_controlSelected` is the single button-owned byte at `+0x108`; the remaining three bytes are natural alignment. `HandleKeyOrTextEvent(Event *)` matches the current secondary EventHandler interface and supersedes the historical `OnKeyPress` alias.

Formal destination count: `8` (`R1-R8`).

Third-party import directive: not applicable. UID0004EL is MSVC compiler output from NexusTK-owned class source, and R2-R8 are project class/method declarations or compiler-data dispositions. No vetted static third-party source or `third_party_embeds/...` path participates in this target.

## Final Recommendation

- UID0004EL is implemented as compiler-only false/blank at `92/94`.
- Exact owner `0000AS`, range, title, path, blank position, `Nested:0`, bytes, hash, pads, vtable/thunk reachability, full flag matrix, teardown order, negative evidence, and source/compiler rationale are retained.
- The complete `ControlPane` declaration R7 is installed at source position `10`, including the exact `0x108` protected state band and inline empty virtual destructor source cause.
- The complete `ButtonControlPane` declaration R8 is installed at source position `10`, including the exact `0x10c` layout, inherited-state constructor order, selected byte, current key/text override, and inline empty virtual destructor.
- The complete class2 declaration R2 is installed at source position `20` after complete Button/StringBase/FunctionObject0 dependencies.
- R3 now provides legal constructor source shape, canonical `RectBounds`, inherited `m_controlFlags`/`m_reservedControlState` assignments through the proven protected contract, and the normalized frame-active name.
- R4 now supplies the normalized paint field spelling.
- R5 and R6 remain exact.
- UID0002UX is `90/94` and UID0000MP is `90/92`; parent and accepted child scores/routes otherwise remain unchanged.
- UID000038 and UID00001E are `91/93`; UID0000IG and UID0000HY are `90/92`; their owners/routes and unrelated family evidence remain preserved.
- Class1 sibling wrapper/class declaration debt remains bounded outside this target. UID0004EM and UID0000AR were not edited.
- External supervisor/validator state owns any later validation, execution, count, path, move, or archive status; this artifact neither performs nor asserts those future lifecycle events.

## Recommended Target Doc Changes

Target path:

`by-memory/0x0054bbc0-0x0054bc3d.PrettyButtonControlPane2ScalarDeletingDestructor.md`

Implemented exact changes:

- `COMPLETION:86 -> 92`.
- `CONFIDENCE:90 -> 94`.
- Kept `CANONICAL_OWNER:0000AS`.
- `RECONSTRUCTABLE:TRUE -> FALSE`.
- `EMITTER_UIDS:0000AS -> blank`.
- Kept blank optional position.
- Kept exact path/title/range and `Nested:0`.
- Replaced the comment-only formal with R1 blank.
- Replaced Item Summary with the concise exact compiler-wrapper summary that includes:
  - 125-byte modeled function;
  - ordinary destructor parity;
  - vtable/thunk-only reachability;
  - bit1/bit4 behavior;
  - complete-object return;
  - human source dependency.
- Added sections for exact bytes/hash/boundaries, ABI/receiver, complete instruction/CFG facts, flag matrix, teardown sequence, reachability, source/compiler decomposition, exact no-code proof, rejected alternatives, score rationale, and history.
- Historicalized the comment-emitter wording rather than deleting the fact that it was the pre-callback generated representation.

## Recommended Support Doc Changes

This section is the implemented callback record. Every accepted B003-owned change below is present at report-level detail; imperative language retained inside quoted source contracts describes the accepted source shape, not pending work.

### `by-class/PrettyButtonControlPane2.md` / [UID:0000AS]

- Applied `89/91 -> 92/93`.
- Kept owner/emitter/file route/reconstructable true.
- Set `EMITTER_POSITION_OPTIONAL:20`.
- Installed R2 exactly.
- Added the exact `0x12c` layout table and source/compiler boundary.
- Updated method/child rows:
  - UID0004EL false/blank compiler wrapper;
  - UID0004EA legal constructor/body-assignment shape;
  - UID0004EF normalized frame-active name;
  - UID0004EB ordinary source destructor remains sole source body.
- Preserved every unrelated method fact, route, range, caller/callee, resource, negative, and history item.
- Historicalized Wave3/simroot claims as provenance rather than current authority.
- Included complete `ButtonControlPane.h`, `FunctionObjects.h`, and `StringBase.h` dependencies; the FunctionObject include is required by R6's `delete m_callback`.
- Documented inherited `m_controlFlags`/`m_reservedControlState` as protected `ControlPane` state supplied by R7 and rejected duplicate derived layout fields, invented setter calls, raw offset access, and the superseded aliases `m_constructorFlag`/`m_reservedState`.

### `by-memory/0x0054b8c0-0x0054b98d.PrettyButtonControlPane2Constructor.md` / [UID:0004EA]

- Kept `89/91`, owner/emitter, true, blank position, `Nested:0`.
- Applied R3 exactly.
- Normalized `m_state11VisualActive -> m_visualStateFrameActive`.
- Normalized `Rect -> RectBounds`.
- Replaced the invalid inherited-member initializer-list explanation with legal protected `m_controlFlags`/`m_reservedControlState` body assignments in the exact post-string store order.
- Preserved all exact constructor range, callers, vtable stores, parameters, resources, fields, pads, negative routes, and score caps.

### `by-memory/0x0054baa0-0x0054bb48.PrettyButtonControlPane2OnPaint.md` / [UID:0004EF]

- Kept `88/90`, owner/emitter, true, blank position, `Nested:0`.
- Applied R4 exactly.
- Normalized only the frame-active spelling in formal/prose/field table.
- Preserved all disabled-frame, resource, branch, helper, range, padding, vtable, and negative evidence.

### `by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md` / [UID:0002UX]

- Applied `88/93 -> 90/94`.
- Preserved owner/emitter/reconstructable true, blank position, `Nested:0`, exact range, three views, bytes, signature, slots, stores, boundary, negative UID0004EC evidence, and R5 marker.
- Added that:
  - UID0004EL is false/blank compiler output;
  - R2 is the complete class cause;
  - R6 is the sole source destructor body.
- Historicalized the old target comment-marker route as pre-callback state.

### `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md` / [UID:0001F9]

- Kept `88/90`, owner `0000MP`, false, blank emitter/formal, `Nested:0`.
- Updated UID0004EL inventory role to compiler deleting-destructor clone, false/blank, with exact flag/size/source dependency.
- Preserved all children, exact pads, endpoints, constructor fan-in, source children, class1 facts, and parent no-code proof.
- Added the class2 `0x12c` layout/name normalization and legal constructor source-shape note.

### `by-file/PrettyButtonControlPane.md` / [UID:0000MP]

- Applied `89/91 -> 90/92`.
- Preserved file route/path and every class1/class2/source/read-only inventory fact.
- Added the class2 complete declaration at position 20, R3/R4 normalization, UID0004EL no-emission, UID0002UX marker, and generated structure evidence.
- Kept class1 UID0000AR/UID0004EM unresolved declaration/wrapper state as an explicit score cap and bounded verify-only fact, not a reason to withhold class2 repair.

### `by-class/ControlPane.md` / [UID:000038]

- Applied `88/91 -> 91/93`.
- Kept owner/emitter/file route/reconstructable true.
- Set `EMITTER_POSITION_OPTIONAL:10`.
- Installed R7 exactly, with the class closed before `[[CHILDREN]]`.
- Added the exact `0x108` layout:
  - inherited `Pane` through `+0xf7`;
  - protected `short` range fields at `+0xf8/+0xfa/+0xfc`;
  - protected control type/flags/reserved state at `+0xfe/+0xff/+0x100`;
  - protected enabled/active/visual/hit-testing state at `+0x101..+0x104`;
  - natural tail alignment at `+0x105..+0x107`.
- Recorded `ControlPane(unsigned char,const RectBounds *)`, inline empty virtual destructor source cause, exact primary virtual order through `HitTestPart(int,int)`, current nonvirtual getter, direct derived access evidence, and the rejection of private fields plus invented setters.
- Preserved all unrelated constructor callers, raw/fixed-virtual caveats, vtable views, adjustor/compiler facts, children, and historical evidence.

### `by-file/ControlPane.md` / [UID:0000IG]

- Applied `88/91 -> 90/92`.
- Kept the current `NexusTK/ui/core/ControlPane.cpp` route and all unrelated control-family inventory.
- Recorded R7 as the complete declaration-before-definition source cause, exact protected state band, constructor/empty-destructor split, current child methods, and no handwritten compiler vtable/thunk/wrapper code.
- Preserved broad derived-control caller fanout, neighboring source families, fixed-virtual caveats, and existing score caps.

### `by-class/ButtonControlPane.md` / [UID:00001E]

- Applied `87/89 -> 91/93`.
- Kept owner/emitter/file route/reconstructable true.
- Set `EMITTER_POSITION_OPTIONAL:10`.
- Replaced the marker-only formal with R8 exactly.
- Added the exact `0x10c` layout and source contract:
  - complete `ControlPane` base `0x108`;
  - one protected `bool m_controlSelected` at `+0x108`;
  - natural `+0x109..+0x10b` tail alignment;
  - inline constructor preserving `m_controlActive`, selected, flags, reserved-state, and `SetMode(1)` order;
  - inline empty virtual destructor;
  - `SetControlSelected(bool)`;
  - protected `HandleKeyOrTextEvent(Event *)`.
- Historicalized `OnKeyPress` and marker-only/incomplete-layout wording; preserved all unrelated derived-class, vtable, raw-helper, caller, and source-split facts.

### `by-file/ButtonControlPane.md` / [UID:0000HY]

- Applied `88/89 -> 90/92`.
- Kept the current `NexusTK/ui/controls/ButtonControlPane.cpp` route and complete current control-family union.
- Recorded R8 as the declaration/source cause before derived definitions, exact constructor/empty-destructor split, selected-state method, current key/text interface, and compiler-only deleting/thunk exclusions.
- Preserved every unrelated Text/Image/Selection/Radio/Slider/CheckBox/SelectBox fact, range, route, caveat, and concurrent source-family detail.

### `by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md` / [UID:0002PB]

- Kept `89/92`, owner/emitter/true, position, range, formal, and current behavior.
- Added exact support prose connecting the constructor stores to R7's protected fields, `RectBounds` signature, `0x108` size proof, and direct derived-access contract.
- Preserved every caller, vtable store, bound-set branch, range, padding, and unrelated constructor fact.

### `by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md` / [UID:000118]

- Kept `86/90`, owner/file route, false/blank aggregate status, position, range, and full child inventory.
- Added the exact Button constructor/member/source contract from R8 and historicalized marker-only/future-declaration wording.
- Preserved every unrelated ButtonChoice child/helper/raw/compiler fact, exact range/padding, source split, and score cap.

### Base-chain verify-only pages

- [UID:0003J8] `ControlPaneVtableData` and [UID:0003J9] `ControlPaneVtables`: current table/RTTI/route evidence remains valid; no score/formal change was required.
- [UID:000252] `ControlPaneReadOnlyData`: the current mixed-family read-only inventory remains preserved; no split or raw-array emission change was required.
- [UID:00011Y] `ButtonChoiceControlDestructors`: all raw/compiler wrapper, thunk, and object-size evidence remains preserved; current readback found no contradiction requiring a direct edit.
- [UID:0000A2] `Pane`, Event, `RectBounds`, StringBase, FunctionObject0, and [UID:000197] operator delete remain read-only dependencies absent a direct current contradiction.

### Verify-only, no edits required

- [UID:0004EB] ordinary destructor: current R6 and `88/91` already exact.
- [UID:0004EH]/[UID:0004EI] thunks: current false/blank `86/90` already exact.
- [UID:0004EC]/[UID:0004ED]/[UID:0004EE]/[UID:0004EG]: current method behavior/formals are exact for this scope.
- StringBase, FunctionObject0, UID000197, Pane, Event, and RectBounds: support dependencies only; current callback-time readback found no direct contradiction.
- UID0004EM and UID0000AR: bounded class1 sibling debt, verify-only for comparison; do not broaden this callback into class1 implementation.

## Score And Metadata Recommendation

The accepted score/metadata transitions below are implemented. The pre-callback column is retained to make the score movement auditable.

| Destination | Pre-callback | Implemented | Metadata decision | Reason not higher |
| --- | --- | --- | --- | --- |
| UID0004EL target | `86/90` | `92/94` | owner unchanged; true -> false; emitter/comment -> blank; position/Nested unchanged | exact original compiler version and original class/header spelling are unavailable. |
| UID0000AS class | `89/91` | `92/93` | owner/emitter/true unchanged; position -> 20; complete R2 | exact original header/member spellings and private/protected labels remain inferred. |
| UID000038 ControlPane class | `88/91` | `91/93` | owner/emitter/true unchanged; position -> 10; complete R7 | exact original field spellings and some public/protected labels remain inferred; broad fixed-virtual history remains. |
| UID00001E ButtonControlPane class | `87/89` | `91/93` | owner/emitter/true unchanged; position -> 10; complete R8 | exact selected-member spelling and original header split remain inferred; broad derived family remains. |
| UID0002UX vtable | `88/93` | `90/94` | route/true/marker unchanged | exact original RTTI/source declaration spelling is compiler-mediated. |
| UID0000MP file | `89/91` | `90/92` | route/path unchanged | class1 declaration and UID0004EM remain unresolved/outside this target. |
| UID0000IG ControlPane file | `88/91` | `90/92` | route/path unchanged; R7 declaration/source split added | broad derived-control inventory and exact original file/header split remain caps. |
| UID0000HY ButtonControlPane file | `88/89` | `90/92` | route/path unchanged; R8 declaration/source split added | broad button/choice family split and exact original header organization remain caps. |
| UID0001F9 parent | `88/90` | unchanged | false/blank unchanged | already complete as a physical split/index. |
| UID0002PB ControlPane constructor | `89/92` | unchanged | support prose only | exact original names/access labels remain inferred; behavior/formal already strong. |
| UID000118 ButtonChoice aggregate | `86/90` | unchanged | false/blank aggregate; support prose only | broad mixed family and remaining raw-helper/source-split debt cap the aggregate. |
| UID0004EA constructor | `89/91` | unchanged | formal parity/source-safety repair only | exact inherited field spellings remain inferred, while access is now closed by R7. |
| UID0004EF paint | `88/90` | unchanged | name normalization only | exact original name and public API remain inferred. |
| UID0004EB destructor | `88/91` | unchanged | verify R6 | raw entry is unmodeled and has no direct xrefs. |
| UID0004EH/EI thunks | `86/90` | unchanged | false/blank | exact compiler ABI already complete enough for role. |

Score-improvement attempt:

1. Function/range blocker: resolved with live lookup, bytes, hash, disassembly, CFG, and pads.
2. Flag/free blocker: resolved with exact branch matrix, operator delete dependency, and one-byte bit-4 helper.
3. Reachability blocker: resolved with primary vtable and two thunk routes.
4. Source destructor blocker: resolved through UID0004EB and exact duplicated teardown.
5. Class size/layout blocker: resolved to `0x12c` with natural layout.
6. String type blocker: resolved to current compiler-backed `mystr::StringBase` spelling.
7. Callback type blocker: resolved to `FunctionObject0 *`.
8. Class declaration/access blocker: resolved with R2 and explicit access.
9. Constructor validity blocker: resolved with R3 body assignments.
10. Field-name conflict blocker: resolved with `m_visualStateFrameActive`.
11. Generated empty/marker blocker: resolved through class source position and target no-emission.
12. Base declaration blocker: resolved with exact `0x108` R7 and `0x10c` R8 declarations, inline source constructors/destructors, protected state, current method signatures, and complete declaration order.
13. Rectangle/type-completeness blocker: resolved with canonical `RectBounds`, complete base includes, complete `StringBase.h`, and complete `FunctionObjects.h` for callback deletion; only Event/RectBounds pointer/reference uses remain valid forward declarations.
14. Exact original header/member spelling remains a confidence cap, not a blocker to the recommended scores/C++.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Resolution / score impact |
| --- | --- | --- |
| Is UID0004EL source-authored or compiler-only? | Full body, flags, return, vtables, thunks, ordinary comparison. | Compiler-only deleting clone. Closed. |
| Should target emit blank, marker, covered-by, or body? | `by-structure`, scalar precedents, generated symptom, source cause. | `RECONSTRUCTABLE:FALSE`, blank emitter/formal. Closed. |
| What does flag `0x04` do? | Target branch and live `0x0041b6a0` disassembly. | Calls one-byte no-op with `this`/`0x12c`; no free. Closed. |
| Is `0x12c` object size or delete-array element size? | Class fields, sibling size, direct no-op helper. | Complete-object size evidence, not vector deletion. Closed. |
| What is the human destructor source? | UID0004EB raw body and target parity. | `virtual ~PrettyButtonControlPane2()` with `delete m_callback;`. Closed. |
| What are the string member types? | Constructor helpers, destructor release, paint c_str, compiler metadata. | `mystr::StringBase<wchar_t,mystr::mychar_traits<wchar_t> >`. Closed enough; exact typedef facade remains a confidence cap. |
| Which frame-active field spelling is best? | Direct writer UID0004EE, class1 family usage, constructor/paint aliases. | `m_visualStateFrameActive`. Closed for first draft. |
| How can inherited `+0xff/+0x100` fields be initialized legally? | C++ rules, exact base/derived stores, repeated derived direct writes, and base declaration reconstruction. | R7 declares protected `m_controlFlags`/`m_reservedControlState`; R3 assigns them in the body in observed order. Duplicate fields and invented setters are rejected. Closed. |
| Are `m_constructorFlag` and `m_reservedState` real base names? | ControlPane/Button/Pretty constructors and sibling derived controls. | No. Best current source-facing names are `m_controlFlags` and `m_reservedControlState`; old names remain superseded aliases only. Closed with a naming confidence cap. |
| What is the exact ControlPane source layout/access? | Constructor stores, deleting-wrapper size `0x108`, method pages/vtables, derived direct reads/writes. | R7 closes `Pane` plus protected `+0xf8..+0x104` fields and natural tail alignment. Public/protected labels are source-safe and evidence-backed. Closed. |
| What is the fixed byte-return virtual at `0x0041d690`? | Base `retn 8` body, ControlPane terminal primary slot `+0x60`, same-slot concrete control overrides, current part/type byte-return family. | Best coherent source contract is `unsigned char HitTestPart(int x,int y)`; base ignores coordinates and returns `10`. Historical `GetFixedValue10` is only a descriptive placeholder. Closed for first draft with exact-original-name confidence cap. |
| What is the exact ButtonControlPane source layout? | Constructor order, selected-byte setter, key/text override, deleting-wrapper size `0x10c`, vtable cells. | R8 closes the `0x108` base plus one protected bool and natural alignment; inline empty destructor is exact. Closed. |
| What declaration/include order is required? | C++ complete-base/by-value-member/delete-expression rules, UID0001WQ/UID0000JO, and historical pre-callback generated defects. | `Pane.h -> ControlPane.h -> ButtonControlPane.h -> PrettyButtonControlPane`, plus complete `StringBase.h` and `FunctionObjects.h`; only Event/RectBounds pointer/reference uses remain forward declarations. Closed. |
| Is `Rect` or `RectBounds` the current source type? | Current RectBounds class/type docs and ControlPane/derived constructor family. | `RectBounds` is canonical; `Rect` remains historical provenance. Closed for first draft. |
| Does the class need multiple source bases because it has three vtable views? | Base class/vtable/thunk evidence. | No. One public `ButtonControlPane` source base; adjusted views are inherited ABI facets. Closed. |
| Should class1 UID0004EM/UID0000AR be repaired now? | Current sibling docs/generated state. | They show parallel debt but are explicitly outside this class2 target. Preserve as verify-only follow-up and file score cap. |
| Can score exceed the recommendation? | All current routes above. | No. The base declarations are reconstructed to implementation-ready quality, but exact original field/header spellings and some access labels remain unavailable; retain the stated confidence caps. |

No in-scope question remains as "needs investigation." Remaining uncertainties are explicitly bounded naming/header confidence caps.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

B003 did not edit manual coverage. The following hashes, metrics, row positions, and row-presence facts are immutable B003 callback-time read-only snapshots, not assertions about later or current global coverage state:

| Manual file | Callback-time SHA256 | Bytes | Lines | Applicable rows at the callback snapshot |
| --- | --- | ---: | ---: | --- |
| `by-memory/-coverage-report.md` | `53E5093AB017A66DC339462C7D4CB4158DE66337AF301C9F19ABC18713BE30CC` | 1,749,329 | 4,217 | UID0002PB line 1122; UID000118 line 1129; UID0001F9 line 2802; UID0002UX line 3836; no UID0004EA/EF/EL rows. |
| `by-class/-coverage-report.md` | `6C2F877525400CCF9C810DABE8A7EC46133E3551868DACF8DA0AF523BF024FDC` | 225,788 | 622 | UID00001E line 76; UID000038 line 141; UID0000AS line 410. |
| `by-file/-coverage-report.md` | `928A50C72BC4321811657199C33351C8C4D93B519EE40991D58D48EA5895E885` | 129,119 | 316 | UID0000HY line 42; UID0000IG line 60; UID0000MP line 214. |
| `by-type/by-vtable/-coverage-report.md` | `BD8A622DCC9CEBD4A7358964BA2446E0A04D7D9B6C045733BAEA502A5EF46A60` | 65,969 | 142 | UID0003J9 line 40 was observed at `88%`; no handoff replacement was supplied because this report changed neither its score nor route. |

The final B003 callback read-only recheck observed unrelated manual-root drift after the `2026-07-16T09:06:18-04:00` process check. At that callback snapshot, applicable UID0002PB, UID000118, UID00001E, UID000038, UID0000AS, UID0000HY, UID0000IG, UID0000MP, and UID0003J9 row text/positions were unchanged; UID0001F9 was at line 2802; and four unrelated by-memory insertions after that row had moved UID0002UX from historical evidence-time line 3830 through the prior line-3832 checkpoint to line 3836. The exact replacement/insertion bodies below are preserved as immutable no-loss handoff material. This report does not assert whether a supervisor later applied them or where equivalent rows reside in current coverage files.

### by-memory ControlPane constructor replacement

Callback-time handoff instruction: replace the then-observed UID0002PB row at line 1122 with:

```markdown
        - [UID:0002PB][0x004949e0-0x00494a81.ControlPaneConstructor](by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md) 0x004949e0-0x00494a81 | constructor | ControlPane::ControlPane : reconstructable : 89% : very-strong : Exact `ControlPane(unsigned char,const RectBounds *)` source constructor with optional inherited-bounds setup, primary/secondary/tertiary vtable stores, complete protected `+0xf8..+0x104` range/control/state initialization, broad derived-control caller population, exact `0x108` class-size support, and declaration contract in UID000038.
```

### by-memory ButtonControlPane aggregate replacement

Callback-time handoff instruction: replace the then-observed UID000118 row at line 1129 with:

```markdown
    - [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md) 0x00494eb0-0x0049803a | non-emitting mixed split/index | ButtonChoiceControlCore : not_reconstructable : 86% : very-strong : Exact address-ordered button/choice-control executable inventory with all retained source/raw/compiler children and padding; the `0x00494eb0-0x00494f38` ButtonControlPane constructor now has a complete `0x10c` source declaration, exact inherited active/flags/reserved-state and owned selected-byte initialization order, `SetMode(1)`, current key/text interface, and compiler-only empty-destructor/deleting-wrapper split, while unrelated family source-split/helper caveats remain explicit.
```

### by-memory parent replacement

Callback-time handoff instruction: replace the then-observed UID0001F9 row at line 2802 with:

```markdown
    - [UID:0001F9][0x0054b5e0-0x0054bcbd.PrettyButtonControls](by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md) 0x0054b5e0-0x0054bcbd | non-emitting split/index | PrettyButtonControls : not_reconstructable : 88% : very-strong : Exact address-ordered inventory for both PrettyButtonControlPane classes, source-authored constructors/destructors/setters/paint/click children, raw retained bodies, four compiler adjustor thunks, two compiler deleting-destructor clones, and every internal 0xcc pad. UID0004EL is class2 compiler-only deleting output regenerated from the complete 0x12c PrettyButtonControlPane2 declaration and UID0004EB ordinary destructor; the parent remains blank/non-emitting.
```

### by-memory changed child insertions

Callback-time handoff instruction: immediately after that UID0001F9 replacement, insert these affected child rows in address order:

```markdown
        - [UID:0004EA][0x0054b8c0-0x0054b98d.PrettyButtonControlPane2Constructor](by-memory/0x0054b8c0-0x0054b98d.PrettyButtonControlPane2Constructor.md) 0x0054b8c0-0x0054b98d | constructor | PrettyButtonControlPane2Constructor : reconstructable : 89% : very-strong : Source-ready class2 constructor with exact eight-argument ABI, canonical RectBounds reference, four frame ids, two pointer-backed wide strings, adjacent selected/frame-active booleans, protected inherited m_controlFlags/m_reservedControlState body assignments in exact observed order, nullable FunctionObject0 callback initialization, three-view vtable stores, two callers, and exact padding.
        - [UID:0004EF][0x0054baa0-0x0054bb48.PrettyButtonControlPane2OnPaint](by-memory/0x0054baa0-0x0054bb48.PrettyButtonControlPane2OnPaint.md) 0x0054baa0-0x0054bb48 | virtual method | PrettyButtonControlPane2OnPaint : reconstructable : 88% : very-strong : Source-ready OnPaint selecting disabled, frame-active, selected, or normal configured frame ids, using normalized m_visualStateFrameActive, two pointer-backed resource strings, EPFTileContext lookup, and shared RenderTileFrame behavior.
        - [UID:0004EL][0x0054bbc0-0x0054bc3d.PrettyButtonControlPane2ScalarDeletingDestructor](by-memory/0x0054bbc0-0x0054bc3d.PrettyButtonControlPane2ScalarDeletingDestructor.md) 0x0054bbc0-0x0054bc3d | compiler deleting-destructor clone | PrettyButtonControlPane2ScalarDeletingDestructor : not_reconstructable : 92% : very-strong : Exact 125-byte MSVC deleting entry reached by the primary vtable plus +0xa0/+0xa4 adjustor thunks; duplicates UID0004EB teardown, returns complete this, frees only when flag bit 1 is set and bit 4 is clear, and uses the 0x12c bit-4 no-op branch. Source is the virtual class destructor; target emitter/formal remain blank.
```

### by-memory vtable replacement

Callback-time handoff instruction: replace the then-observed UID0002UX row at line 3836 with:

```markdown
        - [UID:0002UX][0x00622378-0x0062241c.PrettyButtonControlPane2VtableData](by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md) 0x00622378-0x0062241c | vtable-data | PrettyButtonControlPane2VtableData : reconstructable : 90% : very-strong : Exact primary/secondary/tertiary PrettyButtonControlPane2 RTTI/vtable data with complete slot/store/boundary evidence, generated-binary marker, source cause in the complete 0x12c class declaration, UID0004EB ordinary destructor, and false/blank UID0004EL compiler deleting clone; no raw arrays are emitted.
```

### by-class replacement

Callback-time handoff instruction: replace the then-observed UID00001E row at line 76 with:

```markdown
- [UID:00001E][ButtonControlPane](by-class/ButtonControlPane.md) : reconstructable : 91% : very-strong : Complete `0x10c` ControlPane-derived button base declaration with exact RectBounds constructor, inline empty virtual destructor, protected inherited-state initialization, one selected-state byte plus natural tail alignment, SetControlSelected transition/invalidation behavior, current HandleKeyOrTextEvent(Event *) override, three-view vtable/compiler-thunk split, and declaration-before-derived-definition route at source position 10.
```

Callback-time handoff instruction: replace the then-observed UID000038 row at line 141 with:

```markdown
- [UID:000038][ControlPane](by-class/ControlPane.md) : reconstructable : 91% : very-strong : Complete `0x108` Pane-derived control base declaration with exact `ControlPane(unsigned char,const RectBounds *)` constructor, inline empty virtual destructor, exact primary slot order through byte-return HitTestPart, public enable/disable/hit-testing API, protected state virtuals, exact protected `+0xf8..+0x104` range/control/state layout, natural tail alignment, complete child routing, and compiler vtable/thunk/wrapper exclusions at source position 10.
```

Callback-time handoff instruction: replace the then-observed UID0000AS row at line 410 with:

```markdown
- [UID:0000AS][PrettyButtonControlPane2](by-class/PrettyButtonControlPane2.md) : reconstructable : 92% : very-strong : Complete `0x12c` ButtonControlPane-derived alternate styled-button declaration with canonical RectBounds constructor, complete ButtonControlPane/StringBase/FunctionObject0 dependencies, public virtual destructor/setters, protected SetState/OnPaint/OnClick overrides, exact four-frame/two-bool/two-StringBase/callback tail layout, protected inherited control-state access, natural alignment, complete child emission at source position 20, normalized m_visualStateFrameActive, ordinary-destructor source, and compiler-only vtable/thunk/deleting-wrapper exclusions.
```

### by-file replacement

Callback-time handoff instruction: replace the then-observed UID0000HY row at line 42 with:

```markdown
- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) : reconstructable : 90% : very-strong : Reusable button/choice-control module under `NexusTK/ui/controls/` with the complete `0x10c` ButtonControlPane declaration before derived definitions, exact inherited-state constructor order, selected-state transition, current key/text EventHandler override, inline empty virtual destructor source cause, compiler deleting/thunk exclusions, and the complete no-loss Text/Image/Selection/Radio/Slider/CheckBox/SelectBox family inventory.
```

Callback-time handoff instruction: replace the then-observed UID0000IG row at line 60 with:

```markdown
- [UID:0000IG][ControlPane](by-file/ControlPane.md) : reconstructable : 90% : very-strong : Base UI-control module under `NexusTK/ui/core/` with the complete `0x108` ControlPane declaration before qualified definitions, exact RectBounds constructor, protected `+0xf8..+0x104` state band, exact primary virtual order through byte-return HitTestPart, enable/disable/hit-testing and state methods, inline empty destructor source cause, broad derived-control caller fanout, and compiler vtable/adjustor/deleting-wrapper exclusions.
```

Callback-time handoff instruction: replace the then-observed UID0000MP row at line 214 with:

```markdown
- [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md) : reconstructable : 90% : very-strong : Styled-button source module under `NexusTK/ui/controls/` with complete base/storage/callback-type-safe PrettyButtonControlPane2 declaration, canonical RectBounds constructor, protected inherited control-state assignments, complete FunctionObject0 visibility for callback deletion, exact constructor/destructor/setter/paint/click children, generated RTTI/vtables, compiler adjustor/deleting-wrapper exclusions, exact executable/read-only split inventories, and class2 declaration-before-definition output. Remaining class1 declaration/scalar-wrapper debt and exact original header/member spelling cap the score.
```

Reason B003 did not apply these rows: manual `-coverage-report.md` files are supervisor-owned and remained outside the authorized implementation-callback write scope. Their later application, replacement, or supersession is external state and is not asserted here.

## Follow-Up Actions

- B003 implementation state: all accepted C01-C28 and R1-R8 items are applied or verified at same-or-greater detail; all scoped validators and the waited generated readback are complete; no B003 implementation item remains.
- Manual coverage handoff state: the exact supervisor-owned replacement/insertion text remains recorded as immutable callback material, and B003 did not edit coverage. This artifact makes no claim that external application is pending, complete, absent, stale, current, or unnecessary.
- Bounded adjacent state: class1 UID0004EM/UID0000AR remain explicit verify-only score caps. Their existence is preserved as a factual boundary, not as a directive from this artifact.
- Lifecycle boundary: B003 performed no report execution, report probe/count/revalidation, move, archive, or lifecycle command. Gate 2, coverage application, execution/revalidation/invalidation, count, path, move, archive, and current manual-coverage state are authoritative only in validator-owned headers/footers, registry, audit, and current files.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: high.
- Remaining uncertainty:
  - exact original header split;
  - exact private/protected labels for methods not directly exercised by this target;
  - exact original protected field spellings despite strong neutral-name evidence;
  - exact compiler version behind the observed deleting-destructor flag ABI.
- The inherited base declaration and access route are no longer open: R7 declares `m_controlFlags` and `m_reservedControlState` protected, R8 and R3 use them directly, and repeated current derived constructors prove that source shape.
- None of the remaining uncertainties changes target range, owner, false/blank disposition, any of the three exact class sizes, formal declarations, or source/compiler split.

## Validator Results

- Implementation callback validator command form:
  - `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`
  - final generated wait used the authorized `--wait-generated` option on `by-file/PrettyButtonControlPane.md`.
- Serial scoped validator results:

| Path | command_id | command_timestamp | Exit / ok | Warnings and side effects |
| --- | ---: | --- | --- | --- |
| `by-class/ControlPane.md` | `000000013697` | `2026-07-16T09:35:44-04:00` | `0 / 1` | Existing `missing_ref_uid=16`; registry score/position/formal updates recorded; generated refresh deferred. |
| `by-file/ControlPane.md` | `000000013700` | `2026-07-16T09:36:07-04:00` | `0 / 1` | Existing `missing_ref_uid=14`; score/reference updates recorded; generated refresh deferred. |
| `by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md` | `000000013701` | `2026-07-16T09:36:35-04:00` | `0 / 1` | No target-specific warning; support prose accepted; generated refresh deferred. |
| `by-class/ButtonControlPane.md` | `000000013705` | `2026-07-16T09:37:32-04:00` | `0 / 1` | Registry score/position/formal/reference updates recorded; generated refresh deferred. |
| `by-file/ButtonControlPane.md` | `000000013709` | `2026-07-16T09:38:40-04:00` | `0 / 1` | Reference update recorded; generated refresh deferred. |
| `by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md` | `000000013712` | `2026-07-16T09:39:33-04:00` | `0 / 1` | Existing `missing_ref_uid=10` for unrelated UID0003NA/UID0003NB links; accepted support/reference updates recorded; generated refresh deferred. |
| `by-memory/0x0054bbc0-0x0054bc3d.PrettyButtonControlPane2ScalarDeletingDestructor.md` | `000000013717` | `2026-07-16T09:40:56-04:00` | `0 / 1` | Target metadata/no-code documentation accepted; no target-specific warning; generated refresh deferred. |
| `by-class/PrettyButtonControlPane2.md` | `000000013721` | `2026-07-16T09:42:25-04:00` | `0 / 1` | Registry score/position/formal/reference updates recorded; generated refresh deferred. |
| `by-memory/0x0054b8c0-0x0054b98d.PrettyButtonControlPane2Constructor.md` | `000000013722` | `2026-07-16T09:43:16-04:00` | `0 / 1` | Exact R3 formal registry update recorded; generated refresh deferred. |
| `by-memory/0x0054baa0-0x0054bb48.PrettyButtonControlPane2OnPaint.md` | `000000013723` | `2026-07-16T09:43:46-04:00` | `0 / 1` | Exact R4 formal registry update recorded; generated refresh deferred. |
| `by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md` | `000000013724` | `2026-07-16T09:44:52-04:00` | `0 / 1` | Score/evidence update recorded; generated refresh deferred. |
| `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md` | `000000013725` | `2026-07-16T09:47:02-04:00` | `0 / 1` | Bounded class2 aggregate synchronization accepted; generated refresh deferred. |
| `by-file/PrettyButtonControlPane.md` | `000000013726` | `2026-07-16T09:49:01-04:00` | `0 / 1` | Score/source-union update recorded; generated refresh deferred. |
| `by-file/PrettyButtonControlPane.md --wait-generated` | `000000013727` | `2026-07-16T09:50:07-04:00` | `0 / 1` | Registry rebuild `1`; generated metadata refresh `280`; children fallback insert `15`; marker-missing `84`; emitter-no-code `150`; generated wait completed. Existing warning: UID00001E used validator fallback because R8 intentionally has no `[[CHILDREN]]` marker; generated declaration/derived ordering was correct at the callback readback. |

- Formal verification:
  - no local `cl.exe`, `clang++.exe`, or `g++.exe` is available, so no compiler command was run;
  - a read-only in-memory scan extracted all eight managed R1-R8 bodies;
  - all eight have balanced braces/parentheses/brackets after removing comments, strings, and `[[CHILDREN]]`;
  - R2 and R7 close their classes before `[[CHILDREN]]`;
  - R2/R7/R8 include complete base/by-value dependencies, and R2 includes complete `FunctionObjects.h` for R6's delete expression; only Event/RectBounds pointer/reference uses remain forward declarations;
  - R3 preserves exact `m_controlFlags -> m_callback -> m_reservedControlState` body order;
  - R7 preserves exact `SetVisualState -> Enable -> Disable -> SetIgnoreHitTesting -> Deactivate -> Activate -> HitTestPart` virtual declaration order;
  - zero formal blocks contain `nullptr`, `override`, `final`, `auto`, casts, smart pointers, raw offset comments, stale `Rect`, `m_constructorFlag`, `m_reservedState`, or `OnKeyPress`.
- R1-R8 destination parity is byte-for-byte exact. Formal body SHA256 values:
  - R1 `CA40B93B6569C6F5127EE922903894943A86E38CB071968DB2A2260DC2E3F396`
  - R2 `1F3CA5664AB3843158FF052CE97228F4CC7824EB95497ED8DC21B16EBD503EDA`
  - R3 `1C042B8C1AC648E664A47C23A6F2AAD0F294889EFBC513E2C3C744DB64B84A8C`
  - R4 `E6A2E74A77D5E2F53C81670B2C051F0D8C84680415459487CE6792DE523A5499`
  - R5 `24CB8A9A7508B3A6E09A2171955095958EA5A268ED3A3750FFE53D9DF492F38C`
  - R6 `300282CC0F38C9FF13AC8D0BA49D693068B31314D1A7EDB76362EC879C6763BE`
  - R7 `B22AD938FDF82F7CD2D8D6EFB65A6DDB21C5C9065A8CCA544D509611231C1E25`
  - R8 `A57914DEC8B51421C3AA7D0219D060F0D9080643D09D426A2449F559D90EDC4D`.
- B003 final waited generated epoch `000000013727`, refreshed `2026-07-16T09:50:07-04:00`:
  - `auto-generated/NexusTK/ui/core/ControlPane.cpp`: SHA256 `430FA2501F3B29126FB515F105F22432D837F07AEED18F4B7B75489A787D0817`, 2,898 bytes, 100 lines. Class declaration starts at line 12 and closes at line 45 before five qualified definitions at that epoch; UID000038 marker count is zero; no raw ABI/vtable code exists. Unrelated existing UID0003N2/UID0003N9 markers remain.
  - `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp`: SHA256 `6528DA4F3F925B50126B217DC54CE81B40FC6C1F141F281ECD167F18A8365140`, 9,985 bytes, 301 lines. Class declaration starts at line 13 and closes at line 35 before derived declarations; the inline constructor, inline destructor, `SetControlSelected` declaration, and `HandleKeyOrTextEvent` declaration each occur once; no speculative qualified ButtonControlPane body exists; UID00001E marker count is zero; no raw ABI/vtable code exists. Unrelated compiler-marker comments and UID0003N8 marker remain.
  - `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp`: SHA256 `90CBD0F10697B442434B4A7BB3E8851421830191AEC16DCC29E11965BA56CDCE`, 9,677 bytes, 270 lines. Class2 declaration starts at line 14 and closes at line 45 before definitions; constructor, destructor, SetSelected, SetCallback, SetState, OnPaint, and OnClick each occur once; UID0004EL title/address/comment count is zero; UID0000AS marker count is zero; UID0002UX R5 marker count is one; no duplicate/wrong-range class2 method or handwritten vtable/RTTI/deleting-wrapper body exists. Class1 UID0004EM/UID0000AR markers remain within the explicit verify-only boundary.
- Later evidence-time read-only external generated epoch `000000013759`, refreshed `2026-07-16T10:03:01-04:00`, was not issued by B003:
  - `ControlPane.cpp`: SHA256 `B04068D588FF338513F61DDE5EA06A61B1B3CE4309DDE9F67B1806EC32CE98E1`, 2,898 bytes, 100 lines;
  - `ButtonControlPane.cpp`: SHA256 `6EA48456FC42C4C6259CFB522618EA1C1B0B17DC8A89D2BA7BC8EE8082F9154B`, 9,985 bytes, 301 lines;
  - `PrettyButtonControlPane.cpp`: SHA256 `F78FC98ACDFC4A3C7D6B46EC4F2399C21C332A5DF3A6A46CECB282CD328BF9A0`, 9,677 bytes, 270 lines;
  - declaration closure, definition/declaration counts, target/marker counts, and no-raw-ABI assertions remain identical to the B003 waited epoch.
- Callback claim/checklist state:
  - C01-C28 are contiguous;
  - actions are `incorporate=23`, `already-present=3`, `reject-invalid=2`;
  - verification states are `applied=23`, `already-present=3`, `excluded-with-reason=2`, `blocked=0`;
  - all 49 checklist rows are checked and no implementation blocker remains.
- Evidence-time MCP availability:
  - database `64c11373`;
  - health `ok`;
  - real bounded target lookup and bytes succeeded.
- Lease/lifecycle result:
  - each ordinary page was leased only for its immediate edit/validator batch and released before the next lease;
  - at callback closure, `tools/leaser/Agents/current_leases.md` had no B003 row;
  - B003 made no manual coverage, generated, tracker, audit, supervisor, validator-state, IDA, report execution/probe/count/revalidation, move, archive, or lifecycle edit/command.

## Changed Files

- Report updated:
  - `tools/leaser/Agents/Agent-B003/research/0004EL-PrettyButtonControlPane2ScalarDeletingDestructor-source-quality.md`
  - preserved the complete accepted research and R1-R8;
  - reconciled C01-C28, recommendations, current state, validators, generated proof, changed files, manual handoff, lifecycle boundary, and checklist to callback-complete truth.
- Changed ordinary destinations:

| Path | B003 callback-time SHA256 | Bytes | Lines |
| --- | --- | ---: | ---: |
| `by-memory/0x0054bbc0-0x0054bc3d.PrettyButtonControlPane2ScalarDeletingDestructor.md` | `62A85D1D74F2629700B4A52F8B43697F6762BBE493743F2EDF1D024FF5C4908C` | 9,936 | 111 |
| `by-class/ControlPane.md` | `3F2C4D1A118EC77BE1062DDEA6AA5F7D6A0810C924B8072BF76DC6108938508B` | 31,940 | 223 |
| `by-file/ControlPane.md` | `A606F54577FADC9CB575E237C3A1905BAA7C1AACB2671A7B815122673D0F5566` | 23,882 | 134 |
| `by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md` | `339CEE16B7EF73DEEE667E5D9B39FE1E7F9C1B425FE4C591A931C8D452AE1457` | 18,292 | 180 |
| `by-class/ButtonControlPane.md` | `614158C93457C785C20EFA8F5D0FBF9CDAEB21D2E0342BDF34A512E55C233C8E` | 21,139 | 180 |
| `by-file/ButtonControlPane.md` | `DE420C29D070CBD002CDF9089AA373EA3AE25715E13556FF6E3639D4C2979F3F` | 31,972 | 179 |
| `by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md` | `954191D5DF775E4499D148CC53AEB858AD3EE0AF79B05A56DDCF50B83ADADAFD` | 30,183 | 184 |
| `by-class/PrettyButtonControlPane2.md` | `96BA72D669C7BD59923EE1324A67A765949AA5CCD56EFC1A036B2F98DAC7838A` | 29,060 | 200 |
| `by-memory/0x0054b8c0-0x0054b98d.PrettyButtonControlPane2Constructor.md` | `D06B67380CFE4653A123E77CB11CCBD76593D81C5201FD75A0FDAE8ACA2C5229` | 11,079 | 95 |
| `by-memory/0x0054baa0-0x0054bb48.PrettyButtonControlPane2OnPaint.md` | `606CCD7F91AB517256BD2F038BC0C7CB3B8F10834103AB3B1CB644FA035DD37D` | 10,731 | 107 |
| `by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md` | `38B830EF5773C1B259650AF6B94D80130D33EC8901F1994F67D323AD464D3F85` | 21,457 | 140 |
| `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md` | `6C63FC159DD07EE174629C4ED0BCB6BD23E3A52AD39BB63113212ACA434EC5C2` | 42,270 | 193 |
| `by-file/PrettyButtonControlPane.md` | `6EFBB622926C441429586519C8E0121B1B20640FE61ABE7939260557DBBFC452` | 50,669 | 206 |

- Verify-only ordinary destinations remained unchanged at B003 callback readback:
  - UID0004EB R6: SHA256 `4D1FCD01C586394B1707AEDBBB8117698785001DCAA077CB3ADD20ED54928CF1`, 4,098 bytes, 44 lines.
  - UID0004EH: SHA256 `E089581E6DA7615ECA84BAB3BA5169839822DADDD4D1886B24980586236D2433`, 1,305 bytes, 18 lines.
  - UID0004EI: SHA256 `89B292298CF30B489F44FA5C580C8E2167EB712C0FE972AE3890A427BEEFCFBC`, 1,303 bytes, 18 lines.
  - UID0004EM: SHA256 `9E4A63F33D83F0FEECE27F2DF0D9B2EAA09B095E09B05B59C6E59BE2A1826936`.
  - UID0000AR: SHA256 `AE5CBBD7FF8AC981824811EC66363AFBD1D7871A9C2E7362CCB096F1CDA30C39`.
  - UID0003J8: SHA256 `794BD02A17A638A5940907329B16BFB67EFF893C69D52932A3D1C4A28E87548F`.
  - UID0003J9: SHA256 `53ECE51191B10A47F3896C3E836AC66030DD02DE66945A22BA845E3EBD6AC3BE`.
  - UID000252: SHA256 `43AB2C777A2C724703371AA75281F590E14924CB330BE4475849CFBE1E6F0EF9`.
  - UID00011Y: SHA256 `E9AC90660817B52B4598257D1F35C0ABCCE47484E85270F5A499B25979E34F4E`.
- Generated C++ was read only and is recorded under `Validator Results`; later evidence-time command-13759 hashes were `B04068D5...98E1`, `6EA48456...154B`, and `F78FC98A...F9A0`.
- Manual coverage edits: zero.
- Generated/tracker/audit/supervisor/validator-state/IDA edits: zero.
- Rename/split/new UID/new ordinary path: none.
- Leases: serial short ordinary leases were used and released; B003 lease count was zero at callback closure.
- Report execution/lifecycle: B003 performed none; later validator-owned lifecycle state is not asserted by this artifact.

Historical pre-callback read-only destination snapshots:

| Path | SHA256 | Bytes | Lines |
| --- | --- | ---: | ---: |
| `by-memory/0x0054bbc0-0x0054bc3d.PrettyButtonControlPane2ScalarDeletingDestructor.md` | `94A1614A6972BF4DD082202EDDFD82F24245849A0931A4748477DB1C4B890F0D` | 2,255 | 27 |
| `by-class/PrettyButtonControlPane2.md` | `CC7942FE7A3E360189C97066E3A611C6F8B4F9D41FDD0F535BC653E4B8A9CC3D` | 22,452 | 120 |
| `by-file/PrettyButtonControlPane.md` | `D3BFA3278D8CCE9EF2EADEFC63E3DC74699C819A838F718876290CA525FA9D1D` | 51,566 | 194 |
| `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md` | `738F1C1FE22DC1CB83F78499015616583A5F62520006511EF12A60FD31FF0868` | 39,980 | 179 |
| `by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md` | `49558F136D38244E7C37BB5AF8DACA89293E541F872AC643F136C719E667CE5E` | 20,517 | 133 |
| `by-memory/0x0054b8c0-0x0054b98d.PrettyButtonControlPane2Constructor.md` | `92471AEF27A6641C0E3F397DB9AF8D69727D2DE80FDA79DC7D70A447EAED1628` | 9,811 | 86 |
| `by-memory/0x0054baa0-0x0054bb48.PrettyButtonControlPane2OnPaint.md` | `A706F2F106BFACCDC809A3CB39603C9AD5B9954FBC462F7A6588352D5A5EA4C4` | 9,844 | 100 |
| `by-memory/0x0054b990-0x0054b9db.PrettyButtonControlPane2DestructorBody.md` | `4D1FCD01C586394B1707AEDBBB8117698785001DCAA077CB3ADD20ED54928CF1` | 4,098 | 44 |
| `by-memory/0x0054bb89-0x0054bb94.PrettyButtonControlPane2SecondaryAdjustorThunk.md` | `E089581E6DA7615ECA84BAB3BA5169839822DADDD4D1886B24980586236D2433` | 1,305 | 18 |
| `by-memory/0x0054bb94-0x0054bb9f.PrettyButtonControlPane2TertiaryAdjustorThunk.md` | `89B292298CF30B489F44FA5C580C8E2167EB712C0FE972AE3890A427BEEFCFBC` | 1,303 | 18 |
| `by-class/ControlPane.md` | `1561FB497A27E3CBCEBF58D73E20D8A542E33BD58E471104FD71A397208F585C` | 27,292 | 154 |
| `by-file/ControlPane.md` | `E3AD27639D711E44B56F2D1B9D82C5ED6DBA850337A3EB913C88402922566068` | 21,751 | 124 |
| `by-class/ButtonControlPane.md` | `8036B64B28E47990BF00007616CDD98CA413B5D39162F4DB2A63CB6538F5A1C9` | 17,750 | 130 |
| `by-file/ButtonControlPane.md` | `A1043BAF23FEB72C3CE10BBC8E8AF6568B530DE17DE5BB92BFFECF7E0F41DF53` | 31,277 | 169 |
| `by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md` | `350427867175729C3A9E6CE10A28ED46FEA798D9C9E8E4B07F6706F9D278DBAD` | 16,238 | 161 |
| `by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md` | `9E7BC48367B7573B794216B2832FA4744505E4AB3C726E9E7F07A3B9B147653C` | 27,598 | 166 |
| `by-memory/0x00617a8c-0x00617b30.ControlPaneVtableData.md` | `794BD02A17A638A5940907329B16BFB67EFF893C69D52932A3D1C4A28E87548F` | 5,249 | 74 |
| `by-type/by-vtable/ControlPaneVtables.md` | `53ECE51191B10A47F3896C3E836AC66030DD02DE66945A22BA845E3EBD6AC3BE` | 4,491 | 63 |
| `by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md` | `43AB2C777A2C724703371AA75281F590E14924CB330BE4475849CFBE1E6F0EF9` | 20,343 | 134 |
| `by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md` | `E9AC90660817B52B4598257D1F35C0ABCCE47484E85270F5A499B25979E34F4E` | 44,849 | 206 |
| `auto-generated/NexusTK/ui/core/ControlPane.cpp` | `AD57088D9C46C54469998A8DA58CA64EE9FACDD9ADB0BE3A54C2E4D04A931CDA` | 2,063 | 62 |
| `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp` | `BC515617A85A72C8FF1C8EDFD427D595809963FA8D5D42D5C40A75C02CF4B59B` | 9,550 | 275 |
| `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` | `0B88A93694B188B682ED4D05F7EC24BE1E11C9E70858D60F69786020835B0203` | 8,707 | 236 |
| `auto-generated/-ag-research-tracker.md` | `E1B9A8AA2B5BD0181E4FD392B0E73119CA4B6660693D37FA6836BE7D3377D9B0` | 1,496,319 | 6,088 |
| `auto-generated/-ag-memory-coverage.md` | `00440E67BEDB7EAE874A5EA5484935F5F56CBBE2F2DF27E96BBFAC227088D1DB` | 1,283,385 | 4,586 |
| `by-memory/-coverage-report.md` | `0F53BD71C344B862EA58BA12BE64ABAECE6D3579BBF13566A8197E506DCB1344` | 1,746,578 | 4,213 |
| `by-class/-coverage-report.md` | `E61DB3F079B38666072FDC89D71737BAB9CFBD85C00A3DC7A836D7DB6E34DCD5` | 225,165 | 622 |
| `by-file/-coverage-report.md` | `A1B73657FCC4F2A5F131C7E3F355E8D007538D0323397DFD7F026F64A59DF882` | 128,817 | 316 |
| `by-type/by-vtable/-coverage-report.md` | `2D8E369A8447F8B31D5AE5A0C5EF79BEC4A85D0192EB789DD6A1D4E77663C444` | 66,052 | 142 |

## Implementation Tracking Checklist

Research and implementation obligations:

- [x] Supervisor validation occurred before implementation: exact accepted report SHA256 `3E06565D8E165FE29206E75E21B2384233C6973458F751B735534CFC666E9F0A`.
- [x] Confirmed the target state, evidence, provenance, and B003 lifecycle boundary before callback edits and reconciled them again after validation.
- [x] Re-read target and every editable/verify-only destination immediately before callback edits and preserved concurrent content.
- [x] Applied C01-C28 claim by claim with legal callback states and destination-specific proof.
- [x] Target `by-memory/0x0054bbc0-0x0054bc3d.PrettyButtonControlPane2ScalarDeletingDestructor.md`: applied `92/94`, owner `0000AS`, false, blank emitter/position/formal, `Nested:0`, exact Item Summary, bytes/hash/ABI/CFG/flag/teardown/xref/no-code/history/score evidence.
- [x] Preserved exact target path/title/range and predecessor/successor padding dispositions; no split/rename/new UID occurred.
- [x] `by-class/ControlPane.md`: applied `91/93`, position `10`, exact R7 declaration, exact `0x108` layout/protected-state/access/source/compiler evidence, class close before `[[CHILDREN]]`, and no raw padding/layout artifacts.
- [x] `by-file/ControlPane.md`: applied `90/92`, preserved the complete current union, and added R7 declaration-before-definition, constructor/empty-destructor, protected-state, generated-route, and compiler-exclusion detail.
- [x] `by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md`: preserved `89/92` and formal/route while adding exact R7 field/signature/size/direct-derived-access support.
- [x] `by-class/ButtonControlPane.md`: applied `91/93`, position `10`, exact R8 declaration, exact `0x10c` layout/constructor/order/access/event/destructor evidence, and no marker-only or future-contract wording.
- [x] `by-file/ButtonControlPane.md`: applied `90/92`, preserved the complete current button/choice union, and added R8 declaration-before-derived-definition, source/compiler split, and current event-interface detail.
- [x] `by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md`: preserved `86/90`, false/blank aggregate metadata/formal/range/inventory and added only the exact R8 Button constructor/declaration/source-contract support.
- [x] `by-class/PrettyButtonControlPane2.md`: applied `92/93`, position `20`, exact R2 declaration with complete Button/StringBase/FunctionObject0 dependencies, exact `0x12c` layout/protected inherited access/source/compiler evidence, class close before `[[CHILDREN]]`, and no raw layout comments/fields.
- [x] `by-memory/0x0054b8c0-0x0054b98d.PrettyButtonControlPane2Constructor.md`: applied R3 exactly, normalized `RectBounds` and `m_visualStateFrameActive`, and assigned protected inherited `m_controlFlags`, owned callback, and protected inherited `m_reservedControlState` in the exact body order without changing score/route/behavior.
- [x] `by-memory/0x0054baa0-0x0054bb48.PrettyButtonControlPane2OnPaint.md`: applied R4 exact field-name normalization only and preserved score/route/behavior.
- [x] `by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md`: applied `90/94`, retained R5/route/range/slots/stores/signature/boundaries, and synchronized target/class source cause.
- [x] `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md`: preserved `88/90`, false/blank, complete inventory/pads/class1 union, and updated only accepted class2 target/layout/source-shape facts.
- [x] `by-file/PrettyButtonControlPane.md`: applied `90/92`, preserved the full concurrent class1/class2/read-only/source union, and recorded class2 declaration-before-definition/no-target-marker route.
- [x] Verified R2/R3/R6/R7/R8 use canonical `RectBounds`, complete base/by-value/delete-expression includes, only Event/RectBounds pointer/reference-safe forward declarations, and no stale source-facing `Rect`, `m_constructorFlag`, `m_reservedState`, or `OnKeyPress`.
- [x] Verified direct protected field access is used exactly where proved; no duplicate derived fields, invented setters, raw offset casts, or private inaccessible state were added.
- [x] Verified [UID:0004EB] R6/metadata/prose unchanged at same-or-greater detail.
- [x] Verified [UID:0004EH]/[UID:0004EI] false/blank thunk pages unchanged at same-or-greater detail.
- [x] Verified UID0004EC/ED/EE/EG and Pane/Event/RectBounds/StringBase/FunctionObject0/operator-delete dependencies unchanged with no direct contradiction.
- [x] Verified UID0003J8/UID0003J9/UID000252/UID00011Y remain same-or-greater and required no edit.
- [x] Kept UID0004EM/UID0000AR class1 work verify-only and out of callback edit scope.
- [x] Preserved all historical assumptions, rejected alternatives, negative evidence, exact binary facts, and source/compiler distinctions at report-level detail.
- [x] Preserved Wave2/Wave3/simroot mentions only as explicitly superseded search/history provenance and did not use them as current evidence.
- [x] Confirmed third-party import handling is not applicable: this target is NexusTK-owned class/compiler output and no `third_party_embeds/...` directive or staged third-party source is involved.
- [x] Retained exact supervisor-owned by-memory replacements/insertions for UID0002PB, UID000118, UID0001F9, UID0004EA, UID0004EF, UID0004EL, and UID0002UX; B003 did not edit manual coverage.
- [x] Retained exact supervisor-owned by-class replacements for UID00001E, UID000038, and UID0000AS; B003 did not edit manual coverage.
- [x] Retained exact supervisor-owned by-file replacements for UID0000HY, UID0000IG, and UID0000MP; preserved by-vtable UID0003J9 unchanged after read-only no-change proof.
- [x] Leased only one ordinary file immediately before editing, reread after lease, scoped-validated, and released immediately before the next file.
- [x] Ran one scoped validator per changed ordinary page and recorded command, command_id, timestamp, exit, ok, warnings, and side effects.
- [x] Ran the authorized waited validation/readback at B003 command `000000013727` and recorded the later evidence-time external command `000000013759` hashes/bytes/lines plus unchanged semantic assertions for all three source modules.
- [x] Proved generated `ControlPane` declaration closes before its definitions, UID000038 Empty Emitter Marker is absent, and no raw ABI/vtable code exists.
- [x] Proved generated `ButtonControlPane` declaration closes before its/derived definitions, UID00001E marker-only source symptom is absent, R8 inline constructor/destructor and noninline method declarations occur once without speculative duplicate bodies, and no raw ABI/vtable code exists.
- [x] Proved generated class2 declaration closes before definitions, seven class2 definitions occur once, UID0004EL occurs zero times, UID0000AS Empty Emitter Marker is absent, UID0002UX marker occurs once, and no raw ABI/vtable code exists.
- [x] Updated `Finalized Report / Current Recommendation`, `Current Target State`, C01-C28 ledger, Validator Results, Changed Files, Follow-Up Actions, manual handoff state, and this checklist to durable callback truth.
- [x] Confirmed zero B003 leases at callback closure and zero prohibited execution/lifecycle/manual-generated/manual-coverage actions by B003.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support details incorporated without compression or concurrent-content loss.
- [x] C01-C28 updated to legal terminal callback states with exact destination/validator/generated proof.
- [x] R1-R8 byte-for-byte destination parity verified.
- [x] Metadata/score/owner/emitter/position/reconstructable/C++ changes applied or explicitly excluded with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions closed or retained only as evidence-backed score caps.
- [x] Validators and waited generated proof recorded.
- [x] Manual supervisor-owned coverage handoff preserved without B003 editing coverage or asserting later application state.
- [x] All accepted implementation items reached terminal applied/already-present/excluded states; none was blocked at callback completion.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000013785","destination_path":"executed-b-agent-research/B003/0004EL-PrettyButtonControlPane2ScalarDeletingDestructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0004EL-PrettyButtonControlPane2ScalarDeletingDestructor-source-quality.md","timestamp":"2026-07-16T10:43:22-04:00","uid":"0004EL"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
