** TARGET-REPORT-UID:0002NX **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002NX / 0002O1 Clan Name Raw Constructor Source-Placement Research

Assignment: `B001-goal2-clan-name-raw-constructor-source-placement-0002NX-0002O1-20260615`

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002NX] and [UID:0002O1] as reconstructable raw constructor evidence with blank final C++; do not reclassify them to ignored/non-emitting, and do not emit standalone constructor C++ yet.
- Final disposition: source-authored constructor-shaped byte ranges for real Clan modal-dialog classes, most likely retained out-of-line constructor bodies from the same source family whose active construction paths were inlined at call/open sites.
- Required action: no target/support doc, score, owner/emitter, IDA DB, or `by-memory/-coverage-report.md` change is recommended from this B001 pass.
- Confidence: high for the current metadata/disposition; medium-high for the compiler/source-structure inference because no object file, PDB, linker map, relocation group, or build flag evidence is available.

## Target

| UID | Target | Current state |
| --- | --- | --- |
| [UID:0002NX](../../../../../by-memory/0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor.md) | `0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor` | `85/90`, `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:00002M](../../../../../by-class/ClanSummonNameInputDialog.md), C++ blank |
| [UID:0002O1](../../../../../by-memory/0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor.md) | `0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor` | `85/90`, `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:000028](../../../../../by-class/ClanChangeNameInputDialog.md), C++ blank |

Source queue row: `Supervisor_notes.md` line for `0002NX/0002O1-source-placement`, status `assigned` to B001.

The assigned question is not whether the bytes are constructor-shaped. A001 already settled that. The question is whether the lack of raw-start reachability should make these pages dead/duplicate/non-emitting instead of reconstructable evidence.

## Executive Recommendation

The best-supported model is:

1. The raw bodies are source-authored constructor bodies for the owning C++ classes.
2. They are not current runtime entry anchors, because no direct raw-start reference has been found and the observed opener paths duplicate the construction sequence inline.
3. They should remain reconstructable documentation children because they represent real project class construction semantics, vtable identity, and source layout evidence.
4. Final generated C++ should stay blank because emitting these exact bodies as standalone constructors would overclaim original source placement and can conflict with the inline construction paths already documented as the source-quality runtime anchors.

This is materially different from an ignored/non-emitting classification. Ignored/non-emitting is appropriate for padding, compiler adjustor thunks, pure ABI forwarders, section containers, mixed indexes, or runtime/library glue. These two bodies are executable project-code bytes that call the Clan name-dialog base constructor and install the derived class vtables. They are unreferenced, but not compiler glue or padding.

## Evidence Checked

Read/current documentation:

- Target pages [UID:0002NX] and [UID:0002O1].
- Support classes [UID:00002M] `ClanSummonNameInputDialog` and [UID:000028] `ClanChangeNameInputDialog`.
- Source/file candidates [UID:0000I8] `Clan`, [UID:0000IA] `ClanDialogs`, [UID:00010K] `ClanNameDialogSubmitters`, [UID:00021C] `ClanStatusPacketDispatcher`, [UID:00021S] `ClanStatusPacketDialogHandlers`, [UID:0003HE] `ClanModalDialogVtables`, and [UID:0001X9] `ClanDialogVtableFamily`.
- Neighbor raw constructors: [UID:00021V], [UID:0002NT], [UID:0002NV], [UID:0002NZ], [UID:00021T], [UID:0002NP], [UID:00021W], [UID:0002O4], [UID:0002O6], and [UID:00021X].
- A001 handoff notes, C001 neighboring raw-constructor notes, and A003 clan list-pane raw-constructor notes.
- `by-structure.md`, `by-project-structure/proposed-source-tree.md`, B001 `goal.md`, B001 `notes.md`, and B001 `inference_research.md`.

Wave2 commands run from `E:\NTK\GhidraBridge\source-2\core\wave2`:

- `python wave2.py method 0x00489270 --format json`
- `python wave2.py decomp 0x00489270 --format json`
- `python wave2.py xrefs 0x00489270 --format json`
- `python wave2.py filter --class ClanSummonNameInputDialog --all-methods --format json`
- `python wave2.py method 0x004894d0 --format json`
- `python wave2.py decomp 0x004894d0 --format json`
- `python wave2.py xrefs 0x004894d0 --format json`
- `python wave2.py filter --class ClanChangeNameInputDialog --all-methods --format json`
- `python wave2.py struct ClanNameInputDialog --format json`
- A broader sibling sweep with `filter --class ... --all-methods` for `ClanDepMoneyInputDialog`, `ClanWidMoneyInputDialog`, `ClanExpelNameInputDialog`, `ClanSummonNameInputDialog`, `ClanAppearNameInputDialog`, `ClanChangeNameInputDialog`, `ClanEnlistInputDialog`, `ClanChangeInputDialog`, and `ClanLeaveConfirmDialog`.

Fresh IDA MCP was not available in this resumed B001 session. Existing docs record A001/C001/A003 live IDA MCP evidence, and no MCP resources are exposed to this session. I did not apply any IDA DB edits.

Local PE/raw checks run against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

- Full-file little-endian absolute VA scan for all twelve checked clan raw constructor starts.
- Full-file little-endian RVA scan for the same starts.
- `.text` relative `call`/`jmp` target scan for the same starts.
- Byte-shape/padding comparison for the clan raw constructor family.

## Facts

### Target-Level Facts

- Wave2 records both targets as included constructor methods, not excluded compiler glue:
  - `0x00489270`: effective signature `ClanSummonNameInputDialog* ClanSummonNameInputDialog::ClanSummonNameInputDialog(int clanId)`, size `53`, zero callers, one callee to `0x00488b40`.
  - `0x004894d0`: effective signature `ClanChangeNameInputDialog::ClanChangeNameInputDialog(int parentPaneId)`, size `53`, zero callers, one callee to `0x00488b40`.
- Wave2 has no duplicate-owner metadata for either target: no `shadowed_duplicate_owner`, active duplicates, inactive duplicates, or disabled duplicates.
- Wave2 class filters show the expected two-method surface:
  - `ClanSummonNameInputDialog`: constructor `0x00489270` with zero callers plus submitter `0x004892b0` with one caller/data reference.
  - `ClanChangeNameInputDialog`: constructor `0x004894d0` with zero callers plus submitter `0x00489510` with one caller/data reference.
- Existing live IDA docs record no function object at either raw start/end, no xrefs to either raw start, exact 53-byte bodies, `retn 4`, and eleven `0xcc` bytes before the adjacent submitters.
- Existing live IDA docs record inline construction routes:
  - Summon: `0x00485227` and `0x0048828f` call `0x00488b40`, then store the same three `ClanSummonNameInputDialog` vtables.
  - Change-name: `0x00485332` and `0x00488429` call `0x00488b40`, then store the same three `ClanChangeNameInputDialog` vtables.

### Family-Level Facts

The six `ClanNameInputDialog` derivatives from deposit-money through change-name follow the same pattern:

| Class | Raw constructor | Wave2 constructor callers | Submitter callers | Body shape |
| --- | ---: | ---: | ---: | --- |
| `ClanDepMoneyInputDialog` | `0x00488fa0` | 0 | 1 | 0x35 bytes, `retn 4`, 11-byte padding |
| `ClanWidMoneyInputDialog` | `0x00489070` | 0 | 1 | 0x35 bytes, `retn 4`, 11-byte padding |
| `ClanExpelNameInputDialog` | `0x00489140` | 0 | 1 | 0x35 bytes, `retn 4`, 11-byte padding |
| `ClanSummonNameInputDialog` | `0x00489270` | 0 | 1 | 0x35 bytes, `retn 4`, 11-byte padding |
| `ClanAppearNameInputDialog` | `0x004893a0` | 0 | 1 | 0x35 bytes, `retn 4`, 11-byte padding |
| `ClanChangeNameInputDialog` | `0x004894d0` | 0 | 1 | 0x35 bytes, `retn 4`, 11-byte padding |

Broader PE reachability scan for twelve clan raw constructors found zero absolute VA hits, zero RVA hits, and zero relative call/jump hits for every checked start:

- `0x004885a0`, `0x00488630`, `0x00488fa0`, `0x00489070`, `0x00489140`, `0x00489270`, `0x004893a0`, `0x004894d0`, `0x00489f80`, `0x00489ff0`, `0x0048a060`, and `0x0048a0c0`.

This makes `0002NX/0002O1` ordinary members of a larger clan raw-constructor emission pattern, not special orphan targets.

### Source-Placement Facts

- [UID:0000I8] `Clan` remains the stronger current source owner for the modal dialog family because the same source cluster owns `ClanStatusPane`, opcode `0x43` packet dispatch, opcode `0x4b` helpers, name/attribute modal dialogs, resources, and vtable families.
- [UID:0000IA] `ClanDialogs` is a documented split candidate under `NexusTK/ui/dialogs/`, but it explicitly says `Clan` remains the stronger current owner if final source layout keeps the modal dialogs feature-owned.
- `auto-generated/NexusTK/social/Clan.cpp`, `auto-generated/NexusTK/social/ClanBank.cpp`, and `auto-generated/NexusTK/ui/dialogs/ClanDialogs.cpp` currently exist as zero-byte files. This is not evidence of a dead emitter route; it only reflects blank final reconstruction snippets.
- [UID:00010K] `ClanNameDialogSubmitters` is a non-emitting aggregate. It is not a better parent or emitter for the raw constructors because exact child pages carry the reconstruction decisions.
- [UID:0003HE] `ClanModalDialogVtables` routes the modal vtable family through `Clan`, with `ClanDialogs` only a possible split.

## Ranked Disposition Analysis

### 1. Keep As Reconstructable Raw Constructor Evidence With Blank Final C++

Evidence for:

- Both targets are executable project-code bytes with constructor semantics: base constructor call plus derived primary/secondary/tertiary vtable stores.
- Wave2 includes both as constructor records and does not mark either as duplicate, shadowed, excluded, thunk, or compiler glue.
- The owning classes and submitters are real Clan modal-dialog classes with vtable-backed virtual submit paths.
- The same pattern holds across the neighboring Clan name-dialog constructor family and the wider Clan modal/list raw-constructor family.
- Local docs already use this model for adjacent raw constructors: C001 kept deposit/withdraw/expel/appear raw constructors reconstructable with blank C++, and A003 kept list-pane raw constructors reconstructable while naming inline construction as the runtime anchor.
- `by-structure.md` says `RECONSTRUCTABLE:TRUE` is appropriate when IDA/MCP evidence shows NexusTK-owned source that must be rebuilt even if final owner, emitter route, or C++ is not ready.

Evidence against:

- No direct raw-start call, pointer, RVA, or relative branch target has been found.
- Inline opener paths duplicate the body, so final source should not blindly emit the raw range as the only constructor implementation.

Decision:

Accepted. This is the best current model. The negative reachability evidence limits final C++ emission, not reconstructable/source-authored classification.

### 2. Treat As Dead/Duplicate Bodies Caused By Inline Construction

Evidence for:

- Every checked clan raw constructor start lacks raw-start reachability in IDA docs and local PE scans.
- The active opener paths inline the same base-constructor/vtable-store sequence.
- The family pattern is consistent with an optimized build retaining out-of-line constructor bodies even when local construction sites inline the same logic.

Evidence against:

- There is no object/linker metadata proving these bodies are discarded COMDAT, identical-code-folded leftovers, stale source, or unreachable dead code by design.
- They are not byte-identical duplicate functions; each installs unique vtable addresses for a real class.
- Wave2 does not identify them as shadowed duplicates or inactive duplicate owners.
- The body shape is normal constructor code, not ABI glue. The `wave2-method-analysis` exclusion examples cover compiler-generated adjustor thunks, pure forwarding wrappers, and tiny wrappers with no product logic; these bodies do meaningful class-specific vtable installation.
- Neighbor docs use duplicated inline helper/opener logic as a reachability caveat, not as dead-code proof. [UID:00021S] explicitly keeps no-xref opener siblings as retained source functions unless a stronger linker/object-layout explanation proves otherwise.

Decision:

Rejected as a metadata change. It is fair to describe them as "retained out-of-line constructor bodies whose observed call sites inline equivalent construction," but not safe to classify them as dead or duplicate-only evidence.

### 3. Reclassify To Non-Emitting / Ignored Evidence Only

Evidence for:

- Final generated C++ should remain blank.
- Raw standalone constructor entry reachability is unproven.

Evidence against:

- `RECONSTRUCTABLE:FALSE` is for reviewed containers, compiler/runtime groupings, padding, mixed-owner indexes, or items that should not become source-level objects. These pages are exact executable constructor-shaped ranges, not containers or ledgers.
- `CANONICAL_OWNER:NONE` / blank emitters would discard the direct class ownership already supported by vtable identity and class pages clearing `85/85`.
- Ignored ledgers are for verified non-reconstruction targets. These constructors still explain class identity and source-authored construction behavior.
- The current blank C++ block already prevents accidental source emission while preserving the useful evidence and route.

Decision:

Rejected. Non-emitting/ignored would overcorrect and lose useful class/source evidence.

### 4. Move Ownership/Emission From Classes To `Clan` Or `ClanDialogs`

Evidence for:

- The broader source file owner is likely `Clan.cpp`, with `ClanDialogs.cpp` as a split candidate.
- Final source may eventually define the constructors in a file-level clan modal-dialog source rather than class pages.

Evidence against:

- `by-structure.md` says `CANONICAL_OWNER` should use the narrowest true direct semantic owner. Constructor bodies belong directly to their classes.
- The class pages already route downstream through `Clan`; changing target owner/emitter to the file would bypass the correct class owner.
- `ClanDialogs` is not the stronger current owner and is explicitly a split candidate.

Decision:

Rejected. Keep class owner/emitter routes as currently documented.

## Unresolved Issues And Why They Cannot Be Safely Resolved Further Here

### Raw Standalone Reachability

Evidence checked:

- A001 live IDA no-function/no-xref checks for both targets.
- A001 local PE scans for target VA/RVA/relative branch hits.
- B001 broader local PE scan for twelve clan raw constructor starts.
- Wave2 `xrefs` for both target starts.

Result:

No raw-start reachability was found. This cannot be safely resolved without new evidence such as a PDB, COFF/linker map, object files, relocation group metadata, a different client version with a direct constructor call, runtime execution trace that enters the raw start, or a proven IDA analysis miss. Current evidence supports the reachability caveat and blank final C++.

### Original Source Placement: `Clan.cpp` Versus `ClanDialogs.cpp`

Evidence checked:

- `Clan.md`, `ClanDialogs.md`, `ClanModalDialogVtables.md`, `ClanDialogVtableFamily.md`, and proposed source tree.
- Generated source roots for `Clan.cpp`, `ClanBank.cpp`, and `ClanDialogs.cpp`.

Result:

`Clan` remains the stronger current file owner because the modal constructors are tied to clan status packet dispatch, resources, opcode helpers, and vtables. `ClanDialogs` remains plausible but not proven. This does not require changing the raw constructor pages because their direct semantic owners are the classes and those classes already route through `Clan`.

### Final C++ Shape

Evidence checked:

- Wave2 generated constructor code for both targets.
- Existing inline construction sites documented by A001.
- Neighbor constructor family and source-placement docs.
- `by-structure.md` final C++ gate.

Result:

Even though `(85 + 90) / 2 > 85` and emitters are nonblank, source-quality is still insufficient for final C++. The unresolved issue is not the behavior of the 53-byte body; it is source placement and duplication. A final reconstruction could be a class constructor, inline construction helper, factory/open-site code, or a combination depending on the final `Clan.cpp`/`ClanDialogs.cpp` organization. Emitting this raw range as standalone constructor source now would overclaim the original design.

## Final Recommendation

No direct documentation changes are recommended.

Keep:

- [UID:0002NX] `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:00002M`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002M`, blank C++.
- [UID:0002O1] `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:000028`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000028`, blank C++.
- Class pages [UID:00002M] and [UID:000028] routed through [UID:0000I8] `Clan`.
- [UID:0000IA] `ClanDialogs` as split candidate only.
- Existing `by-memory/-coverage-report.md` rows applied by the supervisor after A001.

Do not:

- Create IDA functions at `0x00489270` or `0x004894d0`.
- Rename or type the raw constructor starts in IDA based on current evidence.
- Reclassify either page to ignored/non-emitting.
- Move direct owners from class UIDs to `Clan` or `ClanDialogs`.
- Add reconstruction C++ for either range.

## Supervisor Actions

No supervisor action is required.

Specifically:

- No target doc edits.
- No support doc edits.
- No score changes.
- No owner/emitter changes.
- No IDA DB changes.
- No `by-memory/-coverage-report.md` replacement rows.
- No validation run is required because this B001 pass changed only this research report.

## Validator Results

Not run. No by-* documentation, coverage, generated, or project-level files were changed.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B001/research/0002NX-0002O1-clan-name-raw-constructor-source-placement.md`

Modified:

- None outside this report.

## Confidence

Recommendation confidence: high.

Reason:

- The class identity, raw body boundaries, vtable stores, target scores, and owner routes are strongly documented by A001/C001/A003 and reconfirmed through Wave2 and local PE family checks.
- The broad family pattern resolves the main heuristic question: these two targets are not anomalous dead-code candidates; they are part of a consistent retained raw-constructor emission pattern.
- The remaining uncertainty is original build/source cause, not classification. Without object/source metadata or a runtime trace, the exact cause cannot be proven safely enough to emit final C++ or reclassify as dead.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002NX-0002O1-clan-name-raw-constructor-source-placement.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002NX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
