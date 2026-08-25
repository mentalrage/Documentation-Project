** TARGET-REPORT-UID:00025K **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00025K InterfaceEfxReadOnlyData Advanced-Scan Research

## Finalized Report / Current Recommendation
- Current recommendation: classify the original `missing document text for InterfaceEfxReadOnlyData` finding as a real scanner-visible compact-label/body-text gap plus stale parent-page wording, not a stale range, stale UID, canonical-owner issue, emitter issue, split/merge issue, or harmless false positive.
- Final disposition: repaired in-scope by adding the exact compact label `InterfaceEfxReadOnlyData` to [UID:00025K][0x0061c5a0-0x0061c7a4.InterfaceEfxReadOnlyData](../../../../../by-memory/0x0061c5a0-0x0061c7a4.InterfaceEfxReadOnlyData.md), clarifying that the parent is a non-reconstructable/non-emitting mixed `.rdata` aggregate, and replacing legacy `AUTOGEN_PARENT_UID` wording with current `CANONICAL_OWNER` / `EMITTER_UIDS` terminology.
- Required action: no UID, target filename, range, score, canonical owner, emitter, split, merge, or reconstruction C++ change is needed. The supervisor should apply the shared `by-memory/-coverage-report.md` replacement block below because the current hand-maintained row still says this aggregate is reconstructable at `82%`.
- Confidence: high. Current documentation, generated ownership reports, `by-memory/-ignored.md`, and live IDA MCP facts agree that `00025K` should remain `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, with exact source-routed children `0003BR`, `0003BS`, and `0003BT`.

## Target
- Target UID: `00025K`.
- Target path: `by-memory/0x0061c5a0-0x0061c7a4.InterfaceEfxReadOnlyData.md`.
- Source queue/report row: `auto-generated/by-memory-tool-report.md` Advanced-Error-Scan reported `0x0061c5a0-0x0061c7a4.InterfaceEfxReadOnlyData.md: missing document text for InterfaceEfxReadOnlyData`.
- Current target metadata after this pass: `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++.

## Executive Recommendation
- Keep the exact target as `0x0061c5a0-0x0061c7a4.InterfaceEfxReadOnlyData`.
- Keep `CANONICAL_OWNER:NONE`. The range crosses `InputMan`, `InterfaceEfx`, `InterfaceEfxMgr`, and interface-effect resource string data, so no single direct semantic owner owns the whole physical range.
- Keep `RECONSTRUCTABLE:FALSE` and blank `EMITTER_UIDS`. This parent is an audit/index page, not a source object to emit. Exact children carry source ownership and output routing.
- Do not enter C++ reconstruction. The parent is non-reconstructable as one unit, and the active 90/90+ code-entry gate is not relevant to this parent.

## Supervisor Active Recheck
- The supervisor assigned exactly one advanced-scan target: `by-memory/0x0061c5a0-0x0061c7a4.InterfaceEfxReadOnlyData.md`.
- B001 treated the current page and prior Batch216 notes as leads, not authority, and rechecked the range through live IDA MCP.
- The directly in-scope page repair was performed under a B001 lease. `by-memory/-coverage-report.md` was not edited directly.

## Evidence Standards Used
- Evidence types used: target metadata/body, split child pages, `InputMan` and `InterfaceEfx` file/class docs, generated `auto-generated/-ag-memory-coverage.md`, generated `auto-generated/by-memory-tool-report.md`, hand-maintained `by-memory/-coverage-report.md`, `by-memory/-ignored.md`, `by-structure.md`, `inference_research.md`, and live IDA MCP `idb_list`, `server_health`, `lookup_funcs`, `entity_query`, `get_bytes`, `get_string`, and `xrefs_to`.
- Evidence quality is strong because vtable-base xrefs, decoded UTF-16 bytes, child boundaries, and successor boundary all agree with the current split.
- Address adjacency alone was not used as ownership proof. The ownership decision follows the by-structure mixed-container rule and direct xrefs into the exact children.

## Inference Research Guidance Check
- `by-structure.md` treats vtables and string literals as `source-declared/generated-binary`: source declarations/literals matter, but raw vtable bytes are compiler/linker output.
- `by-structure.md` says mixed-range pages should be marked `RECONSTRUCTABLE:FALSE` when they are only audit/index maps and exact children carry real source ownership.
- `by-structure.md` also says `RECONSTRUCTABLE:FALSE` pages must not have nonblank `EMITTER_UIDS` or reconstruction code.
- `inference_research.md` warns that `.rdata` adjacency is weak evidence; here, xrefs and exact child content prove the split instead of assigning the full range to one adjacent source file.

## IDA MCP Facts
- IDB/session:
  - `idb_list` reports active session `b001_0003gy` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - `server_health` reports IDB `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- Function/range facts:
  - `lookup_funcs` reports target data addresses `0x0061c5a0`, `0x0061c5a4`, `0x0061c5b0`, `0x0061c5b4`, `0x0061c5fc`, `0x0061c600`, `0x0061c62c`, `0x0061c630`, `0x0061c638`, `0x0061c63c`, `0x0061c684`, `0x0061c688`, `0x0061c6b4`, `0x0061c6b8`, `0x0061c6c0`, and `0x0061c7a4` are not functions.
  - `lookup_funcs` confirms related code anchors: `0x004e8af0` size `0x121`, `0x004e9660` size `0xad`, `0x004e97b0` size `0xfb`, `0x004e9c10` size `0xb`, `0x004e9c1b` size `0xb`, `0x004e9c30` size `0xca`, `0x004e9d00` size `0x178`, `0x004e9ee0` size `0x4d`, `0x004e9f40` size `0x11e`, `0x004ea060` size `0xb`, `0x004ea06b` size `0xb`, `0x004ea076` size `0xb`, `0x004ea090` size `0x91`, and successor `0x004ea130` size `0xd2`.
- Data/entity facts:
  - `entity_query names 0x0061c5a0-0x0061c7b0` reports vtable names `??_7InputMan@@6B@`, `??_7InterfaceEfx@@6B@`, `??_7InterfaceEfx@@6B@_0`, `??_7InterfaceEfx@@6B@_1`, `??_7InterfaceEfxMgr@@6B@`, `??_7InterfaceEfxMgr@@6B@_0`, and `??_7InterfaceEfxMgr@@6B@_1`, plus resource suffix labels and successor `??_7InventoryPane@@6B@` at `0x0061c7a8`.
  - `entity_query strings` over the same range returns zero rows, which matches IDA's suffix-oriented naming for this UTF-16 island rather than disproving the bytes.
  - `get_bytes 0x0061c5a0 size 516` covers exactly `0x0061c5a0-0x0061c7a4`.
  - Byte decoding of `get_bytes` confirms `0x0061c6c0 = INTEFX.PAD`, `0x0061c6d8 = CHREFX.EPD`, `0x0061c6f0 = MAGEFX.EPD`, `0x0061c708 = ITEMEFX.EPD`, `0x0061c720 = FRMLEFX.EPD`, and `0x0061c738 = FRMREFX.EPD`.
  - `get_bytes 0x0061c5a0 size 16` starts with dwords `0x00649444`, `0x004e9660`, `0x004f4b10`, `0x0041b6c0`, matching the `InputMan` locator followed by its three-slot vtable.
  - `get_bytes 0x0061c7a4 size 16` starts with dword `0x006496e8` followed by InventoryPane vtable slots, confirming `0x0061c7a4` is the excluded successor boundary.
- `get_string` caveat:
  - `get_string` returns full `CHREFX.EPD` at `0x0061c6d8`, but only first characters at several other string starts because IDA labels some suffix/interior names. The raw `get_bytes` UTF-16 decode is the stronger string evidence here.

## Direct Xref / Caller Inventory
| Address / item | Live xrefs | Meaning |
| --- | --- | --- |
| `0x0061c5a0` | none | `InputMan` complete-object-locator cell; no direct xrefs expected. |
| `0x0061c5a4` | `0x004e8b44`, `0x004e8c49`, `0x004e9690` | `InputMan` vtable base stores in constructor/destructor/scalar-delete paths. |
| `0x0061c5b4` | `0x004e97e7`, `0x004e98e1`, `0x004e9c68` | `InterfaceEfx` primary table stores. |
| `0x0061c600` | `0x004e97ed`, `0x004e98e7`, `0x004e9c6e` | `InterfaceEfx` secondary table stores. |
| `0x0061c630` | `0x004e97f7`, `0x004e98f1`, `0x004e9c78` | `InterfaceEfx` tertiary/timer table stores. |
| `0x0061c63c` | `0x004e9d6b`, `0x004e9e89`, `0x004ea09c` | `InterfaceEfxMgr` primary table stores and EH cleanup reference. |
| `0x0061c688` | `0x004e9d71`, `0x004e9e8f`, `0x004ea0a2` | `InterfaceEfxMgr` secondary table stores and EH cleanup reference. |
| `0x0061c6b8` | `0x004e9d7b`, `0x004e9e99`, `0x004ea0ac` | `InterfaceEfxMgr` tertiary table stores and EH cleanup reference. |
| `0x0061c6c0` | `0x004e9d94`, `0x004e9dd8`, `0x004e9e20`, `0x004e9f83`, `0x004e9fca`, `0x004ea1ac`, `0x0057c349` | Shared `INTEFX.PAD` literal used by manager/spawner and related UI/resource paths. |
| `0x0061c6d8` | `0x004e9dac` | `CHREFX.EPD` persistent effect literal. |
| `0x0061c6f0` | `0x004e9df0`, `0x0057c361` | `MAGEFX.EPD` persistent/resource-loader refs. |
| `0x0061c708` | `0x004e9e38`, `0x004ea1c4` | `ITEMEFX.EPD` persistent/inventory refs. |
| `0x0061c720` | `0x004e9f98` | `FRMLEFX.EPD` frame-effect spawner ref. |
| `0x0061c738` | `0x004e9fe2` | `FRMREFX.EPD` frame-effect spawner ref. |
| `0x0061c7a4` | none | InventoryPane locator boundary cell; no direct xrefs expected. |
| `0x0061c7a8` | `0x004ea172`, `0x004ea241`, `0x004efad8` | Successor `InventoryPane` vtable base, outside this target. |

## Function / Child Inventory
| Range / item | UID / path | Role | Reconstructable | Direct owner / emitter | Status |
| --- | --- | --- | --- | --- | --- |
| `0x0061c5a0-0x0061c7a4` | [UID:00025K](../../../../../by-memory/0x0061c5a0-0x0061c7a4.InterfaceEfxReadOnlyData.md) | Mixed InputMan/InterfaceEfx read-only-data index | `FALSE` | `NONE` / blank | Keep as non-emitting parent; compact label repaired |
| `0x0061c5a0-0x0061c5b0` | [UID:0003BR](../../../../../by-memory/0x0061c5a0-0x0061c5b0.InputManVtableData.md) | Exact `InputMan` locator/vtable child | `TRUE` | [UID:0000K6][InputMan](../../../../../by-file/InputMan.md) / `0000K6` | Emits through `InputMan.cpp` |
| `0x0061c5b0-0x0061c6c0` | [UID:0003BS](../../../../../by-memory/0x0061c5b0-0x0061c6c0.InterfaceEfxVtableData.md) | Exact `InterfaceEfx`/`InterfaceEfxMgr` vtable child | `TRUE` | [UID:0000K9][InterfaceEfx](../../../../../by-file/InterfaceEfx.md) / `0000K9` | Emits through `InterfaceEfx.cpp` |
| `0x0061c6c0-0x0061c7a4` | [UID:0003BT](../../../../../by-memory/0x0061c6c0-0x0061c7a4.InterfaceEfxResourceStrings.md) | Exact interface-effect UTF-16 resource literals | `TRUE` | [UID:0000K9][InterfaceEfx](../../../../../by-file/InterfaceEfx.md) / `0000K9` | Emits through `InterfaceEfx.cpp` |
| `0x0061c7a4-...` | [UID:0003BU](../../../../../by-memory/0x0061c7a4-0x0061c7e0.InventoryPaneVtableData.md) / [UID:00025L](../../../../../by-memory/0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData.md) | Successor InventoryPane data | mixed | separate owners | Excluded successor boundary |

## Documentation Evidence And Generated State
- Target page before this pass already had correct metadata: UID `00025K`, score `86/91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`.
- Target page body already documented the correct range, observed contents, split children, IDA evidence, and child ownership, but it lacked the compact non-change-section label `InterfaceEfxReadOnlyData`.
- Target page body also had stale prose: the range section still said `Disposition: reconstructable source-declared/generated-binary data`, and the assignment section still said `AUTOGEN_PARENT_UID remains blank intentionally`.
- `auto-generated/-ag-memory-coverage.md` is correct:
  - `00025K` appears as `not_reconstructable`, owner `NONE`, blank emitters/output.
  - `0003BR` emits via `0000K6` to `auto-generated/NexusTK/input/InputMan.cpp`.
  - `0003BS` and `0003BT` emit via `0000K9` to `auto-generated/NexusTK/ui/InterfaceEfx.cpp`.
- `by-memory/-ignored.md` is correct: it lists `00025K` as a reviewed non-reconstructable standalone `.rdata` aggregate whose exact children carry source-owned routing.
- `by-memory/-coverage-report.md` is stale for this row: it still lists `00025K` as `reconstructable : 82%` and does not include the exact child rows in the current file despite earlier Batch216 notes.

## Ranked Ownership Analysis

### 1. Keep `00025K` as `CANONICAL_OWNER:NONE`, non-emitting parent
- Evidence for:
  - The physical range contains multiple direct source owners: `InputMan` vtable data, `InterfaceEfx`/`InterfaceEfxMgr` vtable data, and interface-effect literals.
  - Exact children already isolate those direct owners and emit through the correct file routes.
  - `by-structure.md` explicitly says mixed index pages with exact source-owned children should be `RECONSTRUCTABLE:FALSE` when they are not themselves source objects.
- Evidence against:
  - None found.
- Decision:
  - Accepted and retained.

### 2. Assign the aggregate to `InterfaceEfx`
- Evidence for:
  - Most bytes in the range are interface-effect vtables and strings.
  - `InterfaceEfx` file/page owns children `0003BS` and `0003BT`.
- Evidence against:
  - The first exact child `0x0061c5a0-0x0061c5b0` is `InputMan` locator/vtable data and is assigned to `InputMan`.
  - Direct owner cannot be chosen by byte majority when a real child with another owner is present.
- Decision:
  - Rejected.

### 3. Assign the aggregate to `InputMan`
- Evidence for:
  - The physical range starts at the `InputMan` locator and vtable.
- Evidence against:
  - Most of the range is unrelated to `InputMan`, and the interface-effect children have their own direct parent.
  - Address-start ownership would be adjacency-only inference, which the guidance rejects.
- Decision:
  - Rejected.

### 4. Split further or merge with neighbors
- Evidence for:
  - The page is a parent aggregate over split children.
- Evidence against:
  - Exact children already cover the meaningful subranges: `0003BR`, `0003BS`, and `0003BT`.
  - Live IDA bytes and xrefs confirm `0x0061c7a4` starts InventoryPane successor data, so merging forward is wrong.
  - No uncovered internal owner remains that would justify another child.
- Decision:
  - Rejected.

### 5. Treat the advanced-scan finding as harmless scanner wording only
- Evidence for:
  - The page already documented the semantic content and split.
- Evidence against:
  - `memory_ranges.py` explicitly checks for filename label text in active document body, and the compact label was absent.
  - The body also contained contradictory reconstructable/legacy assignment wording.
- Decision:
  - Rejected as final action. The warning was low risk, but it was a real documentation consistency gap and was repaired.

## Exact Applied Target-Page Edits
- Added in `## Range`:

```text
- Scanner/report label: `InterfaceEfxReadOnlyData`
```

- Replaced stale disposition/rebuild handling with:

```text
- Disposition: reviewed non-reconstructable/non-emitting mixed `.rdata` aggregate; exact children carry the reconstructable source-declared/generated-binary data.
- Rebuild handling: do not emit this aggregate as one source item; reconstruct the exact child class declarations and resource literals through their assigned source owners, while vtables remain compiler-emitted.
```

- Replaced legacy assignment-gate wording with:

```text
`CANONICAL_OWNER` remains `NONE`, `EMITTER_UIDS` remains blank, and `RECONSTRUCTABLE` remains `FALSE` intentionally. This page clears `86/91`, but it is a mixed non-emitting map over `InputMan`, `InterfaceEfx`, `InterfaceEfxMgr`, and interface-effect resource literals. No single direct parent owns the full range under by-structure rules.
```

- Added the dated `2026-06-14 B001 advanced-scan label/body repair` change note.

## Exact Shared Coverage-Report Text For Supervisor Application
Do not edit `by-memory/-coverage-report.md` directly. Supervisor should replace the current single `00025K` row under the `0x0061c360-0x0061c5a0.IMEPaneReadOnlyData` row and before the `0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData` row with this block:

```text
    - [UID:00025K][0x0061c5a0-0x0061c7a4.InterfaceEfxReadOnlyData](by-memory/0x0061c5a0-0x0061c7a4.InterfaceEfxReadOnlyData.md) 0x0061c5a0-0x0061c7a4 | mixed-rdata index | InterfaceEfxReadOnlyData : ignored : 86% : strong : B001 advanced-scan pass repaired the compact report label and refreshed current owner/emitter wording; live IDA reconfirmed this as a non-emitting mixed map over `InputMan`, `InterfaceEfx`, `InterfaceEfxMgr`, and effect resource strings, with no single direct owner for the full physical range.
        - [UID:0003BR][0x0061c5a0-0x0061c5b0.InputManVtableData](by-memory/0x0061c5a0-0x0061c5b0.InputManVtableData.md) 0x0061c5a0-0x0061c5b0 | vtable-data | InputManVtableData : reconstructable : 85% : strong : Exact `InputMan` RTTI locator plus three-slot primary vtable assigned to [UID:0000K6][InputMan](by-file/InputMan.md); live IDA confirms `0x0061c5a0` locator bytes, `0x0061c5a4` vtable base, constructor/destructor/scalar-delete store xrefs at `0x004e8b44`, `0x004e8c49`, and `0x004e9690`, and the `InterfaceEfx` successor locator.
        - [UID:0003BS][0x0061c5b0-0x0061c6c0.InterfaceEfxVtableData](by-memory/0x0061c5b0-0x0061c6c0.InterfaceEfxVtableData.md) 0x0061c5b0-0x0061c6c0 | vtable-data | InterfaceEfxVtableData : reconstructable : 86% : strong : Exact `InterfaceEfx`/`InterfaceEfxMgr` locator and vtable island assigned to [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md); live IDA confirms all six table bases, constructor/destructor/EH/scalar-delete store xrefs, adjustor thunk slots, and boundary before `INTEFX.PAD`.
        - [UID:0003BT][0x0061c6c0-0x0061c7a4.InterfaceEfxResourceStrings](by-memory/0x0061c6c0-0x0061c7a4.InterfaceEfxResourceStrings.md) 0x0061c6c0-0x0061c7a4 | string-data | InterfaceEfxResourceStrings : reconstructable : 85% : strong : Exact interface-effect resource literals assigned to [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md); live IDA bytes decode `INTEFX.PAD`, `CHREFX.EPD`, `MAGEFX.EPD`, `ITEMEFX.EPD`, `FRMLEFX.EPD`, and `FRMREFX.EPD`, with manager/spawner/resource-loader xrefs and the `InventoryPane` successor locator at `0x0061c7a4`.
```

## Validator / Tool Results
- Lease workflow:
  - Read `current_leases.md`: no B001 active lease before this target; another unrelated B003 lease existed later and was ignored.
  - `python .\tools\leaser\leaser.py Agent-B001 lease "E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0061c5a0-0x0061c7a4.InterfaceEfxReadOnlyData.md"` returned `Success`.
  - `python .\tools\leaser\leaser.py Agent-B001 unlease "E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0061c5a0-0x0061c7a4.InterfaceEfxReadOnlyData.md"` returned `Success`.
- Commands run:
  - `python .\tools\validator.py --mode file --file by-memory\0x0061c5a0-0x0061c7a4.InterfaceEfxReadOnlyData.md --apply --queue-timeout 240`
  - `python .\tools\memory_ranges.py --advanced-scan report`
- Results:
  - Validator exited `0`, `ok: 1`; generated `-ag-*` reports were unchanged for ownership coverage, and the target was not in generated stats lists.
  - Validator normal side effects: `project-level/-auto-completion-stats.md` projected path section update and validator registry rebuild.
  - Memory-ranges exited `0`, wrote `auto-generated/by-memory-tool-report.md`.
  - Post-regeneration check: `Select-String` finds no `InterfaceEfxReadOnlyData` entry in `auto-generated/by-memory-tool-report.md`; the first remaining Advanced-Error-Scan entry is unrelated `SelfLookPaneRectConstantsA`.
- Dry runs: none used.
- C++ reconstruction: none entered.

## Files Changed By This Pass
- Direct in-scope edit:
  - `by-memory/0x0061c5a0-0x0061c7a4.InterfaceEfxReadOnlyData.md`.
- Generated/tool side effects from validation/report refresh:
  - `auto-generated/by-memory-tool-report.md`.
  - `project-level/-auto-completion-stats.md`.
  - `tools/validator.ini`.
- Not edited directly:
  - `by-memory/-coverage-report.md`.

## Confidence
- Final confidence in the recommendation: high.
- Remaining uncertainty: only final original source-file naming and inherited base/interface names for related classes, which do not affect this parent aggregate's owner/emitter/range decision.
- No further repair is required for the assigned advanced-scan target after the target-page body fix and regenerated memory-range report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00025K-InterfaceEfxReadOnlyData-advanced-scan.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"00025K"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
