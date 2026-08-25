** TARGET-REPORT-UID:0004A9 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 0004A9 NewMacroEditControlPane SetShortcutIndex Source Quality


## Finalized Report / Current Recommendation

- Implemented recommendation: validator-preserving rename UID0004A9 from
  `by-memory/0x0057fa30-0x0057fa40.NewMacroEditControlPaneSetRecordIndex.md`
  to
  `by-memory/0x0057fa30-0x0057fa40.NewMacroEditControlPaneSetShortcutIndex.md`.
- Implemented disposition: retain the exact half-open range
  `[0x0057fa30,0x0057fa40)`, direct owner/emitter UID000095
  `NewMacroEditControlPane`, `RECONSTRUCTABLE:TRUE`, blank optional position,
  and `Nested:0`. Replace the stale record terminology with
  `SetShortcutIndex(int shortcutIndex)` and `int m_shortcutIndex`.
- Callback result: C01-C20 and formal Destinations R1-R5 were applied under
  the documented validator-aware UID-preserving rename workflow. The bounded
  class, constructor, paint, page-load, aggregate, file, and caller prose now
  contain the complete no-loss B001/B005 same-family union.
- Implemented score: target `86/90 -> 92/94`. All directly affected support
  scores remain unchanged in this B003-only callback.
- Confidence: very strong for behavior, ABI, width, signed type, value domain,
  owner/emitter, source file, range, and source representation; strong for the
  inferred private lexical spellings `SetShortcutIndex` and
  `m_shortcutIndex`.

## Supporting Research

- Fresh mandatory MCP evidence was collected from database session
  `64c11373`. At evidence-collection time, `idb_list` returned one active
  adopted NexusTK IDB worker, and `server_health` returned `status:ok`,
  auto-analysis ready, Hex-Rays ready, strings cache ready, image base
  `0x00400000`, and 2,067 cached strings. This is an evidence-time health fact,
  not an indefinite assertion about later MCP state.
- The analyzed executable is `NexusTK.exe`; the current binary SHA256 recorded
  during the evidence pass is
  `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`
  over 2,679,296 bytes.
- Historical-report search terms:
  `0004A9`, `UID0004A9`, `0x0057fa30`, `0057fa30`,
  `NewMacroEditControlPaneSetRecordIndex`,
  `NewMacroEditControlPaneSetShortcutIndex`, `SetRecordIndex`,
  `SetShortcutIndex`, `SetIndex`, `m_recordIndex`, `m_shortcutIndex`,
  `NewMacroEditControlPane`, and `MacroDialogs`.
- Exact roots searched:
  `source-3/project-documentation/archived/**`,
  `tools/leaser/Agents/Older-Research/**`,
  `tools/leaser/Agents/SpecialReports/**`, and
  `executed-b-agent-research/**`.
- `archived/**`, `Older-Research/**`, and `SpecialReports/**` contained no
  direct target match.
- `executed-b-agent-research/B001/0001IK-MacroEditControlPanes-empty-emitter-source-quality.md`
  is historical split/creation evidence. It supplied the original
  `SetRecordIndex` draft but did not resolve the target-specific shortcut
  ordinal semantics established here.
- `executed-b-agent-research/B005/0004A6-NewMacroEditControlPaneGetKey-source-quality.md`
  is sibling key-field support. It lists UID0004A9 as verify-only and does not
  perform this target's `+0x108` lifecycle/name audit.
- `executed-b-agent-research/B010/0001DR-MacroDialogs-source-quality.md`
  is caller/storage-family support. Its `SetRecordIndex` terminology is a
  historical lead superseded by the complete target-specific evidence below.
- `executed-b-agent-research/B003/00049G-SpellMacroDialogNonDeletingDestructor-source-quality.md`
  and
  `executed-b-agent-research/B003/0003UA-UserPaneDispatchConfiguredShortcutHotkey-source-quality.md`
  are class/runtime support leads. UID0003UA independently uses
  `shortcutIndex` for the same 20-entry compact shortcut table.
- The executed B001 predecessor
  `executed-b-agent-research/B001/0004A7-NewMacroEditControlPaneGetMode-source-quality.md`
  was reread before shared edits. Its SHA256 is
  `CCC80B0FC383785ACA6BB6BEF0DCFCCEF93D26AB838C13FC044E6210FDE32E86`;
  supervisor command `000000014451` had already completed its lifecycle. Its
  accepted `GetSpellMode`/`SetSpellMode`/`m_spellMode` unsigned-char union was
  preserved in every B003 destination.
- The executed B005 same-family artifacts were reread before shared edits:
  `executed-b-agent-research/B005/0004A1-SpellMacroEditControlPaneGetSpellKey-source-quality.md`
  at SHA256
  `D6455A66556D1DF1463BE30286C16197DB16B4B46079CE2A39F5172438DF6C56`
  and
  `executed-b-agent-research/B005/0004A6-NewMacroEditControlPaneGetKey-source-quality.md`
  at SHA256
  `AF8D895A270073F0EED4F4009AAD256F0AF9CABB515A11C553CB6858BCE283CB`.
  Their complete `wchar_t` key union and distinct Spell-row facts were
  preserved; neither artifact supplies UID0004A9 conclusions.
- The report-only collision rule is now historically satisfied. B003 waited
  for the accepted predecessor callbacks, found no conflicting B003 lease,
  reread each shared destination after acquiring its one-file lease, and
  applied the shortcut-index delta over the complete B001/B005 union without
  restoring stale mode/key tokens or dropping unrelated facts.

## Target

- Target UID: UID0004A9.
- Implemented target path:
  `by-memory/0x0057fa30-0x0057fa40.NewMacroEditControlPaneSetShortcutIndex.md`.
- Historical pre-callback path:
  `by-memory/0x0057fa30-0x0057fa40.NewMacroEditControlPaneSetRecordIndex.md`;
  that path is absent after the validator-preserving rename.
- Source queue row at assignment time: tracker `by-memory` not-covered
  reconstructable entry, `86/90`, with zero direct target reports.
- Implemented metadata: `92/94`, owner/emitter UID000095,
  `RECONSTRUCTABLE:TRUE`, blank optional position, `Nested:0`.
- Exact binary range: `[0x0057fa30,0x0057fa40)`, 16 bytes.
- Implemented source placement:
  UID0000KY `NexusTK/ui/dialogs/MacroDialogs.cpp`.

## Current Target State

- The implemented target SHA256 is
  `7204ABE607EF9F356D9D1EDD784C621678398A13F8DCF77B358E754000DFB93C`,
  6,592 bytes / 51 lines. Its managed R1 block uses
  `SetShortcutIndex(int shortcutIndex)` and writes `m_shortcutIndex`.
- The implemented target records the exact bytes/hash/signature, ABI, source
  return, field width/type/domain, closed complete-object field lifecycle,
  caller instruction order, negative routes, exact boundaries, naming
  alternatives, source placement, historical correction, and score rationale.
- Historical pre-callback state: target SHA256
  `7F558CBB475D44B0F953FDA06F7F844C55C285A75A5A3344594489EBF7ABD4CB`
  at 1,578 bytes / 30 lines used `SetRecordIndex`/`m_recordIndex`; generated
  command `000000014382` retained four `SetRecordIndex` lines and six
  `m_recordIndex` lines. Those are evidence-time defects, not current state.
- The final waited validator generated
  `auto-generated/NexusTK/ui/dialogs/MacroDialogs.cpp` under command/header
  `000000014471` at `2026-07-19T17:10:44-04:00`. The read-only file is SHA256
  `C164F22996199EB2C489AD355312436E8B8E1E38072EC19A3BD18982692E5E93`,
  35,013 bytes / 1,053 lines.
- In the current NewMacroEditControlPane segment the complete class closes
  before all qualified definitions; ten definitions have ten unique names;
  R1 and UID0004A9 occur once; the UID0004A9 Empty Emitter Marker,
  `SetRecordIndex`, `m_recordIndex`, stale `GetMode`/`SetMode`, and handwritten
  vtable/RTTI arrays occur zero times. The B005 `wchar_t m_key`/GetKey/SetKey
  and B001 `unsigned char m_spellMode`/GetSpellMode/SetSpellMode union each
  occurs exactly once where applicable.
- Current implemented ordinary snapshots are:

| Destination | SHA256 | Bytes / lines |
| --- | --- | --- |
| UID0004A9 target | `7204ABE607EF9F356D9D1EDD784C621678398A13F8DCF77B358E754000DFB93C` | 6,592 / 51 |
| UID0001IK aggregate | `BFADA166F4FA7D904D636AE05DF5492C20390057D563D3A0EBE2C61416590078` | 44,688 / 212 |
| UID000095 class | `9B21C6E2EC3C758C57D14B92F2DFE31B0185296AAA238FA7E2655F3205920FF5` | 34,799 / 234 |
| UID0000KY file | `A4D8369946F730199AE9604CAE79E140B0A4811C0E9FD172A84D516A496FD690` | 87,861 / 298 |
| UID0004A8 constructor | `AAF989933647C23859A68F49DF9BA0AA3E8434D28435517838A3135843AC36DB` | 10,196 / 127 |
| UID0004AD OnPaint | `0981F94A16ED113CC23DC6943E26E3CD7139D4182E974D853016ABAA9BCC18BF` | 7,409 / 109 |
| UID00049O LoadMacroPage | `C586D41D0E5B79A39A75B2E5AE7437B0948BD5D11200185158DEDE81E20B0F77` | 8,482 / 115 |
| UID00049J NewMacroDialog constructor | `86A3B426F5EFCA964AC9274660AB860069732315CC229982B8E41D33CD19798F` | 10,372 / 130 |
| UID000094 NewMacroDialog class | `79CC9CE34F5A59B62B70FB9A9127790771104A2B3E0E0A76DE79DD4F2F9E2F85` | 17,018 / 131 |
| UID0001VR profile layout | `3A449A0CB8645B26CA76842C6E3C5D491C6079669CC443AC4DC10E25197B3AB8` | 46,992 / 275 |
| UID0001Y1 vtable type | `0D6E643E14F6318656F52572DEE48AB3AAE4BCBE341007180AEE7CA2DEF697E0` | 38,671 / 181 |
| UID0003DB vtable data | `D5D87A8A4E9085F673697F302CDB9DD8F58DE2FC700FFBF95D180FC8E2D000C0` | 18,269 / 84 |

- Callback state: all B003-owned ordinary implementation and scoped/generated
  validation work is complete. B003 did not edit manual coverage or generated
  output directly and performed no report execution, move, archive, or other
  lifecycle command. Exact later path/count/execution/archive state remains
  external supervisor/validator-owned and is not asserted by this artifact.

## Executive Recommendation

- Rename the method and field to `SetShortcutIndex` and `m_shortcutIndex`.
- Retain `int` for the parameter/member and `void` for the source return.
- The field is the signed ordinal of one configured shortcut row, not a
  `CompactShortcutRecord` identifier or pointer. Its exact live domain is
  `0..19`: rows `0..9` display `1..9,0`, and rows `10..19` display
  `Ctrl+1..Ctrl+9,Ctrl+0`.
- Retain UID000095 as direct class owner/emitter and UID0000KY MacroDialogs as
  source-file route.
- Retain the exact range and nesting. No split, child creation, owner move,
  new helper, new struct, vtable slot, or compiler-only reclassification is
  warranted.
- UID0004A9 is now `92/94`; support scores were preserved while synchronizing
  the B003 lexical/behavioral delta.

## Supervisor Active Recheck

- Historical assignment basis: the pre-callback `86/90` page treated
  `SetRecordIndex`, `m_recordIndex`, `SetIndex`, macro-slot terminology, type,
  return, and source placement as hypotheses. The implemented target resolves
  each issue and is `92/94`.
- Split repair is not required. MCP confirms one function starts at
  `0x0057fa30`, ends at `0x0057fa40`, contains one straight-line store, and is
  bounded by already documented padding/method starts.
- Every source-bearing destination required by the target's lexical change is
  represented by a complete managed block or an exact prose-only support
  recommendation.
- Compiler/vtable, compact-record, save, input, refresh, teardown, and padding
  dependencies were rechecked and are either bounded support or verify-only
  with an exact reason.

## Inference Research Guidance Check

- `by-structure.md` requires a direct semantic class owner before a file route.
  UID000095 is the complete-object class receiver and therefore remains the
  direct owner/emitter; UID0000KY remains the file route.
- Existing names and decompiler return types were treated as uncertain.
  `SetRecordIndex`, `m_recordIndex`, and the incidental EAX result were not
  accepted merely because they already appear in generated C++.
- IDA fact: a 32-bit stack argument is stored unchanged at complete-object
  `+0x108`; the only caller computes the value from page and row; OnPaint
  interprets it as two banks of shortcut labels.
- Documentation evidence: Config exposes 20 compact shortcut records and
  runtime dispatch documentation calls the same index a `shortcutIndex`.
- Inference: `SetShortcutIndex` / `m_shortcutIndex` are the strongest
  source-facing spellings. Exact original private spelling is not recoverable,
  so this remains a high-confidence inferred name rather than original-symbol
  proof.
- Stale Wave2/Wave3 material was not used. No current explicit override
  authorizes it.

## Heuristic / Inference Reanalysis And Validation

1. Method role:
   - Direct fact: six instructions form one dword setter with `retn 4`.
   - Best source result: explicit, nonvirtual, source-authored class setter.
   - Rejected: compiler thunk/materialization. It has an ordinary class caller,
     one source field store, no receiver adjustment, and no vtable/data route.
2. Return type:
   - Hex-Rays can infer the incoming value as a result because EAX carries the
     argument into the store and remains live at return.
   - The sole caller ignores that result and overwrites EAX immediately.
   - Adjacent SetKey/SetSpellMode setters use the same load/store/return lowering.
   - Best source result: `void`; an `int` return would invent an unused API
     contract unsupported by callers or sibling naming.
3. Parameter width/type:
   - The function loads one 32-bit stack slot and stores a dword.
   - The caller sign-extends the row/control-derived value before addition,
     and OnPaint uses signed comparison against 10.
   - Best source result: `int`, not byte, word, unsigned, pointer, enum, or
     record object.
4. Receiver and offset:
   - ECX is the complete `NewMacroEditControlPane` object. There is no
     secondary-base adjustment.
   - Store destination is exactly `[ecx+0x108]`, width four.
5. Field lifecycle:
   - Constructor initializes `+0x108`.
   - UID0004A9 rewrites `+0x108` during page load.
   - OnPaint reads it three times for bank selection and decimal label
     conversion.
   - No input, key, refresh, save, teardown, or vtable function writes or
     reads this field.
6. Value semantics:
   - NewMacroDialog construction supplies row ordinals `0..9`.
   - Page load supplies `page * 10 + row`, yielding `0..19` under the two-page
     control flow.
   - OnPaint maps `0..9` to numeric shortcuts and `10..19` to Ctrl-numeric
     shortcuts. This is shortcut identity, not storage record identity.
7. Best name:
   - `shortcutIndex` matches the exact runtime table semantics and the
     independently accepted UserPane runtime vocabulary.
   - `recordIndex` is rejected because the field is never used as a
     `CompactShortcutRecord` identity outside the caller's lookup expression.
   - `SetIndex` is rejected as too generic.
   - `macroSlot` is rejected because the integrated macro-hotkey table and the
     compact shortcut table are distinct layouts and workflows.
   - `hotkeyIndex` is plausible but weaker than project-local
     `shortcutIndex`, which matches the table and caller vocabulary.
8. Access:
   - The caller is `NewMacroDialog`, a distinct class, and no friendship
     evidence exists.
   - Retain the setter in the public section of UID000095.
9. Source placement:
   - The class declaration, constructor, target, paint/input methods, caller
     dialog, vtables, and generated source order all converge on MacroDialogs.
   - Config owns the storage table but not this UI method.
10. C++ shape:
   - An ordinary void setter is exact and human-written.
   - No vptr stores, raw offsets, calling-convention syntax, decompiler
     temporaries, explicit compiler glue, or runtime bounds checks belong in
     source.

## Evidence Standards Used

- Primary evidence: fresh IDA MCP function lookup, bounded bytes, disassembly,
  decompilation, xrefs, function analysis, byte/signature searches, field-use
  search, neighboring boundaries, and PE mapping.
- Corroboration: current by-memory/by-class/by-file/by-struct/by-vtable docs,
  current generated MacroDialogs source, manual coverage rows, exact ignored
  padding, and target-specific caller/consumer formals.
- Historical reports were used only as leads and collision inventory.
- The evidence ladder is sufficient for a source-bearing recommendation
  because binary behavior, all field uses, all direct calls, layout, source
  route, and human C++ are closed. The score remains below 95 because original
  private symbol spelling and exact compiler source text are not available.

## Evidence Checked

- MCP availability:
  fresh `idb_list`, `server_health`, `lookup_funcs(0x0057fa30)`, and corrected
  bounded `get_bytes` succeeded against database `64c11373`.
- Target MCP:
  lookup, 16-byte read, disassembly, decompilation, basic-block/complexity
  analysis, xrefs-to/from, caller analysis, unique exact-byte search, unique
  signature generation, pointer-byte searches, and neighboring reads.
- Field MCP:
  complete NewMacroEditControlPane method island searched for every
  complete-object `+0x108` read/write; constructor, setter, and OnPaint were
  individually analyzed.
- Caller MCP:
  NewMacroDialog constructor, OnControlCommand page switching,
  LoadMacroPage, and compact-record address calculation were analyzed.
- Current docs:
  UID0004A9, UID000095, UID0000KY, UID0001IK, UID0004A8, UID0004A6,
  UID0004A7, UID0004AA-UID0004AF, UID00049J, UID00049N, UID00049O,
  UID000094, UID0001VR, UID0001Y1, UID0003DB, UID0001IM, UID0004AV,
  `by-memory/-ignored.md`, and generated MacroDialogs output.
- Historical roots and exact terms are recorded under Supporting Research.
- Manual coverage inspected:
  current by-memory, by-class, by-file, and by-struct manual roots and every
  target/support row listed in the exact handoff section.
- Negative checks:
  no target vtable/data xref; no raw target pointer or RVA match; no second
  caller; no alternate complete-object `+0x108` user; no post-target padding;
  no split; no Config/UserPane ownership; no integrated MacroHotkeyRecord
  conflation.
- One preliminary bounded `get_bytes` call used the wrong object key and
  returned a schema parameter error. `tools/list` was reread, the required
  `regions:{addr,size}` shape was used, and the corrected bounded read
  succeeded. No conclusion relies on the rejected call.
- IDB `0x005a3a20` is not currently modeled as a function, so this report does
  not claim a fresh decompilation there. The runtime naming corroboration
  comes from current executed documentation and exact compact-table evidence,
  not an invented MCP result.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state | Implementation proof |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | MCP session `64c11373` was healthy at evidence collection and returned a real target lookup/read. | Very strong | `idb_list`, health, lookup, corrected bounded bytes | UID0004A9 Evidence | incorporate | applied | UID0004A9 preserves the evidence-time session health, real lookup, corrected bounded-read schema, and no-fallback boundary; scoped validator `000000014459` passed. |
| C02 | UID0004A9 is exactly `[0x0057fa30,0x0057fa40)`, 16 bytes, SHA256 `8DC87C61978B33D8F886DDCB12B75FE359AEE24ED3A6083F4342DF6F99A9AD5F`. | Very strong | bytes, lookup, PE mapping | UID0004A9 Status/Evidence | incorporate | applied | Renamed UID0004A9 records the exact half-open range, decimal/hex size, bytes, file mapping, and function SHA; validator `000000014459` passed. |
| C03 | The function is one six-instruction basic block, cyclomatic complexity 1, with one dword store and `retn 4`. | Very strong | disassembly/analyze_function | UID0004A9 Behavior/ABI | incorporate | applied | UID0004A9 now records all six instructions, one block, complexity 1, exact dword store, and `retn 4`; validator `000000014459` passed. |
| C04 | ABI is x86 `thiscall`: complete-object ECX receiver, one 4-byte stack argument, no receiver adjustment. | Very strong | prologue/store/return and caller | UID0004A9 ABI | incorporate | applied | UID0004A9 ABI/source sections preserve ECX, one stack argument, no adjustment, and caller transport; validator `000000014459` passed. |
| C05 | Source return is `void`; the apparent EAX value is incidental argument transport and is ignored/overwritten by the sole caller. | Strong | target/caller/sibling setter comparison | UID0004A9 Source Quality/R1 | reject-stale | applied | R1 is a `void` setter; UID0004A9 explains why EAX is incidental and rejects an invented value return. Formal/generated parity passed under commands `000000014459` and `000000014471`. |
| C06 | `+0x108` is an `int`, stored/read as a dword and compared with signed semantics. | Very strong | target, constructor, OnPaint | UID000095 layout; UID0004A9 | incorporate | applied | UID0004A9 and UID000095 record signed `int m_shortcutIndex` at `+0x108`; R1-R4 preserve dword store/reads and signed comparisons. Validators `000000014459`, `000000014461`, `000000014463`, and `000000014464` passed. |
| C07 | All complete-object `+0x108` uses are closed: constructor write, setter write, three OnPaint reads. | Very strong | bounded method-island search | UID000095/UID0001IK/file | incorporate | applied | Class, constructor, target, OnPaint, aggregate, and file pages contain the closed lifecycle and no additional user; validators `000000014461`, `000000014463`, `000000014459`, `000000014464`, `000000014470`, and `000000014468` passed. |
| C08 | The sole direct target caller is `0x0053f26f` in UID00049O LoadMacroPage. | Very strong | xrefs/caller disassembly | UID0004A9/UID00049O | incorporate | applied | Target and LoadMacroPage record the sole call address, receiver, argument, and ignored return; validators `000000014459` and `000000014465` passed. |
| C09 | LoadMacroPage computes the signed shortcut ordinal as `page * 10 + row`, calls the target before key/mode setters and refresh, and uses rows `0..19`. | Very strong | caller disassembly/decompile/control flow | UID00049O R5/prose | incorporate | applied | R5 and UID00049O preserve early return, page update, ten-row loop, `page * 10 + row`, child ids, `0..19`, SetShortcutIndex/SetKey/SetSpellMode/Refresh order, and no invented guard; validator `000000014465` passed. |
| C10 | OnPaint interprets `0..9` as number keys and `10..19` as Ctrl-number keys with the exact zero-key special cases. | Very strong | OnPaint signed branches/literals | UID0004AD R4/prose | incorporate | applied | R4 and UID0004AD preserve the signed bank split, `1..9,0` and `Ctrl+1..Ctrl+9,Ctrl+0`, both zero cases, coordinates, and unrelated paint behavior; validator `000000014464` passed. |
| C11 | `SetShortcutIndex` / `m_shortcutIndex` are the best source-facing names; `SetRecordIndex`, `m_recordIndex`, `SetIndex`, macro slot, and record-pointer meanings are stale or weaker. | Strong | complete lifecycle and runtime vocabulary | rename target/class/support | reject-stale | applied | Validator-aware command `000000014459` preserved UID0004A9 while renaming the path/title and propagating links. All nine edited destinations use shortcut terminology and retain rejected names only as history; current generated New segment has zero stale tokens. |
| C12 | Direct owner/emitter remains UID000095 and source-file route remains UID0000KY MacroDialogs. | Very strong | receiver/class island/caller/vtable/file order | target metadata/source placement | already-present | already-present | UID0004A9 retained owner/emitter UID000095, true, blank position, `Nested:0`; UID000095 retained UID0000KY route. Scoped validators and generated command `000000014471` confirm the existing route. |
| C13 | Exact predecessor pad is `[0x0057fa2b,0x0057fa30)` five `0xcc` bytes; successor UID0004AA begins at `0x0057fa40`; no split or target-owned trailing pad exists. | Very strong | bytes/boundaries/ignored ledger | target/parent/ignored verify | incorporate | applied | UID0004A9 and UID0001IK record exact predecessor/successor boundaries and no split; both ignored rows and UID0004AA were reread unchanged. Validators `000000014459` and `000000014470` passed. |
| C14 | UID0004A9 should become `92/94`, retain owner/emitter/true/blank position/Nested0, receive the new Item Summary, and install R1. | Very strong | all target evidence | renamed UID0004A9 | incorporate | applied | UID0004A9 is `92/94` with exact retained metadata, Item Summary, evidence, and R1; validator `000000014459` passed and generated command `000000014471` emits R1 once with no marker. |
| C15 | UID000095 should retain `92/94` and receive R2 with public `SetShortcutIndex`, constructor parameter rename, and `int m_shortcutIndex` at `+0x108`. | Strong | layout/caller/access evidence | by-class/NewMacroEditControlPane.md | incorporate | applied | UID000095 retained `92/94`, owner/emitter UID0000KY and position 50; R2 contains the public setter and exact field while preserving B001 spell-mode and B005 wchar-key unions. Validator `000000014461` passed. |
| C16 | UID0004A8 should retain its current score in this B003 pass and receive R3 plus exact shortcut-ordinal constructor prose; any separately accepted B001 score/name union must be preserved. | Strong | constructor body/caller and collision audit | UID0004A8 | incorporate | applied | UID0004A8 retained `91/94` and route; R3 plus prose now use signed shortcut ordinal `0..9`, `wchar_t key`, and unsigned-char spell mode with all base/vptr/selectable/layout behavior. Validator `000000014463` passed. |
| C17 | UID0004AD should retain `88/91` and receive R4 with only the B003 shortcut-index lexical delta, preserving all paint behavior. | Strong | OnPaint full field use | UID0004AD | incorporate | applied | UID0004AD retained `88/91`, range, route, helpers, coordinates, key/spell semantics, focus behavior, and history while applying R4 shortcut names. Validator `000000014464` passed. |
| C18 | UID00049O should retain `89/92` and receive R5 plus shortcut-index wording; UID00049J gets bounded constructor-argument prose, while save/input/refresh remain verify-only. | Strong | exact caller/callee flow | UID00049O/UID00049J | incorporate | applied | UID00049O retained `89/92` and received R5/full caller proof under validator `000000014465`; UID00049J retained `90/93`, formal, route, and gained only initial `0..9` prose under `000000014466`. UID00049N/UID0004AE/UID0004AC rereads found no contradiction. |
| C19 | UID0001IK and UID0000KY must update the renamed child/inventory and exact shortcut semantics without score/route changes and without losing accepted B001/B005 unions. | Very strong | current docs and collision inventory | aggregate/file | incorporate | applied | UID0001IK retained `91/93`, false/blank formal/`Nested:-4`, all children/padding/raw/compiler facts under `000000014470`; UID0000KY retained `92/92`, route and complete Macro/Spell/New/Integrate union under `000000014468`. |
| C20 | Manual coverage needs one target insertion and four exact no-loss replacements; implementation requires scoped validation of each changed ordinary page and one waited MacroDialogs refresh with the stated uniqueness assertions. | Very strong | current manual/generated snapshots | manual handoff/checklist | incorporate | applied | Current read-only manual roots were reread and the exact one insertion/four replacement handoff is retained below. Every changed ordinary page passed its scoped validator; waited command `000000014471` passed and produced the recorded current generated hash/count/name/marker assertions. |

## Positive Evidence Summary

- Exact target bytes:
  `55 8B EC 8B 45 08 89 81 08 01 00 00 5D C2 04 00`.
- Exact target SHA256:
  `8DC87C61978B33D8F886DDCB12B75FE359AEE24ED3A6083F4342DF6F99A9AD5F`.
- The exact 16-byte sequence and generated stable signature are unique in the
  executable.
- One direct caller supplies the value computed from current page and row.
- Constructor and OnPaint close the entire `+0x108` lifecycle.
- OnPaint directly proves the two banks of shortcut labels and exact
  `0..19` semantics.
- The field has no independent record dereference, pointer arithmetic, save
  path, or storage-object semantics.
- UID000095 and MacroDialogs already satisfy owner/emitter/source gates.
- Historical pre-callback generated source already had a complete class and
  one target body, so the accepted repair concerned source vocabulary and
  documentation depth rather than a missing emitter. Current command
  `000000014471` emits the corrected class/body union and no stale marker.

## IDA MCP Facts

- Function lookup: `sub_57FA30`, start `0x0057fa30`, size `0x10`.
- Function shape:
  push EBP, establish frame, load argument from `[EBP+8]`, store EAX to
  `[ECX+0x108]`, restore EBP, `retn 4`.
- Basic blocks: 1. Cyclomatic complexity: 1. Instructions: 6.
- Target section/file mapping: executable `.text`; raw file offset
  `0x0017ee30`.
- Numeric conversions used in this report were checked with project
  conversion tooling: `0x10=16`, `0x108=264`, `0x110=272`,
  `0x1d6=470`, `0xa6=166`, and `0x17ee30=1568304`.
- Direct target xrefs: one code call at `0x0053f26f`; zero data xrefs.
- Raw absolute pointer bytes for `0x0057fa30` and raw RVA bytes for
  `0x0017fa30`: zero matches.
- Constructor `0x0057f9d0` stores its second argument at `+0x108`.
- OnPaint reads `+0x108` at `0x0057fb4a`, `0x0057fb5d`, and
  `0x0057fb78`.
- No other complete-object `+0x108` access exists in the bounded
  NewMacroEditControlPane method island.
- Predecessor boundary: constructor ends `0x0057fa2b`; five `0xcc` bytes fill
  `[0x0057fa2b,0x0057fa30)`, SHA256
  `992CF51486F901AA1AA7D1F63E18C150C9156166E08E0B9E59CC3FAF98177329`.
- Successor boundary: UID0004AA starts exactly at `0x0057fa40`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0057f9d0-0x0057fa2b` | UID0004A8 constructor | Initializes shortcut ordinal, key, and spell mode | true | UID000095 | `91/94` | R3/prose applied; B001/B005 union retained |
| `0x0057fa2b-0x0057fa30` | `by-memory/-ignored.md` | Five-byte alignment pad | false | UID0001IK | `100` ignored | already present, verify-only |
| `0x0057fa30-0x0057fa40` | UID0004A9 `...SetShortcutIndex.md` | Signed shortcut-ordinal setter | true | UID000095 | `92/94` | validator-preserving rename, R1, evidence, and score implemented |
| `0x0057fa40-0x0057fa52` | UID0004AA SetKey | Key setter | true | UID000095 | `86/90` | verify-only |
| `0x0057fa52-0x0057fa60` | `by-memory/-ignored.md` | Post-SetKey alignment | false | UID0001IK | `100` ignored | verify-only; not target padding |
| `0x0057faa0-0x0057fc76` | UID0004AD OnPaint | Shortcut label consumer | true | UID000095 | `88/91` | R4/field-name sync applied |
| `0x0053ed90-0x0053f07f` | UID00049J NewMacroDialog constructor | Creates first page rows with ordinals 0..9 | true | UID000094 | `90/93` | bounded prose applied |
| `0x0053f180-0x0053f203` | UID00049N SaveMacroEntries | Saves key/mode only | true | UID000094 | `89/92` | verify-only negative |
| `0x0053f210-0x0053f2b6` | UID00049O LoadMacroPage | Sole target caller; sets ordinal/key/spell-mode/refresh | true | UID000094 | `89/92` | R5/prose applied |
| UID000095 | `by-class/NewMacroEditControlPane.md` | Direct class owner/emitter | true | UID0000KY | `92/94` | R2/prose applied |
| UID0001IK | aggregate split index | Address-ordered inventory | false | UID0000KY | `91/93` | renamed-link/prose applied |
| UID0000KY | `by-file/MacroDialogs.md` | Source file route | true | file root | `92/92` | renamed-link/prose applied |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0053f26f` | UID00049O calls UID0004A9 | Sole direct target caller; argument is current-page base plus row |
| `0x0053f274` | caller immediately performs the next child lookup | EAX is overwritten; target result is ignored |
| `0x0053f27e` | caller invokes UID0004AA SetKey | Exact setter order follows shortcut ordinal |
| `0x0053f28d` | caller invokes UID0004AB SetSpellMode | Spell mode follows key |
| `0x0053f294` | caller invokes UID0004AC Refresh | Refresh is last |
| `0x0053f0f3`, `0x0053f130` | NewMacroDialog command flow invokes LoadMacroPage | Previous/next page actions reach the target through UID00049O |
| `0x0057f9fb` | constructor writes complete-object `+0x108` | Initial shortcut ordinal |
| `0x0057fb4a`, `0x0057fb5d`, `0x0057fb78` | OnPaint reads complete-object `+0x108` | Signed bank selection and displayed shortcut number |
| UID0003DB primary vtable | points to OnPaint, not UID0004A9 | Setter is nonvirtual and must not appear in vtable data |

## Documentation Evidence And IDA Status

- Historical pre-callback state: UID0004A9 correctly classified the function
  as source-authored and routed it through UID000095, but evidence and naming
  were incomplete; UID0004A8 used record-index terminology; UID00049O used a
  generic index; and UID0004AD supplied the decisive numeric/Ctrl-numeric
  contradiction to a record identifier.
- Current applied state: UID0004A9, UID0004A8, UID00049O, UID0004AD,
  UID000095, UID0001IK, UID0000KY, UID00049J, and UID000094 contain the exact
  shortcut-index union at the destination-specific level described below.
- UID0001VR correctly distinguishes 20 four-byte
  `CompactShortcutRecord` rows from 30 integrated `MacroHotkeyRecord` rows.
- UID0001Y1 and UID0003DB correctly classify vtable/RTTI as compiler output;
  UID0004A9 has no vtable route.
- Current manual coverage omits UID0004A9 and retains stale record-index
  wording in UID000095 and generic index wording in UID00049O.
- Historical generated command `000000014382` was structurally valid but
  lexically stale. Current command `000000014471` has the corrected one-body,
  no-marker, no-stale-token union described under Current Target State.

## Ranked Ownership Analysis

### 1. UID000095 NewMacroEditControlPane

- Evidence for: complete-object ECX receiver, class field at `+0x108`, sibling
  methods in one source island, constructor initialization, OnPaint
  consumption, complete class declaration, and existing direct emitter route.
- Evidence against: none.
- Decision: retain as direct semantic owner and emitter.

### 2. UID0000KY MacroDialogs

- Evidence for: established source-family root, class declaration order,
  NewMacroDialog caller, all row-control methods, vtable family, and generated
  source path converge on `NexusTK/ui/dialogs/MacroDialogs.cpp`.
- Evidence against: historical caveat that multiple source generations might
  once have been separate files.
- Decision: retain as source-file route; the caveat does not justify a new
  file for one class-local setter.

### 3. Config/UserPane/separate helper file

- Evidence for: Config owns the compact shortcut storage and UserPane consumes
  the same runtime index domain.
- Evidence against: neither owns the target receiver or method island; target
  has no global/static-helper ABI; a new file would fragment an already
  complete class source route.
- Decision: reject as owner/emitter/source placement. Retain only as semantic
  corroboration.

### Proposed new file/grouping, if applicable

- Not applicable. No new source file, helper grouping, global, struct, or
  compiler grouping is supported.

## Source Placement

- Implemented placement:
  `NexusTK/ui/dialogs/MacroDialogs.cpp`, under class UID000095.
- This placement preserves current source declaration position 50, places the
  qualified definition among the existing NewMacroEditControlPane children,
  and keeps the NewMacroDialog caller in the same source family.
- Rejected:
  `Config.cpp` because Config owns data, not the UI receiver;
  `UserPane.cpp` because UserPane is a runtime consumer;
  a dedicated NewMacroEditControlPane file because current address/source/
  vtable/generated evidence favors the established MacroDialogs family.
- Remaining uncertainty: the exact historical physical-file partition is not
  original-symbol proof, but current project source routing is much stronger
  than any alternative and is not a blocker.

## Range / Split / Padding / Reclassification Analysis

- Exact target range remains `[0x0057fa30,0x0057fa40)`.
- Exact target size is 16 bytes.
- The target has one entry, one basic block, one return, and no internal
  padding or mixed ownership.
- The already documented predecessor pad
  `[0x0057fa2b,0x0057fa30)` remains parent-only ignored alignment.
- UID0004AA begins exactly at `0x0057fa40`; therefore the target owns no
  successor padding.
- `[0x0057fa52,0x0057fa60)` remains padding after UID0004AA and is unrelated
  to UID0004A9.
- UID0001IK retains `Nested:-4`; UID0004A9 retains `Nested:0`. A semantic
  rename does not alter the address-sorted relative nesting delta.
- No split, merge, child registration, owner reassignment, or
  reconstructability reclassification is recommended.

## Negative Evidence Summary

- No data xref or vtable entry references the target.
- No absolute pointer or RVA byte sequence for the target address exists in
  the executable.
- No second direct caller exists.
- No indirect callback, import, export, or global function-pointer route was
  found.
- No receiver adjustment exists; this is not a secondary-base thunk.
- No other complete-object `+0x108` access exists outside constructor, target,
  and OnPaint in the bounded class island.
- SaveMacroEntries reads key and mode only; it does not consume the shortcut
  index.
- Key/text input updates key/mode only; it does not consume the shortcut
  index.
- Refresh only requests repaint/parent refresh; it does not consume the
  shortcut index.
- CompactShortcutRecord is the caller's storage source, not the field type.
- MacroHotkeyRecord is a distinct integrated-macro layout and is rejected.
- An `int` source return is not supported by caller use or sibling setter
  contracts.
- A bounds check or normalization in the setter would be invented behavior.

## IDA Rename / Type / Comment Recommendations

- Implemented source-facing function name:
  `NewMacroEditControlPane::SetShortcutIndex`.
- Implemented source-facing member name: `m_shortcutIndex`.
- Implemented parameter name: `shortcutIndex`.
- Implemented source return/type: `void` and `int`.
- Suggested documentation comment meaning:
  signed configured-shortcut ordinal `0..19`, with lower ten number-key rows
  and upper ten Ctrl-number rows.
- Retain the class name, owner/emitter, source file, range, key API, mode API,
  and vtable classifications.
- No IDA database mutation is requested or authorized. These names/types are
  documentation/source reconstruction recommendations only.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The target and every source destination touched
  by its lexical contract have complete behavior and source shape.
- Third-party import directive: not applicable.
- R1 target destination:
  `by-memory/0x0057fa30-0x0057fa40.NewMacroEditControlPaneSetShortcutIndex.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewMacroEditControlPane::SetShortcutIndex(int shortcutIndex)
{
    m_shortcutIndex = shortcutIndex;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- R2 implemented no-loss class destination:
  `by-class/NewMacroEditControlPane.md`.
  This is the complete applied union: B003 shortcut-index names, executed B001
  unsigned-char spell-mode names, and executed B005 wchar-key names.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
struct Rect;

class NewMacroEditControlPane : public ControlPane
{
public:
    NewMacroEditControlPane(wchar_t key, int shortcutIndex, unsigned char spellMode, const Rect &bounds);

    wchar_t GetKey() const;
    unsigned char GetSpellMode() const;
    void SetShortcutIndex(int shortcutIndex);
    void SetKey(wchar_t key);
    void SetSpellMode(unsigned char spellMode);
    void Refresh();

protected:
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    int m_shortcutIndex;
    wchar_t m_key;
    unsigned char m_spellMode;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- R3 implemented no-loss constructor destination:
  `by-memory/0x0057f9d0-0x0057fa2b.NewMacroEditControlPaneConstructor.md`.
  This block contains the same applied spell-mode/key union as R2.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
NewMacroEditControlPane::NewMacroEditControlPane(
    wchar_t key,
    int shortcutIndex,
    unsigned char spellMode,
    const Rect &bounds)
    : ControlPane(8, bounds),
      m_shortcutIndex(shortcutIndex),
      m_key(key),
      m_spellMode(spellMode)
{
    SetSelectable(true);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- R4 implemented no-loss paint destination:
  `by-memory/0x0057faa0-0x0057fc76.NewMacroEditControlPaneOnPaint.md`.
  The applied block preserves every accepted helper and field-type/name
  improvement while replacing only the shortcut-index lexical uses.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewMacroEditControlPane::OnPaint()
{
    const Rect row = GetClientRect();
    BeginMacroRowPaint();

    const uint16_t normalizedKey = NormalizeSpellKey(m_key);
    const wchar_t *entryName = nullptr;
    if (m_spellMode != 0)
        entryName = g_spellRecords[normalizedKey].displayName;
    else
        entryName = GetLocalInventorySlot(normalizedKey)->displayName;

    const int centerY = (row.Height() + row.top + 12) / 2;
    if (m_shortcutIndex >= 10)
        DrawMacroRowText(row.left, centerY, FormatShortcutNumber(L"Ctrl+%d", m_shortcutIndex == 19 ? 0 : m_shortcutIndex - 9));
    else
        DrawMacroRowText(row.left + 18, centerY, FormatShortcutNumber(L"%d", m_shortcutIndex == 9 ? 0 : m_shortcutIndex + 1));

    DrawMacroRowText(row.left + 48, centerY, m_spellMode != 0 ? L"Spell" : L"Item");
    DrawMacroRowText(row.left + 90, centerY, entryName);

    if (IsFocused())
        DrawMacroRowFocus(row);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- R5 implemented no-loss caller destination:
  `by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md`.
  The applied block preserves the accepted `SetSpellMode` spelling.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewMacroDialog::LoadMacroPage(int page)
{
    if (m_currentPage == page)
        return;

    m_currentPage = page;

    const int baseShortcutIndex = page * 10;
    for (int row = 0; row < 10; ++row)
    {
        const int shortcutIndex = baseShortcutIndex + row;
        NewMacroEditControlPane *edit = GetChild<NewMacroEditControlPane>(2 + row);
        const CompactShortcutRecord &record = g_pConfig->m_compactShortcutRecords[shortcutIndex];

        edit->SetShortcutIndex(shortcutIndex);
        edit->SetKey(record.code);
        edit->SetSpellMode(record.isSpellMode);
        edit->Refresh();
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Behavioral preservation:
  R1 is the exact dword store; R3 preserves initialization order; R4 preserves
  signed branch/order/zero-key cases; R5 preserves early return, page update,
  ten-row order, child ids, storage lookup, setter order, and refresh.
- Human source shape:
  ordinary public setter, private `m_` member, class declaration closed before
  `[[CHILDREN]]`, no raw addresses, no vptr writes, no calling-convention
  annotations, and no decompiler artifacts.

## Final Recommendation

- The accepted rename of UID0004A9 path/title/method/member vocabulary to
  shortcut index is implemented.
- Target `92/94` is applied with all owner/emitter/reconstructable/position/
  nesting/range metadata retained.
- R1-R5 and every accepted report fact are applied to the bounded
  destinations with formal parity recorded below.
- All key/spell-mode semantics, constructor behavior, paint behavior,
  caller order, compact-record layout, vtable/no-code boundaries, padding,
  rejected alternatives, and historical naming corrections are preserved.
- UID00049N save, UID0004AE input, UID0004AC refresh, UID0001VR layout,
  UID0001Y1/UID0003DB vtable support, UID0001IM teardown, UID0004AV scalar
  wrapper, and ignored padding were reread verify-only and remain unchanged.
- No B003 research or implementation item remains. Exact original private spelling is a
  documented confidence cap, not an implementation blocker.

## Recommended Target Doc Changes

- Applied through validator-aware UID-preserving workflow:
  `by-memory/0x0057fa30-0x0057fa40.NewMacroEditControlPaneSetRecordIndex.md`
  to
  `by-memory/0x0057fa30-0x0057fa40.NewMacroEditControlPaneSetShortcutIndex.md`.
- Applied `COMPLETION:92`, `CONFIDENCE:94`.
- Retained:
  `CANONICAL_OWNER:000095`, `EMITTER_UIDS:000095`,
  `RECONSTRUCTABLE:TRUE`, blank optional position, and `Nested:0`.
- Installed Item Summary:
  `Exact 16-byte NewMacroEditControlPane setter storing the signed 0..19 configured-shortcut ordinal at complete-object +0x108, with one NewMacroDialog page-load caller, number/Ctrl-number paint consumers, MacroDialogs ownership, exact boundaries, and complete source C++.`
- Installed R1 exactly.
- Incorporated exact bytes/hash/signature, ABI, sole caller, all field uses, value-domain
  proof, padding/boundary proof, owner/source route, no-vtable/no-pointer
  negatives, source-authored classification, naming rationale, rejected
  alternatives, and score rationale.
- Preserved `SetRecordIndex`/`m_recordIndex` only as historical superseded
  provenance.

## Recommended Support Doc Changes

- `by-class/NewMacroEditControlPane.md` UID000095:
  retained `92/94`, owner/emitter UID0000KY, true, position 50; applied R2 and
  complete `+0x108` shortcut-index lifecycle/access evidence. Preserve the
  exact `0x110` layout, key/mode fields, methods, inherited facets, vtable
  routes, implicit destructor cause, compiler support, and unrelated content.
- `by-memory/0x0057f9d0-0x0057fa2b.NewMacroEditControlPaneConstructor.md`
  UID0004A8:
  retained `91/94` and metadata; applied R3 and replaced
  record-index wording with shortcut ordinal, including first-page `0..9`
  caller evidence. Preserve all base/vptr/selectable/key/mode/layout facts.
- `by-memory/0x0057faa0-0x0057fc76.NewMacroEditControlPaneOnPaint.md`
  UID0004AD:
  retained `88/91` and metadata; applied R4 and documented that `+0x108` alone
  selects/displays number versus Ctrl-number shortcuts. Preserve all
  key/mode/name/focus/helper behavior.
- `by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md`
  UID00049O:
  retained `89/92`; applied R5 and exact page/row/shortcut-index terminology while
  preserving compact-record fields, endpoint, setter order, and no guards.
- `by-memory/0x0053ed90-0x0053f07f.NewMacroDialogConstructor.md`
  UID00049J:
  received the prose-only bounded addition that its second row-control constructor argument
  is the initial signed shortcut ordinal `0..9`; score/formal/route unchanged.
- `by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md` UID0001IK:
  now records the UID0004A9 path/title/inventory row and exact behavior; retained
  `91/93`, owner UID0000KY, false, blank emitter/formal, `Nested:-4`, every
  other child, padding span, raw helper, and compiler artifact.
- `by-file/MacroDialogs.md` UID0000KY:
  now records all UID0004A9 links, class layout text, source child inventory,
  and shortcut-index lifecycle; retained `92/92`, route, source order, complete
  Macro/Spell/New/Integrate union, history, and physical-file caveat.
- `by-class/NewMacroDialog.md` UID000094:
  received the bounded prose link from private LoadMacroPage to the renamed public setter;
  score/formal/route/layout unchanged.
- UID00049N SaveMacroEntries:
  verify-only because it reads key/mode and never reads shortcut index.
- UID0004AE HandleKeyOrTextEvent and UID0004AC Refresh:
  verify-only because neither accesses `+0x108`.
- UID0001VR profile layout:
  verify-only because its exact 20x4 compact-record layout is already
  same-or-greater and does not contain the UI object's shortcut-index member.
- UID0001Y1/UID0003DB vtable support:
  verify-only because this setter is nonvirtual and must not be added to raw
  vtable/RTTI output.
- UID0001IM/UID0004AV and ignored padding:
  verify-only; compiler/no-code and boundary dispositions remain exact.
- Concurrent no-loss boundary:
  the executed B001/B005 artifacts and each current destination were reread
  before B003's one-file edit. The applied union retains all accepted key and
  spell-mode facts while adding the shortcut-index delta; no stale token or
  unrelated content was restored or dropped.

## Score And Metadata Recommendation

- Historical pre-callback target:
  `86/90`, owner/emitter UID000095, true, blank position, `Nested:0`.
- Implemented target:
  `92/94`, with every non-score metadata field unchanged.
- Completion improves because behavior, exact bytes/range, ABI, return, field
  type/domain, complete lifecycle, caller order, source name, source file,
  formal C++, and support destinations are all implementation-ready.
- Confidence improves because one caller and all field users close the
  semantics; exact original lexical spelling remains inferred.
- Reason not 95:
  no PDB/source symbol proves whether the original developers wrote
  `shortcutIndex`, `hotkeyIndex`, or another equivalent private name.
- Score-improvement audit:
  - caller blocker: removed by exact sole-caller and page-flow analysis;
  - field blocker: removed by all-use `+0x108` audit;
  - type blocker: removed as signed 32-bit `int`;
  - return blocker: removed as source `void`;
  - name blocker: resolved to strongest project-local `shortcutIndex`;
  - source-placement blocker: removed by complete MacroDialogs ownership union;
  - C++ blocker: removed by R1-R5;
  - range/split blocker: removed by exact boundary/padding proof;
  - support collision blocker: converted to an exact callback serialization
    and no-loss rebase rule rather than deferred technical research.
- Support scores remained unchanged by this callback. B001/B005 retain ownership
  of their independently assigned direct target score decisions.

## Open Questions With Attempted Resolution

- Was the original exact spelling `shortcutIndex`?
  No symbol proves it. All current evidence was checked; `shortcutIndex` best
  matches the compact shortcut table, page/row calculation, label behavior,
  and current runtime vocabulary. This is not a blocker and caps confidence at
  94.
- Could the field be unsigned?
  Dword width alone permits it, but signed caller extension/comparison,
  ordinary project style, and `int` page/row arithmetic favor `int`.
- Could the source return the assigned value?
  The incoming value remains in EAX, but the sole caller discards it and
  sibling setters use the same lowering. `void` is the stronger source shape.
- Could the setter be private?
  The sole caller is a distinct class and no friendship evidence exists.
  Current public placement is source-safe and should remain.
- Could `+0x108` be a compact-record index?
  The caller uses the same arithmetic to select a record, but the UI field is
  consumed only as displayed shortcut identity. `recordIndex` describes an
  implementation coincidence, while `shortcutIndex` describes the object's
  source role.
- Does any question remain implementation-blocking?
  No. Only unrecoverable original lexical spelling remains as a documented
  confidence cap.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Current manual snapshots reread after the ordinary callback:
  - `by-memory/-coverage-report.md` SHA256
    `CC74FEC6149421F5AB63716C4786FF635C05849F5A1BD688979562EAAB64B56D`,
    1,791,199 bytes / 4,279 lines.
  - `by-class/-coverage-report.md` SHA256
    `F11A3518254E57BDB67A717086F2B2A27E115BE8874EA7C782DC19EB9F8704D7`,
    231,118 bytes / 622 lines.
  - `by-file/-coverage-report.md` SHA256
    `75B4750F44E99DD315AAA39EAECA38C178DAED5CEC31E91CC4CE2B4CC41E15F5`,
    132,820 bytes / 316 lines.
  - `by-type/by-struct/-coverage-report.md` SHA256
    `A59DA1DB4C5D4FFA760A2BDD8EA84D49D412D559AD428FCDE03523096EFE9C0C`,
    57,240 bytes / 137 lines.
- Current by-memory placement:
  UID0001IK is line 3201; executed B005/B001 rows UID0004A6, UID0004A7, and
  UID0004A8 are lines 3206-3208; UID0004AB begins line 3209. UID0004A9 is
  absent. Insert the target in exact address order after UID0004A8 line 3208
  and before UID0004AB line 3209, preserving every neighboring B001/B005 row.
- Exact by-memory insertion:

```text
        - [UID:0004A9][0x0057fa30-0x0057fa40.NewMacroEditControlPaneSetShortcutIndex](by-memory/0x0057fa30-0x0057fa40.NewMacroEditControlPaneSetShortcutIndex.md) 0x0057fa30-0x0057fa40 | method | NewMacroEditControlPaneSetShortcutIndex : reconstructable : 92% : very-strong : Exact 16-byte thiscall setter storing the signed 0..19 configured shortcut ordinal at complete-object +0x108, with exact bytes/hash/unique signature, sole NewMacroDialog page-load caller, constructor/OnPaint full-field lifecycle, direct UID000095/MacroDialogs emission, no vtable/data/pointer route, exact padding boundaries, and complete source C++.
```

- Current UID00049J is line 2655. Exact replacement:

```text
        - [UID:00049J][0x0053ed90-0x0053f07f.NewMacroDialogConstructor](by-memory/0x0053ed90-0x0053f07f.NewMacroDialogConstructor.md) 0x0053ed90-0x0053f07f | constructor | NewMacroDialogConstructor : reconstructable : 90% : very-strong : Exact newer paged MacroDialog constructor with natural 0x270 layout, direct CompactShortcutRecord code/isSpellMode rows and initial signed shortcut ordinals 0..9, OK/previous/next controls, inherited SetHoverControl(2), resource/bounds/layer setup, no final Show, complete source C++, and preserved no-direct-xref caveat.
```

- Current UID00049O is line 2659. Exact replacement:

```text
        - [UID:00049O][0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage](by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md) 0x0053f210-0x0053f2b6 | method | NewMacroDialogLoadMacroPage : reconstructable : 89% : very-strong : Exact page-change and ten-row load helper computing signed shortcutIndex 0..19 and copying direct Config CompactShortcutRecord code/isSpellMode into NewMacroEditControlPane shortcut-index/key/spell-mode state before refresh, with corrected endpoint and complete source C++.
```

- Current UID000095 is by-class line 352. Exact no-loss union replacement:

```text
- [UID:000095][NewMacroEditControlPane](by-class/NewMacroEditControlPane.md) : reconstructable : 92% : very-strong : Complete natural 0x110 ControlPane-derived new macro row declaration at position 50 with int m_shortcutIndex at +0x108, wchar_t m_key/API at +0x10c, unsigned-char m_spellMode at +0x10e, GetSpellMode/SetSpellMode raw-byte API, constructor, SetShortcutIndex/SetKey, refresh, paint, canonical pointer/key EventHandler overrides, exact CompactShortcutRecord code/isSpellMode constructor/save/load/persistence/runtime lifecycle, signed 0..19 number versus Ctrl-number shortcut labeling, zero/nonzero item-inventory versus spell-command semantics without bool narrowing, vtable routes, implicit virtual destructor source cause, compiler helper/scalar/thunk separation, and MacroDialogs ownership.
```

- Current UID0000KY is by-file line 151. Exact no-loss union replacement:

```text
- [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) : reconstructable : 92% : very strong : Macro dialog/edit-control source family with exact Macro/Spell/New/Integrate split inventories, complete six-position Macro/Integrate-dialog/Integrate-edit/New-dialog/New-edit/Spell declarations at 10/20/30/40/50/60 plus complete source-local Spell edit class, canonical OnControlCommand and SetHoverControl contracts, corrected constructor calls and TextEditPane editor type, exact NewMacroEditControlPane signed SetShortcutIndex/m_shortcutIndex 0..19 lifecycle and number/Ctrl-number display semantics plus wchar_t key and unsigned-char GetSpellMode/SetSpellMode/m_spellMode lifecycle mapped to CompactShortcutRecord code/isSpellMode without bool narrowing, registry/profile/runtime storage distinctions, explicit/implicit/source/compiler destructor separation, vtable coverage, historical stale-name corrections, and retained physical-file grouping caveat.
```

- No change is required to current UID0001IK manual line 3201; it does not
  enumerate this child by name/path and remains accurate.
- No change is required to UID0001VR by-struct line 98; the compact record
  table description remains exact and does not expose the UI object's member
  name.
- No-loss supervisor handoff:
  apply the target insertion and four replacements above against the exact
  current rows, preserving any later unrelated accepted union if the manual
  epoch advances. B003 did not edit these supervisor-owned files.

## Follow-Up Actions

- B003's accepted ordinary implementation, UID-preserving rename, R1-R5,
  C01-C20 incorporation, scoped validation, waited generated verification,
  no-loss B001/B005 rebase, report reconciliation, and lease release are
  complete. No B003 implementation item remains.
- The exact manual coverage insertion/replacements above are a read-only
  supervisor-owned handoff; B003 did not mutate any coverage root.
- Exact-artifact review, current report path/count/status, manual coverage
  application, execution, move, and archive state are external supervisor/
  validator-owned facts. This artifact neither asserts nor directs those
  later lifecycle outcomes.
- No future B003 research or callback action remains for UID0004A9.

## Confidence

- Recommendation confidence: very strong.
- Target score confidence: very strong for `92/94`.
- Behavioral confidence: very strong.
- Source-name confidence: strong.
- Owner/emitter/source-placement confidence: very strong.
- Remaining uncertainty is limited to unrecoverable original private symbol
  spelling and does not block implementation.

## Validator Results

- Every changed ordinary page passed a scoped validator while held under its
  one-file lease. Each lease was released before the next lease was acquired.

| Command ID | Timestamp | Scoped destination | Exit / ok | Recorded side effects |
| --- | --- | --- | --- | --- |
| `000000014459` | `2026-07-16T17:45:12-04:00` | UID0004A9 validator-aware rename to `by-memory/0x0057fa30-0x0057fa40.NewMacroEditControlPaneSetShortcutIndex.md` | `0 / 1` | Preserved UID, updated path/title, completion/confidence, two source-path references and four UID links; generated refresh deferred. |
| `000000014461` | `2026-07-16T17:46:29-04:00` | `by-class/NewMacroEditControlPane.md` | `0 / 1` | Autogen registry update; generated refresh deferred. |
| `000000014463` | `2026-07-16T17:47:22-04:00` | UID0004A8 constructor | `0 / 1` | Autogen registry update; generated refresh deferred. |
| `000000014464` | `2026-07-16T17:48:40-04:00` | UID0004AD OnPaint | `0 / 1` | Autogen registry update; generated refresh deferred. |
| `000000014465` | `2026-07-16T17:49:44-04:00` | UID00049O LoadMacroPage | `0 / 1` | Autogen registry update; generated refresh deferred. |
| `000000014466` | `2026-07-16T17:50:38-04:00` | UID00049J NewMacroDialog constructor | `0 / 1` | Validator statistics only; generated refresh deferred. |
| `000000014470` | `2026-07-19T17:10:01-04:00` | UID0001IK MacroEditControlPanes aggregate | `0 / 1` | Validator statistics only; generated refresh deferred. An earlier successful aggregate invocation produced no auditable stdout metadata, so this explicit repeat is the authoritative scoped proof. |
| `000000014468` | `2026-07-19T17:08:38-04:00` | `by-file/MacroDialogs.md` | `0 / 1` | Validator statistics only; generated refresh deferred. |
| `000000014469` | `2026-07-19T17:09:34-04:00` | `by-class/NewMacroDialog.md` | `0 / 1` | Added current reference-index link to UID0004A9; generated refresh deferred. |
| `000000014471` | `2026-07-19T17:10:44-04:00` | final `by-file/MacroDialogs.md --wait-generated` | `0 / 1` | Generated refresh completed; validator-owned registry/research-tracker/generated metadata refreshed. Global warnings (`85` children-marker, `142` emitter-no-code, `13` fallback-insert) are unrelated project-wide diagnostics; no UID0004A9 error remained. |

- Managed-block parity, computed over LF-normalized managed text including the
  literal headers, is exact:
  - R1 target: SHA256
    `8FBFD2C636FE4CD6468B7002AD5ED3DEC68BDF255DAAA243E3E8C0BA74898763`,
    7 lines.
  - R2 class: SHA256
    `CB65BA3C93FFF452C39802D1DB37911BF913A2279FAA2D4C8D2230480C60963C`,
    30 lines.
  - R3 constructor: SHA256
    `E53C9550F6B930D3618852980B4B8C32D549911EFC4CBC51F66AB08302741EA7`,
    15 lines.
  - R4 OnPaint: SHA256
    `43B7655688FF6B82597CCB5B5B63D348372C2EADB97B875203467631909F8050`,
    27 lines.
  - R5 LoadMacroPage: SHA256
    `A7D0AFC243740A48FE040991D3683185C3E6BBDF6AF840410BB8463DB85E86A2`,
    23 lines.
- Final generated readback:
  `auto-generated/NexusTK/ui/dialogs/MacroDialogs.cpp`, command/header
  `000000014471`, refreshed `2026-07-19T17:10:44-04:00`, SHA256
  `C164F22996199EB2C489AD355312436E8B8E1E38072EC19A3BD18982692E5E93`,
  35,013 bytes / 1,053 lines. The complete NewMacroEditControlPane class
  closes before definitions; its ten qualified definitions have ten unique
  names. UID0004A9 R1 and marker occur once, its Empty Emitter Marker occurs
  zero times, and no duplicate/wrong-range body exists. `SetRecordIndex`,
  `m_recordIndex`, `GetMode`, and `SetMode` occur zero times in the New segment.
  `wchar_t m_key`, GetKey, SetKey, `unsigned char m_spellMode`, GetSpellMode,
  and SetSpellMode each occur once where applicable. The Spell-row B005 class,
  `wchar_t m_spellKey`, GetSpellKey, and constructor remain once. No raw
  vtable/RTTI array or compiler glue was handwritten into the source segment.
- B003 ran no report validator, `execute_report`, probe, count, execution,
  move, archive, or other lifecycle command.

## Changed Files

- Report updated in place:
  `tools/leaser/Agents/Agent-B003/research/0004A9-NewMacroEditControlPaneSetRecordIndex-source-quality.md`.
- Renamed and modified ordinary file:
  `by-memory/0x0057fa30-0x0057fa40.NewMacroEditControlPaneSetRecordIndex.md`
  to
  `by-memory/0x0057fa30-0x0057fa40.NewMacroEditControlPaneSetShortcutIndex.md`,
  current SHA256
  `7204ABE607EF9F356D9D1EDD784C621678398A13F8DCF77B358E754000DFB93C`.
- Modified ordinary files:
  - `by-class/NewMacroEditControlPane.md`, SHA256
    `9B21C6E2EC3C758C57D14B92F2DFE31B0185296AAA238FA7E2655F3205920FF5`.
  - `by-memory/0x0057f9d0-0x0057fa2b.NewMacroEditControlPaneConstructor.md`,
    SHA256
    `AAF989933647C23859A68F49DF9BA0AA3E8434D28435517838A3135843AC36DB`.
  - `by-memory/0x0057faa0-0x0057fc76.NewMacroEditControlPaneOnPaint.md`,
    SHA256
    `0981F94A16ED113CC23DC6943E26E3CD7139D4182E974D853016ABAA9BCC18BF`.
  - `by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md`,
    SHA256
    `C586D41D0E5B79A39A75B2E5AE7437B0948BD5D11200185158DEDE81E20B0F77`.
  - `by-memory/0x0053ed90-0x0053f07f.NewMacroDialogConstructor.md`, SHA256
    `86A3B426F5EFCA964AC9274660AB860069732315CC229982B8E41D33CD19798F`.
  - `by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md`, SHA256
    `BFADA166F4FA7D904D636AE05DF5492C20390057D563D3A0EBE2C61416590078`.
  - `by-file/MacroDialogs.md`, SHA256
    `A4D8369946F730199AE9604CAE79E140B0A4811C0E9FD172A84D516A496FD690`.
  - `by-class/NewMacroDialog.md`, SHA256
    `79CC9CE34F5A59B62B70FB9A9127790771104A2B3E0E0A76DE79DD4F2F9E2F85`.
- Verify-only destinations reread and unchanged:
  UID00049N, UID0004AE, UID0004AC, UID0001VR, UID0001Y1, UID0003DB,
  UID0001IM, UID0004AV, UID0004A7, UID0004AB, UID0004AA, and both adjacent
  ignored-padding rows. No exact contradiction required broader edits.
- Manual B003 edits to coverage/generated/tracker/audit/supervisor/
  validator-state/IDA files: none. Validator-owned generated/tracker metadata
  side effects from command `000000014471` are recorded above.
- Leases:
  each ordinary destination was held singly only for reread/edit/scoped
  validation and released immediately. Final current lease-ledger read says
  `No active leases`; B003 holds zero leases.
- Validators: the nine scoped ordinary validations and one final waited
  generated validation listed above all exited `0` with `ok:1`.
- Report execution/lifecycle/move/archive commands by B003: none.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor exact-artifact Gate 1 validation was recorded before implementation.
- [x] Validator-preserving rename UID0004A9 to
  `by-memory/0x0057fa30-0x0057fa40.NewMacroEditControlPaneSetShortcutIndex.md`.
- [x] Applied target `92/94`, exact Item Summary, retained owner/emitter/true/
  blank-position/Nested0 metadata, and R1.
- [x] Incorporated exact target bytes/hash/signature, ABI, caller, field-use,
  range, padding, negative-route, source-placement, rejected-name, history,
  and score evidence.
- [x] Applied R2 and complete `+0x108` shortcut-index prose to UID000095 without
  losing then-current accepted class content.
- [x] Applied R3 and bounded shortcut-ordinal constructor evidence to UID0004A8
  without changing its B003 support score recommendation.
- [x] Applied R4 and exact shortcut display semantics to UID0004AD, preserving
  all unrelated paint behavior.
- [x] Applied R5 and exact page/row/setter ordering to UID00049O.
- [x] Added bounded initial shortcut-ordinal prose to UID00049J; preserved its
  score/formal/route.
- [x] Updated UID0001IK path/title/inventory and behavior while preserving
  `Nested:-4`, all siblings, padding, raw helpers, and compiler support.
- [x] Updated UID0000KY links/source-family/layout prose without losing any
  Macro/Spell/New/Integrate union detail.
- [x] Added the bounded renamed-setter caller link to UID000094; preserved score,
  layout, formal, and unrelated children.
- [x] Verified UID00049N save remains key/spell-mode-only and unchanged.
- [x] Verified UID0004AE input and UID0004AC refresh do not access `+0x108` and
  remain unchanged.
- [x] Verified UID0001VR compact-record layout remains same-or-greater and
  unchanged.
- [x] Verified UID0001Y1/UID0003DB keep compiler vtable/RTTI no-raw-array
  disposition and do not add the nonvirtual setter.
- [x] Verified UID0001IM/UID0004AV and both adjacent padding dispositions remain
  unchanged.
- [x] Waited for accepted B001/B005 callbacks and active leases before shared
  edits; reread their executed artifacts and current destinations, then
  rebased the full no-loss union.
- [x] Updated every C01-C20 ledger row to a legal callback terminal state with
  exact destination, validator, generated, preservation, and collision-rebase
  proof.
- [x] Ran one scoped validator for each actually changed ordinary page and
  released its lease immediately.
- [x] Ran one final authorized waited MacroDialogs refresh and recorded command
  id, timestamp, exit, ok/warnings, side effects, header freshness, SHA256,
  bytes, lines, class closure, target/name counts, and no-compiler-artifact
  assertions.
- [x] Confirmed no B003 lease remains and no stale old-path link remains in the
  accepted destination set.
- [x] Preserved all historical assumptions, rejected alternatives, negative
  evidence, compiler/source distinctions, and source-placement rationale.
- [x] Preserved stale Wave2/Wave3 material as rejected/non-authoritative; none
  was used as evidence.
- [x] Reconciled the exact supervisor-owned manual coverage handoff
  without B003 editing any coverage file.
- [x] Reconciled Current Target State, recommendations, Validator Results,
  Changed Files, generated proof, current hashes, and checklist to callback
  truth.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support details incorporated at report-level depth.
- [x] All C01-C20 claims terminalized with claim-specific proof.
- [x] Metadata/score/rename/C++ changes applied or excluded with exact reason.
- [x] Concurrent B001/B005 accepted facts preserved through current-destination
  reread and no-loss rebase.
- [x] Historical/stale assumptions, rejected alternatives, negative evidence,
  and score caps preserved.
- [x] Scoped validators passed for every changed ordinary page.
- [x] Final waited generated assertions passed and were recorded.
- [x] Exact manual supervisor-owned coverage text retained/rebased to the
  then-current union without B003 coverage edits.
- [x] Zero leases and zero remaining implementation blockers confirmed.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000014489","destination_path":"executed-b-agent-research/B003/0004A9-NewMacroEditControlPaneSetRecordIndex-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0004A9-NewMacroEditControlPaneSetRecordIndex-source-quality.md","timestamp":"2026-07-19T17:38:08-04:00","uid":"0004A9"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
