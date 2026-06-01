*** UID:0001VI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Parcel Notification Pane Layouts

## Status

- Entity kind: class layout notes for the parcel notification pane family.
- Covered classes: [UID:0000A5][ParcelIconPane](by-class/ParcelIconPane.md), [UID:0000A6][ParcelPane](by-class/ParcelPane.md), and [UID:000058][FlyingParcelPane](by-class/FlyingParcelPane.md).
- Likely source owner: [UID:0000MF][ParcelPane](by-file/ParcelPane.md).
- Vtable companion: [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md).
- Confidence: strong for listed offsets; medium for final field names.
- Reconstructable: source-declared layout knowledge for the parcel notification source module. Final C++ declarations are deferred until field names and helper API names are stronger.

All three classes derive from [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md). The base pane occupies `+0x00..+0xf7`; parcel-family fields begin at `+0xf8`. Secondary callbacks receive `this == owner + 0xa0`; timer callbacks receive `this == owner + 0xa4`, so IDA decompiler offsets must be normalized back to the owner object.

## ParcelIconPane

IDA shows `ParcelIconPane` as the outer notification owner. It stores a child [UID:0000A6][ParcelPane](by-class/ParcelPane.md) pointer and the most recent parcel counts decoded from the packet callback.

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `+0x00` | `Pane` base / primary vtable | Constructor `0x00545e40` calls `Pane::Pane`, then installs primary table `0x00621bb4`. |
| `+0xa0` | secondary handler view | Constructor and destructors install secondary table `0x00621c00`; packet callback `0x005461c0` is slot `+0x10` in this table. |
| `+0xa4` | tertiary handler view | Constructor and destructors install tertiary table `0x00621c30`. |
| `+0xf8` | total parcel count/state byte | Packet callback writes secondary `this + 0x58`, which normalizes to owner `+0xf8`. |
| `+0xf9` | left parcel count/id byte | Packet callback writes secondary `this + 0x59`, normalized owner `+0xf9`. |
| `+0xfa` | right parcel count/id byte | Packet callback writes secondary `this + 0x5a`, normalized owner `+0xfa`. |
| `+0xfc` | `ParcelPane*` child pane | Constructor stores the allocated 0x124-byte child at `+0xfc`; destructor reads `Block[63]`; packet callback dereferences secondary `this + 0x5c`. |

## ParcelPane

The child pane is allocated as 292 bytes (`0x124`) by `ParcelIconPane::ParcelIconPane`, which bounds the real `ParcelPane` derived state. Generated fields beyond `+0x124` come from unrelated methods attached to `class_ParcelPane.cpp` and should not be used for this layout.

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `+0x00` | `Pane` base / primary vtable | Constructors install primary table `0x00621c3c`; scalar destructor `0x00547000` restores it. |
| `+0xa0` | secondary input-handler view | Secondary vtable `0x00621c90` owns mouse/key callbacks. |
| `+0xa4` | timer/update view | Tertiary vtable `0x00621cc0` owns timer callback `0x00546810`. |
| `+0xf8` | total parcel state/count byte | Constructor clears it; `SetParcelSlotData` writes the first argument. |
| `+0xf9` | left slot id/count byte | Constructor clears it; packet callback forwards the left nibble through `SetParcelSlotData`. |
| `+0xfa` | right slot id/count byte | Constructor clears it; packet callback forwards the right nibble through `SetParcelSlotData`. |
| `+0xfb` | new/right-side activation flag | Constructor initializes it to `1`; `FlyingParcelPane::AnimateStep` sets it after parcel delivery; mouse handler tests it before opening the right-side action path. |
| `+0xfc` | left button state byte | `OnPaint` passes `this + 0xfc` to the frame-index virtual; mouse and timer paths update it. |
| `+0xfd` | right button state byte | `OnPaint` passes `this + 0xfd` to the frame-index virtual; mouse and timer paths update it. |
| `+0xfe` | left animation frame byte | Constructor initializes this to `0xfd` (-3); timer callback passes it with `+0xfc` into `UpdateAnimationCounter`. |
| `+0xff` | right animation frame byte | Timer callback passes it with `+0xfd` into `UpdateAnimationCounter`. |
| `+0x100` | left button `RECT` | Constructor initializes `(0,0,30,25)`; `OnMouseEvent` hit-tests this rect after secondary-offset normalization. |
| `+0x110` | right button `RECT` | Constructor initializes `(31,0,62,25)`; `OnMouseEvent` hit-tests this rect after secondary-offset normalization. |
| `+0x120` | left slot consumed/acknowledged byte | Timer callback checks it before animating the left slot; mouse activation sets it. |
| `+0x121` | right slot consumed/acknowledged byte | Timer callback checks it before animating the right slot; mouse activation sets it. |

## FlyingParcelPane

`FlyingParcelPane` is the transient animation helper. It reuses `Pane` bounds/origin fields and adds only compact parcel payload state plus an owned 8-byte render/helper object.

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `+0x00` | `Pane` base / primary vtable | Constructor `0x00546ac0` installs primary table `0x00621ccc`. |
| `+0xa0` | secondary handler view | Constructor, raw cleanup body, and scalar destructor install secondary table `0x00621d18`. |
| `+0xa4` | timer/update view | Tertiary table `0x00621d48` owns `AnimateStep` at slot `+0x04`. |
| `+0xf8` | animation tick/frame byte | Start/configure body clears it; `AnimateStep` increments it until it reaches `0x1e`. |
| `+0xf9` | total parcel state/count byte | Start/configure stores first argument; `AnimateStep` forwards it to `ParcelPane::SetParcelSlotData`. |
| `+0xfa` | right slot id/count byte | Start/configure stores third argument; `AnimateStep` forwards it as the right slot value. |
| `+0xfb` | left slot id/count byte | Start/configure stores second argument; `AnimateStep` forwards it as the left slot value. |
| `+0xfc` | parcel-vs-letter flag | Start/configure stores fourth argument; `DrawParcel` chooses `ALERTBTN.*` when nonzero, otherwise `LETTER.*`. |
| `+0x100` | owned render/helper pointer | Constructor allocates 8 bytes and initializes the helper; raw cleanup and scalar destructor call its virtual delete. |

## Wave3 Caveats

- `class_ParcelPane.meta_wave3` reports `vtable_count: 0` and includes generated fields beyond the real 0x124-byte parcel child allocation because it attaches unrelated helpers such as `0x005051c0`.
- `class_ParcelIconPane.meta_wave3` reports `vtable_count: 0` and emits only destructor-side active code.
- `class_FlyingParcelPane.meta_wave3` reports `vtable_count: 0`, has no recovered field list, omits `0x00546b80` and `0x00546bc0`, and disables false post-vtable rows.

## IDA MCP Recheck

- 2026-05-31 IDA MCP enumeration confirms wrapped functions from `0x00545e40` through `0x005470ad`, including the newly split ParcelPane/FlyingParcelPane methods and singleton clear helpers.
- IDA decompilation reconfirms the `0x124`-byte ParcelPane child object, byte fields at `+0xf8..+0x121`, `FlyingParcelPane` payload at `+0xf8..+0x100`, and secondary/tertiary subobject offset normalization.
- The unwrapped raw `0x00546b80` and `0x00546bc0` starts remain documented as raw lifecycle/start bodies rather than IDA function objects.

## Cross References

- [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- [UID:0001EH][0x00545e40-0x005470ac.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ac.ParcelNotificationPanes.md)
- [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md)
- [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-05-31: Grading changed from `0/0` to `78/84`, marked reconstructable, and attached to [UID:0000MF][ParcelPane](by-file/ParcelPane.md).
  - Before: layout evidence was detailed but the page remained unevaluated to validator/stat tooling.
  - After: the score reflects current IDA-verified class layouts, vtable subobjects, field offsets, child object bound, and split child method pages.
  - Evidence: IDA MCP function enumeration/decompilation checked the parcel notification range, constructors, slot update, input/timer/paint helpers, flying parcel animation, draw helper, singleton clear helpers, and destructor boundaries.
