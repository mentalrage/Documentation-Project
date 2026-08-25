*** UID:0000QZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
FpsPane *g_pFpsPane = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pFpsPane

## Status

- Symbol kind: global pointer
- Address: `0x0069b334` (`dword_69B334` in IDA)
- Likely type: `FpsPane*`
- Likely owner file: [UID:0000JK][FpsPane](by-file/FpsPane.md)
- Owner class: [UID:00005F][FpsPane](by-class/FpsPane.md)
- Confidence: very strong for address, owner, exact pointer width, loader-zero initialization, three lifecycle refs, Singleton publication/clear source shape, and one-definition routing; exact original lexical spelling remains inferred.
- Owner/emitter route: [UID:0000JK][FpsPane](by-file/FpsPane.md); this page emits the sole exact source definition while UID0002W0 emits only a covered-storage comment and UID00005F centralizes the extern declaration.

## Behavior

`g_pFpsPane` stores the active FPS overlay singleton. The raw constructor-shaped span [UID:00015C][0x004b6410-0x004b646b.FpsPaneConstructorRaw](by-memory/0x004b6410-0x004b646b.FpsPaneConstructorRaw.md) writes the owner pointer, while both destructor paths clear it. At source level, the accepted existing project pattern represents those writes through explicit `Singleton<FpsPane>` constructor/destructor specializations rather than duplicating assignments in authored `FpsPane` bodies:

- [UID:00015E][0x004b6470-0x004b6499.FpsPaneDestructor](by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md) clears the singleton in the ordinary/non-deleting destructor body.
- [UID:00015L][0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor](by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md) clears the same singleton before base-pane cleanup and optional delete handling.

This makes the symbol source-declared global/module state for the FPS diagnostics overlay, not an independent allocator or parcel/map global.

The accepted UID0000JK reconstruction supersedes the earlier handwritten-clear interpretation: [UID:00015E][0x004b6470-0x004b6499.FpsPaneDestructor](by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md) emits an empty authored `FpsPane::~FpsPane()` body, the `Singleton<FpsPane>` destructor specialization clears this cell, and [UID:00015L][0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor](by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md) remains compiler-generated wrapper evidence.

## Evidence

- [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md) records the aggregate IDA-backed xref set for `0x0069b334` as fully inside the FpsPane diagnostics cluster.
- [UID:00015C][0x004b6410-0x004b646b.FpsPaneConstructorRaw](by-memory/0x004b6410-0x004b646b.FpsPaneConstructorRaw.md) records the constructor write at `0x004b6434`.
- [UID:00015E][0x004b6470-0x004b6499.FpsPaneDestructor](by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md) records the ordinary destructor clear at `0x004b648a`, after reinstalling the three FpsPane vtable views and before the pane base destructor.
- [UID:00015L][0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor](by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md) records the scalar deleting destructor clear at `0x004b6c70`, with vtable/thunk refs proving it is the vtable-dispatched cleanup companion.
- [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md) ties this singleton to the same three-vtable object layout and notes that `g_pFpsPane` xrefs are `0x004b6434`, `0x004b648a`, and `0x004b6c70`.
- [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md) documents the exact `FpsPane` vtable data consumed by the same constructor/destructor paths.
- [UID:0002W0][0x0069b334-0x0069b338.g_pFpsPane](by-memory/0x0069b334-0x0069b338.g_pFpsPane.md) is the exact four-byte storage child for this singleton and records the split boundaries between the exchange alert slot at `0x0069b330-0x0069b334` and `g_fpsLogEnabled` at `0x0069b338`.
- 2026-06-14 live IDA MCP xrefs reconfirmed exactly three direct refs to `0x0069b334`: raw constructor write `0x004b6434`, ordinary destructor clear `0x004b648a`, and scalar deleting destructor clear `0x004b6c70`.
- 2026-06-14 IDA MCP `analyze_component` over the FpsPane lifecycle pair reconfirmed that `sub_4B6470` and `sub_4B6C50` both access the three FpsPane vtable views `0x0061a620`, `0x0061a66c`, and `0x0061a69c`; the singleton xrefs remain confined to FpsPane lifecycle code.
- Corrected local PE section-offset checking places `0x0069b334-0x0069b338` in the virtual `.data` tail beyond initialized raw bytes. Treat any IDA `FF` rendering there as database/unbacked-tail evidence, while the source reconstruction should model a static `FpsPane*` slot with constructor/destructor writes.
- 2026-06-17 B003 local IDA export lists `.data:0069B334 dword_69B334 dd ?`; accepted PE/static-storage analysis represents the same loader-zero state explicitly as `FpsPane *g_pFpsPane = 0;`.

## Ownership Notes

Keep this global with [UID:0000JK][FpsPane](by-file/FpsPane.md) as file-local or module-global overlay state. The neighboring FPS flags [UID:0000PY][g_fpsDebugActive](by-global/g_fpsDebugActive.md) and [UID:0000PZ][g_fpsLogEnabled](by-global/g_fpsLogEnabled.md) share the same diagnostics owner; stale ParcelPane generated-data pollution applies to those flags, but not to the singleton's direct FpsPane constructor/destructor evidence.

The exact accepted definition is emitted here as `FpsPane *g_pFpsPane = 0;`. This page's H channel remains blank because UID00005F centralizes `extern FpsPane *g_pFpsPane;` in `FpsPane.h`.

## Score Rationale

Completion is `94` because the page closes the exact four-byte storage child, loader-zero initializer, three lifecycle refs, FpsPane/Singleton source shape, one-definition route, centralized extern declaration, and compiler-wrapper separation. Confidence is `96` because all direct refs remain confined to FpsPane lifecycle code and agree with the class, layout, vtable, PE-storage, and physical-child evidence; only original lexical spelling remains inferred.

## 2026-08-24 Accepted Singleton Closure

- UID0000QZ emits the sole `FpsPane *g_pFpsPane = 0;` definition.
- Explicit `Singleton<FpsPane>` constructor/destructor specializations publish and clear this same cell, matching the three observed constructor/ordinary-destructor/scalar-wrapper references while preserving an empty authored `FpsPane` destructor.
- UID0002W0 accounts for the physical bytes with a covered-storage comment. No template member storage or second pointer definition is introduced.

## Cross-References

- [UID:00005F][FpsPane](by-class/FpsPane.md)
- [UID:0000JK][FpsPane](by-file/FpsPane.md)
- [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md)
- [UID:00015C][0x004b6410-0x004b646b.FpsPaneConstructorRaw](by-memory/0x004b6410-0x004b646b.FpsPaneConstructorRaw.md)
- [UID:00015E][0x004b6470-0x004b6499.FpsPaneDestructor](by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md)
- [UID:00015L][0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor](by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md)
- [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md)
- [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md)
- [UID:0000PY][g_fpsDebugActive](by-global/g_fpsDebugActive.md)
- [UID:0000PZ][g_fpsLogEnabled](by-global/g_fpsLogEnabled.md)

## Changes

- 2026-06-20 B004 destructor source-quality sync:
  - Score unchanged.
  - Confirmed that [UID:00015E][0x004b6470-0x004b6499.FpsPaneDestructor](by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md) is the ordinary source destructor clear for `g_pFpsPane`, while [UID:00015L][0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor](by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md) is compiler-generated scalar deleting destructor evidence. The global declaration remains `FpsPane* g_pFpsPane;`; no duplicate storage or wrapper declaration is introduced.

- 2026-06-17 B003 source-quality execution:
  - Before: `86/90`, blank C++ with final declaration caveat.
  - Changed to: `87/90`, first-draft `FpsPane* g_pFpsPane;` declaration.
  - Incorporated B003 report details: local IDA export `dword_69B334 dd ?`, source zero-initialized storage, constructor write at `0x004b6434`, ordinary/scalar destructor clears at `0x004b648a`/`0x004b6c70`, and exact-memory storage page remains blank to avoid duplicate output.

- 2026-06-06 A010 evidence consolidation:
  - Before: `COMPLETION:78`, `CONFIDENCE:82`, and a short evidence note only saying the singleton was touched by constructor/destructor xrefs.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:88`, owner-class/autogen notes, exact constructor/destructor/scalar-destructor evidence, layout/vtable links, ownership notes, and the remaining C++-emission caveat.
  - Summary/evidence: existing IDA-backed pages record the singleton write at `0x004b6434`, ordinary destructor clear at `0x004b648a`, scalar deleting destructor clear at `0x004b6c70`, the enclosing `0x004b6410-0x004b6caf` diagnostics cluster, and the three FpsPane vtable views used by the same lifecycle paths.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `78/82`. Summary/evidence: the page documents address, type/owner, FPS-pane singleton behavior, constructor/destructor xrefs, and refs; it is narrower and less detailed than the related diagnostics/global flag pages.
- 2026-06-05: Marked reconstructable under [UID:0000JK][FpsPane](by-file/FpsPane.md). Evidence: live IDA MCP reports three xrefs to `0x0069b334`, confined to the `FpsPane` constructor range and destructor paths at `0x004b6470` and `0x004b6c50`.
- 2026-06-14 A002 Goal 2 by-global score pass:
  - Changed from `84/88` to `86/90`.
  - Summary/evidence: live IDA MCP reconfirmed the three direct singleton refs, the ordinary/scalar destructor functions, and the shared FpsPane vtable accesses; exact storage child [UID:0002W0][0x0069b334-0x0069b338.g_pFpsPane](by-memory/0x0069b334-0x0069b338.g_pFpsPane.md) and corrected PE section mapping now support the singleton storage and initializer caveat. Owner/emitter remain [UID:0000JK][FpsPane](by-file/FpsPane.md), with C++ still blank pending final declaration shape.
