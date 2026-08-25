** TARGET-REPORT-UID:0004A1 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0004A1 SpellMacroEditControlPaneGetSpellKey Source Quality Research

## Finalized Report / Current Recommendation

- Current implemented recommendation: UID0004A1 remains the source-authored, nonvirtual, public const accessor owned and emitted by UID0000DQ `SpellMacroEditControlPane`; the target, complete class declaration, and constructor now use the lifecycle-consistent `wchar_t` spelling.
- Final disposition: exact range `[0x0057f750,0x0057f758)`, one eight-byte function, one two-instruction basic block, unique byte signature, direct AX return from complete-object `+0x108`, one direct caller, no data/vtable route, and source placement in UID0000KY `MacroDialogs`.
- Callback state: supervisor Gate 1 accepted report SHA256 `8C60D1A1A6412A80536D98558197BD4B984AC5EB69D2E4B22B1945CCCFEF264E`; Destinations 1-3 and C01-C40 are applied or verified; UID0004A1 is `92/94`, UID0000DQ is `92/94`, UID0004A2 remains `90/93`, all accepted metadata is preserved, seven ordinary pages passed scoped validation, and final waited generated refresh command `000000014382` passed.
- Confidence: very strong for range, bytes, ABI, field offset/width, caller, constructor, storage lifecycle, owner/emitter, source file, source order, and nesting; strong for the exact `wchar_t`, `GetSpellKey`, and `m_spellKey` lexical spellings because stripped symbols cannot distinguish machine-equivalent two-byte source types or prove private names.

## Supporting Research

- Assignment-time basis: the then-current `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`, listed UID0004A1 at `86/90`, reconstructable true, report count `0`. The callback validator now projects `92/94`; this sentence preserves the historical queue trigger rather than asserting the current tracker score.
- Exact old-report search terms used: `0004A1`, `UID0004A1`, `0x0057f750`, `0057f750`, `SpellMacroEditControlPaneGetSpellKey`, `SpellMacroEditControlPane::GetSpellKey`, `sub_57F750`, `GetSpellKey`, `m_spellKey`, `SpellMacroEditControlPane`, `SpellMacroDialog`, `m_legacyShortcutText`, `MacroEditControlPanes`, and `MacroDialogs`.
- Exact roots searched:
  - central `executed-b-agent-research/**`;
  - active `tools/leaser/Agents/Agent-B001/research` through `Agent-B005/research`;
  - `archived/**`;
  - `tools/leaser/Agents/Older-Research/**`.
- Direct target/address/name matches were opened and classified:
  - `executed-b-agent-research/B001/0001IK-MacroEditControlPanes-empty-emitter-source-quality.md`: direct parent/split support, not a UID0004A1 target-specific report. It established the exact child range, direct Spell class route, caller, and padding, but its integer type was provisional.
  - `executed-b-agent-research/B003/0004A5-SpellMacroEditControlPaneIsSelectable-source-quality.md`: direct class, layout, EventHandler, vtable, constructor, input, and adjacent-boundary support. Its `unsigned short` field spelling was a lifecycle-incomplete class hypothesis and is superseded by the complete storage/persistence/runtime evidence here.
  - `executed-b-agent-research/B003/00049G-SpellMacroDialogNonDeletingDestructor-source-quality.md`: direct Spell dialog/class/source-order support, including the current complete Spell edit-control declaration and `GetSpellKey` caller family. It is not a direct target report.
  - `executed-b-agent-research/B010/0001DR-MacroDialogs-source-quality.md`: direct caller and storage-family support. It established the Spell dialog constructor/confirm paths and legacy shortcut rows but did not perform this target-specific type audit.
  - `executed-b-agent-research/B005/0001AV-SaveUserSettings-empty-emitter-source-quality.md`: direct persistence support. It proves serialization section 2 writes one wide character from each legacy shortcut row.
  - `executed-b-agent-research/B002/0003UJ-UserPaneTryDispatchFunctionKeyShortcut-source-quality.md`: direct retained runtime consumer support. It declares the legacy shortcut element as `wchar_t`, reads the first code unit, and performs the established alphabetic slot mapping.
  - `executed-b-agent-research/B005/0004A6-NewMacroEditControlPaneGetKey-source-quality.md`: sibling accessor methodology and MacroDialogs generated/type consistency support. It targets the distinct compact record table and is not duplicate coverage.
- Broader family-term matches were treated as incidental unless they touched the exact range, Spell class, caller, legacy table, persistence, or runtime consumer. No active B001-B005 report, archived report, older-research report, or central executed report is a prior direct UID0004A1 source-quality report.
- Evidence-based prior-report conclusion: direct target report count is genuinely zero. Existing reports are support leads whose adopted facts were independently checked against current MCP and current documentation.
- No Wave2/Wave3/simroot artifact was used as current authority. Historical Wave2 and stale generated-source references remain useful search provenance only and are explicitly superseded where current evidence is stronger.

## Target

- Target UID: `0004A1`.
- Target path: `by-memory/0x0057f750-0x0057f758.SpellMacroEditControlPaneGetSpellKey.md`.
- Historical source queue/report row at assignment: `86/90`, weighted `88.0`, reconstructable true, zero reports.
- Current supervisor classification: accepted same-report implementation callback complete; independent Gate 2 review and any later lifecycle action remain supervisor-owned external state.
- Current scores and parent state:
  - UID0004A1 target: `92/94`, owner/emitter UID0000DQ, reconstructable true, blank optional position, `Nested:1`.
  - UID0000DQ class: `92/94`, owner/emitter route UID0000KY, reconstructable true, source-local blank position.
  - UID0001IK parent: `91/93`, owner UID0000KY, reconstructable false, blank emitter/position/formal, `Nested:-4`.
  - UID0000KY file: `92/92`, path `NexusTK/ui/dialogs/`.

## Current Target State

- Current target metadata preserves UID, path, exact half-open range, direct class owner/emitter UID0000DQ, reconstructable true, blank optional position, and relative `Nested:1`; only the accepted score rose to `92/94`.
- Current target formal is Destination 1 byte-for-byte and returns `wchar_t`.
- Current class formal is Destination 2 byte-for-byte, closes before `[[CHILDREN]]`, and uses `wchar_t` for the constructor parameter, getter return, and `m_spellKey`; the class score is `92/94`.
- Current constructor formal is Destination 3 byte-for-byte with `wchar_t`; its `90/93` score and all metadata remain unchanged.
- Current generated `auto-generated/NexusTK/ui/dialogs/MacroDialogs.cpp`, validator command `000000014382`, refreshed `2026-07-16T16:37:07-04:00`, SHA256 `7806CD50205A5FFC277B8F108B5824DF43940C4C43FF92653EC775F530D0C80F`, 34,750 bytes / 1,048 physical lines, verifies the completed closure:
  - one complete UID0000DQ declaration closes before child definitions;
  - class constructor/getter/field and UID0004A1 definition use `wchar_t`;
  - exactly one UID0004A1 getter and one UID0004A2 constructor are emitted;
  - the unchanged UID00049H route stores the getter result into `m_legacyShortcutText[row][0]` and clears `[row][1]`;
  - no UID0004A1 Empty Emitter Marker, stale Spell `uint16_t`/`unsigned short` API spelling, raw `+0x108`, vptr, explicit-padding member, duplicate class, or decompiler-shaped source exists.
- The target page now records exact bytes/hash, CFG/ABI, unique signature, exact caller instruction/storage order, complete constructor/input/paint/persistence/runtime lifecycle, name/type ranking, vtable/data negatives, history, and score defense at report-level detail.
- Related target/support docs checked: UID0000DQ, UID0004A2, UID0004A3, UID0004A4, UID0004A5, UID00049F, UID00049H, UID0000DP, UID0001IK, UID0000KY, UID000031 Config, UID0001VR profile layout, UID0003UJ runtime consumer, UID0001AV persistence writer, UID0001Y1 vtable family, UID0003DB vtable data, ignored padding, manual coverage, generated MacroDialogs source, generated by-memory coverage, and the tracker.
- Current artifact/lifecycle status: the authorized implementation callback modified the seven ordinary pages listed under Changed Files and validator-owned generated/registry/projected-stat state was refreshed by commands `14375`-`14382`. B005 did not manually edit manual coverage, generated output, tracker, audit, validator state, lifecycle state, archive, goal, supervisor files, or IDA; did not run or probe `execute_report` or any lifecycle command; and holds zero leases.

## Executive Recommendation

- Direct owner/emitter UID0000DQ, source file UID0000KY, established names/access, exact range, `Nested:1`, and all non-score metadata were retained.
- `wchar_t` is now consistent across the accessor, field, and constructor parameter.
- No split, merge, rename, new UID, endpoint change, padding change, source-route move, third-party import, or IDA mutation occurred.
- Target `92/94`, class `92/94`, constructor `90/93`, and every other support score remain exactly as accepted.
- All three managed blocks are applied exactly. Target-independent vtable, destructor, thunk, padding, persistence, dialog, and Config bodies remain unchanged.

## Supervisor Active Recheck

- Trigger and accepted basis: the supervisor assigned UID0004A1 from the reconstructable not-covered queue, accepted exact report SHA256 `8C60D1A1A6412A80536D98558197BD4B984AC5EB69D2E4B22B1945CCCFEF264E`, and authorized C01-C40 plus Destinations 1-3.
- Split-first result remains verified: IDA models one exact function at the target start and current ignored coverage owns both surrounding alignment regions.
- Source-bearing closure is applied: the target, complete class declaration, and constructor received the only literal C++ changes; paint/input/parent/file pages received bounded prose synchronization; all other dependencies were verified without edit.
- No accepted item is blocked or deferred. Remaining original lexical uncertainty is explicitly confidence-capped and does not affect behavior, ABI, layout, owner/emitter, nesting, source placement, compile legality, or generated output.

## Inference Research Guidance Check

- IDA facts: exact function start/size, bytes, instruction sequence, AX return, receiver offset, CFG, caller, xrefs, constructor stores, allocation size, vtable stores, and alignment.
- Documentation facts: complete Config declaration, profile layout, Spell dialog constructor/save bodies, input/paint bodies, persistence writer, retained runtime consumer, current class/file routes, generated output, and manual coverage.
- Inference: `wchar_t`, `GetSpellKey`, `m_spellKey`, public/protected/private access placement, and the exact header/source lexical style.
- Existing assumptions treated as uncertain and rechecked: target `uint16_t`, class/constructor `unsigned short`, generic "word field", source name alternatives involving key/code/index/slot, possible vtable membership, possible Config/SpellMacroDialog ownership, and whether `Nested:1` was a count rather than a cumulative relative delta.
- `by-structure.md` controls the conclusion: the direct declaring class owns the method, compiler-generated vtable/destructor artifacts remain separate, the exact target emits only its own method, and manual coverage remains supervisor-owned.
- Wave2/Wave3/simroot material was found only in historical/support provenance. It was ignored as current authority.

## Heuristic / Inference Reanalysis And Validation

### Function identity, ABI, and behavior

1. IDA models `sub_57F750` at exact size `0x8`.
2. Exact bytes are `66 8B 81 08 01 00 00 C3`; target-byte SHA256 is `48919BF9FED91392EA24887A075D1492489C2EBE7AD9F5A47F791C6E33C93F94`.
3. Disassembly is one word load from complete-object `+0x108` followed by return.
4. The function has one basic block, cyclomatic complexity `1`, no callee, no string, no branch, no local, and no side effect.
5. The scalar returns in `AX`. No sign-extension or zero-extension instruction fixes a signed or unsigned arithmetic interpretation inside this function.
6. IDA's `__int16` and `_WORD *` types are decompiler placeholders. They prove width, not original source spelling or signedness.

### Direct caller and data lifecycle

1. The sole target xref is code call `0x0053ed27` inside UID00049H `SpellMacroDialog::OnControlCommand`.
2. The caller handles only control index `1`, loops ten child controls `2..11`, and calls the accessor on each row.
3. The caller stores `AX` directly into `g_pConfig + 0x28e89c + row * 0x100`, then stores a zero word at the next element.
4. Decompiler temporaries start from `0x200` and use constants `0x28e69c` / `0x28e69e`; the effective first-row address is `0x200 + 0x28e69c = 0x28e89c`. Decimal-to-hex values `2680476 -> 0x28e69c`, `2680478 -> 0x28e69e`, `2680988 -> 0x28e89c`, `256 -> 0x100`, and `512 -> 0x200` were verified with `tools/int_convert.py`.
5. UID00049F constructs each Spell row from `m_legacyShortcutText[row][0]`.
6. UID0004A2 stores the constructor argument at `+0x108`.
7. UID0004A4 accepts only ASCII letters from the key/text event path, widens the accepted byte, and stores it at `+0x108`.
8. UID0004A3 reads `m_spellKey` for normalization, spell-record selection, and display formatting.
9. UID0001AV serialization section 2 writes one wide character from each `m_legacyShortcutText` row with `fputwc`.
10. UID0003UJ later reads the same first element as `const wchar_t`, performs low-byte alphabetic classification, and maps the full wide code unit into legacy command slots.
11. The complete lifecycle therefore treats the field as a wide character/code unit, not an arithmetic counter, opaque integer id, record index, slot ordinal, or bitfield.

### Source type ranking

1. `wchar_t` is the strongest source-facing type:
   - exact two-byte width on this x86/MSVC binary;
   - direct construction from a `wchar_t[10][0x80]` element;
   - direct save back into that element;
   - wide-character persistence through `fputwc`;
   - direct retained runtime declaration as `wchar_t`;
   - input path widens ASCII keyboard input into the field;
   - display paths treat the value as a spell-key character/code.
2. `unsigned short` is ABI-compatible but weaker source shape. It records machine width while discarding the direct wide-character producer, persistence, and consumer contract.
3. `uint16_t` is ABI-compatible but least plausible for this source family. It is a modern fixed-width storage spelling that contradicts the established late-1990s/mid-2000s Windows wide-character table/API.
4. Signed `short` is rejected because no arithmetic uses signed ordering and every current storage/runtime declaration treats the element as a wide code unit.
5. `char`/`unsigned char` are rejected by the word load/store and two-byte table element.
6. An enum is rejected because the accepted values are keyboard letters persisted as wide characters and no enum conversion or bounded domain exists.

### Source name ranking

1. Retain `GetSpellKey`.
   - It is established across the parent split, Spell dialog caller, class/file docs, generated source, normalization/format helpers, and historical source-family vocabulary.
   - It distinguishes the Spell row from NewMacroEditControlPane's generic compact `GetKey`.
2. Retain `m_spellKey`.
   - The class edits and displays a spell-specific key, and the caller stores it in the legacy shortcut table.
   - `m_key` loses the class-specific semantic distinction; `m_code` is storage-facing rather than control-facing; `m_slot`/`m_index` imply arithmetic record selection not present here.
3. Reject `GetSpellCode`, `GetSpellIndex`, `GetSpellSlot`, `GetKeyCode`, and `GetShortcutKey`; no symbol, helper family, storage field, or caller vocabulary supports them better.
4. Exact original spelling is unavailable. The retained names are high-probability descriptive source names, not claimed PDB proof.

### Class layout and access

| Offset | Source model | Evidence/disposition |
| --- | --- | --- |
| `+0x000..+0x107` | inherited `ControlPane` | Constructor calls the ControlPane constructor; current class support closes inherited storage at `0x108`. |
| `+0x0a0` | inherited EventHandler secondary view | Constructor and RTTI/vtable support store the secondary table there. |
| `+0x0a4` | inherited tertiary view | Constructor and RTTI/vtable support store the tertiary table there. |
| `+0x0ff` | inherited `m_controlFlags` | Constructor writes byte `1`; not a Spell-private field. |
| `+0x108..+0x109` | `wchar_t m_spellKey` | Getter, constructor, input, paint, dialog construction/save, persistence, and runtime consumer converge. |
| `+0x10a..+0x10b` | natural tail alignment | Spell dialog allocates `0x10c`; no source member accesses these bytes. |

- Public constructor/getter are required by external SpellMacroDialog construction and save calls.
- Protected paint/EventHandler overrides match the current inherited interface declaration.
- Private field is the least exposed source shape; no external direct field access exists.
- The const getter is behaviorally exact because it reads state only.
- No explicit destructor declaration/body is required by this target. Existing complete-object destructor glue, adjustor thunks, and scalar deleting wrapper remain compiler consequences documented separately.

### Ownership, source placement, and order

- UID0000DQ is the narrow semantic owner: the receiver is a SpellMacroEditControlPane and the field is private class state.
- UID0000KY is the correct source file: class declaration, constructor, paint/input methods, caller dialog, vtable family, parent split, and generated order all converge on MacroDialogs.
- UID0000DP SpellMacroDialog is a consumer, not the accessor owner.
- UID000031 Config owns storage, not the UI method.
- UID0001VR documents a storage slice, not a standalone source owner.
- A free/static helper is rejected by the receiver field access and member caller.
- The class remains source-local with blank optional position; deterministic positioned classes remain `10/20/30/40/50/60`.

### Range, nesting, and compiler boundary

- Predecessor `[0x0057f742,0x0057f750)` is fourteen `0xcc` bytes already listed in ignored coverage.
- Successor `[0x0057f758,0x0057f760)` is eight `0xcc` bytes already listed in the MacroEditControlPane internal padding group.
- No xref targets the exclusive end.
- UID0004A2 starts independently at `0x0057f760`.
- The exact signature is unique; no duplicate target body was found.
- `Nested:1` is a cumulative relative-delta fact, not a child count. It moves from the parent row to its first child level. Later siblings use zero deltas.
- No vtable cell points to UID0004A1. Vtable data routes paint, EventHandler methods, and compiler destructors only.

### Rejected source shapes

- Blank/no-code target: rejected because the sole direct caller requires an out-of-line body and current generated output already emits it.
- Covered-by class marker only: rejected because a distinct source-authored member definition exists.
- Inline-only declaration with target body removed: rejected because the original binary retains a distinct out-of-line function and one direct call.
- Virtual accessor: rejected by zero data/vtable xrefs and the complete vtable inventory.
- Raw-offset accessor, cast, union overlay, explicit padding field, vptr member, or decompiler-shaped `_WORD` source: rejected as reverse-engineering scaffolding.
- Separate Spell key helper file: rejected by class-local receiver, source island, and MacroDialogs family.

### Remaining uncertainty

- Original symbol spelling, exact header split, and exact access labels are not recoverable from current artifacts.
- This uncertainty is nonblocking because the selected declaration is compile-legal, ABI/layout exact, consistent with the complete lifecycle, and source-clean.
- The uncertainty caps confidence at `94`, not completion or emission eligibility.

## Evidence Standards Used

- Mandatory live IDA MCP: fresh `initialize`, `tools/list`, `idb_list`, `server_health`, bounded `lookup_funcs`, `get_bytes`, `analyze_function`, `xrefs_to`, `make_signature`, and range signature calls.
- Direct binary evidence: exact bytes/hash, instructions, AX return, function size, CFG, caller, constructor stores, direct xrefs, vtable negatives, and surrounding padding.
- Structural evidence: exact `0x10c` allocation, inherited `0x108` base boundary, constructor/input/paint field accesses, class declaration, parent split, vtable family, and generated source order.
- Lifecycle evidence: legacy table construction, editing, save/terminator write, persistence, and retained runtime dispatch.
- Documentation evidence: current by-* pages, current generated MacroDialogs source, manual coverage, generated by-memory coverage, tracker, and matching executed B reports.
- Negative evidence: no alternate caller, no target data/vtable xref, no duplicate signature/body, no endpoint xref, no wider access, no separate setter, no arithmetic role, no independent source file, and no prior direct report.
- Evidence ladder: binary facts control behavior/ABI/range; complete storage lifecycle controls source type; current project naming/source-family conventions control descriptive lexical choices; stripped-name uncertainty limits confidence only.

## Evidence Checked

- Fresh MCP session discovery:
  - `idb_list` returned one active/adopted/owned session `64c11373` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `21508`, `is_analyzing:false`.
  - `server_health(database=64c11373)` returned `status=ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, 2,067 strings.
- Bounded target MCP:
  - `lookup_funcs` for `0x0057f750`, `0x0053ecf0`, and `0x0057f760`;
  - `get_bytes` for `[0x0057f742,0x0057f760)`;
  - `analyze_function` for the target, sole caller, and constructor;
  - `xrefs_to` for target start and exclusive end;
  - exact function and range signatures with operands retained.
- Current binary: `E:\NTK\Resources\NexusTK\NexusTK.exe`, 2,679,296 bytes, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- Current docs: all target/support pages named under Current Target State; manual by-memory/class/file/struct coverage; ignored padding; generated by-memory coverage; generated MacroDialogs.cpp; tracker.
- Historical reports: all exact matches classified under Supporting Research.
- Numeric conversion: relevant decimal decompiler constants were checked with `tools/int_convert.py`.
- Negative checks: target duplicate/signature, alternate xrefs, endpoint xref, vtable/data route, ownership alternatives, type alternatives, range overlap, padding duplication, and manual-row state.
- Failed checks: one local PowerShell `Invoke-WebRequest` attempt required `-UseBasicParsing`; this was a client invocation issue before MCP parsing. One helper-script attempt serialized MCP `arguments` incorrectly and returned schema errors; it was discarded. Fresh raw JSON calls then succeeded. No valid bounded IDB-backed request failed.
- Report-only phase intentionally skipped IDA mutation, symbol rename, type application, comment change, validator, generated refresh, lease command, report lifecycle command, and broad whole-image text scans. During the separately authorized callback, only the seven accepted ordinary pages were leased/edited/scoped-validated; one final waited generated refresh was run; IDA and report lifecycle remained untouched.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0004A1 is exact range `[0x0057f750,0x0057f758)`, size 8. | Very strong | Applied to target Status/Evidence; scoped validator `14375` exit 0/ok 1; target SHA `236FB1...5236E`. | UID0004A1 Status/Evidence | incorporate | applied |
| C02 | Exact bytes and target SHA are `66 8B 81 08 01 00 00 C3` / `48919B...F94`. | Very strong | Applied to target exact-binary evidence; validator `14375`; current target hash recorded below. | UID0004A1 Evidence | incorporate | applied |
| C03 | Body is one word load from `this+0x108`, AX return, one block, complexity 1. | Very strong | Applied to target behavior/ABI and confirmed by generated Destination 1 under command `14382`. | UID0004A1 Behavior/ABI | incorporate | applied |
| C04 | IDA `_WORD`/`__int16` types prove width only, not source signedness/type. | Very strong | Historicalized in target type analysis; Destination 1 now uses lifecycle-backed `wchar_t`. | UID0004A1 Type analysis | historicalize | applied |
| C05 | Exact signature is unique; no duplicate source body exists. | Very strong | Applied to target positive/negative evidence; generated command `14382` emits exactly one getter. | UID0004A1 Evidence/negative | incorporate | applied |
| C06 | Sole direct target caller is `0x0053ed27` in UID00049H. | Very strong | Applied to target caller inventory; UID00049H verify-only hash remains `C5CE21...27FE`. | UID0004A1 Caller inventory | incorporate | applied |
| C07 | Caller loops controls 2..11, writes AX then zero terminator into ten legacy rows. | Very strong | Applied to target evidence; generated command `14382` preserves one direct getter call/store and `[row][1] = 0`. | UID0004A1/UID00049H support | incorporate | applied |
| C08 | Effective storage base is Config `+0x28e89c`, row stride `0x100`. | Very strong | Applied to target storage evidence; UID0001VR verify-only hash remains `3A449A...AB8`. | UID0004A1/UID0001VR support | incorporate | applied |
| C09 | Spell dialog constructor seeds rows from the same first legacy wchar element. | Very strong | UID00049F remained unchanged at hash `A5C40D...4225`; target/class/constructor lifecycle now cites it. | UID0004A1/UID00049F support | already-present | already-present |
| C10 | UID0004A2 stores a two-byte constructor argument at `+0x108`. | Very strong | Applied with `wchar_t` provenance/layout rationale; scoped validator `14377` exit 0/ok 1. | UID0004A2 Evidence | incorporate | applied |
| C11 | Spell dialog allocates exact `0x10c` row objects. | Very strong | Applied to class/constructor layout closure; validators `14376`/`14377`; generated class remains natural `0x10c`. | UID0000DQ/UID0004A2 | incorporate | applied |
| C12 | UID0004A4 writes widened ASCII key input to `m_spellKey`. | Very strong | Wide-character lifecycle applied without formal/score change; scoped validator `14379` exit 0/ok 1. | UID0004A4 prose | incorporate | applied |
| C13 | UID0004A3 reads the field for spell normalization and formatting. | Very strong | Lifecycle and historical type disposition applied without formal/score change; validator `14378` exit 0/ok 1. | UID0004A3 prose | incorporate | applied |
| C14 | SaveUserSettings section 2 persists one wide character per legacy row. | Very strong | UID0001AV remained unchanged at hash `FB2B12...9935`; incorporated as target/class/support evidence. | UID0004A1 evidence; UID0001AV verify-only | already-present | already-present |
| C15 | UID0003UJ reads the same first element as `wchar_t` at runtime. | Very strong | UID0003UJ remained unchanged at hash `088DEE...5B70`; class validator canonicalized its link path as a reference-index side effect. | UID0004A1 evidence; UID0003UJ verify-only | already-present | already-present |
| C16 | Strongest source type is `wchar_t`. | Strong | Applied byte-for-byte in Destinations 1-3; validators `14375`-`14377`; generated command `14382` confirms all declarations/definitions. | Destinations 1-3 | incorporate | applied |
| C17 | Current `uint16_t` target spelling is ABI-correct but source-stale. | Strong | Historicalized in target; generated output has zero stale Spell target `uint16_t` spelling. | UID0004A1 history | historicalize | applied |
| C18 | Current `unsigned short` class/constructor spelling is ABI-correct but source-stale. | Strong | Historicalized in class/constructor; generated output has zero stale Spell API/field `unsigned short` spelling. | UID0000DQ/UID0004A2 history | historicalize | applied |
| C19 | Signed short, byte, int, enum, slot/index types are rejected. | Strong | Rejected alternatives preserved in target/class/constructor with no raw/decompiler source introduced. | Target/class negative evidence | reject-invalid | applied |
| C20 | Retain source-facing method name `GetSpellKey`. | Strong | Name preserved in all three formals and generated output. | Destinations 1-2 | already-present | already-present |
| C21 | Retain private source-facing field name `m_spellKey`. | Strong | Name and private access preserved in Destination 2 and generated class. | Destinations 2-3 | already-present | already-present |
| C22 | Getter remains public and const; field remains private. | Strong | Complete class surface preserved byte-for-byte in Destination 2; validator `14376`. | Destination 2 | already-present | already-present |
| C23 | UID0000DQ remains direct owner/emitter. | Very strong | Target/class/children metadata unchanged; validators and generated route confirm UID0000DQ ownership. | Target metadata/class | already-present | already-present |
| C24 | UID0000KY remains file route; Spell class remains source-local. | Very strong | File path/order/blank by-file formal preserved; validators `14380`/`14381`; generated route remains MacroDialogs. | UID0000KY/UID0000DQ | already-present | already-present |
| C25 | Target has no data/vtable xref and remains nonvirtual. | Very strong | Applied to target negatives; vtable support verify-only hashes unchanged. | UID0004A1 negative evidence | incorporate | applied |
| C26 | No split, merge, rename, new UID, or endpoint change is required. | Very strong | All seven physical paths/UIDs/ranges retained; no UID allocation or rename command occurred. | UID0004A1/UID0001IK | already-present | already-present |
| C27 | Retain `Nested:1` as the first child relative delta. | Very strong | Target `Nested:1` and parent `Nested:-4` preserved; validator `14375` accepted. | UID0004A1 metadata | already-present | already-present |
| C28 | Both adjacent padding spans remain ignored and must not be duplicated. | Very strong | `by-memory/-ignored.md` unchanged at hash `C4875C...DFE9`; each accepted span remains present once. | UID0000VN verify-only | already-present | already-present |
| C29 | Raise UID0004A1 from `86/90` to `92/94`. | Strong | Applied by scoped validator `14375`; generated metadata shows `92/94`. | UID0004A1 metadata | incorporate | applied |
| C30 | Raise UID0000DQ from `91/93` to `92/94`. | Strong | Applied by scoped validator `14376`; generated class metadata shows `92/94`. | UID0000DQ metadata | incorporate | applied |
| C31 | Keep UID0004A2 at `90/93`; synchronize type/formal/evidence only. | Strong | Applied exactly; validator `14377`; current constructor remains `90/93`. | UID0004A2 | incorporate | applied |
| C32 | Apply Destination 1 exactly to UID0004A1. | Strong | Target formal matches report block byte-for-byte; validator `14375`; generated one getter. | UID0004A1 formal | incorporate | applied |
| C33 | Apply Destination 2 exactly to UID0000DQ with class closed before children. | Strong | Class formal matches report block byte-for-byte; validator `14376`; generated class closes before UID0004A1. | UID0000DQ formal | incorporate | applied |
| C34 | Apply Destination 3 exactly to UID0004A2. | Strong | Constructor formal matches report block byte-for-byte; validator `14377`; generated one constructor. | UID0004A2 formal | incorporate | applied |
| C35 | Replace target Item Summary with exact bytes/caller/storage/negative summary. | Strong | Exact accepted Item Summary applied; validator `14375`. | UID0004A1 Item Summary | incorporate | applied |
| C36 | Synchronize UID0004A3/UID0004A4 and UID0001IK/UID0000KY prose without score/route changes. | Strong | Applied at report-level detail; validators `14378`-`14381`; all four scores/formals/routes preserved. | Four support pages | incorporate | applied |
| C37 | Verify UID00049F/UID00049H/UID0000DP/Config/profile/save/runtime/vtable pages unchanged at same-or-greater detail. | Very strong | Current hashes match the accepted baselines listed under Changed Files; no verify-only page was edited. | Verify-only support set | already-present | already-present |
| C38 | Insert exact UID0004A1 manual by-memory row after UID0001IK and before UID0004A2. | Strong | Exact row and placement remain supplied below; B005 did not edit supervisor-owned coverage. | Supervisor-owned by-memory coverage | incorporate | excluded-with-reason |
| C39 | Replace exact UID0000DQ manual class row with `92%` wchar lifecycle union. | Strong | Exact no-loss replacement remains supplied below; B005 did not edit supervisor-owned coverage. | Supervisor-owned by-class coverage | incorporate | excluded-with-reason |
| C40 | Historical Gate 1 phase changed only this report; the authorized callback changed only accepted ordinary pages, while manual coverage and lifecycle remained supervisor-owned; third-party import is not applicable. | Very strong | Report history retained; commands `14375`-`14382` and seven changed pages recorded; no coverage/lifecycle/IDA mutation or report execution occurred. | Report/checklist | historicalize | applied |

## Positive Evidence Summary

- Exact eight-byte modeled function with unique full signature and one live direct caller.
- Complete caller sequence writes the returned word directly to the first element of ten legacy shortcut wide-string rows and writes a zero terminator.
- Constructor, input handler, paint path, dialog construction, save handler, persistence writer, and retained runtime consumer all converge on the same `+0x108` two-byte code unit.
- Complete current Config declaration and profile layout identify the direct storage as `wchar_t[10][0x80]`.
- Existing MacroDialogs class/file/parent/vtable routes already establish owner, emitter, source file, order, inheritance, and compiler boundary.
- The inference chain is sufficient because source type is resolved by producer/persistence/consumer semantics, while exact codegen and layout remain unchanged.

## IDA MCP Facts

- Database session: `64c11373`, active NexusTK IDB, worker PID `21508`.
- Health at evidence collection: `ok`; auto-analysis, Hex-Rays, and strings cache ready.
- Target: `sub_57F750`, address `0x57f750`, size `0x8`.
- Target prototype lead: `__int16 __thiscall(_WORD *this)`; source type intentionally not adopted.
- Instructions:
  - `0x0057f750`: load word from receiver `+0x108` into AX.
  - `0x0057f757`: return.
- CFG: one basic block, cyclomatic complexity one.
- Exact bytes/signature: `66 8B 81 08 01 00 00 C3`, unique.
- Xrefs: one code xref at `0x0053ed27`; zero xrefs to `0x0057f758`.
- Caller: `sub_53ECF0`, size `0x8a`, six blocks, complexity four, vtable-routed through data cell `0x00620df4`.
- Constructor: `sub_57F760`, size `0x49`, one block; two calls at `0x0053eac5` and `0x0053ec1d`; stores argument word at `+0x108`; writes inherited `+0xff`; vptr stores are compiler output.
- Padding: fourteen `0xcc` bytes before target and eight `0xcc` bytes after target.
- Negative IDA facts: no target data xref, no target vtable xref, no callee, no string, no branch, no duplicate signature, no exclusive-end xref, no separate setter, and no alternate modeled entry.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0057f742-0x0057f750` | UID0000VN `by-memory/-ignored.md` | predecessor alignment | no | prior SpellInventory island | `100/strong` | verify unchanged |
| `0x0057f750-0x0057f758` | UID0004A1 target | Spell key accessor | yes | UID0001IK / UID0000DQ | `92/94` | Destination 1 applied/validated |
| `0x0057f758-0x0057f760` | UID0000VN `by-memory/-ignored.md` | internal alignment | no | UID0001IK split island | `100/strong` | verify unchanged |
| `0x0057f760-0x0057f7a9` | UID0004A2 constructor | Spell row constructor | yes | UID0001IK / UID0000DQ | `90/93` | Destination 3 applied/validated |
| `0x0057f7b0-0x0057f7ce` | UID0001IL | compiler complete-object destructor glue | no | UID0001IK / UID0000DQ | `88/92` | verify no-code |
| `0x0057f7d0-0x0057f927` | UID0004A3 | paint method | yes | UID0001IK / UID0000DQ | `88/91` | prose synchronized/validated |
| `0x0057f930-0x0057f998` | UID0004A4 | key/text handler | yes | UID0001IK / UID0000DQ | `92/94` | prose synchronized/validated |
| `0x0057f9a0-0x0057f9a5` | UID0004A5 | pointer/mouse handler | yes | UID0001IK / UID0000DQ | `91/94` | verify unchanged |
| Spell class declaration | UID0000DQ | complete class/source cause | yes | UID0000KY | `92/94` | Destination 2 applied/validated |
| Macro edit-control parent | UID0001IK | non-emitting split index | no | UID0000KY | `91/93` | bounded type/history synchronization validated |
| Macro source file | UID0000KY | family source route | yes | file root | `92/92` | bounded type/generated synchronization validated |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0053ed27` | UID00049H calls UID0004A1 | sole direct accessor call |
| `0x0053ed2c` | stores AX at effective Config `+0x28e89c + row*0x100` | first wide element of legacy row |
| `0x0053ed36` | stores zero at next word | terminates the row |
| `0x0053eac5` | UID00049F calls UID0004A2 | first Spell layout branch row construction |
| `0x0053ec1d` | UID00049F calls UID0004A2 | second Spell layout branch row construction |
| `0x0057f778` | UID0004A2 stores constructor word at `+0x108` | field initialization |
| UID0004A4 | stores accepted ASCII key at `+0x108` | interactive mutation |
| UID0004A3 | reads field for normalization/formatting | display consumer |
| UID0001AV section 2 | `fputwc` from each legacy row first element | persistence consumer |
| UID0003UJ | reads legacy first element as `wchar_t` | retained runtime consumer |
| `0x0062d250` / `0x0062d254` | Spell EventHandler vtable cells | route sibling handlers, not accessor |

## Documentation Evidence And IDA Status

- Current target page identifies owner/emitter, exact behavior, bytes/hash, caller/storage order, lifecycle, negatives, history, and score rationale at final `92/94`; Destination 1 is installed.
- Current class page is structurally complete at `92/94`, closes before `[[CHILDREN]]`, and uses `wchar_t` consistently; Destination 2 is installed.
- UID0004A2 remains `90/93` with Destination 3 and the accepted argument provenance/layout-neutral type rationale.
- UID0004A3 and UID0004A4 preserve their exact formals/scores while documenting the same wide-character spell-key lifecycle and superseded generic-word history.
- UID0001IK preserves its non-emitting split inventory, metadata, complete family union, and historical Wave2 lead while using current lifecycle-backed `wchar_t` wording for UID0004A1.
- UID0000KY preserves the complete MacroDialogs family, path, source order, score, and compiler boundary while adding current Spell type and generated assertions alongside the existing New key consistency checks.
- UID00049F, UID00049H, UID0000DP, Config, profile layout, SaveUserSettings, and UID0003UJ already provide same-or-greater lifecycle facts and need no formal changes.
- UID0001Y1 and UID0003DB correctly omit the accessor from virtual slots.
- Generated command `14373` is retained as the historical report-only snapshot that exposed the mixed integer spelling. Final authorized waited command `14382` is the current callback checkpoint and verifies the exact accepted source closure.
- MCP was healthy throughout the valid bounded research evidence pass. The callback required no IDA mutation or additional MCP-dependent conclusion.

## Ranked Ownership Analysis

### 1. UID0000DQ SpellMacroEditControlPane

- Evidence for: receiver field at class-local `+0x108`; matching constructor, paint, input, caller, class declaration, allocation size, and source family; current owner/emitter already correct.
- Evidence against: exact original class/header spelling is stripped.
- Decision: retain as direct owner and emitter.

### 2. UID0000DP SpellMacroDialog

- Evidence for: sole caller and all row construction/save logic live in SpellMacroDialog.
- Evidence against: dialog obtains child objects and calls a public member; it does not own the child's private field or method body.
- Decision: consumer/support only.

### 3. UID000031 Config / UID0001VR profile layout

- Evidence for: owns the persistent legacy shortcut table that supplies and receives the value.
- Evidence against: storage ownership does not transfer ownership of a UI member operating on a distinct receiver.
- Decision: storage/type support only.

### 4. UID0000KY MacroDialogs file

- Evidence for: source-family route, address clustering, complete class declarations, caller dialogs, vtables, generated output, and deterministic source order.
- Evidence against: exact original physical grouping of every generation remains inferred.
- Decision: retain as file owner/route; confidence caveat already belongs at file level.

### 5. Free/static helper or new file

- Evidence for: none beyond the method's tiny body.
- Evidence against: explicit receiver field access, established class member call, complete class declaration, and source island.
- Decision: reject.

### Proposed new file/grouping, if applicable

- Not applicable. No new file or grouping is justified.

## Source Placement

- Recommended placement: the accessor definition remains under UID0000DQ in UID0000KY `NexusTK/ui/dialogs/MacroDialogs.cpp`.
- The class declaration remains source-local immediately before its children; no artificial emitter position is introduced.
- This placement fits the Spell dialog caller, Spell edit-control constructor/paint/input cluster, MacroDialogs vtables, parent split, and generated source order.
- Rejected placements: Config/RegistryConfig, SpellMacroDialog class, separate key helper, generic input helper, profile storage, UserPane, or new source file.
- Remaining placement uncertainty: only whether the historical original project split some generations into separate physical files. That file-level caveat does not affect the current accepted source-family route.

## Range / Split / Padding / Reclassification Analysis

- Exact target range is already correct and complete.
- No child creation, merge, rename, or endpoint repair is needed.
- Predecessor alignment `[0x0057f742,0x0057f750)` is already documented once in ignored coverage.
- Successor alignment `[0x0057f758,0x0057f760)` is already documented once in the MacroEditControlPane padding group.
- UID0004A2 starts at `0x0057f760`; no overlap exists.
- UID0001IK remains a non-emitting split inventory. UID0004A1 remains its first exact source child and retains `Nested:1`.
- Reclassification to compiler/no-code, raw helper, inline duplicate, or covered-by marker is rejected by the modeled function, live caller, unique bytes, and required emitted definition.

## Negative Evidence Summary

- No target vtable cell or data pointer exists.
- No second code caller exists.
- No xref targets the exclusive end.
- No duplicate exact signature/body exists.
- No four-byte field access, pointer access, arithmetic counter use, slot/index operation, or bit test exists.
- No source path supports Config, RegistryConfig, SpellMacroDialog, UserPane, or a free helper as the method owner.
- No evidence supports a virtual getter, setter pair, static helper, inline-only removal, or raw-offset accessor.
- Nearby address alone does not transfer ownership from the Spell edit-control class to the broad parent aggregate.
- Persistence and runtime consumers corroborate source type but do not own the UI method.
- Historical Wave2/simroot names are not current proof.

## IDA Rename / Type / Comment Recommendations

- Source-facing method name: retain `SpellMacroEditControlPane::GetSpellKey`.
- Source-facing field: retain `m_spellKey`.
- Source-facing type: use `wchar_t` consistently for getter return, constructor parameter, and private field.
- IDA display type: the current `_WORD`/`__int16` decompiler type is not source authority. A future supervisor-approved IDA type could use the class method's `wchar_t` return/field model, but this assignment requests no IDA mutation.
- IDA rename: no database rename is required. The established descriptive method name is already sufficient in documentation.
- Comments: if a future IDA comment is desired, it should state that the field is the legacy wide-character spell shortcut code stored in Config rows, not a numeric spell id. No IDA comment is applied here.

## First-Draft C++ Recommendation

- Applied C++ status: the target is a live source-authored method with complete class and constructor dependencies, and all three accepted destination-specific managed blocks are installed and validated.
- Exactly three destination-specific managed blocks apply; the blocks below match the current ordinary formals byte-for-byte.

Destination 1: `by-memory/0x0057f750-0x0057f758.SpellMacroEditControlPaneGetSpellKey.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
wchar_t SpellMacroEditControlPane::GetSpellKey() const
{
    return m_spellKey;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 2: `by-class/SpellMacroEditControlPane.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
struct RectBounds;

class SpellMacroEditControlPane : public ControlPane
{
public:
    SpellMacroEditControlPane(wchar_t spellKey, const RectBounds &bounds);

    wchar_t GetSpellKey() const;

protected:
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    wchar_t m_spellKey;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 3: `by-memory/0x0057f760-0x0057f7a9.SpellMacroEditControlPaneConstructor.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
SpellMacroEditControlPane::SpellMacroEditControlPane(
    wchar_t spellKey,
    const RectBounds &bounds)
    : ControlPane(8, &bounds),
      m_spellKey(spellKey)
{
    m_controlFlags = 1;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact behavior preservation: `wchar_t` remains two bytes on the target ABI; all loads, stores, AX return, object size, offsets, alignment, call homes, and caller writes remain unchanged.
- Human source shape: ordinary class declaration, constructor initializer, private field, const getter, and no raw offsets, casts, vptrs, padding members, decompiler labels, or ABI annotations.
- Naming style: follows existing MacroDialogs `m_` member convention and the established `GetSpellKey`/`NormalizeSpellKey`/`FormatSpellKey` vocabulary.
- Third-party import: not applicable. This is NexusTK project source, not a static embedded third-party library.
- No-code proof: not applicable because the target is eligible and requires source.

## Final Recommendation

- The three managed blocks are applied exactly.
- UID0004A1 is `92/94`, UID0000DQ is `92/94`, and UID0004A2 remains `90/93`.
- Target path/title/range/UID, UID0000DQ owner/emitter, reconstructable true, blank optional position, `Nested:1`, UID0000KY route, and source-local class position are preserved.
- Full target evidence, exact Item Summary, type/name ranking, lifecycle, negatives, history, and score rationale are incorporated.
- UID0004A3, UID0004A4, UID0001IK, and UID0000KY carry bounded `wchar_t` lifecycle synchronization without score/route/formal loss.
- UID00049F, UID00049H, UID0000DP, Config/profile/persistence/runtime/vtable/compiler/padding support is verified unchanged at the hashes below.
- Compiler destructor glue, thunks, scalar deleting wrapper, vtable/RTTI data, and padding remain non-emitting.
- No target-specific implementation or research item remains. Only stripped original lexical/header uncertainty remains as a confidence cap.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0057f750-0x0057f758.SpellMacroEditControlPaneGetSpellKey.md`.
- Applied metadata:
  - `COMPLETION:92`
  - `CONFIDENCE:94`
  - retain owner/emitter UID0000DQ;
  - retain reconstructable true, blank optional position, `Nested:1`, UID/path/title/range.
- Destination 1 is applied exactly and scoped validator `14375` passed.
- Exact Item Summary:
  - `Exact two-instruction SpellMacroEditControlPane wchar_t spell-key accessor loading the +0x108 field into AX; sole SpellMacroDialog OnControlCommand caller stores it unchanged into Config::m_legacyShortcutText[row][0], with unique bytes/signature, exact alignment, direct class/file route, and no vtable/data xrefs.`
- Exact bytes/hash, function identity, CFG, AX ABI, unique signature, caller instruction sequence, table arithmetic, constructor/input/paint/persistence/runtime lifecycle, type/name ranking, layout/access, owner/file/nesting, padding, negative evidence, rejected alternatives, and score rationale are incorporated.
- Historical `uint16_t` is retained explicitly as an ABI-correct but source-incomplete interim spelling.

## Recommended Support Doc Changes

- `by-class/SpellMacroEditControlPane.md`
  - Raised `91/93 -> 92/94`; Destination 2 applied exactly; validator `14376` passed.
  - Layout/source prose now uses `wchar_t` wide-character spell key while preserving the exact `0x10c` layout, inheritance, EventHandler facets, method inventory, compiler destructor/thunk separation, current history, and unrelated evidence.
  - Complete construction/edit/display/save/persistence/runtime lifecycle and superseded integer source spellings are recorded.
- UID0004A2 `by-memory/0x0057f760-0x0057f7a9.SpellMacroEditControlPaneConstructor.md`
  - Remains `90/93` with all metadata; Destination 3 and exact argument/type rationale applied; validator `14377` passed.
- UID0004A3 paint page
  - Score/metadata/formal preserved; bounded lifecycle evidence applied; validator `14378` passed.
- UID0004A4 key/text page
  - Score/metadata/formal and exact ASCII behavior preserved; current field wording and lifecycle synchronized; validator `14379` passed.
- UID0001IK parent
  - Score/metadata/blank formal/child inventory/nesting preserved; UID0004A1 and representative evidence synchronized to lifecycle-backed `wchar_t`; Wave2 retained only as history; validator `14380` passed.
- UID0000KY file
  - Score/path/source order and complete family/caveat union preserved; Spell type/generated assertions synchronized; scoped validator `14381` and waited refresh `14382` passed.
- Verify-only/no edit absent contradiction:
  - UID00049F, UID00049H, UID0000DP;
  - UID000031 Config and its file;
  - UID0001VR profile layout;
  - UID0001AV persistence writer;
  - UID0003UJ runtime consumer;
  - UID0001Y1/UID0003DB vtable support;
  - UID0001IL/UID0001IN/UID0004AW compiler support;
  - `by-memory/-ignored.md`.

## Score And Metadata Recommendation

- Historical target at assignment: `86/90`; current target: `92/94`, with UID0000DQ owner/emitter, true, blank position, `Nested:1`, and all other metadata unchanged.
- Historical class at assignment: `91/93`; current class: `92/94`, with route/position/reconstructable unchanged.
- Constructor remains `90/93`; all other support scores remain unchanged.
- Reason target rises:
  - exact bytes/hash/function/CFG blocker closed;
  - ABI/return-width blocker closed;
  - direct caller and storage-order blocker closed;
  - field offset/layout blocker closed;
  - constructor/input/paint lifecycle blocker closed;
  - persistence/runtime type blocker closed;
  - source name/type blocker closed;
  - vtable/direct-call blocker closed;
  - owner/emitter/file/order/nesting blocker closed;
  - padding/range/duplicate blocker closed;
  - formal C++ blocker closed.
- Reason not higher than `92/94`: original symbols, exact access labels, header split, and machine-equivalent two-byte typedef spelling cannot be proven independently of lifecycle inference.
- Reason not lower: no behavioral, ABI, layout, caller, source-placement, nesting, or compile-shape blocker remains.
- No owner, emitter, reconstructable, optional-position, nested, range, path, title, UID, or source-path field changes are recommended.

## Open Questions With Attempted Resolution

- Is the source type `wchar_t`, `unsigned short`, or `uint16_t`?
  - Checked exact width, constructor, input writer, paint reader, dialog constructor/save, Config declaration, persistence, and runtime consumer.
  - Resolution: `wchar_t`; integer spellings are ABI-equivalent historical alternatives.
- Is the value a spell id/index/slot rather than a character key?
  - Checked accepted input domain, persistence format, normalization/format helper vocabulary, and runtime mapping.
  - Resolution: spell shortcut key code unit, not numeric spell identity or row index.
- Should the name change from `GetSpellKey`?
  - Checked current class/caller/file vocabulary, historical reports, helper names, and sibling API.
  - Resolution: retain `GetSpellKey`.
- Should the field change from `m_spellKey`?
  - Checked UI class role versus storage terminology.
  - Resolution: retain `m_spellKey`; `m_code` belongs to storage-facing terminology, and index/slot names are behaviorally wrong.
- Is the getter virtual?
  - Checked all xrefs and complete vtable inventories.
  - Resolution: no; ordinary nonvirtual out-of-line member.
- Is `Nested:1` correct?
  - Checked address-sorted manual/generated coverage and cumulative delta semantics.
  - Resolution: yes; it is the first child delta, not a child count.
- Does `wchar_t` alter ABI or layout?
  - Checked x86/MSVC width, allocation, offsets, and call/store shape.
  - Resolution: no.
- Any unresolved implementation blocker?
  - None. Original lexical/header certainty is unavailable but has no code, metadata, or score-blocking effect beyond confidence `94`.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Current read-only manual snapshots:
  - `by-memory/-coverage-report.md`: SHA256 `30F60936189CDAD073D983B5AE1ABE471886D6181B3F903AE6E6499004618774`, 1,787,242 bytes / 4,275 lines.
  - `by-class/-coverage-report.md`: SHA256 `CE04212A8854D587A6E31295068010D3E8EAD1DC33185451619C96FC1D496345`, 230,653 bytes / 622 lines.
  - `by-file/-coverage-report.md`: SHA256 `280C5E3D281D8166B3950851F0E450F841A54623A20D02C7514FE221C4E14E57`, 132,360 bytes / 316 lines.
  - `by-type/by-struct/-coverage-report.md`: SHA256 `1B794F9B0E9AD32D6A0901FC69E9CA99C6F335B26D50E12881DEDFAC4C6F80A6`, 57,045 bytes / 137 lines.
- Current by-memory placement:
  - line 3201 is UID0001IK;
  - UID0004A1 is absent;
  - line 3202 is UID0004A2.
- Exact by-memory insertion after UID0001IK and before UID0004A2:

```text
        - [UID:0004A1][0x0057f750-0x0057f758.SpellMacroEditControlPaneGetSpellKey](by-memory/0x0057f750-0x0057f758.SpellMacroEditControlPaneGetSpellKey.md) 0x0057f750-0x0057f758 | method | SpellMacroEditControlPaneGetSpellKey : reconstructable : 92% : very-strong : Exact two-instruction SpellMacroEditControlPane wchar_t spell-key accessor loading the +0x108 field into AX; sole SpellMacroDialog OnControlCommand caller stores it unchanged into Config m_legacyShortcutText[row][0], with unique bytes/signature, exact alignment, direct class/file route, and no vtable/data xrefs.
```

- Current by-class UID0000DQ row is line 515 at `91%` and says generic `word field`.
- Exact by-class replacement:

```text
- [UID:0000DQ][SpellMacroEditControlPane](by-class/SpellMacroEditControlPane.md) : reconstructable : 92% : very-strong : Complete natural 0x10c ControlPane-derived spell macro row declaration with wchar_t spell-key field/API at +0x108, constructor/getter/paint/EventHandler overrides, exact legacy-shortcut constructor/save/input/paint/persistence/runtime lifecycle, natural tail alignment, implicit destructor/compiler-glue split, vtable views, caller routes, and MacroDialogs ownership.
```

- Verify-only manual rows:
  - UID0001IK already accurately describes the non-emitting split inventory and does not assert the stale target type.
  - UID0004A2/UID0004A4/UID0004A5 rows do not require score/state/path changes.
  - UID0000KY already accurately describes the broad source family and `92%` score; target-specific type detail belongs in ordinary file prose.
  - UID0001VR already states exact `wchar_t[10][0x80]` legacy rows and needs no replacement.
  - UID00049F/UID00049H have no separate current manual insertion requirement from this unchanged-score callback.
- Generated tracker/by-memory coverage is validator-owned; no manual tracker text is supplied.
- B005 must not apply these rows directly because manual coverage is supervisor-owned.

## Follow-Up Actions

- B005's accepted implementation responsibilities are complete. C01-C40 and Destinations 1-3 are applied, verified, or excluded solely because manual coverage is supervisor-owned.
- The exact manual by-memory insertion and by-class replacement below remain a durable supervisor-owned handoff. Their application and any report execution/archive state are external lifecycle facts, not pending B005 report work.
- Current generated assertions from command `14382`:
  - one complete UID0000DQ class closed before UID0004A1 and other child definitions;
  - one UID0004A1 getter definition and one UID0004A2 constructor definition;
  - class/getter/constructor/field all use `wchar_t`;
  - one unchanged UID00049H call and direct legacy-table store;
  - zero UID0004A1 Empty Emitter Markers;
  - zero stale Spell getter/constructor/field `uint16_t` or `unsigned short` spellings;
  - zero raw `+0x108`, vptr, explicit-padding, duplicate class, or decompiler-shaped source.
- A-agent action: none.
- B005 future research or implementation action: none for this target absent a concrete supervisor repair instruction.

## Confidence

- Recommendation confidence: `94/100`.
- Exact behavior/range/ABI confidence: `99/100`.
- Field offset/width/layout confidence: `99/100`.
- Owner/emitter/source-file/nesting confidence: `97/100`.
- Source type confidence: `94/100`.
- Method/field lexical confidence: `87/100`.
- Remaining uncertainty: original private symbol spelling, access labels, header split, and indistinguishable ABI typedef spelling. None affects implementation readiness.

## Validator Results

- Historical report-only phase: no validator or lease command was run before Gate 1; MCP calls were research evidence, not validators.
- Accepted implementation callback validators:

| Command | Timestamp | Scope | Exit / ok | Result and side effects |
| --- | --- | --- | --- | --- |
| `000000014375` | `2026-07-16T16:30:27-04:00` | UID0004A1 target | `0 / 1` | Applied `92/94`, exact formal/summary/evidence; registry/reference/projected-stat updates; generated refresh deferred. |
| `000000014376` | `2026-07-16T16:32:50-04:00` | UID0000DQ class | `0 / 1` | Applied `92/94` and Destination 2; validator canonicalized the UID0003UJ link target in the edited class page; generated refresh deferred. |
| `000000014377` | `2026-07-16T16:33:28-04:00` | UID0004A2 constructor | `0 / 1` | Applied Destination 3 and provenance/history with `90/93` unchanged; generated refresh deferred. |
| `000000014378` | `2026-07-16T16:34:08-04:00` | UID0004A3 paint | `0 / 1` | Applied lifecycle/history prose with score/formal unchanged; generated refresh deferred. |
| `000000014379` | `2026-07-16T16:34:35-04:00` | UID0004A4 key/text | `0 / 1` | Applied lifecycle/history prose with score/formal unchanged; generated refresh deferred. |
| `000000014380` | `2026-07-16T16:35:40-04:00` | UID0001IK parent | `0 / 1` | Applied bounded Spell type/history/source-closure union with metadata/formal/children unchanged; generated refresh deferred. |
| `000000014381` | `2026-07-16T16:36:52-04:00` | UID0000KY file | `0 / 1` | Applied bounded Spell lifecycle/generated assertions with `92/92`, path, order, and family union unchanged; generated refresh deferred. |
| `000000014382` | `2026-07-16T16:37:07-04:00` | UID0000KY file, `--wait-generated` | `0 / 1` | Final generated refresh completed; registry rebuilt with 5,092 nodes/4,100 edges; 280 generated metadata outputs refreshed. Pre-existing project-wide warnings were reported as 13 fallback child insertions, 85 missing child markers, and 142 emitters with no code; none is a UID0004A1 error. |

- Every ordinary validator was run while only that ordinary page was leased; each lease was released immediately after its scoped validator. The final waited refresh ran with zero leases.
- Current generated MacroDialogs snapshot is command `14382`, timestamp `2026-07-16T16:37:07-04:00`, SHA256 `7806CD50205A5FFC277B8F108B5824DF43940C4C43FF92653EC775F530D0C80F`, 34,750 bytes / 1,048 physical lines.
- Historical command `14373` remains the report-only mixed-type snapshot; command `14382` supersedes it as callback proof.
- Unresolved validator errors: none. All eight commands exited zero with `ok:1`.
- Leases: B005 holds zero. Unrelated agents may independently hold leases outside this accepted callback scope; no such lease was acquired, altered, or overridden by B005.

## Changed Files

- Historical creation/current callback artifact:
  - `tools/leaser/Agents/Agent-B005/research/0004A1-SpellMacroEditControlPaneGetSpellKey-source-quality.md`
- Direct ordinary by-* files modified by B005:
  - `by-memory/0x0057f750-0x0057f758.SpellMacroEditControlPaneGetSpellKey.md`
  - `by-class/SpellMacroEditControlPane.md`
  - `by-memory/0x0057f760-0x0057f7a9.SpellMacroEditControlPaneConstructor.md`
  - `by-memory/0x0057f7d0-0x0057f927.SpellMacroEditControlPaneOnPaint.md`
  - `by-memory/0x0057f930-0x0057f998.SpellMacroEditControlPaneHandleKeyOrTextEvent.md`
  - `by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md`
  - `by-file/MacroDialogs.md`
- Validator-owned side effects: registry/reference/projected-stat state was updated by scoped commands, and final command `14382` refreshed generated metadata. B005 did not manually edit generated or validator-owned files. `auto-generated/NexusTK/ui/dialogs/MacroDialogs.cpp` was inspected read-only after refresh.
- Modified manual coverage/tracker/audit/supervisor/lifecycle/IDA files: none.
- Renamed/moved/deleted files: none.
- Report execution: not run or probed.
- Current callback hashes:

| Path | SHA256 |
| --- | --- |
| UID0004A1 target | `236FB1F1217E2A0E669F075A0BC72C47B45B58D86DCCDAD689FF2B2AA695236E` |
| UID0000DQ class | `65B7BEBACE03ED2A32636E50E6153936CB6333FC475DB5D46C5D9CD72FFCD02E` |
| UID0004A2 constructor | `2F90E8D34A3433282FC9F20E514A8010A38C3FF01FCB2D47236B5DCF7D85778E` |
| UID0004A3 paint | `A7741F5CDA0EB278E71D20F7166B0AFBA679F23D583C2B2B5088CF1F4333DB3F` |
| UID0004A4 key/text | `C60AA709757A955CE187EA91BF3CE4B4B7D1BA4FDF5E2D7F7E0493BE81D45145` |
| UID0001IK parent | `543C25D41D95F4C61B48006CF9BD5CF7D970DADD92039B121DDDCC44AB99F3E7` |
| UID0000KY file | `88BA4D31E430DE47374C90102116FA89E715A9420BE57962EAE20B31458BF105` |
| UID00049F Spell dialog constructor | `A5C40D4166734A3A618E07D2294BC3F803680FD2811D0E0279D0870F5CE14225` |
| UID00049H Spell dialog command | `C5CE21263FEAC63EDB7810B2CED013F2C4D5620B35C239A16D0AA17D7ACD27FE` |
| UID0000DP Spell dialog class | `9AABA3AEBB5BBCDB620F6E4E4A01ECEEB334AC625D86FD3FEFC9D203F82FA8D2` |
| Config class | `9ECA99799904B0DD1E6D14E0C84DC784B578E2C31555C3AD7472C9B7A304B473` |
| Config file | `91984E67C9F7E99F2252203A65C892654531030AF190C7DAB7E2F0497FE3D577` |
| UID0001VR profile layout | `3A449A0CB8645B26CA76842C6E3C5D491C6079669CC443AC4DC10E25197B3AB8` |
| UID0003UJ runtime consumer | `088DEEC72AAD5B6EB54A076387D6BCC0FAE1E3703540981765E6537BC01A5B70` |
| UID0001AV persistence writer | `FB2B12DC5E3871AB18C218260E097797C92AC098360174BFD7167BB401859935` |
| UID0001Y1 vtable family | `0D6E643E14F6318656F52572DEE48AB3AAE4BCBE341007180AEE7CA2DEF697E0` |
| UID0003DB vtable data | `D5D87A8A4E9085F673697F302CDB9DD8F58DE2FC700FFBF95D180FC8E2D000C0` |
| UID0001IL teardown glue | `0D079B986F09A929C77977D7884FBA49473A60AC388C643667D4A414497A9DE4` |
| UID0001IN thunks | `724FC0C34FFA7AE164504F28ED2707566B1E1D093D19DA87F767FA3CCF4B7171` |
| UID0004AW scalar wrapper | `69390E6E1717196FF210D7FB9245B7163D4D5507FD47B0293D13E1B51A940E15` |
| ignored padding | `C4875C9DB2BAEF070BE1E0EDFE9268918E93596311CA038F6195764F7D1BDFE9` |
| generated MacroDialogs.cpp command 14382 | `7806CD50205A5FFC277B8F108B5824DF43940C4C43FF92653EC775F530D0C80F` |

- Manual coverage remained read-only and unchanged:
  - by-memory `30F60936189CDAD073D983B5AE1ABE471886D6181B3F903AE6E6499004618774`;
  - by-class `CE04212A8854D587A6E31295068010D3E8EAD1DC33185451619C96FC1D496345`;
  - by-file `280C5E3D281D8166B3950851F0E450F841A54623A20D02C7514FE221C4E14E57`;
  - by-struct `1B794F9B0E9AD32D6A0901FC69E9CA99C6F335B26D50E12881DEDFAC4C6F80A6`.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 accepted exact report SHA `8C60D1A1A6412A80536D98558197BD4B984AC5EB69D2E4B22B1945CCCFEF264E`.
- [x] C01-C40 retain legal actions and now use legal terminal callback verification states.
- [x] UID0004A1 is `92/94` with owner/emitter UID0000DQ, true, blank position, and `Nested:1` retained.
- [x] Destination 1 is applied exactly.
- [x] The exact target Item Summary is applied.
- [x] Target bytes/hash/function/CFG/ABI/signature/caller/xref/padding evidence is incorporated at report-level detail.
- [x] Target constructor/input/paint/dialog-save/persistence/runtime lifecycle is incorporated.
- [x] Source type/name/access ranking and rejected alternatives/history are preserved.
- [x] UID0000DQ is `92/94` with Destination 2 applied exactly.
- [x] UID0000DQ complete class surface, inheritance, layout, methods, compiler history, and class closure before `[[CHILDREN]]` are preserved.
- [x] UID0004A2 remains `90/93`; Destination 3 and exact argument/storage/type evidence are applied.
- [x] UID0004A3 paint prose is synchronized without score/formal change.
- [x] UID0004A4 key/text prose is synchronized without score/formal change.
- [x] UID0001IK target row/type/history is synchronized without metadata/formal/child loss.
- [x] UID0000KY Spell type/generated assertions are synchronized without score/path/family loss.
- [x] UID00049F/UID00049H/UID0000DP are verified same-or-greater and unchanged.
- [x] Config/profile/SaveUserSettings/UID0003UJ lifecycle support is verified same-or-greater and unchanged.
- [x] UID0001Y1/UID0003DB/UID0001IL/UID0001IN/UID0004AW compiler/vtable support is verified unchanged.
- [x] Both ignored padding ranges remain present once with no duplication.
- [x] Target path/title/range/UID, owner/emitter, reconstructable state, blank position, and cumulative nesting are preserved.
- [x] No split, merge, rename, new UID, source-route move, IDA mutation, or third-party import occurred.
- [x] One scoped validator ran per changed ordinary page under one short lease at a time.
- [x] Each lease was released immediately after its scoped validator.
- [x] Final authorized `--wait-generated` MacroDialogs refresh command `14382` completed after all ordinary validators passed.
- [x] Exact generated class/type/definition/count/order/marker/no-raw-source assertions pass.
- [x] Exact supervisor-owned manual by-memory insertion and by-class replacement are preserved; coverage was not edited.
- [x] Command IDs, timestamps, exit/ok, warnings/side effects, final hashes, generated header/hash, and lease closure are recorded.
- [x] Current Target State, recommendations, C01-C40, Validator Results, Changed Files, and checklist are reconciled to callback truth.

Implementation callback pass:
- [x] The accepted report was used for this same-report implementation callback.
- [x] All accepted target/support details are incorporated at report-level detail.
- [x] C01-C40 have legal callback verification states with destination/validator/generated proof.
- [x] Destinations 1-3 match accepted report blocks and current ordinary formals byte-for-byte.
- [x] Metadata/score/type/history/support changes are applied exactly or excluded with the supervisor-owned coverage reason.
- [x] Historical assumptions, rejected alternatives, and negative evidence are preserved.
- [x] Open questions remain closed with only lexical confidence caps.
- [x] Every changed ordinary page passed scoped validation and every lease is released.
- [x] Final waited generated refresh passes all exact assertions.
- [x] Exact manual coverage handoff remains supervisor-owned and unedited by B005.
- [x] No accepted item remains blocked or unapplied.
- [x] No report execution, lifecycle probe/action, move, archive, manual generated edit, coverage edit, tracker edit, audit edit, supervisor edit, manual validator-state edit, or IDA mutation occurred.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000014400","destination_path":"executed-b-agent-research/B005/0004A1-SpellMacroEditControlPaneGetSpellKey-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0004A1-SpellMacroEditControlPaneGetSpellKey-source-quality.md","timestamp":"2026-07-16T16:50:21-04:00","uid":"0004A1"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
