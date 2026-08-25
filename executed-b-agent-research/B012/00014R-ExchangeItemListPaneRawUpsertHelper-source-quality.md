** TARGET-REPORT-UID:00014R **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00014R ExchangeItemListPaneRawUpsertHelper Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00014R] reconstructable, but change its direct semantic owner/emitter from [UID:0000J9] `ExchangeDialog` file to [UID:00004S] `ExchangeItemListPane`; [UID:00004S] already routes to [UID:0000J9] `NexusTK/ui/dialogs/ExchangeDialog.cpp`.
- Final disposition: this is a real raw source-shaped `ExchangeItemListPane` helper body with exact behavior and boundaries, but it still has no proven inbound route. The live [UID:00014L] `ExchangeDialogPacketDispatcher` emits the offer-row update logic inline, so [UID:00014R] should keep formal `RECONSTRUCTION_CPP CODE` blank unless a later retained-clone policy deliberately emits no-route raw helper bodies.
- Required action: update the target/support docs with the route proof, source-facing signature/name recommendation, no-code proof, row layout, duplicate remove/insert details, and exact coverage row text below. Do not edit `by-memory/-coverage-report.md` directly during the B-agent implementation callback.
- Score recommendation: `COMPLETION 85 -> 86`, `CONFIDENCE 87 -> 89`. This is a modest improvement for direct PE/Capstone route scans and owner/source-shape resolution, still capped below 90 completion because the original helper declaration/name and retained-clone emission policy remain unproven.
- Confidence: high for bytes, range, row schema, duplicate remove/insert semantics, class ownership, and no-route status; medium for original source name.

## Target

- Target UID: `00014R`.
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md`.
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B012\research\00014R-ExchangeItemListPaneRawUpsertHelper-source-quality.md`.
- Current target metadata: `COMPLETION:85`, `CONFIDENCE:87`, `CANONICAL_OWNER:0000J9`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000J9`, blank formal C++.
- Current target state: raw/non-IDA helper, no direct xrefs in existing IDA-backed docs, exact half-open range `0x004ae0b0-0x004ae167`.
- Current coverage row state: `by-memory/-coverage-report.md` still shows the stale `78%` row for [UID:00014R].

## Executive Recommendation

The direct owner should be [UID:00004S] `ExchangeItemListPane`, not the file root [UID:0000J9]. The helper's `ecx` receiver is the list pane, it only touches row-list operations and the exchange item row payload, and its row schema is corroborated by `ExchangeItemListPane::DrawItemEntry` plus the live dispatcher case. [UID:0000J9] remains the final source-file route through [UID:00004S].

The best source-facing method name is `ExchangeItemListPane::SetOfferItem`. That name is inferred/descriptive, not original-symbol proof. It is more source-like than the documentation word "upsert" while still matching the behavior: replace any existing row with the same offer-row key, otherwise append. If the project prefers behavior-explicit reconstructed names, `UpdateOfferItem` or `UpsertOfferItem` are acceptable alternates, but `InsertOfferItem` is weaker because the duplicate path removes and reinserts rather than only appending.

Best source-facing signature if a retained helper is ever emitted:

```cpp
void ExchangeItemListPane::SetOfferItem(unsigned char key,
                                        unsigned short itemId,
                                        unsigned char color,
                                        const wchar_t *name);
```

Formal target C++ should remain blank for now. The current combined-score/emitter gate is numerically satisfied, but `by-structure.md` also requires a clear source shape. Here the clear source shape for live behavior is [UID:00014L] dispatcher subcommand `2` inline logic; direct PE scans and current docs find no call, vtable slot, pointer table, VA/RVA pointer, or immediate branch route to `0x004ae0b0`. Emitting this page as a separate method now would risk duplicating source logic not proven to be called by the original program.

## Supervisor Active Recheck

- The supervisor assigned a report-only B-source-quality task for [UID:00014R]. No by-* docs were edited in this pass.
- No split is required. The target range already correctly includes the duplicate-removal tail after the main-path `ret 10h`; the following `0x004ae167-0x004ae170` bytes are padding.
- The task's required focus items are resolved:
  - raw helper name/signature: best inferred `ExchangeItemListPane::SetOfferItem(unsigned char key, unsigned short itemId, unsigned char color, const wchar_t *name)`;
  - row fields: key byte `+0`, padding `+1`, item id word `+2`, color byte `+4`, padding `+5`, name `wchar_t[256]` at `+6`, total `0x206`;
  - duplicate semantics: scan by key, remove one matching row, reinsert at removed index; otherwise append at current count;
  - caller/route: no inbound static route found; live dispatcher duplicates logic inline;
  - owner/source placement: direct owner [UID:00004S], file route [UID:0000J9];
  - formal C++: keep blank with exact no-code proof; include reference draft only for a future retained-clone policy.

## Inference Research Guidance Check

- `by-structure.md` requires the narrowest true direct semantic owner. A file-level owner is too broad because the body is a `thiscall` list-pane member helper, and [UID:00004S] already clears `85/85` with a valid route to [UID:0000J9].
- The active C++ gate is not just numeric. The target is reconstructable, has a route, and averages above `85`, but final-output C++ also needs defensible reachability/source placement. The no-route duplicate relationship blocks formal code insertion for this page.
- Existing docs were treated as leads and rechecked against current evidence:
  - target and support docs preserve prior IDA MCP facts that `0x004ae0b0` is not an IDA function and has no xrefs;
  - [UID:00014L] executed B015 report and implemented dispatcher docs preserve the live inline row-update source shape;
  - direct executable scans in this pass independently confirm no route to the raw helper start.
- Fact/inference split:
  - direct PE/Capstone facts prove bytes, calls, branch targets, padding, dword route absence, and full `.text` immediate route absence;
  - documentation evidence supplies current IDA no-function/no-xref and vtable/draw corroboration;
  - method names and member names are inferred/descriptive.

## Heuristic / Inference Reanalysis And Validation

- Raw helper role:
  - Best inference: private `ExchangeItemListPane` row-set/update helper for an offered item row.
  - Evidence checked: raw body uses `ecx` as list pane receiver, calls shared `ListPane` row-count/get/insert/remove helpers, builds a `0x206` row record, and has `ret 10h` for four explicit arguments.
  - Rejected alternatives: ExchangeDialog method, global helper, runtime/compiler helper, or padding. The body has project UI row semantics and a class receiver; it is not generic compiler glue.

- Source-facing name:
  - Best recommendation: `SetOfferItem`.
  - Evidence checked: helper either replaces an existing key or appends a new row. "Set" matches a mid-2000s C++ style better than the modern/documentation term "upsert".
  - Rejected alternatives:
    - `InsertOfferItem`: incomplete because duplicate keys are removed first and inserted at the same index.
    - `FindOfferItem`: belongs to sibling [UID:00014S], not this mutating helper.
    - `ExchangeDialog::UpdateOfferItemFromPacket`: describes dispatcher subcommand `2`, not this `ExchangeItemListPane` member.
    - raw names such as `sub_4AE0B0`: evidence label only, not source-facing documentation.
  - Remaining uncertainty: no original symbol, caller, or source file text proves the exact method spelling. Use `SetOfferItem` as inferred/descriptive.

- Signature and calling convention:
  - Best recommendation: `void __thiscall ExchangeItemListPane::SetOfferItem(unsigned char key, unsigned short itemId, unsigned char color, const wchar_t *name)`.
  - Evidence checked: `ecx` is copied to `edi` as receiver; `[ebp+8]` is copied to row byte `+0`; `[ebp+0xc]` is copied as word to row `+2`; `[ebp+0x10]` is copied to row byte `+4`; `[ebp+0x14]` is copied to a local and pushed as the `_wcscpy_s` source; `ret 10h` cleans four arguments.
  - Rejected alternatives: `char *` or packet pointer source names. The helper calls `_wcscpy_s` with `0x100` wide-character capacity and a destination at row `+6`, so the input is already wide text.

- Row layout:
  - Best recommendation:

    ```cpp
    struct ExchangeItemListRow {
        unsigned char key;       // +0
        unsigned char pad1;      // +1, alignment/reserved
        unsigned short itemId;   // +2
        unsigned char color;     // +4
        unsigned char pad5;      // +5, alignment/reserved
        wchar_t name[256];       // +6
    };                           // sizeof == 0x206
    ```

  - Evidence checked: constructor [UID:00014Q] passes `0x206` row size to the `ListPane` base; this helper writes key/id/color/name at `+0/+2/+4/+6`; [UID:00004S] and `DrawItemEntry` read id/color/name from `+2/+4/+6`; [UID:00014L] dispatcher subcommand `2` uses the same row schema.
  - Rejected alternatives: packed `key,itemId,color,name` without padding, opaque blob, UTF-8 name in the row, or item id dword. The offsets require padding and a 16-bit id.

- Duplicate remove/insert semantics:
  - Best recommendation: document as "set/replace by key while preserving the old row position; append if key is new".
  - Evidence checked: function first calls `0x004f3bd0` for count, loops index `esi`, calls `0x004f3dc0(index)`, compares `row[0]` to `key`, jumps to tail at `0x004ae156`, calls `0x004f3d60(index, 1)`, and jumps back to insert at the same index. If no key matches, it refreshes count and inserts at count.
  - Rejected alternatives: pure append, stable in-place overwrite, or sort. It removes one row and calls the generic insert helper; no sort helper appears.

- ListPane helper names:
  - Best source-facing names for this report: `GetRowCount`/`GetItemCount` for `0x004f3bd0`, `GetRow`/`GetItemData` for `0x004f3dc0`, `InsertRow`/`InsertItem` for `0x004f3c00`, and `RemoveRows`/`RemoveItems` for `0x004f3d60`.
  - Evidence checked: [UID:000194] and [UID:0003TZ-0003U5] ListPane split docs classify these as shared infrastructure with broad caller fanout; target disassembly passes an explicit index to `0x004f3dc0`, so the source-facing name should not be limited to "selected entry" for this use.
  - Rejected alternatives: treating these as Exchange-owned helpers. Caller fanout and ListPane docs show shared control infrastructure.

- Caller/reachability and raw status:
  - Best inference: no proven inbound route; this is retained/projected duplicate code or dead uncalled private helper body.
  - Evidence checked:
    - current target/support docs record IDA MCP `lookup_funcs 0x004ae0b0` as `Not a function` and no `xrefs_to 0x004ae0b0`;
    - direct PE full-file scan found no little-endian VA, RVA, or file-offset dword for `0x004ae0b0`, `0x004ae156`, `0x004ae167`, or `0x004ae170`;
    - direct PE rel32 scan found no call/jmp/jcc route to those addresses;
    - whole `.text` Capstone immediate scan decoded `725479` records and found no instruction-immediate hit to `0x004ae0b0`, `0x004ae167`, or `0x004ae170`; the only hit to `0x004ae156` is the helper's own internal `je 0x4ae156` at `0x004ae0ed`;
    - positive-control dword scan finds vtable pointers for `0x004ae1b0` at `.rdata` VA `0x00619e40` and `0x004ae1c0` at `.rdata` VA `0x00619e48`, while raw constructor/upsert/find starts have zero VA dword hits.
  - Rejected alternatives:
    - vtable-only method: no vtable dword points to `0x004ae0b0`;
    - missed direct call: no rel32/immediate route;
    - missed pointer table: no VA/RVA/file-offset dword route.
  - Remaining uncertainty: an unmodeled runtime-computed jump is theoretically possible but has no supporting evidence and is lower probability than retained/dead code.

- Relationship to [UID:00014L] `ExchangeDialogPacketDispatcher`:
  - Best inference: dispatcher subcommand `2` is the live source path and should keep the row update inline.
  - Evidence checked: [UID:00014L] implemented B015 report and current formal C++ read packet fields `packet+2/+3/+4/+6/+7/+8`, convert a counted CP_ACP name to wide text, select control `5`/`8`, scan existing rows by key, remove one duplicate, build an `ExchangeItemListRow`, and insert it. B015 explicitly rejected calling the raw no-route helper.
  - Rejected alternative: rewrite dispatcher source to call [UID:00014R]. There is no binary route to `0x004ae0b0`, and the dispatcher currently contains equivalent logic inline.

- Owner/emitter/source placement:
  - Best recommendation: target metadata should be `CANONICAL_OWNER:00004S`, `EMITTER_UIDS:00004S`.
  - Evidence checked: [UID:00014Q] constructor already uses [UID:00004S] as direct owner; [UID:0003NF] vtable data uses [UID:00004S]; [UID:00004S] routes to [UID:0000J9]; [UID:0000J9] owns the broad `ExchangeDialog.cpp` file and private list-pane source grouping.
  - Rejected alternatives:
    - direct file owner [UID:0000J9]: too broad under current by-structure rules;
    - outer class owner [UID:00004R]: dispatcher uses the outer class, but this helper's receiver and behavior are the private list pane;
    - no owner: class, row layout, constructor, draw method, and vtable data are enough for direct class ownership.

- Source-bearing versus no-code:
  - Best recommendation: source-bearing/reconstructable, but formal C++ stays blank now.
  - Evidence checked: body is source-shaped project UI logic, not compiler glue; however live reachable source already covers equivalent behavior inline in [UID:00014L], and no route proves this helper should appear as a called method in final source.
  - Rejected alternatives:
    - `RECONSTRUCTABLE:FALSE`: wrong because the bytes are custom NexusTK behavior, not padding/runtime support.
    - populate formal C++ now: unsafe because it would create a separate emitted helper without proven reachability and could duplicate the dispatcher source shape.

## Evidence Standards Used

- Direct executable evidence:
  - `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
  - MD5 `4247e04e20b65d6414c7238aa8ff5515`
  - image base `0x00400000`
  - `.text` section `0x00401000-0x0060c4ac`
- Direct tooling in this pass:
  - Python PE parsing for section/VA mapping;
  - Capstone 32-bit x86 disassembly for target body and whole `.text` immediate scan;
  - full-file byte searches for VA/RVA/file-offset dword pointers;
  - rel32 call/jmp/jcc target scans.
- Documentation evidence:
  - target [UID:00014R];
  - [UID:00004S] `ExchangeItemListPane`;
  - [UID:0000J9] `ExchangeDialog`;
  - [UID:00014K] exchange aggregate;
  - [UID:00014L] dispatcher with executed B015 source-quality implementation;
  - [UID:00014Q] constructor;
  - [UID:00014S] find helper;
  - [UID:0003NF] vtable-data child;
  - [UID:000194]/ListPane helper split docs;
  - generated `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`;
  - current `by-memory/-coverage-report.md` stale row.
- IDA MCP limitation: no live IDA MCP tool is exposed in this session. Current by-* docs preserve prior IDA MCP facts, and direct PE scans were used to independently validate the raw route and byte claims where possible.

## Raw PE / Disassembly Facts

- Function/range facts:
  - `0x004ae0b0-0x004ae167` maps to file offsets `0x000ad4b0-0x000ad567`.
  - Length is `0xb7` / 183 bytes.
  - Prologue is `push ebp; mov ebp, esp; sub esp, 0x210`.
  - Main path cleanup uses stack cookie global `0x00672f24` and calls `0x005c772f` before `ret 10h` at `0x004ae153`.
  - The duplicate-removal tail starts after the main-path return bytes at `0x004ae156`, is reached by `je 0x004ae156`, calls `0x004f3d60(index, 1)`, and jumps back to the row construction at `0x004ae0fd`.
- Outgoing calls:
  - `0x004ae0d1 -> 0x004f3bd0` (`ListPane::GetRowCount`/count)
  - `0x004ae0e3 -> 0x004f3dc0` (`ListPane::GetRow`/indexed row access)
  - `0x004ae0f6 -> 0x004f3bd0` (refresh count for append index)
  - `0x004ae12c -> 0x005cd657` (`_wcscpy_s`)
  - `0x004ae13e -> 0x004f3c00` (`ListPane::InsertRow`)
  - `0x004ae14b -> 0x005c772f` (security cookie check)
  - `0x004ae160 -> 0x004f3d60` (`ListPane::RemoveRows`)
- Branches:
  - `0x004ae0dc jle 0x004ae0f4`
  - `0x004ae0ed je 0x004ae156`
  - `0x004ae0f2 jl 0x004ae0e0`
  - `0x004ae159 je 0x004ae0f4`
  - `0x004ae165 jmp 0x004ae0fd`
- Boundary/padding:
  - `0x004ae0a4-0x004ae0b0` is twelve `0xcc` bytes after the raw constructor.
  - `0x004ae167-0x004ae170` is nine `0xcc` bytes before the raw find helper.
  - `0x004ae1ac-0x004ae1b0` is four `0xcc` bytes before `nullsub_29`.
- Route scans:
  - No full-file VA/RVA/file-offset dword hits for `0x004ae0b0`, `0x004ae156`, `0x004ae167`, or `0x004ae170`.
  - No rel32 call/jmp/jcc hits to those addresses.
  - Whole `.text` instruction-immediate scan found zero hits to `0x004ae0b0`, zero hits to `0x004ae167`, zero hits to `0x004ae170`, and one internal hit to `0x004ae156` from `0x004ae0ed`.
  - Positive control: full-file VA dword search finds `0x004ae1b0` at `.rdata` VA `0x00619e40` and `0x004ae1c0` at `.rdata` VA `0x00619e48`, matching the documented vtable-routed null/draw virtuals. Raw constructor/upsert/find starts have no such dword hits.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004ae060-0x004ae0a4` | [UID:00014Q](../../../../by-memory/0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor.md) | raw `ExchangeItemListPane` constructor | TRUE | [UID:00004S] | `86/88` | correct class route; formal C++ blank |
| `0x004ae0a4-0x004ae0b0` | [UID:0000VN] `-ignored` | padding | FALSE | none | `100/strong` | unchanged |
| `0x004ae0b0-0x004ae167` | [UID:00014R](../../../../by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md) | raw set/update offer-item helper | TRUE | recommend [UID:00004S] | current `85/87`, recommend `86/89` | no formal C++ now |
| `0x004ae167-0x004ae170` | [UID:0000VN] `-ignored` | padding | FALSE | none | `100/strong` | unchanged |
| `0x004ae170-0x004ae1ac` | [UID:00014S](../../../../by-memory/0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md) | raw key-to-row-index helper | TRUE | recommend [UID:00004S] in support cleanup | `85/88` | formal C++ blank |
| `0x004ae1b0-0x004ae1b3` | inline in class docs | null virtual | TRUE/minor | [UID:00004S] | n/a | vtable-routed positive control |
| `0x004ae1c0-0x004ae4b6` | class method in docs | `DrawItemEntry` | TRUE | [UID:00004S] | n/a | vtable-routed row-layout corroboration |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004ae0b0` | no IDA function/no xrefs in current docs; no PE branch/pointer route in this pass | raw helper has no proven live route |
| `0x004ae0ed -> 0x004ae156` | internal branch | proves tail block after `ret 10h` is reachable and must remain in range |
| `0x004ae160 -> 0x004f3d60` | outgoing call | removes one existing row before replacement |
| `0x004ae13e -> 0x004f3c00` | outgoing call | inserts the built row at append or replacement index |
| `0x004ad320` case `2` | implemented first-draft dispatcher C++ | live source path updates offered-item rows inline |
| `0x00619e48 -> 0x004ae1c0` | vtable data positive control | `DrawItemEntry` is live/routed and corroborates row fields |

## Documentation Evidence And Current Status

- [UID:00014R] already documents exact range, raw no-function/no-xref status, stack row construction, duplicate-removal branch, and row-layout corroboration. It still uses file-level owner/emitter and leaves source-facing name/signature open.
- [UID:00004S] already documents `ExchangeItemListPane` as the private offered-item row list, with constructor, raw upsert/find helpers, null virtual, draw virtual, shared destructor caveat, exact vtable views, and file route to [UID:0000J9].
- [UID:00014Q] uses [UID:00004S] as direct owner/emitter. That is the correct model for [UID:00014R] too.
- [UID:00014S] has the same class-owner mismatch as [UID:00014R]. It should also route through [UID:00004S] during support cleanup, though this report's primary implementation target is [UID:00014R].
- [UID:00014L] now emits inline dispatcher C++ for opcode `0x42`, subcommand `2`, and explicitly says not to call raw no-route `ExchangeItemListPaneRawUpsertHelper`.
- `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` currently contains [UID:00014R] only as an empty emitter marker. That is expected under the current no-code recommendation.
- `by-memory/-coverage-report.md` has stale rows in this address block. The target row still says `78%` despite target metadata `85/87`, and [UID:00014Q]/[UID:00014S] adjacent rows also lag current metadata. This report supplies exact [UID:00014R] replacement text below; adjacent support rows may be corrected by supervisor separately.

## Ranked Ownership Analysis

### 1. [UID:00004S] ExchangeItemListPane

- Evidence for:
  - `ecx` is the list-pane receiver saved in `edi`;
  - the body only uses row count/get/remove/insert operations and row fields;
  - constructor [UID:00014Q], vtable data [UID:0003NF], and draw virtual all route through [UID:00004S];
  - [UID:00004S] already clears the owner gate and routes to [UID:0000J9].
- Evidence against:
  - no inbound calls prove this method was live in the final source.
- Decision:
  - accepted as direct semantic owner and emitter route. No inbound calls affect formal C++ readiness, not class ownership.

### 2. [UID:0000J9] ExchangeDialog file

- Evidence for:
  - final source file route for the exchange feature and private list pane;
  - current target metadata uses this owner/emitter;
  - live dispatcher case is in `ExchangeDialog.cpp`.
- Evidence against:
  - too broad as direct owner under by-structure rules. The helper receiver and behavior are class-local to `ExchangeItemListPane`.
- Decision:
  - keep as source-file route through [UID:00004S]; reject as direct `CANONICAL_OWNER`/`EMITTER_UIDS` for this child.

### 3. [UID:00004R] ExchangeDialog class

- Evidence for:
  - dispatcher case updates local/remote list controls and uses equivalent logic inline.
- Evidence against:
  - raw helper's `this` is the list control, not the outer dialog; no outer-dialog fields or packet pointer are used.
- Decision:
  - reject as direct owner. It remains an important caller/source-shape comparator.

### 4. No-owner / non-reconstructable / runtime helper

- Evidence for:
  - no inbound route and no IDA function object.
- Evidence against:
  - body is custom UI data mutation, not runtime/compiler glue; class and row layout are strongly identified.
- Decision:
  - reject non-reconstructable/no-owner. Keep reconstructable/class-owned, but blank formal code.

### Proposed File/Grouping

- Proposed file/grouping: no new file. Keep `ExchangeItemListPane` inside [UID:0000J9] `NexusTK/ui/dialogs/ExchangeDialog.cpp`.
- Likely full contents of file route: [UID:00004R] `ExchangeDialog`, [UID:00004S] `ExchangeItemListPane`, [UID:00004T] `ExchangeMoneyEditControlPane`, [UID:00004Q] `ExchangeAlertPane`, [UID:0000QV]/[UID:0002VZ] exchange alert singleton, exchange resources/vtables, and exact exchange-owned by-memory children.
- Candidate related items accepted in this family: [UID:00014Q], [UID:00014R], [UID:00014S], [UID:0003NF].
- Candidate related items rejected from this direct owner: `AddItemDialog`, `AddItemWithCountDialog`, `MixItemDialog`, `MyItemListPane`, generic `ListPane` helpers, and function-object callback templates.

## Negative Evidence Summary

- No live IDA-backed docs identify `0x004ae0b0` as a function or xref target.
- No full-file dword search finds VA/RVA/file-offset references to `0x004ae0b0` or successor raw start `0x004ae170`.
- No rel32 or whole-text instruction-immediate route reaches `0x004ae0b0`.
- No vtable slot points to the upsert helper; vtable positive controls point only to `0x004ae1b0` and `0x004ae1c0`.
- The live dispatcher has equivalent row-update logic inline and has already been accepted as first-draft C++ ready.
- Consumer/context evidence from [UID:00014L] proves behavior and row schema, but it does not prove a call route to this raw helper.

## First-Draft C++ / No-Code Decision

Do not populate [UID:00014R]'s formal `RECONSTRUCTION_CPP CODE` block now.

Exact no-code proof:

1. Current IDA-backed docs report no function object and no xrefs at `0x004ae0b0`.
2. Direct PE scans in this pass find no branch, instruction-immediate, VA dword, RVA dword, or file-offset dword route to the raw start.
3. Vtable positive controls prove the scan can identify normal routed ExchangeItemListPane methods, but there is no vtable route to this helper.
4. [UID:00014L] dispatcher subcommand `2` already emits the live row-update behavior inline and explicitly rejects calling this raw helper.
5. A separate emitted method would currently be a no-route duplicate, not proven original source flow. Keep the body documented and reconstructable, but blank until a retained-clone policy says how to emit such raw islands.

Reference body if a future retained-clone policy deliberately emits this range:

```cpp
struct ExchangeItemListRow {
    unsigned char key;
    unsigned char pad1;
    unsigned short itemId;
    unsigned char color;
    unsigned char pad5;
    wchar_t name[256];
};

void ExchangeItemListPane::SetOfferItem(unsigned char key,
                                        unsigned short itemId,
                                        unsigned char color,
                                        const wchar_t *name)
{
    int insertIndex = GetRowCount();

    for (int i = 0; i < insertIndex; ++i) {
        const ExchangeItemListRow *row =
            static_cast<const ExchangeItemListRow *>(GetRow(i));
        if (row->key == key) {
            RemoveRows(i, 1);
            insertIndex = i;
            break;
        }
    }

    ExchangeItemListRow row;
    row.key = key;
    row.itemId = itemId;
    row.color = color;
    wcscpy_s(row.name, 256, name);
    InsertRow(insertIndex, &row);
}
```

Reference body caveats:

- This body is for source-shape documentation and future retained-clone review only; it should not be inserted in [UID:00014R]'s formal block during the immediate implementation callback.
- The padding bytes in `ExchangeItemListRow` are not explicitly initialized by the raw helper. Do not add `memset` to this retained-helper body unless a broader source audit proves the original code initialized the whole row elsewhere.
- `GetRowCount`, `GetRow`, `RemoveRows`, and `InsertRow` are descriptive `ListPane` wrapper names. The final project may choose `GetItemCount`, `GetItemData`, `RemoveItems`, and `InsertItem`.

## Recommended Target Doc Changes

Apply these to `by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md` only after supervisor review:

- Metadata:
  - `COMPLETION:85 -> 86`
  - `CONFIDENCE:87 -> 89`
  - `CANONICAL_OWNER:0000J9 -> 00004S`
  - `RECONSTRUCTABLE:TRUE` unchanged
  - `EMITTER_UIDS:0000J9 -> 00004S`
  - leave `RECONSTRUCTION_CPP CODE` blank
- Status section:
  - replace "Likely source file" direct-owner wording with "Direct owner: [UID:00004S] ExchangeItemListPane; source route: [UID:0000J9] ExchangeDialog".
  - state likely source-facing helper name/signature: `ExchangeItemListPane::SetOfferItem(unsigned char key, unsigned short itemId, unsigned char color, const wchar_t *name)`.
  - state formal C++ remains blank because no inbound route is proven and live dispatcher case `2` emits equivalent behavior inline.
- Behavior section:
  - add exact row struct layout with padding bytes and `sizeof == 0x206`.
  - state duplicate path preserves the existing key's row position by removing one row and reinserting at that index; new keys append at current row count.
  - state `_wcscpy_s` copies a wide source name into row `name[256]`, with no whole-row zeroing in this retained helper.
- Evidence/source-quality section:
  - add direct PE evidence: MD5, range/file offsets, body length `0xb7` / 183, outgoing calls, full route-scan negative results, positive-control vtable dword hits for null/draw methods.
  - add relationship to [UID:00014L] dispatcher subcommand `2`; dispatcher remains inline and should not call [UID:00014R].
  - add rejected alternatives: direct file owner, outer dialog owner, standalone helper, non-reconstructable/runtime, and immediate formal C++.
- Score rationale:
  - explain the modest score increase and continued cap below final-source quality.
- Cross-references:
  - add/keep [UID:00004S], [UID:0000J9], [UID:00014L], [UID:00014Q], [UID:00014S], [UID:0003NF], and [UID:000194].

## Recommended Support Doc Changes

- `by-class/ExchangeItemListPane.md`:
  - Update the `UpsertOfferItemRaw` row to mention best source-facing name `SetOfferItem`, signature above, and direct [UID:00014R] class ownership.
  - Add evidence that B012 direct PE scans found no inbound route to `0x004ae0b0`; live [UID:00014L] dispatcher case `2` keeps the equivalent row update inline.
  - Add row layout with padding and `wchar_t name[256]` if not already detailed at this level.
  - Recommended score: no required score change; optional `CONFIDENCE 86 -> 87` only if the supervisor wants support-page confidence to reflect the route proof.

- `by-file/ExchangeDialog.md`:
  - Add a boundary/source-shape note: [UID:00014R] is directly class-owned by [UID:00004S] and source-routed through this file, not directly owned by the file.
  - State that [UID:00014L] subcommand `2` should remain inline; [UID:00014R] is a raw no-route retained/private helper candidate and formal C++ stays blank.
  - Recommended score: unchanged.

- `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`:
  - Update the [UID:00014R] covered-range row to say direct owner [UID:00004S], best helper name/signature, no-route retained helper, and inline dispatcher relationship.
  - Recommended score: unchanged.

- `by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md`:
  - Optional support note only: B012 00014R recheck confirms no route to the raw upsert helper, supporting the existing inline source-shape decision for subcommand `2`.
  - Recommended score: unchanged.

- `by-memory/0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md`:
  - Sibling consistency recommendation: change `CANONICAL_OWNER:0000J9 -> 00004S` and `EMITTER_UIDS:0000J9 -> 00004S` in a support cleanup callback, because it is the same private `ExchangeItemListPane` row helper family. Keep formal C++ blank.
  - Recommended score: unchanged unless a separate B pass rechecks it.

- `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`:
  - Do not edit manually. After validation/autogen, [UID:00014R] should still appear as an empty marker unless a future retained-clone policy changes the formal C++ decision.

## Exact Implementation Checklist For Later Callback

1. Lease/apply only the accepted target/support docs; do not edit `by-memory/-coverage-report.md`.
2. In [UID:00014R], update metadata to `86/89`, `CANONICAL_OWNER:00004S`, `EMITTER_UIDS:00004S`, blank formal C++.
3. Add target sections covering direct PE route scans, source-facing `SetOfferItem` signature, row layout, duplicate semantics, no-code proof, rejected alternatives, and dispatcher-inline relationship at report-level detail.
4. Update [UID:00004S], [UID:0000J9], and [UID:00014K] support docs with the same facts, preserving that [UID:0000J9] is the file route rather than direct owner.
5. Optionally update [UID:00014L] with a one-line support cross-check and [UID:00014S] owner/emitter consistency if the supervisor includes those in the callback.
6. Provide the exact [UID:00014R] `by-memory/-coverage-report.md` row below for supervisor application; do not apply it directly.
7. Run scoped validators and report exact results.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` directly. If the supervisor accepts this report, replace the current [UID:00014R] row in address order between the padding rows `0x004ae0a4-0x004ae0b0` and `0x004ae167-0x004ae170` with:

```text
    - [UID:00014R][0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper](by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md) 0x004ae0b0-0x004ae167 | raw helper | ExchangeItemListPaneRawUpsertHelper : reconstructable : 86% : strong : B012 2026-06-19 source-quality reanalysis confirms exact `0xb7` / 183-byte raw non-IDA `ExchangeItemListPane` helper body, best source-facing signature `SetOfferItem(unsigned char key, unsigned short itemId, unsigned char color, const wchar_t *name)`, row layout key `+0`, item id `+2`, color `+4`, wide name `+6`, total row size `0x206`, duplicate-key remove/reinsert path through tail block `0x004ae156-0x004ae167`, outgoing shared ListPane calls `0x004f3bd0`/`0x004f3dc0`/`0x004f3d60`/`0x004f3c00`, `_wcscpy_s` name copy with capacity `0x100`, direct owner route through [UID:00004S] `ExchangeItemListPane` to [UID:0000J9] `ExchangeDialog.cpp`, direct PE/Capstone scans finding no branch/immediate/VA/RVA/file-offset route to `0x004ae0b0`, positive-control vtable refs only for successor null/draw virtuals, and formal C++ intentionally blank because live dispatcher case `2` emits equivalent row-update logic inline while this raw helper remains a no-route retained/private helper candidate.
```

Observed adjacent stale rows while reviewing the same block:

- [UID:00014Q] coverage row still says `76%` while the doc metadata is `86/88`.
- [UID:00014S] coverage row still says `80%` while the doc metadata is `85/88`.

Those adjacent rows are not the primary target of this report. If the supervisor chooses to clean them during the same coverage pass, use the current page metadata and existing support facts rather than this report as the authority for their exact text.

## Validation Commands Needed After Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after accepted doc edits:

> Executable block R001 was removed from this report and preserved verbatim in [00014R-ExchangeItemListPaneRawUpsertHelper-source-quality-removed.md](00014R-ExchangeItemListPaneRawUpsertHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Only run the [UID:00014L]/[UID:00014S] validators if those optional support docs are included in the callback. After the supervisor applies the coverage row:

> Executable block R002 was removed from this report and preserved verbatim in [00014R-ExchangeItemListPaneRawUpsertHelper-source-quality-removed.md](00014R-ExchangeItemListPaneRawUpsertHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected results:

- scoped validators should exit `0` with `ok: 1`;
- `auto-generated/-ag-memory-coverage.md` should route [UID:00014R] through `00004S` to `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`;
- generated `ExchangeDialog.cpp` should still keep [UID:00014R] as an empty emitter marker unless the supervisor deliberately accepts retained-clone C++ later;
- [UID:00014R] should disappear from stale low-completion/low-confidence queues if any still list the old `78%` coverage row.

## IDA Rename / Type / Comment Recommendations

- Function/range:
  - Do not force-create an IDA function solely for source emission. If IDA modeling is desired for review, create a function `0x004ae0b0-0x004ae167` named `ExchangeItemListPane_SetOfferItem_raw_no_route` or `ExchangeItemListPane::SetOfferItem`.
  - Confidence: high for range; medium for name.
- Prototype:
  - `void __thiscall ExchangeItemListPane_SetOfferItem(ExchangeItemListPane *this, unsigned char key, unsigned short itemId, unsigned char color, const wchar_t *name);`
  - Confidence: high for calling convention and argument roles.
- Struct:
  - Add `ExchangeItemListRow` with fields and padding shown above; `sizeof(ExchangeItemListRow) == 0x206`.
  - Confidence: high for offsets and size.
- Comments:
  - At `0x004ae0b0`: "Raw no-route ExchangeItemListPane row set/update helper; live dispatcher case 2 inlines equivalent behavior."
  - At `0x004ae156`: "Reachable duplicate-key removal tail; remove one row and reinsert replacement at same index."
  - At `0x004ae167`: "Nine bytes of 0xcc padding before raw find helper."
- Shared ListPane helpers:
  - Prefer source-facing comments `GetRowCount`, `GetRow`, `InsertRow`, and `RemoveRows` on call sites; keep final names aligned with [UID:000194] ListPane docs.

## Open Questions And Closure

- Original method name:
  - Attempted resolution: compared behavior, source style, dispatcher names, and sibling find helper. Best descriptive name is `SetOfferItem`.
  - Remaining uncertainty: no original symbol or route proves spelling. This caps score and blocks formal C++ but does not block owner/source-route correction.
- Why the raw helper exists if uncalled:
  - Attempted resolution: route scans reject normal direct, vtable, and pointer-table reachability. The most likely explanation is retained/dead/private helper body or recovery artifact for logic now inline in the live dispatcher.
  - Remaining uncertainty: exact compiler/linker reason is unproven. Treat as a retained no-route clone candidate, not padding.
- Whether to emit the helper later:
  - Attempted resolution: current source shape should not emit it because [UID:00014L] already emits equivalent live behavior inline.
  - Remaining uncertainty: a future binary-equivalence retained-clone policy may decide to emit no-route raw bodies as standalone unused functions. This report supplies a reference body for that later policy.

## Changed Files

- Created:
  - `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B012\research\00014R-ExchangeItemListPaneRawUpsertHelper-source-quality.md`
- Modified:
  - none outside Agent-B012 research.
- Moved/renamed:
  - none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/00014R-ExchangeItemListPaneRawUpsertHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"00014R"} -->
<!-- {"agent":"B012","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00014R-ExchangeItemListPaneRawUpsertHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B012/00014R-ExchangeItemListPaneRawUpsertHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00014R"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
