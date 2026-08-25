** TARGET-REPORT-UID:00032L **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID00032L Crc16WordBuffer Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: implemented. [UID:00032J] `Crc16` remains owner/emitter and `NexusTK/util/Crc16.cpp` remains the narrow source placement; UID00032L and the directly affected family now emit externally linked free functions over two private writable tables.
- Final disposition: applied. UID00032L remains the exact reconstructable source-bearing child at `0x0049bc10-0x0049bc47`; its formal source calls `Crc16WordStep`, and the binary recurrence is documented as the optimized inline expansion of that source call.
- Required action: B002's accepted C01-C20 implementation, scoped validation, lease release, final waited generated refresh, and generated-family verification are complete. Current or future report validation, execution, path, count, move, archive, and downstream lifecycle state are external validator-owned state and are not asserted or directed here.
- Confidence: high for bytes, range, behavior, types, polynomial family, static-image liveness, ownership, and source placement; medium-high for external function linkage and descriptive names because original symbols are absent.

## Supporting Research

- On 2026-07-12, evidence collection used streamable MCP database session `bf5519ae`. At that observation time, `server_health` returned `ok`, imagebase `0x400000`, completed auto-analysis, initialized Hex-Rays, and a ready string cache. This is an evidence-time observation, not an assertion of later session availability.
- The observed IDB was `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; the input image was `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- Historical B001 work created the exact child split and [UID:00032J] owner. Historical B001 UID00032K and B002 UID00032M reports refreshed individual step helpers but did not exhaust the full-image RVA/raw-offset liveness, table mutability, exact polynomial generation, external-linkage survival, or source-call-versus-inline questions assigned here.
- External source-shape research was used only as corroborating inference, not as original NexusTK source proof. Debian's NuLib `Crc16.c` preserves the 1986 Satchell/Forsberg `updcrc` lineage and the exact `0x1021` table values; SRecord's `crc16.cc` documents the equivalent non-augmented MSB-first update shape. Neither source proves NexusTK identifiers or ownership.

## Target

- Target UID: `00032L`.
- Target path: `by-memory/0x0049bc10-0x0049bc47.Crc16WordBuffer.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `by-memory` -> `Not-Covered Files - Reconstructable`.
- Supervisor classification at callback start: Gate 1 accepted implementation callback for exact report SHA256 `CD430E1DA9FF90F417FD6A05801789C52A17B8DDB0BDD2941A8F2B04A1EA5641`.
- Applied scores and parent state: `92/93`; owner/emitter [UID:00032J] `Crc16`; `RECONSTRUCTABLE:TRUE`; `Nested:0`; emitter position `30`.

## Current Target State

- Pre-callback metadata: exact child range and owner/emitter route were correct; scores and evidence depth were incomplete. Callback metadata now matches the accepted score/order matrix.
- Owner/emitter/reconstructable state: retained unchanged as accepted.
- C++/emitter state: all five accepted complete formal blocks are installed. Tables emit first at `10`; externally linked K/L/M/N functions follow at `20/30/40/50`.
- Resolved blockers: original names remain explicit confidence-capped inferences; full raw liveness and false-positive disposition are present; CRC wording is polynomial-family precise; source-call/inlining is resolved; dead-retained external linkage is documented; and writable `.data` tables replace the superseded const draft.
- Related target/support docs checked: UIDs `00032J`, `00032K`, `00032M`, `00032N`, `00027A`, `000225`, MapPane checksum table UID `00027N`, generated `auto-generated/NexusTK/util/Crc16.cpp`, executed B001 reports for UIDs `000225` and `00032K`, executed B002 report for UID `00032M`, project structure guidance, tracker references, and current source tree documentation.
- Artifact/lifecycle boundary: B002 callback work is complete. No current or future validator-owned report path, count, validation, execution, move, archive, or downstream lifecycle state is asserted by this artifact.

## Executive Recommendation

- Applied: retained the narrow [UID:00032J] `Crc16` owner and `NexusTK/util/Crc16.cpp` source route.
- Applied: retained all four exact code children as reconstructable and [UID:000225] as a non-emitting aggregate/index.
- Applied: changed the four formal function drafts from file-static to external-linkage free functions, preserving the evidence-backed survival/inlining rationale.
- Applied: retained descriptive `Crc16WordStep`, `Crc16WordBuffer`, `Crc16ByteStep`, and `Crc16ByteBuffer` names with explicit inferred-name caps.
- Applied: changed the two tables from `extern const` objects to private writable `static unsigned short` arrays `s_crc16WordTable` and `s_crc16ByteTable`; emitter order is `10/20/30/40/50`.
- Applied: UID00032L is `92/93`; every accepted support score is applied. No page claims `95+` or original symbol proof.

## Supervisor Active Recheck

- Historical triggering instruction: start report-only UID00032L and resolve raw-helper liveness, full CRC-family source shape, naming/types, and every score/C++ blocker using IDB session `bf5519ae`; Gate 1 then accepted the exact pre-callback report SHA recorded above.
- Split repair: no new split is required. The existing four exact code children and three internal padding spans cover the aggregate without overlap or omission.
- Source-bearing inventory: UIDs `00032K`, `00032L`, `00032M`, `00032N`, and table UID `00027A` all have the accepted complete formal changes applied. UID `000225` remains intentionally blank because it is an aggregate only.

## Inference Research Guidance Check

- `by-structure.md` requires binary evidence to outrank generated labels and requires generated output to remain a projection, not source authority. The analysis therefore treated `word_66D480`, `word_66D680`, pre-callback `k*` names, and pre-callback generated `static` linkage as provisional; the accepted callback superseded the latter two source-shape assumptions.
- Existing assumptions treated as uncertain: exact CRC variant name, original function/table spelling, `const` table type, file-static linkage, and the statement that the buffer source necessarily delegated to the step helper.
- Direct IDA/PE facts, documentation evidence, and inference are separated throughout. The external-linkage/helper-call recommendation is inference from survival, layout, optimization, and period source shape; it is not a recovered symbol.
- No Wave2/Wave3 artifact was used as authority. Searches for `UID00032L`, `0x0049bc10`, `Crc16WordBuffer`, `updcrc`, and `crccalc` found the executed family reports and tracker history described above; stale generated output was checked only as current projection state.

## Heuristic / Inference Reanalysis And Validation

- Raw-helper role: exact prologue, two stack arguments, zero seed, unsigned loop, table recurrence, and `retn` prove a callable word-buffer helper despite no IDA function object.
- Calling convention: frame-based stack arguments at `[ebp+8]` and `[ebp+0Ch]`, caller stack cleanup (`retn`, not `retn 8`), and scalar EAX return support a 32-bit `__cdecl`-compatible free function. No explicit convention keyword is needed because project/default C++ `__cdecl` is source-shaped.
- Types: `[ebp+8]` is read-only and indexed at scale two, so `const unsigned short*`; `[ebp+0Ch]` is compared with `jb`, so `unsigned int`; table entries and input elements are 16-bit unsigned; the return is zero-extended from `CX` into EAX and semantically `unsigned short`.
- Zero/invalid behavior: `count == 0` returns zero without dereferencing the pointer. Any positive count reads the pointer. An enormous unsigned count is not guarded and follows normal 32-bit index wrap/undefined source preconditions.
- CRC identity: both 256-word tables exactly match the MSB-first polynomial `0x1021` generation table. The byte recurrence is the historical non-augmented high-byte update form. The word recurrence XORs all 16 input bits, so it is a project word-symbol extension, not a standard byte-only CRC-16 variant. Use `CRC-16/0x1021-style` or `CRC-16 polynomial family`, not an unqualified claim that the word result is standard CCITT/XMODEM output.
- Helper call versus inline expression: UID00032L contains no call instruction; the recurrence is physically inlined. The immediately preceding standalone UID00032K body performs the same update against the same table, and the byte pair has the same step/buffer arrangement. The highest-probability human source calls the step helper and was inlined by optimization. A macro or duplicated expression remains machine-equivalent but is weaker because it does not explain the paired externally emitted step bodies as directly.
- Liveness: no static image route reaches any of the four starts. Full xref, code/data/immediate, absolute-VA, RVA, raw-file-offset, and direct relative E8/E9 checks were negative. The one `0x0009bbf0` byte hit is the displacement field of a call at `0x0041dd8b` to `0x004b9980`, not a pointer to UID00032K.
- Export/public meaning: the PE export directory is empty. "External linkage" here means source/linker visibility within the program build, not DLL export or proven public API use. The functions are dead-retained in this image.
- Static versus external linkage: external function linkage best explains emission of all four optimized bodies despite zero image references. Private table linkage best explains each table's exclusive use by one local function pair. Exact original linkage remains inferred, so confidence remains below final-source certainty.
- Table constness: both arrays occupy PE `.data`, whose section characteristics are writable (`0xc0000040`); `.rdata` exists separately and is read-only. `extern const` is therefore a poor source reconstruction. `static unsigned short` preserves initialized writable storage and private use.
- Source placement: code adjacency, exclusive table xrefs, duplicate pair structure, and rejected feature owners continue to support one narrow `Crc16.cpp` utility unit.
- Historical pre-callback generated output: a read-only observation of `auto-generated/NexusTK/util/Crc16.cpp` at validator command `000000008520`, refresh timestamp `2026-07-12T19:03:53-04:00`, found exactly one marker each for UIDs 00032K, 00032L, 00032M, 00032N, and 00027A, with zero UID00032L Empty Emitter Markers. That superseded projection emitted code in address order with `extern const` declarations and `static` functions. The accepted callback applied explicit emitter positions so private table definitions precede function bodies without artificial external declarations; final generated proof is in `Validator Results`.
- Rejected names: do not adopt IDA labels `word_66D480`/`word_66D680`; do not claim historical `updcrc`/`crccalc` as originals; do not rename to MapPane, packet, zlib, or LodePNG semantics.
- Rejected types: do not use signed `short*`, signed count, `wchar_t*`, or byte count for UID00032L. `wchar_t` is machine-width compatible in this binary but has no semantic evidence; `unsigned short` is the least assumptive exact type.
- Rejected ownership: MapPane, Zlib, LodePNG, Crasher, and critical-section/Monitor neighbors remain rejected by separate xrefs, algorithm families, padding, and no caller bridge.

## Evidence Standards Used

- Evidence types: MCP health/survey, raw bytes, bounded instruction decoding, function lookup, xrefs, code/data/immediate searches, absolute pointer searches, table reads, section permissions, PE headers, export directory, full-file VA/RVA/raw-offset scans, full `.text` E8/E9 target decoding, existing by-* docs, executed reports, generated source, and period primary/source-code references.
- Strength: range, behavior, polynomial, table identity, section mutability, and static-image liveness are direct and exhaustive for the supplied image. Linkage and exact source spelling remain inference because symbols and callers are absent.
- Evidence ladder: direct binary facts outrank existing docs; exclusive data relationships and paired layout support source grouping; historical source patterns refine human source shape but do not override binary facts.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed: `idb_list`, `server_health`, `survey_binary`, `lookup_funcs`, `get_bytes`, bounded `insn_query`, `xrefs_to`, `find` for code/data/immediate routes, `find_bytes`, `entity_query`, `get_global_value`, and table reads with `database='bf5519ae'`.
- PE/manual checks performed: section table and characteristics, empty export directory, full-image VA/RVA/raw-offset patterns, decoded full-`.text` direct E8/E9 destinations, exact file offsets, table SHA256/equality, and generated `0x1021` table comparison.
- Docs/reports checked: target, all CRC siblings, table page, aggregate, owner, MapPane table, proposed source tree, generated Crc16.cpp, executed B001 UID000225/UID00032K reports, executed B002 UID00032M report, tracker mentions, and report/workflow standards.
- External corroboration checked: `https://sources.debian.org/src/nulib2/3.1.0-5/nufxlib/Crc16.c`, `https://sources.debian.org/src/srecord/1.64-2/srecord/crc16.cc/`, and historical Satchell/Forsberg recurrence references. These establish period naming/algorithm shape only.
- Negative checks performed: no target/family IDA functions, xrefs, callers, code refs, data refs, immediates, absolute pointers, usable RVAs, raw offsets, direct calls/jumps, exports, feature bridge, table writes, or additional table consumers.
- Failed/unavailable/intentionally skipped: raw helpers cannot be decompiled without mutating the IDB into function objects; mutation was unnecessary and not authorized. Runtime tracing cannot prove execution because no route exists. Compiler-identical source recovery is impossible without the original toolchain/options/symbols, so the report recommends the strongest behavior-identical source shape and records the residual linkage/name inference.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID00032L is exactly `0x0049bc10-0x0049bc47`, body length 55, ending with `retn` at `0x0049bc46`. | Certain | bytes/instructions/padding | target `Status`, `IDA Evidence`, `Boundaries`, callback section | incorporated | applied and validator-verified |
| C02 | Args are `const unsigned short*` then `unsigned int`; return is `unsigned short`; default `__cdecl` shape. | High | stack accesses, scale two, `jb`, `retn`, EAX zero extension | target `Behavior`, `Draft C++ Notes`, formal block | incorporated | applied and generated-verified |
| C03 | Zero count returns zero without dereference; positive count iterates exactly `count` words. | Certain | control flow | target `Behavior`, callback section | incorporated | applied and verified |
| C04 | Recurrence is table[crc high byte] XOR shifted crc XOR full 16-bit input. | Certain | disassembly | target `Behavior`, formal C++ | incorporated | applied and generated-verified |
| C05 | Machine code contains an inlined recurrence and no call. | Certain | instructions | target `Draft C++ Notes`, callback section | incorporated | applied and verified |
| C06 | Source-level call to UID00032K is the highest-probability human source and optimizer inlining explains C05. | Medium-high | paired leaf/buffer bodies, external survival, period source shape | target, owner, aggregate, byte buffer | incorporated | applied and generated-verified |
| C07 | No static image route reaches any of the four helper starts. | High | all xref/pointer/immediate/raw/direct-branch checks | target and all family support | incorporated | applied and verified |
| C08 | The only family RVA-pattern hit is a relative-call displacement false positive, not a pointer. | Certain | raw offset `0x1d18c`, call decode at `0x41dd8b -> 0x4b9980` | target, word step, aggregate, owner | incorporated | applied and verified |
| C09 | PE export directory is empty; helpers are not exported. | Certain | PE data directory | target, steps/buffers, aggregate, owner | incorporated | applied and verified |
| C10 | External function linkage is more probable than file-static linkage; helpers are dead-retained in this image. | Medium-high | optimized body survival, zero routes, no exports | four helper docs and owner | formal linkage changed | applied and generated-verified |
| C11 | Tables have exactly two xrefs each, one from their step and one from their buffer. | Certain | MCP xrefs | target, table, aggregate, owner, siblings | incorporated | applied and verified |
| C12 | Tables are byte-identical 512-byte arrays, SHA256 `ea5f177f22d32b7e80c132b498ee4b92882484f891f43f1897075f28bb3da4d9`. | Certain | raw bytes/hash | table, owner, aggregate, children | incorporated | applied and verified |
| C13 | Every table entry exactly matches MSB-first polynomial `0x1021` generation. | Certain | generated comparison | target, table, owner, aggregate, siblings | incorporated | applied and verified |
| C14 | Word update is a 16-bit symbol extension and must not be labeled an exact standard byte CRC variant. | High | input width and recurrence | target and full family docs | incorporated | applied and verified |
| C15 | Tables are initialized writable `.data`, not `const` `.rdata`. | Certain | PE sections/permissions | table, step docs, owner, aggregate | type/formal code changed | applied and generated-verified |
| C16 | Retain descriptive function names; replace `k*` table names with private mutable `s_*` names. | Medium-high | absent symbols, project style, storage type | five formal blocks and owner | inferred names applied | applied and generated-verified |
| C17 | Emit table at position 10, then K/L/M/N at 20/30/40/50. | High | dependency/order/buildability | UIDs 00027A, 00032K-L-M-N | metadata applied | generated order verified |
| C18 | Owner/emitter/reconstructable/split remain correct. | High | family layout and docs | all directly affected docs | retained | applied and validator-verified |
| C19 | Target should be `92/93`; support scores move proportionally. | High | blocker audit | target/support score sections | scores applied | all validator-verified |
| C20 | UID000225 stays non-emitting; no new child, ignored range, coverage row, or third-party import is needed. | Certain | exact inventory/workflow | aggregate and support | retained/documented | applied; generated target non-empty and aggregate absent |

## Positive Evidence Summary

- Direct facts: clean callable body, exact unsigned loop, exact 16-bit recurrence, exclusive table xref, exact `0x1021` table, and clean padding boundaries.
- Corroboration: the adjacent word-step and byte step/buffer pair reproduce the same family structure; generated output and existing owner docs route exactly those children together.
- Strongest inference chain: four optimized standalone bodies + no image routes + paired inline recurrence + exclusive private tables supports externally linked utility functions whose step calls were inlined, retained as dead code in the linked executable.

## IDA MCP Facts

- Function/range facts: `lookup_funcs` returns no function at `0x49bbf0`, `0x49bc10`, `0x49bc50`, or `0x49bc70`; `0x49bcb0` is the next modeled function.
- Data/table/padding facts: UID00032L bytes are `55 8b ec 56 8b 75 0c 33 c0 33 d2 85 f6 74 25 57 8b 7d 08 0f b7 c8 c1 e9 08 c1 e0 08 66 8b 0c 4d 80 d4 66 00 66 33 0c 57 42 66 33 c8 0f b7 c1 3b d6 72 e0 5f 5e 5d c3`; preceding padding is three `cc` bytes and following padding is nine `cc` bytes.
- Xref facts: `0x66d480` refs are exactly `0x49bbff`, `0x49bc2c`; `0x66d680` refs are exactly `0x49bc5f`, `0x49bc92`.
- Vtable/global/type facts: no name exists in the helper range; the only nearby named global in the table query was unrelated `lpText` at `0x66d478`; tables are in writable `.data`.
- Negative IDA facts: zero helper-start xrefs and no modeled call graph; no additional table users or writes.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x49bbf0-0x49bc0d` | UID00032K WordStep | one 16-bit symbol update | TRUE | UID00032J | `85/90 -> 90/92` | formal linkage/table name/order repair |
| `0x49bc0d-0x49bc10` | padding | 3 bytes `cc` | no | aggregate only | n/a | retain ignored/alignment |
| `0x49bc10-0x49bc47` | UID00032L WordBuffer | zero-seeded unsigned word buffer | TRUE | UID00032J | `86/90 -> 92/93` | assigned target repair |
| `0x49bc47-0x49bc50` | padding | 9 bytes `cc` | no | aggregate only | n/a | retain ignored/alignment |
| `0x49bc50-0x49bc70` | UID00032M ByteStep | one byte update | TRUE | UID00032J | `88/91 -> 90/92` | formal linkage/table name/order repair |
| `0x49bc70-0x49bca9` | UID00032N ByteBuffer | zero-seeded signed-positive byte buffer | TRUE | UID00032J | `86/90 -> 90/92` | formal linkage/table name/order repair |
| `0x49bca9-0x49bcb0` | padding | 7 bytes `cc` | no | aggregate only | n/a | retain ignored/alignment |
| `0x66d47c-0x66d880` | UID00027A tables | 4-byte prefix + two 512-byte arrays | TRUE | UID00032J | `88/92 -> 92/93` | writable/static/order repair |
| aggregate | UID000225 | family index | FALSE | NONE | `88/91 -> 92/93` | remain non-emitting |
| source owner | UID00032J Crc16 | narrow util file | owner | FILE | `86/88 -> 91/92` | retain path, expand family evidence |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x49bbf0` | none | no static-image word-step entry route |
| `0x49bc10` | none | no static-image target entry route |
| `0x49bc50` | none | no static-image byte-step entry route |
| `0x49bc70` | none | no static-image byte-buffer entry route |
| `0x66d480` | reads at `0x49bbff`, `0x49bc2c` | private to word pair |
| `0x66d680` | reads at `0x49bc5f`, `0x49bc92` | private to byte pair |
| false RVA hit | raw `0x1d18c`, loaded `0x41dd8c` | displacement bytes of call `0x41dd8b -> 0x4b9980`, rejected as pointer |

## Documentation Evidence And IDA Status

- Supporting docs correctly identify the four-child split, narrow owner, table pairing, and rejected feature owners.
- Stale/incomplete content: generic score rationales, current `static` function code, `extern const` tables, unqualified CRC-CCITT wording, and incomplete liveness/source-shape analysis.
- Generated/coverage state: evidence-time generated `NexusTK/util/Crc16.cpp` had one emitter for each source-bearing child and no aggregate emission. It is read-only evidence; no refresh was run.

## Ranked Ownership Analysis

### 1. UID00032J Crc16 in NexusTK/util/Crc16.cpp

- Evidence for: exact compact family; exclusive paired tables; no feature bridge; established owner/emitter; human utility source shape; generated route exists.
- Evidence against: original filename/symbols are not recovered and all functions are dead-retained.
- Decision: retain. The absent runtime route affects liveness/confidence, not source-family coherence.

### 2. Parent-blank dead code

- Evidence for: zero callers and zero image routes.
- Evidence against: discards the strong code/table unit and breaks existing source emission despite complete behavior.
- Decision: reject. Dead-retained source can still be reconstructed under its direct utility owner.

### 3. MapPane or third-party/neighbor owner

- Evidence for: MapPane has a separate table with the same polynomial opening; adjacent code belongs to other modules.
- Evidence against: MapPane table has separate consumers; no helper bridge exists; zlib/LodePNG use different checksum families; Crasher/critical-section ranges are padding-separated and semantically unrelated.
- Decision: reject.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new file; retain `NexusTK/util/Crc16.cpp` and proposed `Crc16.h` declarations.
- Likely full contents: two private writable tables plus four externally linked free functions.
- Candidate related items rejected: MapPane table, zlib/LodePNG CRC support, adjacent Crasher and synchronization wrappers.
- Standalone/narrow/broad inference: narrow standalone utility file.

## Source Placement

- Recommended placement: table definitions and all four functions in `NexusTK/util/Crc16.cpp`; externally linked function declarations may live in `NexusTK/util/Crc16.h` when header reconstruction is modeled.
- Fit: pure algorithmic utility behavior, no object/class state, no feature caller, and existing source-tree route.
- Rejected placements: MapPane.cpp, Crasher.cpp, Monitor/critical-section source, Zlib, LodePNG, or aggregate-only emission.
- Remaining uncertainty: exact original filename and whether declarations were in a header are not symbol-proven.

## Range / Split / Padding / Reclassification Analysis

- Exact facts: code and padding inventory is complete in the table above; no boundary correction is needed.
- Children: retain four exact reconstructable children. No merge or new child.
- Padding/data/code distinctions: retain 3-, 9-, and 7-byte `cc` spans as alignment; retain UID00027A's 4-byte zero prefix as non-emitting alignment/unused storage before the first table.
- Parent/container impact: UID000225 stays `RECONSTRUCTABLE:FALSE`, blank formal body, owner none, and index-only.

## Negative Evidence Summary

- Full-image checks found no xref, pointer, immediate, RVA, raw offset, relative branch, export, vtable, callback registration, or feature route to UID00032L or its siblings.
- Table similarity alone does not connect this family to MapPane.
- Address adjacency alone does not connect it to Crasher or synchronization wrappers.
- Period source recurrence does not prove exact NexusTK names or third-party import identity.
- The empty export directory means external linkage must not be described as exported API.

## IDA Rename / Type / Comment Recommendations

- Source-facing function names: retain descriptive `Crc16WordStep`, `Crc16WordBuffer`, `Crc16ByteStep`, `Crc16ByteBuffer`; label all inferred.
- Source-facing table names: replace const-signaling `kCrc16WordTable`/`kCrc16ByteTable` with private mutable `s_crc16WordTable`/`s_crc16ByteTable`.
- Types: target `const unsigned short* words`, `unsigned int count`, `unsigned short` return; word step `(unsigned short value, unsigned short crc)`; byte step `(unsigned char value, unsigned short crc)`; byte buffer `(const unsigned char* bytes, int count)`.
- Comments: document `0x1021` MSB-first polynomial table, zero seed, non-augmented update shape, and full-16-bit word extension. Do not state exact standard CRC output equivalence.
- Intentionally unchanged: no `wchar_t`, no historical `updcrc` rename, no feature name, no explicit `__cdecl` keyword.
- IDA DB edits: not requested and unnecessary for documentation reconstruction; do not mutate function/name/type state during callback.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. All five source-bearing pages are reconstructable and have a complete behavior-preserving source shape.
- Recommended target code for UID00032L:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
unsigned short Crc16WordBuffer(const unsigned short* words, unsigned int count)
{
    unsigned short crc = 0;
    for (unsigned int i = 0; i < count; ++i) {
        crc = Crc16WordStep(words[i], crc);
    }
    return crc;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Recommended UID00032K support code:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
unsigned short Crc16WordStep(unsigned short value, unsigned short crc)
{
    const unsigned int tableIndex = crc >> 8;
    return static_cast<unsigned short>((crc << 8) ^ s_crc16WordTable[tableIndex] ^ value);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Recommended UID00032M support code:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
unsigned short Crc16ByteStep(unsigned char value, unsigned short crc)
{
    const unsigned int tableIndex = crc >> 8;
    return static_cast<unsigned short>((crc << 8) ^ s_crc16ByteTable[tableIndex] ^ value);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Recommended UID00032N support code:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
unsigned short Crc16ByteBuffer(const unsigned char* bytes, int count)
{
    unsigned short crc = 0;
    for (int i = 0; i < count; ++i) {
        crc = Crc16ByteStep(bytes[i], crc);
    }
    return crc;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Recommended UID00027A support code:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#define CRC16_1021_TABLE_VALUES \
    0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7, \
    0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef, \
    0x1231, 0x0210, 0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6, \
    0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c, 0xf3ff, 0xe3de, \
    0x2462, 0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485, \
    0xa56a, 0xb54b, 0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d, \
    0x3653, 0x2672, 0x1611, 0x0630, 0x76d7, 0x66f6, 0x5695, 0x46b4, \
    0xb75b, 0xa77a, 0x9719, 0x8738, 0xf7df, 0xe7fe, 0xd79d, 0xc7bc, \
    0x48c4, 0x58e5, 0x6886, 0x78a7, 0x0840, 0x1861, 0x2802, 0x3823, \
    0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969, 0xa90a, 0xb92b, \
    0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50, 0x3a33, 0x2a12, \
    0xdbfd, 0xcbdc, 0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a, \
    0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41, \
    0xedae, 0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49, \
    0x7e97, 0x6eb6, 0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70, \
    0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78, \
    0x9188, 0x81a9, 0xb1ca, 0xa1eb, 0xd10c, 0xc12d, 0xf14e, 0xe16f, \
    0x1080, 0x00a1, 0x30c2, 0x20e3, 0x5004, 0x4025, 0x7046, 0x6067, \
    0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c, 0xe37f, 0xf35e, \
    0x02b1, 0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214, 0x6277, 0x7256, \
    0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d, \
    0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405, \
    0xa7db, 0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e, 0xc71d, 0xd73c, \
    0x26d3, 0x36f2, 0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634, \
    0xd94c, 0xc96d, 0xf90e, 0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab, \
    0x5844, 0x4865, 0x7806, 0x6827, 0x18c0, 0x08e1, 0x3882, 0x28a3, \
    0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a, \
    0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1, 0x1ad0, 0x2ab3, 0x3a92, \
    0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b, 0x9de8, 0x8dc9, \
    0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1, \
    0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8, \
    0x6e17, 0x7e36, 0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1, 0x1ef0

static unsigned short s_crc16WordTable[256] = {
    CRC16_1021_TABLE_VALUES
};

static unsigned short s_crc16ByteTable[256] = {
    CRC16_1021_TABLE_VALUES
};

#undef CRC16_1021_TABLE_VALUES
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive: not applicable. The recurrence has historical analogues, but no vetted exact third-party source identity covers NexusTK's four-function/two-table word-and-byte family.
- Exact behavior: integer promotion plus final `unsigned short` conversion preserves the low 16-bit recurrence; buffer loops preserve zero seed and signedness; distinct arrays preserve binary storage and xrefs.
- Mid-2000s source shape: simple free functions, C-era scalar types, private initialized tables, and optimizer-inlined helper calls fit the binary better than templates, classes, modern fixed-width headers, or decompiler labels.
- Naming/style: PascalCase descriptive function names and `s_` private writable table names match project reconstruction conventions. They remain inferred.
- No-code proof: not applicable; all source-bearing family items have formal code. UID000225 remains blank because duplicate aggregate emission would be incorrect.

## Final Recommendation

- Exact changes applied: C01-C20, target `92/93`, all support scores, `10/20/30/40/50` positions, five complete formal blocks, complete family evidence, precise polynomial wording, exhaustive dead-retained liveness, source-call/inlining, and superseded-assumption history.
- Exact parent assignments applied: owner/emitter UID00032J retained for UIDs 00032K-L-M-N and 00027A; FILE ownership retained for UID00032J.
- Exact items left no-owner/non-emitting: UID000225 remains owner-none/non-reconstructable with a blank block; alignment spans and UID00027A's four-byte prefix remain non-emitting support bytes.
- Future evidence boundary: original debug symbols or an exact source release could refine function/table spelling and header declarations. No accepted callback item remains unapplied.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0049bc10-0x0049bc47.Crc16WordBuffer.md`.
- Facts incorporated: exact bytes, signature/convention, zero-count behavior, unsigned loop, recurrence, inlined machine body/source helper-call inference, exhaustive no-route proof, dead-retained external-linkage inference, polynomial-family qualification, writable table dependency, source placement, rejected alternatives, and evidence-time MCP qualification.
- Metadata/C++ applied: `86/90 -> 92/93`; emitter position `30`; owner/emitter/reconstructable/range/nested unchanged; complete accepted formal block installed.
- Preservation verified: historical no-xref evidence, original-name caveat, owner alternatives, exact disassembly, and padding remain; generic "at least 85" and unqualified CRC-16/CCITT claims are explicitly superseded.

## Recommended Support Doc Changes

- `by-memory/0x0049bbf0-0x0049bc0d.Crc16WordStep.md`: applied `85/90 -> 90/92`, position `20`, external-linkage formal block, mutable table name, full liveness and polynomial/source-shape rationale; historical B001 evidence retained and time-scoped.
- `by-memory/0x0049bc50-0x0049bc70.Crc16ByteStep.md`: applied `88/91 -> 90/92`, position `40`, external-linkage formal block, mutable table name, and source-shape/liveness qualification; prior B002 evidence retained as historical evidence-time observation.
- `by-memory/0x0049bc70-0x0049bca9.Crc16ByteBuffer.md`: applied `86/90 -> 90/92`, position `50`, external-linkage formal block and inline/source-call disposition; signed-positive count semantics retained.
- `by-memory/0x0066d47c-0x0066d880.ChecksumLookupTablesData.md`: applied `88/92 -> 92/93`, position `10`, complete formal block, `.data` writability, equality hash, polynomial generation, exclusive xrefs, and four-byte prefix disposition.
- `by-file/Crc16.md`: applied `86/88 -> 91/92` and the exact source-unit shape, linkage/liveness, table, no-export, inlining, polynomial-family, and generated-order contract.
- `by-memory/0x0049bbf0-0x0049bca9.ChecksumTableHelpers.md`: applied `88/91 -> 92/93`; retained owner-none/non-reconstructable/blank state; added complete family evidence and removed the superseded body-only sketch while preserving its historical intent in prose.
- Generated/coverage/tracker/project-structure files: not manually edited. Validator-owned side effects and the final generated readback are recorded below.

## Score And Metadata Recommendation

- Pre-callback target: `86/90`, owner/emitter `00032J`, reconstructable true, blank emitter position, formal code present.
- Applied target: `92/93`, same owner/emitter/reconstructable/range/nesting, emitter position `30`, revised formal code.
- Why higher: every assigned blocker now has direct evidence or an implementation-ready inference: exact boundaries, all route classes, false-positive disposition, table identity/polynomial/mutability, unsigned behavior, convention/signature/return, source helper-call/inlining, dead-retained linkage, owner/source placement, naming/types, full family, and generated order.
- Why not higher: exact original names/linkage/header declarations and runtime history are unavailable. External function linkage is high-probability inference, not symbol proof.
- Score-improvement attempts: each blocker is itemized in C01-C20 and the heuristic section; none is deferred as "needs investigation."
- Fields unchanged: UID, owner, emitter, reconstructable, range, and nesting. Fields changed and validator-confirmed: score, emitter position, formal code, summary/body evidence. Support changes are exact above.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Best resolution | Residual impact |
| --- | --- | --- | --- |
| Exact original function names? | IDA names, strings, docs, reports, generated output, web source analogues | retain descriptive current names; reject historical spellings as proof | confidence cap only |
| Exact original table names? | IDA labels, section/type, project naming style | use `s_crc16WordTable`/`s_crc16ByteTable` | confidence cap only |
| Static or external functions? | optimization shape, four-body survival, zero refs, no exports, period compiler behavior | external source linkage, dead-retained, not exported | inferred; confidence cap |
| Helper call or duplicated recurrence? | no call instruction, paired standalone leaf, byte pair, historical update helper shape | source helper call inlined by optimizer | macro/duplication remains machine-equivalent but weaker |
| Exact CRC variant? | all 256 table entries, recurrence, seed, input widths, source references | `0x1021` MSB-first family; byte non-augmented update; word extension nonstandard | prevents overclaim, no C++ blocker |
| Runtime/computed caller? | exhaustive static image routes and empty exports | no supported route; dead-retained in this image | cannot disprove arbitrary runtime computation, but no evidentiary basis |
| Table constness/linkage? | `.data` RW, separate `.rdata`, exclusive xrefs | private writable static arrays | resolved |
| `unsigned short` or `wchar_t` words? | operand width/extension and absent text semantics | `unsigned short` is exact and least assumptive | resolved |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. No manual coverage/tracker text is needed. Target `Item Summary` and `Nested` metadata are the validator-supported source for generated coverage.

## Follow-Up Actions

- B002 completion record: accepted C01-C20 incorporation, seven scoped page validations, two temporal-wording revalidations, all lease releases, final waited generated refresh, and generated-family verification are complete. No unapplied B002 item remains.
- External lifecycle boundary: current or future report path, report count, validation, execution, move, archive, and downstream assignment state are external validator-owned state and are not asserted or directed by this artifact.
- A-agent scope record: no A-agent action was part of this callback.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `92/93` target and medium-high for proportional support scores.
- Remaining uncertainty: original identifier spelling, exact source linkage/header declaration proof, and historical runtime use before this image was linked.

## Validator Results

- UID00027A: command `000000008555`, timestamp `2026-07-12T19:21:53-04:00`, scoped file apply, exit `0`, `ok:1`; applied `92/93`, emitter position `10`, and formal-code registry hash; generated refresh deferred.
- UID00032K: command `000000008556`, timestamp `2026-07-12T19:22:35-04:00`, exit `0`, `ok:1`; applied `90/92`, position `20`, and formal-code registry hash; generated refresh deferred.
- UID00032L: command `000000008557`, timestamp `2026-07-12T19:23:21-04:00`, exit `0`, `ok:1`; applied `92/93`, position `30`, and formal-code registry hash; generated refresh deferred.
- UID00032M: command `000000008558`, timestamp `2026-07-12T19:24:07-04:00`, exit `0`, `ok:1`; applied `90/92`, position `40`, and formal-code registry hash; generated refresh deferred.
- UID00032N: command `000000008559`, timestamp `2026-07-12T19:24:41-04:00`, exit `0`, `ok:1`; applied `90/92`, position `50`, and formal-code registry hash; generated refresh deferred.
- UID000225: command `000000008560`, timestamp `2026-07-12T19:25:29-04:00`, exit `0`, `ok:1`; applied `92/93` while preserving blank/non-emitting metadata; generated refresh deferred.
- UID00032J and initial waited refresh: command `000000008574`, timestamp `2026-07-12T19:26:59-04:00`, exit `0`, `ok:1`, `generated_refresh:completed`; applied `91/92`. Broad existing generated diagnostics were 17 fallback inserts, 81 missing-child-marker notices, and 220 no-code emitters; none was Crc16-target-specific.
- Temporal-wording revalidation: UID00032K command `000000008577`, timestamp `2026-07-12T19:28:06-04:00`, exit `0`, `ok:1`, generated refresh deferred; UID000225 command `000000008578`, timestamp `2026-07-12T19:28:29-04:00`, exit `0`, `ok:1`, final `--wait-generated` refresh completed. The second passes only time-scoped preserved historical evidence and did not change scores or formal code.
- Final generated readback: `auto-generated/NexusTK/util/Crc16.cpp` retained header command `000000008577` / timestamp `2026-07-12T19:28:06-04:00` because the final waited command produced no later Crc16 body delta. Read-only verification found marker order `00027A, 00032K, 00032L, 00032M, 00032N`; exactly one marker per item; one definition each for both tables and all four functions; zero old `kCrc16*` names, `extern const` table declarations, or static Crc16 function definitions; zero duplicate UID00032L body; and zero UID00032L Empty Emitter Markers.
- Validator-owned side effects observed, not manually edited: registry/reference state, projected statistics, generated metadata/C++, research tracker, and memory coverage updates. No target-specific validator warning or error remains.

## Changed Files

- Historical creation path: `tools/leaser/Agents/Agent-B002/research/00032L-Crc16WordBuffer-source-quality.md`. This records where B002 created the artifact and does not assert its current or future lifecycle path.
- Modified manually during the accepted callback:
  - `by-memory/0x0066d47c-0x0066d880.ChecksumLookupTablesData.md`
  - `by-memory/0x0049bbf0-0x0049bc0d.Crc16WordStep.md`
  - `by-memory/0x0049bc10-0x0049bc47.Crc16WordBuffer.md`
  - `by-memory/0x0049bc50-0x0049bc70.Crc16ByteStep.md`
  - `by-memory/0x0049bc70-0x0049bca9.Crc16ByteBuffer.md`
  - `by-memory/0x0049bbf0-0x0049bca9.ChecksumTableHelpers.md`
  - `by-file/Crc16.md`
  - this report
- Renamed: none.
- Leases: each `by-*` file was leased individually immediately before edit and released immediately after its validator. UID00032K and UID000225 received a second short lease for temporal-wording repair/revalidation. Every lease/unlease returned `Success`; final lease-report readback found no B002 row.
- Validator-owned side effects: generated, coverage, tracker, registry/reference, and projected-statistics files changed only through scoped validators; B002 did not edit them manually.
- Report execution: not run. B002 ran no execute-report, lifecycle, move, archive, or equivalent command.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation. Proof: Gate 1 passed exact SHA256 `CD430E1DA9FF90F417FD6A05801789C52A17B8DDB0BDD2941A8F2B04A1EA5641`.
- [x] Target/support docs identified. Proof: UID00032L target plus UIDs 00032K, 00032M, 00032N, 00027A, 00032J, and 000225 were the only manual `by-*` destinations.
- [x] Current target state and actual evidence recorded. Proof: target callback section carries exact C01-C20 range/signature/behavior/liveness/table/source-shape facts.
- [x] Claim And Incorporation Ledger updated. Proof: C01-C20 all identify applied destinations and verification state.
- [x] Metadata/score changes applied. Proof: exact score and emitter-order matrix appears in docs, validator results, and generated markers.
- [x] Score-limiting blockers researched. Proof: liveness, false pointer, table identity/type, variant, linkage, naming, source call, source placement, and generated blockers are closed or confidence-capped.
- [x] Owner/emitter/reconstructable dispositions confirmed. Proof: accepted UID00032J routes remain; UID000225 stays owner-none/non-reconstructable.
- [x] Split/rename/new-child disposition confirmed. Proof: no split/new child; descriptive function names retained; mutable table names applied.
- [x] Source placement/range/padding/reclassification and IDA disposition completed. Proof: source order/type/linkage applied; exact padding retained; no IDA mutation.
- [x] First-draft C++ applied. Proof: all five exact managed blocks installed and generated once each.
- [x] Third-party import directive checked. Proof: not applicable; no exact third-party source identity.
- [x] Exact target/support facts incorporated. Proof: C01-C20 ledger applied across all seven docs at report-level detail.
- [x] Historical/stale assumptions/rejections preserved. Proof: prior static/const/unqualified-variant/owner-open claims are labeled superseded; prior evidence remains time-scoped.
- [x] Wave2/Wave3 handling completed. Proof: none used as authority.
- [x] Open questions resolved/documented. Proof: only original names/linkage/header/runtime history remain confidence caps.
- [x] Validators run. Proof: commands `000000008555`-`000000008560`, `000000008574`, `000000008577`, and `000000008578` all exited `0` with `ok:1`.
- [x] Generated refresh completed. Proof: final waited command `000000008578` and read-only table-first family verification recorded above.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation. Proof: exact Gate 1 SHA above.
- [x] All accepted target/support details incorporated at report-level detail. Proof: seven callback sections plus owner source-unit contract.
- [x] Ledger updated to applied/verified states. Proof: C01-C20 contain no pre-implementation verification state.
- [x] Metadata/score/linkage/order/C++ applied. Proof: exact accepted matrix and generated definitions verified.
- [x] Historical/stale assumptions and negative evidence preserved. Proof: superseded labels and time-scoped prior evidence remain in every affected area.
- [x] Open questions remain correctly confidence-capped. Proof: no unresolved item blocks source, scores, or generated output.
- [x] Scoped validators run and exact results recorded. Proof: command/timestamp/result details above.
- [x] Final waited generated refresh and read-only verification completed. Proof: command `000000008578` plus exact marker/definition/empty-marker counts.
- [x] Remaining unapplied accepted items listed. Proof: none; C01-C20 are fully applied.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000008605","destination_path":"executed-b-agent-research/B002/00032L-Crc16WordBuffer-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/00032L-Crc16WordBuffer-source-quality.md","timestamp":"2026-07-12T19:36:05-04:00","uid":"00032L"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
