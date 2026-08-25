** TARGET-REPORT-UID:00027S **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00027S NcauthConfirmUserUrlObfuscated Advanced-Scan Pass

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00027S][0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated](../../../../../by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md) as a reconstructable source-declared data item owned and emitted by [UID:0000LG][MiscWorkThread](../../../../../by-file/MiscWorkThread.md).
- Final disposition: the Advanced-Error-Scan finding was a real scanner-visible body-label gap, not an ownership, emitter, range, split, merge, or generated-name problem.
- Required action: no shared `by-memory/-coverage-report.md` edit is required. The target page was repaired in scope and validated.
- Confidence: 94/100 for the recommendation; target page score remains `82/88`.

## Supporting Research

## Target

- Target UID: `00027S`
- Target path: `by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md`
- Source queue/report row: `auto-generated/by-memory-tool-report.md` Advanced-Error-Scan, `missing document text for NcauthConfirmUserUrlObfuscated`
- Current supervisor classification: assigned to Agent-B002 in `tools/leaser/Agents/Supervisor_notes.md` on 2026-06-14.
- Current scores and parent state: `COMPLETION:82`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000LG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LG`, C++ blank.

## Executive Recommendation

Keep the current owner/emitter route. The range is a single source-declared static data item: a bitwise-not encoded fallback URL format string used by the NCA auth/update worker. The strongest direct source owner is `MiscWorkThread`, because all semantic data refs are inside `ProcessNCAUpdate` at `0x00527bb0`, and the current [UID:0000LG][MiscWorkThread](../../../../../by-file/MiscWorkThread.md) file page is `86/85`, clearing the strict parent gate.

No split is needed. The exact URL object occupies `0x0066de30-0x0066de6c`; the next item, [UID:00027T][0x0066de6c-0x0066deb0.NcauthUrlToTableSentinelPadding](../../../../../by-memory/0x0066de6c-0x0066deb0.NcauthUrlToTableSentinelPadding.md), is already a separate ignored padding page. No reconstruction C++ should be entered because this page is `82/88` and the original constant spelling and source-level obfuscation choice remain below the active 90/90+ code-entry gate.

## Supervisor Active Recheck

The supervisor assignment asked B002 to determine whether the advanced-scan finding was a real documentation gap, stale filename/label, owner/emitter/range issue, generated-name issue, or harmless scanner wording issue.

Result:

- Real documentation gap: yes, narrow scanner-visible label gap. The exact filename label `NcauthConfirmUserUrlObfuscated` was absent from the body before ignored/change sections.
- Stale filename/label: no. The filename label is accurate and now explicitly documented.
- Owner/emitter issue: no. `0000LG` remains correct and currently clears `86/85`.
- Range issue: no. Live IDA and raw PE both confirm `0x0066de30-0x0066de6c`.
- Split/merge issue: no. Successor padding is already split as `00027T`.
- Generated-name issue: no. `NcauthConfirmUserUrlObfuscated` is a human descriptive name, not a generated/decompiler placeholder.

## Inference Research Guidance Check

`inference_research.md` cautions that address adjacency is weaker than xrefs and data-flow. I used adjacency only for boundaries. Ownership is inferred from the direct semantic reader/decode/WinInet path, the paired override string page, the `MiscWorkThread` aggregate docs, and the current parent file score. Existing docs were treated as leads until current IDA MCP and raw PE evidence confirmed the byte layout, xrefs, decoded string, and padding boundary.

IDA facts:

- Exact bytes and range.
- Xrefs and containing function.
- Decompiled override/fallback/decode behavior.
- Padding and next-object boundaries.

Documentation evidence:

- Existing target page, `MiscWorkThread` file page, `MiscWorkThreadAndNotifications`, `MainMenuTextUrlStaticString`, and successor padding page.

Inference:

- The original source likely had a private `MiscWorkThread.cpp` NCA fallback URL constant, but the final source spelling and whether the source authored encoded bytes or a plain literal remain unresolved.

## Evidence Standards Used

Evidence used:

- IDA MCP `idb_list` and `server_health`.
- IDA MCP `get_bytes` for the target and adjacent ranges.
- IDA MCP `xref_query` for `0x0066de18`, `0x0066de30`, `0x0066de31`, `0x0066de6b`, `0x0066de6c`, and `0x0066deb0`.
- IDA MCP `lookup_funcs` for `0x00527bb0`, xref sites, nearby data starts, `0x00528310`, and the registration caller area.
- IDA MCP `decompile` and `disasm` for `0x00527bb0`.
- IDA MCP `find_bytes` and `make_signature_for_range`.
- Raw PE section/offset/byte decoding from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Current by-* and generated coverage documentation.

This is strong enough for the owner/emitter and scanner repair. It is not enough for final C++ because source spelling and the source-level encoded/plain-literal choice remain unresolved.

## IDA MCP Facts

Session facts:

- Session: `b001_0003gy`
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- Auto-analysis and Hex-Rays: ready.

Function/range facts:

- `0x00527bb0` is `sub_527BB0`, size `0x2f4`, documented as `ProcessNCAUpdate`.
- `0x00527ca3` and `0x00527d40` are inside `sub_527BB0`.
- `0x0066de30`, `0x0066de6c`, and `0x0066deb0` are data addresses, not functions.
- `0x00528310` is `sub_528310`, the request wrapper family documented under `MiscWorkThread`.
- `0x0053015f` falls inside `sub_530060`, the registration/NCA caller context, not the owner of this storage.

Data facts:

```text
0x0066de30-0x0066de6c:
97 8b 8b 8f c5 d0 d0 92 9e 96 93 d1 91 9a 87 90
91 9c 93 8a 9d d1 9c 90 92 d0 9c 93 8a 9d 9e 9b
92 96 91 d0 9c 90 91 99 96 8d 92 8a 8c 9a 8d c0
b6 bb c2 da 8c d9 af a8 c2 da 8c ff
```

`make_signature_for_range 0x0066de30-0x0066de6c` returned the same 60-byte sequence and reported it as unique.

Decoded by bitwise-not:

```text
http://mail.nexonclub.com/clubadmin/confirmuser?ID=%s&PW=%s\0
```

Boundary facts:

- `0x0066de18-0x0066de30` is the previous `g_metaAliasTableName` static `SimpleUString`.
- `0x0066de6c-0x0066deb0` is 68 zero bytes.
- `0x0066deb0` starts the next monster/riding fallback record.

Xref facts:

| Target | IDA MCP xrefs | Meaning |
| --- | --- | --- |
| `0x0066de18` | six refs from MetaMan/static init/cleanup contexts | Previous object, separate owner. |
| `0x0066de30` | `0x00527ca3`, `0x00527d40` inside `sub_527BB0` | URL object base and scalar decode loop. |
| `0x0066de31` | none | Interior byte has no separate owner/route. |
| `0x0066de6b` | none | Encoded NUL byte, not an independent item. |
| `0x0066de6c` | none | Successor padding has no direct refs. |
| `0x0066deb0` | `0x00528b2f`, `0x00528d11` | Next object starts after the padding. |

Decompiler facts for `0x00527bb0`:

```c
if ( sub_584CF0(&dword_69B3D0) ) {
    v7 = (const char *)sub_584540(&dword_69B3D0);
    strcpy_s(szUrl, 0x100u, v7);
} else {
    v9 = strlen(byte_66DE30);
    ...
    LOBYTE(v8) = ~byte_66DE30[v10]; /*0x527d46*/
    Format[v10] = (char)v8;         /*0x527d48*/
    ...
    Format[v9] = 0;                 /*0x527d6d*/
    ...
    sub_443A00(szUrl, 0x100u, Format, v14); /*0x527dba*/
}
v15 = InternetOpenUrlA(v3, szUrl, Locale, 0, 0, 0); /*0x527dfe*/
```

Disassembly facts:

- `0x00527c71` checks override string `dword_69B3D0`.
- `0x00527ca3` loads `offset byte_66DE30`.
- `0x00527d40` reads `byte_66DE30[eax]`.
- `0x00527d46` applies `not cl`.
- `0x00527d48` stores the decoded byte into the format buffer.

Negative IDA facts:

- No direct refs to `0x0066de6c`, so the target does not extend into successor padding.
- No refs to the interior encoded NUL at `0x0066de6b`, so it is part of the URL object, not a separate data item.
- No data refs from registration-dialog code directly to `0x0066de30`; registration queues NCA work through `MiscWorkThread`.

## Raw PE Facts

Raw-file check:

- File: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Section: `.data`
- VA `0x0066de30` maps to raw offset `0x26ba30`
- VA `0x0066de6c` maps to raw offset `0x26ba6c`
- VA `0x0066deb0` maps to raw offset `0x26bab0`

Raw bytes at `0x26ba30` match the IDA MCP bytes exactly. Bitwise-not decoding gives the confirm-user URL plus NUL. The range `0x0066de6c-0x0066deb0` is all zero bytes. The next 16 bytes at `0x0066deb0` are:

```text
00 00 00 00 FF 00 FF FF 00 00 00 00 58 3A 5C 00
```

Raw pattern counts:

| Pattern | Count | Raw offsets |
| --- | ---: | --- |
| 60-byte encoded URL | 1 | `0x26ba30` |
| Little-endian `0x0066de30` | 3 | `0x1270a4`, `0x1270e5`, `0x127142` |
| Little-endian `0x0066de6c` | 0 | none |
| Little-endian `0x0066deb0` | 2 | `0x127f30`, `0x128112` |

The extra raw occurrence of `0x0066de30` beyond IDA's two direct xrefs is in the optimized/vectorized fallback decode code emitted inside the same function. It does not create a separate consumer or owner.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0066de18-0x0066de30` | [UID:0001OL][g_metaAliasTableName](../../../../../by-memory/0x0066de18-0x0066de30.g_metaAliasTableName.md) | Previous static `SimpleUString` | TRUE | `0000LC` | `82/strong` | Separate MetaMan object. |
| `0x0066de30-0x0066de6c` | [UID:00027S][NcauthConfirmUserUrlObfuscated](../../../../../by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md) | This encoded fallback URL | TRUE | `0000LG` | `82/88` | Keep owner/emitter; repaired scanner body text. |
| `0x0066de6c-0x0066deb0` | [UID:00027T][NcauthUrlToTableSentinelPadding](../../../../../by-memory/0x0066de6c-0x0066deb0.NcauthUrlToTableSentinelPadding.md) | Zero padding | FALSE | NONE | `100/92` | Existing split remains correct. |
| `0x0066deb0-0x0066debc` | [UID:00027U][MonsterImageLibDefaultFrameRecord](../../../../../by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md) | Next source data record | TRUE | `0000LK` | `82/strong` | Separate successor owner. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00527ca3 -> 0x0066de30` | `mov edx, offset byte_66DE30` | Fallback URL object base in `ProcessNCAUpdate`. |
| `0x00527d40 -> 0x0066de30` | `mov cl, byte_66DE30[eax]` | Scalar byte decode loop. |
| `0x00527c71/0x00527c7f -> 0x0069b3d0` | override string checks | Same worker uses packet override URL before fallback. |
| `0x00527dfe` | `InternetOpenUrlA` | Worker opens the constructed URL. |
| `0x0053015f -> 0x00528310` | registration/NCA request path | Registration is caller/producer context, not the URL storage owner. |
| `0x00528b2f`, `0x00528d11 -> 0x0066deb0` | next table refs | Confirms successor object after padding. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:00027S][target page](../../../../../by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md) already documented decoded URL, range, `MiscWorkThread` ownership, fallback role, and final-C++ blocker.
- [UID:0000LG][MiscWorkThread](../../../../../by-file/MiscWorkThread.md) is now `86/85`, has valid `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/"`, and lists the NCA worker family among likely contents.
- [UID:0001CJ][MiscWorkThreadAndNotifications](../../../../../by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md) documents `0x00527bb0-0x00527ea4` as `ProcessNCAUpdate`, owner `0000LG`, score `84/88`.
- [UID:00029T][MainMenuTextUrlStaticString](../../../../../by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md) documents the packet override string and the fallback to this target in the same worker.
- [UID:00027T][NcauthUrlToTableSentinelPadding](../../../../../by-memory/0x0066de6c-0x0066deb0.NcauthUrlToTableSentinelPadding.md) documents the successor padding and no-xref boundary.

Existing docs repaired:

- The target body omitted the exact filename label `NcauthConfirmUserUrlObfuscated`.
- The target used legacy `Autogen parent` wording.
- The target's source-placement sentence still cited `MiscWorkThread` as `86/84`; current file page is `86/85`.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` already lists `00027S` as emitting through owner/emitter `0000LG` into `auto-generated/NexusTK/app/MiscWorkThread.cpp`.
- `by-memory/-coverage-report.md` already has an accurate row for `00027S`; no supervisor replacement is needed.

## Ranked Ownership Analysis

### 1. [UID:0000LG] MiscWorkThread

Evidence for:

- All direct semantic xrefs to `0x0066de30` are inside `ProcessNCAUpdate` at `0x00527bb0`.
- The same helper checks the override URL string first, decodes this fallback string only when the override is empty, formats the account/password URL, and calls `InternetOpenUrlA`.
- `MiscWorkThread` owns the NCA worker helper and notification posting family.
- Current `MiscWorkThread` file page is `86/85`, clearing the strict direct-parent gate.
- The current generated coverage report routes `00027S` to `auto-generated/NexusTK/app/MiscWorkThread.cpp`.

Evidence against:

- Final source path and exact private constant spelling are still provisional.
- It is not yet proven whether the original source authored encoded bytes or a plain literal transformed by build/code.

Decision:

- Accept. The evidence strongly supports `CANONICAL_OWNER:0000LG` and `EMITTER_UIDS:0000LG`; keep final C++ blank.

### 2. [UID:00009I] NexonclubRegistrationDialog / [UID:0000M0] NexonclubRegistrationDialog file

Evidence for:

- Registration/NCA UI code submits account/password strings and triggers the worker request.
- `0x0053015f` sits in the registration helper/caller path.

Evidence against:

- Registration code does not directly reference `0x0066de30`.
- Registration consumes notification states after the worker finishes; it does not build or own the fallback URL storage.
- Moving the literal to registration would split it away from the decode/open/parse behavior.

Decision:

- Reject as direct owner. Keep as caller/consumer context only.

### 3. [UID:00029T] MainMenuTextUrlStaticString / packet writer pages

Evidence for:

- The same worker checks `0x0069b3d0` before falling back to this literal.
- MainMenuPane and MapPane packet handlers write the override string.

Evidence against:

- Packet writers provide runtime override state; they do not own the hardcoded fallback literal.
- The sole semantic reader of both override and fallback is `ProcessNCAUpdate` under `MiscWorkThread`.

Decision:

- Reject as direct owner. The override string remains a related `MiscWorkThread` item, and packet writers remain producer contexts.

### 4. New file/grouping

Proposed owner/name/path:

- Not recommended. A hypothetical `Ncauth.cpp` or `NexonClubAuth.cpp` would be too speculative.

Likely full contents if such a file existed:

- `ProcessNCAUpdate`, NCA request wrapper, `ncauth::Notification`, this fallback URL, and the override string.

Candidate related items that belong:

- These are already coherently grouped under `MiscWorkThread`.

Candidate related items rejected:

- Registration dialog helpers are UI callers, not the auth worker implementation.

Standalone, narrow, or broad source-file inference:

- No new file should be created from this target. The current broad source-file inference is `app/MiscWorkThread.cpp`.

## Negative Evidence Summary

- No xrefs to `0x0066de6c`; the URL does not include successor padding.
- No xrefs to `0x0066deb0` from the NCA worker; successor table data belongs to a different owner.
- No direct refs from registration dialog code to `0x0066de30`; the UI is not the storage owner.
- No generated-name pattern appears in `NcauthConfirmUserUrlObfuscated`.
- No evidence supports splitting the URL bytes from their encoded terminator; the worker decodes the encoded NUL byte and then writes an additional terminator.
- Address adjacency to `g_metaAliasTableName` and monster/riding table data is only layout evidence, not source ownership.

## Final Recommendation

Exact changes applied:

- Edited [UID:00027S][0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated](../../../../../by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md).
- Added scanner-visible `NcauthConfirmUserUrlObfuscated` body text.
- Updated `Autogen parent` wording to current canonical owner/emitter language.
- Corrected the parent score reference to `86/85`.
- Added current B002 live IDA MCP and raw PE evidence.

Exact parent assignments applied or recommended:

- Keep `CANONICAL_OWNER:0000LG`.
- Keep `EMITTER_UIDS:0000LG`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `RECONSTRUCTION_CPP CODE` blank.
- Keep scores `82/88`.

Exact items left no-owner/non-emitting:

- None in this target. The adjacent padding page `00027T` correctly remains `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and emitterless, but it is assigned to B003 and was not edited here.

Future work outside this assignment:

- A later source-reconstruction pass can name the private constant and decide whether final C++ should preserve encoded storage or use a decoded literal, but only after the active 90/90+ code-entry gate is met.

## Follow-Up Actions

Supervisor actions:

- No `by-memory/-coverage-report.md` replacement is needed for `00027S`.
- If regenerating `auto-generated/by-memory-tool-report.md`, the `NcauthConfirmUserUrlObfuscated` advanced-scan warning should clear because the exact label now appears in the target body.

A-agent actions:

- None required for this target.

B002 future research actions:

- None for this assigned item.

## Confidence

- Recommendation confidence: 94/100.
- Score confidence: target score remains `82/88`; no score increase was applied because this was a label/evidence repair, not a final reconstruction audit.
- Remaining uncertainty: original source constant name and source-level obfuscation style are still unresolved, which blocks final C++ despite strong owner/range evidence.

## Validator Results

Command run without dry run:

> Executable block R001 was removed from this report and preserved verbatim in [00027S-NcauthConfirmUserUrlObfuscated-advanced-scan-removed.md](00027S-NcauthConfirmUserUrlObfuscated-advanced-scan-removed.md). The archived block is non-authoritative and must not be executed.

Result summary:

- `apply: True`
- `scanned markdown files: 1`
- `ok: 1`
- `autogen_registry_rebuild: 1`
- `autogen_report_noop: 7`
- `projected_stats_update: 1`
- `stats_incremental_noop 00027S project-level/-auto-completion-stats.md file is not present in generated stats lists`
- Pre-existing broad notice: `autogen_emitter_has_no_code 00000D by-class/Application.md emitting children only`; unrelated to this target.

Generated report state:

- `auto-generated/-ag-class-coverage.md`: unchanged.
- `auto-generated/-ag-file-coverage.md`: unchanged.
- `auto-generated/-ag-function-coverage.md`: unchanged.
- `auto-generated/-ag-global-coverage.md`: unchanged.
- `auto-generated/-ag-item-coverage.md`: unchanged.
- `auto-generated/-ag-memory-coverage.md`: unchanged.
- `auto-generated/-ag-type-coverage.md`: unchanged.

## Lease State

- Leased target page as `B002` before editing.
- Released target page after validation.
- Final lease check showed no active B002 leases. Other agents had unrelated active leases.

## Supervisor-Owned Shared-Report Text

No shared-report edit is required. Keep the existing `by-memory/-coverage-report.md` row for `00027S` exactly as:

```text
    - [UID:00027S][0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated](by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md) 0x0066de30-0x0066de6c | obfuscated URL format string | NcauthConfirmUserUrlObfuscated : reconstructable : 82% : strong : Bitwise-not encoded NCA confirm-user fallback URL attached to MiscWorkThread, with exact 59-byte decoded literal plus terminator, predecessor/successor boundaries, ProcessNCAUpdate xrefs, URL override-slot distinction, registration consumer context, source-declared rebuild handling, and final-C++ gate documented.
```

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/00027S-NcauthConfirmUserUrlObfuscated-advanced-scan.md`
- Modified: `by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md`
- Validator-managed side effect reported: `project-level/-auto-completion-stats.md` projected path completion section updated.
- Not modified: `by-memory/-coverage-report.md`
- Not modified: generated `auto-generated/-ag-*` reports, all reported unchanged.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00027S-NcauthConfirmUserUrlObfuscated-advanced-scan.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00027S"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00027S-NcauthConfirmUserUrlObfuscated-advanced-scan-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00027S-NcauthConfirmUserUrlObfuscated-advanced-scan.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00027S"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
