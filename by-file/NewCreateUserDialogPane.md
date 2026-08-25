*** UID:0000LP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# NewCreateUserDialogPane

## Status

- Confidence: very strong for the newer create-user dialog role, exact method/vtable/global evidence, direct Singleton source cause, login/create-user placement, separate CPP/H routing, retained-code interpretation, and exact child method-body routing; capped below final-source quality by absent direct constructor reachability and inferred original field/helper spellings.
- Proposed module: `login/NewCreateUserDialogPane.cpp` and `.h`
- Umbrella doc: [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- Evidence basis: live IDA MCP function, xref, vtable, direct Singleton RTTI/PMD and constructor lowering, loader-zero PE geometry, command-dispatch, PE reachability, and boundary checks through the 2026-07-29 UID0002X8 pass.

## File Role

`NewCreateUserDialogPane.cpp/.h` is the concrete retained newer/high-resolution create-user dialog root. It uses the newer create-user resource family, drives gender/body/totem controls, and owns a complete 16-slot constructor/selector/event/submit/account/create-character/reply source route. Its absent current constructor reference is retained-code evidence, not permission to fold or discard the class.

## Boundary Notes

Keep [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md) as the finalized adjacent standalone source/header pair. Its decorated class identity, independent method and compiler-support ranges, three-view vtable/RTTI block, complete public H contract, and this file's explicit header dependency reject the earlier fold hypothesis.

Keep [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md) as the alternate 640x480 create-character variant. Keep [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md) out of this module; that class is account registration, not character creation. [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) is now a non-emitting family/index page, so this file owns the concrete newer full-screen variant output.

## Proposed Contents

| Range | Current method family | Notes |
| --- | --- | --- |
| semantic global [UID:0002X7][g_pNewCreateUserDialogPane](by-global/g_pNewCreateUserDialogPane.md) | position-0 external definition | Emits exactly one `NewCreateUserDialogPane *g_pNewCreateUserDialogPane = 0;` definition; physical UID0002X8 is non-emitting loader-zeroed evidence. |
| class [UID:00008Z][NewCreateUserDialogPane](by-class/NewCreateUserDialogPane.md) | position-10 H declaration | Emits the complete class declaration with direct `Singleton<NewCreateUserDialogPane>` inheritance, one matching extern, inline empty destructor, four event virtuals, and exact tail state at `+0x26c/+0x270/+0x274/+0x278/+0x27c`; no H child marker or synthetic selector pointer remains. |
| `0x0052c360-0x0052cd49` | constructor | Exact formal CPP builds the full-screen dialog, all 20 controls/resources/frame tuples, three ordered random-selection phases, child-id-8 selector, focus/pending/hover state, full-screen `OnCreate`, and main-menu `OnShow`. Direct Singleton publication/vptr/EH lowering stays compiler-generated. |
| `0x0052cef0-0x0052d0ff` | gender/totem helpers | Updates gender, totem, and male/female selector state. |
| `0x0052d100-0x0052d1df` | `OpenNexonclubRegistrationOrSendCharacterRequest(bool)` | False sends immediately; true constructs the const-wide-StringBase member callback, uses localized string `227`, and transfers callback ownership to NexonclubRegistrationDialog. |
| `0x0052d1e0-0x0052d20f` | `OnNexonclubRegistrationResult(const StringBaseW&)` | Stores a non-empty account name, then unconditionally sends the create-character request. |
| `0x0052d210-0x0052d33b` | four event handlers | `OnControlCommand`, key/text and pointer/mouse base forwarders, and opcode-`0x02` packet bridge; `0x0052d050` remains explicit no-code nullsub. |
| `0x0052d3e0-0x0052dcf5` | submit/account/create-character/reply flow | Validates three edit controls, emits file-local opcode `0x02`, resolves selector child id `8` for opcode `0x04`, and handles corrected `packet[1]`/`packet[2]`/`packet+3` replies. |
| `0x0052f720`, `0x0052f751`, `0x0052f75c`, `0x0052f870-0x0052f8db` | destructor support | Singleton clear helper, two adjustor thunks, and scalar deleting destructor for this variant. |

## Evidence Notes

- 2026-06-04 live IDA MCP enumerates the exact core starts at `0x0052c360`, `0x0052cef0`, `0x0052cf80`, `0x0052d050`, `0x0052d060`, `0x0052d0b0`, `0x0052d100`, `0x0052d1e0`, `0x0052d210`, `0x0052d2f0`, `0x0052d300`, `0x0052d330`, `0x0052d3e0`, `0x0052d5b0`, `0x0052d7c0`, and `0x0052d9a0`.
- Live IDA MCP confirms constructor-side writes to singleton `0x0069b4a8` at `0x0052c3b8`/`0x0052c3bf` and vtable slots `0x0061fda0`, `0x0061fe00`, and `0x0061fe30` at `0x0052c3d3`, `0x0052c3d9`, and `0x0052c3e3`.
- Live IDA MCP caller checks still show no direct callers for `0x0052c360`. Treat this as a retained/newer dialog variant or indirect dispatch candidate until launcher reachability is reviewed.
- Live IDA MCP confirms [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md) constructor `0x004fd520` is called from `0x0052c7aa` inside this constructor.
- The `0x0052d210` command dispatcher uses a 16-case jump table: case 17 calls the submit helper `0x0052d3e0`, cases 4/5 call gender selectors `0x0052d060`/`0x0052d0b0`, and cases 9-14 call the totem/style selector helpers `0x0052cef0`/`0x0052cf80`.
- The submit path at `0x0052d3e0` calls packet helper `0x0052d5b0` at `0x0052d5a2`; reply handling at `0x0052d9a0` calls the shape-control payload builder `0x0052d7c0` at `0x0052daf6`.
- Historical 2026-06-07 Batch 043 wording described `0x0069b4a8-0x0069b4ac` as a clean `0xffffffff` singleton item, but current support docs and MCP evidence show the storage initializes to `0x00000000` (`00 00 00 00`). The six lifecycle xrefs remain: main-menu cleanup read, constructor publish/fallback clear, constructor-adjacent cleanup clear, singleton helper clear, and scalar deleting destructor clear. The exact storage has a split page [UID:0002X8][0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane](by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md) and a canonical global page [UID:0002X7][g_pNewCreateUserDialogPane](by-global/g_pNewCreateUserDialogPane.md).
- Verified supervisor Gate 2B catalog entry `0362` now models that storage as one size-four `is_data:true` item named `g_pNewCreateUserDialogPane`, typed `NewCreateUserDialogPane *`, with an intentionally incomplete no-layout class type. Exact regular/repeatable comments record the active singleton role and direct Singleton publication/clear contract; bytes remain zero, six refs remain at the start, interior refs remain zero, and neighbors plus all six RTTI dependencies remain protected.
- Catalog action-time saved-IDB proof is SHA256 `3C8F31781C94DF74AADDB65B3D944CD2CA4387C448918BBBFFD60B41C3625B69`, 143,191,631 bytes, saved `2026-07-29T14:12:44.7229687-04:00`. Backup `E:/NTK/Resources/NexusTK/backups/NexusTK.exe.pre-B008-UID0002X8-20260729-1412.i64` preserves historical pre-action SHA256 `0E0AF938...AB481`. Later shared-IDB SHA256 values `296ED21C...63CF8B` and `905D1AB1...604C1` are dated no-drift checkpoints. The current authoritative save is SHA256 `412DA7E81557538D283BBFBC18875CACC6C1DBBC662E88BEC71307E0AE0519CD`, 143,191,140 bytes, saved `2026-07-29T15:00:32.0998001-04:00`; bounded read-only MCP readback found no target or protected-dependency drift.
- PE geometry closes the initializer question: target RVA `0x29b4a8` lies `0x2e4a8` into virtual `.data`, `0x20ca8` beyond its `0xd800` raw payload, and the image has no relocation directory. Loader zero-fill produces the current four zero bytes; no raw file initializer encodes `0xffffffff`.
- Decorated RTTI directly identifies `Singleton<NewCreateUserDialogPane>`. Its base descriptor has PMD `620/-1/0` (`+0x26c`) and attributes `0x40`; the constructor's `this+0x26c` then `-0x26c` sequence is compiler Singleton publication lowering, not an authored global store.
- 2026-06-16 A002 live IDA MCP on database `c001_midiplayer_rdata_20260615` reconfirmed the full method set, scalar deleting destructor `0x0052f870`, zero xrefs to constructor start `0x0052c360`, six lifecycle refs to singleton `0x0069b4a8`, three refs each to vtable bases `0x0061fda0`, `0x0061fe00`, and `0x0061fe30`, and command/submit/packet/reply edges through `0x0052d210`, `0x0052d3e0`, `0x0052d5b0`, and `0x0052d9a0`.
- A local PE byte scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` found zero little-endian absolute-VA pointer hits for `0x0052c360`, zero RVA pointer hits for `0x0012c360`, and zero direct `E8`/`E9` branch or call hits to `0x0052c360`. The direct-constructor reachability blocker is therefore retained as real evidence, not a missing xref note.
- 2026-07-05 B001 UID0002SJ support sync: [UID:0002SJ][0x0061fda0-0x0061fe3c.NewCreateUserDialogPaneVtableData](by-memory/0x0061fda0-0x0061fe3c.NewCreateUserDialogPaneVtableData.md) is not a reconstructable helper body and should not emit an empty marker through this file. It is non-reconstructable/non-emitting compiler-generated vtable support owned directly by [UID:00008Z][NewCreateUserDialogPane](by-class/NewCreateUserDialogPane.md); this file remains the source root/output context for the class declaration and method children.

## Source Output Topology

- [UID:0002X7][g_pNewCreateUserDialogPane](by-global/g_pNewCreateUserDialogPane.md) is the sole source definition emitter at position `0`. Its CPP block contains a forward declaration and `NewCreateUserDialogPane *g_pNewCreateUserDialogPane = 0;`; its H block is blank.
- [UID:00008Z][NewCreateUserDialogPane](by-class/NewCreateUserDialogPane.md) emits at position `10` through H only. Its CPP block is blank; its H block contains the complete direct `DialogPane` plus `Singleton<NewCreateUserDialogPane>` class declaration and the one matching extern declaration.
- [UID:0002QS][0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore](by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md) supplies source-authored method bodies through the class/file route.
- UID0002QS owns one complete aggregate CPP payload: constructor; gender/totem and male/female selectors; registration opener/result; four event methods; submit; file-local account sender; child-id-8 character sender; and reply handler. `nullsub_42` remains no-code. Its translation-unit-local `RegistrationString` alias is not exported; UID00008Z's H declaration uses the full wide StringBase type.
- [UID:0002X8][0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane](by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md), [UID:0002SJ][0x0061fda0-0x0061fe3c.NewCreateUserDialogPaneVtableData](by-memory/0x0061fda0-0x0061fe3c.NewCreateUserDialogPaneVtableData.md), and [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md) are physical/compiler evidence and emit no raw storage, vtable, clear-helper, thunk, or scalar-wrapper C++.
- Expected generated result is one source definition, one header class/extern contract, exact child methods, and only the legitimate class H-only emitter marker in CPP. The physical singleton empty marker must disappear; raw data and lifecycle pages produce no markers.
- Consumer closure is owned by ordinary formal channels: UID00008Z has no synthetic selector member, while [UID:0002QS][0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore](by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md) includes `NewUserShapeSelectControlPane.h` and resolves child id `8` locally. `PrettyButtonControlPane.h` supplies both styled-button complete types required by the constructor.
- The included selector contract supplies inline `SetMaleMode`, `SetFemaleMode`, `SelectedShapeSlot`, and `ShapePage`, plus complete type access for allocation/construction and the packed [UID:00050M][HumanImageRenderParams](by-type/by-struct/HumanImageRenderParams.md) used by `BuildPreviewParams` before dialog-owned packet serialization.

## Singleton Lifecycle And Boundaries

- Exactly six refs target the singleton start: main-menu read `0x004f6a13`; constructor publication/fallback `0x0052c3b8`/`0x0052c3bf`; unwind clear `0x0052cd7a`; Singleton clear helper `0x0052f720`; scalar deleting destructor clear `0x0052f89d`. Interior bytes have zero refs.
- The physical slot is exactly `[0x0069b4a8,0x0069b4ac)`. `g_pNewUserDialogPane2` ends at `0x0069b4a8`; `g_pServerSelectPane` begins at `0x0069b4ac`. Mixed parent UID00029W remains parentless and non-emitting.
- Primary/secondary/tertiary `NewCreateUserDialogPane` vtable views occupy `0x0061fda0`, `0x0061fe00`, and `0x0061fe30`; adjacent `CreateUserDialogPane` begins at `0x0061fe3c`.
- Constructor `0x0052c360` remains without direct xrefs, VA/RVA pointer hits, or direct branch/call targets. Preserve that as retained/indirect-route evidence and a confidence cap, not a source-owner or emission blocker.

## Rejected And Historical Alternatives

- Historical `0xffffffff`, `dword_69B4A8`, pre-Gate2B `unk_69B4A8`/one-byte partitions, and direct constructor-assignment descriptions are superseded. Loader-zero PE proof, the current exact typed/named four-byte IDA item, and direct Singleton lowering are authoritative.
- Reject folding this concrete file into non-emitting family index UID0000IK, assigning the global to a main-menu consumer, emitting duplicate physical storage, or hand-authoring clear helpers, adjustor thunks, deleting wrappers, vtables, RTTI, or EH cleanup.
- Exact original field/helper spellings remain inferred, but human source-facing names are preferred over raw decompiler identities and stay internally consistent across class and method children.

## Score Rationale

The projected path remains `NexusTK/login/` because the source tree lists `login/NewCreateUserDialogPane.cpp`, [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) is a non-emitting family index, and [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md) places the newer create-user variants in the login/create-user family. Completion is `89` because method behavior, direct Singleton source cause, loader-zero physical storage, semantic definition, class H contract, vtable/lifecycle compiler exclusions, child routing, boundaries, and PE no-caller evidence are all current. Confidence is `92` because behavior, inheritance, ownership, and output channels are strongly corroborated; absent direct construction and inferred original field/helper spellings remain the only material caps.

## 2026-06-21 B010 Source-Quality Incorporation

- This file is the concrete source root for [UID:00008Z][NewCreateUserDialogPane](by-class/NewCreateUserDialogPane.md), not a folded child of [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md).
- [UID:0002QS][0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore](by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md) now routes through the direct class and contains first-draft method-body C++ for submit, opcode `0x02` account helper, opcode `0x04` shape-control payload builder, and reply handler.
- The no-direct-caller result remains documented: xrefs and PE scans find no direct reference to `0x0052c360`. This is retained/newer-code evidence, not a reason to discard the class or suppress its method docs.
- Historical 2026-06-21 state: UID00008Z then contained declaration-level draft C++ with `m_shapeSelector` and `[[CHILDREN]]`. The 2026-08-25 UID0000IK callback supersedes that shape with formal H, child-id-8 lookup, exact tail fields, four event virtuals, inline empty destructor, and no H child marker.
- `g_pNewCreateUserDialogPane` and [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) are the preferred source-facing singleton/packet globals; raw generated labels remain evidence aliases only.

## Cross-References

- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:00008Z][NewCreateUserDialogPane](by-class/NewCreateUserDialogPane.md)
- [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md)
- [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md)
- [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md)

## 2026-08-11 UID0001CU Registration-Provider Incorporation

- Metadata remains `89/92`, owner remains `FILE`, and the projected path remains `NexusTK/login/`; emitter, position, Nested, and formal CPP/H metadata are schema-N/A for a by-file root.
- The complete file route now includes the registration opener at `0x0052d100`, callback at `0x0052d1e0`, and all retained UID0002QS aggregate bodies. The formal CPP resides only in UID0002QS, and the compile-closed H resides only in UID00008Z.
- The opener's false branch sends directly. Its true branch constructs the const-wide-StringBase callback and transfers ownership to UID0001CU; the callback stores only non-empty text and always resumes request sending.
- The established Singleton, vtable/RTTI, loader-zero global, constructor-reachability, and NewUserShapeSelectControlPane boundaries remain unchanged. Registration integration does not move those compiler/data products or adjacent source ownership.
- Generated refresh/readback remains supervisor-owned. This page records the exact source topology without duplicating formal channel text.

## Changes

- 2026-08-11 B005 UID0000LY consumer topology synchronization:
  - Finalized the selector as a separate adjacent source/header pair and recorded the exact UID00008Z H forward-declaration plus UID0002QS CPP include ownership.
  - Added the inline selector API and complete HumanImageRenderParams dependency route without duplicating formal code on this generated-root context page.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `72`, confidence `68`.
- Summary/evidence: the page has source-role, boundary, method-family, and shape-control caller evidence, but it remains lighter than nearby pages and has unresolved live reachability plus split questions.
- 2026-06-02 path and confidence update:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the page was scored `72/68`.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/"`, completion `76`, and confidence `80`.
  - Summary/evidence: the create-user umbrella, proposed source tree, aggregate memory page, and exact child memory page all place this retained/newer create-character dialog in the login/create-user source family.
- 2026-06-04 live IDA evidence and child attachment update:
  - What existed before: completion/confidence were `76/80`; the page still cited stale recovered-source provenance and the exact memory children were attached to the create-user umbrella.
  - Changed to: completion `82`, confidence `86`; stale provenance was replaced with live IDA MCP evidence; exact core/vtable children now attach to this file page.
  - Summary/evidence: live IDA confirms the constructor, selector helpers, command dispatcher, submit/packet/reply flow, singleton writes, three vtable slots, destructor support, and boundary bytes. The remaining cap is the absent direct constructor caller and unresolved final field/layout naming.
- 2026-06-07 Batch 043 parent-gate refresh:
  - Before: completion `82`.
  - After: completion `85` with confidence retained at `86`.
  - Evidence: live IDA MCP reconfirmed the exact singleton storage item, initial value, and all six lifecycle xrefs. This closes the completion gate for the direct global parent of the new exact storage split while retaining the documented reachability and field/layout caveats.
- 2026-06-16 A002 file-quality refresh:
  - Before: completion/confidence were `85/86`.
  - After: completion/confidence are `86/88`.
  - Evidence: live IDA MCP reconfirmed all core methods, singleton and vtable xrefs, scalar destructor support, and internal command/submit/packet/reply edges; a local PE scan found no absolute, RVA, or direct branch/call reference to `0x0052c360`. The owner/emitter route remains this file; final C++ remains blank because construction reachability and source-quality field/helper names are not final.
- 2026-06-21 B010 Rule 26 source-quality incorporation:
  - Changed to: `86/89`.
  - Summary/evidence: incorporated non-emitting parent policy, concrete `NewCreateUserDialogPane.cpp` source ownership, direct class routing for [UID:0002QS][0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore](by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md), retained/no-direct-caller interpretation, child method-body C++ readiness, class declaration C++, field/helper candidates, singleton naming, and packet-helper alias rejection.
- 2026-07-05 B001 UID0002SJ vtable-data support sync:
  - Score unchanged.
  - Summary/evidence: [UID:0002SJ][0x0061fda0-0x0061fe3c.NewCreateUserDialogPaneVtableData](by-memory/0x0061fda0-0x0061fe3c.NewCreateUserDialogPaneVtableData.md) now records the full class vtable block as direct class-owned, non-reconstructable/non-emitting compiler output. This file remains the concrete source root for class and method output, but UID0002SJ should no longer generate a file-level empty marker.
- 2026-07-06 B001 UID0002QS support sync:
  - Score unchanged.
  - Summary/evidence: corrected stale `0xffffffff` singleton-storage wording for [UID:0002X8][0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane](by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md). Current support docs and MCP evidence show `0x0069b4a8` initializes to `0x00000000` while retaining the same six lifecycle xrefs.
- 2026-07-29 B008 UID0002X8 Rule 26 implementation:
  - Changed to `89/92` with the same `NexusTK/login/` path and `FILE` ownership.
  - Added the exact position-0 semantic global definition, position-10 class H/extern contract, direct Singleton RTTI/PMD/lowering cause, PE loader-zero and six-reference lifecycle proof, physical/vtable/lifecycle no-code routes, expected generated topology, protected singleton/vtable boundaries, and historicalized the `0xffffffff`, raw-label, handwritten-publication, and CPP-channel class-declaration models.
- 2026-07-29 supervisor Gate 2B catalog entry `0362` synchronization:
  - Recorded the incomplete no-layout type, exact four-byte `g_pNewCreateUserDialogPane` pointer item, both source-role comments, unchanged bytes/xrefs/neighbors/RTTI dependencies, catalog action-time save SHA256 `3C8F31781C94DF74AADDB65B3D944CD2CA4387C448918BBBFFD60B41C3625B69`, dated no-drift checkpoints `296ED21C...63CF8B`/`905D1AB1...604C1`, current no-drift shared-IDB SHA256 `412DA7E8...519CD`, and backed-up historical `0E0AF938...AB481` prestate.
