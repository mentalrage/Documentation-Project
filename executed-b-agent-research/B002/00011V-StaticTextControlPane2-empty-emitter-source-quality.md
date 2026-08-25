** TARGET-REPORT-UID:00011V **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID00011V StaticTextControlPane2 Empty-Emitter Source-Quality Research


## Finalized Report / Current Recommendation

- Completed callback state: [UID:00011V] is now a non-emitting, semantically class-owned
  split index. It retains `CANONICAL_OWNER:0000E4`, has `RECONSTRUCTABLE:FALSE`, blank
  emitter and position, and score `92/94` (raised from historical `86/90`).
- Final disposition: exact children were created and registered for the constructor,
  ordinary destructor,
  center-position helper, four lifecycle forwarders, `OnPaint`, retained style-state
  helper, two adjustor thunks, scalar deleting destructor, and control-type virtual.
  Exact vtable declaration/data support was also created. Ordinary source methods emit through
  [UID:0000E4]; compiler adjustors, scalar-wrapper mechanics, raw vtable arrays, RTTI,
  and padding do not become handwritten source.
- Completed implementation scope: C01-C35 and the B002-owned portions of Destinations
  1-18 were applied without compression. The class declaration contains the complete
  embedded nested class exactly once and places its
  outer `[[CHILDREN]]` marker after the outer `};`, at namespace scope. UID0000E4 and
  every outer child are B002-owned callback scope; [UID:0000E5] and all UID00011U nested
  children remain exclusively B005-owned callback scope under the version-locked order
  in C18. B002 did not edit UID0000E5. The shared declaration is synchronized against
  B005's completed report-only artifact SHA256
  `321CD4518BDB36ACF55A6B9AAF3DE2E434E56AF7462FC6F1C242B318CB7D1811`.
- Confidence: high for ranges, behavior, ownership, source placement, object layout,
  compiler/source disposition, and first-draft behavior; bounded below perfect by the
  inferred 40-wide-character source declaration, stripped private spellings, the
  selected non-const member convention on the type virtual, and original header factoring.

## Supporting Research

- Mandatory live evidence was collected read-only on 2026-07-13 after a fresh MCP
  initialize, `idb_list`, and `server_health`. At evidence-collection time the sole
  adopted NexusTK database was `328356ab`; health was `ok`, analysis and Hex-Rays were
  ready, the string cache was ready, and a live lookup of `0x0049a410` returned the
  expected `0x49c`-byte constructor. These are time-scoped observations, not a claim
  that the session remains available later.
- The live pass covered every requested exact method, all bytes between them, the full
  historical aggregate interval through `0x0049b915`, three vtable views, callers,
  callee/global routes, string resources, and negative external-entry checks for raw
  bodies.
- Read-only documentation checks covered the target, class/file routes, embedded child,
  B005's separate UID00011U report, FontStyle class/layout/core/vector support,
  ControlPane/Pane, Pane mode handling, GrafPort text metrics, rectangle helpers,
  Surface callback evidence, screen globals/helpers, compiler aggregate [UID:00011Y],
  read-only-data aggregate [UID:000252], ignored-range policy, successor [UID:000222],
  relevant executed reports, and generated `NexusTK/ui/controls/StaticTextControlPane.cpp`.
- Historical leads were revalidated rather than inherited. In particular, the existing
  target's raw destructor, bounds helper, and style-helper exclusive ends were stale;
  live bytes establish `0x0049a949`, `0x0049aa71`, and `0x0049ac59` respectively.
- During the report-only evidence pass, no by-* page, generated file, coverage/tracker
  file, supervisor/validator state, IDA database, or lifecycle state was modified, and
  no lease or validator command was used. The later accepted callback edits and
  validator-owned side effects are recorded under `Validator Results` and `Changed Files`.

## Target

- Target UID: `00011V`.
- Target path:
  `by-memory/0x0049a410-0x0049b915.StaticTextControlPane2.md`.
- Source queue/report row: at evidence-collection time the validator-owned research
  tracker classified UID00011V as reconstructable/not-covered with zero reports and the
  generated source showed its Empty Emitter Marker.
- The accepted B002 implementation callback is complete for C01-C35 and the B002-owned
  portions of Destinations 1-18; no B005-owned page was leased or edited.
- Historical pre-callback score and parent state: `86/90`, `CANONICAL_OWNER:0000E4`, reconstructable
  true, emitter UID0000E4, blank emitter position, blank formal C++.
- Applied parent state: `92/94`, semantic class owner retained, false reconstruction,
  blank emitter/position/formal C++, with source moved to exact children and no duplicate
  parent source.

## Current Target State

- Historical metadata treated the physical interval as one reconstructable
  source item even though it contains target methods, compiler support, FontStyle
  support, a Popup callback, many sibling-control thunks/destructors/type helpers, and
  alignment bytes.
- Historical source-facing documentation was directionally useful but stale at three raw
  endpoints, says the base construction is Pane type 1 instead of the live
  `ControlPane` type-8 route, leaves helper names generic, and has no formal source.
- The exact target-owned source inventory is source-ready: constructor; ordinary
  destructor; `SetCenterPosition`; `AddToLayer`; `RemoveFromLayer`; `Show`; `Hide`;
  `OnPaint`; `ApplyStyleState`; and `GetControlType`.
- The exact target-owned compiler inventory is two deleting-destructor adjustors, one
  scalar deleting destructor, three vtable views plus RTTI/data, and alignment bytes.
- The object is `0x2a8` bytes. It contains a `0x108`-byte ControlPane base, one contiguous
  40-wide-character buffer at `+0x108..+0x157` whose observed checked-copy limit is 32,
  two color fields, an embedded `0x20`-byte FontStyle, seven integer layout fields, and a
  `0x10c`-byte embedded [UID:0000E5] child at `+0x19c`. The former separate 16-byte
  reserve interpretation is superseded by the candidate audit below.
- The callback raised [UID:0000E4] to `92/93`, [UID:0000O8] to `92/92`, and FontStyle
  [UID:00005C] to `89/91`; the complete outer declaration, exact methods, source routing,
  and six consumer-proven FontStyle accessors are present. Historical pre-callback values
  were UID0000E4 `88/90`, UID0000O8 `88/86`, and UID00005C `87/89`. B005-owned
  [UID:0000E5] and UID00011U were not edited; their state and callback remain outside
  B002's implementation scope.
- The generated source observation is evidence-time only: validator command
  `000000009273`, refreshed 2026-07-13 05:11 ET, showed the older StaticText constructor
  and Empty Emitter Markers for UID0000E4, UID00011V, UID0000E5, and UID00011U. No
  present availability is inferred from that historical observation. The callback's
  separate waited verification command `000000009385`, refreshed
  `2026-07-13T06:52:36-04:00`, immediately showed one complete outer class block, one of
  each accepted ordinary outer definition, no UID00011V Empty Emitter Marker, and no
  handwritten adjustor/scalar/vtable ABI. A later read-only audit observed a newer
  validator-owned refresh, command `000000009396` at
  `2026-07-13T07:02:42-04:00`, with every B002 count and disposition still exact; B002
  did not run or claim that later command. UID0000E5/UID00011U markers remain the excluded
  B005 stage and are not a B002 callback defect.
- This artifact records the completed B002 research and implementation-callback work.
  All B002 validators and leases are complete and released. Current or future
  report path, report count, validation, execution, move, archive, and lifecycle state
  are external validator/supervisor-owned state and are not asserted here.

## Executive Recommendation

- Keep UID00011V semantically owned by UID0000E4 but make it a false/blank split index.
  Semantic documentation ownership is independent of whether an aggregate emits source.
- Route every handwritten exact child to UID0000E4 and then UID0000O8. The direct class
  emits one complete declaration; exact children emit method definitions in deterministic
  positions 10 through 110.
- Emit an empty ordinary destructor body. Its member/base cleanup is source-authored by
  declaration but compiler-lowered in the binary. Do not transcribe vptr resets, vector
  free guards, Pane teardown, or optional delete ABI.
- Emit `ApplyStyleState` as a private retained method. Its complete standalone body has no
  external xref, but the constructor contains behavior-identical inlined logic and the
  linker retained the out-of-line body. That pattern supports an inlined call site plus
  retained externally linked private source method; blank/no-route treatment would leave
  proven target behavior unmodeled.
- Emit the nested class declaration once inside UID0000E4 because the outer class owns an
  embedded by-value nested object and needs its complete type. Close the complete outer
  class before its `[[CHILDREN]]` marker so generated child definitions are at namespace
  scope. B002 owns UID0000E4 only; B005 owns UID0000E5 and its covered declaration marker
  plus every UID00011U exact method child. C18 froze the page-exclusive order; B002's
  first callback is complete, and no page was shared or edited concurrently.
- Keep UID00011Y and UID000252 as non-emitting aggregates; add exact child links rather
  than broad ownership. Keep all adjacent controls outside UID0000E4.

## Supervisor Active Recheck

- The accepted callback preserved the Gate-1 research and applied its split repair to the
  B002-owned pages without changing B005-owned documentation.
- The historical mixed interval is now a false/blank semantic split index, so source is
  emitted only by exact outer children and compiler/padding regions remain non-handwritten.
- Every target source-bearing item has a registered exact child, metadata, position, and
  synchronized managed block. Every non-source item has an exact compiler, padding,
  support, or excluded-sibling disposition.
- UID00011U is not duplicated. Its B005 report remains the authoritative research record
  for nested child methods and UID0000E5 emission; this report is authoritative for the
  UID0000E4 outer declaration, outer layout, and outer virtual ABI. B005's completed stable
  coordination artifact is exact SHA256
  `321CD4518BDB36ACF55A6B9AAF3DE2E434E56AF7462FC6F1C242B318CB7D1811`. A direct
  case-sensitive managed-body comparison proves its Destination 2 is byte-for-byte the
  same shared declaration as this report's Destination 2, and its Destination 3 is
  byte-for-byte the same route marker as this report's Destination 17. The frozen B005
  artifact remained exact at callback verification time; B002 did not apply Destination
  17 or edit any B005-owned page.
- B005 SHA `321CD451...` records B002 SHA `34D94142...` as the source snapshot it adopted.
  The Gate-1 repair changed only coordination evidence/prose outside Destinations 2 and
  17; those managed bodies remained unchanged from `34D94142...` and were compared again
  against B005 after callback application. Thus the one-way B005 source-snapshot citation
  is not a declaration drift or circular edit dependency.

## Inference Research Guidance Check

- Split-first discipline was applied before ownership or C++ decisions. The physical
  filename range was not treated as proof that every contained function belongs to
  StaticTextControlPane2.
- Existing generic labels such as raw bounds/update helper, raw style-state applier,
  non-deleting destructor helper, and `GetControlTypeId` were treated as provisional.
  Callers, vtable position, body semantics, and sibling conventions were used to resolve
  human source names.
- IDA fact, documentation evidence, and inference remain separated below. Address ranges,
  bytes, xrefs, constants, calls, vptr stores, and field accesses are facts. Class/file
  routes and existing names are documentation evidence. Private field spellings and the
  retained-method explanation are bounded inference.
- `by-structure.md` policy supports exact children, semantic parent ownership without
  parent emission, compiler-marker coverage, and validator-assigned UIDs during serial
  registration.
- No stale Wave2/Wave3 artifact was used as evidence. Any such mentions encountered in
  broad searches were ignored under the current workflow.

## Heuristic / Inference Reanalysis And Validation

- **Base and constructor type:** live construction calls the accepted
  `ControlPane(unsigned char, const RectBounds *)` route with control type 8 and null
  bounds. The lower Pane constructor receives its own internal type during ControlPane
  construction; the existing direct Pane/type-1 claim is superseded.
- **Class size and fields:** all eight constructor callers allocate decimal 680
  (`0x2a8`). The next proven member after the text storage is `m_fillColor` at `+0x158`;
  therefore `+0x108..+0x157` is one exact `0x50`-byte source-layout interval. The
  highest-probability human declaration is `wchar_t m_textBuffer[40]`, not a 32-element
  array followed by a synthetic reserve. It closes exactly at `+0x158` and needs no
  invented field boundary.
- **Sixteen-byte candidate audit:** `RectBounds` and `FontStyleRule` are both 16-byte
  project types, but neither construction/copy/init/access pattern appears at `+0x148`;
  no target body takes that address; and the exact constructor/destructor/caller pass
  finds no lifecycle or semantic route for either. Four anonymous integers, an opaque
  record, and an explicit reserve have the same no-evidence defect. Compiler padding is
  impossible here: a 32-wide-character array ends at aligned `+0x148`, while the next
  four-byte color at `+0x158` would require no intervening padding. In contrast, a
  40-wide-character array is a single natural field that exactly consumes the interval.
  This is the accepted source shape; the old generic reserve is explicitly rejected.
- **External member/pointer audit:** target-range rendered-disassembly searches found no
  `+0x148`, `+0x150`, or `+0x154` access and only unrelated scalar-wrapper immediates at
  `+0x14c/+0x150`. All three exact constructor-caller functions (`0x00450ca0`,
  `0x004523d0`, and `0x0047d050`) likewise contain no access to `+0x148/+0x14c/+0x150/
  +0x154`. Whole-text `mov`/`lea` displacement scans for those four offsets produced no
  target-method or target-caller pointer-taking route; their hits belong to unrelated
  object families. The target constructor exposes only `+0x108` to `wcscpy_s` and the
  child-string assignment.
- **Analogous-layout audit:** current StaticTextControlPane2 documentation already warns
  that the literal `0x20` copy bound may not be the full field extent. Older StaticText
  owns a different TextEditPane-based layout with packed state at `+0x108` and a child
  pointer at `+0x10c`; HelpPane/SimpleHelpTextPartPane owns `SimpleUString` text at
  `+0xf8` and a FontStyle pointer at `+0xfc`. Neither supplies a competing 16-byte member
  at this boundary. Nearby CheckBoxControlPane provides the useful contrast: two proven
  `wchar_t[16]` fields at `+0x108/+0x128` are followed by frame fields at `+0x148/+0x14a`,
  and those boundaries have direct constructor/paint reads and writes. Other documented
  16-byte RectBounds/FontStyleRule members likewise have positive copy, init, or consumer
  evidence absent here.
- **Text buffer:** `wcscpy_s` receives explicit capacity `0x20`, proving a 32-character
  accepted-copy limit, not the declaration's physical extent. Measurement happens before
  the checked copy, and only the destination start is passed onward. The first draft keeps
  `wcscpy_s(m_textBuffer, 32, text)` exactly while declaring the enclosing field as
  `wchar_t m_textBuffer[40]`; the final eight elements have no observed independent use.
- **Measurement:** CR, LF, and tab are each independent delimiters; CRLF therefore counts
  as two breaks. Every segment and the final tail are measured. Width is maximum segment
  width plus double horizontal padding. Height is line count times line height plus
  interline spacing and double vertical padding.
- **Alignment:** horizontal values 0/1/other map to left/right/center; vertical values
  3/4/other map to top/bottom/center. The bounds are then clamped to screen width/height.
  These are exact observed integers; no unsupported enum names are introduced.
- **Bounds helper name:** its only direct caller passes already transformed display-space
  marker coordinates to both this pane and MiniMapSymbolControlPane's accepted
  `SetCenterPosition`. The body rebuilds a rectangle around a center and does not accept
  a rectangle. `SetCenterPosition` is therefore stronger than generic `SetBounds`,
  `SetPosition`, or map-coordinate names.
- **Style helper liveness:** no direct entry xref exists, but the standalone body is valid
  code through `0x0049ac59`, and the constructor contains the same style transition after
  complete object setup. The highest-probability source shape is a private method called
  by the constructor and inlined there while an out-of-line copy remained. Treating it
  as padding or formal no-code would discard a complete source-authored body.
- **FontStyle copy:** the optional style object is copied with the ordinary assignment
  operator at `0x0049ada0`; its vector is deep-copied. The source must use assignment, not
  manual allocator/memmove code.
- **Opacity:** parent style disabled returns immediately. Enabled parent opacity at least
  1 selects mode 1; nonnegative values below 1 select mode 3 and update alpha; negative
  values skip parent mode/alpha but do not skip colors or child logic. Child opacity at
  or below 0 selects mode 1; values in `(0,1]` select mode 3 and alpha; values above 1 do
  nothing.
- **Colors:** FontStyle foreground/background fields feed the pane fill/frame fields.
  `OnPaint` uses those fields with the established `FillRect` and `DrawRectFrame` routes.
- **Embedded child access:** the outer constructor sets the child's owned text, padding,
  spacing, and borrowed FontStyle pointer. A friend declaration is the least invasive
  valid C++ expression because B005's accepted nested fields are private and the raw child
  setters have no supported source entry.
- **Ordinary destructor:** raw teardown has no external entry. It is nevertheless the
  compiler lowering of the source-declared virtual destructor: vptr resets, child string
  and Pane teardown, FontStyle vector deallocation guard, and base Pane teardown are all
  generated from members/bases. An empty source body is behavior-identical and regenerates
  the cleanup.
- **Scalar wrapper/adjustors/vtables:** all are compiler-generated consequences of the
  ordinary virtual destructor and multiple Pane views. Marker or blank treatment avoids
  handwritten MSVC ABI.
- **Type virtual ABI:** the primary vtable's terminal `+0x60` cell `0x00618664` points to
  `0x0049b910`, exactly `mov al,18h; retn 8`. IDA independently types the body as a
  one-byte return with two `int` arguments. ControlPane's corresponding terminal cell
  `0x00617af0 -> 0x0041d690` and CheckBoxText, MiniMapSymbol, CheckBox, Popup, Rectangle,
  Scrollable, and older StaticText overrides all have the same `char(int,int)` lowering,
  fixed AL return, and `retn 8`. The accepted source shape is therefore
  `unsigned char GetControlType(int, int)`; the unused arguments remain unnamed.
  Under 32-bit MSVC `this` is in ECX, the two four-byte explicit arguments account for
  callee cleanup of eight bytes, and the unsigned-byte return accounts for `AL` rather
  than a required full-EAX write. The non-const member form is selected because the two
  implemented sibling formal declarations and B005's integrated outer declaration use
  that project-local convention; a `const` qualifier would have the same observed stack
  layout, but has weaker source-shape support and is rejected for this first draft.
- **Type virtual caller check:** `xrefs_to` finds only the primary-vtable data reference,
  no ordinary direct caller. A whole-text scan of common indirect `call [reg+60h]`
  encodings found nine unrelated virtual layouts and no target/control-type dispatch.
  Thus the contract is established by the exact callee cleanup plus base/sibling slot
  parity, not by inventing a direct caller. Existing no-argument Popup/CheckBoxText docs
  contradict their live `retn 8` bodies and are retained only as stale historical leads.
  `GetControlTypeId` remains a superseded descriptive alias.
- **Nested declaration conflict and ownership:** B005's nested method/class research is
  behaviorally authoritative but cannot coexist with a second complete declaration.
  B002 owns the complete UID0000E4 outer/nested declaration and its namespace-scope child
  marker. B005 alone owns UID0000E5's covered declaration marker and every UID00011U
  nested child. Exact B005 SHA `321CD451...` now embeds the identical shared declaration
  and route marker and explicitly marks UID0000E4 verify-only for B005. The deterministic
  accepted order froze both synchronized report artifacts, then B002 implemented
  UID0000E4 and outer children without touching UID0000E5. B005's UID00011U `a403`
  parent correction and UID0000E5/nested children remain exclusively B005-owned; B002
  made no silent callback adaptation to that external scope.
- **Rejected alternatives:** do not assign FontStyle vector growth/copy assignment to the
  target; do not assign the shared EH funclet to either class as handwritten source; do
  not fold Popup or adjacent control ABI rows into this class; do not emit raw vtable
  arrays; do not make the broad aggregate itself emit duplicate source.
- **Residual uncertainty:** exact original array-count intent behind the explicit
  32-character copy limit, member cv for the terminal virtual, private color/layout names,
  and original header split are stripped. The accepted declarations are behavior- and
  layout-backed; these uncertainties cap confidence below 95 but do not leave a generic
  reserve, stack-ABI, ownership, split, or formal-C++ blocker.

## Evidence Standards Used

- Primary evidence: live MCP function lookup/decompile/disassembly, raw bytes, code/data
  xrefs, caller/callee sets, vptr writes, vtable pointer reads, constants, field offsets,
  and exact adjacent boundaries.
- Corroboration: current by-* metadata and prose, accepted sibling class/method source
  shapes, B005's completed stable nested-child report SHA `321CD451...`, executed
  MiniMap/FontStyle/static-text research, generated source observation, and source-tree
  ownership routes.
- Negative evidence: no external entries to raw destructor/style starts; no pointer-table
  routes to them; no target-owned access or pointer-taking boundary at `+0x148`; no caller
  or vtable route from adjacent sibling controls into UID0000E4; no evidence for manual
  scalar/vtable source.
- The evidence ladder gives greatest weight to exact live binary behavior, then repeated
  caller/vtable/layout patterns, then current documentation, and finally bounded naming
  inference. Decompiler type labels alone were not accepted.
- Tool limitations affect original spelling, not behavior. The complete executable body,
  all relevant routes, and exact bytes were available, so no fallback-only conclusion is
  used.

## Evidence Checked

- Live MCP: fresh `idb_list`; `server_health`; lookups for every requested target start,
  every adjacent support/sibling start, all three target vtables, callers, callees, xrefs,
  strings, and globals; decompile/disassembly of target methods; raw bytes over every gap.
- ABI/layout repair checks: exact disassembly/xrefs for ControlPane and eight fixed-type
  overrides; raw primary-vtable bytes; indirect `[reg+0x60]` call-pattern scan; target and
  exact-constructor-caller searches for `+0x148/+0x14c/+0x150/+0x154`; and whole-text
  `mov`/`lea` displacement scans for possible external record/pointer access.
- Boundary checks: function heads and terminators establish corrected raw ends
  `0x0049a949`, `0x0049aa71`, and `0x0049ac59`; all listed gaps are `0xcc` alignment.
- Documentation: UID00011V, UID0000E4, UID0000O8, UID0000E5, UID00011U/B005,
  UID00005C, UID0001UN, FontStyle core/vector support, UID000038 ControlPane, Pane,
  PaneSetMode, GrafPort metrics/effects, Surface callbacks, RectBounds, screen globals,
  UID00011Y, UID000252, `-ignored`, UID000222, and source-file/generated routes.
- Cross-report synchronization: B005 completed artifact SHA
  `321CD4518BDB36ACF55A6B9AAF3DE2E434E56AF7462FC6F1C242B318CB7D1811`; direct
  case-sensitive comparison found B002 Destination 2 equal to B005 Destination 2
  (`2026` characters; normalized managed-body SHA256
  `19219d0ab438a9aab2a9bc2fd4b53f436bd250d266ca5f9ab4f5151448a2a114`) and B002
  Destination 17 equal to B005 Destination 3 (`196` characters; SHA256
  `40d419cc74fec2979c4eac43f69d9abe0c7270fe54eded27685c8d4502fb5ec2`).
- Historical reports: searched by UID, exact address, class/helper names, and source path.
  Only directly relevant executed/active reports were used as leads and each live claim was
  independently rechecked.
- Negative checks: external xrefs into raw starts/interiors, pointer routes, a separate
  member/access boundary at `+0x148`, duplicate generated class/method source, sibling
  vtable ownership, and alternate source-file ownership.
- Failed/unavailable checks: none during the accepted evidence pass. No IDA mutation,
  external fallback-only evidence, process management, or validator/lifecycle command was
  attempted.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID00011V is a semantic UID0000E4 split index at `92/94`, false, blank emitter/position/C++. | High | Mixed-owner interval and exact child inventory | UID00011V | Applied metadata/index rewrite | Applied and verified |
| C02 | Correct raw ends and preserve every exact `0xcc` padding span. | High | Live terminators/raw bytes | UID00011V, exact children, `-ignored` | Applied | Applied and verified |
| C03 | UID0000E4 is a `0x2a8` ControlPane-derived class with one `wchar_t[40]` field at `+0x108..+0x157`, no synthetic 16-byte reserve, and the exact outer/nested layout. Completed B005 SHA `321CD451...` adopts byte-identical Destination 2. | High-medium | Eight allocations, exact next-member boundary, ctor/dtor/caller/offset/type audit, shared-block equality SHA | UID0000E4 | B002 applied Destination 2 at `92/93`; B005 verify-only | Applied and verified |
| C04 | Constructor is `0x0049a410-0x0049a8ac`, base type 8, position 10. | High | Live body/callers/base ctor | UID0004KS | Created/applied Destination 3 | Applied and verified |
| C05 | Constructor default FontStyle is disabled before optional deep-copy assignment. | High | Stores and sole assignment call | UID0004KS/class/file | Applied | Applied and verified |
| C06 | Constructor measures CR/LF/tab segments and exact padded dimensions. | High | Complete loop/callees | UID0004KS/class/file | Applied | Applied and verified |
| C07 | Constructor alignment, screen clamp, delayed checked copy, child setup, and style call are exact. | High | Complete body/globals/fields | UID0004KS/class/file | Applied | Applied and verified |
| C08 | Eight caller sites, four literals, allocations, and argument sets constrain signature/semantics. | High | Direct xrefs/raw UTF-16 | UID0004KS/file | Applied | Applied and verified |
| C09 | `0x0049a8b0-0x0049a949` is the ordinary destructor and emits an empty body at position 20. | High | Teardown body/no external entry/scalar parity | UID0004KT | Created/applied Destination 4 | Applied and verified |
| C10 | `0x0049a950-0x0049aa71` is `SetCenterPosition`, position 30. | High | Sole MiniMap caller and center bounds body | UID0004KV | Created/applied Destination 5 | Applied and verified |
| C11 | Add-to-layer forwards base then child to overlay context, position 40. | High | Exact call sequence/global | UID0004KW | Created/applied Destination 6 | Applied and verified |
| C12 | Remove, Show, and Hide preserve exact child/base ordering, positions 50/60/70. | High | Exact bodies/vtable refs | UID0004KX/0004KY/0004KZ | Created/applied Destinations 7-9 | Applied and verified |
| C13 | `OnPaint` fills and frames current bounds with style colors, position 80. | High | Exact body/callbacks/vtable | UID0004L0 | Created/applied Destination 10 | Applied and verified |
| C14 | Raw style body is a retained private `ApplyStyleState`, position 90, not no-code. | High-medium | Complete standalone body plus ctor inlining | UID0004L1 | Created/applied Destination 11 | Applied and verified |
| C15 | Parent enabled/opacity/mode/color transitions preserve every branch. | High | Complete style body | UID0004L1/class/file | Applied | Applied and verified |
| C16 | Child style pointer/enabled/text-opacity transitions preserve every branch. | High | Complete style body/child fields | UID0004L1/class/file | Applied | Applied and verified |
| C17 | FontStyle needs six exact inline accessors; all existing fields/methods remain. | High | Direct consumer reads/writes | UID00005C | Applied Destination 18 at `89/91` | Applied and verified |
| C18 | UID0000E4 is exclusively B002-owned; UID0000E5 and UID00011U are exclusively B005-owned. Exact B005 SHA `321CD451...` has byte-identical Destination 2/route blocks and marks UID0000E4 verify-only. The synchronized revisions established B002 outer callback first and B005 `a403` parent/nested callback second; B002 completed its scope without editing UID0000E5, while B005 state remains external. | High | C++ completeness, no-duplicate rule, exact B005 report SHA, direct managed-body equality hashes | UID0000E4/UID0000E5/UID00011U coordination | B002 scope applied; Destination 17 comparison-only; no B005 page leased/edited | Applied and verified for B002 scope |
| C19 | Scalar wrapper is compiler ABI at position 100 with marker only. | High | Flags/delete path/vtable/thunks | UID0004L3 | Created/applied Destination 13 | Applied and verified |
| C20 | Two target adjustors are false/no-owner/no-emitter/blank. | High | `this` deltas and tail jumps | UID0004L2 | Created/applied Destination 12 | Applied and verified |
| C21 | Type virtual returns unsigned byte 24 as non-const `GetControlType(int, int)`, position 110; byte return regenerates AL and two explicit four-byte arguments regenerate `ret 8`. Completed B005 Destination 2 adopts the exact declaration. | High for binary ABI; high-medium for source cv/spelling | Exact body, ControlPane terminal slot, seven sibling implementations, data-only xref, indirect-caller negative scan, local declaration convention, cross-report block equality | UID0004L4 | Created/applied Destination 14 | Applied and verified |
| C22 | Three exact vtable views and RTTI boundaries belong semantically to UID0000E4. | High | Locator/table reads/vptr stores | UID0004L5 | Created/applied Destination 15 | Applied and verified |
| C23 | Exact `0x00618600-0x006186a4` data is compiler-covered, position 130. | High | Raw pointer table/boundaries | UID0004L6 | Created/applied Destination 16 | Applied and verified |
| C24 | UID0000O8 is the direct source file at `92/92`; no alternate owner fits. | High | Class locality, callers, existing route | UID0000O8 | Applied complete source inventory | Applied and verified |
| C25 | UID00011Y remains false/blank and links target adjustor/scalar exact children. | High | Mixed compiler aggregate | UID00011Y | Support synchronized | Applied and verified |
| C26 | UID000252 remains false/blank and links exact target vtable data child. | High | Broad read-only aggregate | UID000252 | Support synchronized | Applied and verified |
| C27 | All target-local and historical-interval alignment is compiler padding. | High | Raw `0xcc` bytes | `by-memory/-ignored.md` | Exact grouped row applied | Applied and verified |
| C28 | FontStyle growth/copy and shared EH cleanup retain their existing owners/dispositions. | High | Calls/xrefs/body roles | FontStyle support/UID00011V | Preserved/excluded | Applied and verified |
| C29 | Slider/TextEdit/TargetOption/TextButton/Rectangle/Scrollable and all other sibling ABI rows stay excluded. | High | Distinct vtable refs and exact ranges | UID00011V/UID00011Y | Exclusions preserved | Applied and verified |
| C30 | Deterministic file-class positions are UID0000E3 `10`, UID0000E4 `20`, UID0000E5 `30`; target method/compiler marker positions are 10-130 as specified. | High | Source dependency/order and complete-type requirement | Class/file/exact children | Definite B002 positions applied; B005 position preserved in file plan | Applied and verified |
| C31 | B002-stage waited output contains one complete outer/nested declaration with namespace-scope outer children, each outer source method, no UID00011V Empty Marker, and no handwritten ABI. Nested-child output and UID0000E5/UID00011U marker state belong to the ordered external B005 stage under exact SHA `321CD451...`. | High | Generator model, exact shared-block equality, exclusive callback ownership | Generated verification split by callback owner | B002 stage verified by command `000000009385` and preserved by later validator-owned refresh `000000009396`; B005 stage external | Applied and verified for B002 scope |
| C32 | No-xref raw destructor/style evidence is reconciled by source/compiler disposition, not deferred. | High-medium | Exhaustive entry checks and body parity | Raw children/report | Rationale applied | Applied and verified |
| C33 | Accept `SetCenterPosition`, `ApplyStyleState`, `GetControlType`; reject generic/superseded aliases. | High-medium | Call/body/vtable semantics | Exact children/class/file | Names/history applied | Applied and verified |
| C34 | Pane, ControlPane, GrafPort, Surface, RectBounds, screen, and existing child method docs remain read-only unless callback drift is concrete. | High | Same-or-greater support review | Dependencies | Verified only; no concrete drift | Applied and verified |
| C35 | No manual coverage/tracker row is needed; scoped validators must own generated refresh. | High | Validator ownership policy | Report/validator plan | Preserved; validator-generated side effects only | Applied and verified |

## Positive Evidence Summary

- Eight direct constructor calls agree on a `0x2a8` allocation and ten arguments. Four
  MiniMap setup calls use the recovered literals `NPC`, `Portal`, `X : `, and `Y : `;
  two dynamic MiniMap paths and one coordinate-label path constrain alignment/padding;
  NewMail uses `Keep a copy `.
- The exact constructor closes every meaningful offset through `+0x2a7`, invokes the
  accepted ControlPane constructor, builds the embedded child, deep-copies optional
  FontStyle state, measures and clamps text, and performs the complete style transition.
- The text destination starts at `+0x108`, the next proven color starts at `+0x158`, and
  no constructor/destructor/target/caller/pointer-taking route creates a boundary inside
  that `0x50`-byte interval. This supports one `wchar_t[40]` field while preserving the
  explicit 32-character checked-copy limit.
- The sole bounds-helper caller applies the same center coordinate to this pane and the
  accepted MiniMapSymbolControlPane center setter, directly supporting the source name.
- Primary vtable slots directly identify Add/Remove/Show/Hide/OnPaint/type methods; the
  secondary and tertiary tables directly identify the two target adjustors.
- The target type virtual, ControlPane terminal slot, and seven sibling implementations
  all return in AL and execute `retn 8`; this independently fixes a one-byte return and
  two four-byte explicit arguments even though no ordinary direct caller survives.
- The ordinary teardown and scalar wrapper operate on the same child, FontStyle, and Pane
  state as construction. Their difference is exactly source destructor versus deleting
  ABI wrapper.
- Vptr stores in construction, ordinary teardown, and scalar teardown independently
  confirm all three vtable views and exact class ownership.
- Corrected end bytes and all `0xcc` gaps leave no unexplained target-local executable
  bytes.

## IDA MCP Facts

- Constructor `0x0049a410-0x0049a8ac` is modeled at size `0x49c`; eight callers allocate
  `0x2a8` bytes.
- Raw ordinary destructor is exactly `0x0049a8b0-0x0049a949`; the invalid-parameter tail
  call through `0x0049a944` proves the old `0x0049a945` end was truncated.
- Bounds helper is now modeled at `0x0049a950`, size `0x121`, exact end
  `0x0049aa71`; its sole code caller is `0x00452f3d`. The existing documented
  `0x0049aa6d` end is a historical truncated endpoint superseded by the live return and
  four-byte tail through `0x0049aa71`.
- Add/Remove/Show/Hide are exactly `0x0049aa80-0x0049aaba`,
  `0x0049aac0-0x0049aada`, `0x0049aae0-0x0049aaf8`, and
  `0x0049ab00-0x0049ab18`.
- OnPaint is exactly `0x0049ab20-0x0049ab79`.
- Raw style helper is exactly `0x0049ab80-0x0049ac59`; the pop/return at
  `0x0049ac57-0x0049ac58` proves the old `0x0049ac57` end was truncated.
- Target adjustors are `0x0049b019-0x0049b024` and `0x0049b024-0x0049b02f`;
  scalar wrapper is `0x0049b5f0-0x0049b6bc`; type virtual is
  `0x0049b910-0x0049b915`.
- Type-virtual disassembly is exactly `mov al,18h; retn 8`, with IDA arguments
  `int arg0, int arg1`. Its only xref is primary-vtable cell `0x00618664`; there is no
  ordinary code xref. ControlPane terminal cell `0x00617af0 -> 0x0041d690` returns `10`
  with the same lowering. Sibling fixed overrides are `0x004214c0 -> 22`,
  `0x004563b0 -> 23`, `0x0049b8d0 -> 20`, `0x0049b8e0 -> 12`,
  `0x0049b8f0 -> 21`, `0x0049b900 -> 18`, and `0x0049b920 -> 19`; every body uses
  `mov al,imm8; retn 8` and IDA's `char(int,int)` prototype.
- FontStyle support in the interval is vector growth `0x0049ac60-0x0049ad74`, shared EH
  cleanup `0x0049ad80-0x0049ad96`, and copy assignment
  `0x0049ada0-0x0049aefe`. Popup callback support is `0x0049af00-0x0049af11`.
- Primary locator/table are `0x00618600`/`0x00618604`; secondary are
  `0x00618668`/`0x0061866c`; tertiary are `0x00618698`/`0x0061869c`. The exact cluster ends
  at `0x006186a4` before successor RTTI/table data.
- Primary vptr stores occur at `0x0049a489`, `0x0049a8ba`, `0x0049b5fd`; secondary at
  `0x0049a48f`, `0x0049a8c0`, `0x0049b603`; tertiary at `0x0049a499`, `0x0049a8ca`,
  `0x0049b60d`.
- Raw destructor/style starts have no external entry xrefs; all interior references are
  internal control flow. This is negative route evidence, not padding evidence.

### Exact primary vtable view

| Slot | Entry | Disposition |
| --- | --- | --- |
| 0 | `0x0049b5f0` | target scalar deleting destructor |
| 1 | `0x004f4b10` | inherited Pane/ControlPane slot |
| 2 | `0x0041b6c0` | inherited slot |
| 3 | `0x004b8e20` | inherited slot |
| 4 | `0x0041d680` | inherited slot |
| 5 | `0x0049aae0` | target Show |
| 6 | `0x0049ab00` | target Hide |
| 7 | `0x005447a0` | inherited slot |
| 8 | `0x00544800` | inherited slot |
| 9 | `0x00544a20` | inherited slot |
| 10 | `0x00544b80` | inherited slot |
| 11 | `0x00544bd0` | inherited SetBounds route |
| 12 | `0x0049aa80` | target AddToLayer |
| 13 | `0x00544cb0` | inherited slot |
| 14 | `0x0049aac0` | target RemoveFromLayer |
| 15 | `0x00544d30` | inherited slot |
| 16 | `0x00544d70` | inherited slot |
| 17 | `0x0049ab20` | target OnPaint |
| 18 | `0x00494b80` | shared control slot |
| 19 | `0x00494bb0` | shared control slot |
| 20 | `0x00494bd0` | shared control slot |
| 21 | `0x00494c00` | shared control slot |
| 22 | `0x00494c10` | shared control slot |
| 23 | `0x00494c30` | shared control slot |
| 24 | `0x0049b910` | target GetControlType |

Slot 24 is byte offset `+0x60` from the primary vtable start. The ControlPane base table
uses the same terminal slot for `0x0041d690`; fixed sibling tables replace that slot with
their class constant-return overrides. This is the inherited two-argument control-type
contract, not a no-argument leaf function selected by physical adjacency.

### Exact secondary and tertiary views

| View | Entries | Disposition |
| --- | --- | --- |
| Secondary at `0x0061866c` | `0x0049b019`, `0x00544db0`, two `0x0041d6b0`, `0x00544de0`, `0x00544df0`, `0x00544e00`, `0x004a89f0`, `0x00544e10`, `0x00544e30`, `0x00544e70` | target adjustor followed by inherited secondary Pane view |
| Tertiary at `0x0061869c` | `0x0049b024`, `0x00544e90` | target adjustor followed by inherited tertiary Pane view |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0049a410-0x0049b915` | UID00011V | mixed historical aggregate/split index | false | UID0000E4 semantic | `92/94` | applied, blank C++ |
| `0x0049a410-0x0049a8ac` | UID0004KS `StaticTextControlPane2Constructor` | source constructor | true | UID0000E4 | `92/94` | registered, pos 10 |
| `0x0049a8b0-0x0049a949` | UID0004KT `StaticTextControlPane2Destructor` | source ordinary destructor | true | UID0000E4 | `91/93` | registered, pos 20 |
| `0x0049a950-0x0049aa71` | UID0004KV `StaticTextControlPane2SetCenterPosition` | source helper | true | UID0000E4 | `92/94` | registered, pos 30 |
| `0x0049aa80-0x0049aaba` | UID0004KW `StaticTextControlPane2AddToLayer` | source virtual | true | UID0000E4 | `91/93` | registered, pos 40 |
| `0x0049aac0-0x0049aada` | UID0004KX `StaticTextControlPane2RemoveFromLayer` | source virtual | true | UID0000E4 | `91/93` | registered, pos 50 |
| `0x0049aae0-0x0049aaf8` | UID0004KY `StaticTextControlPane2Show` | source virtual | true | UID0000E4 | `91/93` | registered, pos 60 |
| `0x0049ab00-0x0049ab18` | UID0004KZ `StaticTextControlPane2Hide` | source virtual | true | UID0000E4 | `91/93` | registered, pos 70 |
| `0x0049ab20-0x0049ab79` | UID0004L0 `StaticTextControlPane2OnPaint` | source virtual | true | UID0000E4 | `92/94` | registered, pos 80 |
| `0x0049ab80-0x0049ac59` | UID0004L1 `StaticTextControlPane2ApplyStyleState` | retained source helper | true | UID0000E4 | `92/93` | registered, pos 90 |
| `0x0049b019-0x0049b02f` | UID0004L2 `StaticTextControlPane2AdjustorThunks` | compiler adjustors | false | NONE | `90/94` | registered, blank |
| `0x0049b5f0-0x0049b6bc` | UID0004L3 `StaticTextControlPane2ScalarDeletingDestructor` | source-declared/generated ABI | true | UID0000E4 | `91/94` | registered, pos 100 marker |
| `0x0049b910-0x0049b915` | UID0004L4 `StaticTextControlPane2GetControlType` | source virtual `unsigned char(int,int)` | true | UID0000E4 | `92/94` | registered, pos 110 |
| three vtable views | UID0004L5 `by-type/by-vtable/StaticTextControlPane2Vtables.md` | declaration support | true | UID0000E4 | `90/94` | registered, pos 120 marker |
| `0x00618600-0x006186a4` | UID0004L6 `StaticTextControlPane2VtableData` | compiler data/RTTI coverage | true | UID0000E4 | `91/94` | registered, pos 130 marker |

### Excluded in-range support and sibling inventory

| Range | Role / owner | Disposition |
| --- | --- | --- |
| `0x0049ac60-0x0049ad74` | FontStyle rule-vector growth | retain FontStyle/template support; no target source |
| `0x0049ad80-0x0049ad96` | shared EH cleanup funclet/tail | compiler support; metadata references target and HelpPane constructors |
| `0x0049ada0-0x0049aefe` | FontStyle copy assignment | retain FontStyle support; source uses assignment |
| `0x0049af00-0x0049af11` | Popup selection callback invoke | Popup owner, excluded |
| `0x0049af11-0x0049af27` | SelectBox adjustors | sibling compiler support |
| `0x0049af27-0x0049af3d` | CheckBox adjustors | sibling compiler support |
| `0x0049af3d-0x0049af53` | Control/Progress adjustors | sibling compiler support |
| `0x0049af53-0x0049af69` | EPFImage adjustors | sibling compiler support |
| `0x0049af69-0x0049af7f` | ImageButton adjustors | sibling compiler support |
| `0x0049af7f-0x0049af95` | NumericString adjustors | sibling compiler support |
| `0x0049af95-0x0049afab` | Popup adjustors | sibling compiler support |
| `0x0049afab-0x0049afc1` | Radio adjustors | sibling compiler support |
| `0x0049afc1-0x0049afd7` | Rectangle adjustors | sibling compiler support |
| `0x0049afd7-0x0049afed` | Scrollable adjustors | sibling compiler support |
| `0x0049afed-0x0049b003` | embedded SimpleHelpTextPartPane adjustors | UID00011U/B005 compiler support |
| `0x0049b003-0x0049b019` | Slider adjustors | sibling compiler support |
| `0x0049b02f-0x0049b045` | TextEdit adjustors | sibling compiler support |
| `0x0049b045-0x0049b05b` | TargetOptionEdit adjustors | sibling compiler support |
| `0x0049b05b-0x0049b071` | TextButton adjustors | sibling compiler support |
| `0x0049b071-0x0049b087` | TextButtonEx adjustors | sibling compiler support |
| `0x0049b090-0x0049b0ce` | function-object scalar wrapper | distinct ABI owner |
| `0x0049b0d0-0x0049b10b` | SelectBox scalar wrapper | sibling compiler support |
| `0x0049b110-0x0049b165` | CheckBox scalar wrapper | sibling compiler support |
| `0x0049b170-0x0049b1ab` | Control/Progress scalar wrapper | sibling compiler support |
| `0x0049b1b0-0x0049b24f` | EPFImage scalar wrapper | sibling compiler support |
| `0x0049b250-0x0049b28e` | function-object scalar wrapper | distinct ABI owner |
| `0x0049b290-0x0049b2e5` | ImageButton scalar wrapper | sibling compiler support |
| `0x0049b2f0-0x0049b3af` | NumericString scalar wrapper | sibling compiler support |
| `0x0049b3b0-0x0049b417` | Popup scalar wrapper | sibling compiler support |
| `0x0049b420-0x0049b487` | Radio scalar wrapper | sibling compiler support |
| `0x0049b490-0x0049b4e5` | Rectangle scalar wrapper | sibling compiler support |
| `0x0049b4f0-0x0049b557` | Scrollable scalar wrapper | sibling compiler support |
| `0x0049b560-0x0049b5a8` | embedded SimpleHelpTextPartPane scalar wrapper | UID00011U/B005 compiler support |
| `0x0049b5b0-0x0049b5eb` | Slider scalar wrapper | sibling compiler support |
| `0x0049b6c0-0x0049b731` | TextEdit scalar wrapper | sibling compiler support |
| `0x0049b740-0x0049b795` | TargetOptionEdit scalar wrapper | sibling compiler support |
| `0x0049b7a0-0x0049b854` | TextButton scalar wrapper | sibling compiler support |
| `0x0049b860-0x0049b8c7` | TextButtonEx scalar wrapper | sibling compiler support |
| `0x0049b8d0-0x0049b8d5` | CheckBox type virtual | sibling source child |
| `0x0049b8e0-0x0049b8e5` | Popup type virtual | sibling source child |
| `0x0049b8f0-0x0049b8f5` | Rectangle type virtual | sibling source child |
| `0x0049b900-0x0049b905` | Scrollable type virtual | sibling source child |
| `0x0049b920-0x0049b925` | UID000222 older StaticText type virtual | successor outside target |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00450fbf` | MiniMap setup -> constructor | `NPC`, x 80, y 730, h 0, v 3, zero padding/spacing |
| `0x0045106c` | MiniMap setup -> constructor | `Portal`, x 125, y 730, h 0, v 3 |
| `0x004510fa` | MiniMap setup -> constructor | `X : `, x 520, y 730, h 0, v 3 |
| `0x0045118f` | MiniMap setup -> constructor | `Y : `, x 580, y 730, h 0, v 3 |
| `0x00452908` | MiniMap dynamic label path -> constructor | dynamic text/coordinates, h 2, v 4 |
| `0x00452b57` | MiniMap dynamic label path -> constructor | dynamic text/coordinates, h 2, v 4 |
| `0x00452c6c` | MiniMap coordinate-label path -> constructor | x 382, y 31, h 2, v 2, horizontal padding 2 |
| `0x0047d446` | NewMail setup -> constructor | `Keep a copy `, x 56, y 386, h 0, v 3 |
| `0x00452f3d` | MiniMap marker-position path -> `0x0049a950` | same center pair then sent to MiniMapSymbolControlPane at `0x00452f4e` |
| constructor `0x0049a583` | FontStyle copy assignment `0x0049ada0` | sole assignment call; deep-copy source shape |
| constructor/style body | `g_pScreenPane` width/height helpers | screen clamp, not CursorManager ownership |
| AddToLayer | `g_mainUiLayerSlots.overlayPaneLayerContext` | embedded child attaches to overlay context |
| OnPaint | SetDrawColor, `FillRect`, `DrawRectFrame` | exact fill/frame behavior |
| ordinary destructor | child StringBase/Pane, FontStyle vector, Pane cleanup | implicit source member/base teardown |
| scalar wrapper | two target adjustors and primary vtable | compiler deleting entry, not an ordinary caller |
| type virtual | primary vtable `0x00618664`; no code xref | exact `mov al,18h; retn 8`; inherited terminal-slot contract is byte return plus two `int` arguments |

## Documentation Evidence And IDA Status

- UID00011V already identifies the broad family and sibling exclusions but has stale raw
  ends, generic names, a stale base-type statement, and blank formal source.
- UID0000E4 already routes to UID0000O8 and describes high-level measurement, alignment,
  style, child, and lifecycle behavior; exact layout and class source are missing.
- UID0000O8 already groups StaticTextControlPane, StaticTextControlPane2, and its nested
  child in `NexusTK/ui/controls/StaticTextControlPane.cpp`. Live local functions and callers
  strengthen that route; no better source file exists.
- UID0000E5 and B005's UID00011U report provide the exact `0x10c` nested class layout,
  constructor, paint, line drawing, raw-helper, adjustor, and scalar dispositions. At
  synchronization time the completed stable B005 artifact SHA was
  `321CD4518BDB36ACF55A6B9AAF3DE2E434E56AF7462FC6F1C242B318CB7D1811`. It adopts
  this report's reserve-free `wchar_t[40]`, non-const `GetControlType(int,int)`, `92/93`
  outer score, namespace-scope outer child marker, and exclusive B002 ownership. Its
  Destination 2 and UID0000E5 route marker are byte-identical to Destinations 2 and 17
  here; no provisional shared declaration remains.
- UID00005C/UID0001UN already establish the `0x20` FontStyle and 16-byte rules. Consumer
  behavior proves exact enabled/opacity/color accessors and deep-copy use.
- UID00011Y and UID000252 are correctly non-emitting broad indexes but need exact target
  child links after registration.
- Generated source is validator-owned. The evidence-time Empty Emitter Markers prove the
  blank-source blocker; they are not a license for manual generated edits.

## Ranked Ownership Analysis

### 1. UID0000E4 StaticTextControlPane2

- Evidence for: all target source methods use the same three-vptr object, exact fields,
  destructor lifecycle, type virtual, and vtable family. Constructor callers allocate the
  complete object and all exact children are class methods.
- Evidence against: the historical UID00011V interval also contains unrelated support and
  sibling compiler rows, so physical range alone is insufficient.
- Decision: retain UID0000E4 as semantic owner of UID00011V and direct owner/emitter of
  every target source-bearing exact child. Split removes the physical-range objection.

### 2. UID0000O8 StaticTextControlPane source file

- Evidence for: current class/file route, older/static variant locality, nested child,
  exact consecutive method island, shared naming, and generated destination all agree.
- Evidence against: exact original header factoring is stripped and FontStyle itself has a
  separate current file owner.
- Decision: retain UID0000O8 as class/file owner. Keep FontStyle in UID0000JI and include
  it as a support dependency rather than re-owning it.

### 3. MiniMap or NewMail feature files

- Evidence for: all observed outer callers are MiniMap or NewMail consumers.
- Evidence against: both features construct the same generic class; class methods, vtables,
  nested text renderer, and type virtual are not feature-local. Neither caller family owns
  the reusable implementation.
- Decision: reject both as owners. Preserve them as caller evidence only.

### 4. UID00011Y or UID000252 aggregate

- Evidence for: each physically contains or indexes compiler artifacts related to the
  class.
- Evidence against: both are deliberately multi-owner, non-emitting indexes and cannot own
  handwritten source.
- Decision: retain false/blank aggregate status and add exact links only.

### Proposed new file/grouping, if applicable

- No new source file is needed. UID0000O8 remains the direct source file.
- New documentation grouping consists only of exact by-memory method/compiler children,
  one by-type vtable page, and one exact vtable-data page.
- Include UID0000E4 and exact children; preserve UID0000E5/UID00011U as nested support.
- Reject FontStyle implementation, Popup callback, shared EH support, and every sibling
  control row from target ownership.

## Source Placement

- Recommended placement: declaration in the StaticTextControlPane header model and method
  definitions in `NexusTK/ui/controls/StaticTextControlPane.cpp` through UID0000O8.
- The class's older static-text sibling, nested part pane, method locality, vtable/type
  identity, and generated source route all support this placement.
- FontStyle remains in its existing UID0000JI file route. Source includes/types should
  expose it to StaticTextControlPane2; physical helper adjacency does not transfer owner.
- MiniMap and NewMail are rejected placements because they are consumers. HelpPanes is
  rejected because its analogous nested class has distinct RTTI, vtables, methods, and
  source route.
- Remaining uncertainty is limited to original header/source factoring. It does not alter
  file owner, emitter route, or body behavior.
- Cross-agent source placement is page-exclusive: B002 owns UID0000E4 and its outer exact
  children; B005 owns UID0000E5 and UID00011U nested children. Shared declaration text is
  synchronized in this artifact and exact B005 SHA `321CD451...`; those exact revisions
  were frozen for B002's callback. B005's nested subblock is authoritative and B002's
  outer fields/virtual ABI are authoritative. B005's report explicitly treats UID0000E4
  as verify-only, eliminating overlapping edit ownership.

## Range / Split / Padding / Reclassification Analysis

- UID00011V is now a non-emitting split index because exact target source, target ABI,
  FontStyle support, Popup support, sibling-control ABI/source, and padding coexist in the
  historical interval.
- Twelve exact target method/compiler children and two exact vtable support pages listed
  in the Function / Child Inventory were registered low-to-high, preserving stable source
  order.
- The three stale ends were corrected during child creation. Current half-open ranges use
  `a8b0-a949`, `a950-aa71`, and `ab80-ac59`.
- Exact target/local and historical-interval padding, all live-read as `0xcc`, is:

| Span | Bytes |
| --- | --- |
| `0x0049a403-0x0049a410` | 13 |
| `0x0049a8ac-0x0049a8b0` | 4 |
| `0x0049a949-0x0049a950` | 7 |
| `0x0049aa71-0x0049aa80` | 15 |
| `0x0049aaba-0x0049aac0` | 6 |
| `0x0049aada-0x0049aae0` | 6 |
| `0x0049aaf8-0x0049ab00` | 8 |
| `0x0049ab18-0x0049ab20` | 8 |
| `0x0049ab79-0x0049ab80` | 7 |
| `0x0049ac59-0x0049ac60` | 7 |
| `0x0049ad74-0x0049ad80` | 12 |
| `0x0049ad96-0x0049ada0` | 10 |
| `0x0049aefe-0x0049af00` | 2 |
| `0x0049b087-0x0049b090` | 9 |
| `0x0049b0ce-0x0049b0d0` | 2 |
| `0x0049b10b-0x0049b110` | 5 |
| `0x0049b165-0x0049b170` | 11 |
| `0x0049b1ab-0x0049b1b0` | 5 |
| `0x0049b24f-0x0049b250` | 1 |
| `0x0049b28e-0x0049b290` | 2 |
| `0x0049b2e5-0x0049b2f0` | 11 |
| `0x0049b3af-0x0049b3b0` | 1 |
| `0x0049b417-0x0049b420` | 9 |
| `0x0049b487-0x0049b490` | 9 |
| `0x0049b4e5-0x0049b4f0` | 11 |
| `0x0049b557-0x0049b560` | 9 |
| `0x0049b5a8-0x0049b5b0` | 8 |
| `0x0049b5eb-0x0049b5f0` | 5 |
| `0x0049b6bc-0x0049b6c0` | 4 |
| `0x0049b731-0x0049b740` | 15 |
| `0x0049b795-0x0049b7a0` | 11 |
| `0x0049b854-0x0049b860` | 12 |
| `0x0049b8c7-0x0049b8d0` | 9 |
| `0x0049b8d5-0x0049b8e0` | 11 |
| `0x0049b8e5-0x0049b8f0` | 11 |
| `0x0049b8f5-0x0049b900` | 11 |
| `0x0049b905-0x0049b910` | 11 |
| `0x0049b915-0x0049b920` | 11 |

- `0x0049a403-0x0049a410` belongs to the predecessor UID00011U boundary but is included
  in support synchronization so the target constructor start remains exact.
- Parent impact: UID00011V loses source emission but retains semantic ownership and rises
  because every byte is classified. UID00011Y/UID000252 remain aggregates. No adjacent
  control page is merged or reparented.

## Negative Evidence Summary

- No external direct, indirect-pointer, vtable, or caller route enters the raw ordinary
  destructor start; only internal control-flow xrefs enter its interior. This rejects an
  independently callable cleanup helper but supports compiler-lowered ordinary destructor
  source.
- No external route enters the raw style start. Its valid standalone code and exact
  constructor duplication reject padding, EH-only, and unrelated-helper classifications.
- No target or exact caller access, lifecycle action, or address-taking route establishes
  a separate field boundary at `+0x148`. That negative result rejects RectBounds,
  FontStyleRule, anonymous integer-record, and opaque-reserve interpretations; it does not
  justify emitting a generic reserve. The contiguous `wchar_t[40]` interpretation is the
  highest-probability source shape because the next proven member begins at `+0x158`.
- No caller passes a rectangle to the bounds helper; generic `SetBounds` is rejected.
  No caller passes map-space coordinates at that point; map-specific naming is rejected.
- No target method calls the nested raw layout/opacity helper starts. Direct field writes
  plus friend access preserve behavior without inventing callable routes and without
  duplicating B005 source.
- No evidence makes FontStyle vector growth, copy assignment, shared EH cleanup, Popup
  callback, or any sibling destructor/thunk/type row a StaticTextControlPane2 source method.
- No evidence supports handwritten scalar-delete flags, vptr writes, RTTI objects, vtable
  arrays, or adjustor arithmetic in developer source.
- The existing `GetControlTypeId` name has no stronger support than the accepted sibling
  source convention; it is rejected as the source-facing accepted name but may be retained
  as historical documentation wording.
- Existing sibling formal bodies that claim no stack arguments are contradicted by live
  `retn 8` disassembly. They remain useful only for the `GetControlType` family name and
  fixed-id role, not for signature or return-width inheritance.

## IDA Rename / Type / Comment Recommendations

- Source-facing accepted names:
  `StaticTextControlPane2::SetCenterPosition`,
  `StaticTextControlPane2::ApplyStyleState`,
  `StaticTextControlPane2::OnPaint`, and
  `StaticTextControlPane2::GetControlType`.
- Accepted types: unsigned-byte control type with two unnamed signed-integer virtual
  arguments; signed integer coordinates, padding,
  spacing, dimensions, and raw alignment values; `const FontStyle *` constructor input;
  borrowed mutable FontStyle pointer in the embedded child; unsigned integer draw-color
  indexes; 40-wide-character owned buffer with an explicit checked-copy limit of 32.
- Recommended field names are descriptive and behavior-backed:
  `m_textBuffer`, `m_fillColor`, `m_frameColor`, `m_fontStyle`,
  `m_horizontalPadding`, `m_verticalPadding`, `m_lineSpacing`, `m_textWidth`,
  `m_textHeight`, `m_horizontalAlignment`, `m_verticalAlignment`, and `m_textPart`.
- Rejected field spellings include `m_reservedTextState`, `m_reserved[16]`,
  `m_textBounds`, and `m_textRule`: none has a distinct access/lifecycle boundary.
- Preserve rejected aliases in prose: raw bounds/update helper, raw style-state applier,
  non-deleting destructor helper, `GetControlTypeId`, generic `SetPosition`, and
  map-position helper. Label them historical/descriptive, never current accepted names.
- IDA database edits are not requested or authorized. These recommendations are for
  source-facing by-* documentation and formal reconstruction only.

## First-Draft C++ Recommendation

There are exactly eighteen destination-specific formal managed blocks. No proposed C++
declaration, body, marker, or no-code block exists outside them.

### Destination 1 - UID00011V parent split index

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact no-code proof: every handwritten target body is emitted by Destinations 3-11 and
14; compiler declarations/data are covered by Destinations 12-13 and 15-16; all remaining
bytes are support, siblings, or padding. Aggregate source would duplicate children and mix
incompatible owners/dispositions.

### Destination 2 - `by-class/StaticTextControlPane2.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Layer;
struct RectBounds;

class StaticTextControlPane2 : public ControlPane
{
public:
    class SimpleHelpTextPartPane : public Pane
    {
    public:
        SimpleHelpTextPartPane();
        virtual ~SimpleHelpTextPartPane() {}
        virtual void OnPaint();

    private:
        friend class StaticTextControlPane2;

        void DrawTextLine(const FontStyleRule& style,
                          int x,
                          int y,
                          const wchar_t *text,
                          short charCount);

        SimpleUString m_text;
        int m_horizontalPadding;
        int m_verticalPadding;
        int m_lineSpacing;
        FontStyle *m_fontStyle;
    };

    StaticTextControlPane2(const wchar_t *text,
                           int x,
                           int y,
                           int horizontalAlignment,
                           int verticalAlignment,
                           const FontStyle *fontStyle,
                           int horizontalPadding,
                           int verticalPadding,
                           int lineSpacing);
    virtual ~StaticTextControlPane2();

    void SetCenterPosition(int centerX, int centerY);

    virtual void AddToLayer(const RectBounds *bounds,
                            int order,
                            Pane *previousPane,
                            Layer *layer);
    virtual void RemoveFromLayer();
    virtual void Show();
    virtual void Hide();
    virtual void OnPaint();
    virtual unsigned char GetControlType(int, int);

private:
    void ApplyStyleState();

    wchar_t m_textBuffer[40];
    unsigned int m_fillColor;
    unsigned int m_frameColor;
    FontStyle m_fontStyle;
    int m_horizontalPadding;
    int m_verticalPadding;
    int m_lineSpacing;
    int m_textWidth;
    int m_textHeight;
    int m_horizontalAlignment;
    int m_verticalAlignment;
    SimpleHelpTextPartPane m_textPart;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

The outer class closes before `[[CHILDREN]]`. The generator must therefore expand exact
outer method definitions at namespace scope; placing the marker inside `private:` or
before `};` is explicitly rejected as ill-formed C++.

This managed body is byte-for-byte identical to Destination 2 in completed B005 report
SHA `321CD4518BDB36ACF55A6B9AAF3DE2E434E56AF7462FC6F1C242B318CB7D1811`. The
case-sensitive normalized-body comparison covers `2026` characters and has SHA256
`19219d0ab438a9aab2a9bc2fd4b53f436bd250d266ca5f9ab4f5151448a2a114` on both sides.
B005 carries that block only for collision detection and explicitly does not edit
UID0000E4.

### Destination 3 - new constructor child

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
StaticTextControlPane2::StaticTextControlPane2(
    const wchar_t *text,
    int x,
    int y,
    int horizontalAlignment,
    int verticalAlignment,
    const FontStyle *fontStyle,
    int horizontalPadding,
    int verticalPadding,
    int lineSpacing)
    : ControlPane(8, NULL),
      m_fillColor(0),
      m_frameColor(0),
      m_fontStyle(),
      m_horizontalPadding(horizontalPadding),
      m_verticalPadding(verticalPadding),
      m_lineSpacing(lineSpacing),
      m_textWidth(0),
      m_textHeight(0),
      m_horizontalAlignment(horizontalAlignment),
      m_verticalAlignment(verticalAlignment),
      m_textPart()
{
    m_fontStyle.SetEnabled(false);
    if (fontStyle != NULL)
        m_fontStyle = *fontStyle;

    const int textLength = static_cast<int>(wcslen(text));
    int lineCount = 1;
    int maxLineWidth = -1;
    int lineStart = 0;

    for (int index = 0; index < textLength; ++index) {
        const wchar_t ch = text[index];
        if (ch != L'\r' && ch != L'\n' && ch != L'\t')
            continue;

        ++lineCount;
        const int lineWidth = GetTextWidth(
            text + lineStart,
            static_cast<short>(index - lineStart));
        if (lineWidth > maxLineWidth)
            maxLineWidth = lineWidth;
        lineStart = index + 1;
    }

    const int tailWidth = GetTextWidth(
        text + lineStart,
        static_cast<short>(textLength - lineStart));
    if (tailWidth > maxLineWidth)
        maxLineWidth = tailWidth;

    m_textWidth = maxLineWidth + (2 * m_horizontalPadding);
    m_textHeight = (lineCount * GetLineHeight())
                 + ((lineCount - 1) * m_lineSpacing)
                 + (2 * m_verticalPadding);

    RectBounds bounds;
    if (m_horizontalAlignment == 0)
        bounds.left = x;
    else if (m_horizontalAlignment == 1)
        bounds.left = x - m_textWidth;
    else
        bounds.left = x - (m_textWidth / 2);
    bounds.right = bounds.left + m_textWidth;

    if (m_verticalAlignment == 3)
        bounds.top = y;
    else if (m_verticalAlignment == 4)
        bounds.top = y - m_textHeight;
    else
        bounds.top = y - (m_textHeight / 2);
    bounds.bottom = bounds.top + m_textHeight;

    const int screenWidth = g_pScreenPane->GetScreenWidth();
    const int screenHeight = g_pScreenPane->GetScreenHeight();
    if (bounds.left < 0)
        OffsetRect(&bounds, -bounds.left, 0);
    else if (bounds.right >= screenWidth)
        OffsetRect(&bounds, screenWidth - bounds.right, 0);
    if (bounds.top < 0)
        OffsetRect(&bounds, 0, -bounds.top);
    else if (bounds.bottom >= screenHeight)
        OffsetRect(&bounds, 0, screenHeight - bounds.bottom);

    wcscpy_s(m_textBuffer, 32, text);
    SetBounds(&bounds, false);

    m_textPart.m_text = m_textBuffer;
    m_textPart.m_horizontalPadding = m_horizontalPadding;
    m_textPart.m_verticalPadding = m_verticalPadding;
    m_textPart.m_lineSpacing = m_lineSpacing;
    m_textPart.m_fontStyle = &m_fontStyle;
    m_alpha = 0.2f;

    ApplyStyleState();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4 - new ordinary destructor child

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
StaticTextControlPane2::~StaticTextControlPane2()
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 5 - new `SetCenterPosition` child

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void StaticTextControlPane2::SetCenterPosition(int centerX, int centerY)
{
    RectBounds bounds;
    if (m_horizontalAlignment == 0)
        bounds.left = centerX;
    else if (m_horizontalAlignment == 1)
        bounds.left = centerX - m_textWidth;
    else
        bounds.left = centerX - (m_textWidth / 2);
    bounds.right = bounds.left + m_textWidth;

    if (m_verticalAlignment == 3)
        bounds.top = centerY;
    else if (m_verticalAlignment == 4)
        bounds.top = centerY - m_textHeight;
    else
        bounds.top = centerY - (m_textHeight / 2);
    bounds.bottom = bounds.top + m_textHeight;

    const int screenWidth = g_pScreenPane->GetScreenWidth();
    const int screenHeight = g_pScreenPane->GetScreenHeight();
    if (bounds.left < 0)
        OffsetRect(&bounds, -bounds.left, 0);
    else if (bounds.right >= screenWidth)
        OffsetRect(&bounds, screenWidth - bounds.right, 0);
    if (bounds.top < 0)
        OffsetRect(&bounds, 0, -bounds.top);
    else if (bounds.bottom >= screenHeight)
        OffsetRect(&bounds, 0, screenHeight - bounds.bottom);

    SetBounds(&bounds, false);
    m_textPart.SetBounds(&bounds, false);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 6 - new `AddToLayer` child

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void StaticTextControlPane2::AddToLayer(const RectBounds *bounds,
                                        int order,
                                        Pane *previousPane,
                                        Layer *layer)
{
    Pane::AddToLayer(bounds, order, previousPane, layer);
    m_textPart.AddToLayer(bounds,
                          order,
                          previousPane,
                          g_mainUiLayerSlots.overlayPaneLayerContext);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 7 - new `RemoveFromLayer` child

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void StaticTextControlPane2::RemoveFromLayer()
{
    m_textPart.RemoveFromLayer();
    Pane::RemoveFromLayer();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 8 - new `Show` child

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void StaticTextControlPane2::Show()
{
    Pane::Show();
    m_textPart.Show();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 9 - new `Hide` child

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void StaticTextControlPane2::Hide()
{
    Pane::Hide();
    m_textPart.Hide();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 10 - new `OnPaint` child

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void StaticTextControlPane2::OnPaint()
{
    RectBounds bounds = m_bounds;
    SetDrawColor(m_fillColor);
    FillRect(&bounds);
    SetDrawColor(m_frameColor);
    DrawRectFrame(&bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 11 - new `ApplyStyleState` child

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void StaticTextControlPane2::ApplyStyleState()
{
    if (!m_fontStyle.IsEnabled())
        return;

    const float parentOpacity = m_fontStyle.GetParentOpacity();
    if (parentOpacity >= 1.0f) {
        SetMode(1);
    } else if (parentOpacity >= 0.0f) {
        SetMode(3);
        m_alpha = parentOpacity;
    }

    m_fillColor = m_fontStyle.GetForegroundColor();
    m_frameColor = m_fontStyle.GetBackgroundColor();

    FontStyle *textStyle = m_textPart.m_fontStyle;
    if (textStyle == NULL || !textStyle->IsEnabled())
        return;

    const float textOpacity = textStyle->GetTextOpacity();
    if (textOpacity <= 0.0f) {
        m_textPart.SetMode(1);
    } else if (textOpacity <= 1.0f) {
        m_textPart.SetMode(3);
        m_textPart.m_alpha = textOpacity;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 12 - new adjustor-thunk child

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact no-code proof: both bodies subtract a fixed secondary-view offset (`0xa0` or `0xa4`)
from `this` and tail-jump to the scalar deleting destructor. Multiple inheritance/vtable
lowering regenerates them; no developer-authored callable method exists.

### Destination 13 - new scalar-deleting-destructor child

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Source-declared/generated-binary only. StaticTextControlPane2's ordinary virtual
// destructor regenerates this scalar deleting destructor, its flags-controlled optional
// operator-delete path, and both secondary-view adjustors. Do not hand-emit MSVC ABI.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 14 - new `GetControlType` child

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
unsigned char StaticTextControlPane2::GetControlType(int, int)
{
    return 24;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 15 - new `by-type/by-vtable/StaticTextControlPane2Vtables.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Covered by the StaticTextControlPane2 declaration and virtual methods. The compiler
// regenerates the primary, secondary, and tertiary vtable views and RTTI locators.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 16 - new exact vtable-data child

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Covered by StaticTextControlPane2Vtables and the class declaration. Do not hand-emit
// raw vtable arrays, RTTI locators, inherited slot pointers, or adjustor addresses.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 17 - coordinated `by-class/StaticTextControlPane2__SimpleHelpTextPartPane.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// The complete nested declaration is emitted once by StaticTextControlPane2. Preserve all
// accepted UID00011U exact method children here without duplicating the class definition.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 17 is a B005-owned destination, not a B002 callback edit. Its managed body is
byte-for-byte identical to B005 Destination 3 in completed report SHA `321CD451...`
(`196` characters; normalized-body SHA256
`40d419cc74fec2979c4eac43f69d9abe0c7270fe54eded27685c8d4502fb5ec2`). The synchronized
artifacts were frozen before B002 applied UID0000E4/outer work. B002 did not lease or edit
UID0000E5. B005 exclusively owns its accepted parent-end correction to `0x0049a403`,
Destination 17 application, and every UID00011U nested child; none of that external scope
was silently adapted or claimed by B002.

### Destination 18 - `by-class/FontStyle.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include <vector>

struct FontStyleRule {
    unsigned int m_textColor;
    unsigned int m_secondaryColor;
    unsigned char m_effect;
    unsigned char m_reserved[3];
    unsigned int m_alignment;
};

class FontStyle {
public:
    FontStyle();
    ~FontStyle();

    bool IsEnabled() const { return m_enabled != 0; }
    void SetEnabled(bool enabled) { m_enabled = enabled ? 1 : 0; }
    float GetParentOpacity() const { return m_parentOpacity; }
    float GetTextOpacity() const { return m_textOpacity; }
    unsigned int GetForegroundColor() const { return m_foregroundColor; }
    unsigned int GetBackgroundColor() const { return m_backgroundColor; }

    void GetRule(unsigned int index, FontStyleRule *outRule) const;
    void Configure(unsigned int textColor,
                   unsigned int secondaryColor,
                   unsigned char effect,
                   unsigned int alignment);

private:
    unsigned char m_enabled;
    unsigned char m_padding0[3];
    float m_parentOpacity;
    float m_textOpacity;
    unsigned int m_foregroundColor;
    unsigned int m_backgroundColor;
    std::vector<FontStyleRule> m_rules;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 18 preserves the complete accepted declaration and adds only six direct,
consumer-proven inline accessors. It does not move FontStyle to UID0000O8 or change rule
vector ownership.

## Final Recommendation

- C01-C35 and the B002-owned portions of Destinations 1-18 are applied and verified as
  the completed B002 implementation specification. Destination 17 remains frozen
  comparison/coordination text and was not applied by B002.
- UID00011V retains semantic owner UID0000E4 while aggregate
  reconstructability/emission/position are cleared and source resides in exact children.
- Exact children were created and registered low-to-high as UID0004KS, UID0004KT,
  UID0004KV-UID0004KZ, and UID0004L0-UID0004L6; ordinary source methods and covered
  compiler artifacts are assigned as listed, while adjustors and padding remain false/blank.
- UID0000E4 is `92/93`, UID0000O8 is `92/92`, and FontStyle is `89/91`; the callback preserved
  every same-or-greater dependency and B005 nested-method detail.
- The declaration emits `wchar_t m_textBuffer[40]` with the body-retained 32-character
  checked-copy limit and no superseded generic 16-byte reserve. The type override has two
  explicit `int` arguments so source lowering preserves `AL` plus `ret 8`.
- B002 owns UID0000E4 and outer children only. B005 owns UID0000E5 and UID00011U only;
  their exact completed report SHA is `321CD451...`, and both shared managed bodies are
  byte-identical. B002's callback was completed first without leasing or editing any
  B005-owned page; B005's separate scope and state are external to this callback artifact.
- Keep all adjacent controls, FontStyle compiler support, Popup callback, shared EH
  cleanup, RTTI/vtable arrays, and alignment outside handwritten target source.
- No separate UID00011U report or replacement nested-method research is recommended.

## Recommended Target Doc Changes

- Target path:
  `by-memory/0x0049a410-0x0049b915.StaticTextControlPane2.md`.
- Callback state is score `92/94`, retained `CANONICAL_OWNER:0000E4`, reconstructable
  false, blank emitter and position, with exact blank Destination 1.
- Broad source-emitter wording was replaced by exact semantic split-index wording. The
  page preserves the historical broad filename and all useful prior evidence while
  labeling old endpoints, base-type statement, generic helper names, and aggregate
  emission as superseded.
- The page contains exact child links, corrected ends, complete padding/support/sibling inventory,
  source/compiler dispositions, direct callers/resources/globals, object layout, vtables,
  negative evidence, and source placement at report-level detail.
- `Nested:0` is preserved; exact child registration, not parent nesting metadata, carries
  the source inventory.

## Recommended Support Doc Changes

- `by-class/StaticTextControlPane2.md`: applied at `92/93`, file owner/emitter UID0000O8, emitter
  position `20`, Destination 2, exact `0x2a8` layout with one `wchar_t[40]` field, method/
  compiler inventory, two-argument type virtual ABI, callers, vtables, source placement,
  and superseded aliases. Its `[[CHILDREN]]` marker is after the complete outer class.
- `by-file/StaticTextControlPane.md`: applied at `92/92`; preserved UID0000E3/older StaticText details,
  added the complete UID0000E4 family, deterministic class order, compiler dispositions,
  nested coordination, callers/resources, and rejected alternate owners. UID0000E3 is
  directly at position `10`; UID0000E4 is position `20`, and B005-owned UID0000E5 is
  position `30`. These positions are required, not conditional.
- Exact source children UID0004KS, UID0004KT, UID0004KV-UID0004KZ, UID0004L0,
  UID0004L1, and UID0004L4 were created with exact ranges, scores, UID0000E4
  owner/emitter, positions, complete report evidence, and Destinations 3-11/14.
- Exact compiler children UID0004L2, UID0004L3, UID0004L5, and UID0004L6 were created:
  adjustors remain false/NONE/blank; scalar, vtable type, and exact vtable-data pages carry
  Destinations 12-13/15-16 and positions only for source-covered items.
- `by-class/StaticTextControlPane2__SimpleHelpTextPartPane.md`: B005 alone owns this edit.
  Exact B005 report SHA `321CD451...` contains the byte-identical route marker. B002
  applied the frozen UID0000E4 declaration but did not lease or edit this page; its
  `91/93` recommendation, children, Destination 17 application, and position `30` remain
  exclusively B005-owned.
- `by-class/FontStyle.md`: applied at `89/91`; preserved UID0000JI owner/emitter and all
  existing declaration/body/history, applied Destination 18, and documented direct StaticText2 use.
- `by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md`: retained false/NONE/
  blank aggregate status, replaced target generic rows with exact adjustor/scalar links,
  and preserved all other owners.
- `by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md` [UID:000252]: retained
  false/NONE/blank aggregate status and linked exact UID0004L6 at
  `0x00618600-0x006186a4`. The earlier broad `ReadOnlyDataSection` path was a stale path
  description for UID000252 and is superseded by this validator-resolved current page.
- `by-memory/-ignored.md`: contains the exact grouped `0xcc` padding row listed above
  without turning source methods or support bodies into ignored bytes.
- UID00011U itself: no duplicate report and no B002 rewrite occurred. B005 owns every nested child
  and any cross-link, including its accepted UID-preserving parent correction from stale
  `0x00499fe0-0x0049a402` to exact `0x00499fe0-0x0049a403`. The B005 artifact hash and
  shared blocks remained exact during B002 callback verification.
- Pane, ControlPane, PaneSetMode, GrafPort, Surface, RectBounds, screen globals/helpers,
  FontStyle layout/core/vector, and successor UID000222 were verified as same-or-greater
  read-only dependencies; no concrete callback drift required edits.

## Score And Metadata Recommendation

| Item | Historical pre-callback | Applied callback state | Owner / emitter / position | Rationale |
| --- | --- | --- | --- | --- |
| UID00011V | `86/90`, true, UID0000E4 emitter | `92/94`, false, blank emitter/position | semantic owner UID0000E4 retained | all bytes classified; exact children prevent duplicate source |
| UID0000E4 | `88/90`, blank C++ | `92/93` | UID0000O8 / UID0000O8 / 20 | complete class/method/vtable model; `wchar_t[40]` is highest-probability inferred declaration |
| UID0000O8 | `88/86` | `92/92` | FILE | complete family and deterministic routing |
| constructor | absent | UID0004KS `92/94` | UID0000E4 / UID0000E4 / 10 | exact body/signature/callers/layout |
| ordinary destructor | absent/raw | UID0004KT `91/93` | UID0000E4 / UID0000E4 / 20 | exact source/implicit cleanup disposition |
| center helper | generic raw | UID0004KV `92/94` | UID0000E4 / UID0000E4 / 30 | sole caller and complete center/clamp behavior |
| Add/Remove/Show/Hide | aggregate rows | UID0004KW/0004KX/0004KY/0004KZ, each `91/93` | UID0000E4 / UID0000E4 / 40-70 | exact virtual bodies and order |
| OnPaint | aggregate row | UID0004L0 `92/94` | UID0000E4 / UID0000E4 / 80 | exact callbacks/colors/body |
| style helper | generic raw | UID0004L1 `92/93` | UID0000E4 / UID0000E4 / 90 | complete body and ctor-inlining liveness proof |
| adjustors | aggregate rows | UID0004L2 `90/94` | NONE / blank / blank | exact compiler thunks, no source |
| scalar wrapper | aggregate row | UID0004L3 `91/94` | UID0000E4 / UID0000E4 / 100 | marker-covered compiler ABI |
| type virtual | aggregate row | UID0004L4 `92/94` | UID0000E4 / UID0000E4 / 110 | exact AL/`ret 8` ABI and terminal slot; source cv/spelling inferred |
| vtable type | absent | UID0004L5 `90/94` | UID0000E4 / UID0000E4 / 120 | exact three-view declaration coverage |
| vtable data | broad aggregate only | UID0004L6 `91/94` | UID0000E4 / UID0000E4 / 130 | exact table/locator/boundary proof |
| UID00005C | `87/89` | `89/91` | UID0000JI unchanged | six exact accessors close legal consumer source |
| UID0000E5 | B005 recommends `91/93` | preserve `91/93` | UID0000O8 / UID0000O8 / 30 | declaration covered once; child methods preserved |

- Score-improvement attempts resolved every identified behavior, helper-name, source-route,
  range, layout, liveness, ownership, compiler-disposition, and C++ blocker through live
  code/caller/vtable/support checks, and the accepted scores were applied without change.
- UID0000E4 confidence is `93`, not `94`: the live layout and no-route audit make
  `wchar_t[40]` decisively stronger than an unsupported reserve/record, but the literal
  32-character copy limit means the original declared array count is inferred rather than
  symbol-proven. The type virtual is capped at `94` because AL return, two arguments,
  terminal slot, and `ret 8` are exact while member cv and original spelling are stripped.
- UID00011V retains semantic owner despite false reconstruction. Clearing the owner would
  incorrectly discard the fact that all target exact methods are UID0000E4 class members.

## Open Questions With Attempted Resolution

- **Are the three old raw ends correct?** No. Live terminators and bytes resolve exact ends
  to `a949`, `aa71`, and `ac59`; no uncertainty remains.
- **Is base construction direct Pane type 1?** No. Live call routing resolves
  ControlPane type 8/null bounds. Historical wording must be preserved only as rejected.
- **Is the bounds helper a generic setter?** No. Sole caller/body parity resolve
  `SetCenterPosition`; exact original capitalization is conventional only.
- **Is the style body dead/no-code?** No. Complete valid standalone code plus exact
  constructor inlining supports a retained private method. No external xref limits name
  confidence but not source liveness.
- **Should destructor cleanup be transcribed?** No. Empty ordinary destructor source plus
  members/bases regenerates all observed cleanup. Scalar/thunks remain compiler ABI.
- **Should nested raw setters be called?** No. B005 exhausts their no-route evidence;
  direct outer friend access matches actual constructor stores and creates no unsupported
  binary entries.
- **Where does the nested class declaration emit?** Inside UID0000E4, once, with the
  outer `[[CHILDREN]]` marker after the complete outer `};`. A by-value nested member
  requires a complete type. B002 owns UID0000E4; B005 alone owns UID0000E5's covered
  marker and nested child route. B002's outer callback is complete without editing that
  B005-owned route.
- **Is control type method named `GetControlTypeId`?** Accepted sibling virtual convention
  resolves `GetControlType`; live target/base/sibling disassembly corrects the source ABI
  to non-const `unsigned char GetControlType(int, int)`. `GetControlTypeId` and every
  no-argument sibling declaration are superseded for current source-facing use.
- **What is the 16-byte region at `+0x148`?** It is not retained as a separate region.
  The accepted declaration is one `wchar_t m_textBuffer[40]` spanning `+0x108..+0x157`.
  Target methods, all exact constructor callers, pointer-taking scans, analogous layouts,
  RectBounds/FontStyleRule candidates, and compiler-alignment rules provide no independent
  boundary at `+0x148`. The body still uses the exact logical checked-copy limit `32`.
- **How is B005 collision avoided?** The synchronized Gate-1 artifacts were frozen before
  callback. The completed dependency is exact B005 SHA `321CD451...`; its Destination 2 and
  Destination 3 are byte-identical to B002 Destinations 2 and 17, and its ledger marks
  UID0000E4 B002-owned/B005-verify-only. B002 applied UID0000E4/outer children first and
  never leased or edited UID0000E5, UID00011U, or B005-owned children. Destination 17
  remains comparison-only here; B005's separate `a403`/UID0000E5/UID00011U state is
  external to this callback artifact.
- **Do adjacent controls belong?** No. Exact vtables, adjustors, scalar wrappers, type
  methods, and class docs assign them separately.
- Remaining unresolved issues: exact original array-count intent behind the explicit
  32-character copy limit, member cv/spelling for the type virtual, private spellings,
  and header factoring. They are reflected in `92/93` and `92/94` caps and do not leave a
  generic reserve, incorrect stack ABI, ownership collision, or managed-source blocker.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. The research tracker, generated source, generated coverage, projected
  stats, and validator state are validator-owned.
- No manual `-coverage-report.md` or supervisor-owned tracker row was required. Exact
  by-memory metadata, child registration, and scoped validators drove validator-owned
  generated reclassification during the accepted callback.
- B002 must not edit generated/coverage/tracker files directly.

## Follow-Up Actions

- B002's C01-C35 implementation scope is complete. Destinations 1-16 and 18 are exact in
  their B002-owned destination pages; Destination 17 remains frozen comparison text for
  B005 and was not applied or edited by B002.
- Each changed ordinary by-* page received its own scoped validator while its immediate
  lease was active, every lease was released, and final command `000000009385` completed
  the authorized waited generated refresh.
- B002-stage generated verification proved one complete outer/nested class block,
  namespace-scope outer child definitions, one each constructor/ordinary destructor/
  center helper/lifecycle/paint/style/two-argument type body, no UID00011V Empty Emitter
  Marker, no duplicate ordinary outer definition, and no handwritten scalar/thunk/vtable
  ABI. Nested child-method counts and UID0000E5/UID00011U marker state remain exclusively
  B005-owned and are not asserted as completed here. A later validator-owned refresh
  `000000009396` preserved every B002-stage count; it was observed read-only and was not a
  B002 command.
- No A-agent or duplicate B005/UID00011U report is required by this recommendation.
- B002 research, implementation, validator, and lease work is complete. Current/future report path, count, validation,
  execution, move, archive, and lifecycle state remain external and are not asserted or
  directed here.

## Confidence

- Recommendation confidence: high (`0.93`) for split, semantic owner, exact source/ABI
  inventory, class/file route, and managed-block disposition. The reduction records the
  inferred 40-element declaration and selected non-const member convention.
- Score confidence: high (`0.92`) because all gate blockers have direct resolutions and
  applied scores remain bounded below perfect where names/layout intent are stripped.
- Remaining uncertainty: exact original physical array-count intent versus its observed
  logical copy limit, member cv/spelling for `GetControlType`, private color/layout field
  spellings, and original header factoring. No generic reserve, stack-ABI, behavior,
  range, liveness, owner, collision, or C++ blocker remains.

## Validator Results

- The historical report-only pass ran no validator. During the accepted callback, every
  changed ordinary by-* page was validated with
  `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240`.
  The final source-file verification added `--wait-generated`. All timestamps below are
  validator-reported and all commands exited `0` with `ok: 1`.

| Page | Command ID | Command timestamp | Result / side effects |
| --- | --- | --- | --- |
| UID0004KS constructor | `000000009327` | `2026-07-13T06:29:44-04:00` | registered UID0004KS; generated refresh deferred |
| UID0004KT destructor | `000000009329` | `2026-07-13T06:30:21-04:00` | registered UID0004KT; generated refresh deferred |
| UID0004KV center helper | `000000009332` | `2026-07-13T06:31:01-04:00` | registered UID0004KV; generated refresh deferred |
| UID0004KW AddToLayer | `000000009334` | `2026-07-13T06:31:37-04:00` | registered UID0004KW; generated refresh deferred |
| UID0004KX RemoveFromLayer | `000000009336` | `2026-07-13T06:32:10-04:00` | registered UID0004KX; generated refresh deferred |
| UID0004KY Show | `000000009338` | `2026-07-13T06:32:43-04:00` | registered UID0004KY; generated refresh deferred |
| UID0004KZ Hide | `000000009340` | `2026-07-13T06:33:17-04:00` | registered UID0004KZ; generated refresh deferred |
| UID0004L0 OnPaint | `000000009342` | `2026-07-13T06:33:54-04:00` | registered UID0004L0; generated refresh deferred |
| UID0004L1 ApplyStyleState | `000000009344` | `2026-07-13T06:34:45-04:00` | registered UID0004L1; generated refresh deferred |
| UID0004L2 adjustors | `000000009347` | `2026-07-13T06:35:19-04:00` | registered UID0004L2; generated refresh deferred |
| UID0004L3 scalar wrapper | `000000009348` | `2026-07-13T06:36:12-04:00` | registered UID0004L3; generated refresh deferred |
| UID0004L4 type virtual | `000000009350` | `2026-07-13T06:36:47-04:00` | registered UID0004L4; generated refresh deferred |
| UID0004L5 vtable type | `000000009352` | `2026-07-13T06:37:26-04:00` | registered UID0004L5; generated refresh deferred |
| UID0004L6 vtable data | `000000009354` | `2026-07-13T06:38:22-04:00` | registered UID0004L6; generated refresh deferred |
| UID00011V target | `000000009358` | `2026-07-13T06:40:39-04:00` | metadata/index accepted; generated refresh deferred |
| UID0000E4 class | `000000009363` | `2026-07-13T06:42:13-04:00` | complete declaration accepted; generated refresh deferred |
| UID0000E3 class | `000000009365` | `2026-07-13T06:42:45-04:00` | position 10 accepted; generated refresh deferred |
| UID0000O8 source file | `000000009369` | `2026-07-13T06:43:58-04:00` | source inventory accepted; generated refresh deferred |
| UID00005C FontStyle | `000000009371` | `2026-07-13T06:44:48-04:00` | six accessors accepted; generated refresh deferred |
| UID00011Y compiler aggregate | `000000009372` | `2026-07-13T06:45:43-04:00` | exact child links accepted; generated refresh deferred |
| UID000252 read-only aggregate | `000000009374` | `2026-07-13T06:47:18-04:00` | exact UID0004L6 island accepted; four pre-existing `missing_ref_uid 0003J8` warnings remained |
| `by-memory/-ignored.md` | `000000009377` | `2026-07-13T06:48:25-04:00` | exact grouped padding row accepted; 328 pre-existing broad-page `missing_ref_uid` warnings remained |
| UID0000O8 final waited verification | `000000009385` | `2026-07-13T06:52:36-04:00` | `generated_refresh: completed`; generated command/timestamp match |

- Final command `000000009385` reported validator-owned side effects only:
  `autogen_registry_rebuild:1`, `generated_metadata_refresh:279`,
  `memory_auto_coverage_update:1`, `projected_stats_update:1`,
  `research_tracker_update:1`, `stats_incremental_noop:1`, plus broad existing
  `autogen_children_fallback_insert:14`, `autogen_children_marker_missing:83`, and
  `autogen_emitter_has_no_code:208` diagnostics. B002 did not manually edit any resulting
  generated, tracker, coverage, stats, registry, or validator-owned file.
- Read-only generated verification of
  `auto-generated/NexusTK/ui/controls/StaticTextControlPane.cpp` found validator header
  command `000000009385` immediately after B002's waited run. A later final read-only
  audit found validator-owned header `000000009396` at
  `2026-07-13T07:02:42-04:00` and preserved the same one UID0000E4 outer declaration
  block and exactly one definition each for constructor, ordinary destructor,
  `SetCenterPosition`, `AddToLayer`,
  `RemoveFromLayer`, `Show`, `Hide`, `OnPaint`, `ApplyStyleState`, and two-argument
  `GetControlType`; no UID00011V Empty Emitter Marker; and marker-only, not handwritten,
  scalar/vtable ABI. UID0000E5/UID00011U empty markers are the excluded B005 stage.

## Changed Files

- Created and registered ordinary by-* pages:
  `by-memory/0x0049a410-0x0049a8ac.StaticTextControlPane2Constructor.md` (UID0004KS),
  `by-memory/0x0049a8b0-0x0049a949.StaticTextControlPane2Destructor.md` (UID0004KT),
  `by-memory/0x0049a950-0x0049aa71.StaticTextControlPane2SetCenterPosition.md` (UID0004KV),
  `by-memory/0x0049aa80-0x0049aaba.StaticTextControlPane2AddToLayer.md` (UID0004KW),
  `by-memory/0x0049aac0-0x0049aada.StaticTextControlPane2RemoveFromLayer.md` (UID0004KX),
  `by-memory/0x0049aae0-0x0049aaf8.StaticTextControlPane2Show.md` (UID0004KY), and
  `by-memory/0x0049ab00-0x0049ab18.StaticTextControlPane2Hide.md` (UID0004KZ).
- Created and registered:
  `by-memory/0x0049ab20-0x0049ab79.StaticTextControlPane2OnPaint.md` (UID0004L0),
  `by-memory/0x0049ab80-0x0049ac59.StaticTextControlPane2ApplyStyleState.md` (UID0004L1),
  `by-memory/0x0049b019-0x0049b02f.StaticTextControlPane2AdjustorThunks.md` (UID0004L2),
  `by-memory/0x0049b5f0-0x0049b6bc.StaticTextControlPane2ScalarDeletingDestructor.md` (UID0004L3),
  `by-memory/0x0049b910-0x0049b915.StaticTextControlPane2GetControlType.md` (UID0004L4),
  `by-type/by-vtable/StaticTextControlPane2Vtables.md` (UID0004L5), and
  `by-memory/0x00618600-0x006186a4.StaticTextControlPane2VtableData.md` (UID0004L6).
- Modified ordinary by-* pages:
  `by-memory/0x0049a410-0x0049b915.StaticTextControlPane2.md`,
  `by-class/StaticTextControlPane2.md`, `by-class/StaticTextControlPane.md`,
  `by-file/StaticTextControlPane.md`, `by-class/FontStyle.md`,
  `by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md`,
  `by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md`, and
  `by-memory/-ignored.md`.
- Created during the original report-only pass and updated claim-by-claim during callback:
  `tools/leaser/Agents/Agent-B002/research/00011V-StaticTextControlPane2-empty-emitter-source-quality.md`.
- Renamed: none. B002 leased and edited no UID0000E5, UID00011U, or B005-owned page.
  Every callback lease was released; the active lease report showed no B002 row after the
  final validator.
- Generated/coverage/tracker/stats/validator state changed only through authorized scoped
  validator side effects; none was manually edited. IDA state was read-only.
- Report execution: not run. B002 did not run `execute_report`, validator lifecycle,
  move, or archive commands.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Read the updated B002 goal and complete project B-agent workflow/template.
- [x] Performed fresh MCP initialize, `idb_list`, health, and live lookup on evidence-time
      database `328356ab` without IDA writes.
- [x] Revalidated every requested target method, all three raw bodies, compiler support,
      sibling exclusions, vtables, callers, resources, globals, and exact padding.
- [x] Corrected raw exclusive ends to `0x0049a949`, `0x0049aa71`, and `0x0049ac59`.
- [x] Resolved UID00011V to semantic-owner-retaining false/blank split-index status.
- [x] Resolved complete `0x2a8` object layout, ControlPane type-8 base construction,
      embedded `0x10c` child, FontStyle deep copy, and destructor ownership.
- [x] Exhausted target/caller/member-pointer/analogous-layout/16-byte-type/compiler-layout
      checks and replaced the unsupported `wchar_t[32] + reserve[16]` split with one
      `wchar_t[40]` field while preserving the exact checked-copy limit `32`.
- [x] Resolved measurement, CR/LF/tab, alignment, clamping, checked-copy order, lifecycle,
      paint, color, opacity, and child forwarding behavior.
- [x] Resolved `SetCenterPosition`, retained `ApplyStyleState`, `OnPaint`, and
      `GetControlType` source names and rejected alternatives.
- [x] Revalidated the type virtual against ControlPane and sibling terminal vtable slots;
      formal source now uses two `int` arguments so `unsigned char` plus MSVC thiscall
      regenerates `AL` and `ret 8`. No-argument sibling declarations are superseded.
- [x] Separated ordinary destructor source from scalar/adjustor/vtable/RTTI compiler output.
- [x] Preserved B005 UID00011U scope and supplied nonduplicating nested declaration
      coordination without creating another report; B002 owns UID0000E4, B005 owns
      UID0000E5/UID00011U, with frozen declaration sync and ordered callbacks.
- [x] Waited through B005's active edits until its completed artifact remained stable at
      SHA `321CD4518BDB36ACF55A6B9AAF3DE2E434E56AF7462FC6F1C242B318CB7D1811`.
- [x] Compared shared managed bodies case-sensitively: B002 Destination 2 equals B005
      Destination 2 (`2026` characters; SHA `19219d...`), and B002 Destination 17 equals
      B005 Destination 3 (`196` characters; SHA `40d419...`). No formal sync edit was
      needed because the completed B005 repair adopted B002's exact blocks.
- [x] Reconciled the completed B005 plan: B002 owns/applies UID0000E4 first; B005 marks it
      verify-only and later owns the UID00011U `a403` correction plus UID0000E5 children.
- [x] Moved Destination 2's outer `[[CHILDREN]]` marker after the complete class close so
      generated outer child definitions expand at namespace scope.
- [x] Set deterministic file-class positions directly to UID0000E3 `10`, UID0000E4 `20`,
      and B005-owned UID0000E5 `30` with no conditional wording.
- [x] Supplied exact new paths/ranges, scores, owners, emitters, positions, source/compiler
      dispositions, and registration order.
- [x] Supplied C01-C35 claim ledger with concrete destination and proposed verification
      state for every implementation item during the initial report-only phase.
- [x] Supplied exactly eighteen destination-specific literal managed blocks; no C++ exists
      outside them.
- [x] Rechecked every score/C++ blocker to resolution or bounded nonblocking uncertainty.
- [x] Confirmed manual coverage/tracker text is not applicable and no prohibited file or
      lifecycle state was touched.
- [x] Confirmed that the initial report-only phase created only this report and used no
      lease or validator.

Implementation callback pass:

- [x] Exact Gate-1 report SHA
      `087985EA5DB05C4731A6596F84A9730B20CB400508AF43A37B68FB22631A33EC`
      was accepted by the supervisor before implementation.
- [x] C01-C35 applied or, for exclusively B005-owned work, preserved as frozen
      comparison/coordination scope without B002 edits.
- [x] Exact children registered low-to-high as UID0004KS, UID0004KT, UID0004KV-UID0004KZ,
      and UID0004L0-UID0004L6 with accepted metadata.
- [x] Destinations 1-16 and 18 synchronized exactly with every B002-owned managed block;
      intentional blank Destinations 1/12 remained blank on both sides. Destination 17
      remained exact comparison text and was not applied by B002.
- [x] Supervisor confirmed B005 still matches exact SHA `321CD451...` and froze the
      byte-identical B002/B005 shared blocks before either implementation callback.
- [x] B002 callback edited UID0000E4/outer pages only and did not lease or edit UID0000E5,
      UID00011U, or any B005-owned child.
- [x] Destination 17 and all B005 `a403`/UID0000E5/UID00011U work remained exclusively
      external B005 scope; B002 neither claimed nor changed that stage.
- [x] Historical assumptions, rejected names/owners, negative evidence, and all sibling
      exclusions preserved at report-level detail.
- [x] One short lease used only for each immediate by-* edit and released after its scoped
      validator.
- [x] One scoped validator run and fully recorded for every changed ordinary by-* page.
- [x] B002 final authorized `--wait-generated` refresh completed as command
      `000000009385`; exact outer counts,
      namespace-scope child placement, marker removal, and no-handwritten-ABI checks were
      recorded. Later validator-owned refresh `000000009396` preserved those counts and
      was observed read-only; B005 owns nested-child generated verification.
- [x] Same report ledger/checklist/results/changed-files/current-state wording reconciled
      archive-neutrally after callback.
- [x] Remaining unapplied accepted items in B002 scope: none. Destination 17 and nested
      child implementation are excluded B005 ownership, not omitted B002 work.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000009409","destination_path":"executed-b-agent-research/B002/00011V-StaticTextControlPane2-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/00011V-StaticTextControlPane2-empty-emitter-source-quality.md","timestamp":"2026-07-13T07:16:42-04:00","uid":"00011V"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
