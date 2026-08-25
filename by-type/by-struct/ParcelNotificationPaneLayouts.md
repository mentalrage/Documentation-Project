*** UID:0001VI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Parcel Notification Pane Layouts

## B001 UID0002ZO Accepted Callback State - 2026-07-21

This support page is complete at `92/94`, semantically routed to UID0000MF but intentionally non-reconstructable, non-emitting, positionless, and formally blank. It retains exact normalized Pane subobject views, direct empty Singleton PMDs/EBO, ParcelIconPane size `0x104`, ParcelPane size `0x124`, FlyingParcelPane size `0x104`, all accepted fields/enums, and natural alignment with no explicit padding members. The three complete class declarations alone emit those fields.

## Status

- Entity kind: class layout notes for the parcel notification pane family.
- Covered classes: [UID:0000A5][ParcelIconPane](by-class/ParcelIconPane.md), [UID:0000A6][ParcelPane](by-class/ParcelPane.md), and [UID:000058][FlyingParcelPane](by-class/FlyingParcelPane.md).
- Likely source owner: [UID:0000MF][ParcelPane](by-file/ParcelPane.md).
- Vtable companion: [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md).
- Confidence: strong for listed offsets, object-size bounds, callback-offset normalization, covered class relationships, vtable companion, direct file ownership, and accepted ParcelPane count/state/frame field names; medium-high for final helper API spelling.
- Reconstructable: source-declared layout knowledge for the parcel notification source module. `ParcelIconPane` now has a complete class declaration; broader ParcelPane/FlyingParcelPane timer, input, and helper spellings retain their independent caps. This support page remains a no-standalone-body marker.

All three classes derive from [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md). The base pane occupies `+0x00..+0xf7`; parcel-family fields begin at `+0xf8`. Flying animation code also touches owner `+0xac`, but that offset is inherited `Pane` origin/position state used by the start/timer paths, not derived `FlyingParcelPane` payload. Secondary callbacks receive `this == owner + 0xa0`; timer callbacks receive `this == owner + 0xa4`, so IDA decompiler offsets must be normalized back to the owner object. These constants were rechecked on 2026-06-13: `0xf8` is 248, `0xfc` is 252, `0xa0` is 160, and `0xa4` is 164 (Verified with int_convert.py).

2026-06-17 B001/B002 reanalysis resolves the main ParcelPane and FlyingParcelPane field names used by the timer/frame helpers. Packet callback code splits a packed parcel count byte into total, left, and right counts; mouse code writes button hover/pressed states; the timer helper writes animating state and frame bytes. Use count/state/frame names rather than generated id names. For `FlyingParcelPane`, use the animation payload names accepted below instead of generic payload/helper placeholders.

2026-06-26 B004 confirms the `FlyingParcelPane` ownership/release semantics for the `+0x100` field. The best source-facing name is `Layer *m_animationLayer`: constructor [UID:0002KJ][0x00546ac0-0x00546b74.FlyingParcelPaneConstructor](by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md) assigns `new Layer`, [UID:0002R6][0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation](by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md) attaches/configures it through ScreenPane helpers, [UID:0002KK][0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep](by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md) removes it through `g_pScreenPane->RemoveLayer(m_animationLayer)`, and [UID:0002R5][0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody](by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md) now emits ordinary destructor source for releasing `m_animationLayer`. `m_screenLayerEntry` remains a descriptive alias for prose only, not the preferred formal C++ name.

2026-06-25 B002 constructor implementation confirms the standalone `ParcelPane::ParcelPane()` source initialization shape. The stable constructor state is total/left/right counts `0`, `m_rightSlotActionEnabled = true`, both button states idle, left animation frame `-3`, right animation frame `0`, both acknowledgement flags false, and button rects `(0,0,30,25)` / `(31,0,62,25)`, followed by `SetParcelSlotData(0,0,0)`, order registration, and the initial 100 ms timer. A transient constructor byte store at `+0xfc` is overwritten by the inlined zero-slot reset before external attach/invalidate/timer-visible behavior, so it is not a separate source field or enum value.

2026-06-25 B002 SetParcelSlotData implementation confirms the setter-specific layout semantics. The method writes `m_totalParcelCount`, `m_leftParcelCount`, and `m_rightParcelCount` at `+0xf8/+0xf9/+0xfa`; clears `m_leftSlotAcknowledged` and `m_rightSlotAcknowledged` at `+0x120/+0x121` only when the corresponding count changes; sets `m_leftButtonState` and `m_rightButtonState` at `+0xfc/+0xfd` to idle when the corresponding new count is zero; and does not clear the animation-frame bytes `+0xfe/+0xff`. This supersedes older wording that grouped the empty-slot reset as an animation-byte clear.

2026-06-26 B002 OnMouseEvent implementation confirms the action-side layout semantics. [UID:0002KE][0x00546610-0x00546807.ParcelPaneOnMouseEvent](by-memory/0x00546610-0x00546807.ParcelPaneOnMouseEvent.md) sets `m_leftSlotAcknowledged` at `+0x120` after a left-slot release sends literal packet byte `0x41` through `g_packetSender->QueueAndSendPacket`, and sets `m_rightSlotAcknowledged` at `+0x121` after a right-slot release passes the `m_rightSlotActionEnabled` / `g_pBulletinSession` gate and constructs `new BulletinSession(1, 0, true)`. `SetParcelSlotData` is the count-change path that clears those acknowledgement flags.

## ParcelIconPane

IDA shows `ParcelIconPane` as the outer notification owner. It stores a child [UID:0000A6][ParcelPane](by-class/ParcelPane.md) pointer and the most recent parcel counts decoded from the packet callback.

RTTI proves two direct non-virtual source bases: `Pane` and `Singleton<ParcelIconPane>`. The Singleton base has PMD `mdisp=0xf8` and is empty-base optimized, so it overlaps the first derived byte field without consuming a separate storage span. Its inlined construction/destruction owns unconditional publication/clear of `g_pParcelIconPane`; those stores are not additional derived members or handwritten constructor/destructor statements.

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `+0x00` | `Pane` base / primary vtable | Constructor `0x00545e40` calls `Pane::Pane`, then installs primary table `0x00621bb4`. |
| `+0xa0` | secondary handler view | Constructor and destructors install secondary table `0x00621c00`; packet callback `0x005461c0` is slot `+0x10` in this table. |
| `+0xa4` | tertiary handler view | Constructor and destructors install tertiary table `0x00621c30`. |
| `+0xf8` | total parcel count byte | Packet callback writes secondary `this + 0x58`, which normalizes to owner `+0xf8`, after summing the split parcel-count nibbles. |
| `+0xf9` | left parcel count byte | Packet callback writes secondary `this + 0x59`, normalized owner `+0xf9`. |
| `+0xfa` | right parcel count byte | Packet callback writes secondary `this + 0x5a`, normalized owner `+0xfa`. |
| `+0xfb` | natural alignment | One byte aligns the following pointer; no independent read/write or source field is evidenced. |
| `+0xfc` | `ParcelPane*` child pane | Constructor stores the allocated 0x124-byte child at `+0xfc`; destructor reads `Block[63]`; packet callback dereferences secondary `this + 0x5c`. |
| `+0x100` | inferred inactive `int m_notificationState` | Two callers allocate `0x104`; the scalar wrapper's sized path also uses `0x104`. No constructor, EH, destructor, callback, singleton consumer, adjusted view, or bounded whole-project displacement search reads or writes this final dword. An inactive 32-bit status member is the highest-ranked project-era source shape and remains intentionally uninitialized. |

The complete `ParcelIconPane` size is therefore exactly `0x104`. Ranked alternatives for `+0x100` are: inactive 32-bit state first; one-byte pending flag plus tail padding second; enum third. A pointer is rejected because no pointer-sized use, initialization, ownership, or teardown exists. An explicit reserved-byte array is rejected because project-era evidence does not establish deliberate reserved storage and the current source-quality policy prefers a realistic inactive scalar over reverse-engineering padding syntax. The original member spelling and meaning remain inferred, which caps confidence without blocking declaration or source generation.

## ParcelPane

The child pane is allocated as 292 bytes (`0x124`) by `ParcelIconPane::ParcelIconPane`, which bounds the real `ParcelPane` derived state (Verified with int_convert.py). Generated fields beyond `+0x124` come from unrelated methods attached to generated ParcelPane output and should not be used for this layout.

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `+0x00` | `Pane` base / primary vtable | Constructors install primary table `0x00621c3c`; scalar destructor `0x00547000` restores it. |
| `+0xa0` | secondary input-handler view | Secondary vtable `0x00621c90` owns mouse/key callbacks. |
| `+0xa4` | timer/update view | Tertiary vtable `0x00621cc0` owns timer callback `0x00546810`. |
| `+0xf8` | `m_totalParcelCount` | Constructor clears it; `SetParcelSlotData` writes the packet-derived total count. |
| `+0xf9` | `m_leftParcelCount` | Constructor clears it; packet callback forwards the left nibble/count through `SetParcelSlotData`. |
| `+0xfa` | `m_rightParcelCount` | Constructor clears it; packet callback forwards the right nibble/count through `SetParcelSlotData`. |
| `+0xfb` | `m_rightSlotActionEnabled` | Constructor initializes it to `1`; `FlyingParcelPane::AnimateStep` sets it after parcel delivery; mouse handler tests it before opening the right-side action path. |
| `+0xfc` | `m_leftButtonState` | `OnPaint` passes `this + 0xfc` to the frame-index virtual; mouse and timer paths update it using `ParcelButtonState`. The constructor's transient pre-reset byte store here is overwritten by `SetParcelSlotData(0,0,0)`, and `SetParcelSlotData` explicitly writes idle here whenever the new left count is zero. |
| `+0xfd` | `m_rightButtonState` | `OnPaint` passes `this + 0xfd` to the frame-index virtual; mouse and timer paths update it using `ParcelButtonState`. Constructor/source reset leaves it idle, and `SetParcelSlotData` writes idle here whenever the new right count is zero. |
| `+0xfe` | `m_leftAnimationFrame` | Constructor initializes this to `0xfd` (`-3`); timer callback passes it with `+0xfc` into `AdvanceButtonAnimation`. `SetParcelSlotData` does not clear this byte; empty-slot reset clears `m_leftButtonState` at `+0xfc`. |
| `+0xff` | `m_rightAnimationFrame` | Constructor initializes this to `0`; timer callback passes it with `+0xfd` into `AdvanceButtonAnimation`. `SetParcelSlotData` does not clear this byte; empty-slot reset clears `m_rightButtonState` at `+0xfd`. |
| `+0x100` | left button `RECT` | Constructor initializes `(0,0,30,25)`; `OnMouseEvent` hit-tests this rect after secondary-offset normalization. |
| `+0x110` | right button `RECT` | Constructor initializes `(31,0,62,25)`; `OnMouseEvent` hit-tests this rect after secondary-offset normalization. |
| `+0x120` | `m_leftSlotAcknowledged` | Timer callback checks it before animating the left slot; `ParcelPane::OnMouseEvent` sets it after a left-slot release sends packet byte `0x41`; `SetParcelSlotData` clears it when the left count changes. |
| `+0x121` | `m_rightSlotAcknowledged` | Timer callback checks it before animating the right slot; `ParcelPane::OnMouseEvent` sets it after a right-slot release constructs `new BulletinSession(1, 0, true)` under the `m_rightSlotActionEnabled` / `g_pBulletinSession` gate; `SetParcelSlotData` clears it when the right count changes. |

Recommended `ParcelButtonState` values: `0` idle, `1` hover, `2` pressed, and `3` animating. `ParcelPane::ResolveButtonFrameIndex` maps these values and the slot count/presence byte to `ALERTBTN.EPF` frames: left empty `0/1/2`, left occupied `3/4/5`, left animation `6..13`, right empty `14/15/16`, right occupied `17/18/19`, and right animation `20..27`.

## FlyingParcelPane

`FlyingParcelPane` is the transient animation helper. It reuses `Pane` bounds/origin fields and adds only compact parcel payload state plus an owned 8-byte `Layer`/screen-layer entry.

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `+0x00` | `Pane` base / primary vtable | Constructor `0x00546ac0` installs primary table `0x00621ccc`. |
| `+0xa0` | secondary handler view | Constructor, raw cleanup body, and scalar destructor install secondary table `0x00621d18`. |
| `+0xa4` | timer/update view | Tertiary table `0x00621d48` owns `AnimateStep` at slot `+0x04`. |
| `+0xf8` | `m_animationFrame` | `StartAnimation` clears it; `AnimateStep` increments it until it reaches `0x1e`. |
| `+0xf9` | `m_parcelCountOrState` | `StartAnimation` stores first argument; `AnimateStep` forwards it to `ParcelPane::SetParcelSlotData`. |
| `+0xfa` | `m_rightSlot` | `StartAnimation` stores third argument; `AnimateStep` forwards it as the right slot value. |
| `+0xfb` | `m_leftSlot` | `StartAnimation` stores second argument; `AnimateStep` forwards it as the left slot value. |
| `+0xfc` | `m_isParcel` | `StartAnimation` stores fourth argument; `DrawParcelOrLetter` chooses `ALERTBTN.*` when nonzero, otherwise `LETTER.*`. |
| `+0x100` | `Layer *m_animationLayer` / `m_screenLayerEntry` | Constructor allocates 8 bytes and initializes the Layer-style entry; start/config attaches it through ScreenPane, animation completion removes `m_animationLayer` through ScreenPane, and the source-ready ordinary destructor [UID:0002R5][0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody](by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md) emits the ownership release for `m_animationLayer`. The binary raw cleanup and scalar wrapper lower that release to a null check plus virtual deleting-dtor call with flag `1`. |

## Wave3 Caveats

- `class_ParcelPane.meta_wave3` reports `vtable_count: 0` and includes generated fields beyond the real 0x124-byte parcel child allocation because it attaches unrelated helpers such as `0x005051c0`.
- `class_ParcelIconPane.meta_wave3` reports `vtable_count: 0` and emits only destructor-side active code.
- `class_FlyingParcelPane.meta_wave3` reports `vtable_count: 0`, has no recovered field list, omits `0x00546b80` and `0x00546bc0`, and disables false post-vtable rows.

## IDA MCP Recheck

- 2026-05-31 IDA MCP enumeration confirms wrapped functions from `0x00545e40` through `0x005470ad`, including the newly split ParcelPane/FlyingParcelPane methods and singleton clear helpers.
- IDA decompilation reconfirms the `0x124`-byte ParcelPane child object, byte fields at `+0xf8..+0x121`, `FlyingParcelPane` payload at `+0xf8..+0x100`, and secondary/tertiary subobject offset normalization.
- The unwrapped raw `0x00546b80` and `0x00546bc0` starts remain documented as raw lifecycle/start bodies rather than IDA function objects.

## 2026-06-13 Live IDA Refresh

- IDA MCP session `a001_goal2_0002UM` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; `server_health` reported image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- `lookup_funcs` reconfirmed the layout-bearing function anchors and sizes: `0x00545e40` size `0x22a` / 554 bytes, `0x005461c0` size `0xcd` / 205 bytes, `0x00546290` size `0x1a6` / 422 bytes, `0x005464b0` size `0xc5` / 197 bytes, `0x00546810` size `0x78` / 120 bytes, `0x00546890` size `0xdf` / 223 bytes, `0x00546ac0` size `0xb4` / 180 bytes, `0x00546d70` size `0x7e` / 126 bytes, `0x00546df0` size `0x7b` / 123 bytes, and `0x00547000` size `0xad` / 173 bytes (Verified with int_convert.py).
- `xrefs_to` reconfirmed lifecycle stores for the three subobject vtable views: `ParcelIconPane` writes `0x00621bb4`, `0x00621c00`, and `0x00621c30` from constructor, destructor, and scalar deleting destructor paths; `ParcelPane` writes `0x00621c3c` from the icon constructor, its own constructor/destructor, and scalar deleting destructor; `FlyingParcelPane` writes the tertiary table `0x00621d48` from constructor, raw cleanup, and scalar deleting destructor paths.
- `analyze_function 0x00545e40` reconfirmed `ParcelIconPane` as the outer owner: it publishes `g_pParcelIconPane`, installs all three icon-pane vtable views, zeroes owner offsets `+0xf8..+0xfa`, allocates a 292-byte (`0x124`) child `ParcelPane`, constructs the child vtable views, initializes child slot fields and rectangles, schedules the child timer, and stores the child pointer at owner `+0xfc`.
- `analyze_function 0x005461c0` reconfirmed the secondary callback normalization: the callback reads packet byte `8`, decodes parcel nibbles, writes secondary offsets `+0x58..+0x5a` as owner `+0xf8..+0xfa`, reads secondary `+0x5c` as owner `+0xfc`, and forwards changes to `ParcelPane::SetParcelSlotData`.
- `analyze_function 0x00546290` and `0x005464b0` reconfirmed the standalone `ParcelPane` layout: constructor clears `+0xf8`, initializes `+0xf9..+0xfd`, creates button rectangles at `+0x100` and `+0x110`, and schedules the `+0xa4` timer view; `SetParcelSlotData` writes `+0xf8..+0xfa`, clears acknowledgement bytes at `+0x120/+0x121` when the corresponding count changes, and idles button-state bytes `+0xfc/+0xfd` when the corresponding count becomes zero. It does not clear animation-frame bytes `+0xfe/+0xff`.
- 2026-06-25 B002 MCP session `80de0a67` refines the constructor evidence: stable source fields are the accepted count/state/frame/ack fields, the inlined zero-slot reset overwrites the transient `+0xfc` byte store before visible behavior, `m_leftAnimationFrame` starts at `-3`, `m_rightAnimationFrame` starts at `0`, and first-draft `ParcelPane::ParcelPane()` now emits these initializers through [UID:0002KB][0x00546290-0x00546436.ParcelPaneConstructor](by-memory/0x00546290-0x00546436.ParcelPaneConstructor.md).
- `analyze_function 0x00546d70` reconfirmed `FlyingParcelPane` tertiary callback normalization from `this == owner + 0xa4`: payload bytes at callback `+0x84..+0x87` normalize to owner `+0xf8..+0xfb`, callback `+0x92` normalizes to owner `+0x100`, and completion updates `g_pParcelPane`.
- `analyze_function 0x00546df0` reconfirmed `FlyingParcelPane` draw mode: owner `+0xfc` selects `ALERTBTN.EPF`/`ALERTBTN.PAL` versus `LETTER.EPF`/`LETTER.PAL`.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `92` | The page contains the complete three-class layout, direct bases, PMD/EBO geometry, exact sizes/fields/enums, callback normalization, natural alignment, and declaration-owned emission route; no standalone layout source remains. |
| Confidence `94` | Constructor allocations, scalar-wrapper size lowering, RTTI, all live accesses, exhaustive negative evidence, and complete declarations independently agree on the layouts and compiler/source disposition. |

## 2026-06-30 B005 Empty-Emitter Implementation

B005 resolves this layout-support empty emitter with a formal comment-only no-code marker. The page remains reconstructable layout evidence for recovered member offsets and enum/state facts, but standalone emitted source belongs in the class/method/global pages: [UID:0000A5][ParcelIconPane](by-class/ParcelIconPane.md), [UID:0000A6][ParcelPane](by-class/ParcelPane.md), [UID:000058][FlyingParcelPane](by-class/FlyingParcelPane.md), and their exact child method pages. Do not duplicate class declarations or method bodies here.

## 2026-07-15 B001 UID0001EO Accepted Callback Synchronization

- Current metadata is `90/92`, owner/emitter [UID:0000MF][ParcelPane](by-file/ParcelPane.md), reconstructable true, blank optional position, and the pre-existing support-only managed marker remains unchanged.
- Fresh wrapper, constructor, ordinary destructor, callback, RTTI, and PMD evidence closes the ParcelIconPane direct-base and complete-object shape without changing any accepted ParcelPane or FlyingParcelPane offset.
- `Singleton<ParcelIconPane>` is a source base despite EBO overlap at `+0xf8`; its publication/clear stores are lifecycle lowering, not evidence for a separate global-management method or explicit field.
- The inactive final dword is required by both independent `0x104` size proofs but has no recovered runtime access. Destination class C++ names it `int m_notificationState` and deliberately leaves it uninitialized; this page preserves the ranking and all rejected alternatives rather than presenting the inferred name as symbol-proven.
- No standalone structure body is emitted here. The exact fields belong in [UID:0000A5][ParcelIconPane](by-class/ParcelIconPane.md), and the constructor/destructor/callback children own executable source.

## Cross References

- [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- [UID:0001EH][0x00545e40-0x005470ad.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md)
- [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md)
- [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-06-26 B002 accepted ParcelPaneOnMouseEvent implementation sync: no score change; recorded that [UID:0002KE][0x00546610-0x00546807.ParcelPaneOnMouseEvent](by-memory/0x00546610-0x00546807.ParcelPaneOnMouseEvent.md) now confirms the action-set side of `m_leftSlotAcknowledged` and `m_rightSlotAcknowledged`. Evidence: accepted B002 report and MCP session `80de0a67` support left release sending packet byte `0x41` through `g_packetSender->QueueAndSendPacket` before setting `+0x120`, right release constructing `new BulletinSession(1, 0, true)` under the `m_rightSlotActionEnabled` / `g_pBulletinSession` gate before setting `+0x121`, and [UID:0002KC][0x005464b0-0x00546575.ParcelPaneSetParcelSlotData](by-memory/0x005464b0-0x00546575.ParcelPaneSetParcelSlotData.md) as the count-change clear path.
- 2026-06-26 B004 accepted FlyingParcelPane cleanup destructor sync: no score change; refined the `FlyingParcelPane +0x100` layout note to source-facing `Layer *m_animationLayer`, recorded that [UID:0002R5][0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody](by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md) now emits the destructor ownership release for `m_animationLayer`, and preserved `m_screenLayerEntry` only as a prose alias for the ScreenPane attachment role. Evidence: B004 MCP session `80de0a67` confirmed the raw cleanup bytes, vtable route, scalar-wrapper parity, and no-direct-route confidence cap.
- 2026-06-25 B002 accepted ParcelPaneSetParcelSlotData implementation sync: no score change; recorded that [UID:0002KC][0x005464b0-0x00546575.ParcelPaneSetParcelSlotData](by-memory/0x005464b0-0x00546575.ParcelPaneSetParcelSlotData.md) now has first-draft formal C++ and confirmed the setter-specific field evidence. Evidence: accepted B002 report and MCP session `80de0a67` support count writes at `+0xf8/+0xf9/+0xfa`, acknowledgement clears at `+0x120/+0x121`, empty-slot button-state idling at `+0xfc/+0xfd`, and no animation-frame clear at `+0xfe/+0xff`.
- 2026-06-25 B002 accepted ParcelPane constructor implementation sync: no score change; recorded that [UID:0002KB][0x00546290-0x00546436.ParcelPaneConstructor](by-memory/0x00546290-0x00546436.ParcelPaneConstructor.md) now has first-draft formal C++ and confirmed the constructor's stable field initialization. Evidence: accepted B002 report and MCP session `80de0a67` support the count/state/frame/ack initializers, button rects, `SetParcelSlotData(0,0,0)` reset, order/timer calls, `m_leftAnimationFrame = -3`, `m_rightAnimationFrame = 0`, and the transient `+0xfc` overwrite rationale.
- 2026-06-13 A003 Goal 2 type-quality pass: Raised from `78/84` to `86/88`.
  - Before: the page had detailed May layout notes but stayed in the Low_Type queue and depended on older generated-output caveats.
  - After: the page records current IDA evidence for function anchors, vtable-store xrefs, `ParcelIconPane` child allocation and callback fields, standalone `ParcelPane` field writes, `FlyingParcelPane` payload normalization, and parcel/letter draw-mode selection. Direct parent [UID:0000MF][ParcelPane](by-file/ParcelPane.md) remains correct at `86/85`; vtable companion [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md) remains correct at `86/92`.
  - Evidence: IDA MCP `server_health`, `lookup_funcs`, `xrefs_to`, and `analyze_function` on 2026-06-13 against session `a001_goal2_0002UM`; key sizes and offsets were verified with `tools/int_convert.py`.
- 2026-06-17 B001 source-quality support refresh: raised from `86/88` to `88/90` after resolving the ParcelPane count/state/frame field names, `ParcelButtonState` enum values, `ALERTBTN` frame map, and timer/helper field usage. Evidence: B001 live IDA rechecked the timer callback, animation helper, frame resolver, mouse state writes, packet count nibble flow, and frame switch behavior.
- 2026-06-17 B002 FlyingParcelPane support refresh: no score change; updated FlyingParcelPane payload/helper fields to `m_animationFrame`, `m_parcelCountOrState`, `m_rightSlot`, `m_leftSlot`, `m_isParcel`, and `m_animationLayer`/`m_screenLayerEntry`, and linked those names to `StartAnimation`, `AnimateStep`, and destructor cleanup behavior.
- 2026-06-19 B012 accepted FlyingParcelPane implementation sync: no score change; recorded that `+0xac` remains inherited `Pane` origin/position state rather than derived flying-animation payload, and normalized the draw helper name to [UID:0002KL][0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter](by-memory/0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md).
- 2026-05-31: Grading changed from `0/0` to `78/84`, marked reconstructable, and attached to [UID:0000MF][ParcelPane](by-file/ParcelPane.md).
  - Before: layout evidence was detailed but the page remained unevaluated to validator/stat tooling.
  - After: the score reflects current IDA-verified class layouts, vtable subobjects, field offsets, child object bound, and split child method pages.
  - Evidence: IDA MCP function enumeration/decompilation checked the parcel notification range, constructors, slot update, input/timer/paint helpers, flying parcel animation, draw helper, singleton clear helpers, and destructor boundaries.
