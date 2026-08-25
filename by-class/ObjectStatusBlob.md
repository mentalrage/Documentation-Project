*** UID:00009S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000M6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000M6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ObjectStatusBlob.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_MAP_OBJECTSTATUSBLOB_H
#define NEXUSTK_MAP_OBJECTSTATUSBLOB_H

#include "../render/NewHumanImageLib.h"

class ObjectStatusBlob : public HumanImageRenderParams
{
public:
    enum StatusKind
    {
        HumanObject = 0,
        FullLivingObject = HumanObject,
        MonsterObject = 1,
        CompactLivingObject = MonsterObject,
        ItemObject = 2
    };

    int ParseTaggedStatus(const unsigned char *packet);
    int ParseFullStatus(const unsigned char *packet);
    int ParsePartialStatus(const unsigned char *packet);

    unsigned char m_faceShape;
    unsigned char m_trailingPadding[3];
};

typedef char ObjectStatusBlobSizeMustBe68[
    sizeof(ObjectStatusBlob) == 0x44 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ObjectStatusBlob

## 2026-08-18 Header And Prefix Closure

- The complete declaration now lives once in the formal H channel and publicly extends the exact packed [UID:00050M][HumanImageRenderParams](by-type/by-struct/HumanImageRenderParams.md) prefix. The inherited prefix is exactly 0x40 bytes; m_faceShape at +0x40 plus three trailing bytes produce the exact 0x44 class size.
- Formal CPP includes ObjectStatusBlob.h and routes only the established tagged/full/partial parser children. The old full class redeclaration in CPP is historical recovery evidence, not active source.
- This source shape is required by ObjectImage and other consumers that embed or instantiate the complete type. A forward declaration is insufficient.
- Scores are 94/94: layout, prefix, parser declarations, source pair, and compile route are closed. Remaining limits are original lexical spellings and absence of rebuilt-binary comparison, not a missing H/CPP contract.

## UID0003TH Hit-Bar Style Consumer - 2026-07-15

- [UID:0003TH][0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPane](by-memory/0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPane.md) is an exact consumer of `LivingObjectPane::m_objectStatus.m_statusKind`.
- The target compares the status kind with `ObjectStatusBlob::HumanObject` value `0`: HumanObject selects HitBarObjectPane constructor style `1`, while every nonzero status kind selects style `0`.
- The branch is an enum comparison, not a generic boolean test or attachment/link flag. It does not alter the enum values, object-status layout, or ownership of the stored status blob.
- At the dated 2026-07-15 checkpoint, score `92/93`, owner/emitter UID0000M6, complete enum/layout formal C++, and every unrelated status consumer remained unchanged. The later 2026-08-18 header/prefix closure superseded only that score and source-shape checkpoint with the current `94/94` public-inheritance declaration.

## Current class status

- `94/94`, reconstructable and emitted by file UID0000M6 through the `NexusTK/map/ObjectStatusBlob.cpp` and `.h` source pair. The complete naturally aligned declaration is exactly 68 bytes, publicly and non-virtually derives from the exact `0x40` `HumanImageRenderParams` prefix, and exposes the three registered source methods.
- Exact method children are UID0004LK tagged (`0x004d1f30-0x004d1f99`, position 10), UID0004LL full (`0x004d1fa0-0x004d2637`, position 20), and UID0004LM partial (`0x004d2640-0x004d2697`, position 30). UID000179 is their non-emitting range/index.
- This remains a packet-state value type with no observed source-authored constructor/destructor, vtable, RTTI, virtual method, or singleton lifecycle. The parser bodies alone do not encode base-class dispatch; the active public non-virtual inheritance is instead the accepted source model for the byte-for-byte `HumanImageRenderParams` prefix and direct NewHuman-compatible pointer use. No virtual or ownership relationship is inferred beyond that exact base-prefix contract.

## Layout and aliases

### HumanImageRenderParams prefix relationship

[UID:00050M][HumanImageRenderParams](by-type/by-struct/HumanImageRenderParams.md) is the exact packed `[+0x00,+0x40)` prefix consumed by NewHuman bounds/draw and selector preview paths. It shares the status, appearance/face/shape, variant/hair/head-offset, equipment, mode/direction, action, riding, color, and invisible fields byte-for-byte. This page's `ObjectStatusBlob` extends that prefix only with `m_faceShape` at `+0x40` and tail padding through exact size `0x44`.

The active source relationship is public non-virtual C++ inheritance, selected to express the exact ABI prefix and direct pointer compatibility without casts or duplicate fields. UID00050M still owns and emits the base declaration once through [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md), while this derived class retains its parser methods and complete `0x44` storage contract through [UID:0000M6][ObjectStatusBlob](by-file/ObjectStatusBlob.md); inheritance does not merge those source owners. Consumers that allocate only `0x40` bytes, including [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md), must use HumanImageRenderParams and must not instantiate or truncate ObjectStatusBlob. The earlier `structural reuse but not C++ inheritance` interpretation is retained only as superseded reasoning rejected by the accepted formal H declaration and direct consumer compatibility.

| Offset | Size | Formal field/aliases | Evidence-backed role |
| --- | --- | --- | --- |
| `+0x00` | 4 | status kind | enum 0 Human/FullLiving, 1 Monster/CompactLiving, 2 Item |
| `+0x04` | 2 | appearance/face/head index union | compact id, full face id, HeadSelect index |
| `+0x06` | 1 | variant/hair/head-draw-offset union | compact palette, full hair, HeadSelect draw adjustment |
| `+0x07` | 1 | padding | natural word alignment, never parsed |
| `+0x08` | 2 | body id | Body row and Body/Coat normalization |
| `+0x0a` | 2 | weapon id | Sword/Spear/Bow/Fan/Back selector |
| `+0x0c` | 2 | shield-or-arrow id | Shield/Arrow selector |
| `+0x0e` | 1 | helmet id | Helmet selector/headgear hiding |
| `+0x0f` | 1 | padding | natural word alignment, never parsed |
| `+0x10/+0x12/+0x14` | 6 | FaceDec, HairDec, second FaceDec ids | exact decoration selectors |
| `+0x16/+0x18/+0x1a` | 6 | mantle, neck, shoes ids | exact Part rows; Shoes sentinel normalization |
| `+0x1c/+0x1e` | 4 | coat and full-body ids | Coat/All rows and `0xffff` sentinels |
| `+0x20` | 1 | headgear mode | 0 hides Helmet; 1/2 hide Hair |
| `+0x21` | 1 | gender/direction union | full boolean tests and compact direction |
| `+0x22` | 1 | composition-mode/posture union | NewHuman render mode and compact posture |
| `+0x23` | 1 | padding | natural dword alignment, never parsed |
| `+0x24` | 4 | action state | initialized to 11 by full/partial |
| `+0x28` | 1 | display-status/default union | full payload byte 4 and `0x50` default |
| `+0x29` | 1 | padding | natural word alignment |
| `+0x2a` | 2 | riding appearance id | packet key; legacy force through `g_useEpfAssets` |
| `+0x2c/+0x2e/+0x30` | 6 | riding definition, palette flags, signed Y offset | `RidableAnimals` columns 1-3 and NewHuman consumers |
| `+0x32..+0x3e` | 13 | face/hair/skin/body/weapon/shield/helmet/decoration/mantle/neck/shoes colors | exact packet tail and Part-tag palette dispatch |
| `+0x3f/+0x40` | 2 | invisible/status and face shape | final packet bytes; invisibility remains raw byte |
| `+0x41..+0x43` | 3 | trailing padding | exact 68-byte value size; no checked access |

- Natural 4/2/1-byte alignment plus explicit padding produces `sizeof(ObjectStatusBlob)==68`; no packing pragma or raw byte array is required. Fixed 68-byte copies in ObjectImage and SelfLook independently confirm the size.
- Aliases represent actual context-dependent consumers, not duplicate storage: Map/ObjectImage use living/item and appearance/variant terms; full parsing uses face/hair, gender/composition; HeadSelect uses head index/draw offset; compact status uses direction/posture.

## Parser surface

| Child | Behavior and return |
| --- | --- |
| UID0004LK `ParseTaggedStatus` | tag 0 delegates full and returns 44; tags 1/2 write compact kind/id/variant and return 4; default returns 0 without writes |
| UID0004LL `ParseFullStatus` | consumes 43 bytes; performs riding metadata, HAIRCOL remap, face/body/coat/shoes/headgear normalization, equipment/color/tail writes |
| UID0004LM `ParsePartialStatus` | consumes 5 bytes; writes compact kind 1, action 11, display `0x50`, direction/posture aliases, BE16 appearance, variant |

- All signatures are member `int(const unsigned char *)`; binary calls lower as thiscall with an ObjectStatusBlob receiver. No free or static overload wrapper is observed.
- Canonical scalar reader is `PacketBufferReadUInt16BE` `0x00575480`. `0x00575470` is compiler/runtime narrow-byte lowering, not a source packet helper.

## Equipment, color, riding, and resource evidence

- `Part.tbl` rows map exactly: 0 Body, 1 Coat, 2 Face, 3 Emotion, 4 FaceDec, 5 Hair, 6 Helmet, 7 HairDec, 8 Sword, 9 Spear, 10 Bow, 11 Fan, 12 Shield, 13 Arrow, 14 Mantle, 15 Shoes, 16 Neck, 17 All, 18 Back. Their range normalization and selectors/colors correspond to formal offsets `+0x08..+0x1e` and `+0x32..+0x3e`.
- Shared `+0x34` is skin/tint, not generic profile state. NewHuman composition consumes `+0x22`, `+0x2c/+0x2e/+0x30`, all equipment ids, `+0x32..+0x3e` colors, and shared tint.
- Full parsing formats riding id with `%d`, queries `RidableAnimals` through MetaMan `FindEntry`, and converts columns 1-3 with `_wtol`. These are riding definition, packed palette/render flags, and signed Y offset, not title metadata.
- `g_pNewHumanImageLib` at `0x0067a760` owns the `HAIRCOL.TBL` vector at class `+0x54/+0x58`. It remaps the low five hair-color bits modulo 32 while preserving upper bits. `g_useEpfAssets` UID0000SW controls the legacy riding-id force.

## Consumers and ownership

- MapPane calls full/partial at `0x0050fba3/0x0050fbbc` and `0x00513354/0x0051336d`, preserving full/compact living and item aliases.
- SelfLook calls full/partial in modeled handlers and raw helpers; SelfLookPane2 has the parallel call family. UserLook/Profile calls at `0x0059f8dc/0x0059f901` consume but do not own the class.
- ObjectImageControlPane copies exactly 68 bytes and dispatches kind 0/1/2. HeadSelect compact mode validates the head aliases. Tagged callers across merchant, text, item, spell, message, and Nexonclub dialogs use returned cursor lengths.
- Broad independent use and the coherent existing class/file route keep ownership here. MapPane, NewHumanImageLib, MetaMan, PacketBuffer, UserLook/Profile, SelfLook, and dialogs remain dependencies/consumers.

## Superseded assumptions and score

- Historical title/profile prose for `+0x2a..+0x40`, generic appearance-remap naming for `0x0067a760`, universal direction/posture labels, and blank-class/raw-field-array guidance are rejected by current parser/resource/consumer evidence. They remain audit history, not present-state semantics.
- Completion/confidence `94/94` reflects the size-checked public `HumanImageRenderParams` derivation, every offset/type/padding byte, enum aliases, all three methods, registered children, resources, globals, callers, separate CPP/H route, and generated declaration verification. Original member spellings, the inferred historical folder/file name, and absent rebuilt-binary comparison remain the evidence caps.

## Changes

- 2026-08-22 B010 Gate 2A repair: reconciled every active inheritance statement with the formal public `HumanImageRenderParams` base and every active score statement with `94/94`; the former no-inheritance and `92/93` positions are now explicitly dated or superseded history.
- 2026-08-11 B005 UID0000LY type synchronization:
  - Documented [UID:00050M][HumanImageRenderParams](by-type/by-struct/HumanImageRenderParams.md) as the exact packed `0x40` prefix, the ObjectStatusBlob-only `+0x40` extension through size `0x44`, separate source ownership, and the selector's non-truncating consumer route.

- 2026-07-13 B005 UID000179 callback: raised `86/90 -> 92/93`; installed the complete 68-byte Destination 2 declaration and `[[CHILDREN]]`; linked UID0004LK/UID0004LL/UID0004LM; replaced stale title/profile/remap summaries with complete layout, aliases, parser, resource, caller, global, and source evidence. Owner/emitter UID0000M6 and reconstructable state remain unchanged.
- Earlier 2026-06 ObjectImage/Map evidence establishing the 68-byte copy and status-kind/compact aliases is retained and now reconciled with the complete class surface.

## Cross-references

- [UID:0000M6][ObjectStatusBlob](by-file/ObjectStatusBlob.md)
- [UID:000179][0x004d1f30-0x004d2697.ObjectStatusBlobParsers](by-memory/0x004d1f30-0x004d2697.ObjectStatusBlobParsers.md)
- [UID:0004LK][0x004d1f30-0x004d1f99.ObjectStatusBlobParseTaggedStatus](by-memory/0x004d1f30-0x004d1f99.ObjectStatusBlobParseTaggedStatus.md)
- [UID:0004LL][0x004d1fa0-0x004d2637.ObjectStatusBlobParseFullStatus](by-memory/0x004d1fa0-0x004d2637.ObjectStatusBlobParseFullStatus.md)
- [UID:0004LM][0x004d2640-0x004d2697.ObjectStatusBlobParsePartialStatus](by-memory/0x004d2640-0x004d2697.ObjectStatusBlobParsePartialStatus.md)
- [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md)
