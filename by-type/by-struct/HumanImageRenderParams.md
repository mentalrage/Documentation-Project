*** UID:00050M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma pack(push, 1)
struct HumanImageRenderParams
{
    unsigned int m_statusKind;
    union {
        unsigned short m_appearanceId;
        unsigned short m_faceId;
        unsigned short m_shapeIndex;
    };
    union {
        unsigned char m_variantOrPalette;
        unsigned char m_hairId;
        unsigned char m_headDrawOffset;
    };
    unsigned char m_padding07;
    unsigned short m_bodyId;
    unsigned short m_weaponId;
    unsigned short m_shieldOrArrowId;
    unsigned char m_helmetId;
    unsigned char m_padding0f;
    unsigned short m_faceDecorationId;
    unsigned short m_hairDecorationId;
    unsigned short m_secondFaceDecorationId;
    unsigned short m_mantleId;
    unsigned short m_neckId;
    unsigned short m_shoesId;
    unsigned short m_coatId;
    unsigned short m_fullBodyId;
    unsigned char m_headgearMode;
    union {
        unsigned char m_gender;
        unsigned char m_direction;
    };
    union {
        unsigned char m_compositionMode;
        unsigned char m_posture;
    };
    unsigned char m_padding23;
    unsigned int m_actionState;
    union {
        unsigned char m_displayStatusByte;
        unsigned char m_defaultByte;
    };
    unsigned char m_padding29;
    unsigned short m_ridingAppearanceId;
    unsigned short m_ridingDefinitionIndex;
    unsigned short m_ridingPaletteFlags;
    short m_ridingYOffset;
    unsigned char m_faceColor;
    unsigned char m_hairColor;
    unsigned char m_skinColor;
    unsigned char m_bodyColor;
    unsigned char m_weaponColor;
    unsigned char m_shieldOrArrowColor;
    unsigned char m_helmetColor;
    unsigned char m_faceDecorationColor;
    unsigned char m_hairDecorationColor;
    unsigned char m_secondFaceDecorationColor;
    unsigned char m_mantleColor;
    unsigned char m_neckColor;
    unsigned char m_shoesColor;
    unsigned char m_invisible;
};
#pragma pack(pop)

typedef char HumanImageRenderParamsSizeMustBe64[
    (sizeof(HumanImageRenderParams) == 0x40) ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact packed 0x40 NewHumanImageLib render descriptor and ObjectStatusBlob prefix, with every member, context alias, padding byte, riding field, color byte, final invisible flag, four-chunk copy evidence, consumer interactions, period-compatible size guard, and formal H emission through UID0000LR. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# HumanImageRenderParams

## Status

- Exact source type: packed `HumanImageRenderParams`, size `0x40` / 64 bytes.
- Source owner/emitter: [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md), at H source position `5` before NewHumanImageLib declarations.
- Reconstruction disposition: H-only source declaration; no standalone CPP definition or body.
- Relationship: exact first `0x40` bytes of [UID:00009S][ObjectStatusBlob](by-class/ObjectStatusBlob.md). ObjectStatusBlob alone appends `m_faceShape` at `+0x40` and tail padding through size `0x44`.
- Evidence strength: direct copy width and consumer offsets establish ABI/layout; original identifier spelling is inferred from established project-wide render semantics.

## Exact Packed Layout

| Offset | Size | Exact source member/type | Contextual meaning |
| ---: | ---: | --- | --- |
| `+0x00` | `0x04` | `unsigned int m_statusKind` | descriptor/status discriminator |
| `+0x04` | `0x02` | union `m_appearanceId`, `m_faceId`, `m_shapeIndex` | context-dependent appearance/face/shape index |
| `+0x06` | `0x01` | union `m_variantOrPalette`, `m_hairId`, `m_headDrawOffset` | context-dependent variant/hair/head offset |
| `+0x07` | `0x01` | `unsigned char m_padding07` | exact packed padding |
| `+0x08` | `0x02` | `unsigned short m_bodyId` | body shape/part id |
| `+0x0a` | `0x02` | `unsigned short m_weaponId` | weapon part id |
| `+0x0c` | `0x02` | `unsigned short m_shieldOrArrowId` | shield/arrow part id |
| `+0x0e` | `0x01` | `unsigned char m_helmetId` | helmet part id |
| `+0x0f` | `0x01` | `unsigned char m_padding0f` | exact packed padding |
| `+0x10` | `0x02` | `unsigned short m_faceDecorationId` | face decoration |
| `+0x12` | `0x02` | `unsigned short m_hairDecorationId` | hair decoration |
| `+0x14` | `0x02` | `unsigned short m_secondFaceDecorationId` | second face decoration |
| `+0x16` | `0x02` | `unsigned short m_mantleId` | mantle part |
| `+0x18` | `0x02` | `unsigned short m_neckId` | neck part |
| `+0x1a` | `0x02` | `unsigned short m_shoesId` | shoes part |
| `+0x1c` | `0x02` | `unsigned short m_coatId` | coat part |
| `+0x1e` | `0x02` | `unsigned short m_fullBodyId` | full-body part |
| `+0x20` | `0x01` | `unsigned char m_headgearMode` | headgear mode |
| `+0x21` | `0x01` | union `m_gender`, `m_direction` | context-dependent gender/direction byte |
| `+0x22` | `0x01` | union `m_compositionMode`, `m_posture` | composition/posture byte |
| `+0x23` | `0x01` | `unsigned char m_padding23` | exact packed padding |
| `+0x24` | `0x04` | `unsigned int m_actionState` | action/render state |
| `+0x28` | `0x01` | union `m_displayStatusByte`, `m_defaultByte` | context-dependent status/default byte |
| `+0x29` | `0x01` | `unsigned char m_padding29` | exact packed padding |
| `+0x2a` | `0x02` | `unsigned short m_ridingAppearanceId` | riding appearance |
| `+0x2c` | `0x02` | `unsigned short m_ridingDefinitionIndex` | riding definition index |
| `+0x2e` | `0x02` | `unsigned short m_ridingPaletteFlags` | riding palette/render flags |
| `+0x30` | `0x02` | `short m_ridingYOffset` | signed riding vertical offset |
| `+0x32` | `0x01` | `unsigned char m_faceColor` | face color |
| `+0x33` | `0x01` | `unsigned char m_hairColor` | hair color |
| `+0x34` | `0x01` | `unsigned char m_skinColor` | skin/tint color |
| `+0x35` | `0x01` | `unsigned char m_bodyColor` | body color |
| `+0x36` | `0x01` | `unsigned char m_weaponColor` | weapon color |
| `+0x37` | `0x01` | `unsigned char m_shieldOrArrowColor` | shield/arrow color |
| `+0x38` | `0x01` | `unsigned char m_helmetColor` | helmet color |
| `+0x39` | `0x01` | `unsigned char m_faceDecorationColor` | face-decoration color |
| `+0x3a` | `0x01` | `unsigned char m_hairDecorationColor` | hair-decoration color |
| `+0x3b` | `0x01` | `unsigned char m_secondFaceDecorationColor` | second-face-decoration color |
| `+0x3c` | `0x01` | `unsigned char m_mantleColor` | mantle color |
| `+0x3d` | `0x01` | `unsigned char m_neckColor` | neck color |
| `+0x3e` | `0x01` | `unsigned char m_shoesColor` | shoes color |
| `+0x3f` | `0x01` | `unsigned char m_invisible` | final visibility byte; exact structure end |

## Binary And Consumer Evidence

- The live body at `0x004e21d0` copies this descriptor as four consecutive `0x10`-byte chunks, proving exact total size `0x40` rather than `0x3c`, `0x44`, or an unbounded local byte array.
- [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md) writes exact preview fields at `+0x00`, `+0x04`, `+0x08`, `+0x0a`, `+0x0c`, `+0x21`, `+0x22`, `+0x32`, and `+0x35` without resetting untouched members.
- `NewHumanImageLib::CalculateBounds` and `NewHumanImageLib::Draw` consume this record by typed descriptor pointer across create-user preview, group rendering, and broader composition paths.
- NewCreate packet code reads the shape-selector descriptor fields after `BuildPreviewParams`; packet serialization remains dialog-owned and does not transfer this type to a packet module.
- Existing `UserShapeSelectControlPane`, `UserCreatePreviewControlPane`, and `NewGroupPane::OnPaint` usages corroborate the same human-facing type family and eliminate raw stack-record labels.

## NewGroupPane Partial-Write Consumer - 2026-08-16

- [UID:0004Z5][0x0056ce50-0x0056da03.NewGroupPaneOnPaint](by-memory/0x0056ce50-0x0056da03.NewGroupPaneOnPaint.md) allocates this packed descriptor as an ordinary unconstructed stack local and writes only the fields observed in the binary before each NewHuman call. No `HumanImageRenderParams::Reset()`, constructor, aggregate zero-initialization, `memset`, or whole-object copy is present.
- The method writes source-facing `m_*` members from the global `GroupMemberRecord`: appearance/part identifiers, hairstyle and decoration identities/colors, face/hair/skin values, equipment identities, and the final invisible byte. It does not use unprefixed decompiler-style field names.
- Absent body, weapon, shield, mantle, neck, and shoes colors are written as zero. Absent item/appearance identifiers use the observed `0xffff` sentinel. `m_bodyColor` is not copied from the group record; it is explicitly zero in this path.
- Fields without observed stack stores remain untouched, including riding-related storage and any other descriptor bytes outside the exact write set. Preserving those bytes is part of the runtime contract; a defensive clear would alter behavior and obscure the binary's partial-initialization shape.
- The fully populated observed subset is passed to the complete nine-argument `NewHumanImageLib::CalculateBounds` and thirteen-argument `NewHumanImageLib::Draw` calls. `memberBounds` is derived from the returned image geometry exactly; the consumer does not justify a shortened overload or a different record layout.
- This independent consumer reinforces the existing packed `0x40` declaration and formal H without changing metadata. The page remains `94/95`, H position 5 under UID0000LR, with the existing size guard and ObjectStatusBlob-prefix relationship intact.

## Packing, ABI, And Source Shape

- `#pragma pack(push, 1)` / `#pragma pack(pop)` is required: the observed offsets place 16-bit and 32-bit fields without natural-alignment gaps.
- The period-compatible typedef size guard requires `sizeof(HumanImageRenderParams) == 0x40`; it avoids modern-only language features while making accidental ABI drift a compile failure.
- Context unions preserve genuine overlapping vocabulary without creating duplicate storage or forcing one subsystem's name onto every consumer.
- No raw IDA names, numeric-address fields, decompiler temporaries, synthetic reset helper, or byte-array replacement belongs in final source.

## ObjectStatusBlob Relationship

- [UID:00009S][ObjectStatusBlob](by-class/ObjectStatusBlob.md) and this type share every byte and semantic alias from `+0x00` through `+0x3f`.
- ObjectStatusBlob extends the shared prefix with `m_faceShape` at `+0x40` and padding through its `0x44` size; that extension is not part of `HumanImageRenderParams`.
- This page is the render-facing source declaration. ObjectStatusBlob remains the larger status/parser record and should link to this prefix rather than redefining conflicting member offsets.

## Ownership And Emission

- Direct owner/emitter [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) places the declaration in `NexusTK/render/NewHumanImageLib.h` at position `5`.
- The formal CPP channel is blank because this packed aggregate has no out-of-line implementation.
- Selector/login classes include the NewHuman header for a complete declaration when stack allocation or field access requires it; forward declaration alone is insufficient for those consumers.
- Generated source remains validator-owned. This page supplies only the formal H fragment and ordinary documentation route.

## Historical Assumptions And Rejected Alternatives

- Historical forward declarations and prose-only `HumanImageRenderParams` mentions were insufficient for compile-closed stack objects and member dereferences.
- Reject `Reset()` as a binary-proven API for selector builders: the NewUser selector performs exact partial writes and intentionally leaves untouched fields unchanged.
- Reject a local `unsigned char[0x40]`, raw offsets, a `0x3c` truncation, or direct reuse of the full `0x44` ObjectStatusBlob; each loses source semantics or changes observed ABI.
- Original spelling is not recovered from symbols. The accepted names are behavior- and subsystem-bounded human-source inference and are preferable to `field_XX`, `unk_`, or decompiler labels.

## Score Rationale

- Completion `94`: exact size, packing, every offset/type/alias/padding byte, all riding/color fields, copy-width proof, consumer interactions, owner/emitter placement, formal H, size guard, larger-record relationship, and rejected alternatives are documented.
- Confidence `95`: direct four-chunk copy and independent field consumers prove layout/ABI at final-audit strength. Identifier spellings are inferred, but no unresolved behavioral, size, offset, owner, or emission question remains.

## Cross-References

- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:00009S][ObjectStatusBlob](by-class/ObjectStatusBlob.md)
- [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md)
- [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md)
- [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md)

## Changes

- 2026-08-11 B005 UID0000LY callback: created the complete packed render descriptor with exact H emission, all offsets and contextual aliases, period-compatible size guard, four-chunk size proof, ObjectStatusBlob prefix relationship, and compile-closed NewHumanImageLib ownership.
- 2026-08-16 B003 UID0003F8 callback: added the exact NewGroupPane partial-write consumer, zero/`0xffff` absent-value policy, untouched-field contract, full NewHuman call relationship, and explicit rejection of Reset/whole-clear/unprefixed-field source while preserving the complete packed H and `94/95` metadata.
