*** UID:0000HK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# AttachedObjectPaneHelper_53AEC0

## Status

- Confidence: strong that `0x0053aec0` is real detach-registry code; low that this was an original standalone source file.
- Proposed owner: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md), likely as a private helper/registry method in `map/AttachedObjectPane.cpp`.
- Historical generated label: `AttachedObjectPaneHelper_53AEC0`; no standalone final source file is recommended.
- Main address doc: [UID:0001DF][0x0053aec0-0x0053b011.AttachedObjectDetachRegistry](by-memory/0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md)

## File Role

This page exists to quarantine a one-method file split. The method removes an `AttachedObjectPane`-derived overlay from an owner/registry object when the overlay is destroyed.

The method is called only from `AttachedObjectPane::~AttachedObjectPane` at `0x005382b0`. The destructor reads its registry pointer from `AttachedObjectPane + 0x128` and calls `sub_53AEC0(registry, this)`, so the recovered helper class label should not drive final source layout.

## Ownership Decision

Do not create a final `AttachedObjectPaneHelper_53AEC0.cpp` source file unless later evidence recovers a broader named manager class around the same object layout.

For now, fold the function into [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) as a private registry/list cleanup helper:

| Entity | Evidence | Proposed placement |
| --- | --- | --- |
| `AttachedObjectPaneHelper_53AEC0::DetachAttachedObject` | `0x0053aec0-0x0053b011`; only caller is `AttachedObjectPane::~AttachedObjectPane` | Private helper in `map/AttachedObjectPane.cpp`; exact reconstructable body tracked by [UID:0001DF][0x0053aec0-0x0053b011.AttachedObjectDetachRegistry](by-memory/0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md). |
| registry layout | list pointers at `+0x170` and `+0x174`; singleton slots at `+0x1d8-0x1e4` | [UID:0001TR][AttachedObjectRegistryLayout](by-type/by-struct/AttachedObjectRegistryLayout.md). |
| [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` | Historical generated alias `g_attachmentModeFlag` is misleading; broad UI/render mode selector with 366 xrefs | Canonical global, not attachment-specific state. |

## Evidence Notes

- 2026-05-25 IDA MCP recheck: the helper still appeared in historical generated output as standalone `AttachedObjectPaneHelper_53AEC0::DetachAttachedObject` and carried the misleading `g_attachmentModeFlag` alias for canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97`.
- 2026-05-26 IDA MCP recheck: the helper remains a one-method split candidate, and IDA caller/xref evidence is unchanged.
- IDA MCP `lookup_funcs` confirms `sub_53AEC0` at `0x0053aec0` with size `0x152`.
- IDA MCP `callers` and `xrefs_to` report a single code caller at `0x005382b0` inside `sub_538100`, the `AttachedObjectPane` non-deleting destructor.
- IDA decompilation of `0x00538100` shows the call shape `sub_53AEC0(*(this + 0x128), this)`.
- IDA decompilation of `0x0053aec0` confirms registry offsets `+0x170`, `+0x174`, `+0x1d8`, `+0x1dc`, `+0x1e0`, and `+0x1e4`.
- The helper reads the attached object's type byte at `attachedObject + 0xf8`.
- The helper removes type `2` and type `4` objects from registry lists and clears type `6`, `7`, `8`, and `9` singleton slots. Type `8` clears only when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` is `1`.
- IDA MCP `py_eval` on 2026-05-26 reconfirmed 366 xrefs to [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97`, so the recovered alias remains a broad UI/render mode byte rather than attachment-specific state.

## Non-Standalone File State

- `PROPOSED_RECONSTRUCTION_PATH:"NONE"` is intentional. This page is a quarantine record for a rejected one-method source-file split, not a source root.
- The reconstructable implementation is tracked by [UID:0001DF][0x0053aec0-0x0053b011.AttachedObjectDetachRegistry](by-memory/0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md), now attached to [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md).
- Keep this page in coverage as ignored/non-standalone until a broader real registry owner class or source file is found.

## Cross-References

- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md)
- [UID:00000N][AttachedObjectPaneHelper_53AEC0](by-class/AttachedObjectPaneHelper_53AEC0.md)
- [UID:0001DF][0x0053aec0-0x0053b011.AttachedObjectDetachRegistry](by-memory/0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md)
- [UID:0001TR][AttachedObjectRegistryLayout](by-type/by-struct/AttachedObjectRegistryLayout.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)

## Changes

- 2026-06-07 A008 alias cleanup:
  - Before: the ownership table and evidence notes still foregrounded the misleading generated `g_attachmentModeFlag` name and bare `byte_66DA97` alias.
  - Changed to: canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) wording while preserving `byte_66DA97` as the IDA lookup alias.
  - Evidence: the documented 366-xref global usage remains broad UI/render mode state, not attachment-specific state.
- 2026-06-06 non-standalone coverage cleanup:
  - Before: the page had `NONE` path and rejected standalone ownership but still scored `74/88`, and the manual file-coverage row still listed it as reconstructable.
  - Changed to: `80/88`, explicit non-standalone file state, exact memory helper ownership, and historical generated-label wording.
  - Evidence: single caller from `AttachedObjectPane::~AttachedObjectPane`, exact helper page [UID:0001DF][0x0053aec0-0x0053b011.AttachedObjectDetachRegistry](by-memory/0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md), and current source root [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md).
- 2026-06-05: Marked the projected reconstruction path as `NONE`.
  - Before: the path was blank, which left this reviewed helper quarantine in file-coverage error state.
  - After: the page is explicitly classified as a non-standalone by-file page; no `AttachedObjectPaneHelper_53AEC0.cpp` should be emitted.
  - Evidence: live IDA MCP `lookup_funcs` confirms `sub_53AEC0` at `0x0053aec0` (`0x152` bytes), and `callers` again reports the single direct caller at `0x005382b0` inside `sub_538100`, matching the documented `AttachedObjectPane` destructor ownership.
- What existed before: the page quarantined the recovered helper split but had unevaluated scores.
- What it was changed to: scores were set to `74/88`.
- Summary and evidence: the code behavior and non-standalone ownership decision are strongly supported by IDA caller/xref evidence; completion is lower because this should likely be folded into `AttachedObjectPane.cpp` after migration.
- 2026-06-06: Replaced stale recovered-source provenance wording without changing score or path.
  - Before: status, file role, ownership evidence, and scoring notes described the quarantine in terms of stale recovered-source ownership.
  - After: kept `74/88` and `PROPOSED_RECONSTRUCTION_PATH:"NONE"`, but framed the page as a recovered one-method split rejected by IDA caller/xref evidence.
  - Evidence: `0x0053aec0` still has a single direct caller from `AttachedObjectPane::~AttachedObjectPane`, the registry offsets are documented by IDA decompilation, and the broad [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97` xref set keeps the mode byte out of attachment-specific ownership.
