*** UID:0000V9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ProfileDialogDestructorAndRefreshHelpers_53fda0_53fe90

## Status

- Confidence: strong for helper behavior, medium for final emitted-source modeling policy.
- Current generated-code caveat: `0x0053fda0` and `0x0053fe90` are not modeled as ordinary ProfileDialog methods in the active generated file; generated destructor labels the shared base teardown through `TransferReplyAlert`.
- Proposed owner file: [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md), with `0x0053fe90` also calling into [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md).
- Rebuild handling: mixed `source-declared/generated-binary` destructor/thunk output plus a tiny `source-authored` or source-visible refresh wrapper. Keep parent attachment and C++ blank until the ProfileDialog source shape and surrounding destructor islands reach the 95% gate.

## Helper Summary

| Address range | Proposed role | Behavior |
| --- | --- | --- |
| `0x0053fda0-0x0053fdbf` | non-deleting destructor helper | Restores the three `ProfileDialog` vtables, then tail-jumps to the shared `DialogPane`/base teardown helper currently named by IDA as `0x0049d9f0`. |
| `0x0053fe90-0x0053fe9b` | profile refresh wrapper | Tiny file-local wrapper that loads `dword_67A764` into `ecx` and jumps to `RefreshSelectedProfileData` at `0x005063e0`. |
| `0x00542639-0x00542644` | adjustor thunk | Adjusts `this` by `-0xa0` bytes and forwards to `0x005429a0`; exact range is now part of [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md). |
| `0x00542644-0x0054264f` | adjustor thunk | Adjusts `this` by `-0xa4` bytes and forwards to `0x005429a0`; exact range is now part of [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md). |
| `0x005429a0-0x005429f5` | scalar deleting destructor | Restores the three `ProfileDialog` vtables, calls shared base teardown, and conditionally frees memory; exact wrapper is now part of [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md). |

## IDA MCP Evidence

Checked on 2026-05-24:

- `lookup_funcs` confirms all helper starts above plus `ProfileDialog::ProfileDialog` at `0x0053f940` and action handler `0x0053fdc0`.
- Decompilation of `0x0053fda0` restores `ProfileDialog` vtables at complete-object offsets `+0x0`, `+0xa0`, and `+0xa4`, then calls the shared base teardown at `0x0049d9f0`.
- `xrefs_to 0x0053fda0` reports no direct xrefs, consistent with a non-virtual cleanup/unwind helper rather than ordinary action logic.
- Decompilation of `0x005429a0` mirrors the same vtable restore and base teardown before conditional delete.
- `xrefs_to 0x00542639` and `xrefs_to 0x00542644` report vtable/data refs at `0x00620fe0` and `0x00621010`; both forward to `0x005429a0`.
- Decompilation of `0x0053fe90` is a one-call wrapper to `0x005063e0`; `xrefs_to 0x0053fe90` reports no direct xrefs, while `xrefs_to 0x005063e0` includes `ProfileDialog::HandleDialogAction` at `0x0053fe65` and the wrapper at `0x0053fe96`.
- `ProfileDialog::HandleDialogAction` copies accepted profile text into the config/profile buffer at `dword_67A7C8 + 2691768`, calls the dialog close/apply helper, then calls `RefreshSelectedProfileData`.

Rechecked on 2026-05-31:

- IDA reports `0x0053fda0` as function `sub_53FDA0` with exclusive end `0x0053fdbf`; no direct xrefs were reported. It writes ProfileDialog vtables at complete-object offsets `+0x0`, `+0xa0`, and `+0xa4`, then calls `0x0049d9f0`.
- IDA reports `0x0053fe90` as function `sub_53FE90` with exclusive end `0x0053fe9b`; it calls only `0x005063e0` and has a data reference to `dword_67A764`.
- IDA reports the adjustor thunk starts at `0x00542639` and `0x00542644`, both forwarding to `0x005429a0`, with data refs from the secondary ProfileDialog vtables.
- IDA reports `0x005429a0` as a scalar deleting destructor body ending exclusively at `0x005429f5`; it restores the same three ProfileDialog vtables, calls `0x0049d9f0`, and conditionally frees via `0x004f4ac0`.

Rechecked on 2026-06-01:

- IDA confirms the same helper endpoints: `0x0053fda0-0x0053fdbf`, `0x0053fe90-0x0053fe9b`, `0x00542639-0x00542644`, `0x00542644-0x0054264f`, and `0x005429a0-0x005429f5`.
- Xrefs remain consistent with destructor/vtable ownership: `0x0053fda0` and `0x0053fe90` have no direct refs; `0x00542639` is referenced from `0x00620fe0`; `0x00542644` is referenced from `0x00621010`; `0x005429a0` is referenced by `0x00620f80` and the two adjustor jumps at `0x0054263f`/`0x0054264a`.
- Raw bytes confirm the local wrapper boundary: `0x0053fe87-0x0053fe90` and `0x0053fe9b-0x0053fea0` are `0xcc` alignment padding.

## Ownership Decision

Keep the destructor/thunk island with `ProfileDialog.cpp`. The generated `TransferReplyAlert::~DialogPane` spelling is base-owner pollution: `0x0049d9f0` is a broad shared dialog/base teardown helper, not proof that `ProfileDialog` depends on a transfer-alert class.

Keep the real profile sidecar work at `0x005063e0` with `ProfileStorage.cpp`, but document `0x0053fe90` as a small ProfileDialog-side wrapper because it sits in the dialog neighborhood and forwards directly to that storage helper.

## Cross-References

- [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md)
- [UID:0000AU][ProfileDialog](by-class/ProfileDialog.md)
- [UID:0001DT][0x0053f940-0x0053fe87.ProfileDialog](by-memory/0x0053f940-0x0053fe87.ProfileDialog.md)
- [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md)
- [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md)
- [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md)
- [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md)
- [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md)

## Changes

- What existed before: the thunk and scalar deleting destructor ranges were documented one byte short.
- What it was changed to: the adjustor thunks now use `0x00542639-0x00542644` and `0x00542644-0x0054264f`; the scalar deleting destructor now uses `0x005429a0-0x005429f5`.
- Summary and evidence: IDA MCP review on 2026-05-28 resolved the shared thunk and scalar deleting destructor island endpoints.
- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with moderate completion and strong confidence, while parent attachment and C++ remain blank.
- Summary and evidence: IDA MCP verification on 2026-05-31 reconfirmed the destructor helper, adjustor thunk, scalar deleting destructor, and refresh wrapper behavior. The score remains below 95 because final emitted-source modeling and exact source placement across ProfileDialog/ProfileStorage/base-dialog teardown still need a full audit.
- 2026-06-01: Changed completion/confidence from `70/85` to `72/88`, attached parent [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md), and corrected the local helper endpoints to exclusive-end ranges.
  - Before: the helper table still used `0x0053fda0-0x0053fdbe` and `0x0053fe90-0x0053fe9a`, and parent attachment was blank.
  - After: current IDA MCP evidence records the exact helper ends, wrapper boundary padding, and vtable/destructor xrefs. C++ remains blank pending final emitted-source policy.
