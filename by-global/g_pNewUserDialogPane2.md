*** UID:0002X3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class NewUserDialogPane2;

NewUserDialogPane2 *g_pNewUserDialogPane2 = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pNewUserDialogPane2

## Status

- Address: `0x0069b4a4` (`unk_69B4A4` in the current live IDB; historical docs used `dword_69B4A4`).
- Type: `NewUserDialogPane2 *`.
- Owner file: [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md), under the create-user/login dialog family.
- Disposition: reconstructable NexusTK singleton global.
- Rebuild handling: sole external-linkage source definition at position `0`; exact physical storage is non-emitting evidence.

## Role

`g_pNewUserDialogPane2` stores the active alternate 640x480 create-user dialog singleton. Direct `Singleton<NewUserDialogPane2>` base construction publishes the complete pane pointer, constructor fallback and compiler-generated cleanup paths clear it, the shared create-user destructor/helper island clears it, and [UID:0000PH][CloseMainMenuDialogSingletons_4F69A0](by-global/CloseMainMenuDialogSingletons_4F69A0.md) reads it while closing pre-login dialogs.

## Evidence

- Live IDA MCP session `5a570ede` reports bytes `00 00 00 00`, value `0x00000000`, and exactly six refs at `0x004f6a22`, `0x0052a597`, `0x0052a59e`, `0x0052b07a`, `0x0052f730`, and `0x0052f90d`; the three interior bytes have no refs.
- Xrefs are main-menu cleanup read `0x004f6a22`, constructor publish/fallback writes `0x0052a597` and `0x0052a59e`, constructor-adjacent cleanup clear `0x0052b07a`, singleton helper clear `0x0052f730`, and scalar deleting destructor clear `0x0052f90d`.
- [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md) and [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md) document the dialog source role, constructor/submit flow, vtable block, and login/create-user ownership.
- The exact storage split is [UID:0002X4][0x0069b4a4-0x0069b4a8.g_pNewUserDialogPane2](by-memory/0x0069b4a4-0x0069b4a8.g_pNewUserDialogPane2.md).

## Ownership Decision

Define this once in `login/NewUserDialogPane2.cpp` at source position `0`. The matching extern declaration belongs in [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md)'s H block with the class declaration. The main-menu cleanup helper is only a cross-translation-unit consumer; it does not own the declaration. [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) is a non-emitting family/index page and must not own or duplicate this global.

## Loader-Zero Storage Proof

- Target RVA `0x0029b4a4` lies in `.data` virtual extent but `0x00020ca4` bytes beyond raw-backed `.data`. It therefore has no raw file offset and is loader-zeroed.
- The executable has COFF characteristics `0x0103`, relocations stripped, zero base-relocation RVA/size, and no `.reloc` section. No relocation or raw initializer can produce historical `0xffffffff`.
- Exact physical evidence remains [UID:0002X4][0x0069b4a4-0x0069b4a8.g_pNewUserDialogPane2](by-memory/0x0069b4a4-0x0069b4a8.g_pNewUserDialogPane2.md), now `92/94`, non-reconstructable, and non-emitting.

## Direct Singleton Lifetime And Type Proof

- RTTI identifies direct base `Singleton<NewUserDialogPane2>` and records PMD `620/-1/0`, placing the empty base at `+0x26c`.
- Constructor instructions form `this+0x26c`, subtract `0x26c`, and write the complete `NewUserDialogPane2 *` to this storage. The null side writes zero. This is template base-constructor lowering rather than an authored explicit assignment.
- Current `NewUserDialogPane2` UDT is exactly `0x280` bytes. Its first derived field also begins at `+0x26c`, consistent with MSVC empty-base optimization and not with a stored Singleton member.
- Raw complete-destructor, clear-helper, and scalar deleting-destructor sites clear the same slot. Ordinary class/destructor source regenerates those operations; the physical/compiler pages remain non-emitting.

## One-Definition And Header Contract

- Exact CPP definition:

```cpp
class NewUserDialogPane2;

NewUserDialogPane2 *g_pNewUserDialogPane2 = 0;
```

- [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md) supplies one matching `extern NewUserDialogPane2 *g_pNewUserDialogPane2;` in H and declares direct `Singleton<NewUserDialogPane2>` inheritance.
- Physical UID0002X4 carries no CPP/H. This page is the only global-definition emitter and prevents duplicate storage source.
- Generated acceptance is one definition before class method children, one header extern/class declaration, no UID0002X3 or UID0002X4 empty marker, and no explicit constructor assignment.

## Rejected And Historical Assumptions

- Historical `0xffffffff` is superseded by exact PE virtual-tail and live-zero proof.
- `dword_69B4A4` and current `unk_69B4A4` are binary-analysis aliases, not source names.
- File-local `static`, MainMenu ownership, mixed-aggregate ownership, duplicate physical emission, and explicit constructor publication are rejected by cross-module use, direct Singleton RTTI/lowering, and one-definition rules.

## 2026-06-21 B010 Source-Quality Sync

- B010 confirms `g_pNewUserDialogPane2` as the source-facing singleton name for `0x0069b4a4`; raw `dword_69B4A4` remains an IDA alias only.
- The exact source owner is [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md) / [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md), with method-body evidence in [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md).
- [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md) and [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md) are non-emitting context/lifecycle evidence only.

## Cross-References

- [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md)
- [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md)
- [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md)
- [UID:0002SH][0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData](by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md)
- [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md)

## Changes

- 2026-06-07 Batch 043: Created canonical global page for the exact `0x0069b4a4` singleton slot. Evidence: live IDA MCP confirmed the item bounds, initial value, six xrefs, and direct ownership by `NewUserDialogPane2` constructor/destructor/helper paths.
- 2026-06-12 C001 Batch C001-020: Raised `86/88` to `87/90` and corrected the initial value from stale `0xffffffff` to current `0x00000000` after live IDA MCP `get_bytes` returned `00 00 00 00`; `xrefs_to` still reports the same six lifecycle refs.
- 2026-06-21 B010 source-quality sync: ownership remains [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md); added explicit non-emitting parent/index policy and raw-name rejection.
- 2026-07-28 B003 UID0002X4 implementation callback: raised `87/90` to `92/94`, assigned source position `0`, added the sole external-linkage CPP definition, incorporated exact PE loader-zero/no-relocation proof, direct Singleton RTTI/PMD and EBO lifetime cause, one-definition/header contract, generated acceptance, and superseded raw-name/value/duplicate-emitter assumptions.
