** TARGET-REPORT-UID:000204 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# UID000204 RankingRewardEntryItemAt Source-Quality Report

## Finalized Report / Current Recommendation

Recommendation: update [UID:000204] `by-memory/0x0045db60-0x0045db9e.RankingRewardEntryItemAt.md` as an evidence-backed, reconstructable, owner-known reward-entry support method that emits through [UID:0000BP][RankingRewardInfoDialog].

Recommended target metadata:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `85` | `90` |
| `CONFIDENCE` | `89` | `92` |
| `CANONICAL_OWNER` | `0000BP` | `0000BP` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `0000BP` | `0000BP` |
| `EMITTER_POSITION_OPTIONAL` | blank | blank |
| `RECONSTRUCTION_CPP CODE` | blank | formal `RankingRewardEntry::ItemAt(int index)` body |

The repaired conclusion is that a private/support `RankingRewardEntry::ItemAt(int index)` representation is defensible. The existing owner [UID:0000BP] already emits the `RankingRewardItem` and `RankingRewardEntry` support declarations; the target body has exact bytes, exact range boundaries, exact receiver layout, and exact behavior. The lack of an IDA function object, lack of ordinary xrefs, lack of pointer/immediate hits, and inline paint traversal cap confidence and prove that the method should be documented as support/private, not public UI API. They do not justify clearing the emitter while leaving a source-shaped method blank.

## Supporting Research

Evidence sources used:

- Current assignment: `tools/leaser/Agents/Agent-B005/goal.md`.
- Project workflow: `.codex/skills/ntk-b-agent-workflow/SKILL.md`, `references/b-agent-research-and-implementation-workflow.md`, `references/score-blocker-audit-standard.md`, and `by-structure.md` IDA MCP Output Discipline.
- Target page: `by-memory/0x0045db60-0x0045db9e.RankingRewardEntryItemAt.md`.
- Direct support docs: `by-class/RankingRewardInfoDialog.md`, `by-file/RankingDialog.md`, `by-memory/0x00458610-0x0045f9f5.RankingDialog.md`, `by-type/by-vtable/RankingDialogVtableFamily.md`, `by-memory/0x00610980-0x00610e38.RankingDialogReadOnlyData.md`, and `by-global/g_pRankingRewardInfoDialog.md`.
- Generated read-only context: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, and `auto-generated/-ag-coverage-report-by-memory.md`.
- Historical executed B report lead: `executed-b-agent-research/B001/0001ZE-0001ZJ-ranking-reward-entry-vector-source-quality.md`.
- Current IDA MCP session: `b010_00032w_20260703`, NexusTK IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Numeric conversions from `tools/int_convert.py`: `0x208` = 520, `0x230` = 560, `0x224` = 548, `0x228` = 552, `0x22c` = 556, `0x26c` = 620, `0x204` = 516, `0x206` = 518, and `0x7d` = 125 (Verified with int_convert.py).

The old pause incident for stale session `2ec9c08f` is historical only. All final MCP-backed claims in this report use restored session `b010_00032w_20260703`.

## Target

- UID: `000204`.
- Target page: `by-memory/0x0045db60-0x0045db9e.RankingRewardEntryItemAt.md`.
- Address range: `0x0045db60-0x0045db9e`.
- Current assignment queue row: `auto-generated/-ag-research-tracker.md` listed the target at assignment time as `85/89`, combined `87.0`, reconstructable `true`, reports `0`.
- Pre-callback by-* metadata was `COMPLETION:85`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000BP`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BP`, blank optional position, blank formal C++.
- Pre-callback target summary said live IDA confirmed the raw body, no ordinary incoming xrefs, `0x208` bounds math, adjacent boundaries, and reward-info paint inline traversal, with final C++ blank.
- Pre-callback target page contained a prose C-like "Equivalent reconstruction shape" outside the formal C++ block. The implementation replaced that with the exact formal C++ body from this report and did not leave duplicate sample C++ outside the formal block.

## Current Target State

UID000204 now documents a complete raw body that behaves like a nested reward-item index accessor for `RankingRewardEntry`. It uses `this + 0x224` as the nested item-vector begin pointer and `this + 0x228` as the end pointer, computes a signed count by dividing `(end - begin)` by `0x208`, returns null when `count <= index`, and otherwise returns `begin + index * 0x208`.

The accepted implementation resolved the prior source-output defect. The page keeps `EMITTER_UIDS:0000BP`, now has formal `RankingRewardEntry::ItemAt(int index)` C++, and preserves the lack of an explicit negative-index guard. Because the class support page already emits `RankingRewardEntry` and `RankingRewardItem`, and because the raw helper has exact source-shaped accessor behavior, the source route is now represented as a private/support method through [UID:0000BP].

Support state after implementation:

- `by-class/RankingRewardInfoDialog.md` has source-level support declarations for `RankingRewardEntry` and `RankingRewardItem`. It records `RankingRewardEntry` as a 560-byte row (`0x230`, Verified with int_convert.py) with the item-vector triplet at `+0x224/+0x228/+0x22c`, includes `RankingRewardItem *ItemAt(int index);`, and preserves `RankingRewardItem` as a 520-byte row (`0x208`, Verified with int_convert.py) with `name[256]`, `quantity` at `+0x200`, `iconId` at `+0x204`, `paletteIndex` at `+0x206`, and a reserved byte at `+0x207`.
- `by-file/RankingDialog.md` routes UID000204 through [UID:0000BP][RankingRewardInfoDialog] as `RankingRewardEntry::ItemAt(int index)` and records `NexusTK/ui/dialogs/RankingDialog.cpp` source placement for the broader ranking subsystem.
- `by-memory/0x00458610-0x0045f9f5.RankingDialog.md` lists UID000204 at `0x0045db60-0x0045db9e` as a source-ready `RankingRewardEntry::ItemAt(int index)` support accessor through [UID:0000BP].

## Heuristic / Inference Reanalysis And Validation

The strongest source-facing name remains `RankingRewardEntry::ItemAt(int index)`. `ItemAt` is preferred over `GetItemAt` because the current page title already uses `ItemAt`, the body is an indexed row accessor rather than a UI getter, and the support declaration already models `itemsBegin/itemsEnd/itemsCapacity` as a vector-like triplet. That name is inferred from:

- The receiver is a reward-entry row, not the dialog itself: `ecx + 0x224` and `ecx + 0x228` match the nested item-vector begin/end fields already documented on `RankingRewardEntry`.
- The return value is a row pointer inside the nested reward item array: success path multiplies the index by `0x208` and adds it to the begin pointer.
- The same `0x208` row stride and `+0x204/+0x206/+0x200` item fields are used by the parser, storage helpers, destroy helpers, clone helpers, and paint loop.
- The owner is the reward-info dialog source area because the parser, packet handler, constructor/destructor, paint, nested vector helpers, and support declarations all belong to [UID:0000BP][RankingRewardInfoDialog].

The final source shape is ready to emit as a support/private method despite route-negative evidence:

- IDA still reports `0x0045db60` as not a function, but the bytes form a complete `__thiscall`-shaped support body ending in `retn 4`.
- `xrefs_to` for `0x0045db60` returns no ordinary incoming refs, but preserved out-of-line helpers can remain uncalled after inlining or route pruning; this is a confidence cap, not a behavioral blocker.
- Pointer/immediate byte searches for `0x0045db60`, `0x0045db61`, `0x0045db91`, and `0x0045db9e` returned no matches, so the method should be documented as support/private and not as a routed public API.
- The reward-info paint function at `0x0045df90` inlines item traversal rather than calling this helper, but its inline traversal validates the exact row layout and makes the formal method body source-coherent.
- The helper does not guard negative indices. Its body returns a before-begin pointer for a negative index when the count is greater than that negative index. The formal C++ must preserve that behavior by testing only `if (itemCount <= index)` and must not add `index < 0`.

Inference validation result: the target is real NexusTK reward-entry behavior, not padding or dead unrelated bytes, and current support declarations make a formal support-method body safe. The evidence supports improving documentation score, keeping the emitter, adding the declaration prototype to [UID:0000BP], and inserting the formal method body in UID000204.

## Evidence Standards Used

- Direct IDA/MCP facts are treated as authoritative for address boundaries, function/non-function state, disassembly, decompilation, xrefs, and byte searches.
- Current by-* docs are treated as durable project documentation when their claims align with current MCP evidence.
- Generated reports are read-only leads for queue status, emitted/non-emitted classification, and coverage symptoms; they are not source of truth for ownership.
- Historical executed B reports are leads only. B001's 2026-06-16 reward-vector report is used because it matches UID000204/address/name and its claims were rechecked with current MCP.
- Inferred names and source placement are accepted only when multiple independent facts agree: receiver layout, surrounding functions, owner file/class context, parser/paint/storage usage, and negative owner alternatives.
- Score movement follows the score-blocker standard: the current blocker is resolved into an implementation-ready formal C++ repair rather than left as "needs more investigation" or no-route deferral.

## Evidence Checked

Current MCP session `b010_00032w_20260703`:

- `server_health` returned status `ok` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.
- Schema-current MCP flow was used: `initialize`, `tools/list`, then narrow `tools/call` requests. Active tools included `server_health`, `lookup_funcs`, `search_text`, `decompile`, `disasm`, `xrefs_to`, and `find_bytes`.
- `lookup_funcs`:
  - `0x0045db10`: `sub_45DB10`, size `0x3`.
  - `0x0045db20`: `sub_45DB20`, size `0x4`.
  - `0x0045db50`: `sub_45DB50`, size `0x4`.
  - `0x0045db54`: not a function.
  - `0x0045db60`: not a function.
  - `0x0045db9e`: not a function.
  - `0x0045dba0`: `sub_45DBA0`, size `0x1b6`.
  - `0x0045d7e0`: `sub_45D7E0`, size `0x326`.
  - `0x0045ddd0`: `sub_45DDD0`, size `0x1bc`.
  - `0x0045df90`: `sub_45DF90`, size `0xa83`.
  - `0x0045eae0`: `sub_45EAE0`, size `0x163`.
  - `0x0045f020`: `sub_45F020`, size `0x87`.
- `disasm` at `0x0045db60` with `max_instructions=40` showed the complete raw helper: `push ebp`, `mov esi,[ecx+224h]`, multiplier `0x7e07e07f`, `mov ecx,[ecx+228h]`, `sub ecx,esi`, signed divide-by-`0x208` sequence, argument load from `[ebp+8]`, `cmp eax,ecx`, null return when not below count, success `imul eax,ecx,208h`, `add eax,esi`, and `retn 4`. The same bounded disassembly also showed `align 10h` at `0x0045db9e` and constructor prologue at `0x0045dba0`.
- `xrefs_to`:
  - `0x0045db60`: no xrefs.
  - `0x0045db61`: internal fall-through from `0x0045db60`.
  - `0x0045db64`: internal fall-through from `0x0045db63`.
  - `0x0045db91`: internal branch from `0x0045db88`.
  - `0x0045db9b`: internal fall-through from `0x0045db9a`.
  - `0x0045db9e`: no xrefs.
  - `0x0045dba0`: code xref from `0x00458abd` in `sub_458A10`.
  - `0x0045df90`: data xref from `0x00610c08` vtable paint slot.
  - `0x0045ddd0`: data xref from `0x00610c34` secondary vtable packet-handler slot.
- `find_bytes`:
  - Little-endian pointers/immediates for `0x0045db60`, `0x0045db61`, `0x0045db91`, and `0x0045db9e` returned no matches.
  - Exact body-prefix bytes `55 8B EC 56 8B B1 24 02 00 00 B8 7F E0 07 7E` matched only `0x0045db60`.
  - Boundary/body bytes `CC CC CC CC CC CC CC CC CC CC CC CC 55 8B EC 56 8B B1 24 02 00 00` matched only `0x0045db54`, confirming the twelve-byte padding before the helper.
- `search_text` bounded to paint function `0x0045df90-0x0045ea20`:
  - `208h` hit at `0x0045e9b3`: paint adds `0x208` to its item-row cursor.
  - `26Ch` hit at `0x0045e4b6`, `0x0045e553`, and `0x0045e590`, matching reward-entry vector traversal inside the dialog.
  - `204h` hit at `0x0045e7cf`: paint reads item icon id at row `+0x204`.
  - `206h` hit at `0x0045e86e` and `0x0045e8fc`: paint reads item palette/index byte at row `+0x206`.
- `decompile` at `0x0045d7e0` confirmed parser/accessor group behavior:
  - It parses rank/symbol strings into `this`, `this+16`, and `this+32`.
  - It writes bytes at `this+544` and `this+545`.
  - It loops over item count, builds a 520-byte temporary item row, stores quantity at byte offset `512`, icon id at byte offset `516`, and palette/index byte at byte offset `518`.
  - It appends rows to nested vector triplet `this+548/+552/+556`, using `sub_45EAE0` when growth is needed or `qmemcpy(...,0x208)` and `end += 520` when capacity exists.

Local report/doc checks:

- Searched executed reports with terms `000204`, `0x0045db60`, `RankingRewardEntryItemAt`, `RankingReward`, `RewardEntry`, and `45db60`.
- B001 executed report recorded UID000204 as a raw helper at `0x0045db60-0x0045db9e`, source-quality eligible, owner/emitter [UID:0000BP], and final C++ blank pending declarations. The current report accepts the owner and behavior and supersedes the blank-code blocker because [UID:0000BP] now has enough support declaration detail to host `RankingRewardEntry::ItemAt(int index)`.
- `RankingRewardInfoDialog.md` already documents the `RankingRewardEntry` and `RankingRewardItem` structures and the source-quality decision that reward vector helpers route to [UID:0000BP].
- `RankingDialog.md` and the broad `RankingDialog` memory page already contain reward-info source placement and the exact UID000204 range row.

## Function / Child Inventory

| Range/address | Current MCP state | Source-quality interpretation |
| --- | --- | --- |
| `0x0045db10` | Function `sub_45DB10`, size `0x3`; no ordinary call evidence found in prior target doc context. | Tiny field accessor in the reward-entry parser/accessor neighborhood. |
| `0x0045db20` | Function `sub_45DB20`, size `0x4`; no ordinary call evidence found in prior target doc context. | Tiny field accessor in the same neighborhood. |
| `0x0045db50` | Function `sub_45DB50`, size `0x4`. | Previous modeled accessor ending immediately before padding. |
| `0x0045db54-0x0045db60` | Twelve `0xcc` bytes confirmed by body-prefix byte search. | Alignment padding before UID000204. |
| `0x0045db60-0x0045db9e` | Not a function; unique raw helper body starts at `0x0045db60`; body returns by `0x0045db9b`; `0x0045db9e` is alignment. | UID000204 reward-entry nested item accessor; reconstructable source-emitting support method through [UID:0000BP]. |
| `0x0045db9e-0x0045dba0` | Not a function; two `0xcc` alignment bytes before constructor. | Padding after UID000204; do not extend target into constructor. |
| `0x0045dba0` | Function `sub_45DBA0`, size `0x1b6`; code xref from `0x00458abd`. | Reward-info dialog constructor; successor boundary is live and separate. |
| `0x0045d7e0` | Function `sub_45D7E0`, size `0x326`. | Parser/accessor group proving reward-entry/item field layout and nested item vector writes. |
| `0x0045df90` | Function `sub_45DF90`, size `0xa83`; vtable paint slot data ref. | Paint function that inlines item-vector traversal and row-field reads. |
| `0x0045eae0` | Function `sub_45EAE0`, size `0x163`. | Reward-item vector insert/growth helper for the same `0x208` rows. |
| `0x0045f020` | Function `sub_45F020`, size `0x87`. | Reward-entry vector destroy path with nested item cleanup. |

No split is recommended. UID000204 already has an exact child-sized page. The only range repair is a documentation update to keep the two alignment windows and successor constructor boundary explicit.

## Ranked Ownership Analysis

1. [UID:0000BP][RankingRewardInfoDialog] as canonical owner: accepted. The receiver layout, parser, paint, packet handler, constructor/destructor, vector helpers, vtable data, singleton, and support declarations all converge on reward-info dialog source. The raw helper belongs to the reward-entry support data model used by that dialog.
2. [UID:0000MZ][RankingDialog] as direct owner/emitter: rejected as direct owner. The broader file contains the reward-info dialog module, but UID000204's receiver is the reward-entry row and the direct class/source support is already [UID:0000BP]. `RankingDialog` remains file-level context, not the immediate owner.
3. [UID:0001ZF][RankingRewardEntryParseAndAccessors] as owner: rejected as direct owner because it is a sibling by-memory group, not a source-owner page. It proves layout and nearby parser/accessor context but should not emit UID000204.
4. [UID:0001ZG][RankingRewardInfoDialogCore] as owner: rejected as direct owner. The constructor/paint/packet-handler range is the adjacent live dialog core, but UID000204 sits before the constructor with padding separation and does not belong inside that exact range.
5. No-owner/non-emitting: rejected. [UID:0000BP] is strong, and the support declarations plus exact body are enough for a formal support method. No-xref evidence is preserved as a confidence cap, not as a reason to clear `EMITTER_UIDS`.
6. Padding/data/dead unrelated code: rejected. The body is unique, structured code with reward-entry offsets and the `0x208` item stride; only route evidence is absent.

## Source Placement

Canonical source placement remains under the reward-info dialog support area inside the ranking dialog module, not a new global utility file. The durable source-facing data types are `RankingRewardEntry` and `RankingRewardItem`, already documented by [UID:0000BP]. UID000204 should be emitted as the out-of-line support method for that data model.

The emitted source route is [UID:0000BP], whose formal C++ already emits the `RankingRewardEntry`/`RankingRewardItem` declarations. The required support sync is to add the `RankingRewardItem *ItemAt(int index);` prototype to `RankingRewardEntry`. The current paint path uses inline traversal, and no pointer/immediate or ordinary call route reaches `0x0045db60`; those facts limit confidence and public API claims but do not prevent representing the observed private/support method.

## Range / Split / Padding / Reclassification Analysis

The range is exact enough and should not be split:

- Start `0x0045db60` is proven by twelve `0xcc` padding bytes at `0x0045db54-0x0045db60`, followed by a complete prologue.
- Body ends at the second `retn 4` at `0x0045db9b`; `0x0045db9e-0x0045dba0` is alignment before the constructor.
- Successor `0x0045dba0` is a modeled constructor with a real code xref from `0x00458abd`, so extending UID000204 forward would contaminate it with a separate live function.
- Previous `0x0045db50-0x0045db54` is a separate tiny modeled accessor.

Reclassification recommendation: keep `RECONSTRUCTABLE:TRUE`, keep owner [UID:0000BP], keep `EMITTER_UIDS:0000BP`, and insert formal C++ for the exact source-shaped accessor. This is not a container conversion and does not require child creation.

## First-Draft C++ Recommendation

Insert this exact formal C++ in UID000204's `RECONSTRUCTION_CPP CODE` block:

```cpp
RankingRewardItem *RankingRewardEntry::ItemAt(int index)
{
    int itemCount = static_cast<int>(itemsEnd - itemsBegin);

    if (itemCount <= index)
        return NULL;

    return itemsBegin + index;
}
```

The body intentionally has no `index < 0` check. The assembly compares only `itemCount` against `index`; it returns null when `itemCount <= index` and otherwise computes `begin + index * 0x208`. With typed `RankingRewardItem *` fields, `itemsEnd - itemsBegin` yields the row count and `itemsBegin + index` yields the same byte address as `begin + index * 0x208`.

Add this exact support declaration line inside `struct RankingRewardEntry` in [UID:0000BP][RankingRewardInfoDialog], after the vector triplet fields:

```cpp
    RankingRewardItem *ItemAt(int index);
```

Route-negative facts still belong in the target as confidence caps: no modeled IDA function, no ordinary incoming xrefs, no pointer/immediate matches, and paint's inline traversal mean this is a private/support method, not proof of a public UI-facing API.

## Final Recommendation

Accept a documentation/source-quality repair with formal C++:

- Target UID000204 should become `90/92`, owner [UID:0000BP], reconstructable true, `EMITTER_UIDS:0000BP`, formal `RankingRewardEntry::ItemAt(int index)` C++.
- The target page should preserve the exact MCP evidence from session `b010_00032w_20260703`: server health, no-function lookup, raw body, no ordinary xrefs, no pointer/immediate matches, unique body bytes, padding boundaries, constructor successor boundary, parser field writes, and paint inline traversal.
- The target should explicitly preserve no-negative-index behavior in formal C++; do not add `index < 0`.
- Support docs should add the `RankingRewardItem *ItemAt(int index);` prototype under `RankingRewardEntry` and keep [UID:0000BP] as owner.

## Recommended Target Doc Changes

For `by-memory/0x0045db60-0x0045db9e.RankingRewardEntryItemAt.md`:

- Set `COMPLETION:90` and `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:0000BP`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000BP`.
- Keep `EMITTER_POSITION_OPTIONAL` blank.
- Replace the blank formal `RECONSTRUCTION_CPP CODE` with the exact `RankingRewardEntry::ItemAt(int index)` body from this report.
- Update the `Item Summary` to say the helper is an owner-known source-emitting reward-entry item accessor with current MCP evidence, no ordinary route, and formal C++ preserving the no-negative-index-check behavior.
- Replace the current illustrative C-like `Equivalent reconstruction shape` block with the formal block; avoid retaining a second informal snippet.
- Add current MCP session `b010_00032w_20260703` evidence: `server_health` OK, no-function `lookup_funcs`, exact raw disassembly, no ordinary xrefs, no pointer/immediate matches, unique body bytes, alignment windows, successor constructor boundary, parser field writes, paint inline traversal, and negative evidence for public/API route.
- Preserve the inferred names `RankingRewardEntry`, `RankingRewardItem`, `itemVectorBegin`, `itemVectorEnd`, `itemVectorCapacity`, `quantity`, `iconId`, `paletteIndex`, and the `0x208` stride / `0x230` entry size conversions with `(Verified with int_convert.py)`.
- Preserve rejected alternatives: dead/unrelated code, padding/data, generic vector helper, direct `RankingDialog` emitter, parser-group emitter, constructor/core inclusion, and adding a defensive negative-index guard.

## Recommended Support Doc Changes

If accepted, inspect and update only the directly relevant support docs that are stale:

- `by-class/RankingRewardInfoDialog.md`: add `RankingRewardItem *ItemAt(int index);` inside `struct RankingRewardEntry` after `itemsCapacity`; add a UID000204 note under method/source-quality decisions stating that current MCP session `b010_00032w_20260703` reconfirms the raw no-function/no-xref nested item accessor at `0x0045db60-0x0045db9e`, now represented as a source-emitting private/support method through [UID:0000BP]. Existing `RankingRewardEntry` and `RankingRewardItem` field declarations are already same-or-greater layout detail and should be preserved.
- `by-file/RankingDialog.md`: update the reward-info helper cluster note only if stale. It should say UID000204 now emits through [UID:0000BP] as `RankingRewardEntry::ItemAt(int index)` while remaining source-placed with reward-info dialog support, not broad [UID:0000MZ] ownership.
- `by-memory/0x00458610-0x0045f9f5.RankingDialog.md`: update the UID000204 row/detail only if stale. It should keep the exact range and raw nested reward-item index accessor behavior, and may add that it now emits through [UID:0000BP] with route-negative evidence preserved as a confidence cap.
- No `by-type`, `by-global`, generated, project-level, or coverage-report edit is recommended. Vtable and singleton support already prove `RankingRewardInfoDialog` context but do not route UID000204 itself.

## Score And Metadata Recommendation

Recommended score: `90/92`.

Completion increases from `85` to `90` because this report adds current MCP session `b010_00032w_20260703` evidence for:

- no-function state at the exact target start and end;
- exact raw disassembly and arithmetic;
- no ordinary xrefs to the start;
- internal-only branch/fall-through xrefs;
- no pointer/immediate matches for start/interior/end addresses;
- unique body bytes;
- exact padding and successor constructor boundaries;
- parser evidence for the same nested item-vector fields;
- paint evidence for the same row traversal, icon/palette reads, and inline access path;
- exact formal C++ insertion text and support declaration text.

Confidence increases from `89` to `92` because the behavior, layout, owner, range, support declaration context, formal method body, and rejected alternatives are now cross-checked by current MCP and support docs. It is capped below final-audit levels because the item still lacks a modeled function, ordinary call route, pointer/immediate reference, proven public source API, and exact original method spelling proof.

Metadata recommendations:

- `CANONICAL_OWNER:0000BP` remains correct because reward-info dialog owns the support declarations and all related parser/paint/storage/destructor behavior.
- `RECONSTRUCTABLE:TRUE` remains correct because this is project-owned reward-entry behavior, not runtime, padding, or unrelated bytes.
- `EMITTER_UIDS:0000BP` should remain because [UID:0000BP] already emits the support declarations needed by the method.
- Formal C++ should be inserted as `RankingRewardEntry::ItemAt(int index)` with no `index < 0` guard.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Resolution |
| --- | --- | --- |
| Is `0x0045db60` a real helper or padding/dead bytes? | `lookup_funcs`, `disasm`, unique body-prefix `find_bytes`, parser/paint/storage context. | Real reward-entry nested item accessor behavior. Padding/dead unrelated code rejected. |
| Should the page emit as `RankingRewardEntry::ItemAt(int)` now? | No-function state, no ordinary xrefs, no pointer/immediate matches, paint inline traversal, support declarations. | Yes. Exact bytes, exact type context, and [UID:0000BP] support declarations make a private/support method safe. Route-negative facts cap confidence and public API claims. |
| Does missing negative-index guard block formal C++? | Raw body uses `cmp count,index` and `jg success`; no lower-bound check. Paint loops from zero and does not call helper. | No. It must be preserved exactly by omitting `index < 0`; it blocks only defensive/source-polished rewrites that change behavior. |
| Should owner become `NONE`? | Reward-info support declarations, parser, paint, packet handler, vtables, singleton, vector helpers. | No. Owner [UID:0000BP] is strong and emitter remains [UID:0000BP]. |
| Should the helper stay under `RankingDialog` file-level emitter? | `RankingDialog` contains the broader ranking source file, but direct receiver and support model are reward-info. | No direct [UID:0000MZ] ownership. Emit through [UID:0000BP] and treat [UID:0000MZ] as file context only. |
| Does this require splitting or child pages? | Adjacent tiny accessors, padding windows, exact body, constructor successor. | No. Existing UID000204 page is exact. |

## Claim And Incorporation Ledger

| Claim | Destination if accepted | Action | Verification state |
| --- | --- | --- | --- |
| Current MCP session `b010_00032w_20260703` server health OK and schema-current tools were used. | Target evidence section. | incorporate | applied: target raw evidence now cites the current MCP session and health facts. |
| `0x0045db60` is not a modeled function, but bounded disassembly proves a complete raw helper body. | Target raw evidence/status. | incorporate | applied: target status/raw evidence records no-function lookup and the complete helper body. |
| Body reads begin/end at `+0x224/+0x228`, divides by `0x208`, returns null when `count <= index`, else returns `begin + index * 0x208`. | Target behavior. | incorporate | applied: target behavior and formal C++ preserve typed pointer arithmetic and `NULL` return. |
| No ordinary incoming xrefs, no useful pointer/immediate matches, and only internal body refs were found. | Target negative evidence/confidence-cap proof. | incorporate | applied: target raw evidence records no xrefs, pointer/immediate misses, and confidence-cap role. |
| Paint function proves the same nested item-vector layout inline through `0x208`, `+0x204`, and `+0x206`, but does not call UID000204. | Target and support note. | incorporate | applied: target raw evidence and support notes record paint inline traversal as confidence cap. |
| Parser at `0x0045d7e0` proves item-row writes and append/growth into `+0x224/+0x228/+0x22c`. | Target and class support note. | incorporate | applied: target parser/paint support and class support note preserve this detail. |
| Alignment `0x0045db54-0x0045db60` and `0x0045db9e-0x0045dba0` proves exact target range and separate constructor successor. | Target range section. | incorporate | applied: target raw evidence and broad memory support row include boundaries/successor. |
| [UID:0000BP] remains canonical owner. | Target metadata and support docs. | incorporate | applied: target metadata remains `CANONICAL_OWNER:0000BP`; support docs route UID000204 through [UID:0000BP]. |
| `EMITTER_UIDS:0000BP` should remain because [UID:0000BP] already emits the support declarations needed by the method. | Target metadata. | incorporate | applied: target keeps `EMITTER_UIDS:0000BP`, class support declaration added. |
| Formal C++ should be inserted as `RankingRewardEntry::ItemAt(int index)` with no `index < 0` guard. | Target C++ block. | incorporate | applied: target formal block contains exact accepted body using `NULL` and no negative-index guard. |
| `RankingRewardInfoDialog.md` support declarations should add `RankingRewardItem *ItemAt(int index);` inside `RankingRewardEntry`. | Support docs. | incorporate | applied: by-class support declaration added after `itemsCapacity`. |
| Direct `RankingDialog`, parser-group, constructor-core, generic vector, padding/data, dead-code alternatives, and defensive negative-index rewrites are rejected. | Target/support source-quality rationale. | incorporate | applied: target and support notes preserve these rejected alternatives; by-file notes [UID:0000MZ] is route context only. |

## Positive Evidence Summary

- The raw helper body is unique and structurally complete at `0x0045db60`.
- It uses the exact nested item-vector offsets already documented for `RankingRewardEntry`: begin at `+0x224` (548, Verified with int_convert.py), end at `+0x228` (552, Verified with int_convert.py), and capacity at `+0x22c` (556, Verified with int_convert.py) in related parser storage.
- It uses item stride `0x208` (520, Verified with int_convert.py), matching parser append, vector helpers, destroy/clone paths, and paint traversal.
- Parser decompilation writes item rows with quantity at `+0x200`, icon id at `+0x204` (516, Verified with int_convert.py), and palette/index at `+0x206` (518, Verified with int_convert.py).
- Paint bounded searches show inline traversal of the same rows and fields.
- Support docs already carry the source-facing type names `RankingRewardEntry` and `RankingRewardItem`, with direct reward-info ownership.
- Adjacent padding and constructor boundaries are explicit and current.

## Negative Evidence Summary

- `0x0045db60` is not a modeled IDA function in the current session.
- No ordinary incoming xrefs reach the helper start.
- No pointer/immediate byte matches were found for start, useful interior, or end/padding addresses.
- The reward-info paint path uses the same layout inline and does not call the standalone helper.
- The helper has no explicit negative-index guard; the formal C++ must not add one, and the method should be described as private/support rather than public UI API.
- Direct `RankingDialog` ownership is too broad; parser/accessor memory-group or constructor/core range ownership is the wrong granularity.
- Keeping `EMITTER_UIDS:0000BP` with blank formal C++ creates an empty-emitter/source-output contradiction; keeping the emitter with formal C++ resolves it.

## Validator Results

Implementation callback scoped validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

| File | Command ID | Timestamp | Exit | OK | Warnings / errors | Generated refresh |
| --- | --- | --- | ---: | ---: | --- | --- |
| `by-memory/0x0045db60-0x0045db9e.RankingRewardEntryItemAt.md` | `000000005603` | `2026-07-03T16:16:19-04:00` | `0` | `1` | warnings `0`, errors `0` | deferred, command id `000000005603` |
| `by-class/RankingRewardInfoDialog.md` | `000000005605` | `2026-07-03T16:16:32-04:00` | `0` | `1` | `missing_ref_uid:14` for pre-existing `0003X*` references, errors `0` | deferred, command id `000000005605` |
| `by-memory/0x00458610-0x0045f9f5.RankingDialog.md` | `000000005608` | `2026-07-03T16:16:49-04:00` | `0` | `1` | `missing_ref_uid:16` for pre-existing `0003X*` references, errors `0` | deferred, command id `000000005608` |
| `by-file/RankingDialog.md` | `000000005611` | `2026-07-03T16:18:12-04:00` | `0` | `1` | `missing_ref_uid:14` for pre-existing `0003X*` references, errors `0` | deferred, command id `000000005611` |

The validators also reported projected stats updates. No generated files, manual coverage reports, lifecycle/archive state, or supervisor ledgers were edited manually by B005.

## Changed Files

Changed during the report and accepted implementation callback:

- `tools/leaser/Agents/Agent-B005/research/000204-RankingRewardEntryItemAt-source-quality.md`
- `by-memory/0x0045db60-0x0045db9e.RankingRewardEntryItemAt.md`
- `by-class/RankingRewardInfoDialog.md`
- `by-memory/0x00458610-0x0045f9f5.RankingDialog.md`
- `by-file/RankingDialog.md`

No generated files, project-level generated files, coverage reports, lifecycle/archive state, or supervisor ledgers were edited manually. Validator-owned registry/projected stats/generated-refresh side effects were produced by the scoped validators above.

Leases used/released:

- Batch 1 leased and released: target `by-memory/0x0045db60-0x0045db9e.RankingRewardEntryItemAt.md`, support `by-class/RankingRewardInfoDialog.md`, and support `by-memory/0x00458610-0x0045f9f5.RankingDialog.md`.
- Batch 2 leased and released after B003's earlier lease expired: support `by-file/RankingDialog.md`.
- Final lease report check showed no active leases.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Not applicable. No manual supervisor-owned coverage or tracker edit is recommended. The accepted by-* metadata/source changes and formal C++ should be propagated by scoped validators and supervisor-owned lifecycle execution only.

## Implementation Tracking Checklist

- [x] Lease only `by-memory/0x0045db60-0x0045db9e.RankingRewardEntryItemAt.md` for the immediate target edit batch, then release after validation. Applied: target was leased in batch 1 and released after validators.
- [x] Target metadata: set `COMPLETION:90`, set `CONFIDENCE:92`, keep `CANONICAL_OWNER:0000BP`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:0000BP`, keep optional position blank, and insert formal C++. Applied in target; validator `000000005603`.
- [x] Target summary/status: state that current MCP session `b010_00032w_20260703` proves the exact raw reward-entry item accessor body and owner; route-negative evidence caps confidence but does not block private/support method emission. Applied in target summary/status/raw evidence.
- [x] Target behavior: preserve begin/end offsets `+0x224/+0x228`, item stride `0x208`, count calculation, null return on `count <= index`, success row pointer calculation, and no explicit negative-index guard. Applied in target behavior and formal C++.
- [x] Target raw/MCP evidence: incorporate server health, `lookup_funcs`, bounded `disasm`, `xrefs_to`, `find_bytes`, parser decompilation, paint `search_text`, padding windows, and constructor successor boundary at report-level detail. Applied in target raw evidence.
- [x] Target formal C++: insert the exact `RankingRewardEntry::ItemAt(int index)` body from this report, preserving no `index < 0` guard and using `NULL`. Applied in target formal C++ block.
- [x] Target confidence-cap proof: preserve no modeled function, no ordinary xrefs, no pointer/immediate route, paint inline traversal, and negative-index API caveat as reasons not to overclaim public API status or original spelling. Applied in target raw evidence/status and support notes.
- [x] Target cleanup: replace the current non-formal illustrative C-like code block with the formal C++ block; do not leave duplicate sample code. Applied; target behavior is prose-only outside the formal block.
- [x] Support sync: update `by-class/RankingRewardInfoDialog.md` by adding `RankingRewardItem *ItemAt(int index);` inside `struct RankingRewardEntry` after the vector triplet, plus a UID000204 source-quality note preserving current MCP evidence. Applied; validator `000000005605`.
- [x] Support sync if stale: update `by-file/RankingDialog.md` so UID000204 is source-placed with reward-info support and emits through [UID:0000BP], not broad [UID:0000MZ]. Applied after prior B003 lease expired; validator `000000005611`.
- [x] Support sync if stale: update `by-memory/0x00458610-0x0045f9f5.RankingDialog.md` UID000204 row/detail to mention exact raw nested item accessor and [UID:0000BP] support-method emission if needed. Applied; validator `000000005608`.
- [x] Preserve rejected alternatives: direct `RankingDialog` emitter, parser-group emitter, constructor/core inclusion, generic vector helper, padding/data, dead unrelated code, and defensive negative-index rewrites. Applied in target/support source-quality notes.
- [x] Run scoped validator for each edited by-* file from `source-3/project-documentation` using `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`. Applied: commands `000000005603`, `000000005605`, `000000005608`, and `000000005611`.
- [x] Report validator command IDs, timestamps, exit codes, ok counts, warnings/errors, generated refresh state, files changed, leases used/released, and any checklist item that was already present or excluded with reason. Applied in this report section.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000005615","destination_path":"executed-b-agent-research/B005/000204-RankingRewardEntryItemAt-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/000204-RankingRewardEntryItemAt-source-quality.md","timestamp":"2026-07-03T16:25:02-04:00","uid":"000204"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
