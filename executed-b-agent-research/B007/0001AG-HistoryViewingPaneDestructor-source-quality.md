** TARGET-REPORT-UID:0001AG **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# UID0001AG HistoryViewingPaneDestructor Source-Quality Report


## Finalized Report / Current Recommendation

Implementation callback status: applied. [UID:0001AG][0x00502760-0x005027cc.HistoryViewingPaneDestructor](by-memory/0x00502760-0x005027cc.HistoryViewingPaneDestructor.md) has been converted from an empty emitter marker to a source-ready `HistoryViewingPane::~HistoryViewingPane()` body under existing owner/emitter [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md).

The target is not a no-owner/no-code island. Current MCP session `eb7ce28b` confirms an exact `0x6c` scalar-deleting destructor wrapper with class-specific `HistoryViewingPane` vtable restores, `m_resourceName` release at `this+0x104`, `g_pHistoryViewingPane` clear at `0x0050278d`, inherited `Pane` cleanup through `0x00544580`, and compiler delete-flag branches through `0x004f4ac0` / guard support. Source emission should model only the source-visible destructor statements in the exact formal block under `First-Draft C++ Recommendation`.

Do not hand-write vtable stores, `Pane::~Pane()`, scalar-delete flag tests, `operator delete`, guard helper calls, or raw `sub_502760` wrapper syntax. Those are compiler-generated destructor and deleting-destructor mechanics. The exact `Release()` spelling is a project-conventional source spelling for `sub_582B70` wide string release/destructor behavior; it remains a confidence cap because the original source method name is not symbol-proven.

## Supporting Research

Assignment target from `tools/leaser/Agents/Agent-B007/goal.md`: UID `0001AG`, `by-memory/0x00502760-0x005027cc.HistoryViewingPaneDestructor.md`, report path `tools/leaser/Agents/Agent-B007/research/0001AG-HistoryViewingPaneDestructor-source-quality.md`. Queue row at assignment time was `85/89`, combined `87.0`, reconstructable `true`, report count `0`, from `auto-generated/-ag-research-tracker.md`.

MCP provenance:

- Active IDB session used for final evidence: `eb7ce28b`, supervisor-provided for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- `server_health` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- MCP calls were narrow/schema-current: `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `disasm`, `decompile`, and a bounded constructor/helper check. No MCP session/process-management command was used.

Local document review:

- Target page already has `CANONICAL_OWNER:0000JW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JW`, and blank formal C++.
- [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md) identifies accepted fields `m_frameIndex`, `m_totalFrames`, `m_delayTimer`, and `m_resourceName +0x104`, with source route through [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md).
- Historical pre-callback generated state: `auto-generated/NexusTK/login/HistoryViewingPane.cpp` recorded UID0001AG as `Completion:85 | Confidence:89 | Empty Emitter Marker`.
- Post-callback generated state: `auto-generated/NexusTK/login/HistoryViewingPane.cpp` now records UID0001AG as `Completion:88 | Confidence:91` and emits `HistoryViewingPane::~HistoryViewingPane()` with `m_resourceName.Release();` and `g_pHistoryViewingPane = NULL;`.
- Nearby support docs already identify [UID:0001AB][0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks](by-memory/0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks.md) as destructor adjustor thunks and [UID:0001PU][0x0069b494-0x0069b498.g_pHistoryViewingPane](by-memory/0x0069b494-0x0069b498.g_pHistoryViewingPane.md) as the singleton slot.

## Target

- UID: `0001AG`
- Path: `by-memory/0x00502760-0x005027cc.HistoryViewingPaneDestructor.md`
- Current title: `HistoryViewingPane Destructor`
- Historical assignment metadata: `COMPLETION:85`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000JW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JW`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Current implemented metadata: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000JW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JW`, blank `EMITTER_POSITION_OPTIONAL`, formal destructor C++ populated.
- Assignment problem resolved by callback: the reconstructable emitter route already existed; the missing piece was a source-ready formal C++ body and updated source-output policy.

## Current Target State

The current target doc now assigns ownership to HistoryViewingPane, records current `eb7ce28b` MCP evidence, and includes the formal source C++ block. The original stale part was source-output policy: the target had a valid emitter route but remained uncovered in generated `HistoryViewingPane.cpp` because the formal C++ block was blank. The callback resolved that state.

Implemented current-state replacement:

- `COMPLETION:88`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000JW`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000JW`
- `EMITTER_POSITION_OPTIONAL:` blank
- Formal C++ block populated with the `HistoryViewingPane::~HistoryViewingPane()` body shown under `First-Draft C++ Recommendation`.

## Heuristic / Inference Reanalysis And Validation

The original empty-emitter state appears to come from the older `95/95` final-source gate and conservative uncertainty about whether the scalar deleting destructor should emit handwritten source. Current B-agent rules allow source-ready first-draft C++ below final-audit scores when evidence is direct, formal, and caveats are recorded.

This target is not just compiler wrapper noise. The wrapper contains two source-facing effects before compiler/base/delete mechanics:

- `sub_582B70(Block + 65)` at `0x00502786`, where `Block + 65` is `this+0x104`, the accepted `m_resourceName` field.
- `unk_69B494 = 0` at `0x0050278d`, the accepted `g_pHistoryViewingPane` singleton clear.

The remaining visible effects are compiler-generated destructor lowering:

- Three `HistoryViewingPane` vtable restores at `this+0`, `this+0xa0`, and `this+0xa4`.
- Inherited `Pane` cleanup through `sub_544580`.
- MSVC scalar deleting destructor flag logic: return without free when `(flags & 1) == 0` or `(flags & 4) != 0`, ordinary delete through `sub_4F4AC0`, and guard helper path for the `flags & 4` branch with size `0x108`.

The accepted source convention for `sub_582B70` is a wide string release/destructor wrapper. Generated `RegistryConfig.cpp` uses `.Release()` for string fields and `.Clear()` for vector/container fields; therefore the source-like first draft uses `m_resourceName.Release()` rather than raw `sub_582B70(...)` or vector-style `Clear()`.

## Evidence Standards Used

- Current live MCP evidence was required and used; no fallback-only conclusion is present.
- Exact owner evidence needed at least one class-specific vtable/global/member signal and no stronger competing owner. UID0001AG has all three.
- Source C++ recommendation required an exact formal insertion block, not an illustrative snippet.
- Compiler-generated mechanics were separated from source-authored statements. Vtable stores, base destructor chaining, scalar-delete flags, guard helper calls, and operator-delete calls are evidence only, not source statements.
- Confidence is capped below final-audit range because exact original `StringBase`/`SimpleUString` member function spelling is unresolved and the target is a scalar deleting destructor wrapper rather than a separately modeled ordinary destructor body.

## Evidence Checked

MCP session `eb7ce28b`:

- `lookup_funcs`:
  - `0x00502760 -> sub_502760`, size `0x6c`.
  - `0x005027cc`: not a function.
  - `0x005027d0 -> sub_5027D0`, size `0x71`, successor begins after four `0xcc` bytes.
  - `0x00582b70 -> sub_582B70`, size `0x36`.
  - `0x00544580 -> sub_544580`, size `0x107`.
  - `0x004f4ac0 -> sub_4F4AC0`, size `0x40`.
  - Adjustor thunks: `0x005024b6 -> sub_5024B6`, size `0xb`; `0x005024c7` resolves inside `sub_5024C1`, size `0xb`.
  - Constructor: `0x004ffd80 -> sub_4FFD80`, size `0x149`.
  - Singleton clear helper: `0x005023b0 -> sub_5023B0`, size `0xb`.

- `get_bytes 0x00502758 size 128`:
  - Eight `0xcc` bytes precede the target.
  - Target bytes begin `55 8b ec 56 8b f1 8d 8e 04 01 00 00`.
  - Vtable immediates are `d0 d9 61 00`, `1c da 61 00`, and `4c da 61 00`.
  - Singleton clear bytes include `c7 05 94 b4 69 00 00 00 00 00`.
  - Delete-flag body includes `a8 01`, `a8 04`, call to `0x004f4ac0`, guard path with pushed `0x108`, and `retn 4`.
  - Four `0xcc` bytes follow before successor prologue at `0x005027d0`.

- `get_bytes 0x0061d9d0 size 64`:
  - First dword is `60 27 50 00`, the primary vtable slot pointing at `0x00502760`.
  - Neighboring vtable entries include `0x004f4b10`, `0x0041b6c0`, and pane/event methods, matching HistoryViewingPane table context.

- `get_bytes 0x0069b494 size 4` returned `00 00 00 00` for current singleton storage.

- `xrefs_to 0x00502760`:
  - Code refs from `0x005024bc` in `sub_5024B6` and `0x005024c7` in `sub_5024C1`.
  - Data ref from `0x0061d9d0`, the primary `HistoryViewingPane` vtable slot.

- `xrefs_to` vtable bases:
  - `0x0061d9d0`: constructor store `0x004ffdf1`, data ref `0x004ffed9`, destructor store `0x0050276c`.
  - `0x0061da1c`: constructor store `0x004ffdf7`, data ref `0x004ffedf`, destructor store `0x00502772`.
  - `0x0061da4c`: constructor store `0x004ffe01`, data ref `0x004ffee9`, destructor store `0x0050277c`.

- `xrefs_to 0x0069b494`:
  - Main-menu cleanup consumer `0x004f69dd`.
  - Constructor publish/fallback clear `0x004ffdd6` and `0x004ffddd`.
  - Constructor/EH-associated data ref `0x004ffefa`.
  - Clear helper `0x005023b0`.
  - Destructor clear `0x0050278d`.

- `disasm 0x00502760`:
  - `0x00502766`: `lea ecx, [esi+104h]`.
  - `0x0050276c`, `0x00502772`, `0x0050277c`: three HistoryViewingPane vtable writes.
  - `0x00502786`: `call sub_582B70`.
  - `0x0050278d`: `mov dword ptr unk_69B494, 0`.
  - `0x00502797`: `call sub_544580`.
  - `0x0050279f-0x005027a5`: delete flag tests.
  - `0x005027a8`: `call sub_4F4AC0`.
  - `0x005027b7-0x005027bd`: guard-helper branch with `push 108h`, `push esi`, `call @_guard_check_icall_nop@4`.
  - Both exits return with `retn 4`.

- `decompile 0x00502760`:
  - Pseudocode writes HistoryViewingPane vtables, calls `sub_582B70(Block + 65)`, clears `unk_69B494`, calls `sub_544580(Block)`, and conditionally calls `sub_4F4AC0(Block)` based on scalar-delete flags.

- `decompile 0x004ffd80` constructor:
  - Publishes `unk_69B494 = this` or clears it on fallback.
  - Installs the same three HistoryViewingPane vtables.
  - Initializes `this+0x104` through `sub_582B20`.
  - Assigns the constructor resource argument to `this+0x104` through `sub_582D20`.
  - Initializes frame fields at `+0xf8`, `+0xfc`, and `+0x100`, matching class docs.

- `decompile 0x005023b0`:
  - Single-purpose helper `unk_69B494 = 0`, supporting the singleton identity.

Generated output:

- Historical pre-callback `auto-generated/NexusTK/login/HistoryViewingPane.cpp` header `validator-command-id: 000000005897`, refreshed `2026-07-03T23:45:00-04:00`, had UID0001AG as `Completion:85 | Confidence:89 | Empty Emitter Marker`.
- Current generated file header records `validator-command-id: 000000005987`, `validator-refreshed-at: 2026-07-04T00:52:33-04:00`, `validator-refresh-source: deferred-generated-refresh`, and contains UID0001AG as `Completion:88 | Confidence:91` with the emitted `HistoryViewingPane::~HistoryViewingPane()` body.

## First-Draft C++ Recommendation

The implementation callback inserted this exact formal block into the target page:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
HistoryViewingPane::~HistoryViewingPane()
{
    m_resourceName.Release();
    g_pHistoryViewingPane = NULL;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Rationale:

- `m_resourceName` is an accepted field name at `+0x104`; constructor evidence initializes/copies it and destructor evidence releases it through `sub_582B70`.
- `g_pHistoryViewingPane` is an accepted singleton name; constructor publish/fallback, helper clear, main-menu cleanup read, and destructor clear all target `0x0069b494`.
- `.Release()` is the conservative source-style spelling for string-field release based on existing generated source conventions and `sub_582B70` support docs.
- `NULL` matches neighboring singleton-destructor generated style for pane globals.

Confidence cap:

- The exact original spelling of the string release method is not symbol-proven; `Release()` is the project source-facing convention, not recovered debug info.
- If future class-layout work proves `m_resourceName` is automatically destructed by a final RAII member declaration, the manual release line may need to become implicit. Current project convention for similar recovered string-field destructor code still supports explicit `.Release()`.

## Ranked Ownership Analysis

| Rank | Candidate | Decision | Evidence |
| --- | --- | --- | --- |
| 1 | [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md) / [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md) | Accept | Target writes three HistoryViewingPane vtable views, clears `g_pHistoryViewingPane`, releases `m_resourceName`, is referenced by HistoryViewingPane adjustor thunks and primary vtable, and matches constructor field/global/vtable setup. |
| 2 | [UID:0000A2][Pane](by-class/Pane.md) | Reject as owner | `0x00544580` is inherited `Pane` cleanup after derived cleanup. Base cleanup is a dependency, not the semantic owner. |
| 3 | [UID:0001AB][HistoryViewingPaneDestructorThunks](by-memory/0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks.md) | Reject as owner/emitter | The thunks route adjusted receivers to this destructor. They corroborate this target but do not own source behavior. |
| 4 | [UID:0001PU][g_pHistoryViewingPane](by-memory/0x0069b494-0x0069b498.g_pHistoryViewingPane.md) / [UID:0000R3][g_pHistoryViewingPane](by-global/g_pHistoryViewingPane.md) | Reject as owner | Singleton page owns the storage declaration/evidence. The destructor body belongs to the class/file route. |
| 5 | Raw helper `sub_502760` / no-owner / non-emitting | Reject | The class-specific vtables, singleton, member field, thunks, primary vtable slot, and existing valid emitter route prove source ownership. |

## Source Placement

Source placement should remain `NexusTK/login/HistoryViewingPane.cpp` through file UID `0000JW`. The class and file pages already attach the story/history viewer to login/main-menu UI, not BackStoryDialogPane, MainMenuPane, Pane, or StringBase. `MainMenuPane` and retained launch helpers are constructors/consumers; they are not the destructor owner.

The implementation callback updated source-output notes so UID0001AG is no longer described as blank solely due to historical final-source gating. Generated `HistoryViewingPane.cpp` now emits the destructor body from the populated target formal C++ block.

## Range / Split Analysis

The target range is exact:

- `lookup_funcs 0x00502760` gives `sub_502760`, size `0x6c`, ending at `0x005027cc`.
- `lookup_funcs 0x005027cc` reports not a function.
- `lookup_funcs 0x005027d0` gives successor `sub_5027D0`, size `0x71`.
- `get_bytes 0x00502758 size 128` shows eight pre-target `0xcc` bytes, the complete target body, four post-target `0xcc` bytes, then successor prologue.

No split is recommended. The scalar-delete flag branch is part of this exact compiler wrapper. Source emission should not split out a separate operator-delete helper or a separate singleton clear method from this page.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0001AG-01 | MCP evidence is current and read-only from session `eb7ce28b`. | High | `server_health status:"ok"`, Hex-Rays ready, active NexusTK IDB; no MCP management commands used. | Target `IDA MCP Evidence`; report `Supporting Research` | incorporate | applied: target now records `eb7ce28b` health/provenance; report preserves same evidence. |
| C-0001AG-02 | UID0001AG exact range is `0x00502760-0x005027cc`, size `0x6c`, with clean padding and successor at `0x005027d0`. | High | `lookup_funcs`, `get_bytes` pre/post padding and successor prologue. | Target `IDA MCP Evidence`; core support evidence | incorporate | applied: target records range, size, bytes, padding, and successor; core support records the same summary. |
| C-0001AG-03 | Owner/emitter should remain HistoryViewingPane / UID0000JW. | High | Three HistoryViewingPane vtable writes, primary vtable data ref `0x0061d9d0`, adjustor thunk refs, constructor parity, singleton clear. | Target metadata; class/file support | incorporate | applied: target keeps owner/emitter `0000JW`; class/file support rows describe UID0001AG as emitted through UID0000JW. |
| C-0001AG-04 | Source-visible destructor work is `m_resourceName` release then `g_pHistoryViewingPane` clear. | High | `lea ecx,[esi+104h]`, `call sub_582B70`, `mov unk_69B494,0`; constructor initializes/copies `+0x104`. | Target `Behavior Summary` / C++ block; class/file/core notes | incorporate | applied: formal target C++ and support notes carry `m_resourceName.Release();` followed by `g_pHistoryViewingPane = NULL;`. |
| C-0001AG-05 | Vtable restores, `Pane` cleanup, scalar-delete flags, `sub_4F4AC0`, and guard-helper path are compiler mechanics and should not be handwritten. | High | Disasm/decompile instruction order and helper roles; project destructor precedent. | Target `Behavior Summary` and `Ownership And Source Policy`; support docs | incorporate | applied: target and support docs explicitly keep these as compiler-generated mechanics, not source statements. |
| C-0001AG-06 | Formal source C++ should be `HistoryViewingPane::~HistoryViewingPane()` with `m_resourceName.Release();` and `g_pHistoryViewingPane = NULL;`. | Medium-high | Accepted field/global names, `sub_582B70` string-release convention, generated source `.Release()` precedent, singleton style. | Target `RECONSTRUCTION_CPP CODE`; generated C++ | incorporate | applied: target formal block contains the body; generated `HistoryViewingPane.cpp` now emits the destructor under UID0001AG. |
| C-0001AG-07 | Historical generated output was an Empty Emitter Marker before callback; the implementation converted it to real destructor output. | High | Historical generated marker at `85/89`, no body; current generated header `000000005987` contains body. | Target generated-output note; by-file support; report validator results | incorporate | applied: target records historical marker state; by-file says marker blocker cleared; generated C++ contains destructor. |
| C-0001AG-08 | Reject Pane, StringBase, singleton storage, destructor-thunk, raw-helper, no-owner, and non-emitting alternatives. | High | Dependency roles only; class-specific vtables/global/member and valid emitter route. | Target `Ownership And Source Policy`; support notes | incorporate | applied: target records all rejected alternatives; class/file/core keep HistoryViewingPane route. |
| C-0001AG-09 | Raise target to `88/91` while keeping reconstructable and emitter UID0000JW. | Medium-high | Evidence clears source-ready threshold; cap remains exact original string method spelling and scalar-wrapper source shape. | Target metadata | incorporate | applied: scoped validator `000000005962` recorded completion/confidence updates to `88/91`; owner/reconstructable/emitter unchanged. |
| C-0001AG-10 | Support docs need only stale-output/source-policy sync, not ownership rewrites. | Medium-high | Class/file/core/global docs already carry owner/field/global facts; generated output and target C++ are stale. | by-class/by-file/core/thunk/global support | incorporate or already-present | applied/already-present: class, file, and core stale wording updated; thunk, singleton child, and global pages already carried the dependency/clear relation and were not edited by B007. |

## Positive Evidence Summary

- Active MCP evidence confirms the exact function and binary behavior.
- Vtable data, constructor parity, thunks, singleton refs, and member offset all point to HistoryViewingPane.
- Existing direct owner and emitter are already valid and clear the gate.
- `m_resourceName` and `g_pHistoryViewingPane` are accepted names in local docs.
- Existing project precedent emits ordinary destructor source statements from scalar deleting destructor targets when the wrapper contains class-owned cleanup, while omitting compiler ABI mechanics.

## Negative Evidence Summary

- No debug symbol names prove the original `m_resourceName.Release()` spelling.
- The body is a scalar deleting destructor wrapper, not a separately modeled ordinary destructor, so the report must document delete-flag mechanics as evidence while emitting only source-facing statements.
- Historical generated `HistoryViewingPane.cpp` output had only an Empty Emitter Marker; current generated output contains the UID0001AG destructor body.
- No reason was found to move ownership to Pane, StringBase, the singleton storage page, MainMenuPane, BackStoryDialogPane, or a raw `sub_502760` helper.

## Final Recommendation

Final disposition for UID0001AG: source-ready emitting HistoryViewingPane destructor. Owner and emitter remain UID0000JW, reconstructable remains true, target metadata is `COMPLETION:88` and `CONFIDENCE:91`, and the target formal C++ block is populated with the exact `HistoryViewingPane::~HistoryViewingPane()` body in this report.

Parent assignment disposition: the target remains under [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md) and [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md). Updated support docs describe UID0001AG as a source-ready destructor that emits through UID0000JW; parent/source-route metadata does not need reassignment.

No-owner/non-emitting disposition: reject. This target is not retained glue or an unowned compiler island because it performs source-visible resource/global cleanup and has a valid class/file emitter route.

Future work outside this UID0001AG source-readiness decision: final class declaration cleanup may refine exact `StringBase`/`SimpleUString` method spelling and destructor implicitness, but it does not block a first-draft source body under current project conventions.

## Score And Metadata Recommendation

| Field | Historical pre-callback | Implemented | Reason |
| --- | --- | --- | --- |
| `COMPLETION` | `85` | `88` | Current MCP evidence, exact source policy, formal C++ body, and support plan removed the empty-emitter blocker. |
| `CONFIDENCE` | `89` | `91` | Owner/range/behavior are direct; cap remains exact original `Release()` spelling and scalar-wrapper source shape. |
| `CANONICAL_OWNER` | `0000JW` | `0000JW` | Existing owner is correct. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Source-owned destructor semantics are reconstructable. |
| `EMITTER_UIDS` | `0000JW` | `0000JW` | Existing emitter route is correct. |
| `EMITTER_POSITION_OPTIONAL` | blank | blank | No special placement needed. |
| Formal C++ | blank | populated | Insert the exact formal block from this report. |

## Recommended Target Doc Changes

Implementation callback applied these target changes:

- Set `COMPLETION:88`.
- Set `CONFIDENCE:91`.
- Kept `CANONICAL_OWNER:0000JW`.
- Kept `RECONSTRUCTABLE:TRUE`.
- Kept `EMITTER_UIDS:0000JW`.
- Kept `EMITTER_POSITION_OPTIONAL:` blank.
- Replaced the blank formal C++ block with the exact destructor body from `First-Draft C++ Recommendation`.
- Replaced stale final-source blocker wording with source-ready destructor policy:
  - source emits `m_resourceName.Release();` and `g_pHistoryViewingPane = NULL;`;
  - compiler regenerates vtable stores, `Pane::~Pane`, scalar-delete flags, guard path, and delete helper;
  - confidence cap is exact string release method spelling / implicit destructor modeling, not owner or route.
- Added current MCP session `eb7ce28b` facts: health, range, bytes, xrefs, vtable/singleton refs, constructor parity, historical generated Empty Emitter Marker state, and rejected alternatives.

## Recommended Support Doc Changes

Support-doc handling:

- `by-class/HistoryViewingPane.md`: applied. The UID0001AG method row and evidence notes now describe a source-ready destructor through UID0000JW and preserve accepted layout names `m_frameIndex`, `m_totalFrames`, `m_delayTimer`, and `m_resourceName +0x104`.
- `by-file/HistoryViewingPane.md`: applied. Proposed contents/source-layout notes now say UID0001AG emits `HistoryViewingPane::~HistoryViewingPane()` through `NexusTK/login/HistoryViewingPane.cpp`; the prior empty-marker/source-gate blocker is no longer current.
- `by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md`: applied. Related-support/evidence/change notes now record UID0001AG as source-ready while keeping the core page's own metadata/C++ unchanged.
- `by-memory/0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks.md`: already-present. It already identifies the range as compiler-generated adjustor thunk support forwarding to UID0001AG and does not claim to be a source emitter.
- `by-memory/0x0069b494-0x0069b498.g_pHistoryViewingPane.md`: already-present. It already records the destructor clear at `0x0050278d`, constructor/singleton lifecycle, and storage ownership. No target-specific contradiction required an edit.
- `by-global/g_pHistoryViewingPane.md`: already-present. It already records constructor/helper/destructor lifecycle refs and keeps final singleton declaration placement as its own separate open question. No target-specific contradiction required an edit.
- Generated files and coverage reports were not manually edited. Scoped validators refreshed generated output.

## Open Questions With Attempted Resolution

| Question | Attempted resolution | Current answer |
| --- | --- | --- |
| Is `0x00502760` source-owned or pure scalar deleting glue? | Checked vtables, singleton, resource field, constructor parity, thunk refs, and destructor precedent. | Source-owned cleanup is present; emit ordinary destructor statements while omitting compiler wrapper mechanics. |
| Should the source body call `Pane::~Pane()` or delete/free `this`? | Checked disasm/decompile and project destructor policy. | No. Those are compiler/base/delete mechanics. |
| Should the string field use `Release()` or `Clear()`? | Compared `sub_582B70` support docs and generated code conventions. | Use `m_resourceName.Release()`; `Clear()` is used for vector/container fields. |
| Could `g_pHistoryViewingPane = NULL` be unsafe due cleanup order? | Checked constructor/destructor order and Application ordering counterexample. | For this target the binary explicitly releases `m_resourceName` before singleton clear. The first draft preserves that order with explicit `Release()` first. |
| Is there a no-code proof? | Checked class-specific side effects and valid emitter route. | No no-code proof applies; recommending code requires the formal block provided above. |

## Validator Results

Scoped validators were run from `source-3/project-documentation` for every by-* file edited by B007:

| File | Command | command_id | command_timestamp | Exit | ok | Notes |
| --- | --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x00502760-0x005027cc.HistoryViewingPaneDestructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x00502760-0x005027cc.HistoryViewingPaneDestructor.md --apply --queue-timeout 240 --wait-generated` | `000000005962` | `2026-07-04T00:44:36-04:00` | 0 | 1 | Applied completion/confidence updates, registry update from blank to block, generated C++ refresh completed, and refreshed research tracker/memory coverage/projected stats. Warnings were unrelated existing `autogen_children_*` / `autogen_emitter_has_no_code` rows. |
| `by-class/HistoryViewingPane.md` | `python .\tools\validator.py --mode file --file by-class/HistoryViewingPane.md --apply --queue-timeout 240` | `000000005964` | `2026-07-04T00:44:53-04:00` | 0 | 1 | Projected stats updated; generated refresh deferred. |
| `by-file/HistoryViewingPane.md` | `python .\tools\validator.py --mode file --file by-file/HistoryViewingPane.md --apply --queue-timeout 240` | `000000005965` | `2026-07-04T00:45:05-04:00` | 0 | 1 | Stats incremental noop for UID0000JW; generated refresh deferred and generated output continued to contain UID0001AG destructor output. |
| `by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md` | `python .\tools\validator.py --mode file --file by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md --apply --queue-timeout 240` | `000000005967` | `2026-07-04T00:45:16-04:00` | 0 | 1 | Stats incremental noop for UID0001A1; generated refresh deferred and the generated `HistoryViewingPane.cpp` header advanced to command `000000005967` while retaining UID0001AG destructor output. |
| `by-memory/0x00502760-0x005027cc.HistoryViewingPaneDestructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x00502760-0x005027cc.HistoryViewingPaneDestructor.md --apply --queue-timeout 240 --wait-generated` | `000000005987` | `2026-07-04T00:52:33-04:00` | 0 | 1 | Final target-summary wording repair validated; generated refresh completed and the generated `HistoryViewingPane.cpp` header advanced to command `000000005987` while retaining UID0001AG destructor output. Warnings were unrelated existing `autogen_children_*` / `autogen_emitter_has_no_code` rows. |

Generated freshness: `auto-generated/NexusTK/login/HistoryViewingPane.cpp` currently has `validator-command-id: 000000005987`, `validator-refreshed-at: 2026-07-04T00:52:33-04:00`, and contains UID0001AG at `Completion:88 | Confidence:91` with the emitted destructor body. The target is no longer an Empty Emitter Marker in that generated C++ file.

No `execute_report`, dry-run/probe lifecycle command, registry lifecycle command, archive move, generated/manual coverage edit, or supervisor-ledger edit was run by B007.

## Changed Files

Files edited by B007:

- `by-memory/0x00502760-0x005027cc.HistoryViewingPaneDestructor.md`
- `by-class/HistoryViewingPane.md`
- `by-file/HistoryViewingPane.md`
- `by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md`
- `tools/leaser/Agents/Agent-B007/research/0001AG-HistoryViewingPaneDestructor-source-quality.md`

Validator-owned/generated side effects observed from scoped validators:

- `auto-generated/NexusTK/login/HistoryViewingPane.cpp` refreshed and now contains UID0001AG destructor output, with latest validator-owned header command `000000005987`.
- Validator output reported generated/project side effects including `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `project-level/-auto-completion-stats.md`, and `tools/validator.ini`; these were tool-owned updates, not manual edits.

Support docs inspected but not edited by B007 because same-or-greater target-specific detail was already present or no contradiction was found:

- `by-memory/0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks.md`
- `by-memory/0x0069b494-0x0069b498.g_pHistoryViewingPane.md`
- `by-global/g_pHistoryViewingPane.md`

## Implementation Tracking Checklist

- [x] Lease and edit `by-memory/0x00502760-0x005027cc.HistoryViewingPaneDestructor.md`. Proof: B007 lease succeeded before edits and again for the final target-summary wording repair; release succeeded after both validator batches.
- [x] Set target metadata to `COMPLETION:88`, `CONFIDENCE:91`, keep owner/reconstructable/emitter as `0000JW`/`TRUE`/`0000JW`, and keep optional position blank. Proof: target metadata updated and validator `000000005962` reported `completion_update 0001AG ... 88` and `confidence_update ... 91`.
- [x] Insert the exact formal `RECONSTRUCTION_CPP CODE` block from this report into the target. Proof: target formal block contains `HistoryViewingPane::~HistoryViewingPane()`, `m_resourceName.Release();`, and `g_pHistoryViewingPane = NULL;`; generated C++ contains the same body.
- [x] Add current MCP `eb7ce28b` evidence at report-level detail: health, range/size, bytes/padding, vtable refs, thunk refs, singleton refs, constructor parity, helper roles, delete-flag/compiler mechanics, historical generated Empty Emitter Marker state, and rejected alternatives. Proof: target `IDA MCP Evidence` and `Ownership And Source Policy` sections now carry these details.
- [x] Update `by-class/HistoryViewingPane.md` if its UID0001AG destructor row/notes still say blank/deferred rather than source-ready. Proof: method row and evidence/change notes now mark UID0001AG source-ready through UID0000JW; validator `000000005964` passed.
- [x] Update `by-file/HistoryViewingPane.md` if generated/source-output notes still say UID0001AG remains an Empty Emitter Marker solely due to old source-gate wording. Proof: proposed contents/source-layout/evidence/change notes now include UID0001AG destructor emission; validator `000000005965` passed.
- [x] Review `by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md`, `by-memory/0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks.md`, `by-memory/0x0069b494-0x0069b498.g_pHistoryViewingPane.md`, and `by-global/g_pHistoryViewingPane.md`; mark already-present unless UID0001AG-specific wording contradicts the accepted report. Proof: core page was stale enough to update and validator `000000005967` passed; thunk/singleton/global pages already carried dependency/clear relation and were not edited by B007.
- [x] Run scoped validators from `source-3/project-documentation` for every changed by-* file using `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`. Proof: validators `000000005962`, `000000005964`, `000000005965`, `000000005967`, and final target revalidation `000000005987` all exited 0 with `ok:1`.
- [x] Report validator command IDs/timestamps/exits/ok counts, generated refresh state, changed files, leases used/released, and final ledger states after implementation. Proof: recorded in `Validator Results`, `Changed Files`, and final response package.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000005999","destination_path":"executed-b-agent-research/B007/0001AG-HistoryViewingPaneDestructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0001AG-HistoryViewingPaneDestructor-source-quality.md","timestamp":"2026-07-04T03:11:30-04:00","uid":"0001AG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
