** TARGET-REPORT-UID:0001FH **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001FH NpcMessageAndMenuQuestionDialogs Source Split Research

## Finalized Report / Current Recommendation

- Current recommendation: reclassify [UID:0001FH] `by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md` as a reviewed non-emitting split index, not as one emitting reconstructable aggregate.
- Final disposition: split into exact class-method children for `MessageDialog`, `MessageDialogLarger`, `MenuQuestionDialog`, `MenuQuestionDialogLarger`, `MenuQuestionItemList`, and `MenuQuestionItemListLarger`; keep existing [UID:0003G8] and [UID:0003G9] unchanged; add exact non-emitting raw no-route children for six source-shaped but currently unreachable helper bodies; add ignored rows for compiler switch tables and `0xcc` alignment.
- Required action: supervisor-owned by-memory child creation/support updates/coverage-row replacement; B001 does not directly edit by-* docs or coverage under this report-only assignment.
- Confidence: high for split/container disposition and modeled child ownership; medium-high for the semantic role of the no-route raw islands; low for liveness of those raw islands because IDA and raw PE scans found no caller/pointer route.

## Target

- Target UID: `0001FH`
- Target path: `source-3/project-documentation/by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md`
- Source queue/report row: current `project-level/-auto-completion-stats.md` lists [UID:0001FH] as top `Low_Completion`, `82/87`, combined `84.5`.
- Current coverage row: `by-memory/-coverage-report.md` still shows `80% : strong` for the broad reconstructable aggregate.
- Current generated-output state: `auto-generated/-ag-memory-coverage.md` emits [UID:0001FH] through [UID:0000LA] `MessageDialogs.cpp` while existing exact children [UID:0003G8]/[UID:0003G9] also emit through `MessageDialogLarger`, creating broad-parent output pollution.

## Executive Recommendation

[UID:0001FH] should become:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000LA
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP CODE:
```

Keep the filename acceptable as `NpcMessageAndMenuQuestionDialogs`, but rewrite the page title/status to call it a `split-index`. The direct semantic owner for the index remains [UID:0000LA] `MessageDialogs`, because every live source-bearing child in this range routes through that source family, but the index itself should not emit C++.

Create exact children for every modeled function and every raw no-route helper island listed below. The modeled functions clear `85/85+` when assigned to their direct class owners. The raw no-route islands should reach only `85/86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, and blank final C++ unless a future caller/pointer/runtime route is found.

## Evidence Standards Used

- IDA MCP session: `b001_000211_20260616`, opened on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, health ready with auto-analysis and Hex-Rays available.
- IDA MCP tools used: `entity_query`, `lookup_funcs`, `xrefs_to`, `analyze_component`, `decompile`, and `disasm`.
- Raw PE checks: local PE section parser over `NexusTK.exe` for exact gap bytes, rel32 call/jump hits, and absolute VA/RVA pointer hits.
- Documentation checked: target page, [UID:0000LA] `MessageDialogs`, class pages for all six classes, exact [UID:0003G8]/[UID:0003G9] children, dispatcher [UID:00023M], shared navigation [UID:0001FG], read-only-data index [UID:000268], vtable/resource exact children [UID:0003D3]/[UID:0003D4]/[UID:0003D6]/[UID:0003D8]/[UID:0003DD], neighboring HeadSelect/TextDialog/Nexonclub file/memory pages, proposed source tree, generated coverage, memory tool report, and current completion stats.

## Heuristic / Inference Reanalysis And Validation

This reanalysis treats existing documentation and generated output as leads, not proof. It confirms the `MessageDialogs` family/source-file route, contradicts the current broad reconstructable aggregate shape, narrows several prior "gap" claims into raw no-route helper bodies plus switch/padding spans, and leaves final C++ blank because original packet/type/control names remain unresolved after the checks below.

| Issue | Evidence checked | Best defensible inference / descriptive name | Rejected alternatives | Status and impact |
| --- | --- | --- | --- | --- |
| Generated function names `sub_54CE10`, `sub_54DB40`, `sub_54E920`, `sub_54F8E0`, `sub_54FA20`, `sub_54FB30`, `sub_550B00`, `sub_550C40`, `sub_550D50`, `sub_550E30`, `sub_550E40`, `sub_550ED0`, `sub_550F90`, and `sub_550FA0` | IDA function inventory, constructor callers from dispatcher/wrappers, vtable data xrefs, decompilation, adjacent class docs, and existing exact children [UID:0003G8]/[UID:0003G9] | Descriptive child names in the inventory table: constructors, action handlers, `UpdateConfirmButtonState`, `ConfirmSelection`, and `DrawRow` for the relevant classes | Keeping generic `sub_` names in new child docs; treating all functions as one `NpcMessageAndMenuQuestionDialogs` source routine; assigning derived list methods to generic base-control owners | Inferred/descriptive, strong enough for child split/ownership. Original source spellings are unproven, so final C++ remains blank. |
| Broad target classification | Current target metadata, generated coverage, memory-tool largest-leaf report, IDA function inventory, raw gap audit, existing exact child pages, and by-structure split rules | [UID:0001FH] should be a non-emitting split index/container owned by [UID:0000LA], with exact function/raw/ignored children | Leaving [UID:0001FH] as one reconstructable emitter; deleting the parent; creating a new source file; renaming into a different dialog family | Proven structural problem and inferred container repair. This changes target to `RECONSTRUCTABLE:FALSE`, blank emitters, `88/90`; no parent final C++. |
| Source file and class placement | [UID:0000LA] `MessageDialogs`, proposed source tree, dispatcher [UID:00023M], vtable/read-only-data docs, constructor callers, vtable cells, and neighboring dialog memory pages | Live modeled children route to direct classes [UID:000085], [UID:000086], [UID:00007X], [UID:00007Y], [UID:00007Z], and [UID:000080], all under `ui/dialogs/MessageDialogs.cpp` | HeadSelect owner, TextDialog owner, Nexonclub owner, generic `DialogPane`/`ListPane` owner, and a new standalone file | Inferred but high confidence. Existing `MessageDialogs` route is confirmed; competing family routes are rejected by boundaries/xrefs. |
| HeadSelect/TextDialog/Nexonclub boundary uncertainty | Function starts and docs around `0x00551030`, `0x00552110`, `0x005534a0`, and `0x00553610`, plus `0xcc` padding `0x00551021-0x00551030` | Target ends before HeadSelect. HeadSelect starts at `0x00551030`; TextDialog/Nexonclub are later and separate | Extending [UID:0001FH] into HeadSelect; treating shared navigation helpers as TextDialog-owned evidence for this target; merging Nexonclub callback/constructor into the island | Proven boundary rejection. No owner/emitter change toward those families. |
| Packet field layout in message/menu constructors and action handlers | Decompilation of constructors/action handlers, shared navigation helper uses, opcode `0x3a` packet serialization, send call `sub_574BB0(dword_67A7EC, &Src, 12)`, and repeated offsets `this+0x26c/0x270/0x274/0x276` | Descriptive field direction: dialog/menu type byte at `this+0x26c`, context/object/session id at `this+0x270`, state/page word at `this+0x274`, current/page index word at `this+0x276`, menu reply opcode `0x3a`, selection marker `1`, selected option byte, trailing zero | Naming these fields as original source names; treating the no-route raw selection helpers as the active send path; assuming `this+0x276 + 1` is definitely "next page" rather than a one-based index/current value | Inferred/descriptive. Strong enough for source-quality documentation and child scores; unresolved original struct/member names block final C++ only. |
| Packet/source sender ownership | Action decompilation, raw helper byte shape, existing packet sender docs by behavior, global `dword_67A7EC`, and send helper `sub_574BB0` | `dword_67A7EC` is a global packet sender/session pointer used by the active menu-question reply path | Locally renaming it as an owner of this dialog code; classifying the dialog action handlers as network/socket source items | Inferred/descriptive. Does not affect owner/emitter because packet send is a dependency, not source ownership; final C++ waits for global/interface naming. |
| Control ids and child-control collection | Action/update decompilation: child id `5` fetched for selection/list behavior, child id `1` fetched for confirm button enable/disable, member collection access through `this+0x508`, virtual enable/disable slots `+0x4c/+0x50` | Control id `5` is the menu option list; control id `1` is the confirm/OK button; `this+0x508` is the child-control collection/member used by lookup helpers | Calling id `5` a text edit/listbox owned by TextEdit/TextBox; naming id `1` as a close/cancel button; treating virtual slots as source-authored methods in this target | Inferred/descriptive with strong behavioral evidence. Source-facing member/API names remain unresolved and block final C++ exactness, not split/ownership. |
| Menu-question action ids | Switch decompilation for `sub_54F8E0` and `sub_550B00`, inline send path, and calls to shared helpers [UID:0001FG] | Menu action `1` submits selected item; actions `2/3/4` route to previous/next/current shared navigation helpers, then close | Treating raw selection-packet helpers as case targets; treating actions `2/3/4` as unique menu-question-only logic; assigning [UID:0001FG] to this range | Proven/descriptive. Confirms shared helper dependency and supports switch-table ignored rows. |
| Message action ids | Decompilation of `sub_54DB40` and existing [UID:0003G9], vtable refs, and shared helper calls | Message action ids `1/2/3` call previous/next/current shared navigation helpers, then close | Creating new child pages for the shared helpers inside [UID:0001FH]; assigning message action handlers to TextDialog because helper ownership is shared | Proven/descriptive. Action handlers are class-owned; shared navigation remains [UID:0001FG]. |
| List row storage and row renderer fields | `sub_550E40`/`sub_550FA0` decompilation, raw add-row helper bytes, `_wcscpy_s`, `sub_4F3C50`, `sub_4F3DC0`, item data access at `itemData+2`, and writes to `this+0x88` | Row records carry a one-byte/word option id prefix followed by UTF-16 label text at offset `+2`; row renderers draw selected background/colors and label text | Declaring a final original `MenuQuestionItem` struct name; treating raw add-row helpers as live constructors; assigning row storage to a generic list framework page | Inferred/descriptive. Supports `DrawRow` and raw add-row child names. Exact struct/API names remain unresolved final-C++ blockers. |
| List support-widget relationship | Constructor xrefs from menu-question constructors to `0x00550d50` and `0x00550ed0`, vtable refs to [UID:0003D6]/[UID:0003D8], and member pointer `this+0x14c` used by selection delegators | `MenuQuestionItemList` and `MenuQuestionItemListLarger` are private support widgets for the normal/larger menu-question dialogs | Generic `ListPane` direct ownership; TextEdit/TextBox support-object route; no-owner treatment for live vtable methods | Proven enough for direct class ownership. Base classes are dependencies only. |
| Raw selection-packet helpers `0x0054fa60-0x0054fb21` and `0x00550c80-0x00550d41` | Raw bytes, stack-cookie shape, opcode `0x3a`, same stored offsets as active action handlers, no IDA function, no xrefs, no rel32 hits, no VA/RVA pointer hits, and active action handlers already inline the behavior | Descriptive roles: `MenuQuestionDialogSelectionPacketNoRouteRaw` and `MenuQuestionDialogLargerSelectionPacketNoRouteRaw` | Assigning them to live class emitters; marking them compiler padding; treating them as switch-table data; deleting them from coverage | Inferred semantic role, but liveness rejected. Create exact no-owner/non-emitting raw child pages at `85/86`; no final C++. |
| Raw add-row helpers `0x00550dc0-0x00550e16` and `0x00550f20-0x00550f76` | Raw bytes, `_wcscpy_s`, one-byte id plus UTF-16 label copy, call to `sub_4F3C50`, `retn 8`, no IDA function/xrefs/rel32/pointer hits, nearby list constructors/renderers | Descriptive roles: `MenuQuestionItemListAddRowNoRouteRaw` and `MenuQuestionItemListLargerAddRowNoRouteRaw` | Treating them as live list methods, padding, compiler thunks, or base-list framework code | Inferred semantic role, no live route. Exact raw non-emitting children; do not assign owner/emitter. |
| Raw selectable-entry probes `0x00550e20-0x00550e2e` and `0x00550f80-0x00550f8e` | Raw bytes `push [ecx+0x134]`, call `sub_4F3DC0`, return first byte, no IDA function/xrefs/rel32/pointer hits, relation to update helpers using selectable-entry tests | Descriptive roles: `MenuQuestionItemListHasSelectableEntryNoRouteRaw` and `MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw` | Treating them as virtual methods, action switch targets, or padding | Inferred semantic role, liveness rejected. Exact no-owner/non-emitting raw children. |
| No-function/no-xref liveness for raw islands | IDA `lookup_funcs` at each raw start, IDA `xrefs_to`, raw rel32 call/jump scan, raw absolute VA/RVA pointer scan, and comparison with vtable data refs | No live route is currently proven for any of the six raw islands | Assigning semantic class owner because the byte shape "looks right"; classifying them compiler-generated artifacts only; ignoring them as unreachable bytes | Negative evidence is strong but not absolute runtime proof. This blocks owner/emitter/final C++ for raw children and caps them at `85/86`; it does not block split-index completion. |
| Compiler switch tables | Raw bytes after action handlers: `0x0054fa10-0x0054fa20` dwords to `0x0054f91e`, `0x0054f90a`, `0x0054f914`, `0x0054f9f3`; `0x00550c30-0x00550c40` dwords to `0x00550b3e`, `0x00550b2a`, `0x00550b34`, `0x00550c13`; disassembly context | These are compiler-generated jump/switch tables owned by the immediately preceding action handlers for coverage purposes only | Treating them as source functions, raw helper bodies, padding, or read-only-data children | Proven compiler data. Recommend `-ignored.md` and coverage ignored rows, no emitter/final C++. |
| Alignment and ignored ranges | Raw byte audit of every gap between modeled/raw children, confirming `0xcc` bytes at the listed internal spans plus existing boundary padding | All listed internal gaps are alignment padding and should be ignored | Leaving them inside source-bearing children; creating code pages for them; using them to extend neighboring function ranges | Proven padding. Add exact `-ignored.md` and coverage rows; does not affect class ownership. |
| Generated-output pollution and stale generated labels | `auto-generated/-ag-memory-coverage.md`, current broad [UID:0001FH] emitter, existing [UID:0003G8]/[UID:0003G9] exact emitters, target page notes, and generated-output warning docs | Broad parent emission pollutes generated `MessageDialogs.cpp` and overlaps exact class children; `MenuQuestionDialogLarger` constructor currently needs an exact child/source-quality pass rather than a broad parent body | Keeping parent reconstructable to preserve generated output; using generated `class_MessageDialog.cpp` placeholder text as final source; treating generated omission as evidence code is absent | Confirmed/narrowed. Reclass parent as non-emitting split index and create exact children; final C++ remains blank until exact child rewrite. |
| Existing documentation claims revalidated | Target page, support docs, generated reports, [UID:0003G8]/[UID:0003G9], [UID:00023M], [UID:000268], vtable/resource docs, and neighbor docs | Confirmed: `MessageDialogs` source family, existing larger-message children, dispatcher/wrapper route, vtable/read-only-data class identities, neighboring family boundaries. Contradicted: broad single-emitter aggregate and any implication that all internal gaps are padding. Narrowed: packet/control/list roles and raw helper semantics. | Blindly carrying forward "unknown packet/control names"; relying on previous broad aggregate wording; treating generated source omission as authoritative | Revalidated per rule 23. Results drive split, ignored rows, raw children, and final-C++ blocker list. |
| Owner/emitter decisions and score effects | by-structure gates, class parent scores, IDA xrefs/vtables/callers, raw negative-route checks, generated coverage, and support-doc routes | Modeled children can be `RECONSTRUCTABLE:TRUE` with direct class emitters and `86/90` to `88/92`. Raw islands are `CANONICAL_OWNER:NONE`, non-emitting `85/86`. Parent index is non-emitting `88/90`. | Raising raw islands as class-owned emitters; leaving modeled children below `85/85`; keeping parent as only emitter; assigning `NONE` to live modeled class methods | Inferred scores are evidence-backed. Unresolved original names do not cap modeled children below `85/85`; raw liveness caps raw children and blocks emission. |
| Final C++ eligibility | Metadata gates, emitter route checks, unresolved struct/global/member/API names, decompiler-shaped constructor bodies, raw no-route results, and generated-output state | Parent and raw children are not final-C++ eligible. Modeled children meet minimum score/emitter gates after creation but should still keep blank final C++ until a UI-framework naming/type rewrite resolves packet, control, row, and helper APIs | Writing broad parent C++; writing final source with `sub_`, `dword_`, `byte_`, or guessed original field names; emitting no-route raw helpers | Unresolved by design after checked evidence. This blocks final C++ only, not split/owner/score recommendations. |

## IDA MCP Facts

Function inventory for `0x0054ce00-0x00551040` contains exactly these modeled starts in the target range:

| Start | IDA name | Size | End | Meaning |
| --- | --- | ---: | --- | --- |
| `0x0054ce10` | `sub_54CE10` | `0xd2e` | `0x0054db3e` | `MessageDialog` constructor |
| `0x0054db40` | `sub_54DB40` | `0x4b` | `0x0054db8b` | `MessageDialog` action handler |
| `0x0054db90` | `sub_54DB90` | `0xd37` | `0x0054e8c7` | existing [UID:0003G8] `MessageDialogLarger` constructor |
| `0x0054e8d0` | `sub_54E8D0` | `0x4b` | `0x0054e91b` | existing [UID:0003G9] `MessageDialogLarger` action handler |
| `0x0054e920` | `sub_54E920` | `0xfbd` | `0x0054f8dd` | `MenuQuestionDialog` constructor |
| `0x0054f8e0` | `sub_54F8E0` | `0x130` | `0x0054fa10` | `MenuQuestionDialog` action handler |
| `0x0054fa20` | `sub_54FA20` | `0x3d` | `0x0054fa5d` | `MenuQuestionDialog` confirm-button updater |
| `0x0054fb30` | `sub_54FB30` | `0xfcb` | `0x00550afb` | `MenuQuestionDialogLarger` constructor |
| `0x00550b00` | `sub_550B00` | `0x130` | `0x00550c30` | `MenuQuestionDialogLarger` action handler |
| `0x00550c40` | `sub_550C40` | `0x3d` | `0x00550c7d` | `MenuQuestionDialogLarger` confirm-button updater |
| `0x00550d50` | `sub_550D50` | `0x64` | `0x00550db4` | `MenuQuestionItemList` constructor |
| `0x00550e30` | `sub_550E30` | `0xb` | `0x00550e3b` | `MenuQuestionItemList` selection delegation helper |
| `0x00550e40` | `sub_550E40` | `0x81` | `0x00550ec1` | `MenuQuestionItemList` row renderer |
| `0x00550ed0` | `sub_550ED0` | `0x4f` | `0x00550f1f` | `MenuQuestionItemListLarger` constructor |
| `0x00550f90` | `sub_550F90` | `0xb` | `0x00550f9b` | `MenuQuestionItemListLarger` selection delegation helper |
| `0x00550fa0` | `sub_550FA0` | `0x81` | `0x00551021` | `MenuQuestionItemListLarger` row renderer |

IDA also reports `sub_551030` at `0x00551030`, confirming the successor HeadSelect boundary after the `0x00551021-0x00551030` alignment.

### Raw no-function bodies found inside former gaps

Raw byte review found six source-shaped unmodeled bodies that the current target page hides inside broad "gap" spans:

| Range | Bytes / shape | Current route evidence | Recommended treatment |
| --- | --- | --- | --- |
| `0x0054fa60-0x0054fb21` | `push ebp`, stack-cookie frame, writes opcode `0x3a`, `this+0x26c/0x270/0x274/0x276`, selection marker `1`, caller-supplied byte, sends 12 bytes through `dword_67A7EC`/`sub_574BB0`, `retn 4` | no IDA function, no IDA xrefs, no rel32 call/jump hits, no VA/RVA pointer hits | no-route raw island; semantic candidate `MenuQuestionDialogSendSelectionPacketRaw`, but do not emit |
| `0x00550c80-0x00550d41` | identical larger-layout copy of the selection-packet helper, ending `retn 4` | same negative route evidence | no-route raw island; semantic candidate `MenuQuestionDialogLargerSendSelectionPacketRaw`, but do not emit |
| `0x00550dc0-0x00550e16` | stack-cookie frame, copies byte id plus UTF-16 text using `_wcscpy_s`, calls `sub_4F3C50`, `retn 8` | no IDA function/xrefs/pointers | no-route raw island; likely list row insertion helper, but not live |
| `0x00550e20-0x00550e2e` | `push [ecx+0x134]`, `call sub_4F3DC0`, `mov al,[eax]`, `retn` | no IDA function/xrefs/pointers | no-route raw probe; likely first/selectable entry byte accessor |
| `0x00550f20-0x00550f76` | larger-list copy of row insertion helper, `retn 8` | no IDA function/xrefs/pointers | no-route raw island; likely larger row insertion helper, not live |
| `0x00550f80-0x00550f8e` | larger-list copy of `this+0x134` selectable-entry probe | no IDA function/xrefs/pointers | no-route raw probe; do not emit |

The negative raw route scan checked targets `0x0054fa60`, `0x00550c80`, `0x00550dc0`, `0x00550e20`, `0x00550f20`, and `0x00550f80`; every target had zero rel32 call/jump hits and zero absolute VA/RVA pointer hits in the PE.

### Xref / caller facts

- `MessageDialog` constructor `0x0054ce10`: code xrefs at `0x0054c388`, `0x0054c3c7`, wrapper xrefs `0x0054c5b5`, `0x0054c675`.
- `MessageDialog` action handler `0x0054db40`: data xref at vtable cell `0x0062250c`.
- `MessageDialogLarger` existing children: constructor xrefs at `0x0054c27c`, `0x0054c2bb`, `0x0054c615`, `0x0054c6d5`; action vtable xref at `0x006225a8`.
- `MenuQuestionDialog` constructor `0x0054e920`: code xrefs at `0x0054c406`, `0x0054c445`, wrapper xrefs `0x0054c735`, `0x0054c7f5`.
- `MenuQuestionDialog` action/update: vtable xrefs `0x00622644 -> 0x0054f8e0`, `0x00622648 -> 0x0054fa20`.
- `MenuQuestionDialogLarger` constructor `0x0054fb30`: code xrefs `0x0054c2fa`, `0x0054c339`, wrapper xrefs `0x0054c795`, `0x0054c855`.
- `MenuQuestionDialogLarger` action/update: vtable xrefs `0x006226e0 -> 0x00550b00`, `0x006226e4 -> 0x00550c40`.
- `MenuQuestionItemList` constructor `0x00550d50`: constructor calls from `0x0054eb04` and `0x0054f276`; selection/draw vtable cells `0x006227b0` and `0x006227b4`.
- `MenuQuestionItemListLarger` constructor `0x00550ed0`: constructor calls from `0x0054fd14` and `0x00550489`; selection/draw vtable cells `0x00622874` and `0x00622878`.

### Behavior facts resolved

- `MenuQuestionDialog::HandleAction` and `MenuQuestionDialogLarger::HandleAction` inline case `1` selection-packet serialization. Both write opcode `0x3a`, the stored dialog fields at `this+0x26c`, `+0x270`, `+0x274`, and `+0x276 + 1`, selection marker `1`, selected row id from child control id `5`, trailing zero, send size `12`, then close the dialog.
- The no-route raw selection helpers serialize the same packet shape but receive the selected byte as an argument and have no close call. This supports "dead/unreferenced helper clone" rather than a missing vtable method.
- `MenuQuestionDialog`/larger update helpers fetch child id `1` as the confirm button and child id `5` as the list, test list entry state through `sub_4F3E20`, and virtual-dispatch enable/disable through slots `+0x4c/+0x50`.
- `MenuQuestionItemList`/larger selection helpers are two-instruction owner/paired-list delegators: load `[ecx+0x14c]`, jump to `0x0049de70`.
- Row renderers read row label text at `itemData + 2`, set selected colors/background (`0x25`, `0x80`), force `this+0x88 = 1`, draw row bounds, then render UTF-16 label text.

## Function / Child Inventory

| Range | Recommended path | Role | Direct owner | Reconstructable | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0054ce10-0x0054db3e` | `by-memory/0x0054ce10-0x0054db3e.MessageDialogConstructor.md` | constructor | [UID:000085] | TRUE, emit [UID:000085] | `87/90` | create |
| `0x0054db40-0x0054db8b` | `by-memory/0x0054db40-0x0054db8b.MessageDialogActionHandler.md` | virtual action handler | [UID:000085] | TRUE, emit [UID:000085] | `88/92` | create |
| `0x0054db90-0x0054e8c7` | existing [UID:0003G8] | constructor | [UID:000086] | TRUE, emit [UID:000086] | `87/90` | keep |
| `0x0054e8d0-0x0054e91b` | existing [UID:0003G9] | virtual action handler | [UID:000086] | TRUE, emit [UID:000086] | `88/92` | keep |
| `0x0054e920-0x0054f8dd` | `by-memory/0x0054e920-0x0054f8dd.MenuQuestionDialogConstructor.md` | constructor | [UID:00007X] | TRUE, emit [UID:00007X] | `87/90` | create |
| `0x0054f8e0-0x0054fa10` | `by-memory/0x0054f8e0-0x0054fa10.MenuQuestionDialogActionHandler.md` | virtual action handler | [UID:00007X] | TRUE, emit [UID:00007X] | `88/91` | create |
| `0x0054fa20-0x0054fa5d` | `by-memory/0x0054fa20-0x0054fa5d.MenuQuestionDialogUpdateConfirmButtonState.md` | virtual confirm updater | [UID:00007X] | TRUE, emit [UID:00007X] | `87/90` | create |
| `0x0054fa60-0x0054fb21` | `by-memory/0x0054fa60-0x0054fb21.MenuQuestionDialogSelectionPacketNoRouteRaw.md` | no-route raw selection-packet clone | NONE | FALSE, no emit | `85/86` | create |
| `0x0054fb30-0x00550afb` | `by-memory/0x0054fb30-0x00550afb.MenuQuestionDialogLargerConstructor.md` | constructor | [UID:00007Y] | TRUE, emit [UID:00007Y] | `87/90` | create |
| `0x00550b00-0x00550c30` | `by-memory/0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler.md` | virtual action handler | [UID:00007Y] | TRUE, emit [UID:00007Y] | `88/91` | create |
| `0x00550c40-0x00550c7d` | `by-memory/0x00550c40-0x00550c7d.MenuQuestionDialogLargerUpdateConfirmButtonState.md` | virtual confirm updater | [UID:00007Y] | TRUE, emit [UID:00007Y] | `87/90` | create |
| `0x00550c80-0x00550d41` | `by-memory/0x00550c80-0x00550d41.MenuQuestionDialogLargerSelectionPacketNoRouteRaw.md` | no-route raw selection-packet clone | NONE | FALSE, no emit | `85/86` | create |
| `0x00550d50-0x00550db4` | `by-memory/0x00550d50-0x00550db4.MenuQuestionItemListConstructor.md` | list constructor | [UID:00007Z] | TRUE, emit [UID:00007Z] | `86/90` | create |
| `0x00550dc0-0x00550e16` | `by-memory/0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw.md` | no-route raw row insertion helper | NONE | FALSE, no emit | `85/86` | create |
| `0x00550e20-0x00550e2e` | `by-memory/0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw.md` | no-route raw entry-state probe | NONE | FALSE, no emit | `85/86` | create |
| `0x00550e30-0x00550e3b` | `by-memory/0x00550e30-0x00550e3b.MenuQuestionItemListConfirmSelection.md` | virtual selection delegator | [UID:00007Z] | TRUE, emit [UID:00007Z] | `87/90` | create |
| `0x00550e40-0x00550ec1` | `by-memory/0x00550e40-0x00550ec1.MenuQuestionItemListDrawRow.md` | virtual row renderer | [UID:00007Z] | TRUE, emit [UID:00007Z] | `87/90` | create |
| `0x00550ed0-0x00550f1f` | `by-memory/0x00550ed0-0x00550f1f.MenuQuestionItemListLargerConstructor.md` | list constructor | [UID:000080] | TRUE, emit [UID:000080] | `86/90` | create |
| `0x00550f20-0x00550f76` | `by-memory/0x00550f20-0x00550f76.MenuQuestionItemListLargerAddRowNoRouteRaw.md` | no-route raw row insertion helper | NONE | FALSE, no emit | `85/86` | create |
| `0x00550f80-0x00550f8e` | `by-memory/0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw.md` | no-route raw entry-state probe | NONE | FALSE, no emit | `85/86` | create |
| `0x00550f90-0x00550f9b` | `by-memory/0x00550f90-0x00550f9b.MenuQuestionItemListLargerConfirmSelection.md` | virtual selection delegator | [UID:000080] | TRUE, emit [UID:000080] | `87/90` | create |
| `0x00550fa0-0x00551021` | `by-memory/0x00550fa0-0x00551021.MenuQuestionItemListLargerDrawRow.md` | virtual row renderer | [UID:000080] | TRUE, emit [UID:000080] | `87/90` | create |

## Ranked Ownership Analysis

### 1. [UID:0000LA] MessageDialogs as source module and split-index owner

- Evidence for: dispatcher [UID:00023M] selects all four message/menu-question dialog constructors; `MessageDialogs.md` and proposed source tree already place this family in `ui/dialogs/MessageDialogs.cpp`; resources `DLGMSG*` and vtable bands are shared across these classes; existing class pages [UID:000085], [UID:000086], [UID:00007X], [UID:00007Y], [UID:00007Z], and [UID:000080] all route to [UID:0000LA] and clear the parent gate.
- Evidence against: the range is too broad for a single emitted source page and contains no-route raw islands plus switch/padding spans.
- Decision: use [UID:0000LA] as the parent of the non-emitting split index and as source-file root for class emitters; do not emit [UID:0001FH] itself.

### 2. Direct class ownership for modeled method children

- Evidence for: constructor callers, vtable stores, vtable-only action/update/draw refs, and class docs prove direct class ownership. For example, `0x0054f8e0`/`0x0054fa20` are vtable cells in `MenuQuestionDialog`; `0x00550e30`/`0x00550e40` are item-list vtable cells; constructors are directly called by the dispatcher/wrapper or owning constructors.
- Evidence against: final source-facing field/control names remain incomplete.
- Decision: assign modeled method children to direct classes with blank final C++ until packet/control/list/framework names are final.

### 3. No-route raw islands as `CANONICAL_OWNER:NONE`

- Evidence for possible class ownership: all six raw bodies are physically inside the class corridor and use the same class field offsets/control APIs as nearby live methods. The selection helpers duplicate menu-question action case `1`; row helpers match item-list row record behavior.
- Evidence against class ownership/emission: no IDA function objects, no `xrefs_to`, no rel32 call/jump hits, no VA/RVA pointer hits, no vtable slots, and live modeled functions already contain the active behavior. The strongest safe claim is "source-shaped no-route clone/probe", not "live class method".
- Decision: create exact non-emitting raw child pages with `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, score `85/86`. Record the semantic candidate class in the body but do not assign or emit unless a route appears.

### Rejected owners

- [UID:0000JT] `HeadSelectDialog`: rejected for [UID:0001FH]. `0x00551030` starts HeadSelect core; `0x00551021-0x00551030` is `0xcc` alignment. HeadSelect vtable/string data starts later in `.rdata`, not inside this executable island.
- [UID:0000OL] `TextDialog`: rejected as owner for [UID:0001FH] children. Shared navigation helpers [UID:0001FG] are staged under TextDialog but are before this range and are cross-called by message/menu-question dialogs; `TextDialog` implementation starts at `0x00552110`.
- [UID:0000LZ] `NexonclubProxyDialog`: rejected. Proxy callback starts at `0x005534a0`, constructor at `0x00553610`; no executable/data evidence pulls proxy code into `0x0054ce10-0x00551021`.
- Generic `ListPane`/`DialogPane`/control owners: rejected for the menu-question item-list and action methods. Those base classes provide APIs, but vtable stores and constructor calls prove the derived private support-widget classes own these exact methods.

## Source-Quality / Final C++ Blockers

Resolved enough for split/source routing:

- Packet reply fields are consistently narrowed to dialog opcode `0x3a`, dialog type byte `this+0x26c`, object/session id `this+0x270`, state/page word `this+0x274`, and page/current index word `this+0x276`.
- Menu-question list child/control id `5` is the selection/list control used by action/update paths.
- Confirm button child/control id `1` is the target enabled/disabled by update helpers.
- Item row records have a one-byte/word prefix area and UTF-16 label text consumed at `itemData+2`.
- `byte_66DA97` is an asset/layout mode branch shared across UI code; do not rename it locally without the dedicated global pass.

Still blocking final C++:

- Original source names for packet structs, dialog state fields, wrapper flags, control member fields, row record type, and `ListPane`/`DialogPane` virtual APIs are not final.
- The no-route raw islands cannot be emitted without a caller/pointer/runtime route.
- Constructor bodies are large and source-authored, but decompiler-shaped local names and helper calls still need a final rewrite pass across the UI framework.

These blockers should not cap the split children below `85/85`, because ownership, boundaries, and behavior are strong. They do block final `RECONSTRUCTION_CPP CODE` on all children for now.

## Exact Supervisor Actions

### Target page metadata

Update `source-3/project-documentation/by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md`:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rewrite status to "non-emitting split index"; remove broad aggregate emission wording; list all exact children and internal ignored spans; keep [UID:0003G8]/[UID:0003G9] as current evidence.

### New child pages

Create the child paths in the inventory table. For modeled children, use:

```text
CANONICAL_OWNER:<direct class UID>
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:<direct class UID>
RECONSTRUCTION_CPP CODE:
```

For no-route raw children, use:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP CODE:
```

### Support docs

Update these docs with child links and the raw no-route caveat:

- `by-file/MessageDialogs.md`: replace the broad [UID:0001FH] executable aggregate wording with the exact child list; record that [UID:0001FH] is now a non-emitting split index; add a note that raw helpers `0x0054fa60`, `0x00550c80`, `0x00550dc0`, `0x00550e20`, `0x00550f20`, and `0x00550f80` are no-route/non-emitting.
- `by-class/MessageDialog.md`: add exact constructor/action child links and remove dependence on the broad aggregate for method evidence.
- `by-class/MenuQuestionDialog.md`: add constructor/action/update child links and the `MenuQuestionDialogSelectionPacketNoRouteRaw` caveat.
- `by-class/MenuQuestionDialogLarger.md`: add constructor/action/update child links and the larger selection raw caveat.
- `by-class/MenuQuestionItemList.md`: add constructor/confirm/draw child links and no-route add-row/probe caveats.
- `by-class/MenuQuestionItemListLarger.md`: add constructor/confirm/draw child links and no-route add-row/probe caveats.
- `by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md`: no metadata change required; optionally add a one-line cross-reference that exact executable child pages now exist for the menu-question vtable slots.
- `by-project-structure/proposed-source-tree.md`: no path change required; optionally update the `MessageDialogs.cpp` section to say the executable aggregate has been split into exact method children and raw no-route rows.

### `by-memory/-ignored.md`

Add an entry under the existing dialog/container boundary alignment area or create a nearby "NpcMessageAndMenuQuestionDialogs internal split support" entry:

```text
- `0x0054db3e-0x0054db40`, `0x0054db8b-0x0054db90`, `0x0054e8c7-0x0054e8d0`, `0x0054e91b-0x0054e920`, `0x0054f8dd-0x0054f8e0`, `0x0054fa5d-0x0054fa60`, `0x0054fb21-0x0054fb30`, `0x00550afb-0x00550b00`, `0x00550c7d-0x00550c80`, `0x00550d41-0x00550d50`, `0x00550db4-0x00550dc0`, `0x00550e16-0x00550e20`, `0x00550e2e-0x00550e30`, `0x00550e3b-0x00550e40`, `0x00550ec1-0x00550ed0`, `0x00550f1f-0x00550f20`, `0x00550f76-0x00550f80`, `0x00550f8e-0x00550f90`, and `0x00550f9b-0x00550fa0` - internal `0xcc` alignment padding inside the split `NpcMessageAndMenuQuestionDialogs` island.
  - Evidence: 2026-06-16 B001 IDA/PE byte audit split [UID:0001FH] into exact modeled functions, raw no-route helper bodies, compiler switch tables, and these `0xcc` padding spans.
  - Owner docs: [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md) and the exact child pages created from this report.
- `0x0054fa10-0x0054fa20` and `0x00550c30-0x00550c40` - compiler-generated action switch tables for `MenuQuestionDialog` and `MenuQuestionDialogLarger`.
  - Evidence: bytes decode as four 32-bit case target addresses inside the immediately preceding modeled action handlers; no standalone source owner.
  - Owner docs: [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md).
```

The existing `0x00551021-0x00551030` boundary padding row can remain; it is already present in `-ignored.md` and coverage.

## Exact Pending `by-memory/-coverage-report.md` Replacement

Replace the single current [UID:0001FH] row at line neighborhood after [UID:0001FG] and before the existing `0x00551021-0x00551030` padding row with this block. Use TMP authoring links until the supervisor-created child pages receive real UIDs.

```text
    - [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md) 0x0054ce10-0x00551021 | split-index | NpcMessageAndMenuQuestionDialogs : ignored/non-emitting : 88% : very-strong : B001 2026-06-16 source-split audit reclassifies this broad message/menu-question dialog island as a non-emitting split index over exact class method children, existing MessageDialogLarger children, no-route raw helper islands, compiler switch tables, and internal alignment. Modeled source-bearing children route through their direct classes to [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md); parent C++ remains blank.
        - [TMP:"by-memory/0x0054ce10-0x0054db3e.MessageDialogConstructor.md"] 0x0054ce10-0x0054db3e | class constructor | MessageDialogConstructor : reconstructable : 87% : very-strong : IDA confirms `sub_54CE10` size `0xd2e`, dispatcher/wrapper callers, MessageDialog vtable stores, packet fields at `this+0x26c/0x270/0x274/0x276`, DLGMSG resource branches, object/text/control construction, and direct class owner/emitter [UID:000085][MessageDialog](by-class/MessageDialog.md).
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0054db3e-0x0054db40 | padding | MessageDialog constructor to action alignment : ignored : 100% : strong : B001 byte audit shows two `0xcc` bytes.
        - [TMP:"by-memory/0x0054db40-0x0054db8b.MessageDialogActionHandler.md"] 0x0054db40-0x0054db8b | virtual action handler | MessageDialogActionHandler : reconstructable : 88% : very-strong : IDA confirms `sub_54DB40` size `0x4b`, sole vtable data ref `0x0062250c`, action ids `1/2/3` call shared previous/next/current helpers [UID:0001FG], then close the dialog; direct class owner/emitter [UID:000085].
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0054db8b-0x0054db90 | padding | MessageDialog action to MessageDialogLarger constructor alignment : ignored : 100% : strong : B001 byte audit shows five `0xcc` bytes.
        - [UID:0003G8][0x0054db90-0x0054e8c7.MessageDialogLargerConstructor](by-memory/0x0054db90-0x0054e8c7.MessageDialogLargerConstructor.md) 0x0054db90-0x0054e8c7 | class constructor | MessageDialogLargerConstructor : reconstructable : 87% : very-strong : Existing exact child; IDA confirms larger message constructor callers, packet fields, vtable stores, DLGMSG resource branches, and direct class owner/emitter [UID:000086].
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0054e8c7-0x0054e8d0 | padding | MessageDialogLarger constructor to action alignment : ignored : 100% : strong : Existing byte review and B001 recheck show nine `0xcc` bytes.
        - [UID:0003G9][0x0054e8d0-0x0054e91b.MessageDialogLargerActionHandler](by-memory/0x0054e8d0-0x0054e91b.MessageDialogLargerActionHandler.md) 0x0054e8d0-0x0054e91b | virtual action handler | MessageDialogLargerActionHandler : reconstructable : 88% : very-strong : Existing exact child; vtable-only action ids `1/2/3` call previous/next/current helpers and close; direct class owner/emitter [UID:000086].
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0054e91b-0x0054e920 | padding | MessageDialogLarger action to MenuQuestionDialog constructor alignment : ignored : 100% : strong : Existing byte review and B001 recheck show five `0xcc` bytes.
        - [TMP:"by-memory/0x0054e920-0x0054f8dd.MenuQuestionDialogConstructor.md"] 0x0054e920-0x0054f8dd | class constructor | MenuQuestionDialogConstructor : reconstructable : 87% : very-strong : IDA confirms `sub_54E920` size `0xfbd`, dispatcher/wrapper callers, MenuQuestionDialog vtable stores, packet fields, optional description/object/list construction, two [UID:00007Z][MenuQuestionItemList](by-class/MenuQuestionItemList.md) constructor calls, and DLGMSG3/31/4 resource branches.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0054f8dd-0x0054f8e0 | padding | MenuQuestionDialog constructor to action alignment : ignored : 100% : strong : B001 byte audit shows three `0xcc` bytes.
        - [TMP:"by-memory/0x0054f8e0-0x0054fa10.MenuQuestionDialogActionHandler.md"] 0x0054f8e0-0x0054fa10 | virtual action handler | MenuQuestionDialogActionHandler : reconstructable : 88% : very-strong : IDA confirms `sub_54F8E0` size `0x130`, vtable data ref `0x00622644`, action `1` inline selection-packet serialization with opcode `0x3a`, actions `2/3/4` call shared navigation helpers, then close.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0054fa10-0x0054fa20 | compiler switch table | MenuQuestionDialog action jump table : ignored : 100% : strong : B001 byte audit shows four action-handler target addresses after `sub_54F8E0`, not source code.
        - [TMP:"by-memory/0x0054fa20-0x0054fa5d.MenuQuestionDialogUpdateConfirmButtonState.md"] 0x0054fa20-0x0054fa5d | virtual updater | MenuQuestionDialogUpdateConfirmButtonState : reconstructable : 87% : very-strong : IDA confirms `sub_54FA20` size `0x3d`, vtable data ref `0x00622648`, child ids `1` and `5`, list selectable-entry test through `sub_4F3E20`, and confirm button enable/disable virtual dispatch.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0054fa5d-0x0054fa60 | padding | MenuQuestionDialog updater to raw no-route selection helper alignment : ignored : 100% : strong : B001 byte audit shows three `0xcc` bytes.
        - [TMP:"by-memory/0x0054fa60-0x0054fb21.MenuQuestionDialogSelectionPacketNoRouteRaw.md"] 0x0054fa60-0x0054fb21 | no-route raw code island | MenuQuestionDialogSelectionPacketNoRouteRaw : ignored/non-emitting : 85% : strong : Raw source-shaped opcode `0x3a` selection-packet helper ending `retn 4`; no IDA function, no xrefs, no rel32 call/jump hits, and no VA/RVA pointer hits. Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/final C++ unless a route is found.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0054fb21-0x0054fb30 | padding | raw selection helper to MenuQuestionDialogLarger constructor alignment : ignored : 100% : strong : B001 byte audit shows fifteen `0xcc` bytes.
        - [TMP:"by-memory/0x0054fb30-0x00550afb.MenuQuestionDialogLargerConstructor.md"] 0x0054fb30-0x00550afb | class constructor | MenuQuestionDialogLargerConstructor : reconstructable : 87% : very-strong : IDA confirms `sub_54FB30` size `0xfcb`, dispatcher/wrapper callers, omitted generated constructor body, larger dialog vtable stores, packet fields, two [UID:000080][MenuQuestionItemListLarger](by-class/MenuQuestionItemListLarger.md) constructor calls, and DLGMSG3/31/4 large-resource branches.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00550afb-0x00550b00 | padding | MenuQuestionDialogLarger constructor to action alignment : ignored : 100% : strong : B001 byte audit shows five `0xcc` bytes.
        - [TMP:"by-memory/0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler.md"] 0x00550b00-0x00550c30 | virtual action handler | MenuQuestionDialogLargerActionHandler : reconstructable : 88% : very-strong : IDA confirms `sub_550B00` size `0x130`, vtable data ref `0x006226e0`, same action matrix and opcode `0x3a` selection serialization as the normal menu-question action handler.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00550c30-0x00550c40 | compiler switch table | MenuQuestionDialogLarger action jump table : ignored : 100% : strong : B001 byte audit shows four action-handler target addresses after `sub_550B00`, not source code.
        - [TMP:"by-memory/0x00550c40-0x00550c7d.MenuQuestionDialogLargerUpdateConfirmButtonState.md"] 0x00550c40-0x00550c7d | virtual updater | MenuQuestionDialogLargerUpdateConfirmButtonState : reconstructable : 87% : very-strong : IDA confirms `sub_550C40` size `0x3d`, vtable data ref `0x006226e4`, child ids `1`/`5`, list selectable-entry test, and confirm button enable/disable dispatch.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00550c7d-0x00550c80 | padding | larger updater to raw no-route selection helper alignment : ignored : 100% : strong : B001 byte audit shows three `0xcc` bytes.
        - [TMP:"by-memory/0x00550c80-0x00550d41.MenuQuestionDialogLargerSelectionPacketNoRouteRaw.md"] 0x00550c80-0x00550d41 | no-route raw code island | MenuQuestionDialogLargerSelectionPacketNoRouteRaw : ignored/non-emitting : 85% : strong : Raw larger-layout selection-packet clone ending `retn 4`; no IDA function, no xrefs, no rel32 hits, and no VA/RVA pointer hits. Keep no-owner/non-emitting unless a route appears.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00550d41-0x00550d50 | padding | larger raw selection helper to MenuQuestionItemList constructor alignment : ignored : 100% : strong : B001 byte audit shows fifteen `0xcc` bytes.
        - [TMP:"by-memory/0x00550d50-0x00550db4.MenuQuestionItemListConstructor.md"] 0x00550d50-0x00550db4 | class constructor | MenuQuestionItemListConstructor : reconstructable : 86% : very-strong : IDA confirms `sub_550D50` size `0x64`, constructor xrefs from `MenuQuestionDialog`, ListPane setup args, owner pointer stored at `this+0x14c`, and vtable stores to [UID:0003D6].
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00550db4-0x00550dc0 | padding | MenuQuestionItemList constructor to raw add-row helper alignment : ignored : 100% : strong : B001 byte audit shows twelve `0xcc` bytes.
        - [TMP:"by-memory/0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw.md"] 0x00550dc0-0x00550e16 | no-route raw code island | MenuQuestionItemListAddRowNoRouteRaw : ignored/non-emitting : 85% : strong : Raw stack-cookie helper copies a one-byte id plus UTF-16 text with `_wcscpy_s` and calls `sub_4F3C50`, ending `retn 8`; no IDA function/xrefs/pointer hits, so keep no-owner/non-emitting.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00550e16-0x00550e20 | padding | raw add-row helper to raw entry probe alignment : ignored : 100% : strong : B001 byte audit shows ten `0xcc` bytes.
        - [TMP:"by-memory/0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw.md"] 0x00550e20-0x00550e2e | no-route raw code island | MenuQuestionItemListHasSelectableEntryNoRouteRaw : ignored/non-emitting : 85% : strong : Raw helper loads `[ecx+0x134]`, calls `sub_4F3DC0`, returns the first byte, with no IDA function/xrefs/pointer hits; keep no-owner/non-emitting.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00550e2e-0x00550e30 | padding | raw entry probe to selection delegator alignment : ignored : 100% : strong : B001 byte audit shows two `0xcc` bytes.
        - [TMP:"by-memory/0x00550e30-0x00550e3b.MenuQuestionItemListConfirmSelection.md"] 0x00550e30-0x00550e3b | virtual selection delegator | MenuQuestionItemListConfirmSelection : reconstructable : 87% : very-strong : IDA confirms `sub_550E30` size `0xb`, vtable data ref `0x006227b0`, body `mov ecx,[ecx+0x14c]; jmp 0x0049de70`, and direct class owner/emitter [UID:00007Z].
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00550e3b-0x00550e40 | padding | selection delegator to row draw alignment : ignored : 100% : strong : B001 byte audit shows five `0xcc` bytes.
        - [TMP:"by-memory/0x00550e40-0x00550ec1.MenuQuestionItemListDrawRow.md"] 0x00550e40-0x00550ec1 | virtual row renderer | MenuQuestionItemListDrawRow : reconstructable : 87% : very-strong : IDA confirms `sub_550E40` size `0x81`, vtable data ref `0x006227b4`, selected-row color/background path, `this+0x88` text-mode write, row bounds draw, and UTF-16 label render from `itemData+2`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00550ec1-0x00550ed0 | padding | normal list renderer to larger list constructor alignment : ignored : 100% : strong : B001 byte audit shows fifteen `0xcc` bytes.
        - [TMP:"by-memory/0x00550ed0-0x00550f1f.MenuQuestionItemListLargerConstructor.md"] 0x00550ed0-0x00550f1f | class constructor | MenuQuestionItemListLargerConstructor : reconstructable : 86% : very-strong : IDA confirms `sub_550ED0` size `0x4f`, constructor xrefs from `MenuQuestionDialogLarger`, ListPane setup args, paired list pointer stored at `this+0x14c`, and vtable stores to [UID:0003D8].
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00550f1f-0x00550f20 | padding | larger list constructor to raw add-row helper alignment : ignored : 100% : strong : B001 byte audit shows one `0xcc` byte.
        - [TMP:"by-memory/0x00550f20-0x00550f76.MenuQuestionItemListLargerAddRowNoRouteRaw.md"] 0x00550f20-0x00550f76 | no-route raw code island | MenuQuestionItemListLargerAddRowNoRouteRaw : ignored/non-emitting : 85% : strong : Raw larger-list row insertion clone ending `retn 8`; no IDA function/xrefs/pointer hits, so keep no-owner/non-emitting.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00550f76-0x00550f80 | padding | larger raw add-row helper to raw entry probe alignment : ignored : 100% : strong : B001 byte audit shows ten `0xcc` bytes.
        - [TMP:"by-memory/0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw.md"] 0x00550f80-0x00550f8e | no-route raw code island | MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw : ignored/non-emitting : 85% : strong : Raw larger-list entry-state probe loads `[ecx+0x134]`, calls `sub_4F3DC0`, returns first byte; no IDA function/xrefs/pointer hits, so keep no-owner/non-emitting.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00550f8e-0x00550f90 | padding | raw entry probe to selection delegator alignment : ignored : 100% : strong : B001 byte audit shows two `0xcc` bytes.
        - [TMP:"by-memory/0x00550f90-0x00550f9b.MenuQuestionItemListLargerConfirmSelection.md"] 0x00550f90-0x00550f9b | virtual selection delegator | MenuQuestionItemListLargerConfirmSelection : reconstructable : 87% : very-strong : IDA confirms `sub_550F90` size `0xb`, vtable data ref `0x00622874`, body `mov ecx,[ecx+0x14c]; jmp 0x0049de70`, and direct class owner/emitter [UID:000080].
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00550f9b-0x00550fa0 | padding | selection delegator to larger row draw alignment : ignored : 100% : strong : B001 byte audit shows five `0xcc` bytes.
        - [TMP:"by-memory/0x00550fa0-0x00551021.MenuQuestionItemListLargerDrawRow.md"] 0x00550fa0-0x00551021 | virtual row renderer | MenuQuestionItemListLargerDrawRow : reconstructable : 87% : very-strong : IDA confirms `sub_550FA0` size `0x81`, vtable data ref `0x00622878`, selected-row color/background path, `this+0x88` text-mode write, row bounds draw, and UTF-16 label render from `itemData+2`.
```

Keep the existing next row unchanged:

```text
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00551021-0x00551030 | padding | NpcMessageAndMenuQuestionDialogs to HeadSelectDialogCore alignment : ignored : 100% : strong : Confirmed `0xcc` bytes after `NpcMessageAndMenuQuestionDialogs` endpoint.
```

## Validation Plan

After applying the supervisor-owned edits:

> Executable block R001 was removed from this report and preserved verbatim in [0001FH-npc-message-menu-question-source-split-removed.md](0001FH-npc-message-menu-question-source-split-removed.md). The archived block is non-authoritative and must not be executed.

Also validate each newly created child page with `validator.py --mode file --file <child> --apply` before validating the shared coverage row so TMP links resolve to real UIDs.

## Changed Files

- Created by B001: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0001FH-npc-message-menu-question-source-split.md`
- Modified by B001: none outside the research folder.
- Direct edits intentionally not performed: target by-memory page, support docs, generated reports, IDA DB, `by-memory/-ignored.md`, and `by-memory/-coverage-report.md`.

## Validator Results

No validator was run because this assignment is report-only and B001 did not create by-* child pages or edit scoped docs. The validation commands above are the recommended supervisor order after applying the split.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001FH-npc-message-menu-question-source-split.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001FH"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001FH-npc-message-menu-question-source-split-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001FH-npc-message-menu-question-source-split.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001FH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
