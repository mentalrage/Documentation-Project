** TARGET-REPORT-UID:000256 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B007 Report - [UID:000256] EmployeeDialogReadOnlyData Source Quality

Assignment id: `B007-revise-000256-EmployeeDialogReadOnlyData-source-quality-20260627` (revision of `B007-report-000256-EmployeeDialogReadOnlyData-source-quality-20260627`)

Mode: report-only revision. No by-* documentation, generated files, coverage reports, validator state, tool state, or IDA DB edits were made.

Primary target: [UID:000256] `by-memory/0x00618efc-0x0061929c.EmployeeDialogReadOnlyData.md`

## Executive Recommendation

Keep [UID:000256] as the employee-dialog `.rdata` aggregate at `0x00618efc-0x0061929c`, keep `CANONICAL_OWNER:0000J0`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:0000J0`, and keep the formal `RECONSTRUCTION_CPP CODE` value/block blank. Raise the source page from `86/91` to `90/92` after implementation because this pass reconfirms the aggregate boundary, all exact vtable-data children, the resource literal tail, the successor AddEmployee warning split, and the source/resource ownership route with current live MCP evidence.

Do not emit raw vtable bytes or a synthetic read-only-data initializer. The source-level rebuild should come from employee-dialog class declarations, virtual methods, inherited interface shape, and feature-local/static resource-string declarations. The compiler/linker should regenerate this storage.

Required support cleanup is documentation-only:

- Fix stale target wording that still treats DAT payload/localized id evidence as open. `employee-dialog-resources` already closes `SELLER.*`, `SELLITEM.*`, shared `DLGEXC3.EPF`, and localized string id `247`; the remaining open issue is final per-string/source declaration style for mixed tail fragments.
- Fill/update [UID:0003V6] `EmployeeDialogResourceLiteralTail` summary/detail with the direct decoded tail fragments from this pass.
- Preserve the already-correct decoded UTF-16LE warning in [UID:0001OE] `AddEmployeeSingleSelectionAlertText` and [UID:0001R9] `employee-dialog-resources`: `한번에 여러개를 추가할 수 없습니다.`. Do not implement the supervisor-rejected `Ã...` mojibake rendering as source-facing text; it is stale rendering evidence only.
- Remove stale support-child wording that still references old `AUTOGEN_PARENT_UID` terminology or old blocked parent gates, especially [UID:0002ME], [UID:0002MH], and the vtable-family support page [UID:0001XH].

No split or rename is recommended for UID `000256`. The existing child split is correct: four exact vtable-data children plus the exact resource-tail child; the independently referenced AddEmployee warning stays outside the parent at `0x0061929c`.

## Current Target State

Source page state before implementation:

- Header score: `COMPLETION:86`, `CONFIDENCE:91`.
- Owner/emitter: `CANONICAL_OWNER:0000J0`, `EMITTER_UIDS:0000J0`, source file [UID:0000J0] `EmployeeDialogPane`.
- Reconstructable: `TRUE`.
- Formal C++: inline value empty and multiline block empty.
- Range: `0x00618efc-0x0061929c`, size `0x3a0` / 928 bytes (Verified with `tools/int_convert.py`).
- Existing source summary: employee dialog `.rdata` island with exact vtable-data children and a resource-tail child, but still describes tail resource-literal/DAT/localized-string follow-ups as open.

Generated state is stale relative to the source page:

- `auto-generated/-ag-research-tracker.md` still lists UID `000256` as `78/88`, combined `83.0`, in the reconstructable not-covered queue.
- `auto-generated/-ag-coverage-report-by-memory.md` still shows the old `78% : strong` row updated `2026-06-23`.
- `auto-generated/-ag-memory-coverage.md` shows the route as `emits` through `0000J0` but does not carry the source page's current `86/91` detail.

The implementation callback should rely on the source by-* files as the source of truth, then run scoped validators with `--wait-generated` so generated reports catch up.

## Documents Checked

Primary and direct support:

- [UID:000256] `by-memory/0x00618efc-0x0061929c.EmployeeDialogReadOnlyData.md`
- [UID:0000J0] `by-file/EmployeeDialogPane.md`
- [UID:0001XH] `by-type/by-vtable/EmployeeDialogPaneVtables.md`
- [UID:0001R9] `by-resource/employee-dialog-resources.md`
- [UID:0002ME] `by-memory/0x00618efc-0x00618f98.EmployeeDialogPaneVtableData.md`
- [UID:0002MF] `by-memory/0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData.md`
- [UID:0002MG] `by-memory/0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData.md`
- [UID:0002MH] `by-memory/0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData.md`
- [UID:0003V6] `by-memory/0x0061916c-0x0061929c.EmployeeDialogResourceLiteralTail.md`
- [UID:0001OE] `by-memory/0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText.md`

Neighbor/support context:

- [UID:000255] `by-memory/0x00618e50-0x00618efc.DirectXBitmapReadOnlyData.md`
- [UID:0003I9] `by-memory/0x006192c6-0x006192c8.PostAddEmployeeAlertPadding.md`
- [UID:000257] `by-memory/0x006192c6-0x00619340.BinaryCodecDatReadOnlyData.md`
- [UID:000138] `by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md`
- [UID:00013A] `by-memory/0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md`
- Class headers for [UID:00004C], [UID:00004D], [UID:00004E], and [UID:000006].

Historical/current tracker context:

- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- Existing A001 notes show UID `000256` was previously raised to `86/91` and a tail child was created; this pass rechecked those facts rather than relying on them.

## Live IDA MCP Provenance

MCP was available and used. No IDA DB write tools were used.

- Endpoint: `http://127.0.0.1:13337/mcp`
- Server: `ida-pro-mcp` protocol `2025-06-18`
- Session/database: `80de0a67`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- Health: `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`

Read-only MCP tools used in this pass:

- `server_health`
- `entity_query`
- `get_int`
- `get_bytes`
- `get_string`
- `xrefs_to`

Local numeric conversion tool used:

- `python .\tools\int_convert.py 0x3a0`
- `python .\tools\int_convert.py 0x130`
- `python .\tools\int_convert.py 0x2`

## Range And Boundary Findings

The aggregate remains exactly `0x00618efc-0x0061929c`.

Positive boundary evidence:

- Predecessor [UID:000255] ends at `0x00618efc`. Its live/documented evidence treats `0x00618efc` as the next owner boundary, the `EmployeeDialogPane` RTTI pointer.
- Current MCP `get_int u32le` shows `0x00618efc -> 0x006468bc`, the `??_R4EmployeeDialogPane@@6B@` RTTI/COL pointer, followed by `0x00618f00 -> 0x004a4d40`, the first `EmployeeDialogPane` primary vtable slot.
- Current MCP `entity_query names 0x00618ef0-0x006192d0` reports only `.rdata` names in the parent range: the twelve employee-dialog vtable labels plus tail string labels. It reports no functions and no imports inside the parent range.
- Current MCP bytes at `0x00619290` show the end of `DLGEXC3.EPF` through the null terminator at `0x0061929a-0x0061929b`, then the successor warning starts at `0x0061929c`.
- Current MCP direct UTF-16LE decode of `0x0061929c` gives `한번에 여러개를 추가할 수 없습니다.`. That confirms the successor [UID:0001OE] starts at the parent exclusive end.
- Current MCP bytes at `0x006192c6` are `00 00`, and `0x006192c8 -> 0x00646b2c` is the following `Encoder` RTTI pointer.

Negative boundary evidence:

- `xrefs_to 0x006192c6` returns zero refs, supporting [UID:0003I9] as padding after the AddEmployee warning rather than a source-owned string/data start.
- `xrefs_to 0x006192c8` returns zero refs to the RTTI pointer itself; the next container's relevant vtable refs begin at later codec vtable slots. This does not pull the `Encoder` data back into UID `000256`.
- No MCP evidence found any code or import entity inside `0x00618efc-0x0061929c`; the parent remains `.rdata`, not executable code.

## Exact Child Findings

The existing child split is correct and should not be changed.

| Range | Child | Current disposition |
| --- | --- | --- |
| `0x00618efc-0x00618f98` | [UID:0002ME] `EmployeeDialogPaneVtableData` | Exact class vtable-data child; owner/emitter should remain [UID:00004C]. Support summary needs stale no-assignment wording removed. |
| `0x00618f98-0x00619034` | [UID:0002MF] `EmployeeItemPropertyDialogPaneVtableData` | Exact class vtable-data child; owner/emitter [UID:00004D] remains correct. |
| `0x00619034-0x006190d0` | [UID:0002MG] `EmployeeQuantityInputDialogPaneVtableData` | Exact class vtable-data child; owner/emitter [UID:00004E] remains correct. |
| `0x006190d0-0x0061916c` | [UID:0002MH] `AddEmployeeItemDialogVtableData` | Exact class vtable-data child; owner/emitter [UID:000006] remains correct. Support summary needs stale `0001XH` parent-gate wording removed. |
| `0x0061916c-0x0061929c` | [UID:0003V6] `EmployeeDialogResourceLiteralTail` | Exact resource/string tail child; owner/emitter [UID:0000J0] remains correct. Item Summary is blank and tail detail should be strengthened with current decoded fragments. |

Representative current MCP vtable/xref confirmation:

- `EmployeeDialogPane` vtable bases `0x00618f00`, `0x00618f60`, and `0x00618f90` have constructor/destructor/scalar-deleting-destructor store refs at `0x004a1dc1/0x004a231c/0x004a4d73`, `0x004a1dc7/0x004a2322/0x004a4d79`, and `0x004a1dd1/0x004a232c/0x004a4d83`.
- `EmployeeItemPropertyDialogPane` vtable bases `0x00618f9c`, `0x00618ffc`, and `0x0061902c` have constructor store refs from `0x004a41c0`.
- `EmployeeQuantityInputDialogPane` vtable bases `0x00619038`, `0x00619098`, and `0x006190c8` have constructor store refs from `0x004a4770`.
- `AddEmployeeItemDialog` vtable bases `0x006190d4`, `0x00619134`, and `0x00619164` have live inline construction refs from `0x004a3240` and raw constructor-shaped byte refs at `0x004a4afe`, `0x004a4b04`, and `0x004a4b0e`.

## Resource Tail Findings

Current byte evidence strengthens [UID:0003V6] and the target parent. `get_string` is not reliable here: it returned truncated values like `S`, `DL`, and `\` for several UTF-16 strings because IDA labels some interior positions. Direct byte decoding is the evidence to record.

The `0x0061916c-0x0061929c` tail size is `0x130` / 304 bytes (Verified with `tools/int_convert.py`).

| Address | Direct decoded value/role | Xref result |
| --- | --- | --- |
| `0x0061916c` | UTF-16LE `Employee` | one xref at `0x004a1da9` in `sub_4A1D70` |
| `0x00619180` | UTF-16LE `SELLER.EPF` | one xref at `0x004a25b8` in `sub_4A2560` |
| `0x00619198` | UTF-16LE `SELLER.PAL` | one xref at `0x004a25c4` in `sub_4A2560` |
| `0x006191b0` | UTF-16LE `%u` | 15 xrefs; employee hits plus non-employee shared consumers |
| `0x006191b8` | UTF-16LE `철거까지 %d 시간 미만 남았습니다.` | one xref at `0x004a2a0c` in `sub_4A2560` |
| `0x006191e4` | UTF-16LE ` 전` | one xref at `0x004a2c01` in `sub_4A2A60` |
| `0x006191ec` | UTF-16LE `%s [ %d ] : ` | one xref at `0x004a2c3c` in `sub_4A2A60` |
| `0x00619208` | CP949-looking bytes decode as `의고용상인` | two refs: `0x004a3193` in `sub_4A2F60`, plus raw helper hit `0x004a40b3` |
| `0x00619214` | UTF-16LE `(%d%%)` | four refs including employee record/update helpers and non-employee `0x0051ecc5` |
| `0x00619224` | UTF-16LE `Property` | one xref at `0x004a41f8` in `sub_4A41C0` |
| `0x00619238` | UTF-16LE `SELLITEM.EPF` | one xref at `0x004a45c1` in `sub_4A4570` |
| `0x00619254` | UTF-16LE `SELLITEM.PAL` | one xref at `0x004a45cd` in `sub_4A4570` |
| `0x00619270` | UTF-16LE `Quantity` | one xref at `0x004a47a6` in `sub_4A4770` |
| `0x00619284` | UTF-16LE `DLGEXC3.EPF` | ten refs; employee quantity hits at `0x004a4810` and `0x004a4988`, plus non-employee dialog users |

Resource/DAT follow-up status:

- Closed for UID `000256`: [UID:0001R9] already records DAT/package provenance for `SELLER.EPF`, `SELLER.PAL`, `SELLITEM.EPF`, `SELLITEM.PAL`, shared `DLGEXC3.EPF`, and `baram.dat` `STR.RES` localized id `247` as `Add how many?`.
- Still intentionally not modeled as final source declarations: exact per-string child pages and final source names for the mixed UTF-16/CP949 fragments. This is not a blocker for UID `000256` because the bounded tail child now records byte starts, xrefs, ownership, and source/resource boundaries at implementation-ready detail.

## Successor AddEmployee Warning

The successor [UID:0001OE] starts exactly at `0x0061929c`, outside UID `000256`.

Current direct decode:

- Address: `0x0061929c`
- Encoding: UTF-16LE
- Value: `한번에 여러개를 추가할 수 없습니다.`
- Working English meaning: "Cannot add multiple items at once."
- `xrefs_to 0x0061929c`: exactly one xref, `0x004a4bc1` inside [UID:00013A] `AddEmployeeItemDialog`.
- Bytes after the string: null terminator through `0x006192c4-0x006192c5`, two padding bytes at `0x006192c6-0x006192c8`, then `0x006192c8 -> 0x00646b2c` for the next codec RTTI pointer.

[UID:0001OE] and [UID:0001R9] were rechecked during this revision and already show the readable decoded warning text `한번에 여러개를 추가할 수 없습니다.` at same-or-greater detail, with the English meaning and source/resource caveats preserved. Implementation should verify and preserve that text, not overwrite it. The rejected `Ã...` rendering is only a stale mojibake artifact from an earlier report interpretation and must not be written into any by-* doc as the decoded value.

## Source Placement And Ownership Decision

Confirmed direct owner for UID `000256`: [UID:0000J0] `EmployeeDialogPane`.

Reasoning:

- Every exact child is employee-dialog family data: `EmployeeDialogPane`, `EmployeeItemPropertyDialogPane`, `EmployeeQuantityInputDialogPane`, `AddEmployeeItemDialog`, and the employee resource/string tail.
- The source file page [UID:0000J0] is `90/88`, has valid projected path `NexusTK/ui/dialogs/`, and already groups the same employee dialog class family.
- The executable aggregate [UID:000138] is `90/92` and documents the corresponding employee dialog code family with a no-monolithic-C++ disposition.
- Generic [UID:0000KE] `ItemDialogs` remains a dependency for base `AddItemDialog` behavior, but the add-employee variant stores an `EmployeeDialogPane*`, uses employee resource id `247`, and dispatches employee command kind `5`.
- [UID:0001R9] supports resource/package interpretation but is not a generated source owner. Resource pages index payloads and text-table provenance; source declarations belong with the consuming file/class/memory pages.

Rejected owner/source alternatives:

- Reclassify UID `000256` as non-reconstructable index-only: rejected. Unlike predecessor [UID:000255], this parent is not mixed DIBitmap/DirectX ownership; it is a coherent employee-dialog read-only data island whose source declarations route through one employee source module.
- Move the resource tail to by-resource/DAT ownership only: rejected. The asset payloads are resource-derived, but the string/resource filename constants and UI labels are source-declared/generated-binary data consumed by employee dialog code.
- Make `DLGEXC3.EPF`, `%u`, or `(%d%%)` employee-exclusive: rejected. Current xrefs show shared non-employee consumers, so support docs must preserve shared-string caveats.
- Merge the successor AddEmployee warning into UID `000256`: rejected. The warning has an independent xref at `0x004a4bc1` and exact byte boundary at `0x0061929c`, and it already has a separate by-memory page.

## Heuristic / Inference Reanalysis

Compiler-generated vtable/data versus source declarations:

- The four vtable-data children are reconstructable because the rebuilt source must declare the same classes and virtual methods, but the raw `.rdata` bytes are compiler/linker output. Rebuild handling remains `source-declared/generated-binary`.
- Support pages should describe vtable slots and class ownership, not emit arrays of raw function pointers as source C++.

Resource literal tail:

- Resource filenames and labels are source declarations or source-visible constants. DAT entries are payload provenance, not the C++ declaration home.
- The current pass closes the DAT/localized-string blocker for this parent: package/id facts are available in [UID:0001R9]. Remaining source-style uncertainty is narrow: final constant names, exact per-string child pages if desired, and whether the mixed Korean/CP949 tail fragments should be modeled as UTF-16 literals, narrow CP949 literals, or resource/string-table lookups.

Generated-output pollution:

- The generated reports are stale relative to the source by-* docs. This is not a target evidence contradiction; it is a validator refresh expectation.
- Existing support pages still contain old `AUTOGEN_PARENT_UID` wording and stale item summaries from before direct class owners cleared the gate. Those are documentation wording defects, not metadata defects.

First-draft C++ readiness:

- UID `000256` clears the minimum numeric/emitter gate, but formal C++ is still intentionally blank because the target is a multi-child `.rdata` aggregate. Writing C++ here would either duplicate child class declarations, hand-author compiler vtables, or conflate employee resource constants with shared string/resource ownership.
- Exact method children that are source-authored already carry or can carry their own C++. UID `000256` should remain a no-monolithic-C++ aggregate.

## Score And Metadata Recommendation

Recommended target metadata after implementation:

| Field | Before | After | Rationale |
| --- | --- | --- | --- |
| `COMPLETION` | `86` | `90` | Current source page already has exact child splits. This pass adds current MCP proof for the range, boundary, child xrefs, direct decoded tail fragments, successor warning split, and closure of DAT/localized-id provenance as parent blockers. |
| `CONFIDENCE` | `91` | `92` | Current MCP independently reconfirms the existing split and source route. Keep below final-audit range because per-string child/source declaration style and some inherited vtable slot names are not final. |
| `CANONICAL_OWNER` | `0000J0` | `0000J0` | EmployeeDialogPane file remains the narrow coherent source module for the aggregate. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | The parent represents source-declared/generated-binary employee dialog `.rdata`, not disposable padding/runtime data. |
| `EMITTER_UIDS` | `0000J0` | `0000J0` | The route surfaces to `NexusTK/ui/dialogs/EmployeeDialogPane.cpp`; the block remains blank. |
| Formal C++ | blank | blank | Target-specific no-code proof above. |

Recommended support metadata:

- [UID:0003V6] `EmployeeDialogResourceLiteralTail`: raise from `85/91` to `88/92` if the direct decoded fragment table and non-blocking source-style caveat are incorporated; keep owner/emitter/reconstructable and blank C++.
- [UID:0001OE] `AddEmployeeSingleSelectionAlertText`: no score change recommended. The current page already has the correct decoded warning text, exact range, sole xref, boundary evidence, English meaning, owner/emitter/reconstructable state, and blank-C++ rationale at same-or-greater detail than this revision requires. Implementation should record same-or-greater/no-edit proof unless it finds a stale `Ã...` artifact in the live file.
- [UID:0001R9] `employee-dialog-resources`: no score change recommended. The current resource page already has the correct decoded warning text in the Resource Strings row and IDA evidence section, plus current package/resource context. No reconstruction metadata applies beyond the owner field already present.
- [UID:0002ME] and [UID:0002MH]: no score change required; update stale summaries/body wording only.
- [UID:0001XH]: no score change required; update stale routing terminology only.

## Target And Support Docs To Update After Acceptance

Required target doc update:

- `by-memory/0x00618efc-0x0061929c.EmployeeDialogReadOnlyData.md`
  - Change score to `90/92`.
  - Keep owner/emitter/reconstructable unchanged.
  - Keep formal C++ blank.
  - Update `Item Summary`, `Summary`, `Evidence`, `Rebuild Notes`, `Score Rationale`, and `Changes` to reflect this B007 live MCP pass, direct decoded tail fragments, closed DAT/localized-id provenance, current stale-generated-row state, and remaining non-blocking per-string/source-declaration caveats.

Required support doc updates:

- `by-memory/0x0061916c-0x0061929c.EmployeeDialogResourceLiteralTail.md`
  - Fill the blank `Item Summary`.
  - Add current direct decode details for `철거까지 %d 시간 미만 남았습니다.`, ` 전`, and CP949 `의고용상인`.
  - State that DAT/localized-id package provenance is already covered by [UID:0001R9]; remaining caveat is final source declaration/style, not parent-blocking resource provenance.
  - Recommended score `88/92`, owner/emitter/reconstructable unchanged, formal C++ blank.

- `by-memory/0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText.md`
  - Verify and preserve the already-correct decoded warning `한번에 여러개를 추가할 수 없습니다.` and retain the English meaning.
  - Verify the existing byte/xref/boundary proof remains present at same-or-greater detail: one xref at `0x004a4bc1`, two padding bytes at `0x006192c6`, next RTTI dword at `0x006192c8`.
  - Do not write the supervisor-rejected `Ã...` stale rendering as the decoded text.
  - No score/metadata change recommended; keep owner/emitter/reconstructable unchanged and formal C++ blank.

- `by-resource/employee-dialog-resources.md`
  - Verify and preserve the Resource Strings row for `0x0061929c-0x006192c6` as `한번에 여러개를 추가할 수 없습니다.`.
  - Verify the IDA evidence section already records the same decoded warning and xref at same-or-greater detail.
  - Do not write the supervisor-rejected `Ã...` stale rendering as the decoded text.
  - No score/metadata change recommended unless a separate, non-duplicate evidence improvement is added during an accepted implementation callback.

- `by-memory/0x00618efc-0x00618f98.EmployeeDialogPaneVtableData.md`
  - Update the `Item Summary` and any gate wording that still says assignment is deliberately blocked. Header metadata already routes to [UID:00004C]; no metadata change required.
  - Replace old `AUTOGEN_PARENT_UID` wording in prose with current `CANONICAL_OWNER` / `EMITTER_UIDS` terminology.

- `by-memory/0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData.md`
  - Update the `Item Summary` so it no longer says the valid parent gate is [UID:0001XH]. Header metadata already routes to [UID:000006]; no metadata change required.
  - Preserve [UID:0001XH] as the family-level support page, not the direct owner.

- `by-type/by-vtable/EmployeeDialogPaneVtables.md`
  - Replace stale autogen/old-gate prose with current `CANONICAL_OWNER:0000J0` / `EMITTER_UIDS:0000J0` terminology and the current 85/85 gate language.
  - No score or metadata change required.

No manual edits should be made to `auto-generated/*`, `project-level/*`, or any `-coverage-report.md` file. Generated tracker/coverage updates should come from validators and later supervisor `execute_report`.

## Validator Plan After Implementation

Run scoped validators from `source-3/project-documentation`, with `--wait-generated` because generated coverage/tracker state is currently stale and generated output freshness matters:

> Executable block R001 was removed from this report and preserved verbatim in [000256-EmployeeDialogReadOnlyData-source-quality-removed.md](000256-EmployeeDialogReadOnlyData-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the implementation decides that [UID:0001OE], [UID:0001R9], or [UID:0001XH] already contain same-or-greater detail after closer editing review, record the explicit no-edit proof in the implementation checklist and skip that validator. Only validate [UID:0001OE] or [UID:0001R9] if an accepted callback actually edits those files.

After the supervisor verifies implementation, the supervisor should execute the report through the normal executed-report lifecycle command. B007 should not manually move this report or edit validator state.

## Implementation Tracking Checklist

- [x] `by-memory/0x00618efc-0x0061929c.EmployeeDialogReadOnlyData.md`: update score to `90/92`; preserve `CANONICAL_OWNER:0000J0`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000J0`; leave formal `RECONSTRUCTION_CPP CODE` value/block blank; update summary/evidence/rebuild/score/change text with B007 MCP proof, direct tail decode, closed DAT/localized-id provenance, stale generated-report note, and no-monolithic-C++ proof.
- [x] `by-memory/0x0061916c-0x0061929c.EmployeeDialogResourceLiteralTail.md`: fill `Item Summary`, add decoded tail fragments including `철거까지 %d 시간 미만 남았습니다.`, ` 전`, and CP949 `의고용상인`; state DAT/localized-id provenance is closed through [UID:0001R9]; recommended score `88/92`; leave formal C++ blank.
- [x] `by-memory/0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText.md`: verify and preserve the already-correct decoded UTF-16LE value `한번에 여러개를 추가할 수 없습니다.`; confirm existing byte/xref/boundary proof is same-or-greater detail; do not write the stale `Ã...` mojibake artifact as decoded text; no score change recommended; leave formal C++ blank; record same-or-greater/no-edit proof unless the accepted callback requires an actual edit.
- [x] `by-resource/employee-dialog-resources.md`: verify and preserve the `0x0061929c-0x006192c6` warning text as `한번에 여러개를 추가할 수 없습니다.`; confirm current resource-row and IDA-evidence detail is same-or-greater; do not write the stale `Ã...` mojibake artifact as decoded text; no score change recommended unless a separate non-duplicate evidence improvement is added; record same-or-greater/no-edit proof unless the accepted callback requires an actual edit.
- [x] `by-memory/0x00618efc-0x00618f98.EmployeeDialogPaneVtableData.md`: remove stale no-assignment/gate wording from the item summary/body and use current `CANONICAL_OWNER`/`EMITTER_UIDS` terminology; no metadata score change expected.
- [x] `by-memory/0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData.md`: remove stale [UID:0001XH] direct-parent wording from the item summary/body; preserve [UID:0001XH] only as family support and [UID:000006] as direct owner/emitter; no metadata score change expected.
- [x] `by-type/by-vtable/EmployeeDialogPaneVtables.md`: update stale autogen/old-gate prose to current owner/emitter terminology and preserve no-raw-vtable-C++ guidance; no score change expected.
- [x] Confirm no by-* split, rename, new child file, generated report edit, manual `-coverage-report.md` edit, project-level generated edit, validator/tool-state edit, or IDA DB edit is made.
- [x] Run scoped validators with `--wait-generated` for every edited by-* file, report each command's `command_id`, `command_timestamp`, exit code, `ok` count, warnings, and generated refresh status.
- [x] After validators, verify generated rows for UID `000256` and affected support docs are current or explicitly report any generated-refresh lag by comparing generated headers to the validator command metadata.
- [x] Release any implementation leases immediately after the edit/validator batch and record lease release/expiry proof.

Implementation callback proof before lease release:

- [x] UID `000256` header is `90/92`, owner/emitter remain `0000J0`, reconstructable remains `TRUE`, formal C++ stays blank, and the page records B007 session `80de0a67`, exact boundary/tail/successor evidence, [UID:0001R9] provenance closure, stale generated-report context, and no-monolithic-C++ handling.
- [x] UID `0003V6` header is `88/92`, owner/emitter remain `0000J0`, formal C++ stays blank, the item summary is filled, and decoded fragments include `철거까지 %d 시간 미만 남았습니다.`, ` 전`, and CP949-looking `의고용상인`.
- [x] UID `0001OE` was same-or-greater/no-edit: no lease, edit, or validator; it already preserves `한번에 여러개를 추가할 수 없습니다.` with the `0x004a4bc1` xref, `0x006192c6` padding boundary, `0x006192c8` successor RTTI note, existing score/metadata, and blank C++.
- [x] UID `0001R9` was same-or-greater/no-edit: no lease, edit, or validator; its resource row and IDA MCP evidence already preserve `한번에 여러개를 추가할 수 없습니다.` with the `0x004a4bc1` xref and current package/localized-id provenance.
- [x] UID `0002ME`, UID `0002MH`, and UID `0001XH` no longer contain stale no-assignment/direct-parent/autogen-gate wording in the implementation-scoped text; the post-edit scan found no `AUTOGEN_PARENT_UID`, no stale gate phrases, and no mojibake marker in the five edited docs.
- [x] No split, rename, new child file, generated report hand edit, generated C++ hand edit, manual coverage edit, project-level hand edit, manual validator/tool-state edit, or IDA DB edit was made. The required validators performed their normal generated/validator refresh only.
- [x] Validators: `000000004181` at `2026-06-27T11:24:37-04:00`, exit `0`, `ok: 1`, generated refresh completed, existing project-wide stale/missing generated noise plus `missing_ref_uid: 6` before UID `0003V6` mapping refresh; `000000004182` at `2026-06-27T11:25:02-04:00`, exit `0`, `ok: 1`, generated refresh completed, existing project-wide stale/missing generated noise; `000000004184` at `2026-06-27T11:25:23-04:00`, exit `0`, `ok: 1`, generated refresh completed, no target-specific warnings in filtered summary; `000000004185` at `2026-06-27T11:25:41-04:00`, exit `0`, `ok: 1`, generated refresh completed, no target-specific warnings in filtered summary; `000000004186` at `2026-06-27T11:25:59-04:00`, exit `0`, `ok: 1`, generated refresh completed, no target-specific warnings in filtered summary.
- [x] Generated rows verified: research tracker now lists UID `000256` as `90/92`, UID `0003V6` as `88/92`, UID `0002ME` as `89/92`, UID `0002MH` as `86/92`, and UID `0001XH` as `88/88`; memory coverage report rows updated at `2026-06-27 11:24:38`, `11:25:03`, `11:25:24`, and `11:25:42` for UID `000256`, `0003V6`, `0002ME`, and `0002MH` respectively.
- [x] Lease release/expiry proof: `leaser.py Agent-B007 unlease ...` returned `Rejected[No active lease]` for all five leased files after the validator batch, and `tools/leaser/Agents/current_leases.md` contains no `Agent-B007` rows and no rows for the five implementation paths.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/000256-EmployeeDialogReadOnlyData-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/000256-EmployeeDialogReadOnlyData-source-quality.md","timestamp":"2026-06-27T11:41:23","uid":"000256"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000256-EmployeeDialogReadOnlyData-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/000256-EmployeeDialogReadOnlyData-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000256"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
