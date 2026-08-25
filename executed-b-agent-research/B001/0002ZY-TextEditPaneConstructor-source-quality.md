** TARGET-REPORT-UID:0002ZY **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002ZY TextEditPane Constructor Source Quality

## Finalized Report / Current Recommendation

- Current callback result: UID0002ZY is `92/94`, retains
  `CANONICAL_OWNER:0000EO`, `RECONSTRUCTABLE:TRUE`,
  `EMITTER_UIDS:0000EO`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:8`,
  and contains Destination 1 exactly.
- Final disposition: one complete source-authored
  `TextEditPane::TextEditPane` body over exact range
  `[0x0058dce0,0x0058e132)`. The in-range registration-failure throw tail is
  part of this constructor. The vtable stores, security cookie, SEH frame,
  constructor-unwind funclets, saved-register schedule, and incomplete-new
  cleanup are compiler output and are not separate source bodies.
- Exact source signature: twelve explicit parameters after `this`, not
  thirteen: four dimensions, text and text-background colors, two scrollbar
  booleans, editor flags, one `unsigned short` legacy-asset mode, one
  `useDefaultAlignment` boolean, and one `useThousandsSeparator` boolean.
- The four internal `List` element types are resolved as UTF-16 code units,
  16-byte `TextEditLineRecord`, 16-byte `TextEditFormatRecord`, and 4-byte
  `TextEditFormatRun`. The 16-byte format record contains a 4-byte header plus
  the already-observed 12-byte `TextRunFormatData` payload.
- Current `m_styleRuns` at `+0x13c` and `m_formatRecords` at `+0x140` are
  reversed descriptive assignments. The evidence-backed names are
  `m_formatTable` at `+0x13c` and `m_formatRuns` at `+0x140`.
- Current `isReadOnly` for parameter 11 is rejected: the only false caller is
  the made-by right-aligned display, and the constructor directly assigns
  alignment mode 2 when it is false. `useDefaultAlignment` is the strongest
  source spelling. Current `inputMode` for parameter 12 is also rejected:
  `0x005946b0` reads the stored byte only to insert thousands separators, so
  `useThousandsSeparator` is the strongest source spelling.
- The accepted source route remains `NexusTK/ui/controls/TextEditPane.cpp`
  through class UID0000EO and file UID0000ON. No split, rename, child UID, new
  file, third-party import, IDA mutation, or direct caller ownership transfer
  is needed.
- The source access policy is now complete rather than deferred. Both
  file-local iterator callbacks are exact friends of `TextEditPane`, so its
  state remains private. `TextRunMeasureCallback` is also an exact friend of
  `TextEditObject`, so `m_payload1` remains protected and the callback keeps
  the observed direct load. Widening either class state to public and routing
  through `GetPayloadPair` are rejected.
- The accepted implementation callback is complete. B001 changed only the
  twelve authorized ordinary pages and this report, used one short ordinary
  lease at a time, ran one scoped validator per destination, released every
  lease, and ran the authorized final waited refresh. Manual coverage, IDA,
  supervisor/audit/registry/lifecycle state, and report movement/execution
  were not changed by B001.

## Supporting Research

- Assignment source: the topmost supervisor override in
  `tools/leaser/Agents/Agent-B001/goal.md` assigns UID0002ZY and requires a
  direct report at this path.
- Queue source: the current research tracker identifies UID0002ZY as an
  uncovered reconstructable by-memory page at `86/90` with no direct report.
- Binary used: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`,
  2,679,296 bytes, MD5 `4247E04E20B65D6414C7238AA8FF5515`, SHA256
  `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- Healthy MCP session: restored fresh discovery returned active NexusTK
  database `9b0396a3`, worker PID `15732`, `is_analyzing:false`.
  `server_health` returned
  `status:ok`, image base `0x00400000`, analysis ready, Hex-Rays ready, and
  string cache ready with 2,067 entries. A bounded
  `get_bytes(0x0058dce0,16)` returned
  `55 8b ec 6a ff 68 8f 96 60 00 64 a1 00 00 00 00`.
- Gate 1 repair recheck used bounded current-session calls. Bytes at
  `0x00593c20` began `55 8b ec 83 ec 08 66 8b 45 1c 8b 4d 18 53 0f b7`;
  current decompile directly loads `format->object` and then `[object+0x10]`
  without calling an accessor. Raw bytes/disassembly at
  `0x00594ec0-0x00594ed5` independently show the existing
  `GetPayloadPair(int *)` copies both `+0x0c/+0x10` dwords and returns with
  `retn 4`. That helper is not a behavior-identical substitute for the direct
  one-field callback load.
- One broad partition search was explicitly terminated after it became
  expensive. This was a query-scope limitation, not MCP loss: all subsequent
  target- and family-bounded lookup, bytes, decompile, xref, and search calls
  against `9b0396a3` succeeded.
- Reproducible search roots checked:
  `tools/leaser/Agents/Agent-B001/research`, B002-B005 active research roots,
  `executed-b-agent-research`, `tools/leaser/Agents/Older-Research`,
  `tools/leaser/Agents/SpecialReports`, and `archived`.
- Search terms included `0002ZY`, `0x0058dce0`, `0x0058e132`,
  `TextEditPaneConstructor`, `sub_58DCE0`, `TextEditPane`,
  `TextEditControlPane`, `m_textStorage`, `m_lineTable`, `m_styleRuns`,
  `m_formatRecords`, `TextRunMeasureCallback`, `g_pActiveTextEditPane`,
  `Nexon.StyledUnicodeText`, `ScrollablePane`, and all 26 callsite addresses.
- Path-specific prior results:
  - `executed-b-agent-research/B004/0000ON-TextEditPane-empty-emitter-family-source-quality.md`,
    SHA256 `B205C3143C71DE518C1FF0259FACDD3926522FE48C1E75049D884DD53C3458D7`,
    is direct family/file support. It explicitly left the UID0002ZY signature,
    table element layouts, helpers, and body unresolved.
  - `executed-b-agent-research/B005/0000EO-TextEditPane-class-source-quality.md`,
    SHA256 `88FD5933A9A50969FFD819C7C9D407CF14CCE1FA4733985E7817266E234F956D`,
    is class-layout support. Its `m_styleRuns`/`m_formatRecords` and
    `isReadOnly`/`inputMode` names were provisional and are superseded here by
    direct target/helper evidence.
  - `executed-b-agent-research/B003/00011H-TextEditControlPaneCore-empty-emitter-source-quality.md`,
    SHA256 `F9A14F53DDFDCC98BD7BF02F940C663C50ED6433EE2D9D8C8C8D135D005C57DB`,
    proves the wrapper's 12-argument call shape, later 1024/1 limits, and
    legacy mode route, but retains the stale `inputMode` spelling.
  - `executed-b-agent-research/B002/00019X-ScrolledTextControlPaneForMadeByCore-source-quality.md`,
    SHA256 `FBD7C700D3CB3E05EB7F45166174DFDC2B1BF4C2C4877FD600D15BFEF60972BA`,
    is the decisive parameter-11 caller: it passes false and receives right
    alignment, while editability is controlled independently.
  - `executed-b-agent-research/B001/0001JP-0001JS-texteditpane-format-nav-source-quality.md`,
    SHA256 `3209BD30117E74137D752E65254076960D8CA4B061294CD394E4DDE23D028F43`,
    is aggregate/table/helper research, not a target substitute.
  - `executed-b-agent-research/B007/0001JQ-TextRunMeasureCallback-source-quality.md`,
    SHA256 `772AFC7EBEB58F1304C6039B3F9DCCF1F4DCE3165EBC1CF2555E0DC4C12E25D3`,
    and `executed-b-agent-research/B006/0001JR-DrawTextRunCallback-source-quality.md`,
    SHA256 `E4A9BBEDE7C8137492FE472711C9C3F2CB92E446AEC96DA6DA3F7A0F71E7E1A9`,
    prove the iterator ABI and 12-byte format payload. Their provisional line
    and format names are synchronized by Destinations 5 and 6.
  - `executed-b-agent-research/B001/00005X-GroupListPane-class-source-quality.md`,
    SHA256 `EF5A36C48EAF070F76E44CA9A8D4630046D1C8BC54F6E8935114444EF63C6C9C`,
    and `executed-b-agent-research/B007/0001H8-GroupListPaneRawConstructor-source-quality.md`,
    SHA256 `C88749608F4C1EDA84ADCA2FA0E67AD99BAAA2E23BF732000C4AE941362C0CC4`,
    independently preserve fixed caller values and 12 explicit stack args.
  - `executed-b-agent-research/B008/0002RV-TextBoxPaneConstructor-source-quality.md`,
    SHA256 `530F0DF201B7D30D8B8A32DB940721B1EAFF702336B59C558FB6FD33A702E8D0`,
    is derived-constructor support only.
  - `tools/leaser/Agents/SpecialReports` has three benchmark IME focus
    reports whose matches are incidental dependencies through
    `IMEPane::SetFocusPane`; none covers UID0002ZY.
  - `tools/leaser/Agents/Older-Research` and `archived` contain no direct
    UID0002ZY/address/body report.
- Search conclusion: no direct prior UID0002ZY report exists. Every matching
  artifact is family, class, aggregate, helper, callback, caller, dependency,
  or incidental evidence and was independently checked against live MCP.

## Target

- UID: `0002ZY`.
- Path: `by-memory/0x0058dce0-0x0058e132.TextEditPaneConstructor.md`.
- Exact half-open range: `[0x0058dce0,0x0058e132)`.
- Exact size: `0x452` bytes, decimal 1,106.
- Current implemented page SHA256:
  `C2B031A631E5E32901504F18D5528A2F721CCD1D158E41BD2A88E00206DD72F9`.
- Current metadata is `92/94`, owner/emitter UID0000EO, reconstructable true,
  blank position, `Nested:8`, with Destination 1 populated exactly.

## Current Target State

- The ordinary target now contains the exact constructor formal block and full
  signature/table/helper/exception evidence. The TextEditPane declaration has
  exact table types and both callback friends; TextEditObject retains protected
  payload fields with the exact measure-callback friend.
- TextEditControlPane class/constructor/file pages now use only
  `useThousandsSeparator` in the accepted route. UID0001JP records the exact
  table identities while remaining blank only for residual raw-helper splits.
- Current generated `auto-generated/NexusTK/ui/controls/TextEditPane.cpp` is
  validator command `000000014635`, refreshed
  `2026-07-19T19:29:41-04:00`, SHA256
  `D2656CC63989CF86197A1DB83921B0F28F19C26D3885F1A992BFAFD243AA18F3`,
  23,137 bytes / 625 physical lines. It has one UID0002ZY marker, zero target
  Empty Emitter Markers, exactly one constructor definition, one UID0001JM
  Empty Emitter Marker and no aggregate body, one complete TextEditObject and
  TextEditPane declaration, and one definition of each callback.
- Current generated `auto-generated/NexusTK/ui/controls/TextEditControlPane.cpp`
  carries the same command/timestamp, SHA256
  `0B1673BB6081887C5DF01D829474EB9FA6DA57B513D27182DD79BCAEE50B76E5`,
  9,780 bytes / 253 physical lines. It contains two constructor definitions,
  exact `useThousandsSeparator` declarations/forwarding, wrapper `1024/1`
  overrides, and zero `inputMode` or `m_inputMode` tokens.
- Current manual coverage contains the complete accepted TextEdit row union:
  UID0001JM/0002ZY/0000VN/0001JP/0001JQ/0001JR in by-memory,
  UID0000EM/0000EN/0000EO in by-class, and UID0000OM/0000ON in by-file,
  each exactly once. The supervisor first applied/validated these rows through
  commands 14636-14638; later combined supervisor validations 14639-14641
  preserve them. Exact applied text and current hashes appear below.
- Implementation and generated verification are complete. B001 did not edit
  manual coverage, mutate IDA, execute/move/archive the report, or run any
  report lifecycle/probe/count command. Coverage application was performed
  externally by the supervisor; report lifecycle state remains external
  supervisor/validator-owned state and is not asserted by this artifact.

## Executive Recommendation

1. Populate UID0002ZY with Destination 1 and raise it to `92/94`.
2. Replace the UID0000EO class declaration with Destination 2 and raise it to
   `92/94`, retaining every unrelated public method and `[[CHILDREN]]` after
   the class-closing brace.
3. Update UID0000ON prose/source inventory and raise the file to `92/92`.
4. Preserve UID0001JM at `86/90` as a broad source-bearing split index; only
   historicalize its constructor blocker and add the source-ready child link.
5. Raise UID0001JP to `88/92`; record exact table identities while retaining
   its unsplit raw-helper blockers and blank aggregate C++.
6. Apply Destinations 5 and 6 to UID0001JQ/UID0001JR so the callbacks share
   exact 16-byte line and 12-byte format-payload types. Recommend `90/93` and
   `91/93`, respectively.
7. Apply Destination 12 to UID0000EN, preserving `m_payload1` as protected and
   adding only the exact `TextRunMeasureCallback` friend contract. Recommend
   `89/92`; do not substitute `GetPayloadPair` or make payload fields public.
8. Apply Destinations 7 and 8 to UID0000EM/UID0004K1, replacing only the stale
   numeric-mode naming with `useThousandsSeparator`; recommend `92/94` for
   both. Update UID0000OM prose to `91/93` without changing its source path.
9. Add exact successor padding `[0x0058e132,0x0058e140)` to
   `by-memory/-ignored.md`. Preserve the existing predecessor row and every
   unrelated range.
10. Keep all 26 callers as consumers. Their constant/dynamic argument evidence
   belongs in target/class/file prose; no caller body requires a semantic code
   change except the bounded TextEditControlPane naming synchronization.
11. After ordinary validation, use a final authorized UID0002ZY
    `--wait-generated` refresh and verify one constructor definition, no target
    empty marker, no aggregate duplicate, exact format/run table order, and
    preserved surrounding TextEditPane content.

## Supervisor Active Recheck

- MCP was rediscovered rather than relying on a stale session. Database
  `9b0396a3`, worker PID `15732`, remained healthy with analysis idle and
  `server_health:ok` through bounded target decompile, exact bytes,
  local-family offset searches, helper decompiles, and caller/xref reads.
- The Gate 1 repair recheck bounded `0x00593c20` and `0x00594ec0` rather than
  repeating a broad search. It proved the callback's direct single-field load
  and the existing accessor's different two-field copy-out shape. No valid
  bounded call failed after restoration.
- Initial target/class/file/support hashes were reread before the report-only
  artifact was written. Callback-current D1-D12, generated, and manual hashes
  are recorded in the terminal sections below; mutable snapshots remain
  evidence-time facts rather than indefinite lifecycle assertions.
- Active B001-B005 report roots contained no direct UID0002ZY report during
  research. No ordinary lease was acquired in that initial phase. During the
  accepted callback B001 used only the twelve short leases enumerated below
  and released each immediately after its scoped validator.
- No callback-time ordinary drift contradicted the accepted source conclusion;
  each edit was rebased over the destination's then-current complete union.

## Inference Research Guidance Check

- Exact behavior was recovered before naming. Names below distinguish direct
  type/offset proof from source-spelling inference.
- `TextEditPane::TextEditPane` is directly established by three vtable stores,
  base construction, 26 allocation/caller sites, and return of `this`.
- `useThousandsSeparator` is medium-high lexical confidence but high semantic
  confidence: the stored byte at `+0x173` has exactly one family read, at
  `0x00594713`, gating insertion of commas into numeric text every three
  digits.
- `useDefaultAlignment` is medium-high lexical confidence but high semantic
  confidence: the stored byte at `+0x172` has no later read in the bounded
  family, but false immediately assigns alignment 2, and only the made-by
  display caller passes false.
- `m_formatTable` and `m_formatRuns` are high semantic confidence. Exact
  original lexical spellings are not symbol-proven, but they are less
  misleading than the current reversed names and align with helper behavior.
- `RebuildLineTable`, `RefreshTextRange`, `ApplyFormatRange`,
  `LoadCurrentFormat`, and `LayoutScrollbars` are descriptive source-facing
  spellings selected from exact behavior and current family vocabulary. The
  report does not claim recovered debug symbols.
- The exact `friend` spellings are source-integration decisions rather than
  recovered debug symbols. They are nevertheless high-confidence policy:
  file-local static prototypes, matching friend declarations, and matching
  later definitions preserve both observed direct loads and existing
  private/protected state without changing ABI or machine behavior.
- No placeholder such as `sub_58DCE0`, `field_13c`, `a12`, `a13`,
  `unknownMode`, or raw offset appears in the accepted/applied source blocks.

## Heuristic / Inference Reanalysis And Validation

- Function identity heuristic: constructor vtable writes at `0x0058dd42`,
  `0x0058dd48`, and `0x0058dd52`, base call `0x0055e660`, three List
  allocations, 26 constructor callsites, and `this` return agree.
- Signature heuristic: physical `retn 0x30` proves 48 bytes of explicit stack
  arguments, exactly twelve four-byte slots. IDA's apparent thirteen-argument
  account includes `this` and is not a thirteen-stack-argument source ABI.
- Boolean heuristic: all caller values for parameters 7, 8, 11, and 12 are
  `0/1` or byte-derived. The callee reads only their low bytes. Source `bool`
  preserves intent without changing the x86 stack width.
- Legacy-mode heuristic: parameter 10 is passed to the accepted
  `SetLegacyAssetMode` helper, whose bounded domain is `0/1`; the machine load
  is 16-bit, so source type stays `unsigned short`.
- Table heuristic: each `new List(elementSize,16)` is followed by an append of
  records whose exact write footprint matches the element size. Cross-helper
  indexing independently confirms the identities.
- Line-table heuristic: `0x00592c20` indexes `+0x138` in 16-byte strides and
  uses `+0x134` as text storage. The callback's historical fields at `+0x10`
  and `+0x14` are the next record's `startIndex` and `top`, not a 24-byte line
  element.
- Format-table heuristic: `0x00592470` indexes `+0x13c` in 16-byte strides and
  `+0x140` in 4-byte strides; `0x00591ec0` reads a run's signed format index,
  then obtains the 12-byte format payload at record `+4`.
- Flags heuristic: caller values cover `0`, `1`, `2`, `4`, `6`, `0x100`, and
  `0x102`; the target tests `0x104`, `0x20`, and `4`, then stores
  `editorFlags | 0x81`. The source uses a bitmask `unsigned int`, not an enum
  falsely claiming a closed domain.
- Exception heuristic: the target registers `L"Nexon.StyledUnicodeText"`
  lazily and throws a heap-allocated `Win32Error *` if registration returns
  zero. `_TI4PAVWin32Error@@` proves a pointer exception. The surrounding EH
  state machine and cleanup funclets are compiler lowering.
- TextEditPane access heuristic: both callback bodies are file-local free
  functions selected by `IterateTextRuns`, not members or lambdas. They make
  direct private/protected field accesses and current class/file docs already
  identify an unresolved friend/access policy. Exact friend declarations
  preserve both the direct loads and non-public class state with no binary
  footprint, making them stronger than widened public fields or raw offsets.
- TextEditObject access heuristic: the measure callback directly loads only
  `m_payload1` at object `+0x10`. The existing `GetPayloadPair(int *)` raw body
  at `0x00594ec0-0x00594ed5` copies both `+0x0c/+0x10` through an output
  pointer and has no call edge from the callback. A friend declaration is the
  only current evidence-backed source contract that preserves the observed
  direct one-field load while retaining protected payload storage.
- Linkage heuristic: namespace-scope `static` prototypes precede the class
  declarations, the classes friend those same functions, and the later
  definitions retain `static`. This forms one internally consistent
  translation-unit-local callback union.
- Source placement heuristic: every body/helper/global clusters in the
  TextEditPane module; dialog/control pages are callers or wrappers only.

## Evidence Standards Used

- Direct/high: exact bytes, PE mapping, modeled function bounds, disassembly,
  stack cleanup, direct xrefs, vtable stores, helper dataflow, field widths,
  List element sizes, literal/string reads, and current ordinary docs.
- Corroborated/high: parameter domains across all 26 callsites, table roles
  across constructor plus three helpers, source owner/emitter across class,
  file, vtables, globals, and generated routing.
- Inferred/medium-high lexical: original local/member/helper spellings and
  whether the original code used constants versus literals.
- Negative evidence is explicit: no direct target report, no extra stack
  argument, no source-authored vptr/cookie/EH body, no caller ownership, no
  read-only interpretation for parameter 11, no generic input-mode use for
  parameter 12, no 24-byte line element, no reversed table identities, no
  public-field widening, and no accessor-call substitution for direct callback
  loads.

## Evidence Checked

- MCP: `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`,
  `analyze_function`, `decompile`, `disasm`, xref/caller/callee queries, local
  family `search_text`, data/global/string reads, and bounded helper queries.
- Local PE: DOS/PE32 headers, i386 machine, image base `0x00400000`, `.text`
  RVA/raw mapping, exact target bytes, target hash, and adjacent padding.
- Ordinary docs: target, TextEditPane class/file/aggregate/formatting/callback
  pages, TextEditControlPane class/file/constructors, ScrollablePane support,
  List, globals, IME focus, vtable, destructor, serialization/draw/input/mouse
  children, and all caller-family pages.
- Historical docs: all path-specific executed reports listed above plus active,
  older-research, special-report, and archived searches.
- Historical report-only generated checkpoint: external command
  `000000014538` TextEditPane.cpp, target/aggregate marker counts, constructor
  absence, then-current TextEditObject-before-TextEditPane source ordering,
  both callback definitions, and the then-current missing-friend compilation
  defect. Current generated truth is command 14635 below.
- Historical initial and pre-application callback coverage checkpoints read
  by-memory/class/file rows and confirmed no by-struct coverage root relevant
  to this target. The current post-application rows/hashes are recorded below.
- During the initial report-only evidence pass, ordinary edits, leases,
  validators, B001-requested generated refresh, manual coverage application,
  IDA mutation, `execute_report`, lifecycle/probe/count commands, movement,
  and archival were intentionally not performed. During the accepted callback,
  the ordinary edits, short leases, scoped validators, and final waited refresh
  enumerated below were performed; manual coverage, IDA mutation,
  `execute_report`, lifecycle/probe/count commands, movement, and archival
  remained unperformed by B001. The supervisor later applied and validated the
  exact accepted coverage rows externally.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C2ZY-001 | UID0002ZY is exactly `[0x0058dce0,0x0058e132)`, size `0x452`. | high | lookup, bytes, PE | D1 target | incorporate | applied |
| C2ZY-002 | Exact target bytes SHA256 is `5D9A2E8E67720730469C4334EA90D5CEA8B8FCD4DA31AC00711E398DAD6A33AD`. | high | MCP and PE bytes | D1 evidence | incorporate | applied |
| C2ZY-003 | Binary identity is MD5 `4247...5515`, SHA256 `9AEC...A632`, image base `0x400000`. | high | health, local hashes | D1 evidence | incorporate | applied |
| C2ZY-004 | Target is one 361-instruction, 46-basic-block constructor with complexity 10. | high | analyze/disasm | D1 evidence | incorporate | applied |
| C2ZY-005 | Source ABI is `thiscall`, returns `this`, has twelve explicit stack slots, and physically uses `retn 0x30`. | high | disasm/decompile | D1/D2 | incorporate | applied |
| C2ZY-006 | The source signature has four dimensions, two colors, two bool scrollbars, flags, legacy ushort, and two bool modes. | high | all callers and callee reads | D1/D2 | incorporate | applied |
| C2ZY-007 | The three TextEditPane vtable stores are compiler output, not handwritten source. | high | disasm/compiler model | D1 history/negative | reject-invalid | excluded-with-reason |
| C2ZY-008 | Base route is `ScrollablePane(hasHorizontalScrollbar,hasVerticalScrollbar)`. | high | direct callee/current support | D1/D2 | incorporate | applied |
| C2ZY-009 | UID0000EO remains canonical owner/emitter; UID0000ON remains source file. | high | vtables, family, docs | D1-D4 | already-present | already-present |
| C2ZY-010 | Target remains one-level nested under UID0001JM with `Nested:8`; this is an indentation delta, not child count. | high | current metadata/generated hierarchy | D1/D4 | already-present | already-present |
| C2ZY-011 | Predecessor `[0x0058dcd3,0x0058dce0)` is thirteen `cc` bytes and already documented. | high | bytes/ignored | verify-only | already-present | already-present |
| C2ZY-012 | Successor `[0x0058e132,0x0058e140)` is fourteen `cc` bytes and is missing from ignored ranges. | high | bytes/ignored search | D11 | incorporate | applied |
| C2ZY-013 | The in-range throw tail belongs to the constructor; no target split is needed. | high | CFG/xrefs | D1/D4 | incorporate | applied |
| C2ZY-014 | External EH funclets, cookie setup, base cleanup, and incomplete-new free are compiler lowering. | high | unwind/disasm | D1/D4 | incorporate | applied |
| C2ZY-015 | The target has exactly 26 direct code xrefs across 17 modeled caller functions. | high | xrefs/analyze | D1-D3 | incorporate | applied |
| C2ZY-016 | All 26 callsites pass twelve explicit arguments in the same order. | high | callsite disasm/decompile | D1/D2 | incorporate | applied |
| C2ZY-017 | Parameters 7/8 are true booleans controlling horizontal/vertical scrollbar construction and 12-pixel viewport deductions. | high | base call and geometry | D1/D2 | incorporate | applied |
| C2ZY-018 | Parameter 9 is an open editor bitmask, not a closed enum. | high | caller domain/bit tests | D1/D2 | incorporate | applied |
| C2ZY-019 | Parameter 10 is `unsigned short legacyAssetMode`, accepted only in domain 0/1. | high | helper and callers | D1/D2 | incorporate | applied |
| C2ZY-020 | Parameter 11 is `useDefaultAlignment`, not `isReadOnly`; false selects alignment 2. | high semantic | direct branch/made-by caller | D1-D3 | reject-stale | excluded-with-reason |
| C2ZY-021 | Parameter 12 is `useThousandsSeparator`, not generic `inputMode`; stored `+0x173` gates comma insertion. | high semantic | local search/decompile 0x5946b0 | D1-D3/D7-D10 | reject-stale | excluded-with-reason |
| C2ZY-022 | `+0x172` is constructor-only in the bounded family; its source spelling remains behavior-descriptive. | high access, medium-high lexical | bounded search | D1/D2 | incorporate | applied |
| C2ZY-023 | `+0x173` has exactly constructor write plus numeric-format read in the bounded family. | high | bounded search | D1/D2 | incorporate | applied |
| C2ZY-024 | Active global updates only when `(editorFlags & 0x104)==0`; otherwise the prior pointer is preserved. | high | target CFG | D1/D3/global prose | incorporate | applied |
| C2ZY-025 | `m_activeLineIndex` at `+0x130` initializes to `-1`. | high | direct write | D1/D2 | incorporate | applied |
| C2ZY-026 | The constructor initializes a two-byte state at `+0x170` to zero. | high | direct word write | D1/D2 prose | incorporate | applied |
| C2ZY-027 | `SetLegacyAssetMode` receives parameter 10 and rejects values above 1. | high | helper decompile | D1/D2 | already-present | already-present |
| C2ZY-028 | `m_textStorage` at `+0x134` is `List(sizeof(wchar_t),128)`. | high | constructor/helpers | D1/D2/D5 | incorporate | applied |
| C2ZY-029 | `m_lineTable` at `+0x138` is `List(sizeof(TextEditLineRecord),16)` with 16-byte records. | high | append/indexing | D1/D2/D5/D6 | incorporate | applied |
| C2ZY-030 | Two zero line records are appended initially. | high | exact append source footprint | D1 | incorporate | applied |
| C2ZY-031 | `m_formatTable` at `+0x13c` is `List(sizeof(TextEditFormatRecord),16)`. | high | append plus helper indexing | D1/D2/D5-D6 | incorporate | applied |
| C2ZY-032 | Initial format record is refcount 1, legacy mode, text color, null object, and zero remaining fields. | high | exact stores | D1/D2 | incorporate | applied |
| C2ZY-033 | `m_formatRuns` at `+0x140` is `List(sizeof(TextEditFormatRun),16)`. | high | append plus helper indexing | D1/D2/D5 | incorporate | applied |
| C2ZY-034 | Initial runs are `{0,0}` and `{1,-1}`. | high | exact local bytes | D1/D2 | incorporate | applied |
| C2ZY-035 | Current `m_styleRuns`/`m_formatRecords` assignments are reversed and must be historicalized. | high | 0x592470/0x591ec0/0x593500 | D2-D6 | reject-stale | excluded-with-reason |
| C2ZY-036 | `TextRunFormatData` is exact 12-byte `{ushort legacy,ushort zero,uint color,TextEditObject*}`. | high | constructor and callbacks | D2/D5/D6 | incorporate | applied |
| C2ZY-037 | `TextEditFormatRecord` is 16 bytes with 4-byte header plus format payload. | high | constructor/list stride | D1/D2/D5 | incorporate | applied |
| C2ZY-038 | `TextEditFormatRun` is 4 bytes with unsigned start and signed format index. | high | sentinel -1 and helper loads | D1/D2/D5 | incorporate | applied |
| C2ZY-039 | Historical 24-byte draw line record is invalid; offsets +16/+20 are the next 16-byte record. | high | line stride/callback dataflow | D2/D5/D6 | reject-stale | excluded-with-reason |
| C2ZY-040 | Constructor rebuilds line range `[0,0x7fff]` after table seeding. | high | direct call | D1/D5 | incorporate | applied |
| C2ZY-041 | Nonzero alignment runs the shared iterator with TextRunMeasureCallback and available text width. | high | address-take/call | D1/D5 | incorporate | applied |
| C2ZY-042 | Text-area bounds initialize to `{0,0,textAreaWidth,textAreaHeight}`. | high | four dword stores | D1/D2 | incorporate | applied |
| C2ZY-043 | Viewport subtracts 12 for each present opposite-axis scrollbar before LayoutScrollbars. | high | direct geometry | D1/base support | incorporate | applied |
| C2ZY-044 | A bottom-only bounds change offsets the text-area rectangle by the vertical delta. | high | equality branch/callee | D1 | incorporate | applied |
| C2ZY-045 | Selection/range refresh runs after layout using the current endpoints. | high | direct call | D1/D5 | incorporate | applied |
| C2ZY-046 | Stored editor flags are `editorFlags | 0x81`. | high | direct OR/write | D1/D2 | incorporate | applied |
| C2ZY-047 | Bit `0x20` applies the initial text color across all text, invalidates current format, then refreshes all text. | high | target branch/helper | D1/D5 | incorporate | applied |
| C2ZY-048 | A collapsed selection loads current format, applies text color, and seeds an empty-document format with mask 3. | high | target branch/helper | D1/D5 | incorporate | applied |
| C2ZY-049 | A noncollapsed selection marks formatting dirty, applies color mask 2, and refreshes the selected range. | high | target branch/helper | D1/D5 | incorporate | applied |
| C2ZY-050 | Masked-text state initializes false. | high | direct byte write | D1/D2 | incorporate | applied |
| C2ZY-051 | Explicit argument 5 is `textColor` and explicit argument 6 is `textBackColor`; `SetTextColor` and `SetTextBackColor` consume them in that order. | high | direct calls/helper docs | D1/D2 | incorporate | applied |
| C2ZY-052 | Constructor defaults are max length 30000 and max lines 30000, not wrapper values 1024/1. | high | packed immediate/caller postcalls | D1-D3/D8-D10 | reject-stale | excluded-with-reason |
| C2ZY-053 | TextEditControlPane later overrides limits to 1024/1. | high | wrapper body | D7-D10 | already-present | already-present |
| C2ZY-054 | Clipboard format is lazily registered as `L"Nexon.StyledUnicodeText"`. | high | string/global/import | D1/D3 | incorporate | applied |
| C2ZY-055 | Registration failure throws `new Win32Error` as a pointer exception. | high | throw info/decompile | D1/D3 | incorporate | applied |
| C2ZY-056 | If editor flag 4 is clear, focus registration is enabled and IME focus is assigned with true. | high | direct callees | D1/D3 | incorporate | applied |
| C2ZY-057 | No explicit List deletion, base destruction, vptr assignment, cookie, or EH label belongs in human source. | high | compiler/source boundary | D1 negative | reject-invalid | excluded-with-reason |
| C2ZY-058 | UID0002ZY should score `92/94`; lexical names and broad surrounding debt cap higher scores. | high | full blocker audit | D1 metadata | incorporate | applied |
| C2ZY-059 | UID0000EO should score `92/94` with exact structs/signature while preserving the full class union. | high | class integration | D2 metadata/formal | incorporate | applied |
| C2ZY-060 | UID0000ON should score `92/92`; broad raw helpers cap file confidence. | high | file integration | D3 prose/score | incorporate | applied |
| C2ZY-061 | UID0001JM remains `86/90` and blank because many other child splits remain unresolved. | high | aggregate scope | D4 prose only | already-present | already-present |
| C2ZY-062 | UID0001JP should score `88/92` but remain a blank aggregate pending raw-helper splits. | high | table closure plus residual debt | D5 prose/score | incorporate | applied |
| C2ZY-063 | UID0001JQ/UID0001JR should use exact shared types and generic callback context, at `90/93` and `91/93`. | high | iterator ABI | D6/D7 metadata/formal | incorporate | applied |
| C2ZY-064 | UID0000EM/UID0004K1 should replace `inputMode` with `useThousandsSeparator` and score `92/94`. | high | wrapper/target route | D8/D9 metadata/formal | incorporate | applied |
| C2ZY-065 | UID0000OM should record the semantic rename and constructor defaults at `91/93`. | high | file integration | D10 prose/score | incorporate | applied |
| C2ZY-066 | All other caller bodies preserve behavior and need evidence/link synchronization only, not code changes. | high | callsite audit | D1-D3 support prose | already-present | already-present |
| C2ZY-067 | Current generated target empty marker is historical pre-callback state and should become one constructor definition. | high | generated checkpoint | callback verification | historicalize | excluded-with-reason |
| C2ZY-068 | Exact supervisor-owned manual coverage rows are supplied; B001 must not edit coverage. | high | current manual read | coverage handoff | incorporate | applied |
| C2ZY-069 | Prior family reports are evidence leads, not direct target authority. | high | full root search | report/history | historicalize | excluded-with-reason |
| C2ZY-070 | No IDA rename/type/comment mutation is required for report quality; recommendations are documentation-only. | high | workflow boundary | report | not-applicable | excluded-with-reason |
| C2ZY-071 | Report-only work used no lease, validator, generated refresh, lifecycle command, or ordinary edit. | high | operational record | Validator Results/Changed Files | not-applicable | excluded-with-reason |
| C2ZY-072 | Implementation must preserve concurrent ordinary content and finish with scoped validators, waited generation, and zero leases. | high | workflow | callback checklist | incorporate | applied |
| C2ZY-073 | TextRunMeasureCallback and DrawTextRunCallback must be exact friends of TextEditPane so private state remains private and direct callback accesses compile. | high source integration | direct loads, file-local linkage, current access caveat | D2/D3/D5-D7 | incorporate | applied |
| C2ZY-074 | TextRunMeasureCallback must be an exact friend of TextEditObject; widening protected payload fields or calling GetPayloadPair would conflict with current declaration policy or observed direct-load shape. | high source integration | live MCP direct load, raw accessor bytes/disasm, current class | D2/D3/D6/D12 | incorporate | applied |

### Callback Claim Verification Proof

| Claim ID | Terminal destination-specific proof |
| --- | --- |
| C2ZY-001 | D1 retains exact `[0x0058dce0,0x0058e132)` path/range and records size `0x452`; command 14560 passed. |
| C2ZY-002 | D1 `## Evidence` now contains the full exact target-byte SHA256 `5D9A2E8E67720730469C4334EA90D5CEA8B8FCD4DA31AC00711E398DAD6A33AD`; scoped waited repair command 14623 passed without changing the range, formal C++, metadata, ownership, score, behavior, or source placement. |
| C2ZY-003 | D1 preserves executable MD5/SHA256/image-base identity and PE mapping; no IDA/binary mutation occurred. |
| C2ZY-004 | D1 records 361 instructions, 46 blocks, complexity 10, and one constructor CFG; validated by 14560. |
| C2ZY-005 | D1 body and D2 declaration use twelve explicit arguments and document physical `retn 0x30`; commands 14560/14561 passed. |
| C2ZY-006 | D1/D2 exact signature contains four dimensions, two colors, two scrollbar bools, flags, legacy ushort, and two final bools. |
| C2ZY-007 | D1 negative/history text excludes three vtable stores from source; generated target body contains no vtable token. |
| C2ZY-008 | D1 initializer and D2 inheritance use `ScrollablePane(hasHorizontalScrollbar, hasVerticalScrollbar)`; support pages remained same-or-greater. |
| C2ZY-009 | D1 retains owner/emitter UID0000EO; D2 retains file emitter UID0000ON; D3/D4 source routing is unchanged. |
| C2ZY-010 | D1 retains `Nested:8`; D4 remains the source-bearing parent index and generated hierarchy remains bounded. |
| C2ZY-011 | Read-only D11 check preserved existing predecessor `[0x0058dcd3,0x0058dce0)` exactly. |
| C2ZY-012 | D11 now contains one exact `[0x0058e132,0x0058e140)` fourteen-`cc` row; command 14596 passed. |
| C2ZY-013 | D1 records the registration-failure throw tail inside the constructor and rejects a split; D4 inventory links one child. |
| C2ZY-014 | D1/D4 preserve external EH/cookie/base/incomplete-new cleanup as compiler lowering; generated body contains none. |
| C2ZY-015 | D1/D3 record exactly 26 direct callsites across 17 modeled functions; no caller source ownership moved. |
| C2ZY-016 | D1/D2 preserve the complete 26-caller twelve-slot audit and matching declaration ordering. |
| C2ZY-017 | D1/D2 use independent horizontal/vertical booleans and exact opposite-axis 12-pixel viewport deductions. |
| C2ZY-018 | D1/D2 retain `unsigned int editorFlags` and document its open bitmask domain. |
| C2ZY-019 | D1/D2 retain `unsigned short legacyAssetMode` and the observed 0/1 domain. |
| C2ZY-020 | D1-D3 historicalize `isReadOnly`; current source uses `useDefaultAlignment` and preserves the made-by right-alignment proof. |
| C2ZY-021 | D1-D3 and D8-D10 historicalize `inputMode`; current accepted route uses `useThousandsSeparator` with zero generated stale tokens. |
| C2ZY-022 | D1/D2 use descriptive `m_useDefaultAlignment` at `+0x172` and preserve the bounded constructor-only access caveat. |
| C2ZY-023 | D1/D2 use `m_useThousandsSeparator` at `+0x173` and document constructor write plus numeric-format read. |
| C2ZY-024 | D1/D3 preserve conditional `g_pActiveTextEditPane` replacement under mask `0x104`; global support hash remained unchanged. |
| C2ZY-025 | D1/D2 initialize `m_activeLineIndex` to `-1` exactly. |
| C2ZY-026 | D1/D2 preserve the zeroed two-byte `m_inputState` at `+0x170`. |
| C2ZY-027 | D1/D2 retain existing `SetLegacyAssetMode` call/domain evidence at same-or-greater detail. |
| C2ZY-028 | D1/D2/D5 now agree on 2-byte `TextRunTextTable m_textStorage`; commands 14560/14561/14565 passed. |
| C2ZY-029 | D1/D2/D5/D6 use exact 16-byte `TextEditLineRecord`/line table and generic callback union. |
| C2ZY-030 | D1 exact formal appends two zero line records and generated output contains the same initialization once. |
| C2ZY-031 | D1/D2/D5/D6 use 16-byte `TextEditFormatRecord` at `+0x13c`; generated format-table initialization precedes runs. |
| C2ZY-032 | D1 exact initial format record has refcount one, legacy mode, text color, null object, and zero initialization. |
| C2ZY-033 | D1/D2/D5 use 4-byte `TextEditFormatRun` at `+0x140`. |
| C2ZY-034 | D1 exact initial run array is `{0,0}`, `{1,-1}` and generated output contains it once. |
| C2ZY-035 | D2-D7 current prose/types reject the former `+0x13c/+0x140` reversal while preserving it as historical evidence. |
| C2ZY-036 | D2/D5/D6 define/use exact 12-byte `TextRunFormatData`; D6 block matches the accepted destination byte-for-byte. |
| C2ZY-037 | D1/D2/D5 define 16-byte `TextEditFormatRecord` with 4-byte header plus 12-byte payload. |
| C2ZY-038 | D1/D2/D5 define 4-byte `TextEditFormatRun` with unsigned start and signed format index. |
| C2ZY-039 | D2/D5/D7 reject the 24-byte overlay; D7 exact body reads lower edge as `line[1].top`. |
| C2ZY-040 | D1/D5 preserve rebuild range `[0,0x7fff]`; generated constructor contains it once. |
| C2ZY-041 | D1/D5 and D6 preserve the nonzero-alignment iterator route through `TextRunMeasureCallback`. |
| C2ZY-042 | D1/D2 preserve initial `{0,0,textAreaWidth,textAreaHeight}` bounds. |
| C2ZY-043 | D1/base support preserves opposite-axis scrollbar deductions before `LayoutScrollbars`; verify-only base hashes are unchanged. |
| C2ZY-044 | D1 exact body offsets text area only for the observed bottom-only bounds delta. |
| C2ZY-045 | D1/D5 preserve post-layout range refresh using current selection endpoints. |
| C2ZY-046 | D1/D2 preserve `editorFlags | 0x81`. |
| C2ZY-047 | D1/D5 preserve bit-`0x20` all-text color application, invalidation, and refresh. |
| C2ZY-048 | D1/D5 preserve collapsed-selection current-format loading, color update, and empty mask-3 seed. |
| C2ZY-049 | D1/D5 preserve noncollapsed dirty mark, mask-2 color application, and selected-range refresh. |
| C2ZY-050 | D1/D2 initialize `m_maskedText` false. |
| C2ZY-051 | D1/D2 exact formals use explicit arguments 5/6 as `textColor`/`textBackColor` and call setters in that order. |
| C2ZY-052 | D1-D3 and D8-D10 distinguish constructor `30000/30000` defaults from wrapper `1024/1`; both generated units agree. |
| C2ZY-053 | D8-D10 retained the already-present wrapper `SetMaxLength(1024)` / `SetMaxLines(1)` source exactly. |
| C2ZY-054 | D1/D3 and generated TextEditPane.cpp contain one lazy `L"Nexon.StyledUnicodeText"` registration. |
| C2ZY-055 | D1/D3 and generated target body contain one registration-failure `throw new Win32Error`. |
| C2ZY-056 | D1/D3 preserve flag-4 conditional focus registration and IME focus assignment; verify-only consumer support remains same-or-greater. |
| C2ZY-057 | D1 negative/history and generated readback exclude explicit List deletion, base teardown, vptr, cookie, and EH-label source. |
| C2ZY-058 | D1 is current `92/94`; command 14560 applied it, command 14598 performed the accepted callback refresh, and evidence-only repair command 14623 preserved the score and source body. |
| C2ZY-059 | D2 is current `92/94`, exact Destination 2, with full prior class union preserved; command 14561 passed. |
| C2ZY-060 | D3 is current `92/92` with raw-helper confidence cap preserved; command 14562 passed. |
| C2ZY-061 | D4 remains `86/90`, blank, and source-bearing with only constructor-specific blockers historicalized; command 14563 passed. |
| C2ZY-062 | D5 is `88/92`, blank only for residual raw-helper splits, with exact table closure; command 14565 passed. |
| C2ZY-063 | D6/D7 are `90/93` and `91/93`, exact Destinations 5/6, with generic context/shared types; commands 14573/14583 passed. |
| C2ZY-064 | D8/D9 are `92/94`, exact Destinations 7/8, and generated control output has zero stale mode tokens; commands 14590/14594 passed. |
| C2ZY-065 | D10 is `91/93` with exact semantic/default/source-route sync; command 14595 passed. |
| C2ZY-066 | D1-D3 retain the 26-callsite consumer inventory; no caller page needed a body or ownership change. |
| C2ZY-067 | Current validator-owned union command 14635 preserves one target marker/definition and zero target empty marker; evidence-repair command 14623 and accepted-callback command 14598 remain historical proof, and command 14598 had already superseded pre-callback command 14538. |
| C2ZY-068 | The exact manual text remains in this report as durable handoff provenance; the supervisor applied/validated every accepted row through commands 14636-14638 and preserved it through combined commands 14639-14641, while B001 made no coverage edit. |
| C2ZY-069 | Historical matching reports remain explicitly evidence-time leads; no authority or lifecycle claim was promoted. |
| C2ZY-070 | No IDA rename/type/comment mutation occurred; accepted source names were applied only to ordinary documentation. |
| C2ZY-071 | Initial no-action report-only record remains phase-qualified and excluded from callback action; actual callback commands are enumerated later. |
| C2ZY-072 | D1-D12 were reread, leased/validated/released serially during the accepted callback; D1 was separately leased/validated/released for the bounded evidence repair, command 14623 completed its waited refresh, and final lease readback shows no B001 row. |
| C2ZY-073 | D2 exact friend union, D3/D5 prose, and D6/D7 exact bodies preserve private TextEditPane state with no raw-offset workaround. |
| C2ZY-074 | D12 exact friend union plus D2/D3/D6 integration preserves protected `m_payload1`; generated source contains no accessor substitution/public widening. |

## Positive Evidence Summary

- Exact target bytes and local PE bytes agree on the full 1,106-byte range and
  SHA256.
- Constructor identity is supported by base construction, three derived
  vtable installs, allocation callsites, 26 direct constructor calls, and
  return of the complete object pointer.
- Physical `retn 0x30` closes the signature count independently of Hex-Rays
  argument labels.
- Every caller was audited. Constant domains and the one parameter-11 false
  caller resolve the boolean semantics without relying on names from older
  reports.
- Three independent helpers prove the four List/table identities and resolve
  the current reversed names.
- The numeric formatter at `0x005946b0` gives a direct semantic use for
  parameter 12; no alternate use exists in the bounded family search.
- Restored-session decompile of `0x00593c20` proves direct TextEditPane and
  `TextEditObject::m_payload1` loads. Raw accessor bytes at
  `0x00594ec0-0x00594ed5` prove the public helper has a different two-field
  copy-out shape. Exact friends therefore close both source-access contracts
  without altering emitted machine behavior.
- Exact imports, RTTI throw info, string literal, global refs, and IME helper
  close the registration/focus tail.
- The range is bracketed by complete `cc` padding and needs no source split.

## IDA MCP Facts

- Database/session: `9b0396a3`.
- Gate 1 repair health recheck: active worker PID `15732`, analysis not
  running, `status:ok`, auto-analysis/Hex-Rays/string cache ready.
- Function: `sub_58DCE0`, start `0x0058dce0`, end `0x0058e132`, size
  `0x452` / 1,106.
- Profile: 361 instructions, 46 basic blocks, cyclomatic complexity 10,
  17 modeled caller functions, 26 direct code xrefs.
- First 16 bytes:
  `55 8b ec 6a ff 68 8f 96 60 00 64 a1 00 00 00 00`.
- Last 16 bytes:
  `94 68 d4 90 65 00 50 c6 45 fc 00 e8 d8 c0 03 00`.
- Exact target SHA256:
  `5D9A2E8E67720730469C4334EA90D5CEA8B8FCD4DA31AC00711E398DAD6A33AD`.
- ABI: ECX complete-object receiver; twelve 4-byte stack slots; EAX returns
  `this`; physical cleanup `retn 30h`.
- Prologue: x86 MSVC SEH registration, local frame `0x84`, security cookie,
  saved registers. These are not source parameters or members.
- Direct target callees include ScrollablePane construction, List allocation/
  construction/append, SetLegacyAssetMode, line rebuilding, run iteration,
  layout, rectangle offset, range refresh, format apply/load, color setters,
  clipboard registration, Win32Error construction/throw, focus registration,
  and IME focus assignment.
- Vtable references: TextEditPane primary at `0x0062df94` and secondary views
  at `0x0062e00c` and `0x0062e03c`.
- Globals: active editor `0x0069be00`, clipboard format `0x0069bdfc`, IME pane
  pointer `0x0069b458`, clipboard string pointer `0x0062e138`.
- Offset search in `[0x0058d000,0x00596000)` found `+0x172` only at the
  constructor store and `+0x173` at constructor store plus the numeric
  formatting read. Valid bounded calls completed successfully.
- Bounded repair query at `0x00593c20` returned a `0xc5` callback and direct
  `mov`-equivalent reads of format object `+0x08`, object `+0x10`, and pane
  `+0x16a`. No payload accessor call appears.
- Bounded bytes/disassembly at raw
  `0x00594ec0-0x00594ed5` returned
  `55 8b ec 8b 45 08 8b 51 0c 8b 49 10 89 10 89 48 04 5d c2 04 00`:
  `GetPayloadPair(int *)` copies both payload dwords and cannot replace the
  callback's direct single-field load without changing source/call shape.
- PE mapping: PE32 i386, image base `0x00400000`, `.text` RVA `0x1000`, raw
  pointer `0x400`, target RVA `0x18dce0`, file offset `0x18d0e0`, `.text`
  virtual size `0x20b4ac`, raw size `0x20b600`.

## Function / Child Inventory

| Range/entity | Classification | Source disposition | Evidence/result |
| --- | --- | --- | --- |
| `[0x0058dcd3,0x0058dce0)` | predecessor padding | already ignored | Thirteen `cc` bytes; preserve existing row. |
| `[0x0058dce0,0x0058e132)` UID0002ZY | complete TextEditPane constructor | source-authored, reconstructable | Destination 1; `92/94`; no split. |
| `0x0058dce0-0x0058e0e0` | main constructor flow | covered by UID0002ZY source | Base, tables, layout, formatting, globals, focus, normal return. |
| `0x0058e0fd-0x0058e132` | registration-failure throw tail | covered by UID0002ZY source | `throw new Win32Error`; noncontiguous compiler layout within same function. |
| external `0x00609650` family | EH cleanup funclets | compiler-generated | Base cleanup and incomplete-new free; blank/no body. |
| `[0x0058e132,0x0058e140)` | successor padding | ignored, applied | Fourteen `cc` bytes; current D11 contains the exact row once. |
| `[0x0058e140,...)` UID0002ZZ | ordinary destructor successor | separate existing child | Not part of UID0002ZY; current body/metadata remain preserved. |

## Direct Xref / Caller Inventory

All 26 direct callsites were independently inspected. Argument tuples below
use source order `(viewportW,viewportH,textAreaW,textAreaH,textColor,textBackColor,hScroll,vScroll,flags,legacy,useDefaultAlignment,useThousandsSeparator)`.

| Callsite | Containing source family | Exact/recovered argument behavior |
| --- | --- | --- |
| `0x00475af2` | ArticleDialogCore | `(405,200,379,200,143,0,false,true,6,legacy,true,false)` |
| `0x00476222` | ArticleDialogCore | `(374,180,362,180,143,0,false,true,6,legacy,true,false)` |
| `0x0047ba8e` | MailDialogCore | `(405,228,379,228,143,0,false,true,6,legacy,true,false)` |
| `0x0047c311` | MailDialogCore | `(374,168,362,168,143,0,false,true,6,legacy,true,false)` |
| `0x004840f5` | ClanStatusPaneConstructor | `(156,192,156,192,128,0,false,true,2,legacy,true,false)` |
| `0x004885dd` | ClanInfoListPaneRawConstructor | Same fixed read-only clan view tuple as `0x004840f5`. |
| `0x00498a82` | TextEditControlPaneConstructors | Dynamic dimensions/colors/scrollbars; flags from alternate and multiline booleans; `legacy,true,m_useThousandsSeparator`. |
| `0x00499137` | StaticTextControlPaneConstructor | Dynamic dimensions/colors; no scrollbars; flags `4` or `6`; `legacy,true,false`. |
| `0x004a01a1` | AlertPaneCore | Mirrored dynamic dimensions; colors `128`/dynamic; no scrollbars; flags `6`; `legacy,true,false`. |
| `0x004f1d64` | LineInputPaneConstructor | Width `0x251-short`, height 12; colors `128/0`; flags `0x100`; `legacy,true,false`. |
| `0x004f1f27` | LineInputPaneConstructor | Width `0x198-short`, height 12; colors `128/143`; flags `0x100`; `legacy,true,false`. |
| `0x004ff175` | ScrolledTextControlPaneCore | Mirrored rect dimensions; colors `143/0`; no scrollbars; flags `1`; `legacy,true,false`. |
| `0x004ff535` | ScrolledTextControlPaneForMadeByConstructor | Made-by display tuple; parameter 11 is false and parameter 12 false; false selects right alignment. |
| `0x0056bad7` | GroupListPaneRawConstructor | `(145,84,145,84,128,0,false,true,6,legacy,true,false)` |
| `0x0056bb81` | SpelledPane | Legacy-dependent `(145/169,108/83,145/155,same,128,0,false,true,6,legacy,true,false)`. |
| `0x0056bc15` | SpelledPane | Second constructor path with same legacy-dependent parameter contract. |
| `0x0056c461` | LegendPane | Legacy-dependent `(145/175,180/229,145/160,same,128,0,false,true,6,legacy,true,false)`. |
| `0x0056c559` | GroupPane | `(145,84,145,84,128,0,false,true,6,legacy,true,false)` |
| `0x0056c809` | GroupPane2 | Same fixed group tuple. |
| `0x0057fdec` | IntegrateMacroEditControlPaneConstructor | Dynamic mirrored dimensions; colors `128/143`; flags `0x102`; `legacy,true,false`. |
| `0x0058eefa` | TextEditPane local temporary measurement helper | `(dynamicWidth,10,dynamicWidth,10,128,0,false,false,6,legacy,true,false)` |
| `0x005953ee` | TextBoxPaneConstructor | Dynamic mirrored dimensions/colors; no scrollbars; flags `bool ? 2 : 0`; `legacy,true,false`. |
| `0x0059f333` | UserLookPaneConstructor | `(145,108,145,108,128,0,false,true,6,legacy,true,false)` |
| `0x0059f3c9` | UserLookPaneConstructor | Second embedded child with the same fixed tuple. |
| `0x005a2317` | MoreInfoPaneRawConstructor | `(145,108,145,108,128,0,false,true,6,legacy,true,false)` |
| `0x005a2397` | ProfilePaneRawConstructor | Same fixed profile tuple. |

Caller conclusions:

- No caller passes a thirteenth stack argument.
- All normal interactive/static callers pass `useDefaultAlignment=true`; the
  made-by display passes false and is visibly right-aligned.
- Only TextEditControlPane forwards a dynamic final byte. That wrapper field
  reaches `+0x173`, whose only semantic read is thousands grouping.
- Scrollbar bools are independent and match viewport deductions and base
  construction. The source signature should not collapse them into flags.
- Callers are consumers, not source owners. Their bodies need no ownership or
  constructor-body duplication.

## Documentation Evidence And IDA Status

- D1 target current SHA256:
  `C2B031A631E5E32901504F18D5528A2F721CCD1D158E41BD2A88E00206DD72F9`
  (16,306 bytes / 233 lines), with exact `92/94` metadata, Destination 1, and
  full target-byte SHA256 `5D9A2E8E67720730469C4334EA90D5CEA8B8FCD4DA31AC00711E398DAD6A33AD`
  in `## Evidence`.
- D2 TextEditPane class current SHA256:
  `A4315D823420DDA095CEA4D6C4F3C829E5F3A3B9A1C5ED402D9E995D4EC497F3`
  (63,553 / 531), with Destination 2 and the preserved full class union.
- D3 TextEditPane file current SHA256:
  `143E904A6E4CC431CBE3B6E8D02E6E620A08D6A26BB10E33E452C74FEF5AFC07`
  (72,181 / 365).
- D4 UID0001JM aggregate current SHA256:
  `01FD2E0529A2DF837CA4EAD1A1A146EE8E37FC5F5F7D19785478E5BB4A6FCDDA`
  (23,576 / 135); it remains `86/90` and blank.
- D5 UID0001JP formatting aggregate current SHA256:
  `7D6E98F3D0C10C2321F7ABF3CA7B80FABB6BBA52B9658B344A23100B0ADDC5BC`
  (18,123 / 170), now `88/92` and blank.
- D6 UID0001JQ measure callback current SHA256:
  `58EA37BDCA774EA835ED8A1353DB743287F6A4E987DD3C4D79D80A479A8C0683`
  (18,996 / 199), now `90/93` with Destination 5 exact.
- D7 UID0001JR draw callback current SHA256:
  `4CA9A52C36E7CA6DADCB523D0602EB5EB99B4EE59187EDC8B75C682C728654A1`
  (22,439 / 213), now `91/93` with Destination 6 exact.
- D8 TextEditControlPane class current SHA256:
  `D925F7CEF9B14810A68929EB4D230BD665767E1798FCF3482A6B56008B55FA4F`
  (13,987 / 166), now `92/94` with Destination 7 exact.
- D9 UID0004K1 constructors current SHA256:
  `F4F0FB8D0AF5740C095049D27CC518CF20A1C2C82F26C8406C2A4F4B10A09C52`
  (8,441 / 130), now `92/94` with Destination 8 exact.
- D10 TextEditControlPane file current SHA256:
  `5C59C0ED5EEF7F298D9E72F43DDECAAB080E80C77E3537B194EF2F3A441B9F08`
  (9,767 / 91), now `91/93`.
- D11 ignored ranges current SHA256 is
  `BF1732216162084176AF56C8ED6669E24B391C07BBA42AAEAF85853599409A33`
  (1,052,628 / 5,150); predecessor and exact successor rows each exist once.
- D12 TextEditObject class current SHA256:
  `4139274A9C4A0EBE60677AEA9C5F7678A9D1F606F27F520BA5A579A1643667B1`
  (18,309 / 168), now `89/92` with Destination 12 exact and protected payloads.
- Verify-only ScrollablePane class/core hashes are
  `39C1BF0235D9E8373ED28766B001CB1A958C07375E82E2CA678E109258CAB602`
  and `C09D1D4665366D57AF525A4230053F17E253FFF7C3B132ADDAFC582D32EAE4F1`.
- Verify-only active-editor global SHA256 is
  `FE24AC15E8BEB9EFC77267A2298DA86C7D9E82A43B336FD2B8E6F28701530999`.
- Verify-only clipboard static SHA256 is
  `5CF93B6400FED4217E90D7E3F467A9C4B2F64DE93AAF1A2065BB202D7BD47677`.
- Verify-only exact global aggregate SHA256 is
  `8B132C23F82DE68307D49A0C2DA5456656BF6DDB935E8D9334ECA8D8A2C398F2`.
- Verify-only IME focus helper current SHA256 is
  `231DEC37A3157357D2B8BF7D1DC0F653E7FA4670E0B94949B7AF8A78741262A3`;
  its newer concurrent metadata/content remains same-or-greater and does not
  contradict the accepted TextEditPane consumer boundary.
- Verify-only List class SHA256 is
  `1AD869D2B329EDD38A26349DF9EC38C096A50A4DA6A22EAB12DAFDEBE1D94B1D`.
- No IDA mutation was performed. Accepted names and declarations are applied
  to D1-D12; descriptive spellings remain source recommendations rather than
  claims of recovered private symbols.

## Ranked Ownership Analysis

1. `TextEditPane` / UID0000EO, very high probability. Three vtable stores,
   fields, helpers, globals, destructor, callbacks, and all callers agree.
2. `TextEditPane.cpp` / UID0000ON, very high probability. Target, formatting,
   callbacks, globals, and support objects form one cohesive module cluster.
3. `TextEditControlPane`, caller/wrapper only. It constructs and limits a
   TextEditPane but does not own the base constructor source.
4. `ScrollablePane`, base/dependency only. It owns base construction and
   scrollbar layout, not the derived table/global/clipboard body.
5. Dialog/Group/UserLook/TextBox/Macro families, consumers only. Their callsite
   constants improve signature confidence but do not transfer ownership.
6. Compiler/runtime, excluded. MSVC EH/cookie/vptr/allocation lowering explains
   mechanical instructions but does not own project source behavior.

## Source Placement

- Header declaration: `NexusTK/ui/controls/TextEditPane.h` through UID0000EO.
- Definition: `NexusTK/ui/controls/TextEditPane.cpp` through UID0000ON.
- Constructor child: UID0002ZY emitted by UID0000EO, blank explicit position,
  address/source order under UID0001JM.
- File-local iterator callbacks stay in TextEditPane.cpp. Their shared record
  declarations must be visible before both callbacks and constructor.
- TextEditControlPane declaration/constructor remain in their existing
  `NexusTK/ui/controls/TextEditControlPane` route. Only the semantic final-byte
  naming changes.
- No standalone `TextEditPaneConstructor.cpp`, dialog source move, List source
  move, ScrollablePane ownership transfer, or generated-only body is justified.

## Range / Split / Padding / Reclassification Analysis

- Keep target path/range unchanged.
- No source split: all in-range branches are constructor behavior or compiler
  lowering for that behavior.
- Keep `Nested:8`; current generated hierarchy proves this is the established
  one-level delta below UID0001JM.
- Preserve existing predecessor ignored range
  `[0x0058dcd3,0x0058dce0)`.
- Add exact successor ignored range `[0x0058e132,0x0058e140)`, fourteen `cc`
  bytes, before the ordinary destructor.
- Do not absorb the destructor at `0x0058e140`, the external EH funclets, the
  vtable data, globals, or callbacks into UID0002ZY.
- UID0001JM remains a broad source-bearing split index; this callback resolves
  only its constructor child and dependent table declarations.

## Negative Evidence Summary

- No direct historical UID0002ZY report exists.
- No thirteenth explicit stack argument exists; `this` is not a stack argument.
- Parameter 11 is not a read-only/editable toggle. The false made-by instance
  still constructs and renders; editor flags and later state methods control
  editability.
- Parameter 12 is not a generic input mode. No bounded family use exists other
  than thousands grouping.
- The 16-byte line List is not a 24-byte record. Callback reads beyond +15
  address the next list element.
- `+0x13c` is not a run list and `+0x140` is not a 16-byte format list.
- The constructor defaults are not 1024/1. Those values are wrapper postcalls.
- The active-editor global is not unconditionally overwritten by `this`.
- Clipboard registration failure is not silently ignored and does not throw a
  value `Win32Error`; RTTI proves a pointer exception.
- Explicit vptr writes, SEH records, cookie checks, state labels, allocation
  cleanup labels, base teardown, and `_CxxThrowException` calls are not
  handwritten source.
- No caller, base class, global page, callback page, or aggregate should emit a
  duplicate constructor body.
- No new UID, rename, source file, external library, or IDA edit is required.
- The callback-consumed TextEditPane state must not be made public. Both
  callbacks are free `__cdecl` address-taken functions, so converting them to
  members would contradict the observed callback ABI and linkage.
- `TextEditObject::m_payload1` must not be made public merely to satisfy one
  callback. Calling `GetPayloadPair(int *)` is also rejected: the binary has no
  such call edge, and the helper copies both payload fields through an output
  buffer instead of directly reading only `m_payload1`.

## IDA Rename / Type / Comment Recommendations

- Documentation/source recommendations only; do not mutate IDA in this task.
- `sub_58DCE0` -> `TextEditPane::TextEditPane`.
- Stack arguments after `this` -> `viewportWidth`, `viewportHeight`,
  `textAreaWidth`, `textAreaHeight`, `textColor`, `textBackColor`,
  `hasHorizontalScrollbar`, `hasVerticalScrollbar`, `editorFlags`,
  `legacyAssetMode`, `useDefaultAlignment`, `useThousandsSeparator`.
- `this+0x134` -> `m_textStorage`.
- `this+0x138` -> `m_lineTable`.
- `this+0x13c` -> `m_formatTable`.
- `this+0x140` -> `m_formatRuns`.
- `this+0x172` -> `m_useDefaultAlignment`.
- `this+0x173` -> `m_useThousandsSeparator`.
- `sub_592C20` -> `TextEditPane::RebuildLineTable`.
- `sub_593500` -> `TextEditPane::IterateTextRuns`.
- `sub_591400` -> `TextEditPane::RefreshTextRange`.
- `sub_592470` -> `TextEditPane::ApplyFormatRange`.
- `sub_591EC0` -> `TextEditPane::LoadCurrentFormat`.
- `sub_55EC00` -> `ScrollablePane::LayoutScrollbars` as a descriptive current
  source name, not a claimed debug symbol.
- At `0x0058e0a8`, comment the lazy `Nexon.StyledUnicodeText` registration and
  pointer exception path. Do not comment compiler state-machine offsets as
  source behavior.
- No IDA type mutation is needed for the access repair. The exact file-local
  static prototypes and matching class friends belong in reconstructed source
  declarations only; they have no binary address, field, or calling-convention
  effect.

## First-Draft C++ Recommendation

All seven destination-specific managed values below are now applied exactly;
the heading is retained as the literal required report-template heading.

### Destination 1 - UID0002ZY target managed value

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace {
const int kTextEditScrollbarSize = 12;
const unsigned int kTextEditPreserveActiveEditor = 0x104;
const unsigned int kTextEditApplyInitialColor = 0x20;
const unsigned int kTextEditNoImeFocus = 0x04;
const unsigned int kTextEditInitialStateFlags = 0x81;
const unsigned char kTextEditColorFormatMask = 2;
const unsigned char kTextEditCompleteFormatMask = 3;
const short kTextEditDefaultLimit = 30000;
}

TextEditPane::TextEditPane(int viewportWidth,
                           int viewportHeight,
                           int textAreaWidth,
                           int textAreaHeight,
                           int textColor,
                           int textBackColor,
                           bool hasHorizontalScrollbar,
                           bool hasVerticalScrollbar,
                           unsigned int editorFlags,
                           unsigned short legacyAssetMode,
                           bool useDefaultAlignment,
                           bool useThousandsSeparator)
    : ScrollablePane(hasHorizontalScrollbar, hasVerticalScrollbar)
{
    m_useThousandsSeparator = useThousandsSeparator;
    if ((editorFlags & kTextEditPreserveActiveEditor) == 0)
        g_pActiveTextEditPane = this;

    m_activeLineIndex = -1;
    m_useDefaultAlignment = useDefaultAlignment;
    if (!m_useDefaultAlignment)
        m_textAlignment = 2;

    m_inputState = 0;
    SetLegacyAssetMode(legacyAssetMode);

    m_textStorage = new List(sizeof(wchar_t), 128);

    m_lineTable = new List(sizeof(TextEditLineRecord), 16);
    TextEditLineRecord initialLines[2] = { 0 };
    m_lineTable->Append(2, initialLines);

    m_formatTable = new List(sizeof(TextEditFormatRecord), 16);
    TextEditFormatRecord initialFormat = { 0 };
    initialFormat.referenceCount = 1;
    initialFormat.format.legacyAssetMode = legacyAssetMode;
    initialFormat.format.textColor = textColor;
    initialFormat.format.object = NULL;
    m_formatTable->Append(1, &initialFormat);

    m_formatRuns = new List(sizeof(TextEditFormatRun), 16);
    TextEditFormatRun initialRuns[2] = {
        { 0, 0 },
        { 1, -1 }
    };
    m_formatRuns->Append(2, initialRuns);

    m_selectionStart = 0;
    m_selectionEnd = 0;

    short firstLine = 0;
    short lastLine = 0x7fff;
    RebuildLineTable(&firstLine, &lastLine);

    if (m_textAlignment != 0) {
        TextRunMeasureState state = {
            m_textAreaRight - m_textAreaLeft,
            0,
            0
        };
        IterateTextRuns(firstLine,
                        lastLine,
                        TextRunMeasureCallback,
                        &state);
    }

    RectBounds textArea = { 0, 0, textAreaWidth, textAreaHeight };
    SetTextAreaBounds(&textArea);

    RectBounds viewport = {
        0,
        0,
        viewportWidth - (hasVerticalScrollbar ? kTextEditScrollbarSize : 0),
        viewportHeight - (hasHorizontalScrollbar ? kTextEditScrollbarSize : 0)
    };
    const RectBounds oldBounds = m_bounds;
    LayoutScrollbars(&viewport);
    if (oldBounds.left == m_bounds.left &&
        oldBounds.top == m_bounds.top &&
        oldBounds.right == m_bounds.right &&
        oldBounds.bottom != m_bounds.bottom) {
        OffsetRect(&textArea, 0, m_bounds.bottom - oldBounds.bottom);
        SetTextAreaBounds(&textArea);
    }

    RefreshTextRange(m_selectionStart, m_selectionEnd);
    m_editorFlags = editorFlags | kTextEditInitialStateFlags;

    TextRunFormatData colorFormat = { 0 };
    colorFormat.textColor = textColor;
    if ((editorFlags & kTextEditApplyInitialColor) != 0) {
        ApplyFormatRange(0,
                         static_cast<short>(m_textStorage->GetCount()),
                         kTextEditColorFormatMask,
                         &colorFormat);
        m_currentFormatValid = false;
        RefreshTextRange(0, static_cast<short>(m_textStorage->GetCount()));
    } else if (m_selectionStart == m_selectionEnd) {
        LoadCurrentFormat();
        m_currentFormat.textColor = textColor;
        if (m_textStorage->GetCount() == 0) {
            ApplyFormatRange(0,
                             0,
                             kTextEditCompleteFormatMask,
                             &m_currentFormat);
        }
    } else {
        m_dirty = true;
        ApplyFormatRange(m_selectionStart,
                         m_selectionEnd,
                         kTextEditColorFormatMask,
                         &colorFormat);
        RefreshTextRange(m_selectionStart, m_selectionEnd);
    }

    m_maskedText = false;
    SetTextColor(textColor);
    SetTextBackColor(textBackColor);
    m_maxLength = kTextEditDefaultLimit;
    m_maxLines = kTextEditDefaultLimit;

    if (s_styledUnicodeClipboardFormat == 0) {
        s_styledUnicodeClipboardFormat =
            RegisterClipboardFormatW(L"Nexon.StyledUnicodeText");
        if (s_styledUnicodeClipboardFormat == 0)
            throw new Win32Error;
    }

    if ((m_editorFlags & kTextEditNoImeFocus) == 0) {
        SetFocusRegistration(true);
        g_pIMEPane->SetFocusPane(this, true);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 2 - UID0000EO TextEditPane declaration managed value

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class List;
class TextEditObject;
class TextEditPane;
class TextEditScrap;
struct Point;
struct TextRunDrawState;
struct TextRunMeasureState;
namespace mystr {
template <class CharT> struct mychar_traits;
template <class CharT, class Traits> class StringBase;
}

struct TextEditLineRecord
{
    unsigned short startIndex;
    unsigned short reserved02;
    int top;
    int remainingWidth;
    unsigned short wrapState;
    unsigned short reserved0e;
};

struct TextRunFormatData
{
    unsigned short legacyAssetMode;
    unsigned short reserved02;
    unsigned int textColor;
    TextEditObject *object;
};

struct TextEditFormatRecord
{
    unsigned short referenceCount;
    unsigned short reserved02;
    TextRunFormatData format;
};

struct TextEditFormatRun
{
    unsigned short startIndex;
    short formatIndex;
};

struct TextRunMeasureState
{
    int availableWidth;
    int remainingWidth;
    int scratch;
};

typedef bool (__cdecl *TextRunIteratorCallback)(TextEditLineRecord *line,
                                                const TextRunFormatData *format,
                                                const wchar_t *text,
                                                int textOffset,
                                                unsigned short charCount,
                                                unsigned short segmentFlags,
                                                void *context,
                                                TextEditPane *pane);

static bool __cdecl TextRunMeasureCallback(TextEditLineRecord *line,
                                           const TextRunFormatData *format,
                                           const wchar_t *text,
                                           int textOffset,
                                           unsigned short charCount,
                                           unsigned short segmentFlags,
                                           void *context,
                                           TextEditPane *pane);

static bool __cdecl DrawTextRunCallback(TextEditLineRecord *line,
                                        const TextRunFormatData *format,
                                        const wchar_t *text,
                                        int textOffset,
                                        unsigned short charCount,
                                        unsigned short segmentFlags,
                                        void *context,
                                        TextEditPane *pane);

class TextEditPane : public ScrollablePane
{
public:
    TextEditPane(int viewportWidth,
                 int viewportHeight,
                 int textAreaWidth,
                 int textAreaHeight,
                 int textColor,
                 int textBackColor,
                 bool hasHorizontalScrollbar,
                 bool hasVerticalScrollbar,
                 unsigned int editorFlags,
                 unsigned short legacyAssetMode,
                 bool useDefaultAlignment,
                 bool useThousandsSeparator);
    virtual ~TextEditPane();

    short CopyWideText(wchar_t *outText, short capacity) const;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > GetText() const;
    short GetTextLength() const;
    void GetCaretRange(short *start, short *end) const;
    void GetCaretLocalPoint(Point *point, short caretIndex) const;
    unsigned char *EncodeState(unsigned short *outSize) const;
    void DecodeState(const unsigned char *data, unsigned short size);

    void InsertText(const wchar_t *text, int flags);
    void SetText(const wchar_t *text, short length, short selectStart, short selectEnd);
    void ClearText();
    void SetSelectionRange(short start, short end);
    void SelectAll();
    void ApplySelectionFormat(unsigned char formatMask, const void *formatData);
    void InsertEmbeddedObject(TextEditObject *object, int width, int height);
    void SetMaxLength(short maxLength);
    void SetMaxLines(short maxLines);
    void EnableMaskedText();
    void SetEditActiveState(bool editActive, bool selectAll);
    bool IsEmpty() const;
    void ScrollToTop();
    unsigned char GetMode() const { return m_mode; }

    void PasteFromClipboard(TextEditScrap *scrap);
    short GetLineCount() const;
    void SetViewportBounds(const RectBounds *bounds);
    void GetTextAreaBounds(RectBounds *bounds) const;
    void SetTextAreaBounds(const RectBounds *bounds);
    virtual void OnDraw();

protected:
    virtual int OnKeyEvent(Event *event);
    virtual bool OnMouseEvent(Event *event);

    void InvalidateTextRegion(short start, short end);
    void DeleteSelection();
    void FindWordBoundary(short index, short *wordStart, short *wordEnd) const;
    void AutoScrollSelectionToPoint(int x, int y);

private:
    friend bool __cdecl TextRunMeasureCallback(TextEditLineRecord *line,
                                               const TextRunFormatData *format,
                                               const wchar_t *text,
                                               int textOffset,
                                               unsigned short charCount,
                                               unsigned short segmentFlags,
                                               void *context,
                                               TextEditPane *pane);
    friend bool __cdecl DrawTextRunCallback(TextEditLineRecord *line,
                                            const TextRunFormatData *format,
                                            const wchar_t *text,
                                            int textOffset,
                                            unsigned short charCount,
                                            unsigned short segmentFlags,
                                            void *context,
                                            TextEditPane *pane);

    void RebuildLineTable(short *firstLine, short *lastLine);
    void IterateTextRuns(short firstLine,
                         short lastLine,
                         TextRunIteratorCallback callback,
                         void *context);
    void RefreshTextRange(short start, short end);
    void ApplyFormatRange(short start,
                          short end,
                          unsigned char formatMask,
                          const TextRunFormatData *format);
    void LoadCurrentFormat();

    int m_activeLineIndex;
    List *m_textStorage;
    List *m_lineTable;
    List *m_formatTable;
    List *m_formatRuns;
    short m_selectionStart;
    short m_selectionEnd;
    short m_savedSelectionStart;
    short m_savedSelectionEnd;
    TextRunFormatData m_currentFormat;
    bool m_dragSelectionActive;
    bool m_currentFormatValid;
    unsigned int m_editorFlags;
    unsigned char m_mouseMode;
    bool m_dirty;
    bool m_maskedText;
    short m_maxLength;
    short m_maxLines;
    unsigned short m_inputState;
    bool m_useDefaultAlignment;
    bool m_useThousandsSeparator;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 5 - UID0001JQ TextRunMeasureCallback managed value

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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
        if ((segmentFlags & kTextRunHasNextSegment) == 0)
            visibleCount = AdjustVisibleCountForTrailingWhitespace(text, visibleCount);

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
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 6 - UID0001JR DrawTextRunCallback managed value

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct TextRunDrawState
{
    RectBounds lineRect;
    RectBounds clippedLineRect;
    bool applyRunTextColor;
};

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
        pane->m_renderMode = 0;
        pane->SetDrawColor((pane->m_editorFlags & 0x02) == 0
                               ? pane->m_textBackColor
                               : 0);
        g_pfnFillOrInvalidateRect(pane, &state->clippedLineRect);
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
        visibleCount = static_cast<unsigned short>(
            AdjustVisibleCountForTrailingWhitespace(text, visibleCount));
    }

    pane->DrawTextRunSegment(text, visibleCount, 0, segmentFlags);
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 7 - UID0000EM TextEditControlPane declaration managed value

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class Layer;
class TextEditPane;
namespace mystr {
template <class CharT> struct mychar_traits;
template <class CharT, class Traits> class StringBase;
}
struct RectBounds;

class TextEditControlPane : public ControlPane
{
public:
    TextEditControlPane(const RectBounds *bounds,
                        bool drawBorder,
                        bool useThousandsSeparator);
    TextEditControlPane(const wchar_t *initialText,
                        bool useAlternateTextStyle,
                        int textColor,
                        int textBackColor,
                        const RectBounds *bounds,
                        bool hasHorizontalScrollbar,
                        bool hasVerticalScrollbar,
                        bool drawBorder,
                        bool allowMultipleLines,
                        float textWidthScale,
                        bool useThousandsSeparator);
    virtual ~TextEditControlPane();

    void SetMaxLength(short maxLength);
    void SetMaxLines(short maxLines);
    void EnableMaskedText();
    void SetEditActiveState(bool editActive, bool selectAll);
    short ReadText(wchar_t *outText, short capacity) const;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > GetInputText() const;
    unsigned char *EncodeState(unsigned short *outSize) const;
    void DecodeState(const unsigned char *data, unsigned short size);
    bool IsEmpty() const;
    void SelectAll();
    void SetText(const wchar_t *text);

    virtual void AddToLayer(const RectBounds *bounds,
                            int order,
                            Pane *previousPane,
                            Layer *layer);
    virtual void RemoveFromLayer();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandleImeEvent(Event *event);

private:
    bool m_useThousandsSeparator;
    bool m_drawBorder;
    TextEditPane *m_textEditPane;
    unsigned char m_cachedChildMode;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 8 - UID0004K1 TextEditControlPane constructors managed value

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace {
const int kTextEditScrollBarSize = 12;
const int kTextEditBorderInset = 2;
const unsigned int kTextEditAlternateStyle = 2;
const unsigned int kTextEditSingleLineStyle = 0x100;
}

TextEditControlPane::TextEditControlPane(const RectBounds *bounds,
                                         bool drawBorder,
                                         bool useThousandsSeparator)
    : ControlPane(5, bounds),
      m_useThousandsSeparator(useThousandsSeparator),
      m_drawBorder(drawBorder)
{
    m_controlFlags = 1;
}

TextEditControlPane::TextEditControlPane(const wchar_t *initialText,
                                         bool useAlternateTextStyle,
                                         int textColor,
                                         int textBackColor,
                                         const RectBounds *bounds,
                                         bool hasHorizontalScrollbar,
                                         bool hasVerticalScrollbar,
                                         bool drawBorder,
                                         bool allowMultipleLines,
                                         float textWidthScale,
                                         bool useThousandsSeparator)
    : ControlPane(5, bounds),
      m_useThousandsSeparator(useThousandsSeparator),
      m_drawBorder(drawBorder)
{
    const int width = m_bounds.right - m_bounds.left -
                      (hasVerticalScrollbar ? kTextEditScrollBarSize : 0);
    const int height = m_bounds.bottom - m_bounds.top -
                       (hasHorizontalScrollbar ? kTextEditScrollBarSize : 0);
    const short contentWidth = static_cast<short>(width * textWidthScale);
    const unsigned int styleFlags =
        (useAlternateTextStyle ? kTextEditAlternateStyle : 0) |
        (allowMultipleLines ? 0 : kTextEditSingleLineStyle);

    m_textEditPane = new TextEditPane(width,
                                      height,
                                      contentWidth,
                                      height,
                                      textColor,
                                      textBackColor,
                                      hasHorizontalScrollbar,
                                      hasVerticalScrollbar,
                                      styleFlags,
                                      IsLegacyAssetMode(),
                                      true,
                                      useThousandsSeparator);

    RectBounds childBounds = *bounds;
    OffsetRect(&childBounds, -childBounds.left, -childBounds.top);
    if (m_drawBorder)
        InsetRect(&childBounds, kTextEditBorderInset, kTextEditBorderInset);

    m_textEditPane->SetMaxLength(1024);
    m_textEditPane->SetMaxLines(1);
    m_textEditPane->SetBounds(&childBounds, false);
    m_textEditPane->SetMode(1);
    m_textEditPane->SetEditActiveState(false, false);

    if (initialText != NULL && initialText[0] != L'\0')
        m_textEditPane->InsertText(initialText, 0);

    m_controlFlags = 1;
    SetMode(m_drawBorder ? 0 : 4);
    m_cachedChildMode = m_textEditPane->GetMode();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 12 - UID0000EN TextEditObject declaration managed value

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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
    virtual void OnAction(int first, int second, int third);

protected:
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
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

## Final Recommendation

- The accepted 12-destination bounded callback and seven exact managed values
  above are fully applied and validated.
- Treat Destination 1 as behavior-identical human source. It intentionally
  preserves the non-obvious conditional global publication, initial 30000/
  30000 limits, two distinct format masks, zero-text seed, pointer exception,
  and focus gate.
- Treat all helper and field spellings as evidence-backed source-facing names,
  not recovered symbol claims.
- Keep UID0001JM and the formatting aggregate blank; populating their broad
  formal blocks would duplicate child bodies.
- Keep callback-consumed TextEditPane and TextEditObject state non-public.
  Destination 2 friends both file-local callbacks; Destination 12 friends the
  measure callback only. The prototypes, friend declarations, and static
  definitions use one identical ABI and form a compilable source union.
- Reject a `GetPayloadPair` call in the measure callback: live MCP proves the
  callback performs one direct `m_payload1` load, while the helper copies both
  payload fields through an output pointer.
- Do not emit vptr assignments, raw offsets, SEH labels, cookies, allocation
  cleanup labels, or explicit base destruction.
- Do not change any caller's constants or behavior. The wrapper change is a
  semantic token correction only.

## Recommended Target Doc Changes

The following accepted target changes are current applied truth; imperative
wording is retained as the exact callback specification and not as pending work.

- D1 `by-memory/0x0058dce0-0x0058e132.TextEditPaneConstructor.md`:
  - Set `COMPLETION:92`, `CONFIDENCE:94`.
  - Preserve owner/emitter UID0000EO, reconstructable true, blank position,
    and `Nested:8`.
  - Install Destination 1 exactly.
  - Replace the stale blank-C++ summary with the exact signature, four table
    identities, global/clipboard/focus behavior, and compiler exclusions.
  - Add complete bytes/hash/PE/CFG/ABI/caller/callee/field/table/flags/EH/
    padding evidence, all 26 callers, negative evidence, and historicalized
    provisional names without compressing existing valid facts.

## Recommended Support Doc Changes

The following accepted support changes are current applied truth. Verify-only
dependencies were reread and remained same-or-greater without B001 edits.

- D2 `by-class/TextEditPane.md`: set `92/94`, install Destination 2 exactly,
  preserve all unrelated methods and children, and synchronize full layout,
  defaults, helper declarations, caller semantics, history, negatives, and
  exact friend declarations for both file-local iterator callbacks.
- D3 `by-file/TextEditPane.md`: set `92/92`; record constructor source order,
  exact table types, callback shared types, globals, source placement, and
  residual raw-helper cap. Record the completed translation-unit-local friend
  policy for TextEditPane and TextEditObject. Preserve every support object and
  unrelated child.
- D4 `by-memory/0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane.md`:
  preserve `86/90` and blank aggregate formal; mark UID0002ZY source-ready and
  historicalize only the constructor-specific blockers.
- D5 `by-memory/0x00591d60-0x00593c20.TextEditPaneFormattingRunsAndMeasureAdapters.md`:
  set `88/92`; correct `+0x13c/+0x140`, exact element types, and shared callback
  context while preserving blank aggregate formal and all unresolved raw
  helper splits.
- D6 `by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md`: set `90/93`,
  install Destination 5, retain behavior/history/address-taking evidence, and
  replace the old future access caveat with the exact D2/D12 friend route.
- D7 `by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md`: set `91/93`,
  install Destination 6, replace the false 24-byte line-record model with
  next-element access, apply the D2 TextEditPane friend route, and preserve all
  draw behavior/history.
- D8 `by-class/TextEditControlPane.md`: set `92/94`, install Destination 7,
  preserve the complete B003/current union, and replace only the stale final
  mode semantics.
- D9 `by-memory/0x004988d0-0x00498b8d.TextEditControlPaneConstructors.md`:
  set `92/94`, install Destination 8, preserve all exact wrapper behavior, and
  distinguish base 30000/30000 defaults from wrapper 1024/1 overrides.
- D10 `by-file/TextEditControlPane.md`: set `91/93`; record the
  `useThousandsSeparator` route and no ownership transfer, preserving source
  path and all unrelated child inventory.
- D11 `by-memory/-ignored.md`: add exactly
  `[0x0058e132,0x0058e140)` as fourteen `cc` alignment bytes between the
  constructor and destructor. Preserve all existing rows, especially the
  predecessor.
- D12 `by-class/TextEditObject.md`: set `89/92`, install Destination 12
  exactly, preserve `m_payload0/m_payload1` as protected and every existing
  method, and record that the exact measure-callback friend preserves the live
  direct `+0x10` load. Reject public payload fields and accessor substitution.
- Verify-only unless current drift contradicts an accepted claim:
  ScrollablePane class/core, List, active-editor and clipboard globals, IMEPane
  focus helper, TextEditPane vtables/destructor/serialization/draw/input/mouse,
  and all 26 caller-family pages.

## Score And Metadata Recommendation

| Destination | Pre-callback | Applied | Metadata disposition | Rationale/cap |
| --- | ---: | ---: | --- | --- |
| UID0002ZY target | 86/90 | 92/94 | retain owner/emitter UID0000EO, true, blank position, Nested 8 | Complete behavior/signature/types/source; lexical names cap final values. |
| UID0000EO class | 91/93 | 92/94 | retain owner/emitter UID0000ON, true | Exact declaration/table closure; unrelated broad methods cap completion. |
| UID0000ON file | 91/90 | 92/92 | retain FILE owner/path | Constructor and tables resolved; raw helper islands cap confidence. |
| UID0001JM aggregate | 86/90 | 86/90 | preserve current route and blank formal | Other unsplit children remain. |
| UID0001JP formatting aggregate | 86/89 | 88/92 | preserve owner/emitter and blank formal | Types/iterator closure; raw bodies still require exact children. |
| UID0001JQ measure callback | 88/90 | 90/93 | preserve owner/emitter/position | Exact shared types and generic context resolve integration. |
| UID0001JR draw callback | 90/91 | 91/93 | preserve owner/emitter/position | Correct 16-byte line element and format field names. |
| UID0000EM control class | 91/93 | 92/94 | retain owner/emitter UID0000OM, true | Complete final-byte semantics and declaration union. |
| UID0004K1 control constructors | 90/93 | 92/94 | retain owner/emitter UID0000EM, true | Existing body exact; semantic parameter blocker resolved. |
| UID0000OM control file | 90/92 | 91/93 | retain FILE owner/path | Wrapper/source relation complete; broader file remains. |
| UID0000VN ignored | -1/-1 | unchanged | shared ignored page | Add only proven exact successor padding. |
| UID0000EN TextEditObject | 88/90 | 89/92 | retain owner/emitter UID0000ON, true, blank position | Exact protected-payload friend route closes callback compilation; virtual-name caps remain. |

## Open Questions With Attempted Resolution

1. Is the function one source constructor or multiple bodies?
   Resolved: one source constructor. The throw tail is an in-function branch;
   external cleanup entries are compiler funclets.
2. Are there twelve or thirteen explicit arguments?
   Resolved: twelve explicit stack slots plus ECX `this`; `retn 0x30` is exact.
3. What are parameters 11 and 12?
   Resolved to `useDefaultAlignment` and `useThousandsSeparator` from direct
   branch/caller/read evidence. Original spelling remains inferred, behavior
   does not.
4. What are the four List types?
   Resolved to wchar_t, 16-byte line, 16-byte format, and 4-byte run records.
5. Which format table is which?
   Resolved: `+0x13c` format records, `+0x140` runs.
6. Is the draw line record 24 bytes?
   Resolved: no. The list stride is 16; draw reads the next record at +16/+20.
7. Are max values 1024/1 or 30000/30000?
   Resolved: base constructor sets 30000/30000; wrapper later sets 1024/1.
8. Does parameter 11 make the pane read-only?
   Resolved: no. The false made-by call selects right alignment; flags and
   later state methods govern interaction.
9. Does the constructor always replace the active-editor global?
   Resolved: no; mask `0x104` preserves the prior pointer.
10. What happens when clipboard registration fails?
    Resolved: heap-allocate and throw `Win32Error *`.
11. Is a new child UID or source file needed?
    Resolved: no. Existing UID/range/class/file route is exact.
12. Are any blockers deferred?
    No target-specific blocker remains. Residual broad aggregate/raw-helper
    debt is explicitly outside the constructor and does not block its source.
13. How do free callbacks legally access private TextEditPane state?
    Resolved: both namespace-scope static callbacks are declared before the
    class and are exact friends in Destination 2. State remains private and
    callback definitions remain file-local.
14. How does the measure callback legally read protected
    `TextEditObject::m_payload1`?
    Resolved: Destination 12 friends exactly `TextRunMeasureCallback` while
    preserving protected payload fields. A public-field change is broader than
    evidence supports, and `GetPayloadPair(int *)` has a different direct
    machine/call shape and copies an unnecessary second field.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

B001 did not edit manual coverage. Ordinary implementation and generated
verification are complete. The supervisor subsequently applied and validated
the exact rows below: first through commands 14636-14638 and then through the
later combined supervisor validations 14639-14641. Current read-only
post-application manual snapshot:

- by-memory SHA256
  `A5CA20135DA4A42D86CB731DF82707EFF8A3DEFDED9DA6ABB586ADEB8C776A44`,
  1,799,251 bytes / 4,295 physical lines; TextEdit handoff first validated by
  supervisor command 14636 and preserved by combined command 14639;
- by-class SHA256
  `63AD4E29536BBFB5445517DB7DA3C4E9CB844102F25D9143379F70975F0051D6`,
  233,032 bytes / 623 physical lines; TextEdit handoff first validated by
  supervisor command 14637 and preserved by combined command 14640;
- by-file SHA256
  `0D039B7BAC0625BEB91C743FA72C5AA74EC5B06C6EB82267908DFA2B91734B06`,
  133,275 bytes / 316 physical lines; TextEdit handoff first validated by
  supervisor command 14638 and preserved by combined command 14641;
- no by-struct manual row is required by this change.

Historical pre-application callback snapshots were by-memory
`729780ED0C747AD0C9FC908C6320F6FBC6890CDF4C94E2067AEA2A8473579AEC`,
by-class `147E54C2044FD8FB81496915061BE428C58E7B2A27FDD5DA1403388DE6D72E74`,
and by-file `6AC2D7B340049EA17E0EFC7DB14E958F02322F4365E82CFECAD6EBBEB27A8E64`.
Those evidence-time hashes and their absent/stale-row findings are superseded
by the post-application snapshot above.

The former pre-application hashes and absent-row findings are historical
snapshots only. Current readback confirms the exact UID0001JM/0002ZY/0000VN/
0001JP/0001JQ/0001JR, UID0000EM/0000EN/0000EO, and UID0000OM/0000ON rows,
including `[0x0058e132,0x0058e140)`, are each present once. The text below is
retained verbatim as the durable supervisor-applied record, not as pending
coverage work.

Exact supervisor-applied by-memory rows:

    - [UID:0001JM][0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane](by-memory/0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane.md) 0x0058dce0-0x00591300 | source-bearing split aggregate | TextEditPaneCoreBeforeTextBoxPane : reconstructable : 86% : strong : Exact TextEditPane pre-TextBox source-bearing split index with source-ready UID0002ZY constructor plus destructor/copy/serialization/draw/key/mouse children, raw helper pockets, switch-table data, by-value wide StringBase GetText hidden-result behavior, text-area getter/setter support, exact boundaries, and blank aggregate C++ pending only the remaining non-constructor method/helper split inventory.
        - [UID:0002ZY][0x0058dce0-0x0058e132.TextEditPaneConstructor](by-memory/0x0058dce0-0x0058e132.TextEditPaneConstructor.md) 0x0058dce0-0x0058e132 | constructor | TextEditPaneConstructor : reconstructable : 92% : very-strong : Complete source-ready TextEditPane constructor with exact 0x452-byte range/hash, twelve-argument thiscall/retn-0x30 ABI, 26 callsites, ScrollablePane base, four exact List element types, active-editor preservation mask, line/layout/format initialization, 30000 limits, styled-Unicode clipboard registration and Win32Error pointer throw, IME focus route, exact padding, and compiler-only vptr/cookie/EH exclusions.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0058e132-0x0058e140 | padding | TextEditPane constructor to destructor alignment : ignored : 100% : strong : IDA MCP and local PE bytes prove fourteen consecutive `0xcc` alignment bytes.
    - [UID:0001JP][0x00591d60-0x00593c20.TextEditPaneFormattingRunsAndMeasureAdapters](by-memory/0x00591d60-0x00593c20.TextEditPaneFormattingRunsAndMeasureAdapters.md) 0x00591d60-0x00593c20 | method cluster | TextEditPaneFormattingRuns : reconstructable : 88% : very-strong : TextEditPane formatting/range-editing and run-iteration aggregate with exact wchar_t text storage, 16-byte TextEditLineRecord, 16-byte TextEditFormatRecord at +0x13c, 4-byte TextEditFormatRun at +0x140, 12-byte TextRunFormatData payload, iterator callback context, solved measure/draw callback integration, and preserved blank aggregate C++ pending raw helper-specific child splits rather than table-layout uncertainty.
    - [UID:0001JQ][0x00593c20-0x00593ce4.TextRunMeasureCallback](by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md) 0x00593c20-0x00593ce4 | file-local callback | TextRunMeasureCallback : reconstructable : 90% : very-strong : Source-ready TextEditPane iterator measurement callback with exact address-taking route, 16-byte TextEditLineRecord, semantic TextRunFormatData fields, generic callback context cast to TextRunMeasureState, masked-text and trailing-whitespace behavior, remaining-width clamp/writeback, and no direct-call or raw-neighbor ownership.
    - [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md) 0x00593db0-0x00593ef5 | file-local callback | DrawTextRunCallback : reconstructable : 91% : very-strong : Source-ready TextEditPane iterator draw callback with exact 16-byte line elements, next-line top via line[1], semantic format textColor/object payload, generic context cast, clip/fill/alignment/draw/object/trailing-whitespace behavior, exact address-taking route, and preserved raw-neighbor exclusion.

Exact supervisor-applied by-class rows:

- [UID:0000EM][TextEditControlPane](by-class/TextEditControlPane.md) : reconstructable : 92% : very-strong : Complete ControlPane-derived TextEditControlPane declaration with exact 0x114 layout, constructor/destructor/text/state/layer/event surface, by-value wide StringBase GetInputText hidden-result contract, exact useThousandsSeparator field forwarded to TextEditPane numeric grouping, twelve exact source children, class closure before child definitions, and compiler-wrapper/source-name exclusions.
- [UID:0000EN][TextEditObject](by-class/TextEditObject.md) : reconstructable : 89% : very-strong : Complete LObject-derived TextEditObject declaration with object-type, owner-handle, protected payload-pair storage, public get/set helpers, provisional OnUpdate/OnAction virtuals, and exact file-local TextRunMeasureCallback friendship preserving the observed direct m_payload1 read without public-field widening or accessor-call substitution.
- [UID:0000EO][TextEditPane](by-class/TextEditPane.md) : reconstructable : 92% : very-strong : Full TextEditPane declaration with exact twelve-argument constructor, wchar_t text storage, 16-byte line and format tables, 4-byte format-run table, semantic TextRunFormatData payload, useDefaultAlignment/useThousandsSeparator fields, exact TextRunMeasureCallback/DrawTextRunCallback friend access while state remains private, by-value one-pointer wide StringBase GetText hidden-result ABI, complete caret/text-area/selection/scroll APIs, bool OnMouseEvent contract, class closure before children, and residual broad raw-helper caps only.

Exact supervisor-applied by-file rows:

- [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md) : reconstructable : 91% : very-strong : TextEditControlPane source module with complete control wrapper union, exact TextEditPane constructor forwarding, semantic useThousandsSeparator byte, base 30000/30000 defaults followed by wrapper 1024/1 limits, text/state/layer/event children, and preserved compiler/source boundaries.
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md) : reconstructable : 92% : very-strong : Rich text editor implementation with source-ready twelve-argument constructor, exact four List/table element types, TextRunMeasureCallback/DrawTextRunCallback shared records and context ABI, exact TextEditPane and TextEditObject friend policy preserving non-public state and direct callback loads, active-editor and styled-Unicode clipboard globals, exact caret/text-area/selection/scroll APIs, support-object split from TextFilter, and residual raw-helper islands explicitly separated from resolved constructor/table source.

No tracker text change is required beyond validator-owned report-count/lifecycle
handling. Coverage application and validation are complete external supervisor
actions; B001 performed neither action.

## Follow-Up Actions

- A-agent actions: none.
- B001 implementation work is complete; no accepted claim or checklist item
  remains blocked or unapplied.
- The exact manual rows above are already supervisor-applied and validated;
  no B001 coverage action remains.
- Coverage command provenance and resulting hashes are external supervisor facts.
  Report validation, execution, count, path, move, and archive state remain
  external supervisor/validator-owned facts. B001 neither performed nor directs
  any report lifecycle command.

## Confidence

- Range/bytes/hash/PE/ABI/callers: very strong.
- Constructor identity/base/vtables/compiler boundary: very strong.
- Table element sizes/layouts/roles: very strong.
- Parameter semantics: very strong for behavior, medium-high for exact original
  lexical spelling.
- Global/clipboard/exception/focus behavior: very strong.
- Owner/emitter/source placement: very strong.
- Callback access policy and translation-unit linkage: very strong. Exact
  friends preserve observed direct accesses and current encapsulation; public
  fields, accessor substitution, and member-callback conversion are rejected
  by bounded source/binary evidence.
- First-draft behavior identity: very strong; exact original helper/local
  spellings remain inferred and cap scores below final-audit values.
- Overall recommendation: target `92/94`.

## Validator Results

- The initial report-only phase used no validator. The accepted callback ran
  exactly one scoped validator per changed ordinary destination:

| Destination | Command / timestamp | Result | Warnings and authorized side effects |
| --- | --- | --- | --- |
| D1 UID0002ZY | `000000014560`, `2026-07-19T18:51:07-04:00` | exit 0, ok 1 | Applied `92/94` and formal value; generated refresh deferred. |
| D2 UID0000EO | `000000014561`, `2026-07-19T18:52:44-04:00` | exit 0, ok 1 | Applied `92/94`; eight pre-existing missing-reference warnings; refresh deferred. |
| D3 UID0000ON | `000000014562`, `2026-07-19T18:55:57-04:00` | exit 0, ok 1 | Applied `92/92`; 59 pre-existing missing-reference warnings; refresh deferred. |
| D4 UID0001JM | `000000014563`, `2026-07-19T18:57:12-04:00` | exit 0, ok 1 | Preserved `86/90`/blank; five pre-existing UID0003N0 reference warnings; refresh deferred. |
| D5 UID0001JP | `000000014565`, `2026-07-19T18:58:02-04:00` | exit 0, ok 1 | Applied `88/92`; four pre-existing raw-neighbor reference warnings; refresh deferred. |
| D6 UID0001JQ | `000000014573`, `2026-07-19T18:58:54-04:00` | exit 0, ok 1 | Applied `90/93`, updated formal/autogen registry; five pre-existing UID0003FC warnings; refresh deferred. |
| D7 UID0001JR | `000000014583`, `2026-07-19T19:00:19-04:00` | exit 0, ok 1 | Applied `91/93`, updated formal/autogen registry; nine pre-existing raw-neighbor warnings; refresh deferred. |
| D8 UID0000EM | `000000014590`, `2026-07-19T19:01:22-04:00` | exit 0, ok 1 | Applied `92/94`, updated formal/autogen registry; refresh deferred. |
| D9 UID0004K1 | `000000014594`, `2026-07-19T19:02:17-04:00` | exit 0, ok 1 | Applied `92/94`, updated formal/autogen registry; refresh deferred. |
| D10 UID0000OM | `000000014595`, `2026-07-19T19:02:50-04:00` | exit 0, ok 1 | Applied `91/93`; refresh deferred. |
| D11 UID0000VN | `000000014596`, `2026-07-19T19:03:32-04:00` | exit 0, ok 1 | Added three reference-index links; 253 pre-existing shared-page missing-reference warnings; refresh deferred. |
| D12 UID0000EN | `000000014597`, `2026-07-19T19:04:09-04:00` | exit 0, ok 1 | Applied `89/92`, updated formal/autogen registry and one reference link; 12 pre-existing support UID warnings; refresh deferred. |

- Final authorized target refresh: command `000000014598`, timestamp
  `2026-07-19T19:04:25-04:00`, exit 0, ok 1, completed after 18.9 seconds.
  It rebuilt validator-owned autogen metadata (`5,097` nodes / `4,090` edges),
  refreshed 280 generated metadata outputs, and reported only project-wide
  pre-existing children-marker/no-code warnings. B001 did not edit those files
  or registry state manually.
- Gate 2 evidence repair scoped/waited validation: command `000000014623`,
  timestamp `2026-07-19T19:24:06-04:00`, exit 0, ok 1, completed after 24.7
  seconds. It scanned only D1, confirmed the exact evidence addition, rebuilt
  validator-owned autogen metadata at 5,098 nodes / 4,091 edges, refreshed 280
  generated metadata outputs, and reported only project-wide pre-existing
  children-marker/no-code warnings. The earlier command 14598 snapshot remains
  historical accepted-callback evidence. Concurrent validator-owned refreshes
  subsequently advanced the shared generated union; the latest stable readback
  is command `000000014635` at `2026-07-19T19:29:41-04:00` and reconfirmed
  every target-specific semantic assertion below without attributing that
  command to B001.
- Generated TextEditPane assertions: one UID0002ZY marker, zero target empty
  markers, one constructor definition, one UID0001JM empty marker and no
  aggregate body, one TextEditObject and one TextEditPane class declaration,
  exact `m_formatTable` before `m_formatRuns`, exact `30000/30000` defaults,
  one styled-Unicode registration and one `throw new Win32Error`, preserved
  focus registration, and no vtable/cookie/EH-label/base-teardown body text.
- Generated callback assertions: D2 and D12's independently complete managed
  declarations produce compatible repeated static measure prototypes, the two
  required class friend declarations, and exactly one measure definition;
  Draw has its declaration/friend and exactly one definition. There is no
  conflicting signature, duplicate body, public payload widening,
  `GetPayloadPair` substitution, or raw-offset workaround.
- Generated TextEditControlPane assertions: two constructor definitions,
  exact wrapper `1024/1` overrides, ten accepted-scope
  `useThousandsSeparator` occurrences, and zero `inputMode`/`m_inputMode`.
- All seven managed blocks compare byte-for-byte equal to their accepted report
  destinations after newline normalization.
- Supervisor-owned manual coverage validation first applied/validated this
  exact TextEdit handoff through commands 14636-14638. Later combined
  supervisor validations 14639-14641 preserved every accepted row once and
  produced the current memory/class/file hashes recorded above. B001 did not
  run those commands, edit coverage, or run a validator during this final
  report-only reconciliation.

## Changed Files

- B001 changed this report and exactly these twelve authorized ordinary pages:
  D1 `by-memory/0x0058dce0-0x0058e132.TextEditPaneConstructor.md`;
  D2 `by-class/TextEditPane.md`; D3 `by-file/TextEditPane.md`; D4
  `by-memory/0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane.md`; D5
  `by-memory/0x00591d60-0x00593c20.TextEditPaneFormattingRunsAndMeasureAdapters.md`;
  D6 `by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md`; D7
  `by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md`; D8
  `by-class/TextEditControlPane.md`; D9
  `by-memory/0x004988d0-0x00498b8d.TextEditControlPaneConstructors.md`; D10
  `by-file/TextEditControlPane.md`; D11 `by-memory/-ignored.md`; and D12
  `by-class/TextEditObject.md`.
- Current hashes/metrics for every D1-D12 ordinary page are recorded under
  `Documentation Evidence And IDA Status`; D2-D12 retain their callback
  snapshots, and repaired D1 was reread after command 14623.
- Validator-owned generated side effects were not manually edited. Current
  generated outputs are TextEditPane.cpp
  `D2656CC63989CF86197A1DB83921B0F28F19C26D3885F1A992BFAFD243AA18F3`
  (23,137 / 625) and TextEditControlPane.cpp
  `0B1673BB6081887C5DF01D829474EB9FA6DA57B513D27182DD79BCAEE50B76E5`
  (9,780 / 253), both current validator-owned union command 14635. The complete
  target-specific semantic assertion set remains true; commands 14598 and
  14623 remain historical callback/repair evidence.
- The bounded Gate 2 repair changed only D1 and this report. No other ordinary,
  manual coverage, generated, tracker, audit, supervisor, validator-state,
  lifecycle/archive, or IDA file was manually edited.
- This final post-coverage reconciliation changes only this report. The current
  by-memory/by-class/by-file coverage hashes are respectively
  `A5CA20135DA4A42D86CB731DF82707EFF8A3DEFDED9DA6ABB586ADEB8C776A44`,
  `63AD4E29536BBFB5445517DB7DA3C4E9CB844102F25D9143379F70975F0051D6`,
  and `0D039B7BAC0625BEB91C743FA72C5AA74EC5B06C6EB82267908DFA2B91734B06`;
  they are supervisor-owned changes, not B001 changed files.
- Manual coverage, tracker, audit, supervisor, lifecycle/archive, and IDA files
  were not edited by B001. Manual coverage now contains the exact applied rows
  above.
- Every B001 ordinary lease was released immediately after its scoped
  validator. Final `tools/leaser/Agents/current_leases.md` readback contains no
  active lease, including no B001 lease.

## Implementation Tracking Checklist

### Initial Research / Report Phase

- [x] Read the topmost canonical B001 goal override and project workflow skill.
- [x] Confirmed the direct report path was absent before creation.
- [x] Rediscovered healthy MCP database `9b0396a3` and ran a bounded bytes probe.
- [x] Recovered exact range, size, body hash, PE mapping, CFG, ABI, and unwind shape.
- [x] Audited all 26 direct callsites and exact argument domains.
- [x] Resolved parameters 11 and 12 without carrying stale names forward.
- [x] Resolved all four List element types and corrected table identities.
- [x] Revalidated helper/global/clipboard/IME/callback routes.
- [x] Resolved both callback access contracts through bounded live-MCP evidence
  and exact file-local friend declarations without widening class state.
- [x] Searched active, executed, older-research, special-report, and archived roots.
- [x] Classified every relevant historical report and stated no-direct-report result.
- [x] Reread current target/support/generated/manual evidence without mutation.
- [x] Produced seven destination-specific exact managed blocks.
- [x] During the initial report-only phase, produced contiguous C2ZY-001 through C2ZY-074 ledger rows using allowed actions and `proposed` states; callback states are now terminal.
- [x] Supplied exact supervisor-owned manual coverage text and confirmed its later external application/validation without editing coverage.
- [x] Kept the implementation checklist entirely unchecked before Gate 1; it is now checked only against callback proof.
- [x] Confirmed zero leases and no ordinary/restricted/lifecycle action.

### Implementation Callback Phase

- [x] Re-read D1 target immediately before leasing; stop if a conflicting lease exists.
- [x] Lease D1 only, apply exact metadata/body/evidence/history, add the full target-byte SHA256 during the bounded Gate 2 repair, scoped-validate through command 14623, and release.
- [x] Re-read D2 TextEditPane class immediately before leasing and preserve full current union.
- [x] Lease D2 only, apply Destination 2 and score/prose changes, scoped-validate, and release.
- [x] Re-read D3 TextEditPane file, merge source/table/history changes, scoped-validate, and release.
- [x] Re-read D4 aggregate, preserve blank formal and unrelated children, scoped-validate, and release.
- [x] Re-read D5 formatting aggregate, apply exact table closure without aggregate body, scoped-validate, and release.
- [x] Re-read D6 measure callback, apply Destination 5/no-loss prose, scoped-validate, and release.
- [x] Re-read D7 draw callback, apply Destination 6/no-loss prose, scoped-validate, and release.
- [x] Re-read D8 TextEditControlPane class and preserve complete concurrent union.
- [x] Lease D8 only, apply Destination 7/score/prose, scoped-validate, and release.
- [x] Re-read D9 constructors, apply Destination 8/score/prose, scoped-validate, and release.
- [x] Re-read D10 TextEditControlPane file, apply bounded semantic sync, scoped-validate, and release.
- [x] Re-read volatile D11 ignored page, confirm the successor row was absent at callback edit time, add the exact span once, scoped-validate, and release; current manual coverage contains the applied row once.
- [x] Re-read D12 TextEditObject class, preserve its complete current union, apply only the exact measure-callback friend/score/prose delta, scoped-validate, and release.
- [x] Verify predecessor padding and all verify-only dependencies remain same-or-greater without edits.
- [x] Verify all 26 caller pages remain consumers and preserve unrelated current content.
- [x] Run the accepted final UID0002ZY refresh and the authorized evidence-repair D1 `--wait-generated` refresh; command 14623 completed after release, and read back the later validator-owned current union at command 14635 without attribution to B001.
- [x] Record every scoped/waited validator command ID, timestamp, exit, ok count, warning, and side effect.
- [x] Verify generated one-target-definition/zero-empty-marker/no-aggregate-duplicate assertions.
- [x] Verify generated table order, constructor defaults, wrapper overrides, registration, throw, and focus behavior.
- [x] Verify no vptr/cookie/EH/base-teardown/compiler glue was emitted as target source.
- [x] Verify all seven managed destinations match the accepted report text exactly.
- [x] Verify both file-local callbacks compile against private TextEditPane state through the exact Destination 2 friends.
- [x] Verify the measure callback compiles against protected TextEditObject payload state through Destination 12 with no GetPayloadPair call or public-field widening.
- [x] Re-read every changed ordinary hash and generated hash/metrics after final refresh.
- [x] Re-read manual coverage, confirm every accepted row is supervisor-applied once after commands 14636-14641, preserve the exact text as durable provenance, and do not edit coverage.
- [x] Convert all 74 ledger rows from `proposed` to legal terminal callback states with per-claim proof.
- [x] Record exact changed-file inventory and identify any verify-only files as unchanged.
- [x] Check each callback item only after independent truth; record any exact blocker rather than silently omitting it.
- [x] Confirm zero placeholders, zero stale `isReadOnly`/`inputMode` target-route tokens, and no reversed format tables in accepted scope.
- [x] Confirm zero active B001 leases.
- [x] Confirm B001 did not run/probe `execute_report`, lifecycle/count/move/archive commands, or mutate IDA.
- [x] Update this same report to current callback truth and return the supervisor-specified post-callback marker.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000014644","destination_path":"executed-b-agent-research/B001/0002ZY-TextEditPaneConstructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0002ZY-TextEditPaneConstructor-source-quality.md","timestamp":"2026-07-19T20:11:00-04:00","uid":"0002ZY"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
