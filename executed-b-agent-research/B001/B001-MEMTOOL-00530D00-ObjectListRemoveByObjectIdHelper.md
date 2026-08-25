** TARGET-REPORT-UID:00023D **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001-MEMTOOL-00530D00 ObjectListRemoveByObjectIdHelper Warning Audit

## Finalized Report / Current Recommendation

- Current recommendation: treat the Advanced-Error-Scan warning as a real stale filename/name issue, not as a heuristic false positive. The current page content and live IDA evidence support `ObjectListStaticObjectLightingSyncHelper`, not `ObjectListRemoveByObjectIdHelper`.
- Final disposition: keep UID `00023D` reconstructable, but rename the page to `by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md`, add an explicit compact filename/search label in the page body, and route ownership through the direct class owner.
- Required metadata action: change `COMPLETION` from `84` to `85`, change `CANONICAL_OWNER` from `0000M4` to `00009Q`, and change `EMITTER_UIDS` from `0000M4` to `00009Q`. Keep `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_POSITION_OPTIONAL`, and blank reconstruction C++.
- Required coverage action: do not edit `by-memory/-coverage-report.md` directly as B001; supervisor should apply the exact replacement row in this report after the rename/validation step.
- Confidence: high for the warning cause, exact range, ObjectList class ownership, and no split/IDA repair; medium-high for the final source-facing method name because the current best name is still a behavior label rather than proven original source text.

## Supporting Research

## Target

- Target UID: `00023D`
- Current target path: `by-memory/0x00530d00-0x00530ed9.ObjectListRemoveByObjectIdHelper.md`
- Recommended target path: `by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md`
- Source warning: `auto-generated/by-memory-tool-report.md` Advanced-Error-Scan reports `missing document text for ObjectListRemoveByObjectIdHelper`.
- Current scores and metadata:

```text
COMPLETION:84
CONFIDENCE:90
CANONICAL_OWNER:0000M4
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000M4
EMITTER_POSITION_OPTIONAL:
```

The target title is already `# 0x00530d00-0x00530ed9 ObjectList Static Object Lighting Sync Helper`, and the page explicitly says the old `RemoveByObjectId` name is incomplete.

## Executive Recommendation

The warning is not caused by missing behavior documentation. The page is well documented, but its filename still uses an old behavior hypothesis. The current Markdown body never contains the compact token `ObjectListRemoveByObjectIdHelper`, so the scanner correctly flags a filename/content mismatch. More importantly, the filename is stale: live IDA decompilation shows this function synchronizes static-object lighting companions by static object id. It can remove an obsolete attached light, but removal is one branch, not the core role.

Recommended end state:

```text
Path: by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md
COMPLETION:85
CONFIDENCE:90
CANONICAL_OWNER:00009Q
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00009Q
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
```

No split or merge is needed. IDA confirms the exact single function at `0x00530d00-0x00530ed9` with padding before and after. No IDA function repair is needed.

No final reconstruction C++ should be entered yet. The active code-entry gate is about `90/90+`, and this page still has unresolved source-facing method name, `StaticObjEntry` field names, ObjectList tier names, and StaticObjectPane virtual slot names.

## Supervisor Active Recheck

The supervisor assigned this as `B001-MEMTOOL-00530D00` to inspect the Advanced-Error-Scan warning for missing document text for `ObjectListRemoveByObjectIdHelper`.

This assignment did not require split repair before a final report:

- The range is already exact and function-sized.
- The preceding and following padding are already represented in `by-memory/-ignored.md` and the coverage report.
- The implementation belongs to the existing `ObjectList` class/file family.
- The issue is stale naming plus a narrower owner/emitter route, not missing child coverage.

## Inference Research Guidance Check

Facts:

- The target page title and behavior section no longer describe remove-by-id as the primary role.
- `rg` / `Select-String` found no exact `ObjectListRemoveByObjectIdHelper` text inside the target body.
- `auto-generated/by-memory-tool-report.md` explains Advanced-Error-Scan checks whether filename start/end addresses and label text appear in the Markdown body, and that the scan is heuristic.
- The target page already records the old `RemoveByObjectId` name as incomplete.

Inference:

- Because the page body intentionally moved away from the old behavior name, adding the old compact filename token alone would clear the warning but preserve a stale filename. Rename is the better repair.
- Because the function is a `__thiscall` method over ObjectList layout and the ObjectList class now clears the parent side of the gate at `85/88`, the current direct `CANONICAL_OWNER:0000M4` file route is too broad under current by-structure rules. The direct semantic owner should be [UID:00009Q][ObjectList](../../../by-class/ObjectList.md), with emission routed through the class to [UID:0000M4][ObjectList](../../../by-file/ObjectList.md).

## Evidence Standards Used

Evidence checked:

- Target page metadata and body text.
- `auto-generated/by-memory-tool-report.md` Advanced-Error-Scan warning.
- `auto-generated/-ag-memory-coverage.md` generated owner/emitter row.
- `by-memory/-coverage-report.md` manual coverage row.
- `by-structure.md` rules for filename/content cleanup, direct `CANONICAL_OWNER`, `EMITTER_UIDS`, and the 90/90+ code-entry gate.
- [UID:00009Q][ObjectList](../../../by-class/ObjectList.md) and [UID:0000M4][ObjectList](../../../by-file/ObjectList.md) current owner evidence.
- Live IDA MCP function, byte, xref, callee, caller-disassembly, and decompilation checks.

The evidence is strong enough for rename, score `85/90`, and class owner/emitter routing. It is not strong enough for final C++ because multiple field/method names are still explicitly provisional.

## IDA MCP Facts

Live IDA MCP session:

- Session/database: `b001_0003gy`
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- `server_health`: `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`

Function/range facts from `lookup_funcs`:

| Query | IDA result | Meaning |
| --- | --- | --- |
| `0x00530d00` | `sub_530D00`, size `0x1d9` | exact target function, ends at `0x00530ed9` |
| `0x00530cf0` | inside `sub_530C90`, size `0x67` | preceding NumberInputDialog destructor region |
| `0x00530ed9` | not a function | target endpoint / padding start |
| `0x00530ee0` | `sub_530EE0`, size `0x37d` | following ObjectList lifecycle constructor |
| `0x005314a0` | `sub_5314A0`, size `0x73c` | later ObjectList insert/categorize helper called by target |
| `0x0053c5e0` | `sub_53C5E0`, size `0x60` | LightingObjectPane construction helper called by target |
| `0x0053c980` | `sub_53C980`, size `0x35` | LightingObjectPane set-intensity helper called by target |
| `0x004dda30` | `sub_4DDA30`, size `0x27` | StaticObjImageLib metadata lookup called by target |
| `0x0050e300` | no function | small MapPane wrapper is not separately modeled by IDA as a function |

Boundary byte facts from `get_bytes`:

| Bytes sampled | Result | Meaning |
| --- | --- | --- |
| `0x00530cf0` size `32` | `sub_530C90` epilogue through `0x00530cf7`, then nine `0xcc` bytes, then `55 8b ec` at `0x00530d00` | exact padding before target |
| `0x00530ed0` size `32` | target epilogue through `0x00530ed9`, then seven `0xcc` bytes, then `55 8b ec` at `0x00530ee0` | exact padding after target |
| `0x0050e300` size `32` | wrapper loads `[ecx+0x424]`, null-checks, tail-jumps to `sub_530D00`, then padding before `0x0050e320` | MapPane wrapper evidence, not ownership transfer |

Xref/callee facts:

- `xrefs_to 0x00530d00`: one code xref at `0x0050e30e`, not in an IDA-modeled function.
- `disasm 0x0050e300`: wrapper does `mov ecx, [ecx+424h]`, tests for null, and tail-jumps to `sub_530D00`; this is a MapPane-to-ObjectList dispatch wrapper.
- `callees 0x00530d00`: `sub_4DDA30`, `sub_5376C0`, `sub_53C980`, `sub_4F4AA0`, `sub_5374D0`, `sub_53C5E0`, and `sub_5314A0`.
- `xrefs_to 0x005314a0`: includes `0x00530e8f` inside `sub_530D00`.
- `xrefs_to 0x0053c5e0`: includes `0x00530e79` inside `sub_530D00`.
- `xrefs_to 0x0053c980`: includes `0x00530dbe` inside `sub_530D00`.
- `xrefs_to 0x004dda30`: includes `0x00530d36` inside `sub_530D00`.

Decompiler facts from `decompile 0x00530d00`:

- Signature decompiles as `int __thiscall sub_530D00(_WORD *this, __int16 a2)`.
- It calls `sub_4DDA30(a2)` to fetch static-object metadata.
- It iterates ObjectList row buckets through `this + 0x28`.
- It compares each candidate object's id at object word index `148` / byte offset `0x128` against the input id.
- It reads an attached light via `sub_5376C0`.
- If a light exists and metadata value is negative, it removes the light from the ObjectList list at `this + 0x3c`, detaches it through a virtual call, and destroys it.
- If a light exists and metadata value is non-negative, it calls `sub_53C980` to update intensity.
- If no light exists and metadata value is non-negative, it allocates 312 bytes, calls `sub_5374D0`, constructs a `LightingObjectPane` via `sub_53C5E0`, inserts it through `sub_5314A0`, and attaches it through a virtual call.

These facts support the target page's current behavioral interpretation and contradict the filename's older remove-by-id framing.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00530cf7-0x00530d00` | [UID:0000VN][-ignored](../../../by-memory/-ignored.md) | padding before target | ignored | n/a | `100/strong` | keep |
| `0x00530d00-0x00530ed9` | [UID:00023D][current target](../../../by-memory/0x00530d00-0x00530ed9.ObjectListRemoveByObjectIdHelper.md) | ObjectList static-object lighting sync helper | true | recommend `00009Q` | recommend `85/90` | rename and reroute |
| `0x00530ed9-0x00530ee0` | [UID:0000VN][-ignored](../../../by-memory/-ignored.md) | padding after target | ignored | n/a | `100/strong` | keep |
| `0x00530ee0-0x00531473` | [UID:0001D1][ObjectListLifecycle](../../../by-memory/0x00530ee0-0x00531473.ObjectListLifecycle.md) | following ObjectList lifecycle aggregate | true | `00009Q` | `85/91` | supports class route |

No child split is needed for `00023D`.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0050e30e` | only xref to `0x00530d00`; tail-jumps after loading `MapPane + 0x424` into `ecx` | MapPane wrapper dispatches to ObjectList method; caller context does not make this a MapPane-owned method |
| `0x00530d36` | call to `sub_4DDA30` | StaticObjImageLib metadata lookup by static object id |
| `0x00530dbe` | call to `sub_53C980` | update existing LightingObjectPane intensity |
| `0x00530e79` | call to `sub_53C5E0` | construct new LightingObjectPane |
| `0x00530e8f` | call to `sub_5314A0` | insert/categorize new light through ObjectList helper surface |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- The target page already retitles the function as `ObjectList Static Object Lighting Sync Helper` and states the old `RemoveByObjectId` name is incomplete.
- [UID:00009Q][ObjectList](../../../by-class/ObjectList.md) lists `0x00530d00-0x00530ed9` as a static-object lighting sync helper and records the ObjectList layout/caller evidence. It is currently `85/88`.
- [UID:0000M4][ObjectList](../../../by-file/ObjectList.md) lists this helper as part of `map/ObjectList.cpp` and says to keep it with ObjectList while the final public method name remains provisional. It is currently `85/88`.
- `by-memory/-coverage-report.md` already uses the row label `ObjectListStaticObjectLightingSyncHelper`, even though the link still points to the old filename.

Existing docs that are stale or incomplete:

- The target filename still says `ObjectListRemoveByObjectIdHelper`.
- Generated `-ag-memory-coverage.md` currently shows owner/emitter `0000M4` for `00023D`; under the current narrow-owner rule, this should route through class UID `00009Q`.
- The target body lacks the exact compact filename label for either the current old filename or the recommended new filename, which is why the current Advanced-Error-Scan entry appears.
- Several by-* documents still contain UID links with the old path/display text. Validator/reverse-reference update should handle many of these after rename; any stragglers should be mechanically updated.

Generated/coverage state:

- Current generated row:

```text
| [UID:00023D][0x00530d00-0x00530ed9.ObjectListRemoveByObjectIdHelper](by-memory/0x00530d00-0x00530ed9.ObjectListRemoveByObjectIdHelper.md) | emits | `0000M4` | `0000M4` |  | no | `auto-generated/NexusTK/map/ObjectList.cpp` | `by-memory/0x00530d00-0x00530ed9.ObjectListRemoveByObjectIdHelper.md` |  |
```

- Expected generated row after supervisor repair and regeneration:

```text
| [UID:00023D][0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper](by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md) | emits | `00009Q` | `00009Q` |  | no | `auto-generated/NexusTK/map/ObjectList.cpp` | `by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md` |  |
```

Do not edit generated rows manually.

## Ranked Ownership Analysis

### 1. [UID:00009Q] ObjectList class

- Evidence for: IDA decompiles `0x00530d00` as a `__thiscall` function over ObjectList-shaped fields; it scans ObjectList row buckets at `this + 0x28`, accesses the ObjectList lighting/global tier at `this + 0x3c`, calls the later ObjectList insertion helper `0x005314a0`, and sits immediately before ObjectList lifecycle code. The ObjectList class page is `85/88` and records this method family.
- Evidence against: final public method name is still provisional; the only direct caller is a MapPane wrapper.
- Decision: best direct semantic owner. The MapPane wrapper is a caller/adapter, not ownership. Recommend `CANONICAL_OWNER:00009Q` and `EMITTER_UIDS:00009Q`.

### 2. [UID:0000M4] ObjectList file

- Evidence for: final source output belongs in `NexusTK/map/ObjectList.cpp`; current metadata already emits there; by-file ObjectList is `85/88`.
- Evidence against: by-structure now requires the narrowest true owner. This helper is a class method/helper over ObjectList layout, so file-level ownership is broader than necessary.
- Decision: keep as the source root reached through the class emitter chain, but do not keep it as direct `CANONICAL_OWNER`.

### 3. [UID:00007Q] / [UID:0000L3] MapPane

- Evidence for: only observed direct caller is the MapPane wrapper at `0x0050e300-0x0050e315`, and that wrapper loads the ObjectList pointer from `MapPane + 0x424`.
- Evidence against: the implementation uses ObjectList internals and later ObjectList helpers; MapPane contributes only the wrapper and the object-list pointer. Consumer/caller evidence alone does not override class-method semantics.
- Decision: reject as direct owner/emitter for `00023D`. The MapPane wrapper may deserve its own exact MapPane child if not already split, but this function should stay ObjectList-owned.

### 4. Keep old filename with alias only

- Evidence for: adding `ObjectListRemoveByObjectIdHelper` as a search alias would clear the current scanner warning with a tiny edit.
- Evidence against: the old compact filename is materially stale and contradicts the documented behavior. The manual coverage row already uses `ObjectListStaticObjectLightingSyncHelper`.
- Decision: reject as the main repair. Accept only as a fallback if supervisor defers rename; do not treat it as the best fix.

## Negative Evidence Summary

- Not a split/merge issue: IDA reports a single function at `0x00530d00` size `0x1d9`, and raw bytes show padding before `0x00530d00` and after `0x00530ed9`.
- Not an IDA function repair issue: the target function, following constructor, and key callees are modeled; the MapPane wrapper is not modeled as a function but is small, understood, and outside this target.
- Not a no-owner/non-emitting case: this is reconstructable ObjectList source code with a valid route to `NexusTK/map/ObjectList.cpp`.
- Not a code-entry case: despite strong behavior evidence, unresolved final source names keep it below the current `90/90+` reconstruction C++ bar.
- Not a pooled/shared multi-emitter case: the function is one class method body; it should not be emitted into both MapPane and ObjectList.

## Exact Recommended Edits

### Rename

Rename:

```text
by-memory/0x00530d00-0x00530ed9.ObjectListRemoveByObjectIdHelper.md
```

to:

```text
by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md
```

### Header metadata

Change:

```text
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000M4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000M4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

to:

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00009Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00009Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep:

```text
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Status body insertion

Insert under `## Status`, before `- Disposition:`:

```markdown
- Filename label: `ObjectListStaticObjectLightingSyncHelper`; current compact filename/search label for this static-object lighting synchronization helper.
- Former filename label: `ObjectListRemoveByObjectIdHelper`; retained only as a stale search alias because live IDA shows the old remove-by-id name describes only one branch.
```

### Suggested Changes entry

Append to `## Changes`:

```markdown
### 2026-06-13 - MEMTOOL Stale Filename And Owner-Route Audit

- What existed before: the file path and generated row still used `ObjectListRemoveByObjectIdHelper`, while the page title/body and coverage row already described the function as `ObjectListStaticObjectLightingSyncHelper`. Metadata routed directly to [UID:0000M4][ObjectList](by-file/ObjectList.md).
- What changed: rename the file to `0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md`, add compact filename/search labels, raise completion to `85`, and route semantic ownership/emission through [UID:00009Q][ObjectList](by-class/ObjectList.md).
- Why: live IDA MCP reconfirmed `sub_530D00` as an exact `0x1d9`-byte ObjectList method with padding before/after, a MapPane wrapper tail-jump, StaticObjImageLib metadata lookup, row/global ObjectList scans, and LightingObjectPane remove/update/create behavior. The old remove-by-id filename is stale, and current by-structure rules prefer the narrow class owner over a direct file owner for class methods.
```

### Mechanical UID-link replacement after rename

Where validator/reverse-reference repair does not update links automatically, replace this UID-link target:

```markdown
[UID:00023D][0x00530d00-0x00530ed9.ObjectListRemoveByObjectIdHelper](by-memory/0x00530d00-0x00530ed9.ObjectListRemoveByObjectIdHelper.md)
```

with:

```markdown
[UID:00023D][0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper](by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md)
```

Relevant non-generated by-* files currently containing the old UID link include:

- `by-class/ObjectList.md`
- `by-file/ObjectList.md`
- `by-meta/client_map_system.md`
- `by-project-structure/proposed-source-tree.md`
- `by-memory/-coverage-report.md`
- `by-memory/-ignored.md`
- `by-memory/0x0053c980-0x0053c9b5.LightingObjectPaneSetIntensity.md`

Do not manually edit generated `auto-generated/*` or `project-level/*` paths; regenerate them through the normal tool flow.

## Exact Coverage-Report Row

Placement context: replace the existing `00023D` row between the ignored padding row `0x00530cf7-0x00530d00` and the ignored padding row `0x00530ed9-0x00530ee0`.

Replacement row for `by-memory/-coverage-report.md`:

```markdown
    - [UID:00023D][0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper](by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md) 0x00530d00-0x00530ed9 | class method | ObjectListStaticObjectLightingSyncHelper : reconstructable : 85% : strong : Live IDA reconfirms ObjectList static-object lighting sync helper bounds 0x00530d00-0x00530ed9, single MapPane wrapper tail-jump at 0x0050e30e, StaticObjImageLib metadata lookup, row/global ObjectList scans, attached-light read/remove/update/create flow, LightingObjectPane constructor/set-intensity callees, ObjectList insert helper, padding before/after, direct [UID:00009Q][ObjectList](by-class/ObjectList.md) class ownership with source emission through [UID:0000M4][ObjectList](by-file/ObjectList.md), stale `ObjectListRemoveByObjectIdHelper` filename repair, unresolved final method/field names, and final C++ remains blank below the 90/90+ code-entry bar.
```

## Validation And Regeneration Recommendation

Validation was not run by B001 because this assignment produced a report only and did not modify by-* documentation.

Commands/evidence run by B001:

- Read `goal.md`, `inference_research.md`, target page, relevant `by-structure.md` rules, ObjectList class/file docs, generated coverage row, manual coverage row, and Advanced-Error-Scan warning.
- `Select-String -SimpleMatch ObjectListRemoveByObjectIdHelper` against the target page: no match.
- `rg -n "ObjectListRemoveByObjectIdHelper|ObjectListStaticObjectLightingSyncHelper" project-documentation --glob "*.md"` to inventory stale links and generated references.
- IDA MCP `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `xrefs_to`, `callees`, `disasm`, and `decompile` checks summarized above.

Recommended supervisor tool flow after applying the rename and edits:

> Executable block R001 was removed from this report and preserved verbatim in [B001-MEMTOOL-00530D00-ObjectListRemoveByObjectIdHelper-removed.md](B001-MEMTOOL-00530D00-ObjectListRemoveByObjectIdHelper-removed.md). The archived block is non-authoritative and must not be executed.

Then regenerate the normal memory coverage/tool report so `auto-generated/by-memory-tool-report.md` and `auto-generated/-ag-memory-coverage.md` reflect the new filename and owner/emitter route. Do not use dry-run validation for this supervisor application, and do not use a memory-range repair mode for this item.

After validation/regeneration, run a normal text check such as:

> Executable block R002 was removed from this report and preserved verbatim in [B001-MEMTOOL-00530D00-ObjectListRemoveByObjectIdHelper-removed.md](B001-MEMTOOL-00530D00-ObjectListRemoveByObjectIdHelper-removed.md). The archived block is non-authoritative and must not be executed.

Expected remaining old-name references should be intentional search-alias prose only, not active UID-link paths or generated current rows.

## Score And Code-Entry Effect

Before:

- `84/90`
- Direct route to file UID `0000M4`
- Stale filename warning present
- Blank C++ block

Recommended after:

- `85/90`
- Direct owner/emitter route through class UID `00009Q`
- Filename aligned with documented behavior
- Blank C++ block retained

The one-point completion increase is justified by the current audit resolving the stale filename, validating the exact function/range/callee/caller facts live, and bringing direct ownership into current by-structure compliance. Confidence should remain `90` rather than increase because final source-facing method name and several field/slot names remain unresolved.

No final reconstruction C++ should be added until the item reaches the active `90/90+` code-entry bar and the MapPane wrapper name, `StaticObjEntry` lighting fields, ObjectList tier names, StaticObjectPane virtual slots, and surrounding dependencies are source-output quality.

## Follow-Up Actions

Supervisor actions:

- Apply the rename and metadata/body edits above.
- Apply or queue the exact manual coverage row replacement above.
- Run normal validator `--apply` on the renamed file and regenerate normal generated reports.
- Confirm no current generated or by-* UID-link path still points to `ObjectListRemoveByObjectIdHelper.md` except intentional stale-alias prose.

A-agent actions:

- Do not add reconstruction C++ to `00023D` yet.
- Continue resolving `StaticObjEntry` lighting fields, ObjectList tier names, and StaticObjectPane attach/detach virtual slot names before code-entry.
- Consider splitting or documenting the small MapPane wrapper at `0x0050e300-0x0050e315` separately if it remains folded into broader MapPane coverage and becomes relevant to final source output.

B001 future research actions:

- None required for this MEMTOOL warning after supervisor repair.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `85/90`; not higher because source-facing names remain provisional.
- Remaining uncertainty: exact original method name is not proven. `ObjectListStaticObjectLightingSyncHelper` is the best current behavior label, not a recovered source symbol.

## Validator Results

- Commands run: none.
- Results: not applicable; report-only assignment.
- Unresolved validator warnings/errors: the current Advanced-Error-Scan warning should remain until the supervisor applies the rename/body label and regenerates the report.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/B001-MEMTOOL-00530D00-ObjectListRemoveByObjectIdHelper.md`
- Modified: none.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/B001-MEMTOOL-00530D00-ObjectListRemoveByObjectIdHelper.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:23","uid":"00023D"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at B001-MEMTOOL-00530D00-ObjectListRemoveByObjectIdHelper-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/B001-MEMTOOL-00530D00-ObjectListRemoveByObjectIdHelper.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00023D"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
