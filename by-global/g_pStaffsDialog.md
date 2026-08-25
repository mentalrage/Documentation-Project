*** UID:0000SC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class StaffsDialogPane;

StaffsDialogPane *g_pStaffsDialog = NULL;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pStaffsDialog

## Status

- Confidence: very strong for type, linkage, initializer, ownership, lifetime, one-definition route, and source placement.
- Physical address/range: `0x0069b490`, exact child `[0x0069b490,0x0069b494)`.
- Primary memory doc: [UID:0001PT][0x0069b490-0x0069b494.g_pStaffsDialog](by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md)
- Owner class: [UID:0000DY][StaffsDialogPane](by-class/StaffsDialogPane.md)
- Likely owner source: [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md)

## Symbol Role

`g_pStaffsDialog` is the sole external project-global definition for the active main-menu staff/credits dialog instance. The source definition is `StaffsDialogPane *g_pStaffsDialog = NULL;` in `NexusTK/login/StaffsDialogPane.cpp`; it is neither file-local `static`, a class-static member, nor duplicate physical-storage source.

[UID:0001PT][0x0069b490-0x0069b494.g_pStaffsDialog](by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md) is exact loader-zeroed physical evidence and no longer emits. Direct `Singleton<StaffsDialogPane>` base construction/destruction causes the observed publication, adjusted-null fallback, EH clear, and scalar-wrapper clear. Those machine writes are compiler/base lowering and must not be duplicated as handwritten assignments in the StaffsDialogPane constructor or destructor.

Emitter order is global definition `0`, file-local `STAFF.EPF` resource pointer `5`, class declaration `10`, and constructor/OnControlCommand methods `20`.

## Evidence Notes

- Exact physical bytes are `00 00 00 00`, SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`. RVA `0x0029b490` lies in virtual `.data` beyond raw backing, proving PE loader-zeroed storage rather than an explicit raw initializer.
- Live IDA MCP reports exactly four write xrefs with no pagination remainder: publication at `0x004ffaf6`, adjusted-null fallback at `0x004ffafd`, constructor-EH Singleton base clear at `0x00502410`, and scalar-wrapper Singleton base clear at `0x00502cc6`. There is no read or additional lifetime route.
- IDA MCP `xrefs_to 0x00502410` reports a constructor-context xref at `0x00601e35`, consistent with small cleanup/unwind support rather than an independent feature entry point.
- 2026-05-26 recheck correctly classified `0x00502410` as compiler-generated constructor EH cleanup; the accepted source-quality closure further identifies it as the direct `Singleton<StaffsDialogPane>` base destructor at complete-object offset `+0x26c`.
- 2026-06-16 live IDA MCP session on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64` reconfirmed the exact four-reference lifecycle: constructor publish at `0x004ffaf6`, constructor null clear at `0x004ffafd`, clear helper `0x00502410`, and scalar deleting destructor clear at `0x00502cc6`. Function lookup also reconfirmed the constructor `0x004ffaa0` size `0x27d`, action handler `0x004ffd20` size `0x1d`, clear helper size `0xb`, and scalar deleting destructor `0x00502cc0` size `0x45`.
- The same pass saved evidence-time IDA names for `sub_4FFAA0`, `sub_4FFD20`, `sub_502410`, and `sub_502CC0`. Those historical labels remain useful provenance, but source-facing `OnDialogAction`/`ClearSingletonHelper` spellings are superseded by `OnControlCommand` and direct Singleton base-destruction semantics.
- 2026-07-03 B014 MCP session `3a33af0b` reports bytes `00 00 00 00` and the same four-reference lifecycle at `0x004ffaf6`, `0x004ffafd`, `0x00502410`, and `0x00502cc6`. The active IDB's raw labels do not change the typed global/source route.

## Source Placement And One-Definition Decision

- Semantic owner/emitter [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md) provides `NexusTK/login/StaffsDialogPane.cpp`.
- The exclusive StaffsDialogPane constructor/destructor lifetime, `STAFF.EPF` resource family, RTTI class identity, and established peer-global style support external global definition here.
- MainMenuPane supplies only show-parent/layer dependencies and never writes the slot. No GM/staff gameplay reference touches it.
- The physical memory page is documentation evidence only. Emitting from both pages would duplicate the global definition.

## Score Rationale

- Completion `92`: exact type/name/linkage/initializer, source path/order, four-write lifetime, physical/semantic split, direct-Singleton compiler cause, formal definition, and no-read/duplicate exclusions are closed.
- Confidence `94`: bytes, PE mapping, xrefs, RTTI/EBO, class/resource ownership, and project-era global style agree. Original symbols and a surviving constructor caller are absent but do not alter the definition route.

## Open Questions

- Constructor entry route: ordinary xrefs, absolute VA/RVA pointers, rel32 calls/jumps, startup/factory/menu-command paths, vtables, globals, and historical reports contain no surviving route. Treat the complete out-of-line body as retained linked source; this caps confidence but does not block source emission.
- Declaration/linkage: resolved as the sole external definition in `StaffsDialogPane.cpp`, with a forward class declaration and `NULL` initializer. No unresolved C++ blocker remains.

## Historical And Superseded Assumptions

- Historical `ff ff ff ff` and explicit-initializer wording is disproved by live zero bytes plus PE no-raw-backing arithmetic.
- Historical constructor/destructor C++ explicitly published/cleared the pointer. Direct Singleton EBO and wrapper/base analysis prove those assignments are implicit compiler/base behavior.
- Historical file-local/class-static and unresolved-declaration alternatives are rejected by the established shared by-global route and one-definition policy.

## Cross-References

- [UID:0000DY][StaffsDialogPane](by-class/StaffsDialogPane.md)
- [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md)
- [UID:0001PT][0x0069b490-0x0069b494.g_pStaffsDialog](by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md)
- [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md)
- [UID:0001RM][staff-dialog-resources](by-resource/staff-dialog-resources.md)

## Changes

- 2026-06-06: Raised completion to `84` after a live IDA MCP recheck confirmed the initialized bytes, exact four-reference singleton lifecycle, and owner-side constructor/destructor boundaries.
  - Reasoning: the storage has no remaining unresolved writer/reader ambiguity at the global level; final reconstruction C++ stays blank because the page documents data ownership rather than a complete source-level implementation.
- 2026-06-16 C001 global/source-quality refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:88`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:90`; owner/emitter remain [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md); final C++ remains blank.
  - Evidence: live IDA reconfirmed the four-slot lifecycle, function boundaries, and matching memory child [UID:0001PT][0x0069b490-0x0069b494.g_pStaffsDialog](by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md) at `86/90`. IDA function names were improved and saved; constructor reachability and exact source declaration placement remain the real blockers to a higher score.
- 2026-06-05: Marked reconstructable and attached to [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md) to resolve the global unclassified coverage row.
  - Reasoning: live IDA xrefs cover the complete four-reference singleton lifecycle inside the staff dialog constructor, constructor-cleanup helper, and destructor; the parent file is now projected to `NexusTK/login/`. No score change and no reconstruction C++ were added.
- What existed before: this page had correct owner/lifetime notes but unevaluated completion/confidence metadata and evidence bullets that mixed in non-live provenance context.
- What changed to: the page now uses live IDA MCP as the evidence source for storage shape and all four data xrefs. Completion/confidence are now `84/88`.
- Summary and evidence: IDA MCP on 2026-05-30 verified `0x0069b490` as a 4-byte `.data` singleton pointer with constructor assignment/fallback at `0x004ffaf6`/`0x004ffafd`, constructor cleanup clear at `0x00502410`, and destructor clear at `0x00502cc6`.
- Historical/superseded 2026-06-19 B005 interpretation: [UID:0001AJ][0x00502cc0-0x00502d05.StaffsDialogPaneScalarDeletingDestructor](by-memory/0x00502cc0-0x00502d05.StaffsDialogPaneScalarDeletingDestructor.md) was treated as emitting a source-authored destructor clear. Direct Singleton-base teardown now proves that clear is compiler output; the global declaration/linkage is closed by this page's formal definition.
- Historical/superseded 2026-07-03 B014 implementation: [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md) previously emitted `g_pStaffsDialog = this`, and UID0001AJ emitted a destructor clear. The accepted direct `Singleton<StaffsDialogPane>` source shape removes both authored assignments while preserving the exact four machine writes and current zero-initialized bytes; older `ff ff ff ff` wording is separately disproved.
- 2026-07-21 B001 UID0001PT accepted callback: raised to `92/94`, inserted the sole external definition at position 0, closed PE/one-definition/direct-Singleton behavior, and superseded explicit publish/destructor-clear source.
