*** UID:0000AL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Concrete PlainMemberFunctionObjectT<MusicControlDialog, StringBaseW> instantiation.
// The reusable declaration is emitted by [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md); the invoke wrapper is covered by [UID:0002N2][0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke](by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6

## Status

- Confidence: strong for `MusicControlDialog` folder-selection callback wrapper role.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) template support, instantiated by [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md).
- Parent gate: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) and this wrapper both clear the current direct-parent documentation gate.
- Rebuild handling: source-declared/generated-binary; the reusable callback-template declaration belongs with `FunctionObjects`, while the exact vtable bytes and instantiation glue are compiler/linker output from that declaration and the `MusicControlDialog` construction site.
- Canonical metadata name is longer and expands the `mystr::StringBase<wchar_t>` argument type.

## Class Purpose

This compiler-emitted callback wrapper forwards a selected folder path from [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md) to a `MusicControlDialog` member function. It copies the incoming wide string, adjusts the stored owner pointer, and invokes the captured member callback.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `Invoke(const mystr::StringBase<wchar_t>&)` | [UID:0002N2][0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke](by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md) | Copies the string argument and calls the stored `MusicControlDialog` member callback; the exact target page now carries B001 current MCP proof and a formal comment-only no-code proof instead of a handwritten wrapper body. |
| scalar deleting destructor | [UID:0002N3][0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor](by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md) | Resets the string callback vtable, destroys `LObject`, and conditionally deletes storage. |

## Evidence Notes

- [UID:0001CP][0x00528e60-0x0052a535.MusicControlDialog](by-memory/0x00528e60-0x0052a535.MusicControlDialog.md) already places this wrapper inside the music-dialog helper island.
- 2026-06-14 C001 IDA MCP `lookup_funcs` confirms the invoke body at `0x0052a3e0` size `0x5e`, the adjustor thunk at `0x0052a43e` size `0x0b`, the scalar deleting destructor at `0x0052a4a0` size `0x3e`, and the following `MusicControlDialog` scalar deleting destructor boundary at `0x0052a4e0`.
- `xrefs_to 0x0052a3e0` and `0x0052a4a0` reports vtable/data references at `0x0061fcf8` and `0x0061fcec`, while the construction site stores the destructor vtable at `0x00529842` and the bound `MusicControlDialog` member target `0x00529ee0` at `0x00529848`.
- `analyze_function 0x0052a3e0` shows the wrapper copying the incoming string, adjusting the stored owner pointer, invoking the captured member callback, and cleaning up the temporary string object.
- 2026-05-31 IDA MCP recheck confirms exact ranges `0x0052a3e0-0x0052a43e` and `0x0052a4a0-0x0052a4de`, no direct callers, and vtable/data references at `0x0061fcf8` and `0x0061fcec`.
- 2026-06-25 B009 accepted MCP recheck on session `80de0a67` decodes the concrete vtable relationship at report-level detail: `0x0061fcec ->` [UID:0002N3][0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor](by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md) and `0x0061fcf8 ->` [UID:0002N2][0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke](by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md). The command-handler construction path writes the concrete vtable at `0x00529842`, writes bound member target `0x00529ee0` at `0x00529848`, writes zero `this` adjustment at `0x0052984f`, and writes the `MusicControlDialog` object pointer at `0x00529856`. This confirms that the invoke/destructor no-direct-caller state is vtable dispatch, while MusicControlDialog remains the construction/target context rather than the reusable wrapper owner.
- 2026-06-25 B001 target-specific invoke proof keeps this class score unchanged but strengthens [UID:0002N2][0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke](by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md): MCP session `80de0a67` proves `sub_52A3E0` size `0x5e` / 94 bytes, no code callers, one data xref from vtable slot `0x0061fcf8`, no byte refs to the slot address itself, and the invoke body's indirect call through fields `+0x8`, `+0x0c`, and `+0x10`. The target's formal C++ should therefore be a comment-only no-code proof through this concrete template wrapper, not an empty marker and not a decompiler-shaped concrete method body.

## Ownership Boundaries

| Owner | Boundary |
| --- | --- |
| [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) | Parent source home for the reusable callback wrapper/template pattern and declaration shape. |
| [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md) | Consumer and construction context for the bound member function that receives the selected folder path. |
| [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md) | Caller/producer context for the selected folder string only; it does not own this wrapper implementation. |
| Long generated class file name | Rejected as final source owner; it is a generated binary/template instantiation artifact, not a standalone original `.cpp`. |

Current owner/emitter routing remains [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md). [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md) owns the construction site and callback target, but the reusable wrapper declaration/template belongs with the FunctionObjects support module; [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md) only supplies the selected string.

## Score Rationale

| Field | Value | Rationale |
| --- | --- | --- |
| Completion | 86 | Exact invoke/destructor child pages, FunctionObjects/MusicControlDialog/FolderSelectDialog ownership split, source-declared/generated-binary handling, IDA-confirmed bounds and vtable/data refs, construction-site store evidence, and parent-gate status are documented. The page stays below higher completion because final template declaration spelling, original header shape, and exact source-expression spelling remain open. |
| Confidence | 88 | Current and prior IDA checks plus exact child pages strongly support the wrapper role, boundaries, vtable-only dispatch, construction-site field layout, and owner split. Confidence remains below near-final because final template/header names and the original construction-site source spelling are still inferred rather than fully reconstructed. |

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:00008U][MusicControlDialog](by-class/MusicControlDialog.md)
- [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md)
- [UID:0002N2][0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke](by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md)
- [UID:0002N3][0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor](by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md)

## 2026-06-29 Empty-Emitter Closeout

This row is the concrete `PlainMemberFunctionObjectT<MusicControlDialog, StringBaseW>` instantiation anchor. The reusable declaration is emitted by [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md), and the exact invoke wrapper is covered by [UID:0002N2][0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke](by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md).

Current MCP revalidated child destructor [UID:0002N3][0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor](by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md) at `0x0052a4a0` as 0x3e-byte compiler scalar deleting destructor glue with the concrete callback vtable-data ref at `0x0061fcec` and scalar delete size `0x18`. UID0002N3 is intentionally non-emitting with blank formal C++; source representation is this concrete instantiation plus the shared declaration, while source-level construction remains in the MusicControlDialog command-handler family.

## Changes

- Before: completion/confidence metadata were `0/0` even though the page documented the `MusicControlDialog` folder-selection callback wrapper, invoke body, scalar deleting destructor, and vtable/data evidence.
- Changed to: `COMPLETION:72` and `CONFIDENCE:82`.
- Evidence: the page links the wrapper to the music-dialog helper island, records the string-argument invoke and destructor ranges, and notes vtable/data xrefs; remaining gaps are final canonical template spelling and allocation/caller context.

- 2026-05-31 exact-page split:
  - What existed before: the two methods were documented only as raw address ranges on this class page.
  - Changed to: exact by-memory pages [UID:0002N2][0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke](by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md) and [UID:0002N3][0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor](by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md), metadata `RECONSTRUCTABLE:TRUE`, and scores `78/86`.
  - Summary/evidence: 2026-05-31 IDA MCP confirms exact function starts/sizes, vtable/data xrefs, and lack of normal callers; final C++ remains blank because the original template declaration and construction-site source shape are not fully audited.

- 2026-06-06 A004 parent-gate cleanup:
  - What existed before: the page still carried generated-source-owner framing and had no parent UID even though both the `FunctionObjects` parent and this child now satisfy the attachment threshold.
  - Changed to: `COMPLETION:80`, legacy parent metadata for [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), explicit source-declared/generated-binary handling, ownership-boundary table, score rationale, and removal of the stale recovered-file source owner line.
  - Summary/evidence: the exact invoke/destructor children, IDA vtable/data references, and documented folder-selection callback role support attachment to `FunctionObjects`; final C++ remains blank because the original template/header spelling and construction site still need a near-final audit.
- 2026-06-14 C001 Goal 2 IDA refresh:
  - Before: `80/86`, with stale parent-threshold wording.
  - After: `86/88`, with live IDA 9.1 evidence for invoke/destructor sizes, adjustor/neighbor boundaries, vtable slots, construction-site stores, the bound `MusicControlDialog` member target, and invoke-body semantics. Owner/emitter routing remains [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md); final C++ stays blank until template/header spelling and construction-site source are final-quality.
- 2026-06-25 B009 support sync:
  - Score and metadata unchanged at `86/88`, owner/emitter [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), and blank formal C++.
  - Added accepted MCP session `80de0a67` evidence tying concrete vtable slot `0x0061fcec` to [UID:0002N3][0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor](by-memory/0x0052a4a0-0x0052a4de.MusicControlDialogFolderCallbackDestructor.md), invoke slot `0x0061fcf8` to [UID:0002N2][0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke](by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md), and construction-site stores at `0x00529842`, `0x00529848`, `0x0052984f`, and `0x00529856`.
- 2026-06-25 B001 0002N2 implementation sync:
  - Score and metadata unchanged at `86/88`, owner/emitter [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), and blank class-level formal C++.
  - Added target-specific proof that [UID:0002N2][0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke](by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md) now carries current MCP evidence and should emit only its formal comment-only no-code proof through this concrete template wrapper.
