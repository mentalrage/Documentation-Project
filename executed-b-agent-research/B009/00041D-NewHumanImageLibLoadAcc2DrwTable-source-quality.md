** TARGET-REPORT-UID:00041D **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# B009 Research Report: UID00041D NewHumanImageLibLoadAcc2DrwTable

## Scope And Callback Status

- Agent: B009
- Assignment: `B009-report-00041D-NewHumanImageLibLoadAcc2DrwTable-direct-research-20260630`
- Target: [UID:00041D] `by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md`
- Mode: report-first research, followed by supervisor-accepted implementation callback for UID00041D.
- Initial report-only pass edited no by-* documentation, generated output, validator/tool state, IDA database, supervisor ledger, executed archive, lease, or lock file.
- During the accepted implementation callback, B009 applied the accepted UID00041D target/support doc changes listed below. Generated C++ and project-state outputs were refreshed only by validators, not by manual edits.
- This bookkeeping rework re-read the current target/support docs; no accepted by-* edit was missing, so no new by-* lease, by-* edit, or by-* validator run was needed in this rework pass.
- No subagents were spawned.

## Current Target State

At the initial report pass, the target page remained below gate:

- `COMPLETION: 84`
- `CONFIDENCE: 86`
- `CANONICAL_OWNER: NONE`
- `RECONSTRUCTABLE: TRUE`
- `EMITTER_UIDS:` blank
- `RECONSTRUCTION_CPP:` blank

The pre-callback page already described the key behavior: open `acc2drw.tbl`, reset the accessory-to-draw vector end pointer, derive a row count from the part table, parse decimal lines, split hundreds/tens/ones into three flags, append 3-byte rows through `VectorGrowAcc2Drw`, and show `Error on ACC2DRW table!` on failure. This report finds that the old no-owner/no-code disposition is stale, and the accepted callback implements the class-owned source body.

## Required Search Results

I searched current by-* docs, generated reports, executed B-agent reports, and active Agent-B009 notes for:

- `00041D`
- `004e1800`
- `004e19c5`
- `NewHumanImageLibLoadAcc2DrwTable`
- `LoadAcc2DrwTable`
- `acc2drw.tbl`
- `VectorGrowAcc2Drw`
- adjacent `NewHumanImageLib` helper names

Relevant matches:

- `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md` calls `LoadAcc2DrwTable(L"acc2drw.tbl")` from the constructor and already belongs to [UID:000092] `NewHumanImageLib`.
- `by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md` currently documents [UID:00041E] as the 3-byte vector grow helper, called only from UID00041D at `0x004e195a`.
- At report intake, `by-class/NewHumanImageLib.md`, `by-file/NewHumanImageLib.md`, and `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md` still described UID00041D as remaining below-gate support. The callback proof below verifies that this stale wording has now been superseded in current support docs.
- `by-type/by-struct/NewHumanImageLibLayout.md` now accepts the `Acc2DrwEntry` row concept and the `m_acc2drwEntries` vector span at offsets `+0x48`, `+0x4c`, and `+0x50`.
- `by-resource/new-human-motion-tables.md` identifies `acc2drw.tbl` as a resource-derived table in `char.dat`, entry index 0, offset 922, size 2,580, with ASCII/CRLF flag rows.
- Executed B011 constructor research created UID00041D/UID00041E as below-gate support pages and named the then-active blocker: promotion should wait until `Acc2DrwEntry` and vector helper declarations were synchronized.
- Executed B010 destructor and B014 composition-bounds research now provide the missing downstream synchronization: generated C++ already uses `m_acc2drwEntries` and `m_acc2drwEntries[state.acc2drwSelector].enabled[0..2]`.
- Executed B002/B006 reports for adjacent promoted loaders (`LoadMotionTable`, `LoadLayerTable`) establish the current project pattern for promoting NewHumanImageLib table loaders to class-owned emitting methods while vector-growth helpers are treated as support/source-disposition items rather than class-method bodies.
- Agent-B010's supervisor-accepted report for [UID:00041E] recommends promoting `VectorGrowAcc2Drw` to [UID:0000LR] NewHumanImageLib file-owned marker-only support at `86/90`, with no standalone helper body. This B009 report must coordinate with that accepted direction: UID00041D should describe UID00041E as the full-capacity vector-growth marker/support path if the B010 implementation lands, not as permanently below-gate support.

There are unrelated old TimerMgr UID collisions in executed report archives using `00041D`/`00041E`; they are rejected because their names, paths, and addresses do not match this target.

## IDA MCP Evidence

IDA MCP was available and responding.

- Endpoint: `http://127.0.0.1:13337/mcp`
- MCP server: `ida-pro-mcp` `1.0.0`
- Active database/session: `supervisor_resume_20260629`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Input path reported by server health: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- Auto-analysis ready: true
- Hex-Rays ready: true
- Strings cache ready: true

Narrow schema-current MCP calls used: `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `callees`, `analyze_function`, `decompile`, `disasm`, `entity_query`, `get_string`, `get_bytes`, and `xref_query`.

Function and range evidence:

- `lookup_funcs(0x004e1800)` returns `sub_4E1800`, size `0x1c5`.
- `0x1c5` converts to decimal 453. Verified with `int_convert.py`.
- `lookup_funcs(0x004e19c5)` returns no function.
- `get_bytes(0x004e19c5, 16)` shows eleven `0xcc` padding bytes followed by the next function prologue at `0x004e19d0`.
- `lookup_funcs(0x004e19d0)` returns `sub_4E19D0`, size `0x557`.

Caller/callee evidence:

- `xrefs_to(0x004e1800)` returns one code xref, at `0x004e0188` in constructor `sub_4DFD10`.
- `xrefs_to(0x0061c324)` returns one constructor data xref at `0x004e0181`; raw bytes decode as `acc2drw.tbl`, followed by `.DSC` and `%s.EPF`.
- `xrefs_to(0x004e4f10)` returns one code xref, at `0x004e195a` in `sub_4E1800`.
- `callees(0x004e1800)` includes `sub_49C130`, `sub_49C180`, `sub_49C370`, `sub_5CEA6D`, `sub_4E4F10`, `sub_49C240`, `sub_49C160`, `sub_467380`, `sub_4673A0`, `MessageBoxW`, and `__loaddll`.

Hex-Rays/body evidence from `analyze_function(0x004e1800)`:

- Raw prototype: `int __thiscall(_DWORD *this, wchar_t *ArgList)`.
- The function constructs/opens a DAT file object with the incoming wide table name.
- It clears the vector by assigning `this[19] = this[18]`, i.e. end equals begin for the vector at class offset `+0x48`.
- It reads the loop count from `*(_DWORD *)(this[1] + 528)`.
- `0x210` converts to decimal 528. Verified with `int_convert.py`.
- The current layout makes this `m_partEntries[7].descriptorCount`: `0x210 = 7 * 0x44 + 0x34`; `0x44` converts to 68 and `0x34` converts to 52. Both conversions were verified with `int_convert.py`.
- It calls the DAT line reader with a 4096-byte buffer. `0x1000` converts to 4096. Verified with `int_convert.py`.
- If `ReadLine(...) <= 1`, it executes the fatal cleanup path.
- It parses each line with `sub_5CEA6D`, matching the project's decimal parser naming as `ParseUnsignedLongBase10`.
- It derives three bytes:
  - `(flags % 1000) / 100 != 0`
  - `(flags % 100) / 10 != 0`
  - `(flags % 10) != 0`
- If vector end equals capacity, it calls `sub_4E4F10`; otherwise it writes two bytes plus one byte directly and advances the vector end by 3.
- It closes/destructs the DAT file object at normal exit.

Fatal string evidence:

- `get_bytes(0x0061bfe0, 52)` decodes as UTF-16LE `Error on ACC2DRW table!`.
- `xrefs_to(0x0061bfe0)` includes the target reference at `0x004e19b1` and an older HumanImageLib constructor reference at `0x004d4a9e`.
- `get_bytes(0x00612598, 14)` decodes as UTF-16LE `Error`.
- `xrefs_to(0x00612598)` includes the target reference at `0x004e19ac`.
- Disassembly shows `push 30h` before `MessageBoxW`; `0x30` converts to decimal 48. Verified with `int_convert.py`; this is source-level `MB_ICONEXCLAMATION`.

## Negative Evidence Summary

Negative checks that affect ownership, source placement, and split decisions:

- MCP `xrefs_to(0x004e1800)` found exactly one code caller, the NewHumanImageLib constructor at `0x004e0188`; no non-NewHuman, generic vector, UI, resource, or HumanImageLib caller was found for the target body.
- MCP `xrefs_to(0x0061c324)` found exactly one constructor data xref for the `acc2drw.tbl` literal; no alternate table-loader owner or shared literal route was found.
- MCP `lookup_funcs(0x004e19c5)` found no function at the target end, and `get_bytes(0x004e19c5, 16)` showed only `0xcc` padding before the next prologue; there is no evidence that UID00041D should absorb the successor or split a child at its tail.
- MCP `lookup_funcs(0x004e19d0)` and `xrefs_to(0x004e19d0)` show the successor is a distinct function with separate constructor/`LoadPartTable` references; it is not part of the `LoadAcc2DrwTable` body.
- MCP `xrefs_to(0x004e4f10)` found the [UID:00041E] helper call only from UID00041D; this proves a dependency/support route, not ownership of UID00041D by the vector helper.
- No target-local vtable, global, resource-table owner, or cross-module source route was found inside UID00041D. The only external resource evidence is the constructor-passed table filename.
- The older HumanImageLib reference to the `Error on ACC2DRW table!` string is a shared fatal-message/string reuse signal only; it does not create HumanImageLib ownership for this NewHumanImageLib method.
- IDA's string renderer returned a misleading short string at `0x0061c324`, so raw bytes were decoded directly before using the table literal as evidence.

## Ownership And Source Placement

Recommended owner:

- `CANONICAL_OWNER: 000092`
- `EMITTER_UIDS: 000092`

Rationale:

- The function is a `thiscall` method on the same object as the constructor and NewHumanImageLib class pages.
- The only code caller is the NewHumanImageLib constructor at `0x004e0188`.
- The constructor passes the literal `L"acc2drw.tbl"` at `0x0061c324`.
- The body reads `m_partEntries` and writes `m_acc2drwEntries`, both accepted NewHumanImageLib layout members.
- The destructor and composition-bounds pages now consume the same vector under NewHumanImageLib source names.
- The source emitter should be the class owner [UID:000092], routed through file owner [UID:0000LR] `NexusTK/render/NewHumanImageLib.cpp`.

Rejected placements:

- `CANONICAL_OWNER: NONE`: stale. The former blocker was the missing synchronized `Acc2DrwEntry`/vector context, and that context now exists.
- `by-file`-only ownership: too coarse. The function has class method semantics and class-member state.
- `by-resource/new-human-motion-tables.md` ownership: the resource page owns payload provenance, not the loader method implementation.
- `by-file/VectorHelpers.md` ownership: UID00041E is a vector grow helper, but UID00041D is the table loader and belongs with NewHumanImageLib.
- Inlining into constructor: rejected because the binary has a distinct out-of-line call from the constructor to `0x004e1800`.

## Range And Split

The target range is exact.

- Start `0x004e1800` is the function start.
- End `0x004e19c5` is the first byte after the function.
- Padding at `0x004e19c5` leads to the next function at `0x004e19d0`.
- The next function `sub_4E19D0` has separate xrefs from the constructor and `LoadPartTable`; it should not be merged into UID00041D.
- SEH setup, stack cookie checks, and compiler-generated cleanup edges in the disassembly should remain evidence only and should not be modeled as source logic.

## Heuristic And Inference Reanalysis

The important inferred names are now supported by multiple accepted docs:

- `m_acc2drwEntries` is supported by destructor and composition-bounds generated C++.
- `Acc2DrwEntry` is supported by the layout page and the composition consumer that reads `.enabled[0..2]`.
- `m_partEntries[7].descriptorCount` is a source-level expression for the raw load from `partEntriesBegin + 0x210`; the field names are accepted project inferences, not original spelling proof.
- `LoadAcc2DrwTable` is supported by constructor call structure, target behavior, table literal, and adjacent accepted loader naming.

UID00041E coordination: the supervisor has accepted Agent-B010's report for [UID:00041E] as NewHumanImageLib file-owned vector-growth marker/support through [UID:0000LR], marker-only, with no standalone helper body. UID00041D should therefore reference UID00041E as the full-capacity vector-growth marker/support path if that B010 implementation lands. This report does not edit UID00041E, and it does not require a standalone `VectorGrowAcc2Drw` body before promoting UID00041D. The UID00041D loader source should express the append as `m_acc2drwEntries.push_back(entry)`, matching the current source-level pattern used for neighboring NewHumanImageLib table loaders and B010's marker-only helper disposition.

## Recommended Metadata Change

Recommended target page metadata:

- `COMPLETION: 88`
- `CONFIDENCE: 90`
- `CANONICAL_OWNER: 000092`
- `RECONSTRUCTABLE: TRUE`
- `EMITTER_UIDS: 000092`
- `EMITTER_POSITION_OPTIONAL:` blank
- Add formal C++ reconstruction.

Score rationale:

- Raise above gate because direct MCP evidence now ties the exact body, caller, table literal, class member writes, row count, parse logic, fatal string path, and vector append semantics together.
- Do not raise above low 90s because original source spellings for member names and the final `Acc2DrwEntry` declaration remain inferred, and UID00041E's exact original helper/template spelling remains B010-coordinated marker/support rather than a recovered standalone source body.

## Recommended Formal C++

Exact formal `RECONSTRUCTION_CPP CODE` insertion text for [UID:00041D]:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewHumanImageLib::LoadAcc2DrwTable(const wchar_t *tableName)
{
    DATFile acc2drwFile;
    char line[4096];
    const int acc2drwCount = m_partEntries[7].descriptorCount;

    acc2drwFile.Open(tableName);
    m_acc2drwEntries.clear();

    for (int index = 0; index < acc2drwCount; ++index)
    {
        if (acc2drwFile.ReadLine(line, sizeof(line)) <= 1)
        {
            DestroyDATFileMgr();
            DestroyExceptionHandler();
            MessageBoxW(0,
                        L"Error on ACC2DRW table!",
                        L"Error",
                        MB_ICONEXCLAMATION);
            __loaddll(0);
        }

        const int flags = ParseUnsignedLongBase10(line);
        Acc2DrwEntry entry = {};

        entry.enabled[0] = (flags % 1000) / 100 != 0;
        entry.enabled[1] = (flags % 100) / 10 != 0;
        entry.enabled[2] = (flags % 10) != 0;

        m_acc2drwEntries.push_back(entry);
    }

    acc2drwFile.Close();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Implementation notes for the supervisor callback:

- `m_acc2drwEntries.clear()` models the exact binary assignment of vector end to vector begin while preserving storage.
- `m_acc2drwEntries.push_back(entry)` models the direct write plus UID00041E full-capacity growth marker/support split at source level, coordinated with B010's accepted marker-only disposition.
- `__loaddll(0)` matches the existing generated first-draft style for fatal tails; this report does not invent a new wrapper.
- `MB_ICONEXCLAMATION` is the source form for the observed `0x30` `MessageBoxW` flag.

## Support Documentation To Synchronize If Accepted

Recommended callback edits by destination:

- Target path: `by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md`.
  - Metadata/header edits: change `COMPLETION` to `88`, `CONFIDENCE` to `90`, `CANONICAL_OWNER` to `000092`, keep `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:000092`, and keep `EMITTER_POSITION_OPTIONAL` blank.
  - Formal C++ edit: insert the exact formal `RECONSTRUCTION_CPP CODE` block above.
  - Evidence/status edits: add current MCP session facts, exact range/padding, constructor-only caller, table literal, row count source, fatal path, and UID00041E full-capacity growth marker/support coordination.
  - Behavior edits: record `m_partEntries[7].descriptorCount` as the row count source and `Acc2DrwEntry.enabled[0..2]` as the three flags derived from hundreds/tens/ones decimal digits.
  - Score/source-quality edits: explain why the old no-owner/no-code blocker is superseded, why the target is class-owned/emitting, why the score is `88/90`, and why exact original spellings and UID00041E marker/template policy still cap confidence.
  - Rejected alternatives: preserve rejection of no-owner/no-emitter, file-only direct ownership, resource ownership, VectorHelpers ownership, HumanImageLib ownership, constructor inlining, successor merge, and standalone raw vector-helper source.

- Support path: `by-class/NewHumanImageLib.md`.
  - Destination: class method/helper inventory and source-quality notes.
  - Edit: move UID00041D out of the remaining below-gate support group and list it as a class-owned emitting loader at `88/90`, with source route through [UID:0000LR].
  - Edit: record that UID00041D fills `m_acc2drwEntries` with `Acc2DrwEntry.enabled[0..2]` rows and that UID00041E is support/marker-only vector growth if B010 implementation lands.

- Support path: `by-file/NewHumanImageLib.md`.
  - Destination: file source route/helper inventory.
  - Edit: update source-summary text so UID00041D is no longer described as below-gate/no-owner.
  - Edit: state that `LoadAcc2DrwTable` emits through [UID:000092] into `NexusTK/render/NewHumanImageLib.cpp`, while UID00041E is coordinated with B010 as [UID:0000LR] marker-only vector-growth support, not a standalone method body.

- Support path: `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`.
  - Destination: constructor helper-call evidence/support notes.
  - Edit: keep constructor formal C++ unchanged.
  - Edit: replace stale child-support wording that identifies UID00041D as below-gate with a note that UID00041D is recommended for promotion by this B009 report; preserve the constructor call `LoadAcc2DrwTable(L"acc2drw.tbl")`.

- Support path: `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`.
  - Destination: active function table and child range documentation.
  - Edit: update UID00041D row/status to class-owned emitting loader at `88/90`.
  - Edit: preserve the exact range `0x004e1800-0x004e19c5`, note padding before `0x004e19d0`, and remove UID00041D from any "remaining below-gate no-owner" group.
  - Edit: coordinate UID00041E wording with B010 if the local cluster also lists the grow helper.

- Support path: `by-type/by-struct/NewHumanImageLibLayout.md`.
  - Destination: `m_acc2drwEntries` / `Acc2DrwEntry` layout evidence.
  - Edit: reinforce that `Acc2DrwEntry` consists of three boolean-like bytes consumed as `enabled[0]`, `enabled[1]`, and `enabled[2]`.
  - Edit: add UID00041D loader evidence that the bytes are derived from hundreds/tens/ones decimal digits, and that the row count comes from `m_partEntries[7].descriptorCount`.
  - Edit: no metadata change is required unless the supervisor decides the added loader proof raises layout score; this report treats layout as support only.

- Support path: `by-resource/new-human-motion-tables.md`.
  - Destination: `acc2drw.tbl` resource provenance and loader synchronization.
  - Edit: keep payload/resource provenance unchanged.
  - Edit: add loader synchronization noting that UID00041D is recommended as class-owned/emitting `LoadAcc2DrwTable`, consumes `acc2drw.tbl`, and maps each text row into `Acc2DrwEntry.enabled[0..2]`.

- Conditional/deferred support path: `by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md`.
  - Destination: UID00041E target page.
  - Edit owner: defer to Agent-B010/supervisor implementation. Do not edit this page as part of B009 report-only work.
  - Conditional B009 callback edit only if the supervisor explicitly includes it after B010 coordination: ensure UID00041E support text says UID00041D source-level code expresses the full-capacity append as `m_acc2drwEntries.push_back(entry)`, while UID00041E is [UID:0000LR] marker-only vector-growth support with no standalone body.

- Conditional support path: `by-file/VectorHelpers.md`.
  - Destination: vector helper policy page.
  - Optional only because UID00041D does not own VectorHelpers and UID00041E coordination is B010-owned.
  - If supervisor expands scope, add one policy note that UID00041E rejects direct generic VectorHelpers ownership due to sole NewHuman caller and NewHuman-specific 3-byte `Acc2DrwEntry`; otherwise no B009 edit is required.

Validator commands proposed for callback implementation:

> Executable block R001 was removed from this report and preserved verbatim in [00041D-NewHumanImageLibLoadAcc2DrwTable-source-quality-removed.md](00041D-NewHumanImageLibLoadAcc2DrwTable-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Do not run a B009 validator for UID00041E unless the supervisor callback explicitly includes a coordinated B009 support edit after the accepted B010 implementation state is known. B010/supervisor owns UID00041E target implementation and validation.

Generated freshness expectation after callback implementation:

- `auto-generated/NexusTK/render/NewHumanImageLib.cpp` should gain the UID00041D method body.
- The generated header should be newer than validator command id `000000002089` / refreshed after `2026-06-30T01:39:05-04:00`, which was the generated NewHumanImageLib.cpp state observed during this research.
- Generated memory coverage and research tracker outputs should update through the validator; they must not be hand-edited.

## Callback Implementation Proof

Callback disposition: applied. Current target/support docs were re-read during this rework with `Get-Content` and targeted `rg` checks for metadata, C++, MCP provenance, range/padding, constructor caller, `acc2drw.tbl`, `m_partEntries[7].descriptorCount`, `Acc2DrwEntry.enabled[0..2]`, fatal path text, B010/UID00041E coordination, rejected alternatives, and generated output freshness. The current docs contain the accepted facts at same-or-greater detail, so this rework only updates the report bookkeeping.

Changed by-* files from the accepted callback:

- `by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md`
- `by-class/NewHumanImageLib.md`
- `by-file/NewHumanImageLib.md`
- `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`
- `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`
- `by-type/by-struct/NewHumanImageLibLayout.md`
- `by-resource/new-human-motion-tables.md`

Report bookkeeping updated in place:

- `tools/leaser/Agents/Agent-B009/research/00041D-NewHumanImageLibLoadAcc2DrwTable-source-quality.md`

Leases used and released:

- Target lease was used for `by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md` during the target edit/validator batch and was released afterward.
- Support leases were used for the six support docs during support edit/validator batches. B009 waited for overlapping B008/B011 shared-support leases before editing; the final B009 support lease batch covered the six support docs from `2026-06-30T07:41:25Z` to `2026-06-30T07:46:25Z` and was released after validation.
- Current lease report after release: `tools/leaser/Agents/current_leases.md` says `No active leases.`
- No lease was required for this Agent-B009 report-file bookkeeping edit.

Validator results from `E:/NTK/GhidraBridge/source-3/project-documentation`:

| Scope | Command | command_id | command_timestamp | Exit | ok | Generated refresh / notes |
| --- | --- | --- | --- | --- | --- | --- |
| Target | `python .\tools\validator.py --mode file --file by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md --apply --queue-timeout 240 --wait-generated` | `000000002109` | `2026-06-30T03:03:41-04:00` | `0` | `1` | `generated_refresh: completed`; generated refresh command/timestamp matched `000000002109` / `2026-06-30T03:03:41-04:00`. |
| Class support | `python .\tools\validator.py --mode file --file by-class/NewHumanImageLib.md --apply --queue-timeout 240 --wait-generated` | `000000002151` | `2026-06-30T03:41:51-04:00` | `0` | `1` | `generated_refresh: completed`; validator also performed generated metadata/autogen registry/projected-stats updates. |
| File support | `python .\tools\validator.py --mode file --file by-file/NewHumanImageLib.md --apply --queue-timeout 240 --wait-generated` | `000000002153` | `2026-06-30T03:42:08-04:00` | `0` | `1` | `generated_refresh: completed`; validator also performed generated metadata/autogen registry/projected-stats updates. |
| Constructor support | `python .\tools\validator.py --mode file --file by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md --apply --queue-timeout 240` | `000000002154` | `2026-06-30T03:42:33-04:00` | `0` | `1` | `generated_refresh: deferred`. |
| Local-cluster support | `python .\tools\validator.py --mode file --file by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md --apply --queue-timeout 240` | `000000002155` | `2026-06-30T03:42:40-04:00` | `0` | `1` | `generated_refresh: deferred`; unrelated pre-existing `missing_ref_uid 0003UD` warning remains for supervisor/validator lifecycle, not UID00041D content. |
| Layout support | `python .\tools\validator.py --mode file --file by-type/by-struct/NewHumanImageLibLayout.md --apply --queue-timeout 240` | `000000002156` | `2026-06-30T03:42:49-04:00` | `0` | `1` | `generated_refresh: deferred`; validator updated projected stats for by-type reconstructable row. |
| Resource support | `python .\tools\validator.py --mode file --file by-resource/new-human-motion-tables.md --apply --queue-timeout 240` | `000000002157` | `2026-06-30T03:42:58-04:00` | `0` | `1` | `generated_refresh: deferred`; validator updated projected stats for by-resource not-reconstructable row. |
| Final file/generated freshness | `python .\tools\validator.py --mode file --file by-file/NewHumanImageLib.md --apply --queue-timeout 240 --wait-generated` | `000000002158` | `2026-06-30T03:43:19-04:00` | `0` | `1` | `generated_refresh: completed`; generated refresh command/timestamp matched `000000002158` / `2026-06-30T03:43:19-04:00`. |

Generated freshness proof:

- `auto-generated/NexusTK/render/NewHumanImageLib.cpp` header is `validator-command-id: 000000002158`, `validator-refreshed-at: 2026-06-30T03:43:19-04:00`, `validator-refresh-source: foreground-generated-refresh`.
- The generated file contains constructor call `LoadAcc2DrwTable(L"acc2drw.tbl");`, UID00041D method header `Completion:88 | Confidence:90`, `m_partEntries[7].descriptorCount`, fatal text `Error on ACC2DRW table!`, and `entry.enabled[0]`, `entry.enabled[1]`, `entry.enabled[2]`.
- No generated file, coverage report, validator/tool state file, IDA DB, supervisor ledger, executed archive, or lock file was manually edited by B009. Validator side effects were tool-owned refreshes only.

## Open Questions

Resolved for promotion:

- Exact range: resolved by MCP lookup/disassembly and padding bytes.
- Direct caller: resolved; constructor only.
- Table literal: resolved; `acc2drw.tbl` raw UTF-16LE bytes and constructor data xref.
- Row shape: resolved enough for source; three boolean-like bytes consumed by composition bounds.
- Fatal path: resolved; cleanup helpers, message text, caption, icon flag, and `__loaddll(0)` are directly observed.

Still inferential:

- Exact original spellings of `m_acc2drwEntries`, `Acc2DrwEntry`, and `enabled`.
- Exact original container declaration and helper template policy for UID00041E remains B010-scoped; this B009 report only coordinates UID00041D wording with the accepted marker/support direction.

These remaining inferences justify `88/90`, not no-owner/no-code.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID00041D initial report-pass target state was `84/86`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, `RECONSTRUCTABLE:TRUE`, and blank formal C++. | Strong | Target page read during the report pass before callback implementation. | Target Current State / historical baseline | already-present | already-present |
| C02 | IDA MCP was available and used; evidence is not fallback-only. | Strong | `initialize`, `tools/list`, `idb_list`, `server_health` on database `supervisor_resume_20260629`. | Target Evidence / MCP provenance | incorporate | applied |
| C03 | Target range `0x004e1800-0x004e19c5` is exact; `0x004e19c5` is padding before successor `0x004e19d0`. | Strong | MCP `lookup_funcs(0x004e1800)` size `0x1c5`; `lookup_funcs(0x004e19c5)` no function; `get_bytes(0x004e19c5,16)` padding; successor lookup. | Target Range; local cluster active-function row | incorporate | applied |
| C04 | UID00041D has exactly one direct code caller, the NewHumanImageLib constructor at `0x004e0188`. | Strong | MCP `xrefs_to(0x004e1800)`. | Target Caller Evidence; constructor support; class/file support docs | incorporate | applied |
| C05 | Constructor passes the UTF-16LE literal `acc2drw.tbl` from `0x0061c324`; no alternate literal owner was found. | Strong | MCP `xrefs_to(0x0061c324)` one data xref; `get_bytes(0x0061c324,52)` decoded literal. | Target Evidence; constructor support; resource sync | incorporate | applied |
| C06 | The loader clears `m_acc2drwEntries` by assigning vector end to begin before loading rows. | Strong | MCP `analyze_function` and disassembly show `this[19] = this[18]`; layout maps vector begin/end/capacity at `+0x48/+0x4c/+0x50`. | Target Behavior / formal C++; layout support | incorporate | applied |
| C07 | Row count source is `m_partEntries[7].descriptorCount`, modeled from raw `partEntriesBegin + 0x210`. | Strong for offset; medium-high for final field spelling | MCP load from `this[1] + 528`; `0x210`, `0x44`, and `0x34` conversions verified with `int_convert.py`; accepted layout field names. | Target Behavior / formal C++; layout support; score rationale | incorporate | applied |
| C08 | Each input row is parsed through `ParseUnsignedLongBase10` and split into hundreds/tens/ones boolean-like flags. | Strong | MCP `sub_5CEA6D` callee and Hex-Rays arithmetic for `% 1000 / 100`, `% 100 / 10`, and `% 10`. | Target Behavior / formal C++; layout support; resource sync | incorporate | applied |
| C09 | `Acc2DrwEntry.enabled[0..2]` is the correct source-facing row shape for UID00041D. | Strong for three bytes; medium-high for final names | MCP direct write/grow path copies three bytes; [UID:0001VF] layout and [UID:0002V8] composition consumer use `Acc2DrwEntry` and `.enabled[0..2]`. | Target formal C++; layout support; class/file support | incorporate | applied |
| C10 | Fatal short-read path calls `DestroyDATFileMgr`, `DestroyExceptionHandler`, `MessageBoxW(0, L"Error on ACC2DRW table!", L"Error", MB_ICONEXCLAMATION)`, and `__loaddll(0)`. | Strong | MCP disassembly/callees; raw UTF-16LE bytes at `0x0061bfe0` and `0x00612598`; `0x30` verified as decimal 48 with `int_convert.py`. | Target formal C++; Evidence; Rejected Alternatives | incorporate | applied |
| C11 | Full-capacity append path calls [UID:00041E] at `0x004e195a`; source-level UID00041D should use `m_acc2drwEntries.push_back(entry)`. | Strong | MCP `xrefs_to(0x004e4f10)` one caller in UID00041D; `analyze_function` direct call; adjacent loader source pattern; B010 UID00041E marker-only report. | Target formal C++; UID00041E coordination note; class/file/local cluster support | incorporate | applied |
| C12 | UID00041E should be referenced as B010-coordinated NewHumanImageLib file-owned marker/support if its accepted implementation lands, not as permanently below-gate support. | Strong, subject to B010 implementation state | Supervisor rework instruction; Agent-B010 report path `tools/leaser/Agents/Agent-B010/research/00041E-VectorGrowAcc2Drw-source-quality.md`. | Target Evidence/Support Notes; support-doc plan; implementation checklist | incorporate | applied |
| C13 | Direct owner/emitter for UID00041D should be [UID:000092] `NewHumanImageLib`, routed through [UID:0000LR] `NexusTK/render/NewHumanImageLib.cpp`. | Strong | `thiscall` receiver, constructor-only caller, class member reads/writes, accepted constructor/destructor/composition routes. | Target metadata; class/file support docs | incorporate | applied |
| C14 | Resource ownership is rejected: `by-resource/new-human-motion-tables.md` owns payload provenance, not the loader method implementation. | Strong | Resource doc identifies `acc2drw.tbl` payload; MCP shows code method is class member and constructor-called. | Target Rejected Alternatives; resource support sync | incorporate | applied |
| C15 | VectorHelpers ownership is rejected for UID00041D; UID00041E is a dependency/support marker path, not the target owner. | Strong | UID00041D body is class method and owns table-loader semantics; UID00041E call is only full-capacity append support. | Target Rejected Alternatives; optional VectorHelpers note | incorporate | applied |
| C16 | Constructor inlining/merge is rejected because the binary has an out-of-line constructor call to `0x004e1800`. | Strong | MCP `xrefs_to(0x004e1800)` and constructor call site. | Target Rejected Alternatives; constructor support note | incorporate | applied |
| C17 | Successor merge/split is rejected because `0x004e19d0` is a distinct function with separate xrefs. | Strong | MCP successor lookup, padding bytes, and `xrefs_to(0x004e19d0)`. | Target Range / Rejected Alternatives; local cluster support | incorporate | applied |
| C18 | The old B011 no-owner/no-code blocker is superseded, not deleted without context. | Strong | B011 historical report plus current layout/destructor/composition/B010 evidence. | Target historical/stale assumption section; class/file/local cluster support | historicalize | applied |
| C19 | Recommended metadata is `88/90`, `CANONICAL_OWNER:000092`, `EMITTER_UIDS:000092`, `RECONSTRUCTABLE:TRUE`, blank emitter position. | Strong | Claims C02-C18; code-entry gate satisfied with exact formal C++ block. | Target metadata / score rationale | incorporate | applied |
| C20 | Recommended formal C++ is the exact formal `RECONSTRUCTION_CPP CODE` block in this report, not a body-only snippet. | Strong | Current B-agent standard; MCP behavior evidence; source-shape analysis. | Target formal C++ block | incorporate | applied |
| C21 | Support docs to synchronize are target, class, file, constructor, local cluster, layout, and resource pages; UID00041E and VectorHelpers are conditional/deferred coordination items. | Strong | Current support docs read; supervisor rework instruction; B010 report state. | Implementation checklist / support-doc plan | incorporate | applied |
| C22 | Generated files, coverage reports, validator/tool state, IDA DB, supervisor ledgers, executed archives, and lock files must not be hand-edited; refresh comes through validators after callback. | Strong | Assignment and B-agent workflow. | Callback exclusions / generated-file policy | not-applicable | excluded-with-reason |

## Callback Claim Proof

| Claim ID | Callback proof |
| --- | --- |
| C01 | Historical baseline remains in this report's `Current Target State`; current target header now shows the accepted post-callback metadata. |
| C02 | Target `Evidence` section records MCP session `supervisor_resume_20260629`, IDB/module details, narrow calls, and no fallback-only evidence; target validator `000000002109` passed. |
| C03 | Target `Status`/`Evidence` and local-cluster active row record exact `0x004e1800-0x004e19c5` body, padding at `0x004e19c5`, and separate successor `0x004e19d0`; validators `000000002109` and `000000002155` passed. |
| C04 | Target evidence, constructor support, class doc, file doc, and local cluster all record the constructor-only caller at `0x004e0188`; validators `000000002109`, `000000002151`, `000000002153`, `000000002154`, and `000000002155` passed. |
| C05 | Target evidence, constructor support, resource page, class/file docs, and local cluster record `acc2drw.tbl` at `0x0061c324` with constructor xref `0x004e0181`; validators `000000002109`, `000000002154`, and `000000002157` passed. |
| C06 | Target formal C++ and behavior section use `m_acc2drwEntries.clear()`; layout support records vector offsets `+0x48/+0x4c/+0x50`; validators `000000002109` and `000000002156` passed. |
| C07 | Target behavior/formal C++, file support, local cluster, layout, and resource page record `m_partEntries[7].descriptorCount` and raw `0x210 = 7 * 0x44 + 0x34`; validators `000000002109`, `000000002153`, `000000002155`, `000000002156`, and `000000002157` passed. |
| C08 | Target formal C++ and support docs record base-10 parsing and hundreds/tens/ones digit mapping; generated output from command `000000002158` contains the same expressions. |
| C09 | Target formal C++, class/file support, layout, and resource page record `Acc2DrwEntry.enabled[0..2]`; generated output from command `000000002158` contains all three stores. |
| C10 | Target formal C++ and evidence record short-read fatal cleanup, `MessageBoxW`, `Error on ACC2DRW table!`, `Error`, `MB_ICONEXCLAMATION`, and `__loaddll(0)`; generated output from command `000000002158` contains the fatal text. |
| C11 | Target status/formal C++, class/file/local-cluster/layout support, and generated output represent the append as `m_acc2drwEntries.push_back(entry)` while documenting UID00041E as the full-capacity marker/support path. |
| C12 | Target status, class doc, file doc, local cluster, layout, and resource page all coordinate UID00041E with B010 as file-owned marker/support, not permanent below-gate support; B009 did not edit UID00041E. |
| C13 | Target metadata now has `CANONICAL_OWNER:000092` and `EMITTER_UIDS:000092`; class/file docs route emission through [UID:000092] into [UID:0000LR]. |
| C14 | Target rejected alternatives and resource support page preserve the resource/source split: `by-resource/new-human-motion-tables.md` owns payload provenance, not method ownership. |
| C15 | Target rejected alternatives and support docs reject VectorHelpers ownership for UID00041D; `by-file/VectorHelpers.md` was intentionally not edited because the accepted UID00041D callback did not require it. |
| C16 | Target rejected alternatives and constructor support preserve the out-of-line constructor call, so the loader body was not pasted into the constructor page. |
| C17 | Target range/rejected alternatives and local cluster preserve the successor-merge rejection for `0x004e19d0`. |
| C18 | Target score rationale, class/file support, constructor support, local cluster, and resource page historicalize the old B011 below-gate/no-code blocker as superseded. |
| C19 | Target header now has `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:000092`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000092`, and blank `EMITTER_POSITION_OPTIONAL`; validator `000000002109` passed. |
| C20 | Target formal `RECONSTRUCTION_CPP CODE` block contains the exact accepted `NewHumanImageLib::LoadAcc2DrwTable` body with header, BEGIN, and END lines; validator `000000002109` passed. |
| C21 | All accepted target/support docs were edited and validated; UID00041E and VectorHelpers remained conditional/excluded as directed. |
| C22 | No manual generated/coverage/tool-state/IDA/supervisor-ledger/executed-archive/lock edits were made; generated `NewHumanImageLib.cpp` freshness came from validator command `000000002158`. |

## Implementation Tracking Checklist

- [x] Supervisor accepted this revised B009 report for implementation callback. Proof: supervisor callback instructed B009 to implement the accepted report for UID00041D.
- [x] Current target/support docs were re-read during this rework. Proof: targeted checks found accepted facts in target, class, file, constructor, local cluster, layout, resource, and generated output; no accepted by-* edit was missing.
- [x] Target metadata applied in `by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md`: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:000092`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000092`, blank `EMITTER_POSITION_OPTIONAL`. Proof: current target header and validator `000000002109`.
- [x] Target formal C++ applied in `by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md`. Proof: current target formal `RECONSTRUCTION_CPP CODE` block contains the exact accepted `LoadAcc2DrwTable` body with header, BEGIN, and END lines; validator `000000002109`.
- [x] Target MCP provenance applied. Proof: target evidence records MCP database `supervisor_resume_20260629`, availability, schema-current calls, exact-address evidence, and no fallback-only evidence.
- [x] Target range/padding facts applied. Proof: target and local cluster record `sub_4E1800`, size `0x1c5`, half-open range `0x004e1800-0x004e19c5`, padding at `0x004e19c5`, and distinct successor `0x004e19d0`.
- [x] Target constructor-only caller and literal facts applied. Proof: target, constructor, class/file, local cluster, and resource pages record caller `0x004e0188`, literal xref `0x004e0181`, and UTF-16LE `acc2drw.tbl` at `0x0061c324`.
- [x] Target row count source applied. Proof: target, file, local cluster, layout, and resource docs record `m_partEntries[7].descriptorCount` and raw `partEntriesBegin + 0x210` / `0x210 = 7 * 0x44 + 0x34`.
- [x] Target `Acc2DrwEntry.enabled[0..2]` digit behavior applied. Proof: target formal C++, behavior text, class/file support, layout, and resource page record hundreds/tens/ones mapping.
- [x] Target vector clear/push source shape applied. Proof: target C++ and support docs record `m_acc2drwEntries.clear()` and `m_acc2drwEntries.push_back(entry)` as source-level forms of end-to-begin clear plus direct/full-capacity append.
- [x] Fatal path applied. Proof: target formal C++ and evidence record short `ReadLine`, `DestroyDATFileMgr`, `DestroyExceptionHandler`, `MessageBoxW`, `Error on ACC2DRW table!`, caption `Error`, `MB_ICONEXCLAMATION`, and `__loaddll(0)`.
- [x] Score rationale applied. Proof: target `Score Rationale` explains the `88/90` promotion, superseded B011 blocker, and remaining original-spelling/helper-template uncertainty.
- [x] Rejected alternatives preserved. Proof: target `Rejected Alternatives` records rejection of no-owner/no-emitter, file-only direct owner, resource owner, VectorHelpers owner, HumanImageLib ownership via shared string, constructor inlining, successor merge, and raw standalone vector-helper source.
- [x] Support doc `by-class/NewHumanImageLib.md` synchronized. Proof: class method inventory lists UID00041D as class-owned/emitting `88/90`, records `m_acc2drwEntries` / `Acc2DrwEntry.enabled[0..2]`, and coordinates UID00041E as marker-only support; validator `000000002151`.
- [x] Support doc `by-file/NewHumanImageLib.md` synchronized. Proof: file source route/helper inventory says UID00041D emits through [UID:000092] into `NexusTK/render/NewHumanImageLib.cpp`, removes stale below-gate/no-owner wording, and coordinates B010 UID00041E marker support; validators `000000002153` and final generated refresh `000000002158`.
- [x] Support doc `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md` synchronized. Proof: constructor C++ remains unchanged, support text keeps `LoadAcc2DrwTable(L"acc2drw.tbl")` out-of-line and points UID00041D to the exact child body; validator `000000002154`.
- [x] Support doc `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md` synchronized. Proof: active function row records UID00041D as class-owned/emitting `88/90`, exact range, row count, enabled bytes, and UID00041E marker path; validator `000000002155`.
- [x] Support doc `by-type/by-struct/NewHumanImageLibLayout.md` synchronized. Proof: layout records `m_acc2drwEntries`, `Acc2DrwEntry.enabled[0..2]`, producer proof, and `m_partEntries[7].descriptorCount`; validator `000000002156`.
- [x] Support doc `by-resource/new-human-motion-tables.md` synchronized. Proof: resource page keeps `acc2drw.tbl` payload provenance and records UID00041D consumes rows into `Acc2DrwEntry.enabled[0..2]`; validator `000000002157`.
- [x] UID00041E target intentionally excluded. Proof: `by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md` was not edited by B009; B010/supervisor owns UID00041E target marker-only implementation and validation.
- [x] `by-file/VectorHelpers.md` intentionally excluded. Proof: accepted UID00041D implementation did not strictly require VectorHelpers edits; UID00041E coordination remained B010/supervisor-owned.
- [x] Claim And Incorporation Ledger updated. Proof: C01 is `already-present`; C02-C21 are `applied`; C22 is `excluded-with-reason`; `Callback Claim Proof` maps every row to concrete doc/validator/generated proof.
- [x] Target validator run. Proof: command `python .\tools\validator.py --mode file --file by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md --apply --queue-timeout 240 --wait-generated`, command_id `000000002109`, timestamp `2026-06-30T03:03:41-04:00`, exit `0`, ok `1`, generated refresh completed.
- [x] Support validators run. Proof: class `000000002151`, file `000000002153`, constructor `000000002154`, local cluster `000000002155`, layout `000000002156`, resource `000000002157`, all exit `0`, ok `1`; final file/generated freshness validator `000000002158` exit `0`, ok `1`.
- [x] Generated freshness checked. Proof: `auto-generated/NexusTK/render/NewHumanImageLib.cpp` header is validator command `000000002158`, refreshed `2026-06-30T03:43:19-04:00`, and contains UID00041D C++ plus constructor call/fatal text/enabled fields.
- [x] Generated coverage/tracker handling obeyed. Proof: generated outputs refreshed only through validators/executed-report flow; no generated report or manual `-coverage-report.md` file was hand-edited by B009.
- [x] Leases released. Proof: target and support leases were used only for edit/validator batches and released; current lease report shows `No active leases.`
- [x] Manual exclusions obeyed. Proof: B009 did not manually edit generated files, coverage reports, validator/tool state, IDA DB, supervisor ledgers, executed archives, or lock files.
- [x] Supervisor execution remains deferred to supervisor. Proof: B009 did not move/archive the report or run `execute_report`; supervisor should execute only after independent verification with `python .\tools\validator.py execute_report B009 00041D-NewHumanImageLibLoadAcc2DrwTable-source-quality.md 00041D --apply`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/00041D-NewHumanImageLibLoadAcc2DrwTable-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/00041D-NewHumanImageLibLoadAcc2DrwTable-source-quality.md","timestamp":"2026-06-30T03:55:23","uid":"00041D"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00041D-NewHumanImageLibLoadAcc2DrwTable-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/00041D-NewHumanImageLibLoadAcc2DrwTable-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00041D"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
