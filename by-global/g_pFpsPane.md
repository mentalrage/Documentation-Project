*** UID:0000QZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pFpsPane

## Status

- Symbol kind: global pointer
- Address: `0x0069b334` (`dword_69B334` in IDA)
- Likely type: `FpsPane*`
- Likely owner file: [UID:0000JK][FpsPane](by-file/FpsPane.md)
- Owner class: [UID:00005F][FpsPane](by-class/FpsPane.md)
- Confidence: strong for address, owner, singleton lifetime, and destructor parity; medium-high for final source declaration spelling.
- Autogen parent: [UID:0000JK][FpsPane](by-file/FpsPane.md); C++ remains blank because final header/static declaration shape is below the `95+` source gate.

## Behavior

`g_pFpsPane` stores the active FPS overlay singleton. The raw constructor-shaped span [UID:00015C][0x004b6410-0x004b646b.FpsPaneConstructorRaw](by-memory/0x004b6410-0x004b646b.FpsPaneConstructorRaw.md) writes the owner pointer, while both destructor paths clear it:

- [UID:00015E][0x004b6470-0x004b6499.FpsPaneDestructor](by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md) clears the singleton in the ordinary/non-deleting destructor body.
- [UID:00015L][0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor](by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md) clears the same singleton before base-pane cleanup and optional delete handling.

This makes the symbol source-declared global/module state for the FPS diagnostics overlay, not an independent allocator or parcel/map global.

## Evidence

- [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md) records the aggregate IDA-backed xref set for `0x0069b334` as fully inside the FpsPane diagnostics cluster.
- [UID:00015C][0x004b6410-0x004b646b.FpsPaneConstructorRaw](by-memory/0x004b6410-0x004b646b.FpsPaneConstructorRaw.md) records the constructor write at `0x004b6434`.
- [UID:00015E][0x004b6470-0x004b6499.FpsPaneDestructor](by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md) records the ordinary destructor clear at `0x004b648a`, after reinstalling the three FpsPane vtable views and before the pane base destructor.
- [UID:00015L][0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor](by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md) records the scalar deleting destructor clear at `0x004b6c70`, with vtable/thunk refs proving it is the vtable-dispatched cleanup companion.
- [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md) ties this singleton to the same three-vtable object layout and notes that `g_pFpsPane` xrefs are `0x004b6434`, `0x004b648a`, and `0x004b6c70`.
- [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md) documents the exact `FpsPane` vtable data consumed by the same constructor/destructor paths.

## Ownership Notes

Keep this global with [UID:0000JK][FpsPane](by-file/FpsPane.md) as file-local or module-global overlay state. The neighboring FPS flags [UID:0000PY][g_fpsDebugActive](by-global/g_fpsDebugActive.md) and [UID:0000PZ][g_fpsLogEnabled](by-global/g_fpsLogEnabled.md) share the same diagnostics owner; stale ParcelPane generated-data pollution applies to those flags, but not to the singleton's direct FpsPane constructor/destructor evidence.

Do not promote this page to final C++ yet. The singleton declaration is straightforward, but the raw constructor/session boundaries and final `FpsPane` header shape are still below the `95+` code-emission gate.

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

- 2026-06-06 A010 evidence consolidation:
  - Before: `COMPLETION:78`, `CONFIDENCE:82`, and a short evidence note only saying the singleton was touched by constructor/destructor xrefs.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:88`, owner-class/autogen notes, exact constructor/destructor/scalar-destructor evidence, layout/vtable links, ownership notes, and the remaining C++-emission caveat.
  - Summary/evidence: existing IDA-backed pages record the singleton write at `0x004b6434`, ordinary destructor clear at `0x004b648a`, scalar deleting destructor clear at `0x004b6c70`, the enclosing `0x004b6410-0x004b6caf` diagnostics cluster, and the three FpsPane vtable views used by the same lifecycle paths.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `78/82`. Summary/evidence: the page documents address, type/owner, FPS-pane singleton behavior, constructor/destructor xrefs, and refs; it is narrower and less detailed than the related diagnostics/global flag pages.
- 2026-06-05: Marked reconstructable under [UID:0000JK][FpsPane](by-file/FpsPane.md). Evidence: live IDA MCP reports three xrefs to `0x0069b334`, confined to the `FpsPane` constructor range and destructor paths at `0x004b6470` and `0x004b6c50`.
