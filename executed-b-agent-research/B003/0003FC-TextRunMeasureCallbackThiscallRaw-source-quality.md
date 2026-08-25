# UID0003FC TextRunMeasureCallbackThiscallRaw Source-Quality Report
** TARGET-REPORT-UID:0003FC **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


- Agent: B003
- Provenance: CHATGPT | 5.6 | xHigh
- Primary target: [UID:0003FC] `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md`
- Scope: source-quality research plus completed ordinary documentation implementation callback; lifecycle authority remains supervisor-owned.
- Evidence date: 2026-08-22

## Finalized Report / Current Recommendation

Keep UID0003FC at the exact half-open byte range `[0x00593cf0,0x00593dad)` and retain [UID:0000EO] `TextEditPane` as direct class owner/emitter with [UID:0000ON] `NexusTK/ui/controls/TextEditPane.cpp` as source placement. Reclassify the binary label from a callback to a compiler-retained, source-authored private member counterpart: `bool TextEditPane::MeasureTextRunSegment(...)`. The `ECX` receiver, seven stack arguments, `retn 0x1c`, neighboring raw TextEditPane members, and complete non-forwarding body exclude a cdecl callback thunk.

The pre-callback target formal body omitted the final-segment call to `0x004baad0`, and the pre-callback helper/source route used file-static `__stdcall` wording plus free-helper callback syntax. The current implemented formal and generated source restore that call, preserve the shipped helper's unusual terminal comparison, classify `0x004baad0` as the receiver-independent inherited member `GrafPort::AdjustVisibleCountForTrailingWhitespace`, route both cdecl siblings through `pane`, and emit the matching GrafPort declaration/definition. All four binary callers set their `TextEditPane`/GrafPort receiver in `ECX`, and the helper consumes two stack arguments with `retn 8`.

The current implemented target score is `92/93`, raised from the pre-callback baseline `85/88`. The remaining cap is limited to non-behavioral original lexical spellings and exact compiler option provenance, not an unresolved range, ABI, behavior, ownership, placement, type, or source-shape question.

The Section 21 Gate 2B rows are retained as the accepted historical entity-action/readback contract. Supervisor transaction `UID0003FC-20260822-071358557` completed that contract with result `APPLIED_VERIFIED_SAVED`; runtime binding, backup, save, semantic/physical readback, rollback protection, and persistence remained external supervisor operations, and no by-* page should copy an operational package from report text. The removed historical package is preserved only in the paired [inert companion](./0003FC-TextRunMeasureCallbackThiscallRaw-source-quality-removed.md), which is non-authoritative, must never be executed, and must remain physically beside this report through any lifecycle movement.

## Supporting Research

Research covered the exact target page; [UID:0001JQ] cdecl measurement callback; [UID:0001JR] cdecl drawing callback; raw member siblings at `0x00593880`, `0x00593b20`, and `0x00593f00`; [UID:00016C] GrafPort text-run helpers; [UID:0000EO] TextEditPane; [UID:0000EN] TextEditObject; [UID:00005V] GrafPort; [UID:0000ON] TextEditPane source unit; the `TextRunMeasureState`, `TextRunFormatData`, and `TextEditLineRecord` declarations; current generated TextEditPane/GrafPort CPP/H; `by-memory/-coverage-report.md`; `by-class/-coverage-report.md`; matching active, archived, and executed B-report text; and the historical UID0000OJ whole-file incorporation.

Historical conclusions were treated as leads. The dated pre-Gate2B raw extent, bytes, item state, instruction flow, helper receiver ABI, xrefs, immediate/pointer routes, type-library state, comments, neighboring functions, generated output, and physical PE bytes were independently rechecked; final canonical verifier session `supervisor_uid0003fc_verify_20260822_0718` then read back the accepted IDA entities and protections. Search terms included `0003FC`, `0x00593cf0`, `TextRunMeasureCallbackThiscallRaw`, `MeasureTextRunSegment`, `TextRunMeasureState`, and `AdjustVisibleCountForTrailingWhitespace`.

No additional target UID is declared. Support recommendations below are the minimum exact consistency repairs forced by the primary target evidence.

## Target

| Field | Value |
| --- | --- |
| UID | `0003FC` |
| Page | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` |
| Documented range style | filename endpoint `0x00593dad` is exclusive; body last byte is `0x00593dac` |
| Physical function range | half-open `[0x00593cf0,0x00593dad)` |
| Physical size | `0xbd` / 189 bytes |
| Pre-callback baseline score | `85/88` |
| Current implemented score | `92/93` |
| Current owner/emitter | `0000EO` / `0000EO` |
| Recommended owner/emitter | unchanged |
| Source unit | `NexusTK/ui/controls/TextEditPane.cpp` through UID0000ON |
| Source identity | private `TextEditPane::MeasureTextRunSegment` member |
| Reconstructable | `TRUE`, unchanged |

## Current Target State

The accepted implementation callback has repaired the target and all authorized ordinary support pages. UID0003FC now contains the complete source-exact member body and an intentionally blank target H channel; its prose distinguishes the stable raw-page label from the source-authored private `TextEditPane::MeasureTextRunSegment` identity. The formal member names and discards `textOffset`, uses `kTextRunHasNextSegment`, calls the inherited visible-count helper before final non-object measurement, preserves the shipped helper comparison, and accesses the protected object payload through the class-level `friend class TextEditPane` route. UID0001JQ and UID0001JR remain cdecl callbacks and invoke the helper through `pane`; UID00016C and UID00005V emit one non-static GrafPort member definition/declaration in source order. All accepted scores, owner/emitter routes, state layout, source placement, and historicalization are applied.

Final supervisor-verified mutable generated receipts, physically reread again read-only during this reconciliation:

| Output | Validator command | Validator refreshed at | Bytes | LF lines | SHA256 |
| --- | --- | --- | ---: | ---: | --- |
| `auto-generated/NexusTK/ui/controls/TextEditPane.cpp` | `000000026443` | `2026-08-22T06:46:02-04:00` | 125749 | 3532 | `DBC306945C977FAA9218F029E880327175D1A19C91C7E2BAC847541455ECAB53` |
| `auto-generated/NexusTK/ui/controls/TextEditPane.h` | `000000026443` | `2026-08-22T06:46:02-04:00` | 22597 | 574 | `2181D40E69E70A4F84F3956179413EA189AEDCC25FCD21F6ECD7C695C01DD75E` |
| `auto-generated/NexusTK/render/GrafPort.cpp` | `000000026444` | `2026-08-22T06:46:20-04:00` | 38415 | 1156 | `8E6DAA54960C169386D86C5AA31F4B8A02B30BC52CC05E8F5BEBDF25EEF82EB0` |
| `auto-generated/NexusTK/render/GrafPort.h` | `000000026444` | `2026-08-22T06:46:20-04:00` | 5169 | 126 | `C4A7842040F7D7E2ECEEB0BA411DB336F0661D6E9DDD1BB8107056EE14C41697` |

These identities remain a dated mutable snapshot, not durable generated-source authority. Scoped supervisor validators `000000026435` through `000000026443` and owner refresh `000000026444` passed before this physical reread. Commands `000000026289`, `000000026323`, and `000000026355` and their prior hashes, sizes, and line counts are historical superseded snapshots rather than final supervisor-verification receipts.

The fresh semantic reread confirms the repaired topology. TextEditPane CPP defines `TextEditPane::MeasureTextRunSegment` once at line 2622, calls the inherited helper at line 2643, measures `text, visibleCount` at line 2650 with no target `charCount` width call, and matches the accepted formal block including the blank line before `return false`. Its four helper calls are exactly the pane-qualified cdecl measure/draw calls at lines 2600 and 2725 plus the inherited raw-member calls at lines 2643 and 2761. GrafPort CPP emits one non-static `GrafPort::AdjustVisibleCountForTrailingWhitespace` definition at line 886 between `GetLineHeight` line 879 and `DrawGlyphWithTextColors` line 903; GrafPort H emits one declaration at line 85. TextEditPane H emits one `TextRunMeasureState` definition, one target declaration at line 481, `friend class TextEditPane` once at line 188, and exactly one `TextEditObject`, `TextEditScrap`, and `EPFTextEditObject` definition at lines 171, 212, and 560. No aggregate duplicate-removal edit occurred.

The exact by-memory and by-class coverage rows in Section 28 were applied by the supervisor and validated with commands `000000026445` and `000000026446`. Read-only reconciliation confirms UID0003FC is present between UID0001JQ and UID0001JR and all six named insert/replacement rows are physically present. Within the retained literal UID0003FC coverage payload, `no-IDA-function` describes the dated pre-Gate2B research baseline, not the final canonical IDA state.

Current canonical IDA receipt: final path `E:/NTK/Resources/NexusTK/NexusTK.exe.i64`, length `143211145`, SHA256 `F5941D0C032A4022F5C59633EA4BFE740ADCD508CE726619E9C5219C3D567DD2`, result `APPLIED_VERIFIED_SAVED`. The canonical target is the exact function `[0x00593cf0,0x00593dad)` named `TextEditPane__MeasureTextRunSegment`; the helper at `0x004baad0` is `GrafPort__AdjustVisibleCountForTrailingWhitespace`; both carry the accepted signatures/comments, and exact verifier details are in Supervisor Active Recheck and IDA MCP Facts.

## Executive Recommendation

1. Preserve UID0003FC, its exact range, owner/emitter, source file, source order, reconstructable state, and blank target H channel.
2. Replace only the target formal CPP body with the complete member source in Section 22.
3. Reclassify `0x004baad0` as a GrafPort member with an unsigned-short return, signed-short count input, and exact observed no-op-prone terminal comparison.
4. Update the two modeled cdecl callbacks to invoke that member through `pane`; raw members already carry the receiver.
5. Add the member declaration to GrafPort H and `friend class TextEditPane` to TextEditObject H.
6. Preserve the refreshed single-owner support-class route: UID0000EN, UID0000EP, and UID00004H each emit once, so no UID0000EO aggregate-removal edit is authorized.
7. Retain A01-A10, CACHE-01/CACHE-02, AT01, PRE/POST, and P01-P06 as the accepted historical contract behind final supervisor result `APPLIED_VERIFIED_SAVED`; this report supplies no persistence program.
8. Preserve the exact manual coverage rows applied and validated by supervisor commands `000000026445` and `000000026446`; all further execution/archive state remains external to ordinary report prose.

## Supervisor Active Recheck

Historical pre-Gate2B research used IDA MCP read-only. At that dated baseline, `runtime_attestation(expected_database="2e5d96cf")` returned schema `1`, top-level `ok:true`, empty top-level and worker errors, and the following then-live route:

| Role | Endpoint | Process/generation | Nonce | Manifest |
| --- | --- | --- | --- | --- |
| listener `supervisor_listener` | `127.0.0.1:13337` | PID `3612`, parent `17668`, `pid:3612;created:134318146704590877` | `53c5ffea3c9e38c1026967804974d5aa` | `D3C792133956B855EBA751FDB5783B2D7177FA204134CFF1D897E0D0770FB7CE` |
| worker `stateful_worker` | `127.0.0.1:64022` | PID `11036`, parent/redirector `15748`, `pid:11036;created:134318274450523827` | `d549844de487c9050608508c3ffd5f69` | `2E883F9025B9811708B812077B7194021F72F741508E32BEEA1A491A59B23C00` |

Both roles then loaded from `C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp`. The package was attested at `2026-08-22T07:26:34Z`. Session `2e5d96cf` was the owned worker route for the NexusTK database copy at `C:\FastStorage\NTK_Sources\source-3\project-documentation\tools\leaser\Agents\ida-backups\NexusTK.exe.uid0000JA-i11i12repair-tx-20260821T225356038Z.i64`. `server_health` returned `status:ok`, image base `0x00400000`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, Hex-Rays ready, and 2,067 cached strings. `auto_analysis_ready:false` did not block any bounded target query. Listener and worker manifests were role-specific and were not required to equal each other.

At that pre-Gate2B baseline, the adopted canonical session entry at `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` was inactive and its stale worker was unreachable, so it was not used for research. The research worker answered all required bounded reads coherently; no repeated MCP failure occurred. This dated route is evidence only and is not a statement about current process/session state.

Historical supervisor Gate 2B failure evidence: isolated disposable session `supervisor_uid0003fc_gate2b_20260822_0649` matched PRE-01 through PRE-08. A01 declared the exact 12-byte `TextRunMeasureState`; A02 defined exactly `[0x00593cf0,0x00593dad)` as temporary `sub_593CF0`, size `0xbd`, with 72 instructions and the post-pad excluded. Immediately after A02, public `stack_frame({"database":"DB","addrs":"0x00593cf0"})` returned exactly two rows: `__saved_registers` offset `0x14`, size `0x4`, type `_DWORD`, and `__return_address` offset `0x18`, size `0x4`, type `_UNKNOWN *`; it returned no local or argument rows. That result disproved the former POST-05 enumeration contract, not the machine-code ABI. The supervisor stopped before A03, discarded the disposable transaction, and did not promote it. Canonical IDB length `143211069` and SHA256 `39754A1765590C4814C6716E645A0DFF974C8B4C83D1761980D11DE6D80D8B11` remained unchanged; no target rename, function type, or comment reached canonical state.

Historical supervisor Gate 2B retry evidence: fresh isolated disposable session `supervisor_uid0003fc_gate2b_retry_20260822_0703` again matched PRE-01 through PRE-08, and A01 through A10 all succeeded in the disposable working copy. POST-05 matched the exact pre-type two-row target result above. After A04, however, target `stack_frame` returned those two metadata rows plus exactly seven typed argument rows: `line` offset `0x1c`, size `0x4`, type `TextEditLineRecord *`; `format` offset `0x20`, size `0x4`, type `const TextRunFormatData *`; `text` offset `0x24`, size `0x4`, type `const wchar_t *`; `textOffset` offset `0x28`, size `0x4`, type `int`; `charCount` offset `0x2c`, size `0x2`, type `unsigned __int16`; `segmentFlags` offset `0x30`, size `0x2`, type `unsigned __int16`; and `state` offset `0x34`, size `0x4`, type `TextRunMeasureState *`. It exposed no local rows. The helper post-type frame remained exactly `__saved_registers` 0x4/0x4 `_DWORD`, `__return_address` 0x8/0x4 `_UNKNOWN *`, `text` 0xc/0x4 `const wchar_t *`, and `count` 0x10/0x2 `__int16`. The false POST-09 contract stopped the transaction before save or promotion. Canonical IDB length `143211069` and SHA256 `39754A1765590C4814C6716E645A0DFF974C8B4C83D1761980D11DE6D80D8B11` remained unchanged; no IDA entity change reached canonical state.

Historical final supervisor Gate 2B receipt: clean transaction `E:/NTK/Resources/NexusTK/gate2b-transactions/UID0003FC-20260822-071358557`, working session `supervisor_uid0003fc_gate2b_final_20260822_0713`, began from canonical/baseline/working length `143211069` and rollback SHA256 `39754A1765590C4814C6716E645A0DFF974C8B4C83D1761980D11DE6D80D8B11`. PRE-01 through PRE-08, A01-A10, CACHE-01/CACHE-02, POST-01 through POST-13, and P01-P06 passed. The saved transaction was length `143211145`, SHA256 `F5941D0C032A4022F5C59633EA4BFE740ADCD508CE726619E9C5219C3D567DD2`; atomic promotion succeeded; and rollback artifact `NexusTK.exe.uid0003fc-canonical-prepromote.i64` retained the exact old length/hash. Fresh canonical verifier session `supervisor_uid0003fc_verify_20260822_0718` attested the exact canonical path and reproduced every accepted semantic/protection readback. Final result: `APPLIED_VERIFIED_SAVED`.

Final canonical semantic receipt: target `[0x00593cf0,0x00593dad)` is named `TextEditPane__MeasureTextRunSegment` with signature `bool __thiscall TextEditPane__MeasureTextRunSegment(TextEditPane *this, TextEditLineRecord *line, const TextRunFormatData *format, const wchar_t *text, int textOffset, unsigned __int16 charCount, unsigned __int16 segmentFlags, TextRunMeasureState *state)`. Its regular comment is `Measures one TextEditPane text-run segment, invokes final visible-count adjustment for non-object text, subtracts object/plain/masked width from TextRunMeasureState, clamps/stores final remaining width, and always returns false.` and repeatable comment is `bool TextEditPane::MeasureTextRunSegment(TextEditLineRecord *, const TextRunFormatData *, const wchar_t *, int, unsigned short, unsigned short, TextRunMeasureState *);`. Helper `0x004baad0` is named `GrafPort__AdjustVisibleCountForTrailingWhitespace` with signature `unsigned __int16 __thiscall GrafPort__AdjustVisibleCountForTrailingWhitespace(GrafPort *this, const wchar_t *text, __int16 count)`, regular comment `Scans backward over trailing space, tab, and carriage return; preserves the shipped count-versus-last-index terminal comparison.`, and repeatable comment `unsigned short GrafPort::AdjustVisibleCountForTrailingWhitespace(const wchar_t *text, short count);`. `TextRunMeasureState` is exactly 12 bytes with the accepted three `int` members. The target frame is the metadata pair plus seven typed arguments/no locals; the helper frame is the exact four rows. Target inbound xrefs remain zero; helper callers remain exactly `0x00593c72`, `0x00593d38`, `0x00593ed4`, and `0x00594019`; target callees are exactly the helper and `GrafPort__GetTextWidth`; helper has no callees. Final canonical `E:/NTK/Resources/NexusTK/NexusTK.exe.i64` is length `143211145`, SHA256 `F5941D0C032A4022F5C59633EA4BFE740ADCD508CE726619E9C5219C3D567DD2`.

## Inference Research Guidance Check

The inference pass separated three questions:

- Binary identity: a real code body with member ABI; the dated pre-Gate2B baseline had no IDA function object, and the final canonical now has the exact accepted function.
- Human source identity: a private TextEditPane member, not a callback pointer target or compiler thunk.
- Source dependency identity: the final-segment helper is an inherited GrafPort member even though it does not read the receiver.

Evidence favoring authored member source is cumulative: a normal prologue/epilogue, seven meaningful parameters, direct stateful logic rather than forwarding, adjacent member helpers with the same raw `retn 0x1c` shape, a matching class declaration, and source-order placement between modeled cdecl callbacks. Zero inbound routes explain why the function was not modeled and likely not called in the shipped build; they do not make the 189-byte algorithm compiler-generated.

The source-facing names are descriptive reconstruction names, but no behavioral issue remains hidden behind lexical uncertainty. `scratch` remains the least-committal name for a 32-bit field whose only target/sibling action is reset to zero. Searches across generated source, support docs, and matching reports found no read, address-take, or stronger semantic name; this is an exhausted lexical route, not deferred investigation.

## Heuristic / Inference Reanalysis And Validation

| Candidate | Positive evidence | Negative evidence | Rank/disposition |
| --- | --- | --- | --- |
| `TextEditPane::MeasureTextRunSegment` private member | ECX is TextEditPane; seven stack args; `retn 0x1c`; full measurement body; adjacent raw members use same pattern; existing class declaration/source order | zero inbound routes; original symbol absent | 1, accepted |
| cdecl `TextRunMeasureCallback` thunk | near-identical sibling body immediately before target | target does not forward; ABI is member plus seven args, not cdecl eight args; no address-taking route | 2, rejected |
| compiler-generated callback adapter | no direct callers and close clone of sibling | 189-byte stateful algorithm is source-shaped, not adjustment/forwarding glue | 3, rejected |
| `GrafPort` member owner for target | inherited width methods and helper dependency | target reads TextEditPane-only `m_maskedText` at `+0x16a` and TextEditPane records/state | 4, rejected as target owner |
| TextEditPane file-local free helper | source unit fits | ECX receiver and `retn 0x1c` prove member ABI | 5, rejected |
| FittingRoom owner/table | stale historical generated slice overlaps this area | exact bytes are executable TextEditPane measurement logic and the stale slice cuts two bodies | rejected |

For `0x004baad0`:

| Candidate | Evidence | Disposition |
| --- | --- | --- |
| `GrafPort::AdjustVisibleCountForTrailingWhitespace` | contiguous GrafPort method corridor; all four callers load pane/GrafPort receiver into ECX; two stack args; `retn 8` | accepted |
| file-static `__stdcall` helper | body does not read ECX | rejected because every independent caller deliberately establishes the receiver and cross-TU static emission is invalid |
| TextEditPane member | all known callers are TextEditPane paths | weaker than GrafPort because the physical function is inside the GrafPort method cluster and works on no TextEditPane state |

## Evidence Standards Used

- Ranges are half-open in analysis and reconciled to inclusive documentation filenames.
- Physical bytes are anchored to the current NexusTK PE, not copied from historical prose.
- Raw code is classified with item boundaries plus bounded instruction queries because decompilation correctly fails without a function object.
- ABI claims require prologue/stack-slot use, return cleanup, and call-site receiver evidence.
- Public `stack_frame` rows are literal IDA frame output only. Before A04 the target exposes only the saved-register/return-address pair; after A04 it exposes that pair plus seven typed argument rows, but still no local rows. The omitted `[ebp-8]` and `[ebp-4]` slots remain disassembly-only evidence; bounded disassembly independently fixes the physical ABI while the post-type argument rows corroborate the applied signature.
- Route-negative claims require IDA xrefs/immediates and raw little-endian pointer-pattern controls.
- Source shape must compile across current CPP/H units and preserve access control.
- Generated output is read-only evidence and never an implementation destination.
- Scores stay below 95 because original lexical names/build flags are not final-audit proof.

## Evidence Checked

| Family | Exact material | Result |
| --- | --- | --- |
| Target docs | UID0003FC metadata, formal CPP/H, prose/history | pre-callback source body was incomplete; current implemented source is complete; owner/range remained right |
| Sibling docs | UID0001JQ, UID0001JR, raw `0x00593f00` member | behavioral and helper-call parity confirmed |
| Parent/owner docs | UID0000EO, UID0000ON, UID0000EN, UID00005V | member/file route retained; two source-access/linkage repairs found |
| Helper docs | UID00016C body, ABI, source placement | pre-callback static/stdcall classification rejected; corrected member route is current implemented |
| Generated source | final supervisor commands `000000026435`-`000000026444` and four physical CPP/H receipts in Section 4 | target final-helper route, cdecl pane-qualified calls, raw inherited calls, non-static GrafPort member definition/declaration, TextEditPane friendship, and singular support-class definitions are present |
| Manual coverage | by-memory and by-class rows plus commands `000000026445`/`000000026446` | exact UID00016C/UID0001JQ/UID0003FC/UID0001JR/UID00005V/UID0000EN rows are applied, physically present, and validator-accepted |
| IDA range/items | dated PRE/POST plus final canonical verifier | historical raw/no-function prestate is superseded by exact target function/name/type/comments; bytes and boundaries remain unchanged |
| IDA references | xrefs, immediate search, byte-pattern search | target zero; sibling positive controls exact |
| IDA types | TextEditPane, TextEditLineRecord, TextRunFormatData, state/typedef searches | known layouts confirmed; historical absence of `TextRunMeasureState` is superseded by the exact final 12-byte UDT |
| Helper call sites | `0x593c72`, `0x593d38`, `0x593ed4`, `0x594019` | all establish receiver in ECX |
| Historical reports | matching UID/address/name/family reports | UID0000OJ lead corrected where current raw facts disagree |
| Historical isolated Gate 2B transactions | sessions `supervisor_uid0003fc_gate2b_20260822_0649` and `supervisor_uid0003fc_gate2b_retry_20260822_0703` | first session established the exact pre-type two-row target frame and stopped at former POST-05; retry matched that pre-type result, completed A01-A10 only in disposable state, and established the post-A04 two-metadata-plus-seven-typed-argument target frame with no locals; neither session saved or promoted, and canonical length/hash plus all canonical entities remained unchanged |
| Final canonical Gate 2B | transaction `UID0003FC-20260822-071358557`; verifier `supervisor_uid0003fc_verify_20260822_0718` | `APPLIED_VERIFIED_SAVED`; exact entities/comments/types/frames/routes/callees/protections reproduced from final canonical length `143211145`, SHA256 `F5941D0C032A4022F5C59633EA4BFE740ADCD508CE726619E9C5219C3D567DD2` |

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C0003FC-001 | 0003FC | Keep UID0003FC at exact half-open range [0x00593cf0,0x00593dad). | very high | 72 bounded instruction heads terminate at `retn 0x1c`; exact CC fences begin outside the interval. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / address metadata and Item Summary | incorporate | applied |
| C0003FC-002 | 0003FC | Record the target as 189 bytes with SHA256 7D11CC7DD7E195A284EAFFDF7DEAACADF05A891E81844EAD0154A04A1D1E1009. | very high | Independent physical PE slice receipt over the exact 189-byte interval. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / Item Summary and Evidence | incorporate | applied |
| C0003FC-003 | 0003FC | Preserve eleven CC bytes at [0x00593ce5,0x00593cf0) and three CC bytes at [0x00593dad,0x00593db0). | very high | Live item boundaries and separate pre-pad/post-pad PE hashes. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / Range and Boundary Evidence | incorporate | applied |
| C0003FC-004 | 0003FC | Record the dated pre-Gate2B IDA baseline at 0x00593cf0 as code with no function, name, type, or comments, explicitly superseded by final canonical state. | very high | Historical PRE-02 through PRE-05 establish the baseline; final verifier session `supervisor_uid0003fc_verify_20260822_0718` proves the exact accepted function/name/type/comments now persist canonically. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / IDA Status; supervisor Gate 2B PRE-02 through PRE-05 and final canonical receipt | incorporate | applied |
| C0003FC-005 | 0003FC | Classify the raw ABI as bool __thiscall with TextEditPane in ECX, seven stack arguments, and retn 0x1c. | very high | Complete bounded disassembly independently maps the ECX receiver, `[ebp+8]` through `[ebp+0x20]`, and callee cleanup; exact post-A04 `stack_frame` argument rows corroborate the seven typed arguments but expose no locals. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / ABI and Item Summary; `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| C0003FC-006 | 0003FC | Name the seven source parameters line, format, text, textOffset, charCount, segmentFlags, and state. | high | Disassembly stack-slot use, sibling callback parity, UDT member accesses, and the exact post-A04 typed argument readback support the names/types; the pre-type two-row result is not argument evidence. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / ABI; `RECONSTRUCTION_CPP CODE` signature | incorporate | applied |
| C0003FC-007 | 0003FC | Preserve bit 0 as has-next-segment, bit 1 as has-previous-segment, reset for flags <= 1, and finalization when bit 0 is clear. | very high | Exact flag tests at `0x00593cf6`, `0x00593d2e`, and `0x00593d84` plus cdecl sibling parity. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / Behavior and `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| C0003FC-008 | 0003FC | Preserve TextRunMeasureState as 12 bytes with availableWidth +0, remainingWidth +4, and reset-only scratch +8. | high | Target and cdecl sibling accesses cover only three dwords; historical PRE-05 confirmed absence, and final POST-01/POST-13 plus canonical verifier confirm the exact 12-byte UDT is applied. | `by-class/TextEditPane.md` [UID:0000EO] / state declaration in `RECONSTRUCTION_H CODE`; target Behavior | incorporate | applied |
| C0003FC-009 | 0003FC | Preserve TextRunFormatData::object +8 and embedded-object advance from TextEditObject::m_payload1 +0x10. | very high | Live UDT offsets and object-branch instructions at `0x00593d15-0x00593d25`. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / Behavior and `RECONSTRUCTION_CPP CODE`; `by-class/TextEditObject.md` [UID:0000EN] / access prose | incorporate | applied |
| C0003FC-010 | 0003FC | Invoke the visible-count helper only for final non-object segments before plain or masked measurement. | very high | Exact branch and call at `0x00593d27-0x00593d48`; the pre-callback formal body omitted it; the implemented target now contains the call. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| C0003FC-011 | 0003FC | Reclassify 0x004baad0 as the receiver-independent GrafPort member AdjustVisibleCountForTrailingWhitespace. | very high | All four callers load a TextEditPane/GrafPort receiver into ECX; helper uses two stack arguments and `retn 8`. | `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md` [UID:00016C] / Item Summary and `RECONSTRUCTION_CPP CODE`; `by-class/GrafPort.md` [UID:00005V] / method inventory | incorporate | applied |
| C0003FC-012 | 0003FC | Type 0x004baad0 as unsigned short __thiscall GrafPort member over const wchar_t * and signed short count, preserving its observed terminal comparison. | very high | Signed word load, low-word returns, caller `movzx eax, ax`, four receiver calls, and full helper body. | `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md` [UID:00016C] / `RECONSTRUCTION_CPP CODE`; `by-class/GrafPort.md` [UID:00005V] / `RECONSTRUCTION_H CODE`; Gate 2B A08 | incorporate | applied |
| C0003FC-013 | 0003FC | Preserve masked measurement as visibleCount times GetTextWidth(L"*", 1). | very high | Mask byte `TextEditPane+0x16a`, wildcard literal xref, width call, sign extension, and multiply. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / Behavior and `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| C0003FC-014 | 0003FC | Preserve plain measurement as GetTextWidth(text, visibleCount). | very high | Direct plain branch at `0x00593d6e-0x00593d77` with typed GrafPort callee. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / Behavior and `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| C0003FC-015 | 0003FC | Subtract run width, clamp negative remaining width to zero only on final segments, store line +8, and clear line word +0x0c. | very high | Exact update sequence `0x00593d7a-0x00593d9e` and live `TextEditLineRecord` offsets. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / Item Summary, Behavior, and `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| C0003FC-016 | 0003FC | Preserve unused textOffset and unconditional false return. | very high | No instruction reads `[ebp+0x14]`; epilogue is `xor al, al` then `retn 0x1c`. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / ABI and `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| C0003FC-017 | 0003FC | Record zero direct start xrefs, zero immediate hits, and zero little-endian VA pointer-pattern hits for 0x00593cf0. | very high | Bounded live xref/immediate checks and physical `F0 3C 59 00` search; sibling positive controls succeed. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / Direct Xrefs and Reachability | incorporate | applied |
| C0003FC-018 | 0003FC | Classify the body as a source-authored compiler-retained private member, not a callback thunk or compiler helper. | high | Full authored algorithm, class receiver/fields, member cleanup, zero forwarding, and neighboring raw members. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / Item Summary and Identity | incorporate | applied |
| C0003FC-019 | 0003FC | Use source-facing name TextEditPane::MeasureTextRunSegment with the exact seven-argument member signature. | high | Existing class declaration, physical source order, exact ABI, and sibling naming convention. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / `RECONSTRUCTION_CPP CODE`; `by-class/TextEditPane.md` [UID:0000EO] / private method declaration in `RECONSTRUCTION_H CODE`; Gate 2B A03-A04 | incorporate | applied |
| C0003FC-020 | 0003FC | Preserve direct class owner/emitter UID0000EO and source file UID0000ON at NexusTK/ui/controls/TextEditPane.cpp. | very high | TextEditPane field access, neighboring unit order, class declaration, and generated emitter route. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / parent metadata; `by-class/TextEditPane.md` [UID:0000EO] / ownership; `by-file/TextEditPane.md` [UID:0000ON] / source placement | already-present | applied |
| C0003FC-021 | 0003FC | Preserve UID0001JQ as the separate cdecl iterator callback with four address-taking routes. | very high | Modeled `[0x00593c20,0x00593ce5)` function and four positive immediate/pointer controls. | `by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md` [UID:0001JQ] / ABI, Xrefs, and Item Summary | already-present | applied |
| C0003FC-022 | 0003FC | Change UID0001JQ's helper call to pane->AdjustVisibleCountForTrailingWhitespace without changing its ABI or other behavior. | very high | Call at `0x00593c72` establishes pane in ECX and passes the same two stack arguments. | `by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md` [UID:0001JQ] / `RECONSTRUCTION_CPP CODE` and helper-route prose | incorporate | applied |
| C0003FC-023 | 0003FC | Change UID0001JR's helper call to pane->AdjustVisibleCountForTrailingWhitespace without changing its ABI or other behavior. | very high | Calls at `0x00593ed4` and `0x00594019` establish pane in ECX; draw ABI/body remain independent. | `by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md` [UID:0001JR] / `RECONSTRUCTION_CPP CODE` and helper-route prose | incorporate | applied |
| C0003FC-024 | 0003FC | Preserve raw DrawTextRunSegment at [0x00593f00,0x0059403b) as corroborating member-ABI evidence, not an additional target. | high | Raw sibling has member receiver shape and helper route but is separately documented and not declared as coverage. | `by-memory/0x00593f00-0x0059403b.DrawTextRunCallbackThiscallRaw.md` [UID:0003FD] / `Status`, `Function`, `IDA Evidence`, `Ownership Decision`, `Reconstruction Notes`, and `Cross-References` support-evidence prose; this report / `Target` declaration | incorporate | applied |
| C0003FC-025 | 0003FC | Emit the corrected GrafPort member definition in UID00016C and its declaration once in UID00005V H. | very high | Helper lies in GrafPort method corridor and the pre-callback generated static source was cross-unit inaccessible; command `000000026355` now emits the member route. | `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md` [UID:00016C] / `RECONSTRUCTION_CPP CODE`; `by-class/GrafPort.md` [UID:00005V] / `RECONSTRUCTION_H CODE` | incorporate | applied |
| C0003FC-026 | 0003FC | Add friend class TextEditPane to UID0000EN so raw TextEditPane members legally access protected TextEditObject payload fields. | high | Formal target and raw member siblings read protected payload dwords; public-field weakening is unnecessary. | `by-class/TextEditObject.md` [UID:0000EN] / `RECONSTRUCTION_H CODE` friendship and access prose | incorporate | applied |
| C0003FC-027 | 0003FC | Replace UID0003FC formal CPP with the complete source block in Section 22. | very high | Formal block mirrors all 72 instructions and restores the missing final-segment helper call. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| C0003FC-028 | 0003FC | Keep UID0003FC formal H blank because UID0000EO already owns the one class declaration. | very high | Existing `TextEditPane` private declaration is canonical; a child H block would duplicate it. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / blank `RECONSTRUCTION_H CODE`; `by-class/TextEditPane.md` [UID:0000EO] / canonical declaration | already-present | applied |
| C0003FC-029 | 0003FC | Retain scratch as the conservative descriptive +8 field name after exhaustive zero-only-use review. | high | Target and cdecl sibling only zero the field; generated/report searches reveal no stronger use. | `by-class/TextEditPane.md` [UID:0000EO] / `TextRunMeasureState` declaration and type prose | already-present | applied |
| C0003FC-030 | 0003FC | Define one IDA function exactly at [0x00593cf0,0x00593dad) only after byte/item/boundary preconditions pass. | very high | Final transaction `UID0003FC-20260822-071358557` passed exact PRE boundaries, A02, POST-02 through POST-05, and canonical verifier readback of the one `0xbd` function with both CC fences excluded. | Supervisor Gate 2B / Section 21 A02 and POST-02 through POST-05; final `APPLIED_VERIFIED_SAVED` receipt | incorporate | applied |
| C0003FC-031 | 0003FC | Rename, type, and comment the defined target exactly as specified in Section 21. | very high | Final canonical verifier read back exact A03-A06 name/signature/comments, POST-07/POST-08 type/prototype, and POST-09 metadata-plus-seven-typed-argument frame with no local rows. | Supervisor Gate 2B / Section 21 A03-A06 and POST-06 through POST-12; final `APPLIED_VERIFIED_SAVED` receipt | incorporate | applied |
| C0003FC-032 | 0003FC | Rename, retype, and comment 0x004baad0 as the GrafPort member specified in Section 21. | very high | Final canonical verifier read back exact A07-A10 helper name/signature/comments, four-row frame, four callers, size `0x42`, and no helper callees. | Supervisor Gate 2B / Section 21 A07-A10 and POST-06 through POST-12; final `APPLIED_VERIFIED_SAVED` receipt | incorporate | applied |
| C0003FC-033 | 0003FC | Preserve target bytes, padding, xrefs, sibling entities, local labels, public frame metadata, disassembly-proven ABI, and all unrelated IDA state. | very high | Final transaction and independent canonical verifier passed P01-P06, unchanged bytes/hashes/ranges/routes, exact post-type frames/types/comments/UDT/callees, and final physical canonical receipt `143211145` / `F5941D0C032A4022F5C59633EA4BFE740ADCD508CE726619E9C5219C3D567DD2`. | Supervisor Gate 2B / Section 21 P01-P06 and final transaction/verifier/rollback/persistence receipts | incorporate | applied |
| C0003FC-034 | 0003FC | Replace stale target summary/history with the exact range, ABI, source identity, helper route, fields, and behavior. | very high | The pre-callback page omitted the final helper and overstated callback identity; the implemented page closes both from live evidence. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / Item Summary, General Documentation, and dated Change History | historicalize | applied |
| C0003FC-035 | 0003FC | Reconcile UID0001JQ, UID0001JR, UID00016C, UID00005V, UID0000EN, UID0000EO, and UID0000ON support prose. | high | The accepted pre-callback formal/generated comparison identified exact linkage, access, declaration, ownership, and ordering dependencies; current docs and generated output implement them. | `by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md` [UID:0001JQ] / `Callback ABI And State Layout`, `Evidence Notes`, `Reconstruction Notes`, `Ownership Notes`, `Cross-References`, and `Changes`; `by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md` [UID:0001JR] / `Evidence Notes`, `Callback ABI, State, And Source Shape`, `First-Draft C++ Behavior Notes`, `Reconstruction Notes`, `Cross-References`, and `Changes`; `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md` [UID:00016C] / `Covered Functions`, `Evidence Notes`, `Ownership Notes`, `Reconstruction Notes`, `Cross-References`, and `Changes`; `by-class/GrafPort.md` [UID:00005V] / `Class Purpose`, `Method Notes`, `Evidence Notes`, `Cross-References`, and `Changes`; `by-class/TextEditObject.md` [UID:0000EN] / `Class Purpose`, `Observed State`, `Method Families`, `Evidence Notes`, `Cross-References`, and `Changes`; `by-class/TextEditPane.md` [UID:0000EO] / `Source Placement And Rejected Owners`, `C++ Declaration Policy`, `Method Families`, `Raw Callback And Support Boundaries`, `Evidence Notes`, `Current Caveats`, and `Changes`; `by-file/TextEditPane.md` [UID:0000ON] / `File Role`, `Proposed Contents`, `Source Emission Policy`, `Ownership Decision`, `Evidence Notes`, `Current Caveats`, and `Changes` | incorporate | applied |
| C0003FC-036 | 0003FC | Preserve the refreshed single-emitter support-class H routing: canonical UID0000EN, UID0000EP, and UID00004H definitions each emit once, with no UID0000EO aggregate-removal edit. | high | Command `000000026355` TextEditPane H has exactly one TextEditObject definition at line 171, one TextEditScrap definition at line 212, and one EPFTextEditObject definition at line 560; the earlier duplicate conclusion remains superseded. | `by-class/TextEditPane.md` [UID:0000EO] / aggregate `RECONSTRUCTION_H CODE` no-change; canonical child H channels `by-class/TextEditObject.md` [UID:0000EN], `by-class/TextEditScrap.md` [UID:0000EP], and `by-class/EPFTextEditObject.md` [UID:00004H] | already-present | applied |
| C0003FC-037 | 0003FC | Independently regenerate or adopt a fresh coherent refresh and physically reread TextEditPane CPP/H and GrafPort CPP/H during supervisor verification. | very high | Supervisor scoped commands `000000026435`-`000000026443` and owner refresh `000000026444` passed; physical command-26443/26444 CPP/H reread reproduced the target/helper/member/declaration/friendship/single-definition topology and exact hashes in Current Target State. | Validator-owned `auto-generated/NexusTK/ui/controls/TextEditPane.cpp`, `auto-generated/NexusTK/ui/controls/TextEditPane.h`, `auto-generated/NexusTK/render/GrafPort.cpp`, and `auto-generated/NexusTK/render/GrafPort.h` / final supervisor physical refresh and semantic readback | incorporate | applied |
| C0003FC-038 | 0003FC | Raise UID0003FC to 92/93, UID00016C to 90/93, UID00005V to 89/92, UID0001JQ to 91/94, and UID0001JR to 92/94; keep 94/94 parents unchanged. | high | Exact range/ABI/behavior/source closure and bounded residual lexical/compiler uncertainty; broader parents retain their independent caps. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC], `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md` [UID:00016C], `by-class/GrafPort.md` [UID:00005V], `by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md` [UID:0001JQ], and `by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md` [UID:0001JR] / `COMPLETION`, `CONFIDENCE`, `RECONSTRUCTABLE`, and `Score Rationale`; explicitly preserve `by-class/TextEditObject.md` [UID:0000EN], `by-class/TextEditPane.md` [UID:0000EO], and `by-file/TextEditPane.md` [UID:0000ON] at unchanged 94/94 with their reconstructable metadata and score rationale unchanged | incorporate | applied |
| C0003FC-039 | 0003FC | Apply the exact supervisor-owned manual coverage insert/replacements from Section 28 only after ordinary validation. | very high | Supervisor applied all six literal rows in the required positions; commands `000000026445` and `000000026446` passed, and read-only reconciliation confirms the exact rows remain physically present. | `by-memory/-coverage-report.md` / UID00016C, UID0001JQ, UID0003FC, UID0001JR rows; `by-class/-coverage-report.md` / UID00005V and UID0000EN rows | incorporate | applied |
| C0003FC-040 | 0003FC | Create no split, merge, new UID, new source file, or alternate owner for this report. | very high | Exact fences, stable primary UID, class/file owner route, and separately documented siblings close every split/ownership alternative. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / identity, parent metadata, and source placement | not-applicable | applied |
| C0003FC-041 | 0003FC | Keep execution/archive state external to ordinary report prose and determined only from this report's current physical path plus validator-owned history; require exact moved-artifact audit and keep the inert companion beside the report through every movement. | very high | Gate 2A, generated verification, coverage, and canonical Gate 2B have exact historical receipts; lifecycle state remains path-and-validator-history authoritative, and report/companion adjacency must be verified rather than inferred. | This report / current physical path plus validator-owned history; paired inert companion / physical adjacency and relative-link verification after movement | incorporate | proposed |

## Positive Evidence Summary

- The PE slice `[0x00593cf0,0x00593dad)` is a unique 189-byte code body with conventional prologue and `retn 0x1c`.
- `ECX` is copied to the pane register and used at TextEditPane-only `m_maskedText +0x16a`.
- Seven stack slots have stable source roles; `textOffset` is the only unused argument.
- The body mirrors the cdecl measurement callback branch for branch, including the helper call omitted by pre-callback source and present in current implemented source.
- The object branch reads payload dwords at `+0x0c/+0x10` and consumes the second as width.
- The plain and masked paths call the typed GrafPort width method.
- State reset/subtract/final clamp/writeback and false return are exact.
- Immediate and raw-pointer searches return zero for the raw member while positive controls recover four cdecl measurement and two cdecl draw routes.
- All four calls to `0x004baad0` establish the pane/GrafPort receiver in ECX.
- The class H already contains the exact member declaration in the expected private method corridor.

## IDA MCP Facts

| Subject | Historical pre-Gate2B baseline | Final applied canonical verifier receipt |
| --- | --- | --- |
| target start/bound | `lookup_funcs(0x00593cf0)`: not a function | one function `[0x00593cf0,0x00593dad)`, size `0xbd`, named `TextEditPane__MeasureTextRunSegment` |
| target tail/pad | no function at `0x00593d00`, `0x00593daa`, or `0x00593dad` | `0x00593d00` and `0x00593daa` resolve inside the exact target function; `0x00593dad` remains outside it as three-byte CC padding |
| target item/type | `0x00593cf0-0x00593cf1`, code, blank name/type | code in the exact target function with full accepted A04 `bool __thiscall` signature |
| target comments | address regular/repeatable blank; no function comment channels | function regular/repeatable exactly equal A05/A06; address regular/repeatable remain blank |
| target modeling | expected `Decompilation failed at 0x593cf0` because no function existed | historical failure superseded by exact function/name/type/comment verifier readback |
| target instructions | 72 complete instruction heads over the exact half-open range | same 72-instruction body and bytes; no target/pad byte drift |
| modeled predecessor | `callback`, `[0x00593c20,0x00593ce5)`, size `0xc5` | unchanged and protected |
| modeled successor | `sub_593DB0`, `[0x00593db0,0x00593ef6)`, size `0x146` | unchanged and protected |
| width callee | `GrafPort__GetTextWidth`, `short __thiscall(GrafPort *, const wchar_t *, int)` | unchanged; one of exactly two unique target callees |
| helper callee | `sub_4BAAD0`, size `0x42`, stale `int __stdcall(unsigned int, __int16)` type | `GrafPort__AdjustVisibleCountForTrailingWhitespace`, size `0x42`, exact accepted A08 `unsigned __int16 __thiscall` signature and A09/A10 comments |
| helper xrefs/callees | exactly `0x593c72`, `0x593d38`, `0x593ed4`, `0x594019` | same exact four callers; helper has no direct callees |
| target xrefs/callees | zero inbound routes | zero inbound routes; exact callees are helper and `GrafPort__GetTextWidth` |
| target frame | no function/frame before A02; pair-only immediately after A02 and before A04 | exact metadata pair plus seven typed arguments at 0x1c-0x34; no local rows |
| helper frame | metadata rows plus untyped `arg_0`/`arg_4` | exact four rows: metadata pair, `text` 0xc/0x4 `const wchar_t *`, `count` 0x10/0x2 `__int16` |
| TextEditPane type | size `0x174`; `m_maskedText` exactly `+0x16a` | unchanged and protected |
| TextRunFormatData | size `0x0c`; object pointer exactly `+0x08` | unchanged and protected |
| TextEditLineRecord | size `0x10`; remainingWidth `+0x08`, wrapState word `+0x0c` | unchanged and protected |
| TextRunMeasureState | absent from the historical local type library | exact size `0x0c`: `availableWidth` +0, `remainingWidth` +4, `scratch` +8, all four-byte `int` |
| TextRunIteratorCallback | absent from the historical local type library | not targeted by the accepted transaction; no claim depends on adding it |
| canonical physical state | length `143211069`, SHA256 `39754A1765590C4814C6716E645A0DFF974C8B4C83D1761980D11DE6D80D8B11` | `E:/NTK/Resources/NexusTK/NexusTK.exe.i64`, exclusive-read length `143211145`, SHA256 `F5941D0C032A4022F5C59633EA4BFE740ADCD508CE726619E9C5219C3D567DD2`, `APPLIED_VERIFIED_SAVED` |

Physical PE receipts:

Target first 16 bytes are `55 8B EC 83 EC 08 66 83 7D 1C 01 53 0F B7 5D 1C`; target last 16 bytes are `C9 66 89 48 0C 5F 5E 32 C0 5B 8B E5 5D C2 1C 00`.

| Range | Bytes | SHA256 |
| --- | ---: | --- |
| cdecl measurement `[0x00593c20,0x00593ce5)` | 197 | `EA9DDB4882084316C0B16EE1284CA9676DA1CD984FCDE728006ADC8E224A5786` |
| predecessor pad `[0x00593ce5,0x00593cf0)` | 11 | `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943` |
| target `[0x00593cf0,0x00593dad)` | 189 | `7D11CC7DD7E195A284EAFFDF7DEAACADF05A891E81844EAD0154A04A1D1E1009` |
| successor pad `[0x00593dad,0x00593db0)` | 3 | `E668F0A1B72560CED14C54488A25335D11336448950BB6485267EBC5EB3FECEE` |
| cdecl draw `[0x00593db0,0x00593ef6)` | 326 | `FB9A897242AB95C3F2AC2754140D5CEA73F1CEA80FB1E7F69A59BA29BA2A9743` |

## Function / Child Inventory

| Order | Range | IDA state | Source disposition |
| --- | --- | --- | --- |
| 1 | `[0x00593c20,0x00593ce5)` | modeled `callback`, size `0xc5` | separate file-local cdecl `TextRunMeasureCallback` |
| 2 | `[0x00593ce5,0x00593cf0)` | one data item, eleven CC bytes | alignment, no source entity |
| 3 | `[0x00593cf0,0x00593dad)` | historical baseline: 72 raw code instructions/no function; final canonical: exact `0xbd` function `TextEditPane__MeasureTextRunSegment` | UID0003FC private member `MeasureTextRunSegment` |
| 4 | `[0x00593dad,0x00593db0)` | one data item, three CC bytes | alignment, no source entity |
| 5 | `[0x00593db0,0x00593ef6)` | modeled `sub_593DB0`, size `0x146` | separate file-local cdecl `DrawTextRunCallback` |
| 6 | `[0x00593f00,0x0059403b)` | raw code, no function | separate private member `DrawTextRunSegment`; support evidence only |

Target flow:

| Phase | Instructions/fields | Meaning |
| --- | --- | --- |
| prologue/ABI | `push ebp`, frame, 8 local bytes; final `retn 1Ch` | member receiver plus seven stack args |
| initial state | flags word at `+0x1c`; state at `+0x20`; this in ECX | exact signature |
| reset | state `+4 = +0`, state `+8 = 0` when flags `<=1` | first/only segment |
| object | format `+8`, object `+0x0c/+0x10`; width from `+0x10` | embedded advance |
| final text adjustment | call `0x004baad0` at `0x00593d38` when bit 0 clear | preserve helper call and return narrowing |
| masked | `this+0x16a`, `L"*"` at `0x0062e168`, width call, multiply | repeated mask glyph |
| plain | width call over text and visible count | normal UTF-16 run |
| update | state `+4 -= width`; final clamp; line `+8`; line word `+0x0c=0` | measurement result |
| return | `xor al, al` | always false |

## Direct Xref / Caller Inventory

The target start has zero inbound code or data xrefs. `find(type=immediate, 0x00593cf0)` returned zero. Raw little-endian pattern `F0 3C 59 00` returned zero. These are complete bounded results.

Positive controls from the same calls:

| Identity | Immediate hits | Raw pointer bytes | Meaning |
| --- | --- | --- | --- |
| cdecl measure `0x00593c20` | `0x0058df01`, `0x0058fb6c`, `0x0059146b`, `0x00592eec` | bytes at each immediate +1 | four address-taking iterator routes |
| cdecl draw `0x00593db0` | `0x005908e6`, `0x0059168c` | bytes at each immediate +1 | two address-taking iterator routes |
| raw target `0x00593cf0` | none | none | not selected by shipped iterator paths |

No direct-call inventory exists for the target. Its runtime reachability is absent in the current binary. The probable source explanation is an out-of-line private member retained by the compiler after the iterator switched to file-local cdecl callbacks; this is stronger than calling it a thunk because the body performs the entire algorithm.

Target callees are exactly one `0x004baad0` helper call and two `GrafPort::GetTextWidth` call instructions. `L"*"` has five total references in the TextEditPane run-measure/draw corridor, including target `0x00593d56`.

## Documentation Evidence And IDA Status

The target page's exact-boundary/no-start-xref evidence remains valid. Historical text saying final C++ was blank is superseded. The UID0000OJ incorporation supplied a useful member name and source route but summarized the text branch too coarsely and emitted an incomplete body.

Pre-callback UID0001JQ was behaviorally complete but used free-helper syntax that contradicted the call ABI; pre-callback UID0001JR had the same source-linkage issue. Pre-callback UID00016C correctly inventoried seven GrafPort text functions but placed the helper first, declared it static/stdcall, and described unresolved cross-file visibility. Current implemented UID0001JQ/UID0001JR use the pane member route, current implemented UID00016C/UID00005V emit the non-static member in source order, and the live call sites independently support that corrected member classification.

The dated pre-Gate2B IDA baseline did not model the target function or state type. That historical modeling gap was not evidence against source. Final canonical verifier session `supervisor_uid0003fc_verify_20260822_0718` now confirms the exact target function, accepted name/type/comments, and exact 12-byte state UDT; the boundary remains safe because the full interval is decoded code and both CC padding fences remain excluded.

The current generated files are mutable corroboration only. The `2026-08-22T09:19:44Z` full-file reread confirms the target member and final helper route at TextEditPane CPP lines 2622-2650, cdecl pane-qualified helper calls at lines 2600 and 2725, raw inherited helper calls at lines 2643 and 2761, the non-static GrafPort member at line 886, and its single H declaration at line 85. TextEditPane H contains one class friendship at line 188 and single support definitions at lines 171, 212, and 560. The earlier omission/static-linkage/missing-declaration/missing-friendship snapshot and duplicate-routing conclusion are superseded.

## Ranked Ownership Analysis

| Rank | Owner | Decision |
| ---: | --- | --- |
| 1 | UID0000EO TextEditPane class | accepted direct owner and emitter |
| 2 | UID0000ON TextEditPane file | accepted source module, not direct member owner |
| 3 | UID00005V GrafPort class | dependency owner for width/helper methods only |
| 4 | UID0001JQ callback | behavioral sibling, never owner |
| 5 | no-owner/compiler helper | rejected; body is authored member logic |
| 6 | FittingRoom | rejected stale overlap |

The owner remains class-direct because source identity is a class member. The file remains the compilation unit because all surrounding run iteration and support-object code routes there. No child/parent gate or new identity is required.

## Source Placement

Emit target CPP once through UID0000EO into `NexusTK/ui/controls/TextEditPane.cpp`, immediately after the cdecl measurement callback and before the cdecl drawing callback. Keep the declaration once in UID0000EO's `TextEditPane` private method list. UID0003FC H remains blank to avoid a second declaration.

Emit the corrected helper as `GrafPort::AdjustVisibleCountForTrailingWhitespace` through UID00016C/UID00005V in `NexusTK/render/GrafPort.cpp`, in physical method order after `GetLineHeight` and before `DrawGlyphWithTextColors`. Declare it once in GrafPort H beside the text-width/line-height methods. TextEditPane inherits the declaration through ScrollBar -> Pane -> GrafPort include/derivation routing.

Keep TextEditObject in `TextEditPane.h`, owned by UID0000EN and emitted through UID0000EO. Add `friend class TextEditPane`; do not make payload fields public and do not invent raw offset access. Preserve the current single-emitter support-class route: the refreshed TextEditPane H already emits the UID0000EN, UID0000EP, and UID00004H definitions exactly once, so no UID0000EO aggregate-removal edit is authorized.

## Range / Split / Padding / Reclassification Analysis

No split or merge is warranted. The exact target interval begins at a normal prologue immediately after eleven CC bytes and ends after `retn 0x1c` immediately before three CC bytes. `0x00593dad` is the first padding byte and therefore the exclusive end, despite the existing filename's inclusive-looking last component. The page should explicitly state both conventions.

Do not expand into predecessor callback padding, successor padding, or the modeled draw callback. Do not reuse the stale `0x00593d00-0x00593e6b` slice; it starts inside the target and ends inside the draw callback.

Reclassification is semantic only: stable page title `TextRunMeasureCallbackThiscallRaw` remains for lookup, while entity kind becomes `compiler-retained private member helper`. Reclassification does not create a new UID or move bytes.

## Negative Evidence Summary

- The dated pre-Gate2B baseline had no target start function, name, type, or comment; those negatives are superseded by the final applied canonical entity. Zero target inbound xrefs, immediate hits, and raw VA pointer hits remain current and verifier-confirmed.
- No vtable entry or callback table points to the target.
- No call forwards from the target to the cdecl callback; it implements the algorithm directly.
- No instruction reads FittingRoom state.
- No helper call omits the receiver: all four `0x004baad0` call sites set ECX.
- The historical baseline defined neither `TextRunMeasureState` nor `TextRunIteratorCallback`; final canonical now defines the exact 12-byte `TextRunMeasureState`, while no report claim requires adding `TextRunIteratorCallback`.
- No evidence supports changing `TextRunMeasureState::scratch` to a stronger semantic name.
- No target-specific H fragment is needed because the class declaration already exists once.
- No new file, class, split, additional target, or duplicate helper is justified.

## IDA Rename / Type / Comment Recommendations

These rows are retained as the exact historical supervisor Gate 2B entity-action/readback contract. B003 performed no mutation, cache invalidation, save, process handling, persistence, or rollback. The dated read-only research session `2e5d96cf` was evidence only; the separate final supervisor transaction `UID0003FC-20260822-071358557` applied the contract and verifier `supervisor_uid0003fc_verify_20260822_0718` reproduced it from canonical state. Final disposition is `APPLIED_VERIFIED_SAVED`.

Public-tool semantic boundary: `stack_frame` is used below only for rows it literally exposes. For this target immediately after A02 and before A04, that is exactly the saved-register and return-address metadata pair, with no local or argument rows. After A04 it is exactly that pair plus seven typed argument rows: `line` 0x1c/0x4 `TextEditLineRecord *`, `format` 0x20/0x4 `const TextRunFormatData *`, `text` 0x24/0x4 `const wchar_t *`, `textOffset` 0x28/0x4 `int`, `charCount` 0x2c/0x2 `unsigned __int16`, `segmentFlags` 0x30/0x2 `unsigned __int16`, and `state` 0x34/0x4 `TextRunMeasureState *`; no local rows are exposed. The physical EBP frame, reserved slots `[ebp-8]` and `[ebp-4]`, ECX receiver, seven arguments at `[ebp+8,+0xc,+0x10,+0x14,+0x18,+0x1c,+0x20]`, and `retn 0x1c` remain independently fixed by bounded disassembly. Persisted function-type authority is the combined POST-07 target `inspect_items.name/type`, POST-08 exact `func_profile.prototype`, and POST-09 typed argument readback; the two local slots remain disassembly-only evidence.

### Literal public MCP request plan

During execution of the accepted contract, `DB` below was a role-local placeholder for the transaction's nonempty session ID; it was never a literal or reusable ID. AT01's external path placeholder was likewise replaced only from that transaction binding. The retained table prescribes no filesystem, worker/process, save, verifier, promotion, rollback, or cleanup program.

| Row | Literal accepted public MCP request | Exact prestate or expected readback | Deterministic stop condition |
| --- | --- | --- | --- |
| AT01 | `runtime_attestation({"expected_database":"DB","expected_canonical_path":"EXTERNAL_ROLE_PATH"})` | Fresh schema-1 top-level and worker success/error closure, listener/worker session/path/process/generation/source-root identity, and independent role-specific module baselines must match the supervisor's external binding; runtime attestation is runtime-only and grants no persistence authority. | Stop on unavailable or partial schema, stale evidence, any error, binding mismatch, module drift, or competing worker claim. |
| PRE-01 | `get_bytes({"database":"DB","regions":[{"addr":"0x00593ce5","size":11},{"addr":"0x00593cf0","size":189},{"addr":"0x00593dad","size":3},{"addr":"0x004baad0","size":66}]})` | Exact pre-pad, target, post-pad, and helper bytes; target SHA256 `7D11CC7DD7E195A284EAFFDF7DEAACADF05A891E81844EAD0154A04A1D1E1009`; pad hashes in Section 13; helper extent `[0x004baad0,0x004bab12)`. | Stop on any null/error, length, byte, hash, or range mismatch. |
| PRE-02 | `inspect_items({"database":"DB","addrs":["0x00593cf0","0x00593dad","0x004baad0"]})` | Target head `0x593cf0`, end `0x593cf1`, size 1, blank name/type, code; pad head `0x593dad`, end `0x593db0`, data; helper name `sub_4BAAD0`, type `int __stdcall(unsigned int, __int16)`. | Stop if any target/pad/helper item, name, type, width, or code/data class differs. |
| PRE-03 | `lookup_funcs({"database":"DB","queries":["0x00593cf0","0x00593dad","0x004baad0"]})` | No function contains target or post-pad start; helper resolves to `sub_4BAAD0`, size `0x42`. | Stop on a target overlap, changed helper bound/name, or ambiguous result. |
| PRE-04 | `get_comments({"database":"DB","addrs":["0x00593cf0","0x004baad0"]})` | Target address regular/repeatable are empty and has no function channels; helper address and function regular/repeatable channels are all empty. | Stop if any channel is nonempty or absent contrary to entity state. |
| PRE-05 | `type_query({"database":"DB","queries":{"filter":"^TextRunMeasureState$","kind":"udt","count":10,"include_decl":true,"include_members":true,"max_members":16}})` | Empty data and total 0. | Stop if the name exists; reconcile rather than overwrite any pre-existing type. |
| PRE-06 | `xref_query({"database":"DB","queries":{"addr":"0x00593cf0","direction":"to","xref_type":"any","offset":0,"count":32,"dedup":true,"include_fn":true}})` | Total 0 and empty data. | Stop if any inbound route appears. |
| PRE-07 | `xref_query({"database":"DB","queries":{"addr":"0x004baad0","direction":"to","xref_type":"code","offset":0,"count":16,"dedup":true,"include_fn":true}})` | Exactly four call sites: `0x00593c72`, `0x00593d38`, `0x00593ed4`, and `0x00594019`. | Stop on any missing, extra, duplicate, or differently typed route. |
| PRE-08 | `stack_frame({"database":"DB","addrs":["0x00593cf0","0x004baad0"]})` | Target returns `vars:null` and no-function error; helper rows are `__saved_registers` 0x4/0x4 `_DWORD`, `__return_address` 0x8/0x4 `_UNKNOWN *`, `arg_0` 0xc/0x4 `_DWORD`, `arg_4` 0x10/0x2 `_WORD`. | Stop if target already has a frame or any helper row/name/offset/size/type differs. |
| A01 | `declare_type({"database":"DB","decls":"struct TextRunMeasureState { int availableWidth; int remainingWidth; int scratch; };"})` | One successful declaration, no error. | Stop on parser error, collision, non-12-byte result, or any unexpected additional declaration. |
| POST-01 | `type_query({"database":"DB","queries":{"filter":"^TextRunMeasureState$","kind":"udt","count":10,"include_decl":true,"include_members":true,"max_members":16}})` | One UDT, size 12, members `availableWidth` +0 size 4 `int`, `remainingWidth` +4 size 4 `int`, `scratch` +8 size 4 `int`; exact declaration only. | Stop before A02 on any member/name/offset/size/type/declaration drift. |
| A02 | `define_func({"database":"DB","items":{"addr":"0x00593cf0","end":"0x00593dad"}})` | One result with start `0x00593cf0`, end `0x00593dad`, size/length `0xbd`, and no error. | Stop on inferred alternate bounds, overlap, partial definition, multiple results, or error. |
| POST-02 | `lookup_funcs({"database":"DB","queries":["0x00593cf0","0x00593daa","0x00593dad"]})` | First two queries resolve the one new function at `0x00593cf0`, size `0xbd`; `0x00593dad` resolves no function. | Stop if target does not cover its last instruction or absorbs padding. |
| POST-03 | `func_profile({"database":"DB","queries":{"addr":"0x00593cf0","count":1,"include_lists":false,"include_prototype":true}})` | One function at `0x00593cf0`, size `0xbd`; temporary auto-name/type is allowed only until A03/A04. | Stop on any alternate start/size or multiple target. |
| POST-04 | `inspect_items({"database":"DB","addrs":["0x00593cf0","0x00593daa","0x00593dad"]})` | Target addresses are code within one function; `0x00593dad-0x00593db0` remains the exact data pad. | Stop on byte/item destruction, pad absorption, or unexpected data conversion. |
| POST-05 | `stack_frame({"database":"DB","addrs":"0x00593cf0"})` | After A02 and before A03/A04, one successful target result with exactly two `vars` rows: `__saved_registers` offset `0x14`, size `0x4`, type `_DWORD`; `__return_address` offset `0x18`, size `0x4`, type `_UNKNOWN *`; no local or argument rows. This literal public-tool result is metadata-only and does not replace the disassembly-proven two local slots, ECX receiver, seven stack arguments, or `retn 0x1c`. | Stop before A03 on null/error, missing/duplicate/extra rows, any name/offset/size/type drift, or any claimed local/argument row; discard the transaction rather than infer a physical ABI from this tool. |
| A03 | `rename({"database":"DB","batch":{"func":{"addr":"0x00593cf0","name":"TextEditPane__MeasureTextRunSegment"},"pure":true,"allow_overwrite":false,"stop_on_error":true}})` | One successful function rename and no directory/decompiler side effect. | Stop on collision, overwrite request, partial batch, or any address other than target. |
| A04 | `set_type({"database":"DB","edits":{"addr":"0x00593cf0","kind":"function","signature":"bool __thiscall TextEditPane__MeasureTextRunSegment(TextEditPane *this, TextEditLineRecord *line, const TextRunFormatData *format, const wchar_t *text, int textOffset, unsigned __int16 charCount, unsigned __int16 segmentFlags, TextRunMeasureState *state)"}})` | One successful exact-signature edit. ECX receiver and stack arguments line +8, format +0xc, text +0x10, textOffset +0x14, charCount +0x18 width 2, segmentFlags +0x1c width 2, and state +0x20 are independently established machine-code ABI facts; after A04, `stack_frame` must additionally project those seven typed arguments at public frame offsets 0x1c through 0x34 while exposing no locals. | Stop on mutation error or parser coercion. Before any later entity action is accepted, POST-07 target `inspect_items.name/type`, POST-08 exact `func_profile.prototype`, and POST-09 exact two-metadata-plus-seven-argument target frame must all agree; stop on any missing, duplicate, extra, changed argument row or any local row, and never infer the two local slots from this endpoint. |
| CACHE-01 | `force_recompile({"database":"DB","items":{"addr":"0x00593cf0"}})` | One nonpersistent target cache invalidation after A04. | Stop on error or any scope beyond the target function. |
| A05 | `set_function_comments({"database":"DB","items":{"addr":"0x00593cf0","comment":"Measures one TextEditPane text-run segment, invokes final visible-count adjustment for non-object text, subtracts object/plain/masked width from TextRunMeasureState, clamps/stores final remaining width, and always returns false."}})` | Exact target regular function comment only. | Stop on error or any change to address/repeatable channels. |
| A06 | `set_repeatable_comments({"database":"DB","items":{"addr":"0x00593cf0","comment":"bool TextEditPane::MeasureTextRunSegment(TextEditLineRecord *, const TextRunFormatData *, const wchar_t *, int, unsigned short, unsigned short, TextRunMeasureState *);"}})` | Exact target repeatable function comment only. | Stop on error or any change to regular/address channels. |
| A07 | `rename({"database":"DB","batch":{"func":{"addr":"0x004baad0","name":"GrafPort__AdjustVisibleCountForTrailingWhitespace"},"pure":true,"allow_overwrite":false,"stop_on_error":true}})` | One successful helper rename. | Stop on collision, overwrite request, partial batch, bound change, or caller change. |
| A08 | `set_type({"database":"DB","edits":{"addr":"0x004baad0","kind":"function","signature":"unsigned __int16 __thiscall GrafPort__AdjustVisibleCountForTrailingWhitespace(GrafPort *this, const wchar_t *text, __int16 count)"}})` | ECX receiver; stack `text` at existing 0xc width 4 and signed `count` at existing 0x10 width 2; saved/return rows unchanged; no stack row added or removed. | Stop on stdcall retention, unsigned-count coercion, return-width drift, or any physical-frame delta beyond argument names/types. |
| CACHE-02 | `force_recompile({"database":"DB","items":{"addr":"0x004baad0"}})` | One nonpersistent helper cache invalidation after A08. | Stop on error or any scope beyond helper. |
| A09 | `set_function_comments({"database":"DB","items":{"addr":"0x004baad0","comment":"Scans backward over trailing space, tab, and carriage return; preserves the shipped count-versus-last-index terminal comparison."}})` | Exact helper regular function comment only. | Stop on error or any change to address/repeatable channels. |
| A10 | `set_repeatable_comments({"database":"DB","items":{"addr":"0x004baad0","comment":"unsigned short GrafPort::AdjustVisibleCountForTrailingWhitespace(const wchar_t *text, short count);"}})` | Exact helper repeatable function comment only. | Stop on error or any change to regular/address channels. |
| POST-06 | `get_comments({"database":"DB","addrs":["0x00593cf0","0x004baad0"]})` | Target/helper function regular/repeatable fields equal A05/A06/A09/A10; both address regular/repeatable fields remain empty. | Stop on missing, normalized, cross-channel, or extra text. |
| POST-07 | `inspect_items({"database":"DB","addrs":["0x00593cf0","0x004baad0"]})` | Target name `TextEditPane__MeasureTextRunSegment` and `inspect_items.type` exactly equal the full A04 signature; helper name/type exactly equal A07/A08; both remain code. This is the first persisted function-type authority component and must agree with POST-08 and POST-09. | Stop on blank, stale, normalized-to-another-calling-convention, reordered/removed/coerced argument, width/sign drift, name drift, item-class change, or contradiction with POST-08/POST-09. |
| POST-08 | `func_profile({"database":"DB","queries":[{"addr":"0x00593cf0","count":1,"include_lists":false,"include_prototype":true},{"addr":"0x004baad0","count":1,"include_lists":false,"include_prototype":true}]})` | One target at `0x00593cf0`, size `0xbd`, name `TextEditPane__MeasureTextRunSegment`, prototype exactly equal the A04 signature; one helper at `0x004baad0`, size `0x42`, name/prototype exactly equal A07/A08. This is the second persisted function-type authority component and must agree with POST-07 and POST-09's typed argument rows. | Stop on bound, size, name, multiplicity, calling-convention, argument-order/type/width/sign, prototype contradiction, or disagreement with POST-07/POST-09. |
| POST-09 | `stack_frame({"database":"DB","addrs":["0x00593cf0","0x004baad0"]})` | Target returns exactly nine rows: `__saved_registers` 0x14/0x4 `_DWORD`; `__return_address` 0x18/0x4 `_UNKNOWN *`; `line` 0x1c/0x4 `TextEditLineRecord *`; `format` 0x20/0x4 `const TextRunFormatData *`; `text` 0x24/0x4 `const wchar_t *`; `textOffset` 0x28/0x4 `int`; `charCount` 0x2c/0x2 `unsigned __int16`; `segmentFlags` 0x30/0x2 `unsigned __int16`; and `state` 0x34/0x4 `TextRunMeasureState *`. It exposes no local rows. Helper returns exactly `__saved_registers` 0x4/0x4 `_DWORD`, `__return_address` 0x8/0x4 `_UNKNOWN *`, `text` 0xc/0x4 `const wchar_t *`, and `count` 0x10/0x2 `__int16`. Combined with POST-07/POST-08, this is persisted function-type authority; the target local slots remain disassembly-only evidence. | Stop on target/helper null or error; any missing, duplicate, extra, reordered, renamed, retyped, resized, or re-offset row; any target local row; or disagreement with POST-07/POST-08. After A04 all seven exact target argument rows are mandatory, and no local row may be inferred from this endpoint. |
| POST-10 | `get_bytes({"database":"DB","regions":[{"addr":"0x00593ce5","size":11},{"addr":"0x00593cf0","size":189},{"addr":"0x00593dad","size":3},{"addr":"0x004baad0","size":66}]})` | Every byte and all four hashes remain prestate-identical. | Stop and reject TX on any byte or item-head mutation. |
| POST-11 | `xref_query({"database":"DB","queries":[{"addr":"0x00593cf0","direction":"to","xref_type":"any","offset":0,"count":32,"dedup":true,"include_fn":true},{"addr":"0x004baad0","direction":"to","xref_type":"code","offset":0,"count":16,"dedup":true,"include_fn":true}]})` | Target incoming total 0; helper exactly four original callers. | Stop on any route delta. |
| POST-12 | `callees({"database":"DB","addrs":["0x00593cf0","0x004baad0"],"limit":16})` | Target unique callees are helper `0x004baad0` and `GrafPort__GetTextWidth`; helper has no direct callee. | Stop on missing/extra callee or changed target. |
| POST-13 | `type_query({"database":"DB","queries":{"filter":"^TextRunMeasureState$","kind":"udt","count":10,"include_decl":true,"include_members":true,"max_members":16}})` | Exact 12-byte state UDT remains present and no unrelated type changed. | Stop on UDT drift or additional same-name declaration. |

The table has 34 structured request rows: 10 persistent entity-action rows A01-A10, two nonpersistent cache rows, and 22 AT01/PRE/POST read-only rows. The final supervisor transaction invoked them under its external fail-closed procedure and crossed no failed boundary. The report still prescribes no worker/process/save/verifier/promotion/rollback orchestration.

### Protection rows

| Row | Protected state | Exact verification |
| --- | --- | --- |
| P01 | Target bytes/items/bounds | PRE-01/POST-10 exact target and pad bytes/hashes; POST-02 through POST-04 exact one-function `0xbd` bound with both CC fences excluded. |
| P02 | Helper bytes/bounds/routes | PRE-01/POST-10 helper 66 bytes; PRE-03/POST-08 size `0x42`; PRE-07/POST-11 exact four incoming calls; POST-12 no helper callee. |
| P03 | Target reachability and body | PRE-06/POST-11 incoming total 0; POST-12 exact two unique callees; complete bounded 72-instruction body and local labels remain. |
| P04 | Public frame output, machine ABI, types, and comments | PRE-04 preserves literal comment channels; PRE-08 preserves the no-function target result and exact helper rows; POST-05 preserves the exact pre-A04 target metadata pair with no arguments or locals; POST-09 preserves the post-A04 pair plus all seven exact typed argument rows, no local rows, and the exact four helper rows. The target's two local slots, ECX receiver, seven stack arguments, and cleanup are protected independently by disassembly plus P01/P03/POST-10 byte/bound/body checks; no local is inferred from `stack_frame`. Combined POST-07 target name/type, POST-08 exact prototype, and POST-09 typed arguments prove the persisted A04 signature; POST-06 preserves only A05/A06/A09/A10 comment deltas. |
| P05 | Siblings and supporting UDTs | Pre/post readbacks preserve callback functions `[0x00593c20,0x00593ce5)` and `[0x00593db0,0x00593ef6)`, raw sibling `[0x00593f00,0x0059403b)`, and existing TextEditPane/TextRunFormatData/TextEditLineRecord layouts. |
| P06 | Unrelated IDA and physical state | No other name/type/comment/function/data/xref/byte/analysis delta; final transaction, rollback artifact, independent canonical verifier, and exclusive-read final hash prove the external persistence procedure protected physical state. |

### External supervisor Gate 2B boundary

AT01 and P01-P06 are entity-level runtime and protection requirements only. The supervisor independently supplied the runtime binding, collision-safe backup, save, semantic/physical readback, guarded rollback, promotion, and verifier procedure outside this report and failed closed during both earlier rejected attempts. Nothing in this report is an operational transaction or persistence program, and no by-* page should copy one from it.

The removed historical operational package is preserved verbatim only in the paired [inert companion](./0003FC-TextRunMeasureCallbackThiscallRaw-source-quality-removed.md). That companion is non-authoritative, must never be executed or submitted to `execute_report`, receives no Gate, coverage, score, IDA, validator, or lifecycle credit, and must remain physically adjacent so this relative link survives any report movement.

## First-Draft C++ Recommendation

### UID0003FC RECONSTRUCTION_CPP CODE

Replace the complete current target CPP channel with:

```cpp
// CPP@00593CF0 | UID0003FC source-quality repair
bool TextEditPane::MeasureTextRunSegment(TextEditLineRecord *line,
                                         const TextRunFormatData *format,
                                         const wchar_t *text,
                                         int textOffset,
                                         unsigned short charCount,
                                         unsigned short segmentFlags,
                                         TextRunMeasureState *state)
{
    (void)textOffset;

    int visibleCount = charCount;
    if (segmentFlags <= kTextRunHasNextSegment) {
        state->remainingWidth = state->availableWidth;
        state->scratch = 0;
    }

    int runWidth = 0;
    if (format->object != NULL) {
        runWidth = format->object->m_payload1;
    } else {
        if ((segmentFlags & kTextRunHasNextSegment) == 0) {
            visibleCount = AdjustVisibleCountForTrailingWhitespace(
                text, static_cast<short>(visibleCount));
        }

        if (m_maskedText)
            runWidth = visibleCount * GetTextWidth(L"*", 1);
        else
            runWidth = GetTextWidth(text, visibleCount);
    }

    state->remainingWidth -= runWidth;
    if ((segmentFlags & kTextRunHasNextSegment) == 0) {
        if (state->remainingWidth < 0)
            state->remainingWidth = 0;
        line->remainingWidth = state->remainingWidth;
        line->wrapState = 0;
    }

    return false;
}
```

### UID0003FC RECONSTRUCTION_H CODE

Keep the target H channel empty. UID0000EO already owns this exact declaration in `TextEditPane`:
`bool MeasureTextRunSegment(TextEditLineRecord *, const TextRunFormatData *, const wchar_t *, int, unsigned short, unsigned short, TextRunMeasureState *);`
Duplicating it in the target H channel would emit the declaration twice.

### UID0001JQ RECONSTRUCTION_CPP CODE

Replace the complete sibling CPP channel with this helper-route correction; all other behavior is preserved:

```cpp
enum TextRunSegmentFlags
{
    kTextRunHasNextSegment = 0x01,
    kTextRunHasPreviousSegment = 0x02
};

static bool __cdecl TextRunMeasureCallback(TextEditLineRecord *line,
                                           const TextRunFormatData *format,
                                           const wchar_t *text,
                                           int textOffset,
                                           unsigned short charCount,
                                           unsigned short segmentFlags,
                                           void *context,
                                           TextEditPane *pane)
{
    (void)textOffset;
    TextRunMeasureState *state =
        static_cast<TextRunMeasureState *>(context);

    int visibleCount = charCount;
    if (segmentFlags <= kTextRunHasNextSegment) {
        state->remainingWidth = state->availableWidth;
        state->scratch = 0;
    }

    int runWidth = 0;
    if (format->object != NULL) {
        runWidth = format->object->m_payload1;
    } else {
        if ((segmentFlags & kTextRunHasNextSegment) == 0) {
            visibleCount = pane->AdjustVisibleCountForTrailingWhitespace(
                text, static_cast<short>(visibleCount));
        }

        if (pane->m_maskedText)
            runWidth = visibleCount * pane->GetTextWidth(L"*", 1);
        else
            runWidth = pane->GetTextWidth(text, visibleCount);
    }

    state->remainingWidth -= runWidth;
    if ((segmentFlags & kTextRunHasNextSegment) == 0) {
        if (state->remainingWidth < 0)
            state->remainingWidth = 0;
        line->remainingWidth = state->remainingWidth;
        line->wrapState = 0;
    }

    return false;
}
```

UID0001JQ H remains blank because the file-local callback prototype is already supplied by the owning TextEditPane H route for friendship/access.

### UID0001JR RECONSTRUCTION_CPP CODE

Replace the complete sibling CPP channel with this helper-route correction; all other behavior is preserved:

```cpp
enum TextEditPaneTextAlignment
{
    kTextEditAlignLeft = 0,
    kTextEditAlignCenter = 1,
    kTextEditAlignRight = 2,
    kTextEditAlignTrimFinalWhitespace = 3
};

static bool __cdecl DrawTextRunCallback(TextEditLineRecord *line,
                                        const TextRunFormatData *format,
                                        const wchar_t *text,
                                        int textOffset,
                                        unsigned short charCount,
                                        unsigned short segmentFlags,
                                        void *context,
                                        TextEditPane *pane)
{
    (void)textOffset;
    TextRunDrawState *state = static_cast<TextRunDrawState *>(context);
    unsigned short visibleCount = charCount;

    if (segmentFlags <= kTextRunHasNextSegment) {
        state->lineRect.left = pane->m_textAreaLeft;
        state->lineRect.top = pane->m_textAreaTop + line->top;
        state->lineRect.right = pane->m_textAreaRight;
        state->lineRect.bottom = pane->m_textAreaTop + line[1].top;

        pane->GetClipRect(&state->clippedLineRect);
        IntersectRects(&state->clippedLineRect,
                       &state->lineRect,
                       &state->clippedLineRect);

        const unsigned int oldDrawColor = pane->m_drawColor;
        pane->m_drawMode = 0;
        pane->SetDrawColor((pane->m_editorFlags & kTextEditBlackBackground) == 0
                               ? pane->m_textBackColor
                               : 0);
        g_pfnFillRect(pane, &state->clippedLineRect);
        pane->SetDrawColor(oldDrawColor);

        int horizontalOffset = 0;
        if (pane->m_textAlignment == kTextEditAlignCenter)
            horizontalOffset = line->remainingWidth / 2;
        else if (pane->m_textAlignment == kTextEditAlignRight)
            horizontalOffset = line->remainingWidth;

        pane->MoveTo(state->lineRect.left + horizontalOffset,
                     state->lineRect.top + pane->GetLineHeight());
    }

    if (state->applyRunTextColor)
        pane->SetTextColor(format->textColor);

    if (format->object != NULL) {
        format->object->OnUpdate();
        return false;
    }

    if (pane->m_textAlignment == kTextEditAlignTrimFinalWhitespace &&
        (segmentFlags & kTextRunHasNextSegment) == 0) {
        visibleCount = pane->AdjustVisibleCountForTrailingWhitespace(
            text, static_cast<short>(visibleCount));
    }

    pane->DrawTextRunSegment(text, visibleCount, 0, segmentFlags);
    return false;
}
```

UID0001JR H remains blank because its file-local callback declaration/access route belongs to the owning class H.

### UID00016C RECONSTRUCTION_CPP CODE

Replace the complete UID00016C CPP channel with the same seven bodies in physical/source order and the corrected member ABI:

```cpp
short GrafPort::GetTextWidth(const wchar_t *text, int charCount)
{
    StringIter iter(text, charCount);

    short totalWidth = 0;
    wchar_t ch = static_cast<wchar_t>(iter.GetNextChar());
    wchar_t nextCh = static_cast<wchar_t>(iter.GetNextChar());

    while (ch != L'\0') {
        short advance = 0;
        g_pFontImageLib->MeasureGlyphWidth(m_fontId,
                                           ch,
                                           nextCh,
                                           0,
                                           0,
                                           NULL,
                                           &advance,
                                           NULL);

        totalWidth = static_cast<short>(totalWidth + advance);
        ch = nextCh;
        nextCh = static_cast<wchar_t>(iter.GetNextChar());
    }

    return totalWidth;
}

short GrafPort::GetTextWidth(const wchar_t *text)
{
    return GetTextWidth(text, static_cast<int>(wcslen(text)));
}

short GrafPort::GetLineHeight()
{
    short lineHeight = 0;
    g_pFontImageLib->GetFontMetrics(m_fontId, NULL, &lineHeight);
    return lineHeight;
}

unsigned short GrafPort::AdjustVisibleCountForTrailingWhitespace(
    const wchar_t *text, short count)
{
    const wchar_t *scan = text + count - 1;
    while (text <= scan) {
        const wchar_t ch = *scan;
        if (ch != L' ' && ch != L'\t' && ch != L'\r')
            break;
        --scan;
    }

    const int lastVisibleIndex = static_cast<int>(scan - text);
    return count <= lastVisibleIndex
        ? static_cast<unsigned short>(lastVisibleIndex)
        : static_cast<unsigned short>(count);
}

void GrafPort::DrawGlyphWithTextColors(wchar_t ch, wchar_t nextCh)
{
    unsigned char colors[6];

    colors[0] = static_cast<unsigned char>(m_textBackColor);
    colors[1] = static_cast<unsigned char>(m_textColor);
    colors[2] = static_cast<unsigned char>(m_textBackColor);
    colors[3] = static_cast<unsigned char>(m_textColor);
    colors[4] = static_cast<unsigned char>(m_textColor);
    colors[5] = static_cast<unsigned char>(m_textBackColor);

    DrawGlyph(ch, nextCh, 0, colors);
}

void GrafPort::DrawWideText(const wchar_t *text, int charCount)
{
    if (static_cast<short>(charCount) < 0)
        return;

    unsigned char colors[6];
    colors[0] = static_cast<unsigned char>(m_textBackColor);
    colors[1] = static_cast<unsigned char>(m_textColor);
    colors[2] = static_cast<unsigned char>(m_textBackColor);
    colors[3] = static_cast<unsigned char>(m_textColor);
    colors[4] = static_cast<unsigned char>(m_textColor);
    colors[5] = static_cast<unsigned char>(m_textBackColor);

    if (m_textDrawMode == 0 || m_textDrawMode == 2) {
        short lineHeight = 0;
        g_pFontImageLib->GetFontMetrics(m_fontId, NULL, &lineHeight);

        RectBounds backgroundRect;
        backgroundRect.left = m_currentX;
        backgroundRect.top = m_currentY - lineHeight;
        backgroundRect.right = m_currentX + GetTextWidth(text, charCount);
        backgroundRect.bottom = m_currentY;

        const unsigned char oldDrawMode = m_drawMode;
        const unsigned int oldDrawColor = m_drawColor;

        m_drawMode = m_textDrawMode;
        m_drawColor = m_textBackFillColor;
        g_pfnFillOrInvalidateRect(this, &backgroundRect);
        m_drawMode = oldDrawMode;
        m_drawColor = oldDrawColor;
    }

    StringIter iter(text, charCount);
    wchar_t ch = static_cast<wchar_t>(iter.GetNextChar());
    wchar_t nextCh = static_cast<wchar_t>(iter.GetNextChar());

    while (ch != L'\0') {
        DrawGlyph(ch, nextCh, 0, colors);
        ch = nextCh;
        nextCh = static_cast<wchar_t>(iter.GetNextChar());
    }
}

void GrafPort::DrawOutlinedText(int x, int y,
                                const wchar_t *text, int charCount)
{
    const unsigned int oldTextColor = m_textColor;
    m_textColor = m_textBackColor;

    m_currentX = x;
    m_currentY = y - 1;
    DrawWideText(text, charCount);

    m_currentX = x;
    m_currentY = y + 1;
    DrawWideText(text, charCount);

    m_currentX = x - 1;
    m_currentY = y;
    DrawWideText(text, charCount);

    m_currentX = x + 1;
    m_currentY = y;
    DrawWideText(text, charCount);

    m_textColor = oldTextColor;
    m_currentX = x;
    m_currentY = y;
    DrawWideText(text, charCount);
}
```

UID00016C H remains blank because UID00005V owns the GrafPort class declaration.

### UID00005V RECONSTRUCTION_H CODE

Replace the complete GrafPort H channel with the current declaration plus the one member declaration after `GetLineHeight`:

```h
#ifndef NEXUSTK_RENDER_GRAFPORT_H
#define NEXUSTK_RENDER_GRAFPORT_H

#include <cstddef>
#include "../util/LObject.h"
#include "../ui/core/RectBounds.h"
#include "../ui/core/Region.h"
#include "EPFTileContext.h"

struct IDirectDrawSurface;
struct DLPalette;
struct FrameDrawRecord;
struct SurfaceSpriteBlitOptions;

class GrafPort : public LObject
{
public:
    GrafPort();
    virtual ~GrafPort();
    virtual void UpdateRenderRegion(const RectBounds *bounds);

    void EnableSoftwareBuffer();
    RectBounds *GetBounds(RectBounds *outBounds) const;
    void ReleaseSurface();
    void SetSurfacePixelData(void *pixelData);
    void SetSurfaceRowStride(int rowStridePixels);
    Point *GetOrigin(Point *outOrigin) const;
    void SetOrigin(int x, int y);
    void SetClipRegion(const Region *clipRegion);
    void GetClipRegion(Region *outClipRegion) const;
    void SetClipRect(const RectBounds *clipRect);
    void DisableDrawing();
    void EnableDrawing();
    void GetDrawPosition(int *outPosition);
    void MoveTo(int x, int y);
    void OffsetDrawPosition(int deltaX, int deltaY);
    void SetFontId(unsigned short fontId);
    void SetDrawMode(unsigned char drawMode) { m_drawMode = drawMode; }
    void SetTextDrawMode(unsigned char textDrawMode) { m_textDrawMode = textDrawMode; }
    void SetDrawColor(unsigned int color);
    void SetTextBackFillColor(unsigned int color);
    void SetTextColor(unsigned int color);
    void SetTextBackColor(unsigned int color);
    DLPalette *GetPalette() const;
    void SetPalette(DLPalette *palette);
    void GetClipRect(RectBounds *outClipRect);
    void ReleaseBackingStore();
    void UpdateSurfaceInfo();
    void EndPaint();
    void LineTo(int x, int y);
    int DrawSprite(GrafPort *source, const RectBounds *sourceRect,
                   const RectBounds *destinationRect, int mode,
                   void *palette, const SurfaceSpriteBlitOptions *options);
    int RenderTileFrame(const EPFTileContext *sourceContext,
                        const RectBounds *sourceRect,
                        const RectBounds *destinationRect, int mode,
                        const wchar_t *paletteName,
                        const SurfaceSpriteBlitOptions *options);
    int ForwardToTileFrameBlitHelper(
        int destinationX, int destinationY,
        const FrameDrawRecord *frameRecord, void *palette, int mode,
        const SurfaceSpriteBlitOptions *options);
    void ScrollPixelBuffer(const RectBounds *scrollRect,
                           int deltaX, int deltaY, Region *dirtyRegion);
    void BlitSurface(GrafPort *source, const RectBounds *sourceRect,
                     const RectBounds *destinationRect, int mode);
    void DrawRectFrame(const RectBounds *rect);
    void CompositePixels(const RectBounds *rect);
    void DrawTiledBackground(const RectBounds *clipRect,
                             const FrameDrawRecord *frameRecord,
                             const wchar_t *paletteName);
    void FitTextAndAppendSuffix(wchar_t *text, std::size_t textCapacity,
                                const wchar_t *suffix, int maxPixelWidth);
    int CountCharsFittingWidth(const wchar_t *text, int maxPixelWidth);
    short GetTextWidth(const wchar_t *text, int charCount);
    short GetTextWidth(const wchar_t *text);
    short GetLineHeight();
    unsigned short AdjustVisibleCountForTrailingWhitespace(
        const wchar_t *text, short count);
    void DrawGlyphWithTextColors(wchar_t ch, wchar_t nextCh);
    void DrawWideText(const wchar_t *text, int charCount);
    void DrawOutlinedText(int x, int y,
                          const wchar_t *text, int charCount);
    void DrawTextInRect(const wchar_t *text, int length,
                        const RectBounds *rect);
    void DrawOutlinedText(const wchar_t *text, int length,
                          const RectBounds *rect);
    void DrawShadowedText(const wchar_t *text, int length,
                          const RectBounds *rect);
    void DrawGlyph(wchar_t ch, wchar_t nextCh, bool fillBackground,
                   const unsigned char *glyphColors);

protected:
    Region m_exposedRegion;
    IDirectDrawSurface *m_ddSurface;
    EPFTileContext m_surfaceContext;
    RectBounds m_visibleBounds;
    Region m_clipRegion;
    int m_currentY;
    int m_currentX;
    unsigned char m_drawMode;
    bool m_drawEnabled;
    unsigned int m_drawColor;
    unsigned int m_textBackFillColor;
    unsigned int m_textColor;
    unsigned int m_textBackColor;
    DLPalette *m_palette;
    unsigned char m_textDrawMode;
    unsigned short m_fontId;
    int m_textAlign;
    float m_alpha;
    bool m_usesSoftwareBuffer;
    void *m_softwareBuffer;
    int m_softwarePitchBytes;
};

typedef char GrafPortSizeMustBe160[sizeof(GrafPort) == 0xa0 ? 1 : -1];

#endif
```

UID00005V CPP remains the existing include/children envelope.

### UID0000EN RECONSTRUCTION_H CODE

Replace the complete TextEditObject H channel with the current class plus class friendship:

```h
class Event;
class TextEditPane;
struct TextEditLineRecord;
struct TextRunFormatData;

static bool __cdecl TextRunMeasureCallback(TextEditLineRecord *line,
                                           const TextRunFormatData *format,
                                           const wchar_t *text,
                                           int textOffset,
                                           unsigned short charCount,
                                           unsigned short segmentFlags,
                                           void *context,
                                           TextEditPane *pane);

class TextEditObject : public LObject
{
public:
    TextEditObject(void *ownerHandle);
    virtual ~TextEditObject();

    int GetObjectType() const;
    void GetPayloadPair(int *outPair) const;
    void *GetOwnerHandle() const;
    void SetPayloadPair(int first, int second);

    virtual void OnUpdate();
    virtual void OnMouseEvent(Event *event,
                              bool repeatedClick,
                              unsigned int messageTime);

protected:
    friend class TextEditPane;
    friend bool __cdecl TextRunMeasureCallback(TextEditLineRecord *line,
                                               const TextRunFormatData *format,
                                               const wchar_t *text,
                                               int textOffset,
                                               unsigned short charCount,
                                               unsigned short segmentFlags,
                                               void *context,
                                               TextEditPane *pane);

    int m_objectType;
    void *m_ownerHandle;
    int m_payload0;
    int m_payload1;
};

typedef char TextEditObjectSizeMustBe14[
    (sizeof(TextEditObject) == 0x14) ? 1 : -1];
```

UID0000EN CPP remains blank. The current generated TextEditPane H already contains exactly one TextEditObject, TextEditScrap, and EPFTextEditObject definition from canonical child H blocks UID0000EN, UID0000EP, and UID00004H. Preserve that single-emitter routing and UID0000EO's forward declarations, callback declarations, TextEditPane declaration, and unrelated content; do not perform the formerly proposed aggregate-removal edit.

## Final Recommendation

Accept the target as an exact raw private member at the existing address and source route. The completed ordinary callback repaired the missing helper invocation, helper member ABI, two modeled sibling calls, GrafPort declaration, and TextEditObject friendship as one coherent source-quality change while preserving the refreshed single-emitter support-class H route and the helper's shipped comparison.

The target has no runtime caller in this binary, but reconstructability remains true because it is authored TextEditPane source. No-code classification would lose a complete private method and contradict the established neighboring raw-member source model.

Supervisor Gate 2B remained external and fail-closed. Final transaction `UID0003FC-20260822-071358557` applied A01-A10/CACHE-01/CACHE-02 only after AT01/PRE checks, passed every POST/P01-P06 expectation, saved and atomically promoted the exact transaction, preserved the rollback artifact, and passed independent canonical verifier session `supervisor_uid0003fc_verify_20260822_0718`. Result is `APPLIED_VERIFIED_SAVED`; nothing in this report is a persistence program or may be copied into by-* pages as one.

## Recommended Target Doc Changes

- Change entity kind from raw callback variant to compiler-retained private member counterpart while preserving the stable title.
- Add exact half-open range, size, hash, first/last bytes, 72-instruction count, and padding hashes.
- Preserve the literal dated pre-Gate2B IDA baseline as historical, add the final canonical `APPLIED_VERIFIED_SAVED` receipt, and retain the 34 accepted AT01/entity-level MCP request rows plus P01-P06 protections; do not copy a persistence program into the target page.
- Add the seven-argument member ABI and explicit `textOffset` unused disposition.
- Add exact segment-flag, state, object/plain/masked, helper-call, clamp/store, and false-return flow.
- Add complete xref/immediate/pointer-negative evidence with sibling controls.
- Replace the formal CPP exactly; keep formal H blank with class-owner reason.
- Replace historical broad trim wording with the exact helper-call and shipped comparison caveat.
- Raise metadata to `92/93`; preserve owner/emitter/reconstructable/position/nesting.
- Add a dated change note preserving valid earlier evidence and superseding only incomplete source/prose.

## Recommended Support Doc Changes

| Destination | Exact additive repair |
| --- | --- |
| UID0001JQ | preserve cdecl ABI/routes/body; change helper call to inherited pane member; document helper return narrowing and shipped comparison |
| UID0001JR | preserve cdecl ABI/routes/body; change helper call to inherited pane member |
| UID00016C | reclassify helper as GrafPort member; correct signature/body/order; replace static-linkage caveat with closed member route |
| UID00005V | add one public member declaration; update method inventory/source evidence |
| UID0000EN | add `friend class TextEditPane`; preserve protected payloads and callback friendship |
| UID0000EO | preserve target declaration/state types and the refreshed single-emitter support-class H route; make no aggregate-removal edit; update member inventory |
| UID0000ON | preserve source unit/order; document corrected member/helper route and generated expectations |
| generated TextEditPane CPP/H | validator regeneration only; physically reread mutable outputs; target/siblings compile against inherited helper, TextEditPane friendship is present, and each support class remains once |
| generated GrafPort CPP/H | validator regeneration only; physically reread mutable outputs; non-static member definition/declaration appears once |

No by-item page, source-tree page, split page, global page, tracker, audit ledger, or lifecycle file requires an agent edit from this report.

## Score And Metadata Recommendation

| Page | Pre-callback baseline | Current implemented | Basis |
| --- | --- | --- | --- |
| UID0003FC target | `85/88` | `92/93` | exact bytes/range/ABI/routes/behavior/source/IDA/formal closure |
| UID0001JQ measure callback | `90/93` | `91/94` | exact helper member route closes source linkage |
| UID0001JR draw callback | `91/93` | `92/94` | exact helper member route closes source linkage |
| UID00016C GrafPort helpers | `88/90` | `90/93` | helper ABI/return/count/source placement resolved |
| UID00005V GrafPort class | `88/90` | `89/92` | declaration and member inventory repaired; broad class still below final audit |
| UID0000EN TextEditObject | `94/94` | `94/94` | friendship is an access repair; page remains at ordinary ceiling |
| UID0000EO TextEditPane | `94/94` | `94/94` | declaration/type/source inventory retained |
| UID0000ON TextEditPane file | `94/94` | `94/94` | unit ownership/order retained |

Scores remain below 95. UID0003FC's exact original method spelling and compiler switches are unavailable; UID00016C/00005V are broader than this one corrected member. These are explicit score caps, not behavioral blockers.

External supervisor ownership and final `APPLIED_VERIFIED_SAVED` Gate 2B persistence change no score. The retained entity actions, readbacks, protections, rollback receipt, and canonical verifier prove modeling closure, while the external runtime/backup/save/promotion/readback procedure adds no new behavioral evidence.

## Open Questions With Attempted Resolution

| Question | Routes attempted | Resolution |
| --- | --- | --- |
| exact target range? | items, 72 instructions, PE bytes, both pads, neighbors | `[0x00593cf0,0x00593dad)` |
| callback or member? | ECX use, stack cleanup, sibling ABI, address routes | private member |
| source name? | adjacent member naming, class declaration, whole-file order, rejected raw label | `MeasureTextRunSegment` |
| exact signature? | bounded disassembly of all stack slots, ECX receiver, `retn 0x1c`, and sibling callback; pre-type `stack_frame` deliberately excluded as argument evidence | seven arguments in Section 22; after A04, exact persistence is proved by combined POST-07 `inspect_items.name/type`, POST-08 `func_profile.prototype`, and POST-09 seven typed argument rows, while the two locals remain disassembly-only |
| final text behavior? | target instructions and cdecl parity | mandatory call to helper before width |
| does helper truly trim? | complete helper disassembly/decompile and terminal compare | it scans whitespace but preserves observed count-versus-last-index comparison; no stronger claim |
| helper free or member? | all four call sites, ECX, `retn 8`, physical corridor | GrafPort member |
| helper source types? | signed word load, low-word returns, caller `movzx ax` | unsigned-short return, signed-short count |
| state +8 name? | all target/sibling/generated/report uses | reset-only; retain conservative `scratch` |
| object field access legal? | TextEditObject H/access, raw member siblings | add `friend class TextEditPane`; keep protected |
| owner/source file? | state fields, class methods, surrounding unit, generated route | UID0000EO / UID0000ON |
| H disposition? | current target declaration at TextEditPane H line 481, single support definitions at lines 171, 212, and 560, and class friendship at line 188 | target H blank; class declaration once; child support classes once; `friend class TextEditPane` present once |
| target reachability? | xrefs, immediates, raw pointer bytes with controls | no shipped route; compiler-retained authored member |
| split/new UID? | exact fences, neighbors, existing identities | none |
| coverage row? | exact by-memory ordering plus supervisor commands `000000026445`/`000000026446` | applied and validated UID0003FC between UID0001JQ and UID0001JR, with all five replacement rows also present |
| Gate 2B ownership complete? | retained AT01, A01-A10, CACHE-01/CACHE-02, PRE/POST, P01-P06, final transaction, rollback, and verifier receipts | yes: external supervisor transaction `UID0003FC-20260822-071358557` is `APPLIED_VERIFIED_SAVED`; report text remains a non-operational evidence contract |

No item remains categorized as future investigation.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Historical supervisor application receipt: the exact rows below were applied after ordinary validation and validated by commands `000000026445` and `000000026446`. They are retained verbatim as the C0003FC-039 evidence payload; the UID0003FC phrase `no-IDA-function` describes the dated pre-Gate2B baseline rather than final canonical state.

Replace UID00016C in `by-memory/-coverage-report.md`:

>     - [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md) 0x004ba9a0-0x004bad66 | GrafPort text-method cluster | GrafPortTextRunHelpers : reconstructable : 90% : very-strong : Seven source-ready GrafPort text methods with exact boundaries and formal C++, including receiver-independent AdjustVisibleCountForTrailingWhitespace as an inherited member with unsigned-short return/signed-short count, four TextEditPane receiver calls, preserved shipped terminal comparison, UTF-16 width/line-height/glyph/draw behavior, and complete GrafPort H route.

Replace UID0001JQ in `by-memory/-coverage-report.md`:

>     - [UID:0001JQ][0x00593c20-0x00593ce4.TextRunMeasureCallback](by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md) 0x00593c20-0x00593ce4 | file-local callback | TextRunMeasureCallback : reconstructable : 91% : very-strong : Exact cdecl TextEditPane iterator measurement callback with four address-taking routes, generic context/state ABI, object/plain/masked width paths, inherited GrafPort visible-count member call on final non-object segments, remaining-width clamp/writeback, complete formal C++, and raw-member separation.

Insert UID0003FC immediately after UID0001JQ and before UID0001JR in `by-memory/-coverage-report.md`:

>     - [UID:0003FC][0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw](by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md) 0x00593cf0-0x00593dad | compiler-retained private member | TextEditPane::MeasureTextRunSegment : reconstructable : 92% : very-strong : Exact 189-byte no-IDA-function TextEditPane member with ECX plus seven stack arguments, retn 0x1c, zero start/immediate/pointer routes, exact CC fences, TextRunMeasureState reset/subtract/final clamp/writeback, object/plain/masked width paths, inherited final visible-count member call, unconditional false return, complete formal C++, and single class/file emitter route.

Replace UID0001JR in `by-memory/-coverage-report.md`:

>     - [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md) 0x00593db0-0x00593ef5 | file-local callback | DrawTextRunCallback : reconstructable : 92% : very-strong : Exact cdecl TextEditPane draw callback with two address-taking routes, shared TextRunDrawState ABI, clip/fill/alignment/object/text behavior, inherited GrafPort visible-count member call for final trim-alignment segments, lower renderer forwarding, complete formal C++, and raw-member separation.

Replace UID00005V in `by-class/-coverage-report.md`:

> - [UID:00005V][GrafPort](by-class/GrafPort.md) : reconstructable : 89% : very-strong : Core graphics-port class with exact surface/clip/draw/text children and layouts, including the receiver-independent AdjustVisibleCountForTrailingWhitespace member declaration proven by four TextEditPane ECX receiver calls, exact unsigned-short return/signed-short count ABI, inherited text-width/line-height routes, and preserved renderer ownership boundaries.

Replace UID0000EN in `by-class/-coverage-report.md`:

> - [UID:0000EN][TextEditObject](by-class/TextEditObject.md) : reconstructable : 94% : very-strong : Complete 0x14 LObject-derived TextEditObject declaration with object-type, owner-handle, protected payload-pair storage, public get/set helpers, virtual update/mouse hooks, exact cdecl measurement-callback friendship, TextEditPane class friendship for raw member payload access, and single TextEditPane H/source ownership.

No generated tracker, audit ledger, or lifecycle state is manually edited from this report.

## Follow-Up Actions

1. Supervisor performs fresh exact-artifact Gate 1 on this reconciled report body and confirms the validator-owned history footer is byte-identical.
2. Treat Gate 2A, command-26443/26444 generated verification, command-26445/26446 coverage validation, and final canonical Gate 2B as historical completed receipts; do not repeat mutation from ordinary report prose.
3. Determine execution/archive state only from this report's current physical path plus validator-owned history, never from a fixed active/archive path assertion in the body.
4. Keep the paired inert companion physically beside this report through every movement and verify the relative link in the exact moved artifact.
5. Preserve lifecycle commands, movement, and post-move exact-artifact auditing as explicit supervisor-only C0003FC-041 work.

## Confidence

| Area | Confidence | Basis |
| --- | --- | --- |
| range/bytes/padding | very high | physical PE hashes plus live items/instructions |
| raw ABI/signature | very high | bounded disassembly proves ECX, two reserved locals, seven stack slots, and `retn 0x1c`; post-A04 `stack_frame` corroborates the seven typed arguments but exposes no locals |
| behavior/state flow | very high | complete instruction pass plus cdecl parity |
| no-route result | very high | xref/immediate/raw-pointer checks with controls |
| member identity/owner | high | ABI, fields, neighbors, class declaration |
| helper member ABI | very high | four independent receiver call sites plus callee |
| source name/field spelling | medium-high | project convention; no original symbols |
| exact compiler retention flags | medium | output shape supports retention; switches absent |
| formal source fidelity | high | behavior/access/linkage/source-order closure |
| current generated-source state | high for this dated snapshot only | supervisor commands `000000026435`-`000000026444` passed and the four command-26443/26444 artifacts were physically reread with exact hashes and line anchors; generated identities remain mutable |
| Gate 2B entity closure | very high | 34 retained AT01/entity request rows, exact A01-A10/CACHE/PRE/POST/P01-P06 topology, rollback receipt, saved/promoted physical hash, and independent canonical verifier support `APPLIED_VERIFIED_SAVED` |

## Validator Results

B003 validated every changed ordinary by-* page with scoped file mode and `--apply`; commands `000000026324` through `000000026333`, plus exact-source follow-ups `000000026351`, `000000026353`, and `000000026355`, all exited `0` with `ok: 1`. Commands `000000026324`, `000000026325`, `000000026326`, `000000026327`, `000000026328`, `000000026329`, `000000026331`, `000000026332`, `000000026333`, `000000026351`, `000000026353`, and `000000026355` completed foreground generated refresh; command `000000026330` validated UID0003FD with generated refresh deferred. Command `000000026328` retained three known unrelated `missing_ref_uid 0003XE` warnings and otherwise succeeded. Command `000000026355`, refreshed at `2026-08-22T05:19:01-04:00`, is the historical coherent B003 callback receipt after the TextEditPane aggregate emitter and UID0003FC narrow formal channel were synchronized exactly with the accepted report block.

Historical supervisor verification then passed scoped validator commands `000000026435` through `000000026443`, owner generated-refresh command `000000026444`, and coverage validators `000000026445`/`000000026446`. Physical final generated readback matched Current Target State: TextEditPane CPP/H command `000000026443`, GrafPort CPP/H command `000000026444`, with the accepted target/helper calls, member definition/declaration, friendship, and single support definitions intact. The exact manual coverage rows were also physically present.

During the B003 implementation and report-repair phases, B003 ran no `execute_report` variant, compile probe, lifecycle command, IDA mutation/save, manual coverage mutation, generated-file direct edit, process handling, persistence, rollback, or archive operation. Subsequent supervisor events are historical receipts only; current execution/archive state is intentionally not asserted here and is authoritative only from this report's current physical path plus validator-owned history. The report retains all 33 fixed headings and formal CPP/H, the three mandatory provenance headers, 41 ordered exact eight-field ledger/checklist twins, 40 checked/applied rows and only C0003FC-041 unchecked/proposed, 34 retained AT01/entity request rows, a relative paired-companion link, and exactly one terminal lifecycle marker.

This POST-05 contract repair ran no validator or IDA request. It records the supervisor's first discarded isolated transaction as historical evidence, keeps A01-A10 unchanged, and replaces the false target local/argument enumeration with the exact public two-row metadata result plus POST-07/POST-08 type/prototype authority. The then-canonical length/hash and blank target entity remained unchanged only for that discarded attempt; the later final canonical receipt supersedes that baseline.

This POST-09 contract repair likewise ran no validator or IDA request. It records discarded retry session `supervisor_uid0003fc_gate2b_retry_20260822_0703` as historical evidence, preserves the exact pair-only pre-type POST-05 result, and replaces the false post-A04 absence rule with the exact two metadata plus seven typed target argument rows and no locals. Persisted target type authority fails closed on the combined POST-07 name/type, POST-08 prototype, and POST-09 typed argument readback. The retry performed no save or promotion, so only that attempt retained the old canonical baseline; final transaction `UID0003FC-20260822-071358557` later produced the applied canonical receipt.

Historical final supervisor result is `APPLIED_VERIFIED_SAVED`: transaction `UID0003FC-20260822-071358557`, working session `supervisor_uid0003fc_gate2b_final_20260822_0713`, verifier `supervisor_uid0003fc_verify_20260822_0718`, rollback SHA256 `39754A1765590C4814C6716E645A0DFF974C8B4C83D1761980D11DE6D80D8B11`, and final canonical length `143211145` / SHA256 `F5941D0C032A4022F5C59633EA4BFE740ADCD508CE726619E9C5219C3D567DD2`.

## Changed Files

- The authoritative report location is its current physical path plus validator-owned history. The paired `0003FC-TextRunMeasureCallbackThiscallRaw-source-quality-removed.md` is non-authoritative, and the supervisor must keep it physically beside the report through active/executed movement so the relative companion link remains valid.
- The implementation changed exactly the nine authorized ordinary pages: UID0003FC, UID0001JQ, UID0001JR, UID00016C, UID0003FD, UID00005V, UID0000EN, UID0000EO, and UID0000ON. Each page was leased only for an immediate edit/validator batch and released immediately. UID0003FC and UID0000EO were later reacquired for the exact blank-line source correction; UID0000EO was also reacquired for aggregate CPP synchronization. Follow-up commands `000000026351`, `000000026353`, and `000000026355` validated those exact-source repairs, and every reacquired lease was released immediately.
- During the B003 implementation callback, B003 directly changed no manual coverage file, generated file, tracker, audit ledger, goal/notes, IDA database, lifecycle state, or validator-owned report location. Validator and supervisor commands later produced the separately recorded historical generated, coverage, canonical, and lifecycle receipts.
- The new report was created as the minimum file needed for the explicit short report lease. The initial lease began at `2026-08-22T05:59:46Z` and expired during formal-report assembly; B003 reacquired the same report-only lease at `2026-08-22T06:08:45Z` for the final artifact correction/readback and releases it immediately afterward.
- This Gate 1 repair changed only the same report's provenance preamble, Sections 7, 11, 21, 23-27, 29-33, and the two C0003FC twin tables. Its first repair lease expired during the large table insertion; B003 reacquired the same report-only lease at `2026-08-22T07:37:37Z` for dependent reconciliation and final readback and releases it immediately afterward.
- This narrow current-state repair physically reread all four generated artifacts, replaced the superseded command `000000026289` authority with dated mutable command `000000026323` receipts, reconciled the changed support-class conclusion and every dependent report occurrence, and touched no generated or ordinary documentation. B003 leased only this report at `2026-08-22T08:14:05Z` and releases it immediately after final readback.
- This Gate 1 package-removal repair moved only the rejected operational material into the linked inert companion, retained the entity-level IDA handoff, and reconciled its dependent summaries and C033/C041 twins. B003 leased the source at `2026-08-22T08:35:35Z`; the new companion was created under that source lease, then separately leased at `2026-08-22T08:35:42Z` for its substantive edit. Both leases were released immediately after their respective edits.
- This implementation callback applied all 34 ordinary claims to the nine named pages, validated them with commands `000000026324` through `000000026333` and exact-source follow-ups `000000026351`, `000000026353`, and `000000026355`, physically reread the four coherent command-`000000026355` generated artifacts, and left C0003FC-030 through C0003FC-033, C0003FC-037, C0003FC-039, and C0003FC-041 for supervisor ownership. The report lease was acquired only for this receipt/checklist reconciliation and is released immediately after final readback.
- This Gate 2B POST-05 repair changed only this report: it historicalized disposable session `supervisor_uid0003fc_gate2b_20260822_0649`, repaired POST-05/A04/POST-07 through POST-09/P04 and dependent C005/C006/C030/C031/C033 twins/prose, retained all 34 request rows and A01-A10, and made no ordinary, IDA, coverage, generated, validator, lifecycle, companion, or archive edit. The report lease is released immediately after final readback.
- This Gate 2B POST-09 repair changed only this report: it historicalized disposable retry session `supervisor_uid0003fc_gate2b_retry_20260822_0703`, retained the exact pre-type POST-05 pair-only contract, repaired A04/POST-07 through POST-09/P04 and dependent C005/C006/C031/C033 twins/prose to require the post-A04 metadata pair plus seven typed arguments and no locals, retained all 34 request rows and A01-A10, and made no ordinary, IDA, coverage, generated, validator, lifecycle, companion, or archive edit. The report lease is released immediately after final readback.
- This post-execution reconciliation changes only this report body: it historicalizes every old canonical prestate, records final `APPLIED_VERIFIED_SAVED` canonical/generated/coverage receipts, reconciles C0003FC-030 through C0003FC-033/C0003FC-037/C0003FC-039 as checked/applied, keeps only lifecycle-neutral C0003FC-041 unchecked/proposed, and removes hard-coded authoritative-path wording. The validator-owned history footer and paired inert companion remain byte-unchanged; the report lease is released immediately after final readback.

## Implementation Tracking Checklist

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C0003FC-001 | 0003FC | Keep UID0003FC at exact half-open range [0x00593cf0,0x00593dad). | very high | 72 bounded instruction heads terminate at `retn 0x1c`; exact CC fences begin outside the interval. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / address metadata and Item Summary | incorporate | applied |
| [x] | C0003FC-002 | 0003FC | Record the target as 189 bytes with SHA256 7D11CC7DD7E195A284EAFFDF7DEAACADF05A891E81844EAD0154A04A1D1E1009. | very high | Independent physical PE slice receipt over the exact 189-byte interval. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / Item Summary and Evidence | incorporate | applied |
| [x] | C0003FC-003 | 0003FC | Preserve eleven CC bytes at [0x00593ce5,0x00593cf0) and three CC bytes at [0x00593dad,0x00593db0). | very high | Live item boundaries and separate pre-pad/post-pad PE hashes. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / Range and Boundary Evidence | incorporate | applied |
| [x] | C0003FC-004 | 0003FC | Record the dated pre-Gate2B IDA baseline at 0x00593cf0 as code with no function, name, type, or comments, explicitly superseded by final canonical state. | very high | Historical PRE-02 through PRE-05 establish the baseline; final verifier session `supervisor_uid0003fc_verify_20260822_0718` proves the exact accepted function/name/type/comments now persist canonically. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / IDA Status; supervisor Gate 2B PRE-02 through PRE-05 and final canonical receipt | incorporate | applied |
| [x] | C0003FC-005 | 0003FC | Classify the raw ABI as bool __thiscall with TextEditPane in ECX, seven stack arguments, and retn 0x1c. | very high | Complete bounded disassembly independently maps the ECX receiver, `[ebp+8]` through `[ebp+0x20]`, and callee cleanup; exact post-A04 `stack_frame` argument rows corroborate the seven typed arguments but expose no locals. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / ABI and Item Summary; `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| [x] | C0003FC-006 | 0003FC | Name the seven source parameters line, format, text, textOffset, charCount, segmentFlags, and state. | high | Disassembly stack-slot use, sibling callback parity, UDT member accesses, and the exact post-A04 typed argument readback support the names/types; the pre-type two-row result is not argument evidence. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / ABI; `RECONSTRUCTION_CPP CODE` signature | incorporate | applied |
| [x] | C0003FC-007 | 0003FC | Preserve bit 0 as has-next-segment, bit 1 as has-previous-segment, reset for flags <= 1, and finalization when bit 0 is clear. | very high | Exact flag tests at `0x00593cf6`, `0x00593d2e`, and `0x00593d84` plus cdecl sibling parity. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / Behavior and `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| [x] | C0003FC-008 | 0003FC | Preserve TextRunMeasureState as 12 bytes with availableWidth +0, remainingWidth +4, and reset-only scratch +8. | high | Target and cdecl sibling accesses cover only three dwords; historical PRE-05 confirmed absence, and final POST-01/POST-13 plus canonical verifier confirm the exact 12-byte UDT is applied. | `by-class/TextEditPane.md` [UID:0000EO] / state declaration in `RECONSTRUCTION_H CODE`; target Behavior | incorporate | applied |
| [x] | C0003FC-009 | 0003FC | Preserve TextRunFormatData::object +8 and embedded-object advance from TextEditObject::m_payload1 +0x10. | very high | Live UDT offsets and object-branch instructions at `0x00593d15-0x00593d25`. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / Behavior and `RECONSTRUCTION_CPP CODE`; `by-class/TextEditObject.md` [UID:0000EN] / access prose | incorporate | applied |
| [x] | C0003FC-010 | 0003FC | Invoke the visible-count helper only for final non-object segments before plain or masked measurement. | very high | Exact branch and call at `0x00593d27-0x00593d48`; the pre-callback formal body omitted it; the implemented target now contains the call. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| [x] | C0003FC-011 | 0003FC | Reclassify 0x004baad0 as the receiver-independent GrafPort member AdjustVisibleCountForTrailingWhitespace. | very high | All four callers load a TextEditPane/GrafPort receiver into ECX; helper uses two stack arguments and `retn 8`. | `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md` [UID:00016C] / Item Summary and `RECONSTRUCTION_CPP CODE`; `by-class/GrafPort.md` [UID:00005V] / method inventory | incorporate | applied |
| [x] | C0003FC-012 | 0003FC | Type 0x004baad0 as unsigned short __thiscall GrafPort member over const wchar_t * and signed short count, preserving its observed terminal comparison. | very high | Signed word load, low-word returns, caller `movzx eax, ax`, four receiver calls, and full helper body. | `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md` [UID:00016C] / `RECONSTRUCTION_CPP CODE`; `by-class/GrafPort.md` [UID:00005V] / `RECONSTRUCTION_H CODE`; Gate 2B A08 | incorporate | applied |
| [x] | C0003FC-013 | 0003FC | Preserve masked measurement as visibleCount times GetTextWidth(L"*", 1). | very high | Mask byte `TextEditPane+0x16a`, wildcard literal xref, width call, sign extension, and multiply. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / Behavior and `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| [x] | C0003FC-014 | 0003FC | Preserve plain measurement as GetTextWidth(text, visibleCount). | very high | Direct plain branch at `0x00593d6e-0x00593d77` with typed GrafPort callee. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / Behavior and `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| [x] | C0003FC-015 | 0003FC | Subtract run width, clamp negative remaining width to zero only on final segments, store line +8, and clear line word +0x0c. | very high | Exact update sequence `0x00593d7a-0x00593d9e` and live `TextEditLineRecord` offsets. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / Item Summary, Behavior, and `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| [x] | C0003FC-016 | 0003FC | Preserve unused textOffset and unconditional false return. | very high | No instruction reads `[ebp+0x14]`; epilogue is `xor al, al` then `retn 0x1c`. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / ABI and `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| [x] | C0003FC-017 | 0003FC | Record zero direct start xrefs, zero immediate hits, and zero little-endian VA pointer-pattern hits for 0x00593cf0. | very high | Bounded live xref/immediate checks and physical `F0 3C 59 00` search; sibling positive controls succeed. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / Direct Xrefs and Reachability | incorporate | applied |
| [x] | C0003FC-018 | 0003FC | Classify the body as a source-authored compiler-retained private member, not a callback thunk or compiler helper. | high | Full authored algorithm, class receiver/fields, member cleanup, zero forwarding, and neighboring raw members. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / Item Summary and Identity | incorporate | applied |
| [x] | C0003FC-019 | 0003FC | Use source-facing name TextEditPane::MeasureTextRunSegment with the exact seven-argument member signature. | high | Existing class declaration, physical source order, exact ABI, and sibling naming convention. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / `RECONSTRUCTION_CPP CODE`; `by-class/TextEditPane.md` [UID:0000EO] / private method declaration in `RECONSTRUCTION_H CODE`; Gate 2B A03-A04 | incorporate | applied |
| [x] | C0003FC-020 | 0003FC | Preserve direct class owner/emitter UID0000EO and source file UID0000ON at NexusTK/ui/controls/TextEditPane.cpp. | very high | TextEditPane field access, neighboring unit order, class declaration, and generated emitter route. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / parent metadata; `by-class/TextEditPane.md` [UID:0000EO] / ownership; `by-file/TextEditPane.md` [UID:0000ON] / source placement | already-present | applied |
| [x] | C0003FC-021 | 0003FC | Preserve UID0001JQ as the separate cdecl iterator callback with four address-taking routes. | very high | Modeled `[0x00593c20,0x00593ce5)` function and four positive immediate/pointer controls. | `by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md` [UID:0001JQ] / ABI, Xrefs, and Item Summary | already-present | applied |
| [x] | C0003FC-022 | 0003FC | Change UID0001JQ's helper call to pane->AdjustVisibleCountForTrailingWhitespace without changing its ABI or other behavior. | very high | Call at `0x00593c72` establishes pane in ECX and passes the same two stack arguments. | `by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md` [UID:0001JQ] / `RECONSTRUCTION_CPP CODE` and helper-route prose | incorporate | applied |
| [x] | C0003FC-023 | 0003FC | Change UID0001JR's helper call to pane->AdjustVisibleCountForTrailingWhitespace without changing its ABI or other behavior. | very high | Calls at `0x00593ed4` and `0x00594019` establish pane in ECX; draw ABI/body remain independent. | `by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md` [UID:0001JR] / `RECONSTRUCTION_CPP CODE` and helper-route prose | incorporate | applied |
| [x] | C0003FC-024 | 0003FC | Preserve raw DrawTextRunSegment at [0x00593f00,0x0059403b) as corroborating member-ABI evidence, not an additional target. | high | Raw sibling has member receiver shape and helper route but is separately documented and not declared as coverage. | `by-memory/0x00593f00-0x0059403b.DrawTextRunCallbackThiscallRaw.md` [UID:0003FD] / `Status`, `Function`, `IDA Evidence`, `Ownership Decision`, `Reconstruction Notes`, and `Cross-References` support-evidence prose; this report / `Target` declaration | incorporate | applied |
| [x] | C0003FC-025 | 0003FC | Emit the corrected GrafPort member definition in UID00016C and its declaration once in UID00005V H. | very high | Helper lies in GrafPort method corridor and the pre-callback generated static source was cross-unit inaccessible; command `000000026355` now emits the member route. | `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md` [UID:00016C] / `RECONSTRUCTION_CPP CODE`; `by-class/GrafPort.md` [UID:00005V] / `RECONSTRUCTION_H CODE` | incorporate | applied |
| [x] | C0003FC-026 | 0003FC | Add friend class TextEditPane to UID0000EN so raw TextEditPane members legally access protected TextEditObject payload fields. | high | Formal target and raw member siblings read protected payload dwords; public-field weakening is unnecessary. | `by-class/TextEditObject.md` [UID:0000EN] / `RECONSTRUCTION_H CODE` friendship and access prose | incorporate | applied |
| [x] | C0003FC-027 | 0003FC | Replace UID0003FC formal CPP with the complete source block in Section 22. | very high | Formal block mirrors all 72 instructions and restores the missing final-segment helper call. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| [x] | C0003FC-028 | 0003FC | Keep UID0003FC formal H blank because UID0000EO already owns the one class declaration. | very high | Existing `TextEditPane` private declaration is canonical; a child H block would duplicate it. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / blank `RECONSTRUCTION_H CODE`; `by-class/TextEditPane.md` [UID:0000EO] / canonical declaration | already-present | applied |
| [x] | C0003FC-029 | 0003FC | Retain scratch as the conservative descriptive +8 field name after exhaustive zero-only-use review. | high | Target and cdecl sibling only zero the field; generated/report searches reveal no stronger use. | `by-class/TextEditPane.md` [UID:0000EO] / `TextRunMeasureState` declaration and type prose | already-present | applied |
| [x] | C0003FC-030 | 0003FC | Define one IDA function exactly at [0x00593cf0,0x00593dad) only after byte/item/boundary preconditions pass. | very high | Final transaction `UID0003FC-20260822-071358557` passed exact PRE boundaries, A02, POST-02 through POST-05, and canonical verifier readback of the one `0xbd` function with both CC fences excluded. | Supervisor Gate 2B / Section 21 A02 and POST-02 through POST-05; final `APPLIED_VERIFIED_SAVED` receipt | incorporate | applied |
| [x] | C0003FC-031 | 0003FC | Rename, type, and comment the defined target exactly as specified in Section 21. | very high | Final canonical verifier read back exact A03-A06 name/signature/comments, POST-07/POST-08 type/prototype, and POST-09 metadata-plus-seven-typed-argument frame with no local rows. | Supervisor Gate 2B / Section 21 A03-A06 and POST-06 through POST-12; final `APPLIED_VERIFIED_SAVED` receipt | incorporate | applied |
| [x] | C0003FC-032 | 0003FC | Rename, retype, and comment 0x004baad0 as the GrafPort member specified in Section 21. | very high | Final canonical verifier read back exact A07-A10 helper name/signature/comments, four-row frame, four callers, size `0x42`, and no helper callees. | Supervisor Gate 2B / Section 21 A07-A10 and POST-06 through POST-12; final `APPLIED_VERIFIED_SAVED` receipt | incorporate | applied |
| [x] | C0003FC-033 | 0003FC | Preserve target bytes, padding, xrefs, sibling entities, local labels, public frame metadata, disassembly-proven ABI, and all unrelated IDA state. | very high | Final transaction and independent canonical verifier passed P01-P06, unchanged bytes/hashes/ranges/routes, exact post-type frames/types/comments/UDT/callees, and final physical canonical receipt `143211145` / `F5941D0C032A4022F5C59633EA4BFE740ADCD508CE726619E9C5219C3D567DD2`. | Supervisor Gate 2B / Section 21 P01-P06 and final transaction/verifier/rollback/persistence receipts | incorporate | applied |
| [x] | C0003FC-034 | 0003FC | Replace stale target summary/history with the exact range, ABI, source identity, helper route, fields, and behavior. | very high | The pre-callback page omitted the final helper and overstated callback identity; the implemented page closes both from live evidence. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / Item Summary, General Documentation, and dated Change History | historicalize | applied |
| [x] | C0003FC-035 | 0003FC | Reconcile UID0001JQ, UID0001JR, UID00016C, UID00005V, UID0000EN, UID0000EO, and UID0000ON support prose. | high | The accepted pre-callback formal/generated comparison identified exact linkage, access, declaration, ownership, and ordering dependencies; current docs and generated output implement them. | `by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md` [UID:0001JQ] / `Callback ABI And State Layout`, `Evidence Notes`, `Reconstruction Notes`, `Ownership Notes`, `Cross-References`, and `Changes`; `by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md` [UID:0001JR] / `Evidence Notes`, `Callback ABI, State, And Source Shape`, `First-Draft C++ Behavior Notes`, `Reconstruction Notes`, `Cross-References`, and `Changes`; `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md` [UID:00016C] / `Covered Functions`, `Evidence Notes`, `Ownership Notes`, `Reconstruction Notes`, `Cross-References`, and `Changes`; `by-class/GrafPort.md` [UID:00005V] / `Class Purpose`, `Method Notes`, `Evidence Notes`, `Cross-References`, and `Changes`; `by-class/TextEditObject.md` [UID:0000EN] / `Class Purpose`, `Observed State`, `Method Families`, `Evidence Notes`, `Cross-References`, and `Changes`; `by-class/TextEditPane.md` [UID:0000EO] / `Source Placement And Rejected Owners`, `C++ Declaration Policy`, `Method Families`, `Raw Callback And Support Boundaries`, `Evidence Notes`, `Current Caveats`, and `Changes`; `by-file/TextEditPane.md` [UID:0000ON] / `File Role`, `Proposed Contents`, `Source Emission Policy`, `Ownership Decision`, `Evidence Notes`, `Current Caveats`, and `Changes` | incorporate | applied |
| [x] | C0003FC-036 | 0003FC | Preserve the refreshed single-emitter support-class H routing: canonical UID0000EN, UID0000EP, and UID00004H definitions each emit once, with no UID0000EO aggregate-removal edit. | high | Command `000000026355` TextEditPane H has exactly one TextEditObject definition at line 171, one TextEditScrap definition at line 212, and one EPFTextEditObject definition at line 560; the earlier duplicate conclusion remains superseded. | `by-class/TextEditPane.md` [UID:0000EO] / aggregate `RECONSTRUCTION_H CODE` no-change; canonical child H channels `by-class/TextEditObject.md` [UID:0000EN], `by-class/TextEditScrap.md` [UID:0000EP], and `by-class/EPFTextEditObject.md` [UID:00004H] | already-present | applied |
| [x] | C0003FC-037 | 0003FC | Independently regenerate or adopt a fresh coherent refresh and physically reread TextEditPane CPP/H and GrafPort CPP/H during supervisor verification. | very high | Supervisor scoped commands `000000026435`-`000000026443` and owner refresh `000000026444` passed; physical command-26443/26444 CPP/H reread reproduced the target/helper/member/declaration/friendship/single-definition topology and exact hashes in Current Target State. | Validator-owned `auto-generated/NexusTK/ui/controls/TextEditPane.cpp`, `auto-generated/NexusTK/ui/controls/TextEditPane.h`, `auto-generated/NexusTK/render/GrafPort.cpp`, and `auto-generated/NexusTK/render/GrafPort.h` / final supervisor physical refresh and semantic readback | incorporate | applied |
| [x] | C0003FC-038 | 0003FC | Raise UID0003FC to 92/93, UID00016C to 90/93, UID00005V to 89/92, UID0001JQ to 91/94, and UID0001JR to 92/94; keep 94/94 parents unchanged. | high | Exact range/ABI/behavior/source closure and bounded residual lexical/compiler uncertainty; broader parents retain their independent caps. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC], `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md` [UID:00016C], `by-class/GrafPort.md` [UID:00005V], `by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md` [UID:0001JQ], and `by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md` [UID:0001JR] / `COMPLETION`, `CONFIDENCE`, `RECONSTRUCTABLE`, and `Score Rationale`; explicitly preserve `by-class/TextEditObject.md` [UID:0000EN], `by-class/TextEditPane.md` [UID:0000EO], and `by-file/TextEditPane.md` [UID:0000ON] at unchanged 94/94 with their reconstructable metadata and score rationale unchanged | incorporate | applied |
| [x] | C0003FC-039 | 0003FC | Apply the exact supervisor-owned manual coverage insert/replacements from Section 28 only after ordinary validation. | very high | Supervisor applied all six literal rows in the required positions; commands `000000026445` and `000000026446` passed, and read-only reconciliation confirms the exact rows remain physically present. | `by-memory/-coverage-report.md` / UID00016C, UID0001JQ, UID0003FC, UID0001JR rows; `by-class/-coverage-report.md` / UID00005V and UID0000EN rows | incorporate | applied |
| [x] | C0003FC-040 | 0003FC | Create no split, merge, new UID, new source file, or alternate owner for this report. | very high | Exact fences, stable primary UID, class/file owner route, and separately documented siblings close every split/ownership alternative. | `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md` [UID:0003FC] / identity, parent metadata, and source placement | not-applicable | applied |
| [ ] | C0003FC-041 | 0003FC | Keep execution/archive state external to ordinary report prose and determined only from this report's current physical path plus validator-owned history; require exact moved-artifact audit and keep the inert companion beside the report through every movement. | very high | Gate 2A, generated verification, coverage, and canonical Gate 2B have exact historical receipts; lifecycle state remains path-and-validator-history authoritative, and report/companion adjacency must be verified rather than inferred. | This report / current physical path plus validator-owned history; paired inert companion / physical adjacency and relative-link verification after movement | incorporate | proposed |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000026447","destination_path":"executed-b-agent-research/B003/0003FC-TextRunMeasureCallbackThiscallRaw-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0003FC-TextRunMeasureCallbackThiscallRaw-source-quality.md","timestamp":"2026-08-22T07:18:57-04:00","uid":"0003FC"} -->
<!-- {"agent":"B003","command_id":"000000026448","destination_path":"tools/leaser/Agents/Agent-B003/research/0003FC-TextRunMeasureCallbackThiscallRaw-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B003/0003FC-TextRunMeasureCallbackThiscallRaw-source-quality.md","timestamp":"2026-08-22T07:20:26-04:00","uid":"0003FC"} -->
<!-- {"agent":"B003","command_id":"000000026449","destination_path":"executed-b-agent-research/B003/0003FC-TextRunMeasureCallbackThiscallRaw-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0003FC-TextRunMeasureCallbackThiscallRaw-source-quality.md","timestamp":"2026-08-22T07:35:38-04:00","uid":"0003FC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
