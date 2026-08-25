*** UID:00038O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000DK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SpelledPane Vtables

## Status

- Entity kind: compiler-generated four-view vtable family derived from one source class declaration.
- Scope: `SpelledPane` four-view vtable layout.
- Disposition: non-emitting type/layout evidence parented to the `SpelledPane` class; never handwrite table bytes or pointers.
- Source candidate: [UID:0000NZ][SpelledPane](by-file/SpelledPane.md) or a shared text-pane source if later evidence proves a different original split.
- Created from B001-048 split research of [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md).

## Vtable Groups

| Class | Exact data range | Primary | Secondary | Tertiary | Extra view | Evidence |
| --- | --- | --- | --- | --- | --- | --- |
| `SpelledPane` | [UID:0002UZ][0x006242c4-0x00624384.SpelledPaneVtableData](by-memory/0x006242c4-0x00624384.SpelledPaneVtableData.md) | `0x006242c8` | `0x00624340` | `0x00624370` | `0x0062437c` | Constructor stores at `0x0056bb92`, `0x0056bb98`, `0x0056bba2`, `0x0056bbac`; destructor-neighborhood stores at `0x0056bc26`, `0x0056bc2c`, `0x0056bc36`, `0x0056bc40`. |

## Boundary Evidence

- The exact table span is `0x006242c4-0x00624384`, beginning at the `SpelledPane` RTTI record and ending before `LegendPane`.
- `SpelledPane` is used by self-look and message/status flows, so consumer xrefs are not proof of a single owning source page.
- This page is split out from [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md), which remains a non-emitting cross-source index.

## Assignment Gate

`AUTOGEN_PARENT_UID` is [UID:0000DK][SpelledPane](by-class/SpelledPane.md). This page covers a single class vtable layout, so the class is the narrowest direct semantic parent and already clears the strict gate at `94/94`; its file parent [UID:0000NZ][SpelledPane](by-file/SpelledPane.md) clears at `93/93`. Exact child [UID:0002UZ][0x006242c4-0x00624384.SpelledPaneVtableData](by-memory/0x006242c4-0x00624384.SpelledPaneVtableData.md) can route here without using the broad cross-source [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md).

## Score Rationale

Completion `93` and confidence `95` are supported by exact RTTI/vtable boundaries, constructor stores, callback-slot references, complete-object offsets, and the resolved `TextEditPane` plus `FrameHandler` source declaration. The tables are compiler output and therefore intentionally non-emitting.

## Source Regeneration Disposition

- [UID:0000DK][SpelledPane](by-class/SpelledPane.md) declares `class SpelledPane : public TextEditPane, public FrameHandler`, a virtual destructor, primary mouse/key-text overrides, and the FrameHandler update override. That ordinary declaration regenerates all four binary views.
- Primary and secondary source callbacks route to exact children [UID:0004YU][0x0056c2e0-0x0056c2e5.SpelledPaneHandleKeyOrTextEvent](by-memory/0x0056c2e0-0x0056c2e5.SpelledPaneHandleKeyOrTextEvent.md), [UID:0004YV][0x0056c2f0-0x0056c2f5.SpelledPaneOnMouseEvent](by-memory/0x0056c2f0-0x0056c2f5.SpelledPaneOnMouseEvent.md), and [UID:0004YW][0x0056c300-0x0056c3f1.SpelledPaneOnFrameUpdate](by-memory/0x0056c300-0x0056c3f1.SpelledPaneOnFrameUpdate.md).
- [UID:0002UZ][0x006242c4-0x00624384.SpelledPaneVtableData](by-memory/0x006242c4-0x00624384.SpelledPaneVtableData.md) remains exact binary evidence and is likewise non-emitting. Formal CPP/H stay blank here to prevent duplicate handwritten compiler machinery.

## Cross-References

- [UID:0000NZ][SpelledPane](by-file/SpelledPane.md)
- [UID:0000DK][SpelledPane](by-class/SpelledPane.md)
- [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md)

## Changes

- 2026-07-29 Agent-B001 UID0001HA callback: changed `87/91 -> 93/95`, `RECONSTRUCTABLE:TRUE -> FALSE`, and cleared the emitter. The complete class declaration now owns source semantics; this page retains exact four-view layout and slot evidence only.

- 2026-06-11 Agent-A001 Batch 232:
  - Before: `86/91`, parent blank pending stale source/class gate notes.
  - Changed to: `87/91`, `AUTOGEN_PARENT_UID:0000DK`.
  - Evidence: [UID:0000DK][SpelledPane](by-class/SpelledPane.md) is `87/86` and its file parent is `87/85`; live IDA rechecked the four table bases and store refs while routing [UID:0002UZ][0x006242c4-0x00624384.SpelledPaneVtableData](by-memory/0x006242c4-0x00624384.SpelledPaneVtableData.md) through this type page.
- 2026-06-11 supervisor implementation of B001-048: created source-local SpelledPane vtable page instead of using the broad multi-owner LookPane vtable family as a parent.

## 2026-07-29 Supervisor Gate 2B IDA Reconciliation

- Gate 2B assigned exact source-facing identities and prototypes to all three SpelledPane vtable callbacks:
  - `[0x0056c2e0,0x0056c2e5)` `SpelledPane__HandleKeyOrTextEvent`, `bool __thiscall(SpelledPane *this, Event *event)`: SpelledPane EventHandler key/text override; intentionally returns false without consuming the event.
  - `[0x0056c2f0,0x0056c2f5)` `SpelledPane__OnMouseEvent`, `bool __thiscall(SpelledPane *this, Event *event)`: SpelledPane mouse-event override; intentionally returns false without consuming the event.
  - `[0x0056c300,0x0056c3f1)` `SpelledPane__OnFrameUpdate`, `bool __thiscall(SpelledPane *this, const FrameUpdateContext *context)`: SpelledPane FrameHandler callback; decrements positive entry lifetimes, removes expired entries, rebuilds text while restoring scroll, and reschedules after 50 frames.
- The callback identities were read back at the same vtable slots and xrefs: A08 from `0x00624348`, A09 from `0x00624328`, and A10 from `0x00624380`. Their incoming xref counts remain one each, their byte hashes remain A08/A09 `CC0E3CB106EB0FDEC984D44A563D98C3DA80700BBB8D2BE4E66EBD54A9919626` and A10 `7A99329BF7E33B18CA4CC60C7EDD365E24BA1A2CC4FB32CE2C5AFDF7D342B68C`, and no vtable cell or table byte changed.
- Gate 2B declared an incomplete `FrameUpdateContext` analysis type solely to express A10's exact callback prototype. Authoritative saved database: session `1da2b2ae`, SHA256 `0E0AF9383DE743CB91E076959498A0D9DAF906C5CA6E620F99425931A09AB481`, 143,190,636 bytes, saved `2026-07-29T13:59:50.138-04:00`; backup `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B001-UID0001HA-20260729-135636.i64`; catalog entry `0361`. Agent-B001 made no IDA mutation.

## 2026-07-29 Shared IDB Currentness Recheck

- The `0E0AF938...AB481` applied checkpoint and `03F102...DBE5DA` prestate are historical. Current authoritative session `1da2b2ae` is `3C8F31781C94DF74AADDB65B3D944CD2CA4387C448918BBBFFD60B41C3625B69`, 143,191,631 bytes, saved `2026-07-29T14:12:44.7229687-04:00`.
- Read-only recheck preserved A08/A09/A10 identities, types, comments, body hashes, one-ref callback routes, exact slots `0x624348/0x624328/0x624380`, four table views, and incomplete `FrameUpdateContext`. No vtable bytes changed; Agent-B001 did not mutate/save IDA.
- Currentness supersession: `3C8F3178...5B69` is historical. Current authoritative session `1da2b2ae` is `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B`, 143,190,676 bytes, last write `2026-07-29T14:22:15.9735862-04:00`; all callback/table evidence again matched.
- Currentness supersession: `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B` and every earlier identity are now dated history. Current authoritative session `1da2b2ae` is saved SHA256 `905D1AB131C953911CD1DF5E536AF36EAECFA67486E2F800907B36C0673604C1`, 143,190,814 bytes, last write `2026-07-29T14:42:53.5091352-04:00`; bounded read-only target/dependency readback again found zero UID0001HA drift across exact names, ranges, prototypes, four comment channels, body hashes, xref counts, padding, callback slots, literals, helper identities, and relevant type state. A02/A03 retain exact typed analysis with the same bounded Hex-Rays failures at `0x0056bc15` and `0x0056bc84`. Agent-B001 did not mutate or save IDA.
