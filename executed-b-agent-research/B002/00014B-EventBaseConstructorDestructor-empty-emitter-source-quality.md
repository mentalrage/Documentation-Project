** TARGET-REPORT-UID:00014B **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID00014B EventBaseConstructorDestructor Empty Emitter Source Quality Research


## Finalized Report / Current Recommendation

- Completed callback result: [UID:00014B] remains the exact source-authored `Event::Event()` and `Event::~Event()` pair with direct class owner/emitter [UID:00004L] `Event`; its score is `92/93`, emitter position is `20`, and its formal block exactly matches Destination 1 below.
- Final disposition: the former empty-emitter state was a real missing-source defect, not a no-code case. The constructor/destructor are ordinary source-visible lifecycle methods. Their compiler-lowered vptr writes and base calls are not hand-spelled, while the explicit `m_type = kEventNone` state changes are represented.
- Implemented scope: C01-C20 were applied without compression. Destination 2 supplies the Event declaration/payload overlay, Destinations 3 and 4 supply only the accepted covered-by markers for the scalar deleting destructor and vtable data, and the bounded support documentation is synchronized.
- Confidence: very strong for exact bytes, bounds, owner/emitter, base lifecycle, unsigned type storage, object size, source method bodies, scalar-wrapper separation, and Event.cpp placement; strong for reconstructed source-facing enum/payload names, which are descriptive rather than recovered symbols.

## Supporting Research

- Evidence collection occurred on 2026-07-12 through streamable MCP database session `supervisor_20260712`. At collection time, `idb_list` showed one active adopted worker session for `NexusTK.exe.i64`, and `server_health` returned `status:ok`, image base `0x00400000`, auto-analysis ready, Hex-Rays ready, and string cache ready. These are evidence-time observations only; no present or future session availability is asserted.
- The report rechecked current by-* docs, the generated Event output, the current tracker row, the matching executed B008 EventMan/factory report as lead material, all five direct constructor call sites, all 49 ordinary-destructor xrefs, the Event vtable, the scalar wrapper, LObject lifecycle children, EventDispatcher routing, representative mouse/key/text/IME/packet factories, and Main_WndProc type-19/type-22 construction.
- Historical assumption superseded: the target said payload field names and event constants must be resolved later. Evidence-time MCP data resolved the storage shape and supplied defensible source-facing names. Exact original spellings remain unrecoverable, but that is a confidence cap, not a behavior or C++ blocker.
- B002 research, implementation, validation, generated verification, and lease work for this report are complete. Current or future report path, count, validation, execution, move, and archive state are external validator-owned state and are not asserted here.

## Target

- Target UID: `00014B`.
- Target path: `by-memory/0x004a8a90-0x004a8abf.EventBaseConstructorDestructor.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md`, `by-memory` reconstructable not-covered inventory, observed at evidence time as `86/90`, average `88.0`, zero indexed reports.
- Generated state observed at evidence time: `auto-generated/NexusTK/ui/core/Event.cpp`, validator command `000000008883`, refreshed `2026-07-12T21:50:54-04:00`, contained UID00014B as an `Empty Emitter Marker`.
- Assignment classification at research time: independent report-only research for an exact source-authored empty emitter; Gate 1 subsequently accepted the report for the bounded implementation callback.
- Applied scores and parent state: target `92/93`; class owner [UID:00004L] `Event` `92/93`; file route [UID:0000J6] `Event` `91/92` at `NexusTK/ui/core/Event.cpp`.

## Current Target State

- Preserved metadata: `CANONICAL_OWNER:00004L`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004L`, and `Nested:0` remain unchanged. `EMITTER_POSITION_OPTIONAL` is now `20`; the formal C++ block is Destination 1 exactly.
- Owner/emitter state remains correct. The exact pair is class-owned Event source and routes through Event to [UID:0000J6] Event.cpp.
- Historical pre-callback defect: the nonblank route plus blank formal block produced a target Empty Emitter Marker even though both methods had exact source-level bodies. The accepted callback replaced that blank block and the waited generated output has no UID00014B Empty Emitter Marker.
- Historical blocker wording is preserved as superseded: payload/type naming was formerly deferred, but is no longer a reason to omit these lifecycle bodies.
- Historical related contradiction is resolved: [UID:0003LU] previously called the scalar deleting destructor `source-authored` and left another blank emitter. Vtable-only reachability and delete-flag ABI logic establish compiler-generated wrapper support covered by the ordinary destructor; its page now carries Destination 3 only.
- No separate Event layout/type page was created. The complete overlay is documented and emitted on canonical class [UID:00004L] `Event` through Destination 2.
- B002 callback state: all nine by-* edits, their scoped validators, all lease releases, and final waited generated verification are complete. Report execution, lifecycle changes, moves, and archival were not run by B002; current or future external lifecycle state is not asserted.

## Executive Recommendation

- The accepted implementation keeps the exact half-open range and direct Event class ownership.
- UID00014B emits `Event::Event()` and `Event::~Event()` using `kEventNone` as the reconstructed name for byte sentinel `0xff`.
- UID00004L emits the size-preserving Event declaration before the target child. Its four-byte-aligned `EventPayload` union is `0x108`; with the inherited four-byte LObject/vptr, one-byte `m_type`, and compiler padding, `sizeof(Event)` is `0x110`.
- UID0003LU is documented as a reconstructable class-owned compiler-generated scalar deleting destructor wrapper with the Destination 3 covered-by marker to UID00014B. No flag checks, explicit frees, vptr resets, or `0x110` guard-size branch are hand-emitted.
- UID0003I7 is documented as source-declared/generated-binary RTTI/vtable data with the Destination 4 marker covered by UID00004L and UID00014B. No raw dword arrays are emitted.
- UID00014C remains the mixed Event.cpp helper island with corrected payload offsets and globally proven producers; its aggregate formal C++ remains blank.

## Supervisor Active Recheck

- Historical triggering instruction: start report-only UID00014B EventBaseConstructorDestructor research with MCP session `supervisor_20260712`; resolve the empty emitter, raw lifecycle, Event type/payload naming, ownership, source placement, and all score/C++ blockers. Session health and availability statements in this report are evidence-collection-time observations only.
- Callback authorization: supervisor Gate 1 accepted exact pre-callback report SHA256 `8F81E3475ED44D87B96A245D851B1D22E20765238660CCC11317F0AAAD86EC48`; C01-C20 and Destinations 1-4 were then applied in the bounded scope recorded below.
- Split repair was not required for UID00014B: live bounds prove exactly two contiguous source methods and no internal padding. The successor byte is outside the target.
- Every source-bearing target item in scope has a disposition: UID00014B carries the source methods; UID00004L carries the declaration; UID0003LU and UID0003I7 carry only compiler-generated covered-by markers; UID00014C remains a split-first mixed helper aggregate.
- No other active `goal.md` assigned UID00014B, its address range, or this report path. No prior indexed B report for UID00014B was found.

## Inference Research Guidance Check

- `by-structure.md` requires source-bearing exact by-memory methods to carry copy-ready formal C++ once owner, route, score, dependencies, boundaries, and names are defensible. UID00014B satisfies that gate.
- The source/binary distinction is explicit: base ctor/dtor calls, vptr stores, scalar delete flags, sized-delete guard logic, and RTTI/vtable bytes are compiler lowering; the explicit type sentinel stores are source semantics.
- Existing documentation, generated output, and B008 research were treated as leads. Evidence-time MCP revalidated all material binary claims and corrected the overgeneralized claim that every event timestamp is at `+0x10c`.
- No Wave2/Wave3 evidence was used. Any stale Wave2/Wave3 naming found through broad project search was ignored.

## Heuristic / Inference Reanalysis And Validation

### Constructor and destructor source shape

- IDA fact: `0x004a8a90` calls the exact LObject constructor, installs Event vftable `0x006196a4`, stores `0xff` at `this+4`, and returns `this`.
- IDA fact: `0x004a8ab0` installs the Event vftable, stores `0xff` at `this+4`, and tail-jumps to the exact LObject destructor.
- Source inference: an empty initializer-list constructor with `m_type(kEventNone)` and a destructor body assigning `kEventNone` produce precisely the source-visible state. Handwritten base calls/vptr writes are rejected as decompiler-shaped compiler lowering.
- Rejected alternative: an empty destructor is behaviorally incomplete because the binary explicitly writes the sentinel before base teardown.
- Rejected alternative: literal `0xff` in both bodies is behaviorally valid but weaker source shape than the project-wide accepted Event enum style and loses the shared sentinel meaning.

### Type storage and constants

- The field at `+0x04` is an unsigned byte. `IsPointerEvent` uses byte `cmp 7` plus unsigned `setbe`; the other family predicates subtract byte bases and use unsigned `setbe`. A signed `char` would make `0xff` compare incorrectly as a valid low-family event.
- `kEventNone = 0xff` is the highest-probability name: constructor, ordinary destructor, scalar wrapper, and every temporary-factory cleanup restore that value, and no dispatcher family accepts it.
- Types `0-16` and `18` retain the accepted B008 source-facing map. Type `17` is accepted only by the IME classifier and has no producer, so `kEventImeReserved` is explicitly descriptive. It is not omitted.
- Type `19` is now globally resolved as application notification: Main_WndProc message `0x406` constructs an Event, stores type `19`, channel at `+0x08`, and `LObject *` payload at `+0x0c`; `EventMan::PostNotification` posts that exact message. Use `kEventApplicationNotification`.
- Type `20` is explicitly suppressed by `EventDispatcher::DispatchEvent` before routing. With no producer, `kEventDispatchSuppressed` is the most behaviorally honest descriptive name.
- Type `21` has no producer or special consumer beyond the `20..22` classifier. Use `kEventSystemControl` as a descriptive family name and retain the no-producer caveat.
- Type `22` is produced by Main_WndProc when custom message `0x400` carries low-word subtype `32`, then routed through the system/control handler slot. Independent consumers test message/event byte `22` for queued work/notification handling. Use `kEventWorkNotification`.

### Payload and layout

- Scalar-wrapper guard immediate `0x110` and stack-record extents prove `sizeof(Event) == 0x110`.
- `m_type` is at `+0x04`; alignment places a `0x108` payload union at `+0x08`.
- Pointer/mouse overlay: x at `+0x08`, y at `+0x0c`, modifier byte at `+0x10`, detail/wheel value at `+0x14`, and message time at `+0x18`. This corrects the old blanket `tick +0x10c` wording.
- Key overlay: translated key byte at `+0x08`, modifier byte at `+0x10a`, and message time at `+0x10c`.
- Text/composition overlay: subtype/input code at `+0x08`, length or text start at `+0x09/+0x0a`, up to 128 UTF-16 units for live composition text, modifier at `+0x10a`, and message time at `+0x10c`.
- IME result overlay: length at `+0x09`, 129-word storage beginning `+0x0a` so a 128-unit payload can be NUL-terminated through `+0x10b`, and message time at `+0x10c`.
- IME open overlay: open-state integer at `+0x08`, message time at `+0x10c`.
- Candidate overlay: candidate-list pointer at `+0x08`, selected row at `+0x0c`, message time at `+0x10c`.
- Packet overlay: packet-kind/ownership byte at `+0x08`, transferred data pointer at `+0x0c`, and size at `+0x10`. Dispatcher cleanup frees `+0x0c` for type `18`; no destructor-owned payload free belongs in Event::~Event.
- Application-notification overlay: channel/message id at `+0x08`, borrowed/transferred `LObject *` at `+0x0c`; Main_WndProc invokes the payload virtual release after dispatch.
- Source inference: named overlay structs plus a raw `0x108` union member preserve exact size and make all currently proven variants human-readable without inventing a single false common timestamp field.

### Class, factories, and scalar wrapper

- RTTI/name search found Event, EventHandler, EventDispatcher, and EventMan, but no class deriving from Event and no second Event-record vtable. RankingEvent names are unrelated UI classes, not Event subclasses.
- The EventMan/free factory island creates Event stack records by directly invoking LObject construction and storing Event vftable, rather than calling UID00014B. That is consistent with compiler inlining, not a separate subclass or owner.
- Five direct non-inlined constructor call sites remain exact. Two live Main_WndProc uses produce types `22` and `19`; MapPane alert handling creates a default temporary whose scope only needs lifecycle; two retained/no-inbound helper bodies create mouse and key events.
- UID0003LU has exactly one xref from Event vtable slot `0x006196a4`, no direct code caller, and a 27-instruction flag-bearing ABI body. It is not a second source destructor.

## Evidence Standards Used

- Primary: evidence-time IDA MCP function lookup, decompilation, disassembly, bytes, name query, function/data xrefs, caller/callee inventories, vtable slot reads, and health/session checks.
- Secondary: current by-memory/by-class/by-file docs, generated Event.cpp, generated tracker/coverage rows, and matching executed B008 report as a lead.
- Negative evidence: no function at `0x004a8abf`, no Event-derived RTTI class, no direct code caller to scalar wrapper, no producer for types `17`, `20`, or `21`, no separate Event layout page, and no duplicate active B assignment/report.
- Evidence ladder: exact binary facts control behavior/range/layout; current docs establish project UID/source routing; period-appropriate source inference supplies descriptive names only where symbols are absent.
- Tool limitation: no original PDB/source symbols reveal exact member or enum spelling. This caps naming confidence below `95`; it does not prevent a defensible behavior-identical draft.

## Evidence Checked

- Evidence-time MCP availability checks: `idb_list`; `server_health(database=supervisor_20260712)`.
- Core lookups: `0x004a8a90`, `0x004a8ab0`, `0x004a8abf`, `0x004a8ac0`, `0x004a8ad0`, `0x004a8ae0`, `0x004a8af0`, `0x004a8b00`, `0x004ab3f0`, `0x004f4a80`, `0x004f4a90`.
- Raw bytes: `0x004a8a80` size `0x50`; exact target size `47`; successor byte at `0x004a8abf`; Event vtable dwords at `0x006196a0`; scalar post-padding at `0x004ab435`.
- Xrefs: constructor (5), ordinary destructor (49), scalar destructor (1 data), Event vtable (79).
- Decompiled callers: Main_WndProc `0x00465f20`; MapPane alert packet handler `0x00513da0`; retained mouse helper `0x00588c40`; retained key helper `0x0058eb50`.
- Decompiled routes/factories: EventDispatcher `0x004a6ef0`, `0x004a7130`, `0x004a77d0`; mouse/key/text `0x004a9120`, `0x004a95a0`, `0x004a96a0`, `0x004a97e0`, `0x004a98a0`; IME `0x004a9a40`, `0x004a9ae0`, `0x004a9c10`, `0x004a9cb0`, `0x004a9db0`, `0x004a9e50`, `0x004a9f00`; packet `0x004a9fa0`, `0x004aa050`, `0x004aa110`.
- Docs checked: UID00014B, UID00004L, UID0000J6, UID00014C, UID0003LU, UID0003I7, UID00036Z, UID000370, UID00007D, EventHandler/EventDispatcher/EventMan support, by-structure, by-memory guidance, report template, score-blocker standard.
- Historical report search terms: `00014B`, `EventBaseConstructorDestructor`, `0x004a8a90`, `Event`, `EventMan`, `EventType`, `m_type`. Only the related executed B008 UID00014C report was used as a lead.
- Research pass exclusions: validators, leases, by-* edits, and generated refresh were intentionally skipped before Gate 1. The accepted callback subsequently used only the bounded edits, leases, validators, and generated refresh recorded below. IDA writes, process management, report execution, and lifecycle commands were not performed.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Target is exact half-open `0x004a8a90-0x004a8abf`, two functions, no internal padding. | Very high | lookup, disasm, exact bytes | UID00014B Scope/Range | historicalize prior shallow wording; incorporate exact scope | applied; command `000000008922` passed |
| C02 | `0x004a8abf-0x004a8ac0` is one outside `0xcc` alignment byte. | Very high | get_bytes, successor lookup | UID00014B Range/Padding | incorporate | applied; target page records outside-range padding |
| C03 | Constructor calls LObject ctor and source-initializes type to none. | Very high | analyze/decompile `0x004a8a90` | UID00014B Behavior/C++ | incorporate | applied in target prose and Destination 1 |
| C04 | Destructor resets type then performs LObject teardown. | Very high | analyze/decompile `0x004a8ab0` | UID00014B Behavior/C++ | incorporate | applied in target prose and Destination 1 |
| C05 | LObject lifecycle bodies are exact compiler-lowered base dependencies. | Very high | UID00036Z/UID000370 plus MCP | UID00014B Dependencies | incorporate | applied; compiler-lowering boundary retained |
| C06 | Constructor has five exact calls in four functions with described contexts. | Very high | xrefs/decompile | UID00014B Callers | incorporate | applied; all five calls and four caller roles recorded |
| C07 | Destructor has 49 xrefs: six normal call sites plus EH cleanup references. | Very high | xrefs_to | UID00014B Callers | incorporate | applied; six normal and 43 EH references recorded |
| C08 | Event COL/vtable is `0x006196a0-0x006196b0`, slots `4ab3f0/4f4b10/41b6c0`, 79 vtable refs. | Very high | bytes/xrefs/names | UID00014B, UID0003I7 | incorporate | applied to target and UID0003I7; commands `000000008922`/`000000008926` passed |
| C09 | UID0003LU is compiler-generated scalar deleting wrapper, vtable-only, size guard `0x110`. | Very high | xref/decompile/disasm | UID0003LU | historicalize source-authored claim; add marker | applied; Destination 3 only, command `000000008925` passed |
| C10 | Exact Event size is `0x110`. | Very high | scalar guard and stack extents | UID00004L layout | incorporate | applied; declaration arithmetic and generated source verified |
| C11 | `m_type` is unsigned byte at `+0x04`; none sentinel is `0xff`. | Very high | unsigned classifier opcodes and lifecycle stores | UID00014B/UID00004L | incorporate | applied to target methods and class declaration |
| C12 | Types `0-22` have the resolved/descriptive enum disposition in this report. | High | factories, dispatcher, Main_WndProc | UID00004L/UID00014C/EventMan | incorporate | applied; types 17/20/21 remain explicit no-producer values |
| C13 | Payload is variant union at `+0x08`, not one common tick layout. | Very high | representative factory stack offsets | UID00004L/UID00014C | historicalize old common-tick wording; incorporate overlays | applied to class, aggregate, and file route |
| C14 | Packet fields are kind `+8`, data `+c`, size `+10`; dispatcher frees data for type 18. | Very high | three packet factories and dispatcher | UID00004L/UID00014C | incorporate | applied with ownership/free route preserved |
| C15 | Type 19 is application notification with channel `+8` and LObject pointer `+c`; type 22 is work notification. | Very high/high | Main_WndProc and PostNotification docs | UID00004L/UID00014C/EventMan/EventDispatcher/EventHandler | incorporate | applied to all five bounded support destinations |
| C16 | No Event subclass or alternate Event-record vtable exists in evidence-time RTTI/name evidence. | High | entity names and vtable inventory | UID00004L | incorporate negative evidence | applied; no-subclass result and confidence cap retained |
| C17 | Source placement remains `NexusTK/ui/core/Event.cpp`; no new EventLayout file/page. | High | owner chain and helper island | UID0000J6/UID00004L | incorporate | applied; canonical class/file route retained and no duplicate page created |
| C18 | Destination 1 is exact target formal C++ and resolves the target Empty Emitter Marker. | High | source/binary lowering analysis | UID00014B formal block | apply exactly | applied exactly; waited output has one ctor/dtor pair and no target empty marker |
| C19 | Destination 2 is exact size-preserving Event declaration and enum/payload support. | High | all layout/factory evidence | UID00004L formal block | apply exactly | applied exactly; waited output has one Event declaration and `0x110` layout |
| C20 | Destinations 3/4 preserve ABI/vtable separation with no raw wrapper/data emission. | Very high | scalar/vtable evidence and project precedent | UID0003LU/UID0003I7 formal blocks | apply exactly | applied exactly; waited output has both markers and no scalar body/raw vtable array |

## Positive Evidence Summary

- The target has exact modeled methods, direct source owner, valid emitter chain, score above the C++ gate, known dependencies, exact neighboring boundary, and source-visible state writes.
- Constructor and destructor bodies are simple enough to reconstruct without decompiler artifacts: one source member initialization each, with all vptr/base mechanics left to the compiler.
- Five non-inlined constructor calls and 49 destructor cleanup refs prove live lifecycle use; 79 vtable refs show broad inline Event construction in Event.cpp factories.
- Factory and dispatcher bodies resolve unsigned type storage, full family ranges, per-variant payload offsets, and producer semantics for type 19 and type 22.
- Existing project precedent uses formal comment-only covered-by markers for scalar deleting destructors and generated vtable data once an ordinary source destructor/class declaration exists.

## IDA MCP Facts

- Functions: `sub_4A8A90` size `0x20`; `sub_4A8AB0` size `0x0f`; no function at `0x004a8abf`; successor `sub_4A8AC0` size `0x08`.
- Exact target bytes: 47 bytes from `0x004a8a90` through `0x004a8abe`; byte `0x004a8abf` is `cc`.
- Constructor assembly: LObject call at `0x004a8a9a`; Event vptr store at `0x004a8a9f`; byte-`ff` store at `0x004a8aa7`.
- Destructor assembly: Event vptr store at `0x004a8ab0`; byte-`ff` store at `0x004a8ab6`; tail jump to LObject destructor at `0x004a8aba`.
- Vtable bytes: `0x006196a0 -> 0x0064707c`, `0x006196a4 -> 0x004ab3f0`, `0x006196a8 -> 0x004f4b10`, `0x006196ac -> 0x0041b6c0`.
- Scalar wrapper: `0x004ab3f0-0x004ab435`, 27 instructions; writes Event vptr/type, calls LObject teardown, tests flags `1` and `4`, calls `0x004f4ac0` for ordinary free, and carries guard-size immediate `0x110`.
- Classifier bodies: `<=7`, `(type-8)<=2`, `(type-11)<=6`, `type==18`, `(type-20)<=2`, all with unsigned byte behavior.
- RTTI/name query: one `Event` type descriptor/COL/vtable family; no Event-derived class type.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004a8a90-0x004a8ab0` | within UID00014B | `Event::Event()` | true | UID00004L | target `86/90 -> 92/93` | source body ready |
| `0x004a8ab0-0x004a8abf` | within UID00014B | `Event::~Event()` | true | UID00004L | target `86/90 -> 92/93` | source body ready |
| `0x004a8abf-0x004a8ac0` | UID0000VN ignored index | one-byte alignment | false | none | unchanged | outside target |
| `0x004a8ac0-0x004ab3eb` | UID00014C | mixed classifiers/EventMan/free factories | true aggregate | UID0000J6 | `88/90 -> 91/92` | support sync, aggregate blank |
| `0x004ab3f0-0x004ab435` | UID0003LU | Event scalar deleting destructor | true generated support | UID00004L | `86/90 -> 90/93` | formal covered-by marker |
| `0x006196a0-0x006196b0` | UID0003I7 | Event COL/vtable data | true generated data | UID00004L | `85/91 -> 90/94` | formal covered-by marker |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00466530` | Main_WndProc `0x00465f20` | Constructs type 22 for custom message `0x400`, low-word subtype `32`; dispatches and destroys. |
| `0x0046668b` | Main_WndProc `0x00465f20` | Constructs type 19 for message `0x406`, stores channel/payload, dispatches, releases payload, destroys. |
| `0x00513e62` | MapPane alert packet helper `0x00513da0` | Default Event temporary around browser navigation/dialog creation; both branches destroy it without assigning another type. |
| `0x00588c74` | retained/no-inbound helper `0x00588c40` | Constructs one Event and sends pointer types `1`, `0`, and `3` through a handler. |
| `0x0058eb81` | retained/no-inbound helper `0x0058eb50` | Constructs key type `8`, stores key/modifier/time state, passes to `0x00594040`, destroys. |
| UID00014B destructor | six normal caller sites plus 43 EH cleanup references | Normal scope teardown and compiler unwind cleanup for Event temporaries. |
| UID0003LU | sole data xref from `0x006196a4` | Expected vtable-only scalar deleting destructor reachability. |
| Event vtable `0x006196a4` | 79 refs | Base lifecycle, inline factories, cleanup sites, and scalar wrapper. |

## Documentation Evidence And IDA Status

- Historical pre-callback UID00014B state: correct basic range, owner/emitter, five constructor call sites, one-byte successor padding, and Event.cpp split context were already present; source C++, exact caller roles, unsigned type reasoning, payload closure, and correct scalar-wrapper disposition were missing. The callback supplied each missing item.
- Historical pre-callback UID00004L state: classifier families and approximate union direction were already present; `tick +0x10c` wording was too broad and the blank declaration caused a class Empty Emitter Marker. Destination 2 and the corrected variant-specific offsets now resolve both defects.
- UID0000J6 correctly owns Event/EventMan/factories in `ui/core/Event.cpp`; it needs the resolved class declaration, enum, payload overlay, type19/type22 producers, and scalar/vtable marker relationships.
- UID00014C and the executed B008 report contained strong factory/type leads. Evidence-time MCP confirmed them and superseded the unresolved global producer statement for type 19 and type 22; the callback synchronized those accepted facts.
- UID0003LU correctly records exact bounds and vtable relation but incorrectly labels the wrapper source-authored and defers it on payload names. It must be historicalized as compiler-generated ABI support.
- UID0003I7 has exact dwords/owner but blank formal output. A class/source coverage marker is safer than raw vtable data.
- Generated Event.cpp evidence-time state contains Empty Emitter Markers for UID00004L and UID00014B. Generated output is validator-owned and must not be edited manually.

## Ranked Ownership Analysis

### 1. Event class UID00004L through Event.cpp UID0000J6

- Evidence for: decorated Event vtable/RTTI, exact ctor/dtor vptr writes, source member at `+4`, scalar wrapper in first vtable slot, all Event.cpp factories constructing the same record, current direct owner/emitter chain, and Event.cpp generated route.
- Evidence against: exact original header split and private/public member spellings are not symbol-proven.
- Decision: retain. This is direct semantic and source ownership, not merely adjacency.

### 2. Event file UID0000J6 directly

- Evidence for: physical/source module owns Event, EventMan, classifiers, and free factories.
- Evidence against: class methods should attach to their direct class, not bypass it to a file fallback.
- Decision: retain only as the class's source emitter root.

### 3. EventDispatcher UID00004M / UID0000J7

- Evidence for: consumes every Event and owns family routing.
- Evidence against: no construction ownership; dispatcher receives ready records and calls Event predicates/handlers.
- Decision: reject as target owner. Update only consumer documentation where type19/type22 producer wording is stale.

### 4. EventMan UID00004O

- Evidence for: produces most pointer/key events and participates in Event.cpp.
- Evidence against: target lifecycle is Event class behavior, and free IME/packet factories plus Main_WndProc also create Event records.
- Decision: reject as target owner; synchronize producer support only.

### 5. New EventLayout/EventType source file or no-owner route

- Evidence for: payload overlays are substantial enough to merit detailed documentation.
- Evidence against: UID00004L is already the canonical class declaration owner; a new file/page would duplicate layout and fragment one small Event source family. No-owner/non-emitting contradicts decorated class identity and exact live methods.
- Decision: reject. Keep layout and enum on UID00004L and source placement in UID0000J6.

## Source Placement

- Recommended placement: `NexusTK/ui/core/Event.cpp`, with the class declaration conceptually sourced from Event/EventHandler-adjacent UI-core headers but emitted by current UID0000J6 route.
- Event declaration position: UID00004L at `10` with `[[CHILDREN]]`.
- Target method position: UID00014B at `20`.
- Scalar wrapper marker position: UID0003LU at `90`.
- Vtable marker position: UID0003I7 at `100`.
- Rejected `EventMan.cpp`: plausible historical split but weaker than current physical clustering and existing file route; no binary evidence requires moving this target.
- Rejected `EventDispatcher.cpp`: consumption is not ownership.
- Remaining uncertainty: exact historical header filename is not recoverable and does not affect current emitter route or method body.

## Range / Split / Padding / Reclassification Analysis

- Exact target range: `0x004a8a90-0x004a8abf`, half-open, 47 bytes.
- Internal children: constructor `0x20` bytes, destructor `0x0f` bytes; no gap.
- Predecessor: EventHandler range ends at `0x004a8a84`, followed by twelve `0xcc` bytes through `0x004a8a90`.
- Successor: one `0xcc` byte at `0x004a8abf`, then first Event classifier at `0x004a8ac0`.
- Scalar wrapper remains split at `0x004ab3f0-0x004ab435` because Event.cpp helper code occupies the intervening range and wrapper reachability is a distinct vtable ABI route.
- Target remains source-authored/reconstructable. UID0003LU is reworded to source-declared/generated-binary wrapper support without clearing its class route; UID0003I7 remains source-declared/generated-binary data.
- `Nested:0` remains correct for UID00014B because the page directly represents its two contiguous methods rather than a parent range with separate child pages.

## Negative Evidence Summary

- No function starts at the exclusive target end or one-byte padding address.
- No payload allocation, copy, release, or external call occurs in the source destructor; adding payload cleanup would change behavior.
- No Event-derived RTTI class or alternate Event-record vtable was found.
- No direct code calls UID0003LU; hand-authoring it as a normal method would duplicate compiler ABI output.
- No type `17`, `20`, or `21` producer was found in all Event-vtable construction sites and all five out-of-line constructor callers. Their descriptive names must retain that caveat.
- Consumer xrefs from EventDispatcher prove routing, not ownership of Event lifecycle or factories.
- Address adjacency to EventHandler and EventMan is supporting source-family evidence, not the primary ownership proof.
- No new by-type layout page is justified when UID00004L can carry the declaration and exact overlay evidence without duplication.

## IDA Rename / Type / Comment Recommendations

- Rename `sub_4A8A90` source-facing role to `Event::Event` and `sub_4A8AB0` to `Event::~Event` in documentation; IDA database mutation is not requested.
- Type `this` as `Event *`; type field `+0x04` as `unsigned char m_type`; type payload at `+0x08` as `EventPayload` size `0x108`.
- Use enum/source names from Destination 2. `kEventImeReserved`, `kEventDispatchSuppressed`, and `kEventSystemControl` are explicitly descriptive, not original-symbol claims.
- Use `EventPointerPayload::m_messageTime` at Event `+0x18`; do not label it `+0x10c`.
- Use `m_packetKind`, `m_data`, and `m_size` for packet overlay; avoid calling the `+8` byte a proven ownership flag because all type-18 data pointers are freed after dispatch.
- Use `m_channel`/`m_payload` for type19 notification overlay and `kEventWorkNotification` for type22.
- IDA renames/types are safe as comments/local type overlays after supervisor acceptance, but no IDB writes are part of this report.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. UID00014B is source-authored and clears the score/emitter gate; UID00004L needs the declaration dependency; UID0003LU/UID0003I7 need comment-only compiler-coverage markers.
- No draft/example/sample code exists outside the four destination-specific managed formal blocks below.

### Destination 1 - UID00014B EventBaseConstructorDestructor

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
Event::Event()
    : m_type(kEventNone)
{
}

Event::~Event()
{
    m_type = kEventNone;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 2 - UID00004L Event

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
enum EventType
{
    kEventCursorMove = 0,
    kEventLeftButtonDown = 1,
    kEventLeftButtonDoubleClick = 2,
    kEventLeftButtonUp = 3,
    kEventRightButtonDown = 4,
    kEventRightButtonDoubleClick = 5,
    kEventRightButtonUp = 6,
    kEventMouseWheel = 7,
    kEventKeyDown = 8,
    kEventKeyUp = 9,
    kEventTextInput = 10,
    kEventImeOpenStatus = 11,
    kEventImeCompositionStart = 12,
    kEventImeCompositionResult = 13,
    kEventImeCompositionEnd = 14,
    kEventImeCandidateList = 15,
    kEventImeCandidateClose = 16,
    kEventImeReserved = 17,
    kEventPacket = 18,
    kEventApplicationNotification = 19,
    kEventDispatchSuppressed = 20,
    kEventSystemControl = 21,
    kEventWorkNotification = 22,
    kEventNone = 0xff
};

struct EventPointerPayload
{
    int m_x;
    int m_y;
    unsigned char m_modifiers;
    unsigned char m_padding[3];
    int m_detail;
    unsigned int m_messageTime;
};

struct EventKeyPayload
{
    unsigned char m_key;
    unsigned char m_reserved;
    wchar_t m_text[128];
    unsigned char m_modifiers;
    unsigned char m_padding;
    unsigned int m_messageTime;
};

struct EventTextPayload
{
    unsigned short m_inputCode;
    wchar_t m_text[128];
    unsigned char m_modifiers;
    unsigned char m_padding;
    unsigned int m_messageTime;
};

struct EventCompositionPayload
{
    unsigned char m_subtype;
    unsigned char m_length;
    wchar_t m_text[128];
    unsigned char m_modifiers;
    unsigned char m_padding;
    unsigned int m_messageTime;
};

struct EventImeResultPayload
{
    unsigned char m_reserved;
    unsigned char m_length;
    wchar_t m_text[129];
    unsigned int m_messageTime;
};

struct EventImeOpenPayload
{
    int m_isOpen;
    unsigned char m_reserved[0x100];
    unsigned int m_messageTime;
};

struct EventCandidatePayload
{
    void *m_candidateList;
    int m_selectedRow;
    unsigned char m_reserved[0xfc];
    unsigned int m_messageTime;
};

struct EventPacketPayload
{
    unsigned char m_packetKind;
    unsigned char m_padding[3];
    void *m_data;
    unsigned int m_size;
};

struct EventNotificationPayload
{
    unsigned int m_channel;
    LObject *m_payload;
};

union EventPayload
{
    EventPointerPayload m_pointer;
    EventKeyPayload m_key;
    EventTextPayload m_text;
    EventCompositionPayload m_composition;
    EventImeResultPayload m_imeResult;
    EventImeOpenPayload m_imeOpen;
    EventCandidatePayload m_candidate;
    EventPacketPayload m_packet;
    EventNotificationPayload m_notification;
    unsigned char m_raw[0x108];
};

class Event : public LObject
{
public:
    Event();
    virtual ~Event();

    bool IsPointerEvent() const;
    bool IsKeyOrTextEvent() const;
    bool IsImeEvent() const;
    bool IsPacketEvent() const;
    bool IsSystemOrControlEvent() const;

    unsigned char m_type;
    EventPayload m_payload;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 3 - UID0003LU EventScalarDeletingDestructor

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0003LU] Compiler-generated MSVC scalar deleting destructor wrapper for
// Event is covered by the source-level Event::~Event() body in
// [UID:00014B][0x004a8a90-0x004a8abf.EventBaseConstructorDestructor](by-memory/0x004a8a90-0x004a8abf.EventBaseConstructorDestructor.md); do not hand-emit the
// ABI delete flags, vtable resets, object free, or 0x110 guard-size path.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 4 - UID0003I7 EventVtableData

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0003I7] Event RTTI and vtable bytes are compiler-generated from the
// [UID:00004L][Event](by-class/Event.md) class declaration and the source-level
// destructor in [UID:00014B][0x004a8a90-0x004a8abf.EventBaseConstructorDestructor](by-memory/0x004a8a90-0x004a8abf.EventBaseConstructorDestructor.md); do not emit raw RTTI or vtable arrays.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Behavior preservation: Destination 1 preserves only the explicit type stores while relying on normal C++ lowering for LObject lifecycle and vptr state. Destination 2 preserves exact size/offsets through a `0x108` aligned union. Destinations 3/4 intentionally prevent duplicate ABI/data source.
- Source-shape rationale: an ordinary VC6/VC7-era enum, POD payload union, virtual LObject-derived record, out-of-line lifecycle bodies, and compiler-generated scalar wrapper/vtable are more plausible than raw offsets, synthetic ABI functions, or byte arrays.
- Naming convention: project-accepted `kEvent...` constants and `m_...` members. Original spelling uncertainty is preserved in prose and score caps.
- Third-party import directive: not applicable; this is NexusTK-owned source.

## Final Recommendation

- C01-C20 are applied to the exact target and listed support docs.
- Target owner/emitter/reconstructable remain unchanged; target is `92/93`, position `20`, with Destination 1 formal code.
- UID00004L is `92/93`, position `10`, with Destination 2 and `[[CHILDREN]]`.
- UID0003LU is `90/93`, position `90`, retains owner/emitter/reconstructable, is classified as compiler-generated source-declared/generated-binary support, and carries Destination 3 only.
- UID0003I7 is `90/94`, position `100`, retains owner/emitter/reconstructable, and carries Destination 4 only.
- UID00014C, Event.cpp, EventMan, EventDispatcher, and EventHandler facts are synchronized without moving source ownership or adding aggregate code.
- No in-scope item remains no-owner/non-emitting and no payload/type/C++ blocker is deferred.
- No generated/tracker/coverage file was edited manually. Scoped validation and the final waited generated refresh completed under the accepted callback.

## Recommended Target Doc Changes

- Applied target path: `by-memory/0x004a8a90-0x004a8abf.EventBaseConstructorDestructor.md`.
- Applied metadata: `86/90 -> 92/93`; owner `00004L` unchanged; reconstructable true unchanged; emitter `00004L` unchanged; position blank -> `20`; formal block -> Destination 1; `Nested:0` unchanged.
- Stale `final C++ remains blank` and future payload/constants blocker wording is retained only as explicitly superseded history; the current page records the resolved source-ready disposition.
- Exact raw bytes/instruction anchors, unsigned type proof, five caller roles, all 49 destructor xref classes, 79 vtable refs, LObject dependencies, size `0x110`, payload overlay summary, source/compiler lowering distinction, scalar-wrapper relation, and rejected alternatives are incorporated.
- Historical broad-range split and old blocker provenance remain explicitly labeled as superseded.
- Applied Item Summary: exact source-authored Event constructor/destructor with five constructor calls, 49 destructor refs, unsigned `m_type` sentinel `0xff`, LObject lifecycle, one-byte successor alignment, source-ready formal bodies, and separate compiler-generated scalar/vtable support.

## Recommended Support Doc Changes

- `by-class/Event.md` UID00004L: applied `87/90 -> 92/93`, position `10`, and Destination 2 with exact size/overlay, source constants, no derived Event class, and correct pointer versus text/IME time offsets.
- `by-file/Event.md` UID0000J6: applied `88/89 -> 91/92` with complete Event declaration/type/payload source shape, constructor caller roles, type19/type22 producers, wrapper/vtable markers, and unchanged Event.cpp placement.
- `by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md` UID00014C: applied `88/90 -> 91/92`, corrected the overgeneralized timestamp statement, added exact overlays and globally proven type19/type22 producers, and preserved mixed aggregate blank-C++/split-first disposition.
- `by-class/EventMan.md` UID00004O: applied `88/90 -> 90/92`, replaced `type19 producer not proven` and provisional type22 wording with Main_WndProc/PostNotification evidence, and preserved types17/20/21 no-producer caveats.
- `by-memory/0x004ab3f0-0x004ab435.EventScalarDeletingDestructor.md` UID0003LU: applied `86/90 -> 90/93`, position `90`, and Destination 3; historicalized `source-authored` and payload-name deferral; recorded exact disassembly, sole vtable xref, delete flags, size guard, and no handwritten wrapper.
- `by-memory/0x006196a0-0x006196b0.EventVtableData.md` UID0003I7: applied `85/91 -> 90/94`, position `100`, and Destination 4 while retaining exact dwords/79 refs and source-declared/generated-binary classification.
- `by-class/EventHandler.md` UID00004N and `by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md` UID000141: scores and formal blocks remain unchanged; global type19 application-notification and type22 work-notification producer evidence was added while slot-family names and source ownership were preserved.
- No new by-type/by-struct page was created; the exact class declaration remains the canonical layout destination.

## Score And Metadata Recommendation

- Target pre-callback state: `86/90`, correct owner/emitter/reconstructable, blank position/code.
- Target applied state: `92/93`, same owner/emitter/reconstructable, position `20`, Destination 1.
- Completion rationale: exact bytes/bounds, dependencies, all callers/xrefs, state/layout, source placement, formal methods, wrapper/vtable dispositions, and open-question closure are documented.
- Confidence rationale: binary behavior is exact; inferred enum/member spellings and historical header split keep both values below final-audit `95+`.
- Blocker audit:
  - Payload names: resolved with exact variant offsets and descriptive POD overlays.
  - Event constants: resolved through factories/classifiers/callers; unproduced values retain explicit descriptive names/caveats.
  - Constructor/destructor callers: all five constructor calls and all destructor xrefs checked.
  - LObject dependencies: exact children and evidence-time MCP bodies checked.
  - Scalar wrapper: resolved as compiler-generated marker-covered ABI support.
  - Vtable/layout: exact dwords, RTTI family, size, and no-subclass result checked.
  - Source placement: Event class -> Event.cpp retained; alternatives ranked/rejected.
  - C++: exact formal target/declaration/marker blocks supplied.
- Metadata left unchanged: target owner `00004L`, reconstructable true, emitter `00004L`, `Nested:0`.

## Open Questions With Attempted Resolution

- Exact original enum/member spellings: no symbols expose them. Factories, consumers, accepted project convention, and storage offsets support the names in Destination 2. This is a confidence cap only.
- Type 17: all IME classifier routes checked; no producer exists. Resolved as reserved IME family value, not deferred.
- Type 20: DispatchEvent exact gate checked; no producer exists. Resolved descriptively as dispatch-suppressed control value.
- Type 21: all Event vtable construction sites and five constructor callers checked; no producer exists. Resolved descriptively as system/control family value.
- Type 22: Main_WndProc producer and downstream work-notification consumers checked. Resolved as work notification.
- Type19: Main_WndProc message `0x406` and EventMan PostNotification route checked. Resolved as application notification.
- Payload `+0x08` byte for packet events: three factory variants and dispatcher free checked. It distinguishes packet construction kind, but exact semantic spelling is not provable. `m_packetKind` avoids the unsupported claim that only one value owns memory.
- Historical header split: no source/path symbols exist. Event.cpp route is sufficient and no score/C++ impact remains.
- No unresolved question blocks implementation, ownership, range, score, or formal C++.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. The relevant tracker and generated coverage files are validator-owned. No manual row text is supplied.
- Actual tool-owned result from waited command `000000008932`: UID00014B emits Destination 1 instead of an Empty Emitter Marker; UID00004L emits Destination 2; UID0003LU/UID0003I7 emit their explicit covered-by markers. Generated output remains validator-owned.

## Follow-Up Actions

- Completed B002 callback scope: C01-C20 were applied to the target and bounded support docs under short per-file leases; each changed by-* file passed a scoped validator; the final waited refresh verified one UID00014B constructor/destructor pair, one Event declaration, both support markers, and no UID00014B Empty Emitter Marker.
- A-agent actions: none required.
- Remaining B002 work: none for this assignment; exact helper-child splitting inside UID00014C remains independent work and is not a blocker for UID00014B.
- Report execution, lifecycle, move, and archive actions remain external validator-owned state and are not directed or asserted here.

## Confidence

- Recommendation confidence: very high.
- Score confidence: high; `92/93` reflects complete exact-range research while respecting inferred source spelling.
- Remaining uncertainty: original identifier/header spellings and semantics of never-produced type17/type20/type21 values. These do not change bytes, behavior, ownership, source placement, or target code.

## Validator Results

- Research pass: no validator was run before Gate 1, as required.
- UID00014B target: command `000000008922`, `2026-07-12T23:08:47-04:00`, exit `0`, `ok:1`. Its interim unresolved UID0003LU/UID0003I7 references cleared after those pages were registered by their own scoped validators.
- UID00004L Event: command `000000008924`, `2026-07-12T23:09:54-04:00`, exit `0`, `ok:1`. Its interim UID0003LU/UID0003I7 references likewise cleared after registration.
- UID0003LU scalar wrapper: command `000000008925`, `2026-07-12T23:10:38-04:00`, exit `0`, `ok:1`; the new UID mapping registered. Its interim UID0003I7 reference cleared after the next scoped validation.
- UID0003I7 vtable data: command `000000008926`, `2026-07-12T23:11:39-04:00`, exit `0`, `ok:1`; the new UID mapping registered.
- UID0000J6 Event.cpp route: command `000000008927`, `2026-07-12T23:12:20-04:00`, exit `0`, `ok:1`; two pre-existing unresolved UID0003LV references remain outside UID00014B callback scope.
- UID00014C helper aggregate: command `000000008928`, `2026-07-12T23:13:15-04:00`, exit `0`, `ok:1`; three pre-existing unresolved UID0003LV references remain outside UID00014B callback scope.
- UID00004O EventMan: command `000000008929`, `2026-07-12T23:13:45-04:00`, exit `0`, `ok:1`; two pre-existing unresolved UID0003LV references remain outside UID00014B callback scope.
- UID00004N EventHandler: command `000000008930`, `2026-07-12T23:14:16-04:00`, exit `0`, `ok:1`; four pre-existing unresolved UID0003I6 references remain outside UID00014B callback scope.
- UID000141 EventDispatcher: command `000000008931`, `2026-07-12T23:14:48-04:00`, exit `0`, `ok:1`; no missing references were reported.
- Final waited validation: command `000000008932`, `2026-07-12T23:15:03-04:00`, exit `0`, `ok:1`; `generated_refresh` completed under the same command and timestamp. Broad project-wide generator warnings reported 218 unrelated no-code emitters, 81 unrelated missing `[[CHILDREN]]` markers, and 16 unrelated fallbacks; none is a UID00014B callback defect.
- Generated `auto-generated/NexusTK/ui/core/Event.cpp` proof: validator header command `000000008932`; exactly one UID00004L Event declaration, one UID00014B constructor definition, one UID00014B destructor definition, one Event global, one key table, and one `m_raw[0x108]`; UID0003LU and UID0003I7 covered-by markers are present; UID00014B and UID00004L Empty Emitter Markers are absent; no scalar-wrapper body or raw vtable address is emitted. Event payload overlay arithmetic is `0x108`, and `4 + 1 + 3 + 0x108 == 0x110`.
- MCP result: evidence-time session `supervisor_20260712` health and all listed read-only calls succeeded after correcting local PowerShell client argument handling; this does not assert present session availability.

## Changed Files

- Report updated: `tools/leaser/Agents/Agent-B002/research/00014B-EventBaseConstructorDestructor-empty-emitter-source-quality.md`.
- Modified by B002: `by-memory/0x004a8a90-0x004a8abf.EventBaseConstructorDestructor.md` (`C9C841B839B6E35F0A10276CFEDEE33375C481E3FD11F6741343B51B536B8166`).
- Modified by B002: `by-class/Event.md` (`7F9E98F3A00F1A277E7AFE98C7A45A90F2C5EFA23FF556894B1FC1F186FC2630`).
- Modified by B002: `by-memory/0x004ab3f0-0x004ab435.EventScalarDeletingDestructor.md` (`49225F0D0635059018054C3A58365A05A55C9DD9FADAC5CD15A939000A420A28`).
- Modified by B002: `by-memory/0x006196a0-0x006196b0.EventVtableData.md` (`3BAAD1786F83CF610E588F0D1FCC82230405808627089A6CB21BF42BAAF05D5A`).
- Modified by B002: `by-file/Event.md` (`EC7D393B029A0D947C94D1CF7F2E4074256F2FAF8297A67070F5F2B9205061AF`).
- Modified by B002: `by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md` (`EA21D29D1E9A0B17E68C08C553A08AA527F38A694078850E7C7F7404978F1FC9`).
- Modified by B002: `by-class/EventMan.md` (`240D2FC1D8124990E9AE1050B774DE099CBBE8A4F3AF5F9FC42E8483A8C72171`).
- Modified by B002: `by-class/EventHandler.md` (`544FB573254DA6BE71F8C1A17B9E6F6E283087DF5B107942AA4A01CA6215636A`).
- Modified by B002: `by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md` (`35A1CB605F798B7E2DD14E859A8545F3C508B26572844C5A15CF2994409A82E0`).
- Renamed: none.
- Validator-owned refresh: `auto-generated/NexusTK/ui/core/Event.cpp` was regenerated by command `000000008932`; B002 made no manual generated/coverage/tracker/supervisor edit.
- Leases: each by-* page was leased only while it was edited and validated, then released immediately. No B002 lease remains active.
- Report execution: not run. No lifecycle, move, or archive command was run; current or future external lifecycle state is not asserted.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 accepted exact pre-callback report SHA256 `8F81E3475ED44D87B96A245D851B1D22E20765238660CCC11317F0AAAD86EC48` before implementation.
- [x] Apply C01-C20 to target/support docs without compression.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger includes every accepted claim, destination, and applied callback proof.
- [x] Metadata/score changes specified exactly.
- [x] Every in-scope score/source-quality blocker researched to resolution.
- [x] Owner/emitter/reconstructable decisions resolved.
- [x] Range/split/padding/reclassification decisions resolved.
- [x] Source placement and IDA rename/type/comment recommendations resolved.
- [x] Four destination-specific exact managed formal blocks supplied; no C++ exists outside them.
- [x] Third-party import directive confirmed not applicable.
- [x] Historical assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions closed or bounded with evidence and no blocking impact.
- [x] Set UID00014B to `92/93`, position `20`, and apply Destination 1 exactly.
- [x] Set UID00004L to `92/93`, position `10`, and apply Destination 2 exactly.
- [x] Set UID0003LU to `90/93`, position `90`, and apply Destination 3 exactly.
- [x] Set UID0003I7 to `90/94`, position `100`, and apply Destination 4 exactly.
- [x] Synchronize UID0000J6, UID00014C, UID00004O, UID00004N, and UID000141 at report-level detail.
- [x] Run one scoped validator per changed by-* file only after approved callback.
- [x] Run final validator-generated refresh with wait and verify generated Event.cpp.
- [x] No manual generated/coverage/tracker text required.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support facts incorporated at report-level detail.
- [x] Ledger updated from pending callback to applied with claim-specific proof.
- [x] Metadata/score/owner/emitter/position/formal block changes applied exactly.
- [x] Historical assumptions and rejected alternatives preserved.
- [x] Scoped validators recorded with command id, timestamp, exit code, and ok count.
- [x] Final waited generated refresh verified.
- [x] Remaining unapplied accepted items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000008979","destination_path":"executed-b-agent-research/B002/00014B-EventBaseConstructorDestructor-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/00014B-EventBaseConstructorDestructor-empty-emitter-source-quality.md","timestamp":"2026-07-12T23:29:59-04:00","uid":"00014B"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
