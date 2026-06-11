# B001-002 / B001-004 Ownership Research: UID 0002DR

Revision: B001-004 audit / supervisor override active recheck / inference guidance review / 00030X follow-up / finalized-top-format, 2026-06-08

## Finalized Report / Current Recommendation

- Target UID/path: [UID:0002DR] `by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md`
- Current recommendation: close [UID:0002DR] as an intentionally mixed aggregate/container with blank aggregate parent; source placement belongs on exact child pages, not the aggregate.
- Recommended status/classification: mixed by-memory helper island / non-single-source aggregate. It should not be attached as a whole to `FittingRoom`, `FittingRoomListPane`, `VectorHelpers`, `StringUtil`, `NewHumanImageLib`, `MacroDialogs`, or `WorldMapPane`.
- Confidence: `91/100` for mixed-aggregate classification; `84/100` for the new [UID:00030X] -> [UID:0000OB] `StringUtil` recommendation.
- Concrete next action: A-agent/supervisor should keep [UID:0002DR] aggregate parent blank or mark it with a mixed-aggregate/non-emitting-audit classification if supported. Separately, update [UID:00030X] `by-memory/0x00421260-0x00421290.WideFormatWrapper128.md` to record the direct IDA evidence below, raise the child to at least the corrected `85/85` gate if accepted, and set `AUTOGEN_PARENT_UID:0000OB` for `StringUtil`.
- Report state: final for B001 aggregate and [UID:00030X] ownership recommendation; follow-up required by A-agent/supervisor to apply child-page score/parent changes. Not blocked.

## Supporting Research

## Target

- Target UID: `0002DR`
- Target path: `by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md`
- Full path reviewed: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md`
- Assigned queue row: `tools\leaser\Agents\Supervisor_notes.md:181`
- Current supervisor classification: `reviewed-85-but-ownership-unknown-under-review`
- Supervisor row context: B001-002 assigned after Batch 101 split/review; aggregate improved from `80/86` to `86/88`, exact children assigned or rerouted where justified, and `00030X` was left below gate before this follow-up research.
- Current target metadata: `COMPLETION:86`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, blank `AUTOGEN_PARENT_UID`.

## Executive Recommendation

Close `0002DR` as an intentionally mixed aggregate/container over already split children with different real source owners. Keep its `AUTOGEN_PARENT_UID` blank because any single-source parent would be false, not because the research is waiting for impossible proof. Do not attach the whole `0x00420de0-0x00421301` range to `FittingRoom`, `FittingRoomListPane`, `VectorHelpers`, `StringUtil`, `NewHumanImageLib`, `MacroDialogs`, or `WorldMapPane`.

The range is a mixed helper island, not one direct source owner. Current IDA and documentation evidence divide it into:

- shared pointer-vector/template support: `00030Q` and `00030Z`, already assigned to [UID:0000P3] `by-file/VectorHelpers.md`;
- fitting-room list-entry vector support: `00030R` and `00030T`, already assigned to [UID:000053] `by-class/FittingRoomListPane.md`;
- shared wide-format utility support: `00030V`, already assigned to [UID:0000OB] `by-file/StringUtil.md`;
- shared wide-format utility support now recommended for [UID:00030X] after this follow-up: assign to [UID:0000OB] `by-file/StringUtil.md` once the child page records the added evidence and clears the corrected gate.

Confidence in the recommendation: `91/100`.

If forced to choose a single existing parent despite the mixed evidence, the least bad candidate is [UID:0000JE] `by-file/FittingRoom.md`, because the island is physically inside the fitting-room UI-core neighborhood and two exact children plus one unresolved child are fitting-room-list driven. That forced candidate is still too weak to act on because IDA proves three children have non-fitting-room callers and the exact children already route to `VectorHelpers`, `FittingRoomListPane`, and `StringUtil`.

Evidence that would change the recommendation: a source-level policy that allows a mixed aggregate/audit page to parent as a non-emitting container without claiming source ownership, or new IDA/source-layout evidence proving all non-fitting-room caller uses are template instantiations emitted from a fitting-room-only source unit. Current IDA evidence supports neither.

## B001 Supervisor Override Active Recheck

Fresh read-only IDA MCP `py_eval` on 2026-06-08 reconfirmed the aggregate split: six separate functions at `0x00420de0`, `0x00420ef0`, `0x00421150`, `0x00421230`, `0x00421260`, and `0x00421290`, followed by no function at `0x00421301` and the next unrelated function beginning at `0x00421310`. The internal gaps `0x00420eea-0x00420ef0`, `0x00421143-0x00421150`, `0x0042122b-0x00421230`, `0x0042125d-0x00421260`, and `0x00421301-0x00421310` are all `0xcc` padding.

The same recheck reconfirmed the caller split: `0x00420de0` has fitting-room and non-fitting-room callers including `0x004e020d` in `sub_4DFD10`; `0x00420ef0` is fitting-room-list driven; `0x00421150` is internal to `0x00420ef0`; `0x00421230` has fitting-room plus macro/edit-control callers at `0x0057fb94` and `0x005800de`; `0x00421260` is fitting-room-only at the caller level but is a fixed-capacity wide-format utility wrapper matching the `StringUtil` wrapper family; and `0x00421290` has fitting-room plus `WorldMap` caller `0x005c2c7b`.

This override pass makes the recommendation more active: the supervisor should treat [UID:0002DR] as a resolved mixed aggregate/audit container whose children carry ownership, not as an unresolved source-owner search. The best forced single existing parent remains [UID:0000JE] `FittingRoom`, but it is weaker than the mixed-container decision because IDA proves real children route to `VectorHelpers`, `FittingRoomListPane`, `StringUtil`, and non-fitting-room callers.

## Inference Research Guidance Check

Applied `Agent-B001\inference_research.md` on 2026-06-08. A read-only IDA MCP string/segment breadcrumb scan found no `.pdb`, `RSDS`, `NB10`, `.cpp`, or `.cxx` strings and no debug/PDB segment. The current ownership decision is therefore not based on confirmed compilation-unit metadata. It is based on function boundaries, caller/callee evidence, exact child behavior, padding, and the current documented child-owner split.

Evidence ladder classification:

- Confirmed binary facts: the aggregate contains six independent functions separated by `0xcc` padding; the next unrelated function begins at `0x00421310`; callers cross fitting-room, NewHumanImageLib, MacroDialogs, and WorldMap contexts.
- Strongly inferred child ownership: `00030Q`/`00030Z` are shared 4-byte pointer-vector helpers; `00030R`/`00030T` are fitting-room entry-vector helpers; `00030V` is a shared wide-format wrapper; `00030X` is the fixed-`0x80` wide-format sibling and is now recommended for [UID:0000OB] `StringUtil` after child-page evidence/score update.
- Strong aggregate inference: the parent range is an address-contiguous emitted helper island/audit map, not a single source-level owner.
- Weak evidence deliberately rejected: physical adjacency in `.text` and the fitting-room neighborhood cannot override the non-fitting-room callers and exact child split.

Counter-evidence checked: no data reference, vtable, class layout, constructor, or source breadcrumb ties the whole aggregate to one owner; exact child pages already route to multiple owners; the least-bad forced `FittingRoom` parent is weaker than the mixed-container result. Next verification that would change confidence: a PDB/linker map proving one original compilation unit emitted all six helpers intentionally, or a schema/policy change that allows a non-emitting mixed aggregate page to carry a special parent/classification without claiming source ownership.

## Follow-Up Research: [UID:00030X] `0x00421260-0x00421290.WideFormatWrapper128`

Direct target reviewed:

- [UID:00030X] `by-memory/0x00421260-0x00421290.WideFormatWrapper128.md`
- Current child metadata in project docs: `COMPLETION:82`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, blank `AUTOGEN_PARENT_UID`
- Prior documented blocker: behavior was clear but source ownership was withheld because live caller evidence was fitting-room-only and the child page did not clear the strict `85/85` assignment gate.

Read-only IDA MCP facts from this follow-up:

- `lookup_funcs` / IDAPython: `0x00421260` is `sub_421260`, exact function range `0x00421260-0x00421290`, size `0x30`.
- Direct callers: one call at `0x0041f89b` inside `sub_41F2B0` (`0x0041f2b0-0x0041fb9b`), documented as [UID:0002DL] `FittingRoomListPaneOnPaint`.
- Callees: `0x00421274` calls `sub_41B9A0`; `0x0042127e` calls `___stdio_common_vswprintf_s`.
- Disassembly pushes `ArgList`, `Locale=0`, incoming `Format`, fixed `BufferCount=0x80`, incoming `Buffer`, then the CRT stdio option pair from `sub_41B9A0`, calls `___stdio_common_vswprintf_s`, and normalizes negative return values to `-1` through `cmovs`.
- Hex-Rays decompilation:
  - `int sub_421260(wchar_t *Buffer, wchar_t *Format, ...)`
  - calls `sub_41B9A0()`
  - calls `__stdio_common_vswprintf_s(*options, Buffer, 0x80u, Format, 0, va)`
  - returns `-1` if the CRT result is negative.
- Caller context in `sub_41F2B0`: the call is `sub_421260(Src, L"%s", v20 + 10)` where `Src` is a local `wchar_t Src[128]`. The result is then assigned into an SSO/wide-string object through `sub_421590`, tokenized with `wcstok(..., L" ", ...)`, and rewrapped into `wchar_t Buffer[32]` using sibling `sub_421230` at `0x0041f9d7` and `0x0041f9fc`.

Sibling and family comparison:

| Item | Range | Fixed capacity | Callers | Owner evidence |
| --- | --- | ---: | --- | --- |
| [UID:00030V] `WideFormatWrapper32` | `0x00421230-0x0042125d` | `0x20` | fitting-room plus macro edit-control paint callers | already assigned to [UID:0000OB] `StringUtil` |
| [UID:00030X] `WideFormatWrapper128` | `0x00421260-0x00421290` | `0x80` | fitting-room paint caller only | same wrapper body as `00030V`; now recommended for [UID:0000OB] |
| [UID:0002UA] `WideFormatWrapper` | `0x004236e0-0x00423710` | `0x104` | broad fitting-room/minimap/map/screenshot fan-in | already assigned to [UID:0000OB] `StringUtil` |

Documentation evidence:

- [UID:0000OB] `by-file/StringUtil.md` already lists fixed-capacity wide-format wrappers as `StringUtil` contents and explicitly includes [UID:00030X] as the likely fixed-`0x80` sibling. The prior reason for withholding assignment was the child page's `82/86` score and single caller, not any conflicting owner evidence.
- [UID:000053] `FittingRoomListPane.md` routes only [UID:00030R] and [UID:00030T] to the list-pane class and states sibling wide-format helpers route to shared utility parents or remain below gate.
- [UID:0000JE] `FittingRoom.md` provides source neighborhood context but rejects single aggregate ownership; it does not provide a stronger direct claim over fixed-format CRT wrappers.

Ranked [UID:00030X] owner candidates:

1. [UID:0000OB] `StringUtil` - recommended, confidence `84/100`. IDA proves the function is a generic fixed-capacity `wchar_t` varargs formatting wrapper over the same CRT option accessor and `___stdio_common_vswprintf_s` path as assigned `StringUtil` wrappers. The only semantic difference from [UID:00030V] is capacity `0x80` instead of `0x20`; the caller uses it as a generic safe wide copy/format into `wchar_t[128]`, then passes the result into shared string/tokenization helpers.
2. [UID:000053] `FittingRoomListPane` - rejected as direct owner, confidence `42/100`. The sole caller is `FittingRoomListPaneOnPaint`, but consumer-only evidence is weaker than the function's generic CRT wrapper body and the established `StringUtil` wrapper family.
3. [UID:0000JE] `FittingRoom` - rejected as direct owner, confidence `38/100`. Physical address neighborhood and caller locality support fitting-room context only; they do not explain why the function is an isolated fixed-size formatting wrapper identical to shared utility wrappers.
4. New local `FittingRoomFormattingHelpers` grouping - rejected, confidence `15/100`. Its likely full contents would be only [UID:00030X] and perhaps [UID:00030V], but [UID:00030V] already has non-fitting-room callers and a stronger `StringUtil` assignment, making a new fitting-room-local wrapper grouping misleading.

Counter-evidence and remaining uncertainty:

- Counter-evidence: [UID:00030X] has only one direct caller, and that caller is fitting-room paint. There is no non-fitting-room caller fan-in like [UID:00030V] or [UID:0002UA].
- Why it is still strong enough to act: the body is a pure generic formatting wrapper with no fitting-room fields, globals, strings, vtables, or item-entry layout; it shares the exact local CRT option helper and negative-result normalization pattern with assigned `StringUtil` wrappers; [UID:0000OB] already models the fixed-wide-format wrapper family.
- Remaining missing evidence: original compilation-unit proof, public function name, and direct non-fitting-room caller fan-in. These would raise confidence, but lack of them should not block the best current owner inference.

Final [UID:00030X] recommendation: A-agent/supervisor should update [UID:00030X] to record the above evidence, raise completion to at least `85` if accepted, and set `AUTOGEN_PARENT_UID:0000OB` for [UID:0000OB] `StringUtil`. Do not assign [UID:00030X] to `FittingRoomListPane` or to the mixed [UID:0002DR] aggregate.

## Facts From Current Documentation

Existing documentation is treated as prior inferred evidence, not ground truth. The table below is useful because live IDA MCP confirms the child function boundaries and caller split; the existing parent assignments are accepted only where IDA behavior and caller evidence support them.

The target page itself already documents six exact child functions:

| UID | Range | Current parent state | Key fact |
| --- | --- | --- | --- |
| `00030Q` | `0x00420de0-0x00420eea` | `AUTOGEN_PARENT_UID:0000P3` | 4-byte pointer-vector grow/insert; fitting-room and non-fitting-room callers. |
| `00030R` | `0x00420ef0-0x00421143` | `AUTOGEN_PARENT_UID:000053` | `0xb4` byte fitting-room item-entry insert; sole ordinary caller is list-pane input. |
| `00030T` | `0x00421150-0x0042122b` | `AUTOGEN_PARENT_UID:000053` | Internal range move helper for `00030R`; fitting-room entry layout-specific. |
| `00030V` | `0x00421230-0x0042125d` | `AUTOGEN_PARENT_UID:0000OB` | fixed `0x20` wchar format wrapper; fitting-room and macro-row callers. |
| `00030X` | `0x00421260-0x00421290` | blank parent in current docs; B001 now recommends [UID:0000OB] | fixed `0x80` wchar format wrapper; only confirmed caller is fitting-room paint, but direct follow-up evidence supports `StringUtil` ownership. |
| `00030Z` | `0x00421290-0x00421301` | `AUTOGEN_PARENT_UID:0000P3` | 4-byte pointer-vector copy/construct; fitting-room and WorldMap callers. |

`auto-generated\-ag-memory-coverage.md` agrees with that split: rows 97-101 assign `00030Q` to `0000P3`, `00030R` to `000053`, `00030T` to `000053`, `00030V` to `0000OB`, and `00030Z` to `0000P3`; rows 2110-2111 leave the aggregate `0002DR` and child `00030X` unassigned.

## IDA MCP Evidence

All IDA MCP use was read-only.

### Function Boundaries

Live `lookup_funcs` and `py_eval` on 2026-06-08 report exact child function records:

- `0x00420de0`: `sub_420DE0`, size `0x10a`, range `0x00420de0-0x00420eea`.
- `0x00420ef0`: `sub_420EF0`, size `0x253`, range `0x00420ef0-0x00421143`.
- `0x00421150`: `sub_421150`, size `0xdb`, range `0x00421150-0x0042122b`.
- `0x00421230`: `sub_421230`, size `0x2d`, range `0x00421230-0x0042125d`.
- `0x00421260`: `sub_421260`, size `0x30`, range `0x00421260-0x00421290`.
- `0x00421290`: `sub_421290`, size `0x71`, range `0x00421290-0x00421301`.
- `0x00421301`: no function.
- `0x00421310`: next function `sub_421310`, range `0x00421310-0x00421362`.

IDA byte reads confirm the internal and trailing gaps are all `0xcc` alignment:

- `0x00420eea-0x00420ef0`: 6 bytes `cc`.
- `0x00421143-0x00421150`: 13 bytes `cc`.
- `0x0042122b-0x00421230`: 5 bytes `cc`.
- `0x0042125d-0x00421260`: 3 bytes `cc`.
- `0x00421301-0x00421310`: 15 bytes `cc`.

This proves the aggregate is a sequence of separate functions and padding, not one contiguous source-level method.

### Caller Evidence

Live `callers` and `py_eval` xref checks report:

- `0x00420de0` callers: `0x0041fef1` in `sub_41FCD0`, `0x00422d31` in `sub_422BA0`, and `0x004e020d` in `sub_4DFD10`.
- `0x00420ef0` callers: `0x00420191` in `sub_41FCD0`.
- `0x00421150` callers: `0x0042105e`, `0x0042106b`, and `0x00421078`, all inside `sub_420EF0`.
- `0x00421230` callers: `0x0041f9e7` and `0x0041f9fc` in `sub_41F2B0`, plus `0x0057fb94` in `sub_57FAA0` and `0x005800de` in `sub_57FFB0`.
- `0x00421260` callers: `0x0041f89b` in `sub_41F2B0`.
- `0x00421290` callers: `0x00420179` in `sub_41FCD0`, `0x00421047` in `sub_420EF0`, `0x004224b7` in `sub_422470`, `0x004226fe` in `sub_4226D0`, `0x00422d65` in `sub_422BA0`, and `0x005c2c7b` in `sub_5C2AC0`. `py_eval` listed duplicate xrefs at `0x005c2c7b`, but the `callers` tool collapses this to one caller site.

The non-fitting-room caller identities are documented:

- `sub_4DFD10` is [UID:0002JR] `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`, under [UID:0000LR] `by-file/NewHumanImageLib.md`.
- `sub_57FAA0` is [UID:000095] `NewMacroEditControlPane::OnPaint`, under [UID:0000KY] `MacroDialogs`.
- `sub_57FFB0` is [UID:00006M] `IntegrateMacroEditControlPane::OnPaint`, under [UID:0000KY] `MacroDialogs`.
- `sub_5C2AC0` is [UID:0001O4] `by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md`, under [UID:0000PB] `WorldMapPane`.

This caller spread is the strongest negative evidence against a single `FittingRoom.cpp` or `FittingRoomListPane` parent for the aggregate.

### Callee and Decompilation Evidence

`0x00420de0` calls `sub_421500`, `sub_421520`, `_memmove_0`, checked free `sub_5C7526`, and invalid-parameter handling. Decompilation computes distances with `>> 2`, inserts one `_DWORD`, memmoves prefix/suffix spans, and updates begin/end/capacity. This is 4-byte vector grow/insert support, not fitting-room-specific entry logic.

`0x00420ef0` calls `sub_421290`, `sub_421150`, `sub_421380`, `sub_4214D0`, `sub_4216D0`, `operator new`, checked free, vector throw support, C++ throw support, and invalid-parameter handling. Decompilation divides vector distances by `180`, allocates `180 * capacity`, copies `0xa0` bytes from source offset `+4`, copies the word at source offset `+0xa4`, and deep-copies a nested vector from source offset `+0xa8` through `0x00421290`. This is fitting-room entry-vector support.

`0x00421150` has no callees. Decompilation loops over 180-byte entries, copies inline fields, transfers nested vector fields at `+0xa8/+0xac/+0xb0`, and zeroes the source nested-vector fields. This is move-construction for the same fitting-room entry layout.

`0x00421230` and `0x00421260` both call `sub_41B9A0` and `___stdio_common_vswprintf_s`. Decompilation proves fixed capacities of `0x20` and `0x80` wide characters respectively.

`0x00421290` calls `sub_421500`, `sub_421520`, and `_memmove_0`. Decompilation zero-initializes three vector header pointers, computes element count from `(end - begin) >> 2`, allocates `4 * count`, memmoves the pointer span, and updates `end`.

No data-reference or vtable evidence was found that would make the aggregate itself a class method or source-level object. The evidence is function-level and points to multiple helper families.

## Ranked Ownership Analysis

### 1. Split exact-child ownership with `0002DR` left as a mixed aggregate container

Recommendation rank: best outcome.

Evidence for:

- IDA confirms six separate functions and multiple padding gaps, not one source-level method.
- IDA caller/callee evidence divides the range into at least three source-owner families: shared pointer-vector support, fitting-room entry-vector support, and wide-format string utility support.
- Existing generated coverage and docs already assign the exact children that clear gates to different parents, matching the live IDA evidence.
- Mixed aggregate pages are useful as maps over adjacent emitted code, but the aggregate itself is not a direct source owner.

Evidence against / uncertainty:

- The aggregate is still reconstructable because it spans real executable bytes and reconstructable child code.
- Current project policy may continue surfacing reconstructable unassigned aggregate pages even when exact children are correctly assigned.

Conclusion: classify/close the aggregate as intentionally mixed and keep the parent blank; use exact child pages for ownership.

Confidence: `91/100`.

### 2. Forced existing by-file fallback: [UID:0000JE] `FittingRoom`

Recommendation rank: least bad forced single-parent candidate, still rejected.

Evidence for:

- The range is physically inside the fitting-room UI-core neighborhood.
- [UID:0000JE] documents the surrounding `FittingRoomListPane` island and acknowledges `0002DR` as context.
- `00030R` and `00030T` are fitting-room item-entry vector helpers, and `00030X` has only a fitting-room paint caller in current project docs.

Evidence against:

- IDA proves `00030Q` is called by non-fitting-room [UID:0002JR] `NewHumanImageLibConstructor`.
- IDA proves `00030V` is called by non-fitting-room macro edit-control paint functions.
- IDA proves `00030Z` is called by non-fitting-room [UID:0001O4] `WorldMapPane`.
- Current exact children already have better direct parents where they clear the gate.

Conclusion: use only if a supervisor policy requires a physical-neighborhood parking parent and explicitly marks it provisional/non-emitting. It is too weak as actual source ownership.

Confidence if forced: `45/100`.

### 3. New source/grouping `FittingRoomSelectionVectorHelpers.cpp`

Recommendation rank: considered but rejected.

Likely full contents if such a grouping were created:

- [UID:0002DR] aggregate container, `0x00420de0-0x00421301`
- [UID:00030Q] `0x00420de0-0x00420eea.PointerVectorGrowInsert`
- [UID:00030R] `0x00420ef0-0x00421143.FittingRoomItemEntryVectorInsert`
- [UID:00030T] `0x00421150-0x0042122b.FittingRoomItemEntryMoveConstructRange`
- [UID:00030V] `0x00421230-0x0042125d.WideFormatWrapper32`
- [UID:00030X] `0x00421260-0x00421290.WideFormatWrapper128`
- [UID:00030Z] `0x00421290-0x00421301.PointerVectorCopyConstruct`
- internal `0xcc` alignment gaps between those exact functions

Why this new file is not recommended:

- It would group by physical adjacency rather than source ownership.
- It would duplicate existing better owners: [UID:0000P3] `VectorHelpers`, [UID:000053] `FittingRoomListPane`, and [UID:0000OB] `StringUtil`.
- IDA caller evidence proves at least three helpers are shared outside fitting-room.
- The proposed file would be broad/mixed, not standalone or narrow, and would encode a false original-source boundary.

Conclusion: reject new file creation.

Confidence for creating this new owner: `10/100`.

### 4. Existing [UID:000053] `FittingRoomListPane`

Recommendation rank: best real owner only for two children.

Evidence for:

- IDA confirms `00030R` is called from `FittingRoomListPaneOnInputEvent`.
- IDA confirms `00030T` is internal to `00030R`.
- Both operate on the `0xb4` fitting-room item-entry layout.

Evidence against:

- Does not own `00030Q`, `00030V`, or `00030Z`, and cannot own the aggregate.

Conclusion: correct for `00030R`/`00030T` only.

### 5. Existing [UID:0000P3] `VectorHelpers`

Recommendation rank: best real owner only for two children.

Evidence for:

- IDA confirms `00030Q` and `00030Z` are 4-byte pointer-vector helper patterns with fitting-room and non-fitting-room callers.

Evidence against:

- Does not own fitting-room entry-vector layout helpers or wide-format wrappers.

Conclusion: correct for `00030Q`/`00030Z` only.

### 6. Existing [UID:0000OB] `StringUtil`

Recommendation rank: best real owner for `00030V` and recommended real owner for `00030X`; not an aggregate owner.

Evidence for:

- IDA confirms `00030V` and `00030X` are fixed-capacity wide-format wrappers over `___stdio_common_vswprintf_s`.
- `00030V` has fitting-room and non-fitting-room callers and is already assigned to `StringUtil`.
- `00030X` has the same wrapper shape, fixed-`0x80` capacity, CRT option accessor, negative-result normalization, and stack-buffer usage pattern; this follow-up recommends attaching it to `StringUtil` after child-page evidence/score update.

Evidence against:

- Does not own vector helpers or fitting-room entry layout logic.
- `00030X` has lower confidence than `00030V` and `0002UA` because it still has only one confirmed fitting-room caller.

Conclusion: correct direct parent for `00030V`; B001 now recommends the same direct parent for `00030X` once the child page records this follow-up evidence and clears the gate. Not an owner for `0002DR` as a whole.

## Candidate Parents Considered

### [UID:0000JE] `by-file/FittingRoom.md`

Facts supporting partial relationship:

- `FittingRoom.md` places `FittingRoomListPane` and the surrounding list/input/helper neighborhood under `cashshop/FittingRoom.cpp`.
- It explicitly says exact children `00030R` and `00030T` attach to `FittingRoomListPane`.

Facts against aggregate ownership:

- The same page states the `0002DR` aggregate remains mixed/unassigned.
- It rejects a single `FittingRoom.cpp` assignment for `0002DR` because sibling helpers route to `VectorHelpers`, `StringUtil`, or no parent.
- IDA current callers include non-fitting-room `NewHumanImageLib`, macro edit-control, and `WorldMapPane` paths.

Conclusion: `FittingRoom` is valid broader context for two children, not a direct owner for the aggregate.

### [UID:000053] `by-class/FittingRoomListPane.md`

Facts supporting partial relationship:

- `FittingRoomListPane.md` is `85/87`, reconstructable, parented to `FittingRoom`.
- It directly owns `00030R` and `00030T`.
- IDA callers for `0x00420ef0` and `0x00421150` are limited to the list-pane input insertion path.

Facts against aggregate ownership:

- The class page explicitly states only the 180-byte entry-vector insert/move children are direct `FittingRoomListPane` evidence.
- It routes pointer-vector helpers to `VectorHelpers`, the `0x20` wide-format wrapper to `StringUtil`, and historically left the `0x80` wrapper below gate; B001 now recommends `StringUtil` for that `0x80` wrapper after evidence/score update.
- `0x00420de0`, `0x00421230`, and `0x00421290` have non-list-pane callers.

Conclusion: best direct parent for `00030R`/`00030T`, not for `0002DR`.

### [UID:0000P3] `by-file/VectorHelpers.md`

Facts supporting partial relationship:

- `VectorHelpers.md` is `86/86`, projected to `NexusTK/util/`.
- It specifically covers `00030Q` and `00030Z` as pointer-vector insert/copy helpers with fitting-room and non-fitting-room callers.
- `UInt32Vector.md` records that older reports classified `0x00420de0`/`0x00421290` as `UInt32Vector`, but the current interpretation is shared 4-byte pointer-vector/template support.

Facts against aggregate ownership:

- `00030R`/`00030T` operate on 180-byte fitting-room item entries, not generic pointer-vector slots.
- `00030V`/`00030X` are wide-format wrappers, not vector helpers.
- `VectorHelpers.md` itself says only `00030Q`/`00030Z` route here and the mixed aggregate remains unassigned.

Conclusion: best direct parent for `00030Q`/`00030Z`, not for `0002DR`.

### [UID:0000OB] `by-file/StringUtil.md`

Facts supporting partial relationship:

- `StringUtil.md` is `86/88`, projected to `NexusTK/util/`.
- It includes fixed-capacity wide-format wrappers.
- It directly owns `00030V` and records `00030X` as a likely fixed-`0x80` sibling; B001 follow-up now supplies the missing direct evidence needed to recommend updating the child page and assigning it here.
- IDA decompilation proves the `0x20` and `0x80` capacities and shared CRT formatting wrapper shape.

Facts against aggregate ownership:

- The vector and fitting-room entry helpers are unrelated to string formatting.
- `00030X` has only one confirmed fitting-room caller, so assignment confidence is lower than for wrappers with broader fan-in.
- `StringUtil.md` says physical adjacency to fitting-room is not ownership proof.

Conclusion: best direct parent for `00030V` and recommended direct parent for `00030X` after child-page update; not for `0002DR`.

### [UID:0000FD] `by-class/UInt32Vector.md`

Facts considered:

- Older reports classified `0x00420de0` and `0x00421290` as `UInt32Vector` helpers.
- Current `UInt32Vector.md` explicitly downgrades that interpretation: these are shared 4-byte pointer-vector helpers in a mixed fitting-room/helper island, not proof of standalone `UInt32Vector.cpp`.

Conclusion: not a direct aggregate owner and weaker than `VectorHelpers` even for the pointer-vector children.

### [UID:0000LR] `by-file/NewHumanImageLib.md`

Facts considered:

- IDA current caller `0x004e020d` for `0x00420de0` lies inside [UID:0002JR] `0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`.
- `NewHumanImageLib.md` documents a separate render module under `NexusTK/render/`.

Conclusion: this is negative evidence against fitting-room-only ownership and positive evidence for shared vector support. It is not a plausible owner for the whole aggregate because it calls only `00030Q`.

### [UID:0000KY] Macro Dialogs / Macro Edit Controls

Facts considered:

- IDA current callers `0x0057fb94` and `0x005800de` for `0x00421230` lie in `NewMacroEditControlPane::OnPaint` [UID:000095] and `IntegrateMacroEditControlPane::OnPaint` [UID:00006M].
- Both are macro-dialog UI classes, not cash-shop fitting-room code.

Conclusion: negative evidence against fitting-room-only ownership and positive evidence for shared `StringUtil` formatting support. Not an aggregate owner.

### [UID:0000PB] `WorldMapPane`

Facts considered:

- IDA current caller `0x005c2c7b` for `0x00421290` lies inside [UID:0001O4] `0x005c2ac0-0x005c5c87.WorldMapPane.md`.
- `WorldMapPane.md` is a separate map source module.

Conclusion: negative evidence against fitting-room-only ownership and positive evidence for shared pointer-vector support. Not an aggregate owner.

### Adjacent [UID:0000WT] `0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland`

Facts considered:

- IDA confirms `0x00421301-0x00421310` is 15 bytes of `0xcc` padding.
- The next function `0x00421310` belongs to another mixed helper island.
- `0000WT` itself is intentionally unassigned because it mixes SimpleUString, fitting-room cleanup, thunks, checkbox, and runtime/vector support.

Conclusion: adjacency does not create a source owner. It supports the pattern that this address neighborhood contains mixed emitted helpers and should be split by exact children.

## Negative Evidence Summary

- No single candidate parent explains all six child functions.
- The aggregate has multiple exact IDA function starts and padding gaps, not one method body.
- Non-fitting-room callers exist for three of the six functions:
  - `00030Q`: `NewHumanImageLib` constructor caller.
  - `00030V`: macro edit-control paint callers.
  - `00030Z`: `WorldMapPane` constructor-family caller.
- The only fitting-room-specific children are `00030R` and `00030T`.
- [UID:00030X] is still below the strict child completion gate in current project docs, but B001 follow-up now recommends raising/updating it and assigning it to `StringUtil`; its single fitting-room caller remains the main confidence limiter.
- Existing candidate parent docs all explicitly refuse ownership of the full aggregate.
- Generated coverage already emits exact children to different output files while leaving the aggregate blank, matching the evidence.

## Recommendation

Primary recommendation: close [UID:0002DR] `by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md` as an intentionally mixed aggregate/container with blank `AUTOGEN_PARENT_UID`.

Do not assign the aggregate upward to a single owner. Use the exact child pages for source emission and ownership:

- Keep `00030Q` and `00030Z` under [UID:0000P3] `VectorHelpers`.
- Keep `00030R` and `00030T` under [UID:000053] `FittingRoomListPane`.
- Keep `00030V` under [UID:0000OB] `StringUtil`.
- Update `00030X` with this follow-up evidence and assign it to [UID:0000OB] `StringUtil` once the child page clears the corrected gate.

Secondary recommendation for supervisor policy review: if reconstructable-unassigned queues keep surfacing `0002DR` as noise, mark this page with an explicit mixed-aggregate/non-emitting-audit classification if the documentation schema supports it. Do not relabel the actual executable children as non-reconstructable: the current page covers real executable bytes, and the contained child functions remain reconstructable or source-bearing where their exact pages say so.

## Confidence

Recommendation confidence: `91/100`.

High-confidence facts:

- IDA function boundaries, padding, callers, and callees are current and exact.
- Documentation and generated coverage agree that exact children route to multiple parents.
- Non-fitting-room caller evidence is direct and current.

Remaining uncertainty:

- `00030X` has a recommended `StringUtil` owner, but current project docs still show it below gate and caller evidence remains fitting-room-only.
- Final original source shape for `VectorHelpers` may be header/template support rather than a standalone `.cpp`; that affects emission style, not the aggregate ownership decision.
- Project policy for reconstructable mixed aggregate pages is not fully settled.

## Follow-Up Actions

For A-agents:

- Do not assign `0002DR` to any parent as a whole.
- For `00030X`, record the direct IDA evidence from this report in the child page, raise the child from `82/86` to at least `85/85` if accepted, and set parent [UID:0000OB] `StringUtil`.
- Keep generated output driven by exact child pages, not by the aggregate.

For the supervisor:

- Close B001-002 as "intentionally mixed aggregate; exact children own source placement" rather than "ownership unknown".
- Add or use a future tracker classification for mixed by-memory aggregate maps that should not be resolved to one parent after exact children are assigned.
