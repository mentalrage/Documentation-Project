*** UID:0002X7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class NewCreateUserDialogPane;

NewCreateUserDialogPane *g_pNewCreateUserDialogPane = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pNewCreateUserDialogPane

## Status

- Address: semantic source object backed physically by `[0x0069b4a8,0x0069b4ac)`; verified supervisor Gate 2B catalog entry `0362` now models that exact range as one size-four data item named `g_pNewCreateUserDialogPane` and typed `NewCreateUserDialogPane *`.
- Type: `NewCreateUserDialogPane *`.
- Owner file: [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md), under the create-user/login dialog family.
- Disposition: reconstructable NexusTK singleton global and sole external-linkage definition emitter.
- Rebuild handling: authored semantic definition at source position `0`; physical address storage and Singleton lowering are generated binary consequences.

## Role

`g_pNewCreateUserDialogPane` stores the active newer create-user dialog singleton. Direct `Singleton<NewCreateUserDialogPane>` construction publishes the complete object; constructor fallback/unwind and generated teardown paths clear it; [UID:0000PH][CloseMainMenuDialogSingletons_4F69A0](by-global/CloseMainMenuDialogSingletons_4F69A0.md) reads it while closing pre-login dialogs. The authored source contains one zero-initialized external pointer definition, not handwritten publication/clear code.

## Evidence

- Current physical storage is one exact four-byte `NewCreateUserDialogPane *` data item with four zero bytes, six refs at `0x0069b4a8`, and zero refs at each interior byte. IDA uses the source-facing `g_pNewCreateUserDialogPane` name; an incomplete no-layout `NewCreateUserDialogPane` type provides only the pointer identity and does not invent class layout.
- Catalog entry `0362` applied the regular comment `Active NewCreateUserDialogPane singleton pointer; loader-zeroed before newer create-user dialog construction.` and repeatable comment `NewCreateUserDialogPane *g_pNewCreateUserDialogPane; Singleton<NewCreateUserDialogPane> publishes and clears this external-linkage storage.`
- Catalog entry `0362` action-time save proof is SHA256 `3C8F31781C94DF74AADDB65B3D944CD2CA4387C448918BBBFFD60B41C3625B69`, 143,191,631 bytes, saved `2026-07-29T14:12:44.7229687-04:00`; backup `E:/NTK/Resources/NexusTK/backups/NexusTK.exe.pre-B008-UID0002X8-20260729-1412.i64` preserves historical prestate SHA256 `0E0AF938...AB481`. Later shared-IDB SHA256 values `296ED21C...63CF8B` and `905D1AB1...604C1` are dated no-drift checkpoints. The current authoritative save is SHA256 `412DA7E81557538D283BBFBC18875CACC6C1DBBC662E88BEC71307E0AE0519CD`, 143,191,140 bytes, saved `2026-07-29T15:00:32.0998001-04:00`; read-only MCP session `1da2b2ae` reconfirmed no target, neighbor, xref, byte, comment, type, or RTTI drift.
- Xrefs are main-menu cleanup read `0x004f6a13`, constructor publish/fallback writes `0x0052c3b8` and `0x0052c3bf`, constructor-adjacent cleanup clear `0x0052cd7a`, singleton helper clear `0x0052f720`, and scalar deleting destructor clear `0x0052f89d`.
- PE proof is exact: target RVA `0x29b4a8` is `0x2e4a8` into virtual `.data`, `0x20ca8` beyond its `0xd800` raw-backed payload. The image has no relocation directory capable of supplying an initializer. Windows loader zero-fill therefore explains `00 00 00 00`, rejecting historical `0xffffffff`.
- RTTI directly names both `NewCreateUserDialogPane` and `Singleton<NewCreateUserDialogPane>`. The Singleton base descriptor has PMD `620/-1/0` (`+0x26c`) and attributes `0x40`; constructor adjustment through `this+0x26c` then `-0x26c` identifies compiler Singleton publication rather than handwritten assignment.
- [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md) and [UID:00008Z][NewCreateUserDialogPane](by-class/NewCreateUserDialogPane.md) document the dialog source role, constructor/submit flow, vtable block, and login/create-user ownership.
- The exact storage split is [UID:0002X8][0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane](by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md).

## Ownership Decision

Define this exactly once in `login/NewCreateUserDialogPane.cpp` through [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md), at position `0`. The main-menu cleanup helper is only a consumer; it does not own the declaration. [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) is a non-emitting family/index page and must not own or emit this global. Physical child [UID:0002X8][0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane](by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md) is false/non-emitting evidence, preventing a duplicate definition.

## Source Definition And Header Contract

- Exact CPP definition emitted by this page:

```cpp
class NewCreateUserDialogPane;

NewCreateUserDialogPane *g_pNewCreateUserDialogPane = 0;
```

- This page's H block is intentionally blank. [UID:00008Z][NewCreateUserDialogPane](by-class/NewCreateUserDialogPane.md) owns the complete class declaration, direct Singleton base, and one matching `extern NewCreateUserDialogPane *g_pNewCreateUserDialogPane;` declaration in its H channel.
- The plain forward declaration, raw pointer, C++03 zero literal, and `.cpp` definition are consistent with the project's late-1999 through mid-2000s source style. No IDA alias, explicit address, or decompiler-derived storage representation appears in emitted source.
- Constructor source initializes the Singleton base and does not explicitly assign this global. Ordinary destructor/class declarations similarly regenerate all clear-helper and scalar-wrapper stores.

## Physical Storage And Boundary Contract

- [UID:0002X8][0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane](by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md) is the exact four-byte loader-zeroed storage child and canonical physical evidence page.
- Current IDA readback matches the semantic definition without creating a second source emitter: one typed/named physical item, exact regular/repeatable source-role comments, unchanged zero bytes and six-start/zero-interior xrefs, and unchanged predecessor/successor state. The physical page remains false/non-emitting despite the improved IDA model.
- The predecessor `g_pNewUserDialogPane2` slot occupies `[0x0069b4a4,0x0069b4a8)` with six refs. The successor `g_pServerSelectPane` slot occupies `[0x0069b4ac,0x0069b4b0)` with seven refs. Neither belongs to this semantic global.
- Mixed aggregate [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md) remains parentless/non-emitting and cannot replace the semantic definition route.

## Rejected And Historical Alternatives

- `dword_69B4A8`, pre-Gate2B `unk_69B4A8`, and `0xffffffff` are traceability/history only. The raw names are not current IDA or source identities, and PE/current-byte evidence disproves the sentinel initializer.
- Reject duplicate emission from the physical by-memory page, mixed aggregate, main-menu consumer, vtable page, or lifecycle island.
- Reject handwritten constructor publication, standalone authored clear helpers, explicit vptr/RTTI arrays, scalar-deleting-destructor bodies, and address-based globals. Those are compiler-generated consequences of the ordinary class/global source model.
- No direct constructor xref, VA/RVA pointer hit, or direct branch/call target survives. That evidence caps class/file confidence but does not weaken this global's type, identity, definition, or source owner.

## Score Rationale

- Completion `92`: exact physical storage, loader-zero/relocation proof, six-reference lifecycle, direct Singleton cause, source/header channel separation, sole-emitter placement, protected boundaries, generated disposition, and rejected historical alternatives are complete.
- Confidence `94`: class identity, pointer role, lifecycle, owner, and one-definition route are directly corroborated. Exact original spelling and lexical zero token remain inferred but are high-probability and source-appropriate.

## 2026-06-21 B010 Source-Quality Sync

- B010 confirms `g_pNewCreateUserDialogPane` as the source-facing singleton name for `0x0069b4a8`; raw `dword_69B4A8` remains an IDA alias only.
- The exact source owner is [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md) / [UID:00008Z][NewCreateUserDialogPane](by-class/NewCreateUserDialogPane.md), with method-body evidence in [UID:0002QS][0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore](by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md).
- The no-direct-caller status for constructor `0x0052c360` is retained as reachability evidence, not as a global ownership blocker. The constructor, vtable stores, singleton lifecycle refs, and scalar deleting destructor all point to this class-specific singleton.
- [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md) and [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md) are non-emitting context/lifecycle evidence only.

## Cross-References

- [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md)
- [UID:00008Z][NewCreateUserDialogPane](by-class/NewCreateUserDialogPane.md)
- [UID:0002QS][0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore](by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md)
- [UID:0002SJ][0x0061fda0-0x0061fe3c.NewCreateUserDialogPaneVtableData](by-memory/0x0061fda0-0x0061fe3c.NewCreateUserDialogPaneVtableData.md)
- [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md)

## Changes

- 2026-06-07 Batch 043: Created canonical global page for the exact `0x0069b4a8` singleton slot. Evidence: live IDA MCP confirmed the item bounds, initial value, six xrefs, and direct ownership by `NewCreateUserDialogPane` constructor/destructor/helper paths.
- 2026-06-12 C001 Batch C001-020: Raised `86/88` to `87/90` and corrected the initial value from stale `0xffffffff` to current `0x00000000` after live IDA MCP `get_bytes` returned `00 00 00 00`; `xrefs_to` still reports the same six lifecycle refs.
- 2026-06-21 B010 source-quality sync: ownership remains [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md); added explicit non-emitting parent/index policy, retained/no-direct-caller caveat, and raw-name rejection.
- 2026-07-29 B008 UID0002X8 Rule 26 implementation: raised `87/90` to `92/94`, set source position `0`, populated the sole CPP definition, retained a blank H block, and incorporated PE loader-zero proof, six exact refs, direct Singleton RTTI/PMD/lowering, physical-child no-code routing, header ownership, protected boundaries, generated-code exclusions, and historical raw-name/`0xffffffff` rejection.
- 2026-07-29 supervisor Gate 2B catalog entry `0362`: normalized the physical storage to the exact source-facing pointer item and comments while preserving bytes, xrefs, neighbors, and RTTI dependencies; action-time saved IDB SHA256 was `3C8F31781C94DF74AADDB65B3D944CD2CA4387C448918BBBFFD60B41C3625B69`, with `0E0AF938...AB481` retained only as backed-up pre-action history. Dated checkpoints `296ED21C...63CF8B`/`905D1AB1...604C1` and current shared-IDB SHA256 `412DA7E8...519CD` preserve the applied state.
