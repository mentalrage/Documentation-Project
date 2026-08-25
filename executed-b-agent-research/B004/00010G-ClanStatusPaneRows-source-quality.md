** TARGET-REPORT-UID:00010G **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID00010G ClanStatusPaneRows Source-Quality Report

## Finalized Report / Current Recommendation

The accepted callback converted [UID:00010G]
`by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md` from a source-emitting
aggregate into a false, non-emitting split index and registered three exact
method-level source emitters:

1. `UID0004Q5` at `[0x00486800,0x00486cdf)` for inferred
   `ClanStatusPane::DrawStatusRowText(short)`.
2. `UID0004Q6` at `[0x00486d20,0x00486f40)` for inferred
   `ClanStatusPane::GetStatusRowRect(short, RectBounds *)`.
3. `UID0004Q7` at `[0x00486f90,0x00487292)` for inferred
   `ClanStatusPane::HitTestStatusRow(int y, int x)`.

The parent is now `92/94`, remains semantically owned by [UID:00002K]
`ClanStatusPane`, is `RECONSTRUCTABLE:FALSE`, has blank `EMITTER_UIDS` and
position, retains `Nested:0`, and carries a blank managed C++ block. The
children were registered serially as `0004Q5`, `0004Q6`, and `0004Q7` before
dependent cross-references were added. Their scores are `91/93`, `92/94`, and
`91/93`; all are reconstructable, emitted through `00002K`, and source-placed
in [UID:0000I8] `NexusTK/social/Clan.cpp`.

The recovered human-source model uses the existing [UID:0001VP]
`RectBounds`, preserves signed `short` row ABI, names the two view modes and
all 16 row indices descriptively, and treats the duplicated hit-test switch as
an inlined copy of `GetStatusRowRect`, not a second handwritten geometry body.
The original enumerator spellings and helper access specifier are not
symbol-proven; the selected names are the strongest behavior-preserving
project-source inference.

Implementation and scoped validation are complete. B004 performed no report
execution, count, move, archive, or other lifecycle command. Those external
states remain supervisor/validator-owned and are neither asserted nor directed
by this artifact.

## Supporting Research

### Documentation read at research-evidence time

- Target [UID:00010G] SHA256
  `108F16C8FA05DBE9D2AACA551D090572F3A8EE489DE59EA828B62BF893487527`.
- Class [UID:00002K] `by-class/ClanStatusPane.md` SHA256
  `626B83033A5E22EB5F5288A8F663EBC46E5E601128D9E0EF145003A1A8D6AD50`.
- File [UID:0000I8] `by-file/Clan.md` SHA256
  `0D51C3961BF42730FCCB389641AAEF29D745F8346042736CDEC1721FE8F3443C`.
- Caller aggregate [UID:00010C] SHA256
  `C2B569C6176ADE92562F4CADBC768625D9B47577AC56164454F38DDE26B3EF85`.
- Successor helper [UID:00021N] SHA256
  `FFDE95B34978518A9BF4166220321B450E1FBB5371551A4F46A2ED7DD1E44754`.
- Action sender [UID:00010H] SHA256
  `6D53E9E68F5BCCF6937A492808273D3D86A15877F7D2F8CBAEA1A55149DDFC59`.
- `by-memory/-ignored.md` SHA256
  `8400EFA850EEF3B47669C5859966D4E4F382D54053E3C5C4234B6D05B618D8F7`.
- Read-only generated `auto-generated/NexusTK/social/Clan.cpp` SHA256
  `04F81D6DE0E6CC6C1FDB1439F93D17B4CEA2CD5BC77A13B29E9C97686726CEC9`.

Those hashes are explicitly historical pre-callback snapshots. Current
post-callback destination and generated hashes are recorded under `Validator
Results` and `Changed Files`; the research snapshots are retained to show the
accepted before/after transition rather than frozen as present state.

### Report-corpus search

Concrete terms searched in every root were `UID00010G`, `[UID:00010G]`,
`0x00486800`, `0x00487291`, `ClanStatusPaneRows`, `DrawStatusRowText`,
`GetStatusRowRect`, `HitTestStatusRow`, `DrawInfoRow`, `BuildStatusRowRect`,
`HitTestRow`, `ClanStatusPane`, and `Clan.cpp`.

- Active `tools/leaser/Agents/Agent-B001/research` through
  `Agent-B015/research`: twelve Markdown artifacts were present across those
  roots and no direct target/range/helper match was found. This report did not
  exist when the search was performed.
- `tools/leaser/Agents/Older-Research`: three Markdown reports, no match.
- `tools/leaser/Agents/SpecialReports`: five Markdown reports. The sole broad
  match was an incidental reference to the ClanStatusPane constructor report
  in `benchmark-medium-0004CC-IMEPaneSetFocusPane-source-quality.md`; it has no
  target evidence.
- Actual project archive root `project-documentation/archived`: zero Markdown
  reports and no match. The root contains non-Markdown archived evidence only.
- `project-documentation/executed-b-agent-research`: 2,196 Markdown reports.
  The broad family search matched 72 reports; the 14 target/source-family
  reports below were opened and classified.

Opened executed leads, with evidence-time SHA256 and disposition:

| Executed report | SHA256 | Revalidated finding |
| --- | --- | --- |
| `B002/00010C-00010G-clan-status-pane-ui-source-quality.md` | `DD5A95E8A538AEEBA6503C52E0DCAD0C15A1CD9932B0E719840DD50E63EC2875` | Historical basis for the three descriptive method names, row/view geometry, and `86/90`; its unresolved rectangle type, labels, and aggregate-emitter stance are superseded by current evidence. |
| `B015/00002K-ClanStatusPane-class-source-quality.md` | `9603B8B13703324A4358E10F6B1CD1DEB8D7FE036865569C782D0F02D3D29316` | Revalidated `ClanStatusPane` ownership and `Clan.cpp` route; it did not model the row enum or declarations. |
| `B007/0000I8-Clan-empty-emitter-family-source-quality.md` | `353FE390C36D753DBC17D5E54C54BFD47C55B6AB36498BF78968B46AB0489073` | Revalidated the broad `NexusTK/social/Clan.cpp` source family. |
| `B014/00010A-ClanStatusPaneConstructor-source-quality.md` | `312F46418BF508FA968FF241B6917924EAA46E6063932F88A2B258F6C8F3F7EC` | Revalidated fields at `+0xf8`, `+0xf9`, `+0xfa`, child-pane ownership, and constructor source family. |
| `B012/00010B-00021C-ClanStatusPacketParserDispatcher-source-quality.md` | `5745BD409108AA44259EAF71DAEECA2555123D57649A92DE678A6BED9FA3AF2C` | Revalidated packet-populated row labels, status-data version, subtype families, and status/manage child routes. |
| `B005/00021O-ClanStatusPaneRefreshChildPanes-source-quality.md` | `9C05DCF9516330E0D456F9E3729F30235EF98C4EBEA53A1A363E71E63FE3622A` | Revalidated view-byte semantics and child refresh routing. |
| `B006/00021P-ClanStatusPaneShowInfoList-source-quality.md` | `ABF049797F9337152E3873149482F350193F30F4EC95D71174878E5237DCA27B` | Revalidated view value `2` as info-list mode. |
| `B001/00021Q-ClanStatusPaneShowJoinList-empty-emitter-source-quality.md` | `F0476B1445FAE771F827BCC54144B3FF473FC30F9248ACA1C0F2249EEAC4F366` | Revalidated view value `3` as join-list mode. |
| `B001/00021R-ClanStatusPaneShowEnlistList-source-quality.md` | `C0AEFC450D8EF009DF0DDF244F587EB178C2B6AE0882F51360EC73E59623371D` | Revalidated view value `4` as enlist-list mode. |
| `B011/00010H-ClanStatusRowActionPacket-source-quality.md` | `E72C8CF54CB6962C6EE19C44923055E9DDDE98DEB96D369B710D6D0B0FCD8C22` | Revalidated row `2-13` to opcode `0x4b` subtype `1-12`, row `7` delegation, and signed-short row ABI. Numeric cases remain valid; new enum names are descriptive. |
| `B001/00021D-00021J-clan-opcode4b-packet-helper-source-quality.md` | `E669381813CE2B48F8CE1C6E522E1FFBD0FE3247ED08EF843C9F00922E65E756` | Revalidated subtype/action relationships and the deposit/name-action helper families. |
| `B013/00021M-ClanWithdrawAndNoticePacketHelpers-source-quality.md` | `B366B186D88539FBFA483FE6A9BEB1EC2B5842FD90DA53029D11A64CA844AC24` | Revalidated subtypes `11`, `12`, and distinct subtype `13` notice handling; subtype `13` has no row index. |
| `B013/00021N-ClanStatusPaneRowEligibilityHelper-empty-emitter-source-quality.md` | `045442263C21E1087EBCCCD7A0A6C72375AF7F4CF9804C8F46A96FE2E550D457` | Revalidated `IsRowActionBlocked(short)`, status/version gating, and short row ABI. Its current page is authoritative over report-era wording. |
| `B011/0002XH-g_pClanStatusPane-source-quality.md` | `2863BAA9C01C6A0756198EE864AD1596251ABA96ECBE3B458FAA1EAEC0AEDB35` | Revalidated singleton/class association only; it adds no helper-name evidence. |

No prior report supplies recovered original symbols. These reports are treated
as revalidated leads; all binary conclusions below come from the live MCP pass
and current destinations.

## Target

- UID: `00010G`.
- Current path: `by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md`.
- Exact current covered code union: `[0x00486800,0x00487292)` with internal
  compiler-only gaps.
- Current documented score: `92/94`; the accepted pre-callback score was
  `86/90`.
- Assignment tracker snapshot: reconstructable/not-covered queue row `86/90`,
  reports `0` before creation of this artifact.
- Current owner/emitter: `00002K` / blank.
- Current reconstructable/position/nesting: `FALSE` / blank / `0`.
- Current managed block: exactly blank; source is emitted only by children
  `0004Q5`, `0004Q6`, and `0004Q7`.
- Required source route: [UID:0000I8] `NexusTK/social/Clan.cpp` through class
  [UID:00002K] `ClanStatusPane`.

## Current Target State

The page is now the false, non-emitting index for a mixed source/compiler
physical band. It records three independent IDA functions, five internal
compiler spans, and three successor compiler spans while the exact registered
children carry the three human source bodies. The inclusive parent filename
still ends at the final instruction byte `0x00487291`; its documentation
separately records the successor switch table through `0x004872e0`.

The historical pre-callback statement that final C++ had to remain blank until
row labels, rectangle type, and member declarations were stabilized is
superseded:

- [UID:0001VP] establishes `RectBounds` exactly.
- [UID:00015S] establishes `InitRectBounds(RectBounds *, int, int, int, int)`
  and `PointInRect(int y, int x, const RectBounds *)`.
- Parser/action/helper evidence resolves descriptive row roles and preserves
  original-spelling uncertainty explicitly.
- Current callers and callee ABI resolve signed `short` row parameters,
  `void` rectangle output, and y-first/x-second hit testing.
- Internal tables and padding have exact ranges, hashes, xrefs, and generated
  source disposition.

All accepted ordinary destinations were changed, scoped-validated, and
released. The waited validator generated one definition per child, no parent
entry, and no handwritten compiler span.

## Executive Recommendation

The split-first implementation is complete. UID00010G remains the non-emitting
evidence/container index; the three method pages were registered in ascending
address order. `by-memory/-ignored.md` now records the five internal spans and
three successor spans, and relative nesting is `+4, 0, 0, -4` across the first
child, later children, and UID00021N.

The three complete method bodies and their declarations plus inferred row/view
enums are installed in the complete `ClanStatusPane` class model. Binary facts
remain separate from inferred source spellings. No parent body or handwritten
jump-table/helper duplication is emitted.

## Supervisor Active Recheck

This standalone artifact preserves the accepted research and records the
completed bounded callback. It does not depend on an unfinalized B-agent
report. Active B001-B015 research roots were searched at evidence time and
produced no target collision. Every destination was reread before editing, and
the validator allocated `0004Q5`, `0004Q6`, and `0004Q7` serially before
dependent cross-links were installed.

No report lifecycle state is asserted here. External supervisor/validator
history is authoritative for validation, execution, counting, movement, and
archive status.

## Inference Research Guidance Check

| Question | Investigation | Resolution |
| --- | --- | --- |
| Is this one human function? | Function lookup, return boundaries, tables, caller clusters | No. It is three independent member methods with compiler-only spans. |
| Can the parent remain an aggregate emitter? | Generator behavior and method-level ownership | No. A comment-only aggregate suppresses three source bodies and cannot safely own three definitions. |
| Are helper names symbol-proven? | Exact-name probes for qualified and unqualified names | No. Selected names are project-consistent inferences and historical aliases are retained as rejected alternatives. |
| Is a new rectangle type needed? | UID0001VP/UID00015S signatures and caller use | No. Exact common type is `RectBounds`; a new `ClanStatusRowRect` would duplicate the established contract. |
| Is GetStatusRowRect non-void? | Callsite return liveness and InitRectBounds residue | No human return value is consumed. IDA's integer result is propagated register residue; strongest source return is `void`. |
| Is hit-test x-first? | OnMouseEvent pushes, PointInRect canonical signature, sibling precedent | No. Project ABI is `int y, int x`, matching the call order and PointInRect contract. |
| Is the duplicated rectangle switch handwritten? | Hit-test disassembly, switch tables, source-shape comparison | Highest-probability source calls `GetStatusRowRect`; MSVC inlines it into HitTestStatusRow. |
| Can exact original row names be recovered? | Parser, action sender, sibling helpers, report and symbol search | Original spellings are lost. Descriptive enum names are the highest-probability maintainable source form; ABI remains short. |
| Does subtype 13 map to a row? | Packet-helper and notice-parser evidence | No. Rows 2-13 map only to subtypes 1-12; subtype 13 is a separate notice/string path. |
| Is this source in another module? | Owner, callers, class/file route, generated output | No. All evidence converges on `ClanStatusPane` in `NexusTK/social/Clan.cpp`. |

## Heuristic / Inference Reanalysis And Validation

The source-shape inference was tested against four controls:

1. ABI control: all row consumers sign-extend the 16-bit argument and return
   hit-test results through `AX`; formal method parameters/return therefore
   remain `short` even though named constants are introduced.
2. Geometry control: the exact four-int `RectBounds` layout and half-open
   `PointInRect(y,x,bounds)` contract already exist in UID0001VP/UID00015S.
3. Inlining control: HitTestStatusRow contains a second 17-entry switch with
   the same row/view geometry but has no call to `0x00486d20`; this is the
   expected optimized result of a small class helper being inlined into the
   loop, not evidence for a second human geometry helper.
4. Source-era control: a pair of plain enums, `short` ABI, switch statements,
   stack `RectBounds`, fixed-width member arrays, and direct drawing calls are
   plausible late-1990s/mid-2000s C++ and do not require templates, lambdas,
   range loops, inferred modern types, or decompiler offset arithmetic.

The method names rank as follows:

1. `DrawStatusRowText`, `GetStatusRowRect`, `HitTestStatusRow`: best fit to
   behavior and existing project naming.
2. `DrawStatusRow`, `BuildStatusRowRect`, `HitTestRow`: plausible but less
   explicit or inconsistent with existing `Get...Rect`/`HitTest...` patterns.
3. `DrawInfoRow`: rejected because the first helper draws header, status, and
   management rows, not the info-list child.

The row names are descriptive behavior names, not localized labels. This
avoids claiming packet-supplied Korean/English UI strings as source constants.

## Evidence Standards Used

- Exact facts: live IDA function objects, addresses, bytes, xrefs, callsites,
  switch-table entries, field offsets, constants, helper signatures, current
  destination headers, and read-only generated output.
- Strong inference: source-facing method names, enum spelling, private helper
  visibility, human call from HitTestStatusRow to GetStatusRowRect, and source
  placement in the established Clan module.
- Historical lead only: executed B-agent report wording and former unresolved
  blockers, accepted only where independently reproduced.
- Negative evidence: no recovered exact names, no method data/vtable xrefs, no
  independent row type, no row for subtype 13, no consumed GetRect return, and
  no reason to emit compiler tables or alignment.
- Hash evidence: read-only PE bytes corroborate MCP ranges; MCP remains the
  primary authority.

## Evidence Checked

### Live MCP session

- Streamable endpoint: `http://127.0.0.1:13337/mcp`.
- Protocol session used for this pass:
  `eefd641d-3058-4fc8-8a26-570bfc651afc`.
- `idb_list` returned one active adopted worker database `fa658e1e`, PID
  `17316`, for `E:/NTK/Resources/NexusTK/NexusTK.exe.i64`.
- `server_health(database=fa658e1e)` returned `status=ok`, image base
  `0x00400000`, `auto_analysis_ready=true`, `hexrays_ready=true`,
  `strings_cache_ready=true`, cache size `2067`.
- Bounded `get_bytes` at `0x00486800`, size 32, returned
  `55 8b ec 66 8b 45 08 57 8b f9 0f bf d0 0f b7 8f fa 00 00 00 83 fa 0d 0f 87 bd 04 00 00 53 56 ff`.
- One schema-invalid evidence call used obsolete `address`/`size` keys and
  returned missing `regions`; `tools/list` was reread, the call was corrected,
  and the bounded read above succeeded. This was not an MCP outage and no
  evidence conclusion relies on the invalid call.

### MCP operations

- `lookup_funcs` for all three starts and exact-name variants.
- bounded decompilation/disassembly for all three functions and the direct
  caller portions of `OnPaintFrame` and `OnMouseEvent`.
- bounded callers/callees and xrefs for method starts, tables, and padding.
- bounded bytes for each function, internal/successor table, and padding span.
- helper lookups and current signatures for `InitRectBounds`, `PointInRect`,
  `GrafPort::GetTextWidth`, `GrafPort::MoveTo`, and
  `GrafPort::DrawWideText`.

### Documentation and report corpus

- Current target, class, file, caller, action, eligibility, rectangle, graphics,
  ignored-range, manual-coverage, and generated Clan.cpp pages.
- Active B001-B015 research roots, Older-Research, SpecialReports, actual
  `project-documentation/archived`, and executed-b-agent-research.
- Concrete search terms and every relevant opened report are listed under
  Supporting Research; roots with no direct result are recorded explicitly.

## Claim And Incorporation Ledger

All C01-C46 claims are in legal terminal callback states. `applied` identifies
accepted content incorporated into ordinary destinations, this report, or the
read-only generated proof; `already-present` identifies preserved accepted
facts whose correctness was reverified without expanding ownership.

| ID | Claim | Action | Destination | Verification state | Proof / callback requirement |
| --- | --- | --- | --- | --- | --- |
| C01 | Preserve assignment-time `86/90`, owner/emitter `00002K`, true, blank position, Nested 0 as historical current-page input. | historicalize | UID00010G | applied | Target now states current `92/94`, false, blank emitter; the accepted old header remains explicitly historical. |
| C02 | Record healthy MCP database `fa658e1e` and bounded target-byte proof. | incorporate | UID00010G | applied | Research evidence remains intact; callback introduced no contradictory binary fact. |
| C03 | Correct three code ranges to exact end-exclusive boundaries. | incorporate | UID00010G and children | applied | Registered paths end at `0x486cdf`, `0x486f40`, and `0x487292`; commands `12129-12131`. |
| C04 | Reclassify UID00010G as false/non-emitting split index. | incorporate | UID00010G | applied | Header/formal/summary validated by `12133` and final `12145`; generated UID count is zero. |
| C05 | Register DrawStatusRowText child first in ascending address order. | incorporate | `UID0004Q5` | applied | Validator registration `000000012129`; exact `[0x486800,0x486cdf)`. |
| C06 | Register GetStatusRowRect child second. | incorporate | `UID0004Q6` | applied | Validator registration `000000012130`; exact `[0x486d20,0x486f40)`. |
| C07 | Register HitTestStatusRow child third. | incorporate | `UID0004Q7` | applied | Validator registration `000000012131`; exact `[0x486f90,0x487292)`. |
| C08 | Classify five internal and three successor spans as compiler data/alignment. | incorporate | by-memory/-ignored.md | applied | Eight exact entries with bytes/xrefs/hashes validated by `000000012144`. |
| C09 | Preserve per-function SHA256 values. | incorporate | UID00010G and children | applied | Each child and parent retains the three function hashes from the accepted report. |
| C10 | Preserve target code-union and physical-span hashes separately. | incorporate | UID00010G | applied | Parent records `9E794C...C66DB` code union and `0FDE60...0232` physical band separately. |
| C11 | Record exact caller counts and callsite addresses. | incorporate | UID00010G, children, UID00010C | applied | Parent/children/UID00010C retain 13 Draw, 8 GetRect, and 2 HitTest callsites. |
| C12 | Record only true helper callees and reject switch targets as callees. | incorporate | children | applied | Child evidence keeps helper calls distinct from ignored table targets. |
| C13 | Preserve no data/vtable xrefs to the three method starts. | incorporate | children | applied | All three pages retain code-call liveness and negative data/vtable-xref evidence. |
| C14 | Use `void DrawStatusRowText(short rowIndex)`. | incorporate | Draw child/class | applied | Exact formal and declaration validated by `12129`/`12134`; generated definition count one. |
| C15 | Name exact text fields and arrays without raw offsets in C++. | incorporate | Draw child/class | applied | Formal block uses typed packet-populated fields; offsets remain evidence prose only. |
| C16 | Preserve exact baseline, center-x 94, and selected x/y offset 2 behavior. | incorporate | Draw child | applied | Exact formal/evidence validated by `12129` and emitted once by `12145`. |
| C17 | Reuse `RectBounds`; reject a new row rectangle type. | reject-invalid | GetRect/Hit/class | applied | Class and both children use `RectBounds`; no new rectangle type was created. |
| C18 | Use `void GetStatusRowRect(short, RectBounds *)`; reject IDA residue return. | incorporate | GetRect child/class | applied | Exact formal/declaration validated by `12130`/`12134`; generated return type is void. |
| C19 | Preserve all exact rectangles, including management row 10 top `157`. | incorporate | GetRect child | applied | Exact switch body and evidence retained in UID0004Q6. |
| C20 | Preserve view 0/1 row gates and tab gate `view <= 1`. | incorporate | GetRect child, class, UID00010C | applied | UID0004Q6, class, and caller aggregate retain the exact gates. |
| C21 | Use `short HitTestStatusRow(int y, int x)`. | incorporate | Hit child/class/UID00010C | applied | Exact formal/declaration/caller prose validated by `12131`, `12134`, and `12136`. |
| C22 | Model hit-test as loop calling GetStatusRowRect; record current inlining. | incorporate | Hit child | applied | Formal source call and compiler-inlined successor table evidence coexist; no duplicate generated body. |
| C23 | Add descriptive 16-value ClanStatusRow enum while preserving short ABI. | incorporate | class and row/action support | applied | Complete class enum validated by `12134`; UID00010H/UID00021N cross-links preserve numeric ABI. |
| C24 | Preserve row 2-13 to opcode `0x4b` subtype 1-12 mapping and subtype 13 exclusion. | incorporate | UID00010G, UID00010H, class/file | applied | Target/support union records mapping and no subtype-13 row; UID00010H body remains numeric. |
| C25 | Preserve `m_statusDataVersion >= 2` management/tab enablement. | incorporate | UID00010G, UID00010C, class | applied | Parent/class/caller evidence and formal gates retain the version rule. |
| C26 | Preserve `m_currentClanStatusView`, `m_statusDataVersion`, `m_selectedStatusRow`, and text-field names. | incorporate | class/children/UID00010C | applied | Typed fields are synchronized across class and three child pages without raw-offset C++. |
| C27 | Retain inferred-name status and reject DrawInfoRow/new rectangle aliases. | reject-stale | target and support prose | applied | All destinations preserve inferred spelling and rejected stale aliases. |
| C28 | Keep canonical semantic owner `00002K`. | already-present | parent and children | already-present | Owner was reverified and is current on parent plus all children. |
| C29 | Keep source placement `0000I8`, `NexusTK/social/Clan.cpp`. | already-present | file/class/children | already-present | Source route was preserved; final generated file is the expected Clan.cpp. |
| C30 | Replace complete ClanStatusPane formal block with rebased enums/declarations and class closure before `[[CHILDREN]]`. | incorporate | by-class/ClanStatusPane.md | applied | Command `12134`; generated class closes at line 538 before first child at line 819. |
| C31 | Make parent managed block exactly blank. | incorporate | UID00010G | applied | Commands `12133` and `12145`; generated contains zero UID00010G occurrences. |
| C32 | Insert three complete method formal blocks only into child destinations. | incorporate | three children | applied | Commands `12129-12131`; generated has one definition and UID marker per child. |
| C33 | Raise class score `87/89 -> 89/91`. | incorporate | UID00002K | applied | Current header `89/91`, validated by `12134`. |
| C34 | Raise parent score `86/90 -> 92/94`. | incorporate | UID00010G | applied | Current header `92/94`, validated by `12133` and `12145`. |
| C35 | Set child scores `91/93`, `92/94`, `91/93`. | incorporate | three children | applied | Current child headers and generated metadata match exactly. |
| C36 | Raise UID00010C `86/90 -> 88/91` and correct row-helper/y-x prose without altering its aggregate body. | incorporate | UID00010C | applied | Command `12136`; exact aggregate formal block and unrelated content preserved. |
| C37 | Synchronize UID00010H enum/action cross-link; preserve `88/91`, numeric packet body, and all packet facts. | incorporate | UID00010H | applied | Command `12138`; score and numeric formal body unchanged. |
| C38 | Change UID00021N only as needed for cross-links and relative `Nested:-4`; preserve `88/91` and body. | incorporate | UID00021N | applied | Command `12140`; current `Nested:-4`, score/body/range preserved. |
| C39 | Add missing internal ignored rows and rebase existing successor ignored ownership. | incorporate | by-memory/-ignored.md | applied | Command `12144`; five internal plus three successor entries use real UIDs and exact hashes/xrefs. |
| C40 | Synchronize Clan file inventory/source route without changing `90/85`. | incorporate | by-file/Clan.md | applied | Command `12142`; current `90/85`, route and unrelated Clan union preserved. |
| C41 | Preserve old report findings as dated leads and supersede only reproduced stale blockers. | historicalize | target/support prose | applied | Historical report table remains; current destination truth is distinguished explicitly. |
| C42 | Preserve all negative evidence and rejected alternatives. | incorporate | target and children | applied | Parent, children, class, support, and this report retain those sections at accepted depth. |
| C43 | Replace current aggregate-only generated marker with exactly three definitions and no target marker after callback. | incorporate | generated readback only | applied | Waited `12145`: child definition counts `1/1/1`, UID00010G count `0`, target empty count `0`. |
| C44 | Supply exact manual coverage replacements/additions and finalize child rows after registration. | incorporate | supervisor-owned coverage | applied | Exact rows below use real UIDs; read-only post-callback comparison confirms manual rows remain stale/absent; B004 did not edit coverage. |
| C45 | Run one scoped validator per changed ordinary page and one final waited generated refresh. | incorporate | validator plan/report | applied | Registrations `12129-12131`, ordinary validations `12133-12144`, waited refresh `12145`; all exit 0. |
| C46 | Preserve B004 role boundaries and external report-lifecycle ownership. | already-present | this report | already-present | B004 used only authorized ordinary validators and report edits; no report lifecycle/manual coverage command ran. |

## Positive Evidence Summary

- Three exact IDA function objects exist at the assigned starts.
- Draw has 13 direct live calls from OnPaintFrame; GetRect has seven paint and
  one mouse call; HitTest has two mouse callsites.
- All row text slots, baselines, rectangle constants, view gates, selection
  offsets, helper calls, action relationships, and return behavior are
  recoverable.
- `RectBounds`, `InitRectBounds`, and `PointInRect` are already modeled with
  compatible signatures.
- The three methods operate exclusively on ClanStatusPane state or UI helpers.
- The duplicated hit-test geometry is compiler-inline explainable without
  inventing source duplication.
- Every gap/table/padding span has an exact boundary and disposition.
- The current generated Clan.cpp already places the aggregate in the correct
  file; only source granularity is wrong.

## IDA MCP Facts

### Function and byte identity

| Function | IDA object | Size/end | Instruction / block profile | SHA256 |
| --- | --- | --- | --- | --- |
| DrawStatusRowText | `sub_486800` | `0x4df`, end `0x486cdf` | 491 instructions, 43 basic blocks | `7E57554F95EB711ABE3ED2F228541F22EA0CDD7F0A8B07138A612E3ABD2631B7` |
| GetStatusRowRect | `sub_486D20` | `0x220`, end `0x486f40` | 152 instructions, 24 basic blocks | `22F221166562683F172D3FAEBC8C27DAC50A66F32F76FF54E8EC72850E363A46` |
| HitTestStatusRow | `sub_486F90` | `0x302`, end `0x487292` | 215 instructions, 27 basic blocks | `AF80BCD3A78DD66E1EC929D126A3BCF287698945CB90A02D8B585E6457165D40` |

- Code plus internal spans `[0x486800,0x487292)` size `0xa92`: SHA256
  `9E794C763876579FF38E8636590C4E21895B683750E7B855490A9A09276C66DB`.
- Physical band through successor support `[0x486800,0x4872e0)` size `0xae0`:
  SHA256 `0FDE60F0B2F16404571030BF3ECA5F3CDD2407475A053DBE54A5E935CB1D0232`.

### DrawStatusRowText facts

- Stack argument is sign-extended from 16 bits; function returns with `retn 4`.
- It handles row 0 and rows 2-13. Row 1 and all out-of-range values return.
- Text storage is header `+0xfe`; status array elements at `+0x2150`,
  `+0x21a0`, `+0x21f0`, `+0x2240`, `+0x2290`; management elements at
  `+0x22e0`, `+0x2330`, `+0x2380`, `+0x23d0`, `+0x2420`, `+0x2470`,
  `+0x24c0`. The `0x50` stride is 40 wide characters.
- Baselines are 61 for header; 112, 141, 170, 199, 228 for status; and 83,
  112, 141, 170, 199, 228, 257 for management.
- Center x is 94. A selected row adds 2 to both computed x and baseline y.
- True callees are `GrafPort::GetTextWidth(const wchar_t *)` at `0x4baa70`,
  `GrafPort::MoveTo(int,int)` at `0x4b9600`, and
  `GrafPort::DrawWideText(const wchar_t *,int)` at `0x4bab70`.

### GetStatusRowRect facts

- Stack arguments are signed 16-bit row then `RectBounds *`; `retn 8`.
- Every caller ignores EAX. IDA's result follows the final InitRectBounds call
  and is not a live human return value.
- Rows 2-6 require view 0. Rows 7-13 require view 1. Rows 14/15 require view
  at most 1. Row 0, row 1, hidden rows, and invalid rows become all `-1`.
- It calls only `InitRectBounds` as a true helper.

### HitTestStatusRow facts

- Arguments are `int y, int x`; result is signed short in AX; `retn 8`.
- The loop tests row 0 through 15 in ascending order and returns first match or
  `-1`.
- The binary inlines the complete geometry switch and then calls
  `PointInRect(y,x,&bounds)`; it has no direct call to `0x486d20`.
- True callees are `InitRectBounds`, `PointInRect`, and the compiler security
  cookie checker. The cookie is compiler support, not source behavior.

## Function / Child Inventory

| Order | Current destination | Exact range | Kind | Metadata | Nested | Formal disposition |
| --- | --- | --- | --- | --- | --- | --- |
| Parent | UID00010G current path | `[0x486800,0x487292)` mixed | false split index | `92/94`, owner `00002K`, false, emitter/position blank | `0` | Blank. |
| 1 | `by-memory/0x00486800-0x00486cde.ClanStatusPaneDrawStatusRowText.md` | `[0x486800,0x486cdf)` | class method | `91/93`, owner/emitter `00002K`, true, position blank | `+4` | Complete body. |
| 2 | `by-memory/0x00486d20-0x00486f3f.ClanStatusPaneGetStatusRowRect.md` | `[0x486d20,0x486f40)` | class method | `92/94`, owner/emitter `00002K`, true, position blank | `0` | Complete body. |
| 3 | `by-memory/0x00486f90-0x00487291.ClanStatusPaneHitTestStatusRow.md` | `[0x486f90,0x487292)` | class method | `91/93`, owner/emitter `00002K`, true, position blank | `0` | Complete body. |
| Successor | UID00021N current path | `[0x4872e0,0x487336)` modeled helper | existing class method | preserve `88/91`, owner/emitter `00002K`, true | `-4` | Preserve body. |

The historical registration tokens were replaced serially. Current exact UIDs
are `0004Q5`, `0004Q6`, and `0004Q7`; no registration token remains.

### Row and view inventory

| Value | Descriptive source name | View / behavior | Packet relationship |
| --- | --- | --- | --- |
| 0 | Header | Header text, baseline 61 | None. |
| 1 | Unused | No draw, invalid rectangle | None. |
| 2 | EnlistRequest | Status view | Opcode `0x4b`, subtype 1. |
| 3 | JoinList | Status view | Subtype 2, join-list refresh/open family. |
| 4 | LeaveClan | Status view | Subtype 3, leave-request family. |
| 5 | DepositMoney | Status view | Subtype 4. |
| 6 | DepositItem | Status view | Subtype 5. |
| 7 | EnlistList | Management view | Subtype 6 via refresh helper. |
| 8 | ExpelMember | Management view | Subtype 7/name dialog family. |
| 9 | SummonMember | Management view | Subtype 8/name dialog family. |
| 10 | AppearMember | Management view | Subtype 9/name dialog family. |
| 11 | ChangeName | Management view | Subtype 10/name dialog family. |
| 12 | WithdrawMoney | Management view | Subtype 11. |
| 13 | WithdrawItem | Management view | Subtype 12. |
| 14 | ManagementTab | Views 0/1 only | Switch to management if version >=2. |
| 15 | StatusTab | Views 0/1 only | Switch to status if version >=2. |

View values are status `0`, management `1`, info list `2`, join list `3`, and
enlist list `4`. The exact original enum spellings are not recoverable.

## Direct Xref / Caller Inventory

- DrawStatusRowText has 13 code refs from `sub_484A60` at `0x484b3c`,
  `0x484b5a`, `0x484b63`, `0x484b6c`, `0x484b75`, `0x484b7e`,
  `0x484b87`, `0x484b90`, `0x484bb1`, `0x484bba`, `0x484bc3`,
  `0x484bcc`, and `0x484bd5`.
- GetStatusRowRect has seven paint refs at `0x484b06`, `0x484bfb`,
  `0x484c14`, `0x484c2d`, `0x484c4a`, `0x484c77`, `0x484c90`, plus
  mouse ref `0x484ea1`.
- HitTestStatusRow has mouse refs `0x484de2` and `0x484e24`.
- Draw jump table `0x486ce0` has data xref from `0x48681f`.
- GetRect jump table `0x486f40` has data xref from `0x486d34`.
- HitTest jump table `0x487294` has data xref from `0x486fb8`.
- No data/vtable xrefs target any method start. Liveness is established by
  direct code calls; lack of vtable entries is consistent with private/nonvirtual
  helpers.

OnMouseEvent's secondary receiver is adjusted back by `0xa0`. It passes event
field `+0x08` as y and `+0x0c` as x, calls hit test for two event kinds, applies
UID00021N before row packet dispatch, stores selected row, obtains its rectangle,
and invalidates that region. Rows 14/15 switch the view instead of sending a
row-action packet.

## Documentation Evidence And IDA Status

- Current IDA status was healthy when this evidence was collected. This does
  not assert indefinite future session availability.
- The target's prior boundaries are correct for function instruction ranges
  but incomplete as a source container because internal compiler spans are not
  represented in `-ignored.md`.
- Current target names are useful and retained, but they are inferred names,
  not IDA symbols.
- Current UID00010C's `mouseX`/`mouseY` interpretation must be corrected to
  y-first/x-second where it describes the helper ABI.
- Current class has no row/view enum or row-helper declarations.
- Current file route is correct and needs inventory synchronization only.
- Current UID00010H and UID00021N formal bodies remain behaviorally valid.
- Current generated Clan.cpp, validator command `000000012100`, refreshed at
  `2026-07-14T19:08:43-04:00`, emits UID00010G only as an aggregate comment at
  lines 785-786. It contains no UID00010G Empty Emitter Marker. Two unrelated
  empty markers (UID0003B9 and UID0003HE) are outside scope.

## Ranked Ownership Analysis

1. **ClanStatusPane member helpers in Clan.cpp: accepted.** All methods consume
   ClanStatusPane fields, all calls originate in its frame/input methods, and
   all support pages route through class UID00002K/file UID0000I8.
2. **File-local static helpers in Clan.cpp: rejected.** A static helper could
   receive the pane explicitly, but every caller establishes a ClanStatusPane
   receiver and the bodies access fields through `this`.
3. **Pane/GrafPort member helpers: rejected.** Rectangle/draw primitives are
   dependencies only; row arrays, view state, and packet relationships are
   clan-specific.
4. **Aggregate UID00010G source owner: rejected.** The range is an evidence
   index, not a single source entity. Emitting a shared comment or three bodies
   from one multi-function page makes ordering/nesting and generated ownership
   fragile.

Canonical semantic owner remains `00002K`. Each source child emits through
that class. The parent has no emitter because it is a false split index.

## Source Placement

Place declarations in the complete [UID:00002K] ClanStatusPane class block and
definitions in [UID:0000I8] `NexusTK/social/Clan.cpp`, adjacent to the existing
ClanStatusPane frame/input and packet/helper family in address/source order.

No evidence supports `ClanBank.cpp`, `ClanItemDialogs.cpp`, `ClanDialogs.cpp`,
or a generic UI geometry source file. `RectBounds` and GrafPort APIs remain
dependencies and must not acquire clan-specific methods.

## Range / Split / Padding / Reclassification Analysis

### Exact compiler-only spans

| Range | Bytes / table | SHA256 | Disposition |
| --- | --- | --- | --- |
| `[0x486cdf,0x486ce0)` | one `90` | `9E076CEAF246B6003D9C2680A2B4CF0BFFD069805902B0B5EDEEBF49039FE4BD` | alignment |
| `[0x486ce0,0x486d18)` | 14-entry Draw jump table | `5443D77E306691002E222D9B289885615498141DC005E5F2B46D9DDE5DC4AA67` | compiler switch data |
| `[0x486d18,0x486d20)` | eight `cc` | `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3` | alignment |
| `[0x486f40,0x486f84)` | 17-entry GetRect jump table | `0AF441481CBF26D2735684D11EAA90B31A98D9FC563B83BAA05DD36665DA4ED2` | compiler switch data |
| `[0x486f84,0x486f90)` | twelve `cc` | `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902` | alignment |
| `[0x487292,0x487294)` | `66 90` | `88174BA925C5691BFF5CF2698A670490725C2F586FD946282B314EA52D9C24CE` | alignment |
| `[0x487294,0x4872d8)` | 17-entry HitTest jump table | `148B3E315EA398AFFACF64E8B94672E0E9B1F5C06C8CCE2667671EC9DC10CF9B` | compiler-inlined switch data |
| `[0x4872d8,0x4872e0)` | eight `cc` | `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3` | alignment |

Draw table targets are `0x486826`, `0x486cd8`, `0x48687f`, `0x4868d5`,
`0x48692f`, `0x48698f`, `0x4869ef`, `0x486a4f`, `0x486aa5`, `0x486aff`,
`0x486b5f`, `0x486bbf`, `0x486c1f`, `0x486c7f`.

GetRect table targets are `0x486f21` three times, then `0x486d3b`,
`0x486d69`, `0x486d99`, `0x486dc9`, `0x486df9`, `0x486e29`,
`0x486e59`, `0x486e69`, `0x486e81`, `0x486e99`, `0x486eb1`,
`0x486ec9`, `0x486f01`, `0x486ee1`.

HitTest table targets are `0x48722c` three times, then `0x486fbf`,
`0x486ff1`, `0x487023`, `0x487055`, `0x487087`, `0x4870b9`,
`0x4870eb`, `0x4870f8`, `0x48712a`, `0x48715c`, `0x48718e`,
`0x4871bd`, `0x48720c`, `0x4871ec`.

### Relative nesting

`Nested` is a relative delta from the previous address-sorted row, not a child
count. Keep parent UID00010G at `0`; apply `+4` to the first registered child,
`0` to the second and third children, and `-4` to successor UID00021N. This
creates one visual child level for all three methods and restores the prior
cumulative level before the successor. No other page receives a nesting delta.

## Negative Evidence Summary

- No exact qualified or unqualified helper symbol exists in IDA for any
  recommended method name.
- No separate `ClanStatusRowRect` type or ClanStatusPane layout page exists.
- No caller consumes a GetStatusRowRect return value.
- No method start has a vtable/data xref; these are nonvirtual helpers.
- No row 1 draw/rectangle/action exists.
- No row maps to opcode `0x4b` subtype 13.
- No source-facing localized label constants are recovered; row text arrives
  through packet-populated wide arrays.
- No evidence supports x-first hit-test arguments.
- No evidence supports handwritten duplicate geometry in HitTestStatusRow.
- No evidence supports emitting switch tables, padding, security-cookie logic,
  raw offsets, or decompiler register artifacts.
- No active report collision was found.

## IDA Rename / Type / Comment Recommendations

- Rename IDA functions only if a later supervisor-authorized IDA pass exists:
  `sub_486800` -> `ClanStatusPane__DrawStatusRowText`, `sub_486D20` ->
  `ClanStatusPane__GetStatusRowRect`, and `sub_486F90` ->
  `ClanStatusPane__HitTestStatusRow`.
- Apply `ClanStatusPane *this` and signed-short row types; apply
  `RectBounds *outBounds` to the second method; apply `int y, int x` and short
  return to the third.
- Comment the two later geometry switches as compiler-generated/inlined source
  lowering, not separate helpers.
- Comment `0x486ce0`, `0x486f40`, and `0x487294` as switch tables with their
  owning method.
- Do not mutate IDA during this task. These are documentation recommendations
  only.

## First-Draft C++ Recommendation

The following exact complete managed destination blocks are installed at their
named destinations. No additional source text exists outside them.

### Destination 1: UID00010G parent, blank by design

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 2: `UID0004Q5`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ClanStatusPane::DrawStatusRowText(short rowIndex)
{
    const wchar_t *text;
    int baselineY;

    switch (rowIndex) {
    case kClanStatusRowHeader:
        text = m_statusHeaderText;
        baselineY = 61;
        break;
    case kClanStatusRowEnlistRequest:
        text = m_statusActionText[0];
        baselineY = 112;
        break;
    case kClanStatusRowJoinList:
        text = m_statusActionText[1];
        baselineY = 141;
        break;
    case kClanStatusRowLeaveClan:
        text = m_statusActionText[2];
        baselineY = 170;
        break;
    case kClanStatusRowDepositMoney:
        text = m_statusActionText[3];
        baselineY = 199;
        break;
    case kClanStatusRowDepositItem:
        text = m_statusActionText[4];
        baselineY = 228;
        break;
    case kClanStatusRowEnlistList:
        text = m_managementActionText[0];
        baselineY = 83;
        break;
    case kClanStatusRowExpelMember:
        text = m_managementActionText[1];
        baselineY = 112;
        break;
    case kClanStatusRowSummonMember:
        text = m_managementActionText[2];
        baselineY = 141;
        break;
    case kClanStatusRowAppearMember:
        text = m_managementActionText[3];
        baselineY = 170;
        break;
    case kClanStatusRowChangeName:
        text = m_managementActionText[4];
        baselineY = 199;
        break;
    case kClanStatusRowWithdrawMoney:
        text = m_managementActionText[5];
        baselineY = 228;
        break;
    case kClanStatusRowWithdrawItem:
        text = m_managementActionText[6];
        baselineY = 257;
        break;
    default:
        return;
    }

    const int selectedOffset = m_selectedStatusRow == rowIndex ? 2 : 0;
    MoveTo(94 - GetTextWidth(text) / 2 + selectedOffset,
           baselineY + selectedOffset);
    DrawWideText(text, static_cast<int>(wcslen(text)));
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 3: `UID0004Q6`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ClanStatusPane::GetStatusRowRect(short rowIndex, RectBounds *outBounds)
{
    switch (rowIndex) {
    case kClanStatusRowEnlistRequest:
        if (m_currentClanStatusView == kClanStatusViewStatus) {
            InitRectBounds(outBounds, 16, 98, 175, 116);
            return;
        }
        break;
    case kClanStatusRowJoinList:
        if (m_currentClanStatusView == kClanStatusViewStatus) {
            InitRectBounds(outBounds, 16, 127, 175, 145);
            return;
        }
        break;
    case kClanStatusRowLeaveClan:
        if (m_currentClanStatusView == kClanStatusViewStatus) {
            InitRectBounds(outBounds, 16, 156, 175, 174);
            return;
        }
        break;
    case kClanStatusRowDepositMoney:
        if (m_currentClanStatusView == kClanStatusViewStatus) {
            InitRectBounds(outBounds, 16, 185, 175, 203);
            return;
        }
        break;
    case kClanStatusRowDepositItem:
        if (m_currentClanStatusView == kClanStatusViewStatus) {
            InitRectBounds(outBounds, 16, 214, 175, 232);
            return;
        }
        break;
    case kClanStatusRowEnlistList:
        if (m_currentClanStatusView == kClanStatusViewManagement) {
            InitRectBounds(outBounds, 16, 69, 175, 87);
            return;
        }
        break;
    case kClanStatusRowExpelMember:
        if (m_currentClanStatusView == kClanStatusViewManagement) {
            InitRectBounds(outBounds, 16, 98, 175, 116);
            return;
        }
        break;
    case kClanStatusRowSummonMember:
        if (m_currentClanStatusView == kClanStatusViewManagement) {
            InitRectBounds(outBounds, 16, 127, 175, 145);
            return;
        }
        break;
    case kClanStatusRowAppearMember:
        if (m_currentClanStatusView == kClanStatusViewManagement) {
            InitRectBounds(outBounds, 16, 157, 175, 174);
            return;
        }
        break;
    case kClanStatusRowChangeName:
        if (m_currentClanStatusView == kClanStatusViewManagement) {
            InitRectBounds(outBounds, 16, 185, 175, 203);
            return;
        }
        break;
    case kClanStatusRowWithdrawMoney:
        if (m_currentClanStatusView == kClanStatusViewManagement) {
            InitRectBounds(outBounds, 16, 214, 175, 232);
            return;
        }
        break;
    case kClanStatusRowWithdrawItem:
        if (m_currentClanStatusView == kClanStatusViewManagement) {
            InitRectBounds(outBounds, 16, 243, 175, 261);
            return;
        }
        break;
    case kClanStatusRowManagementTab:
        if (m_currentClanStatusView <= kClanStatusViewManagement) {
            InitRectBounds(outBounds, 96, 270, 108, 282);
            return;
        }
        break;
    case kClanStatusRowStatusTab:
        if (m_currentClanStatusView <= kClanStatusViewManagement) {
            InitRectBounds(outBounds, 84, 270, 96, 282);
            return;
        }
        break;
    }

    InitRectBounds(outBounds, -1, -1, -1, -1);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 4: `UID0004Q7`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
short ClanStatusPane::HitTestStatusRow(int y, int x)
{
    for (short rowIndex = 0; rowIndex < 16; ++rowIndex) {
        RectBounds bounds;
        GetStatusRowRect(rowIndex, &bounds);
        if (PointInRect(y, x, &bounds))
            return rowIndex;
    }

    return -1;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 5: complete rebased by-class/ClanStatusPane.md block

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
enum ClanStatusView
{
    kClanStatusViewStatus = 0,
    kClanStatusViewManagement = 1,
    kClanStatusViewInfoList = 2,
    kClanStatusViewJoinList = 3,
    kClanStatusViewEnlistList = 4
};

enum ClanStatusRow
{
    kClanStatusRowHeader = 0,
    kClanStatusRowUnused = 1,
    kClanStatusRowEnlistRequest = 2,
    kClanStatusRowJoinList = 3,
    kClanStatusRowLeaveClan = 4,
    kClanStatusRowDepositMoney = 5,
    kClanStatusRowDepositItem = 6,
    kClanStatusRowEnlistList = 7,
    kClanStatusRowExpelMember = 8,
    kClanStatusRowSummonMember = 9,
    kClanStatusRowAppearMember = 10,
    kClanStatusRowChangeName = 11,
    kClanStatusRowWithdrawMoney = 12,
    kClanStatusRowWithdrawItem = 13,
    kClanStatusRowManagementTab = 14,
    kClanStatusRowStatusTab = 15
};

class ClanStatusPane : public Pane
{
public:
    ClanStatusPane();
    virtual ~ClanStatusPane();

    void ParseClanStatusAttributePacket(const unsigned char *packet);
    void RefreshChildPanes();
    void ShowInfoList();
    void ShowEnlistList();
    void ForwardInputEvent(const InputEvent &event);

    int SendClanJoinListSelectionPacket(const wchar_t *selectedClanName);
    void SendClanLeaveResponse(bool confirmed);
    int SendClanStatusRowActionPacket(short rowIndex);
    int SendClanEnlistListRefreshPacket();
    int SendClanEnlistListSelectionPacket(const wchar_t *applicantName);
    int SendClanAttributePacket(const wchar_t *clanName, const wchar_t *descriptionText, const wchar_t *attributeText, unsigned short attributeType);
    bool IsRowActionBlocked(short rowIndex);

private:
    void DrawStatusRowText(short rowIndex);
    void GetStatusRowRect(short rowIndex, RectBounds *outBounds);
    short HitTestStatusRow(int y, int x);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Private visibility is the strongest inference from class-internal callers and
no external xrefs, but original access tokens are not symbol-proven. This
uncertainty is reflected in the confidence cap and does not change ABI/body.

## Final Recommendation

The exact split and formal plan above is implemented. The three source-bearing
method bodies no longer remain blocked by the historical 85-gate or
unresolved-label wording. The parent, jump tables, padding, and security-cookie
lowering remain non-source and non-emitting.

The callback registered Draw as `0004Q5`, GetRect as `0004Q6`, and HitTest as
`0004Q7` in ascending address order, then installed dependent parent/support
cross-links, relative nesting, formal blocks, ignored spans, and exact report
UIDs. No temporary or guessed UID remains.

Report validation/execution/count/path/move/archive state is externally owned
and is not directed or predicted by this artifact.

## Recommended Target Doc Changes

Current applied UID00010G state:

- `COMPLETION:92`, `CONFIDENCE:94`.
- `CANONICAL_OWNER:00002K` is preserved.
- `RECONSTRUCTABLE:FALSE` is current.
- `EMITTER_UIDS` and `EMITTER_POSITION_OPTIONAL` are blank.
- `Nested:0` is current.
- The aggregate comment was replaced by the exact blank managed block.
- Complete Item Summary names the three real child UIDs, all
  code/table/padding boundaries, source route, and false split-index
  disposition.
- Exact caller/callee, field, geometry, row/action, version/view,
  hash, negative, historical, and rejected-alternative evidence at report
  depth is preserved.
- Complete child inventory and links were added after registration.

Applied parent Item Summary substance: false/non-emitting split index for
three ClanStatusPane row methods; exact code ranges and internal switch/padding
spans; semantic owner UID00002K; source route UID0000I8 Clan.cpp; no parent
source; current method UIDs named after allocation; exact evidence retained.

## Recommended Support Doc Changes

1. Registered the three method pages serially with the accepted metadata,
   ranges, nesting, summaries, evidence, and exact managed blocks.
2. `by-class/ClanStatusPane.md`: applied `87/89 -> 89/91`, complete rebased
   class block, row/view inventories, exact method links, fields, callers,
   geometry, inlining, source route, uncertainty, and rejected alternatives.
3. UID00010C `ClanStatusPaneFrameAndInput`: applied `86/90 -> 88/91`, real child
   links, and corrected y/x semantics while preserving its aggregate comment,
   ranges, resources, event behavior, and unrelated split work.
4. UID00010H `ClanStatusRowActionPacket`: preserved `88/91` and exact numeric
   formal body while adding descriptive enum cross-reference and subtype 13
   exclusion.
5. UID00021N `ClanStatusPaneRowEligibilityHelper`: preserved `88/91`, formal
   body, range, and evidence while adding links and setting `Nested:-4`.
6. [UID:0000I8] `by-file/Clan.md`: preserved `90/85` and source path while
   synchronizing the false parent, three children, compiler spans, and
   generated source expectations.
7. `by-memory/-ignored.md`: added five missing internal spans and rebased the
   three successor spans to the hit-test child and inlined switch.
8. UID0001VP, UID00015S, UID00016C, UID000162, parser/constructor/global/vtable,
   and child-view pages were verify-only; their scores/formals/content were
   preserved.
9. No new ClanStatusPane layout page is justified; existing class/detail plus
   RectBounds is sufficient.

## Score And Metadata Recommendation

| Destination | Historical / prior | Current applied | Owner / emitter | Reconstructable | Position | Nested | Rationale / cap |
| --- | --- | --- | --- | --- | --- | --- | --- |
| UID00010G | `86/90` | `92/94` | `00002K` / blank | false | blank | 0 | Complete split/evidence; original symbols remain lost. |
| UID0004Q5 Draw child | new | `91/93` | `00002K` / `00002K` | true | blank | +4 | Exact body/callers/fields; names and access inferred. |
| UID0004Q6 GetRect child | new | `92/94` | `00002K` / `00002K` | true | blank | 0 | Exact geometry/type/gates; name inferred. |
| UID0004Q7 HitTest child | new | `91/93` | `00002K` / `00002K` | true | blank | 0 | Exact ABI/loop; source call versus compiler inline inferred. |
| UID00002K | `87/89` | `89/91` | `0000I8` / `0000I8` | true | blank | preserve | Row contract resolved; broader class uncertainty remains. |
| UID00010C | `86/90` | `88/91` | `00002K` / `00002K` | true | blank | preserve | Dependencies resolved; own split/body remains aggregate. |
| UID00010H | `88/91` | unchanged | `00002K` / `00002K` | true | blank | preserve | Cross-link only. |
| UID00021N | `88/91` | unchanged | `00002K` / `00002K` | true | blank | -4 | Body unchanged; nesting restores cumulative level. |
| UID0000I8 | `90/85` | unchanged | FILE | n/a | n/a | n/a | Inventory/source synchronization only. |

No score is raised beyond the applied values merely because an uncertainty is
unresolved. Remaining uncertainties are irrecoverable spelling/access
questions with bounded source choices and explicit confidence caps.

## Open Questions With Attempted Resolution

| Question | Attempts | Resolution |
| --- | --- | --- |
| Original function names | Exact-name MCP probes, reports, callers, project patterns | Not recoverable; selected names are strongest descriptive forms and ready for use. |
| Original row enumerators | Parser/action/label searches and sibling helpers | Not recoverable; descriptive enum accepted, short ABI preserved. |
| Original view enum | Constructor/show-helper/parser values | Five descriptive values fully resolved; spelling inferred. |
| Helper access | Xrefs and class use | Private is highest probability; no external calls. Confidence cap retained. |
| Rectangle type | Type/support/current signatures | Resolved exactly as RectBounds. |
| GetRect return | Callsite liveness and callee residue | Resolved void. |
| Hit-test argument order | Event pushes and PointInRect | Resolved y, x. |
| Duplicate geometry source | Direct call absence and optimized shape | Resolved as inlined GetStatusRowRect source call. |
| Row 10 top coordinate | Separate status/management switch constants | Exact management top is 157; status row 4 top is 156. |
| Subtype 13 row | Packet helper inventory | No row; retain separate notice behavior. |
| Parent emission | Generator and method identity | Resolved false/non-emitting split index. |
| Internal data ownership | Xrefs/bytes/tables | Resolved compiler-only ignored spans tied to owning child. |

No investigable blocker remains deferred.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

B004 re-read the manual rows after the callback in
`by-memory/-coverage-report.md` lines 887, 920, 924, and 935;
`by-class/-coverage-report.md` line 117; and `by-file/-coverage-report.md` line
52. UID00010C/00010G/00021N/00010H and the class/file rows remain stale, and
UID0004Q5/0004Q6/0004Q7 remain absent. B004 did not edit them.

The following are the exact current supervisor-owned manual coverage rows with
validator-assigned child UIDs. They originated as pre-registration templates,
but every placeholder was replaced during the callback. B004 did not apply
them to the manual coverage file.

Replace the UID00010C row with:

    - [UID:00010C][0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput](by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md) : reconstructable : 88% : very strong : IDA-verified ClanStatusPane frame/key/mouse virtual aggregate with exact resources, view/version/selection state, y-first/x-second row hit testing through the registered row-helper children, child-pane refresh, row-action packet dispatch, and compiler-data boundaries; its own three-way source split remains explicit.

Replace UID00010G and insert the three real-UID child rows immediately after
it using this finalized text:

    - [UID:00010G][0x00486800-0x00487291.ClanStatusPaneRows](by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md) : not reconstructable : 92% : very strong : False/non-emitting split index for three registered ClanStatusPane row source methods; exact function/table/padding ranges, callers, fields, geometry, row/view/action semantics, source route, hashes, historical evidence, and rejected alternatives are complete.
        - [UID:0004Q5][0x00486800-0x00486cde.ClanStatusPaneDrawStatusRowText](by-memory/0x00486800-0x00486cde.ClanStatusPaneDrawStatusRowText.md) : reconstructable : 91% : very strong : ClanStatusPane::DrawStatusRowText(short) draws the header and status/management rows from packet-populated wide fields using exact baselines, center x 94, selected x/y offset 2, GrafPort width/move/draw helpers, and descriptive row constants.
        - [UID:0004Q6][0x00486d20-0x00486f3f.ClanStatusPaneGetStatusRowRect](by-memory/0x00486d20-0x00486f3f.ClanStatusPaneGetStatusRowRect.md) : reconstructable : 92% : very strong : ClanStatusPane::GetStatusRowRect(short,RectBounds*) initializes exact status/manage/tab rectangles, preserves all view gates and invalid all-minus-one bounds, and has a void source contract despite IDA register residue.
        - [UID:0004Q7][0x00486f90-0x00487291.ClanStatusPaneHitTestStatusRow](by-memory/0x00486f90-0x00487291.ClanStatusPaneHitTestStatusRow.md) : reconstructable : 91% : very strong : ClanStatusPane::HitTestStatusRow(int y,int x) scans rows 0-15 with RectBounds/GetStatusRowRect and PointInRect, returns the first signed-short row or -1, and records MSVC's inlined geometry switch/cookie lowering separately.

Insert these missing ignored rows in address order between the Draw/Get/Hit
children:

    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00486cdf-0x00486ce0 | padding | ClanStatusPaneDrawStatusRowText alignment : ignored : 100% : very strong : One-byte NOP after the exact DrawStatusRowText function.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00486ce0-0x00486d18 | jump-table | ClanStatusPaneDrawStatusRowText switch table : ignored : 100% : very strong : Fourteen-entry compiler switch table referenced from 0x0048681f; generated by the DrawStatusRowText switch.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00486d18-0x00486d20 | padding | ClanStatusPane row-draw/GetRect alignment : ignored : 100% : very strong : Eight int3 alignment bytes before GetStatusRowRect.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00486f40-0x00486f84 | jump-table | ClanStatusPaneGetStatusRowRect switch table : ignored : 100% : very strong : Seventeen-entry compiler switch table referenced from 0x00486d34; generated by the GetStatusRowRect switch.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00486f84-0x00486f90 | padding | ClanStatusPane GetRect/hit-test alignment : ignored : 100% : very strong : Twelve int3 alignment bytes before HitTestStatusRow.

Replace existing successor ignored rows 921-923 with the real hit-child UID:

    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00487292-0x00487294 | padding | ClanStatusPaneHitTestStatusRow switch-table alignment : ignored : 100% : very strong : Two-byte alignment after [UID:0004Q7] HitTestStatusRow.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00487294-0x004872d8 | jump-table | ClanStatusPaneHitTestStatusRow inlined GetStatusRowRect switch table : ignored : 100% : very strong : Seventeen-entry compiler table referenced from 0x00486fb8; generated by the source call to GetStatusRowRect in the hit-test loop.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004872d8-0x004872e0 | padding | ClanStatusPane hit-test/row-eligibility alignment : ignored : 100% : very strong : Eight int3 bytes before UID00021N.

Replace UID00021N with:

    - [UID:00021N][0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper](by-memory/0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper.md) 0x004872e0-0x00487335 | class method | ClanStatusPaneRowEligibilityHelper : reconstructable : 88% : very strong : ClanStatusPane::IsRowActionBlocked(short) preserves the exact signed-row switch, view/version gates, fields, caller route, compiler table boundary, formal body, and descriptive row-enum relationship; its Nested -4 delta restores the parent level after the three UID00010G children.

Replace UID00010H with:

    - [UID:00010H][0x00487600-0x0048779f.ClanStatusRowActionPacket](by-memory/0x00487600-0x0048779f.ClanStatusRowActionPacket.md) 0x00487600-0x0048779f | class method | ClanStatusRowActionPacket : reconstructable : 88% : very strong : ClanStatusPane::SendClanStatusRowActionPacket(short) preserves rows 2-13 to opcode 0x4b subtypes 1-12, row 7 refresh delegation, packet writer/send dependencies, exact switch table, numeric formal body, and cross-links the descriptive ClanStatusRow enum without inventing a subtype-13 row.

Replace the class row with:

- [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md) : reconstructable : 89% : very strong : ClanStatusPane source model now includes complete status-view and row enums, exact DrawStatusRowText/GetStatusRowRect/HitTestStatusRow declarations and registered children, RectBounds/y-first hit-test contracts, packet-populated label arrays, view/version/selection fields, existing packet/helper/class relationships, vtable/global anchors, and Clan.cpp ownership; inferred original spellings/access remain confidence-capped.

Replace the file row with:

- [UID:0000I8][Clan](by-file/Clan.md) : reconstructable : 90% : strong : NexusTK/social/Clan.cpp module map includes the non-emitting UID00010G row-helper split index, three source-emitting ClanStatusPane row methods, compiler-only switch/alignment spans, exact status/manage/action relationships, and the existing clan pane/dialog/list/packet/global/vtable families; broader file confidence remains unchanged.

No tracker row should be manually edited by B004. The supervisor-owned tracker
must derive the real report/count state from validator/lifecycle processing.

## Follow-Up Actions

- The accepted implementation scope is complete: UID00010G, children
  UID0004Q5/UID0004Q6/UID0004Q7, UID00002K, UID00010C, UID00010H, UID00021N,
  UID0000I8, `by-memory/-ignored.md`, and this report.
- RectBounds/GrafPort/parser/constructor/vtable/global/child-view destinations
  are verify-only unless reread reveals a direct contradiction requiring
  supervisor notice before scope expansion.
- Child registration was serial and every placeholder was replaced after its
  real UID became known.
- Manual coverage text above remains supervisor-owned and uses the real UIDs.
- No implementation item remains outstanding in this artifact.
- Report validation, implementation authorization, execution, count, path,
  movement, and archive state remain external supervisor/validator-owned and
  are not tracked as pending work by this artifact.

## Confidence

- Split/ranges/tables/padding: `0.99`.
- ClanStatusPane ownership and Clan.cpp placement: `0.98`.
- RectBounds, void GetRect, y/x HitTest ABI: `0.97`.
- Draw/geometry/action behavior: `0.97`.
- Human source call from HitTest to GetRect with compiler inlining: `0.91`.
- Selected method names: `0.90`.
- Descriptive row/view enum names: `0.84` for spelling, `0.98` for numeric
  meaning.
- Private access: `0.82`; behavior and ABI are unaffected if original access
  differed.

Overall recommendation confidence is `0.94`, matching parent confidence 94.

## Validator Results

All commands ran from `source-3/project-documentation`; all exited `0`. Child
registration and ordinary edit commands used `--no-generated-refresh`; the
last target command used the authorized `--wait-generated` refresh.

| Command | Timestamp | Final scoped path | Result / relevant side effects |
| --- | --- | --- | --- |
| `000000012129` | `2026-07-14T19:53:10-04:00` | `by-memory/0x00486800-0x00486cde.ClanStatusPaneDrawStatusRowText.md` | Registration succeeded (registration mode has no `ok` counter); assigned UID0004Q5, inserted path/metadata/references; generated refresh skipped. |
| `000000012130` | `2026-07-14T19:54:23-04:00` | `by-memory/0x00486d20-0x00486f3f.ClanStatusPaneGetStatusRowRect.md` | Registration succeeded; assigned UID0004Q6, inserted path/metadata/references; generated refresh skipped. |
| `000000012131` | `2026-07-14T19:55:31-04:00` | `by-memory/0x00486f90-0x00487291.ClanStatusPaneHitTestStatusRow.md` | Registration succeeded; assigned UID0004Q7, inserted path/metadata/references; generated refresh skipped. |
| `000000012133` | `2026-07-14T19:57:05-04:00` | `by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md` | `ok:1`; parent metadata/reference/stats synchronization; generated refresh skipped. |
| `000000012134` | `2026-07-14T19:58:37-04:00` | `by-class/ClanStatusPane.md` | `ok:1`; 17 pre-existing `missing_ref_uid` warnings for UID0003B8 and UID000411/000412/000413; generated refresh skipped. |
| `000000012136` | `2026-07-14T19:59:36-04:00` | `by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md` | `ok:1`; three pre-existing UID0003B8 missing-reference warnings; generated refresh skipped. |
| `000000012138` | `2026-07-14T20:00:19-04:00` | `by-memory/0x00487600-0x0048779f.ClanStatusRowActionPacket.md` | `ok:1`; no target warning; generated refresh skipped. |
| `000000012140` | `2026-07-14T20:01:20-04:00` | `by-memory/0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper.md` | `ok:1`; no target warning; generated refresh skipped. |
| `000000012142` | `2026-07-14T20:03:25-04:00` | `by-file/Clan.md` | `ok:1`; added three child reference-index entries; 13 pre-existing missing references involving UID000411/000412/000413/0003B8; generated refresh skipped. |
| `000000012144` | `2026-07-14T20:04:38-04:00` | `by-memory/-ignored.md` | `ok:1`; inserted target links and three child reference-index entries; 293 broad pre-existing ignored-page missing-reference warnings; generated refresh skipped. |
| `000000012145` | `2026-07-14T20:04:50-04:00` | `by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md` | `ok:1`; waited generated refresh completed at the same command/timestamp; `Clan.cpp` updated. Global generator warnings (`children_fallback_insert:14`, `children_marker_missing:86`, `emitter_has_no_code:176`) are unrelated inventory diagnostics. |

Read-only generated proof for
`auto-generated/NexusTK/social/Clan.cpp`, SHA256
`6BAF5AF9444433DBBFE943293A749069C0278F2322A09BBF94CE785A0CE4ED34`:

- Header command/timestamp exactly `000000012145` / `2026-07-14T20:04:50-04:00`.
- UID and exact definition counts are one each for UID0004Q5
  `DrawStatusRowText(short)`, UID0004Q6
  `GetStatusRowRect(short, RectBounds *)`, and UID0004Q7
  `HitTestStatusRow(int y, int x)`.
- UID00010G count is zero; UID00010G Empty Emitter Marker count is zero.
- `jpt_486`, `0x00486ce0`, `0x00486f40`, and `0x00487294` counts are zero, so
  no handwritten table/padding/cookie body was emitted.
- `ClanStatusPane` closes at generated line 538, before the first new child
  definition at line 820; the other definitions begin at lines 889 and 982.
- The hit-test body contains one source call to `GetStatusRowRect`; no duplicate
  geometry definition or duplicate child UID is present. Existing unrelated
  UID0003B9/UID0003HE empty markers remain outside this target.

## Changed Files

Created and registered ordinary pages:

- `3CDADC2CEB6BCFB252734738F6A9F89EDA1EC05F6783E4B40FCD605EEC9CDE7C` - `by-memory/0x00486800-0x00486cde.ClanStatusPaneDrawStatusRowText.md` (UID0004Q5).
- `E80A6F3269AB5008835729B87E8C1D2D79775629CB0BCC4701FEF5F7B98106BB` - `by-memory/0x00486d20-0x00486f3f.ClanStatusPaneGetStatusRowRect.md` (UID0004Q6).
- `994CC2981B1C701082D4584500197260AE59F201C1D7316F798E8C1301502A70` - `by-memory/0x00486f90-0x00487291.ClanStatusPaneHitTestStatusRow.md` (UID0004Q7).

Modified ordinary pages, with final SHA256:

- `AB234EFB2D716A144F79EB834F652C33EEC3B223EDC7FF699EAD3D12377801F5` - `by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md`.
- `7B592E09B268877738B3BA083519AA50619584D11E3C92ADB7843C4EC2854C81` - `by-class/ClanStatusPane.md`.
- `2DDA455FC3F95C6C3C328490215B6B7153A99F2286B6F12D03E09EBA14B3F5BA` - `by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md`.
- `4385F71079CE34678844D6EB988B57169F26FF9A7593A3B46A612DA5C735B6D9` - `by-memory/0x00487600-0x0048779f.ClanStatusRowActionPacket.md`.
- `2C782E06F655E91EF62DF1DB7BEDD990AA277AFFFDAD0F45A71D4D90CB734AA6` - `by-memory/0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper.md`.
- `DFA8FF4121EF194E07F66C093DE784B7291424CE47AA488073A4569D2074DF31` - `by-file/Clan.md`.
- `8FDAD2AF934A8510F3FEA497228CB6D0E23B91DC547E31C27807D6291F3AB5C9` - `by-memory/-ignored.md`.

This same report was updated in place after implementation. The generated
`Clan.cpp` change was validator-owned and read-only to B004. Manual coverage,
tracker, audit/supervisor, validator state, lifecycle/archive, and IDA files
were not manually edited. Verify-only RectBounds/GrafPort/parser/constructor/
global/vtable/child-view support pages were not edited. One ordinary file was
leased at a time, each lease was released immediately after its validation
window, and no B004 lease remains. No report lifecycle command ran.

Exact lease closure inventory:

| Leased path | Immediate purpose | Closure |
| --- | --- | --- |
| `by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md` | Four separate short windows: serial UID0004Q5/0004Q6/0004Q7 creation-registration and the later parent edit | Released after each registration/validation window and after parent command `12133`; not held during other edits or final generated wait. |
| `by-class/ClanStatusPane.md` | Class block/detail edit and `12134` | Released immediately after validation. |
| `by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md` | Caller synchronization and `12136` | Released immediately after validation. |
| `by-memory/0x00487600-0x0048779f.ClanStatusRowActionPacket.md` | Action cross-link synchronization and `12138` | Released immediately after validation. |
| `by-memory/0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper.md` | Nesting/cross-link synchronization and `12140` | Released immediately after validation. |
| `by-file/Clan.md` | File inventory/source-route synchronization and `12142` | Released immediately after validation. |
| `by-memory/-ignored.md` | Eight compiler-span entries and `12144` | Released immediately after validation. |

The three new child paths did not exist before their registration and therefore
could not be leased directly; each was created and scoped-validated inside its
corresponding short parent split lease, as required by the workflow.

## Implementation Tracking Checklist

### Report-only review phase

- [x] The exact Gate-1-passed revision independently established the MCP
  evidence and all three function boundaries; this evidence remains intact.
- [x] Exact compiler table/padding ranges, xrefs, hashes, and ignored
  dispositions remain intact and are now incorporated.
- [x] The accepted false/non-emitting parent decision and `92/94` score are
  current destination truth.
- [x] The three accepted child paths, ranges, scores, owner/emitter metadata,
  and relative nesting are current destination truth under real UIDs.
- [x] `RectBounds` is reused and no new row rectangle type was created.
- [x] Signed-short row ABI, void GetRect, and y-first/x-second hit-test order are
  preserved in declarations, formal bodies, and caller prose.
- [x] All row/view enum values remain descriptive and inferred-spelling status
  remains explicit.
- [x] Every exact rectangle is retained, including status top 156 and
  management top 157 cases.
- [x] Draw text fields, 40-wide-character stride, baselines, center x 94, and
  selected x/y offset 2 remain in the child evidence/formal body.
- [x] Row 2-13 subtype 1-12 mapping and absence of a subtype-13 row are
  preserved.
- [x] View/version/tab gates and current field names are synchronized.
- [x] The HitTest-to-GetRect human-source call and compiler-inlining decision
  are preserved separately.
- [x] All five complete managed destinations are retained exactly; no draft
  C++ exists outside managed blocks.
- [x] The class closes before `[[CHILDREN]]` and all unrelated existing
  declarations remain present.
- [x] Target/support score changes and verify-only bounds match the accepted
  report.
- [x] Old reports remain dated historical leads rather than current authority.
- [x] Negative, rejected, and historical evidence remains at report-level
  detail.
- [x] Manual coverage text now contains real UIDs; its pre-registration origin
  remains historicalized and the rows remain supervisor-owned.
- [x] C01-C46 remain claim-complete and now use legal callback terminal states.
- [x] B004's implementation/validation boundary and external report lifecycle
  ownership are stated without asserting a lifecycle outcome.

### Implementation callback phase

- [x] Reread every authorized destination and shared lease report immediately
  before editing; preserved concurrent/unrelated content.
- [x] Leased UID00010G only for each immediate child-registration or bounded
  parent edit window and released it after validation.
- [x] Created/registered DrawStatusRowText first as UID0004Q5 with command
  `000000012129`, then installed its real UID before dependent edits.
- [x] Scoped-validated the Draw registration and released the parent lease
  immediately; parent reclassification later passed `000000012133`.
- [x] Created/registered GetStatusRowRect second as UID0004Q6 with command
  `000000012130`, then installed its real UID.
- [x] Scoped-validated the GetRect registration and released the immediate
  parent lease.
- [x] Created/registered HitTestStatusRow third as UID0004Q7 with command
  `000000012131`, then installed its real UID.
- [x] Confirmed no temporary registration token remains in the report or
  changed ordinary destinations.
- [x] Applied parent `92/94`, false, blank emitter/position/formal, owner
  `00002K`, Nested 0, complete summary/evidence/cross-links.
- [x] Applied UID0004Q5 `91/93`, owner/emitter `00002K`, true, blank position,
  Nested +4, complete summary/evidence/formal block.
- [x] Applied UID0004Q6 `92/94`, owner/emitter `00002K`, true, blank position,
  Nested 0, complete summary/evidence/formal block.
- [x] Applied UID0004Q7 `91/93`, owner/emitter `00002K`, true, blank position,
  Nested 0, complete summary/evidence/formal block.
- [x] Rebased/applied the complete UID00002K class block at `89/91` without
  erasing existing declarations or evidence.
- [x] Updated UID00010C to `88/91`, real child links, and y/x semantics while
  preserving its aggregate body and unrelated details.
- [x] Updated UID00010H cross-links while preserving `88/91`, numeric formal
  body, packet facts, boundaries, and siblings.
- [x] Updated UID00021N links and `Nested:-4` while preserving `88/91`, formal
  body, range, and unrelated evidence.
- [x] Updated UID0000I8 inventory/source detail while preserving `90/85`, path,
  unrelated Clan families, and formal content.
- [x] Added five internal ignored spans and rebased three successor spans with
  real child UIDs, exact hashes/xrefs, and no source emission.
- [x] Preserved predecessor/successor relationships and all verify-only support
  pages; no contradiction required scope expansion.
- [x] Ran one scoped validator for every changed ordinary page and recorded all
  command IDs, timestamps, exits, ok counts, warnings, and side effects.
- [x] Released every one-file lease immediately after its validation window;
  current shared lease readback has no B004 row.
- [x] Ran final waited refresh `000000012145`; generated header freshness is
  exact.
- [x] Verified one definition per real child, zero UID00010G entry/target empty
  marker, zero handwritten compiler span, no duplicate geometry definition,
  class closure before children, and preserved unrelated output.
- [x] Updated C01-C46 to legal terminal states with claim-level destination and
  validator proof.
- [x] Updated Current Target State, Final Recommendation, Validator Results,
  Changed Files, score table, real UID map, and this checklist to durable
  archive-neutral post-callback truth.
- [x] Did not manually edit manual coverage/generated/tracker/audit/supervisor/
  validator-state/lifecycle/IDA files and did not run `execute_report` or any
  report lifecycle command.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000012180","destination_path":"executed-b-agent-research/B004/00010G-ClanStatusPaneRows-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00010G-ClanStatusPaneRows-source-quality.md","timestamp":"2026-07-14T20:22:28-04:00","uid":"00010G"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
