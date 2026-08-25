** TARGET-REPORT-UID:0002HD **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002HD] DeserializeEmployeeRecord Source-Quality Report

## Finalized Report / Current Recommendation

FINISHED_REPORT recommendation: accept [UID:0002HD] `by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md` for source-quality update after supervisor review.

Recommended target state:

- `COMPLETION:90`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:0000J0`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000J0`
- blank `EMITTER_POSITION_OPTIONAL`
- add formal first-draft C++ in the target `RECONSTRUCTION_CPP CODE` header block.

The prior blockers were investigated. The raw mutation helper blocker is no longer a target blocker: the raw upsert body at `0x004a3be0` calls this parser at `0x004a3c05`, copies one full `0x41c` record, and remains documented as retained raw support under [UID:0003L2]. The helper-name blocker is closed enough for draft source through accepted `PacketBufferReadUInt16BE`, `PacketBufferReadUInt32BE`, `GetMemoryMan`, `MemmoveWrapper`, `MultiByteToWideChar`, and ordinary `swprintf_s`/`wcscat_s` source forms. The field-name blocker is mostly closed through current `EmployeeRecord` and property-dialog support docs; the only remaining semantic cap is the third trailing dword at `+0x414`, which should be documented as `dataField3` / `serverDataField3` until a consumer proves a more specific gameplay role.

## Supporting Research

This report used live IDA MCP session `80de0a67` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, current target/support docs, executed B-agent reports for EmployeeDialogPane and EmployeeItemPropertyDialogPane, current PacketBuffer/MemoryMan helper docs, and local `tools/int_convert.py`.

Report-only phase did not edit target/support by-* files. Implementation callback phase edited only the accepted target/support by-* files listed below under B001 leases. No generated files, project-level generated files, or `-coverage-report.md` files were edited manually.

## Target

- [UID:0002HD] `by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md`
- Current source family: [UID:0000J0] `by-file/EmployeeDialogPane.md`
- Current support class: [UID:00004C] `by-class/EmployeeDialogPane.md`
- Current broad aggregate: [UID:000138] `by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md`
- Current record type: [UID:0001UD] `by-type/by-struct/EmployeeRecord.md`

## Current Target State

The target page currently has:

- `COMPLETION:86`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:000138`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000138`
- blank formal C++

The page already records the main parser behavior and current xrefs, but it still leaves first-draft C++ blank because of provisional record field names and raw helper shape. Current evidence resolves those issues enough to move this target from aggregate-attached evidence into a file-local emitting helper.

## Executive Recommendation

Update [UID:0002HD] as a source-authored file-local helper in `EmployeeDialogPane.cpp`:

- direct owner/emitter: [UID:0000J0] `EmployeeDialogPane` file page;
- support owner/class context: [UID:00004C] `EmployeeDialogPane`;
- keep [UID:000138] as broad aggregate/source-family context, not the direct emitter;
- add first-draft C++ for `static int __stdcall DeserializeEmployeeRecord(const unsigned char *packet, EmployeeRecord *record)`;
- document the one remaining field-name cap at `EmployeeRecord +0x414`.

## Supervisor Active Recheck

- MCP endpoint `http://127.0.0.1:13337/mcp` responded.
- `server_health(database=80de0a67)` returned `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.
- This is not a fallback-only report. MCP was used for the target function, callers, raw caller, helper functions, xrefs, bytes, and pointer-pattern checks.

## Inference Research Guidance Check

This target has source-quality blockers, so the report did not stop at "field names remain provisional" or "raw mutation helper needs investigation."

Investigated blockers:

- source placement: parser is a file-local helper, not a class method and not broad aggregate-only evidence;
- helper names: PacketBuffer, MemoryMan, CRT formatting, and Win32 conversion helpers have accepted source-facing roles;
- field names: known record fields are supported by EmployeeRecord and property-dialog docs; `+0x414` remains a descriptive field because no current consumer gives a narrower role;
- raw helper shape: raw upsert/remove bodies are separate retained raw support and do not block the modeled parser C++;
- final C++ safety: current gate is cleared because target is reconstructable, average score is above 85, and the first-draft C++ can use human source-facing names without raw `sub_` labels.

## Heuristic / Inference Reanalysis And Validation

The target should not remain blank-C++ merely because exact original symbols are unrecovered. The correct standard is exact runtime behavior plus human-looking reconstructed source.

Accepted inference:

- `DeserializeEmployeeRecord` is a good source-facing helper name because current docs already use it, it matches the function's sole operation, and no broader or conflicting source name exists.
- `EmployeeDialogPane.cpp` file-local static helper is the best source shape because the function has no `this` input, is called by class methods and a retained raw file helper, and parses a shared file-private record type.
- `PacketBufferReadUInt32BE` and `PacketBufferReadUInt16BE` are accepted PacketBuffer scalar helper names from [UID:0003YK].
- `GetMemoryMan()->MemmoveWrapper(...)` is acceptable exact source-facing wording for the observed `GetMemoryMan` plus `MemmoveWrapper` copy shape, while a final source cleanup could use direct `memmove` if the project standard later inlines that helper.
- `swprintf_s` is the right source-level expression for `sub_41B9B0` in this caller; the helper is documented as CRT/UCRT formatting glue and should not be modeled as a game-specific helper.

Rejected inference:

- Do not keep `sub_4A34D0`, `sub_5754C0`, `sub_575480`, `sub_516030`, `sub_516220`, or `sub_41B9B0` in draft source.
- Do not make this a non-emitting aggregate-only child; it is a modeled source-authored helper with exact behavior.
- Do not promote the raw upsert/remove bodies into this parser's C++; they are separate retained raw support bodies.
- Do not invent a precise gameplay name for `+0x414`; current evidence supports only a descriptive third server value.

## Evidence Standards Used

- Live IDA MCP decompilation/disassembly/xrefs/bytes.
- Existing validated by-* docs for owner route and support fields.
- Executed B-agent reports for property-dialog field naming.
- Local numeric conversions through `tools/int_convert.py`.
- Negative evidence for direct pointers to parser/raw starts through MCP `find_bytes`.

## Evidence Checked

- Target page [UID:0002HD].
- [UID:000138] `EmployeeDialogPanes` aggregate.
- [UID:00004C] `EmployeeDialogPane` class.
- [UID:0000J0] `EmployeeDialogPane` file.
- [UID:0001UD] `EmployeeRecord` struct.
- [UID:0003KX] packet dispatcher.
- [UID:0003L1] full-list loader.
- [UID:0003L2] raw record mutation helpers.
- [UID:0003L3] field-update path.
- [UID:0003KW] command sender.
- [UID:0002HF] property dialog paint report/docs.
- [UID:0002HG] property dialog command report/docs.
- [UID:0003YK] PacketBuffer scalar big-endian reader docs.
- [UID:0001BC] `GetMemoryMan`.
- [UID:0001BH] `MemmoveWrapper`.
- [UID:0000WO] CRT stdio formatting glue through ignored/support docs.

## Inference Claim Ledger

| Claim | Decision | Confidence | Evidence |
| --- | --- | ---: | --- |
| Target range is exactly `0x004a34d0-0x004a3644`. | accepted | 0.99 | `lookup_funcs` size `0x174`, pre/post `0xcc` bytes, no function at end-exclusive `0x004a3644`. |
| Target is source-authored and reconstructable. | accepted | 0.98 | Modeled function, meaningful parser body, three live/raw callers, no compiler-glue shape. |
| Direct source owner should be [UID:0000J0] file, not [UID:000138] aggregate. | accepted | 0.93 | No `this` argument; shared helper called by class methods and raw file helper; source family is `EmployeeDialogPane.cpp`. |
| Class [UID:00004C] should remain support context. | accepted | 0.90 | Class methods own the record array and invoke the helper, but helper itself is not a method. |
| `PacketBufferReadUInt32BE`/`PacketBufferReadUInt16BE` are the helper names. | accepted | 0.97 | [UID:0003YK] and MCP helper decompilation. |
| `GetMemoryMan()->MemmoveWrapper` is the source-facing copy path. | accepted | 0.91 | [UID:0001BC]/[UID:0001BH] docs and target call sequence. |
| `swprintf_s` is the source-level formatter expression. | accepted | 0.94 | `sub_41B9B0` is CRT/UCRT formatting glue with broad call fanout. |
| `EmployeeRecord +0x000` is `employeeItemId`. | accepted | 0.91 | Parser writes id; property command sends selected record id. |
| `EmployeeRecord +0x004` is `itemImageId`. | accepted | 0.90 | Property paint and image drawing use it as sprite/image id. |
| `EmployeeRecord +0x006` is `itemPaletteFlags`. | accepted | 0.88 | Property paint passes it into item image rendering as palette/variant flags. |
| `EmployeeRecord +0x008` is `name[256]`. | accepted | 0.96 | Parser converts packet name into 256-wide destination, property dialog uses it as item name. |
| `EmployeeRecord +0x20a` is `statusText[257]` first wchar. | accepted | 0.84 | Parser clears it, update path copies the status/source text slot; exact final role is still broader-record work. |
| `EmployeeRecord +0x40c` is `priceValue`. | accepted | 0.91 | Constructor/current display and property remove scheduling use it as current/display price. |
| `EmployeeRecord +0x410` is `editablePriceValue`. | accepted | 0.91 | Constructor seeds the edit control and command handler uses it as parse default. |
| `EmployeeRecord +0x414` is `dataField3` / `serverDataField3`. | accepted as provisional | 0.70 | Parser and update path both store the third trailing dword; no current consumer proves a narrower price/quantity/state role. |
| `EmployeeRecord +0x418` is `fallbackItemId`. | accepted | 0.82 | Zero-record branch writes it; raw remove/rebuild path uses empty/default records. |

## Positive Evidence Summary

- `analyze_function 0x004a34d0` gives exact parser behavior and all field writes.
- `xrefs_to 0x004a34d0` reports exactly three calls: dispatcher `0x004a300d`, full-list loader `0x004a3bb1`, and raw upsert body `0x004a3c05`.
- The parser returns `nameLength + 21` for nonzero records and `8` for zero records.
- The parser writes the same trailing dword triplet as the update path at `0x004a3e10`.
- Property dialog reports resolve the item id, image id, palette flags, current/display price, and editable price aliases.
- PacketBuffer docs resolve the scalar endian readers.
- MemoryMan docs resolve the memory copy helper route.
- CRT ignored/support docs resolve the wide format wrapper as `swprintf_s`-style source expression.
- Raw helper docs and fresh MCP bytes prove the raw upsert helper is a caller/support body, not a reason to block parser C++.

## IDA MCP Facts

Live session: `80de0a67`.

Target facts:

- `lookup_funcs` reports `sub_4A34D0` at `0x004a34d0`, size `0x174` / decimal `372`.
- `lookup_funcs` reports no function at `0x004a3644`, `0x004a3650`, `0x004a3be0`, `0x004a3c05`, or `0x004a3ca0`.
- `analyze_function 0x004a34d0` reports prototype residue `int __stdcall(unsigned __int8 *, int)`, five basic blocks, cyclomatic complexity `2`, and callees `_wcscat_s`, `sub_5754C0`, `sub_575480`, narrow byte helper, `sub_516030`, `sub_41B9B0`, `MultiByteToWideChar`, security cookie, and `sub_516220`.
- The same decompilation writes output offsets `+0x000`, `+0x004`, `+0x006`, `+0x008`, `+0x20a`, `+0x40c`, `+0x410`, `+0x414`, and `+0x418`.

Xref facts:

- `xrefs_to 0x004a34d0`: `0x004a300d` in `sub_4A2F60`, `0x004a3bb1` in `sub_4A3A90`, and raw `0x004a3c05` with no containing function.
- `xrefs_to 0x004a3644`: none.
- `xrefs_to 0x004a3be0`: none.
- `xrefs_to 0x004a3ca0`: none.
- `xrefs_to 0x004a3c05`: one code xref from `0x004a3c03`, the local call instruction inside the raw body.

Byte facts:

- `get_bytes 0x004a34c0 size 420` shows five `0xcc` bytes before the target prologue and twelve `0xcc` bytes at `0x004a3644-0x004a3650`.
- `get_bytes 0x004a3bd8 size 256` shows raw body prologue at `0x004a3be0`, call to this parser at `0x004a3c05`, stride/copy logic, and a second raw body at `0x004a3ca0`.
- `find_bytes` for VA/RVA pointer patterns to `0x004a34d0`, `0x004a3be0`, and `0x004a3ca0` returned no matches for the checked little-endian VA/RVA patterns.

Helper facts:

- `analyze_function 0x005754c0`: reads four big-endian bytes and returns a dword. This matches `PacketBufferReadUInt32BE`.
- `analyze_function 0x00575480` is documented by [UID:0003YK] as `PacketBufferReadUInt16BE`.
- `analyze_function 0x00516030` and [UID:0001BC] identify `GetMemoryMan`.
- `analyze_function 0x00516220` and [UID:0001BH] identify the MemoryMan `memmove` wrapper.
- `analyze_function 0x0041b9b0` shows varargs forwarding to `__stdio_common_vswprintf_s`; source should use `swprintf_s`.

## Function / Child Inventory

| Address/range | Status | Role |
| --- | --- | --- |
| `0x004a34d0-0x004a3644` | modeled function | target parser, source-ready file-local helper |
| `0x004a2f60-0x004a322c` | modeled function | `EmployeeDialogPane` packet dispatcher caller |
| `0x004a3a90-0x004a3bdf` | modeled function | full employee list loader caller |
| `0x004a3be0-0x004a3c9f` | raw non-function body | record upsert/mutation helper, calls target at `0x004a3c05` |
| `0x004a3ca0-0x004a3e10` | raw non-function body | record remove/rebuild helper |
| `0x004a3e10-0x004a4057` | modeled function | field update path with matching record field writes |

## Direct Xref / Caller Inventory

| Caller | Evidence | Target implication |
| --- | --- | --- |
| `0x004a300d` in `sub_4A2F60` | modeled dispatcher caller | Parser handles a response case inside `EmployeeDialogPane` packet dispatch. |
| `0x004a3bb1` in `sub_4A3A90` | modeled full-list load caller | Parser consumes repeated variable-length records into a `0x41c` array. |
| `0x004a3c05` in raw `0x004a3be0` body | raw upsert caller | Parser fills a stack `EmployeeRecord`, then raw body copies `0x107` dwords / `0x41c` bytes into the array. |

## Documentation Evidence And IDA Status

- Target page is current enough on core behavior but stale on score, owner/emitter, and C++ disposition.
- [UID:000138] now documents the raw helper island as no-code evidence, so the target does not need to defer C++ for that issue.
- [UID:0001UD] already records every target output offset and accepted target-context aliases.
- [UID:0002HF] and [UID:0002HG] provide stronger accepted support for the property-dialog field names.
- [UID:0003L3] current MCP decompile confirms the update path writes the same `+0x40c/+0x410/+0x414` trailing values.
- [UID:0003YK], [UID:0001BC], and [UID:0001BH] provide source-facing helper names.

## Ranked Ownership Analysis

1. [UID:0000J0] `EmployeeDialogPane` file page: best direct owner/emitter. The helper has no `this` parameter and should emit as a file-local static/stdcall helper in `EmployeeDialogPane.cpp`.
2. [UID:00004C] `EmployeeDialogPane` class: strong support context but not direct owner. Class methods own the record array and call the helper, but the target itself is not a class method.
3. [UID:000138] aggregate: keep as broad range/source-family context only. It is too broad for direct C++ ownership once the exact helper is source-ready.
4. PacketBuffer/MemoryMan/StringUtil: dependencies only. They own helper functions, not this employee parser.

## Source Placement

Place the first-draft helper in `NexusTK/ui/dialogs/EmployeeDialogPane.cpp` as a file-local helper:

- `static int __stdcall DeserializeEmployeeRecord(const unsigned char *packet, EmployeeRecord *record)`

Keep support references from `EmployeeDialogPane` class docs and `EmployeeRecord` type docs. Do not place this as an `EmployeeDialogPane::` member unless later source/header evidence proves that the original code used a static member instead of a file-local free helper.

## Range / Split / Padding / Reclassification Analysis

- The target range is exact: `0x004a34d0-0x004a3644`.
- Five `0xcc` bytes precede the target from the previous function tail to `0x004a34d0`.
- Twelve `0xcc` bytes follow the target from `0x004a3644` to raw body `0x004a3650`.
- `0x004a3650` and `0x004a3be0/0x004a3ca0` remain raw non-function bodies; they should not be merged into this exact target.
- The raw upsert body copies a full record with `0x107` dwords, which is `263 * 4 = 1052` bytes / `0x41c`.

## Negative Evidence Summary

- No current symbol/PDB/source string proves exact original helper or field spellings.
- No current consumer proves a narrower gameplay name for `EmployeeRecord +0x414`.
- No function object exists at `0x004a3644`, `0x004a3650`, `0x004a3be0`, `0x004a3c05`, or `0x004a3ca0`.
- No xrefs point to the end-exclusive target boundary or raw helper starts checked here.
- `find_bytes` found no little-endian VA/RVA pointer patterns for the target/raw starts checked.
- The broad aggregate [UID:000138] is not a precise direct emitter for this exact helper once first-draft C++ is ready.

## IDA Rename / Type / Comment Recommendations

Optional IDA changes, only if the supervisor explicitly approves C-agent/IDA edits later:

- Rename `sub_4A34D0` to `DeserializeEmployeeRecord`.
- Type as `int __stdcall DeserializeEmployeeRecord(const unsigned char *packet, EmployeeRecord *record)`.
- Do not rename raw starts as normal functions unless IDA function creation/split policy changes; document them as raw record mutation helpers.
- Do not force a final name for `EmployeeRecord +0x414` until a consumer proves the role.

No IDA DB edits were made in this report-only pass.

## First-Draft C++ Recommendation

Add this exact formal C++ block to [UID:0002HD] if the supervisor accepts the report:

```cpp
static int __stdcall DeserializeEmployeeRecord(const unsigned char *packet, EmployeeRecord *record)
{
    const unsigned int itemId = PacketBufferReadUInt32BE(packet);
    record->employeeItemId = itemId;

    if (itemId == 0) {
        record->fallbackItemId = PacketBufferReadUInt32BE(packet + 4);
        record->itemImageId = 0;
        return 8;
    }

    char nameBytes[256];
    wchar_t suffix[256];

    record->itemImageId = PacketBufferReadUInt16BE(packet + 4);
    record->itemPaletteFlags = packet[6];

    const unsigned int nameLength = packet[7];
    GetMemoryMan()->MemmoveWrapper(nameBytes, packet + 8, nameLength);
    nameBytes[nameLength] = '\0';

    const int wideLength = MultiByteToWideChar(
        CP_ACP,
        0,
        nameBytes,
        nameLength,
        record->name,
        256);
    record->name[wideLength] = L'\0';

    const unsigned char percent = packet[8 + nameLength];
    if (percent != 0xff) {
        swprintf_s(suffix, 256, L"(%d%%)", percent);
        wcscat_s(record->name, 256, suffix);
    }

    record->statusText[0] = L'\0';
    record->priceValue = PacketBufferReadUInt32BE(packet + nameLength + 9);
    record->editablePriceValue = PacketBufferReadUInt32BE(packet + nameLength + 13);
    record->dataField3 = PacketBufferReadUInt32BE(packet + nameLength + 17);

    return static_cast<int>(nameLength + 21);
}
```

C++ caveats:

- If the project standard later prefers `memmove` over `GetMemoryMan()->MemmoveWrapper`, that is a style-level change; both represent the accepted copy behavior.
- `CP_ACP` is source-facing for code page `0`.
- `dataField3` should be treated as provisional/descriptive, not final audit quality.
- This is first-draft source-quality C++, not final source. It must not use raw `sub_` labels.

## Final Recommendation

Accept a score raise and first-draft C++ entry:

- update direct owner/emitter to [UID:0000J0];
- add the first-draft C++ block above;
- update target prose to state that the raw mutation helper shape is investigated and no longer blocks this parser's draft source;
- update `EmployeeRecord` support only lightly, if needed, to clarify that `+0x414` is still descriptive/provisional and should not block this exact parser C++;
- keep score below final-audit because exact original field/helper spellings and `+0x414` semantics are still not symbol-proven.

## Recommended Target Doc Changes

For `by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md`:

1. Set header metadata:
   - `COMPLETION:90`
   - `CONFIDENCE:92`
   - `CANONICAL_OWNER:0000J0`
   - `RECONSTRUCTABLE:TRUE`
   - `EMITTER_UIDS:0000J0`
2. Replace the blank `RECONSTRUCTION_CPP CODE` body with the formal C++ block from this report.
3. Update the item summary to:

```text
File-local EmployeeDialogPane parser for one variable-length EmployeeRecord: reads big-endian id/image/value fields, converts the byte-counted name through CP_ACP MultiByteToWideChar, appends optional percent suffix text, clears status text, handles zero-id fallback records, returns exact consumed byte count, and now emits first-draft source C++ through EmployeeDialogPane.cpp.
```

4. Add a `2026-06-26 B001 Source-Quality Reanalysis` section documenting:
   - MCP session `80de0a67`;
   - exact target boundary and padding;
   - three callers including raw `0x004a3c05`;
   - helper names and accepted source-facing replacements;
   - field-name decisions and the `+0x414` confidence cap;
   - raw helper island no longer blocks this target C++.
5. Update score rationale to explain why it is not higher:
   - `+0x414` remains descriptive/provisional;
   - exact original `EmployeeRecord` member spellings are inferred;
   - final file-static versus static-member spelling is not symbol-proven;
   - raw mutation helpers remain no-code support bodies.
6. Update score rationale to explain why it is not lower:
   - modeled function, exact xrefs, exact body, exact offset writes, accepted helper names, accepted field aliases, and formal first-draft C++ are now present.

## Recommended Support Doc Changes

Recommended support edits if the supervisor accepts the report:

- [UID:0000J0] `by-file/EmployeeDialogPane.md`: add a short note that [UID:0002HD] now emits as a file-local static/stdcall parser helper in `EmployeeDialogPane.cpp`; keep [UID:000138] as aggregate context.
- [UID:00004C] `by-class/EmployeeDialogPane.md`: clarify that `DeserializeEmployeeRecord` is a file-local helper used by class methods, not an `EmployeeDialogPane::` method.
- [UID:0001UD] `by-type/by-struct/EmployeeRecord.md`: keep current score unless the supervisor wants a support score raise; add/refresh note that `+0x414` is the third server-provided trailing dword, currently best documented as `dataField3` / `serverDataField3`, and is not a blocker for first-draft parser C++.
- [UID:000138] `by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md`: optional support note that the exact parser child now owns first-draft C++ through [UID:0000J0]; raw mutation helpers remain no-code evidence.

No support edit is required to PacketBuffer, MemoryMan, or CRT formatting docs; current pages already cover the helper names.

## Score And Metadata Recommendation

Target recommendation:

| Field | Current | Recommended | Reason |
| --- | --- | --- | --- |
| Completion | `86` | `90` | Adds source-ready owner route, helper-name resolution, raw-helper blocker resolution, field decision ledger, and formal first-draft C++. |
| Confidence | `89` | `92` | Live MCP and accepted support docs independently agree on body, callers, range, helper roles, and most field aliases. |
| Canonical owner | `000138` | `0000J0` | Parser is file-local free/static helper, not a broad aggregate emitter. |
| Reconstructable | `TRUE` | `TRUE` | Keep. |
| Emitter UIDs | `000138` | `0000J0` | Emit through EmployeeDialogPane.cpp file page. |
| Formal C++ | blank | nonblank | First-draft C++ is now safe under the current gate. |

Support metadata:

- [UID:0000J0] `EmployeeDialogPane`: keep current score unless the supervisor wants a small support refresh.
- [UID:00004C] `EmployeeDialogPane`: keep current score unless the supervisor wants a support wording refresh.
- [UID:0001UD] `EmployeeRecord`: keep `86/89`; the remaining `+0x414` cap belongs to the broad record type, not this exact parser.
- [UID:000138] `EmployeeDialogPanes`: keep `90/92`; no aggregate score change required.

## Open Questions With Attempted Resolution

- Exact original spelling of `DeserializeEmployeeRecord`: no recovered symbol was found. Best source-facing name remains `DeserializeEmployeeRecord` because it is already used in docs and accurately names the parser.
- File-local free helper versus static class member: no `this`, no vtable, and raw/file helper caller evidence favor file-local `static` helper. This should not block target C++.
- Exact original `EmployeeRecord` member names: accepted target-context aliases are good enough for first-draft C++. Do not use raw offsets or `field_` names in source.
- `EmployeeRecord +0x414`: checked target parser, update path, property dialog reports/docs, and broader `EmployeeRecord` docs. No current consumer proves a specific gameplay meaning. Keep a descriptive source-facing name such as `dataField3` / `serverDataField3`; this caps final-audit score but does not block first-draft C++.
- Raw mutation helper shape: checked raw call, bytes, xrefs, pointer patterns, and B006 docs. It is separate retained raw support and does not block this modeled parser's draft C++.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

If accepted and implemented, supervisor should update `by-memory/-coverage-report.md` manually with a replacement row equivalent to:

```text
        - [UID:0002HD][0x004a34d0-0x004a3644.DeserializeEmployeeRecord](by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md) 0x004a34d0-0x004a3644 | function | DeserializeEmployeeRecord : reconstructable : 90% : very strong : B001 2026-06-26 source-quality reanalysis resolves this as a file-local EmployeeDialogPane.cpp parser helper with formal first-draft C++: exact 0x174-byte stdcall body, dispatcher/full-list/raw-upsert callers, raw 0x004a3c05 support route, CP_ACP name conversion, optional percent suffix, zero-id fallback, fixed EmployeeRecord writes, accepted PacketBuffer/MemoryMan/CRT helper roles, owner/emitter reroute to [UID:0000J0], and only +0x414 exact semantic naming below final-audit confidence.
```

Do not manually edit auto-generated tracker files. Refresh generated coverage/research tracker through the normal project tools after validator execution.

## Implementation Callback Result

FINISHED_IMPLEMENTATION-ready from B001 side: accepted report details were applied to the target/support docs, or were already present at same-or-greater detail where noted by the support pages.

Applied target changes:

- [UID:0002HD] `by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md`: metadata raised to `90/92`; owner/emitter rerouted to [UID:0000J0]; item summary replaced; accepted first-draft formal C++ inserted in the header block; B001 source-quality reanalysis section added with MCP session `80de0a67`, exact boundary/padding, callers, helper decisions, field decisions, raw-helper disposition, negative evidence, reconstruction notes, and updated score rationale.

Applied support changes:

- [UID:0000J0] `by-file/EmployeeDialogPane.md`: proposed contents, IDA evidence, ownership notes, follow-up notes, and changes now record [UID:0002HD] as a file-local static/stdcall parser helper emitted through `EmployeeDialogPane.cpp`, with [UID:000138] kept as aggregate/source-family context.
- [UID:00004C] `by-class/EmployeeDialogPane.md`: method map, evidence notes, ownership synthesis, score rationale, and changes now clarify that `DeserializeEmployeeRecord` is a file-local helper used by class packet/load paths, not an `EmployeeDialogPane::` method.
- [UID:0001UD] `by-type/by-struct/EmployeeRecord.md`: `+0x414` row/evidence/open-question/change notes now preserve the accepted `dataField3` / `serverDataField3` provisional disposition and state that it does not block [UID:0002HD] first-draft parser C++.
- [UID:000138] `by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md`: aggregate status/covered range/ownership/changes now record that [UID:0002HD] owns first-draft C++ through [UID:0000J0], while the aggregate remains blank C++ support/range context.

Manual exclusions:

- No generated reports, project-level generated files, or manual `-coverage-report.md` files were edited by B001.
- No PacketBuffer, MemoryMan, or CRT formatting docs were edited because the accepted report found their helper names already sufficient.

Lease result:

- B001 leased the five edited by-* docs immediately before editing. The cleanup unlease command returned `Rejected[No active lease]` for each path because no active B001 leases remained by cleanup time. A later `tools/leaser/Agents/Agent-B001/current_leases.md` read showed only unrelated B009 zlib leases, confirming no active B001 lease remained.

## Follow-Up Actions

Supervisor should now verify each checklist item against the changed docs. If verification passes, supervisor should execute/archive the report through the current validator executed-report workflow and apply any still-needed manual coverage-report update.

## Confidence

Overall report confidence: high.

Main cap: `EmployeeRecord +0x414` has no current consumer-specific semantic name. This prevents final-audit scoring but does not justify blank C++ or aggregate-only routing.

## Validator Results

Report-only pass: no validators were run because no by-* or coverage files were edited.

Implementation callback validators were run from `source-3/project-documentation`; all exited `0` with `ok: 1`.

> Executable block R001 was removed from this report and preserved verbatim in [0002HD-DeserializeEmployeeRecord-source-quality-removed.md](0002HD-DeserializeEmployeeRecord-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Generated refresh state was deferred for each scoped validation. B001 did not rely on refreshed generated output for implementation verification.

## Changed Files

Report-only pass changed only:

- `tools/leaser/Agents/Agent-B001/research/0002HD-DeserializeEmployeeRecord-source-quality.md`

Implementation callback changed:

- `by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md`
- `by-file/EmployeeDialogPane.md`
- `by-class/EmployeeDialogPane.md`
- `by-type/by-struct/EmployeeRecord.md`
- `by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md`
- `tools/leaser/Agents/Agent-B001/research/0002HD-DeserializeEmployeeRecord-source-quality.md`

Validator-driven side effects were reported for validator state/projected stats. No generated files or `-coverage-report.md` files were edited manually by B001.

## Implementation Tracking Checklist

Supervisor validation phase:

- [x] Supervisor reviewed report quality under Rule 26/supervisor standard. Proof: implementation callback received in B001 `goal.md`.
- [x] Supervisor accepted the owner/emitter reroute to [UID:0000J0] or sent exact correction. Proof: `goal.md` accepted disposition explicitly reroutes owner/emitter to [UID:0000J0].
- [x] Supervisor accepted the `90/92` score recommendation or sent exact correction. Proof: `goal.md` accepted disposition raises [UID:0002HD] to `90/92`.
- [x] Supervisor accepted the formal first-draft C++ block or sent exact correction. Proof: `goal.md` supplied the accepted exact formal C++ block.
- [x] Supervisor accepted the `EmployeeRecord +0x414` provisional naming disposition or sent exact correction. Proof: `goal.md` accepted `dataField3` / `serverDataField3` support-note disposition.

Implementation callback phase, to be completed only after supervisor approval:

- [x] Lease target [UID:0002HD] immediately before editing, edit it, validate it, and release the lease immediately after the edit/validator batch. Proof: B001 lease command succeeded for the target and four support docs; cleanup unlease found no active B001 leases, and later current lease report showed only unrelated B009 zlib leases.
- [x] Update target header metadata to `90/92`, owner/emitter [UID:0000J0], reconstructable `TRUE`. Proof: target header now has `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000J0`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000J0`.
- [x] Insert the accepted formal C++ block into the target header. Proof: target `RECONSTRUCTION_CPP CODE` block contains the accepted `static int __stdcall DeserializeEmployeeRecord(...)` body.
- [x] Update target summary, behavior, evidence, source-placement, score-rationale, and changes sections with the accepted report details. Proof: target item summary replaced and `2026-06-26 B001 Source-Quality Reanalysis`, reconstruction notes, score rationale, and changes sections now contain the accepted details.
- [x] Update [UID:0000J0] support note if supervisor accepts that support edit. Proof: file page proposed contents, IDA evidence, ownership notes, follow-up notes, and changes now record [UID:0002HD] as a file-local emitting helper.
- [x] Update [UID:00004C] support note if supervisor accepts that support edit. Proof: class method map/evidence/ownership/score/changes now clarify [UID:0002HD] is a file-local helper, not a class method.
- [x] Update [UID:0001UD] support note for `+0x414` if supervisor accepts that support edit. Proof: struct layout/evidence/open questions/changes now document `dataField3` / `serverDataField3`.
- [x] Update [UID:000138] support note if supervisor accepts that support edit. Proof: aggregate status/covered range/ownership/changes now record [UID:0002HD] as emitting through [UID:0000J0] while aggregate C++ stays blank.
- [x] Do not edit generated files or any `-coverage-report.md` file. Proof: no manual generated or coverage edits were made by B001.
- [x] Run scoped validators for every changed by-* file. Proof: commands `000000003675` through `000000003679` all exited `0` with `ok: 1`.
- [x] Record validator commands/results in this report. Proof: `Validator Results` section updated with command IDs, timestamps, exit status, ok counts, warnings, and deferred generated-refresh state.
- [x] Report `FINISHED_IMPLEMENTATION` only after edits, validators, checklist proof, and lease releases are complete. Proof: this checklist is complete from B001 side and current lease report shows no active B001 leases.

Supervisor-owned after implementation:

- [ ] Verify every implementation claim against changed files.
- [ ] Move this report to `Agent-B001/research/executed/`.
- [ ] Apply the accepted `by-memory/-coverage-report.md` row if needed.
- [ ] Validate `by-memory/-coverage-report.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002HD-DeserializeEmployeeRecord-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0002HD-DeserializeEmployeeRecord-source-quality.md","timestamp":"2026-06-26T23:27:55","uid":"0002HD"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002HD-DeserializeEmployeeRecord-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0002HD-DeserializeEmployeeRecord-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002HD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
