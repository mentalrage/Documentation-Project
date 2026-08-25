** TARGET-REPORT-UID:0002PM **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002PM LogoPane Cleanup Destructor Source-Quality Report

Assignment: `B002-goal2-logopane-cleanup-destructor-source-quality-0002PM-20260618`  
Primary target: [UID:0002PM] `by-memory/0x004f4eb0-0x004f4f29.LogoPaneCleanupDestructor.md`  
Required output path: `tools/leaser/Agents/Agent-B002/research/0002PM-LogoPaneCleanupDestructor-source-quality.md`  
Report-only status: no by-* docs, generated reports, generated source, IDA database, or `by-memory/-coverage-report.md` were edited.

## Finalized Report / Current Recommendation

- Current recommendation: raise [UID:0002PM] from `82/90` to `88/91`, keep `CANONICAL_OWNER:00007G`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:00007G`, and populate formal C++ with the ordinary `LogoPane::~LogoPane()` source body.
- Final disposition: source-authored ordinary `LogoPane` destructor. The source body releases the embedded logo tile context and explicitly frees live palette data; compiler-generated member/base destructor lowering then destroys `DLPalette` and `Pane`.
- Required action: update [UID:0002PM], update support docs for [UID:00007G] `LogoPane`, [UID:0002PR] scalar deleting destructor, and [UID:0002PQ] destructor thunks, then update the supervisor-owned by-memory coverage rows listed below.
- Confidence: strong. The destructor behavior, range, vtable writes, helper calls, no-direct-caller state, class layout, and source route are all documented by existing IDA-backed pages. Fresh IDA MCP was unavailable in this B002 session, so do not raise above low-90s without a new live byte/xref refresh.

## Supporting Research

## Target

- Target UID: `0002PM`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004f4eb0-0x004f4f29.LogoPaneCleanupDestructor.md`
- Current scores and parent state: `COMPLETION:82`, `CONFIDENCE:90`, `CANONICAL_OWNER:00007G`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007G`, blank formal C++.
- Current emitter route: [UID:0002PM] emits through [UID:00007G] `LogoPane`, which emits through [UID:0000O4] `StartupLogoPanes` to `auto-generated/NexusTK/app/StartupLogoPanes.cpp`.
- Generated output state: `auto-generated/NexusTK/app/StartupLogoPanes.cpp` currently exists but is zero bytes, because the relevant formal C++ blocks are still blank.

## Executive Recommendation

The open source-quality blockers on [UID:0002PM] are resolved well enough for first-draft formal C++:

- `this + 0xf8` should be documented as `EPFTileContext m_logoTileContext`.
- `this + 0x120` should be documented as `DLPalette m_logoPalette`.
- Helper call `0x00458500(this + 0xf8)` should be documented as `m_logoTileContext.ReleaseBuffers()`.
- Helper call `0x00542cd0(this + 0x120)` should be documented as `m_logoPalette.FreePaletteData()`.
- Helper call `0x00542ca0(this + 0x120)` is the compiler/member destructor call `m_logoPalette.~DLPalette()`, not a source line that should be hand-written in the ordinary destructor body.
- Helper call `0x00544580(this)` is the compiler/base destructor call `Pane::~Pane()`, not a source line that should be hand-written in `LogoPane::~LogoPane()`.
- The no-direct-caller evidence should be interpreted as ordinary destructor body / emitted complete-destructor reachability, not as proof that the function is padding, dead generic cleanup, or non-source.

The strongest source representation is:

```cpp
LogoPane::~LogoPane()
{
    m_logoTileContext.ReleaseBuffers();
    m_logoPalette.FreePaletteData();
}
```

The scalar deleting destructor [UID:0002PR] should stay documented and class-owned, but its formal C++ must remain blank. The source representation for that ABI wrapper is the virtual destructor declaration and the ordinary destructor body above. The secondary adjustor thunks [UID:0002PQ] should be reclassified as non-emitting compiler-generated glue, matching the treatment used by other pure destructor thunk pages such as [UID:0001BZ].

## Supervisor Active Recheck

This was a report-only B002 source-quality assignment for one primary target. The target does not require by-structure split repair: it is already an exact function range with alignment before and after, and the surrounding LogoPane island already has exact child pages. I did not lease or edit any by-* file because the user explicitly instructed report-only work.

Fresh IDA MCP was checked through `http://127.0.0.1:13337/mcp` with `tools/list`; the connection failed with `Unable to connect to the remote server`. New recommendations below are therefore based on existing IDA-backed documentation and local generated/coverage reads, not a new IDA live session.

## Inference Research Guidance Check

I treated existing docs as leads, not authority. The key reanalysis used independent support routes:

- Constructor [UID:0002PL] proves initialization and use of `+0xf8` and `+0x120`.
- Static loader [UID:0002PO] proves retained helper use of the same fields and already names `m_logoTileContext` / `m_logoPalette`.
- Scalar destructor [UID:0002PR] proves the same cleanup order plus delete flags and guard size `0x354`.
- Thunks [UID:0002PQ] prove secondary/tertiary `this` adjustors only.
- Pane layout [UID:0001VH] proves derived fields start at `+0xf8`.
- EPFTileContext [UID:00004I]/[UID:0000XY] proves the context is `0x28` bytes and owns `ReleaseBuffers`.
- DLPalette [UID:00003Z]/[UID:0001E4] proves `DLPalette` layout and `FreePaletteData` / destructor split.
- Vtable data [UID:0003OP] proves the three LogoPane table views are source-declared/generated-binary data regenerated from the class declaration.

Fact vs inference:

- Fact from existing IDA-backed docs: range, size, vtable writes, four callee addresses, no direct callers/xrefs, scalar wrapper/thunk relationship, and helper names on supporting pages.
- Strong inference: original source names `m_logoTileContext` and `m_logoPalette` are descriptive source-facing names, not proven original spellings.
- Source-policy inference: formal C++ should express only the ordinary destructor body, while member/base destructor calls, scalar delete flags, and adjustor thunks are compiler lowering.

## Heuristic / Inference Reanalysis And Validation

### `this + 0xf8` Member

- Best source-facing name/type: `EPFTileContext m_logoTileContext`.
- Evidence checked: [UID:0001VH] says `Pane` derived fields begin at `+0xf8`; [UID:0000XY] documents a `0x28`-byte `EPFTileContext` layout; [UID:0002PL] initializes `+0xf8`, writes decoded pixel state at `+0xfc/+0x104/+0x108/+0x118/+0x11c`, and uses the same field for logo image state; [UID:0002PO] names this field `m_logoTileContext` and records retained loader writes; [UID:0002PM]/[UID:0002PR] call `0x00458500` on `this + 0xf8`.
- Rejected alternatives: generic `TileContext` is too vague because the helper page and class owner are explicitly `EPFTileContext`; `LogoImageState` hides the reusable render-support type; raw-buffer fields would lose the existing `EPFTileContext` method evidence.
- Validation: `+0xf8 + sizeof(EPFTileContext 0x28) == +0x120`, exactly where the palette object begins.
- Impact: resolves the target's main member-name blocker and supports formal C++.

### `this + 0x120` Member

- Best source-facing name/type: `DLPalette m_logoPalette`.
- Evidence checked: [UID:00003Z] documents `DLPalette` as `LObject` plus optional data/header and 256 mapped colors; [UID:0001E4] names `0x00542cd0` as `DLPalette::FreePaletteData` and `0x00542ca0` as `DLPalette::~DLPalette`; [UID:0002PL] constructs/populates `+0x120`; [UID:0002PO] loads bitmap palette into `+0x120`; [UID:0002PM]/[UID:0002PR] free/destroy `+0x120`.
- Rejected alternatives: raw `DLPaletteData*` is wrong because destructor calls operate on an object at `this + 0x120`; generic `Palette` is too broad because the method cluster and class page identify `DLPalette`; `m_startupPalette` is plausible but less specific than `m_logoPalette` in the LogoPane class.
- Validation: `DLPalette` visible fields run through `+0x22b`; placing a `DLPalette` at LogoPane `+0x120` reaches LogoPane `+0x34c`, exactly where the LogoPane flags begin. The completion callback pointer at `+0x350` plus four bytes closes at `+0x354`, matching the scalar deleting destructor guard size.
- Impact: resolves the palette member blocker and supports formal C++.

### Destructor Source Declaration

- Best source declaration: `LogoPane::~LogoPane()`.
- Evidence checked: target page says `__thiscall`, receiver in `ecx`, return `void`; the body resets LogoPane vtables and then tears down derived members/base. [UID:0002PR] is the scalar deleting wrapper with flags and optional delete; [UID:0002PQ] secondary thunks adjust `this` and jump to the scalar wrapper.
- Rejected alternatives: `LogoPane::Cleanup()` is weaker because vtable stores and scalar wrapper parity identify destructor lowering; a static helper is wrong because the receiver is a class instance and vtables are restored; writing a `ScalarDeletingDestructor` source method for the target is wrong because that is a separate ABI wrapper.
- Validation: `0x004f4eb0` has the ordinary no-delete destructor shape, while `0x004f5300` adds scalar-delete flag handling and operator delete.
- Impact: formal C++ should be the ordinary destructor, not a helper or ABI wrapper.

### Helper Call Names And Source Body

- `0x00458500`: `EPFTileContext::ReleaseBuffers`, source call `m_logoTileContext.ReleaseBuffers()`.
- `0x00542cd0`: `DLPalette::FreePaletteData`, source call `m_logoPalette.FreePaletteData()`.
- `0x00542ca0`: `DLPalette::~DLPalette`, compiler-generated member destructor call after the destructor body; do not hand-write as a source statement.
- `0x00544580`: `Pane::~Pane`, compiler-generated base destructor call; do not hand-write as a source statement.
- Rejected alternatives: call only `m_logoTileContext.ReleaseBuffers()` and rely solely on `DLPalette::~DLPalette()` is likely behaviorally incomplete because the binary explicitly calls `FreePaletteData` before the member destructor; hand-writing `m_logoPalette.~DLPalette()` or `Pane::~Pane()` is decompiler-shaped C++ and risks double destruction if compiled normally.
- Impact: recommended formal body has exactly two explicit statements.

### No-Direct-Caller / No-Direct-Xref Interpretation

- Evidence checked: [UID:0002PM] records 2026-06-06 `callers` and `xrefs_to 0x004f4eb0` as no direct static references; [UID:0002PR] records vtable/thunk reachability to the scalar wrapper; [UID:0002PQ] records secondary vtable slots pointing to adjustor thunks.
- Best interpretation: the ordinary complete destructor body is source-authored/constructor-compatible code that may be retained for explicit destructor or EH/unwind uses even though normal virtual deletion routes through the scalar deleting wrapper. Absence of direct callers does not disprove source authorship.
- Rejected alternatives: padding is rejected by the full prologue/body/epilogue and member cleanup calls; dead generic cleanup is rejected by exact LogoPane vtable writes and field-specific cleanup; base Pane ownership is rejected because base teardown is only the final callee.
- Remaining caveat: this B002 session could not perform a fresh PE rel32/VA/RVA scan for `0x004f4eb0`. Keep confidence at `91`, not higher.
- Impact: no-direct-caller evidence should remain documented but should no longer block first-draft C++.

### Scalar Deleting Destructor And Thunks

- [UID:0002PR] source policy: document as `source-declared/generated-binary` scalar deleting destructor wrapper, keep `RECONSTRUCTABLE:TRUE` under the current scalar-wrapper convention, keep owner/emitter [UID:00007G], but keep formal C++ blank with an explicit no-code proof.
- [UID:0002PQ] source policy: reclassify to `RECONSTRUCTABLE:FALSE`, blank emitter, and keep owner [UID:00007G] or `NONE` depending on supervisor convention. Best recommendation is owner [UID:00007G], blank emitter, non-reconstructable, because these are pure secondary/tertiary adjustor thunks regenerated from the class declaration.
- Rejected alternatives: hand-writing the thunks or scalar wrapper in C++ is rejected as ABI code; ignoring the pages is rejected because they explain vtable dispatch and adjusted-this destructor routing.
- Impact: primary destructor [UID:0002PM] should carry the source C++; scalar/thunk support pages should not.

### Source Placement

- Best direct owner: [UID:00007G] `LogoPane`.
- Best source module: [UID:0000O4] `StartupLogoPanes`, generated path `NexusTK/app/StartupLogoPanes.cpp`.
- Evidence checked: [UID:0000O4] owns the static LogoPane and LogoPlayerPane startup flow; constructor [UID:0002PL] has a startup caller around `0x004f643c`; target fields and helpers are LogoPane-specific; generated `-ag-memory-coverage.md` routes [UID:0002PM] through [UID:00007G] to `StartupLogoPanes.cpp`.
- Rejected alternatives: `EPFTileContext` and `Palette` own helper classes, not the LogoPane destructor; `Pane` owns the base teardown only; `Application` constructs the startup pane but does not own the class implementation; `VideoPlayerPane` belongs to the LogoPlayerPane/Bink side, not static LogoPane.
- Impact: keep owner/emitter unchanged.

### Generated Output

- Existing state: `auto-generated/NexusTK/app/StartupLogoPanes.cpp` is zero bytes in this local checkout. The route exists but formal C++ is blank.
- Best action: populate [UID:0002PM]'s formal C++ after score/support updates. This will not make `StartupLogoPanes.cpp` complete, but it will stop this eligible destructor page from being a blank source-output gap.
- Rejected alternative: copying generated `class_LogoPane.cpp` or Wave2/Wave3 source is outside this assignment and is not needed for this destructor.

## Evidence Standards Used

- Existing IDA-backed by-memory pages for ranges, sizes, vtables, callees, callers, xrefs, and padding.
- Class/file/type docs for source placement and layout inference.
- Generated `-ag-memory-coverage.md` for current emitter route.
- Manual `by-memory/-coverage-report.md` row for stale score/coverage state.
- Local generated output file size for current zero-byte output state.
- Negative evidence: no direct callers/xrefs for the ordinary destructor in existing IDA docs; no fresh MCP available in this session.

The evidence is strong enough for `88/91` on [UID:0002PM] because the field layout is independently cross-validated by constructor, static-loader, destructor, scalar-wrapper, Pane, EPFTileContext, and DLPalette pages. It is not strong enough for `95+` because fresh MCP/PE scans were unavailable and exact original member spellings remain inferred/descriptive.

## IDA MCP Facts

Fresh facts could not be collected because IDA MCP was unavailable. Existing IDA-backed documentation records these facts:

- `0x004f4eb0` is `sub_4F4EB0`, size `0x79`, half-open range `0x004f4eb0-0x004f4f29`.
- `0x004f4eac-0x004f4eb0` and `0x004f4f29-0x004f4f30` are `0xcc` alignment.
- The destructor writes `LogoPane` vtables `0x0061cf78`, `0x0061cfc4`, and `0x0061cff4`.
- Callees are exactly `0x00458500`, `0x00542cd0`, `0x00542ca0`, and `0x00544580`.
- `callers` and `xrefs_to 0x004f4eb0` report no direct static references.
- Scalar deleting destructor `0x004f5300-0x004f53a8` repeats cleanup and applies scalar-delete flags, optional `0x004f4ac0` delete, and guard size `0x354`.
- Thunks `0x004f52de` and `0x004f52e9` subtract `0xa0` and `0xa4`, then jump to `0x004f5300`.
- Vtable data [UID:0003OP] confirms the three table heads and constructor/destructor/scalar-destructor stores.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score Recommendation | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004f4eb0-0x004f4f29` | [UID:0002PM] `LogoPaneCleanupDestructor` | Ordinary `LogoPane::~LogoPane()` source body plus compiler member/base lowering | `TRUE` | [UID:00007G] | `88/91` | Populate first-draft C++. |
| `0x004f52de-0x004f52f4` | [UID:0002PQ] `LogoPaneDeletingDestructorThunks` | Secondary/tertiary destructor adjustor thunks | Recommend `FALSE` | [UID:00007G] or `NONE` | `86/92` if reclassified | Blank emitter/C++; compiler-generated. |
| `0x004f5300-0x004f53a8` | [UID:0002PR] `LogoPaneScalarDeletingDestructor` | MSVC scalar deleting destructor wrapper | `TRUE` under current scalar-wrapper convention | [UID:00007G] | `86/91` | Keep formal C++ blank with no-code proof. |
| `0x004f4c10-0x004f4eac` | [UID:0002PL] `LogoPaneConstructor` | Constructor initializes same fields | `TRUE` | [UID:00007G] | no required score change | Support evidence. |
| `0x004f50b0-0x004f5246` | [UID:0002PO] `LogoPaneStaticLogoLoaderHelpers` | Retained loader/attach helpers using same fields | `TRUE` | [UID:00007G] | no required score change | Support evidence. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004f4eb0` | no direct static callers/xrefs in existing IDA docs | Ordinary destructor body is not on the normal virtual delete route. |
| `0x004f4edc` | vtable write `0x0061cf78` | Restores primary `LogoPane` table during destructor lowering. |
| `0x004f4ee2` | vtable write `0x0061cfc4` | Restores secondary EventHandler-style view. |
| `0x004f4eec` | vtable write `0x0061cff4` | Restores tertiary Timer/Event-style view. |
| `0x00458500` | callee from target and scalar wrapper | `EPFTileContext::ReleaseBuffers`. |
| `0x00542cd0` | callee from target and scalar wrapper | `DLPalette::FreePaletteData`. |
| `0x00542ca0` | callee from target and scalar wrapper | `DLPalette::~DLPalette`. |
| `0x00544580` | callee from target and scalar wrapper | `Pane::~Pane` ordinary base teardown. |
| `0x004f5300` | primary vtable slot plus thunk jumps | Scalar deleting destructor wrapper. |
| `0x004f52de`, `0x004f52e9` | secondary/tertiary vtable slots | Adjusted-this destructor thunks. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:0002PM] already documents exact boundary, cleanup order, vtable writes, helper call list, no-direct-caller evidence, and scalar parity.
- [UID:00007G] already documents `m_logoTileContext` and `m_logoPalette` as best field names.
- [UID:0002PL] documents initialization and static logo resource loading through the same fields.
- [UID:0002PO] documents retained helper bodies, field names, and loader/attach behavior.
- [UID:0002PR] documents scalar wrapper cleanup order and `0x354` guard size.
- [UID:0002PQ] documents pure adjustor thunk behavior.
- [UID:0001VH], [UID:00004I]/[UID:0000XY], and [UID:00003Z]/[UID:0001E4] prove the class/member layout.

Existing docs that are stale or incomplete:

- [UID:0002PM] says the C++ block is blank because `+0xf8` / `+0x120` names and destructor declaration still need a class layout pass. That is now stale.
- [UID:0002PR] says field names and final destructor declaration remain below final-code threshold. The field names and destructor source policy are now resolved enough for [UID:0002PM], while [UID:0002PR] still needs blank C++ as ABI glue.
- [UID:0002PQ] currently has `RECONSTRUCTABLE:TRUE` and an emitter despite being pure compiler-generated adjustor thunks. This should be corrected or at least documented as non-emitting generated-binary glue.
- Manual coverage row for [UID:0002PM] still says `82%` and final C++ blank pending field names.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` currently routes [UID:0002PM], [UID:0002PQ], and [UID:0002PR] through [UID:00007G] to `auto-generated/NexusTK/app/StartupLogoPanes.cpp`.
- `auto-generated/NexusTK/app/StartupLogoPanes.cpp` is zero bytes locally.
- `project-level/-auto-completion-stats.md` lists [UID:0002PM] and [UID:0002PQ] in low-completion/low-both style rows at `82/90`.

## Ranked Ownership Analysis

### 1. [UID:00007G] LogoPane

- Evidence for: destructor writes LogoPane vtables; fields are LogoPane-specific; constructor/static-loader/scalar-wrapper pages all use the same offsets; class emits through the correct startup source file.
- Evidence against: no direct callers to the ordinary destructor body; exact original member spellings are not proven.
- Decision: accepted as direct semantic owner.

### 2. [UID:0000O4] StartupLogoPanes

- Evidence for: file owns static LogoPane and LogoPlayerPane startup flow; generated route is valid; startup constructor caller and resources tie the class to app startup.
- Evidence against: file is a source module, not the narrowest semantic owner for a class method.
- Decision: accepted as source file/emission root through [UID:00007G], not as direct `CANONICAL_OWNER` for [UID:0002PM].

### 3. [UID:00004I] EPFTileContext / [UID:0000MA] Palette / [UID:0000A2] Pane

- Evidence for: helper callees belong to these classes/files.
- Evidence against: they are dependencies invoked by `LogoPane` destruction, not owners of the `LogoPane` destructor.
- Decision: rejected as direct owners; keep as dependencies/support docs.

### 4. Application / StartupWindow / VideoPlayerPane

- Evidence for: application startup constructs LogoPane; StartupLogoPanes sits in app startup; VideoPlayerPane is adjacent startup-media support.
- Evidence against: destructor fields/vtables are LogoPane, not Application; StartupWindow is a different pre-game update/news module; VideoPlayerPane belongs to LogoPlayerPane/Bink playback, not static LogoPane cleanup.
- Decision: rejected.

## Negative Evidence Summary

- No direct static callers/xrefs to `0x004f4eb0`: does not disprove source authorship; normal virtual destruction routes through `0x004f5300`, and ordinary complete destructors can be emitted without ordinary direct calls.
- No fresh MCP/PE scan in this session: caps confidence and should be recorded, but existing IDA-backed pages already cover the core facts.
- Generated/source output zero bytes: reflects blank formal C++ blocks, not invalid owner/emitter route.
- Helper ownership: `ReleaseBuffers`, `FreePaletteData`, `DLPalette::~DLPalette`, and `Pane::~Pane` belong to dependencies and should not move the destructor's owner.

## First-Draft C++ Recommendation

Populate [UID:0002PM]'s formal `RECONSTRUCTION_CPP CODE` block after applying the score/support updates. The target already has `RECONSTRUCTABLE:TRUE`, a valid nonblank emitter route through [UID:00007G], and after the recommended `88/91` score has `(88 + 91) / 2 > 85`.

Recommended formal C++:

```cpp
LogoPane::~LogoPane()
{
    m_logoTileContext.ReleaseBuffers();
    m_logoPalette.FreePaletteData();
}
```

Rationale:

- These are the two source-visible cleanup actions required by the ordinary destructor body.
- The compiler should emit the `LogoPane` vtable restores, `DLPalette::~DLPalette()` member destructor call, `Pane::~Pane()` base destructor call, secondary adjustor thunks, and scalar deleting destructor wrapper.
- Do not hand-write `m_logoPalette.~DLPalette()`, `Pane::~Pane()`, `operator delete`, delete-flag tests, or vtable stores in source C++.
- Do not keep [UID:0002PM] blank merely because exact original member spellings are unproven; the source-facing types and names are high-probability and already consistent with support docs.

Target-specific no-code proof for support pages:

- [UID:0002PR] should keep formal C++ blank because it is the MSVC scalar deleting destructor wrapper. Its source representation is the virtual destructor declaration plus [UID:0002PM]'s ordinary destructor body.
- [UID:0002PQ] should keep formal C++ blank and preferably become `RECONSTRUCTABLE:FALSE` because it is pure adjustor thunk glue: `this -= 0xa0` / `this -= 0xa4`, jump to scalar wrapper.

## Exact Supervisor Edits

### [UID:0002PM] Header

Replace:

```text
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

with:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep:

```text
*** CANONICAL_OWNER:00007G | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007G | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace the formal C++ block contents with the first-draft C++ above.

### [UID:0002PM] Status

Add after the existing rebuild-handling bullet:

```text
- Source-quality closure: B002 2026-06-18 resolves `this + 0xf8` as `EPFTileContext m_logoTileContext` and `this + 0x120` as `DLPalette m_logoPalette`. The ordinary destructor source body should release tile-context buffers and free live palette data; the subsequent `DLPalette` member destructor, `Pane` base destructor, scalar deleting destructor wrapper, and adjusted-this thunks are compiler lowering.
```

### [UID:0002PM] Behavior

Replace the behavior paragraph with:

```text
This body performs ordinary `LogoPane::~LogoPane()` cleanup without freeing the object allocation. The binary restores the three `LogoPane` vtable views at offsets `+0x00`, `+0xa0`, and `+0xa4`, calls `EPFTileContext::ReleaseBuffers` on `this + 0xf8` / `m_logoTileContext`, calls `DLPalette::FreePaletteData` on `this + 0x120` / `m_logoPalette`, then runs the compiler-emitted `DLPalette::~DLPalette` member destructor and `Pane::~Pane` base teardown. Source C++ should express the first two cleanup calls in `LogoPane::~LogoPane()` and let the compiler emit the member/base destructor calls and vtable stores.
```

### [UID:0002PM] New Layout Closure Section

Insert after `## Touched State And Dependencies`:

```text
## LogoPane Member Layout Closure

The destructor member names are now source-quality enough for first-draft C++. `Pane` layout documentation places the first derived field at `+0xf8`. [UID:00004I][EPFTileContext](by-class/EPFTileContext.md) documents a `0x28`-byte context, so `LogoPane +0xf8` through `+0x11f` is best modeled as `EPFTileContext m_logoTileContext`, and the next field starts at `+0x120`.

[UID:00003Z][DLPalette](by-class/DLPalette.md) documents `DLPalette` as an `LObject`-based palette object with optional entry/remap data, a `0x20`-byte header, and a 256-entry 16-bit lookup table through object offset `+0x22b`. Placing `DLPalette m_logoPalette` at `LogoPane +0x120` reaches `LogoPane +0x34c`, exactly where LogoPane's early-click/ready/queued flags begin. The completion callback pointer at `+0x350` then closes at `+0x354`, matching the scalar deleting destructor guard size.

Use `m_logoTileContext` and `m_logoPalette` as source-facing member names. Original spelling is not proven, but the types and field roles are strongly supported by constructor, static-loader, ordinary-destructor, scalar-destructor, EPFTileContext, DLPalette, and Pane layout evidence.
```

### [UID:0002PM] Reconstruction Notes

Replace the section body with:

```text
Keep this body with `LogoPane`; it is not generic base-pane cleanup even though it delegates to lower-level image, palette, and base-pane destructors.

Formal C++ is now eligible under the active code-entry gate. Use:

```cpp
LogoPane::~LogoPane()
{
    m_logoTileContext.ReleaseBuffers();
    m_logoPalette.FreePaletteData();
}
```

Do not include explicit vtable stores, `m_logoPalette.~DLPalette()`, `Pane::~Pane()`, scalar-delete flag checks, or `operator delete` in this page's source body. Those are compiler-generated lowering from the class declaration, embedded member, base class, and scalar deleting destructor wrapper.
```

### [UID:0002PM] Score Rationale

Replace the score table with:

```text
| Score | Rationale |
| --- | --- |
| Completion `88` | The page records the live range, surrounding alignment, signature, behavior, raw decompile/disassembly evidence, direct caller/xref absence, exact callee list, touched state, dependency docs, rebuild handling, resolved `m_logoTileContext` / `m_logoPalette` member layout, destructor source-policy decision, scalar/thunk relationship, and first-draft C++ body. It remains below final-audit range because fresh MCP/PE route scans were unavailable in the B002 pass and exact original member spellings are descriptive rather than proven. |
| Confidence `91` | Existing live IDA evidence directly supports the boundary, vtable writes, cleanup order, dependency calls, and no-direct-caller caveat. Cross-doc layout evidence independently proves `+0xf8` as `EPFTileContext`, `+0x120` as `DLPalette`, and object size `0x354`. Confidence stays below higher final-audit levels because this B002 pass could not perform a fresh live MCP byte/xref refresh. |
```

### [UID:0002PM] Changes

Add:

```text
- 2026-06-18 B002 source-quality closure: recommended `88/91`, kept owner/emitter [UID:00007G][LogoPane](by-class/LogoPane.md), resolved `this +0xf8` as `EPFTileContext m_logoTileContext` and `this +0x120` as `DLPalette m_logoPalette`, proved the layout through `Pane` derived start `+0xf8`, `EPFTileContext` size `0x28`, `DLPalette` size through `+0x22b`, LogoPane flags at `+0x34c`, callback pointer at `+0x350`, and scalar-destructor guard size `0x354`, and supplied formal first-draft `LogoPane::~LogoPane()` C++. Fresh IDA MCP was unavailable during this pass, so exact original member spellings remain descriptive/inferred.
```

### [UID:00007G] LogoPane Support Page

Recommended metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace Data Notes bullets for `+0xf8` and `+0x120` with:

```text
- `this + 0xf8` is `EPFTileContext m_logoTileContext`; `+0xfc` is the decoded pixel pointer, `+0x104` the row stride, `+0x108` the `RectBounds`, `+0x118` the encoded-mask byte count, and `+0x11c` the encoded-mask bytes pointer.
- `this + 0x120` is `DLPalette m_logoPalette`; the field follows the `0x28`-byte tile context and runs through the palette lookup table before LogoPane-specific flags start at `+0x34c`.
```

Add to Data Notes:

```text
- Layout closure: `Pane` derived state starts at `+0xf8`; `EPFTileContext` is `0x28` bytes, so the palette begins at `+0x120`; `DLPalette` occupies through object offset `+0x22b`, so LogoPane-specific flags begin at `+0x34c`; the completion callback pointer at `+0x350` closes the object at `+0x354`, matching the scalar deleting destructor guard size.
```

Add to Method Notes destructor row or evidence notes:

```text
- The ordinary destructor [UID:0002PM] should emit `LogoPane::~LogoPane()` with `m_logoTileContext.ReleaseBuffers();` and `m_logoPalette.FreePaletteData();`. The scalar deleting destructor [UID:0002PR] and adjustor thunks [UID:0002PQ] remain compiler-generated destructor-dispatch glue.
```

### [UID:0002PR] LogoPane ScalarDeletingDestructor

Recommended metadata:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep owner/emitter under [UID:00007G] and keep formal C++ blank.

Replace Reconstruction Notes with:

```text
Keep this page as the MSVC scalar deleting destructor wrapper for `LogoPane`. The source representation is the virtual destructor declaration plus the ordinary destructor body at [UID:0002PM][0x004f4eb0-0x004f4f29.LogoPaneCleanupDestructor](by-memory/0x004f4eb0-0x004f4f29.LogoPaneCleanupDestructor.md). Do not hand-write this wrapper in C++.

The wrapper's cleanup order now has source-quality names: restore `LogoPane` vtables, release `m_logoTileContext` through `EPFTileContext::ReleaseBuffers`, free `m_logoPalette` data through `DLPalette::FreePaletteData`, run the compiler/member `DLPalette::~DLPalette`, run `Pane::~Pane`, then apply scalar-delete flags and optional storage free. Formal C++ stays blank because this page is ABI glue generated from `LogoPane::~LogoPane()`.
```

Replace Score Rationale with:

```text
| Score | Rationale |
| --- | --- |
| Completion `86` | The page documents live boundaries, alignment, signature, vtable/thunk reachability, full cleanup order, scalar-delete flags, touched state, dependency UIDs, resolved `m_logoTileContext` / `m_logoPalette` names, and the no-code source policy tying this wrapper to [UID:0002PM]. |
| Confidence `91` | Existing live IDA evidence directly supports the range, branch logic, vtable refs, adjustor-thunk xrefs, callees, and alignment. Cross-doc layout evidence now resolves the field names. Confidence remains below final-audit range because fresh MCP/PE checks were unavailable in B002's 2026-06-18 pass. |
```

### [UID:0002PQ] LogoPane DeletingDestructorThunks

Recommended metadata:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep `CANONICAL_OWNER:00007G` if the supervisor wants semantic containment by the class; alternatively use `CANONICAL_OWNER:NONE` if following the stricter pure-ignored-thunk convention. In both cases, emitter and formal C++ should be blank.

Replace Reconstruction Notes with:

```text
These thunks are pure compiler-generated secondary/tertiary destructor adjustor glue. They subtract `0xa0` or `0xa4` from `this` and tail-jump to [UID:0002PR][0x004f5300-0x004f53a8.LogoPaneScalarDeletingDestructor](by-memory/0x004f5300-0x004f53a8.LogoPaneScalarDeletingDestructor.md). The source-facing `LogoPane` declaration and ordinary destructor [UID:0002PM] regenerate this behavior; do not emit handwritten C++ for the thunks.
```

## Coverage Row Recommendation

Placement context: replace the existing by-memory coverage rows at the LogoPane neighborhood around `by-memory/-coverage-report.md:1898-1903`.

Replace current [UID:0002PM] row with:

```text
    - [UID:0002PM][0x004f4eb0-0x004f4f29.LogoPaneCleanupDestructor](by-memory/0x004f4eb0-0x004f4f29.LogoPaneCleanupDestructor.md) 0x004f4eb0-0x004f4f29 | destructor body | LogoPane cleanup destructor : reconstructable : 88% : strong : B002 2026-06-18 source-quality closure resolves the ordinary `LogoPane::~LogoPane()` source body, with exact `0x79` boundary, surrounding `0xcc` alignment, three `LogoPane` vtable writes, `EPFTileContext m_logoTileContext` at `+0xf8` released through `0x00458500`, `DLPalette m_logoPalette` at `+0x120` freed through `0x00542cd0`, compiler/member `DLPalette::~DLPalette` at `0x00542ca0`, base `Pane::~Pane` at `0x00544580`, no direct static callers/xrefs, scalar-destructor parity, layout closure through flags `+0x34c` and callback `+0x350` ending at guard size `0x354`, and first-draft formal C++ `m_logoTileContext.ReleaseBuffers(); m_logoPalette.FreePaletteData();`.
```

Replace current [UID:0002PQ] row with:

```text
    - [UID:0002PQ][0x004f52de-0x004f52f4.LogoPaneDeletingDestructorThunks](by-memory/0x004f52de-0x004f52f4.LogoPaneDeletingDestructorThunks.md) 0x004f52de-0x004f52f4 | compiler-generated thunks | LogoPane deleting destructor thunks : ignored : 86% : strong : B002 2026-06-18 source-policy cleanup classifies the two `0xb` secondary/tertiary destructor adjustor thunks as non-emitting compiler glue: `0x004f52de` subtracts `0xa0`, `0x004f52e9` subtracts `0xa4`, both tail-jump to [UID:0002PR] `LogoPaneScalarDeletingDestructor`, vtable slots `0x0061cfc4/0x0061cff4` are the only dispatch route, no ordinary direct callers exist, and source should regenerate them from the `LogoPane` class declaration/destructor rather than handwritten C++.
```

Replace current [UID:0002PR] row with:

```text
    - [UID:0002PR][0x004f5300-0x004f53a8.LogoPaneScalarDeletingDestructor](by-memory/0x004f5300-0x004f53a8.LogoPaneScalarDeletingDestructor.md) 0x004f5300-0x004f53a8 | scalar deleting destructor | LogoPane scalar deleting destructor : reconstructable : 86% : strong : MSVC scalar deleting destructor wrapper for `LogoPane`; existing IDA evidence confirms exact `0xa8` boundary, primary vtable slot plus two adjustor-thunk xrefs, three `LogoPane` vtable writes, `m_logoTileContext` release, `m_logoPalette` free/member destructor, base `Pane` teardown, scalar-delete flags, optional `OperatorDeleteWrapper`, guard-check branch size `0x354`, no ordinary direct callers, and formal C++ intentionally blank because the source representation is the ordinary [UID:0002PM] `LogoPane::~LogoPane()` body plus compiler-generated ABI wrapper.
```

If the supervisor chooses not to reclassify [UID:0002PQ] to ignored/non-reconstructable in this pass, keep its status as reconstructable but still replace the description with the non-emitting no-code proof and remove any implication that the thunks need formal C++.

## Final Recommendation

Apply the primary target update now:

- [UID:0002PM] `82/90 -> 88/91`.
- Formal C++ should be populated with `LogoPane::~LogoPane()` containing `m_logoTileContext.ReleaseBuffers();` and `m_logoPalette.FreePaletteData();`.
- Keep owner/emitter [UID:00007G] `LogoPane`; route remains [UID:0000O4] `StartupLogoPanes`.
- Update class/support docs so `+0xf8` and `+0x120` are no longer open blockers.
- Keep [UID:0002PR] scalar deleting destructor formal C++ blank with explicit no-code proof.
- Prefer reclassifying [UID:0002PQ] adjustor thunks as non-reconstructable/ignored compiler glue with blank emitter.

## Follow-Up Actions

Supervisor actions:

- Apply the exact [UID:0002PM] edits and formal C++ block.
- Apply support updates for [UID:00007G], [UID:0002PR], and preferably [UID:0002PQ].
- Replace the three by-memory coverage rows above.
- Run scoped validators for the touched target/support pages and `by-memory/-coverage-report.md`.
- Run autogen/rescore if the normal supervisor workflow requires generated output refresh after formal C++ insertion.

A-agent actions:

- No immediate A-agent work is required for [UID:0002PM] after these edits.
- A future class-level pass should coordinate first-draft constructor and callback helper C++ for [UID:0002PL], [UID:0002PP], and the split LogoPane child methods. That is outside this report's primary scope.

B002 future research:

- None required for [UID:0002PM] unless the supervisor rejects the source body or needs fresh MCP/PE scans once MCP becomes available.

## Confidence

- Recommendation confidence: strong.
- Score confidence: strong for `88/91`; not higher because fresh IDA MCP/PE direct-route scans were unavailable.
- Remaining uncertainty: exact original spellings of `m_logoTileContext`, `m_logoPalette`, and helper methods. This is not a blocker because the descriptive names are type-correct, evidence-backed, and already consistent with support docs.

## Validator Results

- Commands run: none.
- Reason: assignment is report-only and no by-* documentation was edited.
- Expected supervisor validation after applying edits: scoped file validation for [UID:0002PM], [UID:00007G], [UID:0002PR], [UID:0002PQ] if changed, and `by-memory/-coverage-report.md`; then autogen/rescore if formal C++ is inserted.

## Changed Files

- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\0002PM-LogoPaneCleanupDestructor-source-quality.md`
- Modified: none outside the B002 research folder.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002PM-LogoPaneCleanupDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002PM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
