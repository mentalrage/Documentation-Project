*** UID:000058 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Layer;

class FlyingParcelPane : public Pane
{
public:
    FlyingParcelPane();
    virtual ~FlyingParcelPane();

    void StartAnimation(unsigned char parcelCountOrState,
                        unsigned char leftSlot,
                        unsigned char rightSlot,
                        bool isParcel);

protected:
    virtual bool AnimateStep(int timerId, int userData1, int userData2);
    virtual void DrawParcelOrLetter();

private:
    unsigned char m_animationFrame;
    unsigned char m_parcelCountOrState;
    unsigned char m_rightSlot;
    unsigned char m_leftSlot;
    bool m_isParcel;
    Layer *m_animationLayer;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FlyingParcelPane

## B001 UID0002ZO Accepted Callback State - 2026-07-21

The class is now source-ready at `92/93`, emitted by [UID:0000MF][ParcelPane](by-file/ParcelPane.md) at class position `30`. The managed declaration is authoritative: the inherited Pane occupies `0x00..0xf7`; the byte fields occupy `+0xf8..+0xfc`; natural x86 alignment places `Layer *m_animationLayer` at `+0x100`; and the complete object size is `0x104`. No explicit padding member is source-authored.

The class remains implementation-private to `ParcelPane.cpp`. [UID:0000A6][ParcelPane](by-class/ParcelPane.md) grants `FlyingParcelPane` friend access to the private inline `FinishFlyingParcelAnimation` helper, so `AnimateStep` no longer reaches ParcelPane private fields directly. The constructor, ordinary destructor, StartAnimation, AnimateStep, and DrawParcelOrLetter children emit at positions `20/30/40/50/60`; scalar deletion, adjustors, RTTI, vtables, and EH funclets remain compiler output.

## Layer Client Synchronization - 2026-07-14

FlyingParcelPane construction calls [UID:0004NR][0x004f0480-0x004f0597.LayerConstructor](by-memory/0x004f0480-0x004f0597.LayerConstructor.md) at `0x00546b3b` for its animation/UI Layer member or owned context. This establishes an owned Layer client but does not transfer Layer source ownership. Layer retains its own RTTI/vtable, eight-byte object, root tree, Region lifetime, and method island. Existing FlyingParcelPane score, declaration, route, and unrelated behavior remain unchanged.

## Status

- Confidence: strong for parcel/letter animation helper ownership, vtable layout, constructor/destructor cluster, and `ParcelPane.cpp` source grouping; medium-high for final helper-field names and whether the helper class was private-header or file-local in the original source.
- Likely source file: [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- Stale generated lead: `source-3/simroot_v2/class_FlyingParcelPane.cpp`; use as warning evidence only because it omits raw bodies and carries rejected helper/type names.
- Source exposure direction: high-probability implementation-private or file-local helper class in [UID:0000MF][ParcelPane](by-file/ParcelPane.md) / `ParcelPane.cpp`, not a public standalone class unless later source/header evidence proves that exposure.
- Memory range: [UID:0001EH][0x00545e40-0x005470ad.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md), now documented as a non-emitting mixed container/source-family index. Exact FlyingParcelPane child pages and the [UID:0001EL][0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart](by-memory/0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart.md) carry FlyingParcelPane source decisions.
- Vtable/type evidence: [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md)
- Vtable-data evidence: [UID:0002OH][0x00621bb0-0x00621d50.ParcelNotificationVtableData](by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md)
- Layout evidence: [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md)

## Class Purpose

`FlyingParcelPane` is the transient helper pane that animates parcel and letter delivery over the parcel notification HUD. It owns a compact payload at the end of the base `Pane`, owns a small `Layer`/screen-layer entry pointer at `+0x100`, draws either the parcel alert button or letter sprite, advances a short timer animation, and finally updates [UID:0000A6][ParcelPane](by-class/ParcelPane.md) through [UID:0000RY][g_pParcelPane](by-global/g_pParcelPane.md). The best source-facing model is an implementation-private parcel animation helper inside `ParcelPane.cpp`; the RTTI/vtables prove a real C++ class, but the binary does not prove public header exposure.

## Layout Notes

The class derives from [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md). The base pane occupies the inherited range through `+0xf7`; `FlyingParcelPane` adds:

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `+0x00` | Primary `Pane`/`FlyingParcelPane` vtable | Constructor, raw cleanup body, and scalar destructor write `0x00621ccc`. |
| `+0xa0` | Secondary handler view | Constructor, raw cleanup body, and scalar destructor write `0x00621d18`. |
| `+0xa4` | Tertiary timer/update view | Constructor, raw cleanup body, and scalar destructor write `0x00621d48`; slot `+0x04` dispatches `AnimateStep`. |
| `+0xf8` | `m_animationFrame` | Constructor clears it as part of a dword store; `StartAnimation` clears it; `AnimateStep` increments it until the frame limit. |
| `+0xf9` | `m_parcelCountOrState` | `StartAnimation` stores first argument; `AnimateStep` forwards it to `ParcelPane::SetParcelSlotData`. |
| `+0xfa` | `m_rightSlot` | `StartAnimation` stores third argument; `AnimateStep` forwards it as the right slot value. |
| `+0xfb` | `m_leftSlot` | `StartAnimation` stores second argument; `AnimateStep` forwards it as the left slot value. |
| `+0xfc` | `m_isParcel` | Constructor clears it; `StartAnimation` stores the draw-mode argument; draw helper selects `ALERTBTN.*` when nonzero and `LETTER.*` otherwise. |
| `+0x100` | `Layer *m_animationLayer` / `m_screenLayerEntry` | Constructor allocates 8 bytes (decimal 8, Verified with int_convert.py), initializes through the Layer constructor path, `StartAnimation` attaches it through ScreenPane helpers, `AnimateStep` removes it through `g_pScreenPane`, and [UID:0002R5][0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody](by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md) now emits the destructor release for `m_animationLayer`. Use `m_animationLayer` in formal C++; keep `m_screenLayerEntry` only as a descriptive alias. |

Secondary callbacks receive `this == owner + 0xa0`; timer/update callbacks receive `this == owner + 0xa4`, so IDA decompiler offsets in callback bodies must be normalized back to the owner object. Offset `+0xac` is inherited [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md) origin state used by the flying animation, not a derived `FlyingParcelPane` payload field.

## Method Notes

| Range | Method | Notes |
| --- | --- | --- |
| [UID:0002KJ][0x00546ac0-0x00546b74.FlyingParcelPaneConstructor](by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md) | `FlyingParcelPane::FlyingParcelPane` | Exact constructor body, `0xb4` / 180 bytes (Verified with int_convert.py). Calls base Pane construction with flag `1`, installs three vtable views, clears payload bytes, allocates the 8-byte helper, initializes it through the Layer constructor path, stores it at `+0x100`, and now carries formal first-draft method C++. |
| [UID:0002R5][0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody](by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md) | raw cleanup destructor body | Ordinary source-ready `FlyingParcelPane::~FlyingParcelPane()` cleanup body. The child now emits formal first-draft destructor C++ for releasing `m_animationLayer`; compiler lowering restores `FlyingParcelPane` vtables, releases the owned `Layer`/screen-layer entry at `+0x100` through deleting vslot `+0x00` with flag `1`, and tail-jumps to base pane teardown. IDA currently does not wrap this start as a function, and no raw-start direct pointer/branch route survives. |
| [UID:0002R6][0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation](by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md) | `StartAnimation` / `StartDeliveryAnimation` | Source-ready `FlyingParcelPane::StartAnimation(...)` body. Configures parcel/letter animation fields, EPF/legacy rectangles, `g_useEpfAssets` rendering-mode behavior, `g_pScreenPane` layer attachment, `g_pSoundManager` sample playback, inherited origin adjustment, and a 10 ms or 100 ms timer. IDA still does not wrap this start as a function, but that is now a confidence cap rather than a method-level C++ blocker. |
| [UID:0002KK][0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep](by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md) | `AnimateStep` | Exact tertiary timer/update callback, now `92/93` with formal source C++. Continues a 10 ms animation until frame `0x1e` / 30 (Verified with int_convert.py) by decrementing inherited `m_origin.y`, invalidating `m_bounds`, and rescheduling the `+0xa4` timer handler through `TimerHandler::ScheduleTimer`; completion calls `Pane::RemoveFromLayer`, removes `m_animationLayer` through `ScreenPane::RemoveLayer`, and invokes the private friend-accessible ParcelPane completion helper. |
| [UID:0002KL][0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter](by-memory/0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md) | `DrawParcelOrLetter` | Exact primary-vtable draw helper, now `92/93` with formal source C++. Draws `ALERTBTN.EPF` frame 5 or `LETTER.EPF` frame 0 with the matching palette, initializes one `EPFTileContext`, passes `&tileContext.bounds` and inherited `m_bounds` to `RenderTileFrame`, and preserves `m_isParcel` as the branch flag. Avoid stale parcel-only `DrawParcel` wording when it hides the letter path. |
| `0x00546e8b-0x00546ea1` | destructor adjustor thunks | Secondary/tertiary vtable thunks forwarding to the scalar deleting destructor. Compiler-generated; see [UID:0001EM][0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks](by-memory/0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks.md). |
| [UID:0001EN][0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor](by-memory/0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md) | scalar deleting destructor wrapper | MSVC deleting-destructor wrapper for source-declared `virtual ~FlyingParcelPane()`; restores all three vtable views, releases the owned layer entry, destroys the Pane base, and conditionally frees `this`. Formal source C++ should be emitted through the ordinary destructor shape, not this wrapper. |

## Evidence Notes

- Live IDA MCP on 2026-06-12 rechecked [UID:0002KJ][0x00546ac0-0x00546b74.FlyingParcelPaneConstructor](by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md): `lookup_funcs` reports a single `sub_546AC0` function object of size `0xb4` / 180 bytes (Verified with int_convert.py), `callees` reports `0x00544460`, `0x004f4aa0`, and `0x004f0480`, and `get_bytes` confirms the twelve-byte `0xcc` padding before raw cleanup.
- 2026-06-25 B007 rechecked [UID:0002KJ][0x00546ac0-0x00546b74.FlyingParcelPaneConstructor](by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md) through MCP session `80de0a67`: command id `10` reports `sub_546AC0` size `0xb4` / 180 bytes (Verified with int_convert.py), command id `11` reports only `sub_544460`, `sub_4F4AA0`, and `sub_4F0480` as normal-body callees, command id `12` reports no direct inbound xrefs to the constructor, command id `15` confirms twelve `0xcc` padding bytes at `0x00546b74-0x00546b80`, and command ids `16` through `18` confirm the base call, vtable stores, payload clears, `Layer` allocation/constructor path, nullable `+0x100` store, and constructor EH fragments.
- B007 supplemental PE scanning of `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` found no absolute VA, RVA, or direct `E8`/`E9` relative edge to constructor `0x00546ac0`, while vtable-slot targets still appear as `.rdata` code pointers. This is negative reachability evidence only; it no longer blocks method-level constructor C++.
- Live IDA MCP `xrefs_to` for `0x00621ccc`, `0x00621d18`, and `0x00621d48` reports the expected `FlyingParcelPane` constructor writes at `0x00546afb`, `0x00546b01`, and `0x00546b0b`, raw cleanup writes at `0x00546b89`, `0x00546b8f`, and `0x00546b99`, and scalar destructor writes at `0x00546edc`, `0x00546ee2`, and `0x00546eec`.
- [UID:0002OH][0x00621bb0-0x00621d50.ParcelNotificationVtableData](by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md) bounds the `FlyingParcelPane` vtable-data island: primary base `0x00621ccc`, secondary base `0x00621d18`, tertiary base `0x00621d48`, draw slot `0x00621d10 -> 0x00546df0`, and animation-step slot `0x00621d4c -> 0x00546d70`.
- [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md) records the same `+0xf8..+0x100` payload layout and callback-offset normalization.
- Live IDA MCP on 2026-06-12 rechecked [UID:0002KK][0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep](by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md): `lookup_funcs` reports `sub_546D70` size `0x7e` / 126 bytes (Verified with int_convert.py), no function exists at the exclusive end `0x00546dee`, the unique tertiary vtable-slot signature covers `0x00621d48-0x00621d50`, and the method normalizes `this == owner + 0xa4` before consuming `+0xf8..+0xfb` payload bytes and `+0x100` helper state.
- 2026-06-25 B001 rechecked [UID:0002KK][0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep](by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md) through IDA MCP session `80de0a67`: the exact body, callback route, payload, timer/layer/parcel behavior, and inherited owner `+0xac` access were confirmed. That pass labeled the component `.x`; the 2026-07-16 Point-layout correction supersedes only that label with `m_origin.y`.
- Existing raw method pages document the non-IDA-wrapped cleanup and start bodies at exact ranges, preserving the structure required by the parcel notification aggregate. The constructor itself is not mixed with those raw bodies because `0x00546b74-0x00546b80` is confirmed padding.
- The class belongs under [UID:0000MF][ParcelPane](by-file/ParcelPane.md): `ParcelIconPane`, `ParcelPane`, and `FlyingParcelPane` are contiguous in the `0x00545e40-0x005470ad` executable island, share parcel globals/resources, and end immediately before [UID:0000MH][PatchPane](by-file/PatchPane.md).
- B007 reclassified [UID:0001EH][0x00545e40-0x005470ad.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md) as a non-emitting mixed container, matching this page's existing policy that exact FlyingParcelPane children own source decisions. The aggregate's owner-none/no-emitter state does not weaken this class's source-family placement under [UID:0000MF][ParcelPane](by-file/ParcelPane.md).

## 2026-06-19 B012 Source-Quality Implementation

B012 rechecked the target against the accepted source-quality report, current by-* support pages, stale generated output, and local PE disassembly of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` (`MD5 4247e04e20b65d6414c7238aa8ff5515`, `SHA1 c285b73dc7b54c9a0e28ff7591a9bdde2ac55f9a`). The class stays owned by [UID:0000MF][ParcelPane](by-file/ParcelPane.md) and should be treated as a high-probability implementation-private helper in `NexusTK/ui/panels/ParcelPane.cpp`.

Direct PE evidence and route closure:

- Constructor [UID:0002KJ][0x00546ac0-0x00546b74.FlyingParcelPaneConstructor](by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md) calls `Pane::Pane`, installs primary/secondary/tertiary vtables `0x00621ccc`, `0x00621d18`, and `0x00621d48`, clears the compact payload, allocates an 8-byte helper, calls the `Layer` constructor path, and stores the result at `+0x100`.
- Local pointer/edge scan found no absolute VA dword, RVA dword, or direct `E8`/`E9` rel32 edge to constructor `0x00546ac0`. Constructor ownership is proven by the vtable writes, class family, layout, and parcel notification source grouping, not by a public direct xref.
- Raw cleanup [UID:0002R5][0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody](by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md) restores all three vtable views, releases the `Layer`/screen-layer entry at `+0x100`, and tail-jumps to Pane base teardown. Local pointer/edge scan found no absolute VA, RVA, or rel32 route to raw start `0x00546b80`. Source role is ordinary `virtual FlyingParcelPane::~FlyingParcelPane()` cleanup, not a standalone helper.
- Raw start [UID:0002R6][0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation](by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md) has a security-cookie frame, `ret 0x10`, four byte arguments, EPF-mode branch, ScreenPane layer attachment, optional `SoundManager::PlaySample(g_pSoundManager, 200, 100)`, payload writes at `+0xf8..+0xfc`, inherited origin adjustment at `+0xac`, and timer scheduling through the tertiary view at `+0xa4`. Local pointer/edge scans and B007 MCP session `398b87c1` found no absolute VA, RVA, rel32, direct xref, or function-object route to raw start `0x00546bc0`; however, [UID:0002R6][0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation](by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md) now emits first-draft `FlyingParcelPane::StartAnimation(...)` through this class. Use `StartAnimation` as the preferred source-facing name; preserve `StartDeliveryAnimation` only as a descriptive alias.
- [UID:0002KK][0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep](by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md) is reached through tertiary vtable slot `0x00621d4c -> 0x00546d70`, with callback `this == owner + 0xa4`. Owner-normalized offsets are `+0xf8` animation frame, `+0xf9` parcel count/state, `+0xfa` right slot, `+0xfb` left slot, `+0x100` animation layer, and inherited Pane origin `+0xac`. On completion it calls `ScreenPane::RemoveLayer`, forwards payload to `ParcelPane::SetParcelSlotData`, sets `g_pParcelPane +0xfb` to `1`, and invalidates the parcel pane.
- [UID:0002KL][0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter](by-memory/0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md) is reached through primary vtable draw slot `0x00621d10 -> 0x00546df0`. B003 MCP session `80de0a67` rechecked the exact `0x7b` / 123-byte body, padding, no ordinary callers, one vtable data xref, `m_isParcel` read at `+0xfc`, `g_pEPFLib` load, `ALERTBTN.EPF` frame 5 / `ALERTBTN.PAL` versus `LETTER.EPF` frame 0 / `LETTER.PAL`, `&tileContext.bounds` as the source rectangle, inherited Pane bounds at `+0x44` as the destination, `RenderTileFrame` at `0x004b9980`, and security-cookie frame protection. The target-level render-helper/source-shape blocker is resolved; this child now emits first-draft `FlyingParcelPane::DrawParcelOrLetter()` C++ through its target page. The exact public helper declarations remain class-level support caveats only.
- [UID:0001EN][0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor](by-memory/0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md) is an MSVC scalar deleting destructor wrapper. It restores all three vtable views, duplicates the owned-layer cleanup, destroys the Pane base, and conditionally frees storage, including the `0x104` sized/vector-style path. Source should declare/define ordinary `virtual ~FlyingParcelPane()`, not hand-author `ScalarDeletingDestructor`.
- 2026-06-26 B004 rechecked [UID:0002R5][0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody](by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md) through MCP session `80de0a67` request ids `21`, `22`, `24`, `31-38`, `41`, `42`, `45`, and `46`: the raw body is still not an IDA function, covers exactly `0x35` / 53 bytes (Verified with int_convert.py), has twelve `0xcc` bytes before and eleven after, stores vtables `0x00621ccc`, `0x00621d18`, and `0x00621d48`, deletes the `+0x100` helper through its deleting vslot, and tail-jumps to `Pane` teardown. Supplemental PE scanning found no absolute VA/RVA pointer or direct `E8`/`E9` branch to `0x00546b80`; that negative route evidence is a confidence cap only. The method-level source body is now resolved as the ordinary `FlyingParcelPane` destructor release for `m_animationLayer`, while [UID:0001EN][0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor](by-memory/0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md) remains scalar deleting destructor wrapper glue.

Accepted field and type names:

| Offset | Accepted source-facing name | Notes |
| --- | --- | --- |
| `+0xf8` | `m_animationFrame` | Cleared by constructor/start, incremented by `AnimateStep` until frame `30`. |
| `+0xf9` | `m_parcelCountOrState` | Start arg 1, forwarded to `ParcelPane::SetParcelSlotData`. |
| `+0xfa` | `m_rightSlot` | Start arg 3, forwarded as the right-slot value. |
| `+0xfb` | `m_leftSlot` | Start arg 2, forwarded as the left-slot value. |
| `+0xfc` | `m_isParcel` | Start arg 4, draw branch flag for parcel art versus letter art. |
| `+0x100` | `Layer *m_animationLayer` / `m_screenLayerEntry` | Constructor allocates/initializes Layer-style entry; start attaches through ScreenPane; animation completion removes it; the ordinary destructor child [UID:0002R5][0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody](by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md) emits the source destructor release for `m_animationLayer`. |

Rejected stale/generated assumptions:

- `RenderBuffer`, `SpriteFrame`, `AssetManager`, `ObjectPane`, `RemoveFromObjectList`, and `DeliverParcel` from active generated `class_FlyingParcelPane.cpp` are rejected. The actual callee set and data flow use `Layer`, `ScreenPane` layer helpers, `SoundManager` sample playback, EPF resource lookup, shared surface rendering, Pane base cleanup, and `ParcelPane::SetParcelSlotData`.
- `m_targetObjectId`, `m_itemType`, `m_itemSubType`, `m_itemId`, `m_parentPane`, `m_altitude`, and `m_animBounds` are rejected as generated field pollution that does not match the exact derived offsets or handoff behavior.
- `m_isFlying` for `+0xfc` is rejected because the byte selects parcel versus letter resources.
- A derived field at `+0xac` is rejected. That offset is inherited Pane origin state.
- Source-level `FlyingParcelPane::ScalarDeletingDestructor` is rejected. It is compiler ABI output represented by [UID:0001EN][0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor](by-memory/0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md).
- `ScreenPane.cpp`, `Layer.cpp`, `TimerMgr.cpp`, `SoundManager.cpp`, `PatchPane.cpp`, and standalone `FlyingParcelPane.cpp` are weaker source placements. Each is a dependency or successor boundary, while the class itself is parcel notification feature code under `ParcelPane.cpp`.

Class-level formal C++ no-code/defer proof:

- This class page would need to define declaration visibility, method signatures, callback prototypes, inherited Pane virtual names, layer helper typedefs, and render helper declarations across several child pages.
- The constructor still has no direct absolute VA, RVA, or rel32 route in the local PE scan, but [UID:0002KJ][0x00546ac0-0x00546b74.FlyingParcelPaneConstructor](by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md) documents why that is negative reachability evidence rather than a no-code blocker. [UID:0002R5][0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody](by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md) does the same for the ordinary destructor body and emits the destructor C++; [UID:0002R6][0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation](by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md) now does the same for `StartAnimation(...)`. Their raw no-direct-route evidence remains a class confidence cap and declaration/reachability caveat only.
- [UID:0002KK][0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep](by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md) has now resolved its target-level timer, layer-removal, parcel-handoff, inherited-origin, and vtable-slot source shape and emits first-draft method C++. [UID:0002KL][0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter](by-memory/0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md) has likewise resolved its target-level EPF context/render-helper source shape and emits first-draft method C++. Shared declarations remain class-level support caveats only.
- The scalar deleting destructor is compiler-generated wrapper output and must remain formal-C++ blank.
- Active generated `class_FlyingParcelPane.cpp` is stale historical warning evidence: it previously omitted the raw `StartAnimation` body, treated the raw cleanup body as blank, used rejected helper/type names, and emitted a source-level scalar deleting wrapper. Current accepted child pages supersede those generated omissions.
- Therefore this class page remains formal-C++ blank. This is a class-declaration/source-shape hold only; it does not override the accepted method-level constructor C++ now carried by [UID:0002KJ][0x00546ac0-0x00546b74.FlyingParcelPaneConstructor](by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md), the accepted ordinary destructor C++ now carried by [UID:0002R5][0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody](by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md), the accepted `StartAnimation(...)` C++ now carried by [UID:0002R6][0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation](by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md), the accepted method-level `AnimateStep` C++ now carried by [UID:0002KK][0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep](by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md), or the accepted method-level draw C++ now carried by [UID:0002KL][0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter](by-memory/0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md). Other method-level C++ should still wait for each child page's own source-shape proof.

## Assignment Gate And Score Rationale

- 2026-06-30 B005 empty-emitter implementation: this class page now contains a formal comment-only no-code marker instead of an empty formal block. The marker is target-specific: no standalone class-page source body is emitted because constructor [UID:0002KJ][0x00546ac0-0x00546b74.FlyingParcelPaneConstructor](by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md), ordinary cleanup destructor [UID:0002R5][0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody](by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md), `StartAnimation` [UID:0002R6][0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation](by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md), `AnimateStep` [UID:0002KK][0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep](by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md), and draw helper [UID:0002KL][0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter](by-memory/0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md) already carry method-level source. The class remains a support/ownership and layout surface for an implementation-private `ParcelPane.cpp` helper, not a duplicate emitter.
- Current child route: constructor `92/94` position `20`, ordinary destructor `92/94` position `30`, StartAnimation `92/93` position `40`, AnimateStep `92/93` position `50`, and DrawParcelOrLetter `92/93` position `60`.
- Direct parent gate: this class is `92/93`; [UID:0000MF][ParcelPane](by-file/ParcelPane.md) is `92/93`, so the declaration and all source-bearing children have a complete class/file emitter route.
- Completion is `88` because the page now records source placement, class exposure direction, raw-route evidence, ordinary destructor versus scalar wrapper split, callback-offset normalization, accepted field/type names, constructor/destructor/start/draw/animate child source readiness, and rejected generated names. It remains below final-audit range because class declaration visibility and several shared helper signatures are still inferred.
- Confidence is `91` because the ownership chain, vtable writes, layout offsets, exact constructor boundary, raw lifecycle child pages, exact draw/timer vtable routes, destructor/start raw-body MCP rechecks, and local PE no-route scans all agree with `ParcelPane.cpp` ownership. It remains below final because exact private-header/file-local spelling and the raw `StartAnimation` caller/declaration route are not proven.

## Closed And Narrowed Questions

- Class exposure: highest-probability direction is implementation-private/file-local helper in `ParcelPane.cpp`. A public standalone class remains unproven.
- Source names: use `StartAnimation`, `AnimateStep`, and `DrawParcelOrLetter`. Keep `StartDeliveryAnimation` as a descriptive alias only.
- Derived fields: use `m_animationFrame`, `m_parcelCountOrState`, `m_rightSlot`, `m_leftSlot`, `m_isParcel`, and `m_animationLayer` / `m_screenLayerEntry`.
- Inherited state: `+0xac` is Pane origin state, not FlyingParcelPane payload.
- C++: keep this class page formal block blank under the class-level no-code proof above, while allowing [UID:0002KJ][0x00546ac0-0x00546b74.FlyingParcelPaneConstructor](by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md) to emit method-level first-draft constructor source, [UID:0002R5][0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody](by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md) to emit ordinary destructor source, [UID:0002R6][0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation](by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md) to emit method-level first-draft start-animation source, [UID:0002KK][0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep](by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md) to emit method-level first-draft timer callback source, and [UID:0002KL][0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter](by-memory/0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md) to emit method-level first-draft draw source.

## Cross-References

- [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- [UID:0000A6][ParcelPane](by-class/ParcelPane.md)
- [UID:0001EH][0x00545e40-0x005470ad.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md)
- [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md)
- [UID:0002OH][0x00621bb0-0x00621d50.ParcelNotificationVtableData](by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md)
- [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md)
- [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md)
- [UID:00018W][0x004f0480-0x004f1bf6.Layer](by-memory/0x004f0480-0x004f1bf6.Layer.md)
- [UID:000196][0x004f4aa0-0x004f4ab4.OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md)
- [UID:0002KJ][0x00546ac0-0x00546b74.FlyingParcelPaneConstructor](by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md)
- [UID:0002R5][0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody](by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md)
- [UID:0002R6][0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation](by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md)
- [UID:0001EN][0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor](by-memory/0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md)
- [UID:0001EM][0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks](by-memory/0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks.md)
- [UID:0000RY][g_pParcelPane](by-global/g_pParcelPane.md)

## Changes

- 2026-07-16 B005 UID0003XX bounded support sync: Class score, metadata, formal support marker, layout, source route, and unrelated method/history detail remain unchanged. Corrected StartAnimation/AnimateStep owner `+0xac` to inherited `m_origin.y` and explicitly historicalized the older `.x` interpretation.

- 2026-06-27 B007 accepted StartAnimation implementation sync:
  - No score or metadata change; this class remains `88/91`, owned/emitted by [UID:0000MF][ParcelPane](by-file/ParcelPane.md). The then-current broad-class formal C++ blank for class declaration/private-helper exposure and shared helper signatures is superseded by B005's comment-only support marker.
  - Updated [UID:0002R6][0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation](by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md) notes after supervisor acceptance of B007's source-quality report. The method child now scores `90/90` and emits first-draft `FlyingParcelPane::StartAnimation(...)` C++ through this class.
  - Summary/evidence: B007 MCP session `398b87c1` reconfirmed no IDA function/direct xref/VA/RVA/rel32 route to the raw start, exact padding and bounded body, helper/global names, rectangle/delay behavior, and class/file emitter route. The no-direct-route fact is now a confidence/declaration cap only, not a class-level method-C++ blocker.
- 2026-06-26 B004 accepted cleanup destructor implementation sync:
  - Updated [UID:0002R5][0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody](by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md) after supervisor acceptance of B004's source-quality report.
  - Before: this class scored `87/90`, treated the cleanup destructor as source-owned but still class-level blank under raw no-route/destructor-shape coordination, and listed destructor shape among the class-level formal-C++ caveats.
  - After: `COMPLETION:88`, `CONFIDENCE:91`; owner/emitter remain [UID:0000MF][ParcelPane](by-file/ParcelPane.md), and at that time the class formal block remained blank only for declaration visibility, raw `StartAnimation`, and shared helper-signature issues. B005 supersedes the empty class block with a comment-only support marker. The target-level destructor child now scores `90/92` and emits the ordinary destructor body that releases `m_animationLayer`.
  - Summary/evidence: B004 MCP session `80de0a67` request ids `21`, `22`, `24`, `31-38`, `41`, `42`, `45`, and `46` confirm exact `0x35` / 53-byte raw body, no IDA function at `0x00546b80`, exact padding, vtable stores, unique signature, scalar-wrapper and adjustor-thunk route, base teardown target, and vtable dwords. Supplemental PE scanning found no absolute VA/RVA or direct branch route to the raw start; that is now documented as a confidence cap rather than a no-code proof. `Layer *m_animationLayer` is the emitted field name; `m_screenLayerEntry` stays a prose alias. [UID:0001EN][0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor](by-memory/0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md) remains scalar deleting wrapper glue with blank C++.
- 2026-06-26 B007 accepted ParcelNotificationPanes support sync:
  - Clarified that [UID:0001EH][0x00545e40-0x005470ad.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md) is a non-emitting mixed container/source-family index and does not supersede exact FlyingParcelPane child decisions.
  - Preserved [UID:0001EL][0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart](by-memory/0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart.md) as the non-emitting raw split inventory over [UID:0002R5][0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody](by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md) and [UID:0002R6][0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation](by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md), while method-level constructor, animate-step, and draw children keep their accepted source decisions.
  - C++ policy later narrowed by child implementations: broad class C++ stayed blank for declaration/source-placement and shared helper signature reasons, while constructor/destructor/start/animate/draw method bodies emit through their exact child pages. B005 replaces the empty class block with a formal comment-only support marker.
- 2026-06-25 B001 accepted AnimateStep implementation sync:
  - Updated [UID:0002KK][0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep](by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md) after supervisor acceptance of B001's source-quality report.
  - Summary/evidence: animation-step child now scores `91/92`, has blank optional emitter position, and emits formal first-draft `bool FlyingParcelPane::AnimateStep(int, int, int)` C++ through its target page. MCP session `80de0a67` confirmed the exact body boundary, callback route, padding, helper callees, globals, and behavior. Its then-current `.x` component label is superseded by the 2026-07-16 `m_origin.y` correction; every other accepted source name and ownership conclusion remains current.
- 2026-06-25 B003 accepted DrawParcelOrLetter implementation sync:
  - Updated [UID:0002KL][0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter](by-memory/0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md) after supervisor acceptance of B003's source-quality report.
  - Summary/evidence: draw child now scores `91/92`, has blank optional emitter position, and emits formal first-draft `FlyingParcelPane::DrawParcelOrLetter()` C++ through its target page. MCP session `80de0a67` command ids `3`, `4`, `10` through `18`, `20`, and `24` through `30` confirmed the exact body boundary, vtable draw slot, bytes/padding, decompile/disasm call flow, resource strings/xrefs, helper/resource lookup evidence, vtable dwords, sibling/thunk evidence, and int conversions. The page now uses `m_isParcel`, `EPFTileContext`, `&tileContext.bounds`, inherited `m_bounds`, `g_pEPFLib->LookupLayoutEntry`, and `RenderTileFrame`; it rejects parcel-only `DrawParcel`, `m_isFlying`, generated helper/type names, dependency owners, stack `EPFTileContext` cleanup, and source-authored security-cookie behavior. The old class-level empty block was superseded by B005's comment-only support marker.
- 2026-06-25 B007 accepted constructor source-quality implementation sync:
  - Updated [UID:0002KJ][0x00546ac0-0x00546b74.FlyingParcelPaneConstructor](by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md) notes after supervisor acceptance of B007's report.
  - Summary/evidence: constructor child now scores `90/92`, has position `10`, and emits formal first-draft `FlyingParcelPane::FlyingParcelPane()` C++ through its target page. MCP session `80de0a67` command ids `10` through `18` and supplemental PE no-xref scanning confirm the exact constructor body, no direct inbound constructor edge, payload clears, `Layer` helper construction, vtable stores, EH fragments, and padding boundary. The old class-level empty block was superseded by B005's comment-only support marker; exact child pages carry the method bodies.
- 2026-06-12 A004 Goal2:
  - No score change; retained `COMPLETION:85`, `CONFIDENCE:86`, and direct file parent [UID:0000MF][ParcelPane](by-file/ParcelPane.md).
  - Updated the method inventory, evidence notes, and assignment-gate rationale after [UID:0002KK][0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep](by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md) was raised to `87/90` with live IDA evidence. This older cap note is superseded by the exact [UID:0002KL][0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter](by-memory/0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md) page now scoring `91/92`; the remaining class cap is final helper/source naming and declaration exposure.
- 2026-06-17 B002 source-quality support refresh:
  - Updated field names to `m_animationFrame`, `m_parcelCountOrState`, `m_rightSlot`, `m_leftSlot`, `m_isParcel`, and `m_animationLayer`/`m_screenLayerEntry`; clarified [UID:0002R5][0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody](by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md) as the ordinary destructor cleanup body, [UID:0002R6][0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation](by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md) as `StartAnimation`/`StartDeliveryAnimation`, and [UID:0001EN][0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor](by-memory/0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md) as a generated scalar deleting destructor wrapper with corrected half-open range `0x00546ed0-0x00546f37`. No score change; remaining class cap is final header/private-helper exposure and coordinated final-C++ readiness.
- 2026-06-19 B012 accepted source-quality implementation:
  - Before: `COMPLETION:85`, `CONFIDENCE:86`; implementation-private exposure, raw-route proof, draw-helper closure, rejected generated names, and no-code proof were not yet incorporated at class level.
  - After at that time: `COMPLETION:87`, `CONFIDENCE:90`; owner/emitter remained [UID:0000MF][ParcelPane](by-file/ParcelPane.md), and formal C++ was blank. B005 supersedes the empty block with a comment-only support marker.
  - Evidence: accepted B012 report rechecked local PE disassembly and pointer/edge scans for constructor, raw cleanup, raw start, `AnimateStep`, `DrawParcelOrLetter`, scalar deleting wrapper, vtable data, ScreenPane layer helpers, generated simroot pollution, and support docs. The page now treats `FlyingParcelPane` as a high-probability implementation-private `ParcelPane.cpp` helper, records exact payload and layer fields, preserves callback offset normalization, rejects stale `RenderBuffer`/`SpriteFrame`/`AssetManager`/`ObjectPane` and source-level `ScalarDeletingDestructor`, and states the class-level no-formal-C++ proof later narrowed by B007 for the constructor child and B003 for the draw child.
- 2026-06-12 A002 Goal2:
  - Before: `COMPLETION:82`, `CONFIDENCE:84`.
  - After: `COMPLETION:85`, `CONFIDENCE:86`; parent remains [UID:0000MF][ParcelPane](by-file/ParcelPane.md) at position `30`.
  - Evidence: live IDA MCP rechecked the constructor boundary and body, vtable-write xrefs for constructor/raw cleanup/scalar destructor, helper allocation/init, payload clears, and successor padding; linked vtable-data/layout/file pages already support the parcel notification family and file ownership. Remaining open work is limited to final helper/source names and exact high-score pages for `AnimateStep`/`DrawParcel`, so the class clears the 85/85 route gate but remains below final-code readiness.
- 2026-05-31: Marked reconstructable and attached to [UID:0000MF][ParcelPane](by-file/ParcelPane.md); split the IDA-wrapped constructor, animation step, and draw helper into exact child pages.
  - Before: class evidence was documented but validator autogen metadata was blank and several wrapped methods had no exact by-memory page.
  - After at that time: `RECONSTRUCTABLE:TRUE` with file parent set; C++ was blank because helper object type, scheduler names, and render APIs were not final-source ready. Later child implementations and B005 supersede the blank state.
  - Evidence: IDA MCP confirms constructor `0x00546ac0`, animation step `0x00546d70`, draw helper `0x00546df0`, scalar destructor `0x00546ed0`, and raw lifecycle/start bodies retained in the existing raw aggregate page.
- Earlier score update:
  - Before: raw cleanup/start bodies were only described through the aggregate `0x00546b80-0x00546d64` page.
  - Changed to: exact child pages now document `0x00546b80-0x00546bb5` and `0x00546bc0-0x00546d64`, and class completion/confidence were raised to `82/84`.
  - Summary/evidence: 2026-06-01 IDA MCP bounded disassembly, vtable xrefs, and byte checks confirmed the raw method boundaries and padding while final field/API names remained below C++ rewrite quality.
