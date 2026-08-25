** TARGET-REPORT-UID:000295 **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# UID000295 g_pDirectX Source-Quality Report


## Finalized Report / Current Recommendation

[UID:000295] `by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md` is the exact four-byte writable `.data` storage for the process-wide `DirectX` singleton pointer. MCP session `ddf5b602` confirmed the target is not code, starts as zero, has exactly 19 direct xrefs / 19 VA operand-pattern hits, is written and cleared by the `DirectX` constructor/destructor/compiler cleanup paths, and is consumed by render/surface helpers. At report-only time, the page was correctly owned by [UID:0000QS] `by-global/g_pDirectX.md` but still emitted as an empty marker even though `DirectX.cpp` already used `g_pDirectX` in emitted constructor/destructor code. After the implementation callback, UID000295 is source-ready at `90/92` and generated `DirectX.cpp` emits the single formal definition.

Final disposition: UID000295 is source-ready as a declaration-only global definition and keeps the semantic owner as [UID:0000QS] `g_pDirectX`. Current target metadata is `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000QS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000QS`, blank target `EMITTER_POSITION_OPTIONAL`, with exact formal C++:

```cpp
class DirectX;

DirectX *g_pDirectX = NULL;
```

Support route: [UID:0000QS] `by-global/g_pDirectX.md` is now the ordered source route under [UID:0000IW] `DirectX.cpp` through a `[[CHILDREN]]` formal block and `EMITTER_POSITION_OPTIONAL:0`, so the UID000295 child definition appears before `DirectX::DirectX()` uses it. The definition is not duplicated in both by-global and by-memory.

## Supporting Research

Lifecycle/status: B009 report artifact in `tools/leaser/Agents/Agent-B009/research/` after accepted implementation callback. Target/support by-* docs were edited only under leases during callback; scoped validators were run for changed by-* files. B009 did not manually edit generated files, coverage reports, validator state, lifecycle/archive state, report moves, or supervisor ledgers, and did not run `execute_report`.

MCP/session status: current IDA MCP session `ddf5b602` is active and IDB-backed for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. `server_health` returned `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.

Pre-callback generated-output state: `auto-generated/NexusTK/render/DirectX.cpp` header was validator command `000000006422`, refreshed `2026-07-04T18:25:08-04:00`. It emitted [UID:00003Y] `DirectX` class declaration and [UID:000137] constructor/destructor source that read/wrote `g_pDirectX`, but [UID:0000QS] `g_pDirectX` and [UID:000295] exact storage were still `Empty Emitter Marker` comments. That historical state proved source use without the corresponding storage definition. Post-callback generated output now emits UID000295 once as `DirectX *g_pDirectX = NULL;`.

Prior reports searched and used as leads: B001 `000294-g_pApplication-source-quality.md`, B014 `000137-DirectX-source-quality.md`, B003 `00023S-SurfaceDirectDrawCopyHelper-source-quality.md`, B005/B002 `00039R-SurfaceDirectDrawRestoreMaintenance-source-quality.md`, B012 `00039T-SurfaceDrawTilePresentation-source-quality.md`, and related GrafPort/Surface reports. The prior reports confirm DirectX ownership and consumer boundaries, but none is a direct executed report for UID000295.

## Target

- UID: `000295`
- Target path: `by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md`
- Assignment-time metadata: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000QS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000QS`, blank optional emitter position.
- Current metadata after callback: `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000QS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000QS`, blank optional emitter position.
- Assignment-time formal C++: blank.
- Current formal C++ after callback: `class DirectX;` plus `DirectX *g_pDirectX = NULL;`.
- Assignment-time generated state: empty emitter marker in `auto-generated/NexusTK/render/DirectX.cpp`.
- Current generated state after callback: single UID000295 definition before `DirectX::DirectX()`, no UID000295 empty marker.
- Semantic owner: [UID:0000QS] `by-global/g_pDirectX.md`.
- Source-file root: [UID:0000IW] `by-file/DirectX.md`, projected to `NexusTK/render/`.
- Class/type context: [UID:00003Y] `by-class/DirectX.md`.

## Current Target State

The target page already records the correct high-level identity: `0x0067ab20-0x0067ab24` is `dword_67AB20` / `unk_67AB20`, the `DirectX *g_pDirectX` singleton pointer between adjacent [UID:000294] `g_pApplication` at `0x0067ab1c` and [UID:0001P2] `g_pFontImageLib` at `0x0067ab24`.

At assignment time, the remaining source-quality gap was not ownership. The gap was final source emission and ordering. Pre-callback generated `DirectX.cpp` used `g_pDirectX` in `DirectX::DirectX()` and `DirectX::~DirectX()`, but the exact storage page and by-global parent both emitted only empty markers. The implementation callback resolved that gap by emitting the exact child definition through the ordered by-global route.

The old A002 initializer caveat is now fully resolved by two independent current-ish evidence passes: B001 session `80de0a67` and B009 session `ddf5b602` both read `00 00 00 00` / `0x0` at `0x0067ab20`. The historical `0xffffffff` observation should remain historical/stale unless a later current session reproduces it.

## Evidence Checked

Current docs checked:

| Document | Evidence used |
| --- | --- |
| `by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md` | Assignment-time metadata, blank formal C++, existing ownership, xref list, initializer-history caveat, consumer notes; post-callback metadata/formal C++ are recorded in Target and checklist sections. |
| `by-global/g_pDirectX.md` | Semantic global owner, DirectX file route, lifetime writes/clears, consumer-versus-owner distinction, alias warning. |
| `by-file/DirectX.md` | `NexusTK/render/` source root, proposed contents, `g_pDirectX` as module global, source-quality exclusions. |
| `by-class/DirectX.md` | Class declaration, `m_pDirectDraw`, constructor/destructor inventory, `[[CHILDREN]]` route, compiler-glue exclusion. |
| `by-memory/0x004a1b60-0x004a1d6a.DirectX.md` | Existing constructor/destructor C++, lifetime writes/clears, unwind helper/scalar deleting destructor proof. |
| `auto-generated/NexusTK/render/DirectX.cpp` | Pre-callback generated output used `g_pDirectX` but left UID0000QS and UID000295 empty markers; post-callback output emits UID000295 once before `DirectX::DirectX()`. |
| `auto-generated/-ag-research-tracker.md` | Assignment-time tracker context placed UID000295 in not-covered reconstructable by-memory queue at `86/88`, while adjacent UID000294 had executed B001 coverage. |
| `auto-generated/-ag-memory-coverage.md` and `auto-generated/-ag-global-coverage.md` | UID000295 and UID0000QS route to `NexusTK/render/DirectX.cpp` but lack emitted source code. |

Searches performed with `rg`: `000295`, `g_pDirectX`, `0x0067ab20`, `67AB20`, `DirectX *g_pDirectX`, `extern DirectX *g_pDirectX`, and related DirectX/render/source-family terms across `tools/leaser/Agents`, `executed-b-agent-research`, `by-*`, `auto-generated`, and `project-level` inputs. Relevant prior reports are listed in Supporting Research.

MCP evidence checked:

| MCP id | Tool | Result |
| ---: | --- | --- |
| `1` | `initialize` | MCP initialized, server `ida-pro-mcp`, protocol `2025-06-18`. |
| `2` | `idb_list` | Active session `ddf5b602`, `NexusTK.exe.i64`, `is_analyzing:false`, worker pid `20820`. |
| `3` | `server_health` | `status:ok`, Hex-Rays ready, auto-analysis ready, strings cache ready. |
| `4` | `tools/list` | Current schema checked; data tools require `regions`, `queries`, `addrs`, and `patterns`. |
| `5` | `lookup_funcs` | `0x0067ab18`, `0x0067ab1c`, `0x0067ab20`, and `0x0067ab24` are not functions; DirectX functions at `0x004a1b60`, `0x004a1c60`, `0x004a1cc0`, `0x004a1cd0` are modeled with sizes `0xf6`, `0x5c`, `0xb`, `0x9a`. |
| `15` | `get_bytes` | `0x0067ab18` size 16 and `0x0067ab20` size 4 read all zero bytes. |
| `16` | `get_global_value` | `dword_67AB20`, `unk_67AB20`, and `0x0067ab20` all read `0x0`. |
| `17` | `xrefs_to` | Exactly 19 xrefs to `0x0067ab20`, `more:false`, including DirectX lifetime sites and render/surface consumers. |
| `18` | `find_bytes` | VA pattern `20 AB 67 00` has 19 matches; RVA-style pattern `20 AB 27 00` has 0 matches. |
| `19-22` | `disasm` | Constructor stores/zeroes target; destructor, helper, and scalar deleting wrapper clear it. |
| `23-26` | `decompile` | Hex-Rays confirms constructor publishes `unk_67AB20`, destructor clears it, helper only clears it, and scalar deleting wrapper clears it as compiler wrapper. |
| `27`, `29`, `30` | `disasm` | Representative consumers load the pointer in application cleanup / render-surface paths; raw helper `0x00559a10` reads both `g_pApplication` and `g_pDirectX`. |

## Evidence Standards Used

IDA MCP facts are authoritative for current bytes, values, direct xrefs, non-function/function boundaries, operand-pattern route checks, disassembly, decompiler behavior, and representative consumer instruction shape.

Current by-* docs are authoritative for project ownership state, generated routing, file/class context, and existing source-quality decisions unless current MCP directly contradicts them. In this pass, current MCP agrees with DirectX ownership and supersedes only the historical `0xffffffff` initializer caveat.

Generated output is read-only evidence. It proves the current source draft uses `g_pDirectX` before any emitted definition appears and that UID000295 remains an empty marker. Generated files were not edited.

Prior B reports are lead evidence only. B001 gives the best adjacent singleton pattern; B014 gives DirectX constructor/destructor source shape and notes the need for `extern DirectX *g_pDirectX`, but neither replaces the current UID000295 MCP pass.

Inference confidence caps remain for exact original spelling and header exposure: `g_pDirectX` is project-canonical/source-facing, but the original symbol is not recovered from PDB; `NULL`, `0`, and implicit zero are binary-equivalent; the exact header declaration location is not recoverable from this four-byte storage slot alone.

## Heuristic / Inference Reanalysis And Validation

Storage and initializer: UID000295 is source-declared writable global storage, not padding, not a function, and not linker-only data. Current MCP reads four zero bytes and `0x0`, so the rebuilt source should define zero-initialized pointer storage. The exact source token is inferred; `NULL` is the best first draft because adjacent UID000294 uses `NULL`, current generated project source uses Win32-era pointer style, and `nullptr` would be anachronistic for the source style.

Name and type: `DirectX *g_pDirectX` is the best source-facing name/type. The pointer is written by `DirectX` lifetime code and consumers dereference `+4` as the stored DirectDraw interface (`m_pDirectDraw`). DirectX class/file/global docs consistently use `g_pDirectX`; IDA labels remain `unk_67AB20` / `dword_67AB20` evidence labels, not source names.

Ownership and route: semantic ownership should stay with [UID:0000QS] `by-global/g_pDirectX.md`, whose owner/emitter is [UID:0000IW] `DirectX.cpp`. The exact storage page should still carry the formal definition because it alone represents the four-byte memory range. The by-global page should order/include its child rather than duplicate the definition. This preserves by-structure separation: global semantic page owns the concept, exact memory page owns the source bytes, DirectX file owns the source module.

Ordering: the generated definition must appear before `DirectX::DirectX()` because current constructor source uses `g_pDirectX = this;`. The safest implementation plan is to make [UID:0000QS] the ordered parent in `DirectX.cpp` with `EMITTER_POSITION_OPTIONAL:0` and a `[[CHILDREN]]` formal block, then place UID000295's definition as the child. A validator-supported equivalent direct ordering is acceptable, but duplicate definitions are not.

No-code alternative rejected: leaving UID000295 blank or only marker-covered is no longer sufficient. The target is exact source-owned data, has current bytes/value, a valid owner/emitter route, and current generated source uses the symbol. The only remaining uncertainties are style/header exposure, which do not block a definition-only global.

## Positive Evidence Summary

- Exact range: half-open `0x0067ab20-0x0067ab24`, four-byte pointer slot in writable `.data`.
- Current bytes/value: MCP id `15` reads `00 00 00 00`; id `16` reads `0x0` for names/address.
- Non-code: MCP id `5` reports `Not a function` for the target and adjacent slots `0x0067ab18`, `0x0067ab1c`, and `0x0067ab24`.
- Direct xrefs: MCP id `17` reports exactly 19 xrefs and `more:false`.
- Operand route: MCP id `18` reports 19 VA pattern hits for `20 AB 67 00` and zero RVA-style hits for `20 AB 27 00`.
- Lifetime writes/clears: constructor writes `this` or zero at `0x004a1ba2`/`0x004a1ba9`; ordinary destructor clears at `0x004a1c9d`; helper clears at `0x004a1cc0`; scalar deleting wrapper clears at `0x004a1d14`.
- Consumer evidence: application cleanup reads the pointer at `0x00464b44`; render/surface consumers include `0x004b8d78`, `0x004b92bc`, `0x004b9800`, `0x004bb83f`, `0x00556b22`, `0x00556b77`, `0x005574a0`, `0x005576d0`, `0x005583d0`, `0x00558875`, `0x00558b24`, and raw helper `0x00559a63`.
- Source placement: `by-file/DirectX.md`, `by-class/DirectX.md`, `by-global/g_pDirectX.md`, and generated `DirectX.cpp` agree that this belongs to the DirectX/render source family.

## Negative Evidence Summary

- No PDB/original symbol proves the exact spelling `g_pDirectX`; it is inferred but project-canonical and consistently documented.
- Bytes cannot distinguish `= NULL`, `= 0`, or implicit zero. `NULL` is recommended as best project-era first draft, not original-token proof.
- Current evidence does not recover exact header exposure. Cross-file consumers need an `extern DirectX *g_pDirectX;` declaration somewhere, but this target should emit only the single storage definition.
- `0x0067ab24` is adjacent `g_pFontImageLib`, not part of this target. Font/text-layout aliases are rejected for UID000295.
- Render/surface/GrafPort/ScreenPane helpers are consumers; they do not own the global definition.
- The constructor-unwind helper and scalar deleting destructor are compiler output. They prove cleanup semantics but should not be emitted as standalone source functions.
- Leaving the target as no-code/empty-marker is rejected because source-owned storage, route, value, and use are all known.

## Ranked Ownership Analysis

| Rank | Candidate | Decision | Evidence for | Evidence against / limits |
| ---: | --- | --- | --- | --- |
| 1 | [UID:0000QS] `by-global/g_pDirectX.md` semantic owner, emitting through [UID:0000IW] `DirectX.cpp` | Accepted | by-structure places process-wide singleton pointers in `by-global`; DirectX constructor/destructor own lifetime; file route already exists. | Needs source-ready `[[CHILDREN]]`/ordering support so target child emits before constructor use. |
| 2 | [UID:0000IW] `by-file/DirectX.md` direct file owner | Source root only | DirectX.cpp is final source file and owner of wrapper/lifetime. | Too broad as canonical owner; by-global page is the existing direct semantic owner. |
| 3 | [UID:00003Y] `by-class/DirectX.md` class static | Rejected as canonical storage owner | Class methods write/clear the slot. | Binary/source shape is a free absolute global, not proven `DirectX::s_*`; consumers use a process global. |
| 4 | Surface/GrafPort/ScreenPane/render consumers | Rejected | Many xrefs read `g_pDirectX->m_pDirectDraw`. | They consume DirectDraw state but do not publish or clear the singleton. |
| 5 | Adjacent globals / `.data` container | Rejected | Physical neighborhood contains other singleton pointers. | Xrefs and writers separate `g_pApplication`, `g_pDirectX`, and `g_pFontImageLib`; section container is not the source owner. |
| 6 | `CANONICAL_OWNER:NONE`, blank emitter/no-code | Rejected | Would avoid style/header uncertainty. | Too weak: source-owned storage, DirectX lifetime, route, and formal definition are all established. |

## Source Placement

Final source placement should remain `NexusTK/render/DirectX.cpp`. The declaration is a file/module global associated with the DirectX DirectDraw bootstrap wrapper. It should not move to Surface, GrafPort, ScreenPane, a broad render helper file, or a `.data` aggregate page.

Recommended emitted source order in `DirectX.cpp`:

1. UID0000QS global parent position `0`, using `[[CHILDREN]]`.
2. UID000295 exact child definition:
   `class DirectX;`
   `DirectX *g_pDirectX = NULL;`
3. UID00003Y `DirectX` class declaration.
4. UID000137 constructor/destructor bodies that use `g_pDirectX`.

This order preserves behavior and plausible C++ visibility without inventing a header file from a data-slot target.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. UID000295 is `RECONSTRUCTABLE:TRUE`, has a valid emitter route, has current MCP byte/value/xref/lifetime evidence, and represents exactly one source-level global pointer definition.

Exact formal insertion text for the target:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class DirectX;

DirectX *g_pDirectX = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Behavior preservation: the definition creates zero-initialized writable pointer storage. `DirectX::DirectX()` publishes `this`; destructor, unwind helper, and scalar deleting wrapper clear the slot; consumers load the same storage.

Rejected C++ forms:

- `extern DirectX *g_pDirectX;` alone: this is needed for consumers/headers but does not define the storage represented by UID000295.
- `static DirectX *g_pDirectX`: rejects broad cross-module xrefs and generated external uses.
- `DirectX *g_pDirectX;` with no initializer: binary-equivalent, but less explicit than the accepted adjacent `g_pApplication` style.
- `DirectX *g_pDirectX = 0;`: binary-equivalent but less consistent with current project-era `NULL` style.
- `nullptr`: anachronistic for the inferred source era and current project style.
- Putting the definition in both UID0000QS and UID000295: duplicate source definition.

## Score And Metadata Recommendation

Recommended target metadata:

```text
COMPLETION:90
CONFIDENCE:92
CANONICAL_OWNER:0000QS
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000QS
EMITTER_POSITION_OPTIONAL:
```

Completion moves from `86` to `90` because this pass resolves the remaining source-quality blockers: current MCP confirms zero bytes/value, no-function state, exact xref/operand count, lifetime writers/clearers, source placement, generated empty-marker gap, and implementation-ready C++ definition.

Confidence moves from `88` to `92` because current MCP, target/support docs, adjacent singleton precedent, DirectX constructor/destructor output, and generated route all agree. Confidence remains below `95` because exact original symbol spelling, exact initializer token, and exact header exposure are inferred rather than recovered.

Recommended support metadata:

- [UID:0000QS] `by-global/g_pDirectX.md`: consider `COMPLETION:90`, `CONFIDENCE:90`, keep `CANONICAL_OWNER:0000IW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000IW`, set `EMITTER_POSITION_OPTIONAL:0`, and add formal `[[CHILDREN]]` so UID000295 emits before DirectX methods.
- [UID:0000IW] `by-file/DirectX.md` and [UID:00003Y] `by-class/DirectX.md`: no score change required unless supervisor wants the now-source-ready global route reflected there.

## Final Recommendation

Approve implementation callback for UID000295. Apply the target formal C++ definition, raise target score to `90/92`, preserve by-global ownership, and update `g_pDirectX` support routing so generated `DirectX.cpp` contains a single `DirectX *g_pDirectX = NULL;` definition before `DirectX::DirectX()`.

Do not leave the target blank, do not mark it covered only by UID000137, do not move canonical ownership to Surface/GrafPort/ScreenPane, do not merge it with adjacent globals, and do not manually edit generated output.

## Recommended Target Doc Changes

Target path: `by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md`

Required target changes if accepted:

- Set metadata to `COMPLETION:90`, `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:0000QS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000QS`, blank `EMITTER_POSITION_OPTIONAL`.
- Insert the exact formal C++ block from `First-Draft C++ Recommendation`.
- Update item summary/status/evidence with current MCP session `ddf5b602`: active IDB, health OK, zero bytes/value, no-function at adjacent slots, 19 xrefs, 19 VA operand hits / zero RVA hits, constructor/destructor/helper/deleting-wrapper write/clear sites, representative consumers, and generated empty-marker gap.
- Historicalize the old `0xffffffff` initializer observation as superseded by current B001/B009 zero-value evidence.
- Preserve rejected alternatives: font singleton/`g_pFontImageLib` aliasing, Surface/GrafPort/ScreenPane ownership, DirectX class-static storage, no-owner/no-code, duplicate by-global definition, raw IDA labels, and compiler helper/scalar deleting destructor as handwritten source.

## Recommended Support Doc Changes

Support path: `by-global/g_pDirectX.md`

- Make this page source-ready as the semantic global parent for UID000295.
- Keep owner/emitter route through [UID:0000IW] `DirectX.cpp`.
- Set `EMITTER_POSITION_OPTIONAL:0` or use an equivalent validator-supported ordering mechanism so the child definition precedes `DirectX::DirectX()`.
- Add exact formal parent block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Record current session `ddf5b602` evidence and state that UID000295 carries the single storage definition; by-global must not duplicate it.

Support path: `by-file/DirectX.md`

- Add a short source-layout note if stale: `g_pDirectX` now emits through the ordered by-global/child route before class/method bodies in `NexusTK/render/DirectX.cpp`; DirectX.cpp owns the DirectDraw wrapper and singleton definition, while Surface/GrafPort/ScreenPane remain consumers.
- No file metadata change required.

Support path: `by-class/DirectX.md`

- Already has class declaration, `m_pDirectDraw`, `[[CHILDREN]]`, and constructor/destructor support. Optional sync only if wording still implies the global is merely an unresolved `extern`; state that UID000295 defines storage and headers/consumers need an `extern DirectX *g_pDirectX` declaration elsewhere.
- No class metadata change required.

Support path: `by-memory/0x004a1b60-0x004a1d6a.DirectX.md`

- Already present at same-or-greater detail for constructor/destructor/helper/scalar deleting destructor behavior. Optional sync only if generated output after callback still lacks the global definition before method bodies.

Support path: `by-memory/0x0066d000-0x0069d000.DataSection.md`

- Optional child-work note only if stale: UID000295 is now source-ready as `DirectX *g_pDirectX = NULL;`, with exact neighboring singleton boundaries preserved. Keep the data-section container non-emitting.

## Open Questions With Attempted Resolution

| Question | Attempted resolution | Result |
| --- | --- | --- |
| Is UID000295 code or data? | MCP `lookup_funcs` on target and adjacent slots; bytes/value reads. | Resolved: exact writable data slot, not function code. |
| Is the initializer zero or `0xffffffff`? | Current B009 MCP `get_bytes`/`get_global_value` and earlier B001 session both checked target. | Resolved for current evidence: zero bytes/value; old `0xffffffff` is historical/stale. |
| Should the target emit C++? | Checked by-structure gate, assignment-time metadata, emitter route, generated empty marker, adjacent UID000294 precedent. | Yes. It should emit a declaration-only definition. |
| Should by-global or by-memory own the actual definition? | Compared by-structure roles and current route. | Exact by-memory page should carry the definition; by-global should provide semantic ownership/order/children route and not duplicate code. |
| Should `EMITTER_UIDS` change to DirectX file directly? | Considered direct file route to fix ordering. | Not preferred. Keep `EMITTER_UIDS:0000QS`; fix by-global ordering/children route so ownership remains precise. |
| Is `NULL` proven original? | Compared bytes, adjacent UID000294, generated source style. | Not proven; recommended as best first draft. `0` or implicit zero are binary-equivalent but less consistent. |
| Is header exposure recovered? | Checked generated output and B014 support note. | Not fully. This target defines storage only; support docs can mention consumers require `extern DirectX *g_pDirectX`. |

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-000295-01 | UID000295 is exact four-byte `g_pDirectX` storage at `0x0067ab20-0x0067ab24`. | High | MCP ids `5`, `15`, `16`; target docs. | Target summary/evidence. | incorporate | applied: target summary/evidence now records exact range, no-function data-slot proof, zero bytes/value, and source-ready storage role. Validator `000000006448`, exit `0`, `ok:1`. |
| C-000295-02 | Current initializer/value is zero, not `0xffffffff`. | High | MCP `get_bytes` id `15`; `get_global_value` id `16`; B001 session `80de0a67`. | Target evidence/history; by-global support. | incorporate / historicalize | applied: target and by-global support record B009 zero-byte/value evidence and keep old `0xffffffff` as historical/stale. Validators `000000006448` and `000000006449`, both exit `0`, `ok:1`. |
| C-000295-03 | The target has exactly 19 direct xrefs and 19 VA operand hits; RVA pattern has zero hits. | High | MCP `xrefs_to` id `17`; `find_bytes` id `18`. | Target evidence. | incorporate | applied: target evidence records 19 xrefs, `more:false`, 19 `20 AB 67 00` VA hits, and zero `20 AB 27 00` RVA hits. |
| C-000295-04 | DirectX constructor/destructor/helper/deleting wrapper own writes/clears. | High | MCP ids `19-26`; by-memory UID000137. | Target evidence; by-global lifetime evidence; DirectX support. | incorporate | applied: target and by-global lifetime evidence record constructor stores, destructor clear, helper clear, and scalar-wrapper clear; by-file/by-class support notes link the source-ready singleton route. |
| C-000295-05 | Render/surface/application cleanup refs are consumers, not owners. | High | MCP id `17`; representative disasm ids `27`, `29`, `30`; support reports/docs. | Target negative evidence; by-global support. | incorporate | applied: target/by-global evidence preserve application cleanup, ScreenPane restore, and raw Surface copy helper as consumer/dependency routes, not owners. |
| C-000295-06 | Formal target C++ should be `class DirectX;` plus `DirectX *g_pDirectX = NULL;`. | Medium-high | Zero storage, valid route, adjacent UID000294 precedent, generated use without definition. | Target formal `RECONSTRUCTION_CPP CODE`. | incorporate | applied: target formal block now contains exactly `class DirectX;` plus `DirectX *g_pDirectX = NULL;`; validator `000000006448` updated autogen registry from blank to block. |
| C-000295-07 | By-global should order/include the target child and avoid duplicate definition. | Medium-high | Current generated `DirectX.cpp` marker order; by-global route; by-structure emitter rules. | `by-global/g_pDirectX.md` formal block/position/source notes. | incorporate | applied: `by-global/g_pDirectX.md` now has `EMITTER_POSITION_OPTIONAL:0`, formal `[[CHILDREN]]`, and explicit no-duplicate-definition notes; validator `000000006449`, exit `0`, `ok:1`. |
| C-000295-08 | Target score should rise from assignment-time `86/88` to `90/92`. | Medium-high | Current MCP closes initializer/no-code/output blockers; remaining caveats are style/header only. | Target metadata and score rationale. | incorporate | applied: target metadata now `COMPLETION:90`, `CONFIDENCE:92`; validator `000000006448` reported `completion_update:1`, `confidence_update:1`. |
| C-000295-09 | Font singleton / `g_pFontImageLib` aliasing remains rejected for this slot. | High | Adjacent address docs, xrefs to `0x0067ab24`, target xref/byte evidence. | Target negative evidence; support alias warning. | incorporate / already-present | applied/already-present: target reconstruction notes reject `g_pFontImageLib` aliasing for this slot; by-global and DirectX file/class docs already carried the adjacent-font alias warning at same-or-greater detail. |
| C-000295-10 | Generated `DirectX.cpp` should no longer leave UID000295 as an empty marker after callback. | High | Pre-callback generated file header `000000006422` and empty marker state. | Validator/generated freshness expectation. | incorporate | applied: latest observed generated `auto-generated/NexusTK/render/DirectX.cpp` header during final check is `validator-command-id: 000000006467`, refreshed `2026-07-04T19:07:58-04:00`; UID000295 emits `DirectX *g_pDirectX = NULL;` once before `DirectX::DirectX()`, and UID000295 is no longer an empty marker. |

## Implementation Tracking Checklist

- [x] Update `by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md` metadata to `COMPLETION:90`, `CONFIDENCE:92`; keep owner/reconstructable/emitter/position as recommended. Proof: target metadata is `90/92`, `CANONICAL_OWNER:0000QS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000QS`, blank optional position; validator `000000006448`.
- [x] Insert exact formal C++ block into the target:
  `class DirectX;`
  blank line
  `DirectX *g_pDirectX = NULL;`
  Proof: target formal block contains the exact insertion text and no additional code.
- [x] Incorporate current MCP session `ddf5b602` evidence into target: session health, bytes/value, no-function state, xrefs, byte-pattern route, writer/clear sites, representative consumers, generated empty-marker state. Proof: target evidence records each fact at report-level detail.
- [x] Historicalize stale `0xffffffff` initializer wording as superseded by current zero-value evidence. Proof: target evidence/change log and by-global lifetime evidence distinguish B001/B009 zero evidence from historical A002 observation.
- [x] Preserve rejected alternatives: `g_pFontImageLib` alias, Surface/GrafPort/ScreenPane ownership, class static member, no-owner/no-code, duplicate by-global definition, raw IDA labels, compiler helper/scalar deleting destructor source. Proof: target reconstruction notes, by-global ownership decision, and by-file/by-class support notes preserve these exclusions.
- [x] Update `by-global/g_pDirectX.md` as source-ready parent route: ordered before DirectX methods, formal `[[CHILDREN]]`, no duplicate direct definition, current evidence and target child definition note. Proof: by-global metadata now `90/90`, `EMITTER_POSITION_OPTIONAL:0`, formal block `[[CHILDREN]]`; validator `000000006449`.
- [x] Inspect/update `by-file/DirectX.md`, `by-class/DirectX.md`, `by-memory/0x004a1b60-0x004a1d6a.DirectX.md`, and `by-memory/0x0066d000-0x0069d000.DataSection.md` only where stale; otherwise mark already-present in this ledger. Proof: by-file and by-class were updated with source-ready singleton route notes; UID000137 already had constructor/destructor/helper/scalar-wrapper detail at same-or-greater level and was not edited; DataSection was read-only checked and left unedited because it has no contradiction and remains a non-emitting section container.
- [x] Run scoped validators for every changed by-* file after implementation callback, from `source-3/project-documentation`, and record command, command_id, command_timestamp, exit, ok, warnings, and generated refresh state. Proof: validator table below records `000000006448`, `000000006449`, `000000006450`, and `000000006452`.
- [x] Check generated `auto-generated/NexusTK/render/DirectX.cpp` freshness after validators. Expected output: one definition `DirectX *g_pDirectX = NULL;` appears before `DirectX::DirectX()`, and UID000295 is no longer an empty emitter marker. UID0000QS should not duplicate the definition. Proof: latest observed generated header during final check `000000006467`, refreshed `2026-07-04T19:07:58-04:00`; output has UID0000QS comment, UID000295 comment, one `DirectX *g_pDirectX = NULL;`, then UID00003Y class and UID000137 methods.
- [x] Update this report's ledger/checklist after callback with `applied`, `already-present`, `excluded-with-reason`, or `blocked` proof. Proof: ledger/checklist updated in this report.

## Validator Results

Scoped validators run from `source-3/project-documentation` after by-* edits:

| File | Command | command_id | command_timestamp | Exit | ok | Notes |
| --- | --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md` | `python .\tools\validator.py --mode file --file by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md --apply --queue-timeout 240` | `000000006448` | `2026-07-04T19:02:30-04:00` | `0` | `1` | `completion_update:1`, `confidence_update:1`, `autogen_registry_update:2`, `uid_link_update:1`, known `missing_ref_uid 00039R:3`, `generated_refresh: deferred`. |
| `by-global/g_pDirectX.md` | `python .\tools\validator.py --mode file --file by-global/g_pDirectX.md --apply --queue-timeout 240` | `000000006449` | `2026-07-04T19:02:41-04:00` | `0` | `1` | `completion_update:1`, `confidence_update:1`, `autogen_registry_update:3`, `reference_index_add:1`, known `missing_ref_uid 00039R:3`, `generated_refresh: deferred`. |
| `by-file/DirectX.md` | `python .\tools\validator.py --mode file --file by-file/DirectX.md --apply --queue-timeout 240` | `000000006450` | `2026-07-04T19:02:43-04:00` | `0` | `1` | `reference_index_add:1`, `stats_row_update:1`, known `missing_ref_uid 0003HP/00039R`, `generated_refresh: deferred`. |
| `by-class/DirectX.md` | `python .\tools\validator.py --mode file --file by-class/DirectX.md --apply --wait-generated --queue-timeout 240` | `000000006452` | `2026-07-04T19:02:45-04:00` | `0` | `1` | `generated_refresh: completed`; broad generated warnings elsewhere included `autogen_children_marker_missing:82` and `autogen_emitter_has_no_code:226`; known `missing_ref_uid 0003HP:3`. |

Generated freshness proof: `auto-generated/NexusTK/render/DirectX.cpp` latest observed header during final check shows `validator-command-id: 000000006467`, `validator-refreshed-at: 2026-07-04T19:07:58-04:00`, and `validator-refresh-source: foreground-generated-refresh`. The generated file contains exactly one `DirectX *g_pDirectX = NULL;` under UID000295 before `DirectX::DirectX()`, and UID000295 no longer appears as an empty emitter marker. UID0002MD remains an intentional empty marker.

## Changed Files

Manual edits:

```text
by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md
by-global/g_pDirectX.md
by-file/DirectX.md
by-class/DirectX.md
tools/leaser/Agents/Agent-B009/research/000295-g_pDirectX-source-quality.md
```

Validator-owned generated/project side effects from scoped validators:

```text
auto-generated/NexusTK/render/DirectX.cpp
auto-generated/-ag-class-coverage.md
auto-generated/-ag-file-coverage.md
auto-generated/-ag-function-coverage.md
auto-generated/-ag-global-coverage.md
auto-generated/-ag-item-coverage.md
auto-generated/-ag-memory-coverage.md
auto-generated/-ag-type-coverage.md
project-level/-auto-completion-stats.md
tools/validator_autogen_backup/20260704-190300
tools/validator_autogen_backup/20260704-190304
tools/validator_autogen_backup/20260704-190306
```

No generated files, coverage reports, validator state files, lifecycle/archive files, report moves, or supervisor ledgers were edited manually.

## Follow-Up Actions

Implementation callback is complete and ready for supervisor verification/execution. B009 leased `by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md`, `by-global/g_pDirectX.md`, `by-file/DirectX.md`, and `by-class/DirectX.md` only for the edit/validator batch; all four leases were released successfully and `current_leases.md` showed no B009/UID000295 matches afterward. B009 did not run `execute_report`, dry-run/probing variants, registry/lifecycle/archive commands, or manual report moves.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000006485","destination_path":"executed-b-agent-research/B009/000295-g_pDirectX-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/000295-g_pDirectX-source-quality.md","timestamp":"2026-07-04T19:16:29-04:00","uid":"000295"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
