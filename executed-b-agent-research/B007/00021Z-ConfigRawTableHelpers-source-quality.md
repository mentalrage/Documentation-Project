** TARGET-REPORT-UID:00021Z **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00021Z ConfigRawTableHelpers Source-Quality Research

Agent: B007  
Assignment: report-only research for [UID:00021Z] `by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md`; implementation callback applied 2026-06-26  
Required output: `tools/leaser/Agents/Agent-B007/research/00021Z-ConfigRawTableHelpers-source-quality.md`  
Workflow: project `ntk-b-agent-workflow` skill. Report-only pass made no by-* edits; the 2026-06-26 supervisor-accepted implementation callback updated the target/support by-* docs listed below.

## Final Recommendation

Implement the target/support documentation update on callback. Do not keep the prior "blank C++ because no caller/original-name proof" conclusion as the final state. The current MCP and local PE evidence still prove that `0x0048e310` and `0x0048e410` have no IDA function objects and no direct inbound route, but that is now a score cap, not a source-reconstruction blocker: both bodies are complete function-shaped Config methods, the owner/emitter route is stable, the fixed table layout is now defensible, and `g_pApplication + 0x858` has current selected-server-name proof.

Recommended target metadata:

| Field | Current | Recommended | Reason |
| --- | ---: | ---: | --- |
| `COMPLETION` | `85` | `88` | Adds current 2026-06-26 MCP evidence, fixes the local-buffer width, resolves the row-table start/count layout, and supplies first-draft helper C++ instead of leaving the code block blank. |
| `CONFIDENCE` | `88` | `90` | Function-route/original-name uncertainty remains, but owner, bounds, unique signatures, no-route proof, table layout, and `g_pApplication + 0x858` meaning now align. |
| `CANONICAL_OWNER` | `0000IE` | unchanged | Config file remains the only valid source/emitter route. |
| `RECONSTRUCTABLE` | `TRUE` | unchanged | These are source-authored Config helper bodies, not padding or runtime code. |
| `EMITTER_UIDS` | `0000IE` | unchanged | Emit with Config support if callback accepts the C++ block. |
| Split | one mixed raw helper page | keep one page | Two complete helpers plus internal `0xcc` padding share owner, table layout, and support evidence. A split would duplicate the same no-route caveat without improving reconstruction quality. |

The implementation callback should update:

- Target: `by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md`.
- Support: `by-class/Config.md`, `by-file/Config.md`, and `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`.
- Optional support refresh, only if supervisor wants the new MCP timestamp recorded there: `by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md` and `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md`.
- Do not edit generated files, project-level reports, validator/tool state, IDA DB, `by-memory/-coverage-report.md`, or any other `-coverage-report.md`.

## Current MCP Proof

MCP was available and mandatory evidence was collected from session `80de0a67`.

- `server_health`: status `ok`, module `NexusTK.exe`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready.
- `lookup_funcs`: `0x0048e310`, `0x0048e408`, `0x0048e410`, and `0x0048e479` are still `Not a function`; neighbor `0x0048e2b0` is `sub_48E2B0` size `0x55`; neighbor `0x0048e480` is `sub_48E480` size `0x28`.
- `xrefs_to`: zero direct xrefs to `0x0048e310`, `0x0048e408`, `0x0048e410`, and `0x0048e479`; `0x0048e480` has two data xrefs and `0x0048e2b0` has three xrefs, so the no-xref condition is specific to this raw island.
- `xref_query` inbound-only: zero code xrefs and zero data xrefs to `0x0048e310` and `0x0048e410`.
- `get_bytes`: `0x0048e305-0x0048e310` is eleven `0xcc` bytes before the first prologue; `0x0048e408-0x0048e410` is eight `0xcc` bytes; `0x0048e479-0x0048e480` is seven `0xcc` bytes before `sub_48E480`.
- `make_signature_for_range`: unique signatures for the full `0x0048e310-0x0048e479` island and for each helper subrange.
- `find_bytes`: VA/RVA pointer patterns for both raw starts are absent: `10 E3 48 00`, `10 E3 08 00`, `10 E4 48 00`, and `10 E4 08 00` all return zero matches.
- Read-only PE scan of executable `.text` from the MCP-reported input path found zero direct `E8`/`E9` relative call/jump destinations to `0x0048e310` or `0x0048e410`.

One broad `insn_query` operand scan partially timed out and is not used as decisive proof. The no-route conclusion rests on inbound MCP xrefs, pointer-byte MCP searches, and the local PE direct-call/jump scan.

## Helper Body Findings

### `0x0048e310-0x0048e408`

This is a `thiscall`/`ecx` Config helper that returns a row index.

Key instructions:

- `0x48e323 lea eax, [ebp-54h]`, `0x48e328 push 28h`, `0x48e32e call sub_5A2DA0`: clears `0x28` bytes, which is 40 bytes or 20 UTF-16 characters. The current target/support text saying "40-wide-character local buffer" is wrong and should become "20-wide-character / 40-byte local buffer".
- `0x48e333 mov edx, [esi+28D9D4h]`: reads the active row count.
- `0x48e346 mov eax, dword ptr unk_67AB1C`, `0x48e351 add eax, 858h`: reads `g_pApplication + 0x858`.
- `0x48e34b lea ebx, [esi+208h]` and `0x48e363 lea ecx, [ebx-202h]`: first row compares text at Config `+0x6` and `+0x208`, then advances by stride `0x6894`.
- `0x48e3eb lea eax, [edx+1]`, `0x48e3f0 mov [esi+28D9D4h], eax`: appends one row only when no existing row matches.
- Return value is `edi`, the found or appended row index.

Behavior:

1. Clear a 20-wide-character local empty string.
2. If `m_fixedConfigRowCount <= 0`, skip search, set count to `count + 1`, and return index `0`.
3. Iterate active rows.
4. Match only when row lookup text equals the empty local string and row server text equals `g_pApplication->currentServerName`.
5. If no match, increment active count and return the first appended index.

The best source-facing name remains `FindOrAppendFixedConfigTableRow`. It is descriptive rather than original-symbol proof, but it is now good enough for report-level C++ because it describes the exact search/append behavior.

### `0x0048e410-0x0048e479`

This is a `thiscall`/`ecx` Config helper with no return value.

Key instructions:

- `0x48e412 lea edx, [ecx+206h]`, `0x48e418 mov esi, 64h`: starts from the first row's server header and loops 100 rows.
- `0x48e425 mov [edx-202h], ax`: clears row base `+0x0000`.
- `0x48e431 mov [edx], ax`: clears row `+0x0202`.
- `0x48e434 movups xmmword ptr [edx+202h], xmm0` and `0x48e43b mov [edx+212h], eax`: clears a 20-byte row state block at row `+0x0404`.
- Inner `0x14` loop clears 20 UTF-16 values at row `+0x1840` and 20 UTF-16 values at row `+0x4068`.
- `0x48e465 mov [edx+668Eh], edi`: clears trailing dword at row `+0x6890`.
- `0x48e46b add edx, 6894h`: advances one row.

The best source-facing name remains `ResetFixedConfigTableRows`.

## Fixed Table Layout Resolution

The fixed table starts at `Config + 0x4`, not at the `0x206`/`0x208` cursor used by the raw instructions. With row base defined as `this + 0x4 + index * 0x6894`, the reset and lookup offsets line up cleanly.

`int_convert.py` was used for base conversions:

- `0x6894` = 26772 decimal row stride.
- `0x64` = 100 rows.
- `0x28d9d0` = 2677200 bytes = 100 rows * stride.
- `0x28d9d4` = 2677204 bytes = row table start `+0x4` plus 100 rows, so the count sits immediately after the 100-row slab.
- `0x858` = 2136 decimal Application offset.
- `0x28` = 40 bytes = 20 UTF-16 characters.

Recommended descriptive layout names:

| Row offset | Width | Evidence | Recommended name |
| ---: | ---: | --- | --- |
| `+0x0000` | word | reset helper clears it | `lookupKey.header` |
| `+0x0002` | 256 UTF-16 chars | lookup helper compares from `this + 0x6` | `lookupKey.text` |
| `+0x0202` | word | reset helper clears it | `serverName.header` |
| `+0x0204` | 256 UTF-16 chars | lookup helper compares from `this + 0x208` | `serverName.text` |
| `+0x0404` | 20 bytes | `xorps`/`movups` plus dword clear | `stateBlock` |
| `+0x1840` | 20 UTF-16 values | inner reset loop | `wideValueSetA` |
| `+0x4068` | 20 UTF-16 values | inner reset loop | `wideValueSetB` |
| `+0x6890` | dword | trailing dword clear before next stride | `trailingStateValue` |

Recommended support declarations for `by-class/Config.md` if the callback accepts method-body C++:

```cpp
struct ConfigFixedTableText
{
    unsigned short header;
    wchar_t text[256];
};

struct ConfigFixedTableRow
{
    ConfigFixedTableText lookupKey;
    ConfigFixedTableText serverName;
    unsigned char stateBlock[0x14];
    unsigned char reserved0[0x1428];
    wchar_t wideValueSetA[20];
    unsigned char reserved1[0x2800];
    wchar_t wideValueSetB[20];
    unsigned char reserved2[0x2800];
    int trailingStateValue;
};
```

Recommended `Config` field prose:

- `m_fixedConfigRows[100]` starts at object offset `+0x4`.
- `m_fixedConfigRowCount` is the active count at object offset `+0x28d9d4`.
- The first text key is only known behaviorally as the empty lookup key. Do not rename it as a character, account, profile, or registry field without independent proof.
- The second text key is server-name text because it is compared against `g_pApplication + 0x858`.

## `g_pApplication + 0x858` Resolution

The target should stop using active `dword_67AB1C + 0x858` wording except as IDA label context. The source-facing expression should be `g_pApplication->currentServerName` or the already documented equivalent `selectedServerNameDisplay`.

Current MCP proof:

- `xrefs_to 0x0067ab1c` includes the target read at `0x48e346`.
- Application constructor disassembly at `0x4635f2-0x463603` copies wide literal `TestServer` into `this + 0x858` with `_wcscpy_s(..., 0x100, ...)`.
- `xrefs_to 0x00612788` returns exactly one data xref, `0x4635f8` in `Application__Constructor`; `get_bytes 0x00612788` returns UTF-16 `TestServer`.
- ServerSelect raw apply helper `0x574570` reads `g_pApplication`, adds `0x858`, and formats the selected entry name into that 256-wide-character buffer.
- ServerSelect draw helper `0x574670` has the same selected-row write path at `0x5746ca-0x5746df`.
- Existing `by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md`, `by-memory/0x00573d20-0x005747df.ServerSelectPane.md`, and `by-class/ServerSelectMenuItemList.md` already record this field as `currentServerName[256]` / `selectedServerNameDisplay`.

This resolves the field-meaning blocker. Exact original member spelling is still not recovered, but that is a naming caveat, not a reason to leave the Config helper C++ blank.

## Recommended Formal Target C++ Block

Use this only with the support layout names above. If the supervisor accepts this report, the implementation callback should replace the target's formal C++ block with the exact text below and remove the old no-code rationale.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int Config::FindOrAppendFixedConfigTableRow()
{
    wchar_t emptyLookupKey[20];
    memset(emptyLookupKey, 0, sizeof(emptyLookupKey));

    int rowCount = m_fixedConfigRowCount;
    int rowIndex = 0;

    if (rowCount > 0)
    {
        ConfigFixedTableRow *row = m_fixedConfigRows;
        const wchar_t *currentServerName = g_pApplication->currentServerName;

        do
        {
            if (wcscmp(row->lookupKey.text, emptyLookupKey) == 0 &&
                wcscmp(row->serverName.text, currentServerName) == 0)
            {
                return rowIndex;
            }

            ++rowIndex;
            ++row;
            rowCount = m_fixedConfigRowCount;
        }
        while (rowIndex < rowCount);
    }

    m_fixedConfigRowCount = rowCount + 1;
    return rowIndex;
}

void Config::ResetFixedConfigTableRows()
{
    for (int rowIndex = 0; rowIndex < 100; ++rowIndex)
    {
        ConfigFixedTableRow &row = m_fixedConfigRows[rowIndex];

        row.lookupKey.header = 0;
        row.serverName.header = 0;
        memset(row.stateBlock, 0, sizeof(row.stateBlock));

        for (int valueIndex = 0; valueIndex < 20; ++valueIndex)
        {
            row.wideValueSetA[valueIndex] = 0;
            row.wideValueSetB[valueIndex] = 0;
        }

        row.trailingStateValue = 0;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Notes on this block:

- The `memset(emptyLookupKey, 0, 0x28)` shape is intentional and matches the `sub_5A2DA0` call.
- The row-count reload inside the loop mirrors the assembly reload at `0x48e3dd`. A simpler `for (rowIndex < m_fixedConfigRowCount)` source form may also compile similarly, but the recommended block keeps the observed reload explicit.
- The helper names remain descriptive. There is still no original-symbol proof.
- No direct caller route was recovered. That should stay in the evidence and score rationale, but it no longer blocks first-draft C++ because the bodies are self-contained Config methods and the required table/application fields are now named at report-level detail.

## Rejected Routes

- Padding: rejected by two executable helper bodies, prologues/epilogues, unique range signatures, and Config field semantics.
- Preceding collection-dialog ownership: rejected by the eleven-byte `0xcc` boundary after `0x0048e305` and by Config object access.
- Following config-entry initializer ownership: rejected by the seven-byte `0xcc` boundary before `0x0048e480` and by separate `sub_48E480` function modeling.
- RegistryConfig ownership: rejected because the helpers operate on the base Config fixed table before adjacent ConfigEntry/Registry defaults ranges.
- No-owner/non-emitting: rejected because target and parent clear the current code gate, the owner/emitter is stable, and method behavior is reconstructable.
- Keeping C++ blank solely because no caller route exists: rejected for this pass. The no-route fact caps score and must remain documented, but it does not invalidate the source-authored method bodies.

## Implementation Callback Checklist

Checked during the 2026-06-26 supervisor-accepted implementation callback.

- [x] Lease only the immediate edit files required by the accepted report details. Proof: leased exactly `by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md`, `by-class/Config.md`, `by-file/Config.md`, and `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md` as `B007` immediately before the edit/validator batch.
- [x] Update `by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md` with the score, summary, 20-wide-character correction, current MCP evidence, fixed table layout, `g_pApplication + 0x858` wording, C++ block, and revised score rationale. Proof: target metadata is now `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter unchanged; item summary, evidence, fixed-table layout, source-reconstruction notes, score rationale, and change log now record the 20-wide-character / 40-byte local buffer, row slab at `Config + 0x4`, stride `0x6894`, 100 rows, count at `+0x28d9d4`, row-field meanings, `g_pApplication->currentServerName` / `selectedServerNameDisplay`, and no-route evidence as a score cap. The accepted formal `RECONSTRUCTION_CPP CODE` block was inserted exactly in the target's formal block.
- [x] Update `by-class/Config.md` with the fixed table start/count/row layout and remove the stale "C++ bodies remain blocked" sentence if C++ is accepted. Proof: class formal block now includes accepted `ConfigFixedTableText` and `ConfigFixedTableRow` support declarations; the field/layout notes now document `m_fixedConfigRows[100]` at `+0x4`, `m_fixedConfigRowCount` at `+0x28d9d4`, row stride `0x6894`, row fields, corrected local-buffer width, accepted helper C++ readiness, and the no-route/original-name caveat as a score cap.
- [x] Update `by-file/Config.md` so the file-level row no longer says the helpers are C++-blank pending caller/name proof. Proof: proposed contents, IDA MCP evidence, B012 source-quality summary, and change log now state that [UID:00021Z] emits accepted first-draft C++ and that the missing direct route/original-name proof caps score rather than blocking C++.
- [x] Update `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md` with the fixed table row slab and count field if supervisor accepts support synchronization. Proof: Known Field Clusters now includes `+0x0004..+0x28d9d3` and `+0x28d9d4` for the fixed row slab/count, 100 rows, stride `0x6894`, descriptive row fields, and the accepted `currentServerName` comparison; change log records the B007 support sync.
- [x] Optionally add a short B007 MCP refresh note to Application/g_pApplication support docs without changing their existing ownership or C++. Proof: intentionally not edited because `by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md` already records `+0x858` as `currentServerName[256]` / `selectedServerNameDisplay`, and `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md` already records `this + 0x858` initialized to `TestServer`. Existing detail is same-or-greater for this callback.
- [x] Do not edit generated files, project-level reports, validator/tool state, IDA DB, `by-memory/-coverage-report.md`, or any other `-coverage-report.md`. Proof: no manual edits were made to those files. Scoped validators reported validator-owned side effects including `projected_stats_update`, autogen registry/reference updates, and deferred generated refresh metadata; no generated/coverage/project-level/tool-state file was hand-edited.
- [x] Run the required validator batch after edits. Proof: all commands ran from `source-3/project-documentation` and exited `0` with `ok: 1`:
  - `python .\tools\validator.py --mode file --file by-memory\0x0048e310-0x0048e479.ConfigRawTableHelpers.md --apply --queue-timeout 240` -> command_id `000000002172`, timestamp `2026-06-26T03:01:56-04:00`, `ok: 1`, exit `0`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-class\Config.md --apply --queue-timeout 240` -> command_id `000000002173`, timestamp `2026-06-26T03:02:03-04:00`, `ok: 1`, exit `0`, `generated_refresh: deferred`; existing `missing_ref_uid 0003FU` diagnostics remain.
  - `python .\tools\validator.py --mode file --file by-file\Config.md --apply --queue-timeout 240` -> command_id `000000002174`, timestamp `2026-06-26T03:02:15-04:00`, `ok: 1`, exit `0`, `generated_refresh: deferred`; existing `missing_ref_uid 0003FU` diagnostics remain.
  - `python .\tools\validator.py --mode file --file by-memory\0x0067a7c8-0x0067a7cc.g_pConfig.md --apply --queue-timeout 240` -> command_id `000000002175`, timestamp `2026-06-26T03:02:28-04:00`, `ok: 1`, exit `0`, `generated_refresh: deferred`; existing `missing_ref_uid 0003UA` / `0003UJ` diagnostics remain.
  - Follow-up `python .\tools\validator.py --queue-status` -> command_id `000000002177`, timestamp `2026-06-26T03:04:33-04:00`, exit `0`; queued generated refresh jobs `0`, processing generated refresh jobs `0`.
  - Generated-output freshness proof: `auto-generated/NexusTK/config/Config.cpp` header now has `validator-command-id: 000000002175`, `validator-refreshed-at: 2026-06-26T03:02:28-04:00`, and contains `ConfigFixedTableRow`, `Config::FindOrAppendFixedConfigTableRow`, and `Config::ResetFixedConfigTableRows`.
- [x] Release leases immediately after the validator batch. Proof: `python .\tools\leaser\leaser.py B007 unlease ...` succeeded for all four leased files; follow-up read of `tools/leaser/Agents/current_leases.md` found no active `B007` lease and no active lease rows for the four implementation files.
- [x] Check this implementation checklist with proof before returning `FINISHED_IMPLEMENTATION`. Proof: this checklist was updated after the edit, validator, and lease-release batch with concrete file/section, validator command, optional-exclusion, and release evidence.

## Report-Only Checklist

- [x] Read and followed `Agent-B007/goal.md`.
- [x] Used the project `ntk-b-agent-workflow` skill and required references.
- [x] Used IDA MCP successfully; did not produce a fallback-only report.
- [x] Did not spawn subagents.
- [x] Did not edit target/support by-* docs during the report-only pass.
- [x] Did not edit generated files, project-level files, validator/tool state, IDA DB, `by-memory/-coverage-report.md`, or any other `-coverage-report.md`.
- [x] Resolved the local-buffer width, fixed table layout, `g_pApplication + 0x858` meaning, helper naming, and C++ blank-block blocker into an implementation-ready plan.
- [x] Created only the required report file for this pass.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/00021Z-ConfigRawTableHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/00021Z-ConfigRawTableHelpers-source-quality.md","timestamp":"2026-06-26T03:06:41","uid":"00021Z"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
