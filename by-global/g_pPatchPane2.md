*** UID:0000RZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
PatchPane2 *g_pPatchPane2 = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pPatchPane2

## Status

- Address: `0x0069ba2c`
- Primary memory doc: [UID:0002ZP][0x0069ba2c-0x0069ba30.g_pPatchPane2](by-memory/0x0069ba2c-0x0069ba30.g_pPatchPane2.md)
- Likely type: `PatchPane2*`
- Direct owner file: [UID:0000MH][PatchPane](by-file/PatchPane.md)
- Confidence: very strong for storage, type, lifecycle, semantic ownership, one-definition route, and PatchPane.cpp placement.

## Purpose

`g_pPatchPane2` is the sole externally linked source definition for the active alternate patch dialog singleton. [UID:0004VS][0x00548690-0x00548a06.PatchPane2Constructor](by-memory/0x00548690-0x00548a06.PatchPane2Constructor.md) publishes the instance through `Singleton<PatchPane2>` lowering; [UID:0004VT][0x00548a10-0x00548a7d.PatchPane2Destructor](by-memory/0x00548a10-0x00548a7d.PatchPane2Destructor.md), constructor-EH cleanup, and the scalar deleting wrapper clear it during teardown.

## Evidence

- IDA MCP decompilation of `0x00548690` writes `dword_69BA2C = this`.
- IDA MCP decompilation of `0x00549340` and `0x00549370` clears `dword_69BA2C`.
- Current B011 MCP evidence confirms the exact storage value/bytes are zero/null (`0x0`, `00 00 00 00`), so source emits a normal zero-initialized singleton declaration rather than hand-authored address storage.
- IDA MCP `xrefs_to 0x0069ba2c` on 2026-05-25 reports constructor writes at `0x005486f4` and `0x005486fb`, a nearby cleanup reference at `0x00548a6d`, the constructor-EH clear-helper write at `0x00549340`, and the scalar-destructor write at `0x005493d0`.
- [UID:0001VJ][PatchPane2Layout](by-type/by-struct/PatchPane2Layout.md) records the surrounding object fields that are live while this singleton is set.

## 2026-05-30 Review Notes

- IDA MCP `py_eval` on 2026-05-30 confirms `0x0069ba2c` is `dword_69BA2C`, size `4`, in `.data`, with 5 data xrefs.
- Live IDA xrefs confirm constructor writes at `0x005486f4` and `0x005486fb` in `sub_548690`, a cleanup/body reference at `0x00548a6d`, constructor-EH singleton clear helper at `0x00549340` in `sub_549340`, and scalar deleting destructor clear at `0x005493d0` in `sub_549370`.
- Live IDA MCP also confirms adjacent `0x0069ba28` as the `ParcelPane` singleton slot, matching [UID:0002A0][0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots](by-memory/0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots.md).
- Live IDA decompilation on 2026-06-05 confirms `0x00548690` stores `this` into `dword_69BA2C` and installs the `PatchPane2` vtable, while `0x00549340` and `0x00549370` clear the singleton during cleanup/destruction.
- Completion now reaches the corrected assignment gate because the adjacent parcel/patch singleton cluster has been split into exact child storage pages. Remaining uncertainty is final source declaration spelling and precise classification of the `0x00548a6d` lifecycle reference.

## 2026-06-07 A001 Gate Review

- 2026-06-14 B003 IDA/PE recheck supersedes the earlier initializer wording: `dword_69BA2C` is four bytes in `.data`, bytes/value `00 00 00 00` / `0`, with five data xrefs.
- The former mixed memory aggregate [UID:0002A0][0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots](by-memory/0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots.md) has been split; the exact child storage page is [UID:0002ZP][0x0069ba2c-0x0069ba30.g_pPatchPane2](by-memory/0x0069ba2c-0x0069ba30.g_pPatchPane2.md).
- At the time of the A001 gate review, this page was no longer auto-assigned to [UID:0000MH][PatchPane](by-file/PatchPane.md) because that direct by-file parent was `88/80`, below the corrected `85/85` confidence gate. The likely owner text and cross-reference remained as evidence until the Batch124 parent refresh below cleared the file gate.

## 2026-06-07 A005 Generated Coverage Note

- At the time of Batch079, [UID:0002ZP][0x0069ba2c-0x0069ba30.g_pPatchPane2](by-memory/0x0069ba2c-0x0069ba30.g_pPatchPane2.md) left `AUTOGEN_PARENT_UID` blank because generated memory coverage rejected this then-parentless by-global UID as `autogen_parent_unknown`.
- This page remained the canonical by-global evidence anchor for the exact storage slot, but stayed blank upward because [UID:0000MH][PatchPane](by-file/PatchPane.md) was below the corrected confidence gate and [UID:0000AA][PatchPane2](by-class/PatchPane2.md) was also below the corrected confidence gate.

## 2026-06-08 A005 Batch124 Parent-Gate Refresh

- Live IDA MCP reconfirmed `0x0069ba2c` as `dword_69BA2C`, a 4-byte `.data` singleton slot loader-zeroed in the virtual `.data` tail.
- `xrefs_to 0x0069ba2c` still reports the `PatchPane2` constructor publish/clear pair at `0x005486f4` and `0x005486fb`, the raw cleanup/body reference at `0x00548a6d`, the constructor-EH singleton clear helper at `0x00549340`, and the scalar deleting destructor clear at `0x005493d0`.
- The direct file parent [UID:0000MH][PatchPane](by-file/PatchPane.md) now clears the corrected gate at `88/85`, and [UID:0000AA][PatchPane2](by-class/PatchPane2.md) now clears the associated lifecycle-class gate at `86/85`.
- `AUTOGEN_PARENT_UID` is therefore set to [UID:0000MH][PatchPane](by-file/PatchPane.md). The exact memory child [UID:0002ZP][0x0069ba2c-0x0069ba30.g_pPatchPane2](by-memory/0x0069ba2c-0x0069ba30.g_pPatchPane2.md) can again attach to this rooted by-global evidence anchor under the corrected child-and-parent gate.

## Ownership Decision

Declare this with the patch/update module under [UID:0000MH][PatchPane](by-file/PatchPane.md). It is not an application-wide manager; it is lifecycle-bound to `PatchPane2`.

## Cross-References

- [UID:0000MH][PatchPane](by-file/PatchPane.md)
- [UID:0000AA][PatchPane2](by-class/PatchPane2.md)
- [UID:0001VJ][PatchPane2Layout](by-type/by-struct/PatchPane2Layout.md)
- [UID:0002ZP][0x0069ba2c-0x0069ba30.g_pPatchPane2](by-memory/0x0069ba2c-0x0069ba30.g_pPatchPane2.md)
- [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md)
- [UID:0001EZ][0x00549340-0x0054934b.ClearPatchPane2Singleton](by-memory/0x00549340-0x0054934b.ClearPatchPane2Singleton.md)
- [UID:0002A0][0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots](by-memory/0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots.md)
- [UID:0004VS][0x00548690-0x00548a06.PatchPane2Constructor](by-memory/0x00548690-0x00548a06.PatchPane2Constructor.md)
- [UID:0004VT][0x00548a10-0x00548a7d.PatchPane2Destructor](by-memory/0x00548a10-0x00548a7d.PatchPane2Destructor.md)
- [UID:0004VX][0x00549370-0x0054940f.PatchPane2ScalarDeletingDestructor](by-memory/0x00549370-0x0054940f.PatchPane2ScalarDeletingDestructor.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`, and Evidence included weak metadata.
- Changed to: completion `80`, confidence `88`; weak metadata was removed from Evidence.
- Summary/evidence: live IDA MCP on 2026-05-30 verified exact storage, size, segment, 5 xrefs, constructor writes, clear-helper write, and scalar-deleting-destructor clear. Completion remains below full until the `0x00548a6d` lifecycle reference is precisely classified.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000MH`; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0069ba2c` and decompilation of `0x00548690`, `0x00549340`, and `0x00549370` prove NexusTK-owned `PatchPane2` singleton storage owned by [UID:0000MH][PatchPane](by-file/PatchPane.md). No final C++ body was added because the page is below the current `90/90+` code-entry gate.
- 2026-06-07 A001 Batch 054 parent-gate refresh:
  - Before: score `80/88`; `AUTOGEN_PARENT_UID` pointed to [UID:0000MH][PatchPane](by-file/PatchPane.md), whose confidence is below the corrected `85/85` gate.
  - Changed to: score `85/90`, `AUTOGEN_PARENT_UID` blank, explicit primary exact memory child, and an assignment-gate note.
  - Summary/evidence: live IDA reconfirmed the exact four-byte storage, five xrefs, constructor publish/fallback clears, cleanup/body reference, clear-helper write, scalar deleting destructor clear, and the new split child. The direct by-file parent was not raised because its broader source-unit confidence remains below gate.
- 2026-06-07 A005 Batch 079:
  - Changed to: documentation only; scores remain `85/90` and parent metadata remains blank.
  - Summary/evidence: recorded that exact memory child [UID:0002ZP][0x0069ba2c-0x0069ba30.g_pPatchPane2](by-memory/0x0069ba2c-0x0069ba30.g_pPatchPane2.md) now clears its unsupported by-global autogen parent link. This page remains the evidence anchor until [UID:0000MH][PatchPane](by-file/PatchPane.md) or another direct owner clears the corrected `85/85` gate.
- 2026-06-08 A005 Batch124:
  - Before: `85/90`, parent metadata blank because [UID:0000MH][PatchPane](by-file/PatchPane.md) and [UID:0000AA][PatchPane2](by-class/PatchPane2.md) were below the corrected confidence gate.
  - Changed to: `86/90` and `AUTOGEN_PARENT_UID:0000MH`.
  - Summary/evidence: live IDA MCP reconfirmed exact storage, initial value, five data xrefs, constructor publish/clear, cleanup/body reference, helper clear, scalar-destructor clear, and PatchPane2 owner boundaries. [UID:0000MH][PatchPane](by-file/PatchPane.md) now clears `88/85`, making it the justified direct file parent.
- 2026-06-17 B003 helper follow-up executed by supervisor:
  - Score unchanged at `86/90`; purpose wording now identifies [UID:0001EZ][0x00549340-0x0054934b.ClearPatchPane2Singleton](by-memory/0x00549340-0x0054934b.ClearPatchPane2Singleton.md) as constructor-EH cleanup rather than a normal source helper.
  - Summary/evidence: B003 live IDA reanalysis confirmed the exact `0x00549340` clear body, one code xref from constructor-unwind funclet `0x00605eb1`, and ordinary scalar-destructor counterpart at `0x005493d0`.
- 2026-07-01 B011 empty-emitter implementation:
  - Before: `COMPLETION:86`, `CONFIDENCE:90`, formal C++ blank.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:91`, with formal source declaration `PatchPane2 *g_pPatchPane2 = 0;`.
  - Summary/evidence: current MCP reconfirmed zero/null bytes and value for `0x0069ba2c`, plus constructor publish/fallback writes and destructor/EH clears. The exact memory child [UID:0002ZP][0x0069ba2c-0x0069ba30.g_pPatchPane2](by-memory/0x0069ba2c-0x0069ba30.g_pPatchPane2.md) is now covered by this source-level declaration rather than separate address storage.
- 2026-07-21 B005 UID0002ZP source-quality callback:
  - Raised `88/91 -> 92/94`, retained owner/emitter UID0000MH and reconstructable true, set source position 10, and preserved the formal definition byte-for-byte.
  - Fresh MCP and PE evidence prove UID0002ZP is loader-zero physical backing with exact four-zero-byte SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`; this page alone owns semantic source emission.
  - Exactly five storage refs are classified: constructor publish/fallback at `0x005486f4/0x005486fb`, ordinary destructor clear at `0x00548a6d`, constructor-EH clear at `0x00549340`, and scalar-wrapper clear at `0x005493d0`.
  - Direct RTTI proves `PatchPane2 : DialogPane, Singleton<PatchPane2>`; explicit publish/clear operations remain compiler/Singleton lowering and are not added to handwritten methods.
  - Historical `0xffffffff`, parentless, unresolved `0x00548a6d`, covered-physical-emitter, and optional companion-file assumptions are superseded while preserved above as dated history.
