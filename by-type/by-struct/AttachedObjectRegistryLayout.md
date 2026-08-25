*** UID:0001TR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AttachedObjectRegistryLayout

## UID0003Z4 Final Typed Layout - 2026-07-14

- This is a descriptive layout/evidence page; formal C++ remains blank because the actual fields are declared once in [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md).
- Exact current mapping: `+0x170 List *m_primaryEffectObjectPanes`, `+0x174 List *m_secondaryEffectObjectPanes`, `+0x1d8 BalloonObjectPane *m_balloonObjectPane`, `+0x1dc HitBarObjectPane *m_hitBarObjectPane`, `+0x1e0 DamageNumberObjectPane *m_damageNumberObjectPane`, and `+0x1e4 ObjectInfoObjectPane *m_objectInfoObjectPane`.
- Registration is owned by UID0004QJ/UID0004QK/UID0004QL/UID0004QM/UID0004QN/UID0004QO. UID0001DF unregisters the first matching pointer from type-2/type-4 Lists, clears types 6/7/9 unconditionally, and clears type 8 only while `g_useEpfAssets` is true. UID0004QH owns final destruction/list lifetime.
- Lists store four-byte `EffectObjectPane *` values and additions compare public `m_effectId`, delete every same-ID object while scanning backward, then append one pointer. This does not imply vector semantics or safe element erasure.
- Historical type2/type4, ground/shadow/EPF/nameplate, registry-owner-open, and exact-name-blocked conclusions are superseded by constructor producers, concrete overlay callers, unregister switch, and source-legal class declarations.

## Status

- Entity kind: class layout support struct for the living-object attached-object registry used by attached overlay teardown.
- Confidence: very strong for the listed offsets, caller shape, unregister data flow, detached-object type byte, exact list/singleton types and names, and `LivingObjectPane` field ownership.
- Primary owner: [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md), emitted through [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md)
- Detach helper source owner: [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md)
- Detach helper caller/source-use context: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- Primary memory: [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md)
- Evidence basis: live IDA MCP checks of `0x0053aec0`, the `AttachedObjectPane` destructor call at `0x005382b0`, and the linked class/file/memory support pages.
- Reconstructable: yes, as source-level layout information for `LivingObjectPane` attached-overlay state. Formal C++ remains blank on this descriptive support page because the exact fields and unregister declaration are emitted once by [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md), not because names or types remain blocked.
- Parent assignment: attached to [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md). A001's 2026-06-16 evidence pass found the constructor/setup writes for this exact field group in [UID:0002R0][0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup](by-memory/0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup.md), and B001's 2026-06-16 source-shape pass resolved the detach helper itself to the same owner; the attached-pane destructor remains the caller context.

## Layout

This layout describes the registry/list-owner object passed as `this` to the detach helper at `0x0053aec0`. The object pointer is stored in [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md) at offset `+0x128` / 296 (Verified with int_convert.py).

| Offset | Field | Type | Evidence |
| --- | --- | --- | --- |
| `+0x170` | `m_primaryEffectObjectPanes` | `List *` of `EffectObjectPane *` | UID0001DF scans pointer values and removes the first match; UID0004QK deletes same-`m_effectId` entries while scanning backward and appends one pointer. |
| `+0x174` | `m_secondaryEffectObjectPanes` | `List *` of `EffectObjectPane *` | Same storage/removal pattern as `+0x170`; UID0004QL owns the secondary registration path. |
| `+0x1d8` | `m_balloonObjectPane` | `BalloonObjectPane *` | UID0004QJ stores it; UID0001DF clears it for object type `6`. |
| `+0x1dc` | `m_hitBarObjectPane` | `HitBarObjectPane *` | UID0004QM stores it; UID0001DF clears it for object type `7`. |
| `+0x1e0` | `m_damageNumberObjectPane` | `DamageNumberObjectPane *` | UID0004QN stores it; UID0001DF clears it for object type `8` only when `g_useEpfAssets` is true. |
| `+0x1e4` | `m_objectInfoObjectPane` | `ObjectInfoObjectPane *` | UID0004QO deletes the old pointer before storing its argument; UID0001DF clears it for object type `9`. |

## MapPane Object-Effect Use

[UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md) scans `m_secondaryEffectObjectPanes` for `EffectInfo`'s secondary sequence and `m_primaryEffectObjectPanes` for its primary sequence. The companion create helper [UID:0003TF][0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane](by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md) registers sequence `0` through `AddSecondaryEffectObjectPane` and sequence `1` through `AddPrimaryEffectObjectPane`.

## Related Object Fields

The detached object uses byte offset `+0xf8` as its attachment-type discriminator. Current observed values are `2`, `4`, `6`, `7`, `8`, and `9`.

## Live IDA Evidence

- 2026-06-03 restarted IDA MCP reports the detach helper as `void __thiscall(int this, int)`: the registry/list-owner object is `this`, and the detached attached-object pointer is the single explicit argument.
- IDA caller analysis confirms one call site, `0x005382b0` inside [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md)'s destructor. Decompilation shows the destructor call shape `sub_53AEC0(*(this + 0x128), this)`, proving the registry pointer is stored at `AttachedObjectPane + 0x128`.
- IDA callee analysis reports no outgoing helper calls from `0x0053aec0`; all list operations are vtable dispatches through the list objects stored in this registry.
- Decompilation gates behavior on a non-null detached object and the detached object's signed byte at `+0xf8`, accepting values in the `2..9` range.
- For attachment type `2`, the helper reads the list pointer at registry offset `+0x170`, retrieves list data through vtable slot `+0x0c`, scans the list count at list offset `+0x0c`, and removes the matching object through vtable slot `+0x1c` with remove flag `1`.
- Attachment type `4` uses the same list pattern through registry offset `+0x174`.
- Attachment types `6`, `7`, and `9` clear registry offsets `+0x1d8`, `+0x1dc`, and `+0x1e4`.
- Attachment type `8` clears registry offset `+0x1e0` only when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97` equals `1`; the legacy/non-EPF branch does not clear that slot.

## 2026-06-13 Live IDA Refresh

- IDA MCP session `a001_goal2_0002UM` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; `server_health` reported image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- `lookup_funcs` reconfirmed `AttachedObjectPane` destructor `0x00538100` as a `0x1f8` / 504-byte function and detach helper `0x0053aec0` as a `0x152` / 338-byte function; `0x0053b011` still resolves inside that helper and `0x0053b012` is not a function (Verified with int_convert.py).
- `analyze_function 0x00538100` reconfirmed the destructor restores `AttachedObjectPane` vtable views, releases the attached payload, and calls `sub_53AEC0(v12, this)` at `0x005382b0`, where `v12` is loaded from `this + 0x128`.
- `xrefs_to 0x0053aec0` reports exactly one code xref, the destructor call at `0x005382b0`; the helper still has no ordinary callees because list operations dispatch through list-object vtables.
- `analyze_function 0x0053aec0` reconfirmed the helper signature shape `void __thiscall sub_53AEC0(int this, int a2)`, the detached object null check, and the signed type-byte gate at detached object offset `+0xf8` / 248 (Verified with int_convert.py).
- The same helper analysis reconfirmed type `2` uses the list pointer at registry `+0x170` / 368, type `4` uses `+0x174` / 372, and both list paths fetch list data through vtable slot `+0x0c`, compare entries against the detached object, and remove the match through vtable slot `+0x1c` with remove flag `1` (Verified with int_convert.py).
- The singleton clear cases remain tied to registry offsets `+0x1d8` / 472, `+0x1dc` / 476, `+0x1e0` / 480, and `+0x1e4` / 484 for detached-object types `6`, `7`, `8`, and `9` respectively; the type `8` clear remains gated by `byte_66DA97 == 1` / [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) (Verified with int_convert.py).
- `xrefs_to 0x0066da97` still returns broad UI/rendering consumers beyond attached-object code, supporting the existing decision that this byte is the global EPF/legacy asset-mode selector rather than an attachment-specific flag.

## 2026-06-16 Owner Refresh

- A001 live IDA MCP session `c001_midiplayer_rdata_20260615` reconfirmed the detach-helper/destructor edge, then searched the local object-pane code for the registry offsets.
- `search_text` found `LivingObjectPane` constructor writes at `0x0053a257` / `+0x174`, `0x0053a27f` / `+0x170`, `0x0053a287` / `+0x1dc`, `0x0053a291` / `+0x1e0`, and `0x0053a29b` / `+0x1e4` inside `sub_53A110`; the constructor variant at `0x0053a360` repeats the same `+0x174`, `+0x170`, `+0x1dc`, `+0x1e0`, and `+0x1e4` initialization pattern.
- The same search found [UID:0001DE][0x0053a110-0x0053d818.LivingObjectPaneCore](by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md) linked-object helpers reading, replacing, and clearing the same field group before the detach helper at `0x0053aec0`.
- A section-mapped PE scan found the expected direct branches to `0x0053a110` at `0x0050609b`, to `0x0053a360` at `0x005a256b`, and to `0x0053aec0` at `0x005382b0`, with zero absolute-VA or RVA pointer encodings for those starts. This supports field ownership by `LivingObjectPane`; B001's later source-shape pass resolved the helper placement to [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) while preserving `AttachedObjectPane` as the caller context.
- B001's source-shape pass also checked the registration side of the lifecycle. MapPane packet/update paths construct attached overlays and then call `LivingObjectPane` registration helpers: `0x0050e100` calls `0x004682c0` plus `0x0053ada0`, `0x0050e4c0` and `0x0050e690` call `0x00538dc0` plus `0x0053ae70`, `0x0050ea30` calls `0x005387b0` plus `0x0053adb0`/`0x0053ae10`, and `0x0050ef00` calls `0x00539230` plus `0x0053ae80`. This makes MapPane a creator/controller consumer and confirms that the registry storage belongs to the living object.
- The same pass rejected standalone helper ownership with negative evidence: no hidden VA/RVA pointer route, exactly one branch to the detach helper, no vtable/data object for an `AttachedObjectPaneHelper_53AEC0` class, and only compiler switch-table data after the function body. The layout stays owned by `LivingObjectPane`; [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) remains only the stored-back-pointer caller context.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `92` | The page records the exact unregister boundary/body, destructor caller, `AttachedObjectPane +0x128` owner pointer, object-type discriminator, typed Lists and singleton pointers, type-8 mode gate, constructor setup, registration/destruction helpers, and direct class/file route. Exact names and source placement are resolved; only original private spelling provenance and unrelated attachment internals keep this below final audit. |
| Confidence `94` | The layout is corroborated by the LivingObjectPane declaration, UID0002R0 initialization, UID0004QJ-UID0004QO producers, UID0001DF consumer, concrete overlay constructors, and MapPane dispatch. The score uses the normal-audit ceiling because no original symbols survive. |

## Naming Notes

- `AttachedObjectPaneHelper_53AEC0` is a generated pseudo-class, not a stable original name.
- The setup search and helper placement are resolved to [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md). Current source uses the exact field names above and `UnregisterAttachedObjectPane`; types `2/4/6/7/8/9` map to the primary effect, secondary effect, Balloon, HitBar, DamageNumber, and ObjectInfo routes respectively.
- The `byte_66DA97` branch is layout/rendering mode behavior, not an attachment subsystem flag.
- Current `simroot_v2` still emits the byte as `g_attachmentModeFlag`; normalize that alias to [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) in project docs.
- 2026-05-26 IDA MCP recheck reconfirmed the listed offsets and showed type `8` is cleared only in the `byte_66DA97 == 1` branch.
- 2026-05-31 IDA MCP recheck of `0x0053aec0` confirms the type discriminator read at detached-object offset `+0xf8`, list-object accesses through this-object offsets `+0x170` and `+0x174`, and pointer clears at `+0x1d8`, `+0x1dc`, `+0x1e0`, and `+0x1e4`.
- The same decompilation confirms type `8` clearing at `+0x1e0` only occurs in the `byte_66DA97 == 1` branch, while types `6`, `7`, and `9` clear their dedicated pointers in the broader fallback branch.

## Open Questions

- No in-scope layout, field-type, source-owner, unregister-name, or formal-placement blocker remains. Original private spelling cannot be symbol-proven and is retained as a confidence limitation rather than deferred work.

## Cross-References

- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md)
- [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md)
- [UID:0000HK][AttachedObjectPaneHelper_53AEC0](by-file/AttachedObjectPaneHelper_53AEC0.md)
- [UID:00000N][AttachedObjectPaneHelper_53AEC0](by-class/AttachedObjectPaneHelper_53AEC0.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)

## Changes

- 2026-06-20 B007 object-effect descriptor implementation support:
  - Added UID 000232 cross-reference for type-4/type-2 list scans and create-helper insertion mapping.
- 2026-06-16 B001 source-shape execution:
  - Scores unchanged at `87/90`.
  - Updated the detach-helper placement from unresolved/[UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) caller-context wording to resolved [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) source ownership. The attached-pane destructor remains the source-use context.
  - Evidence: B001 live IDA and raw PE checks tied [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md) to the LivingObjectPane field group through constructor/list setup, same-field cleanup/replacement helpers, MapPane overlay-registration caller pairs, and negative standalone-pointer evidence.

- 2026-06-16 A001 Goal 2 owner refresh: raised `86/89` to `87/90`, changed `CANONICAL_OWNER`/`EMITTER_UIDS` from [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) to [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md), and documented the now-found constructor/setup evidence.
  - Evidence: live IDA `search_text` found the same registry offset group initialized by `sub_53A110` and `sub_53A360`, with linked-object helpers in the `LivingObjectPane` core reading/clearing the same fields; `xrefs_to`/PE checks reconfirmed the sole detach-helper branch from the attached-pane destructor and direct constructor branches into the two `LivingObjectPane` constructors. Final C++ remains blank pending source-quality field names and detach-helper placement.
- 2026-06-13 A003 Goal 2 type-quality pass: Raised from `76/88` to `86/89`.
  - Before: the page had strong offset evidence but stayed in the Low_Type queue because completion did not reflect the now-cleared parent/support gate and the current by-* evidence set.
  - After: the page records current IDA evidence for helper size/end, sole destructor caller, `AttachedObjectPane + 0x128` registry pointer, detached-object `+0xf8` type byte, list offsets `+0x170/+0x174`, singleton offsets `+0x1d8/+0x1dc/+0x1e0/+0x1e4`, broad `g_useEpfAssets` mode-byte handling, and the direct parent/support gate. Direct parent [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) remains correct at `86/86`.
  - Evidence: IDA MCP `server_health`, `lookup_funcs`, `analyze_function`, and `xrefs_to` on 2026-06-13 against session `a001_goal2_0002UM`; key sizes and offsets were verified with `tools/int_convert.py`.
- 2026-06-03 restarted IDA MCP evidence and parent assignment:
  - What existed before: scores were `68/82`, and autogen parent metadata was blank.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:88`, and `AUTOGEN_PARENT_UID:0000HJ`.
  - Summary/evidence: live IDA MCP confirms the `void __thiscall(int this, int)` detach-helper shape, single destructor caller, registry pointer source at `AttachedObjectPane + 0x128`, detached-object type byte at `+0xf8`, list offsets `+0x170/+0x174`, singleton offsets `+0x1d8/+0x1dc/+0x1e0/+0x1e4`, no direct helper callees, and the `g_useEpfAssets`-gated type `8` clear. C++ remains blank because final registry owner/type names and constructor/setup evidence are not at the 95+ gate.
