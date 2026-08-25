** TARGET-REPORT-UID:0001C1 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001C1 SharedListPaneScalarDeletingDestructor Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md) as a reviewed, non-emitting MSVC scalar deleting destructor wrapper.
- Final disposition: `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank formal C++.
- Required action: update the target and support docs to resolve the current score rationale blockers: exact vtable family names, thunk routes, helper names, complete-object size `0x15c` / 348 (Verified with `int_convert.py`), and source declaration responsibilities.
- Score recommendation: raise target `COMPLETION` from `82` to `86`; keep `CONFIDENCE` at `90`.
- Confidence: strong for the no-code/compiler-glue classification and shared vtable set. Current-session IDA MCP was unavailable, so confidence should not be raised beyond the existing live-MCP-backed `90`.

## Target

- Target UID: `0001C1`.
- Target path: `source-3/project-documentation/by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md`.
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0001C1-SharedListPaneScalarDeletingDestructor-source-quality.md`.
- Current target metadata: `COMPLETION:82`, `CONFIDENCE:90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++.
- Current coverage row: ignored, `82%`, strong.
- Assignment context: B001 report-only source-quality/heuristic research. Target/support by-* docs and `by-memory/-coverage-report.md` were not edited.

## Executive Recommendation

The wrapper is exact no-code compiler glue. It is the shared first-slot scalar deleting destructor target for the `ClientItemMenuItemList`, `ServerSpellMenuItemList`, and `ClientSpellMenuItemList` primary vtables, with secondary and tertiary vtable routes through [UID:0001BY][0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks](by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md). It has no ordinary direct callers and contains no class-specific teardown beyond calling the shared `ListPane` non-deleting destructor body at `0x004f3b60`.

Do not reframe this as `ClientItemMenuItemList::~ClientItemMenuItemList`, `ServerSpellMenuItemList::~ServerSpellMenuItemList`, `ClientSpellMenuItemList::~ClientSpellMenuItemList`, or `ListPane::~ListPane` source code. Source reconstruction should express the ordinary/implicit destructors of the three derived list classes plus the real `ListPane::~ListPane()` body. A compatible compiler should regenerate and may fold the scalar deleting destructor wrapper and adjustor thunks.

The source-quality name direction is:

- Source-facing helper name for `0x004f3b60`: `ListPane::~ListPane()` / `ListPane` non-deleting destructor body.
- Binary wrapper name for `0x00520c20`: keep `SharedListPaneScalarDeletingDestructor` as the current doc title/search name, but describe it as a descriptive binary-artifact label, not an original C++ method name. If a later rename pass wants a more precise descriptive title, `SharedMenuItemListScalarDeletingDestructor` is the best alias, but a file rename is not required for this report's score recommendation.
- Binary thunk names for `0x00520ad1` and `0x00520adc`: `SharedClientSpellMenuListDestructorThunks`, with per-class vtable mapping documented.
- Delete helper `0x004f4ac0`: [UID:000197][0x004f4ac0-0x004f4b00.OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md), the MemoryMan-backed global `operator delete` wrapper.
- Guard helper `0x0041b6a0`: MSVC `@_guard_check_icall_nop@4`, a one-byte `retn` runtime/compiler no-op documented in `by-memory/-ignored.md`.

## Supervisor Active Recheck

- The user explicitly assigned this B001 report-only task after the completed `00019L` report and told B001 not to edit target/support docs or `by-memory/-coverage-report.md`.
- Existing report `00019L-EnsureLoginDialogPane-source-quality.md` was left in place and was not modified.
- This target does not require split repair. Its range is already an exact `0x3b` / 59-byte (Verified with `int_convert.py`) function, with the paired adjustor-thunk page and surrounding mixed destructor-island page already split.
- Current-session IDA MCP recheck failed:

```text
IDA_MCP_UNAVAILABLE: Unable to connect to the remote server
```

Existing by-* docs record multiple live IDA MCP passes for the same function, thunks, vtables, and helper callees. This report therefore relies on those embedded live-MCP records plus local documentation cross-checks and keeps confidence at `90`.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best-supported direction | Rejected alternatives / impact |
| --- | --- | --- | --- |
| No-code/compiler-glue classification | Target doc records `lookup_funcs 0x00520c20` size `0x3b`, no function at `0x00520c5b`, no ordinary callers, only code refs from `0x00520ad1`/`0x00520adc` and primary vtable refs. Sibling [UID:0000ZR] has same scalar deleting wrapper shape and is `RECONSTRUCTABLE:FALSE`. | Keep `RECONSTRUCTABLE:FALSE`, no owner/emitter, blank C++. This is MSVC scalar deleting destructor ABI output. | Reject hand-authored C++ for this page. Reject treating the wrapper as row/menu behavior. Score can rise because no-code proof is now source-quality, not because it becomes reconstructable. |
| Source-facing method name/signature | The function takes `this` in `ecx`, a scalar delete `flags` argument on stack, returns original `this`, and is reached only through vtables/thunks. | No source-facing method should be emitted for this range. In source notes, describe the compiler shape as `void * __thiscall scalar_deleting_destructor(Class *this, unsigned int flags)` only as ABI evidence. | Reject names like `ClientItemMenuItemList::~ClientItemMenuItemList(unsigned int)` or a user-authored `SharedListPaneScalarDeletingDestructor(...)`; those are not source methods. |
| Owner/emitter routing | Primary vtable refs are exactly `0x0061f0a4`, `0x0061f204`, and `0x0061f364`; secondary/tertiary refs route through thunks at `0x00520ad1` and `0x00520adc`. The three owning classes already have file routes: [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) and [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md). | Keep target owner `NONE` and blank emitters. The classes emit their ordinary methods/destructor declarations; the wrapper does not emit. | Reject assigning the wrapper to ItemMenuDialogs only. It is shared with SpellMenuDialogs. Reject multiple emitters because the item is not reconstructable source, unlike pooled source constants. |
| Vtable consumer breadth | [UID:00031Z][ItemMenuDialogVtables](by-type/by-vtable/ItemMenuDialogVtables.md), [UID:00031X][SpellMenuDialogVtables](by-type/by-vtable/SpellMenuDialogVtables.md), and [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) map the table bases. [UID:0001BY] records the secondary/tertiary thunk data refs. | Document the full route table in the target and support docs: `ClientItemMenuItemList`, `ServerSpellMenuItemList`, `ClientSpellMenuItemList`, primary plus secondary/tertiary slots. | Reject the current target score-rationale blocker that the class-vtable names are unresolved. They are resolvable from existing support docs. |
| `0x004f3b60` helper role/name | [UID:0003TZ][0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor](by-memory/0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor.md) says `0x004f3b60-0x004f3ba5` is a `0x45` / 69-byte (Verified with `int_convert.py`) non-deleting destructor/base cleanup. It restores the three `ListPane` vtables, deletes the two owned list objects at `+0x130` and `+0x138`, and chains to `ScrollablePane` teardown. | Source-facing name should be `ListPane::~ListPane()` or `ListPane` non-deleting destructor body. Use raw `sub_4F3B60` only as an evidence alias. | Reject generated ownership of `0x004f3b60` as `ClientItemMenuItemList::~ClientItemMenuItemList`; existing class/file docs already flag that as too narrow. |
| Delete helper `0x004f4ac0` | [UID:000197][OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md) confirms a MemoryMan-backed global delete wrapper: `GetMemoryMan` then `FreeBufferMemory`, with broad scalar-dtor fanout. | Name it `OperatorDeleteWrapper` / global `operator delete` wrapper. | Reject generic "delete helper" as final wording in score-critical sections. |
| Guard helper `0x0041b6a0` | `by-memory/-ignored.md` records `0x0041b6a0-0x0041b6a1` as `@_guard_check_icall_nop@4`, single `retn`, compiler/runtime helper. Coverage report and many vtable docs use the same interpretation. | Document the `flags & 4` branch as compiler/runtime guard/sized-delete support. It passes `this` and object size, then returns. | Reject any source feature behavior or callback interpretation for this branch. |
| Object size `0x15c` | Target and sibling [UID:0001C2][ServerItemMenuItemListScalarDeletingDestructor](by-memory/0x00520ce0-0x00520d47.ServerItemMenuItemListScalarDeletingDestructor.md) use `0x15c`. `int_convert.py` verifies `0x15c` as 348. Constructors for the three classes write common context offsets up through `+0x158` and use the same `ListPane` triple-vtable layout at `+0x00/+0xa0/+0xa4`. | Interpret as the compiler-emitted complete-object size for this menu-item-list class family, not a field offset. It likely reflects a common 348-byte concrete object layout for the shared wrapper users. | Reject treating `0x15c` as `ListPane` base size or a member field. It appears only as a scalar/delete path immediate, not as normal list-row state. |
| Adjustor thunk offsets | [UID:0001BY] records `0x00520ad1` subtracts `0xa0` / 160 and `0x00520adc` subtracts `0xa4` / 164 (Verified with `int_convert.py`) before jumping to `0x00520c20`. Vtable docs show secondary and tertiary table bases matching those offsets. | Document secondary route as `this -= 0xa0`, tertiary route as `this -= 0xa4`. | Reject unknown/broad thunk consumer wording. The consumers are known enough for target/source-quality docs. |
| Final C++ readiness | Target is `RECONSTRUCTABLE:FALSE`, no emitter route, and is compiler-generated. By-structure allows C++ only for reconstructable targets with nonblank valid emitters and `(completion + confidence) / 2 > 85`. | Formal C++ must stay blank. Source responsibility belongs to class declarations and `ListPane::~ListPane()`. | Reject first-draft C++ insertion for this target. This is a hard no-code proof, not a passive blocker. |

## Evidence Standards Used

- Existing live IDA evidence in target/support docs was treated as direct documentation evidence because current-session MCP was down.
- Existing generated labels were treated as leads only. In particular, generated `ClientItemMenuItemList` ownership for `0x004f3b60` and `0x00520c20` was rejected because vtable and caller fanout contradict exclusive ownership.
- Number conversions were performed with `source-3/project-documentation/tools/int_convert.py`:
  - `0x15c` = 348.
  - `0x3b` = 59.
  - `0xb` = 11.
  - `0xa0` = 160.
  - `0xa4` = 164.
  - `0x45` = 69.
- Negative evidence is central: no ordinary callers, no class-specific vtable restores, no singleton/global cleanup, and no row/menu behavior inside `0x00520c20`.

## IDA MCP / Documentation Facts

### Function and range facts

| Address / range | Fact |
| --- | --- |
| `0x00520c20-0x00520c5b` | IDA-modeled `sub_520C20`, size `0x3b` / 59 bytes (Verified with `int_convert.py`), end-exclusive at `0x00520c5b`. |
| `0x00520ad1-0x00520adc` | Adjustor thunk, size `0xb` / 11 bytes (Verified with `int_convert.py`), subtracts `0xa0` / 160 from `ecx`, jumps to `0x00520c20`. |
| `0x00520adc-0x00520ae7` | Adjustor thunk, size `0xb` / 11 bytes (Verified with `int_convert.py`), subtracts `0xa4` / 164 from `ecx`, jumps to `0x00520c20`. |
| `0x004f3b60-0x004f3ba5` | `ListPane` non-deleting destructor/base cleanup, size `0x45` / 69 bytes (Verified with `int_convert.py`). |
| `0x004f4ac0-0x004f4b00` | `OperatorDeleteWrapper`, MemoryMan-backed global delete wrapper. |
| `0x0041b6a0-0x0041b6a1` | `@_guard_check_icall_nop@4`, MSVC one-byte runtime/helper no-op. |

### Direct xref / caller inventory

| Route | Evidence | Meaning |
| --- | --- | --- |
| `0x00520ad7 -> 0x00520c20` | Code ref from `sub_520AD1`. | Secondary `this - 0xa0` destructor route. |
| `0x00520ae2 -> 0x00520c20` | Code ref from `sub_520ADC`. | Tertiary `this - 0xa4` destructor route. |
| `0x0061f0a4 -> 0x00520c20` | Primary vtable data ref. | `ClientItemMenuItemList` primary destructor slot. |
| `0x0061f204 -> 0x00520c20` | Primary vtable data ref. | `ServerSpellMenuItemList` primary destructor slot. |
| `0x0061f364 -> 0x00520c20` | Primary vtable data ref. | `ClientSpellMenuItemList` primary destructor slot. |
| no ordinary callers | Target doc records `callers 0x00520c20` has no ordinary direct callers. | Confirms vtable/thunk-only ABI glue. |

### Vtable route map

| Class | Source owner | Primary route | Secondary route | Tertiary route |
| --- | --- | --- | --- | --- |
| `ClientItemMenuItemList` | [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) | `0x0061f0a4 -> 0x00520c20` | `0x0061f12c -> 0x00520ad1` (`this -= 0xa0`) | `0x0061f15c -> 0x00520adc` (`this -= 0xa4`) |
| `ServerSpellMenuItemList` | [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md) | `0x0061f204 -> 0x00520c20` | `0x0061f28c -> 0x00520ad1` (`this -= 0xa0`) | `0x0061f2bc -> 0x00520adc` (`this -= 0xa4`) |
| `ClientSpellMenuItemList` | [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md) | `0x0061f364 -> 0x00520c20` | `0x0061f3ec -> 0x00520ad1` (`this -= 0xa0`) | `0x0061f41c -> 0x00520adc` (`this -= 0xa4`) |

### Behavior facts

The target wrapper performs only compiler destructor support:

1. Save original `this`.
2. Call `ListPane::~ListPane()` non-deleting cleanup at `0x004f3b60`.
3. If `flags & 1` is clear, return original `this`.
4. If `flags & 1` is set and `flags & 4` is clear, call `OperatorDeleteWrapper` at `0x004f4ac0`, then return original `this`.
5. If `flags & 4` is set, pass `this` and complete-object size `0x15c` / 348 (Verified with `int_convert.py`) to the `@_guard_check_icall_nop@4` path at `0x0041b6a0`, then return original `this`.

There are no class-specific vtable resets, no singleton clears, no row/text/packet behavior, and no list-menu owner state writes in this range. That distinguishes it from [UID:0001C2][ServerItemMenuItemListScalarDeletingDestructor](by-memory/0x00520ce0-0x00520d47.ServerItemMenuItemListScalarDeletingDestructor.md), which restores `ServerItemMenuItemList` vtables and closes `g_pItemHelpPane` before calling the same `ListPane` cleanup.

## Documentation Evidence And Current Status

- Target [UID:0001C1] already records exact range, scalar-delete flag behavior, callee set, thunk code refs, primary vtable refs, no ordinary callers, and broad `0x004f3b60` fanout.
- [UID:0001BY] records both adjustor thunks, `0xb` sizes, `-0xa0` and `-0xa4` deltas, and the six secondary/tertiary vtable data refs.
- [UID:0003TZ] resolves the target's `0x004f3b60` callee as `ListPane` non-deleting destructor/base cleanup.
- [UID:000197] resolves the `0x004f4ac0` callee as MemoryMan-backed `operator delete`.
- `by-memory/-ignored.md` resolves `0x0041b6a0` as MSVC `@_guard_check_icall_nop@4`.
- [UID:00031Z], [UID:00031X], and [UID:0001Y5] identify the item/spell menu-list vtable families.
- [UID:00002Q], [UID:0000D4], and [UID:00002S] confirm the three class owners and source file routes.
- [UID:0000KF] and [UID:0000O2] already warn not to duplicate shared list-pane destructor glue in each item/spell menu source body.

## Ranked Ownership / Placement Analysis

### 1. No owner / non-emitting compiler artifact - selected

- Evidence for: only vtable/thunk reachability, no ordinary callers, no class-specific body, shared by three concrete classes across two source files, standard MSVC scalar deleting destructor flag pattern, calls only base cleanup/delete/guard helpers.
- Evidence against: primary vtable slots are owned by real classes, so the wrapper is meaningful binary evidence.
- Decision: selected. The classes and `ListPane` own the source responsibilities; this exact wrapper remains `CANONICAL_OWNER:NONE`, blank emitters, `RECONSTRUCTABLE:FALSE`.

### 2. Assign to `ClientItemMenuItemList` / `ItemMenuDialogs` - rejected

- Evidence for: current generated owner wording points at `ClientItemMenuItemList`; one primary vtable ref is `0x0061f0a4`.
- Evidence against: two other primary vtable refs are spell-menu list classes, and both thunk docs and vtable docs show shared routing. The wrapper also lacks client-item-specific state cleanup.
- Decision: rejected as stale generated owner pollution.

### 3. Assign to `SpellMenuDialogs` - rejected

- Evidence for: two of the three primary vtable refs are spell list classes.
- Evidence against: `ClientItemMenuItemList` also uses the wrapper. No single spell source owns all vtable consumers.
- Decision: rejected for the same reason as item-only ownership.

### 4. Assign to `ListPane` - rejected as owner, accepted as callee/source dependency

- Evidence for: the wrapper calls `ListPane::~ListPane()` non-deleting cleanup and shares the ListPane triple-vtable offset pattern.
- Evidence against: the wrapper's vtable refs are not `ListPane` vtable refs; they are concrete menu-list primary slots and concrete secondary/tertiary thunk routes. `ListPane` owns `0x004f3b60`, not `0x00520c20`.
- Decision: reject owner assignment, but docs should name the callee as `ListPane::~ListPane()`.

### 5. Multiple emitters with `CANONICAL_OWNER:NONE` - rejected

- Evidence for: the wrapper is used from multiple source contexts.
- Evidence against: by-structure multiple-emitter behavior is for reconstructable shared source items such as pooled constants. This wrapper is compiler-generated and should not emit in any source file.
- Decision: keep emitters blank.

## Source Declaration Responsibilities

No formal source should be placed in the target page. The source-bearing responsibilities are:

- [UID:0003TZ] / `ListPane`: emit or document the real `ListPane::~ListPane()` behavior. It destroys owned `List` objects at `+0x130` and `+0x138`, restores base vtables, and chains to `ScrollablePane`.
- [UID:00002Q] / `ClientItemMenuItemList`: source may rely on an implicit/empty virtual destructor or a simple ordinary destructor declaration if final class layout requires one. No class-specific body is proven here.
- [UID:0000D4] / `ServerSpellMenuItemList`: same implicit/empty destructor direction.
- [UID:00002S] / `ClientSpellMenuItemList`: same implicit/empty destructor direction.
- Compiler/linker: regenerate/fold the scalar deleting destructor at `0x00520c20` and adjustor thunks at `0x00520ad1`/`0x00520adc`.

Conceptual source-shape note for support docs only, not for the target C++ block:

```cpp
// Do not insert into UID:0001C1. This is the source responsibility that
// causes equivalent compiler ABI glue, not the ABI glue itself.
class ClientItemMenuItemList : public ListPane {
public:
    virtual ~ClientItemMenuItemList(); // implicit or empty; no unique teardown observed
};

class ServerSpellMenuItemList : public ListPane {
public:
    virtual ~ServerSpellMenuItemList(); // implicit or empty; no unique teardown observed
};

class ClientSpellMenuItemList : public ListPane {
public:
    virtual ~ClientSpellMenuItemList(); // implicit or empty; no unique teardown observed
};
```

If final reconstruction can keep these destructors implicit while still producing the required vtables, that is preferable to adding empty out-of-line bodies. The important policy is that UID `0001C1` itself must not emit a hand-authored `scalar_deleting_destructor` function.

## Recommended Target Changes

### Metadata

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Target body additions/replacements

Add or replace the current unresolved-score material with this exact content, adjusted only for local formatting:

```markdown
## Source-Quality Classification

This page is exact MSVC scalar deleting destructor glue, not a source-authored NexusTK method. Source reconstruction should express the ordinary/implicit destructors of `ClientItemMenuItemList`, `ServerSpellMenuItemList`, and `ClientSpellMenuItemList`, plus the real `ListPane::~ListPane()` body at `0x004f3b60`; the compiler/linker should regenerate or fold this wrapper and the paired adjustor thunks.

The current generated owner label `ClientItemMenuItemList` is too narrow. The wrapper is shared by three primary vtable slots:

| Class | Primary destructor slot | Secondary thunk slot | Tertiary thunk slot |
| --- | --- | --- | --- |
| `ClientItemMenuItemList` | `0x0061f0a4 -> 0x00520c20` | `0x0061f12c -> 0x00520ad1` (`this -= 0xa0` / 160, Verified with `int_convert.py`) | `0x0061f15c -> 0x00520adc` (`this -= 0xa4` / 164, Verified with `int_convert.py`) |
| `ServerSpellMenuItemList` | `0x0061f204 -> 0x00520c20` | `0x0061f28c -> 0x00520ad1` (`this -= 0xa0` / 160, Verified with `int_convert.py`) | `0x0061f2bc -> 0x00520adc` (`this -= 0xa4` / 164, Verified with `int_convert.py`) |
| `ClientSpellMenuItemList` | `0x0061f364 -> 0x00520c20` | `0x0061f3ec -> 0x00520ad1` (`this -= 0xa0` / 160, Verified with `int_convert.py`) | `0x0061f41c -> 0x00520adc` (`this -= 0xa4` / 164, Verified with `int_convert.py`) |

`0x004f3b60` is the `ListPane` non-deleting destructor body, not a private client-item/spell-list method. [UID:0003TZ][0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor](by-memory/0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor.md) records that it restores the three `ListPane` vtable views, deletes the owned list objects at `+0x130` and `+0x138`, and chains to `ScrollablePane` teardown.

The `flags & 4` branch passes complete-object size `0x15c` / 348 bytes (Verified with `int_convert.py`) and `this` to the MSVC `@_guard_check_icall_nop@4` path at `0x0041b6a0`. Treat `0x15c` as the compiler-emitted complete-object size for this shared menu-item-list layout, not as a `ListPane` field or allocation helper argument.
```

Replace the current score rationale with:

```markdown
| Score | Rationale |
| --- | --- |
| Completion `86` | Exact function boundary, thunk relation, per-class primary/secondary/tertiary vtable routes, no ordinary callers, scalar-delete flag behavior, helper identities (`ListPane::~ListPane`, `OperatorDeleteWrapper`, `@_guard_check_icall_nop@4`), complete-object size `0x15c` / 348 (Verified with `int_convert.py`), shared cleanup fanout, source-declaration responsibility, and non-emitting rebuild handling are documented. Completion stays below final-audit levels because this page intentionally remains a compiler-generated binary artifact and current-session IDA MCP was unavailable for a fresh raw-byte/decompile replay. |
| Confidence `90` | Existing live IDA evidence strongly verifies the boundary, wrapper behavior, vtable-only reachability, and shared/compiler-generated disposition. Confidence remains below 95 because the target is no-code ABI glue, not an original source method, and this report could not run a current live IDA recheck. |
```

## Recommended Support-Doc Updates

### `by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md`

Add a route table after the Evidence section:

```markdown
## Vtable Route Map

| Class | Secondary thunk route | Tertiary thunk route | Primary scalar target |
| --- | --- | --- | --- |
| `ClientItemMenuItemList` | `0x0061f12c -> 0x00520ad1` (`this -= 0xa0` / 160, Verified with `int_convert.py`) | `0x0061f15c -> 0x00520adc` (`this -= 0xa4` / 164, Verified with `int_convert.py`) | `0x0061f0a4 -> 0x00520c20` |
| `ServerSpellMenuItemList` | `0x0061f28c -> 0x00520ad1` (`this -= 0xa0` / 160, Verified with `int_convert.py`) | `0x0061f2bc -> 0x00520adc` (`this -= 0xa4` / 164, Verified with `int_convert.py`) | `0x0061f204 -> 0x00520c20` |
| `ClientSpellMenuItemList` | `0x0061f3ec -> 0x00520ad1` (`this -= 0xa0` / 160, Verified with `int_convert.py`) | `0x0061f41c -> 0x00520adc` (`this -= 0xa4` / 164, Verified with `int_convert.py`) | `0x0061f364 -> 0x00520c20` |

These are compiler-generated secondary/tertiary adjustor routes into [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md). They should be regenerated from the class inheritance/vtable layout and ordinary destructor declarations, not hand-authored as source methods.
```

### `by-memory/0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor.md`

Add to Source Placement:

```markdown
Source-facing name for `0x004f3b60` should be `ListPane::~ListPane()` / `ListPane` non-deleting destructor body. Shared scalar deleting destructor wrappers such as [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md) call this cleanup after their concrete-list destructor routing, but they do not make `0x004f3b60` private to any one derived list class.
```

### `by-type/by-vtable/ItemMenuDialogVtables.md`

Add under Reconstruction Notes:

```markdown
Destructor slot detail for `ClientItemMenuItemList`: primary vtable base `0x0061f0a4` routes to [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md), secondary base `0x0061f12c` routes to [UID:0001BY][0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks](by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md) thunk `0x00520ad1` (`this -= 0xa0` / 160, Verified with `int_convert.py`), and tertiary base `0x0061f15c` routes to thunk `0x00520adc` (`this -= 0xa4` / 164, Verified with `int_convert.py`). This is shared compiler-generated destructor glue, not an item-menu handwritten source function.
```

### `by-type/by-vtable/SpellMenuDialogVtables.md`

Add under Reconstruction Notes:

```markdown
Destructor slot detail for the spell menu item-list classes: `ServerSpellMenuItemList` primary base `0x0061f204` and `ClientSpellMenuItemList` primary base `0x0061f364` route to [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md). The secondary bases `0x0061f28c` and `0x0061f3ec` route to [UID:0001BY][0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks](by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md) thunk `0x00520ad1` (`this -= 0xa0` / 160, Verified with `int_convert.py`), and the tertiary bases `0x0061f2bc` and `0x0061f41c` route to thunk `0x00520adc` (`this -= 0xa4` / 164, Verified with `int_convert.py`). Do not duplicate this compiler glue in `SpellMenuDialogs.cpp`; reconstruct ordinary class declarations/destructors and the shared `ListPane` base cleanup.
```

### `by-class/ClientItemMenuItemList.md`

Add to Evidence Notes or Method Notes:

```markdown
Destructor routing is shared compiler output: primary vtable `0x0061f0a4` routes to [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md), secondary `0x0061f12c` routes to [UID:0001BY][0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks](by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md) thunk `0x00520ad1`, and tertiary `0x0061f15c` routes to thunk `0x00520adc`. The shared wrapper's `0x15c` / 348-byte size immediate (Verified with `int_convert.py`) is the complete-object size for this menu-item-list layout, not a row field. Source reconstruction should use an ordinary implicit/empty destructor plus `ListPane::~ListPane()`, not a hand-authored scalar deleting destructor.
```

### `by-class/ServerSpellMenuItemList.md`

Add to Evidence Notes:

```markdown
Destructor routing is shared compiler output: primary vtable `0x0061f204` routes to [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md), secondary `0x0061f28c` routes to [UID:0001BY][0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks](by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md) thunk `0x00520ad1`, and tertiary `0x0061f2bc` routes to thunk `0x00520adc`. The shared wrapper calls `ListPane::~ListPane()` at `0x004f3b60` and uses complete-object size `0x15c` / 348 (Verified with `int_convert.py`) on the compiler guard/sized-delete path. It should not be emitted as a `ServerSpellMenuItemList` source method.
```

### `by-class/ClientSpellMenuItemList.md`

Add to Evidence Notes:

```markdown
Destructor routing is shared compiler output: primary vtable `0x0061f364` routes to [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md), secondary `0x0061f3ec` routes to [UID:0001BY][0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks](by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md) thunk `0x00520ad1`, and tertiary `0x0061f41c` routes to thunk `0x00520adc`. The shared wrapper calls `ListPane::~ListPane()` at `0x004f3b60` and uses complete-object size `0x15c` / 348 (Verified with `int_convert.py`) on the compiler guard/sized-delete path. It should not be emitted as a `ClientSpellMenuItemList` source method.
```

### `by-file/ItemMenuDialogs.md`

Add to Ownership Notes:

```markdown
For `ClientItemMenuItemList`, destructor source responsibility is an ordinary implicit/empty class destructor and the inherited `ListPane::~ListPane()` cleanup. [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md) is shared compiler-generated ABI glue also used by spell menu item-list vtables, so it must not be imported into `ItemMenuDialogs.cpp` as handwritten source.
```

### `by-file/SpellMenuDialogs.md`

Replace or extend the existing shared-glue note with:

```markdown
Do not duplicate the shared list-pane destructor glue in each spell list source body. `ServerSpellMenuItemList` and `ClientSpellMenuItemList` primary destructor slots route to [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md), with secondary/tertiary routes through [UID:0001BY][0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks](by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md). The wrapper calls the `ListPane::~ListPane()` non-deleting cleanup at `0x004f3b60` and carries complete-object size `0x15c` / 348 (Verified with `int_convert.py`) for compiler delete support. Source should reconstruct ordinary class destructors/declarations and let the compiler regenerate equivalent ABI glue.
```

### `by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md`

Update the neighboring-glue row for `0x00520c20-0x00520c5b` to link the exact target:

```markdown
| `0x00520c20-0x00520c5b` | Shared client item/spell menu-list scalar deleting destructor; calls `ListPane::~ListPane()` at `0x004f3b60`, handles scalar-delete flags, optional `OperatorDeleteWrapper`, and guard/sized-delete object size `0x15c` / 348 (Verified with `int_convert.py`) | [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md). |
```

### `by-memory/-ignored.md`

The ledger already has a target entry at `0x00520c20-0x00520c5b`. Update it with the stronger helper/object-size wording:

```markdown
- `0x00520c20-0x00520c5b` - shared client-item/spell menu list scalar deleting destructor glue.
  - Why ignored: compiler-generated/shared MSVC scalar deleting destructor wrapper over the common `ListPane::~ListPane()` non-deleting cleanup path; not handwritten menu-list row, action, packet, or draw behavior.
  - Evidence: [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md) records the `0x3b` / 59-byte function (Verified with `int_convert.py`), code refs from adjustor thunks `0x00520ad1` (`this -= 0xa0` / 160, Verified with `int_convert.py`) and `0x00520adc` (`this -= 0xa4` / 164, Verified with `int_convert.py`), primary vtable refs `0x0061f0a4` / `0x0061f204` / `0x0061f364`, no ordinary callers, call to `ListPane::~ListPane()` at `0x004f3b60`, optional MemoryMan-backed `OperatorDeleteWrapper` at `0x004f4ac0`, and `@_guard_check_icall_nop@4` guard/sized-delete path with complete-object size `0x15c` / 348 (Verified with `int_convert.py`).
  - Replacement/procurement: no external dependency and no hand-authored source replacement; regenerated by the compiler from menu-list inheritance/vtable layout, ordinary implicit/empty list destructors, and the source-owned `ListPane::~ListPane()` body.
  - Owner docs: [UID:00002Q][ClientItemMenuItemList](by-class/ClientItemMenuItemList.md), [UID:0000D4][ServerSpellMenuItemList](by-class/ServerSpellMenuItemList.md), [UID:00002S][ClientSpellMenuItemList](by-class/ClientSpellMenuItemList.md), [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md), [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md), [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md), and [UID:0003TZ][0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor](by-memory/0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor.md).
```

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` directly under the current supervisor ban. Replace the current UID `0001C1` row with this exact line:

```text
    - [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md) 0x00520c20-0x00520c5b | shared scalar deleting destructor | SharedListPaneScalarDeletingDestructor : ignored : 86% : strong : B001 source-quality report confirms exact no-code compiler-glue proof for the shared ClientItemMenuItemList/ServerSpellMenuItemList/ClientSpellMenuItemList deleting wrapper: primary vtable slots `0x0061f0a4`/`0x0061f204`/`0x0061f364`, secondary/tertiary adjustor-thunk routes `0x00520ad1` (`this -= 0xa0` / 160, Verified with `int_convert.py`) and `0x00520adc` (`this -= 0xa4` / 164, Verified with `int_convert.py`), common complete-object size `0x15c` / 348 bytes (Verified with `int_convert.py`), `ListPane::~ListPane()` non-deleting cleanup `0x004f3b60`, MemoryMan-backed `OperatorDeleteWrapper` `0x004f4ac0`, MSVC guard-check no-op `0x0041b6a0`, no ordinary callers, and `RECONSTRUCTABLE:FALSE` source-declaration responsibility through the owning list classes rather than handwritten C++.
```

## Validator Needs

No validator was required for this report-only pass because only an Agent-B001 research report was created.

If the supervisor accepts the recommendations and sends an implementation callback, validate each edited by-* file. Suggested commands:

> Executable block R001 was removed from this report and preserved verbatim in [0001C1-SharedListPaneScalarDeletingDestructor-source-quality-removed.md](0001C1-SharedListPaneScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After supervisor-owned coverage-row application, run whichever coverage refresh workflow the supervisor currently uses. B001 must not apply the `by-memory/-coverage-report.md` row while the ban remains active.

If live IDA MCP is available during the implementation callback, recommended spot checks are:

```text
tools/list
lookup_funcs 0x00520c20 0x00520c5b 0x00520ad1 0x00520adc 0x004f3b60 0x004f4ac0 0x0041b6a0
xrefs_to 0x00520c20
callers 0x00520c20
callees 0x00520c20
disasm 0x00520c20
disasm 0x00520ad1
disasm 0x00520adc
```

## Implementation Readiness

- Target/support doc implementation readiness: ready.
- Exact score/metadata: ready (`86/90`, `RECONSTRUCTABLE:FALSE`, no owner/emitter).
- Exact helper names: ready (`ListPane::~ListPane`, `OperatorDeleteWrapper`, `@_guard_check_icall_nop@4`).
- Exact object-size interpretation: ready as complete-object size `0x15c` / 348 (Verified with `int_convert.py`), not a field.
- Exact vtable routes: ready, with all primary/secondary/tertiary consumer addresses listed.
- First-draft C++: not applicable by hard evidence. The target must remain blank because it is compiler-generated ABI glue. Source declaration guidance is included above for the owning classes, but no formal `RECONSTRUCTION_CPP CODE` belongs in UID `0001C1`.
- Remaining open questions: none that should block implementation. A live IDA recheck would improve audit freshness but is not needed to accept the no-code/source-placement direction because existing docs already record live IDA facts.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0001C1-SharedListPaneScalarDeletingDestructor-source-quality.md`.
- Modified: none.
- Target/support by-* docs edited: none.
- `by-memory/-coverage-report.md` edited: no.
- Reports preserved: existing `0002NQ`, `00013I`, `00016R`, and `00019L` research reports were not modified.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001C1-SharedListPaneScalarDeletingDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001C1"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001C1-SharedListPaneScalarDeletingDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001C1-SharedListPaneScalarDeletingDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001C1"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
