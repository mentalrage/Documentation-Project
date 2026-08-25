** TARGET-REPORT-UID:000426 **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID000426 MapPaneAllowsMovementStatusTag Source Quality Research


## Finalized Report / Current Recommendation

- Current recommendation and ordinary state: retain `bool MapPane::AllowsMovementStatusTag() const` at `0x005055d0-0x005055db`; the accepted ordinary callback physically installs `return !m_movementStatusTagDisabled;`, canonical bool field documentation, full lifecycle/caller evidence, and target score `92/94`.
- Final disposition: [UID:000426] remains a reconstructable MapPane member definition owned and emitted by [UID:00007Q] in [UID:0000L3] `NexusTK/map/MapPane.cpp`. It needs no split, new class, new file, additional target UID, or H-channel declaration.
- Ordinary callback result: C001-C044 and C053-C060 are physically applied, verified already present, or excluded with the report's exact reason across 24 changed ordinary files plus protected UID000425/UID000427 readback. Commands `000000020253` through `000000020289`, followed by the bounded C043/C044 documentation reconciliations `000000020345` and `000000020346`, validated every changed file serially with generated refresh disabled.
- Supervisor Gate 2B result: catalog0381 applied and verified C043-C044 at dated checkpoint `5F2679A7...9A21`; the bounded current catalog0382 `B7CC899D...58277` reread found A00/A01 and P00-P06 unchanged. The target and class ordinary pages now explicitly preserve that action/readback evidence; B008 did not mutate or save IDA.
- Supervisor closure result: command `000000020347` applied and read back the exact C045 manual by-memory row, and foreground autogen command `000000020348` resolved C049-C050 while refreshing C051-C052 to current generated identities. All C001-C060 evidence/implementation rows are now applied, already present, historicalized, or excluded with reason. Only fresh exact-artifact gates and lifecycle execution/archive remain supervisor-owned.
- Confidence: very strong for behavior, type, range, callers, source placement, ownership, and field polarity; strong for the inferred private field lexeme.

## Supporting Research

- This is a new dedicated report for [UID:000426]. The executed B009 [UID:0001AP] family report established the child, baseline `AllowsMovementStatusTag` spelling, `87/90` recommendation, and rejection of `IsDayMode`, but it did not exhaust the `+0x40e` writer lifecycle, all 24 direct call sites, the constructor's packed initializer, the precise packet-bit polarity, or the final private field type/name.
- Executed caller reports for [UID:0003U6], [UID:0003UP], [UID:0003UQ], [UID:0003UX], and [UID:0003UY] independently establish movement-history and direction high-bit use. Executed status-pane reports for [UID:0004T6], [UID:0004T7], [UID:0004TP], [UID:0004TQ], [UID:000499], and [UID:00049A] independently establish the signed-direction compatibility rule.
- Fresh bounded IDA MCP work used session `f608d7c2`. The report-construction checkpoint `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, SHA256 `4B5F2EC3F83106BAC18640D079C51CD2E2FB56797577EFE7D994EF483D9A696A`, `143192707` bytes, last write `2026-07-31T04:26:38.9922636-04:00`, is dated history.
- The catalog0380-era saved IDB SHA256 `1BC3C43BCEDB92B9BF8950DA6E6DE759C3FA44B50C6A2FA0458CE129B6800CFD`, `143195497` bytes, physical last write `2026-07-31T09:35:32.8233834Z`, is now a dated pre-Gate2B checkpoint.
- Catalog0381 saved the applied UID000426 Gate 2B transaction as dated checkpoint SHA256 `5F2679A7C6BFF2CD3E91FE59BDCBD298C1A233EB7988D838C34C05508FC79A21`, `143192720` bytes, at `2026-07-31T05:57:03.6144571-04:00`. Unrelated catalog0382 later advanced the authoritative shared IDB to SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, `143192751` bytes, saved `2026-07-31T06:21:13.3464834-04:00`. Fresh bounded read-only session `f608d7c2` checks against B7CC confirm A00/A01 exact poststate and no drift in protected P00-P06. Shared-IDB authority remains moving and must be rechecked if a later supervisor transaction advances it again.
- MCP health was `status:ok`, module `NexusTK.exe`, image base `0x00400000`, Hex-Rays ready, strings cache ready, and `auto_analysis_ready:false`. Bounded live queries succeeded, so the false auto-analysis flag was context rather than an outage.
- No exact dedicated report with `TARGET-REPORT-UID:000426` existed. Older reports mention this UID as a dependency or as additional family research. A historical RankingDialog report once reused textual UID000426, but validator repair reassigned that unrelated RankingDialog page to UID0004YX; canonical UID000426 is the MapPane predicate.
- Accepted ordinary implementation callbacks were applied on 2026-07-31 without B008 IDA, manual coverage, generated, tracker, or lifecycle mutation. Twenty-four distinct ordinary documents changed; the later C043/C044 reconciliation revisited two of those same destinations to preserve catalog0381 action evidence and catalog0382 no-drift readback. UID000425 and UID000427 boundary claims were already present at same-or-greater detail.
- Lifecycle-neutral status: report execution/archive truth is supervisor-owned and authoritative only from the current report path plus validator-owned status/history metadata.

## Target

- Target UID: `000426`.
- Additional target UIDs: none.
- Declared-target inventory: [UID:000426] `by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md`, sole source-bearing MapPane predicate body.
- Target path: `source-3/project-documentation/by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md`.
- Moving source queue/report row: current physical `auto-generated/-ag-research-tracker.md` has header command `000000020348`, refreshed `2026-07-31T06:53:05-04:00`, SHA256 `3EE8DC45E02014AF8C395B7E0D77A1CF60041ED50653F099B49C77FF8F871805`, `1,687,890` bytes / `6,665` lines. UID000426 remains at line `3185` with `92/94`, score average `93.0`, and `0/0/0`; command `000000020306` is a dated pre-closure tracker checkpoint.
- Current supervisor classification: accepted ordinary and post-IDA ordinary reconciliation callbacks implemented; fresh supervisor Gate 2 verification remains external.
- Current ordinary metadata: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank optional position, exact populated CPP, blank H.

## Current Target State

- Historical pre-callback identity was SHA256 `941884F5DE6FEBDBD7DC7056CFEE378A6E8D3EBBB4C1314532CB1B3A18AC1013`, `2,464` bytes at `87/90`, with `return m_movementGate == 0;`.
- Current target identity after post-IDA reconciliation command `000000020345`: SHA256 `FE4E9F30E12C25B3835834C1DD9059E8FA585C5724DCF7BBD0CEF1675A803AF5`, `11,541` bytes / `119` lines at `92/94`. Command `000000020253` is the earlier ordinary source-quality callback checkpoint.
- Current target C++ is exactly `return !m_movementStatusTagDisabled;`; H remains blank and route metadata remains unchanged.
- The current page now carries exact range/bytes/ABI/frame, 24-call inventory, writer lifecycle, bool/polarity proof, boundary padding, source placement, rejected alternatives, historical assumptions, a dedicated catalog0381-applied/catalog0382-no-drift IDA state section, no-split/no-third-party/Wave2/Wave3 dispositions, and full support links.
- Existing open questions are now resolved:
  - `IsDayMode` is false for this address. Day/night state is adjacent but independent.
  - `IsMovementGateClear` describes lowering rather than source intent.
  - `AllowsMovementStatusTag` matches all consumers and remains the strongest method name.
  - `+0x40e` is a one-byte boolean disable flag, not a generic movement/collision gate.
  - The return type is `bool`.
- Historical stale support is now corrected in ordinary docs:
  - [UID:0002I7] formal CPP uses `m_movementStatusTagDisabled = true;` and documents packed `0x00010001` byte order.
  - [UID:0003TK] formal CPP uses `kEffectMapStateDisableMovementStatusTag` and `m_movementStatusTagDisabled`.
  - [UID:00007Q] declares `bool m_movementStatusTagDisabled` and retains the singular method declaration.
  - [UID:00042K] records the canonical bool and complete constructor/writer/reader lifecycle.
  - [UID:000113] uses `MapPane::AllowsMovementStatusTag()` and preserves raw/alternate names only as rejected history.
- Related target/support docs checked: [UID:00007Q], [UID:0000L3], [UID:0001AP], [UID:0002I7], [UID:0003TK], [UID:00042K], [UID:000425], [UID:0003U6], [UID:0003UP], [UID:0003UQ], [UID:0003UX], [UID:0003UY], [UID:00030L], [UID:000113], [UID:0003AA], [UID:0004T6], [UID:0004T7], [UID:0001NO], [UID:0004TI], [UID:0004TP], [UID:0004TQ], [UID:0001NR], [UID:000499], and [UID:00049A].
- Current artifact/lifecycle state is represented by this report's actual path and validator-owned metadata only.

## Executive Recommendation

- Keep the direct owner [UID:00007Q] `MapPane` and source root [UID:0000L3] `NexusTK/map/MapPane.cpp`.
- Keep the public/private method lexeme `AllowsMovementStatusTag`. It communicates the protocol capability exposed to UserPane and three status-pane generations without exposing the inverted storage representation.
- Rename and retype the private field to `bool m_movementStatusTagDisabled`. The packet's bit `0x02` stores true, the constructor initializes true, and the method returns false while stored true. The name therefore records both domain and polarity.
- The target is now physically `92/94`; the remaining cap is only the unprovable original private lexeme and exact packet-enum spelling, not behavior or source placement.
- The target CPP and exact support formals are physically corrected. Target H remains blank because [UID:00007Q] owns the sole class declaration.
- Do not merge this target with [UID:000425] collision logic, day/night helpers, the [UID:0001AP] aggregate, or any caller source file.

## Supervisor Active Recheck

- The assignment explicitly required a new dedicated report for the uncovered reconstructable by-memory target and required live MCP resolution of the field/name/type/caller/source-placement blockers.
- No split repair is required. The target is already the exact 11-byte function, fenced by six and five bytes of `0xcc` padding.
- Every source-bearing entity in scope has a disposition:
  - target method body: source-ready;
  - class declaration/field: exact support edit;
  - constructor packed initialization: exact support correction;
  - packet writer: exact support correction;
  - all callers: inventoried and classified;
  - predecessor/successor/padding: protected and separate.

## Inference Research Guidance Check

- Binary facts, documentation facts, and inference are separated below. The method range, bytes, prototype, frame, callers, field offset, constructor value, and packet write are direct IDA facts.
- Existing `IsDayMode`, `m_movementGate`, `m_viewportMoveGate`, and `AllowsMovementStatusFlag` labels were treated as uncertain rather than copied forward.
- `AllowsMovementStatusTag` and `m_movementStatusTagDisabled` are source-facing inferences. The former is strongly corroborated by every consumer. The latter is the best descriptive private name for the exact stored polarity.
- `by-structure.md` principles require one body in the exact by-memory child and one declaration/field in the class H emitter, with no aggregate or by-file duplicate body.
- Historical Wave2/Wave3 mentions were not used. Any such archived workflow language is stale under the current skill.

## Heuristic / Inference Reanalysis And Validation

| Issue | Investigation | Best resolution | Classification |
| --- | --- | --- | --- |
| Method name | Checked body, 24 direct calls, all modeled caller families, old reports, target/class/aggregate, UI consumers, collision predecessor, and packet writer. | `AllowsMovementStatusTag` | inferred, very strong |
| `IsDayMode` alternative | Separated BackGroundPane's independent `m_dayNightTargetBrightness > 0.8f` store from its later target call. Checked adjacent `m_dayNightHour` and packet day/night math. | rejected | contradicted |
| Collision alternative | Compared [UID:000425] tri-state collision method, its nine callers, range, and return values with this one-byte predicate and protocol callers. | rejected | contradicted |
| `IsMovementGateClear` alternative | It accurately paraphrases `byte == 0` but does not state the protocol capability and overfits storage lowering. | search/historical alias only | descriptive but weaker |
| Field meaning | Found exactly one constructor packed write, one runtime packet write, and one direct read in the MapPane range. Classified all consumers. | per-map disable flag for movement/status high-bit protocol | inferred from complete lifecycle |
| Field type | Stores are `0/1`; target uses `cmp byte,0; setz al`; IDA and class declaration treat the method as bool; all callers use predicate control flow. | `bool` | high-confidence source type |
| Field name | Compared `m_movementGate`, `m_viewportMoveGate`, generic policy names, and polarity-preserving domain names. | `m_movementStatusTagDisabled` | inferred, strong |
| Return type | Compared `bool`, `unsigned char`, `char`, and enum. No caller consumes non-boolean bits or arithmetic value. | `bool` | direct plus ABI inference |
| Packet-bit name | Packet flag `0x02` makes helper false and blocks high-bit path. | `kEffectMapStateDisableMovementStatusTag` | inferred, strong |
| Source placement | Receiver is `const MapPane *`; neighboring methods and class/file routes are MapPane-owned; all callers are consumers. | `MapPane.cpp`, declaration in `MapPane.h` | very strong |
| Generated mismatch | Historical command `000000020207` MapPane CPP/H rendered the pre-callback field/score state. Foreground autogen command `000000020348` now renders the exact `92/94` method body, canonical class declaration/field, coded memory route, and `92/94` tracker row. | applied/read-back verified; preserve command `000000020207` only as dated stale history | direct moving-artifact closure |
| Manual coverage | Historical manual SHA `6C2C8B45...41B7` lacked UID000426. Supervisor command `000000020347` inserted the accepted row after UID000425. | applied/read-back verified at current manual SHA `5CDCBB4B...53FF`, row 2377 | direct file evidence and physical readback |

- Rejected `SupportsMovementStatusTag`: semantically plausible, but existing project-wide method declarations and callers already use `AllowsMovementStatusTag`, and no evidence justifies a needless method rename.
- Rejected `m_movementStatusTagEnabled`: wrong polarity because stored true makes the method false.
- Rejected `m_allowMovementStatusTag`: wrong polarity for the same reason.
- Rejected `m_disableMovement`: too broad because ordinary movement and collision still operate; only optional status/history tagging and related status UI behavior change.
- No source-quality blocker is deferred. The only remaining uncertainty is the original private lexeme, which cannot be recovered without original symbols/source and does not block realistic source.

## Evidence Standards Used

- Primary evidence: bounded IDA MCP function analysis, decompile, disassembly, raw bytes, stack frame, item boundaries, comments, direct xrefs, type layout, and exact constructor/packet writes.
- Secondary evidence: current ordinary by-* docs, exact formal channels, executed target-family/caller reports, generated CPP/H, generated tracker/coverage, and manual coverage rows.
- Negative evidence: no callee, no additional direct `+0x40e` access in the bounded MapPane code range, no collision caller pattern, no day/night consumer of the result, and no separate source-file/vtable ownership route.
- Evidence ladder: direct bytes and xrefs control behavior; cross-caller agreement controls domain; constructor/writer lifecycle controls field polarity; source-tree and receiver ABI control placement; naming is inferred only after those facts.
- Tool limitation: `xrefs_to_field` does not index the MapPane member in this IDB. A bounded rendered-disassembly scan found the direct read/write set and the constructor's packed store independently.

## Evidence Checked

- IDA MCP:
  - `server_health` for session `f608d7c2`;
  - `analyze_function`, `func_profile`, `decompile`, `disasm`, `stack_frame`, `get_comments`, `inspect_items`, `get_bytes`, `xref_query`, `lookup_funcs`, `type_inspect`, and `type_query`;
  - bounded listing search for `40Eh]` and `40Ch]` inside the MapPane code family;
  - bounded raw helper checks for the two unmodeled OldUserStatusPane call sites.
  - historical post-callback/catalog0380 bounded no-drift recheck against pre-Gate2B IDB `1BC3C43B...00CFD`;
  - dated catalog0381 action checkpoint `5F2679A7...9A21`, followed by the current bounded no-drift readback against catalog0382 saved IDB `B7CC899D...58277`: exact A00 function comment, A01 UDT member name/type, target/protected function identities/prototypes/comments, target/padding bytes, 24 xrefs, constructor/packet-writer identities and comment channels, and MapPane `+0x40c-+0x40f` member layout.
- Ordinary documentation:
  - target, class, file, aggregate, constructor, packet writer, layout, collision predecessor, direct caller pages, status-pane aggregates/children, and legacy raw helpers;
  - current hashes recorded in Recommended Support Doc Changes.
- Old reports:
  - B009 UID0001AP family report;
  - B005 UID000425 and UID0003UP;
  - B001 UID0003U6;
  - B003 UID0003UX;
  - B008 UID0003UY;
  - relevant status-pane/legacy reports.
- Generated/manual:
  - dated stale command `000000020207` MapPane CPP/H retained as pre-closure evidence;
  - supervisor manual command `000000020347` and current by-memory coverage SHA `5CDCBB4B...53FF`, with UID000426 at row 2377 after UID000425 row 2376;
  - current foreground autogen command `000000020348`, refreshed `2026-07-31T06:53:05-04:00`, covering MapPane CPP/H, generated memory coverage, and the independently moving research tracker;
  - current by-class, by-file, and by-struct manual coverage reports.
- Negative checks:
  - no dedicated `TARGET-REPORT-UID:000426`;
  - no active competing goal/report/lease;
  - no day-mode or collision semantics in any target caller;
  - no arithmetic/non-boolean use of return value;
  - no extra direct field reads/writes in bounded MapPane listing.
- No required evidence source failed. The broad full-image search path was not used.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C001 | 000426 | Function is exact half-open range `0x005055d0-0x005055db`, 11 bytes, three instructions, one block. | exact | live analyze/disasm/bytes; current target SHA `FE4E9F30...3AF5` | `by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md` / Evidence | incorporate | applied |
| C002 | 000426 | Exact bytes are `80 B9 0E 04 00 00 00 0F 94 C0 C3`. | exact | live get_bytes; current target Evidence | `by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md` / Evidence | incorporate | applied |
| C003 | 000426 | Exact signature is `bool __thiscall(const MapPane *this)` with ECX receiver and only `__return_address` in the frame. | exact | func_profile/stack_frame; current target Evidence | `by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md` / ABI | incorporate | applied |
| C004 | 000426 | Body compares byte `this+0x40e` with zero and returns `setz al`; it has no callees. | exact | disasm/analyze_function; current target Behavior | `by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md` / Behavior | incorporate | applied |
| C005 | 000426 | Six `0xcc` bytes at `0x5055ca-0x5055d0` and five at `0x5055db-0x5055e0` are protected padding. | exact | inspect_items/get_bytes; current target Boundaries | `by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md` / Boundaries | incorporate | applied |
| C006 | 000426 | There are 24 direct code xrefs across 14 modeled caller functions plus two raw retained helper bodies. | exact | xref_query; current target Cross-References/caller prose | `by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md` / Callers | incorporate | applied |
| C007 | 000426 | Source method name remains `AllowsMovementStatusTag`; stale `IsDayMode` and storage-shaped `IsMovementGateClear` are rejected. | very strong | caller/domain analysis; current Naming/Historical Assumptions | `by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md` / Naming | incorporate | applied |
| C008 | 000426 | Source return type is `bool`, not byte/char/enum. | very strong | setz ABI and predicate-only callers; current Evidence | `by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md` / Type | incorporate | applied |
| C009 | 000426 | Best source body is `return !m_movementStatusTagDisabled;`. | strong | complete field lifecycle; exact current formal CPP | `by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md` / formal CPP | incorporate | applied |
| C010 | 000426 | Target H remains blank because the class page owns the declaration. | exact | current target H blank; class declaration singular | `by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md` / formal H | already-present | already-present |
| C011 | 000426 | Owner/emitter stay UID00007Q, reconstructable true, optional position blank. | exact | current target header readback | `by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md` / metadata | already-present | already-present |
| C012 | 000426 | Accepted target score movement `87/90 -> 92/94` is physically applied. | strong | command `000000020253`, exit 0, ok 1 | `by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md` / metadata | incorporate | applied |
| C013 | 00007Q | MapPane method declaration `bool AllowsMovementStatusTag() const;` is already exact and singular. | exact | current class H readback | `by-class/MapPane.md` / formal H method list | already-present | already-present |
| C014 | 00007Q | Ordinary formal H now uses `bool m_movementStatusTagDisabled` at `+0x40e` instead of `unsigned char m_movementGate`. | strong | current class SHA `1F910109...314BF`; source callback command `000000020254`, post-IDA reconciliation command `000000020346` | `by-class/MapPane.md` / formal H fields | incorporate | applied |
| C015 | 00007Q | Class behavior/layout prose must record packet bit `0x02` as a disable flag and reject day/collision meanings. | strong | current class UID000426 section/layout table | `by-class/MapPane.md` / layout and UID000426 sections | incorporate | applied |
| C016 | 0000L3 | MapPane.cpp remains the single source route; record target method, field polarity, constructor, and packet-writer relationship. | very strong | current file UID000426 source-route section | `by-file/MapPane.md` / UID000426 source route | incorporate | applied |
| C017 | 0001AP | Aggregate child row should state inverse disable-flag semantics and full caller-family role without emitting duplicate code. | strong | current aggregate row/change history | `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md` / UID000426 child | incorporate | applied |
| C018 | 0002I7 | Constructor packed dword `0x00010001` initializes `+0x40e` to true, not false. | exact | current constructor Behavior/field table | `by-memory/0x00504110-0x00504521.MapPaneInitialize.md` / Evidence | incorporate | applied |
| C019 | 0002I7 | Formal CPP now replaces stale `m_movementGate = 0;` with exact target-field initialization `m_movementStatusTagDisabled = true;`. | exact behavior, strong lexeme | current constructor formal CPP; command `000000020257` | `by-memory/0x00504110-0x00504521.MapPaneInitialize.md` / formal CPP | incorporate | applied |
| C020 | 0003TK | Packet flags byte bit `0x02` is the sole runtime writer and sets the disable field. | exact | current packet behavior/runtime order | `by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md` / Behavior | incorporate | applied |
| C021 | 0003TK | Formal CPP enum token should become `kEffectMapStateDisableMovementStatusTag`. | strong | exact current formal CPP; command `000000020258` | `by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md` / formal CPP enum | incorporate | applied |
| C022 | 0003TK | Formal CPP assignment should use `m_movementStatusTagDisabled`. | strong | exact current formal CPP; command `000000020258` | `by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md` / formal CPP assignment | incorporate | applied |
| C023 | 00042K | Layout row `+0x40e` should be canonical bool `m_movementStatusTagDisabled` with constructor/writer/read lifecycle. | strong | current layout SHA `5818F6CB...FD4A`; command `000000020259` | `by-type/by-struct/MapPaneLayout.md` / layout table | incorporate | applied |
| C024 | 000425 | Collision predecessor is a separate tri-state method and supplies no semantic ownership for UID000426. | exact | physical SHA unchanged `D91F5BE6...F91A3`; boundary text already exact | `by-memory/0x00505430-0x005055ca.MapPaneCheckMovementCollision.md` / successor boundary | already-present | already-present |
| C025 | 00030L | BackGroundPane callback separately computes brightness readiness and then uses the movement-status predicate under config gating. | exact | current ordinary SHA `284CB506...8748`; command `000000020260` | `by-memory/0x00467510-0x0046782f.BackGroundPaneCoreMethods.md` / callback behavior | incorporate | applied |
| C026 | 000113 | ConnStatusPane replaces raw target aliases with `MapPane::AllowsMovementStatusTag()` and records the per-map disable semantics. | strong | current ordinary SHA `BA7063D7...3B14`; command `000000020261` | `by-memory/0x00494520-0x004949df.ConnStatusPane.md` / message handler evidence | incorporate | applied |
| C027 | 0003U6 | ProcessMovement uses the predicate plus config to set high-bit history tags and status-event direction bytes, with the exact disable-field cross-link. | exact | current ordinary SHA `8053BAA1...2C10`; command `000000020262` | `by-memory/0x005a2e00-0x005a36f0.UserPaneProcessMovement.md` / movement status gate | incorporate | applied |
| C028 | 0003UP | Normal reply handler uses the predicate/config gate for tagged direction/history reconciliation and records the per-map disable-field polarity. | exact | current ordinary SHA `BF4B4951...51A9`; command `000000020263` | `by-memory/0x005ab090-0x005ab410.UserPaneHandleMovementReplyPacket.md` / capability gate | incorporate | applied |
| C029 | 0003UQ | Extended reply handler uses the same predicate/config gate with its distinct reply timing and records the per-map disable-field polarity. | exact | current ordinary SHA `4FD119A2...3653`; command `000000020265` | `by-memory/0x005ab410-0x005ab75d.UserPaneHandleExtendedMovementReplyPacket.md` / capability gate | incorporate | applied |
| C030 | 0003UX | Waypoint sender sets history index bit `0x80` only when config and predicate both pass and cross-links the exact disable field. | exact | current ordinary SHA `8EB498F5...CBC8`; final command `000000020287` | `by-memory/0x005ac7e0-0x005ac99b.UserPaneSendMovementWaypointPacket.md` / packet tag | incorporate | applied |
| C031 | 0003UY | Face-direction sender uses the same high-bit history-index capability gate and cross-links the exact disable field. | exact | current ordinary SHA `5F362231...ED7`; final command `000000020289` | `by-memory/0x005ac9a0-0x005acad5.UserPaneSendFaceDirectionPacket.md` / packet tag | incorporate | applied |
| C032 | 0003AA | UserStatusPane packet event records the two direct predicate calls for movement packet variants. | exact | current ordinary SHA `E447943F...9CC3`; command `000000020269` | `by-memory/0x005b8700-0x005b8a0c.UserStatusPaneHandlePacketEvent.md` / caller evidence | incorporate | applied |
| C033 | 0004T6 | Legacy movement-step path requires tagged negative direction and strips `0x80` while the feature is active, with the exact predicate cross-link. | exact | current ordinary SHA `F09D6314...BE66`; command `000000020270` | `by-memory/0x005ba1a0-0x005ba31c.UserStatusPaneApplyLegacyMovementStep.md` / gate behavior | incorporate | applied |
| C034 | 0004T7 | Alternate legacy movement-step path has the same per-map/config tag rule and exact predicate cross-link. | exact | current ordinary SHA `B1581588...19F`; command `000000020272` | `by-memory/0x005ba320-0x005ba49c.UserStatusPaneApplyLegacyMovementStepAlt.md` / gate behavior | incorporate | applied |
| C035 | 0004TI | UserStatusPane2 event handler records the two direct predicate calls for movement packet variants. | exact | current ordinary SHA `433D5B08...E999`; command `000000020274` | `by-memory/0x005bac80-0x005baf64.UserStatusPane2HandlePacketEvent.md` / caller evidence | incorporate | applied |
| C036 | 0004TP | UserStatusPane2 legacy step records predicate/config and signed high-bit direction semantics with exact field polarity. | exact | current ordinary SHA `21C19361...040F`; command `000000020276` | `by-memory/0x005bc180-0x005bc2cc.UserStatusPane2ApplyLegacyMovementStep.md` / gate behavior | incorporate | applied |
| C037 | 0004TQ | UserStatusPane2 alternate step records the same predicate/config rule with exact field polarity. | exact | current ordinary SHA `C1494803...0609`; command `000000020278` | `by-memory/0x005bc2d0-0x005bc41c.UserStatusPane2ApplyLegacyMovementStepAlt.md` / gate behavior | incorporate | applied |
| C038 | 0001NR | OldUserStatusPane router records two modeled target calls and routes two retained raw movement helpers. | exact | current ordinary SHA `26FFF652...607`; command `000000020283` | `by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md` / router evidence | incorporate | applied |
| C039 | 000499 | Raw retained helper call at `0x5bf576` uses the same feature gate before signed-direction handling and is tied to the exact predicate lifecycle. | exact | current ordinary SHA `D3FC0809...613A`; command `000000020285` | `by-memory/0x005bf520-0x005bf670.OldUserStatusPaneApplyLegacyMovementStep.md` / gate behavior | incorporate | applied |
| C040 | 00049A | Raw retained alternate helper call at `0x5bf6c6` uses the same feature gate and is tied to the exact predicate lifecycle. | exact | current ordinary SHA `429141F7...6BA1`; command `000000020286` | `by-memory/0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt.md` / gate behavior | incorporate | applied |
| C041 | 0001NO | UserStatusPane2 aggregate cross-links the exact MapPane capability predicate without becoming an emitter. | strong | current ordinary SHA `92F45065...4F21`; command `000000020280` | `by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md` / movement gate summary | incorporate | applied |
| C042 | 000426 | Target function IDA name and prototype are already source-quality and collision-free. | exact | accepted Gate 1 IDA prestate; no B008 IDA mutation | `by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md` / IDA status | already-present | already-present |
| C043 | 000426 | Target function regular comment is the exact packet-disable/high-bit consumer explanation. | strong | catalog0381 applied at dated IDB `5F2679A7...9A21`; current catalog0382 IDB `B7CC899D...58277` bounded readback shows no drift; ordinary SHA `FE4E9F30...3AF5`, command `000000020345` | `by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md` / IDA Applied State | incorporate | applied |
| C044 | 00007Q | IDA MapPane UDT member `+0x40e` is renamed/retyped to `bool m_movementStatusTagDisabled`. | strong | catalog0381 applied at dated IDB `5F2679A7...9A21`; current catalog0382 IDB `B7CC899D...58277` bounded readback shows no drift; ordinary SHA `1F910109...314BF`, command `000000020346` | `by-class/MapPane.md` / UID000426 Movement-Status Tag Policy Contract | incorporate | applied |
| C045 | 000426 | Manual by-memory coverage carries the exact accepted UID000426 row immediately after UID000425. | exact | supervisor command `000000020347`; current manual SHA `5CDCBB4B...53FF`, `2,119,450` bytes / `4,788` lines; UID000425 row 2376 and UID000426 row 2377 physically read back | `by-memory/-coverage-report.md` / MapPane aggregate children | incorporate | applied |
| C046 | 00007Q | Manual class row remains `93%`; no score/path replacement is required for this callback. | exact | current class coverage SHA `9B8B7753...5033`, row 302 | `by-class/-coverage-report.md` / UID00007Q row | already-present | already-present |
| C047 | 0000L3 | Manual file row remains `92%`; no path/score replacement is required. | exact | current file coverage SHA `E71703BB...4126`, row 156 | `by-file/-coverage-report.md` / UID0000L3 row | already-present | already-present |
| C048 | 00042K | Manual struct row remains `93%`; no score/path replacement is required. | exact | current struct coverage SHA `A5567B78...1496`, row 70 | `by-type/by-struct/-coverage-report.md` / UID00042K row | already-present | already-present |
| C049 | 000426 | Foreground autogen command `000000020348` resolves historical command `000000020207` CPP drift and renders the exact UID000426 `92/94` definition once. | exact | current CPP SHA `D6D7740A...8FB7`, `159,505` bytes / `4,776` lines; UID block lines 599-603; canonical field uses physically read back | `auto-generated/NexusTK/map/MapPane.cpp` / UID000426 generated block | reject-stale | applied |
| C050 | 00007Q | Foreground autogen command `000000020348` resolves historical command `000000020207` H drift and renders the canonical method declaration and bool field. | exact | current H SHA `3493BD4B...E228`, `12,861` bytes / `366` lines; method line 105 and `bool m_movementStatusTagDisabled` line 327 physically read back | `auto-generated/NexusTK/map/MapPane.h` / UID00007Q generated declaration/layout | reject-stale | applied |
| C051 | 000426 | Command `000000020348` tracker row renders the current target at `92/94`, average `93.0`, and `0/0/0`. | exact | current tracker SHA `3EE8DC45...1805`, `1,687,890` bytes / `6,665` lines, line 3185 | `auto-generated/-ag-research-tracker.md` / UID000426 row | already-present | already-present |
| C052 | 000426 | Command `000000020348` generated memory coverage routes UID000426 as coded through UID00007Q. | exact | current generated-memory SHA `C2D261C9...791C`, `1,428,860` bytes / `4,978` lines, line 1453 | `auto-generated/-ag-memory-coverage.md` / UID000426 row | already-present | already-present |
| C053 | 000426 | No split, merge, child creation, or reclassification is needed. | exact | item boundaries and physically verified source route | `by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md` / range analysis | not-applicable | excluded-with-reason |
| C054 | 000426 | No third-party import applies because this is NexusTK project member code. | exact | project-owned MapPane method and source route | `by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md` / formal disposition | not-applicable | excluded-with-reason |
| C055 | 000426 | Historical `IsDayMode`, raw byte-gate names, and copied RankingDialog UID collision remain documented as rejected history. | strong | current target SHA `FE4E9F30...3AF5` | `by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md` / Historical assumptions | historicalize | applied |
| C056 | 0002I7 | Constructor IDA name/prototype cleanup belongs to UID0002I7 and must not be mutated through this target. | exact | current constructor ordinary SHA `32AFEABA...BFD0`; no IDA mutation | `by-memory/0x00504110-0x00504521.MapPaneInitialize.md` / protected dependency | incorporate | applied |
| C057 | 0003TK | Packet-handler IDA identity/comment are preserved while only the ordinary source-facing member and enum names change. | exact | current packet ordinary SHA `D4375548...9C18`; no IDA mutation | `by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md` / protected dependency | incorporate | applied |
| C058 | 000425 | Predecessor code and six-byte padding remain protected from target expansion. | exact | unchanged physical SHA `D91F5BE6...F91A3` | `by-memory/0x00505430-0x005055ca.MapPaneCheckMovementCollision.md` / boundaries | already-present | already-present |
| C059 | 000427 | Successor code and five-byte preceding padding remain protected from target expansion. | exact | unchanged physical SHA `1D00B382...87B` | `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md` / boundaries | already-present | already-present |
| C060 | 000426 | Wave2/Wave3 material supplies no current evidence and remains excluded. | exact | current target Evidence standards | `by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md` / Evidence standards | reject-stale | excluded-with-reason |

## Positive Evidence Summary

- The function is only 11 bytes and implements exactly one boolean predicate.
- The direct access lifecycle is closed:
  - constructor packed write initializes the byte to one;
  - opcode-`0x15` map-state packet writes `(flags & 0x02) != 0`;
  - this method is the sole direct read in the bounded MapPane range.
- All 24 direct call sites agree on movement/status protocol behavior.
- Senders set history/status bit `0x80`; receivers and legacy status panes require and strip that bit while the capability is active.
- BackGroundPane and ConnStatusPane use the same predicate only in branches gated by `m_mapMovementStatusOption`.
- Day/night state is adjacent but separately read/written; collision is a separate predecessor with tri-state result and unrelated callers.
- Class/file/aggregate and binary neighborhood all agree on MapPane ownership.

## IDA MCP Facts

- Currentness checkpoint: authoritative catalog0382 saved IDB SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, `143192751` bytes, saved `2026-07-31T06:21:13.3464834-04:00`, live session `f608d7c2`. Catalog0381 checkpoint `5F2679A7...9A21`, `1BC3C43B...00CFD`, and `4B5F2EC3...A696A` are dated history. Bounded `server_health`, `lookup_funcs`, `func_profile`, `get_comments`, `inspect_items`, `get_bytes`, `xrefs_to`, `stack_frame`, and `type_inspect` calls repeated the complete A00/A01 and P00-P06 target/protected readback against B7CC without mutation or drift.
- Function:
  - start `0x005055d0`, end `0x005055db`, size `0x0b`;
  - current name `MapPane_AllowsMovementStatusTag`;
  - current prototype `bool __thiscall(const MapPane *this)`;
  - three instructions, one basic block, cyclomatic complexity one;
  - no callees.
- Disassembly:
  - `0x005055d0 cmp byte ptr [ecx+40Eh], 0`;
  - `0x005055d7 setz al`;
  - `0x005055da retn`.
- Frame: only `__return_address` at `+0`, size four, type `_UNKNOWN *`; no stack arguments or locals.
- Current post-Gate2B comment channels:
  - address regular: absent;
  - address repeatable: absent;
  - function regular: `Source: bool MapPane::AllowsMovementStatusTag() const; returns true when effect-map-state packet flag 0x02 is clear. Callers combine it with Config::m_mapMovementStatusOption to gate movement-history/status high-bit tags and related status UI handling.`;
  - function repeatable: absent.
- `MapPane` UDT:
  - ordinal `614`, size `2320` / `0x910`;
  - `+0x40c m_mapTransitionState unsigned __int8`;
  - `+0x40d m_weatherMode unsigned __int8`;
  - `+0x40e m_movementStatusTagDisabled bool`;
  - `+0x40f m_dayNightHour unsigned __int8`.
- Constructor:
  - current function `sub_504110`, range `0x00504110-0x00504521`;
  - at `0x0050429c`, `mov dword ptr [this+0x40c], 0x00010001`;
  - little-endian byte result is `01 00 01 00`, so `+0x40e` starts true.
- Runtime writer:
  - current function `MapPane_HandleEffectMapStatePacket`, range `0x005104d0-0x00510958`;
  - current prototype `bool __thiscall(MapPane *this, const unsigned __int8 *packet)`;
  - at `0x00510771`, stores `(packetFlags & 0x02) != 0` to `+0x40e`;
  - address regular/repeatable comments at the store are absent;
  - function regular comment is the current exact opcode-`0x15` packet summary; function repeatable absent.
- Bounded rendered-listing searches found only target read `0x5055d0`, packet write `0x510771`, and constructor packed write `0x50429c` for the lifecycle.
- Direct target xrefs: 24, enumerated below.
- Protected no-drift result:
  - P00 remains `sub_505430`, size `0x19a`, prototype `int __thiscall(int this, int, int, char)`, with four comment channels absent;
  - P01/P02 remain exact six-byte/five-byte `0xcc` data items with blank comments;
  - P03 remains `MapPane__ApplyMovementSubstepScroll`, size `0x65`, prototype `bool __thiscall(MapPane *this, unsigned __int8 direction)`, only its accepted function-repeatable comment present;
  - P04 remains `sub_504110`, size `0x411`, prototype `int __thiscall(int this, int, int)`, blank entry/store comments, and packed write instruction starting at `0x50429c`;
  - P05 remains `MapPane_HandleEffectMapStatePacket`, size `0x488`, exact packet prototype and function-regular comment, with store-address comments absent at `0x510771`;
  - P06 adjacent UDT members remain `+0x40c m_mapTransitionState`, `+0x40d m_weatherMode`, and `+0x40f m_dayNightHour`, each one byte, around the exact applied `+0x40e m_movementStatusTagDisabled bool` poststate.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00505430-0x005055ca` | [UID:000425] MapPaneCheckMovementCollision | predecessor tri-state collision method | true | UID00007Q | 88/90 | separate/protected |
| `0x005055ca-0x005055d0` | ignored padding | six `0xcc` bytes | no source | UID0001AP | 100 | protected |
| `0x005055d0-0x005055db` | [UID:000426] target | const bool movement-status capability predicate | true | UID00007Q | 92/94 (historical pre-callback 87/90) | source-ready |
| `0x005055db-0x005055e0` | ignored padding | five `0xcc` bytes | no source | UID0001AP | 100 | protected |
| `0x005055e0-0x00505645` | [UID:000427] MapPaneApplyMovementSubstepScroll | successor viewport substep method | true | UID00007Q | 88/91 | separate/protected |
| `MapPane +0x40e` | [UID:00042K] layout support | bool disable flag | layout support | UID00007Q | 93/94 | rename/retype support |
| `0x00504110-0x00504521` | [UID:0002I7] constructor | packed initial true writer | true | UID00007Q | 89/91 | formal correction |
| `0x005104d0-0x00510958` | [UID:0003TK] packet handler | sole runtime writer from bit `0x02` | true | UID00007Q | 92/94 | formal correction |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0046763c` | `sub_4675E0`, BackGroundPane callback | For event codes `4,8,0x0b,0x15,0x26`, config plus predicate invalidates background state; independent brightness readiness write is not target semantics. |
| `0x004946fd` | `sub_4946C0`, ConnStatusPane message handler | For `4,0x0b,0x15,0x26`, config plus predicate forces connection frame `4`; otherwise latency frame update remains active. |
| `0x005a3257` | UserPane_ProcessMovement | Waypoint movement-history tag gate. |
| `0x005a342f` | UserPane_ProcessMovement | Normal movement-history tag gate. |
| `0x005a34ff` | UserPane_ProcessMovement | Opcode-`0x0b` status-event direction high-bit gate. |
| `0x005a3612` | UserPane_ProcessMovement | Opcode-`0x26` status-event direction high-bit gate. |
| `0x005ab105` | UserPane_HandleMovementReplyPacket | Capability branch before reply/history reconciliation. |
| `0x005ab1b0` | UserPane_HandleMovementReplyPacket | Tagged-direction branch selection. |
| `0x005ab485` | UserPane_HandleExtendedMovementReplyPacket | Capability branch before extended reply reconciliation. |
| `0x005ab511` | UserPane_HandleExtendedMovementReplyPacket | Tagged-direction branch selection. |
| `0x005ac80f` | UserPane_SendMovementWaypointPacket | Sets history-index bit `0x80` only when config and predicate pass. |
| `0x005ac9d8` | UserPane_SendFaceDirectionPacket | Same high-bit history-index gate for face-direction packet. |
| `0x005b8818` | UserStatusPane_HandlePacketEvent | Opcode-`0x0b` movement status tag interpretation. |
| `0x005b88cb` | UserStatusPane_HandlePacketEvent | Opcode-`0x26` movement status tag interpretation. |
| `0x005ba206` | UserStatusPane_ApplyLegacyMovementStep | Requires negative/tagged direction and strips bit `0x80` while enabled. |
| `0x005ba386` | UserStatusPane_ApplyLegacyMovementStepAlt | Same rule for alternate legacy packet. |
| `0x005bad61` | UserStatusPane2_HandlePacketEvent | Opcode-`0x0b` movement status tag interpretation. |
| `0x005bae14` | UserStatusPane2_HandlePacketEvent | Opcode-`0x26` movement status tag interpretation. |
| `0x005bc1d6` | UserStatusPane2_ApplyLegacyMovementStep | Requires and strips high-bit direction while enabled. |
| `0x005bc326` | UserStatusPane2_ApplyLegacyMovementStepAlt | Same rule for alternate packet. |
| `0x005bdd8d` | `sub_5BDCB0`, OldUserStatusPane router | Opcode-`0x0b` movement status route. |
| `0x005bde40` | `sub_5BDCB0`, OldUserStatusPane router | Opcode-`0x26` movement status route. |
| `0x005bf576` | raw UID000499 body, no modeled function | Retained legacy step applies predicate/config signed-high-bit rule. |
| `0x005bf6c6` | raw UID00049A body, no modeled function | Retained alternate applies the same rule. |
| none | target callees | No callee; source body is a direct member read. |

## Documentation Evidence And IDA Status

- The accepted ordinary callback now records the exact `AllowsMovementStatusTag` method, `bool m_movementStatusTagDisabled` field, inverse polarity, constructor/packet-writer lifecycle, and caller families in the target/class/file/aggregate/layout/caller destinations.
- Constructor formal CPP now reflects the machine bytes with `m_movementStatusTagDisabled = true;`.
- Packet-handler and layout formals now name bit `0x02` as `kEffectMapStateDisableMovementStatusTag` and the canonical bool field.
- ConnStatusPane now uses `MapPane::AllowsMovementStatusTag()`; raw/alternate aliases remain only as rejected historical evidence.
- UserPane and all three status-pane generations now retain their exact high-bit behavior and cross-link the per-map disable field without changing source ownership.
- IDA status is current through authoritative catalog0382 checkpoint `B7CC899D...58277`: catalog0381's dated `5F2679A7...9A21` A00/A01 transaction remains applied, and bounded read-only checks found no drift in the target or P00-P06 protected state. The target's `## IDA Applied State` and the class's `## UID000426 Movement-Status Tag Policy Contract - 2026-07-31` now record the exact action-time comment/member state and current no-drift result; the file and UID0001AP aggregate were inspected and already contained no stale future-action wording.
- Historical command `000000020207` left MapPane CPP/H behind the ordinary target. Foreground autogen command `000000020348`, refreshed `2026-07-31T06:53:05-04:00`, resolves that drift and is current across all four closure surfaces:
  - `auto-generated/NexusTK/map/MapPane.cpp`, SHA256 `D6D7740AE18AA2568CC39A0EA1F15F5B32DC20023372085EB10CE8CCA0398FB7`, `159,505` bytes / `4,776` lines, renders the UID000426 `92/94` marker at line 599 and the exact `bool MapPane::AllowsMovementStatusTag() const` body with `return !m_movementStatusTagDisabled;` at lines 600-603;
  - `auto-generated/NexusTK/map/MapPane.h`, SHA256 `3493BD4BEFB80C146C0A700021C3534BB95DE7C0A455F1531B1A5EF2240EE228`, `12,861` bytes / `366` lines, renders the singular method declaration at line 105 and canonical `bool m_movementStatusTagDisabled` field at line 327;
  - `auto-generated/-ag-research-tracker.md`, SHA256 `3EE8DC45E02014AF8C395B7E0D77A1CF60041ED50653F099B49C77FF8F871805`, `1,687,890` bytes / `6,665` lines, renders current `92/94`, average `93.0`, and `0/0/0` at line 3185;
  - `auto-generated/-ag-memory-coverage.md`, SHA256 `C2D261C91496DD1C3C264766554D815C121F0465BCCD798F305D51A5F48D791C`, `1,428,860` bytes / `4,978` lines, routes the target as coded through UID00007Q at line 1453.
- Current generated topology is nonduplicating and fully closed: MapPane.cpp contains one UID000426 marker and one exact definition; MapPane.h contains no child-body duplication, one method declaration, and the canonical bool field. Historical command `000000020207`, command `000000020304`, and command `000000020306` identities remain dated checkpoints rather than current state.

## Ranked Ownership Analysis

### 1. MapPane class in MapPane.cpp

- Evidence for: const MapPane receiver; exact field at MapPane `+0x40e`; adjacent MapPane methods; constructor and packet-handler writers; class declaration already exists; 24 cross-source callers consume but do not own behavior.
- Evidence against: none.
- Decision: direct owner [UID:00007Q], source root [UID:0000L3], target owns sole CPP body.

### 2. UserPane or status-pane source

- Evidence for: most calls concern movement/status packets.
- Evidence against: callers span UserPane, three status-pane generations, BackGroundPane, and ConnStatusPane; none owns the receiver or storage.
- Decision: dependency consumers only.

### 3. Collision/day-night helper placement

- Evidence for: collision predecessor is adjacent; day/night fields are adjacent in layout and BackGroundPane also reads brightness.
- Evidence against: separate ranges, separate fields, separate caller sets, different return contracts, and packet bit/write evidence.
- Decision: rejected.

### Proposed new file/grouping, if applicable

- No new file or grouping.
- Keep `NexusTK/map/MapPane.cpp`.
- Do not create a standalone movement protocol utility or aggregate-owned duplicate.

## Source Placement

- Recommended definition: target CPP in `NexusTK/map/MapPane.cpp` through UID00007Q.
- Recommended declaration/field: existing UID00007Q `MapPane` H block in `NexusTK/map/MapPane.h`.
- Source order remains between `CheckMovementCollision` and `ApplyMovementSubstepScroll`, matching binary order.
- Constructor and opcode-`0x15` packet handler remain separate MapPane member definitions in the same source file.
- Rejected placements: UserPane.cpp, status pane files, BackPane.cpp, ConnStatusPane.cpp, a protocol utility, day/night source, collision source, or a separate child file.
- Remaining placement uncertainty: none.

## Range / Split / Padding / Reclassification Analysis

- Target range is exact and complete: `0x005055d0-0x005055db`.
- Pre-padding `0x005055ca-0x005055d0` is six bytes of `0xcc`.
- Post-padding `0x005055db-0x005055e0` is five bytes of `0xcc`.
- The function has one IDA entry, one block, no tail, no jump table, no EH, no thunk, no data island, and no child.
- No merge with UID000425/UID000427 is valid.
- No ignored or no-owner subrange exists inside the target.
- Parent UID0001AP remains a nonduplicating aggregate/source-range index.

## Negative Evidence Summary

- No caller treats the result as day/night brightness, hour, tint, weather, or map transition state.
- No caller performs collision arithmetic or consumes `-1/0/1`; that belongs to UID000425.
- No caller consumes a byte value beyond boolean truth.
- No alternate field writer or reader was found in the bounded MapPane code family.
- No callee, table, global, vtable slot, or free-function receiver route suggests another owner.
- `SupportsMovementStatusTag` is not better than the established `AllowsMovementStatusTag`.
- The private field cannot be named as an enabled flag because stored true makes the method false.
- The old RankingDialog textual UID000426 is invalid historical registry reuse and supplies no target evidence.

## IDA Rename / Type / Comment Recommendations

### Actionable/current entities

| ID | Exact entity | Historical accepted prestate and current verified state | Collision state | Exact supervisor action | Current readback | Classification |
| --- | --- | --- | --- | --- | --- | --- |
| A00 | function `0x005055d0-0x005055db` | Historical pre-Gate2B: name `MapPane_AllowsMovementStatusTag`; declaration `bool __thiscall(const MapPane *this)`; frame `__return_address +0x0`, size `0x4`, `_UNKNOWN *`, no other stack args/locals; address regular absent; address repeatable absent; function regular `Source: MapPane::AllowsMovementStatusTag() const. Returns the movement-status policy byte as a bool.`; function repeatable absent. Dated catalog0381 checkpoint `5F2679A7...9A21` established the applied replacement. Current catalog0382 `B7CC899D...58277`: same name/declaration/frame/address channels, exact replacement function regular below, function repeatable absent. | `lookup_funcs` resolves the exact name only to `0x5055d0`; no competing target function before or after action. | Supervisor preserved name, declaration, frame, address comments, and function-repeatable absence; replaced function regular comment with `Source: bool MapPane::AllowsMovementStatusTag() const; returns true when effect-map-state packet flag 0x02 is clear. Callers combine it with Config::m_mapMovementStatusOption to gate movement-history/status high-bit tags and related status UI handling.` | B7CC readback: exact action comment present; same name/type/frame; address regular/repeatable and function repeatable absent; bytes and 24 xrefs preserved. | applied and verified |
| A01 | `MapPane` UDT ordinal `614`, member `+0x40e`, size `1` | Historical pre-Gate2B: UDT size `0x910`; `+0x40e m_movementGate unsigned __int8`; neighbors `+0x40c m_mapTransitionState unsigned __int8`, `+0x40d m_weatherMode unsigned __int8`, `+0x40f m_dayNightHour unsigned __int8`; tool schema exposes no UDT-member comment channel. Dated catalog0381 checkpoint `5F2679A7...9A21` established the applied member. Current catalog0382 `B7CC899D...58277`: same UDT size/neighbors/offset/width, `+0x40e m_movementStatusTagDisabled bool`. | Proposed member name was absent before action; current member inventory has one exact `m_movementStatusTagDisabled` at unique offset `+0x40e`, with no collision. | Supervisor renamed member to `m_movementStatusTagDisabled` and changed type to `bool`, preserving offset `+0x40e`, width `1`, UDT size `0x910`, and every neighbor. | B7CC `type_inspect MapPane` shows exact `+0x40e m_movementStatusTagDisabled bool`; target/protected bytes, identities, comments, frame, xrefs, and adjacent layout remain unchanged. | applied and verified |

### Protected read-only dependencies

| ID | Exact entity/current state | Comment-channel state | Constraint/readback |
| --- | --- | --- | --- |
| P00 | UID000425 function `0x00505430-0x005055ca`, current name `sub_505430`, prototype `int __thiscall(int this, int, int, char)` | address regular absent; address repeatable absent; function regular absent; function repeatable absent | Do not rename/retype/comment through UID000426. Preserve function end and separate collision ownership. |
| P01 | Data item `0x005055ca-0x005055d0`, six bytes `CC CC CC CC CC CC`, no name/type | regular absent; repeatable absent | Preserve as padding; do not absorb into either function. |
| P02 | Data item `0x005055db-0x005055e0`, five bytes `CC CC CC CC CC`, no name/type | regular absent; repeatable absent | Preserve as padding; do not absorb into either function. |
| P03 | UID000427 function `0x005055e0-0x00505645`, current name `MapPane__ApplyMovementSubstepScroll`, prototype `bool __thiscall(MapPane *this, unsigned __int8 direction)` | address regular absent; address repeatable absent; function regular absent; function repeatable `Applies one scaled movement substep to MapPane pixel origins and returns shifted-area invalidation result.` | Do not alter successor identity/type/comment or range. |
| P04 | UID0002I7 constructor `0x00504110-0x00504521`, current name `sub_504110`, current prototype `int __thiscall(int this, int, int)`; packed write at `0x50429c` stores `0x00010001` at `+0x40c` | entry address regular absent; entry address repeatable absent; function regular absent; function repeatable absent; store address regular absent; store address repeatable absent | Preserve bytes and ownership. Correct ordinary source prose/formal only; constructor IDA normalization belongs to UID0002I7. |
| P05 | UID0003TK packet handler `0x005104d0-0x00510958`, current name `MapPane_HandleEffectMapStatePacket`, prototype `bool __thiscall(MapPane *this, const unsigned __int8 *packet)`; write at `0x510771` | entry address regular/repeatable absent; function regular is exact opcode-`0x15` packet summary; function repeatable absent; store address regular/repeatable absent | Function identity, signature, comment, bytes, and packet behavior are preserved; only the applied A01 UDT member presentation changed. |
| P06 | Adjacent UDT members `+0x40c/+0x40d/+0x40f` with exact current names/types above | UDT member comment channel not exposed by current tool schema | Preserve offsets, widths, names, and types; no widening or packed-field merge. |

- Negative constraints:
  - do not rename the method to `IsDayMode`, `IsMovementGateClear`, or `SupportsMovementStatusTag`;
  - do not alter the function range, code bytes, calling convention, return type, frame, callers, or padding;
  - do not rename or retype packet/config globals through this action;
  - do not modify predecessor, successor, constructor, packet-handler, or caller function identities through this report;
  - do not save IDA until supervisor verifies exact poststate and protected readback.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. Behavior, field polarity, type, ownership, and source placement are closed.
- Target CPP block disposition: replace the target formal CPP contents with exactly:

```cpp
bool MapPane::AllowsMovementStatusTag() const
{
    return !m_movementStatusTagDisabled;
}
```

- Target H block disposition: remain blank. The declaration is already present once in UID00007Q.
- UID00007Q formal H result: physically preserves `bool AllowsMovementStatusTag() const;` and uses `bool m_movementStatusTagDisabled;`; the old `unsigned char m_movementGate;` token sequence is historical.
- UID0002I7 formal CPP result: physically uses `m_movementStatusTagDisabled = true;`; the old `m_movementGate = 0;` assignment is historical.
- UID0003TK formal CPP result:
  - physically uses enum token `kEffectMapStateDisableMovementStatusTag`;
  - physically uses field token `m_movementStatusTagDisabled`;
  - preserve the exact comparison with packet flag `0x02`.
- Third-party import directive: not applicable.
- Exact behavior: source compiles to a one-byte zero test and boolean return; constructor starts disabled, packet bit `0x02` maintains disabled state, and callers see true only while the disable bit is clear.
- Plausible developer source shape: a const predicate over a private bool is ordinary human-written C++ for the project era and avoids decompiler offsets, raw bytes, or compiler labels.
- Naming style: existing class uses `m_` member prefix and descriptive boolean state; method names use PascalCase.

## Final Recommendation

- Accepted ordinary result: target behavior/evidence/history/callers/boundaries/formal CPP and score are physically updated to `92/94`.
- Target owner/emitter/reconstructable/optional-position/H dispositions remain unchanged.
- MapPane class field is physically updated to the source-facing bool; the method declaration remains singular.
- Constructor initial value and packet writer polarity/name are physically corrected.
- Layout, aggregate, file route, and caller destinations retain prior evidence and now include the accepted exact cross-links/detail.
- Supervisor command `000000020347` applied and read back the exact manual by-memory row at line 2377 after UID000425 line 2376.
- Foreground autogen command `000000020348` resolved historical command `000000020207` CPP/H drift and refreshed the tracker/memory artifacts to the exact current identities recorded above; all earlier B008 scoped callback validators correctly used `--no-generated-refresh`.
- Catalog0381 applied and verified A00/A01 at dated checkpoint `5F2679A7...9A21`; B008 remained read-only and reconciled the unchanged target/protected poststate against current catalog0382 checkpoint `B7CC899D...58277`.
- No future B-agent investigation is required for this target unless fresh binary evidence contradicts the current lifecycle.

## Recommended Target Doc Changes

- Target path: `by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md`.
- Exact sections physically added/updated by the accepted callback:
  - metadata `Item Summary`: source-ready const MapPane predicate with inverse per-map disable-flag lifecycle and complete caller role.
  - existing `## Status`: exact route, score, reconstructable, and source-readiness.
  - existing `## Evidence`: exact bytes, instructions, frame, comments, 24 xrefs, no callees, and writer lifecycle.
  - new `## IDA Applied State`: catalog0381's dated A00 function-comment application, exact saved identity/declaration/frame/comment channels, and catalog0382 B7CC target/protected no-drift readback.
  - new `## Behavior`: inverse per-map disable flag, global config interaction, sender/receiver/status UI roles.
  - new `## Field Lifecycle`: constructor true, packet bit `0x02` runtime writer, sole direct read.
  - new `## Naming`: accept method and field, reject day/collision/storage aliases.
  - new `## Boundaries`: exact padding and protected neighbors.
  - new `## Ownership And Source Placement`: class/file route.
  - existing `## Cross-References`: add all exact writer/caller/support pages without dropping current links.
  - new `## Historical Assumptions`: preserve and explain rejected older names and stale generated score.
  - existing `## Changes`: dedicated B008 source-quality closure.
- Current metadata:
  - `COMPLETION:92`;
  - `CONFIDENCE:94`;
  - owner/emitter/reconstructable/position unchanged.
- Formal CPP: exact block above, physically verified once.
- Formal H: blank.
- Current post-IDA ordinary identity: SHA256 `FE4E9F30E12C25B3835834C1DD9059E8FA585C5724DCF7BBD0CEF1675A803AF5`, `11,541` bytes / `119` lines; scoped command `000000020345`, exit `0`, `ok: 1`, no warning, generated refresh skipped.

## Recommended Support Doc Changes

| UID | Support path | Current SHA256 | Exact report-level incorporation |
| --- | --- | --- | --- |
| 00007Q | `by-class/MapPane.md` | `1F9101091F6920E5FD89C731B2FEAEE3FCF8830262475853872A86E2F34314BF` | Applied: field rename/retype, exact lifecycle/polarity/caller summary, rejected aliases, catalog0381 comment/member action evidence, and catalog0382 B7CC no-drift readback; retained 93/94 and singular method declaration. Scoped command `000000020346` passed with only 36 pre-existing unrelated missing-UID warnings. |
| 0000L3 | `by-file/MapPane.md` | `F4BF09A860EB24CCC426F1D441445F94656517129B39CEBA8BE4AA05D32CCBCE` | Applied: UID000426 source-route section tying target, constructor, packet writer, class H, and consumer families; retained 92/92. |
| 0001AP | `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md` | `822160D963EB660AAC2D2DEC57A570F985FFF8206CAC7FDB7E9541EB1846851F` | Applied: exact disable-flag lifecycle and complete consumer classes; aggregate remains nonduplicating. |
| 0002I7 | `by-memory/0x00504110-0x00504521.MapPaneInitialize.md` | `32AFEABA022F116C180E31A579CE8E6230BD31E73B72D762E9FAB4BFBDE6BFD0` | Applied: initial field value true, packed-dword byte-order proof, and corrected formal token. |
| 0003TK | `by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md` | `D4375548F3D779F1528E0D2384CD7B2C31C2D1617E5A7D9495DD50C6EC339C18` | Applied: enum/field rename, bit `0x02` disable semantics, exact packet behavior, retained 92/94. |
| 00042K | `by-type/by-struct/MapPaneLayout.md` | `5818F6CBB69EB312D0F7A055830FE20174E567B11615FE66D902F1D5E189FD4A` | Applied: canonical bool at +0x40e, exact neighbors, lifecycle, and rejected aliases; retained 93/94. |
| 000425 | `by-memory/0x00505430-0x005055ca.MapPaneCheckMovementCollision.md` | `D91F5BE66E0F8D95D307C57C2BB0A3BA447DA6E6AE33A8560492BD77C13F91A3` | Verify-only: current successor boundary already exact; do not add movement-status semantics. |
| 00030L | `by-memory/0x00467510-0x0046782f.BackGroundPaneCoreMethods.md` | `284CB50669A32422C4570B4C8769DF5C81B520CFAA9185A8A406D493F8008748` | Applied: separated brightness readiness from config/predicate invalidation and recorded exact method/disable semantics. |
| 000113 | `by-memory/0x00494520-0x004949df.ConnStatusPane.md` | `BA7063D7A12C8E3640A8485B1394E3AFBEC1DAB0F17159A9366794D08BAA3B14` | Applied: source-facing method identity, historical raw aliases, and frame-4 behavior under the exact gate. |
| 0003U6 | `by-memory/0x005a2e00-0x005a36f0.UserPaneProcessMovement.md` | `8053BAA172A5980F0C898F8085985D583391B647C0F790B377F3BC4954AF2C10` | Applied: preserved exact high-bit sender/status-event detail and added field-polarity cross-link. |
| 0003UP | `by-memory/0x005ab090-0x005ab410.UserPaneHandleMovementReplyPacket.md` | `BF4B49512098A4A61F2DEEF663913ED4BB02F5C468719F32BED2DBD3F59E51A9` | Applied: preserved exact reply behavior and cross-linked per-map disable field. |
| 0003UQ | `by-memory/0x005ab410-0x005ab75d.UserPaneHandleExtendedMovementReplyPacket.md` | `4FD119A21891D95A0ABEBB5F33A52567CA2D56EEE047F7FA095C6CE84C1E3653` | Applied: preserved exact extended-reply behavior and cross-linked per-map disable field. |
| 0003UX | `by-memory/0x005ac7e0-0x005ac99b.UserPaneSendMovementWaypointPacket.md` | `8EB498F51A8E405883DE2979B76D4883FDC861967A7EC0F47ED587B8BAACCBC8` | Applied: exact tag behavior, rejected old names, and field-polarity cross-link. |
| 0003UY | `by-memory/0x005ac9a0-0x005acad5.UserPaneSendFaceDirectionPacket.md` | `5F362231511320630CFD065336C1BE9B1F02D1C38D64CE62211B86B91C3B0ED7` | Applied: exact tag behavior, rejected old names, and field-polarity cross-link. |
| 0003AA | `by-memory/0x005b8700-0x005b8a0c.UserStatusPaneHandlePacketEvent.md` | `E447943FF9935D9102386806D0065D8382FDFB802960D964B248EF5285949CC3` | Applied: two exact call sites and movement packet variants. |
| 0004T6 | `by-memory/0x005ba1a0-0x005ba31c.UserStatusPaneApplyLegacyMovementStep.md` | `F09D631459163AE38F2B74943D43060BEDB8BD2C04AE04B576B8B71BBE07BE66` | Applied: exact MapPane predicate and preserved high-bit rule. |
| 0004T7 | `by-memory/0x005ba320-0x005ba49c.UserStatusPaneApplyLegacyMovementStepAlt.md` | `B1581588553A883D2119499A5ACC4215CEC7C25E27EFFECDCB04B620A8C61D9F` | Applied: exact predicate and preserved alternate high-bit rule. |
| 0001NO | `by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md` | `92F4506558A619E9F1FEEEAD4A1D095F2446A9A82C3152C180D6948D93974F21` | Applied: aggregate-only exact predicate/caller-family cross-link; remains non-emitting. |
| 0004TI | `by-memory/0x005bac80-0x005baf64.UserStatusPane2HandlePacketEvent.md` | `433D5B088C6F323C9D108845EEFB70BC596B41A8032C3B811EAC7772F150E999` | Applied: two exact call sites and packet variants. |
| 0004TP | `by-memory/0x005bc180-0x005bc2cc.UserStatusPane2ApplyLegacyMovementStep.md` | `21C19361997D7C5994121BF319FE9B8DBD86804B9F14F4133CA6692EC31D040F` | Applied: exact predicate/config signed-direction behavior and field polarity. |
| 0004TQ | `by-memory/0x005bc2d0-0x005bc41c.UserStatusPane2ApplyLegacyMovementStepAlt.md` | `C14948035628E938E1C48BEC53DFC6A3F49553F4DDBC7EE67198F975A56E0609` | Applied: exact alternate behavior and field polarity. |
| 0001NR | `by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md` | `26FFF6524138700D64B6313620AB9A3C0F0587062E36EA473CFE001473D2E607` | Applied: two modeled router calls and exact capability-field cross-link. |
| 000499 | `by-memory/0x005bf520-0x005bf670.OldUserStatusPaneApplyLegacyMovementStep.md` | `D3FC0809F6E4636E10883406BB8098B626E1C27BEC8B8C602FC4E8B1DF1F613A` | Applied: raw call `0x5bf576` tied to exact predicate and disable lifecycle. |
| 00049A | `by-memory/0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt.md` | `429141F78FAFD9155FE4ACD3D05F6BB94120FBE188DD17697D73E594015B6BA1` | Applied: raw call `0x5bf6c6` tied to exact predicate and disable lifecycle. |

- No support score changes are recommended solely for this cross-link repair.
- UID0000L3 `by-file/MapPane.md` and UID0001AP `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md` were explicitly re-read for stale future IDA-action language. Their SHA256 identities remain `F4BF09A860EB24CCC426F1D441445F94656517129B39CEBA8BE4AA05D32CCBCE` and `822160D963EB660AAC2D2DEC57A570F985FFF8206CAC7FDB7E9541EB1846851F`; both already express applied source/ownership evidence without an unfulfilled IDA handoff, so no edit or validator rerun was warranted.
- Preserve all valid prior detail in these files; add the dedicated evidence instead of replacing broad sections with summaries.

## Score And Metadata Recommendation

| Field | Current physical target | Recommended |
| --- | --- | --- |
| Completion | 92 | 92 |
| Confidence | 94 | 94 |
| Canonical owner | 00007Q | unchanged |
| Reconstructable | TRUE | unchanged |
| Emitter UIDs | 00007Q | unchanged |
| Optional position | blank | unchanged |
| CPP | exact updated block | unchanged |
| H | blank | blank |

- Reason not lower: exact range, bytes, CFG, ABI, frame, padding, 24 calls, no callees, full field lifecycle, return type, source placement, owner/emitter, and first-draft source are closed.
- Reason not higher:
  - no original symbols or source prove the private field lexeme;
  - packet enum spelling is inferred;
  - final compiler-equivalence audit has not yet compared emitted object code.
- Score-improvement attempts:
  - method-name blocker: resolved through all caller domains and rejected alternatives;
  - field-meaning blocker: resolved through constructor, packet writer, sole read, and every caller;
  - field-type blocker: resolved to bool through 0/1 stores and predicate ABI;
  - caller blocker: all 24 direct call sites classified;
  - source-placement blocker: resolved to MapPane.cpp through receiver, neighborhood, class/file topology;
  - code blocker: exact human-shaped formal C++ supplied;
  - coverage blocker: exact missing manual row staged.

## Open Questions With Attempted Resolution

1. Original method lexeme:
   - Checked current class/formal, IDA name/comment, all callers, old reports, and alternatives.
   - Resolution: retain `AllowsMovementStatusTag`; changing it would reduce consistency without stronger evidence.
2. Original private field lexeme:
   - Checked all direct writes/reads, adjacent fields, packet flags, caller behavior, and project bool naming.
   - Resolution: `m_movementStatusTagDisabled` is the strongest source-facing inference. Original spelling remains unknowable but does not justify an IDA-shaped name.
3. `bool` versus byte:
   - Checked stores, setz return, IDA type, class declaration, and caller uses.
   - Resolution: bool.
4. Day mode:
   - Checked adjacent day/night fields, BackGroundPane decompile, and packet math.
   - Resolution: rejected.
5. Collision gate:
   - Checked predecessor body/range/returns/callers.
   - Resolution: rejected.
6. Global config relation:
   - Checked `m_mapMovementStatusOption` branches across senders/receivers/UI.
   - Resolution: config globally requests feature use; per-map disable field can veto it.
7. Packet bit polarity:
   - Checked assignment and target inverse.
   - Resolution: bit `0x02` means disable movement/status tag capability.
8. Source location:
   - Checked receiver ABI, class/file pages, aggregate, constructor/writer, and neighborhood.
   - Resolution: MapPane.cpp.
9. Manual coverage:
   - Checked exact current reports.
   - Resolution: supervisor command `000000020347` applied the exact target row; physical readback finds UID000425 at line 2376 and UID000426 at line 2377. Support rows need no score/path replacement.
10. Generated mismatch:
    - Checked historical stale command `000000020207` MapPane CPP/H and current foreground command `000000020348` CPP/H, memory coverage, and moving tracker.
    - Resolution: command `000000020348` closes all generated drift with exact canonical CPP/H, tracker `92/94` and `0/0/0`, and coded UID00007Q memory routing. B008 intentionally disabled generated refresh on every earlier scoped ordinary validation; the supervisor later performed the foreground closure.

- No unanswered open question blocks score, ownership, or formal source.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Current manual by-memory report after supervisor command `000000020347`:
  - path `by-memory/-coverage-report.md`;
  - SHA256 `5CDCBB4B7CBAD1516373078F0117F4062087F806F69E98574F077705AEDD53FF`;
  - `2,119,450` bytes, `4,788` physical lines;
  - UID000425 remains at line `2376`; UID000426 is applied and read-back verified at line `2377`, before UID0001AQ.
- Exact supervisor-applied payload:

```markdown
        - [UID:000426][0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag](by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md) 0x005055d0-0x005055db | MapPane const predicate | MapPaneAllowsMovementStatusTag : reconstructable : 92% : very-strong : Exact 11-byte bool MapPane::AllowsMovementStatusTag() const body over canonical bool m_movementStatusTagDisabled at +0x40e; constructor initializes the disable flag true through packed bytes, opcode-0x15 effect/map-state packet bit 0x02 is the sole runtime writer, and 24 direct calls across UserPane movement send/reply processing, UserStatusPane/UserStatusPane2/OldUserStatusPane compatibility paths, BackGroundPane, and ConnStatusPane gate high-bit movement-history/status tagging and related status UI behavior; exact bytes, ABI, frame, boundaries, source placement, formal C++, and rejected day-mode/collision aliases are documented.
```

- Current manual support rows inspected:
  - `by-class/-coverage-report.md`, SHA256 `9B8B77532BAA43613618BCB3275E9E9D6668EADA1A499F154ACAC18B3DAF5033`, `273,344` bytes, `625` lines: UID00007Q line 302, `93%`; no replacement required.
  - `by-file/-coverage-report.md`, SHA256 `E71703BB63B1E1C9A4E9CED4677F5E1C1355416655282674378DA1ADF6EA4126`, `164,309` bytes, `317` lines: UID0000L3 line 156, `92%`; no replacement required.
  - `by-type/by-struct/-coverage-report.md`, SHA256 `A5567B78117387A71F4D1CD213C373C5F3514CBEA8EB759D497886E8CE771496`, `59,146` bytes, `137` lines: UID00042K line 70, `93%`; no replacement required.
- B008 did not apply or validate any manual coverage row. The supervisor applied and validated the exact insertion under command `000000020347`; the report records physical readback only.
- Generated tracker text is validator-owned and must not be edited manually.

## Follow-Up Actions

- Supervisor:
  - preserve the completed Gate 2A verification of each changed ordinary destination, including post-IDA target/class hashes and commands `000000020345`/`000000020346`;
  - preserve catalog0381's completed A00/A01 Gate 2B result at dated `5F2679A7...9A21` and the current catalog0382 `B7CC899D...58277` no-drift P00-P06 readback; recheck only if later shared-IDB movement occurs;
  - preserve command `000000020347` manual-row application/readback and command `000000020348` generated CPP/H/tracker/memory closure as completed supervisor evidence;
  - perform fresh exact-artifact gates and run the lifecycle command only after they pass.
- A-agent actions: none.
- B008 future research: none for this report unless supervisor returns an exact defect or current-state drift.

## Confidence

- Recommendation confidence: 94/100.
- Score confidence: high.
- Exact behavior/type/placement confidence: very strong.
- Private field lexeme confidence: strong, inferred rather than original-proof.
- Remaining uncertainty does not justify retaining decompiler/raw terminology.

## Validator Results

- Working directory for every command: `E:\NTK\GhidraBridge\source-3\project-documentation`.
- B008 commands `000000020253` through `000000020346` were serial scoped validations, exited `0`, reported `ok: 1`, and skipped generated refresh as required. Supervisor command `000000020347` separately validated the manual coverage edit, and foreground autogen command `000000020348` performed the generated closure; B008 did not run either supervisor command.
- Exact command records:

| Command ID | Timestamp | Exact command | Result / warning disposition |
| --- | --- | --- | --- |
| `000000020253` | `2026-07-31T05:07:39-04:00` | `python .\tools\validator.py --mode file --file 'by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; no warning |
| `000000020254` | `2026-07-31T05:08:54-04:00` | `python .\tools\validator.py --mode file --file 'by-class/MapPane.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; `missing_ref_uid: 36` is pre-existing/unrelated to UID000426 and did not block validation |
| `000000020255` | `2026-07-31T05:09:48-04:00` | `python .\tools\validator.py --mode file --file 'by-file/MapPane.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; `missing_ref_uid: 43` is pre-existing/unrelated to UID000426 and did not block validation |
| `000000020256` | `2026-07-31T05:10:28-04:00` | `python .\tools\validator.py --mode file --file 'by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; no warning |
| `000000020257` | `2026-07-31T05:11:05-04:00` | `python .\tools\validator.py --mode file --file 'by-memory/0x00504110-0x00504521.MapPaneInitialize.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; no warning |
| `000000020258` | `2026-07-31T05:11:57-04:00` | `python .\tools\validator.py --mode file --file 'by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; no warning |
| `000000020259` | `2026-07-31T05:12:43-04:00` | `python .\tools\validator.py --mode file --file 'by-type/by-struct/MapPaneLayout.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; no warning |
| `000000020260` | `2026-07-31T05:13:43-04:00` | `python .\tools\validator.py --mode file --file 'by-memory/0x00467510-0x0046782f.BackGroundPaneCoreMethods.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; no warning |
| `000000020261` | `2026-07-31T05:14:41-04:00` | `python .\tools\validator.py --mode file --file 'by-memory/0x00494520-0x004949df.ConnStatusPane.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; no warning |
| `000000020262` | `2026-07-31T05:15:18-04:00` | `python .\tools\validator.py --mode file --file 'by-memory/0x005a2e00-0x005a36f0.UserPaneProcessMovement.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; no warning |
| `000000020263` | `2026-07-31T05:15:46-04:00` | `python .\tools\validator.py --mode file --file 'by-memory/0x005ab090-0x005ab410.UserPaneHandleMovementReplyPacket.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; no warning |
| `000000020265` | `2026-07-31T05:16:11-04:00` | `python .\tools\validator.py --mode file --file 'by-memory/0x005ab410-0x005ab75d.UserPaneHandleExtendedMovementReplyPacket.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; no warning |
| `000000020266` | `2026-07-31T05:16:53-04:00` | `python .\tools\validator.py --mode file --file 'by-memory/0x005ac7e0-0x005ac99b.UserPaneSendMovementWaypointPacket.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; no warning; superseded only by the final same-file validation `000000020287` after source-name reconciliation |
| `000000020268` | `2026-07-31T05:17:20-04:00` | `python .\tools\validator.py --mode file --file 'by-memory/0x005ac9a0-0x005acad5.UserPaneSendFaceDirectionPacket.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; no warning; superseded only by the final same-file validation `000000020289` after source-name reconciliation |
| `000000020269` | `2026-07-31T05:18:04-04:00` | `python .\tools\validator.py --mode file --file 'by-memory/0x005b8700-0x005b8a0c.UserStatusPaneHandlePacketEvent.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; no warning |
| `000000020270` | `2026-07-31T05:18:40-04:00` | `python .\tools\validator.py --mode file --file 'by-memory/0x005ba1a0-0x005ba31c.UserStatusPaneApplyLegacyMovementStep.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; no warning |
| `000000020272` | `2026-07-31T05:19:10-04:00` | `python .\tools\validator.py --mode file --file 'by-memory/0x005ba320-0x005ba49c.UserStatusPaneApplyLegacyMovementStepAlt.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; no warning |
| `000000020274` | `2026-07-31T05:19:44-04:00` | `python .\tools\validator.py --mode file --file 'by-memory/0x005bac80-0x005baf64.UserStatusPane2HandlePacketEvent.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; no warning |
| `000000020276` | `2026-07-31T05:20:28-04:00` | `python .\tools\validator.py --mode file --file 'by-memory/0x005bc180-0x005bc2cc.UserStatusPane2ApplyLegacyMovementStep.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; no warning |
| `000000020278` | `2026-07-31T05:21:00-04:00` | `python .\tools\validator.py --mode file --file 'by-memory/0x005bc2d0-0x005bc41c.UserStatusPane2ApplyLegacyMovementStepAlt.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; no warning |
| `000000020280` | `2026-07-31T05:21:39-04:00` | `python .\tools\validator.py --mode file --file 'by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; no warning |
| `000000020283` | `2026-07-31T05:22:36-04:00` | `python .\tools\validator.py --mode file --file 'by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; no warning |
| `000000020285` | `2026-07-31T05:23:28-04:00` | `python .\tools\validator.py --mode file --file 'by-memory/0x005bf520-0x005bf670.OldUserStatusPaneApplyLegacyMovementStep.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; no warning |
| `000000020286` | `2026-07-31T05:24:19-04:00` | `python .\tools\validator.py --mode file --file 'by-memory/0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; no warning |
| `000000020287` | `2026-07-31T05:24:55-04:00` | `python .\tools\validator.py --mode file --file 'by-memory/0x005ac7e0-0x005ac99b.UserPaneSendMovementWaypointPacket.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; no warning; final current validation |
| `000000020289` | `2026-07-31T05:25:23-04:00` | `python .\tools\validator.py --mode file --file 'by-memory/0x005ac9a0-0x005acad5.UserPaneSendFaceDirectionPacket.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; no warning; final current validation |
| `000000020345` | `2026-07-31T06:38:27-04:00` | `python .\tools\validator.py --mode file --file 'by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; no warning; post-IDA C043 ordinary reconciliation; generated refresh skipped |
| `000000020346` | `2026-07-31T06:39:00-04:00` | `python .\tools\validator.py --mode file --file 'by-class/MapPane.md' --apply --queue-timeout 240 --no-generated-refresh` | exit 0; ok 1; `missing_ref_uid: 36` is pre-existing and unrelated to UID000426; post-IDA C044 ordinary reconciliation; generated refresh skipped |
| `000000020347` | `2026-07-31T06:52:48-04:00` | `python .\tools\validator.py --mode file --file 'by-memory/-coverage-report.md' --apply --queue-timeout 240 --no-generated-refresh` | supervisor-owned manual validation completed; current SHA `5CDCBB4B...53FF`; exact UID000426 row read back at line 2377; generated refresh deferred to command `000000020348` |
| `000000020348` | `2026-07-31T06:53:05-04:00` | `python .\tools\validator.py --mode autogen --apply` | supervisor foreground autogen completed; generated headers identify command/timestamp/source; exact CPP/H/memory/tracker hashes and topology physically read back |

- No target-specific validator error remains. Command `000000020346` repeated 36 pre-existing `missing_ref_uid` findings from the large MapPane class page; they do not concern UID000426, its field, its formal C++, or this callback's support links. Command `000000020345` had no warning.
- Commands `000000020347` and `000000020348` close the manual and generated surfaces without changing ordinary UID000426 metadata or IDA state.
- No validator lifecycle/report-execution command was run or probed.

## Changed Files

- Ordinary callback physical readback:

| UID | Path | Current SHA256 | Bytes / lines |
| --- | --- | --- | --- |
| 000426 | `by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md` | `FE4E9F30E12C25B3835834C1DD9059E8FA585C5724DCF7BBD0CEF1675A803AF5` | `11,541 / 119` |
| 00007Q | `by-class/MapPane.md` | `1F9101091F6920E5FD89C731B2FEAEE3FCF8830262475853872A86E2F34314BF` | `198,948 / 1,097` |
| 0000L3 | `by-file/MapPane.md` | `F4BF09A860EB24CCC426F1D441445F94656517129B39CEBA8BE4AA05D32CCBCE` | `204,969 / 840` |
| 0001AP | `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md` | `822160D963EB660AAC2D2DEC57A570F985FFF8206CAC7FDB7E9541EB1846851F` | `72,076 / 357` |
| 0002I7 | `by-memory/0x00504110-0x00504521.MapPaneInitialize.md` | `32AFEABA022F116C180E31A579CE8E6230BD31E73B72D762E9FAB4BFBDE6BFD0` | `33,918 / 329` |
| 0003TK | `by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md` | `D4375548F3D779F1528E0D2384CD7B2C31C2D1617E5A7D9495DD50C6EC339C18` | `28,150 / 386` |
| 00042K | `by-type/by-struct/MapPaneLayout.md` | `5818F6CBB69EB312D0F7A055830FE20174E567B11615FE66D902F1D5E189FD4A` | `30,231 / 173` |
| 00030L | `by-memory/0x00467510-0x0046782f.BackGroundPaneCoreMethods.md` | `284CB50669A32422C4570B4C8769DF5C81B520CFAA9185A8A406D493F8008748` | `10,328 / 171` |
| 000113 | `by-memory/0x00494520-0x004949df.ConnStatusPane.md` | `BA7063D7A12C8E3640A8485B1394E3AFBEC1DAB0F17159A9366794D08BAA3B14` | `17,537 / 235` |
| 0003U6 | `by-memory/0x005a2e00-0x005a36f0.UserPaneProcessMovement.md` | `8053BAA172A5980F0C898F8085985D583391B647C0F790B377F3BC4954AF2C10` | `29,231 / 367` |
| 0003UP | `by-memory/0x005ab090-0x005ab410.UserPaneHandleMovementReplyPacket.md` | `BF4B49512098A4A61F2DEEF663913ED4BB02F5C468719F32BED2DBD3F59E51A9` | `19,264 / 236` |
| 0003UQ | `by-memory/0x005ab410-0x005ab75d.UserPaneHandleExtendedMovementReplyPacket.md` | `4FD119A21891D95A0ABEBB5F33A52567CA2D56EEE047F7FA095C6CE84C1E3653` | `21,261 / 244` |
| 0003UX | `by-memory/0x005ac7e0-0x005ac99b.UserPaneSendMovementWaypointPacket.md` | `8EB498F51A8E405883DE2979B76D4883FDC861967A7EC0F47ED587B8BAACCBC8` | `29,727 / 323` |
| 0003UY | `by-memory/0x005ac9a0-0x005acad5.UserPaneSendFaceDirectionPacket.md` | `5F362231511320630CFD065336C1BE9B1F02D1C38D64CE62211B86B91C3B0ED7` | `25,912 / 247` |
| 0003AA | `by-memory/0x005b8700-0x005b8a0c.UserStatusPaneHandlePacketEvent.md` | `E447943FF9935D9102386806D0065D8382FDFB802960D964B248EF5285949CC3` | `6,493 / 90` |
| 0004T6 | `by-memory/0x005ba1a0-0x005ba31c.UserStatusPaneApplyLegacyMovementStep.md` | `F09D631459163AE38F2B74943D43060BEDB8BD2C04AE04B576B8B71BBE07BE66` | `6,948 / 114` |
| 0004T7 | `by-memory/0x005ba320-0x005ba49c.UserStatusPaneApplyLegacyMovementStepAlt.md` | `B1581588553A883D2119499A5ACC4215CEC7C25E27EFFECDCB04B620A8C61D9F` | `6,758 / 108` |
| 0004TI | `by-memory/0x005bac80-0x005baf64.UserStatusPane2HandlePacketEvent.md` | `433D5B088C6F323C9D108845EEFB70BC596B41A8032C3B811EAC7772F150E999` | `5,084 / 84` |
| 0004TP | `by-memory/0x005bc180-0x005bc2cc.UserStatusPane2ApplyLegacyMovementStep.md` | `21C19361997D7C5994121BF319FE9B8DBD86804B9F14F4133CA6692EC31D040F` | `6,120 / 110` |
| 0004TQ | `by-memory/0x005bc2d0-0x005bc41c.UserStatusPane2ApplyLegacyMovementStepAlt.md` | `C14948035628E938E1C48BEC53DFC6A3F49553F4DDBC7EE67198F975A56E0609` | `6,161 / 110` |
| 0001NO | `by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md` | `92F4506558A619E9F1FEEEAD4A1D095F2446A9A82C3152C180D6948D93974F21` | `22,584 / 139` |
| 0001NR | `by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md` | `26FFF6524138700D64B6313620AB9A3C0F0587062E36EA473CFE001473D2E607` | `23,108 / 157` |
| 000499 | `by-memory/0x005bf520-0x005bf670.OldUserStatusPaneApplyLegacyMovementStep.md` | `D3FC0809F6E4636E10883406BB8098B626E1C27BEC8B8C602FC4E8B1DF1F613A` | `6,356 / 110` |
| 00049A | `by-memory/0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt.md` | `429141F78FAFD9155FE4ACD3D05F6BB94120FBE188DD17697D73E594015B6BA1` | `11,120 / 139` |

- Protected verify-only destinations were already present and remained byte-identical:
  - UID000425 `by-memory/0x00505430-0x005055ca.MapPaneCheckMovementCollision.md`, SHA256 `D91F5BE66E0F8D95D307C57C2BB0A3BA447DA6E6AE33A8560492BD77C13F91A3`, `10,089` bytes / `98` lines;
  - UID000427 `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md`, SHA256 `1D00B3821EEAC8B67DC75753563767EAB51B7A77FFB28552B9B936A0A44DA87B`, `6,852` bytes / `66` lines.
- Post-IDA ordinary reconciliation changed only UID000426 and UID00007Q. UID0000L3 and UID0001AP were read-only inspected and remained byte-identical at `F4BF09A8...32CCBCE` and `822160D9...851F`; neither contained the stale future-action wording that required correction.
- Supervisor closure artifacts physically read back after commands `000000020347`/`000000020348`:

| Surface | Current SHA256 | Bytes / lines | Exact UID000426 state |
| --- | --- | --- | --- |
| `by-memory/-coverage-report.md` | `5CDCBB4B7CBAD1516373078F0117F4062087F806F69E98574F077705AEDD53FF` | `2,119,450 / 4,788` | exact `92%` row at line 2377 after UID000425 line 2376 |
| `auto-generated/NexusTK/map/MapPane.cpp` | `D6D7740AE18AA2568CC39A0EA1F15F5B32DC20023372085EB10CE8CCA0398FB7` | `159,505 / 4,776` | `92/94` marker and exact definition at lines 599-603 |
| `auto-generated/NexusTK/map/MapPane.h` | `3493BD4BEFB80C146C0A700021C3534BB95DE7C0A455F1531B1A5EF2240EE228` | `12,861 / 366` | singular method line 105 and canonical bool field line 327 |
| `auto-generated/-ag-memory-coverage.md` | `C2D261C91496DD1C3C264766554D815C121F0465BCCD798F305D51A5F48D791C` | `1,428,860 / 4,978` | coded through UID00007Q at line 1453 |
| `auto-generated/-ag-research-tracker.md` | `3EE8DC45E02014AF8C395B7E0D77A1CF60041ED50653F099B49C77FF8F871805` | `1,687,890 / 6,665` | `92/94`, `93.0`, `0/0/0` at line 3185 |
- Modified report: `tools/leaser/Agents/Agent-B008/research/000426-MapPaneAllowsMovementStatusTag-source-quality.md`.
- Renamed/moved files: none.
- IDA mutations/saves by B008: none. Supervisor catalog0381 applied A00/A01 and saved dated checkpoint `5F2679A7...9A21`; unrelated catalog0382 advanced current authority to `B7CC899D...58277`, and B008 performed only bounded read-only no-drift verification.
- Coverage/generated/tracker edits by B008: none. Supervisor commands `000000020347` and `000000020348` applied and verified those closure surfaces; B008 only reconciled their physical identities into this report.
- Leases: every ordinary lease was acquired only immediately before its edit and released immediately after its serial validator; no B008 lease remains.
- Report lifecycle boundary: execution/archive status is supervisor-owned and authoritative only from the report's current path plus validator-owned status/history metadata.

## Implementation Tracking Checklist

Initial report and ordinary callback:
- [x] Supervisor Gate 1 accepted exact report SHA `9438437E891FB539BAC0BD0BCDF3A45754F928D366A3435EE139A8D8AB0A688E` before implementation.
- [x] Update UID000426 target behavior/evidence/history/callers/boundaries.
- [x] Apply UID000426 score `92/94`, exact CPP, blank H, and unchanged route metadata.
- [x] Update UID00007Q class field/type/prose while preserving method declaration and score.
- [x] Update UID0000L3 MapPane.cpp source-route detail.
- [x] Update UID0001AP aggregate child detail without duplicate emission.
- [x] Correct UID0002I7 constructor initial value and formal token.
- [x] Correct UID0003TK packet enum/field polarity and formal tokens.
- [x] Update UID00042K canonical layout field/lifecycle.
- [x] Preserve UID000425/UID000427 boundaries and padding.
- [x] Update UID00030L and UID000113 stale caller semantics/names.
- [x] Verify and cross-link UID0003U6/UID0003UP/UID0003UQ/UID0003UX/UID0003UY.
- [x] Update UID0003AA/UID0004T6/UID0004T7 caller detail.
- [x] Update UID0001NO/UID0004TI/UID0004TP/UID0004TQ caller detail.
- [x] Update UID0001NR/UID000499/UID00049A caller detail.
- [x] Every declared additional UID has target-specific evidence, recommendations, ledger rows, and validation proof: no additional target UIDs are declared.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim ledger C001-C060 reconciled claim by claim; supervisor-owned C045/C049-C052 closure rows are applied or already present under commands `000000020347`/`000000020348`.
- [x] Score-limiting blockers researched to resolution.
- [x] Owner/emitter/reconstructable state confirmed unchanged.
- [x] Split/rename/new-child state confirmed: no split/new child; ordinary class-field rename only.
- [x] Source-placement/range/padding/reclassification disposition accepted and physically preserved.
- [x] Supervisor catalog0381 applied A00/A01 and verified P00-P06 at dated `5F2679A7...9A21`; B008 performed no mutation and independently re-read the unchanged poststate against current catalog0382 `B7CC899D...58277`.
- [x] Exact target CPP and blank target H dispositions accepted and physically verified.
- [x] Exact support formal token operations accepted and physically verified.
- [x] Third-party import confirmed not applicable.
- [x] Historical assumptions/rejected alternatives preserved.
- [x] Open questions accepted as resolved.
- [x] Scoped validators run for every ordinary file changed during callback.
- [x] C043 exact catalog0381 function-comment evidence and catalog0382 B7CC no-drift readback incorporated into UID000426 and validated by command `000000020345`.
- [x] C044 applied `+0x40e bool m_movementStatusTagDisabled`, exact accepted function comment, preserved neighbors/width/class size, dated 5F transaction, and current B7 no-drift incorporated into UID00007Q and validated by command `000000020346`.
- [x] UID0000L3 and UID0001AP inspected for stale future-action wording; both already expressed applied source/ownership state and remained byte-identical, so no edit was made.
- [x] Supervisor command `000000020347` inserted and validated the exact by-memory manual coverage row; current SHA `5CDCBB4B...53FF`, UID000426 line 2377 after UID000425 line 2376.
- [x] Current command `000000020348` research tracker and generated memory coverage physically verified at UID000426 `92/94`, `0/0/0`, and coded-through-UID00007Q state.
- [x] Supervisor foreground autogen command `000000020348` resolved historical command `000000020207` MapPane CPP/H drift and verified exact source/header topology.

Implementation callback pass:
- [x] Supervisor-owned IDA changes were not applied by B008; supervisor-applied A00/A01 poststate is reconciled.
- [x] Report accepted by supervisor for implementation.
- [x] All accepted ordinary target/support details incorporated at report-level detail.
- [x] Every ordinary destination independently verified against C001-C044 and C053-C060, including the post-IDA target/class reconciliation and file/aggregate verify-only inspection.
- [x] Ledger verification states updated only after physical readback.
- [x] Metadata/score/owner/emitter/split/rename/CPP/H changes applied, already present, or excluded with exact reason.
- [x] Historical/stale assumptions and negative evidence preserved.
- [x] Validators and exact results recorded.
- [x] MapPane CPP/H, tracker, and memory coverage refreshed and verified under current command `000000020348`; prior command `000000020207`, `000000020304`, and `000000020306` identities are retained only as dated checkpoints.
- [x] No implementation/coverage/generated blocker remains; only fresh supervisor gates and lifecycle execution/archive are external.
- [x] Report body remains lifecycle-neutral after callback.
- [ ] Supervisor performs fresh exact-artifact Gate 1 and final Gate 2 review on this closure-reconciled report.
- [ ] Supervisor alone performs report execution/archive and mandatory post-archive audit after Gate 2 closure.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000020355","destination_path":"executed-b-agent-research/B008/000426-MapPaneAllowsMovementStatusTag-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/000426-MapPaneAllowsMovementStatusTag-source-quality.md","timestamp":"2026-07-31T07:12:10-04:00","uid":"000426"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
