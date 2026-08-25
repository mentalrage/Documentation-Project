*** UID:0000C9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ScreenEffecter is the root virtual interface for the Effects family.
// Formal class C++ is intentionally withheld until the three state-predicate
// slot names used by AreAllEffectsComplete are source-quality. Current MCP
// confirms the 0x0055c1d0 body and folded true/false stubs, but only the
// IsPixelEffecter direction is naming-ready.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScreenEffecter

## Status

- Confidence: very strong for base-class role, vtable identity, and exact method behavior; medium-high for final header split and final virtual names.
- Proposed source: `render/Effects.cpp`
- Proposed header: `render/Effects.h`
- Legacy generated-source alias, for searching only: `class_ScreenEffecter.cpp`
- Current code ranges inside [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md): `0x0055a260-0x0055a297`, `0x0055bfd0-0x0055bff4`, and `0x0055c1d0-0x0055c1ff`.
- Autogen parent: [UID:0000IZ][Effects](by-file/Effects.md), now `90/88` and assigned to `NexusTK/render/`. Formal output is comment-only under a target-specific no-code policy, not an old score threshold: this page is the abstract root/interface record for the runtime effecter family, while exact subclasses and exact by-memory method pages carry source-ready declarations or bodies when their names/layouts are resolved.

## Responsibility

`ScreenEffecter` is the base virtual interface for runtime screen effects. It provides scalar deleting cleanup and a completion predicate that checks three virtual effect-state slots.

The class is the common root for pixel, overlay, and filter effecters documented in [UID:0000IZ][Effects](by-file/Effects.md). Several subclasses only install a vtable and store effect parameters, which supports treating them as one source-module family rather than independent original files.

B002's 2026-06-17 MapPane pass documents one external consumer of the first category slot: [UID:0002I2][0x00503e90-0x00503ecd.MapPaneFindActiveEffect](by-memory/0x00503e90-0x00503ecd.MapPaneFindActiveEffect.md) iterates MapPane's `ScreenEffecter *` list and uses vtable slot `+0x00` as a pixel/primary-effect predicate before Layer invokes the returned effecter's apply slot.

The live vtable evidence indicates a vptr-only base layout. The scalar deleting destructor frees `0x4` / 4 bytes (Verified with `int_convert.py`) when the deletion flag is set, and no data fields beyond the primary vptr are currently evidenced for the base class itself.

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055a260-0x0055a269` | base vtable install / constructor-like stub | Stores `??_7ScreenEffecter@@6B@` at `[ecx]`, returns `this`; size `0x9` / 9 bytes (Verified with `int_convert.py`). |
| `0x0055a270-0x0055a271` | no-op virtual body | One-byte `ret` body used by the base vtable. |
| `0x0055a280-0x0055a281` | no-op virtual body | Second one-byte `ret` body used by the base vtable. |
| `0x0055a290-0x0055a297` | base vtable reset helper | Stores `??_7ScreenEffecter@@6B@` and returns; size `0x7` / 7 bytes (Verified with `int_convert.py`). |
| `0x0055bfd0-0x0055bff4` | scalar deleting destructor | Resets base vtable and conditionally deletes `this`; size `0x24` / 36 bytes (Verified with `int_convert.py`). |
| `0x0055c1c0-0x0055c1c3` | default false state virtual / inferred `IsPixelEffecter()` false for slot `+0x00` | Returns `false`; `ScreenEffecter` uses it in the first three vtable slots. The first slot is consumed by MapPane as a pixel/primary-effect predicate, with `IsPixelEffecter()` / `UsesPrimaryEffectPass()` as descriptive source-name candidates; the physical false body is folded with SystemMessagePanes and runtime tables in [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md). |
| `0x0055c1d0-0x0055c1ff` | `AreAllEffectsComplete` | Calls the first three virtual state checks and returns true only when all return false; size `0x2f` / 47 bytes (Verified with `int_convert.py`). |

## Evidence Notes

- [UID:0000IZ][Effects](by-file/Effects.md) is scored `90/88`, assigned to `NexusTK/render/`, and identifies `ScreenEffecter` as the base virtual effect interface for the runtime effecter family.
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) is scored `88/90`, reconstructable, and attached to [UID:0000IZ][Effects](by-file/Effects.md); it records the tiny base vtable/default stubs at `0x0055a260-0x0055a297`, the scalar deleting destructor strip, the completion predicate at `0x0055c1d0-0x0055c1ff`, raw constructor islands, active MCP session `nexustk_supervisor_20260704` no-function/no-xref and pointer-pattern-negative evidence, and the comment-only aggregate policy for the broad runtime cluster.
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md) records the `ScreenEffecter` vtable base at `0x006235a4`. Its slot refresh shows `0x0055c1c0`, `0x0055c1c0`, `0x0055c1c0`, `0x0055c1d0`, `0x0055a270`, `0x0055a280`, and `0x0055bfd0`, matching this page's method inventory.
- [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md) and the runtime aggregate keep the stale generated global-name caveat separate from the class identity: the old `g_pScreenEffecterList` alias is shared UI layer/context storage, not an owned `ScreenEffecter` list declaration.
- [UID:0002I2][0x00503e90-0x00503ecd.MapPaneFindActiveEffect](by-memory/0x00503e90-0x00503ecd.MapPaneFindActiveEffect.md) consumes the first category slot as an inferred `IsPixelEffecter()` / primary-effect predicate. This is source-facing inference, not original-name proof; a later whole-family Effects pass may choose a different spelling such as `UsesPrimaryEffectPass()`.
- 2026-06-18 B002 MapPane effect-list helper pass: [UID:0002I6][0x005040a0-0x00504102.MapPaneClearEffectList](by-memory/0x005040a0-0x00504102.MapPaneClearEffectList.md) consumes the primary vtable slot `+0x18` as the scalar deleting destructor with flag `1`; source-level MapPane code should represent that call as `delete effecter;`, not as a hand-authored `Cleanup(1)` or `Destroy(1)` method.
- B001 2026-06-18 reanalysis keeps [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md) no-owner/non-emitting even though this class uses the false body. The same physical stub is folded with SystemMessagePanes marker slots and runtime/startup table cells, so the class should document the virtual predicate semantics rather than claim the folded address as class-owned source.

## 2026-06-13 IDA Refresh

Live IDA MCP session `a003_goal2_rtti_type_descriptors` on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` rechecked the base class:

- `lookup_funcs` confirms modeled function heads at `0x0055a260`, `0x0055a270`, `0x0055a280`, `0x0055a290`, `0x0055bfd0`, `0x0055c1c0`, and `0x0055c1d0`; `0x0055c1ff` is not a function head and is the exclusive end after the completion predicate.
- `analyze_function(0x0055bfd0)` decompiles as a scalar deleting destructor: store `??_7ScreenEffecter@@6B@`, test the low deletion flag, push size `0x4` / 4 bytes (Verified with `int_convert.py`), call the sized free helper, and return `this`.
- `analyze_function(0x0055c1d0)` decompiles as a predicate over three virtual calls at offsets `+0`, `+4`, and `+8`; it returns true only if all three calls return false.
- `disasm(0x0055a260)` and `disasm(0x0055a290)` both show direct stores of `??_7ScreenEffecter@@6B@`; `disasm(0x0055a270)` / `0x0055a280` are one-byte no-op virtual returns, and `disasm(0x0055c1c0)` is `xor al, al; retn`.
- `trace_data_flow` backward from `0x006235a4` reports stores/resets from the base stubs, `0x0055bfd0`, and derived teardown paths across overlay, filter, water, lake, and pixel-effect branches, confirming that this vtable is the common base target rather than a standalone subclass table.

## Assignment Gate

The class remains reconstructable and assigned to [UID:0000IZ][Effects](by-file/Effects.md). The active code-entry gate is clear: this page is `86/90`, the direct file parent is `90/88`, and older `95/95` threshold wording is stale. This page still keeps formal source comment-only for a target-specific reason: `ScreenEffecter` is the family root/interface record, exact virtual predicate spelling remains support-level, and whole-family header/source split remains unresolved. Exact subclasses and by-memory method pages should emit source when their own evidence supports it.

## Derived Runtime Families

- [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md): base for map/pixel effects such as [UID:000046][EarthquakeEffecter](by-class/EarthquakeEffecter.md), [UID:0000GC][XWaveEffecter](by-class/XWaveEffecter.md), [UID:0000GD][YFlipEffecter](by-class/YFlipEffecter.md), and [UID:000070][LakeEffecter](by-class/LakeEffecter.md).
- [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md): base for pane-backed overlay images and moving/frame overlay effects.
- [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md): base for full-screen filters such as color, cloud, static cloud, and water filters.

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md)
- [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md)
- [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md)
- [UID:0002I2][0x00503e90-0x00503ecd.MapPaneFindActiveEffect](by-memory/0x00503e90-0x00503ecd.MapPaneFindActiveEffect.md)

## 2026-06-30 B006 Empty-Emitter Callback

Formal output is now a comment-only root-interface block. Historical B006 MCP database `supervisor_resume_20260629` confirmed modeled base stubs and destructor/reset paths plus `0x0055c1d0` as the completion predicate over three virtual state checks; B004 active session `nexustk_supervisor_20260704` reconfirmed the cluster inventory, raw starts, no-xref/no-pointer route, and `0x0055c1d0` representative decompile during the 2026-07-04 UID0001GE callback. The folded true/false stubs remain shared physical bodies; this page documents source semantics at the class/vtable level instead of claiming [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md) as a standalone Effects helper. Only the `IsPixelEffecter()` direction is naming-ready, so the remaining predicate slot names and whole-family header/source split still block a full `ScreenEffecter` class declaration here.

## Changes

- 2026-07-04 B004 UID0001GE support sync:
  - Class metadata unchanged at `86/90`.
  - Summary/evidence: updated the UID0001GE support row from stale `82/86` wording to the accepted target `88/90` state. Active MCP session `nexustk_supervisor_20260704` supports the runtime-cluster function inventory, raw constructor no-function/no-xref status, pointer-pattern negatives, vtable-store positive controls, representative `0x0055c1d0` decompile, and comment-only aggregate output policy; old `supervisor_resume_20260629` wording is now historical.
- 2026-06-18 B001 folded-boolean slot sync:
  - Score unchanged at `86/90`.
  - Summary/evidence: documented that the first `ScreenEffecter` boolean slot remains best described as inferred `IsPixelEffecter()` / `UsesPrimaryEffectPass()` false, but [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md) remains a folded physical helper shared with SystemMessagePanes and runtime tables, not class-owned source.
- 2026-05-30: Changed completion/confidence from `0/0` to `72/76`.
  - Before: The page was unevaluated despite documenting the base effecter responsibility, two method bodies, and derived runtime families.
  - After: Scored as moderate-high completion and confidence because the base role is clear but final header split and deeper virtual-state semantics remain open.
  - Evidence: Existing responsibility notes, method table, derived-family map, vtable family reference, runtime-cluster reference, and global list cross-reference support the score.
- 2026-06-03 parent attachment pass:
  - What existed before: the page had the base role and method family documented but remained unattached with blank reconstructable metadata and `72/76` scoring.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:82`, `RECONSTRUCTABLE:TRUE`, and parent [UID:0000IZ][Effects](by-file/Effects.md).
  - Summary/evidence: the Effects file doc, runtime aggregate, and vtable-family page give enough written evidence for source ownership and parent placement. Formal output was withheld under the then-current reconstruction gate; current docs treat this as a target-specific root/interface comment-only policy rather than a `95+` threshold rule.
- 2026-06-13 Goal 2 refresh:
  - What existed before: the page was `76/82`, had stale parent-score text, inclusive-looking method endpoints, and did not record the current IDA method/vtable evidence.
  - Changed to: `86/90`, corrected half-open method ranges, added the tiny base vtable/default stubs, documented the vptr-only base-layout evidence, and retained parent [UID:0000IZ][Effects](by-file/Effects.md).
  - Summary/evidence: live IDA MCP confirmed the base stubs, destructor size and delete behavior, default false virtual, completion predicate behavior, `ScreenEffecter` vtable slots, and cross-family vtable reset/store xrefs. The direct parent now clears `90/88`, so assignment remains justified; formal output is comment-only for the target-specific root/interface reason documented above, not because of the old final-source gate.
