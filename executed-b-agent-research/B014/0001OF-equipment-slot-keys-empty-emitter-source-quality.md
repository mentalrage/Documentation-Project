** TARGET-REPORT-UID:0001OF **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001OF g_equipmentSlotKeys Empty Emitter Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: resolve [UID:0001OF] as a source-ready exact data-table emitter, not a no-code item. Keep the existing semantic route through [UID:0000PX] `g_equipmentSlotKeys` and [UID:0000KC] `ItemActionInputPanes`, populate [UID:0001OF]'s formal C++ block with the exact 23-entry `static const wchar_t` initializer, and populate [UID:0000PX]'s formal C++ block with `[[CHILDREN]]` so the exact child declaration is assembled through the semantic global route without duplicating the table on the global page.
- Final disposition: [UID:0001OF] remains a reconstructable source-declared/generated-binary `.rdata` table. After the correction callback, generated `ItemActionInputPanes.cpp` contains exactly one table declaration and UID0001OF is no longer an Empty Emitter Marker.
- Required action: implementation and correction callbacks have been applied to source docs; supervisor still owns verification and `execute_report`.
- Confidence: high for bytes, range, xref, consumer semantics, owner/emitter route, and source declaration form; medium-high for original identifier spelling because no PDB/source symbol proves the original name.

## Supporting Research

## Target

- Target UID: `0001OF`
- Target path: `by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md`
- Assignment id: `B014-report-0001OF-equipment-slot-keys-empty-emitter-source-quality-20260628`
- Required report path: `tools/leaser/Agents/Agent-B014/research/0001OF-equipment-slot-keys-empty-emitter-source-quality.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` lists [UID:0001OF] at stale `84/89`, reconstructable `true`, direct report count `0`.
- Generated output state checked before this report: `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp`, validator command `000000000079`, refreshed `2026-06-28T22:29:25-04:00`, still emits line 185 as `// UID:0001OF ... Completion:84 | Confidence:89 | Empty Emitter Marker`.
- Current target page state: source page itself is `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000PX`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000PX`, formal C++ blank.
- Parent/global state: [UID:0000PX] `by-global/g_equipmentSlotKeys.md` is `88/86`, owner/emitter [UID:0000KC], formal C++ blank, and the generated output also marks it as an Empty Emitter Marker at line 183.

## Current Target State

- Existing metadata: `86/91`, owner/emitter [UID:0000PX], reconstructable true.
- Existing C++/emitter state: formal `RECONSTRUCTION_CPP CODE` is blank, so the target is generated as an Empty Emitter Marker despite having a valid emitter chain.
- Existing open blockers from the target page and goal:
  - fixed 23-entry UTF-16 table contents needed current MCP confirmation;
  - placeholder `#` selector slots needed preservation in any declaration;
  - `TakeOffInputPane::ProcessUnequipCommand` consumer, one-character read, uppercase `A` branch, table scan, and selector `index + 1` semantics needed current confirmation;
  - parent/global [UID:0000PX], likely source module [UID:0000KC], and exact source declaration placement needed reanalysis;
  - predecessor/successor boundaries needed recheck against adjacent `.rdata`;
  - blank formal C++ needed either exact code or a stronger no-code proof.
- Related docs checked:
  - `by-global/g_equipmentSlotKeys.md`
  - `by-file/ItemActionInputPanes.md`
  - `by-class/TakeOffInputPane.md`
  - `by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md`
  - `by-memory/0x005b2830-0x005b296b.TakeOffInputPaneProcessUnequipCommand.md`
  - `by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md`
  - `by-memory/0x006307ec-0x00630bd8.UserPaneInputStrings.md`
  - `by-memory/0x00630c06-0x0063104c.UserStatusMenuReadOnlyData.md`
  - `by-global/-guidance.md`, `by-memory/-guidance.md`, `by-structure.md`, and generated `ItemActionInputPanes.cpp` context.

## Supervisor Active Recheck

- The current user/supervisor instruction says this is a report-only assignment for [UID:0001OF] and forbids target/support by-* edits until supervisor validates this report and sends an implementation callback.
- IDA MCP is mandatory. This report uses live MCP session `agent_b009_0002my_20260628`; no fallback-only finalization was used.
- No split execution was authorized. No leases were taken.
- No generated reports, generated C++, project-level files, manual coverage reports, validator/tool state, or IDA DB were edited.

## Inference Research Guidance Check

- Direct IDA/MCP facts are separated below from documentation evidence and inference.
- Existing docs were treated as leads: prior C001/B002/B006 notes already described the table, but this pass rechecked bytes, xrefs, decompilation, generated output, and source-placement with current MCP and current by-* docs.
- No stale Wave2/Wave3 claim was used as authority. The generated output and tracker were used only as queue/generator-state evidence.
- Source-placement inference follows by-structure: exact data declarations may emit from by-memory when the target range itself is the source-declared object; `CANONICAL_OWNER` records semantic ownership and `EMITTER_UIDS` records output route.

## Evidence Standards Used

- MCP availability and provenance: `initialize` and `tools/list` succeeded against `http://127.0.0.1:13337/mcp`. `idb_list` returned one active worker session, `agent_b009_0002my_20260628`, for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `2412`.
- MCP health: `server_health` returned status `ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready `true`, Hex-Rays ready `true`, strings cache ready `true`, strings cache size `2067`.
- Evidence ladder used: live MCP bytes/xrefs/decompile/disasm first; current by-* docs second; executed B reports only as checked context; generated output only as output-state evidence.
- Numeric conversions: MCP `int_convert` verified `0x2e = 46`, `0x17 = 23`, `0x1f = 31`, `0x41 = 65`, and `0x13b = 315`.

## Evidence Checked

### IDA MCP / Raw Facts

- `get_bytes 0x00630bd8 size 46` returned exactly:

```text
77 00 61 00 73 00 68 00 23 00 6e 00 6c 00 72 00
23 00 23 00 23 00 23 00 66 00 6d 00 23 00 63 00
23 00 23 00 23 00 5b 00 5d 00 31 00 32 00
```

- Decoded as 23 UTF-16 code units: `w a s h # n l r # # # # f m # c # # # [ ] 1 2`.
- `get_string 0x00630bd8` returned only `"w"`, which supports the existing warning that IDA string typing is not a useful representation for this fixed table.
- `xrefs_to 0x00630bd8` returned exactly one data xref: `0x005b28f0` inside `sub_5B2830`, size `0x13b`.
- `xref_query 0x00630bd8 direction both` returned the same single data xref and no other route.
- `find_bytes` for the complete 46-byte table pattern found one match at `0x00630bd8`.
- `find_bytes D8 0B 63 00` found one match at `0x005b28f4`, the encoded address operand inside the table-scan instruction. This is not an independent pointer table or separate storage reference.
- `find_bytes D8 0B 63 00 66 8B` returned zero matches.
- `lookup_funcs`:
  - `0x005b2830` and `0x005b28f0` resolve to `sub_5B2830`, size `0x13b`.
  - `0x005b27c0` resolves to `sub_5B27C0`, size `0x67`.
  - `0x005b2720` resolves to `sub_5B2720`, size `0x93`.
  - `0x00630bd8` and `0x00630c06` are not functions.
- `decompile 0x005b2830` confirms:
  - one-character gate through `sub_4F2310(this) == 1`;
  - one wide-character read through `sub_4F2300(this, &wideChar, 1)`;
  - uppercase `A` branch compares to `0x41`;
  - the `A` branch calls `sub_5B27C0` for selectors `1,2,3,4,6,7,8,13,14,16,20,21,22,23`;
  - the non-`A` branch scans `word_630BD8[index]` and stops after `0x17` entries;
  - the single-slot branch sends opcode `0x1f`, selector `index + 1`, and length `2` through `dword_67A7EC`/packet sender when `unk_69B380 <= 0`.
- `disasm 0x005b2830` confirms the key instruction at `0x005b28f0`:

```asm
cmp ax, ds:word_630BD8[ecx*2]
inc bl
movsx ecx, bl
cmp ecx, 17h
jl short loc_5B28F0
```

- MCP byte reads around boundaries:
  - `0x00630bc8` ends the predecessor string data with bytes for `s 'v'.` plus null/padding.
  - `0x00630c06` begins with `00 00 49 00 6e 00 76 00...`, the successor mixed lead-in before `Invalid...`.

### Documentation / Generated Evidence

- [UID:0001OF] target already documents the exact 23-entry table, predecessor [UID:00026X], successor [UID:00026Y], and fixed selector semantics.
- [UID:0000PX] parent global already documents exact size, selector mapping, direct consumer, and source-owner caveat, but its confidence remained capped by an older live-MCP timeout note and unresolved final declaration placement.
- [UID:0000KC] `ItemActionInputPanes` is the existing source-file route and already clears the output source-root gate with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`, `COMPLETION:90`, `CONFIDENCE:85`, and `CANONICAL_OWNER:FILE`.
- [UID:00041M] exact consumer method already documents the table scan, but keeps method C++ blank because the inherited command helpers and virtual return convention are unresolved. That no-code proof does not block a source declaration for this exact data table.
- Generated `ItemActionInputPanes.cpp` line 185 still marks [UID:0001OF] as an Empty Emitter Marker at stale `84/89`; this should be corrected by source doc edits plus scoped validator refresh, not by manual generated-file edits.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| [UID:0001OF] is a fixed 23-entry source-authored equipment selector key table. | Confirmed. | Current MCP bytes, single data xref, `0x17` scan bound, selector `index + 1` send. | `get_string` returns only `"w"`; no null-terminated string interpretation is used by code. | None for behavior. |
| The table should emit formal C++ from the exact by-memory page. | Strong inference. | By-memory guidance allows exact data declarations; analogous exact string/table data pages emit constants from by-memory; the target range itself is the source-declared object. | Parent global could emit the definition, but that would duplicate or hide the exact range source owner. A plain parent comment marker was tested by implementation and did not assemble the child declaration. | Use `[[CHILDREN]]` on [UID:0000PX] and the actual declaration on [UID:0001OF]. |
| Existing owner/emitter route should remain [UID:0001OF] -> [UID:0000PX] -> [UID:0000KC]. | Strong inference. | Parent global and file both clear gates; source module is item action input panes; one consumer is TakeOff item-action command code; validator-generated output now proves the child declaration reaches [UID:0000KC] when [UID:0000PX] exposes `[[CHILDREN]]`. | Direct route to [UID:0000EC] rejected because the table is source data, not class object state; direct route to [UID:0000KC] would bypass the existing valid global page. | No UID route change needed; the parent block must be `[[CHILDREN]]`, not a plain comment. |
| Formal source name can remain `g_equipmentSlotKeys`. | Medium-high inference. | Current by-global/by-memory docs and future consumer docs already use this source-facing alias; no original symbol proves another spelling; project also uses `g_` globals for source-facing state. | `kEquipmentSlotKeys` would fit many file-local const examples, but it would create more renaming churn without direct original-name proof. | If a later file-wide naming pass standardizes item-action constants as `k...`, rename can be coordinated then. |
| Braced `wchar_t[23]` initializer is safer than an `L"..."` string literal. | Strong inference. | Consumer scans exactly 23 code units; target range is exactly `0x2e` bytes. | There is a null word at `0x00630c06`, but current docs assign it to successor lead-in, and the caller does not use terminator semantics. | Preserve explicit 23 entries to avoid accidentally rebuilding this as a 24-code-unit string. |

## Positive Evidence Summary

- Current MCP confirms the table bytes, unique full-pattern match, one consumer xref, and exact scan semantics.
- The only data xref is from `TakeOffInputPane::ProcessUnequipCommand`, which is already part of `ItemActionInputPanes.cpp`.
- The table is not a mixed range, not a vtable, not runtime support, not a pooled string with unrelated consumers, and not a pointer alias.
- The existing owner/emitter chain is valid and reaches a generated source root. The remaining Empty Emitter Marker is a formal-code/documentation issue, not an ownership/routing issue.
- A source-level `static const wchar_t [23]` table exactly matches the memory object and avoids a fake null-terminated string.

## Negative Evidence Summary

- No second xref, no pointer-table xref, and no direct data reference from `SendTakeOffPacket`; the helper shares selector values by argument but does not own or read the table.
- The table should not be attached directly to `TakeOffInputPane`: it is file-level source data near equipment action command code, while the class page is the consumer class.
- The table should not be split. All 23 entries have the same storage shape, same owner, same consumer, same selector-index meaning, and no internal source-owner boundary.
- A separate one-item source file is rejected. The only consumer and source context are the existing item-action input pane route.
- A null-terminated `L"wash#nlr####fm#c###[]12"` declaration is rejected for this target because it would imply 24 code units and string-terminator semantics. If the adjacent null at `0x00630c06` needs source representation, it belongs to the successor lead-in/literal documentation, not to [UID:0001OF]'s 23-entry table.

## Ranked Ownership Analysis

### 1. Existing parent global [UID:0000PX] -> file [UID:0000KC]

- Evidence for: [UID:0000PX] documents this exact symbol/table, clears the gate, and routes to [UID:0000KC]; [UID:0000KC] is the existing `ItemActionInputPanes.cpp` source root. Current MCP confirms the only consumer is inside the TakeOff item-action command path.
- Evidence against: final original symbol spelling is inferred; [UID:0000PX] currently has blank C++ and stale timeout wording.
- Decision: accepted with correction. Keep owner/emitter unchanged. Update [UID:0000PX] to explain that the exact source declaration is emitted by [UID:0001OF] and use `[[CHILDREN]]` as the parent insertion point; the earlier plain comment marker avoided a parent Empty Emitter Marker but did not assemble the child table declaration.

### 2. Direct file owner/emitter [UID:0000KC]

- Evidence for: file-level source data in `ItemActionInputPanes.cpp`; one consumer inside that source family.
- Evidence against: bypasses the existing and useful [UID:0000PX] global symbol page; not needed to fix the empty marker.
- Decision: rejected as an unnecessary route change.

### 3. Direct class owner/emitter [UID:0000EC] `TakeOffInputPane`

- Evidence for: the only current table reader is `TakeOffInputPane::ProcessUnequipCommand`.
- Evidence against: the table is source-declared module/static data, not class object state or a vtable/static member proven to belong to the class. The helper `SendTakeOffPacket` is already file-level due SelfLook callers, so equipment action source data is not purely class-private.
- Decision: rejected. Mention the class as consumer, not owner.

### 4. No-owner/non-emitting

- Evidence for: original symbol spelling is not proven.
- Evidence against: source table bytes, route, owner context, and formal source shape are all strong enough; leaving it blank would preserve a generated Empty Emitter Marker unnecessarily.
- Decision: rejected.

## Source Placement

- Recommended placement: `NexusTK/ui/dialogs/ItemActionInputPanes.cpp` through the existing [UID:0001OF] -> [UID:0000PX] -> [UID:0000KC] emitter route.
- Declaration form: module-scope `static const wchar_t g_equipmentSlotKeys[23]`.
- Why this placement fits: the only table read is in `TakeOffInputPane::ProcessUnequipCommand`; the same source family owns `SendTakeOffPacket` and other item action input pane source data; [UID:0000KC] is already the validated generated source root for this family.
- Rejected placements:
  - `TakeOffInputPane` class declaration: table is not instance state.
  - `SelfLookPane`: no table read; only shares selector IDs via `SendTakeOffPacket` constants.
  - shared protocol/helper module: no separate table use or protocol-wide evidence.
  - standalone global/table source file: too granular and not supported by xrefs.

## Range / Split / Padding / Reclassification Analysis

- Exact range remains `0x00630bd8-0x00630c06`, `0x2e` / 46 bytes (Verified with MCP `int_convert`) and 23 UTF-16 code units.
- Predecessor [UID:00026X] ends exactly at `0x00630bd8`; current bytes before start belong to prior prompt/string data.
- Successor [UID:00026Y] starts at `0x00630c06`; current bytes there begin `00 00 49 00 6e 00...` and are already modeled as the following user-status/menu lead-in before exact children.
- No split needed inside [UID:0001OF].
- Reclassification: no change. It remains `RECONSTRUCTABLE:TRUE`, source-declared/generated-binary table data.

## IDA Rename / Type / Comment Recommendations

- IDA DB edits are not requested and were not performed.
- Source-facing type: `static const wchar_t [23]`.
- Source-facing name: keep `g_equipmentSlotKeys` for this implementation because it is already the cross-doc canonical alias, it is descriptive, and there is no direct evidence for an original `k...` spelling.
- Historical/search aliases to preserve: IDA `word_630BD8`; documentation/global page name `g_equipmentSlotKeys`.
- Rejected name alternatives:
  - `word_630BD8`: IDA label only, not source quality.
  - `kEquipmentSlotKeys`: plausible local-constant style but not enough benefit to justify renaming the established global page in this focused fix.
  - `TakeOffInputPane::EquipmentSlotKeys`: class static form not proven and would over-attach the data to the consumer class.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. [UID:0001OF] is reconstructable, has a nonblank emitter route that reaches [UID:0000KC], and the target score average is already above the current code-entry gate.
- Recommended target [UID:0001OF] formal `RECONSTRUCTION_CPP CODE` insertion:

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static const wchar_t g_equipmentSlotKeys[23] = {
    L'w', L'a', L's', L'h', L'#', L'n', L'l', L'r',
    L'#', L'#', L'#', L'#', L'f', L'm', L'#', L'c',
    L'#', L'#', L'#', L'[', L']', L'1', L'2'
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Recommended parent [UID:0000PX] formal child-insertion marker to avoid duplicate source and assemble [UID:0001OF]'s exact declaration:

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason this preserves exact behavior: the declaration stores exactly 23 UTF-16 code units, including the `#` placeholders. Future consumer code can scan exactly 23 entries and compute selector `index + 1`, matching `sub_5B2830`.
- Reason it matches plausible original source shape: a file-scope static const wide-character lookup table in `ItemActionInputPanes.cpp` is era-appropriate and local to the item-action command code. Braced characters make the non-terminated selector table explicit and avoid decompiler labels.
- Third-party import directive: not applicable.

## Final Recommendation

- Keep [UID:0001OF] metadata owner/emitter route unchanged, but raise source readiness and add formal C++.
- Recommended [UID:0001OF] score: `COMPLETION:90`, `CONFIDENCE:92`.
- Recommended [UID:0000PX] score: `COMPLETION:90`, `CONFIDENCE:90`.
- Keep [UID:0000KC] score unchanged at `90/85`; the file still has broader raw-helper/source-quality caps unrelated to this table.
- Keep [UID:0000EC], [UID:0001M1], and [UID:00041M] scores unchanged; their method/class C++ blockers are separate helper-name/return-convention issues, not table-declaration blockers.
- Generated output expectation after implementation and validator refresh: `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` should contain exactly one UID0001OF `static const wchar_t g_equipmentSlotKeys[23]` declaration and no UID0001OF Empty Emitter Marker. UID0000PX should appear as the semantic parent trace comment immediately before the routed child declaration, not as a separate covered-by comment marker.

## Recommended Target Doc Changes

Target path: `by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md`

- Change `COMPLETION:86` to `90`.
- Change `CONFIDENCE:91` to `92`.
- Keep `CANONICAL_OWNER:0000PX`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000PX`.
- Insert the exact formal C++ block above.
- Update `Status` and `Reconstruction Notes` to say the previous blank-C++ blocker is resolved: current MCP confirms the exact bytes, unique table pattern, single consumer xref, 23-entry scan, and source placement through [UID:0000PX]/[UID:0000KC].
- Preserve that `g_equipmentSlotKeys` is an inferred source-facing name, not a proven original symbol.
- Preserve rejected alternatives: no C string declaration, no class-static table, no direct file reroute, no split, no `word_630BD8` source name.
- Update `IDA Evidence` with this pass's MCP session `agent_b009_0002my_20260628`: health/session, bytes, `get_string` one-character result, one xref at `0x005b28f0`, unique full table byte pattern at `0x00630bd8`, decompile/disasm facts.
- Update `Score Rationale` with `90/92` and why not higher: original symbol spelling and broader consumer method helper names remain inferred.
- Add a `Changes` entry for this B014 report.

## Recommended Support Doc Changes

Support path: `by-global/g_equipmentSlotKeys.md`

- Change `COMPLETION:88` to `90`.
- Change `CONFIDENCE:86` to `90`.
- Keep owner/emitter [UID:0000KC].
- Insert the parent `[[CHILDREN]]` formal C++ block shown above, not a duplicate table declaration and not a plain covered-by comment marker.
- Replace the old live-MCP-timeout caveat with current MCP success evidence from session `agent_b009_0002my_20260628`.
- Clarify that [UID:0001OF] owns the exact emitted source definition and this global page is the semantic symbol/route page.
- Preserve final-name caveat: `g_equipmentSlotKeys` is inferred/descriptive and `word_630BD8` is only the IDA alias.

Support path: `by-file/ItemActionInputPanes.md`

- Keep score unchanged.
- Update the `TakeOffInputPane`/source-family notes or proposed contents to record that [UID:0001OF] now emits a first-draft static const table through this module.
- Preserve that [UID:0001M2] `SendTakeOffPacket` shares selector IDs but does not read the table.
- Preserve broader file caps for raw helpers, constructors, and method names.

Support path: `by-class/TakeOffInputPane.md`

- Keep score unchanged.
- Update data dependency wording to say the source-facing table declaration is now `static const wchar_t g_equipmentSlotKeys[23]` emitted by [UID:0001OF].
- Preserve that the class is the consumer, not the direct owner, and that class-level C++ remains blank for broader declaration/method policy.

Support path: `by-memory/0x005b2830-0x005b296b.TakeOffInputPaneProcessUnequipCommand.md`

- Keep score and blank method C++ unchanged.
- Update data dependency and no-code proof wording to remove the table declaration as a blocker: future method C++ should use `g_equipmentSlotKeys`, but method C++ remains blocked by source-facing input helper names and return convention.
- Preserve current MCP facts: one-character gate, uppercase `A` branch, 23-entry table scan, selector `index + 1`, and inline opcode `0x1f` send.

Optional support path: `by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md`

- Keep score unchanged.
- If touched during implementation, add one sentence that the exact table child [UID:0001OF] now carries the formal table declaration while this aggregate remains blank-C++ for mixed method/helper/padding reasons.

No manual `-coverage-report.md`, generated tracker, generated C++, project-level generated file, validator-state, or IDA DB edits are recommended.

## Score And Metadata Recommendation

- [UID:0001OF] current: `86/91`, owner/emitter [UID:0000PX], reconstructable true, blank C++.
- [UID:0001OF] recommended: `90/92`, owner/emitter unchanged, reconstructable true, formal C++ populated.
- Score rationale:
  - Completion rises because the only meaningful target-local blocker, formal source declaration placement, is resolved with current MCP evidence and an exact code block.
  - Confidence rises moderately because current MCP supersedes older timeout/stale generated evidence and confirms bytes/xrefs/decompile directly.
  - Confidence stays below final-audit levels because original identifier spelling is inferred and the consumer method's final helper names/return convention are separate open source-quality work.
- [UID:0000PX] recommended: `90/90`, owner/emitter unchanged, formal `[[CHILDREN]]` child-insertion marker populated.
- [UID:0000KC], [UID:0000EC], [UID:0001M1], [UID:00041M] recommended: score unchanged.

## Open Questions With Attempted Resolution

- Original symbol spelling: no PDB/source symbol exists in current evidence. Resolved for implementation by keeping the established inferred source-facing `g_equipmentSlotKeys` name and documenting it as inferred. Rejected `word_630BD8`.
- `k...` versus `g_...`: checked local source-style examples. `k...` is common for local constants, but this focused item already has an established global page and cross-doc alias. The report recommends no rename now to avoid churn without original-name proof.
- Null terminator/source string question: current bytes show a zero word at successor start, but current target range and consumer semantics are exactly 23 entries. Resolved by using a braced 23-entry initializer rather than an `L"..."` string literal.
- Method C++ blocker: not resolved for [UID:00041M] because its blockers are inherited helper names and return convention, not this table. This target can still emit the table independently.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Not applicable. Do not manually edit generated `auto-generated/-ag-*` reports, project-level generated files, or manual `-coverage-report.md` files. After implementation, scoped validators should refresh generated output; the generated research tracker direct report count changes only after supervisor executes this report.

## Validator / Generated Refresh Plan For Implementation Callback

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after accepted by-* edits:

> Executable block R001 was removed from this report and preserved verbatim in [0001OF-equipment-slot-keys-empty-emitter-source-quality-removed.md](0001OF-equipment-slot-keys-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Generated output proof expected after the first/global/by-file validator batch:

- `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` header should be equal/newer than the validator command with `--wait-generated`.
- UID0001OF should no longer include `Empty Emitter Marker`.
- UID0001OF should emit the exact `static const wchar_t g_equipmentSlotKeys[23]` declaration.
- UID0000PX should no longer be an Empty Emitter Marker; it should appear as the parent trace for UID0001OF's routed declaration through `[[CHILDREN]]`.

## Follow-Up Actions

- Supervisor: validate this report and checklist before any implementation callback.
- B014 implementation callback, if accepted: apply exactly the target/support edits above under short leases, update this checklist with proof, run scoped validators, check generated `ItemActionInputPanes.cpp`, release leases immediately, and return implementation result.
- No A-agent action is required.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for [UID:0001OF] `90/92`; medium-high for [UID:0000PX] `90/90` because original identifier spelling remains inferred.
- Remaining uncertainty: original source name and whether a later module-wide style pass would rename the constant to `kEquipmentSlotKeys`. This does not block current source emission because behavior, bytes, route, and declaration shape are strong.

## Validator Results

- No validators were run in this report-only pass because no by-* docs were edited.
- No generated files or validator/tool state were edited.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B014/research/0001OF-equipment-slot-keys-empty-emitter-source-quality.md`
- Modified: none outside B014's own research folder.
- Report execution: left blank. Supervisor owns `tools/validator.py execute_report ... --apply` after implementation verification.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor callback in `goal.md` accepted this report for implementation on 2026-06-28.
- [x] Target doc `by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md`: change score to `90/92`, keep owner/emitter/reconstructable unchanged, insert the exact `static const wchar_t g_equipmentSlotKeys[23]` formal C++ block, add current MCP evidence, update reconstruction notes, score rationale, rejected alternatives, and change log. Proof: implemented in target header/body; validator `000000000115` returned exit `0`, `ok: 1`.
- [x] Support doc `by-global/g_equipmentSlotKeys.md`: change score to `90/90`, keep route to [UID:0000KC], replace old timeout caveat with current MCP success evidence, and state that [UID:0001OF] owns the emitted table declaration. Proof: initial implementation inserted a non-duplicating comment marker and validator `000000000118` returned exit `0`, `ok: 1`; correction callback then superseded that plain marker with `[[CHILDREN]]` after generated proof showed the comment did not assemble UID0001OF.
- [x] Support doc `by-file/ItemActionInputPanes.md`: keep score unchanged and record that [UID:0001OF] now emits the source table through this module while [UID:0001M2] shares selector IDs but does not read the table. Proof: implemented; final validator `000000000135` returned exit `0`, `ok: 1` after transient generated-file permission failure in `000000000134`.
- [x] Support doc `by-class/TakeOffInputPane.md`: keep score unchanged and update the data dependency/source-facing table declaration wording while preserving class-consumer/not-owner and class-level blank-C++ rationale. Proof: implemented; final validator `000000000137` returned exit `0`, `ok: 1`.
- [x] Support doc `by-memory/0x005b2830-0x005b296b.TakeOffInputPaneProcessUnequipCommand.md`: keep score and method C++ unchanged; update data dependency/no-code proof wording so table declaration is resolved but helper names/return convention still block method C++. Proof: implemented; validator `000000000121` returned exit `0`, `ok: 1`.
- [x] Optional support doc `by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md`: if touched, keep score unchanged and add one sentence that [UID:0001OF] now carries the formal table declaration while the aggregate remains blank-C++. Proof: touched and implemented; final validator `000000000138` returned exit `0`, `ok: 1`.
- [x] Current target state and actual evidence checked recorded: MCP session `agent_b009_0002my_20260628`, health ok, exact 46 bytes, one data xref at `0x005b28f0`, unique full table pattern, `get_string` only `"w"`, decompile/disasm table scan, generated stale Empty Emitter Marker state. Proof: target/global/support docs now record the B014 MCP evidence and stale generated-state correction.
- [x] Score-limiting blockers researched to resolution: fixed table contents, placeholder slots, consumer scan, selector `index + 1`, parent/global route, source module placement, predecessor/successor boundaries, and formal C++ declaration shape. Proof: target/global docs include score rationale, formal code, and rejected alternatives.
- [x] Owner/emitter/reconstructable changes to apply: no route/reconstructable change for [UID:0001OF] or [UID:0000PX]. Proof: target remains owner/emitter [UID:0000PX], reconstructable true; global remains owner/emitter [UID:0000KC].
- [x] Split/rename/new-child changes to apply: none; explicitly preserve no-split decision and no rename in this focused pass. Proof: target `Reconstruction Notes`, `Range / boundary` evidence, and changes preserve no split/no rename.
- [x] Source-placement/range/reclassification decisions to apply: source placement remains `NexusTK/ui/dialogs/ItemActionInputPanes.cpp`; [UID:0001OF] remains exact source-declared/generated-binary data; [UID:0000PX] is semantic route/child-insertion page. Proof: target/global/by-file support docs updated with this route and role split.
- [x] First-draft C++ to apply: exact [UID:0001OF] formal block with 23 braced `wchar_t` entries and [UID:0000PX] `[[CHILDREN]]` insertion marker. Proof: source docs contain the exact table formal block plus parent child marker; validators `000000000183`, `000000000184`, and `000000000185` passed, and generated output contains the table exactly once.
- [x] Third-party import directive: not applicable. Proof: no third-party import used or needed.
- [x] Historical/stale assumptions and rejected alternatives to preserve: generated stale `84/89` marker, older MCP timeout caveat superseded by current success, no C string, no `word_630BD8` source name, no class-static table, no direct file reroute, no standalone source file, no split. Proof: target/global docs preserve these points; by-file/class/method/aggregate support docs include current table declaration and consumer/not-owner wording.
- [x] Open questions to close/document: original symbol spelling remains inferred; `k...` rename deferred/rejected for this focused pass; method [UID:00041M] C++ remains blocked for helper names/return convention, not table declaration. Proof: target score rationale and method no-code proof updated.
- [x] Validators to run after implementation: target/global/by-file with `--wait-generated`, class/method scoped validators, and generated `ItemActionInputPanes.cpp` header/UID marker check as listed above. Proof: commands/results recorded below.
- [x] Generated report refresh expected: generated C++ should refresh through validator; no manual generated report/manual coverage/project-level edits. Proof: generated output refreshed by validator through command `000000000138`; generated files/reports were not manually edited.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: active callback in `goal.md` accepted this report and directed implementation.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: modified target plus support docs `by-global/g_equipmentSlotKeys.md`, `by-file/ItemActionInputPanes.md`, `by-class/TakeOffInputPane.md`, `by-memory/0x005b2830-0x005b296b.TakeOffInputPaneProcessUnequipCommand.md`, and optional aggregate `by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md`.
- [x] Metadata/score/owner/emitter/C++ changes applied or explicitly not applied with reason. Proof: [UID:0001OF] is `90/92`, owner/emitter/reconstructable unchanged, formal table C++ inserted; [UID:0000PX] is `90/90`, owner/emitter unchanged, formal `[[CHILDREN]]` marker inserted; support scores unchanged.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target/global/support docs preserve `get_string` caveat, unique-pattern/xref facts, rejected string/class-static/direct-file/standalone/split/IDA-name alternatives, and original-name caveat.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: target/global docs document inferred original symbol spelling; method page documents table declaration resolved and method C++ still blocked only by command helper names/original virtual name/return convention.
- [x] Validators run and results recorded with command IDs, timestamps, exit codes, ok counts, warnings, and generated-refresh state. Proof:
  - `python .\tools\validator.py --mode file --file by-memory\0x00630bd8-0x00630c06.g_equipmentSlotKeys.md --apply --queue-timeout 240 --wait-generated` -> `000000000115`, `2026-06-28T22:48:24-04:00`, exit `0`, `ok: 1`, generated refresh completed.
  - `python .\tools\validator.py --mode file --file by-global\g_equipmentSlotKeys.md --apply --queue-timeout 240 --wait-generated` -> `000000000118`, `2026-06-28T22:48:43-04:00`, exit `0`, `ok: 1`, generated refresh completed.
  - `python .\tools\validator.py --mode file --file by-file\ItemActionInputPanes.md --apply --queue-timeout 240 --wait-generated` -> initial `000000000119`, `2026-06-28T22:48:59-04:00`, exit `0`, `ok: 1`; second-batch retry `000000000135`, `2026-06-28T22:52:19-04:00`, exit `0`, `ok: 1`, generated refresh completed. Intermediate retry `000000000134` failed with `PermissionError` replacing generated `auto-generated/NexusTK/map/ObjectStatusBlob.cpp`; no generated file was manually edited, and retry succeeded.
  - `python .\tools\validator.py --mode file --file by-class\TakeOffInputPane.md --apply --queue-timeout 240` -> initial `000000000120`, `2026-06-28T22:49:23-04:00`, exit `0`, `ok: 1`; second-batch `000000000137`, `2026-06-28T22:52:34-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory\0x005b2830-0x005b296b.TakeOffInputPaneProcessUnequipCommand.md --apply --queue-timeout 240` -> `000000000121`, `2026-06-28T22:49:30-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory\0x005b2720-0x005b296b.TakeOffInputPane.md --apply --queue-timeout 240` -> initial `000000000122`, `2026-06-28T22:49:38-04:00`, exit `0`, `ok: 1`; second-batch `000000000138`, `2026-06-28T22:52:41-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
  - Validator diagnostics to preserve for supervisor/tooling: repeated unrelated `autogen_registry_stale` / missing-file diagnostics, by-file `missing_ref_uid` diagnostics for several pre-existing refs, UID00041L/UID00041M link rewrites caused by stale validator registry mappings, and method validator `duplicate_path_conflict 00041M ... validator.ini maps UID to existing file: by-memory/0x00526340-0x00526350.MidiPlayerStopPlayback.md`.
- [x] Generated `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` checked for UID0001OF no longer being an Empty Emitter Marker. Proof: initial implementation generated header `validator-command-id: 000000000138`, `validator-refreshed-at: 2026-06-28T22:52:41-04:00`; `UID:0001OF` was not an Empty Emitter Marker but the table declaration was absent under the plain parent marker. Correction callback replaced the parent marker with `[[CHILDREN]]`; final generated header is `validator-command-id: 000000000185`, `validator-refreshed-at: 2026-06-28T23:08:13-04:00`; UID0001OF appears once with the table declaration and zero Empty Emitter Marker hits.
- [x] Leases released immediately after implementation edit/validator batch. Proof: first batch leased six by-* docs successfully; release after validators reported `Rejected[No active lease]` for each, and lease report showed no active B014 leases. Second batch leased `by-file/ItemActionInputPanes.md`, `by-class/TakeOffInputPane.md`, and aggregate `by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md`; release succeeded for all three; final lease report shows no active B014 leases.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: resolved by correction callback. The accepted table declaration is now present in current generated output exactly once under unchanged UID route [UID:0001OF] -> [UID:0000PX] -> [UID:0000KC].

Correction callback pass:

- [x] Investigated generated-route failure. Proof: by-structure/validator docs state that `[[CHILDREN]]` inside a C++ block is the explicit insertion point for recursively assembled children; the previous plain covered-by comment on [UID:0000PX] produced a parent trace comment but no UID0001OF declaration in generated output.
- [x] Corrected target/support by-* docs without duplicating the table. Proof: changed `by-global/g_equipmentSlotKeys.md` formal C++ block to `[[CHILDREN]]`, updated `by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md` route notes to require that child insertion point, and updated `by-file/ItemActionInputPanes.md` to describe [UID:0000PX] as a child-insertion route page rather than a comment-marker page.
- [x] Correction validators passed. Proof: `python .\tools\validator.py --mode file --file by-memory\0x00630bd8-0x00630c06.g_equipmentSlotKeys.md --apply --queue-timeout 240` -> `000000000183`, `2026-06-28T23:07:48-04:00`, exit `0`, `ok: 1`, generated refresh deferred; `python .\tools\validator.py --mode file --file by-global\g_equipmentSlotKeys.md --apply --queue-timeout 240 --wait-generated` -> `000000000184`, `2026-06-28T23:07:53-04:00`, exit `0`, `ok: 1`, generated refresh completed; `python .\tools\validator.py --mode file --file by-file\ItemActionInputPanes.md --apply --queue-timeout 240 --wait-generated` -> `000000000185`, `2026-06-28T23:08:13-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- [x] Generated output proof passed. Proof: `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` header is `validator-command-id: 000000000185`, `validator-refreshed-at: 2026-06-28T23:08:13-04:00`, matching the final `--wait-generated` validator. Counts: `static const wchar_t g_equipmentSlotKeys[23]` = 1, `UID:0001OF` = 1, `UID:0001OF.*Empty Emitter Marker` = 0, old covered-by marker = 0, `UID:0000PX` = 1 parent trace.
- [x] Leases released immediately. Proof: correction lease batch for `by-global/g_equipmentSlotKeys.md`, `by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md`, and `by-file/ItemActionInputPanes.md` succeeded; release after validators succeeded for all three.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/0001OF-equipment-slot-keys-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B014/research/0001OF-equipment-slot-keys-empty-emitter-source-quality.md","timestamp":"2026-06-28T23:22:45","uid":"0001OF"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001OF-equipment-slot-keys-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/0001OF-equipment-slot-keys-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001OF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
