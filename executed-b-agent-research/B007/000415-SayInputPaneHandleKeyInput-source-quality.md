** TARGET-REPORT-UID:000415 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID000415 SayInputPane Handle Key Or Text Event Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: reconstruct `0x005b3570-0x005b3670` as `bool SayInputPane::HandleKeyOrTextEvent(Event *event)` in `NexusTK/social/SayInputPanes.cpp`.
- Final disposition: retain [UID:0000C3] `SayInputPane` as canonical owner/emitter, retain [UID:0000N9] `SayInputPanes` as source-file owner, retain `RECONSTRUCTABLE:TRUE`, replace the stale draft with the exact formal CPP body below, and keep this by-memory target's formal H block blank because the declaration belongs on the class page.
- Ordinary implementation status: the accepted Event layout, adjusted-receiver offsets, `UserPane` history-helper ownership, `g_pUserPane` dependency, inherited `TextEditPane` calls, base-forwarding contract, source-facing names, historical corrections, scores, and formal blocks are incorporated in the ten authorized ordinary destinations and physically re-read. Supervisor Gate 2B catalog entry `0372` applies and verifies A415-01 through A415-05; the supervisor's final reaffirmation readback and required save preserve that exact state, including the physical-frame label exception, in current saved IDB `D7D29DEB...08CCA`. Current generated reconstruction topology is verified from command `000000019926`; current moving tracker state was read from command `000000019933`, while commands `000000019928`, `000000019891`, `000000019890`, and `000000019887` are dated history. The five manual coverage operations are supervisor-applied and validated by commands `000000019980` through `000000019982`; fresh final exact-artifact gates remain supervisor-owned.
- Confidence: very strong for behavior, signature, field widths/offsets, owner/emitter route, range, vtable dispatch, helper ownership, and formal source shape; inferred but high-probability for the original lexical spellings of the three `UserPane` history methods.
- The authoritative report execution/archive state is determined only by the artifact's current path and validator-owned status/history metadata, not by lifecycle prose in this report body.

## Supporting Research

- Fresh live read-only evidence used IDA MCP database `1da2b2ae` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Fresh `server_health` returned `status:ok`, `auto_analysis_ready:false`, `hexrays_ready:true`, `strings_cache_ready:true`, and `strings_cache_size:2068`; bounded IDB-backed queries succeeded, so the documented false auto-analysis flag is context rather than MCP unavailability.
- Current authoritative physical IDB: SHA256 `D7D29DEB8CDA07A6693B36BEF32A544ABD1921D3A0C9B306A47DFCC350D08CCA`, `143194156` bytes, saved `2026-07-30T15:35:19.0223971Z`, active database `1da2b2ae`.
- Gate 2B transaction evidence: historical catalog entry `0372` recorded `APPLIED_VERIFIED_RECONCILIATION_REQUIRED_FOR_SAVED_STATE`; byte-identical prestate backup `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B007-UID000415-20260730_091137.i64`; transaction prestate and backup SHA256 `D65C96CEE79AB084596B633491F2A6AF57AC18B1CB966F86D6DD9088988F2D11`, `143193979` bytes; supervisor `idb_save` result `ok:true`; transaction save checkpoint SHA256 `2CCA289FBF2BA0D2CEEF5F870AF560AD3BA6025109FB47A4D66E154F70D7E851`, `143192020` bytes, saved `2026-07-30T09:23:53.4855352-04:00`. The supervisor's final Gate 2 verification entry closes that report-reconciliation requirement: reaffirmation used byte-identical backup `E:\NTK\Resources\NexusTK\NexusTK.exe.uid000415-gate2b-20260730-113455.i64`, SHA256 `3892BDA899A18612985539399C9AC1C97B5AE6F7F9FD5D1DF2859C96472798D1`, `143194020` bytes; no additional semantic mutation was needed, and required `idb_save` returned `ok:true` before producing current authority `D7D29DEB...08CCA`. Shared-IDB identities `3892BDA8...98D1`, `4EDEC155...5D09F`, `83C20CE9...C294A9E`, `87D34CCD...6F500F2`, `A4A6BC82...DAC02C4`, and `64704F81...E54642` are dated historical checkpoints only.
- Supervisor final Gate 2 readback against current `D7D29DEB...08CCA` found no UID000415 target/dependency drift from catalog0372. UID000415 remains `SayInputPane__HandleKeyOrTextEvent`, size `0x100`, with exact accepted `bool __thiscall(void *eventHandlerFacet, Event *event)` prototype and function comment; helpers remain `UserPane__GetPreviousChatHistoryLine` size `0x5b`, `UserPane__GetNextChatHistoryLine` size `0x4b`, and `UserPane__SaveChatHistoryLine` size `0xbc`, with exact accepted source-facing prototypes/comments. Target/helper frames retain `event +0x214 Event *`, `historyCursor +0xc __int16 *`, physical `Destination +0x10` / `SizeInWords +0x14`, and `text +0x18 const wchar_t *`; action comment channels, the `0x005b35dc` clear, first-item classifications, bytes, and xref counts remain exact. The base and submit siblings remain protected `sub_4F25A0` size `0x1b4` and `sub_5B3670` size `0x17a`; global `0x0067a748` remains `g_pUserPane : UserPane *`; protected constructor, EventMan, TextEditPane, vtable, and padding state remains unchanged.
- The two history-helper prototypes and decompiler use `historyCursor`, `destination`, and `destinationCount`, while the physical IDA frame deliberately retains argument-member labels `Destination` and `SizeInWords` at `+0x10/+0x14`. Bounded stack-member rename dry-run and apply both returned `Argument member` and made no change; this is a verified presentation limitation, not a type or source-contract ambiguity.
- B008's UID000414 constructor work was checked only as support. Its supervisor Gate 2B save introduced the current incomplete/no-layout `SayInputPane` type and the exact protected `SayInputPane__ConstructorWithInitialText` identity; this report does not claim UID000414 or broaden its declared target scope.
- Existing UID000415 evidence from sessions `b880584f` and `ff68e691` is retained as historical corroboration. Current IDA facts and current documentation were re-read rather than copied forward.
- Generated commands `000000019802`, `000000019812`, `000000019887`, and `000000019890` are dated historical checkpoints; tracker-only commands `000000019891` and `000000019928` are also historical. Current reconstruction-state CPP/H and generated-memory authority is command `000000019926` at `2026-07-30T10:34:57-04:00`. Current moving validator-owned tracker identity is command `000000019933` at `2026-07-30T11:03:10-04:00`. Exact current identities and unchanged target topology are recorded below without treating tracker path/count state as durable lifecycle truth.

## Target

- Target UID: `000415`.
- Additional target UIDs: none.
- Declared-target inventory: [UID:000415] `by-memory/0x005b3570-0x005b3670.SayInputPaneHandleKeyInput.md`, exact source-bearing virtual method child.
- Target path: `by-memory/0x005b3570-0x005b3670.SayInputPaneHandleKeyInput.md`.
- Assignment-time/historical queue row at dated tracker checkpoint command `000000019812`: `auto-generated/-ag-research-tracker.md` by-memory `Not-Covered Files - Reconstructable`, `87/89`, reconstructable true, zero direct/additional/total reports. This is not asserted as current tracker state.
- Current supervisor classification: reconstructable exact by-memory method target with ordinary implementation, generated CPP/H closure, catalog-`0372` Gate 2B actions verified and reaffirmed, and all five manual-coverage operations supervisor-applied and validated; fresh final gates and lifecycle authority remain separate.
- Current ordinary state after accepted callback: target `94/95`, `CANONICAL_OWNER:0000C3`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000C3`; class [UID:0000C3] `93/94`; aggregate [UID:0001MB] `89/93`; file [UID:0000N9] `89/90`.

## Current Target State

- Target metadata is now `94/95` with owner/emitter [UID:0000C3], reconstructable true, position blank, `Nested:0`, and the exact Item Summary. Range and routing metadata did not change.
- Target CPP now contains the exact Event-based body from this report. Formal H remains correctly blank because [UID:0000C3] owns the declaration.
- Current ordinary prose preserves the exact `0x100` range, vtable-only dispatch, adjusted receiver, history cursor, edit child, padding fences, base fallback, Event payload/modifier semantics, UserPane helper ownership, and all superseded assumptions as explicit history.
- The class H declares `HandleKeyOrTextEvent(Event *)`; its CPP remains `[[CHILDREN]]`. The aggregate remains blank/non-emitting. UserPane declares the three history members and only `+0x13eb04` is `List *m_chatHistory`.
- `0x0067a748` is documented consistently as canonical `g_pUserPane : UserPane *` under stable historical paths; UID000416 now calls `g_pUserPane->SaveChatHistoryLine(wideText)` and the base handler is documented as `LineInputPane::HandleKeyOrTextEvent(Event *)` without changing its body.
- Current supervisor/validator-owned generated checkpoint command `000000019926`, timestamp `2026-07-30T10:34:57-04:00`, reads back UID000414 constructor `92/94`; UID000415 exact `HandleKeyOrTextEvent(Event *)` `94/95` with `g_pUserPane` previous/next calls; UID000416 with the current `g_pUserPane->SaveChatHistoryLine(wideText)` source call; no `PaneKeyEvent`; and UID0001MB as an `89/93` empty emitter marker. Commands `000000019890` and `000000019887` are dated checkpoints with the same accepted target-family topology.
- Current report lifecycle authority is external to this body and must be read from the report path plus validator-owned status/history metadata.

## Executive Recommendation

- Rename the source method to the inherited virtual spelling `SayInputPane::HandleKeyOrTextEvent(Event *event)`.
- Catalog `0372` now expresses the EventHandler-secondary-facet ABI in IDA as `void *eventHandlerFacet`; emitted C++ remains a normal member method so the compiler regenerates the `+0xa0` receiver adjustment.
- Catalog `0372` now records the three source-facing UserPane helper identities and prototypes in IDA; ordinary source uses `g_pUserPane->GetPreviousChatHistoryLine`, `GetNextChatHistoryLine`, and `SaveChatHistoryLine`.
- Rename the `UserPane+0x13eb04` source member from stale `m_whisperHistoryOther` to `m_chatHistory`; adjacent whisper-recipient history fields remain separate and unchanged.
- Replace the target draft with exact formal source that preserves translation-before-gating order, exact zero-modifier equality, Up/Down constants, bounded 256-wide-character history output, inherited edit replacement, handled-empty-history behavior, and base forwarding.
- No split, merge, reclassification, owner change, emitter change, or source-file move is warranted.

## Supervisor Active Recheck

- Supervisor accepted Gate 1 for exact pre-callback SHA `855632A934BF2D77D6006278B1BE6641AB21EEF116EDCE36212CEC36683A8CC5` and authorized the bounded ordinary-document callback. B007 changed only the ten authorized ordinary destinations and this same report.
- The exact child split is already correct. UID000415 begins at the modeled virtual body, excludes four leading `0xcc` bytes, and ends exactly at the next modeled sibling method.
- The target contains one source-bearing method, not a mixed aggregate. No new child is needed.
- Every named score blocker was actively checked: method signature, Event layout, secondary receiver, history cursor, edit child, three helper roles/types, global dependency, vtable route, callers, fences, owner/source placement, and source-level CPP/H.
- UID000414 remains B008-owned support. Its applied constructor/type state is a protected prerequisite for this report, and no claim or change here takes over that target. After B008's active LineInputPane callback released its lease, `by-class/LineInputPane.md` was re-read twice without drift at SHA256 `5C2B543E38E1A76FAAAD0A67546320D7D4ECA5C3660AB4B1EBE892F6509BD1E5`, `19245` bytes/`155` lines. Its current formal H still contains `class Event;` and `virtual bool HandleKeyOrTextEvent(Event *event);`, so C415-048 remains satisfied and no B007 edit, lease, or validator was required for that file.
- The same sustained post-B008 no-lease window advanced three other UID000415 support identities without invalidating this report's claims: `by-class/UserPane.md` is now SHA256 `DB7867530A0DC231BC7DB350BD079858BBF88CEF8C90A2E35556DDA8AED97578`, `105930` bytes/`768` lines; `by-file/UserPane.md` is now SHA256 `54A260E46F9E452904B6D9E6ED01DF5D0656435DF333C2C1172300BBA1C7781B`, `118431` bytes/`491` lines; and `by-memory/0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md` is now SHA256 `E63A912FBE7EDC7DC65BB5658D51BDBD1381D9C4CA0D11F3F1CCBEC778CB5A3E`, `7566` bytes/`68` lines. Read-only content checks reconfirm the three UserPane history declarations, `List *m_chatHistory` at `+0x13eb04`, UserPane.cpp ownership/behavior, and the exact derived-to-base `HandleKeyOrTextEvent(Event *)` contract. The seven other ordinary destinations retain the B007 post-validator identities recorded below.

## Inference Research Guidance Check

- IDA facts, documentation evidence, and source inference are separated throughout this report.
- Existing labels and older drafts were treated as hypotheses. In particular, `PaneKeyEvent`, `imeActive`, `NarrowInputEventByte`, `g_pCollectionData`, and free history helpers were not retained merely because they were already documented.
- The evidence ladder starts with exact bytes/ranges/xrefs/decompilation, then current UDT/layout data and sibling callers, then source-tree/class conventions, and only then lexical inference.
- Inference is required for stripped original method spellings. The best human source names are selected from behavior and the existing project convention; raw `sub_`, `dword_`, `a2`, and offset expressions must not survive final source.
- Wave2/Wave3 references in older material were ignored as stale and were not used as authority.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis and evidence | Resolution |
| --- | --- | --- |
| Virtual method name | The same inherited slot family is documented across `LineInputPane` and `UserPane` as `HandleKeyOrTextEvent(Event *)`; the target handles both translated key identity and Event metadata, then forwards to the base slot. | `SayInputPane::HandleKeyOrTextEvent(Event *event)`, high-probability inferred spelling. |
| Raw receiver type | Binary receiver is the EventHandler secondary facet at complete `SayInputPane+0xa0`; direct use of a complete `SayInputPane *` in the raw IDA prototype would misstate the ABI. | IDA uses `void *eventHandlerFacet`; source emits a normal class member and no manual pointer subtraction. |
| Event type/layout | Current `Event` UDT is `0x110`; `m_type+0x4`, `m_payload+0x8`, key `m_key+0x0`, wide text `+0x2`, modifiers `+0x102` within payload, making complete `event+0x10a`. | Replace `PaneKeyEvent`, `eventKind`, and `imeActive` with `Event`, `m_type`, and `m_payload.m_key.m_modifiers`. |
| Key translation | Live target calls `EventMan__TranslateEventKey(g_pEventMan, event key, modifiers)` before checking the Event kind/modifiers. | Use `g_pEventMan->TranslateEventKey(...)`; do not use invented `NarrowInputEventByte`. |
| Key constants | Current Event family defines `kPaneKeyUp=0x81`, `kPaneKeyDown=0x83`, and `kEventKeyDown=8`. | Use named constants, preserving exact values and branch order. |
| Cursor field | Raw secondary `this+0x68` maps to complete object `+0x108`; constructors initialize signed short `-1`, helpers read/write 16 bits. | `short m_chatHistoryCursor`, already correctly represented in SayInputPane H. |
| Edit child | Raw secondary `this+0x5c` maps to complete object `+0xfc`; typed dependency is `TextEditPane *`. | `m_textEditPane`; use public `SetSelectionRange` and `InsertTextRange`. |
| Global identity | `0x0067a748` is currently named `g_pUserPane` and typed `UserPane *`; helper bodies index UserPane's large complete layout. | Use `g_pUserPane`; preserve stable legacy documentation paths while correcting current source identity in their content. |
| History storage | All three helpers use the same `List *` at `UserPane+0x13eb04`; two retrieval helpers and one save helper share SayInputPane/ChatInputPane callers. | Rename source member `m_whisperHistoryOther` to `m_chatHistory`; do not merge adjacent recipient-history fields. |
| Previous helper | Count check, `-1` sentinel, wraparound `(count+cursor-1)%count`, List element fetch, cursor store, bounded `wcscpy_s`. | `UserPane::GetPreviousChatHistoryLine(short *, wchar_t *, rsize_t)`. |
| Next helper | Count check, wraparound `(count+cursor+1)%count`, List fetch, cursor store, bounded copy. | `UserPane::GetNextChatHistoryLine(short *, wchar_t *, rsize_t)`. |
| Save helper | Deduplicates matching text, removes oldest when count is already ten, then appends a new string. | `UserPane::SaveChatHistoryLine(const wchar_t *)`; source return type `void` despite residual EAX from final List insertion. |
| Buffer initialization | Binary allocates `wchar_t[256]` without explicit zero fill; each retrieval helper writes either an empty terminator or a copied line. | Remove stale `{}` initialization so source shape matches behavior and generated code more closely. |
| Insert contract | Current typed callee is `TextEditPane::InsertTextRange(const wchar_t *, short, const unsigned short *, TextEditObject *)`. | Use signed-short length and `NULL` optional pointers; reject stale `InsertText(..., int, 0, 0)`. |
| Selection contract | Current source docs expose `SetSelectionRange(short, short)`. | Replace stale `SelectText` with two exact `SetSelectionRange(0, 0x7fff)` calls. |
| Owner/source route | Vtable cell belongs to SayInputPane; method uses SayInputPane cursor and inherited edit child; source tree already places family under social/SayInputPanes. | Keep class owner UID0000C3 and file UID0000N9. |
| Range/split | One modeled function `[0x5b3570,0x5b3670)` with explicit preceding padding and next-method boundary. | Keep exact child; no split/merge. |

Rejected alternatives:

- `HandleKeyInput(PaneKeyEvent *)`: superseded by the current Event hierarchy and inherited virtual naming.
- IME/composition interpretation for `event+0x10a`: contradicted by current `EventKeyPayload::m_modifiers` layout and use as the second key-translation argument.
- `g_pCollectionData` or a free history-manager object: contradicted by current global type, `UserPane` lifetime identity, and helper access to `UserPane+0x13eb04`.
- `Chatting`, `ChatInputPane`, or `LineInputPane` ownership: similar consumers/base behavior do not override the SayInputPane vtable cell and receiver-specific cursor.
- `GetPreviousChatHistoryEntry`/`GetNextChatHistoryEntry`: plausible, but `Line` matches the wide-string copy API and current project naming; it remains descriptive rather than original-symbol proof.
- Rebuilding the entire 1.3 MB `UserPane` UDT in Gate 2B: unnecessary and unsafe for this target; the accepted function prototypes can use the existing incomplete/current pointer type.

No source-quality blocker remains deferred. Only original lexical proof is unavailable, and the report supplies the highest-probability human-written form rather than preserving IDA labels.

## Evidence Standards Used

- Direct evidence: live IDA function bounds, instruction count, block count, decompilation, disassembly, stack frame, bytes, vtable data xref, callee set, UDT/type inspection, global identity, helper caller sets, and collision queries.
- Documentation evidence: current target/class/file/aggregate/sibling/global/UserPane/Event/LineInputPane/TextEditPane documents and current formal blocks.
- Generated evidence: current reconstruction-state command `000000019926` SayInputPanes CPP/H, InputPanes H, and generated memory coverage. Moving validator-owned research-tracker identity advanced independently to command `000000019933`; command `000000019928` and commands `000000019890`, `000000019891`, `000000019887`, `000000019802`, and `000000019812` are explicitly historical checkpoints.
- Manual evidence: current by-memory/by-class/by-file coverage rows, including the supervisor-applied target/child insertions and no-loss aggregate/class/file replacements.
- Negative evidence: zero direct code callers to the target, no second target pointer beyond its vtable cell, no mixed range, no distinct history object, no complete SayInputPane layout beyond the current incomplete type, and no evidence supporting the IME/free-helper draft.
- The binary context is sufficiently complete to reproduce behavior exactly. Missing original symbols affect spelling confidence but do not justify decompiler-shaped source.

## Evidence Checked

- IDA MCP: `idb_list`, `server_health`, target/helper function lookup and profiles, decompile/disassembly, xrefs, bytes, frame/locals, type/UDT inspection, global entity readback, function/comment readback, and name-collision queries.
- Target and support docs: UID000415, UID0000C3, UID0000N9, UID0001MB, UID000416, UID0000FQ, UID0000P1, UID0000QK, UID0001OR, UID00035Y, UID000077, Event/EventMan, and TextEditPane support.
- Generated docs: `auto-generated/NexusTK/social/SayInputPanes.cpp`, `SayInputPanes.h`, `InputPanes.h`, and `auto-generated/-ag-research-tracker.md`.
- Manual rows: by-memory, by-class, by-file, and relevant global coverage reports.
- Negative checks: direct code xrefs, target VA pointer hits outside the vtable, helper caller sets, adjacent bytes/functions, alternative owner routes, and existing symbol collisions.
- All ten changed ordinary paths were validated serially across eleven invocations with `--apply --no-generated-refresh --queue-timeout 240`; command IDs, timestamps, warnings, side effects, and the one class-link repair/rerun are recorded below. B007 did not mutate/save IDA, edit manual coverage or generated files, or invoke a lifecycle command. Supervisor catalog0372 and the final Gate 2 reaffirmation supply the applied IDA transaction/readback/backup/save evidence. Supervisor commands `000000019980`, `000000019981`, and `000000019982` validated the applied by-memory/by-class/by-file manual coverage changes with generated refresh disabled. Commands `000000019887`, `000000019890`, `000000019891`, and tracker command `000000019928` are dated generated/tracker history; read-only currentness checks use reconstruction command `000000019926` and tracker command `000000019933` without running a B007 validator.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C415-001 | 000415 | Exact source range is `[0x005b3570,0x005b3670)`, size `0x100`. | certain | live function/boundary readback | `by-memory/0x005b3570-0x005b3670.SayInputPaneHandleKeyInput.md` / Covered Range | incorporate | applied |
| C415-002 | 000415 | `0x005b356c-0x005b3570` is four-byte `0xcc` leading alignment and excluded. | certain | bytes and preceding partition | target / Range analysis | incorporate | applied |
| C415-003 | 000415 | `0x005b3670` starts sibling submit method and is the exclusive target end. | certain | function lookup and sibling page | target / Range analysis | incorporate | applied |
| C415-004 | 000415 | Only inbound target route is vtable cell `0x0062fbb4`. | certain | xrefs/pointer search | target / Vtable evidence | incorporate | applied |
| C415-005 | 000415 | Zero direct code callers are expected virtual-dispatch evidence, not dead-code evidence. | very strong | xref filters plus vtable | target / Negative evidence | incorporate | applied |
| C415-006 | 000415 | Raw receiver is EventHandler facet at complete SayInputPane `+0xa0`. | very strong | constructor/vtable and adjusted offsets | target / ABI behavior | incorporate | applied |
| C415-007 | 000415 | Raw `this+0x68` maps to complete `m_chatHistoryCursor+0x108`. | certain | adjusted receiver and constructors | target / Field mapping | incorporate | applied |
| C415-008 | 000415 | Raw `this+0x5c` maps to complete inherited `m_textEditPane+0xfc`. | certain | adjusted receiver and typed calls | target / Field mapping | incorporate | applied |
| C415-009 | 000415 | Event type is `Event *`, not `PaneKeyEvent *`. | very strong | Event UDT and inherited slot | target / Signature | incorporate | applied |
| C415-010 | 000415 | `event+0x10a` is key modifiers, not IME/composition state. | certain | EventKeyPayload layout | target / Historical corrections | reject-stale | applied |
| C415-011 | 000415 | Key translation executes before event/modifier/key gating. | certain | decompile/disassembly order | target / Behavior | incorporate | applied |
| C415-012 | 000415 | Intercept gate is key-down Event, zero modifiers, Up or Down key. | certain | exact branches/constants | target / Behavior | incorporate | applied |
| C415-013 | 000415 | Source constants are `kEventKeyDown`, `kPaneKeyUp`, and `kPaneKeyDown`. | very strong | current Event declarations | target / Source names | incorporate | applied |
| C415-014 | 000415 | Up invokes previous shared chat-history lookup. | certain | branch and helper decompile | target / Behavior | incorporate | applied |
| C415-015 | 000415 | Down invokes next shared chat-history lookup. | certain | branch and helper decompile | target / Behavior | incorporate | applied |
| C415-016 | 000415 | Empty helper output skips edit replacement but still returns handled. | certain | target control flow | target / Behavior | incorporate | applied |
| C415-017 | 000415 | Nonempty output selects `0..0x7fff` before insertion. | certain | call arguments | target / Behavior | incorporate | applied |
| C415-018 | 000415 | Insert uses `InsertTextRange`, signed-short length, and null format/object pointers. | certain | typed callee and call arguments | target / Behavior and CPP | incorporate | applied |
| C415-019 | 000415 | Target selects `0..0x7fff` again after insertion. | certain | call order | target / Behavior | incorporate | applied |
| C415-020 | 000415 | All unhandled events forward to `LineInputPane::HandleKeyOrTextEvent`. | very strong | final call and inherited slot | target / Behavior | incorporate | applied |
| C415-021 | 000415 | Best source method is `SayInputPane::HandleKeyOrTextEvent`. | very strong | slot convention and semantics | target / Source-Quality Names | incorporate | applied |
| C415-022 | 000415 | Canonical owner/emitter remains UID0000C3; reconstructable remains true. | certain | vtable/class route | target / metadata | already-present | already-present |
| C415-023 | 000415 | Source placement remains `NexusTK/social/SayInputPanes.cpp`. | very strong | class/file/source tree | target / Source Placement | already-present | already-present |
| C415-024 | 000415 | Replace stale formal CPP with the exact formal body in this report. | very strong | complete behavior reconstruction | target / RECONSTRUCTION_CPP | incorporate | applied |
| C415-025 | 000415 | Formal H remains blank because declaration is class-owned. | certain | emitter topology | target / RECONSTRUCTION_H | already-present | already-present |
| C415-026 | 000415 | Raise score `87/89 -> 94/95`; metadata route otherwise unchanged. | very strong | blocker closure | target / headers and Score Rationale | incorporate | applied |
| C415-027 | 000415 | Populate Item Summary with exact nonduplicative behavior/route summary. | very strong | generator contract | target / Item Summary | incorporate | applied |
| C415-028 | 000415 | Preserve old PaneKeyEvent/IME/free-helper draft as historical rejected provenance. | certain | current contradictions | target / Changes or Historical Assumptions | historicalize | applied |
| C415-029 | 0000C3 | Replace `PaneKeyEvent` declaration with `Event *` override declaration. | very strong | inherited slot and current Event UDT | `by-class/SayInputPane.md` / formal H | incorporate | applied |
| C415-030 | 0000C3 | Keep class CPP as `[[CHILDREN]]`; method body remains child-owned. | certain | emitter topology | `by-class/SayInputPane.md` / formal CPP | already-present | already-present |
| C415-031 | 0000C3 | Raise class score `88/90 -> 93/94`. | very strong | exact constructor/key/submit declarations | `by-class/SayInputPane.md` / headers and Score Rationale | incorporate | applied |
| C415-032 | 0000C3 | Correct method inventory and historicalize HandleKeyInput/IME/free-helper assumptions. | very strong | current target research | `by-class/SayInputPane.md` / Method Notes, Evidence, Changes | historicalize | applied |
| C415-033 | 0000N9 | Record exact Event override, UserPane history contract, and current child score. | very strong | target/support evidence | `by-file/SayInputPanes.md` / SayInputPane row and evidence | incorporate | applied |
| C415-034 | 0000N9 | Raise file score `88/87 -> 89/90`. | strong | improved exact family route | `by-file/SayInputPanes.md` / headers and Score Rationale | incorporate | applied |
| C415-035 | 0001MB | Keep aggregate blank and non-emitting over exact children. | certain | mixed-method cluster plus padding | `by-memory/0x005b34d0-0x005b37ea.SayInputPane.md` / aggregate policy | already-present | already-present |
| C415-036 | 0001MB | Correct UID000415 row, helper ownership, event layout, and current score. | very strong | current target/helper evidence | aggregate / child inventory and evidence | incorporate | applied |
| C415-037 | 0001MB | Raise aggregate score `87/90 -> 89/93` without adding CPP/H. | strong | all exact child routes now source-qualified | aggregate / metadata and Score Rationale | incorporate | applied |
| C415-038 | 0000FQ | Rename source field `m_whisperHistoryOther` at `+0x13eb04` to `m_chatHistory`. | very strong | three helper bodies/callers and current post-B008 no-loss readback | `by-class/UserPane.md` / formal H and layout evidence | incorporate | applied |
| C415-039 | 0000FQ | Add public previous-history helper declaration. | very strong | exact helper body/signature | `by-class/UserPane.md` / formal H | incorporate | applied |
| C415-040 | 0000FQ | Add public next-history helper declaration. | very strong | exact helper body/signature | `by-class/UserPane.md` / formal H | incorporate | applied |
| C415-041 | 0000FQ | Add public save-history helper declaration. | very strong | exact helper body/signature/callers | `by-class/UserPane.md` / formal H | incorporate | applied |
| C415-042 | 0000FQ | Preserve adjacent whisper-recipient history fields and complete layout unchanged. | certain | exact offset neighborhood | `by-class/UserPane.md` / layout/history | already-present | already-present |
| C415-043 | 0000P1 | Document the three shared chat-history helpers as UserPane.cpp members. | very strong | helper receiver/field offset and current post-B008 no-loss readback | `by-file/UserPane.md` / method inventory/source placement | incorporate | applied |
| C415-044 | 0000QK | Record canonical source identity `g_pUserPane` while retaining stable page path. | certain | current IDA global name/type | `by-global/g_pCollectionData.md` / current identity/history | incorporate | applied |
| C415-045 | 0001OR | Record canonical source identity `g_pUserPane` and history-helper consumers. | certain | current IDA global and xrefs | `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md` / current identity | incorporate | applied |
| C415-046 | 000416 | Replace stale free `SaveChatHistoryLine(g_pCollectionData, wideText)` with `g_pUserPane->SaveChatHistoryLine(wideText)`. | very strong | helper receiver/body and global type | `by-memory/0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat.md` / formal CPP and evidence | incorporate | applied |
| C415-047 | 00035Y | Record base source spelling `LineInputPane::HandleKeyOrTextEvent(Event *)`; preserve body/route. | very strong | inherited vtable slot plus current post-B008 handler/class readback | `by-memory/0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md` / source name/history | incorporate | applied |
| C415-048 | 000077 | Preserve existing Event-based LineInputPane declaration and edit-child contract. | certain | post-B008 stable readback SHA `5C2B543E...BD1E5`, `19245` bytes/`155` lines; formal H retains `class Event;` and `virtual bool HandleKeyOrTextEvent(Event *event);` | `by-class/LineInputPane.md` / formal H and method notes | already-present | already-present |
| C415-049 | 000415 | Supervisor Gate 2B applied and verified the target name, prototype, function comment, typed event frame member, and protected-state preservation. | very strong | catalog0372 transaction plus final supervisor reaffirmation/readback/save at current `D7D29DEB...08CCA`; `3892BDA8...98D1` is the byte-identical pre-reaffirmation backup | target / IDA section | incorporate | applied |
| C415-050 | 0000FQ | Supervisor Gate 2B applied and verified the previous-helper name, prototype, function comment, typed cursor, and bounded physical-frame label exception. | very strong | catalog0372 transaction plus final `D7D29DEB...08CCA` helper/decompiler/frame reaffirmation; physical `Destination`/`SizeInWords` labels preserved | `by-class/UserPane.md` / IDA evidence | incorporate | applied |
| C415-051 | 0000FQ | Supervisor Gate 2B applied and verified the next-helper name, prototype, function comment, typed cursor, and bounded physical-frame label exception. | very strong | catalog0372 transaction plus final `D7D29DEB...08CCA` helper/decompiler/frame reaffirmation; physical `Destination`/`SizeInWords` labels preserved | `by-class/UserPane.md` / IDA evidence | incorporate | applied |
| C415-052 | 0000FQ | Supervisor Gate 2B applied and verified the save-helper name, prototype, function comment, typed text frame member, and protected-state preservation. | very strong | catalog0372 transaction plus final `D7D29DEB...08CCA` helper/frame reaffirmation | `by-class/UserPane.md` / IDA evidence | incorporate | applied |
| C415-053 | 0000FQ | Do not rebuild or broadly rename the 1.3 MB UserPane UDT in this Gate 2B. | certain | bounded-action safety | report / IDA negative constraints | not-applicable | already-present |
| C415-054 | 0000C3 | Do not expand the current incomplete/no-layout SayInputPane type or use `SayInputPane *` for the secondary-facet receiver; raw target prototype uses `void *` facet. | certain | current incomplete type and ABI safety | report / IDA negative constraints | not-applicable | already-present |
| C415-055 | 000415 | Insert exact target manual by-memory coverage row. | certain | dated command `000000019980` application/validation, exit `0`, `ok:1`, generated refresh disabled; exact row survives unrelated B001 additions at current by-memory line `3955` | `by-memory/-coverage-report.md` after `0x005b356c-0x005b3570` padding row | incorporate | applied |
| C415-056 | 0001MB | Replace the former B008-updated `89%` aggregate row with the exact no-loss merged `89%` row below, preserving constructor evidence while adding the Event-history, submit, and blank-aggregate routing facts. | certain | dated command `000000019980` application/validation, exit `0`, `ok:1`, generated refresh disabled; exact merged row survives at current by-memory line `3952` | `by-memory/-coverage-report.md` UID0001MB row | incorporate | applied |
| C415-057 | 0000C3 | Replace the former B008-updated `93%` class row with the exact no-loss merged `93%` row below, preserving constructor/vtable evidence while adding the Event override, UserPane history, and child-only emission facts. | certain | dated command `000000019981` application/validation, exit `0`, `ok:1`, generated refresh disabled; exact merged row survives at current by-class line `459` | `by-class/-coverage-report.md` UID0000C3 row | incorporate | applied |
| C415-058 | 0000N9 | Replace the former B008-updated `89%` file row with the exact no-loss merged `89%` row below, preserving constructor/helper/split evidence while adding the exact Event-history and dependency route. | certain | dated command `000000019982` application/validation, exit `0`, `ok:1`, generated refresh disabled; exact merged row survives at current by-file line `234` | `by-file/-coverage-report.md` UID0000N9 row | incorporate | applied |
| C415-059 | 000416 | Insert exact submit-child manual by-memory row because the row was absent and the formal call changed. | certain | dated command `000000019980` application/validation, exit `0`, `ok:1`, generated refresh disabled; exact row survives unrelated B001 additions at current by-memory line `3956` | `by-memory/-coverage-report.md` after UID000415 | incorporate | applied |
| C415-060 | 000415 | Generated CPP contains the exact target method and no stale PaneKeyEvent/free-helper tokens. | very strong | current command000000019926 emitter topology readback; command000000019890 and earlier are dated matching history | `auto-generated/NexusTK/social/SayInputPanes.cpp` supervisor readback | incorporate | applied |
| C415-061 | 0000C3 | Generated SayInputPanes H declares the Event override and contains no PaneKeyEvent. | very strong | current command000000019926 class H readback; command000000019890 and earlier are dated matching history | `auto-generated/NexusTK/social/SayInputPanes.h` supervisor readback | incorporate | applied |
| C415-062 | 0001MB | Generated aggregate remains an `89/93` empty emitter marker with no duplicate method body. | certain | current command000000019926 aggregate no-code readback; command000000019890 and earlier are dated matching history | generated SayInputPanes CPP supervisor readback | already-present | already-present |
| C415-063 | 000415 | Scoped target validator is required with generated refresh disabled. | certain | validator workflow | target validator evidence | incorporate | applied |
| C415-064 | 0000C3 | Scoped class validator is required with generated refresh disabled. | certain | validator workflow | class validator evidence | incorporate | applied |
| C415-065 | 0000N9 | Scoped file validator is required with generated refresh disabled. | certain | validator workflow | file validator evidence | incorporate | applied |
| C415-066 | 0001MB | Scoped aggregate validator is required with generated refresh disabled. | certain | validator workflow | aggregate validator evidence | incorporate | applied |
| C415-067 | 0000FQ | Scoped UserPane class validator is required with generated refresh disabled. | certain | validator workflow | UserPane class validator evidence | incorporate | applied |
| C415-068 | 0000P1 | Scoped UserPane file validator is required with generated refresh disabled. | certain | validator workflow | UserPane file validator evidence | incorporate | applied |
| C415-069 | 0000QK | Scoped global alias validator is required with generated refresh disabled. | certain | validator workflow | global validator evidence | incorporate | applied |
| C415-070 | 0001OR | Scoped memory-global validator is required with generated refresh disabled. | certain | validator workflow | memory-global validator evidence | incorporate | applied |
| C415-071 | 000416 | Scoped submit sibling validator is required with generated refresh disabled. | certain | validator workflow | submit-child validator evidence | incorporate | applied |
| C415-072 | 00035Y | Scoped base-handler validator is required with generated refresh disabled if its prose is changed. | certain | validator workflow | base-child validator evidence | incorporate | applied |
| C415-073 | 000415 | Supervisor Gate 2B cleared the stale instruction regular comment `int` at `0x005b35dc` and preserved the one-byte item, repeatable channel, surrounding comments, bytes, and control flow. | certain | catalog0372 transaction plus final supervisor `D7D29DEB...08CCA` item/comment reaffirmation | target / IDA section | reject-stale | applied |

## Positive Evidence Summary

- The target is one exact modeled function with fixed fences, a unique SayInputPane vtable cell, and no competing range owner.
- Constructor evidence supplies the complete-object offset and signed-short `m_chatHistoryCursor` invariant.
- Current Event UDT data directly resolves every previously invented event field.
- The three helper bodies and their restricted caller sets resolve receiver, storage, capacity, cursor, deduplication, and maximum-history semantics.
- Current global typing resolves `dword_67A748` as `g_pUserPane`.
- Typed TextEditPane callees resolve the source APIs and argument widths.
- The inherited Event-based base slot resolves the method signature and fallback spelling.
- Together, these independent facts support exact runtime source and a plausible human-written source form without decompiler labels.

## IDA MCP Facts

- Gate 2B transaction: supervisor catalog entry `0372`, active database `1da2b2ae`, prestate/backup SHA256 `D65C96CEE79AB084596B633491F2A6AF57AC18B1CB966F86D6DD9088988F2D11`, backup `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B007-UID000415-20260730_091137.i64`, save result `ok:true`, transaction save checkpoint SHA256 `2CCA289FBF2BA0D2CEEF5F870AF560AD3BA6025109FB47A4D66E154F70D7E851`, `143192020` bytes, saved `2026-07-30T09:23:53.4855352-04:00`. The final supervisor Gate 2 reaffirmation used byte-identical backup `E:\NTK\Resources\NexusTK\NexusTK.exe.uid000415-gate2b-20260730-113455.i64`, SHA256 `3892BDA899A18612985539399C9AC1C97B5AE6F7F9FD5D1DF2859C96472798D1`, `143194020` bytes; all A415-01 through A415-05 and protected dependencies passed exact live readback, no additional semantic mutation was needed, and `idb_save` returned `ok:true`. Current shared saved IDB SHA256 is `D7D29DEB8CDA07A6693B36BEF32A544ABD1921D3A0C9B306A47DFCC350D08CCA`, `143194156` bytes, saved `2026-07-30T15:35:19.0223971Z`. `3892BDA8...98D1`, `4EDEC155...5D09F`, and all earlier identities are historical checkpoints only.
- Historical target prestate: `sub_5B3570`, declaration `char __thiscall(__int16 *this, _BYTE *)`, all four function-start comment channels absent, raw frame argument `arg_0 +0x214 _DWORD`, and Hex-Rays parameters `this:__int16 *`, `a2:_BYTE *`. The historical raw local/frame inventory remains `Destination +0x8 wchar_t` width 2, `var_4 +0x208 _DWORD`, saved `+0x20c _DWORD`, return `+0x210 _UNKNOWN *`; Hex-Rays reconstructed `Destination:wchar_t[256]`, `v3:unsigned char`, and `v5:__int16 *`, with local user comments absent.
- Current target readback: `SayInputPane__HandleKeyOrTextEvent`, `[0x005b3570,0x005b3670)`, size `0x100`, 81 instructions, 13 blocks, exact source-facing declaration `bool __thiscall SayInputPane__HandleKeyOrTextEvent(void *eventHandlerFacet, Event *event)`. Address-regular absent; address-repeatable absent; function-regular exactly `Handles unmodified Up/Down keys by replacing the edit control with previous/next local chat history; forwards all other events to LineInputPane.`; function-repeatable absent. Frame argument is now `event +0x214 Event *`; Hex-Rays presents typed `Event *event`, the named UserPane helpers, existing TextEditPane helpers, and the LineInputPane fallback. The raw `Destination` width-2 member and reconstructed `wchar_t[256]` local remain unchanged.
- Target first item remains `[0x005b3570,0x005b3571)`, one-byte code (`push ebp`); byte fingerprint remains SHA16 `77317c3876917ced`. The exact range/body bytes and one data xref `0x0062fbb4 -> 0x005b3570` remain unchanged; direct code callers remain zero.
- Target instruction regular comments remain literal at `0x005b358a="this"`, `0x005b3597="modifiers"`, `0x005b359c="key"`, `0x005b35ce="SizeInWords"`, `0x005b35db="Destination"`, `0x005b361b="textObject"`, `0x005b3627="formatPayload"`, `0x005b3629="length"`, `0x005b362a="this"`, `0x005b362d="text"`, `0x005b3649="StackCookie"`, and `0x005b3662="StackCookie"`; corresponding instruction-repeatable channels remain absent. Catalog0372 cleared only historical stale address-regular comment `int` at `0x005b35dc`; current address-regular and address-repeatable are absent, and `[0x005b35dc,0x005b35dd)` remains one-byte code with no name/type.
- Vtable base item `0x0062fbac-0x0062fbb0` remains named `??_7SayInputPane@@6B@_0`; target cell `0x0062fbb4-0x0062fbb8` remains unnamed/untyped with pointer bytes `70 35 5b 00` and all four comment channels absent. Leading `[0x005b356c,0x005b3570)` remains one four-byte `cc cc cc cc` data/alignment item with name/type/comments absent.
- Historical previous-helper prestate: `sub_5A4930`, declaration `wchar_t *__thiscall(_DWORD *this, __int16 *, wchar_t *Destination, rsize_t SizeInWords)`, all four function-start channels absent, frame `arg_0 +0xc:int`, `Destination +0x10:wchar_t *`, `SizeInWords +0x14:rsize_t`, and raw Hex-Rays locals `v4:_DWORD *`, `v5:int`, `result:wchar_t *`, `v7:int`, `v8:const wchar_t *`; local comments absent.
- Current previous-helper readback: `UserPane__GetPreviousChatHistoryLine`, `[0x005a4930,0x005a498b)`, size `0x5b`, exact source-facing declaration `void __thiscall UserPane__GetPreviousChatHistoryLine(UserPane *this, short *historyCursor, wchar_t *destination, rsize_t destinationCount)`; IDA renders `short` equivalently as `__int16`. Address-regular absent; address-repeatable absent; function-regular exactly `Copies the previous shared chat-history entry into a bounded destination and updates the caller's signed history cursor.`; function-repeatable absent. Frame `historyCursor +0xc __int16 *` is applied. Physical argument members deliberately remain `Destination +0x10 wchar_t *` and `SizeInWords +0x14 rsize_t`; the prototype/decompiler use `destination` and `destinationCount`. Rename dry-run and apply returned `Argument member` without mutation. First item, bytes, two callers, and instruction comments `0x005a4972="Source"`, `0x005a4973="SizeInWords"`, `0x005a4979="Destination"` remain unchanged; their repeatable channels remain absent.
- Historical next-helper prestate matched the previous helper's raw declaration/frame/local shape under `sub_5A4990`, with all four function-start channels absent.
- Current next-helper readback: `UserPane__GetNextChatHistoryLine`, `[0x005a4990,0x005a49db)`, size `0x4b`, exact source-facing declaration `void __thiscall UserPane__GetNextChatHistoryLine(UserPane *this, short *historyCursor, wchar_t *destination, rsize_t destinationCount)` with equivalent IDA `__int16` rendering; address-regular absent; address-repeatable absent; function-regular exactly `Copies the next shared chat-history entry into a bounded destination and updates the caller's signed history cursor.`; function-repeatable absent. Frame `historyCursor +0xc __int16 *` is applied, while physical `Destination +0x10` and `SizeInWords +0x14` labels remain for the same bounded `Argument member` limitation. Prototype/decompiler source names are `destination` and `destinationCount`. First item, bytes, two callers, and instruction comments `0x005a49c3="Source"`, `0x005a49c4="SizeInWords"`, `0x005a49ca="Destination"` remain unchanged; repeatable channels remain absent.
- Historical save-helper prestate: `sub_5A49E0`, declaration `int __thiscall(_DWORD *this, const unsigned __int16 *)`, all four function-start channels absent, frame `arg_0 +0x18 _DWORD`, and Hex-Rays parameters `this:_DWORD *`, `a2:const unsigned __int16 *`; locals and local-comment absence remain documented as assignment-time evidence.
- Current save-helper readback: `UserPane__SaveChatHistoryLine`, `[0x005a49e0,0x005a4a9c)`, size `0xbc`, exact source-facing declaration `void __thiscall UserPane__SaveChatHistoryLine(UserPane *this, const wchar_t *text)`; address-regular absent; address-repeatable absent; function-regular exactly `Deduplicates a submitted chat line, keeps at most ten entries, and appends the newest line to the shared UserPane chat history.`; function-repeatable absent. Frame is now `text +0x18 const wchar_t *`. First item, bytes, two callers, control flow, and List operations are unchanged; no instruction comments are reported.
- Helper caller sets remain exact: previous/next are called by UID000415 at `0x005b35df`/`0x005b35e6` and ChatInputPane at `0x005b39af`; save is called by SayInputPane submit at `0x005b37d0` and ChatInputPane submit at `0x005b3ba0`. Incoming xref counts remain target `1`, previous `2`, next `2`, save `2`.
- Helper padding remains `[0x005a4928,0x005a4930)` eight `0xcc`, `[0x005a498b,0x005a4990)` five `0xcc`, `[0x005a49db,0x005a49e0)` five `0xcc`, and `[0x005a4a9c,0x005a4aa0)` four `0xcc`.
- Global `0x0067a748-0x0067a74c` remains a four-byte zero-initialized item named `g_pUserPane`, typed `UserPane *`, address-regular comment `Active complete UserPane singleton used by packet and group-state routes.`, address-repeatable absent; data has no function-comment channels.
- Current `UserPane` UDT size remains `0x13eb84`; IDA's member at `+0x13eb04` retains the historical physical name `m_whisperHistoryOther` and type `List *`, while ordinary source documentation uses inferred `m_chatHistory`. Adjacent `+0x13eb08`, `+0x13eb0c`, and `+0x13eb10` recipient-history state remains distinct. Catalog0372 intentionally did not rebuild or broadly mutate this UDT.
- `SayInputPane` remains an incomplete/no-layout type with no materialized complete-object members. `Event` remains a `0x110`-byte UDT with the exact key-payload layout documented above. `EventHandler` remains a four-byte pointer-form type, so `EventHandler *` would be a double pointer and remains rejected for the raw receiver.
- Protected UID000414 constructor `[0x005b34d0,0x005b356c)` remains `SayInputPane__ConstructorWithInitialText`, size `0x9c`, with its exact typed constructor declaration/comment/frame and zero incoming xrefs. `LineInputPane__Constructor`, `g_pUserPane`, `EventMan__TranslateEventKey`, `TextEditPane__InsertTextRange`, `TextEditPane_SetSelectionRange`, `sub_4F25A0`, and `sub_5B3670` retain their prior names, types, comments, ranges, and protected roles.
- Historical collision queries for the four accepted names returned zero before mutation; current exact names resolve only at their intended addresses. No body, control-flow, range, vtable, global, sibling-function, padding, or protected-dependency mutation occurred.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005b356c-0x005b3570` | UID0000VN / `by-memory/-ignored.md` | leading alignment | no source | ignored ledger | 100 | Preserve. |
| `0x005b3570-0x005b3670` | UID000415 / target | SayInputPane Event-handler override | true | UID0001MB / UID0000C3 | `87/89 -> 94/95` | Exact source body/formal applied; catalog0372 IDA identity verified. |
| `0x005b3670-0x005b37ea` | UID000416 / submit child | SayInputPane submit override | true | UID0001MB / UID0000C3 | `88/90` | Support call correction only. |
| `0x005a4930-0x005a498b` | no exact page | UserPane previous-history helper | source-authored support | UserPane.cpp | not scored | Fully analyzed; no target-scope expansion. |
| `0x005a4990-0x005a49db` | no exact page | UserPane next-history helper | source-authored support | UserPane.cpp | not scored | Fully analyzed; no target-scope expansion. |
| `0x005a49e0-0x005a4a9c` | no exact page | UserPane save-history helper | source-authored support | UserPane.cpp | not scored | Fully analyzed; no target-scope expansion. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0062fbb4` | data xref to `0x005b3570` | SayInputPane secondary-vtable dispatch; target liveness. |
| target | no direct code callers | Expected for this virtual override. |
| `0x005b358a` | `EventMan__TranslateEventKey` | Translates key using key code and modifiers before gating. |
| `0x005b35df` | `UserPane__GetPreviousChatHistoryLine` (historical prestate `sub_5A4930`) | Previous chat-history line. |
| `0x005b35e6` | `UserPane__GetNextChatHistoryLine` (historical prestate `sub_5A4990`) | Next chat-history line. |
| `0x005b35ff`, `0x005b363d` | `TextEditPane_SetSelectionRange` | Select broad edit range before/after insertion. |
| `0x005b362e` | `TextEditPane__InsertTextRange` | Insert bounded history output. |
| `0x005b3659` | `sub_4F25A0` | Base `LineInputPane::HandleKeyOrTextEvent`. |
| `0x005b39af` | caller of previous/next helpers | ChatInputPane shares the UserPane history. |
| `0x005b37d0`, `0x005b3ba0` | callers of save helper | SayInputPane and ChatInputPane submit paths share the UserPane history. |

## Documentation Evidence And IDA Status

- Target documentation has correct exact boundaries, vtable-only liveness, adjusted-this arithmetic, cursor/edit-child roles, child-only emitter routing, and the applied exact Event-based CPP/prose.
- Historical pre-callback target state used stale event/modifier/helper/global/buffer/edit/base-method assumptions. Current target CPP/prose instead records `Event *`, exact modifier/key behavior, `g_pUserPane` history members, the bounded buffer without explicit zero initialization, typed TextEditPane APIs, and `LineInputPane::HandleKeyOrTextEvent(event)`.
- Historical pre-callback SayInputPane H forward-declared `PaneKeyEvent` and declared `HandleKeyInput`. Current applied H declares `virtual bool HandleKeyOrTextEvent(Event *event);` and contains no `PaneKeyEvent`.
- Historical pre-callback UserPane H named `+0x13eb04` `m_whisperHistoryOther` and omitted the history members. Current applied H names only that slot `List *m_chatHistory` and declares `GetPreviousChatHistoryLine`, `GetNextChatHistoryLine`, and `SaveChatHistoryLine` while preserving adjacent recipient-history fields.
- Historical pre-callback UID000416 called a free helper with `g_pCollectionData`. Current applied formal/prose calls `g_pUserPane->SaveChatHistoryLine(wideText)`.
- Historical checkpoint command `000000019802` generated CPP/H reflected those stale pre-callback ordinary formals. Commands `000000019887` at `2026-07-30T08:15:21-04:00` and `000000019890` at `2026-07-30T08:36:15-04:00` are dated accepted closure checkpoints. Current supervisor/validator-owned command `000000019926` at `2026-07-30T10:34:57-04:00` reconfirms UID000414 constructor `92/94`, UID000415 exact Event handler `94/95` with `g_pUserPane` previous/next calls, UID000416's current save-member call, no `PaneKeyEvent`, and UID0001MB as the `89/93` empty emitter marker.
- Current manual coverage contains the supervisor-applied UID000415 and UID000416 rows. The former B008 M01-M05 aggregate/class/file rows are preserved below as historical prestates; supervisor commands `000000019980` through `000000019982` applied and validated the exact no-loss merges that retain those constructor facts while adding UID000415's Event-history, UserPane dependency, submit, and emission-routing detail.
- Supervisor Gate 2B catalog entry `0372` applied and verified the target and three helper names/types/function comments plus the `0x005b35dc` clear. The final supervisor reaffirmation readback and required save establish current saved IDB `D7D29DEB...08CCA`; historical raw prestates, pre-reaffirmation backup `3892BDA8...98D1`, and earlier shared-IDB identities remain explicit history rather than current truth.

## Ranked Ownership Analysis

### 1. SayInputPane / SayInputPanes.cpp

- Evidence for: exact SayInputPane vtable cell, SayInputPane-specific signed history cursor, inherited edit child, sibling constructors/submit method, existing source tree, and class emitter route.
- Evidence against: no direct code caller and no complete SayInputPane layout beyond the current incomplete type; both are expected for a secondary-facet virtual method and do not weaken semantic ownership.
- Decision: accepted canonical method owner and source file.

### 2. UserPane / UserPane.cpp

- Evidence for: owns `g_pUserPane`, `m_chatHistory`, and all three history helper bodies.
- Evidence against: it is a dependency, not the target receiver or vtable owner.
- Decision: accepted support owner for helper declarations/storage; rejected as target owner.

### 3. ChatInputPane, Chatting, or LineInputPane

- Evidence for: ChatInputPane shares helper callers; LineInputPane supplies fallback and edit control; Chatting is the broader UI feature.
- Evidence against: separate vtables/receivers/source families; none owns the target cursor or target vtable cell.
- Decision: rejected as target owners.

### Proposed new file/grouping, if applicable

- Not applicable. Existing `SayInputPanes.cpp/.h` and `UserPane.cpp/.h` placements are sufficient.
- No additional UID is declared because helper support research does not require claiming separate target coverage.

## Source Placement

- Target declaration: `NexusTK/social/SayInputPanes.h` through [UID:0000C3].
- Target definition: `NexusTK/social/SayInputPanes.cpp` through exact child [UID:000415].
- History helper declarations and future exact definitions: `NexusTK/ui/panels/UserPane.h/.cpp` through [UID:0000FQ]/[UID:0000P1].
- Rejected `Chatting.cpp`: shared history behavior does not make the SayInputPane virtual method a Chatting source member.
- Rejected free helper module: all three helper bodies use UserPane `this` and the same private List member.
- No source-placement uncertainty remains material to target code or score.

## Range / Split / Padding / Reclassification Analysis

- Exact target range is one modeled function `[0x005b3570,0x005b3670)`.
- Leading `[0x005b356c,0x005b3570)` is four `0xcc` bytes and remains ignored padding.
- Exclusive end `0x005b3670` is the sibling submit method prologue; no byte from UID000416 belongs to this target.
- Parent UID0001MB remains a blank non-emitting method-cluster index over constructor/key/submit children and padding.
- No child creation, merge, range expansion, or reclassification is needed.
- History helpers are support research outside the target range. Their complete analysis informs ownership/signatures without falsely making them UID000415 children.

## Negative Evidence Summary

- No direct rel32 call/jump reaches `0x005b3570`; the vtable data xref is the valid route.
- No evidence supports interpreting `event+0x10a` as IME state after current Event layout inspection.
- No evidence supports a separate `CollectionData` history owner after current global and helper-receiver inspection.
- No evidence supports manual source-level adjusted-this arithmetic; that is compiler ABI lowering.
- No evidence supports zero-initializing the history buffer; helper control flow guarantees output initialization.
- No evidence supports `SelectText`/`InsertText`; current typed APIs are `SetSelectionRange`/`InsertTextRange`.
- No evidence supports changing owner/emitter/source range or merging the target with UID000416.
- No original symbol proves exact helper spellings, but retaining raw labels would be lower-quality than the convergent behavior-based names.

## IDA Rename / Type / Comment Recommendations

Supervisor Gate 2B applied and verified all five accepted actions under catalog entry `0372`. B007 remained read-only before, during, and after the transaction; the table preserves literal historical prestate and applied action. The supervisor's final Gate 2 reaffirmation against active session `1da2b2ae` reconfirmed every table readback and protected dependency, created byte-identical pre-reaffirmation backup `E:\NTK\Resources\NexusTK\NexusTK.exe.uid000415-gate2b-20260730-113455.i64` at `3892BDA8...98D1`, and saved current authority `D7D29DEB...08CCA` without requiring an additional semantic mutation.

| Row | Entity and exact historical prestate | Applied supervisor action | Exact current verified readback | Constraints / classification |
| --- | --- | --- | --- | --- |
| A415-01 | Function `[0x005b3570,0x005b3670)`, first item `[0x005b3570,0x005b3571)` one-byte code. Historical name `sub_5B3570`, declaration `char __thiscall(__int16 *this, _BYTE *)`; all four function-start comment channels absent. Historical raw frame: `Destination +0x8 wchar_t` width 2, `var_4 +0x208 _DWORD`, saved `+0x20c _DWORD`, return `+0x210 _UNKNOWN *`, `arg_0 +0x214 _DWORD`; Hex-Rays parameters `this:__int16 *`, `a2:_BYTE *`, locals `v3:unsigned char`, `v5:__int16 *`, `Destination:wchar_t[256]`; local comments absent. Historical instruction comments included stale `0x5b35dc="int"`; collision query for the accepted name was zero. | Applied exact name `SayInputPane__HandleKeyOrTextEvent`, declaration `bool __thiscall SayInputPane__HandleKeyOrTextEvent(void *eventHandlerFacet, Event *event)`, and function-regular comment `Handles unmodified Up/Down keys by replacing the edit control with previous/next local chat history; forwards all other events to LineInputPane.`. Left address-regular, address-repeatable, and function-repeatable absent; preserved body/frame/locals and all non-stale instruction comments. | Exact name/declaration/comment read back. Frame is `event +0x214 Event *`; Hex-Rays presents typed Event use and named dependencies. Bounds `0x100`, bytes, one vtable xref, zero code callers, raw `Destination` member, reconstructed `wchar_t[256]`, range, vtable, and protected state are unchanged. | Existing `Event` used; incomplete/no-layout `SayInputPane` preserved; secondary-facet receiver remains `void *`; no boundary/vtable/data change. Classification: `apply`; catalog0372 `applied/verified`. |
| A415-02 | Function `[0x005a4930,0x005a498b)`, first item `[0x005a4930,0x005a4931)` one-byte code. Historical name `sub_5A4930`, raw declaration `wchar_t *__thiscall(_DWORD *this, __int16 *, wchar_t *Destination, rsize_t SizeInWords)`; all four function-start channels absent. Historical frame cursor was `arg_0 +0xc:int`, with `Destination +0x10:wchar_t *`, `SizeInWords +0x14:rsize_t`; raw Hex-Rays locals and instruction comments remain recorded above. Collision query was zero. | Applied name `UserPane__GetPreviousChatHistoryLine`, source-facing declaration `void __thiscall UserPane__GetPreviousChatHistoryLine(UserPane *this, short *historyCursor, wchar_t *destination, rsize_t destinationCount)`, and exact function-regular bounded-copy comment. Left other three function-start channels absent and preserved all literal instruction comments/body/range. | Exact name/declaration/comment read back; IDA renders `short` as `__int16`; `historyCursor +0xc __int16 *` is current. Prototype/decompiler use `destination`/`destinationCount`, but physical frame labels remain `Destination +0x10` and `SizeInWords +0x14`. Dry-run and apply frame-member renames returned `Argument member` and made no change. Bytes, bounds, two callers, comments, and padding remain unchanged. | Physical label exception is accepted and must not be hidden or represented as a double pointer/type failure. No List layout or body change. Classification: `apply`; catalog0372 `applied/verified` with bounded presentation limitation. |
| A415-03 | Function `[0x005a4990,0x005a49db)`, first item `[0x005a4990,0x005a4991)` one-byte code. Historical name `sub_5A4990`, same raw declaration/frame shape as A415-02, all four function-start channels absent, raw locals/instruction comments recorded above, collision query zero. | Applied name `UserPane__GetNextChatHistoryLine`, source-facing declaration `void __thiscall UserPane__GetNextChatHistoryLine(UserPane *this, short *historyCursor, wchar_t *destination, rsize_t destinationCount)`, and exact function-regular bounded-copy comment. Left other three function-start channels absent and preserved literal instruction comments/body/range. | Exact name/declaration/comment read back; IDA renders `short` as `__int16`; `historyCursor +0xc __int16 *` is current. Prototype/decompiler use `destination`/`destinationCount`, while physical labels remain `Destination +0x10` and `SizeInWords +0x14` after the same non-mutating `Argument member` result. Bytes, bounds, two callers, comments, and padding remain unchanged. | Preserve the exact physical-label exception and List internals. Classification: `apply`; catalog0372 `applied/verified` with bounded presentation limitation. |
| A415-04 | Function `[0x005a49e0,0x005a4a9c)`, first item `[0x005a49e0,0x005a49e1)` one-byte code. Historical name `sub_5A49E0`, declaration `int __thiscall(_DWORD *this, const unsigned __int16 *)`; all four function-start channels absent; historical frame `arg_0 +0x18 _DWORD`, raw parameters/locals and local-comment absence recorded above; collision query zero. | Applied name `UserPane__SaveChatHistoryLine`, declaration `void __thiscall UserPane__SaveChatHistoryLine(UserPane *this, const wchar_t *text)`, and function-regular comment `Deduplicates a submitted chat line, keeps at most ten entries, and appends the newest line to the shared UserPane chat history.`. Left other three function-start channels absent; no body/frame-local/padding mutation beyond prototype-driven argument typing. | Exact name/declaration/comment read back; frame is `text +0x18 const wchar_t *`. Bounds `0xbc`, bytes, two callers, List calls, control flow, padding, and other comment channels remain unchanged. Source return is `void`; no residual-EAX behavior was changed. | Preserve List calls/control flow and neighbors. Classification: `apply`; catalog0372 `applied/verified`. |
| A415-05 | Instruction item `[0x005b35dc,0x005b35dd)`, size 1, code, name/type absent. Historical address-regular comment was exactly `int`; address-repeatable absent; function channels not applicable. | Applied exact address-regular clear at `0x005b35dc`; left address-repeatable absent and preserved all surrounding instruction comments. | Address-regular absent; address-repeatable absent; same one-byte code item, bytes, no name/type, and unchanged surrounding comments/control flow. | Stale raw-type artifact only. Classification: `apply`; catalog0372 `applied/verified`. |

Protected dependencies, verified unchanged after Gate 2B:

- `0x005b34d0-0x005b356c`: already present as `SayInputPane__ConstructorWithInitialText`, exact typed constructor declaration and function-regular comment recorded above; all other function-start comment channels absent, zero incoming xrefs, and the incomplete/no-layout `SayInputPane` prerequisite type preserved; no change recommended.
- `0x004f1c00`: already present as `LineInputPane__Constructor`, declaration `LineInputPane *__thiscall(LineInputPane *this, const wchar_t *promptText)`, address-regular absent, address-repeatable absent, exact existing function-regular constructor comment retained, and function-repeatable absent; no change recommended.
- `0x0067a748-0x0067a74c`: already present as `g_pUserPane : UserPane *`, exact regular address comment retained, repeatable absent; no change recommended.
- `0x004a8b10-0x004a8b1a`: already present as `EventMan__TranslateEventKey`, declaration `unsigned __int8 __thiscall(EventMan *this, unsigned __int8 key, unsigned __int8 modifiers)`, address-regular absent, address-repeatable absent, existing function-regular comment retained, and function-repeatable absent; no change recommended.
- `0x0058fc30-0x0058fe93`: already present as `TextEditPane__InsertTextRange`, exact declaration `int __thiscall(TextEditPane *this, const wchar_t *text, __int16 length, const unsigned __int16 *formatPayload, TextEditObject *textObject)`, address-regular absent, address-repeatable absent, existing function-regular comment retained, and function-repeatable absent; no change recommended.
- `0x0058f2a0-0x0058f489`: already present as `TextEditPane_SetSelectionRange`, current declaration `char __thiscall(int this, __int16, __int16)`, address-regular absent, address-repeatable absent, existing function-regular support comment retained, and function-repeatable absent. This report uses the accepted source-doc spelling `SetSelectionRange` and does not expand Gate 2B scope.
- `0x004f25a0-0x004f2754`: current `sub_4F25A0`, declaration `char __thiscall(_DWORD *this, _BYTE *)`, all four function-start comment channels absent; bounds/body are protected. Ordinary support prose may carry the Event-based source spelling, but this report does not add a separate IDA action.
- `0x005b3670-0x005b37ea`: current `sub_5B3670`, declaration `__int16 __thiscall(_DWORD **this)`, all four function-start comment channels absent; this sibling submit body and boundary are protected except for the report's ordinary source-call correction.
- Vtable base `0x0062fbac-0x0062fbb0`, target cell `0x0062fbb4-0x0062fbb8`, leading padding `0x005b356c-0x005b3570`, helper predecessor/successor padding, all current xrefs, and all bounded bytes read back unchanged. Function sizes remain `0x100`, `0x5b`, `0x4b`, and `0xbc`; incoming xref counts remain `1`, `2`, `2`, and `2`.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes; the recommended source is substantially source-ready.
- Target formal CPP replacement:

```cpp
bool SayInputPane::HandleKeyOrTextEvent(Event *event)
{
    const unsigned char key =
        g_pEventMan->TranslateEventKey(
            event->m_payload.m_key.m_key,
            event->m_payload.m_key.m_modifiers);

    if (event->m_type != kEventKeyDown ||
        event->m_payload.m_key.m_modifiers != 0 ||
        (key != kPaneKeyUp && key != kPaneKeyDown)) {
        return LineInputPane::HandleKeyOrTextEvent(event);
    }

    wchar_t historyText[256];
    if (key == kPaneKeyUp) {
        g_pUserPane->GetPreviousChatHistoryLine(
            &m_chatHistoryCursor, historyText, _countof(historyText));
    } else {
        g_pUserPane->GetNextChatHistoryLine(
            &m_chatHistoryCursor, historyText, _countof(historyText));
    }

    if (historyText[0] != L'\0') {
        m_textEditPane->SetSelectionRange(0, 0x7fff);
        m_textEditPane->InsertTextRange(
            historyText,
            static_cast<short>(wcslen(historyText)),
            NULL,
            NULL);
        m_textEditPane->SetSelectionRange(0, 0x7fff);
    }

    return true;
}
```

- Target formal H disposition: keep blank; the declaration belongs in [UID:0000C3].
- Exact SayInputPane class H replacement:

```cpp
#include "../ui/dialogs/InputPanes.h"

class SayInputPane : public LineInputPane
{
public:
    SayInputPane();
    explicit SayInputPane(const wchar_t *initialText);
    virtual ~SayInputPane();

protected:
    virtual void OnSubmitChat();
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    short m_chatHistoryCursor;
};
```

- Exact UserPane H declarations to add in the public method surface:

```cpp
void GetPreviousChatHistoryLine(short *historyCursor,
                                wchar_t *destination,
                                size_t destinationCount);
void GetNextChatHistoryLine(short *historyCursor,
                            wchar_t *destination,
                            size_t destinationCount);
void SaveChatHistoryLine(const wchar_t *text);
```

- Exact UserPane field replacement at the existing `+0x13eb04` slot:

```cpp
List *m_chatHistory;
```

- Exact UID000416 formal CPP call replacement:

```cpp
g_pUserPane->SaveChatHistoryLine(wideText);
```

- Behavior fidelity: order, branches, width conversions, empty-history handling, range selection, bounded history count, and base return are preserved exactly.
- Human source shape: no cookie scaffolding, raw adjusted pointers, `sub_` labels, `dword_` labels, byte-array event indexing, or decompiler temporaries survive.
- Naming style follows current project `PascalCase` methods, `m_` members, and `g_p` pointer globals. Runtime fidelity and human source quality take precedence over cosmetic consistency.
- Third-party import directive: not applicable; this is NexusTK project C++.

## Final Recommendation

- The accepted target score/formal/prose corrections are applied and physically read back without changing owner, emitter, reconstructable state, range, or source file.
- The accepted SayInputPane declaration and support score/history updates are applied and physically read back.
- The accepted UserPane history field/declarations and source-placement documentation are applied and physically read back; complete layout and unrelated UserPane facts remain preserved.
- UID000416's save-history call is corrected while its behavior, metadata, and remaining source are retained.
- Supervisor Gate 2B catalog entry `0372` applied and verified all five deterministic IDA actions, saved the IDB, and preserved the bounded physical-frame label exception without weakening the source-facing prototypes.
- The five current-coverage-reconciled manual operations were applied by the supervisor and validated by commands `000000019980` through `000000019982`, with generated refresh disabled. Generated reconstruction readback remains command `000000019926`; preserve commands `000000019890` and `000000019887` as dated matching history through final gates.
- No target split, merge, no-owner state, non-emitting reclassification, or additional target UID is recommended.

## Recommended Target Doc Changes

- Target path: `by-memory/0x005b3570-0x005b3670.SayInputPaneHandleKeyInput.md`.
- Applied/read-back metadata is `COMPLETION:94`, `CONFIDENCE:95`; owner/emitter/reconstructable/position/Nested metadata is retained.
- Formal CPP is replaced exactly and formal H remains blank.
- Applied Item Summary: `Exact SayInputPane Event-handler override for unmodified Up/Down chat-history navigation, shared UserPane history helpers, inherited TextEditPane replacement, vtable-only liveness, and base Event forwarding.`
- Source name/signature/event/helper/global/edit API claims now match the report's current conclusions.
- Preserve exact bytes, range, vtable xref, zero direct callers, padding, adjusted offsets, helper behavior, negative ownership evidence, and historical prior-session evidence.
- Historicalize, do not silently delete, the former PaneKeyEvent/IME/free-helper/zero-init/SelectText/InsertText assumptions and state why each was superseded.

## Recommended Support Doc Changes

- `by-class/SayInputPane.md`: applied exact formal H replacement, method inventory/name/behavior correction, `93/94`, current IDB evidence, and historicalized stale signature.
- `by-file/SayInputPanes.md`: applied exact UID000415 behavior/source topology, UserPane dependency, score `89/90`, and historical correction.
- `by-memory/0x005b34d0-0x005b37ea.SayInputPane.md`: remains a blank aggregate; UID000415 row/evidence and score are now `89/93`.
- `by-class/UserPane.md`: now has the three public declarations and only the `+0x13eb04` source field renamed; layout/adjacent fields are preserved and helper behavior/caller evidence is incorporated without changing `94/95`.
- `by-file/UserPane.md`: now documents the three UserPane.cpp member helpers and shared SayInputPane/ChatInputPane consumers without changing `93/94`.
- `by-global/g_pCollectionData.md` and `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md`: stable paths remain, while current canonical source identity `g_pUserPane : UserPane *`, target/helper consumers, and stale alias history are incorporated; scores are unchanged.
- `by-memory/0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat.md`: the exact formal call and associated helper/global prose are corrected; `88/90` is retained.
- `by-memory/0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md`: source-facing method/signature prose now says `HandleKeyOrTextEvent(Event *)`; range/body/metadata are preserved.
- `by-class/LineInputPane.md`: callback-time inspection found the Event declaration already present, so B007 made no edit. After B008's later callback lease cleared, repeated read-only checks stabilized at SHA256 `5C2B543E...BD1E5`, `19245` bytes/`155` lines; both `class Event;` and `virtual bool HandleKeyOrTextEvent(Event *event);` remain present, preserving the required declaration/support assumptions.

## Score And Metadata Recommendation

- UID000415 assignment-time state was `87/89`, owner/emitter UID0000C3, reconstructable true, stale populated CPP, blank H.
- UID000415 current applied state is `94/95`, owner/emitter/reconstructable unchanged, exact CPP, blank H.
- Reason higher: all former type/helper/global/source-body blockers are resolved with current binary/type/caller evidence and formal human C++.
- Reason not `95/95` or higher: stripped original symbols do not prove the exact lexical spellings `GetPreviousChatHistoryLine`, `GetNextChatHistoryLine`, and `SaveChatHistoryLine`; the chosen names are high-probability source reconstruction, not original-symbol recovery.
- SayInputPane class is now `93/94` from assignment-time `88/90`; owner/file route is unchanged.
- SayInputPane aggregate is now `89/93` from assignment-time `87/90`; blank CPP/H and route are unchanged.
- SayInputPanes file is now `89/90` from assignment-time `88/87`; source path is unchanged.
- UserPane class/file, global pages, submit child, base child, and LineInputPane class retain current scores/routes.
- Score-improvement attempt resolved every listed blocker rather than treating it as future work: Event type/layout, modifiers, receiver, cursor/edit fields, helper identities/types/owner, global identity, vtable route, exact API calls, range, formal CPP/H, and source placement.

## Open Questions With Attempted Resolution

| Open question found | Evidence checked | Resolution |
| --- | --- | --- |
| Is this `HandleKeyInput(PaneKeyEvent *)`? | Event UDT, inherited slots, target field reads, base docs | No. Best source is `HandleKeyOrTextEvent(Event *)`. |
| Is `event+0x10a` IME state? | EventKeyPayload layout and translation call | No. It is `m_modifiers`; exact comparison is zero. |
| Is `dword_67A748` collection data? | current global name/type, UserPane lifetime/docs, helper field access | It is `g_pUserPane : UserPane *`. Stable old paths remain historical aliases. |
| Who owns the history helpers? | helper `this`, `+0x13eb04`, caller sets, UserPane size | UserPane.cpp member methods. |
| What is `+0x13eb04`? | all three helper bodies and adjacent recipient fields | Shared local chat-history `List *m_chatHistory`. |
| Are helper return types source-significant? | all call sites and bodies | Retrieval/save methods are source `void`; residual EAX is not consumed. |
| Should history buffer be zeroed? | both retrieval-helper empty/list paths | No explicit source zero-initialization is needed or supported. |
| Should helpers get separate target UIDs now? | assignment scope, exact target range, existing source routing | No. Their behavior is fully documented as support; separate future queue targeting is optional, not a UID000415 blocker. |
| Does no direct caller weaken reconstruction? | vtable cell and constructors | No; this is virtual dispatch. |
| Is original lexical spelling proven? | names, docs, collision queries, behavior | No original symbols survive. High-probability human names are used; no raw labels remain. |

No unresolved question blocks behavior, source placement, owner/emitter, formal C++, or the recommended score.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Manual identities and supervisor-applied operations:

- Historical pre-command-`000000019882` snapshot: `by-memory/-coverage-report.md` SHA256 `4376E67096521938B6B67C6724819A594B9AE7089342DFFE131863D4E18E39EE`, `2093619` bytes, `4742` lines. This identity is not current.
- Historical post-command-`000000019882` checkpoint: `by-memory/-coverage-report.md` SHA256 `FD7EF2458667827CBDF6F95FB6550403FCC29CE44FF80DC2921205A5AB05FAA6`, `2094784` bytes, `4744` lines. This identity was superseded by a later unrelated manual-coverage advance.
- Historical pre-command-`000000019890` currentness checkpoint: `by-memory/-coverage-report.md` SHA256 `35B4FAE329160F61FE2713C1EA5F7ACBECBCEC3C2BDB6ACA565E16E27FE44FC3`, `2095531` bytes, `4745` lines; `by-class/-coverage-report.md` SHA256 `E401089D9A3A322F271D61B1577E54362D316C252B8157722DB9EC92595E3163`, `271678` bytes, `625` lines; `by-file/-coverage-report.md` SHA256 `5E04B7C12D7268B0C149E28B1532A258BCE84B2C8B5F4A3DCB7758118CAC91DC`, `162456` bytes, `317` lines. Those identities and their `78%`/`82%`/`87%` rows are dated history.
- Historical post-B008-M01-M05 read-only checkpoint: `by-memory/-coverage-report.md` SHA256 `1E8ADE03DAC904CEF6A396BE9E389DD01737CCC74EE2A1EFB324B695E0EFCF42`, `2096375` bytes, `4746` lines; `by-class/-coverage-report.md` SHA256 `B1166F5ED1A35CF9793E110459F3E61C076DD6590EAA6CB5DA50461F1EA62CE2`, `271791` bytes, `625` lines; `by-file/-coverage-report.md` SHA256 `33826E899598F6E4D84D92A69551CF4BE6D222A9C0CBA5DB791E3836252B2E04`, `162528` bytes, `317` lines. These are dated checkpoints, not current physical identities.
- Historical intermediate read-only checkpoint: `by-memory/-coverage-report.md` SHA256 `400717A7F2EC205DC920DE666E69198F9D87581AE5FCBCFDB24B61527A1974BB`, `2098064` bytes, `4748` lines; `by-class/-coverage-report.md` SHA256 `3E382C559A3BC8C742ED7A9299AC7350DF67F71557820B399A27867496EC3536`, `271962` bytes, `625` lines; `by-file/-coverage-report.md` SHA256 `2AE8504F3421629A0FF7473462E8310F73F86F6F87729DB09039F5A6AE2AC6EE`, `162658` bytes, `317` lines. These identities and their former line anchors are dated history.
- Historical pre-application snapshot: `by-memory/-coverage-report.md` SHA256 `22BB0BB3366ED1A445E99E03D6CED32D1F263E12940D400AEA68D1D19EC705F2`, `2101781` bytes, `4754` lines; `by-class/-coverage-report.md` SHA256 `EE896367FAA8DF9113167918E06166EE932342C986E0BA7A5FA32C674CD74565`, `272165` bytes, `625` lines; `by-file/-coverage-report.md` SHA256 `21886E924A4062AB4A82892CB36754634CB933B41683810A8D185553123A24E2`, `162812` bytes, `317` lines. At that checkpoint UID000415 and UID000416 were absent, and the quoted UID0001MB/UID0000C3/UID0000N9 rows were the exact replacement prestates.
- Dated supervisor application/validation checkpoint: `by-memory/-coverage-report.md` SHA256 `8C8C35AB230F91786C7EF0B0AFF0A6F8B8D5241C4B57A2D88B041124B829BEDF`, `2102841` bytes, `4756` lines; `by-class/-coverage-report.md` SHA256 `73685EF31BFA5F268A47EFB89FCAB253F6D6B55A003C4F83A736D1454FEB7D92`, `272255` bytes, `625` lines; `by-file/-coverage-report.md` SHA256 `995F7753F8FF5A84E557337EB6B15F3C7C9C38EEF94A05E63E9269743E01C24C`, `162924` bytes, `317` lines. Commands `000000019980`, `000000019981`, and `000000019982` applied and validated the five exact operations at this checkpoint; each exited `0` with `ok:1` and generated refresh disabled. Later unrelated B001 coverage additions superseded only these shared-file identities and by-memory line positions.
- Current unrelated-advance snapshot: `by-memory/-coverage-report.md` SHA256 `C5E4E81C9EBC12C6A0A73D187100657F9406043C2B826C1519B8A21BED62BAC5`, `2107677` bytes, `4768` lines; `by-class/-coverage-report.md` SHA256 `64862329F2FCE0B5AEF01B349E0D5A5D2F09F0B319C8A9EB173521F5F385BC03`, `272272` bytes, `625` lines; `by-file/-coverage-report.md` SHA256 `736B2900338FDFE34C44CD18CF9DF0C7791820D28D42DAB7B5E9DD0691EB6BFE`, `162964` bytes, `317` lines.
- Current applied-row readback: UID0001MB remains the exact no-loss merged `89%` row at by-memory line `3952`; UID000414 remains line `3953`; the stable `0x005b356c-0x005b3570` padding anchor remains line `3954`; UID000415 remains the exact inserted `94%` row at line `3955`; UID000416 remains the exact inserted `88%` row at line `3956`; and the stable `0x005b37ea-0x005b37f0` padding anchor follows at line `3957`. UID0000C3 remains the exact no-loss merged `93%` row at by-class line `459`, and UID0000N9 remains the exact no-loss merged `89%` row at by-file line `234`. The unrelated B001 additions did not alter any UID000415 payload.

1. Supervisor-applied UID000415 insertion after the stable `0x005b356c-0x005b3570` ignored-padding row and before UID000416:

```text
        - [UID:000415][0x005b3570-0x005b3670.SayInputPaneHandleKeyInput](by-memory/0x005b3570-0x005b3670.SayInputPaneHandleKeyInput.md) 0x005b3570-0x005b3670 | SayInputPane virtual Event handler | SayInputPaneHandleKeyInput : reconstructable : 94% : very-strong : Exact SayInputPane::HandleKeyOrTextEvent(Event *) override for unmodified Up/Down shared UserPane chat-history navigation, inherited TextEditPane replacement, vtable-only dispatch, and base Event forwarding, with source-ready formal C++.
```

2. Historical pre-application B008-updated UID0001MB row:

```text
    - [UID:0001MB][0x005b34d0-0x005b37ea.SayInputPane](by-memory/0x005b34d0-0x005b37ea.SayInputPane.md) 0x005b34d0-0x005b37ea | class-method cluster | SayInputPane : reconstructable : 89% : very-strong : Non-emitting SayInputPane method index with exact constructor-overload, key/history, and submit children, exact padding, current vtable/prompt/helper evidence, resolved constructor retained-code route and source-facing InsertTextRange contract, while child pages alone emit method CPP.
```

Supervisor-applied exact no-loss merged row:

```text
    - [UID:0001MB][0x005b34d0-0x005b37ea.SayInputPane](by-memory/0x005b34d0-0x005b37ea.SayInputPane.md) 0x005b34d0-0x005b37ea | non-emitting class-method cluster | SayInputPane : reconstructable : 89% : very-strong : Non-emitting SayInputPane index with exact constructor-overload, Event-based Up/Down shared-history, and opcode 0x0e subtype 0 submit children; exact padding, three-vtable/prompt/helper evidence, resolved retained-constructor route, typed InsertTextRange and g_pUserPane history contracts, source-ready child C++, and blank aggregate CPP/H so only child pages emit method bodies.
```

3. Historical pre-application B008-updated UID0000C3 class row:

```text
- [UID:0000C3][SayInputPane](by-class/SayInputPane.md) : reconstructable : 93% : very-strong : Default local say input class with exact default/initial-text constructors, signed-short chat-history cursor, history navigation, submit packet behavior, three-vtable identity, social source placement, corrected class-H/child-CPP topology, and current typed TextEditPane insertion contract.
```

Supervisor-applied exact no-loss merged row:

```text
- [UID:0000C3][SayInputPane](by-class/SayInputPane.md) : reconstructable : 93% : very-strong : Source-ready default local say-input class with exact default/initial-text constructors, signed-short m_chatHistoryCursor, virtual HandleKeyOrTextEvent(Event *) Up/Down shared g_pUserPane history navigation, OnSubmitChat packet behavior, three-vtable identity, inherited typed TextEditPane insertion contract, corrected class-H/child-CPP topology, and SayInputPanes.cpp placement.
```

4. Historical pre-application B008-updated UID0000N9 file row:

```text
- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) : reconstructable : 89% : strong : Social chat input family placed at `NexusTK/social/SayInputPanes.cpp` with declarations in `SayInputPanes.h`, exact SayInputPane constructor/key/submit child routes, current helper and vtable evidence, and retained broader group/clan/source-split caveats.
```

Supervisor-applied exact no-loss merged row:

```text
- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) : reconstructable : 89% : very-strong : Social chat input source root at `NexusTK/social/SayInputPanes.cpp` with declarations in `SayInputPanes.h`, exact source-ready SayInputPane constructor/Event-history/submit child routes, shared UserPane history and typed TextEditPane dependencies, current helper/vtable/current-mode dispatcher evidence, and retained broader group/clan/chat source-split caveats.
```

5. Supervisor-applied UID000416 insertion after UID000415 and before the existing `0x005b37ea-0x005b37f0` padding row:

```text
        - [UID:000416][0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat](by-memory/0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat.md) 0x005b3670-0x005b37ea | SayInputPane submit override | SayInputPaneSubmitSayChat : reconstructable : 88% : very-strong : Source-ready normal say-chat submit path with password/sanitizer gates, opcode 0x0e subtype 0 packet construction, g_packetSender delivery, and shared g_pUserPane SaveChatHistoryLine persistence.
```

No manual row change is recommended for UID0000FQ (`94%`), UID0000P1 (`93%`), UID0000QK, UID0001OR, UID00035Y, or UID000077 because their scores/routes remain unchanged and their existing rows do not need target-specific structural replacement. Their ordinary prose changes remain independently validated.

B007 did not apply these rows. Manual `-coverage-report.md` files remain supervisor-owned collision surfaces; the supervisor applied and validated all five operations under commands `000000019980` through `000000019982`.

## Follow-Up Actions

- Historical callback gate: supervisor accepted exact pre-callback SHA `855632A934BF2D77D6006278B1BE6641AB21EEF116EDCE36212CEC36683A8CC5` and authorized the ordinary implementation recorded here.
- B007 ordinary callback closure: all accepted ordinary ledger rows were applied at report-level detail, physically read back, validated serially with `--no-generated-refresh`, and all leases were released.
- Supervisor Gate 2A claim-by-claim verification passed C415-001 through C415-073 before this final same-report reconciliation; the repaired artifact requires fresh exact-artifact gates under supervisor authority.
- Supervisor Gate 2B closure: catalog entry `0372` applies and verifies A415-01 through A415-05 with exact prestate/action/readback and protected-state evidence. The final reaffirmation used byte-identical backup `E:\NTK\Resources\NexusTK\NexusTK.exe.uid000415-gate2b-20260730-113455.i64` at historical checkpoint `3892BDA8...98D1`; required `idb_save` returned `ok:true` and produced current shared IDB `D7D29DEB...08CCA`, with no additional semantic mutation.
- Supervisor manual-coverage closure: commands `000000019980`, `000000019981`, and `000000019982` applied and validated the two insertions and three no-loss replacements; current exact identities and row anchors are recorded above and below.
- Current generated checkpoint command `000000019926` at `2026-07-30T10:34:57-04:00` is physically read back with the exact reconstruction-state CPP/H and generated-memory identities below. Validator-owned command `000000019933` at `2026-07-30T11:03:10-04:00` is the current moving research-tracker identity; command `000000019928` at `2026-07-30T10:40:11-04:00` is dated tracker history. Commands `000000019890`, `000000019891`, and `000000019887` remain dated matching checkpoints. Fresh exact gates remain after this same-report final reconciliation.
- No additional B-agent research is indicated unless a fresh gate identifies a concrete defect or current evidence drifts.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: very strong for `94/95`; lexical helper spelling is the only reason not to recommend full-final score.
- Range/owner/emitter/source confidence: certain to very strong.
- Formal behavior confidence: very strong; every branch, width, call, and state transition is grounded in current evidence.
- Remaining uncertainty is lexical rather than behavioral and has been resolved with the best defensible human source names.
- The retained physical frame labels `Destination`/`SizeInWords` do not reduce behavior or prototype confidence: exact source-facing types and decompiler names are applied, and the non-mutating `Argument member` result is explicitly bounded to IDA frame presentation.

## Validator Results

- Working directory for every run: `C:\FastStorage\NTK_Sources\source-3\project-documentation`.
- All commands exited `0` with `ok:1`. Generated refresh was disabled by `--no-generated-refresh` in every invocation; no command changed generated CPP/H/tracker artifacts.

| Command ID | Timestamp | Relative file / exact command | Result and side effects |
| --- | --- | --- | --- |
| `000000019838` | `2026-07-30T07:47:26-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x005b3570-0x005b3670.SayInputPaneHandleKeyInput.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`, `ok:1`; read back `94/95`; validator registry/projected-stats bookkeeping applied; generated refresh skipped. |
| `000000019839` | `2026-07-30T07:47:51-04:00` | `python .\tools\validator.py --mode file --file by-class/SayInputPane.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`, `ok:1`; exposed callback-introduced wrong UID0003DC link warning; no generated refresh. B007 corrected that link to canonical UID00035Y and reran command `000000019848`. |
| `000000019840` | `2026-07-30T07:47:54-04:00` | `python .\tools\validator.py --mode file --file by-file/SayInputPanes.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`, `ok:1`; read back `89/90`; 18 pre-existing missing-reference warnings retained; validator reference/projected-stats bookkeeping applied; generated refresh skipped. |
| `000000019841` | `2026-07-30T07:47:57-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x005b34d0-0x005b37ea.SayInputPane.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`, `ok:1`; read back `89/93`; generated refresh skipped. |
| `000000019842` | `2026-07-30T07:48:00-04:00` | `python .\tools\validator.py --mode file --file by-class/UserPane.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`, `ok:1`; five pre-existing missing-reference warnings retained; validator normalized UID links and updated registry/reference/projected-stats state; generated refresh skipped. |
| `000000019843` | `2026-07-30T07:48:03-04:00` | `python .\tools\validator.py --mode file --file by-file/UserPane.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`, `ok:1`; 18 pre-existing missing-reference warnings retained; validator normalized UID links and updated reference/projected-stats state; generated refresh skipped. |
| `000000019844` | `2026-07-30T07:48:06-04:00` | `python .\tools\validator.py --mode file --file by-global/g_pCollectionData.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`, `ok:1`; validator normalized UID links and updated reference/projected-stats state; generated refresh skipped. |
| `000000019845` | `2026-07-30T07:48:09-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`, `ok:1`; generated refresh skipped. |
| `000000019846` | `2026-07-30T07:48:11-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`, `ok:1`; validator registry/projected-stats bookkeeping applied; generated refresh skipped. |
| `000000019847` | `2026-07-30T07:48:15-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`, `ok:1`; validator normalized the target UID link and updated reference/projected-stats state; generated refresh skipped. |
| `000000019848` | `2026-07-30T07:48:40-04:00` | `python .\tools\validator.py --mode file --file by-class/SayInputPane.md --apply --no-generated-refresh --queue-timeout 240` | final class repair run, exit `0`, `ok:1`; canonical UID00035Y link read back, no callback-introduced warning, generated refresh skipped. |

- The warnings on commands `000000019840`, `000000019842`, and `000000019843` are pre-existing support-reference warnings outside this callback's accepted claims. The only callback-introduced warning, command `000000019839`'s UID0003DC link, was corrected and cleared by final command `000000019848`.
- Dated supervisor checkpoint command `000000019887` completed at `2026-07-30T08:15:21-04:00`. Historical supervisor command `000000019890` used working directory `E:\NTK\GhidraBridge\source-3\project-documentation` and exact command `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --queue-timeout 240 --wait-generated`; timestamp `2026-07-30T08:36:15-04:00`; exit `0`, `ok:1`; only pre-existing missing-reference warnings UID00039L and UID0003T6 remained; foreground generated refresh completed.
- Supervisor manual-coverage validators `000000019980` for `by-memory/-coverage-report.md`, `000000019981` for `by-class/-coverage-report.md`, and `000000019982` for `by-file/-coverage-report.md` each exited `0` with `ok:1`; generated refresh was disabled. The cited supervisor audit records the command IDs, paths, results, and generated disposition but does not expose exact timestamps or full CLI strings, so this report does not invent them.
- No validator was run for catalog0372 reconciliation or this report-only final reconciliation. Current generated command `000000019926` and tracker command `000000019933` were observed read-only from their artifact headers; tracker command `000000019928` is preserved as a dated checkpoint. Final lifecycle-time readback and exact gates remain supervisor-owned.

## Changed Files

- Frozen read-only ordinary destination baseline used for Gate 1/currentness comparison:

| Ordinary destination | SHA256 | Bytes | Lines |
| --- | --- | ---: | ---: |
| `by-memory/0x005b3570-0x005b3670.SayInputPaneHandleKeyInput.md` | `47F5841C24A0984CF6A160AC2A3BC737EBC0593588437FC4F4079178B14D0CD6` | 14096 | 197 |
| `by-class/SayInputPane.md` | `ED5B3BF8256F87EA02BB06A4A0D5C159B0A7C1DDCD4F5A0F48FB1E4F80192C33` | 21770 | 135 |
| `by-file/SayInputPanes.md` | `334A2419D191335FFDBC7DAEFCA15B4D81364A161498D6C1746F96BC3DE6A979` | 44213 | 194 |
| `by-memory/0x005b34d0-0x005b37ea.SayInputPane.md` | `F003D27CD689289A752E179CC8ECE78EB274B4659FDCFCDD0B222A11D1F0D28B` | 37399 | 220 |
| `by-class/UserPane.md` | `1ECD11678A39EABED11033D82F5B2A1BD12EF2E2A9682E2A1C2EC9022F74DEEA` | 100000 | 736 |
| `by-file/UserPane.md` | `4171E336C19C2D90171B272100CB824D519292A2F93789E44A999677F2C94F66` | 113756 | 472 |
| `by-global/g_pCollectionData.md` | `0FA2945D6285861003C900CE8E7C9489CA015A54804CFC40A8DAAD2F4C966770` | 26699 | 183 |
| `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md` | `2AB66571314BE595FE0196A3B173989F97AD91AF5C6862699C1D0D456B2D8F9C` | 32429 | 283 |
| `by-memory/0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat.md` | `4C1277942404BE91B9F8C1AC005E7B434A90EC07BBB45CCC590C88E81C80F307` | 18159 | 228 |
| `by-memory/0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md` | `D4EF91F9B6579FE3050B71DD2F6A300AC8BE84D0EB1A72659BEE441C5CA497B8` | 4112 | 56 |
| `by-class/LineInputPane.md` | `AD02AF7461479FC46F481084ABD2E0C6CC5FB81811541C948710E1F09A4AF35F` | 15903 | 138 |

- Dated B007 post-callback physical readback after the final scoped validator for each path; later B008 support advances are separately recorded below rather than overwriting this validator-time evidence:

| Ordinary destination | SHA256 | Bytes | Lines |
| --- | --- | ---: | ---: |
| `by-memory/0x005b3570-0x005b3670.SayInputPaneHandleKeyInput.md` | `7957EA2C43FB8C5B2078CEF245A85200FF5C9DD17FF1D6517CD65ECAF611F4C6` | 18678 | 211 |
| `by-class/SayInputPane.md` | `6A7AAA6D7DDFAB62F56CEDA3C2CFAFCB39CC1BABDFCAFCD1EA8EA386E8AC206E` | 24457 | 141 |
| `by-file/SayInputPanes.md` | `C8AA2BB30572D060D7983642B63DD20F5FA143B560B3B7E3CA5DD2D9A2A4509F` | 46333 | 200 |
| `by-memory/0x005b34d0-0x005b37ea.SayInputPane.md` | `6E263F31F2BE087B4590C7FDDDBD0BBA1BA952DF5604C961A0F9A19B2D91447F` | 39151 | 223 |
| `by-class/UserPane.md` | `7C2BCD5F65B8FD6AE8972F67BA6E1B3B3E4AD7216504BFE2319990EE75B47982` | 103714 | 758 |
| `by-file/UserPane.md` | `1FA4850B48BAC76EB16CBC90618CEE73AE5B760E14946FBF87D726C258CACE55` | 116751 | 484 |
| `by-global/g_pCollectionData.md` | `3341473A64A33E4D9D206B799BE40810078C86C1ED30B3E5BAFBC6AD8A1C9290` | 28351 | 188 |
| `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md` | `98B4E78095EF6196EA74EBD12246421B9E3A3CC292100BFBA2028526C4030F33` | 33818 | 289 |
| `by-memory/0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat.md` | `D01CBFD291832800D37C77CA7FC48314F8B8EF39D3C5801D79671610AAD758D8` | 19181 | 232 |
| `by-memory/0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md` | `BC4DED6AB4FF89A2237E3859EAA265F8EC3F1C26F3F1F3BA1C0E6673D2347654` | 5380 | 59 |
| `by-class/LineInputPane.md` (inspect only) | `A4F60260895C5793FE71C71EA09B29EB6C853BFC0F44FC81D23630C3270FDFDB` | 17047 | 140 |

- Final stable read-only identities after B008's active LineInputPane callback completed and all B008 leases cleared for a sustained interval:

| Concurrently advanced support destination | SHA256 | Bytes | Lines | UID000415 no-loss readback |
| --- | --- | ---: | ---: | --- |
| `by-class/UserPane.md` | `DB7867530A0DC231BC7DB350BD079858BBF88CEF8C90A2E35556DDA8AED97578` | 105930 | 768 | Three history member declarations, `m_chatHistory +0x13eb04`, helper behavior/callers, and adjacent-field exclusions remain present. |
| `by-file/UserPane.md` | `54A260E46F9E452904B6D9E6ED01DF5D0656435DF333C2C1172300BBA1C7781B` | 118431 | 491 | UserPane.cpp ownership for all three history helpers and Say/Chat caller boundaries remain present. |
| `by-memory/0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md` | `E63A912FBE7EDC7DC65BB5658D51BDBD1381D9C4CA0D11F3F1CCBEC778CB5A3E` | 7566 | 68 | Exact `HandleKeyOrTextEvent(Event *)` base contract and UID000415 fallback relationship remain present. |
| `by-class/LineInputPane.md` (inspect only) | `5C2B543E38E1A76FAAAD0A67546320D7D4ECA5C3660AB4B1EBE892F6509BD1E5` | 19245 | 155 | Formal H retains `class Event;` and `virtual bool HandleKeyOrTextEvent(Event *event);`; B007 made no edit. |

- Modified in place: this report and the ten authorized ordinary destinations above. No ordinary file was created, renamed, split, merged, or deleted.
- This B007 final reconciliation changed only this same report. The supervisor separately applied and validated the three manual coverage files under commands `000000019980` through `000000019982`; B007 did not edit any ordinary, generated, manual-coverage, IDA, audit, catalog, or lifecycle state during this pass.
- Inspect-only result: B007 did not lease or edit `by-class/LineInputPane.md`. The earlier inspect-only SHA `A4F60260...FDFDB`, `17047` bytes/`140` lines is a dated pre-B008-callback checkpoint. After B008's complete callback lease sequence cleared, repeated read-only checks over a sustained no-lease interval found the current page stable at SHA `5C2B543E...BD1E5`, `19245` bytes/`155` lines; its formal H still declares `class Event;` and `virtual bool HandleKeyOrTextEvent(Event *event);`, so the Event declaration and support assumptions used by this report remain valid.
- Currentness drift reconciled: the prior UID000414 support advance remains preserved. The pre-Gate-2B bounded MCP readback against historical IDB SHA `83C20CE9...C294A9E` found no UID000415/dependency drift; catalog0372 and its bounded transaction-save readback establish the applied state at historical checkpoint `2CCA289F...0D7E851`. Checkpoints `4EDEC155...5D09F` and `3892BDA8...98D1` are historical; `3892BDA8...98D1` is also the byte-identical final-reaffirmation backup. The final supervisor readback and required save establish current shared IDB SHA `D7D29DEB...08CCA`, preserving the exact target/helper identities, protected state, and physical `Destination`/`SizeInWords` frame-label exception.
- Manual-coverage currentness reconciled: the pre-command-`000000019882` identity `4376E670...E18E39EE`, post-command-`000000019882` checkpoint `FD7EF245...05FAA6`, pre-command-`000000019890` identities `35B4FAE3...44FC3` / `E401089D...E3163` / `5E04B7C1...C91DC`, post-B008 checkpoints `1E8ADE03...EFCF42` / `B1166F5E...62CE2` / `33826E89...2B2E04`, intermediate checkpoints `400717A7...974BB` / `3E382C55...C3536` / `2AE8504F...AC6EE`, pre-application identities `22BB0BB3...705F2` / `EE896367...74565` / `21886E92...A24E2`, and dated commands-`19980`-through-`19982` application identities `8C8C35AB...29BEDF` / `73685EF3...B7D92` / `995F7753...01C24C` are historical shared-file checkpoints. Current physical identities after unrelated B001 additions are by-memory `C5E4E81C...62BAC5`, `2107677` bytes/`4768` lines; by-class `64862329...85BC03`, `272272` bytes/`625` lines; and by-file `736B2900...B6BFE`, `162964` bytes/`317` lines. UID0001MB remains the exact merged row at by-memory line `3952`, UID000415 and UID000416 remain the exact inserted rows at lines `3955`/`3956`, UID0000C3 remains the exact merged row at by-class line `459`, and UID0000N9 remains the exact merged row at by-file line `234`; stable padding anchors are now by-memory lines `3954`/`3957`.

| Current supervisor-changed manual destination | SHA256 | Bytes | Lines | Applied/validated result |
| --- | --- | ---: | ---: | --- |
| `by-memory/-coverage-report.md` | `C5E4E81C9EBC12C6A0A73D187100657F9406043C2B826C1519B8A21BED62BAC5` | 2107677 | 4768 | Dated command `000000019980` applied/validated the rows; current no-loss readback after unrelated additions has UID0001MB at line `3952` and UID000415/UID000416 at lines `3955`/`3956`. |
| `by-class/-coverage-report.md` | `64862329F2FCE0B5AEF01B349E0D5A5D2F09F0B319C8A9EB173521F5F385BC03` | 272272 | 625 | Dated command `000000019981` applied/validated UID0000C3; the exact row remains current at line `459`. |
| `by-file/-coverage-report.md` | `736B2900338FDFE34C44CD18CF9DF0C7791820D28D42DAB7B5E9DD0691EB6BFE` | 162964 | 317 | Dated command `000000019982` applied/validated UID0000N9; the exact row remains current at line `234`. |
- Generated closure currentness: command `000000019802` CPP/H artifacts are historical stale pre-final-refresh evidence only. Commands `000000019887`, `000000019890`, and tracker-only commands `000000019891` and `000000019928` are dated history. Current reconstruction-state artifacts are command `000000019926`, timestamp `2026-07-30T10:34:57-04:00`; current moving tracker identity is command `000000019933`, timestamp `2026-07-30T11:03:10-04:00`:

| Generated destination | SHA256 | Bytes | Lines | Current disposition / bounded topology |
| --- | --- | ---: | ---: | --- |
| `auto-generated/NexusTK/social/SayInputPanes.cpp` | `88F58B6726D4FD02F7CF5231F6C8D83C25F4A7B74090ABD58A1D2DA4C0CCECE4` | 12896 | 420 | Command19926 header/timestamp exact; UID000414 constructor `92/94`; UID000415 `HandleKeyOrTextEvent(Event *)` `94/95` with `g_pUserPane` previous/next calls; UID000416 current `SaveChatHistoryLine` member call; no `PaneKeyEvent`; UID0001MB `89/93` empty emitter marker. |
| `auto-generated/NexusTK/social/SayInputPanes.h` | `90BD7D03925BC9E342E399782F8474C0A0265DF46FC5BA83ECC24872EDF26BBB` | 722 | 23 | Command19926 header/timestamp exact; UID0000C3 `93/94`; `virtual bool HandleKeyOrTextEvent(Event *event);`; no `PaneKeyEvent`. |
| `auto-generated/NexusTK/ui/dialogs/InputPanes.h` | `33FE0F5D452871C365A3506AC1C8CFD4124E97FBC965772ED198397574EE2895` | 1167 | 36 | Command19926 header/timestamp exact; UID000077 `91/93`; `virtual bool HandleKeyOrTextEvent(Event *event);`; no `PaneKeyEvent`. |
| `auto-generated/-ag-memory-coverage.md` | `6A2DA8391DDE03DDF7949AE430E6E5A538F364C4D0F1D3FAAAB14B7A7F3CD544` | 1419904 | 4949 | Command19926 header/timestamp exact; UID000414, UID000415, and UID000416 are coded through owner/emitter UID0000C3 into SayInputPanes.cpp; UID0001MB retains the same source route without a duplicate body. |
| `auto-generated/-ag-research-tracker.md` | `A1FA9680D296AF86A2BDBB7C6994413256035E5292ADECB4FB42E985B04958D1` | 1679360 | 6633 | Current moving validator-owned identity is command `000000019933`, timestamp `2026-07-30T11:03:10-04:00`. Command19928 and commands19890/19891 tracker identities are bounded historical topology evidence only. UID000414 `92/94`, UID000415 `94/95`, UID000416 `88/90`, UID0001MB `89/93`, and UID0000C3 `93/94` remain the reconstruction facts; report counts/path are moving validator-owned state and are not asserted as durable current truth. |

- B007 did not edit any generated or manual coverage artifact. The supervisor-owned manual changes and command `000000019980` through `000000019982` readbacks are recorded above; historical commands `000000019887`, `000000019890`, `000000019891`, and `000000019928` plus current commands `000000019926` and `000000019933` and their readbacks are supervisor/validator-owned.
- Renamed: none.
- IDA state: B007 remained read-only and performed no mutation/save. Supervisor catalog0372 applied A415-01 through A415-05; the final Gate 2 reaffirmation created byte-identical backup `E:\NTK\Resources\NexusTK\NexusTK.exe.uid000415-gate2b-20260730-113455.i64` at historical SHA `3892BDA8...98D1`, passed exact action/protected readback, and saved current IDB `D7D29DEB...08CCA` successfully.
- Report lifecycle boundary: execution/archive truth is supervisor-owned and authoritative only from the current artifact path plus validator-owned status/history metadata. B007 must never invoke or probe `execute_report` or move the report manually.

## Implementation Tracking Checklist

Initial report-only research/content:

- [x] Exact target path, UID, scope, and current metadata recorded.
- [x] All 33 literal report headings supplied with target-specific content.
- [x] Current target/support documentation and manual coverage surfaces inspected; current physical coverage identities after unrelated B001 additions are by-memory `C5E4E81C...62BAC5`, by-class `64862329...85BC03`, and by-file `736B2900...B6BFE`. Commands-`19980`-through-`19982` application identities `8C8C35AB...29BEDF` / `73685EF3...B7D92` / `995F7753...01C24C`, pre-application identities, intermediate/post-B008 identities, and all earlier identities are explicitly historical. UID000415/UID000416 remain exact at by-memory lines `3955`/`3956`; UID0001MB, UID0000C3, and UID0000N9 exactly match the no-loss merged payloads at lines `3952`, `459`, and `234`; stable by-memory padding anchors remain lines `3954`/`3957`.
- [x] Current authoritative IDB identity and historical prior identity distinguished.
- [x] Exact range, padding, vtable liveness, callers, callees, frame, locals, and bytes recorded.
- [x] Event type/layout and modifier semantics resolved.
- [x] Adjusted receiver, history cursor, and inherited edit child resolved.
- [x] Previous/next/save history helper ownership, signatures, behavior, and caller sets resolved.
- [x] Global identity and UserPane history field resolved.
- [x] Owner/emitter/source placement and no-split disposition resolved.
- [x] Score-limiting blockers researched to implementation-ready conclusions.
- [x] Exact formal target CPP and blank target H disposition supplied.
- [x] Exact class/support declaration/call payloads supplied in formal code shape.
- [x] Historical/stale assumptions and rejected alternatives identified for preservation.
- [x] Atomic C415-001 through C415-073 ledger prepared with canonical actions; ordinary, generated, Gate 2B, and five manual-coverage states transitioned to applied only after physical readback.
- [x] Five deterministic supervisor IDA handoff rows preserve literal historical prestates and catalog0372 applied/current readbacks, including the exact history-helper physical-frame label exception.
- [x] Five exact supervisor-owned manual coverage operations supplied, applied, physically read back, and validated by commands `000000019980` through `000000019982`; no-change rows remain classified.
- [x] Planned serial validator commands and generated closure surfaces listed; command `000000019802` CPP/H artifacts are historical stale pre-final-refresh evidence.
- [x] Wave2/Wave3 material rejected as stale authority.
- [x] Report body made lifecycle-neutral and limited to one declared target.

Callback completion and supervisor-owned work:

- [x] Supervisor Gate 1 accepted exact pre-callback SHA `855632A934BF2D77D6006278B1BE6641AB21EEF116EDCE36212CEC36683A8CC5`.
- [x] Supervisor authorized the bounded ordinary-document callback.
- [x] Accepted target ordinary changes physically applied and read back.
- [x] Accepted SayInputPane class/file/aggregate changes physically applied and read back.
- [x] Accepted UserPane class/file history changes physically applied and read back; final post-B008 stable identities `DB786753...97578` / `54A260E4...7781B` preserve the three helper declarations, `m_chatHistory +0x13eb04`, UserPane.cpp ownership, behavior, callers, and exclusions.
- [x] Accepted global alias/current-identity changes physically applied and read back.
- [x] Accepted submit-child and base-handler support changes physically applied and read back; final post-B008 handler SHA `E63A912F...B5A3E` preserves the exact Event-based base/derived contract.
- [x] After B008's complete callback lease sequence cleared, inspect-only `by-class/LineInputPane.md` stabilized over a sustained no-lease interval at SHA `5C2B543E...BD1E5`, `19245` bytes/`155` lines with `class Event;` and `virtual bool HandleKeyOrTextEvent(Event *event);` still present; B007 made no edit.
- [x] Ledger verification states transitioned only after physical implementation or already-present readback.
- [x] Ten changed ordinary paths validated serially across eleven invocations with generated refresh disabled; all final path states exited `0` with `ok:1`.
- [x] Supervisor Gate 2A claim-by-claim verification passed C415-001 through C415-073 before this final report-only reconciliation.
- [x] Supervisor Gate 2B applied and verified A415-01 through A415-05 under catalog0372, then reaffirmed exact action/protected state with byte-identical pre-reaffirmation backup `3892BDA8...98D1`; required `idb_save` returned `ok:true` and produced current shared IDB `D7D29DEB...08CCA` without additional semantic mutation.
- [x] Supervisor applied and validated all five manual coverage operations under commands `000000019980`, `000000019981`, and `000000019982`, each exit `0`, `ok:1`, generated refresh disabled.
- [x] Current generated checkpoint command `000000019926` and tracker command `000000019933` were physically read back with exact CPP/H/generated-memory/tracker hashes, headers, scores, methods, calls, absence constraints, and empty-emitter topology; tracker command `000000019928` and commands `000000019890`, `000000019891`, and `000000019887` are preserved as dated history, and lifecycle-time authority remains supervisor-owned.
- [ ] Fresh final report/ordinary/IDA/manual/generated gates.
- [x] Timeless boundary: B007 does not run/probe `execute_report`, move/archive the report, or claim supervisor lifecycle completion.

READY_FOR_SUPERVISOR_GATE1_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000019991","destination_path":"executed-b-agent-research/B007/000415-SayInputPaneHandleKeyInput-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/000415-SayInputPaneHandleKeyInput-source-quality.md","timestamp":"2026-07-30T11:50:37-04:00","uid":"000415"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
